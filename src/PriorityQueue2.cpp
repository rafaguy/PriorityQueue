//============================================================================
// Name        : PriorityQueue.cpp
// Author      : fabrice
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <utility>
#define maxN 100
#define INT_MAX 3000;
using namespace std;

static int a[maxN+1],N;

void construct(int b[],int M)
{
	for(N=1;N<=M;N++)
	{
		a[N]=b[N];
	}
}
void insert(int v)
{
	a[N++]=v;
}
int remove()
{
	int j,max,v;
	max=1;
	for(j=2;j<=N;j++)
	{
		if(a[max]<a[j])max=j;
	}
	v=a[max];
	a[max]=a[--N];
	return v;
}
////////////////////////////////////////////////////////////

void upheap(int k)
{
	int v;
	v=a[k];a[0]=INT_MAX;
	while(a[k/2]<=v)
	{
		a[k]=a[k/2];k=k/2;
	}
	a[k]=v;
}
void downheap()
{
	int maxchild,i=1;
	int j=1;
	int v=a[i];
	while(true)
	{
		j = a[2*i]>a[2*i+1]?2*i:2*i+1;
		while(a[j]>a[i])
		{
			a[i]=a[j];
			i=j;
		}
		if(i!=1)
		 a[j]=v;
		break;
	}
}
void downheap(int k)
{
	int j,v;
	v=a[k];
	while(k<=N/2)
	{
		j=k+k;
		if(j<N && a[j]<a[j+1]) j++;
		if(v>=a[j]) break;
		a[k]=a[j];k=j;
	}
	a[k]=v;
}
void insertheap(int v)
{
	a[++N]=v;
	upheap(N);
}
int replace(int v)
{
	a[0]=v;
	downheap(0);
	return a[0];
}
int removeheap()
{
	int v=a[1];
	a[1]=a[N--];

	downheap(1);
	return v;
}
////////////////////////////////////////Using Indirect Heap/////////
int p[100],q[100];
void pqdownheap(int a[],int N,int k)
{
	int j,v;
	v=p[k];
	while(k<=N/2)
	{
		j=k+k;
		if(j<N&&a[p[j]]<a[p[j+1]]) j++;
		if(a[v]>=a[p[j]]) break;
		p[k]=p[j];
		q[p[j]] =k;
		k=j;

	}
	p[k]=v;q[v]=k;
}

void pqconstruct(int a[],int N)
{
	int k;
	for(k=1;k<=N;k++) {
		p[k]=q[k]=k;
	}
	for(k=N/2;k>=1;k--) pqdownheap(a,N,k);
}

////////////////////////////////////////Recursive
template<typename T>
void f( T& param)
{
	std::cout<<param<<std::endl;
}
template<typename T>
void f(const T&& rhs)
{
	std::cout<<rhs<<" rvalue"<<std::endl;
}
template<typename T>
void f1(T param)
{
	std::cout<<param<<std::endl;
}
template<typename T,std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept
{
	return N;
}
///////////////////////////////////////////////////
int main() {

	int a[]={111,12,11,23,55,66,22,88,56,76};
	pqconstruct(a,9);

	/*
	int x=27;
	const int cx=x;
	const int& rx=x;
	const int&& a= 24;
	f(x);
	f(cx);
	f(rx);
	const char* const ptr="Fun with pointers";
	f1(ptr);
	const char name[]="J. P. Briggs";
	const char *ptrToName = name;
	int keyVals[]= {1,3,7,9,11};
	int mappedVals[arraySize(keyVals)];
	f(std::forward<int>(a) );
	//*/

	/*

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	//int b[]={22,34,67,34,77,66,55,98,76};
	//construct(b,8);
	insertheap(5);
	insertheap(10);
	insertheap(15);
	insertheap(6);
	insertheap(7);


	for(int i=0;i<6;i++)
	{
		std::cout<<" " <<a[i];
	}
	replace(14);
	for(int i=0;i<6;i++)
		{
			std::cout<<"\n " <<a[i];
		}
	//*/
	return 0;
}
