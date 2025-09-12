#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

//delete
#include <iostream>
using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val){
  if(head_ == nullptr){ // Empty Case
    head_ = new Item; // This will set first=last=0, and next=prev=nullptr
    tail_ = head_;
    head_->val[ARRSIZE-1] = val;
    head_->last = ARRSIZE; 
    head_->first = ARRSIZE-1;  
  }
  else if( tail_->last < ARRSIZE ){ // Array has space
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
  else if(tail_->last == ARRSIZE){ // Array does not have space
    Item* tempLoc = tail_;
    tail_ = new Item; // This will set first=last=0, and next=prev=nullptr
    tail_->prev = tempLoc;
    tail_->prev->next = tail_;
    tail_->val[tail_->first] = val;
    tail_->last++;
  }
  size_++;
}

void ULListStr::push_front(const std::string& val){
  if(head_ == nullptr){ // Empty Case
    head_ = new Item; // This will set first=last=0, and next=prev=nullptr
    tail_ = head_;
    head_->val[ARRSIZE-1] = val;
    head_->last = ARRSIZE;
    head_->first = ARRSIZE-1;
  }
  else if(head_->first > 0){ // Array has space
    head_->val[(head_->first)-1] = val;
    head_->first = (head_->first) - 1;
  }
  else if((head_->first) == 0){ // Array does not have space
    Item* tempLoc = head_;
    head_ = new Item; // This will set first=last=0, and next=prev=nullptr
    head_->val[ARRSIZE-1] = val;
    head_->first = ARRSIZE-1;
    head_->last = ARRSIZE;
    head_->next = tempLoc; 
    head_->next->prev = head_;
  }
  size_++;
}

void ULListStr::pop_back(){
  if(head_ == nullptr){ // Empty-Case
    return;
  }
  else if( (tail_->first != tail_->last-1) ){ // Non-Empty Case 
    tail_->last = (tail_->last) - 1;
    size_--;
  }
  else if(tail_->first == tail_->last-1){ // One Element Case
    if(head_ == tail_){ // Last Item Case
      delete tail_;
      head_ = nullptr;
      tail_ = nullptr;
      size_--;
    }
    else{
      Item* tempLoc = tail_->prev;
      delete tail_;
      tail_ = tempLoc;
      tail_->next = nullptr; 
      size_--;
    }
  }
}

void ULListStr::pop_front(){
  if(head_ == nullptr){ // Empty-Case
    return;
  }
  else if((head_->first != (head_->last)-1)){ // Non-Empty Case
    head_->first = (head_->first) + 1;
    size_--;
  }
  else if(head_->first == (head_->last) - 1){ // One-Element Case
    if(head_ == tail_){ // Last Item Case
      delete head_;
      head_ = nullptr;
      tail_ = nullptr;
      size_--;
    }
    else{
      cout << "hello, deleting fisrt item since last in array" << endl;
      Item* tempLoc = head_->next;
      delete head_;
      head_ = tempLoc;
      head_->prev = nullptr;
      size_--;
    }
  }
}

std::string const & ULListStr::back() const{
    int index = (tail_->last) - 1;
    return tail_->val[index];
}

std::string const & ULListStr::front() const{
    return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  size_t cnt = 0;
  if(head_ == nullptr){ // Empty-Case
    return NULL;
  }
  else{
    Item* curr = head_;
    
    while(curr != nullptr){
      for(size_t i = curr->first; i < (size_t)curr->last; i++){
        
        if(cnt == loc){
          return &curr->val[i];
        }
        cnt++;
      }
      
      curr = curr->next;
    }
  }

  return NULL;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


