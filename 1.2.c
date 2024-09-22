#include<stdio.h>

int main()
{
	printf("请输入金额。\n");
	int sum = 0;
	scanf_s("%d", &sum);
	printf("共应付%d元，请投入1元，2元或5元，每次投入后回车，直到总金额大于或等于应付金额。\n", sum);
	int sum2 = 0;
	int pay = 0;
	while (sum2 < sum)
	{
		scanf_s("%d", &pay);
		do {
			if (pay != 1 && pay != 2 && pay != 5) {
				printf("输入金额无效，请重新输入。\n");
				scanf_s("%d", &pay);
			}
		} while (pay != 1 && pay != 2 && pay != 5);
		sum2 += pay;
	}
	printf("找您%d元\n", sum2 - sum);
	printf("本次付款结束。\n");
	return 0;
}