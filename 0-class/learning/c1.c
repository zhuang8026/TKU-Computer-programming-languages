#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    
    int a = 5;
    int *p = &a; // &a gets the address of variable a
                 // p is a pointer to save an integer

    // %d 用來印「數字的值」
    // %p 用來印「記憶體位址」
    printf("Value of a: %p\n", p); // %p 印記憶體位址 (a 的位址 )
    printf("Value of a: %p\n", &p); // 指標 p 自己的位址
    printf("Value of a: %d\n", *p); // 取得 p 指向的位址裡面的值

    return 0;
}