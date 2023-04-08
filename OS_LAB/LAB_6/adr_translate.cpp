//This program is implemented by Tanishq Agarwal (211B326)

#include <iostream>

using namespace std;

bool validCheck(int bs,int v,int bnd){
int temp= bs+v;
if (temp<=bnd){
	return true;
}

else{
	return false;
  }

}


int addressReallocate(int b,int v){
int phy = b + v;
return phy;
}

//phy=base+virt->stands valid addresss else invalid address

int main(){

int base=0;
int bounds=0;
int virt=0;

cout<<"Enter base register value for memory translation:"<<endl;
cin>>base;

cout<<"Enter bounds register value for memory translation:"<<endl;
cin>>bounds;

cout<<"Enter virtual addresss to start with:"<<endl;
cin>>virt;

bool resultValidity = validCheck(base,virt,bounds);

if(resultValidity==true){
int result_phy_addr = addressReallocate(base,virt);
cout<<"The resulting physical address will be:"<<result_phy_addr<<endl;
}

else{
cout<<"Adrress cannot be translated as it will go out of bound! ERROR!!"<<endl;
}

return 0;
}
