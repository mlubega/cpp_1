/*******************************************************************************
Author:        Maimuna Lubega
CS Login:      maimuna

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
#include <string>
#include <iomanip>
#include <sstream>
#include <cstdlib>

using namespace std;

#define BUFSIZE 5000




int numRecs= 0;

//enum Grades { A = 4, B = 3, C = 2, D= 1, F = 0 };

struct record {
  
  int studentID;
   int credits;
  double gpa;
} ;

int findStudent(int id, record dbpointer[]){
  
  int i;
  for ( i =0; i < numRecs; i++){
    
    if (dbpointer[i].studentID == id){
      return(i);
    }

 }
  return (-1);

}


int addStudent( int id, int credits, double gpa, record  dbpointer[]){

  int x;
  if (( x = findStudent(id, dbpointer)) == -1){
    dbpointer[numRecs].studentID = id;
    dbpointer[numRecs].gpa = gpa;
    dbpointer[numRecs].credits = credits;
    numRecs++;
    return (1);
  }else{
    fprintf(stderr, "Student already exists in system\n");
    // cout <<"Student already exists in system" << endl;
    return (-1);

  }


}
/**
double calcGPA (double newgpa, double oldgpa){
  return ((newgpa + oldgpa)/2);
}
int deleteStudent( int id, int *dbpointer, int &recNum){
  
  int o;
  if( (o = findStudent(id, dbpointer)) == -1){
    printf(stderr, "Student not found\n");
    return (-1);
  }else{
    dbpointer[o].id = dbpointer[recNum].id;
    dbpointer[o].gpa = dbpointer[recNum].gpa;
    dbpointer[o].credits = dbpointer[recNum].credits;
    recNum--;
    return (1);
  }


}
int updateStudent(int id, char grade, int credits, int *dbpointer){

  int k;
  
  if((k = findStudent(id, dbpointer)) == -1){
    printf(stderr, "Student not found\n");
    return (-1);
  }else{
    int oldcredits = dbpointer[k].credits;
    double oldgpa = dpointer[k].gpa

    dbpointer[k].credits = oldcredits + credits;
    
    switch (toupper(grade)){
      
      case 'A': 
	dbpointer[k].gpa = calcGPA(A, oldgpa); 
	break;
      case 'B':
	dbpointer[k].gpa = calcGPA(B, oldgpa);
	break;
      case 'C':
	dbpointer[k].gpa = calcGPA(C, oldgpa);
	break;
      case 'D':
	dbpointer[k].gpa = calcGPA(D, oldgpa);
	break;
      case 'F':
	dbpointer[k].gpa =calcGPA(F, oldgpa);
	break;
    default:
      printf(stderr, "Invalid Letter Grade\n");
      return (-1);

    }
    return (1);
  }
  
}

void print(int *dbpointer){
  int i;
  char comma = ',';
  for ( i = 0; i < BUFSIZE; i++){
    cout << dbpointer[i].id << comma << dbpointer[i].credits << comma << dbpointer[i].gpa << "\n"
  }

}
*/





int main() {
 
    bool done = false;
    char choice;
    int userID;
    record studentRecords[BUFSIZE];
    
    int userCredits;
    double usergpa;

    cout << "Enter your commands at the > prompt:" << endl;
    
    while (!done) {
        cout << "> ";
	cin >> choice;

        switch (choice) {
	    
            case 'a':
	      cin >> userID >> userCredits >> usergpa;
	      addStudent(userID, userCredits, usergpa, studentRecords);
	      cout << "added: " <<  numRecs << endl;
	      break;
	      /*

            case 'd':  
                cin >> studentID;  // read in the integer ID
                break;
	    case 'u':
	      cin >> studentID;
	      break;
	    case 'p':

	      print();
	      break;
	      */
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
