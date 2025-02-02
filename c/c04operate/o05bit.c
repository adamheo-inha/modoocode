/* 비트 연산 */
#include <stdio.h>
int main() {
    int a = 0xAF; // 10101111
    int b = 0xB5; // 10110101

    printf("%x \n", a & b);     // a & b = 10100101
    printf("%x \n", a | b);     // a | b = 10111111
    printf("%x \n", a ^ b);     // a ^ b = 00011010
    printf("%x \n", ~a);        // ~a = 1...1 01010000 int형 4bytes의 빈부분은 0인데 반전되엇 1이됨
    printf("%x \n", a << 2);    // a << 2 = 10111100
    printf("%x \n", b >> 3);    // b >> 3 = 11110110

    return 0;
}