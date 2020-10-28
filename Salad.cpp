#include "Salad.h"

const char* sDressingType[4] = { "vinigert", "soy", "thousand island", "none" };

Salad::Salad(const char* name, int calories, double cost, double price, eDressingType dressing) : Product(name, calories, cost, price)
{
	this->dressing = dressing;
}

bool Salad::addDressing(Salad::eDressingType dressing)
{
	if (dressing != Salad::eDressingType::enumTypeEnd)
		return false;
	this->dressing = dressing;
	return true;
}

void Salad::toOs(std::ostream& os) const
{
	Product::toOs(os);
	os << "Dressing: " << sDressingType[(int)dressing] << std::endl;
}

