/* * 연산자 */
#include <stdio.h>

int main() {
    int *p;
    int a;

    p = &a;  //변수a의 주소를 포인터p에 대입
    a = 2;
    //*p = 3;  // 포인터p에 있는 주소로 3을 대입, 그 주소는 변수a의 주소이므로 a에 3이 대입

    printf("a의 값 : %d \n", a);
    printf("*p의 값 : %d \n", *p);

    return 0;
}