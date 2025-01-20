#include <iostream>

class Date {
    private:
    int year_;
    int month_;  // 1 부터 12 까지.
    int day_;    // 1 부터 31 까지.

    bool Month28 = (month_ == 2);
    bool Month30 = (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11);
    bool Month31 = (month_ == 1 || month_ == 3 || month_ == 5 || month_ == 7 || month_ == 8 || month_ == 10 || month_ == 12);

 public:
    //함수 내부 초기화 
    void SetDate(int year, int month, int day) {
        year_ = year;
        month_ = month;
        day_ = day;

    }
    // 날짜 더하기
    void AddDay(int inc) {
        day_ += inc;
        if (Month31) {
            while(day_ > 31) {
                day_ -= 31;
                AddMonth(1);
            }
        } else if (Month30) {
            while(day_ > 30) {
                day_ -= 30;
                AddMonth(1);
            }
        } else if (Month31) {
            while(day_ > 28) {
                day_ -= 28;
                AddMonth(1);
            }
        } else {
            std::cout << "월정 정정 해주세요." << std::endl;
        }
    }
    void AddMonth(int inc) {
        month_ += inc;
        if(month_ > 12) {
            month_ -= 12;
            AddYear(1);
        }
    }
    void AddYear(int inc){
        year_ += inc;
    }
    //날짜 출력
    void ShowDate() {
        std::cout << year_ << "년 " << month_ << "월 " << day_ << "일" << std::endl;
    }    
};

int main() {
    int day = 0;
    int month = 0;
    int year = 0;
    Date date;
    bool Month28 = (month_ == 2);
    bool Month30 = (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11);
    bool Month31 = (month_ == 1 || month_ == 3 || month_ == 5 || month_ == 7 || month_ == 8 || month_ == 10 || month_ == 12);

    // 날짜초기화
    std::cout << "몇 년?  : ";
    std::cin >> year;
    
    std::cout << "몇 월? : ";
    std::cin >> month;

    while (1) {
        std::cout << "몇 일? : ";
        std::cin >> day;
        if (Month31) {
            if (day > 31) {
            std::cout << "다시 입력해주세요" << std::endl;

            std::cin >> month;
        } else if (Month30) {

        }

    }

    } 
        



    date.SetDate(year, month, day);
    date.ShowDate();



    return 0;
}