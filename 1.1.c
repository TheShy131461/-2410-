#include<stdio.h>

int main()
{
	printf("��ʼ�ڷŻ����������д�������࣬ͨ�������ۺ�������\n");
	char brand[100];
	int channel = 0;
	int price = 0;
	int number = 0;

	scanf_s("%c", &brand[0], 1);
	scanf_s("%d", &channel);
	scanf_s("%d",&price);
	scanf_s("%d", &number);
	if (number > 50) {
		printf("�������ܻ����������ܳ���50������������������\n");
		scanf_s("%d", &number);
	}

	char h = brand[0];
	int i = 0;
	printf("����Ϊ�ڷŽ����\n");
	printf("%d:",channel);
	for (i = 0;i < number;i++) { printf("%c", h); }
	printf("  %d", price);

	return 0;
}