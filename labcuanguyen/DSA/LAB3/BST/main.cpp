#include <iostream>
using namespace std;
class Student {
private:
  string fullname;
  int age;
  int grade;

public:
  Student() // constructor
  {
    fullname = "Nguyen Van A";
    age = 18;
    grade = 12;
  }
  void upAge() { age++; }
  // getter setter
  int getAge() { return age; }
  void setAge(int age) { this->age = age; }
};

int main() {
  Student *s = new Student();
  s->upAge();
  cout << s->getAge() << endl;
  s->setAge(100);
  cout << s->getAge() << endl;
}
