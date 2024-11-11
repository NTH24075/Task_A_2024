#include "list_products.h"

#include <fstream>

void List_products::read_From_Txt(){
	ifstream fileIn;
	fileIn.open("./data_input.txt",ios::in);
	if(fileIn.is_open()){
		int num;
		fileIn>>num;
		while(num--){
			string id_a,name_a;
			int amount_a;
			float cost_a;
			fileIn.ignore();
			getline(fileIn,id_a);
			getline(fileIn,name_a);
			fileIn>>amount_a;
			fileIn>>cost_a;
			product a(id_a,name_a,amount_a,cost_a);
			li.push_back(a);
		}
		cout<<"Success !!!";
	}
	else {
		cout<<"Khong mo duoc file!";
	}
	fileIn.close();
}

void List_products::append(){
	product a;
	cin>>a;
	li.push_back(a);
}
product* List_products::findByID(string ID_find){
	for ( auto& prod : li) {
            if(prod.getID()==ID_find){
 				return &prod;            	
            }
        }
    return NULL;
}

product* List_products::findByName(string name_find){
	
	for ( auto& prod : li) {
            if(prod.getName()==name_find){
 				return &prod;            	
            }
        }
    return NULL;
}
void List_products::remove_product(){
	cout<<"Tim san pham can xoa bang ID hoac ten: ";
	cout<<"\n1Tim bang ID san pham?\n2 Tim bang ten san pham?\n0 Quay lai.";
	cout<<"\nLua chon cua ban la: ";
	int option;
	product* found;
	while(1){
		cin>>option;
		cin.ignore();
		if(option==1){
			string id;
			cout<<"Nhap ID can tim:";
			getline(cin,id);
			found=findByID(id);
			break;
		}
		else if(option==2){
			string name;
			cout<<"Nhap Ten can tim: ";
			getline(cin,name);
			found=findByName(name);
			break;
		}
		else if(option==0){
			cout<<"Ban da thoat chuong trinh tim kiem!\n";
			return ;
		}
		else{
			cout<<"Lua chon khong hop le!"
			<<"\nMoi ban chon lai: ";
		}
	}
	if(found==NULL){
		cout<<"Khong tim thay san pham trong kho!\n";
	}
	else {
		cout<<*(found);
	    auto it = li.begin();
	    while (1) {
	        if (&(*it) == found) {
	            it = li.erase(it); 
	            break;
	        } else {
	            ++it;
	        }
	    }
	    cout << "Xoa thanh cong!!\n";
	}
}
int List_products::edit_Infor(){
	cout<<"Tim san pham can sua bang Ma hoac Ten: ";
	cout<<"\n1 Tim bang ID san pham?\n2 Tim bang ten san pham?\n0 Quay lai.";
	cout<<"\nLua chon cua ban la: ";
	int option;
	product* found;
	while(1){
		cin>>option;
		cin.ignore();
		if(option==1){
			string id;
			cout<<"Nhap ID can tim:";
			getline(cin,id);
			found=findByID(id);
			break;
		}
		else if(option==2){
			string name;
			cout<<"Nhap Ten can tim: ";
			getline(cin,name);
			found=findByName(name);
			break;
		}
		else if(option==0){
			cout<<"Ban da thoat chuong trinh tim kiem!\n";
			return 0;
		}
		else{
			cout<<"Lua chon khong hop le!"
			<<"\nMoi ban chon lai: ";
		}
	}
	if(found==NULL){
		cout<<"Khong tim thay san pham trong kho!";
		cout<<"\nBan muon them san pham vao danh sach?(Y/N)";
		char option_2;
		cin>>option_2;
		if(option_2=='Y' || option_2=='y'){
			cin.ignore();
			cout<<"Thong tin san pham can them:\n";
			append();
			cout<<"Success!! Them san pham thanh cong\n";
		}
		else{
			cout<<"Khong them san pham.";
			return 0;
		}
	}
	else {
		cout<<*(found);
		product fixed;
	    cout << "\nThong tin moi cua san pham:\n";
	    cin >> fixed;
	    auto it = li.begin();
	    while (1) {
	        if (&(*it) == found) {
	            it = li.erase(it); 
	            break;
	        } else {
	            ++it;
	        }
	    }
	    li.insert(it, fixed);
	    cout << "Success!!\n";
	}
}
void List_products::sort_Amount(){
	cout<<"\nBan muon sap xep theo: "
	<<"\n1 So luong Hang giam dan \n2 So luong Hang tang dan";
	int option;
	while(1){
		cout<<"\nLua chon cua ban la: ";
		cin>>option;
		if(option==1){
		    li.sort([]( product &a,  product &b){
		        return a > b;
		    });
		    break;
			}
		else if(option==2){
			li.sort([]( product &a,  product &b){
		        return b > a;
		    });
		    break;
		}
		else{
			cout<<"\nLua chon khong hop le!";
		}
	}
}
void List_products::sort_Cost(){
	cout<<"\nBan muon sap xep theo: "
	<<"\n1 Tong Gia tri cua Ma hang hoa giam dan."
	<<"\n2 Tong Gia tri cua Ma hang hoa tang dan."
	<<"\n3 Gia tri rieng cua tung san pham giam dan."
	<<"\n4 Gia tri rieng cua tung san pham tang dan.";
	int option;
	while(1){
		cout<<"\nLua chon cua ban la: ";
		cin>>option;
		if(option==1){
			li.sort([](const product &a,const  product &b){
        	return a.getCost()*a.getAmount() > b.getCost()*b.getAmount();
    		});
    		break;
		}
		else if(option==2){
			li.sort([](const product &a,const  product &b){
        	return a.getCost()*a.getAmount() < b.getCost()*b.getAmount();
    		});
    		break;
		}
		else if(option==3){
			li.sort([](const product &a,const  product &b){
        	return a.getCost() > b.getCost();
    		});
    		break;
		}
		else if(option==4){
			li.sort([](const product &a,const  product &b){
        	return a.getCost() < b.getCost();
    		});
    		break;
		}
		else{
			cout<<"\nLua chon khong hop le!";
		}
	}
}
void List_products::print(){
	for ( auto prod : li) {
            cout << "ID: " << prod.getID() << "\n"
           	<< "Ten: " << prod.getName() << "\n"
            << "So luong: " << prod.getAmount() << "\n"
            << "Gia: " << prod.getCost() << "\n"
            << "-------------------------\n";
        }
}
void List_products::print_To_Txt(){
	ofstream fileOut;
	string file;
	//cin.ignore();
	cout<<"File in Thong tin: ";
	getline(cin,file);
	fileOut.open(file,ios::out);
	if(fileOut.is_open()){
		for ( auto prod : li) {
            fileOut << "ID: " << prod.getID() << "\n";
            fileOut << "Ten: " << prod.getName() << "\n";
            fileOut << "So luong: " << prod.getAmount() << "\n";
            fileOut << "Gia: " << prod.getCost() << "\n";
            fileOut << "-------------------------\n";
        }
        fileOut.close();
	}
}
