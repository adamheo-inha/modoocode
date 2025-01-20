#include <stdio.h>
                // 정수형 변수의 주소를 담는 포인터
int change_val(int *pi) {
    printf("--- 함수 안에서 ---\n");
                // 함수밖에 있는 주소를 받음
    printf("pi 값 %p \n", pi);
                // 받은 주소에 있는 값을 출력
    printf("pi 가리키는 값 %d \n", *pi);
    //받은 주소에 있는 값을 변경
    *pi = 3;

    printf("----End--- \n");
    return 0;
}
int main() {
    int i = 0;

    printf("i address : %p \n", &i);
    printf("before calling velue i : %d \n", i);
            //i의 주소값을 함수로 전달(및 변경)
    change_val(&i);
    printf("after calling velue i : %d \n", i);

    return 0;
}