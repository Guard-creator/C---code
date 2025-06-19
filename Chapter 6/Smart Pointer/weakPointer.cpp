#include <iostream>
#include <memory>

// i hope you understand circular refernece

// CIRCULAR REFERENCES & std::weak_ptr

// weak ptr works with share ptr 
// when we tranfer ownership of share ptr to weak ptr 
// weak ptr does not own it but hold a reference to it and does not 
// increase reference count 

// kinda like it weak ptr can take a peak in share ptr 
// and does not increase reference count

// this is useful we want share  information in both
// classes with each other

// It allows one object to hold a weak reference to another without keeping it alive.

class B;

class A {
  public:

    // std::shared_ptr<B> b_ptr;
    std::weak_ptr<B> b_ptr; //👈 Change shared_ptr to weak_ptr to break cycle
    A() {
      std::cout << "A created\n";
    }
    ~A() {
      std::cout << "A Destroyed\n";
    }

};

class B {
  public:

    std::shared_ptr<A> a_ptr;
    B() {
      std::cout << "B created\n";
    }
    ~B() {
      std::cout << "B Destroyed\n";
    }

};

int main() {

  std::shared_ptr<A> a = std::make_shared<A>(); // create A
  std::shared_ptr<B> b = std::make_shared<B>(); // create B

  std::cout << a.use_count() << '\n';
  std::cout << b.use_count() << '\n';

  a->b_ptr = b; // A uses weak_ptr (no increase in reference count)
  b->a_ptr = a; // B still owns A

  
  return 0;
}
