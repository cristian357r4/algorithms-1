#include <iostream>
#include <vector>

// Source: https://leetcode.com/problems/island-perimeter/

/**
 * The naive solution to this is trivial. More
 * of a coding challenge than an algorithm one.
 * Complexity analysis:
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 */

int islandPerimeterNaive(const std::vector<std::vector<int> >& grid) {
  int totalPerimCount = 0;
  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid[i].size(); ++j) {
      if (grid[i][j]) {
        if (i == 0 || grid[i - 1][j] == 0) totalPerimCount++;
        if (i == grid.size() - 1 || grid[i+1][j] == 0) totalPerimCount++;
        if (j == 0 || grid[i][j - 1] == 0) totalPerimCount++;
        if (j == grid[0].size() - 1 || grid[i][j+1] == 0) totalPerimCount++;
      }
    }
  }

  return totalPerimCount;
}

int main() {
  int n, m;
  std::cin >> n >> m;

  // Setup multi vec with appropriate size
  std::vector<std::vector<int> > grid(n, std::vector<int>(m));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> grid[i][j];
    }
  }

  std::cout << islandPerimeterNaive(grid) << std::endl;
  return 0;
}
