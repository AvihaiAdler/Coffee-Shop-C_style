#ifndef __SHIFT_H__
#define __SHIFT_H__

#include <iostream>
#include "date.h"
#include "order.h"

class Shift {
private:
	const int SIZE_MULTIPLIER = 2;
	double clubDiscountPercent;
	Date shiftDate;

	int numEmployees, employeesMaxSize;
	Employee** employees;

	int dailyMenuSize, dailyMenuMaxSize;
	Product** dailyMenu;

	int numOrders, ordersMaxSize;
	Order** orders;

	Employee* shiftManager;
public:
	// ctor
	Shift(double clubDiscountPercent, const Date& shiftDate);
	// copy ctor
	Shift(const Shift& other) = delete;
	// assignment operator
	const Shift& operator=(const Shift& other) = delete;
	// move assignment operator
	const Shift& operator=(Shift&& other) = delete;
	// dtor
	~Shift();

	// getters
	int getNumEmployees() const { return numEmployees; }
	int getDailyMenuSize() const { return dailyMenuSize; }
	int getNumOrders() const { return numOrders; }
	double getClubDiscountPercent() const { return clubDiscountPercent; }
	const Date* getShiftDate() const { return &shiftDate; }
	const Employee*const* getEmployees() const { return employees; }
	const Product*const* getDailyMenu() const { return dailyMenu; }
	const Order*const* getOrders() const { return orders; }

	// setters
	bool setClubDiscountPercent(double clubDiscountPercent);

	// functions
	bool addProductToMenu(const Product& product);
	bool addEmployeeToShift(const Employee& employee);
	bool addOrder(const Order& order);
	const Employee* getShiftManger() const;
	double getShiftProfit() const;
	friend std::ostream& operator<<(std::ostream& os, const Shift& shift);
};

#endif