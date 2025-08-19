#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {

private:
	std::string name;
	bool isFamily;

public:
	void update(std::string message);

	Customer(std::string name, bool isFamily);
};

#endif
