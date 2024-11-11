#ifndef PRODUCT_APP_H
#define PRODUCT_APP_H

#include "list_products.h"
#include "list_products.cpp"
class product_app{
private:
	List_products products_app;
public:
	void menu();
	void run();
};
#endif 
