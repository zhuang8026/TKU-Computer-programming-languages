// 題目1：讀入兩個正整數 a、b（需 a <= b；否則持續重新讀入）。
// 輸出 [a,b] 之間奇數的「數量」與「平均值」（到小數點後兩位）。
// 若沒有奇數則輸出「無奇數」。
#include <stdio.h>

int main() {
    int a, b;
    int i, count = 0, sum = 0;

    // 要求 a <= b
    do {
        printf("輸入兩個正整數 a b：");
        scanf("%d%d", &a, &b);
    } while (a <= 0 || b <= 0 || a > b);

    for (i = a; i <= b; i++) {
        if (i % 2 != 0) {   // 奇數判斷（無法被2整除）
            count++; // 計算奇數數量
            sum += i;
            printf("%d ", sum);
        }
    }

    if (count == 0)
        printf("無奇數\n");
    else
        printf("奇數數量=%d 平均值=%d\n", count, sum / count);

    return 0;
}