#ifndef __COFFEESHOP_H__
#define __COFFEESHOP_H__

#include <iostream>
#include "Address.h"
#include "Shift.h"

class CoffeeShop {
private:
	const int SIZE_MULTIPLIER = 2;
	char* name;
	Address address;

	int numCustomers, customersMaxSize;
	Customer** customers;

	int numEmployees, employeesMaxSize;
	Employee** employees;

	int numShifts, shiftsMaxSize;
	Shift** shifts;

	int numProducts, productsMaxSize;
	Product** products;

public:
	// ctor
	CoffeeShop(const char* name, const Address& address) noexcept(false);
	// copy ctor
	CoffeeShop(const CoffeeShop& other) = delete;
	CoffeeShop(CoffeeShop&& other);
	// move ctor
	CoffeeShop(const char* name, Address&& address);
	// assignment operator
	const CoffeeShop& operator=(const CoffeeShop& other) = delete;
	// move assignment operator
	const CoffeeShop& operator=(CoffeeShop&& other) = delete;
	// dtor
	~CoffeeShop();

	// getters
	const char* getName() const { return name; }
	int getNumCustomers() const { return numCustomers; }
	int getNumEmployees() const { return numEmployees; }
	int getNumShifts() const { return numShifts; }
	int getNumProducts() const { return numProducts; }
	const Address* getAddress() const { return &address; }
	const Customer* const* getCustomers() const { return customers; }
	const Employee* const* getEmployees() const { return employees; }
	const Shift* const* getShifts() const { return shifts; }
	const Product* const* getProducts() const { return products; }

	// setters
	bool setName(const char* name);
	bool setAddress(const Address& address);

	// functions
	bool addNewEmployee(const Employee& employee);
	bool addNewEmployee(Employee&& employee);
	bool addNewProduct(const Product& product);
	bool addNewProduct(Product&& product);
	bool addNewCustomer(const Customer& customer);
	bool addNewCustomer(Customer&& customer);
	bool openShift(double clubDiscountPercent, const Date& date);
	Shift* getCurrentShift() const;
	friend std::ostream& operator<<(std::ostream& os, const CoffeeShop& coffeeShop);
};

#endif