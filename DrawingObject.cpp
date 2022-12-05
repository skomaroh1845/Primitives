#include "DrawingObject.h"

void DrawingObject::setColor(float r, float g, float b) {
	this->red = r;
	this->green = g;
	this->blue = b;
}

void DrawingObject::animate(float speed)
{
}

void DrawingObject::setCenter(const T& V) {
	v.x = V.x;
	v.y = V.y;
}

T DrawingObject::getCenter() const {
	return v;
}