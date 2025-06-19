#include <iostream>
#include <algorithm>
#include <vector>

int main() {

  std::vector<std::pair<std::string, int>> students = {
    {"Alice", 60},
    {"Bob", 342442},
    {"Zhongli", 6000}
  };

  std::sort(students.begin(), students.end());
  // std::pair has built-in comparison:
  // First compares .first (names as strings)
  // If names are equal, compares .second (ages)
  // This gives alphabetical order by name
  std::cout << "Sorted by name: \n";
  for(const auto& p : students) {
    std::cout << p.first << " - " << p.second << '\n';
  }

  std::sort(students.begin(), students.end(), [](const auto& a, const auto& b) { return a.second < b.second; });
  // Uses a lambda function to compare only ages (.second)
  // a.second < b.second means sort in ascending age order

  std::cout << "Sorted by age: \n";
  for(const auto& p : students) {
    std::cout << p.first <<  " - " << p.second << '\n';
  }

  return 0;
}