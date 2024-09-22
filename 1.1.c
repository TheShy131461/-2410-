#include<stdio.h>

int main()
{
	printf("开始摆放货物，请依次填写货物种类，通道，单价和数量。\n");
	char brand[100];
	int channel = 0;
	int price = 0;
	int number = 0;

	scanf_s("%c", &brand[0], 1);
	scanf_s("%d", &channel);
	scanf_s("%d",&price);
	scanf_s("%d", &number);
	if (number > 50) {
		printf("单个货架货物数量不能超过50，请重新输入数量。\n");
		scanf_s("%d", &number);
	}

	char h = brand[0];
	int i = 0;
	printf("以下为摆放结果。\n");
	printf("%d:",channel);
	for (i = 0;i < number;i++) { printf("%c", h); }
	printf("  %d", price);

	return 0;
}