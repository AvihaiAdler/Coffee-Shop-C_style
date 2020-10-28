#include "Coffee.h"

Coffee::Coffee(const char* name, int calories, double cost, double price, bool withMilk, int sugarSpoons) :
	Product(name, calories, cost, price)
{
	if (sugarSpoons < 0)
		throw "Spoons can't be negative";
	this->withMilk = withMilk;
	this->sugarSpoons = sugarSpoons;
}

const Coffee& Coffee::operator+=(int sugarSpoons)
{
	addSugar(sugarSpoons);
	return *this;
}

bool Coffee::addSugar(int sugarSpoons)
{
	if (sugarSpoons <= 0)
		return false;
	this->sugarSpoons += sugarSpoons;
	return true;
}

bool Coffee::setMilk(bool isWithMilk)
{
	return withMilk = isWithMilk;
}

void Coffee::toOs(std::ostream& os) const
{
	Product::toOs(os);
	os << "Milk: " << withMilk << "\tSugar: " << sugarSpoons << " spoons\n";
}