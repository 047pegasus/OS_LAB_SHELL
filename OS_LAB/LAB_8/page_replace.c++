#include<iostream>

using namespace std;

void fifo(int fstr[],int n){
//Frame initialization
    int frames=0;
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
            if(frame[j]==fstr[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            frame[k]=fstr[i];
            k=(k+1)%frames;
            page_fault++;
        }
        cout<<"Page fault after inserting "<<fstr[i]<<" is "<<page_fault<<endl;
    }
    cout<<"Total page faults are: "<<page_fault<<endl;
}

int main()
{
 // Random array generation
    int n;
    cout<<"Enter the no of random frames to be generated in the string array:";
    cin>>n;
    int framestr[n];
    for(int i=0;i<n;i++)
    {
        framestr[i]=rand()%10;
    }
    cout<<"The random frame reference string generated is: ";
    for(int i=0;i<n;i++)
    {
        cout<<framestr[i]<<" ";
    }
    cout<<endl;

    fifo(framestr,n);//FIFO Page Replacement policy invoked on generated frame reference string.

    return 0;
}
