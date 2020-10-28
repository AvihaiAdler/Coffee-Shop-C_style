#pragma warning(disable : 4996)
#include<string.h>
#include "Product.h"

Product::Product(const char* name, int calories, double cost, double price)
{
	if (!setName(name))
		throw "Invalid Product name";

	if (!setCalories(calories))
	{
		delete[] name;
		throw "Invalid calories value";
	}
			
	if (!setCost(cost))
	{
		delete[] name;
		throw "cost must be higher than 0";
	}
		
	if (!setPrice(price))
	{
		delete[] name;
		throw "Price must be higher than 0";
	}
		

	
}

Product::Product(const Product& other)
{
	*this = other;
}

Product::Product(Product&& other)
{
	this->name = other.name;
	other.name = nullptr;
	delete other.name;

	setCalories(other.calories);
	setCost(other.cost);
	setPrice(other.price);
}

Product::~Product()
{
	delete[]name;
}

const Product& Product::operator=(const Product& other)
{
	if (this != &other)
	{
		setName(other.name);
		setCalories(other.calories);
		setCost(other.cost);
		setPrice(other.price);
	}
	return *this;
}

const Product& Product::operator=(Product&& other)
{
	this->name = other.name;
	other.name = nullptr;
	delete other.name;

	setCalories(other.calories);
	setCost(other.cost);
	setPrice(other.price);
	return *this;
}

bool Product::operator==(const Product& other) const
{
	if (strncmp(this->name, other.name, strlen(this->name)) == 0)
		return calories == other.calories && cost == other.cost && price == other.price;
	return false;
}

bool Product::setName(const char* name)
{
	if (isdigit(*name))
		return false;
	int length = strlen(name) + 1;

	this->name = new char[length];
	if (strncpy(this->name, name, length) != nullptr)
		return true;
	return false;
}

bool Product::setCalories(int calories)
{
	if (calories < 0)
		return false;
	this->calories = calories;
	return true;
}

bool Product::setCost(double cost)
{
	if (cost <= 0)
		return false;
	this->cost = cost;
	return true;
}

bool Product::setPrice(double price)
{
	if (price <= 0)
		return false;
	this->price = price;
	return true;
}

void Product::toOs(std::ostream& os) const
{
	os << "Product name: " << name << "\nCalories: " << calories << "\tCost: " << cost << "\tPrice: " << price << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Product& product)
{
	product.toOs(os);
	return os;
}
