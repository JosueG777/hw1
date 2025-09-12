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
  Node* inputList = nullptr;
	Node* oddList = nullptr;
	Node* evenList = nullptr;

  inputList = new Node(1,nullptr);

  Node* currentNode = inputList;
  for(int i=3; i <= 7; i++){
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

  cout << "The number of odd items is: " << oddCount << ". The expected amount was: 4" << endl;

  clearList(inputList);
  clearList(oddList);
  clearList(evenList);

  // All-Even List Test
  
  // cout << "The number of odd items is: " << oddCount << ". The expected amount was: 4" << endl;

  // oddCount = 0;
  // evenCount = 0;

  // inputList = new Node(1,nullptr);
  // currentNode = inputList;
  // for(int i=3; i <= 7; i++){
  //   if (i % 2 == 1){
  //      currentNode->next = new Node(i, nullptr);
  //      currentNode = currentNode->next;
  //   }
  // }

  // split(inputList,oddList, evenList);

  // curr = oddList;
 
  // while(curr != nullptr){
  //   oddCount++;
  //   curr = curr->next;
  // }

  // cout << "The number of odd items is: " << oddCount << ". The expected amount was: 4" << endl;




  // Empty Test


  // Normal Mixed Test


  // Duplicates Test



}

void clearList(Node* & x){

  Node* currPos = x;

  while(currPos != nullptr){
    Node* del = currPos;
    Node* temp = currPos->next;
    delete del;
    currPos = temp;
  }

  delete currPos;

  // delete currPos;
}
