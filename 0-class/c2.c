// 2. 請使用者輸入兩個整數運算元A, B 與一個運算代碼 (1:加, 2:減, 3:乘, 4:除)
// 並設計一個函式， 用用 switch 判斷並回傳運算結果 
// 若執行除法 必須使用浮點數轉型以保留小數點；若代碼錯誤則回傳 0.0
// 範例輸入:
// 請輸入兩個整數A, B: 5 2
// 請輸入運算碼 (1:+, 2:-, 3:*, 4:/): 4
// 範例輸出:
// 運算結果: 2.50

#include <stdio.h>

double calculate(int A, int B, int op) {
    switch (op) {
        case 1:
            return A + B; // 1:+
        case 2:
            return A - B; // 2:-
        case 3:
            return A * B; // 3:*
        case 4:
            return (double)A / B; // 4:/ 轉型為浮點數
        default:
            return 0.0; // 錯誤代碼
    }
}

int main() {
    int A, B, op;

    printf("請輸入兩個整數A, B: ");
    scanf("%d %d", &A, &B);

    printf("請輸入運算碼 (1:+, 2:-, 3:*, 4:/): ");
    scanf("%d", &op);

    printf("運算結果: %.2f\n", calculate(A, B, op));

    return 0;
}