//This program is implemented by Tanishq Agarwal(211B326)
#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

int* decToBinary(int n)
{
vector<int> binaryNum;
int i = 0;
while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
}

int bin[14]=0;
int k=0;
for (int j = i - 1; j >= 0; j--)
{   bin[k]= binaryNum[j];
k++;
}

return bin;
}

int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;
    int base = 1;
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }

    return dec_value;
}

//Main Driver code
int main(){
vector<int> segBit;

int virtAddr=0;
cout<<"Enter virtual adrress for bit translation:"<<endl;
cin>>virtAddr;

segBit= decToBinary(virtAddr);

/*
00->Code
01->Heap
10->Nothing
11->Stack
*/

char sect;
if(segBit[0]==0 && segBit[1]==0){
cout<<"It is in Code section"<<endl;
sect= 'C';
}
else if(segBit[0]==0 && segBit[1]==1){
cout<<"It is in Heap section"<<endl;
sect= 'H';
}
else if(segBit[0]==1 && segBit[1]==0){
cout<<"This segment is NULL segment!"<<endl;
sect= 'N';
}
else{
cout<<"It is in Stack segment"<<endl;
sect= 'S';
}

vector <int> offset;
int count=0;
stringstream ss;

for(int i=2;i<=segBit.size();i++){
	offset[count]=segBit[i];
	ss<<offset[count];
	count++;
}

int offset_bin=0;
ss>>offset_bin;

int resultOffset = binaryToDecimal(offset_bin);

switch(sect){
	case 'C':{
		cout<<"The physical address of code section is:"<<virtAddr+resultOffset<<endl;
		break;
	}

	case 'H':{
		cout<<"The physical address of heap section is:"<<virtAddr+resultOffset<<endl;
		break;
	}
	case 'N':{
		cout<<"out of bound or invalid address!!"<<endl;
		exit(0);
		break;
	}
	case 'S':{
		cout<<"The physical address of stack section is:"<<endl;
		break;
	}
}

cout<<"Program OK!! Exit"<<endl;

return 0;
}

