//Guess your lucky number
#include <iostream>

int main() {
    int lucky_number = 3;
    std::cout << " dj " << std::endl;

    int user_input;

    while (1) {
        std::cout << "input : ";
        std::cin >> user_input;//cin(키보드로 들어온 값을 변수에 저장)
        if(lucky_number == user_input) {
            std::cout << "Your guess is right!" << std::endl;
            break;
        } else {
            std::cout << "Think again" << std::endl;
        }
    }
    return 0;
}