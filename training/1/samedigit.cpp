#include <iostream>

#include <iostream>
#include <string>

int main() {

  int a, b;
  std::cin >> a >> b;
  std::string sa = std::to_string(a);
  std::string sb = std::to_string(b);
  if (sa[0] == sb[0]) {
    std::cout << "true" << std::endl;
  } else {
    std::cout << "false" << std::endl;
  }

  return 0;
}
