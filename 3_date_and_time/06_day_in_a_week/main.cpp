#include <iostream>

#include "boost/date_time/gregorian/gregorian.hpp"

using namespace std;
using namespace boost::gregorian;

int main(int argc, char** argv)
{
    date cppNow(2013, May, 12);
    
    cout << "Date to test is "<< cppNow << "." << endl;
    cout << "Day of year: " << cppNow.day_of_year() << endl;
    cout << "ISO week number: " << cppNow.week_number() << endl;
    cout << "Day of week: " << cppNow.day_of_week() << endl;
}