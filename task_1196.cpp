// 1196. Экзамен по истории

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
  std::ios::sync_with_stdio(false);
  
  int n;
  std::cin >> n;
  std::vector<int> list(n);
  for (auto& date : list)
    std::cin >> date;
  
  int count = 0;  
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    int date;
    std::cin >> date;
    if (std::binary_search(list.begin(), list.end(), date))
      ++count;
  }
  
  std::cout << count << std::endl;
    
  return 0;
}
