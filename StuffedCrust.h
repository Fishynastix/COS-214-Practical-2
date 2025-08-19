#ifndef STUFFEDCRUST_H
#define STUFFEDCRUST_H

#include "Pizza.h"
#include <string>

class StuffedCrust {


public:
	double getPrice();

	std::string getName();

	StuffedCrust(Pizza pizza);
};

#endif
