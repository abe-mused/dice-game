#include "Shirt.h"

Shirt::Shirt(string color, string type) : Clothing(color)
{
	this->type = type;
}
Shirt::Shirt() : Clothing("NO COLOR")
{
	this->type = "NO TYPE";
}
void Shirt::setType(string type){
	this->type = type;
}
string Shirt::getType(){
	return this->type;
}
bool Shirt::operator==(Pants pants){
	if(this->getColor() == pants.getColor())
	return true;
	return false;
}
