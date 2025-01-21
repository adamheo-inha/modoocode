class MyString {
    private:
    char* string_constent;  // 문자열 데이터를 가리키는 포인터
    int string_length;      // 문자열 길이

    public:
    // constructor
    // 문자 하나로 생성
    MyString(char c);

    // 문자열로 부터 생성
    MyString(const char* str);

    // 복사 생성자
    MyString(char c);

    
}