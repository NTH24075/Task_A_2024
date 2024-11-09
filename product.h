#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

using namespace std;
class product{
private:
	string id,name;
	int amount;
	float cost;
public:
	product(string id="",string name="",int amount=0,float cost=0);
	string getID() const;
	string getName() const;
	int getAmount() const;
	float getCost() const;
	friend ostream& operator << (ostream& out,product& a);
	friend istream& operator >> (istream& in,product& a);
	bool operator > (product other_hang);
};
#endif 
