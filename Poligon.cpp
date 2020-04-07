#include "Primitives.h"
#include <glut.h>

Poligon::Poligon() {};

Poligon::Poligon(const T& v, float size, unsigned int n) {
	this->setVector(v);
	this->setSize(size);
	this->n = n;
};

Poligon::Poligon(const T& v, float size, unsigned int n, float red, float green, float blue) {
	this->setVector(v);
	this->setSize(size);
	this->n = n;
	this->setColor(red, green, blue);
};

unsigned int Poligon::getSides() const {
	return this->n;
};

bool Poligon::getEmpty() const {
	return this->empty;
};

Poligon::Poligon(const Poligon& P) {
	float r, g, b;
	P.getColor(r, g, b);
	this->setColor(r, g, b);
	this->n = P.getSides();
	this->empty = P.getEmpty();
	this->setVector(P.getVector());
	this->setSize(P.getSize());
};

void Poligon::setEmpty(bool empty) {
	this->empty = empty;
};

void Poligon::print() const {
	float r, g, b;
	this->getColor(r, g, b);
	glColor3f(r, g, b);
	if (!this->empty) {
		glBegin(GL_POLYGON);
		
		glEnd();
	}
	else {
		glLineWidth(this->getWidth());
		glBegin(GL_LINE_LOOP);

		glEnd();
	}	
};