#include "Primitives.h"

line::line() : line(T(0, 0), T(1, 0)) {}  // unit lenght line along x axis 

line::line(const line& L) : 
		line(L.end1, L.end2, L.width, L.red, L.green, L.blue) {}

line::line(const T& v1, const T& v2, float width, float red, float green, float blue): 
		width(width), end1(v1), end2(v2) {
	this->setColor(red, green, blue);
}

void line::rotate(double angle) {
	T relative_end2(end2 - end1);
	relative_end2.rotate(angle);
	end2 = relative_end2 + end1;
}

void line::moveBy(double x, double y) {
	end1 += T(x, y);
	end2 += T(x, y);
}

void line::moveTo(double x, double y) {
	end2 = T(x, y) + T(end2 - end1);
	end1 = T(x, y);
}

void line::print() const {
	glColor3f(red, green, blue);
	glLineWidth(width);
	glBegin(GL_LINES);
	
	glVertex2f(end1.x, end1.y);
	glVertex2f(end2.x, end2.y);
	
	glEnd();
}