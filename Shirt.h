#ifndef SHIRT_H
#define SHIRT_H
#include <iostream>
#include <string>
using namespace std;

#include "Clothing.h"
#include "Pants.h"

class Shirt : public Clothing
{
	friend ostream& operator<<(ostream&, Shirt);
	friend istream& operator>>(istream&, Shirt&);
	private:
		string type;
	public:
		Shirt(string, string);
		Shirt();
		void setType(string);
		string getType();
		bool operator==(Pants);
};

#endif
