#ifndef PANTS_H
#define PANTS_H
#include <iostream>
#include <string>
using namespace std;

#include "Clothing.h"

class Pants : public Clothing
{
	friend ostream& operator<<(ostream&, Pants);
	friend istream& operator>>(istream&, Pants&);
	private:
		string style;
	public:
		Pants(string color, string style);
		Pants();
		void setStyle(string);
		string getStyle();
};

#endif
