#include<stdio.h>

int main()
{
	printf("�������\n");
	int sum = 0;
	scanf_s("%d", &sum);
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
	return 0;
}