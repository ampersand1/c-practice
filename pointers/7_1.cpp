/*
jshin, 3/2019
From Big C++:  7.1

In short, this takes in a list of names, then proceeds to ask the
names of everyone's best friend.  A person's popularity counter ticks up
everytime that person's name is mentioned as someone's best friend.
In the end, the results are all printed out.

*****************************************************
I made the assumption that everyone's friend is within the list.
So your best friend cannot exist outside the list.
I guess there's this assumption that there is only one person of each name.
Only one "Bob" on the list for example.
*****************************************************

new is useful when you don't know how
many variables you need before you compile.
cin is working much better than getline for some reason.  

*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;  // bad practice.

class Person
{
public:
  Person(string n);
  void print() const;
  void set_best_friend(Person* p);
  string getname() const;


private:
  string name;
  Person* bfriend;
  int popcount;

};

Person::Person(string n){
  name = n ;
  popcount = 0;
}


string Person::getname() const {
  return name;

}

/*
sets the peron's best friend to point to that person object.
That person's popularity counter increases by 1.
*/

void Person::set_best_friend(Person* p){
  bfriend = p;
  p->popcount++;

}

void Person::print() const {
  cout << "name:" << name << "\n";
  cout << "bestfriend:"<< bfriend->name << "\n";
  cout << "popcount =" << popcount << "\n";
}



int main(){
  char endchar = 'y';
  string pname;
  string bfriend;
  vector<Person*> plist;

  //Gathers everyone's names
  do{
    cout << "Name? :";
    cin >> pname;
    //cin.ignore();
    //getline(cin,pname);


    Person* ptemp = new Person(pname);
    plist.push_back(ptemp);

    cout << "would you like to add another person? (y/n)" ;
    cin >> endchar;
  }
  while(endchar == 'y');

  //Goes through and asks for everyone's best friends name.
  //matches name to person object and sets_best_friend() accordingly.
  //updates popularity counter.

  for(int i = 0; i < plist.size(); i++){
    cout << "Who is " << plist[i]->getname() << "'s bestfriend?";
    cin >> bfriend;
    //cin.ignore();
    //getline(cin,bfriend) ;

    for(int j=0; j<plist.size(); j++){
      if (plist[j]->getname() == bfriend){
        plist[i]->set_best_friend(plist[j]);
      }
    }
  }

  //deallocating the pointers.
  for(int i = 0; i < plist.size(); i++){
    plist[i]->print();
    delete plist[i];
  }

  return 0;
}
