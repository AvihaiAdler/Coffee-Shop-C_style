#pragma warning(disable : 4996)
#include "Address.h"

Address::Address(const char* city, const char* streetName, int streetNumber)
{
	if (!setCity(city))
		setCity("Unknown");
	if (!setStreet(streetName))
		setStreet("Unknown");
	this->streetNumber = streetNumber;
}

Address::Address(const Address& other)
{
	*this = other;
}

Address::Address(Address&& other)
{
	*this = other;
}

Address::~Address()
{
	delete[] city;
	delete[] streetName;
}

const Address& Address::operator=(const Address& other)
{
	if (this != &other)
	{
		if (!setCity(other.city))
			setCity("Unknown");
		if (!setStreet(other.streetName))
			setStreet("Unknown");
		this->streetNumber = other.streetNumber;
	}
	return *this;
}

const Address& Address::operator=(Address&& other)
{
	if (this != &other)
	{
		city = other.city;
		streetName = other.streetName;
		streetNumber = other.streetNumber;

		other.city = nullptr;
		other.streetName = nullptr;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Address& address)
{
	os << "Address: " << address.city << "\t" << address.streetName << "\t" << address.streetNumber << std::endl;
	return os;
}

bool Address::setCity(const char* city)
{
	int length = strlen(city) + 1;

	this->city = new char[length];
	if (strncpy(this->city, city, length) != nullptr)
		return true;
	return false;
}

bool Address::setStreet(const char* streetName)
{
	int length = strlen(streetName) + 1;

	this->streetName = new char[length];
	if (strncpy(this->streetName, streetName, length) != nullptr)
		return true;
	return false;
}
