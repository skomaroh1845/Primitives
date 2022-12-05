#pragma once

#include "Vector2D.h"

#define T Vector2D

class DrawingObject {        // parent class for primitives 
private:
	T v;  // coordinates of object center				
protected:
	float red, green, blue; // colors

public:
	virtual ~DrawingObject() = default;
	
	void setColor(float r, float g, float b);

	virtual void moveBy(double x, double y) = 0;

	virtual void moveTo(double x, double y) = 0;

	virtual void print() const = 0;

	virtual void rotate(double angle) = 0;

	virtual void animate(float speed = 1);

	void setCenter(const T& V);

	T getCenter() const;
};