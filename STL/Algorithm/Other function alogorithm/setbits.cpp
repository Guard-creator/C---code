#include <iostream>
#include <vector>
#include <algorithm>

int main() {

  // it used to count setbits
  // if interger equal to 4bytes
  // means 32 bits in memory 
  // kinda look like this 000......111 // in binary
  // soo how many times in binaries 1 appears its a setbits
  // and that is used to find out using these function

  // kinda useless btu in competivite it is used more
  // and not frequently used

  int n1 = 153;
  long int n2 = 643;
  long long int n3 = 423;

  std::cout << "n1: " << __builtin_popcount(n1) << '\n';
  std::cout << "n2: " << __builtin_popcount(n2) << '\n';
  std::cout << "n3: " << __builtin_popcount(n3) << '\n';

  return 0;
}