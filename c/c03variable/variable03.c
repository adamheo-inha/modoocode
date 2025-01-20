/* 변수 알아보기 3*/
#include <stdio.h>
int main() {
    //float형임을 알리기 위해 숫자 마지막에 f를 붙임
    float a = 3.141592f;
    double b = 3.141592;
    int c = 3.141592;
    printf("a : %f \n", a);
    printf("b : %f \n", b);
    // 정수형으로 정의한 변수는 소수를 입력해도 정수부만 받아 출력
    printf("c : %d \n", c);
    return 0;
}