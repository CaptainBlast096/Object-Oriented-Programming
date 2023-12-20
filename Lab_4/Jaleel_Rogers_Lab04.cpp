/***************************************************************************
 * Title:               Lab 4
 * Author:              Jaleel Rogers
 * Email:               jrogers1239@floridapoly.edu
 * Creation date:       10/20/2022 @ 7:30 PM
 * Modification date:   10/20/2022 @ 8:15 PM
 * Description:         A. Design a class named Account that contains:
                            1) An int data field named id for the account.
                            2) A double data field named balance for the account.
                            3) A double data field named annualInterestRate that stores the current interest
                            rate.
                            4) A no-arg constructor that creates a default account with id 0, balance 0.0, and
                            annualInterestRate 0.0.
                            5) A user-defined constructor that creates an account object with given three data
                            fields.
                            6) A function named getMonthlyInterestRate () that returns the monthly interest
                            rate.
                            double getMonthlyInterestRate();
                            7) A function named withdraw that withdraws a specified amount from the
                            account.
                            void withdraw (double amount);
                            8) A function named deposit that deposits a specified amount to the account.
                            void deposit (double amount);

                        Write a test program (main) that creates an Account object with an account ID of 1122, a
                        balance of 20000, and an annual interest rate of 4.5%.
                            • Call the withdraw function to withdraw $2500
                            • Call the deposit function to deposit $3000
                            • Print the balance and the monthly interest.
 **************************************************************************/
#include <iostream>
using namespace std;

class Account
{
public:

int id; // 1) An int data field named id for the account
double balance; // 2) A double data field named balance for the account
double annualInterestRate; // 3) A double data field named annualInterestRate that stores the current interest rate.


Account() // 4) A no-arg constructor that creates a default account with id 0, balance 0.0, and annualInterestRate 0.0.
    {
    id = 0, balance = 0.0, annualInterestRate = 0.0;
    }

Account (int newID, double newBalance, double newAnnualinterestRate) // 6) A user-defined constructor that creates an account object with given three data fields.
                                                                    // This is what I missed on the exam, unlike a private class, you just need a setter
                                                                    // and not a getter because everything is in the public class.
    {
    id = newID;
    balance = newBalance;
    annualInterestRate = newAnnualinterestRate;
    }

    double getMonthlyInterestRate() // 6) A function named getMonthlyInterestRate () that returns the monthly interest rate
    {
    return annualInterestRate/12;
    }

void withdraw (double amount) // 7) A function named withdraw that withdraws a specified amount from the account.
    {
        balance -= amount;
    }
void deposit (double amount) // 8) A function named deposit that deposits a specified amount to the account.
    {
        balance += amount;
    };

};

int main()
{

Account User = Account (1122,20000,4.5); // The account object with the requested parameters

User.withdraw(2500); // Withdrawing money
User.deposit(3000); // Depositing money


cout << "The balance for the account is " << User.balance << endl; //Printing the balance
cout <<"The monthly interest rate is " << User.getMonthlyInterestRate() << endl; // Printing the monthly interest


return 0;
}
