/*
Name: Jaleel Rogers
Class: COP3337.04
Date: 09/18/22
Summary: Use the lottery game in command prompt in order to modify the code, 
			complete the 4 TODOs and test implementation using the T command.
*/
// This lab (project) is an extension of the book example "Lottery Using Strings"
// https://liveexample.pearsoncmg.com/liang/cpp3e/html/LotteryUsingStrings.html

#include <iostream>
#include <iomanip>
#include <string> // for using strings
#include <ctime> // for time function
#include <cstdlib> // for rand and srand functions
#include <fstream>
#include <cmath>
using namespace std;

#define PLAYERS     10 // number of players
#define LOTTERYBALLS    4 // number of digits in the lottery

// global data structure
// 10 elements array, fill in circularly, if it is played 11 times, 
// the information of the first player will be overwritten
string gPlayerNames[PLAYERS];
string gPlayerGuess[PLAYERS];
string gPlayerLottery[PLAYERS];
int gPlayerAward[PLAYERS];
int gSortedAward[PLAYERS];
int gcurrentplayer = 0; // to index global arrays
int gtimesplayed = 0; // how many times played so far?


// function forward declaration
string GenerateLottery();
string GuessLottery();
int DecideAward(const string& lottery, const string& guess);
void SortAwards(); // in decreasing order
void PrintResults();
void DoAwardStatistics();
void SaveLottery();
void LoadLottery();
void TestLottery();

int main()
{

    // 1. initialize the ramdom number generator
    // Refer to: https://liveexample.pearsoncmg.com/liang/cpp3e/html/LotteryUsingStrings.html
    srand(time(0));

    // help information
    cout << "Welcome to the lottery game!\n";
    cout << "============================\n";

    string helpinfo = "The game starts asking for a command:\n\
        h: show this help information\n\
        n: start a new game\n\
        p: print lottery results\n\
        o: sort the awards in decreasing order\n\
        d: display the statistics about the awards\n\
        t: test the program\n\
        s: save lotteries played\n\
        l: load lotteries played\n\
        q: quit the game\n\
        ";
    cout << helpinfo << endl;

    // variables
    char command = 'n';
    char yn = 'n';
    string lottery, guess;
    string playername;


    // main lottery logic
    while (true)
    {
        cout << "Please enter your command: ";
        cin >> command;
        switch (command)
        {
            case 'h':
            case 'H':
                cout << helpinfo << endl;
                break;
            case 'n':
            case 'N':
                cout << "Please enter your name: ";
                //cin.clear(); // refer to: https://stackoverflow.com/questions/7786994/c-getline-isnt-waiting-for-input-from-console-when-called-multiple-time
                //cin.sync();
                //cin.ignore();
                //getline(cin, gPlayerNames[gcurrentplayer]);
                cin >> gPlayerNames[gcurrentplayer];


                gPlayerLottery[gcurrentplayer] = GenerateLottery();
                gPlayerGuess[gcurrentplayer] = GuessLottery();

                gPlayerAward[gcurrentplayer] = DecideAward(gPlayerLottery[gcurrentplayer], gPlayerGuess[gcurrentplayer]);
                // Move to the next slot of the arrays
                gcurrentplayer++;
                gcurrentplayer %= PLAYERS; // wrap back to the beginning when the arrays are filled up

                gtimesplayed++;
                break;
            case 'l':
            case 'L':
                cout << "loading lottery records..." << endl;
                LoadLottery();
                break;
            case 'o':
            case 'O':
                SortAwards();
                break;
            case 's':
            case 'S':
                cout << "saving lottery records..." << endl;
                SaveLottery();
                break;
            case 't':
            case 'T':
                TestLottery();
                break;
            case 'p':
            case 'P':
                PrintResults();
                break;
            case 'd':
            case 'D':
                DoAwardStatistics();
                break;
            case 'q':
            case 'Q':
                cout << "Do you really want to quit? (y/n)?" << endl;
                cin >> yn;
                if (yn == 'y' || yn == 'Y')
                {
                    return 1;
                }
                break;

            default:
                cout << "Unknow command!" << endl;
                break;
        }
    }

    return 0;
}


// function implementation
string GenerateLottery() {
    // refer to: https://liveexample.pearsoncmg.com/liang/cpp3e/html/LotteryUsingStrings.html
    string lottery;
    int digit = 0;
    for (int i = 0; i < LOTTERYBALLS; i++)
    {
        digit = rand() % 10;
        lottery += static_cast<char>(digit + '0');
    }
    return lottery;
}

string GuessLottery() {
    string guess;
    bool alldigits = false;
    cout << "To guess the lottery," << endl;
    do
    {
        cout << "Please enter " << LOTTERYBALLS << " consecutive digits: " << endl;
        cin >> guess;
        if (guess.size() != LOTTERYBALLS)
        {
            cout << "Please enter exactly " << LOTTERYBALLS << " digits!" << endl;
            continue;
        }

        alldigits = true;
        for (int i = 0; i < guess.size(); i++)
        {
            alldigits = alldigits && isdigit(guess[i]);
        }
        if (!alldigits)
        {
            cout << "Not all digits in your guess!" << endl;
        }
    } while (!alldigits);

    return guess;
}

