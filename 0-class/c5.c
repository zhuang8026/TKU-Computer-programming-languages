// 5. 請撰寫一個 C 語言程式 引入 <stdarg.h> 程式庫，並設計一個不定個數參數的函式，用交計算多個整數的平均值。
// 請在主程式中直接撰寫程式碼，分別呼叫該該函式計算以下兩組數據，
// 並印出結果：
// 數值：80, 90, 100 (共3 個)
// 數值：60, 60, 60, 60, 60 (共5 個)
// 輸出:
// 3 個平均: 90
// 5 個平均: 60

#include <stdio.h>
#include <stdarg.h>

double average(int count, ...) {
    va_list args; // 宣告「參數List」變數（va_list: 處理「不固定參數數量」的工具）
    va_start(args, count); // 從 count 參數後開始取（ex:80, 90, 100）

    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += va_arg(args, int); // 第一次 va_arg → 80
    }

    va_end(args); // 結束參數取用

    return (double)sum / count;
}

int main() {
    printf("3 個數平均 = %.0f\n", average(3, 80, 90, 100));
    printf("5 個數平均 = %.0f\n", average(5, 60, 60, 60, 60, 60));

    return 0;
}
