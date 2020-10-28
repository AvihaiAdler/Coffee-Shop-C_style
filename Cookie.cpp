#include "Cookie.h"

const char* sFlourType[4] = { "White", "Whole wheat", "gluten free", "none" };

Cookie::Cookie(const char* name, int calories, double cost, double price, eFlourType flour) :
	Product(name, calories, cost, price)
{
	this->flour = flour;
}

void Cookie::toOs(std::ostream& os) const
{
	Product::toOs(os);
	os << "Flour: " << sFlourType[(int)flour] << std::endl;
}