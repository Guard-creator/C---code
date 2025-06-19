#include <iostream>
#include <vector>
#include <algorithm>

// finding the vector max value and min value 

// two way use function or do it manually...

int main() {

  std::vector <int> myVector = {2, 10, 6, 2, 3, 4, 1};

  int maxValue;
  int minValue;

  maxValue = *std::max_element(myVector.begin(), myVector.end());
  minValue = *std::min_element(myVector.begin(), myVector.end());

  std::cout << "Maximum Value: "  << maxValue << '\n';
  std::cout << "Minimum Value: " << minValue << '\n';

  /*
  for(int i = 0; i < myVector.size(); i++) {

    if(maxValue < myVector[i]) {
      maxValue = myVector[i];
    }

    if(minValue > myVector[i]) {
      minValue = myVector[i];
    }

  }

  std::cout << "Maximum Value: "  << maxValue << '\n';
  std::cout << "Minimum Value: " << minValue << '\n';
  */
 
  return 0;
}