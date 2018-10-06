// 1545. Иероглифы

#include <iostream>
#include <vector>
#include <string>

int main()
{
  int n;
  std::cin >> n;
  std::vector<std::string> dictionary(n);
  for (auto& word : dictionary)
    std::cin >> word;
  
  char letter;
  std::cin >> letter;
  
  for (const auto& word : dictionary) {
    if (word.front() == letter)
      std::cout << word << std::endl;
  }
   
  return 0;
}
