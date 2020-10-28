#pragma warning(disable : 4996)
#include "CoffeeShop.h"

CoffeeShop::CoffeeShop(const char* name, const Address& address) : address(address)
{
	if (!setName(name))
		throw "Error coping coffeshop name";
	numCustomers = 0;
	customersMaxSize = SIZE_MULTIPLIER;
	numEmployees = 0;
	employeesMaxSize = SIZE_MULTIPLIER;
	numShifts = shiftsMaxSize = 3;
	numProducts = 0;
	productsMaxSize = SIZE_MULTIPLIER;
}

CoffeeShop::CoffeeShop(CoffeeShop&& other) : address(std::move(other.address))
{
	if (this != &other)
	{
		numCustomers = other.numCustomers;
		customersMaxSize = other.customersMaxSize;
		numEmployees = other.numEmployees;
		employeesMaxSize = other.employeesMaxSize;
		numShifts = other.numShifts;
		shiftsMaxSize = other.shiftsMaxSize;
		numProducts = other.numProducts;
		productsMaxSize = other.productsMaxSize;

		name = other.name;
		customers = other.customers;
		employees = other.employees;
		products = other.products;
		shifts = other.shifts;
		other.shifts = nullptr;
		other.products = nullptr;
		other.employees = nullptr;
		other.customers = nullptr;
		other.name = nullptr;
	}
}

CoffeeShop::CoffeeShop(const char* name, Address&& address) : address(std::move(address))
{
	setName(name);
	numCustomers = 0;
	customersMaxSize = SIZE_MULTIPLIER;
	numEmployees = 0;
	employeesMaxSize = SIZE_MULTIPLIER;
	numShifts = shiftsMaxSize = 3;
	numProducts = 0;
	productsMaxSize = SIZE_MULTIPLIER;
}

CoffeeShop::~CoffeeShop()
{
	delete[] name;
	delete[] customers;
	delete[] employees;
	delete[] shifts;
	delete[] products;
}

// setters
bool CoffeeShop::setName(const char* name)
{
	int length = strlen(name) + 1;
	this->name = new char[length];

	if (strncpy(this->name, name, length) != nullptr)
		return true;
	return false;
}

bool CoffeeShop::setAddress(const Address& address)
{
	if (&this->address == &address)
		return false;

	this->address = address;
	return true;
}

bool CoffeeShop::addNewEmployee(const Employee& employee)
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

bool CoffeeShop::addNewEmployee(Employee&& employee)
{
	Employee tmp = Employee(employee.getName(), employee.getPhoneNumber(), employee.getShiftSalary(), *employee.getHireDate());
	return addNewEmployee(tmp);
}

bool CoffeeShop::addNewProduct(const Product& product)
{
	if (numProducts == 0)
		products = new Product*[productsMaxSize];
	if (numProducts == productsMaxSize)
	{
		productsMaxSize *= SIZE_MULTIPLIER;
		Product** tmp = new Product*[productsMaxSize];
		for (int i = 0; i < numProducts; i++)
		{
			tmp[i] = products[i];
			products[i] = nullptr;
		}
		delete[] products;
		products = tmp;
	}
	products[numProducts++] = product.clone();
	return true;
}

bool CoffeeShop::addNewProduct(Product&& product)
{
	if (numProducts == 0)
		products = new Product*[productsMaxSize];
	if (numProducts == productsMaxSize)
	{
		productsMaxSize *= SIZE_MULTIPLIER;
		Product** tmp = new Product*[productsMaxSize];
		for (int i = 0; i < numProducts; i++)
		{
			tmp[i] = products[i];
			products[i] = nullptr;
		}
		delete[] products;
		products = tmp;
	}
	products[numProducts++] = product.clone();
	return true;
}

bool CoffeeShop::addNewCustomer(const Customer& customer)
{
	if (numCustomers == 0)
		customers = new Customer*[customersMaxSize];
	if (numCustomers == customersMaxSize)
	{
		customersMaxSize *= SIZE_MULTIPLIER;
		Customer** tmp = new Customer*[customersMaxSize];
		for (int i = 0; i < numCustomers; i++)
		{
			tmp[i] = customers[i];
			customers[i] = nullptr;
		}
		delete[] customers;
		customers = tmp;
	}
	customers[customersMaxSize++] = new Customer(customer.getName(), customer.getPhoneNumber(), customer.isClubMember());
	return true;
}

bool CoffeeShop::addNewCustomer(Customer&& customer)
{
	Customer tmp = Customer(customer.getName(), customer.getPhoneNumber(), customer.isClubMember());
	return addNewCustomer(tmp);
}

bool CoffeeShop::openShift(double clubDiscountPercent, const Date& date)
{
	if (numShifts == 0)
		shifts = new Shift*[SIZE_MULTIPLIER];
	if (numShifts == shiftsMaxSize)
	{
		shiftsMaxSize *= SIZE_MULTIPLIER;
		Shift** tmp = new Shift*[shiftsMaxSize];
		for (int i = 0; i < numShifts; i++)
		{
			tmp[i] = shifts[i];
			shifts[i] = nullptr;
		}
		delete[] shifts;
		shifts = tmp;
	}
	shifts[numShifts++] = new Shift(clubDiscountPercent, date);
	return true;
}

Shift* CoffeeShop::getCurrentShift() const
{
	return shifts[numShifts - 1];
}

std::ostream& operator<<(std::ostream& os, const CoffeeShop& coffeeShop)
{
	os << "Coffee Shop: " << coffeeShop.name << "\nNumber of employees: " << coffeeShop.getNumEmployees() <<
		"\nShifts: " << coffeeShop.getNumShifts() << std::endl;
	
	if (coffeeShop.shifts != nullptr)
	{
		for (int i = 0; i < coffeeShop.getNumShifts(); i++)
			os << coffeeShop.getShifts()[i] << std::endl;
	}
		
	
	if (coffeeShop.products != nullptr)
	{
		os << "Products list:\n";
		for (int i = 0; i < coffeeShop.getNumProducts(); i++)
			os << *coffeeShop.getProducts()[i] << std::endl;
	}
	
	return os;
}