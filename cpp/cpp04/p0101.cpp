#include <iostream>

class Date {
    private:
    // 현재 년 월 일
    int year_;
    int month_;  // 1 부터 12 까지.
    int day_;    // 1 부터 28,30,31 까지.
    
 public:
    int Month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//1월부터 12월까지 마지막날 배열
    int lastday = 0;  //달의 마지막날 28,30,31

// 그 달의 마지막 날
    void LastDayOfMonth(int month_) {
        lastday = Month[month_ - 1];
    }//LastDayOfMonth
    
// 초기 날짜 설정
    void SetDate(int year = 0, int month = 0, int day = 0) {
        year_ = year;
        month_ = month;
        day_ = day;

        std::cout << "원하시는 년도를 숫자만 입력하세요. ";
        std::cin >> year_;
        std::cout << "원하시는 달을 숫자만 입력하세요. ";
        std::cin >> month_;
        // 1~12 값이 들어올때까지 반복
        while (1) {
            // 1부터 12사이에 들어왔는지 확인
            if(1 <= month_ && month_ <= 12) {
                LastDayOfMonth(month_);
                break;
                //조건이 성립해서 while exit
            // 1부터 12이외에 입력값이 들어와 재입력 요청과 값 입력과 수정
            } else {
                std::cout << "달을 다시 입력해줘요." << std::endl;
                std::cin >> month_;
            }
        }//while ()


        
        std::cout << "원하시는 날짜를 숫자만 입력하세요. ";
        std::cin >> day_;
        // 월 입력에서 얻은 마지막날 조건확인
        char notoverinputagain[] = "일을 넘지마세요. 다시 입력해주세요.";
        if (lastday == 31) {
            while(1) {
                // 달에 맞는 날안에 들어오면 while문 탈출
                if (1 <= day_ && day_ <= 31) {
                    break;
                // 들어오지 못하면 넘었다는 문구 출력과 최대날 변수에 입력
                } else {
                    std::cout << lastday << notoverinputagain << std::endl;
                    std::cin >> day_;
                }
            }    
        } else if (lastday == 30) {
            while(1) {
                if (1 <= day_ && day_ <= 30) {
                    break;
                } else {                    
                    std::cout << lastday << notoverinputagain << std::endl;
                    std::cin >> day_;                                                                                    
                }
            }
        } else if (lastday == 28) {
            while(1) {
                if (1 <= day_ && day_ <= 28) {
                    break;
                } else {                    
                    std::cout << lastday << notoverinputagain << std::endl;
                    std::cin >> day_;
                }
            }
        }//if()
    }//SetDate()


    // 날짜 더하기
    void AddDay(int inc) {
        for (int i = 0; i < inc; i++) {
            day_++;
            if (lastday == 31 && day_ == 32) {
                day_ = 1;
                AddMonth(1);
            } else if (lastday == 30 && day_ == 31) {
                day_ = 1;
                AddMonth(1);
            } else if (lastday == 28 && day_ == 29) {
                day_ = 1;
                AddMonth(1);
            }
        }
    }//AddDay()

    void AddMonth(int inc) {
        for (int i = 0; i < inc; i++) {
            month_++;
            LastDayOfMonth(month_);
            if(month_ == 13) {
                month_ = 1;
                AddYear(1);
            }
        }
        
        if (day_ > lastday) {
            day_ = lastday;
        }
    }//AddMonth()

    void AddYear(int inc){
        year_ += inc;
    }//AddYear()

    //날짜 출력
    void ShowDate() {
        std::cout << year_ << "년 " << month_ << "월 " << day_ << "일" << std::endl;
    }//ShowDate()
};

int main() {
    int state = 0;
    int inc = 0;
    int theend = 0;
    Date date;

    date.SetDate();
    // 추가 및 결과 출력
    while(1) {
        //while 탈출 종료
        if (theend == 1) break;
        std::cout << "원하시는 기능을 입력하세요." << std::endl << "1번 년도 추가" << std::endl << "2번 월 추가" << std::endl << "3번 일 추가" << std::endl << "4번 날짜보기" << std::endl << "5번 종료" << std::endl;
        std::cin >> state;
        switch (state) {
            case 1:
                std::cout << "몇 년 추가 하시겠습니까? : ";
                std::cin >> inc;
                date.AddYear(inc);
                //date.ShowDate();
                break;
            case 2:
                std::cout << "몇 달 추가 하시겠습니까? : ";
                std::cin >> inc;
                date.AddMonth(inc);
                //date.ShowDate();
                break;
            case 3:
                std::cout << "몇 일 추가 하시겠습니까? : ";
                std::cin >> inc;
                date.AddDay(inc);
                //date.ShowDate();
                break;
            case 4:
                 date.ShowDate();
                break;
            case 5:
                theend = 1;
                break;
    
        default:
            break;
        }
    }

    return 0;
}