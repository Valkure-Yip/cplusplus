#include <iostream>
#include <string>
using namespace std;

int main()
{
  string food = "pizza";
  string &meal = food;

  cout << food << "\n";  // pizza
  cout << meal << "\n";  // pizza
  cout << &food << "\n"; // 0x7ffee08708f0
  cout << &meal << "\n"; // 0x7ffee08708f0
  return 0;
}