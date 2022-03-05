#include<iostream>
#include<conio.h>
#define size 100
using namespace std;

class SJF
{	
	private:
		int i,n, bt[size], wt[size], sum, print[size][size], temp=0, k=0;

	public:
		void input();
		void sort();
		void wait_time();
		void output();
};

int main()
{	
	SJF obj;
	obj.input();
	obj.sort();
	obj.wait_time();
	obj.output();	
	
	return 0;
}

void SJF::input()
{
	cout<<"Enter number of Processes: ";
	cin>>n;

	for(i=0; i<n; i++)
	{
	  cout<<"Enter Burst time for Process"<< i+1 << " : ";
	  cin>>bt[i];
	}

}

void SJF::sort()
{
	for(i=1; i<n; i++)
	{
		for(k=0; k<n-i; k++)
		{
		  if(bt[k]>bt[k+1])
		  {
			temp = bt[k];
			bt[k] = bt[k+1];
			bt[k+1] = temp;
		  }
		}
	}
}

void SJF::wait_time()
{	
	sum=0;
	wt[0]=0;
	for(i=1; i<n; i++)
	{
	       wt[i]=wt[i-1]+ bt[i-1];
	       sum=sum+wt[i];
	}
}

void SJF::output()
{
	for(i=0;i<n; i++)
	{
	 print[i][0] = i+1;
	 print[i][1] = bt[i];
	 print[i][2] = wt[i];
	}

	for(i=0; i<n; i++)
	{
		for(int j=0; j<3; j++)
		{
			cout<<print[i][j]<<"\t"<<"\t";
		}
		cout<<endl;
	}
	cout<<"Avg. Waiting Time :"<<sum/n;
}