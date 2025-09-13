/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

using namespace std;

void clearList(Node* & x);

int main(int argc, char* argv[])
{
  int oddCount = 0;
  int evenCount = 0;

  // All-Odd List Test
  cout << "Test 1: All-Odd List Test" << endl; 
  Node* inputList = nullptr;
	Node* oddList = nullptr;
	Node* evenList = nullptr;

  inputList = new Node(1,nullptr);

  Node* currentNode = inputList;
  for(int i=3; i <= 9; i++){
    if (i % 2 == 1){
       currentNode->next = new Node(i, nullptr);
       currentNode = currentNode->next;
    }
  }

  split(inputList,oddList, evenList);

  Node* curr;
  curr = oddList;
 
  while(curr != nullptr){
    oddCount++;
    curr = curr->next;
  }

  cout << "The number of odd items is: " << oddCount << ". The expected amount was: 5" << endl << endl;

  clearList(inputList);
  clearList(oddList);
  clearList(evenList);

  // All-Even List Test
  cout << "Test 2: All-Even List Test" << endl;
  oddCount = 0;
  evenCount = 0;

  inputList = new Node(2,nullptr);

  currentNode = inputList;
  for(int i=4; i <= 10; i++){
    if (i % 2 == 0){
       currentNode->next = new Node(i, nullptr);
       currentNode = currentNode->next;
    }
  }

  split(inputList,oddList, evenList);

  curr = nullptr;
  curr = evenList;
 
  while(curr != nullptr){
    evenCount++;
    curr = curr->next;
  }
  
  cout << "The number of even items is: " << evenCount << ". The expected amount was: 5" << endl << endl;

  clearList(inputList);
  clearList(oddList);
  clearList(evenList);

  // Empty Test
  cout << "Test 3: Empty List Test" << endl; 
  oddCount = 0;
  evenCount = 0;

  split(inputList,oddList, evenList);

  curr = nullptr;
  curr = evenList;
 
  while(curr != nullptr){
    evenCount++;
    curr = curr->next;
  }

  curr = nullptr;
  curr = oddList;
 
  while(curr != nullptr){
    oddCount++;
    curr = curr->next;
  }
  
  cout << "The number of even items is: " << evenCount << ". The expected amount was: 0" << endl;
  cout << "The number of odd items is: " << oddCount << ". The expected amount was: 0" << endl << endl;

  clearList(inputList);
  clearList(oddList);
  clearList(evenList);


  // Mixed List Test
   cout << "Test 4: Mixed List Test" << endl;
  oddCount = 0;
  evenCount = 0;

  inputList = new Node(0,nullptr);

  currentNode = inputList;
  for(int i=1; i <= 10; i++){
      currentNode->next = new Node(i, nullptr);
      currentNode = currentNode->next;
  }

  split(inputList,oddList, evenList);

  curr = nullptr;
  curr = evenList;
 
  while(curr != nullptr){
    evenCount++;
    curr = curr->next;
  }

  curr = nullptr;
  curr = oddList;
 
  while(curr != nullptr){
    oddCount++;
    curr = curr->next;
  }
  
  
  cout << "The number of even items is: " << evenCount << ". The expected amount was: 6" << endl;
  cout << "The number of odd items is: " << oddCount << ". The expected amount was: 5" << endl << endl;

  clearList(inputList);
  clearList(oddList);
  clearList(evenList);
}

void clearList(Node* & x){

  Node* currPos = x;

  while(currPos != nullptr){
    Node* temp = currPos->next;
    delete currPos;
    currPos = temp;
  }

  x = nullptr;
}
