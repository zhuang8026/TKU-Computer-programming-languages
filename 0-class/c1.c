// 1. 請宣告兩個整數變數x, y， 使用scanf 輸入這兩個整數的值， 並設計一個swap的函式， 
// 用交換兩兩個變數的值， 換兩後的結果必須由主程式 (main) 負責印出 以驗證換兩是否成功
// 範例輸入:
// 請輸入兩個整數x, y: 100 500
// 範例輸出:
// 換兩前: x=100, y=500
// 換兩後: x=500, y=100

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y;

    printf("請輸入兩個整數 x y：");
    scanf("%d %d", &x, &y);

    printf("交換前：x = %d, y = %d\n", x, y);

    swap(&x, &y);

    printf("交換後：x = %d, y = %d\n", x, y);

    return 0;
}
