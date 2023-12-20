/***************************************************************************
 * Title:               Lab 3 Part A
 * Author:              Jaleel Rogers
 * Email:               jrogers1239@floridapoly.edu
 * Creation date:       10/19/2022 @ 6:00 AM
 * Modification date:   10/20/2022 @ 8:00 AM
 * Description:         Write the following function that returns a new string in which the uppercase letters
                        are changed to lowercase and lowercase to uppercase.

                        string swapCase (const string & n)

                        Write a test program (main) that prompts the user to enter a string and invokes this
                        function and displays the return value from this function.
 **************************************************************************/
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

string swapCase(const string & n)
{
    /*Steps of Logic:
     *  1. Since its an array a for loop is the best option for checking and outputting
     *  2. Since we are typing a string, input should be a string. Check if input is string
     *  3. Either check if its upper or lower respectively. If chose either or flip it to the other case
     *  4. Else chose the other case and flip it.
     *  5. Then output it.
     * */
    string s = n;

    for (int i = 0; i < s.length(); i++)
{

        if (isalpha(s[i]))  //isalpha checks if the char is an alphabet according to the ASCII table. Returns an integer value if argument is alphabet otherwise returns a zero


        {
        if (islower(s[i])) //islower & isupper converts a char into an integer based on it ASCII value
        {
            s[i] = toupper(s[i]); //tolower & toupper converts a lowercase char into an uppercase char
        }
        else
        {
            s[i] = tolower(s[i]);
        }

        }
}
        return s;
}

int main()
{
    string input;

    cout << "Enter a string:";
    getline(cin,input);
    cout << "The new string is:" << swapCase(input) << endl;
    return 0;
}
