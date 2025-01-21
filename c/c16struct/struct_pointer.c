#include <stdio.h>
//하나의 형(type)
struct test {
    int a, b;
};
int main() {
    struct test st;
    struct test *ptr;

    ptr = &st;
/* 
    (*ptr).a = 1;
    (*ptr).b = 2;
 */
    ptr -> a = 1;
    ptr->b = 2;

    printf("st의 a 멤버 : %d \n", st.a);
    printf("st의 b 멤버 : %d \n", st.b);

    return 0;
}