#include<iostream>
#include<conio.h>
#define size 100
using namespace std;

class FCFS
{
    private:
    int i, j, n,sum=0,o[size], bt[size], wt[size], pt[size][size];

    public:
    int input();
    int sort();
    int wait_time();
    int output();


};

int main()
{
    FCFS obj;
    obj.input();
    obj.sort();
    obj.wait_time();
    obj.output();
	return 0;
}

int FCFS::input()
{   
    cout<<"Enter num of processes : ";
	cin>>n;

	for(i=0; i<n; i++)
	{
		cout<<"Enter Order of Arival of Process" << i+1<<" : ";
		cin>>o[i];

		cout<<"Enter Burst Time (in ms) of Process"<< i+1<<" : ";
		cin>>bt[i];
	}

    return 0;
}

int FCFS::sort()
{
    for(i=0; i<n; i++)
	{
		for(j=0; j<n-i; j++)
		{
			if(o[j]>o[j+1])
			{
				int temp, temp2;
				temp=o[j];
				o[j]=o[j+1];
				o[j+1]=temp;

				temp2 = bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp2; 
			}
		}
	}

    return 0;
}

int FCFS::wait_time()
{
    wt[0] = 0;
	for(i=1; i<n; i++)
	{
	  wt[i]= wt[i-1] + bt[i-1];
	  sum+=wt[i];
	}

    return 0;
}

int FCFS::output()
{
    for(i=0; i<n; i++)
	{
		  pt[i][0] =o[i];
		  pt[i][1] =bt[i];
		  pt[i][2] =wt[i];

	}
	cout<<endl<<"Order of Arival   Burst Time   W.T."<<endl;
	for(i=0; i<n; i++)
	{

		for(j=0; j<n; j++)
	{
			cout<<pt[i][j]<< "\t "<<"\t";
		}
		cout<<endl;
	}

	cout<<"Avg. Waiting Time (in ms) : "<<sum/n;

    return 0;
}

