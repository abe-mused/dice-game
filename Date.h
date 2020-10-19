#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>
using namespace std;
class Date
{
	friend ostream& operator<<(ostream&, const Date);
	private:
		int month, day, year;
	public:
		Date(int month, int day, int year);
};

#endif
