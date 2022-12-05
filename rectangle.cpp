#include "Primitives.h"
#include <glut.h>

rectangle::rectangle(): rectangle(T(0,0), 1, 1, 1, 1, 1) {}

rectangle::rectangle(const rectangle& R): 
			rectangle(R.getCenter(), R.sideSizeX, R.sideSizeY, R.red, R.green, R.blue) {}

rectangle::rectangle(const T& center, double sideSizeX, double sideSizeY, float red, float green, float blue):
			sideSizeX(sideSizeX), sideSizeY(sideSizeY) 
{
	this->setColor(red, green, blue);
	this->setCenter(center);

	this->top = T(center.x, center.y + sideSizeY / 2);
	this->bottom = T(center.x, center.y - sideSizeY / 2);
	this->left = T(center.x - sideSizeX / 2, center.y);
	this->right = T(center.x + sideSizeX / 2, center.y);

	this->topLeft = T(center.x - sideSizeX / 2, center.y + sideSizeY / 2);
	this->topRight = T(center.x + sideSizeX / 2, center.y + sideSizeY / 2);
	this->bottomLeft = T(center.x - sideSizeX / 2, center.y - sideSizeY / 2);
	this->bottomRight = T(center.x + sideSizeX / 2, center.y - sideSizeY / 2);
}

void rectangle::moveBy(double x, double y) {
	T movement(x, y);
	this->setCenter(getCenter() + movement);
	
	this->top += movement;
	this->bottom += movement;
	this->left += movement;
	this->right += movement;
	
	this->topLeft += movement;
	this->topRight += movement;
	this->bottomLeft += movement;
	this->bottomRight += movement;
}

void rectangle::moveTo(double x, double y) {
	this->moveBy(x - getCenter().x, y - getCenter().y);
}

void rectangle::changeSize(double sideSizeX, double sideSizeY) {  // sideSize must be > 0
	
	double cX = sideSizeX / this->sideSizeX;  // change factor
	double cY = sideSizeY / this->sideSizeY;

	this->sideSizeX = sideSizeX;  
	this->sideSizeY = sideSizeY;

	this->top.x *= cX;  // X component
	this->bottom.x *= cX;
	this->left.x *= cX;
	this->right.x *= cX;
	this->topLeft.x *= cX;
	this->topRight.x *= cX;
	this->bottomLeft.x *= cX;
	this->bottomRight.x *= cX;
	
	this->top.y *= cY;  // Y component
	this->bottom.y *= cY;
	this->left.y *= cY;
	this->right.y *= cY;
	this->topLeft.y *= cY;
	this->topRight.y *= cY;
	this->bottomLeft.y *= cY;
	this->bottomRight.y *= cY;
}

void rectangle::rotate(double angle) {  // in degrees
	// get side coordinates relative to the center 
	T relative_top(top - getCenter());
	T relative_bottom(bottom - getCenter());
	T relative_left(left - getCenter());
	T relative_right(right - getCenter());
	T relative_topLeft(topLeft - getCenter());
	T relative_topRight(topRight - getCenter());
	T relative_bottomLeft(bottomLeft - getCenter());
	T relative_bottomRight(bottomRight - getCenter());

	// rotate this vectors
	relative_top.rotate(angle);
	relative_bottom.rotate(angle);
	relative_left.rotate(angle);
	relative_right.rotate(angle);
	relative_topLeft.rotate(angle);
	relative_topRight.rotate(angle);
	relative_bottomLeft.rotate(angle);
	relative_bottomRight.rotate(angle);

	// save new vectors
	top = relative_top + getCenter();
	bottom = relative_bottom + getCenter();
	left = relative_left + getCenter();
	right = relative_right + getCenter();
	topLeft = relative_topLeft + getCenter();
	topRight = relative_topRight + getCenter();
	bottomLeft = relative_bottomLeft + getCenter();
	bottomRight = relative_bottomRight + getCenter();
}

void rectangle::print() const {
	glColor3f(red, green, blue);
	glBegin(GL_POLYGON);
	
	glVertex2f(topLeft.x, topLeft.y);
	glVertex2f(topRight.x, topRight.y);
	glVertex2f(bottomRight.x, bottomRight.y);
	glVertex2f(bottomLeft.x, bottomLeft.y);
	
	glEnd();
}