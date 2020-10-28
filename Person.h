#ifndef __PERSON_H__
#define __PERSON_H__

#include <iostream>

class Person {
protected:
	char *name, *phoneNumber;

	Person(const Person& other);
	const Person& operator=(const Person& other);
	const Person& operator=(Person&& other);

public:
	// ctor
	Person(const char* name, const char* phoneNumber) noexcept(false);

	// dtor
	virtual ~Person();

	// operators
	virtual bool operator==(const Person& other) const;

	// getters
	const char* getName() const { return name; }
	const char* getPhoneNumber() const { return phoneNumber; }

	// setters
	bool setName(const char* name);
	bool setPhoneNumber(const char* phoneNumber);

	// functions
	virtual void toOs(std::ostream& os) const = 0;
	friend std::ostream& operator<<(std::ostream& os, const Person& person);
};

#endif
