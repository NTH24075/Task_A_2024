#ifndef LIST_PRODUCTS_H
#define LIST_PRODUCTS_H

#include <list>
#include "product.h"

class List_products{
private:
	list<product> li;
public:
	void read_From_Txt();
	void append();
	int edit_Infor();
	void remove_product();
	product* findByID(string ID_find);
	product* findByName(string name_find);
	void sort_Amount();
	void sort_Cost();
	void print();
	void print_To_Txt();
};
#endif 
