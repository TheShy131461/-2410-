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
	int q = 0;//��¼���˴���
	int h = 0;
	int z = 0;

	printf("��������Ʒ���ơ�ͨ�������ۡ��������м��ÿո������\n");
	do {
		scanf_s("%s", &grand[n], 1);
		scanf_s("%d", &channel[n]);
		scanf_s("%d", &price[n]);
		scanf_s("%d", &number[n]);
		if (channel[n] > 5) {
			printf("ֻ�ܰڵ�1-5ͨ��,����������ͨ����");
			scanf_s("%d", &channel[n]);
		};
		if (number[n] > 50) {
			printf("����ͨ�����ڷ�50������������������������");
			scanf_s("%d", &number[n]);
		};
		rewind(stdin);
		for (q = 0;q <= 2;q++) {
			printf("�Ƿ��˻���һ����������������back����������no��\n");
			scanf_s("%s", s3, 5);
			if (strcmp(s3, "back") == 0) {
				h++;z++;
				printf("�ѻ��ˣ�������������Ʒ���ơ�ͨ�������ۡ�������\n");
				scanf_s("%s", &grand[n], 1);
				scanf_s("%d", &channel[n]);
				scanf_s("%d", &price[n]);
				scanf_s("%d", &number[n]);

			}
			else { break; }
		}
		printf("�Ƿ����������һ����Ʒ����������YES����������END��\n");
		scanf_s("%s", s2, 4);
		if (strcmp(s1, s2) == 0) {
			printf("�Ż�������\n");
			break;
		}
		else {
			n++;
		}rewind(stdin);
	} while (n <= 4);
	if (n == 5) {
		printf("�ڻ�ͨ�������ꡣ");

	}



	printf("�ڻ���������ʼ�����������������������Ʒ�ơ�ͨ��������������ENDֹͣ����\n");
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
				printf("�Ƿ��˻���һ������������back����������no��\n");
				scanf_s("%s", s3, 5);
				if (strcmp(s3, "back") == 0) {
					z++;
					printf("������������������Ʒ�ơ�ͨ����������\n");
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
					printf("�������������ִ����������������롣\n");
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
					printf("�������������ִ����������������롣\n");
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
					printf("�������������ִ����������������롣\n");
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
					printf("�������������ִ����������������롣\n");
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
					printf("�������������ִ����������������롣\n");
					scanf_s("%d", &numberx);
					i--;
				}
			}
			else { continue; }

		}break;
		}
		if (number[0] == 0 && number[1] == 0 && number[2] == 0 && number[3] == 0 && number[4] == 0) {
			printf("��Ʒ�����ꡣ");
			break;
		}
		char s3[100];
		scanf_s("%s", s3, 4);
		if (strcmp(s1, s3) == 0) {
			printf("ֹͣ����");
			break;
		}
		else { i = 0; }
	} while (number[0] != 0 || number[1] != 0 || number[2] != 0 || number[3] != 0 || number[4] != 0);



	printf("��Ӧ��%dԪ����Ͷ��1Ԫ��2Ԫ��5Ԫ��ÿ��Ͷ���س���ֱ���ܽ����ڻ����Ӧ����\n", sum);
	int sum2 = 0;
	int pay = 0;
	while (sum2 < sum)
	{
		scanf_s("%d", &pay);
		if (z<= 2) {
			for (z = z;z<= 2;z++) {
				printf("�Ƿ��˻���һ��֧������������back����������no��\n");
				scanf_s("%s", s3, 5);
				if (strcmp(s3, "back") == 0) {

					printf("�����¸��\n");
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
				printf("��������Ч�����������롣\n");
				scanf_s("%d", &pay);
			}
		} while (pay != 1 && pay != 2 && pay != 5);
		sum2 += pay;
	}
	printf("����%dԪ\n", sum2 - sum);
	printf("���ι��������\n");

	return 0;
}