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
    void reserve(int size);
    //임의의 위치의 문자를 리턴하는 함수
    char at(int i) const;

    //삽입
    MyString& insert(int loc, const MyString& str);
    MyString& insert(int loc, const char * str);
    MyString& insert(int loc, char c);
    
    
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
    memory_capacity = string_length;
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
void MyString::reserve(int size) {
    if (size > memory_capacity) {
        char * prev_string_content = string_content;

        string_content = new char[size];
        memory_capacity = size;

        for (int i = 0; i != string_length; i++) string_content[i] = prev_string_content[i];

        delete[] prev_string_content;
    }
}


char MyString::at(int i) const {
    if (i >= string_length || i < 0)
        return '\0';
    else
        return string_content[i];

}

//삽입
//문자열
MyString& MyString::insert(int loc, const MyString& str) {
    // 삽입할려는 위치가 문자열 밖에 위치하면 삽입을 수행하지 않음.
    if (loc < 0 || loc > string_length) return *this;
    //기존 문자열이와 삽입되는 문자열의 일이가 할당되 메모리 공간(수)보다 크다면
    if (string_length + str.string_length > memory_capacity) {
        //할당 크기(수)를 바꾼다.
        memory_capacity = string_length + str.string_length;
        // 기존의 문자열을 임시 보관하고 할당된 메모리 크기를 조정한다.
        char * prev_string_content = string_content;
        string_content = new char[memory_capacity];

        //삽입하려는 부분 전까지 복사한다.
        int i;  // i는 삽입이후에 남음 부분을 복사할때 기준으로 사용하기위해 함수 for문이 아니라 함수 안에서 정의한다.
        for (i = 0; i < loc; i++) {
            string_content[i] = prev_string_content[i];
        }
        //삽입하여려는 문자열을 복사
        for (int j = 0; j != str.string_length; j++) {
            string_content[i+j] = str.string_content[j];
        }
        //기존의 문자열의 남은 부분을 복사
            //조건식과 증감식에 사용되는 변수가 이미 초기화 되어있으면 for문에서 생략가능
                //기존과 삽입될 문자열의 전체를 세야하므로 조건식이 아래와 같음
        for (; i < string_length; i++) {
                            //기존 + 더해진 문자열 길이
            string_content[i+string_length] = prev_string_content[i];
        }

        //사용을 다한 임시 저장 문자열을 해제
        delete[] prev_string_content;

        //현재 문자열의 길이을 최신화
        string_length = string_length + str.string_length;
        return *this;
    }
    // 기존 + 삽입 문자열의 크기가 기존 할당된 메모리에 들어갈때
    // 기준의 문자열의 마지막 메모리 공간부터 삽입될 위치의 메모리 공간까지
    // 삽입될 문자열의 크기 만큼 뒤로 민다
    /*예
    기존 메모리 공간 9개의 문자열4개이고
     0 1 2 3 4 5 6 7 8
    [a|b|c|d| | | | | ]
    삽입 문자열의 3개(3공간)이며
    (1(2(3
    [E|F|G]
    3에 삽입할때(네 번째 공간부터 삽입)
     0 1 2 3 4 5 6 7 8       0 1 2       3 4 5 6 7 8
    [a|b|c|d| | | | | ] ->  [a|b|c| | | |d| | | | | ]    
    */ 
    for (int i = string_length - 1; i >= loc; i--) {
        string_content[i+str.string_length] = string_content[i];
    }
    //메모리 공간의 loc번째부터 loc개는 앞 for문으로 비어있다.
    //거기에 삽입 문자열을 복사한다.
    /*
     0 1 2       3 4 5 6 7 8
    [a|b|c| | | |d| | | | | ]
    ->
     0 1 2(1(2(3 3 4 5 6 7 8
    [a|b|c|E|F|G|d| | | | | ]
    */
    for (int i = 0; i < str.string_length; i++) {
        string_content[i+loc] = str.string_content[i];
    }
    string_length = string_length + str.string_length;
    return *this;
}
MyString& MyString::insert(int loc, const char * str) {
    MyString temp(str);
    return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c) {
    MyString temp(c);
    return insert(loc, temp);
}
/*
int main() {
    MyString str1("very very very long string");
    str1.reserve(30);

  std::cout << "Capacity : " << str1.capacity() << std::endl;
  std::cout << "String length : " << str1.length() << std::endl;
  str1.println();
}
*/
int main() {
  MyString str1("very long string");
  MyString str2("<some string inserted between>");
  str1.reserve(30);

  std::cout << "Capacity : " << str1.capacity() << std::endl;
  std::cout << "String length : " << str1.length() << std::endl;
  str1.println();

  str1.insert(5, str2);
  str1.println();
}
