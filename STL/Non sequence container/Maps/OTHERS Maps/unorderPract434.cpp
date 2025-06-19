#include <iostream>
#include <vector>
#include <unordered_map>

int main() {

    std::vector<std::string> vec = {"cat", "dog", "hello", "yes", "no", "world"};

    std::unordered_map<int, std::vector<std::string>> groupedWords;

    for(auto word : vec) {
        int len = word.length();
        groupedWords[len].push_back(word);
    }

    for(auto pr : groupedWords) {
        std::cout << pr.first << ": ";
        for(auto word : pr.second) {
            std::cout << word << " ";
        }
        std::cout << '\n';
    }

  return 0;
}