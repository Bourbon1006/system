#include<stdio.h>

typedef struct order
{
	char op;
	int page;
	int address;
};

typedef struct page {
	int pageNumber;
	int flag;
	int pageNo;
	int Fflag;
	int location;
	int address(int i)
	{
		return pageNo * 1024 + i;
	}
};