int DecideAward(const string& lottery, const string& guess) {
    // exact match
    if (guess == lottery)
    {
        cout << "Exact match: you win $10,000!" << endl;
        return 1000;
    }
        // match 3 consecutive digits, pay attention to the hard code here
    else if (guess.substr(0, 3) == lottery.substr(0, 3) ||
             guess.substr(1, 3) == lottery.substr(1, 3)) // match LOTTERYBALLS-1 digits consecutively
    {
        cout << "Match " << LOTTERYBALLS - 1 << " consecutive digits: you win $5000!" << endl;
        return 500;
    }
        // match 2 consecutive digits
    else if (guess.substr(0, 2) == lottery.substr(0, 2) ||
             guess.substr(1, 2) == lottery.substr(1, 2) ||
             guess.substr(2, 2) == lottery.substr(2, 2)
            )
    {
        cout << "Match " << LOTTERYBALLS - 2 << " consecutive digits: you win $2500!" << endl;
        return 250;
    }
        // math 1 digit in place
    else if (guess[0] == lottery[0] ||
             guess[1] == lottery[1] ||
             guess[2] == lottery[2] ||
             guess[3] == lottery[3]
            )
    {
        cout << "Match " << LOTTERYBALLS - 3 << " digits in place, you win $1000!" << endl;
        return 100;
    }
    else
    {
        cout << "Nothing match, $10 is awarded as encouragement." << endl;
        return 10;
    }
}

void SortAwards() {
    // Refer to: https://liveexample.pearsoncmg.com/liang/cpp3e/html/SelectionSort.html
    // find the current number of records
    int records = PLAYERS;
    if (gtimesplayed < PLAYERS)
    {
        records = gtimesplayed;
    }
    // copy gPlayerAward to gSortedAward, then sort gSortedAward
    for (int i = 0; i < records; i++)
    {
        gSortedAward[i] = gPlayerAward[i];
    }


    // TODO 1.================================================
    // sort gSortedAward[records] with records integers
    for (int i = 0; i < records; i++)
    {
        for (int j = i + 1; j < records; j++) // Bubble sort of gSortedAwards i and j
        {
            if (gSortedAward[i] > gSortedAward[j]) {
                int temp = gSortedAward[i]; // making a temp box to swap the varibales
                gSortedAward[i] = gSortedAward[j];
                gSortedAward[j] = temp;
            }
        }

    }
    for (int i = 0; i < floor(records / 2); i++)
    {
        int temp = gSortedAward[i];
        gSortedAward[i] = gSortedAward[records - (i + 1)];
        gSortedAward[records - (i + 1)] = temp;
    }

    // Finish
    // END OF TODO 1.=========================================

    //print the sorted awards
    cout << "The awards in decreasing order:" << endl;
    for (int i = 0; i < records; i++)
    {
        cout << gSortedAward[i] << " ";
    }
    cout << endl;
}

void PrintResults() {
    int records = PLAYERS;
    if (gtimesplayed < PLAYERS)
    {
        records = gtimesplayed;
    }
    cout << "**********" << setw(2) << records << " lottery records **************" << endl;
    // refer to: checkpoint 4.22-27
    // 1. https://liveexample.pearsoncmg.com/liang/cpp3e/review/04review.doc
    cout << left; // left align
    cout << setw(16) << "player name" << setw(10) << "awards" << setw(6) << "guess" << setw(6) << "lottery" << endl;
    for (int i = 0; i < records; i++)
    {
        cout << setw(16) << gPlayerNames[i] << setw(10) << gPlayerAward[i] << setw(6) << gPlayerGuess[i] << setw(6) << gPlayerLottery[i] << endl;
    }
    cout << "*******************************************" << endl;
}

