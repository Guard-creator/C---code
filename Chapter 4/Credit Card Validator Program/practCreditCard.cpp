#include <iostream>

  // so in this program we gonna make a program that check if the credit card number is valid or not 
  // and we  will use luhn alogrithm to check how its done.

  // all the step are here

  /*
        --------------
        Luhn Algorithm
        --------------
        1. Double every second digit from right to left If doubled number is 2 digits, split them.
        2. Add all single digits from step 1.
        3. Add all odd numbered digits from right to left(from position odd number 
           not the actual number in the credit card).
        4. Sum results from steps 2 & 3.
        5. If step 4 is divisble by 10, # is valid.

  */

 using string = std::string;

int getdigit(const int number);
int sumOddNumber(const string cardNumber);
int sumEvenNumber(const string cardNumber);

int main() {

  string creditCardNumber;\
  int sumOfBothEvenOdd = 0;

  std::cout << "Enter Your Credid Cart Number: ";
  std::cin >> creditCardNumber;

  sumOfBothEvenOdd += sumEvenNumber(creditCardNumber) + sumOddNumber(creditCardNumber);

  if(sumOfBothEvenOdd % 10 == 0) {
    std::cout << sumOfBothEvenOdd << '\n';
    std::cout << creditCardNumber << " is Valid Number!!." << '\n';
  } else {
    std::cout << sumOfBothEvenOdd << '\n';
    std::cout << creditCardNumber << " is Not Valid Number!!." << '\n';
  }

  
  return 0; 
}

int getdigit(const int number) {
  // we making 2 digit number split
  return number % 10 + (number / 10 % 10);
}
int sumOddNumber(const string cardNumber) {

  int sum = 0;

    for(int i = cardNumber.size() - 1; i >= 0; i-=2) {
       sum += cardNumber[i] - '0';
    }

  return sum;
}
int sumEvenNumber(const string cardNumber) {
  
  int sum = 0;

  for(int i = cardNumber.size() - 2; i >= 0; i-=2) {
    /*  here we minus char 0 why and multiply 2 
        because when we pass a number to function 
        it take as the associated value or decimal value 
        like the number 5 it take as 56 
        and according to steps we have to double the even number 
        that why we multiply 2 
    */
    sum += getdigit((cardNumber[i] - '0') * 2);
  }

  return sum;

}