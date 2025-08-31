#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

class Observer {
public:
	virtual void update(std::string message) = 0;
};

class Customer : public Observer {
private:
	std::string name;
	bool isFamily;
public:
	void update(std::string message) override;
	Customer(std::string name, bool isFamily);
};

class Website : public Observer {
public:
	void update(std::string message) override;
};

#endif