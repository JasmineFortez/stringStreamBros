//File: main.cpp
//Programmer: Miakhau, Chia
//Date: 10/25/2021
//Compiler: clang(replit.com)
//Purpose: To read data into an array of objects and sort them based on age

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Person
{
 string name = "";
 int age = 0;
 string status = "";
};

void display(Person pArray[], int numOfpeople);
void sortPeople(Person pArray[],int numOfPeople);

int main() {

 //Extract each line from file
 string aLineFromFile = "";
 ifstream input ("people.txt");
 Person peopleArray[20] = {""};
 int numberOfPeople = 0;

 if (input.is_open())
 {
  while (!input.eof())
  {
    getline(input, aLineFromFile);
    stringstream ss (aLineFromFile);
    ss >> peopleArray[numberOfPeople].name;
    ss >> peopleArray[numberOfPeople].age;
    ss >> peopleArray[numberOfPeople].status;
    numberOfPeople++;
 }
 }
 
  cout << endl;
  cout << "Sorted by age... " <<endl;
  sortPeople(peopleArray, numberOfPeople);

  input.close();
  return 0;
}

void display(Person pArray[], int numOfPeople)
{
 for (int i = 0; i < numOfPeople; i++)
 {
  cout << pArray[i].name << " ";
  cout << pArray[i].age << " ";
  cout << pArray[i].status << endl;
 }

}
void sortPeople(Person pArray[],int numOfPeople){
  for (int flag = 1; flag < numOfPeople; flag++) 
 { 
  for (int i = numOfPeople - 1; i >= flag; i--) 
  { 
   if (pArray[i].age < pArray[i - 1].age) 
    swap(pArray[i], pArray[i - 1]); 
  } 
 }
  display(pArray, numOfPeople); 
}