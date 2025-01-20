/* 산술 연산 */
#include <stdio.h>
int main() {
    int a, b;
    a = 10; // =는 대입연산자 Assignment Operator
    b = 3;
    double c;
    c = 3;
    printf("a + b 는 : %d \n", a + b);
    printf("a - b 는 : %d \n", a - b);
    printf("a * b 는 : %d \n", a * b);
    printf("a / b 는 : %d \n", a / b);  // 몫, 정수형이기 때문에 소수점 이하는 출력 안됨
    printf("a %% b 는 : %d \n", a % b); // 나머지, %를 줄력하기 위해 %%로 사용
    // 정수형와 실수형은 연산이 가능하면 실수형으로 계산됨
    // 서식지정자도 실수형으로 사용.
    printf("a / c 는 : %f \n", a / c);
    printf("c / b 는 : %f \n", c / a); 
    return 0;
}