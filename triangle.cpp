#include "Primitives.h"
#include <glut.h>

triangle::triangle() : triangle(T(0,0)) {}

triangle::triangle(const triangle& Tr):
			triangle(Tr.v1, Tr.v2, Tr.v3, Tr.red, Tr.green, Tr.blue) {}

triangle::triangle(const T& v1, const T& v2, const T& v3, float red, float green, float blue):
			v1(v1), v2(v2), v3(v3) 
{
	setColor(red, green, blue);
	setCenter( (v1 + v2 + v3) / 3 );
	l12 = (v1 - v2).length();
	l23 = (v2 - v3).length();
	l31 = (v3 - v1).length();
}

triangle::triangle(const T& center, double size, float red, float green, float blue) 
{
	setCenter(center);
	setColor(red, green, blue);
	T vert(0, size);
	v1 = center + vert;
	vert.rotate(120);
	v2 = center + vert;
	vert.rotate(120);
	v3 = center + vert;

	l12 = (v1 - v2).length();
	l23 = (v2 - v3).length();
	l31 = (v3 - v1).length();
}

void triangle::changeSizeAlongAxis(double sizeX, double sizeY) 
{
	T vert1(v1 - getCenter());  // get a vertex coordinate relative to the center
	T vert2(v2 - getCenter());
	T vert3(v3 - getCenter());

	// calculate a change size factor
	double cX = sizeX / this->max_minus_min(vert1.x, vert2.x, vert3.x);
	double cY = sizeY / this->max_minus_min(vert1.y, vert2.y, vert3.y);
	if (sizeX == 0) cX = 1;
	if (sizeY == 0) cY = 1;
	
	vert1.x *= cX;  // change size of vectors 
	vert2.x *= cX;
	vert3.x *= cX;

	vert1.y *= cY;
	vert2.y *= cY;
	vert3.y *= cY;

	v1 = vert1 + getCenter();  // save new vectors
	v2 = vert2 + getCenter();
	v3 = vert3 + getCenter();

	l12 = (v1 - v2).length();  // save new lenghts of sides 
	l23 = (v2 - v3).length();
	l31 = (v3 - v1).length();
}

void triangle::rotate(double angle) {
	T vert1(v1 - getCenter());  // get a vertex coordinate relative to the center
	T vert2(v2 - getCenter());
	T vert3(v3 - getCenter());

	vert1.rotate(angle);  // rotate
	vert2.rotate(angle);
	vert3.rotate(angle);

	v1 = vert1 + getCenter();  // save new vectors
	v2 = vert2 + getCenter();
	v3 = vert3 + getCenter();
}

void triangle::moveBy(double x, double y) {
	T movement(x, y);

	setCenter(getCenter() + movement);
	v1 += movement;
	v2 += movement;
	v3 += movement;
}

void triangle::moveTo(double x, double y) {
	T vert1(v1 - getCenter());  // get a vertex coordinate relative to the center
	T vert2(v2 - getCenter());
	T vert3(v3 - getCenter());

	setCenter(T(x, y));
	v1 = getCenter() + vert1;
	v2 = getCenter() + vert2;
	v3 = getCenter() + vert3;
}


void triangle::print() const {
	glColor3f(red, green, blue);
	glBegin(GL_POLYGON);
	
	glVertex2f(v1.x, v1.y);
	glVertex2f(v2.x, v2.y);
	glVertex2f(v3.x, v3.y);
	
	glEnd();
}