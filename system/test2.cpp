#include "fifo.h"


int main()
{
	int out_page, in_page;
	int k = 0;
	int p[4] = { 0,1,2,3 };
	int num = 0;
	struct order Order[50]{};
	struct page Page[7];
	int a = 0;
	int b = 0;
	
	Order[0] = {"+",0,70};
	Order[1] = {"+",1,50};
	Order[2] = { "*",2,15 };
	Order[3] = { "存",3,21 };
	Order[4] = { "取",0,56 };
	Order[5] = { "-",6,40 };
	Order[6] = { "移位",4,53 };
	Order[7] = { "+",5,23 };
	Order[8] = { "存",1,37 };
	Order[9] = { "取",2,78 };
	Order[10] = { "+",4,1 };
	Order[11] = { "存",6,84 };


	Page[0] = { 0 ,1,5	,0,	011 };
	Page[1] = { 1 ,1 ,8	,0 ,012 };
	Page[2] = { 2 ,1 ,9	,1 ,013 };
	Page[3] = { 3 ,1, 1 ,0,	021 };
	Page[4] = { 4 ,0 ,0	,0 ,022 };
	Page[5] = { 5 ,0 ,0	,0 ,023 }; 
	Page[6] = { 6 ,0 ,0	,0 ,121 };


	while (num < 12)
	{
		int x = Order[num].Page;
		if (Page[x].Flag != 0)
		{
			if (Order[num].Op == "存")
			{
				Page[x].Fflag = 1;
			}
			//printf("%d\n", Page[x].Fflag);
			printf("%d\n", Page[x].address(Order[0].Address));
			b++;
		}
		else {
			cout << "*" << Order[num].Page << endl;
			a++;
			//int out_page = Order[num].Page;
			out_page = p[k];
			if (Page[out_page].Fflag == 1) {
				printf("%d\n", out_page);
			}
			p[k] = num;
			k = (k + 1) % 4;
			Page[num].Flag = 1;								
			Page[out_page].Flag = 0;								
			Page[num].Fflag = 0;						
			if (Order[0].Op == "存")
				Page[num].Fflag = 1;
		    Page[num].PageNo = Page[out_page].PageNo;
		}
		num++;
		
	}
	cout << "当前数据下的FIFO算法缺页率为： " << a / b;
}