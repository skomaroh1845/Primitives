#define _USE_MATH_DEFINES

#include "Primitives.h"
#include <cmath>
#include <glut.h>

circle::circle() : circle(T(0, 0)) {};

circle::circle(const circle& C): 
			circle(C.getCenter(), C.R, C.red, C.green, C.blue) {
	this->isFull = C.isFull;
	this->angle1 = C.angle1;
	this->angle2 = C.angle2;
};

circle::circle(const T& center, float R, float red, float green, float blue): 
			R(R), isFull(true), angle1(0), angle2(0) 
{
	this->setCenter(center);
	this->setColor(red, green, blue);
}

void circle::rotate(double angle) {
	if (isFull) return;
	angle1 += angle;
	angle2 += angle;
}

void circle::moveBy(double x, double y) {
	setCenter( getCenter() + T(x, y) );
}

void circle::moveTo(double x, double y) {
	setCenter(T(x, y));
}

void circle::setSector(double angle1, double angle2) {
	this->angle1 = angle1;
	this->angle2 = angle2;
	isFull = false;
}

void circle::print() const {
	if (isFull)
	{
		glColor3f(red, green, blue);
		glBegin(GL_TRIANGLE_FAN);
		for (double a = 0; a < 2 * M_PI; a += 0.4)
		{
			glVertex2d(getCenter().x + R * cos(a), getCenter().y + R * sin(a));
		}
		glEnd();
	}
	else print(angle1, angle2);
}

void circle::print(double angle, double angle2) const {
	using std::max;
	using std::min;
	angle = angle * M_PI / 180.0;
	angle2 = angle2 * M_PI / 180.0;
	glColor3f(red, green, blue);
	glBegin(GL_TRIANGLE_FAN);
	
	glVertex2f( getCenter().x, getCenter().y );
	
	for (double a = min(angle, angle2); a < max(angle, angle2) - 0.1; a += 0.1)
		glVertex2d( getCenter().x + R*cos(a), getCenter().y + R*sin(a) );
	
	glVertex2d( getCenter().x + R*cos(angle2), getCenter().y + R*sin(angle2) );
	
	glEnd();
}