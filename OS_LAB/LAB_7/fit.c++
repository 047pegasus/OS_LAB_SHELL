#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//Fitting functions
void bestFit(int blockSize[], int processSize[], int bs, int ps){
	int allocation[ps]={0};
	int temp[bs]={0};
	int i=0,j=0;
	for(i=0;i<ps;i++){
		for(j=0;j<bs;j++){
			if(blockSize[j]>=processSize[i]){
				temp[j]=blockSize[j]-processSize[i];
			}
			else{
				temp[j]=100000;
			}
		}
		int min=100000;
		int index=0;
		for(j=0;j<bs;j++){
			if(temp[j]<min){
				min=temp[j];
				index=j;
			}
		}
		if(min==100000){
			cout<<"Process("<<i<<") cannot be allocated memory!"<<endl;
		}
		else{
			allocation[i]=index;
			blockSize[index]=blockSize[index]-processSize[i];
		}
	}
	cout<<"Process No.\tProcess Size\tBlock No.\tBlock Size"<<endl;
	for(i=0;i<ps;i++){
		cout<<i<<"\t\t"<<processSize[i]<<"\t\t"<<allocation[i]<<"\t\t"<<blockSize[allocation[i]]<<endl;
	}
}

void worstFit(int blockSize[], int processSize[], int bs, int ps){
	int allocation[ps]={0};
	int temp[bs]={0};
	int i=0,j=0;
	for(i=0;i<ps;i++){
		for(j=0;j<bs;j++){
			if(blockSize[j]>=processSize[i]){
				temp[j]=blockSize[j]-processSize[i];
			}
			else{
				temp[j]=100000;
			}
		}
		int max=0;
		int index=0;
		for(j=0;j<bs;j++){
			if(temp[j]>max){
				max=temp[j];
				index=j;
			}
		}
		if(max==100000){
			cout<<"Process("<<i<<") cannot be allocated memory!"<<endl;
		}
		else{
			allocation[i]=index;
			blockSize[index]=blockSize[index]-processSize[i];
		}
	}
	cout<<"Process No.\tProcess Size\tBlock No.\tBlock Size"<<endl;
	for(i=0;i<ps;i++){
		cout<<i<<"\t\t"<<processSize[i]<<"\t\t"<<allocation[i]<<"\t\t"<<blockSize[allocation[i]]<<endl;
	}
}

void firstFit(int blockSize[], int processSize[], int bs, int ps){
	int allocation[ps]={0};
	int temp[bs]={0};
	int i=0,j=0;
	for(i=0;i<ps;i++){
		for(j=0;j<bs;j++){
			if(blockSize[j]>=processSize[i]){
				temp[j]=blockSize[j]-processSize[i];
			}
			else{
				temp[j]=100000;
			}
		}
		int index=0;
		for(j=0;j<bs;j++){
			if(temp[j]!=100000){
				index=j;
				break;
			}
		}
		if(temp[index]==100000){
			cout<<"Process("<<i<<") cannot be allocated memory!"<<endl;
		}
		else{
			allocation[i]=index;
			blockSize[index]=blockSize[index]-processSize[i];
		}
	}
	cout<<"Process No.\tProcess Size\tBlock No.\tBlock Size"<<endl;
	for(i=0;i<ps;i++){
		cout<<i<<"\t\t"<<processSize[i]<<"\t\t"<<allocation[i]<<"\t\t"<<blockSize[allocation[i]]<<endl;
	}
}

void nextFit(int blockSize[], int processSize[], int bs, int ps){
	int allocation[ps]={0};
	int temp[bs]={0};
	int i=0,j=0;
	int index=0;
	for(i=0;i<ps;i++){
		for(j=0;j<bs;j++){
			if(blockSize[j]>=processSize[i]){
				temp[j]=blockSize[j]-processSize[i];
			}
			else{
				temp[j]=100000;
			}
		}
		for(j=index;j<bs;j++){
			if(temp[j]!=100000){
				index=j;
				break;
			}
		}
		if(temp[index]==100000){
			cout<<"Process("<<i<<") cannot be allocated memory!"<<endl;
		}
		else{
			allocation[i]=index;
			blockSize[index]=blockSize[index]-processSize[i];
		}
	}
	cout<<"Process No.\tProcess Size\tBlock No.\tBlock Size"<<endl;
	for(i=0;i<ps;i++){
		cout<<i<<"\t\t"<<processSize[i]<<"\t\t"<<allocation[i]<<"\t\t"<<blockSize[allocation[i]]<<endl;
	}
}

void buddyAllocation(int blockSize[], int processSize[], int bs, int ps){
	int allocation[ps]={0};
	int temp[bs]={0};
	int i=0,j=0;
	for(i=0;i<ps;i++){
		for(j=0;j<bs;j++){
			if(blockSize[j]>=processSize[i]){
				temp[j]=blockSize[j]-processSize[i];
			}
			else{
				temp[j]=100000;
			}
		}
		int min=100000;
		int index=0;
		for(j=0;j<bs;j++){
			if(temp[j]<min){
				min=temp[j];
				index=j;
			}
		}
		if(min==100000){
			cout<<"Process("<<i<<") cannot be allocated memory!"<<endl;
		}
		else{
			allocation[i]=index;
			blockSize[index]=blockSize[index]-processSize[i];
		}
	}
	cout<<"Process No.\tProcess Size\tBlock No.\tBlock Size"<<endl;
	for(i=0;i<ps;i++){
		cout<<i<<"\t\t"<<processSize[i]<<"\t\t"<<allocation[i]<<"\t\t"<<blockSize[allocation[i]]<<endl;
	}
}

//Main(): Driver code function
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
cout<<"1.) Best Fit \n"<<"2.) Worst Fit \n"<<"3.) First Fit \n"<<"4.) Next Fit\n"<<"5.) Buddy Allocation\n"<<"6.) Exit"<<endl;
cin>>choice;

cout<<"Proceeding with choosen strategy.. Now computing the fit size... \n";

switch(choice){
	case 1:{
		//Best Fit Approach
		cout<<"Chosen strategy is Best fit!"<<endl;
		bestFit(blockSize,processSize,bs,ps);
		break;
	}

	case 2:{
		//Worst fit approach
		cout<<"Chosen strategy is Best fit!"<<endl;
		worstFit(blockSize,processSize,bs,ps);
		break;
	}

	case 3:{
		//First Fit approach
		cout<<"Chosen strategy is Best fit!"<<endl;
		firstFit(blockSize,processSize,bs,ps);
		break;
	}

	case 4:{
		//Next Fit Approach
		cout<<"Chosen strategy is Best fit!"<<endl;
		nextFit(blockSize,processSize,bs,ps);
		break;
	}

	case 5:{
		//Buddy Allocation approach
		cout<<"Chosen startegy is Buddy Allocation!"<<endl;
		buddyAllocation(blockSize,processSize,bs,ps);
		break;
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

return 0;
}
