#include <iostream>

// 구조체(일종의 Type?)와 값들
typedef struct Animal{
    char name[30];
    int age;

    int health;
    int food;
    int clean;
} Animal;

// 동물 생성 및 초기화
                    // Animal Type의 pointer animal을 인수로 받음)
void create_animal(Animal *animal) {
    std::cout << "동물의 이름? ";
    std::cin >> animal->name;
    
    std::cout << "age? ";
    std::cin >> animal->age;

    animal->health = 100;
    animal->food = 100;
    animal->clean = 100;
}
// 놀기
void play(Animal *animal) {
    animal->health += 10;
    animal->food -= 20;
    animal->clean -= 30;
}
// 하루 경과
void one_day_pass(Animal *animal) {
    animal->health -= 10;
    animal->food -= 30;
    animal->clean -= 20;
}
// 상태 확인
void show_stat(Animal *animal) {
    std::cout << animal->name << "의 상태" << std::endl;
    std::cout << "체력   :" << animal->health << std::endl;
    std::cout << "배부름 :" << animal->food << std::endl;
    std::cout << "청결   :" << animal->clean << std::endl;
}
// 메인
int main() {
    //구조체 Animal 크기의 포인터 10개를 가지는 배열 10개 
    Animal *list[10];
    int animal_num = 0;

    for (;;) {
        std::cout << "1. add animal " << std::endl;
        std::cout << "2. play " << std::endl;
        std::cout << "3. show stat "<< std::endl;

        int input;
        std::cin >> input;

        switch (input) {
            int play_with;
            case 1:
                                    // Animal 크기의 메모리를 확보
                //확보한 메모리의 주소를 animal_num번째 포인트 배열원소에 할당
                list[animal_num] = new Animal;
                create_animal(list[animal_num]);

                animal_num++;
                break;

            case 2:
                // 이름이 아니라 배열의 순서를 입력해야됨.
                std::cout << "Who are you going to play with? : ";
                std::cin >> play_with;
                    // 현재 정의된 동물수보다 작은 값이 들어왔는지 비교.
                if (play_with < animal_num) play(list[play_with]);

                break;

            case 3:
                std::cout << "Whose are you going to see? : ";
                std::cin >> play_with;

                if (play_with < animal_num) show_stat(list[play_with]);

                break;
        }
        for (int i = 0; i != animal_num; i++) {
            one_day_pass(list[i]);
        }  
    }
    for (int i = 0; i != animal_num; i++) {
        delete list[i];
    }
}