#include "DrawingObject.h"
#include <glut.h>
 
// T = Vector2D

class rectangle:public DrawingObject {
protected:
	double sideSizeX, sideSizeY;
	T topLeft, topRight, bottomLeft, bottomRight;
	T top, left, right, bottom;
public:
	rectangle();  // init a square with the center in (0, 0) and 1 length side  
	rectangle(const T& center, double sideSizeX, double sideSizeY, float red = 1, float green = 1, float blue = 1);
	rectangle(const rectangle& P);
	
	void changeSize(double sideSizeX, double sideSizeY);
	void rotate(double angle) override;
	void moveBy(double x, double y) override;
	void moveTo(double x, double y) override;
	void print() const override;
};

class line :private DrawingObject { // vectors point the begin and the end of line
protected:
	T end1, end2; // ends of line
	float width;
public:
	line();
	line(const T& v1, const T& v2, float width = 1, float red = 1, float green = 1, float blue = 1);
	line(const line& L);

	void rotate(double angle) override;  // turn around end1
	void moveBy(double x, double y) override;
	void moveTo(double x, double y) override;  // move end1 to this coordinates
	void print() const override;
};

/*
class triangle:public DrawingObject {
private:
	bool empty = false;
	T v2, v3;
public:
	triangle();
	triangle(const T& v1, const T& v2, const T& v3);
	triangle(const T& v1, const T& v2, const T& v3, float red, float green, float blue);
	triangle(const triangle& P);
	void setV1(const T& v);
	void setV2(const T& v);
	void setV3(const T& v);
	T getV1() const;
	T getV2() const;
	T getV3() const;
	void moveUp(float x);
	void moveDown(float x);
	void moveLeft(float x);
	void moveRight(float x);
	bool getEmpty() const;
	void print() const;
	void setEmpty(bool empty); // makes the triangle empty inside
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
};  */