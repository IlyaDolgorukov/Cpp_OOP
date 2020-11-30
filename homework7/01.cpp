#include <iostream>
#include <memory>

using namespace std;

class Date {
private:
    int day, month, year;
public:
    Date(int d, int m, int y) : day(d), month(m), year(y) { }
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    friend ostream& operator<< (ostream& out, const Date& date);
};

ostream& operator<< (ostream& out, const Date& date) {
    out << "Date: " << date.day << "." << date.month << "." << date.year << endl;
    return out;
}

unique_ptr<Date>& getMaxDate(unique_ptr<Date>& date1, unique_ptr<Date>& date2) {
    int d1 = date1->getDay() + date1->getMonth() * 31 + date1->getYear() * 365;
    int d2 = date2->getDay() + date2->getMonth() * 31 + date2->getYear() * 365;
    return d1 > d2 ? date1 : date2;
}

void swapDates(unique_ptr<Date>& date1, unique_ptr<Date>& date2) {
    unique_ptr<Date> date_tmp(move(date1));
    date1 = move(date2);
    date2 = move(date_tmp);
}

int main() {
    unique_ptr<Date> today = make_unique<Date>(14, 11, 2020);

    cout << *today;
    cout << "Today day: " << today->getDay() << endl;
    cout << "Today month: " << today->getMonth() << endl;
    cout << "Today year: " << today->getYear() << endl;

    unique_ptr<Date> date(move(today));

    if (today) {
        cout << "today is not null" << endl;
    } else {
        cout << "today is null" << endl;
    }
    if (date) {
        cout << "date is not null" << endl;
    } else {
        cout << "date is null" << endl;
    }

    unique_ptr<Date> date1 = make_unique<Date>(10, 11, 2020);
    unique_ptr<Date> date2 = make_unique<Date>(14, 11, 2020);

    cout << endl;
    cout << "MAX " << *getMaxDate(date1, date2);

    swapDates(date1, date2);
    cout << endl;
    cout << *date1;
    cout << *date2;

    return 0;
}
