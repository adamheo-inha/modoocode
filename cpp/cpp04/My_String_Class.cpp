#include <iostream>

// string.h 는 strlen 때문에 include 했는데, 사실 여러분이 직접 strlen
// 과 같은 함수를 만들어서 써도 됩니다.
#include <string.h>

class MyString {
    char* string_content;   // 문자열 데이터를 가리키는 포인터
    int string_length;      // 문자열 길이
    int memory_capacity;    // 현재 할당된 메모리 공간의 크기


    public:
    // 문자 하나로 생성
    MyString(char c);
    // 문자열로 부터 생성
    MyString(const char* str);
    // 복사 생성자
    MyString(const MyString& str);
    //소멸자
    ~MyString();

    int length() const;

    void print() const;
    void println() const;

    // assing
    MyString& assign(const MyString& str);
    MyString& assign(const char * str);
    //현재 문자열의 메모리 크기
    int capacity() const;
    //문자열의 크기를 미리 예약
    int reserve(int size);
    
    
};
// 문자 하나를 저장
MyString::MyString(char c) {
    //문자 하나이므로 문자열을 1칸 크기에 메모리 공간을 할당
    string_content = new char[1];
    //할당받은 메모리의 첫 공간에 받은 문자를 대입
    string_content[0] = c;
}
//문자열을 저장
                    //str에 저장되는 char 타입의 주소를 바뀔수 있지만
                    //주소에 담겨 있는 값은 변경할 수 없다.
MyString::MyString(const char* str) {
    //받은 문자열의 길이를 확인하고 길이값으로 저장
    string_length = strlen(str);
    //길이에 맞는 메모리 공간을 할당
    string_content = new char[string_length];
    //응~ 복사야
    for (int i = 0; i != string_length; i++) {
        string_content[i] = str[i];
    }
}
MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) string_content[i] = str.string_content[i];
}
//소멸자 메모리 할당 해제
MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

void MyString::print() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }
}
void MyString::println() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }

    std::cout << std::endl;
}

// assing
//생성
MyString& MyString::assign(const char * str) {
    int str_length = strlen(str);
    if (str_length > memory_capacity) {
        delete[] string_content;
        string_content = new char[str_length];
        memory_capacity = str_length;
    }
    for (int i = 0; i != str_length; i++) {
        string_content[i] = str[i];
    }
    string_length = str_length;

    return *this;
}
//복사
MyString& MyString::assign(const MyString& str) {
    // 받은 str이 더 길면
    if (str.string_length > memory_capacity) {
        //기존 메모리 공간 해제
        delete[] string_content;
        //받은 문자열에 맞는 메모리 공간 할당
        string_content = new char[str.string_length];
        //더 큰 문자열의 크기로 값을 변경
        memory_capacity = str.string_length;
    }
    //만든 메모리 공간에 받은 문자열을 대입(복사)
    for (int i = 0; i != str.string_length; i++) {
        string_content[i] = str.string_content[i];
    }
    //길이에 대한 값도 변경
    string_length = str.string_length;
            //object.assign에서 object를 반환
    return *this;
}
int MyString::capacity() const { return memory_capacity; }
int MyString::reserve(int size) {
    if (size > memory_capacity) {

    }
}
int main() {
    MyString str1("hello world!");
    MyString str2(str1);

    str1.println();
    str2.println();
}