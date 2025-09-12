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
	dat.push_back("oldfront");
	dat.push_back("oldback");
  std::cout << "The front is " << dat.front() << " and the back is " << dat.back() << std::endl;
  cout << "The size of the array is curently: " << dat.size() << endl << endl;

  dat.pop_front();
  dat.push_front("newfront");
  std::cout << "The front is " << dat.front() << " and the back is " << dat.back() << std::endl; 
  cout << "The size of the array is curently: " << dat.size() << endl << endl;

  cout << "isolation front" << endl;
 	dat.pop_back(); // SEGFAULT
  cout << "isolation back" << endl;
	dat.push_front("cloudfront");
  std::cout << "The front is " << dat.front() << " and the back is " << dat.back() << std::endl; 
  cout << "The size of the array is curently: " << dat.size() << endl;
}
