#include "Employee.h"

Employee::Employee(const char* name, const char* phoneNumber, double shiftSalary, const Date& hireDate) :
	Person(name, phoneNumber), hireDate(hireDate)
{
	if (!setShiftSalary(shiftSalary))
		throw "Invalid salary";
}

Employee::Employee(const Employee& other) : Person(other), hireDate(*other.getHireDate())
{
	*this = other;
}

const Employee& Employee::operator=(const Employee& other)
{
	if (this != &other)
	{
		Person::operator=(other);
		hireDate = other.hireDate;
		shiftSalary = other.shiftSalary;
	}
	return *this;
}

const Employee& Employee::operator=(Employee&& other)
{
	if (this != &other)
	{
		Person::operator=(other);
		hireDate = other.hireDate;
		shiftSalary = other.shiftSalary;
	}
	return *this;
}

bool Employee::operator<(const Employee& other) const
{
	return getSeniority() < other.getSeniority();
}

bool Employee::operator>(const Employee& other) const
{
	return getSeniority() > other.getSeniority();
}

bool Employee::operator==(const Employee& other) const
{

	if (!Person::operator==(other))
		return false;
	return getSeniority() == other.getSeniority();
}

bool Employee::setShiftSalary(double shiftSalary)
{
	if (shiftSalary <= 0)
		return false;
	else if(shiftSalary < MINIMUN_WAGE_PER_HOUR * 8)
	{
		this->shiftSalary = MINIMUN_WAGE_PER_HOUR * 8;
		return true;
	}
	else
	{
		this->shiftSalary = shiftSalary;
		return true;
	}
}

inline int Employee::getSeniority() const
{
	return (hireDate.getCurrentYear() - hireDate.getYear());
}

void Employee::toOs(std::ostream& os) const
{
	Person::toOs(os);
	os << "Hire date:\t" << hireDate << "Seniority:\t" << getSeniority() << " years" << std::endl;
}