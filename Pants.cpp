#include "Pants.h"

Pants::Pants(string color, string style) : Clothing(color)
{
	this->style = style;
}
Pants::Pants() : Clothing("NO COLOR")
{
	this->style = "NO STYLE";
}
void Pants::setStyle(string style){
	this->style = style;
}
string Pants::getStyle(){
	return this->style;
}
