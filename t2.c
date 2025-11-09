// 題目2：讀入 n(n>=3) 與接著的 n 個整數，輸出第二小與第二大（需與最小/最大不同值）。
// 若所有值相同或無法找出，輸出「無法找出第二大/第二小」。
#include <stdio.h>
#define MAX_SIZE 100

int main() {
    int n;
    int i, j, temp;
    int list[MAX_SIZE]; // 預設最多 100 個整數

    printf("輸入整數 n (n>=3)：");
    scanf("%d", &n);
    if (n < 3) return 0;

    printf("輸入 %d 個整數：\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &list[i]);

    // 氣泡排序
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (list[j] > list[j + 1]) {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }

    // 找第二小（不同於最小）
    int second_min = -1, second_max = -1;
    for (i = 1; i < n; i++) {
        if (list[i] != list[0]) {
            second_min = list[i];
            break;
        }
    }

    // 找第二大（不同於最大）
    for (i = n - 2; i >= 0; i--) {
        if (list[i] != list[n - 1]) {
            second_max = list[i];
            break;
        }
    }

    if (second_min == -1 || second_max == -1)
        printf("無法找出第二大/第二小\n");
    else
        printf("第二小=%d 第二大=%d\n", second_min, second_max);

    return 0;
}