#include "Order.h"

Order::Order(const Employee& employee, const Customer& customer) :
	employee(employee), customer(customer)
{
	numItems = 0;
	itemsMaxSize = SIZE_MULTIPLIER;	
}

Order::Order(const Order& other) : employee(other.employee), customer(other.customer)
{
	numItems = other.numItems;
	itemsMaxSize = other.itemsMaxSize;
	items = other.items;
}

Order::~Order()
{
	delete[] items;
}

const Order& Order::operator=(const Order& other)
{
	return Order(other);
}
const Order& Order::operator=(Order&& other)
{
	return Order(other);
}

Product& Order::operator[](int index)
{
	if (index > numItems || index < 0)
		throw "Invalid index";
	else if (numItems == 0)
		throw "No products";
	return *items[index];
}

const Product& Order::operator[](int index) const
{
	if (index > numItems || index < 0)
		throw "Invalid index";
	else if (numItems == 0)
		throw "No products";
	return *items[index];
}

void Order::operator+(const Order& order)
{
	if (this != &order)
	{
		for (int i = 0; i < order.getNumItems(); i++)
			addItem(order[i]);
	}
}

bool Order::addItem(const Product& product)
{
	if (numItems == 0)
		items = new Product*[itemsMaxSize];
	if (numItems == itemsMaxSize)
	{
		itemsMaxSize *= SIZE_MULTIPLIER;
		Product** tmp = new Product*[itemsMaxSize];
		for (int i = 0; i < numItems; i++)
		{
			tmp[i] = items[i];
			items[i] = nullptr;
		}
		delete[] items;
		items = tmp;
	}
	items[numItems++] = product.clone();
	return true;

}

int Order::getTotalCalories() const
{
	int sumCalories = 0;
	for (int i = 0; i < numItems; i++)
		sumCalories += (*this)[i].getCalories();
	return sumCalories;
}

double Order::getOrderTotal() const
{
	double price = 0;
	for (int i = 0; i < numItems; i++)
		price += (*this)[i].getPrice();
	return price;
}

std::ostream& operator<<(std::ostream& os, const Order& order)
{
	os << "Order for: " << order.getCustomer().getName() << "\tCashier: " << order.getEmployee().getName() << std::endl;
	for (int i = 0; i < order.getNumItems(); i++)
		os << order[i] << std::endl;
	os << "Total price: " << order.getOrderTotal() << std::endl;
	return os;
}