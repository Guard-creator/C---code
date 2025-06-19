#include <iostream>
#include <memory>

class B;

class A {
  public:

    std::weak_ptr<B> b_ptr;

    A() {
      std::cout << "A CREADTED\n";
    }

    ~A() {
      std::cout << "A DESTROYED\n";
    }

};

class B {
  public:

  std::shared_ptr<A> a_ptr;

  B() {
    std::cout << "B CREADTED\n";
  }

  ~B() {
    std::cout << "B DESTROYED\n";
  }

};

int main() {

  std::shared_ptr<A> a = std::make_shared<A>();
  std::shared_ptr<B> b = std::make_shared<B>();

  a->b_ptr = b;
  b->a_ptr = a;

  return 0;
}