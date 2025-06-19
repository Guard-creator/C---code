#include <iostream>
#include <vector>
#include <algorithm>

// famous leet code problem 
// koko eating bananas 
// koko has a piles of banana pile = {3, 6, 7, 11}
// but guard dont let him but he get a brakes of 8 hour (h = 8);
// koko need to eat minimist banana at such speed that she can finish in finish each pile all
// in 8 hours
// for example koko eat 2 bananas per hour
// so 3 = 1.50 hours == round up = 2
// 6 = 3 hours == round up 3
// 7 = 3.50 == round up 4
// 11 = 5.50 == round up 6
// so total hours 2 + 3 + 4 + 6 = 15 hours too long
// so we need to find minimist range so she can 
// finish all the banana in h = 8 hours

int minEatingSpeed(std::vector<int>& piles, int h) {
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    int answer = high;

    while (low <= high) {
        int k = low + (high - low) / 2;

        long long hours = 0;
        for (int pile : piles) {
            hours += (pile + k - 1) / k;  // same as ceil(pile / k)
        }

        // The +k is to push it over to the next integer if there's a remainder
        // The -1 prevents it from pushing too far, when the number is already perfectly divisible

        if (hours <= h) {
            answer = k;        // Try to find smaller k
            high = k - 1;
        } else {
            low = k + 1;       // Need more speed
        }
    }

    return answer;
}

int main() {
    std::vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    int result = minEatingSpeed(piles, h);
    std::cout << "Minimum eating speed Koko needs: " << result << '\n';

    return 0;
}
