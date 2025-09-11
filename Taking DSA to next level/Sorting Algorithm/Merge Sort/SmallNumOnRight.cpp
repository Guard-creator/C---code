#include <iostream>
#include <vector>

// Used in: LeetCode 315 – Count of Smaller Numbers After Self

// We are counting how many smaller elements appear to the right of each element.
// Example: nums = {5, 2, 6, 1} → Output: {2, 1, 1, 0}

void merge(std::vector<std::pair<int, int>>& nums, int left, int mid, int right, std::vector<int>& count) {
    std::vector<std::pair<int, int>> temp;
    int i = left;
    int j = mid + 1;
    int rightSmaller = 0;

    // we do count[num[i].second] += rightsmaller
    // so we can get the exact which value in array
    // was smaller then num[j];

    // Merge the two sorted halves while counting smaller elements on the right
    while (i <= mid && j <= right) {
        if (nums[i].first <= nums[j].first) {
            // All right-side elements already placed are smaller than nums[i]
            count[nums[i].second] += rightSmaller;
            temp.push_back(nums[i++]);
        } else {
            // nums[j] is smaller than nums[i], so it's a valid "smaller after self"
            rightSmaller++;
            temp.push_back(nums[j++]);
        }
    }

    // same here when right side element have passed 
    // places smaller one that are remain
    while (i <= mid) {
        count[nums[i].second] += rightSmaller;
        temp.push_back(nums[i++]);
    }

    while (j <= right) {
        temp.push_back(nums[j++]);
    }

    for (int k = left; k <= right; ++k) {
        nums[k] = temp[k - left];
    }
    // you can also do this way but there is no acutally difference
    //  for(int k = 0; k < temp.size(); k++)
    //     nums[left + k] = temp[k];
}

void mergeSort(std::vector<std::pair<int, int>>& nums, int left, int right, std::vector<int>& count) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    mergeSort(nums, left, mid, count);
    mergeSort(nums, mid + 1, right, count);
    merge(nums, left, mid, right, count);
}

std::vector<int> countSmaller(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<std::pair<int, int>> indexedNums;
    std::vector<int> count(n, 0);

    // Attach index to each number so we can place results correctly
    for (int i = 0; i < n; ++i) {
        indexedNums.push_back({nums[i], i});
    }

    mergeSort(indexedNums, 0, n - 1, count);
    return count;
}

int main() {
    std::vector<int> nums = {5, 2, 6, 1};
    std::vector<int> result = countSmaller(nums);

    for (int x : result) {
        std::cout << x << " ";
    }

    return 0;
}
