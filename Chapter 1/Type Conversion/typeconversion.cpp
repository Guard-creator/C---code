#include <iostream>

int main() {

  /*
    type conversion = is used to convert the number into any type of
     data if a num with decimal is double we can turn it to int.
  */

  const int x = 10;
  const double y = 2.5;

  double z = x / (int)y;

  //std::cout << z; ==> 5.

  //char character = 100;
  //std::cout << character; ==> d.

  //std::cout << (char) 100; ==> d.

  /*
  
    int correct = 8;
    int questions = 10;

    double result = correct/questions * 100;

    std::cout << result << "%"; ==> 0

    the reason the output is 0 because when we divide 8/10 the number are still integer
    so the divide part was just 0 that why the answer is zero;
  
  */

  int correct = 8;
  int questions = 10;

  // so to solve to issue we just convert the int to double so after the decimal the
  // numbers should be display and in the end it will multiply with 100.
  double result = correct/(double)questions * 100;

  std::cout << result << "%";

  return 0;
}