#include <iostream>

// it is sort of like a function but its a namespace 
// you can name anything to namespace and put a value inside and use it
namespace anything{
  int num = 5 + 4;
}

int main() {

  /*
    we can also use namespace like in someplaces i have seen it now 
    i know what is means.

    using namespace std;

    string alpha = "alpha";
    cout << "hello!" << '\n';
    cout << alpha << '\n';
  */

 /*
  this is more saver then using namespace std.

  using std::string;

  string male = "I am a boy";
  std::cout << male;
  */

  /* we can also use namespace like this
  using namespace anything;*/

  // in cpp the const variable are used before the datatype or any variable like 
  // if you want to use string you have learn it a new feature before that.

  const double PI = 3.14 ;
  const double LIGHT_SPEED = 2.913314;
  const int HIEGHT = 56;
  const int WIDTH = 60;
  const char grade = 'A';

  // A namespace is a container that organizes a set of 
  // identifiers or names to ensure they are unique and
  // avoid conflicts

  /*
    we are using namespace to get the value of num
    the double colon we use after anything is know as
    scope resolution operator.
    enables us to access variables, functions, or classes defined in different scopes

    std::cout << anything::num;
  */

  //std::cout << num;


  return 0;
}