#include <stdio.h>
// 구조체 생성
struct Human {
    int age;
    int height;
    int weight;
};                  // ;를 붙여야한다.

int main() {
    // 구조제를 하나의 type(int나 char)처럼 사용하여 Psi를 생성
    struct Human Psi;

    Psi.age = 99;
    Psi.height = 185;
    Psi.weight = 80;

    printf("Psi 에 대한 정보 \n");
    printf("나이 : %d \n", Psi.age);
    printf("키 : %d \n", Psi.height);
    printf("몸무게 : %d \n", Psi.weight);

    return 0;
}