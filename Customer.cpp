#include "Customer.h"

Customer::Customer(const char* name, const char* phoneNumber, bool clubMember) :
	Person(name, phoneNumber)
{
	setClubMember(clubMember);
}

Customer::Customer(const Customer& other) : Person(other)
{
	*this = other;
}

const Customer& Customer::operator=(const Customer& other)
{
	if (this != &other)
	{
		Person::operator=(other);
		clubMember = other.clubMember;
	}
	return *this;
}

const Customer& Customer::operator=(Customer&& other)
{
	if (this != &other)
	{
		Person::operator=(other);
		clubMember = other.clubMember;
	}
	return *this;
}

void Customer::setClubMember(bool clubMember)
{
	this->clubMember = clubMember;
}

void Customer::toOs(std::ostream& os) const
{
	Person::toOs(os);
	os << "Club member:\t" << isClubMember() << std::endl;
}