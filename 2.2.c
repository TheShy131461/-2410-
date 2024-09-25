//这是半成品！成品是下面的complete2.2！

#include <stdio.h>
#include<string.h>


int main()
{
	char grand[100];
	int channel[5] = { 0 };
	int price[5] = { 0 };
	int number[5] = { 0 };
	int n = 0;
	char s1[100] = "END";
	char s2[100];
	char s3[100];
	int q = 0;//记录回退次数
	int h = 0;
	int z = 0;

	printf("请输入商品名称、通道、单价、数量，中间用空格隔开。\n");
	do {
		scanf_s("%s", &grand[n], 1);
		scanf_s("%d", &channel[n]);
		scanf_s("%d", &price[n]);
		scanf_s("%d", &number[n]);
		if (channel[n] > 5) {
			printf("只能摆到1-5通道,请重新输入通道。");
			scanf_s("%d", &channel[n]);
		};
		if (number[n] > 50) {
			printf("单个通道最多摆放50个货物，请重新输入货物数量。");
			scanf_s("%d", &number[n]);
		};
		rewind(stdin);
		for (q = 0;q <= 2;q++) {
			printf("是否退回上一步操作？是请输入back，否请输入no。\n");
			scanf_s("%s", s3, 5);
			if (strcmp(s3, "back") == 0) {
				h++;z++;
				printf("已回退，请重新输入商品名称、通道、单价、数量。\n");
				scanf_s("%s", &grand[n], 1);
				scanf_s("%d", &channel[n]);
				scanf_s("%d", &price[n]);
				scanf_s("%d", &number[n]);

			}
			else { break; }
		}
		printf("是否继续加入下一样商品？是请输入YES，否请输入END。\n");
		scanf_s("%s", s2, 4);
		if (strcmp(s1, s2) == 0) {
			printf("放货结束。\n");
			break;
		}
		else {
			n++;
		}rewind(stdin);
	} while (n <= 4);
	if (n == 5) {
		printf("摆货通道已用完。");

	}



	printf("摆货结束，开始买货。请依次输入所买货物的品牌、通道、数量。输入END停止购买。\n");
	int sum = 0;
	char grandx = '0';
	int channelx = 0;
	int numberx = 0;
	int i = 0;

	do {
		scanf_s("%c", &grandx, 1);
		scanf_s("%d", &channelx);
		scanf_s("%d", &numberx);

		/*if (h <= 2) {
			for (h = h;h <= 2;h++) {
				printf("是否退回上一步？是请输入back，否请输入no。\n");
				scanf_s("%s", s3, 5);
				if (strcmp(s3, "back") == 0) {
					z++;
					printf("请重新输入所买货物的品牌、通道、数量。\n");
					scanf_s("%c", &grandx, 1);
					scanf_s("%d", &channelx);
					scanf_s("%d", &numberx);
					continue;
				}
				else {
					break;
				}
			}
		}*/


		switch (channelx) {
		case 1:for (i = 0; i <= 4; i++) {
			if (channel[i] == 1) {
				if (numberx <= number[i]) {
					number[i] -= numberx;
					sum += numberx * price[i];
				}
				else {
					printf("输入数量大于现存数量，请重新输入。\n");
					scanf_s("%d", &numberx);
					i--;
				}
			}
			else { continue; }
		}break;
		case 2:for (i = 0; i <= 4; i++) {
			if (channel[i] == 2) {
				if (numberx <= number[i]) {
					number[i] -= numberx;
					sum += numberx * price[i];
				}
				else {
					printf("输入数量大于现存数量，请重新输入。\n");
					scanf_s("%d", &numberx);
					i--;
				}
			}
			else { continue; }
		}break;
		case 3:for (i = 0; i <= 4; i++) {
			if (channel[i] == 3) {
				if (numberx <= number[i]) {
					number[i] -= numberx;
					sum += numberx * price[i];
				}
				else {
					printf("输入数量大于现存数量，请重新输入。\n");
					scanf_s("%d", &numberx);
					i--;
				}
			}
			else { continue; }
		}break;
		case 4:for (i = 0; i <= 4; i++) {
			if (channel[i] == 4) {
				if (numberx <= number[i]) {
					number[i] -= numberx;
					sum += numberx * price[i];
				}
				else {
					printf("输入数量大于现存数量，请重新输入。\n");
					scanf_s("%d", &numberx);
					i--;
				}
			}
			else { continue; }
		}break;
		case 5:for (i = 0; i <= 4; i++) {
			if (channel[i] == 5) {
				if (numberx <= number[i]) {
					number[i] -= numberx;
					sum += numberx * price[i];
				}
				else {
					printf("输入数量大于现存数量，请重新输入。\n");
					scanf_s("%d", &numberx);
					i--;
				}
			}
			else { continue; }

		}break;
		}
		if (number[0] == 0 && number[1] == 0 && number[2] == 0 && number[3] == 0 && number[4] == 0) {
			printf("商品已卖完。");
			break;
		}
		char s3[100];
		scanf_s("%s", s3, 4);
		if (strcmp(s1, s3) == 0) {
			printf("停止购买。");
			break;
		}
		else { i = 0; }
	} while (number[0] != 0 || number[1] != 0 || number[2] != 0 || number[3] != 0 || number[4] != 0);



	printf("共应付%d元，请投入1元，2元或5元，每次投入后回车，直到总金额大于或等于应付金额。\n", sum);
	int sum2 = 0;
	int pay = 0;
	while (sum2 < sum)
	{
		scanf_s("%d", &pay);
		if (z<= 2) {
			for (z = z;z<= 2;z++) {
				printf("是否退回上一步支付？是请输入back，否请输入no。\n");
				scanf_s("%s", s3, 5);
				if (strcmp(s3, "back") == 0) {

					printf("请重新付款。\n");
					scanf_s("%d", &pay);
					continue;
				}
				else {
					break;
				}
			}
		}
		do {
			if (pay != 1 && pay != 2 && pay != 5) {
				printf("输入金额无效，请重新输入。\n");
				scanf_s("%d", &pay);
			}
		} while (pay != 1 && pay != 2 && pay != 5);
		sum2 += pay;
	}
	printf("找您%d元\n", sum2 - sum);
	printf("本次购买结束。\n");

	return 0;
}
