// 4. 請使用者輸入 5 個整數存入陣列， 並設計一個 bubbleSort 函式 將傳入的陣列內容由小到大排序， 
// 主程式叫該該函式後 利用用圈印印出排序後的陣列結果
// 範例輸入:
// 請輸入 5 個數字: 50 30 10 40 20
// 範例輸出:
// 排序結果: 10 20 30 40 50

#include <stdio.h>

void bubbleSort(int arr[], int n) {
    // 外層迴圈
    for (int i = 0; i < n - 1; i++) {
        // 內層迴圈
        for (int j = 0; j < n - 1 - i; j++) {
            // 若前面的數字比後面的數字大，就交換位置
            if (arr[j] > arr[j + 1]) {
                // 使用暫存變數 temp 來交換兩個數
                int temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[5];

    printf("請輸入 5 個整數：");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, 5);

    printf("排序後結果：");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

