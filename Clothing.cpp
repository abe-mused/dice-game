#include "Clothing.h"

Clothing::Clothing(string color)
{
	this->color = color;
}
void Clothing::setColor(string color){
	this->color = color;
}
string Clothing::getColor(){
	return this->color;
}
