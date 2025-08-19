#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {

private:
	string name;
	boolean isFamily;

public:
	void update(string message);

	Customer(string name, boolean isFamily);
};

#endif
