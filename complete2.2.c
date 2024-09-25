#include <stdio.h>
#include <string.h>
int main() {
    char grand[100][100]; // 商品名称
    int channel[5] = { 0 };
    int price[5] = { 0 };
    int number[5] = { 0 };
    int n = 0;
    char s1[] = "END";
    char s2[100];
    char s3[100];
    int q = 0; // 记录回退次数
    int h = 0; // 记录在买货阶段的回退次数
    printf("请输入商品名称、通道、单价、数量，中间用空格隔开。\n");
    do {
        // 修改为正确使用 scanf_s
        scanf_s("%s", grand[n], sizeof(grand[n]));
        scanf_s("%d", &channel[n]);
        scanf_s("%d", &price[n]);
        scanf_s("%d", &number[n]);
        // 输入数据合法性检查
        if (channel[n] < 1 || channel[n] > 5) {
            printf("只能摆到1-5通道,请重新输入通道。\n");
            scanf_s("%d", &channel[n]);
        }
        if (number[n] < 1 || number[n] > 50) {
            printf("单个通道最多摆放50个货物，请重新输入货物数量。\n");
            scanf_s("%d", &number[n]);
        }

        // 回退操作
        for (q = 0; q <= 2; q++) {
            printf("是否退回上一步操作？是请输入back，否请输入no。\n");
            scanf_s("%s", s3, sizeof(s3));
            if (strcmp(s3, "back") == 0) {
                h++;
                if (h > 3) {
                    printf("已经达到最大回退次数，不能再回退。\n");
                    h--;  // 恢复回退次数
                }
                else {
                    printf("已回退，请重新输入商品名称、通道、单价、数量。\n");
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

        printf("是否继续加入下一样商品？是请输入YES，否请输入END。\n");
        scanf_s("%s", s2, sizeof(s2));
        if (strcmp(s1, s2) == 0) {
            printf("放货结束。\n");
            break;
        }
        else {
            n++;
        }

    } while (n < 5);
    if (n == 5) {
        printf("摆货通道已用完。\n");
    }
    printf("摆货结束，开始买货。请依次输入所买货物的品牌、通道、数量。输入END停止购买。\n");
    int sum = 0;
    char grandx[100];
    int channelx = 0;
    int numberx = 0;
    while (number[0] != 0 || number[1] != 0 || number[2] != 0 || number[3] != 0 || number[4] != 0) {
        scanf_s("%s", grandx, sizeof(grandx));
        if (strcmp(grandx, s1) == 0) {
            printf("停止购买。\n");
            break;
        }
        scanf_s("%d", &channelx);
        scanf_s("%d", &numberx);

        // 检查输入合法性
        if (channelx < 1 || channelx > 5) {
            printf("通道应在1-5之间，请重新输入。\n");
            continue;
        }

        // 回退操作
        for (h = h; h < 3; h++) {
            printf("是否退回上一步操作？是请输入back，否请输入no。\n");
            scanf_s("%s", s3, sizeof(s3));
            if (strcmp(s3, "back") == 0) {
                printf("已回退，请重新输入所买货物的品牌、通道、数量。\n");
                scanf_s("%s", grandx, sizeof(grandx));
                scanf_s("%d", &channelx);
                scanf_s("%d", &numberx);
               
                continue;
            }
            else {
                break; // 结束回退询问
            }
        }

        // 检查商品存货
        for (int i = 0; i < 5; i++) {
            if (channel[i] == channelx) {
                if (numberx <= number[i]) {
                    number[i] -= numberx;
                    sum += numberx * price[i];
                }
                else {
                    printf("输入数量大于现存数量，请重新输入。\n");
                    scanf_s("%d", &numberx);
                    i--; // 继续确认同一通道下的商品
                }
                break; // 找到对应通道后跳出
            }
        }
    }
    if (sum > 0) {
        printf("共应付%d元，请投入1元，2元或5元，每次投入后回车，直到总金额大于或等于应付金额。\n", sum);
        int sum2 = 0;
        int pay = 0;
        while (sum2 < sum) {
            scanf_s("%d", &pay);
            for (h = h; h < 3; h++) {
                printf("是否退回上一步操作？是请输入back，否请输入no。\n");
                scanf_s("%s", s3, sizeof(s3));
                if (strcmp(s3, "back") == 0) {
                    printf("已回退，请重新输入。\n");
                    scanf_s("%d", &pay);
                    continue;
                }
                else {
                    break; // 结束回退询问
                }
            }
            if (pay != 1 && pay != 2 && pay != 5) {
                printf("输入金额无效，请重新输入。\n");
                continue; 
            }
            sum2 += pay; // 更新已投入金额
        }
        printf("支付完成，找零% d\n", sum2 - sum); // 打印找零金额
    }
    return 0;
}