// 1496. Спамер

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
  int n;
  std::cin >> n;
  std::vector<std::string> teams(n);
  for (auto& team : teams)
    std::cin >> team;
  
  std::sort(teams.begin(), teams.end());
  
  auto it = std::adjacent_find(teams.begin(), teams.end());
  
  std::string prev;
  while (it != teams.end()) {
    if (*it != prev)
      std::cout << *it << std::endl;
    prev = *it;
    it = std::adjacent_find(++it, teams.end());
  }
  
  return 0;
}
