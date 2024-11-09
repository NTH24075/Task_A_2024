#include "product.h"


product::product(string id,string name,int amount,float cost){
		this->id=id;
		this->name=name;
		this->amount=amount;
		this->cost=cost;
}

string product::getID() const{
	return this->id;
}
string product::getName() const{
	return this->name;
}
int product::getAmount() const{
	return this->amount;
}
float product::getCost() const{
	return this->cost;
}
ostream& operator << (ostream& cout,product& a){
	cout<<"Thong tin hang hoa: \n";
	cout<<"ID hang: "<<a.id;
	cout<<"\nTen hang: "<<a.name;
	cout<<"\nSo luong hien tai: "<<a.amount;
	cout<<"\nGia hang hien tai: "<<a.cost<<"\n";
	return cout;
}
istream& operator >> (istream& cin,product& a){
	
	cout<<"Nhap ID hang hoa: ";
	getline(cin,a.id);
	cout<<"Nhap Ten hang hoa: ";
	getline(cin,a.name);
	cout<<"Nhap So Luong hang hoa: ";
	cin>>a.amount;
	cout<<"Nhap Gia hang hoa(don vi la trieu): ";
	cin>>a.cost;
	cin.ignore();
	return cin;
}
bool product::operator > (product other_hang){
	return this->amount >other_hang.amount;
}

