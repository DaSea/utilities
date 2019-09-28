#include <iostream>
#include <map>
#include <string>

int main ()
{
  std::map<int, int> mymap;

  mymap[10] = 12;
  mymap[1] = 222;

  std::cout << "mymap now contains " << mymap.size() << " elements.\n";

  std::cout << "mymap[10] is " << mymap[10] << '\n';
  std::cout << "mymap['b'] is " << mymap[0] << '\n';
  std::cout << "mymap['c'] is " << mymap[1] << '\n';
  std::cout << "mymap['d'] is " << mymap[2] << '\n';

  std::cout << "mymap now contains " << mymap.size() << " elements.\n";

  return 0;
}
