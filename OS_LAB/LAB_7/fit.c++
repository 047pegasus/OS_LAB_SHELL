#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

//Input data for process and block size
int bs=0,ps=0;
cout<<"Enter no. of block(s):"<<endl;
cin>>bs;
cout<<"Enter no. of processes:"<<endl;
cin>>ps;

int blockSize[bs]={0};
int processSize[ps]={0};

for(int i=0;i<bs;i++){
cout<<"Enter the block size value for block("<<i<<"):"<<endl;
cin>>blockSize[i];
}

//Sorting block size in a temp array dblock in descending order manner.
vector<int> dblock;

for(int i=0;i<bs;i++){
	dblock.push_back(blockSize[i]);
}

for(const auto &i: dblock){
sort(dblock.begin(), dblock.end(), greater <>());
}

int max_block=dblock[0];

for(int i =0;i<ps;i++){
cout<<"Enter the process size for process("<<i<<")"<<endl;
cin>>processSize[i];
}
//Check for fitting startegy to be applied as per user demand.

int choice=0;
A:
cout<<"Enter the strategy no. to be applied as per provided strategies below in menu:"<<endl;
cout<<"1.) Best Fit \n"<<endl<<"2.) Worst Fit \n"<<"3.) First Fit \n"<<"4.) Next Fit\n"<<"5.) Buddy Allocation"<<"6.) Exit"<<endl;
cin>>choice;

cout<<"Proceeding with choosen strategy.. Now computing the fit size... \n";

switch(choice){
	case 1:{
		//Best Fit Approach
		cout<<"Chosen strategy is Best fit!"<<endl;
		for(int i=0;i<bs;i++){
			if(processSize[i]>=dblock[i]){
				result[i]=processSize[i];
			}
		}
	}

	case 2:{
		//Worst fit approach

	}

	case 3:{
		//First Fit approach

	}

	case 4:{
		//Next Fit Approach

	}

	case 5:{
		//Buddy Allocation approach

	}

	case 6:{
		cout<<"Now exiting program!!"<<endl;
		exit(0);
	}

	default:{
		cout<<"Enter a correct choice from menu (under 5)!!"<<endl;
		goto A;
	}
}

//Actual computation


return 0;
}