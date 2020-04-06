#ifndef Primitiv
#define Primitiv

#include "C:\Users\Skomaroh\Desktop\LinalLegokol\Vector2D.h"

typedef Vector2D T; // you can use any vector

class DrawingObject {        //parent class for primitives 
private:
	float red = 1, green = 1, blue = 1; //colors 
	T v;				//points the center of object
	float size = 1;            
	float width = 1;
public:
	void setVector(T& V) {
		this->v.setX(V.getX());
		this->v.setY(V.getY());
	};
	void setColor(float r, float g, float b) {
		this->red = r;
		this->green = g;
		this->blue = b;
	};
	void setSize(float size) {
		this->size = size;
	};
	void setWidth(float width) {
		this->width = width;
	};
	virtual void print() override;
};
#endif // !Primitiv