void DoAwardStatistics() {

    // refer to:
    // 1. find the formula for calculating std - standard deviation on https://en.wikipedia.org/wiki/Standard_deviation
    // 2. programming exercises 7.11

    // current number of records
    int records = PLAYERS;
    if (gtimesplayed < PLAYERS)
    {
        records = gtimesplayed;
    }

    int maximum = -1;
    int minimum = -1;
    int sum = 0; // sum was originally set to -1 but caused the total number of awards to be 4587
    double average = -1.0;
    double std = -1.0;

    // TODO 2. ===================================================
    // find the maximum of gPlayerAward
    for (int i = 0; i < records; i++)
    {
        if (gPlayerAward[i] > maximum)
        {
            maximum = gPlayerAward[i];
        }
    }
    /*
        *	This time we are using the gPlayerAward array and comarping it with the minimum.
                In this case the minimum is -1 and if the count is less than that of course it goes through
                gPlayerAward's elements. If the array is less than the minimum, the array's element is assigned
                As the new minimum until the array's element is finally greater than the minimum
                Which is implied rather than stating using just the if statment instead of if-else.

            Side-note: I did not realise that the minimum already had it own code so I created the maxmium with inspiration from the bubble-sort
                featured in TODO 1.
        */

    // Finsh
    // END OF TODO 2.=============================================

    // find the minimum of gPlayerAward
    minimum = gPlayerAward[0];
    for (int i = 0; i < records; i++)
    {
        if (gPlayerAward[i] < minimum)
            minimum = gPlayerAward[i];
    }
    //Finish
    // TODO 3. ===================================================
    // find the sum and average of gPlayerAward

    sum = 0;
    for (int i = 0; i < records; i++) // Accidentally had the condition be the i > records causing otuput to be 0
    {
        sum += gPlayerAward[i]; // Adding each element to the sum
    }
    average = (sum) / (double)(records);
    //Finish
    // END OF TODO 3.=============================================


    // TODO 4. ===================================================
    // find the std of gPlayerAward
    double temp; // Creating a placeholder for ouput
    // average is already calcuated and standard deviation already initialized

    for (int i = 0; i < records; i++)
    {
        temp = gPlayerAward[i] - average;  // Deviation from mean
        std += pow(temp, 2); // Alternative is temp * temp | square of deviation from the mean
        // built in functions used
    }
    std /= records; // Deviding by the total number of awards
    std = sqrt(std); // Taking the square root
    // Finish
    // END OF TODO 4.=============================================


    // print out the statistics of gPlayerAward
    cout << "**********" << setw(2) << records << " lottery awards statistics **************" << endl;
    // refer to: checkpoint 4.22-27
    // 1. https://liveexample.pearsoncmg.com/liang/cpp3e/review/04review.doc
    // 2. https://en.cppreference.com/w/cpp/io/manip/fixed
    cout << left // left align
         << setprecision(2)
         << showpoint
         << fixed;
    cout << setw(15) << "# of awards"
         << setw(16) << "total awards"
         << setw(12) << "top"
         << setw(8) << "bottom"
         << setw(10) << "average"
         << setw(10) << "std"
         << endl;

    cout << setw(15) << records
         << setw(16) << sum
         << setw(12) << maximum
         << setw(8) << minimum
         << setw(10) << average
         << setw(10) << std
         << endl;

    cout << "*****************************************************" << endl;

}

void SaveLottery() {
    // refer to: https://liveexample.pearsoncmg.com/liang/cpp3e/html/SimpleFileOutput.html
    int records = PLAYERS;
    if (gtimesplayed < PLAYERS)
    {
        records = gtimesplayed;
    }

    ofstream savef;
    savef.open("lottery-records.txt");
    int i = 0;
    for (i = 0; i < records - 1; i++)
    {
        // seperate each item with a single blank space!
        savef << gPlayerNames[i] << " " << gPlayerAward[i] << " " << gPlayerLottery[i] << " " << gPlayerGuess[i] << endl;
    }
    savef << gPlayerNames[i] << " " << gPlayerAward[i] << " " << gPlayerLottery[i] << " " << gPlayerGuess[i];
    savef.close();
    cout << records << " lottery records saved!" << endl;
}

void LoadLottery() {
    // refer to:
    // 1. https://liveexample.pearsoncmg.com/liang/cpp3e/html/SimpleFileInput.html
    // 2. https://liveexample.pearsoncmg.com/liang/cpp3e/html/ReadAllData.html
    ifstream loadf;

    loadf.open("lottery-records.txt");

    gtimesplayed = 0;
    while (!loadf.eof())
    {
        loadf >> gPlayerNames[gtimesplayed] >> gPlayerAward[gtimesplayed] >> gPlayerLottery[gtimesplayed] >> gPlayerGuess[gtimesplayed];
        gtimesplayed++;
    }

    loadf.close();
    gcurrentplayer = gtimesplayed % PLAYERS;

    cout << gtimesplayed << " lottery records loaded!" << endl;
}

void TestLottery() {
    ifstream loadf;
    loadf.open("test-records.txt");

    gtimesplayed = 0;
    while (!loadf.eof())
    {
        loadf >> gPlayerNames[gtimesplayed] >> gPlayerAward[gtimesplayed] >> gPlayerLottery[gtimesplayed] >> gPlayerGuess[gtimesplayed];
        gtimesplayed++;
    }

    loadf.close();
    gcurrentplayer = gtimesplayed % PLAYERS;

    // Test your implementation
    filebuf fbuf;
    cout << "test started..." << endl;
    fbuf.open("test-results.txt", ios::out);
    auto oldbuf = cout.rdbuf(&fbuf);
    DoAwardStatistics();
    SortAwards();
    cout.rdbuf(oldbuf);
    cout << "test done!" << endl;
}
