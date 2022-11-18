#define _USE_MATH_DEFINES

#include "Primitives.h"
#include <cmath>
#include <glut.h>

leaf::leaf() : leaf(T(0, 0)) {}

leaf::leaf(const leaf& F): 
			leaf(F.getCenter(), F.size, F.red, F.green, F.blue) {}

leaf::leaf(const T& v, double size, float red, float green, float blue): size(size) {
	this->setColor(red, green, blue);
	this->setCenter(v);
};

void leaf::rotate(double angle) {
	this->angle += angle;
	if (this->angle > 360) this->angle -= 360;
}

void leaf::moveBy(double x, double y) {
	setCenter(getCenter() + T(x, y));
}

void leaf::moveTo(double x, double y) {
	setCenter(T(x, y));
}

void leaf::print() const {
	glColor3f(red, green, blue);
	glBegin(GL_TRIANGLE_FAN);
	
	glVertex2f(getCenter().x, getCenter().y);
	for (float a = 0; a < 2 * M_PI + 0.2; a += 0.11)
	{
		float r = size * 0.2 * (1 + sin(a)) * (1 + 0.9 * cos(8 * a)) * (1 + 0.1 * cos(24 * a));
		//     general size  size of bottom parts    shape of leaf           shape of segments 
		T v(r * cos(a), r * sin(a));
		v.rotate(angle);
		glVertex2f( getCenter().x + v.x, getCenter().y + v.y );
	}
	
	glEnd();
};