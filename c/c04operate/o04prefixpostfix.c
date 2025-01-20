/* prefix, postfix  */
#include <stdio.h>
int main() {
    int a = 1;

    printf("++a : %d \n", ++a);

    a = 1;
    // 후위형은 현재 변수의 값을 먼저 돌려주고 연산을 진행
    // 그래서 1이 출력
    // o03에서 d는 후위형 연산이 끝난 후에 값을 돌려주기 때문에 2가 출력
    printf("a++ : %d \n", a++);
    printf("a : %d \n", a);

    return 0;
}