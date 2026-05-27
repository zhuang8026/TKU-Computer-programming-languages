// 3. 宣告一個包含 5 個整數的陣列 並使用 scanf 讓使用者輸入數值 請設計一
// 個函式 接收該陣列並找出最大值 最後將最大值回傳給主程式印出
// 範例輸入:
// 請輸入 5 個數字: 10 32 -5 100 20
// 範例輸出:
// 陣列中的最大值是: 100

#include <stdio.h>

int findArrayMaxValue(int arr[], int size) {
    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

int main() {
    int arr[5];

    printf("請輸入 5 個整數：");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    printf("最大值為：%d\n", findArrayMaxValue(arr, 5));

    return 0;
}
