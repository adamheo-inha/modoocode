/*포인터의 포인터*/
#include <stdio.h>
int main() {
    int a;
    int *pa;
    int **ppa;

    pa = &a;
    ppa = &pa;

    a = 3;
    /*
    a : 정수변수
    *pa : a 주소에 저장된 값 정수
    **ppa : ppa 주소에 저장된 값 정수
        *(*ppa) : *(pa의 주소에 담긴 값 즉, a의 주소)
            *(&a) : a의 주소에 담긴 값 , 3
    ---
    &a : a의 주소                   0xa
    pa : a의 주소가 담김              0xa
    *ppa : pa의 주소에 담김 값 == a의 주소 0xa
    ---
    &pa : pa의 주소       0xpa
    ppa : pa의 주소가 담김  0xpa
    */

    printf("a : %d // *pa : %d // **ppa : %d \n", a, *pa, **ppa);
    printf("&a : %p // pa : %p // *ppa : %p \n", &a, pa, *ppa);
    printf("&pa : %p // ppa : ppa : %p \n", &pa, ppa);
}