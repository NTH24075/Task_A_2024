#include "product_app.h"
void product_app::menu(){
	cout<<"\n\n*----------------------------------------------*"
	<<"\n|1.Nhan thong tin tu file."
	<<"\n|2.Them Hang hoa vao kho."
	<<"\n|3.Sua thong tin cua hang hoa."
	<<"\n|4.Xoa 1 san pham ra khoi kho."
	<<"\n|5.Tim kiem Hang hoa bang Ma hang hoa."
	<<"\n|6.Tim kiem Hang hoa bang Ten hang hoa."
	<<"\n|7.Sap xep danh sach hang hoa theo So luong hang."
	<<"\n|8.Sap xep danh sach hang hoa theo Gia hang hoa."
	<<"\n|9.In danh sach ra man hinh."
	<<"\n|10.In danh sach ra file."
	<<"\n|0.Thoat chuong trinh"
	<<"\n*----------------------------------------------*"
	<<"\nLua chon cua ban la: ";	
}
void product_app::run(){
	int option;
	while(1){
		menu();
		cin>>option;
		if(option==1){
			products_app.read_From_Txt();
		}
		else if(option==2){
			cin.ignore();
			cout<<"\nThong tin Hang can them:\n";
			products_app.append();
			cout<<"Success !!!";
		}
		else if(option==3){
			products_app.edit_Infor();
		}
		else if(option==4){
			products_app.remove_product();
		}
		else if(option==5){
			cin.ignore();
			cout<<"\nNhap ma hang hoa can tim: ";
			string s;
			getline(cin,s);
			product* prd=products_app.findByID(s);
			if(prd==NULL) cout<<"\nKhong tim thay san pham!!\n";
			else cout<<*prd;
		}
		else if(option==6){
			cin.ignore();
			cout<<"\nNhap ten hang hoa can tim: ";
			string s;
			getline(cin,s);
			product* prd=products_app.findByName(s);
			if(prd==NULL) cout<<"\nKhong tim thay san pham!!\n";
			else cout<<*prd;
		}
		else if(option==7){
			products_app.sort_Amount();
			cout<<"\nDanh sach sau khi duoc sap xep:\n";
			products_app.print();
		}
		else if(option==8){
			products_app.sort_Cost();
			cout<<"\nDanh sach sau khi duoc sap xep:\n";
			products_app.print();
		}
		else if(option==9){
			cout<<"\nDanh sach san pham trong kho:\n";
			products_app.print();
		}
		else if(option==10){
			cin.ignore();
			products_app.print_To_Txt();
		}
		else if(option==0){
			cout<<"Thank for using !!!";
			break;
		}
		
		else {
			cout<<"\nLua chon khong hop le!!";
		}
	}
}
