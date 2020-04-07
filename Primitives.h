#include "DrawingObject.h"
 
// T = Vector2D

class Poligon:public DrawingObject {
private:
	bool empty = false;
	unsigned int n = 3;
public:
	Poligon();
	Poligon(const T& v, float size, unsigned int n); // v points the center of object
													 // n - num of sides
	Poligon(const T& v, float size, unsigned int n, float red, float green, float blue);
	Poligon(const Poligon& P);
	unsigned int getSides() const; //get num of sides
	bool getEmpty() const; // get type of poligon
	void print() const;
	void setEmpty(bool empty); // makes the poligon empty inside
};

class line:public DrawingObject { // vectors point the begin and the end of line
private:
	T v2;
	bool dotted = false;
public:
	line();
	line(const T& v1, const T& v2);
	line(const T& v1, const T& v2, float width, float red, float green, float blue);
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
	bool dotted = false;
	bool empty = true;
public:
	circle();
	circle(const T& v, float R); // v points the center of object
	circle(const T& v, float R, float red, float green, float blue);
	circle(const circle& C);
	void print() const;
	void print(float angle) const; // you can choose how many parts of a circle to draw
								   // the angle is counted from the x axis
	void print(float angle1, float angle2) const;
	bool getDotted() const;		 // actual for empty circle
	void setDotted(bool dotted); // makes the circle dotted
	bool getEmpty() const;
	void setEmpty(bool empty); // makes the circle empty inside
};

class leaf:public DrawingObject {
private:
	bool empty = false;
public:
	leaf();
	leaf(const T& v, float size);
	leaf(const T& v, float size, float red, float green, float blue);
	leaf(const leaf& F);
	void print() const;
	bool getEmpty() const;
	void setEmpty(bool empty);
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