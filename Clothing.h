#ifndef CLOTHING_H
#define CLOTHING_H
#include <iostream>
#include <string>
using namespace std;

class Clothing
{	
	private:
		string color;
	public:
		Clothing(string color);
		void setColor(string);
		string getColor();

};

#endif
