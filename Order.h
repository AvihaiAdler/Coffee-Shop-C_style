#ifndef __ORDER_H__
#define __ORDER_H__

#include <iostream>
#include "Product.h"
#include "Employee.h"
#include "Customer.h"

class Order {
private:
	const int SIZE_MULTIPLIER = 2;
	int numItems; 
	int itemsMaxSize; 
	Product** items;

	const Employee& employee;
	const Customer& customer;

	Order(const Order& other);
	const Order& operator=(const Order& other);
	const Order& operator=(Order&& other);
public:
	friend class Shift;
	// ctor
	Order(const Employee& employee, const Customer& customer);
	// dtor
	~Order();

	// operators
	Product& operator[](int index) noexcept(false);
	const Product& operator[](int index) const noexcept(false);
	void operator+(const Order& order);

	// getters
	int getNumItems() const { return numItems; }
	const Product*const* getItems() const { return items; }
	const Employee& getEmployee() const { return employee; }
	const Customer& getCustomer() const { return customer; }

	// functions
	bool addItem(const Product& product);
	int getTotalCalories() const;
	double getOrderTotal() const;
	friend std::ostream& operator<<(std::ostream& os, const Order& order);
};

#endif
