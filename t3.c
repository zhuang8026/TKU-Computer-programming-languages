// 題目3：讀入整數 n。若 n<=0 印「程式結束」；
// 否則判斷是否為完全平方數，分別輸出「n 是完全平方數」或「n 不是完全平方數」。
// 完全平方數是 「某個整數 × 自己」（ex: 3x3=9(yes), ?x? = 8(no)）
#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;

    printf("輸入整數 n：");
    scanf("%d", &n);

    if (n <= 0) {
        printf("程式結束\n");
        return 0;
    }

    bool is_square = false; 
    for (int i = 1; i * i <= n; i++) {
        if (i * i == n) {
            is_square = true;
            break;
        }
    }

    if (is_square)
        printf("%d 是完全平方數\n", n);
    else
        printf("%d 不是完全平方數\n", n);

    return 0;
}