// 題目5：讀入正整數 n，輸出右對齊的星號三角形（共 n 行）。
//     * 
//    ** 
//   *** 
//  ****
#include <stdio.h>

int main() {
    int n;
    int i, j;

    printf("請輸入正整數 n：");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) { // 判斷一共有幾行
        for (j = 1; j <= n - i; j++) // ex:2 -> 1 <= 2-1 ? '': return
            printf(" ");  // 空白
        for (j = 1; j <= i; j++) // ex:2 -> 1 <= 1 ? '*': return
            printf("*"); // 星號
        printf("\n"); // 換行
    }

    return 0;
}