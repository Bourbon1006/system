#include<stdio.h>
#include "iostream"
#include <string>
using namespace std;

typedef struct order
{
	string Op;
	int Page;
	int Address;
};

typedef struct page {
	int PageNumber;
	int Flag;
	int PageNo;
	int Fflag;
	int Location;
	int address(int i)
	{
		return PageNo * 1024 + i;
	}
};