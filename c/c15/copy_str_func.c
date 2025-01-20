/*
src를 dest로 복사, dset > src
*/
char copy_str(char *dest, const char *src) {
    while (*src) {
        *dest = *src;   //src의 문자를 dest로 이동
        src++;  //다음 문자 가리키기
        dest++; //따라서 다음 문자칸으로 이동
    }   //src의 마지막(NULL)에 도달하면 while를 탈출

    *dest = '\0';   //여기서의 dest는 src의 NULL과 같은 위치이므로 NULL값으로 \0를 대입.

    return 1;   //리턴은 맘대로?
}