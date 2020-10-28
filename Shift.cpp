#include "Shift.h"

Shift::Shift(double clubDiscountPercent, const Date& shiftDate) : shiftDate(shiftDate)
{
	if (!setClubDiscountPercent(clubDiscountPercent))
		setClubDiscountPercent(0);
	numEmployees = 0;
	employeesMaxSize = SIZE_MULTIPLIER;
	dailyMenuSize = 0;
	dailyMenuMaxSize = SIZE_MULTIPLIER;
	numOrders = 0;
	ordersMaxSize = SIZE_MULTIPLIER;
}

Shift::~Shift()
{
	delete[] employees;
	delete[] dailyMenu;
	delete[] orders;
}

bool Shift::setClubDiscountPercent(double clubDiscountPercent)
{
	if (clubDiscountPercent < 0)
		return false;
	this->clubDiscountPercent = clubDiscountPercent;
	return true;
}

bool Shift::addProductToMenu(const Product& product)
{
	if (dailyMenuSize == 0)
		dailyMenu = new Product*[dailyMenuMaxSize];
	if (dailyMenuSize == dailyMenuMaxSize)
	{
		dailyMenuMaxSize *= SIZE_MULTIPLIER;
		Product** tmp = new Product*[dailyMenuMaxSize];
		for (int i = 0; i < dailyMenuSize; i++)
		{
			tmp[i] = dailyMenu[i];
			dailyMenu[i] = nullptr;
		}

		delete[] dailyMenu;
		dailyMenu = tmp;
	}
	dailyMenu[dailyMenuSize++] = product.clone();
	return true;
}

bool Shift::addEmployeeToShift(const Employee& employee)
{
	if (numEmployees == 0)
		employees = new Employee*[employeesMaxSize];
	if (numEmployees == employeesMaxSize)
	{
		employeesMaxSize *= SIZE_MULTIPLIER;
		Employee** tmp = new Employee*[employeesMaxSize];
		for (int i = 0; i < numEmployees; i++)
		{
			tmp[i] = employees[i];
			employees[i] = nullptr;
		}
		delete[] employees;
		employees = tmp;
	}
	employees[numEmployees++] = new Employee(employee.getName(), employee.getPhoneNumber(), employee.getShiftSalary(), *employee.getHireDate());
	return true;
}

bool Shift::addOrder(const Order& order)
{
	if (numOrders == 0)
		orders = new Order*[ordersMaxSize];
	if (numOrders == ordersMaxSize)
	{
		ordersMaxSize *= SIZE_MULTIPLIER;
		Order** tmp = new Order*[ordersMaxSize];
		for (int i = 0; i < numOrders; i++)
		{
			tmp[i] = orders[i];
			orders[i] = nullptr;
		}
		delete[] orders;
		orders = tmp;
	}
	orders[numOrders++] = new Order(order);
	return true;
}

const Employee* Shift::getShiftManger() const
{
	Employee* shiftManager = *employees;
	for (int i = 1; i < numEmployees; i++)
	{
		if (*shiftManager < *employees[i])
			shiftManager = employees[i];
	}
	return shiftManager;
}
double Shift::getShiftProfit() const
{
	double totalProductsCost = 0;
	double totalSales = 0;
	for (int i = 0; i < numOrders; i++)
	{
		totalSales += orders[i]->getOrderTotal();
		for (int j = 0; j < orders[i]->getNumItems(); j++)
			totalProductsCost += orders[i]->getItems()[j]->getCost();
	}
	return totalSales - totalProductsCost;
}

std::ostream& operator<<(std::ostream& os, const Shift& shift)
{
	os << "Shift at: " << *shift.getShiftDate() << "Employees on shift: " << shift.getNumEmployees() << std::endl;
	for (int i = 0; i < shift.getNumEmployees(); i++)
		os << shift.getEmployees()[i] << std::endl;
	os << "\nNumber of orders processed in shift: " << shift.getNumOrders() << "\nProfit made in the Shift: " << shift.getShiftProfit() <<
		"\nShift Manager: " << shift.getShiftManger() << std::endl;
	return os;
}