#include <iostream>

int main() {

  // do i need to explain this 
  // i have done this many time.

  double randnum[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int result = 0;

  for(int i = 0; i < sizeof(randnum) / sizeof(double); i++) {
    result += randnum[i];
  }

  std::cout << result << '\n';

  // let do another example.

  std::string studentNames[] = {"Billy", "Makima", "Radien Shogun", "Hu tao", "Yumiko", "WIfe"};

  for(int i = 0; i < sizeof(studentNames)/sizeof(std::string); i++) {
    std::cout << studentNames[i] << '\n';
  }

  return 0;
}