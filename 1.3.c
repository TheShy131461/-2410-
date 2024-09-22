#include<stdio.h>
#include<string.h>
int main()
{
	printf("开始摆放货物，请依次填写货物种类，通道，单价和数量。\n");
	char brand[100];
	int channel = 0;
	int price = 0;
	int number = 0;

	scanf_s("%c", &brand[0], 1);
	scanf_s("%d", &channel);
	scanf_s("%d", &price);
	scanf_s("%d", &number);
	do {
		if (number > 50) {
			printf("单个货架货物数量不能超过50，请重新输入数量。\n");
			scanf_s("%d", &number);
		}
	} while (number > 50);
	char h = brand[0];
	int i = 0;
	printf("以下为摆放结果。\n");
	printf("%d:", channel);
	for (i = 0;i < number;i++) { printf("%c", h); }
	printf("  %d\n", price);
	rewind(stdin);


	do {
		printf("开始买货，请输入所买货物的种类，通道，数量。\n");
		char brandx[100];
		int channelx = 0;
		int pricex = 0;
		int numberx = 0;
		scanf_s("%s", &brandx, 1);
		scanf_s("%d", &channelx);
		scanf_s("%d", &numberx);
		do {
			if (channelx != channel) {
				printf("通道错误，请再次输入通道。\n");

				scanf_s("%d", &channelx);
			}
			else {
				break;
			};
		} while (channelx != channel);

		do {
			if (numberx > number) {
				printf("购买数量不能超出货物数量，请重新输入数量。\n");
				scanf_s("%d", &numberx);
			}
			else { break; }
		} while (numberx > number);
		number -= numberx;
		rewind(stdin);

		int sum = 0;
		sum = numberx * price;
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
		char s1[100]="END";
		char s2[100];
		printf("如要继续购买，输入YES，否则输入END。\n");
		scanf_s("%s", &s2,4);
		if (strcmp(s1, s2) == 0) {
			printf("结束购买。\n");
			break;
		}
	} while (number != 0);
	if (number == 0) { printf("货已卖完。\n"); }
	return 0;
}