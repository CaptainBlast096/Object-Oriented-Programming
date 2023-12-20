/***************************************************************************
 * Title:               Lab 1 Part A
 * Author:              Jaleel Rogers
 * Email:               jrogers1239@floridapoly.edu
 * Creation date:       10/17/2022 @ 12:10 PM
 * Modification date:   10/17/2022 @ 9:20 PM
 * Description:         Write a complete C++ program that displays your first name, last name, and number
                            of seconds you should dedicate to this course.

                        To calculate number of seconds, consider conditions below. You should perform all calculations in your code:
                            1) 13 weeks of studying.
                            2) Two 1.25-hour lectures per week.
                            3) Two 1-hour midterm exams.
                            4) One 2-hour final exam.
                            5) 2.5 hours of self-study per week.
 **************************************************************************/
#include <iostream>
using namespace std;
int main()
{

    int weeksStudying = 13; // 13 Weeks of studying
    double lecturesWeek = 1.25; // Two lectures per week
    int midtermExam = 1; // Two midterm exams
    int finalExam = 2; // One final exam
    double selfStudying = 2.5;
    int secondsPerHour = 3600;

    // Same code but with no variables (((1.25* 2) * 13) + (1 *2) +(2) + (13 * 2.5)) * 3600;
    double secondsStudying = (((lecturesWeek * 2) * weeksStudying) + (midtermExam * 2) +(finalExam) + (weeksStudying * selfStudying)) * secondsPerHour;

    std::cout << "First Name: Jaleel" << "\nLast Name: Rogers" << "\nI am supposed to spend " << secondsStudying << " seconds studying C++ Programming" << std::endl;


    return 0;
}
