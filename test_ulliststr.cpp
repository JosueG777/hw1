#include <string>
#include <vector>
#include <sstream>

#include "ulliststr.h"

#include <iostream>
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat;

  // Test Case 1: Mixed Stress Test
  cout << endl << "Test Case 1: Mixed Stress Test" << endl;
  for(int i = 0; i < 10; i++){
    if(i % 2 == 0){
     dat.push_front("e");
    } 
    else{
     dat.push_back("o");
    }
  }

  cout << "The front of the array is: " << dat.front() << ". The expected front is e"<< endl;
  cout << "The back of the array is: " << dat.back() << ". The expected back is o"<< endl;
  cout << "The array size is: " << dat.size() << ". The expected size is 10" << endl << endl;

  for(int i=0; i < 10; i++){
    if(i % 2 == 0){
     dat.pop_front();
    }
    else{
     dat.pop_front();
    }
  }

  cout << "Clearing array...it should now be empty and the size is: " << dat.size() << ". The expected size is 0" << endl << endl;
  
  // Test Case 2: Popping the front and back of an empty list
  cout << endl << "Test Case 2: Popping the front and back of an empty list" << endl;
  dat.pop_front();
  dat.pop_back();

  cout << "If you are seeing this message, then the program did not delete the empty list and avoided a crash!" << endl;


  // Test Case 3: Pushing back only then popping front only
  cout << endl << "Test Case 3: Pushing back only then popping front only" << endl;
  for(int i=0; i < 15; i++){
    if(i==0){
      dat.push_back("a");
    }
    else{
    dat.push_back("b");
    }
  }

  cout << "The front of the array is: " << dat.front() << ". The expected front is a"<< endl;
  cout << "The back of the array is: " << dat.back() << ". The expected back is b"<< endl;
  cout << "The array size is: " << dat.size() << ". The expected size is 15" << endl << endl;

  for(int i=0; i < 15; i++){
    dat.pop_front();
  }

  cout << "After using pop_front for the entire array the contents are now: " << dat.size() << ". Expected: 0" << endl;

  // Test Case 4: Pushing front only then popping back only
  cout << endl << "Test Case 4: Pushing front only then popping back only" << endl;
  for(int i=0; i < 15; i++){
    if(i==0){
      dat.push_front("f");
    }
    else{
    dat.push_front("x");
    }
  }

  cout << "The front of the array is: " << dat.front() << ". The expected front is x"<< endl;
  cout << "The back of the array is: " << dat.back() << ". The expected back is f"<< endl;
  cout << "The array size is: " << dat.size() << ". The expected size is 15" << endl << endl;

  for(int i=0; i < 15; i++){
    dat.pop_back();
  }

  cout << "After using pop_back for the entire array the contents are now: " << dat.size() << ". Expected: 0" << endl;
}
