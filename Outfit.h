#ifndef OUTFIT_H
#define OUTFIT_H

#include "Pants.h"
#include "Shirt.h"
#include "Date.h"
class Outfit
{
	friend ostream& operator<<(ostream&, Outfit);
	private:
		Shirt shirt;
		Pants pants;
		Date date;
	public:
		Outfit(int month, int day, int year, string pantsColor, string pantsStyle, string shirtColor, string shirtType);
		Pants getPants();
		Shirt getShirt();
		Date getDate();
};

#endif
