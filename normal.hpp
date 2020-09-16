#include<stdio.h>
#include<fstream>
#include<iostream>
#include<sstream>
#include<stdlib.h>
#include <string.h>
#include<vector>
#include<time.h>
using namespace std;

vector<char> onemax;
vector<char> temp;
int opt=0;

void create(vector<char>arr,int size)
{
	for(int i=0;i<size;i++)
	{
  	int a=rand()%2;
    char c =a+'0';
    arr[i]=c;
    }
}
 void Print(vector<char>arr,int size){
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<' ';
	}
	cout<<endl;
} 
int Evaluate(vector<char>arr,int size)
{
	int optimal=0;
	for(int i=0;i<size;i++)
	{
		if(arr[i]=='1')
			optimal++;
	}
	return optimal;
}
void add(vector<char> &arr,int len)
{
	int i=len-1;
	int chc=1;
	while(chc){
    	if(arr[i]=='1')
		{
			arr[i]='0';
			i--;
		}
		else if (arr[i]=='0')
		{
			arr[i]='1';
			chc=0;
			break;
		}
	} 
}
void sub (vector<char>arr,int len)
{
	int i=len-1;
	int chc=1;
	while(chc){
    	if(arr[i]=='1')
		{
			arr[i]='0';
			chc=0;
			break;
		}
		else if (arr[i]=='0')
		{
			arr[i]='1';
			i--;
		}
	} 
}
int avg(int *arr,int len)
{
	int sum=0;
	for(int i=0;i<len;i++)
	{
		sum+=arr[i];
		cout<<"iteration"<<i+1<<':'<<arr[i]<<endl;
	}
	int avg=sum/len;
	return avg;
}
void compare(vector<char>arr,vector<char>temp,int len,int &opt,int curropt)
{
	if(curropt>=opt)
	{
		for(int i=0;i<len;i++)
		{
			arr[i]=temp[i];
		}
		opt=curropt;
	}

	
}
void ITER(vector<char> onemax,vector<char>temp,int len,int opt,double time)
{
    onemax.resize(len,'0');
	temp.resize(len,'0');
	double START,END;
	 START = clock();
	while( ((END - START) / CLOCKS_PER_SEC) < time){
		add(temp,len);
		//Print(temp,len);
		int temp2=Evaluate(temp,len);
		if(temp2>=opt)
		{
            opt=temp2;
			onemax.assign(temp.begin(), temp.end());

		}
         END=clock();
	}
	Print(onemax,len);
	cout<<"Quantity:"<<endl<<opt<<endl;
	cout<<"Execution Time:";
	cout<<(END - START) / CLOCKS_PER_SEC<<"(s)"<<endl;
}

