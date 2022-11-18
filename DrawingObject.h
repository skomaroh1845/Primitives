#ifndef Primitiv_DrawingObject
#define Primitiv_DrawingObject

#include "Vector2D.h"

#define T Vector2D

class DrawingObject {        // parent class for primitives 
private:
	T v;  // coordinates of object center				

protected:
	float red, green, blue; // colors

public:
	void setColor(float r, float g, float b) {
		this->red = r;
		this->green = g;
		this->blue = b;
	}

	virtual void moveBy(double x, double y) = 0;

	virtual void moveTo(double x, double y) = 0;

	virtual void print() const = 0;

	virtual void rotate(double angle) = 0;

	void setCenter(const T& V) {
		v.x = V.x;
		v.y = V.y;
	}

	T getCenter() const {
		return v;
	}
};
#endif // !Primitiv_DrawingObject
