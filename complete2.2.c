#include <stdio.h>
#include <string.h>
int main() {
    char grand[100][100]; // ��Ʒ����
    int channel[5] = { 0 };
    int price[5] = { 0 };
    int number[5] = { 0 };
    int n = 0;
    char s1[] = "END";
    char s2[100];
    char s3[100];
    int q = 0; // ��¼���˴���
    int h = 0; // ��¼������׶εĻ��˴���
    printf("��������Ʒ���ơ�ͨ�������ۡ��������м��ÿո������\n");
    do {
        // �޸�Ϊ��ȷʹ�� scanf_s
        scanf_s("%s", grand[n], sizeof(grand[n]));
        scanf_s("%d", &channel[n]);
        scanf_s("%d", &price[n]);
        scanf_s("%d", &number[n]);
        // �������ݺϷ��Լ��
        if (channel[n] < 1 || channel[n] > 5) {
            printf("ֻ�ܰڵ�1-5ͨ��,����������ͨ����\n");
            scanf_s("%d", &channel[n]);
        }
        if (number[n] < 1 || number[n] > 50) {
            printf("����ͨ�����ڷ�50������������������������\n");
            scanf_s("%d", &number[n]);
        }

        // ���˲���
        for (q = 0; q <= 2; q++) {
            printf("�Ƿ��˻���һ����������������back����������no��\n");
            scanf_s("%s", s3, sizeof(s3));
            if (strcmp(s3, "back") == 0) {
                h++;
                if (h > 3) {
                    printf("�Ѿ��ﵽ�����˴����������ٻ��ˡ�\n");
                    h--;  // �ָ����˴���
                }
                else {
                    printf("�ѻ��ˣ�������������Ʒ���ơ�ͨ�������ۡ�������\n");
                    scanf_s("%s", grand[n], sizeof(grand[n]));
                    scanf_s("%d", &channel[n]);
                    scanf_s("%d", &price[n]);
                    scanf_s("%d", &number[n]);
                }
            }
            else {
                break;
            }
        }

        printf("�Ƿ����������һ����Ʒ����������YES����������END��\n");
        scanf_s("%s", s2, sizeof(s2));
        if (strcmp(s1, s2) == 0) {
            printf("�Ż�������\n");
            break;
        }
        else {
            n++;
        }

    } while (n < 5);
    if (n == 5) {
        printf("�ڻ�ͨ�������ꡣ\n");
    }
    printf("�ڻ���������ʼ�����������������������Ʒ�ơ�ͨ��������������ENDֹͣ����\n");
    int sum = 0;
    char grandx[100];
    int channelx = 0;
    int numberx = 0;
    while (number[0] != 0 || number[1] != 0 || number[2] != 0 || number[3] != 0 || number[4] != 0) {
        scanf_s("%s", grandx, sizeof(grandx));
        if (strcmp(grandx, s1) == 0) {
            printf("ֹͣ����\n");
            break;
        }
        scanf_s("%d", &channelx);
        scanf_s("%d", &numberx);

        // �������Ϸ���
        if (channelx < 1 || channelx > 5) {
            printf("ͨ��Ӧ��1-5֮�䣬���������롣\n");
            continue;
        }

        // ���˲���
        for (h = h; h < 3; h++) {
            printf("�Ƿ��˻���һ����������������back����������no��\n");
            scanf_s("%s", s3, sizeof(s3));
            if (strcmp(s3, "back") == 0) {
                printf("�ѻ��ˣ�������������������Ʒ�ơ�ͨ����������\n");
                scanf_s("%s", grandx, sizeof(grandx));
                scanf_s("%d", &channelx);
                scanf_s("%d", &numberx);
               
                continue;
            }
            else {
                break; // ��������ѯ��
            }
        }

        // �����Ʒ���
        for (int i = 0; i < 5; i++) {
            if (channel[i] == channelx) {
                if (numberx <= number[i]) {
                    number[i] -= numberx;
                    sum += numberx * price[i];
                }
                else {
                    printf("�������������ִ����������������롣\n");
                    scanf_s("%d", &numberx);
                    i--; // ����ȷ��ͬһͨ���µ���Ʒ
                }
                break; // �ҵ���Ӧͨ��������
            }
        }
    }
    if (sum > 0) {
        printf("��Ӧ��%dԪ����Ͷ��1Ԫ��2Ԫ��5Ԫ��ÿ��Ͷ���س���ֱ���ܽ����ڻ����Ӧ����\n", sum);
        int sum2 = 0;
        int pay = 0;
        while (sum2 < sum) {
            scanf_s("%d", &pay);
            for (h = h; h < 3; h++) {
                printf("�Ƿ��˻���һ����������������back����������no��\n");
                scanf_s("%s", s3, sizeof(s3));
                if (strcmp(s3, "back") == 0) {
                    printf("�ѻ��ˣ����������롣\n");
                    scanf_s("%d", &pay);
                    continue;
                }
                else {
                    break; // ��������ѯ��
                }
            }
            if (pay != 1 && pay != 2 && pay != 5) {
                printf("��������Ч�����������롣\n");
                continue; 
            }
            sum2 += pay; // ������Ͷ����
        }
        printf("֧����ɣ�����% d\n", sum2 - sum); // ��ӡ������
    }
    return 0;
}