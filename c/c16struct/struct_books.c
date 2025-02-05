#include <stdio.h>

char copy_str(char *dest, const char *src);

struct books{
    char name[30];
    char auth[30];
    char publ[30];
    int borrowed;
};

int main() {
    struct books Harry_Potter;
    //copy_str 아래 구현되어 있음.
    copy_str(Harry_Potter.name, "Harry Potter");
    copy_str(Harry_Potter.auth, "J.K. Rolling");
    copy_str(Harry_Potter.publ, "Scholastic");
    Harry_Potter.borrowed = 0;
    
    printf("책 이름 : %s \n", Harry_Potter.name);
    printf("저자 이름 : %s \n", Harry_Potter.auth);
    printf("출판사 이름 : %s \n", Harry_Potter.publ);

    return 0;
}

//문자열의 src에서 dest로 복사하는 함수
// 문자열의 주소를 포인터로 받고
char copy_str(char *dest, const char *src) {
    while (*src) {
        *dest = *src;
        src++;
        dest++;
    }

    *dest = '\0';

    return 1;
}