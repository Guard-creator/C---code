#include <iostream>
#include <fstream>

int main() {

    std::fstream fileContent("data.txt", std::ios::in | std::ios::out);

    std::string currentContent;
    std::getline(fileContent, currentContent);

    std::cout << "Current Content: " << currentContent << '\n';

    std::string newWord;
    int pos;
    std::cout << "Enter a New Word: ";
    std::getline(std::cin, newWord);
    std::cout << "Enter a New Position: ";
    std::cin >> pos;

    currentContent.insert(pos, newWord + " ");

    fileContent.seekp(0);
    fileContent << currentContent;
    fileContent.close();

    std::cout << "Update Content: " << currentContent << '\n';

    return 0;
}
