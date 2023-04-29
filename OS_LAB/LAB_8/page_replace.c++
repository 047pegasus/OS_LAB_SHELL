#include<iostream>

using namespace std;

int main()
{  // Random array generation
    int n;
    cout<<"Enter the no of random frames to be generated in the sttring array:";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%10;
    }
    cout<<"The random frame reference string generated is: ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
   
   //Frame initialization
    int frames;
    cout<<"Enter the number of frames: ";
    cin>>frames;
    int frame[frames];
    for(int i=0;i<frames;i++)
    {
        frame[i]=-1;
    }
    //Page replacement and page fault calculation
    int page_fault=0;
    int j=0;
    int k=0;
    for(int i=0;i<n;i++)
    {
        int flag=0;
        for(j=0;j<frames;j++)
        {
            if(frame[j]==a[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            frame[k]=a[i];
            k=(k+1)%frames;
            page_fault++;
        }
        cout<<"Page fault after inserting "<<a[i]<<" is "<<page_fault<<endl;
    }
    cout<<"Total page faults are: "<<page_fault<<endl;
    
    return 0;
}
