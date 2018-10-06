#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <limits>

int main()
{
  std::map<std::string, std::map<std::string, bool>> map;
  std::set<std::string> set;

  int n;
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    std::string a, b, c;
    std::cin >> a >> b >> c;
    map[a][b];
    map[a][c];
    map[b][a];
    map[b][c];
    map[c][a];
    map[c][b];
    set.insert(a);
    set.insert(b);
    set.insert(c);
  }

  const int size = set.size();
  const int inf = std::numeric_limits<int>::max();
  std::vector<int> distance(size, inf);
  std::vector<int> visit(size, 0);

  std::vector<std::vector<int>> matrix(size);
  for (auto& i : matrix)
    i.resize(size);

  for (const auto& i : map)
    for (const auto& j : i.second) {
      auto ii = std::distance(set.begin(), set.find(i.first));
      auto jj = std::distance(set.begin(), set.find(j.first));
      matrix[ii][jj] = 1;
      matrix[jj][ii] = 1;
    }

  if (set.count("Isenbaev")) {
    distance[std::distance(set.begin(), set.find("Isenbaev"))] = 0;
    int minindex, min;
    do {
      minindex = inf;
      min = inf;
      for (int i = 0; i < size; ++i) {
        if ((!visit[i]) && (distance[i] < min)) {
          min = distance[i];
          minindex = i;
        }
      }
      if (minindex != inf) {
        for (int i = 0; i < size; ++i) {
          if (matrix[minindex][i] > 0) {
            int temp = min + matrix[minindex][i];
            if (temp < distance[i])
              distance[i] = temp;
          }
        }
        visit[minindex] = 1;
      }
    } while (minindex < inf);
  }

  int k{0};
  for (const auto& i : set) {
    std::cout << i << ' ' << ((distance[k] == inf) ? "undefined" : std::to_string(distance[k])) << std::endl;
    ++k;
  }

  return 0;
}
