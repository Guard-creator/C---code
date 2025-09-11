#include <iostream>
#include <vector>

// we want to sort the marks of students
// but only using mark names should be the same.

// it's pretty much is same as counting negative number
// because the mark can be 40 or 1 or 100 
// so we find min and max and create it's range 
// we also do s.mark - min to make it access the array in count

// we use struct to save names and marks
struct Students {
  std::string names;
  int mark;
};

void stableSort(std::vector<Students> &students) {

  int n = students.size();

  // we find max and min to get the range for frequencies
  int maxMark = students[0].mark;
  int minMark = students[0].mark;
  for(const auto& s : students) {
    maxMark = std::max(maxMark, s.mark);
    minMark = std::min(minMark, s.mark);
  }

  // we make count vector to count frequencies
  int range = maxMark - minMark + 1;
  std::vector<int> count(range, 0);

  // Count how many times each mark appears
  for(const auto& s : students) {
    count[s.mark - minMark]++;
  }

  // Convert count[] to prefix sum array
  // This tells us the ending position of each mark in sorted order
  for(int i = 1; i < range; i++) {
    count[i] += count[i - 1];
  }

  // Build the output array in reverse (for stable sort)
  std::vector<Students> output(n);
  for(int i = n - 1; i >= 0; i--) {
    output[--count[students[i].mark - minMark]] = students[i];
  }

  students = output;

}

int main() {

  std::vector<Students> students = {
    {"Rais", 78},
    {"Miku", 95},
    {"Furina", 90},
    {"Dante", 80} 
  };

  stableSort(students);

  for(auto s : students) {
    std::cout << s.names << ", " << s.mark << '\n';
  }

  return 0;
}