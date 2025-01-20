#include <iostream>

int main() {
    int arr_size;
    std::cout << "array size : ";
    std::cin >> arr_size;
                // arr_size 크기의 int 배열을 heap에 할당
    // list이름의 포인터로 배열 주소를 받아 가르킴 
    int *list = new int[arr_size];
    
        // i는 for문 안에서만 정의됨
        // 다음 for문에 있는 i와는 다른 i
    // 배열의 크기(arr_size)만큼 반복
    for (int i = 0; i < arr_size; i++) {
        std::cin >> list[i];
    }
    for (int i = 0; i < arr_size; i++) {
        std::cout << i << "th element of list : " << list[1] << std::endl;
    }
    delete[] list;
    return 0;
}