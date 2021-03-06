#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include "Person.h"
#include "Date.h"

class Employee : public Person {
private:
	const int MINIMUN_WAGE_PER_HOUR = 25;
	double shiftSalary;
	Date hireDate;

	Employee(const Employee& other);

	const Employee& operator=(const Employee& other);
	const Employee& operator=(Employee&& other);

public:
	friend class CoffeeShop;
	// ctor
	Employee(const char* name, const char* phoneNumber, double shiftSalary, const Date& hireDate) noexcept(false);

	// operators
	bool operator<(const Employee& other) const;
	bool operator>(const Employee& other) const;
	virtual bool operator==(const Employee& other) const;

	// getters
	double getShiftSalary() const { return shiftSalary; }
	const Date* getHireDate() const { return &hireDate; }

	// setters
	bool setShiftSalary(double shiftSalary);

	// functions
	int getSeniority() const;
	void toOs(std::ostream& os) const override;
};

#endif