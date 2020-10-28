#ifndef __PRODUCT_H__
#define __PRODUCT_H__
#include<iostream>

class Product
{
protected:
	char* name;
	int calories;
	double cost, price;
public:
	// ctor
	Product(const char* name, int calories, double cost, double price) noexcept(false);
	// copy ctor
	Product(const Product& other);
	// move ctor
	Product(Product&& other);
	// assignment operator
	virtual const Product& operator=(const Product& other);
	// move assignment operator
	virtual const Product& operator=(Product&& other);
	// dtor
	virtual ~Product();

	// operators
	bool operator==(const Product& other) const;

	// clone
	virtual Product* clone() const = 0;

	// getters
	const char* getName() const { return name; }
	int getCalories() const { return calories; }
	double getCost() const { return cost; }
	double getPrice() const { return price; }

	// setters
	bool setName(const char* name);
	bool setCalories(int calories);
	bool setCost(double cost);
	bool setPrice(double price);

	// functions
	virtual void toOs(std::ostream& os) const;
	friend std::ostream& operator<<(std::ostream& os, const Product& product);
};

#endif