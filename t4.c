// 題目4：輸入一串整數，以 0 作為結束標記；只累加負數的總和。
// 若沒有負數則輸出「無負數」，否則輸出總和。
#include <stdio.h>

int main() {
    int num;
    int sum = 0; // 最後要輸出的總數
    int count = 0;   // 記錄有幾個負數

    printf("請輸入整數序列 (以 0 結束)：\n");
    scanf("%d", &num); 

    while (num != 0) { // 先去除 0
        if (num < 0) { // 判斷是否為負數
            sum += num; // 負數總和
            count++; // 記錄負數個數
        }
        scanf("%d", &num);  // 再輸入下一個
    }

    if (count == 0)
        printf("無負數\n");
    else
        printf("負數總和=%d\n", sum);

    return 0;
}