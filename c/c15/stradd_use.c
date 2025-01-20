#include <stdio.h>

int stradd(char *str1, char *str2);
int main() {
    char str1[100] = "Hello my name is ";
    char str2[] = "Psi";

    printf("합치기 이전 : %s \n", str1);

    stradd(str1, str2);

    printf("합치기 이후 : %s \n", str1);
}

int stradd(char *str1, char *str2) {
    while (*str1) {
        str1++;
    }// 공백도 while문에서 참이므로 아랫줄에 str1++은 필요없다.
    //str1++;
    while (*str2) {
        *str1 = *str2;
        str1++;
        str2++;
    }
    
    *str1 = '\0';

    return 0;
}