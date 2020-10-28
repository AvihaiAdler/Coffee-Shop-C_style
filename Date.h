#ifndef __DATE_H__
#define __DATE_H__

#include <iostream>

class Date {
private:
	const static int CURRENT_YEAR;
	int day, month, year;
public:
	// ctor
	Date(int day, int month, int year);
	Date(const Date& other);
	const Date& operator=(const Date& other);

	// getters
	int getDay() const { return day; }
	int getMonth() const { return month; }
	int getYear() const { return year; }
	int getCurrentYear() const { return CURRENT_YEAR; }

	// functions
	friend std::ostream& operator<<(std::ostream& os, const Date& date);
};

#endif