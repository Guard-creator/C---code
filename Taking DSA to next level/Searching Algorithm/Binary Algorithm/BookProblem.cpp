#include <iostream>

// Problem book allocation
// here we have student 2 
// and each books with certain pages in it 10 20 30 40
// we have to distribute the book in such way 
// that everyone gets each books
// it have to be in contiguously order means you cant give book from middle at first
// Goal: Minimize the maximum number of pages assigned to any student

bool isPossible(int books[], int size, int students, int maxPages) {
    int studentCount = 1;
    int currentSum = 0;

    for (int i = 0; i < size; i++) {

        if (books[i] > maxPages) return false; // Single book too large

        if (currentSum + books[i] > maxPages) {
            // if the student surpass it limit of holding books
            // at max it gonna go the other student to give them 
            // book and the book with pages that broke it limit 
            // i gonna give it to the other student until array ends
            studentCount++;
            currentSum = books[i];
            // this is happen when max is like low but not 
            // low then books pages, but if we add another book
            // that student the max is so low that it gonna give each
            // student a book for suppose if there is 4 with 2 students
            // but max is low like 40 or 41 
            // it end up giving to 3 students
            // 1 with 10 and 20 not giving 30 because limit is 41
            // 2 with 30 not giving 40 because limit is 41
            // 3 with 40 then array ends with 3 students that why..
            if (studentCount > students) return false;

        } else if(books[i] <= maxPages){
            // this condition assign student books
            // for example 1 student hold now 10 page
            // but if above conditon becomes true 
            // it means it surpass his max 
            // and can only hold currentsum + books[i]
            // equal means it is limit or max can hold books
            currentSum += books[i];
        }

    }

    return true;
}

int findMinPages(int books[], int size, int students) {
    if (students > size) return -1; // Not enough books

    int low = books[0], high = 0;

    for (int i = 0; i < size; i++) {
        if (books[i] > low) low = books[i]; // max(books)
        high += books[i];                   // sum of pages
    }

    int answer = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(books, size, students, mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return answer;
}

int main() {
    int books[] = {10, 20, 30, 40};
    int size = sizeof(books) / sizeof(books[0]);
    int students = 2;

    int result = findMinPages(books, size, students);

    std::cout << "Minimum possible maximum pages: " << result << '\n';

    return 0;
}
