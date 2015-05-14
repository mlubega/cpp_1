/*******************************************************************************
Author:        <your name>
CS Login:      <your login name>
 
Pair Partner:  <name of your pair programming partner (if applicable)>
CS Login:      <your partner's login name>
 
Credits:       <name of anyone (other than your pair programming partner) who 
                helped you write your program>
 
Course:         CS 368, Fall 2013
Assignment:     Programming Assignment 1 
*******************************************************************************/
#include <iostream>
#include <stdio.h>
#include <ctype.h>
 
#define BUFSIZE 5000
using namespace std;
 
int recNum = 0;
 
struct Record {
  int studentID;
  int credits;
  double gpa;
};
 
int findStudent(int userID, Record studentRecords[]){
   
  int i;
  for ( i = 0; i < recNum; i++){
     
    if (studentRecords[i].studentID == userID){
      return(i);
    }
 
  }
  return (-1);
 
}
 
int addStudent(int userID, int userCredits, double usergpa, Record studentRecords[]) {
  int x;
  if ((x = findStudent(userID,  studentRecords)) == -1 ) {
      studentRecords[recNum].studentID = userID;
      studentRecords[recNum].gpa = usergpa;
      studentRecords[recNum].credits = userCredits;
      recNum++;
      cout << "num recs: "  << recNum;
      return (1);
    } else {
     
      cout << "Student already exists in system \n";
     //   fprintf(stderr, "Student already exists in system\n");
      return (-1);
    }
  }
int deleteStudent( int id, Record *studentRecords){
  
  int o;
  if((o = findStudent(id, studentRecords)) == -1){
    cout <<  "Student not found" << endl;
       return (-1);
  }else{
    studentRecords[o].studentID = studentRecords[recNum].studentID;
    studentRecords[o].gpa = studentRecords[recNum].gpa;
    studentRecords[o].credits = studentRecords[recNum].credits;
    recNum--;
    cout << "num recs: "  << recNum;
   return (1);
  }


}
void print(Record *dbpointer){
  int i;
  char comma = ',';
   for ( i = 0; i < recNum; i++){
     cout << dbpointer[i].studentID << comma << dbpointer[i].credits << comma <<  dbpointer[i].gpa << endl;
  }

}
 
 
int main() {
    bool done = false;
    char choice;
    int studentID;
    Record studentRecords[BUFSIZE];
    double gpa;
    int credits;
 
    cout << "Enter your commands at the > prompt:" << endl;
    while (!done) {
        cout << "> ";
        cin >> choice;
 
        switch (choice) {
 
    case 'a':
      cin >> studentID >> credits >> gpa;
      addStudent(studentID, credits,  gpa, studentRecords);
 
      break;
 
            case 'd':  
                cin >> studentID;  // read in the integer ID
	deleteStudent(studentID , studentRecords);
                break;
	case 'p':
	  print(studentRecords);
	  break;
 
            case 'q':  
                done = true;
                cout << "quit" << endl;
                break;
 
            // If the command is not one listed in the specification, for the 
            // purposes of this assignment, we will ignore it.  Note that you 
            // will see multiple ?'s printed out if there is additional 
            // information on the line (in addition to the unknown command 
            // character).  
            default: break;
        } // end switch
 
    } // end while
 
    return 0;
}
