#include <stdio.h>

int copy_str(char *src, char *dest);    //여기와 원본의 인수순서가 달라도 된다. 원본의 순서를 따라간다.
int main() {
    char str1[] = "hello";      //dest
    char str2[] = "hihello";    //src

    printf("복사 이전 : %s \n", str1);
    copy_str(str1, str2);   //dest=str1, src=str2 로 생각
                            // 배열의 이름은 배열의 첫번쨰 원소의 주소를 가르키다.
                            // dest, src는 주소를 담아 가르키는 포인터.
    printf("복사 이후 : %s \n", str1);
}

/*
src를 dest로 복사, dset > src
*/
int copy_str(char *dest, char *src) {
    while (*src) {
        *dest = *src;   //src의 문자를 dest로 이동
        // *를 사용 하여 현재 주소의 담긴 char를 사용.
        src++;  //다음 문자 가리키기
        dest++; //따라서 다음 문자칸으로 이동
    }   //src의 마지막(NULL)에 도달하면 while를 탈출

    *dest = '\0';   //여기서의 dest는 src의 NULL과 같은 위치이므로 NULL값으로 \0를 대입.

    return 1;   //리턴은 맘대로?
}