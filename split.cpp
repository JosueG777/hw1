/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

  // Empty Case for Input List
  if(in == nullptr){
    return;
  }
  else{ // Non-Empty Case
    if( (in->value % 2) == 0 ) { // Checking if the node value is even

      // Grabbing the value and address for the new node to be added
      int tempVal = in->value; 

      // Creating and filling the new node
      if(evens == nullptr){
        evens = new Node(tempVal, nullptr);
      }
      else{
        evens = new Node(tempVal, evens);
      }

      if(in->next == nullptr){ // Current node to be sorted is the last
        delete in;
        in = nullptr;
      }
      else{ // If there's another node shift to new one for future iteration
        Node* tempLoc = in->next;
        delete in;
        in = tempLoc;
      }
      split(in, odds, evens);
    }
    else if( (in->value % 2) == 1 ){ // Checking if the node value is odd 

    // Grabbing the value and address for the new node to be added
    int tempVal = in->value; 

    // Creating and filling the new node
    if(odds == nullptr){
    odds = new Node(tempVal, nullptr);
    }
    else{
      odds = new Node(tempVal, odds);
    }

    if(in->next == nullptr){ // Current node to be sorted is the last
      delete in;
      in = nullptr;
    }
    else{ // If there's another node shift to new one for future iteration
      Node* tempLoc = in->next;
      delete in;
      in = tempLoc;
    }
    split(in, odds, evens);
    }
  }
}

/* If you needed a helper function, write it here */
