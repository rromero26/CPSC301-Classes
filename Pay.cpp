#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include "Person.cpp"

using namespace std;
//-----------------------------------------------------------------------------------------
int readData(Person myArray[], int size){    // WILL RETURN A INT counter OF NUM OF EMPLOYEES
    string lName;
    string fName;
    float rate;
    float hours;
    int counter = 0;                        //counter that will save
    string line;

    fstream myFile;                         //opens file
    myFile.open("data.txt");

    if(!myFile) {                           //check if file open properly
      cout << "Error: data.txt could not open. Closing Program." << endl;
      exit(1);
    }

    do {       //counts num of records
      myFile >> fName;
      myFile >> lName;
      myFile >> hours;
      myFile >> rate;
      myArray[counter].setLastName(lName);      //Sets all values while looping
      myArray[counter].setFirstName(fName);
      myArray[counter].setPayRate(rate);
      myArray[counter].setHoursWorked(hours);
      counter++;
    }
    while(getline(myFile, line));

    myFile.close();
    return counter;
}
//-------------------------------------------------------------------------------------------
void writeData(Person anArray[], int size){
  ofstream myFile("Output.txt");

  if(!myFile){                           //check if file open properly
    exit(1);
  }

  for(int i = 0; i < size; i++){         //Based on num of Employee, loops and print Employee's name and pay
    myFile << anArray[i].fullName() << " " << anArray[i].totalPay() << endl;
  }
  myFile.close();
}

//-----------------------------------------------------------------------------------------------

main() {
  int EmployeeMax = 20;               //Maz size of array
  Person myArray[EmployeeMax];       //creates array

  int numOfEmployee = readData(myArray, EmployeeMax);     //Returns num of existing Employees in file
  writeData(myArray, numOfEmployee);                      //Will only print the amount of exisiting Employees
  return 0;
}
