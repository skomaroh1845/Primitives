#include "DrawingObject.h"
 
// T = Vector2D

class Poligon:public DrawingObject {
private:
	bool empty;
public:
	Poligon();
	Poligon(T v, float size, int n); // v points the center of object
									 // n - num of sides
	Poligon(T v, float size, int n, float red, float green, float blue);
	Poligon(const Poligon& P);
	void print();
	void setEmpty(bool empty); // makes the poligon empty inside
};

class line:public DrawingObject { // vectors point the begin and the end of line
private:
	T v2;
	bool dotted = false;
public:
	line();
	line(T v1, T v2);
	line(T v1, T v2, float width, float red, float green, float blue);
	line(const line& L);
	void setV1(const T& v);
	void setV2(const T& v);
	T getV1() const;
	T getV2() const;
	bool getDotted() const;
	void print() const;
	void setDotted(bool dotted); // makes the line dotted
};

class circle:public DrawingObject {
private:
	bool dotted;
	bool empty;
public:
	circle();
	circle(T v, float size); // size = radius; v points the center of object
	circle(T v, float size, float red, float green, float blue);
	circle(circle& C);
	void print();
	void print(float angle); // you can choose how many parts of a circle to draw
							 // the angle is counted from the x axis
	void setDotted(bool dotted); // makes the circle dotted
	void setEmpty(bool empty); // makes the circle empty inside
};

class conabis:public DrawingObject {
private:
public:
	conabis();
	conabis(T v, float size);
	conabis(T v, float size, float red, float green, float blue);
	conabis(circle& C);
	void print();
};

class explosion {
private:
public:
	explosion();
	explosion(T v);
	explosion(T v, float size);
	explosion(explosion& E);
	void print();
};