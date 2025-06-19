#include <iostream>
#include <vector>

class Sum {
  public:
  int sumOfAll = 0;
  Sum(std::vector<int> myVector) {
    
    for(int i = 0; i < myVector.size(); i++) {
      sumOfAll += myVector[i];
    }

    std::cout << sumOfAll << '\n';

  }

};

int main() {

  std::vector<int> myVector = {4, 5, 3, 5, 6, 7, 78, 42};
  Sum adding(myVector);
  
  return 0;
}