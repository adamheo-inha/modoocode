#include <iostream>

class Animal {
    private:        //접근 지시자 : 외부의 접근 유무를 지시. // private는 객체내에서 보호된다는 의미.
        int food;
        int weight;

    public:         //접근 지시자 : 외부의 접근 유무를 지시. // public는 외부에서 접근 가능.
    void set_animal(int _food, int _weight) {
        food = _food;
        weight = _weight;
    }
    void increase_food(int inc) {
        food += inc;
        weight += (inc/3);
    }
    void view_state() {
        std::cout << "이동물의 food   : " << food << std::endl;
        std::cout << "이동물의 weight : " << weight << std::endl;
    }
}; //주의 세미콜롤

int main() {
    Animal animal;
    animal.set_animal(100, 50);
    animal.increase_food(30);

    animal.view_state();
    return 0;
}