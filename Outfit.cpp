#include "Outfit.h"

Outfit::Outfit(int month, int day, int year, string pantsColor, string pantsStyle, string shirtColor, string shirtType):
	date(month, day, year), pants(pantsColor, pantsStyle), shirt(shirtColor, shirtType){
}

Pants Outfit::getPants(){
	return this->pants;
}
Shirt Outfit::getShirt(){
	return this->shirt;
}
Date Outfit::getDate(){
	return this->date;
}
