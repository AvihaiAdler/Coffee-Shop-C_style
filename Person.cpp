#pragma warning(disable : 4996)
#include "Person.h"

Person::Person(const char* name, const char* phoneNumber)
{
	if (!setName(name))
		throw "invalid name";
	if (!setPhoneNumber(phoneNumber))
	{
		delete[] name;
		throw "invalid phoneNumber";
	}		
}

Person::Person(const Person& other)
{
	*this = other;
}

Person::~Person()
{
	delete[] name;
	delete[] phoneNumber;
}

const Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		setName(other.name);
		setPhoneNumber(other.phoneNumber);
	}
	return *this;
}

const Person& Person::operator=(Person&& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->phoneNumber = other.phoneNumber;

		other.name = nullptr;
		other.phoneNumber = nullptr;
	}
	return *this;
}

bool Person::operator==(const Person& other) const
{
	if (this == &other)
		return true;
	if (strcmp(name, other.name) == 0 && strcmp(phoneNumber, other.phoneNumber) == 0)
		return true;
	return false;
}

bool Person::setName(const char* name)
{
	if (isdigit(*name))
		return false;
	int length = strlen(name) + 1;

	this->name = new char[length];
	if (strncpy(this->name, name, length) != nullptr)
		return true;
	return false;
}

bool Person::setPhoneNumber(const char* phoneNumber)
{
	if (!isdigit(*phoneNumber) || *phoneNumber != '0')
		return false;
	int length = strlen(phoneNumber) + 1;

	this->phoneNumber = new char[length];
	if (strncpy(this->phoneNumber, phoneNumber, length) != nullptr)
		return true;
	return false;
}

void Person::toOs(std::ostream& os) const
{
	os << name << "\t" << phoneNumber << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Person& person)
{
	person.toOs(os);
	return os;
}