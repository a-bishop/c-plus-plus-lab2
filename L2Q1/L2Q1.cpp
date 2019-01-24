
//  L1Q2
//
//  author: Andrew Bishop

#include <iostream>
using namespace std;

int main() {
    
    enum class Month { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEPT, OCT, NOV, DEC };
    enum class Day { Saturday, Sunday, Monday, Tuesday, Wednesday, Thursday, Friday };
    
    int year, month, day;
    
    cout << "Enter year (eg 2012): ";
    cin >> year;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter the day of the month (1-31): ";
    cin >> day;
    
    // if month is Jan or Feb, month is 13 or 14, year is year minus one
    if (month == static_cast<int>(Month::JAN)) {
        month = 13;
        year -= 1;
    }
    else if (month == static_cast<int>(Month::FEB)) {
        month = 14;
        year -= 1;
    }
    
    int yearCent = year % 100;
    int century = year / 100;
    
    int dayOfWeek = (day + ((26 * (month + 1)) / 10) + yearCent + (yearCent / 4) + (century / 4) + (5 * century)) % 7;
    
    
    Day dayWord = Day(dayOfWeek);
    
    switch (dayWord) {
        case Day::Saturday:
            cout << "Saturday" << endl;
            break;
        case Day::Sunday:
            cout << "Sunday" << endl;
            break;
        case Day::Monday:
            cout << "Monday" << endl;
            break;
        case Day::Tuesday:
            cout << "Tuesday" << endl;
            break;
        case Day::Wednesday:
            cout << "Wednesday" << endl;
            break;
        case Day::Thursday:
            cout << "Thursday" << endl;
            break;
        case Day::Friday:
            cout << "Friday" << endl;
            break;
    }
    
    return 0;
}
