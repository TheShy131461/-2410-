#include<stdio.h>
#include<string.h>
int main()
{
	printf("��ʼ�ڷŻ����������д�������࣬ͨ�������ۺ�������\n");
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
			printf("�������ܻ����������ܳ���50������������������\n");
			scanf_s("%d", &number);
		}
	} while (number > 50);
	char h = brand[0];
	int i = 0;
	printf("����Ϊ�ڷŽ����\n");
	printf("%d:", channel);
	for (i = 0;i < number;i++) { printf("%c", h); }
	printf("  %d\n", price);
	rewind(stdin);


	do {
		printf("��ʼ����������������������࣬ͨ����������\n");
		char brandx[100];
		int channelx = 0;
		int pricex = 0;
		int numberx = 0;
		scanf_s("%s", &brandx, 1);
		scanf_s("%d", &channelx);
		scanf_s("%d", &numberx);
		do {
			if (channelx != channel) {
				printf("ͨ���������ٴ�����ͨ����\n");

				scanf_s("%d", &channelx);
			}
			else {
				break;
			};
		} while (channelx != channel);

		do {
			if (numberx > number) {
				printf("�����������ܳ�����������������������������\n");
				scanf_s("%d", &numberx);
			}
			else { break; }
		} while (numberx > number);
		number -= numberx;
		rewind(stdin);

		int sum = 0;
		sum = numberx * price;
		printf("��Ӧ��%dԪ����Ͷ��1Ԫ��2Ԫ��5Ԫ��ÿ��Ͷ���س���ֱ���ܽ����ڻ����Ӧ����\n", sum);
		int sum2 = 0;
		int pay = 0;
		while (sum2 < sum)
		{
			scanf_s("%d", &pay);
			do {
				if (pay != 1 && pay != 2 && pay != 5) {
					printf("��������Ч�����������롣\n");
					scanf_s("%d", &pay);
				}
			} while (pay != 1 && pay != 2 && pay != 5);
			sum2 += pay;
		}
		printf("����%dԪ\n", sum2 - sum);
		printf("���θ��������\n");
		char s1[100]="END";
		char s2[100];
		printf("��Ҫ������������YES����������END��\n");
		scanf_s("%s", &s2,4);
		if (strcmp(s1, s2) == 0) {
			printf("��������\n");
			break;
		}
	} while (number != 0);
	if (number == 0) { printf("�������ꡣ\n"); }
	return 0;
}