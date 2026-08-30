#include <iostream>
#include <string>

int main() {

  //   На вход подаётся 2 числа. Выведите на экран произведение этих чисел,
  //   сумму, разность, частное и остаток от деления первого числа на второе.
  //   Данные выводить в одной строке через пробел.

  // Входные данные:
  // Два целых числа, разделённые пробелом.

  // Выходные данные:
  // Пять чисел: произведение, сумма, разность, частное и остаток от деления —
  // через пробел.

  int a, b;
  std::cin >> a >> b;

  int product = a * b;
  int sum = a + b;
  int difference = a - b;
  int quotient = a / b;
  int remainder = a % b;

  std::cout << product << " " << sum << " " << difference << " " << quotient
            << " " << remainder << std::endl;

  return 0;
}
