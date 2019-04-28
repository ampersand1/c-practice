/*
Implement a base class Account and derived classes Savings and Checking.  In
In the base class, supply member functions deposit and withdraw.  Provide
a function daily_interest that computes and adds the daily interest.  For
calculations, assume that every month has 30 days.  Checking accounts yield
interest of 3 percent monthly on balances over $1000.  Savings accounts yield 6 percent on the entire balance.
 Write a driver program that makes a month's worth of deposits and withdrawls and calculates the interest every day.


*/

#include <iostream>
#include<cmath>
#include<vector>

using namespace std;

class Account
{
public:
  Account();
  Account(double n);
  void deposit(double d);
  void withdraw(double d);
  void daily_interest(double d);
  void print() const;
  double get_balance();
private:
  double balance;

};

class Savings : public Account
{
public:
  Savings(double b);
  void daily_savings_calculator();
};

class Checking: public Account {
public:
  Checking(double b);
  void daily_checking_calculator();
};


//class member function definitions *********************************
Account::Account() {
  balance = 0.0;
  cout << balance << "\n";

}

Account::Account(double d) {
  balance = d;

}

void Account::deposit(double d){
  balance = balance + d ;

}

void Account::withdraw(double d){
  balance = balance - d ;

}

double Account::get_balance(){
  return balance;
}

/*
Calculates the interested compounded daily where d is the daily interest rate.
*/
void Account::daily_interest(double d){
  balance = balance*(1+d);

}



Savings::Savings(double b) : Account(b)  {

  }

Checking::Checking(double b) : Account(b)  {

  }
//******************************************************************

void Savings::daily_savings_calculator(){
  Account::daily_interest(0.001944);


}
void Checking::daily_checking_calculator(){
  double b1 = Account::get_balance();
  if (b1>=1000){
    Account::daily_interest( 0.000985779);
  }

}
//******************************************************************


int main(){

  char accountType;
  double ibalance;

  cout << "Savings or checking? (c/s)";
  cin >> accountType ;    //getline?
  cout << "initial balance";
  cin >> ibalance;

  if(accountType == 'c'){
    Checking myChecking(ibalance);
  }

  if(accountType == 's'){
    Savings mySavings(ibalance);
  }


  return 0;
}
