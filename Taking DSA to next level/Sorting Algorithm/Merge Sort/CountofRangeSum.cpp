#include <iostream>
#include <vector>
#include <algorithm>

// LeetCode — Problem no.327
// "Count of Range Sum

// we are given an array 
// and with an range of lower and upper (it an be anything)
// we have to return the number of range sums that lie in [lower, upper] inclusive.
// example ===
// nums = [1, 2, -1]
// lower = 1, upper = 2
// We want subarrays whose sum is between 1 and 2 inclusive.
 
// Step 1 — Find all subarrays & their sums (brute force way for clarity)
// [1] → sum = 1 (in range)
// [1, 2] → sum = 3 (too big)
// [1, 2, -1] → sum = 2 (in range)
// [2] → sum = 2  (in range)
// [2, -1] → sum = 1 (in range)
// [-1] → sum = -1 (too small)

// Step 2 — Count valid ones
// Valid subarrays are:
// [1], [1, 2, -1], [2], [2, -1] → count = 4

// Brute force checks every subarray (O(n²)), but we can do better using prefix sums + merge sort.
// When prefix sums are sorted (within each half during merge sort), we can use two pointers to
// quickly find how many sums fall in [lower, upper].

int countWhileMerge(std::vector<long long> &prefix, int left, int mid, int right, int lower, int upper) {
    int count = 0;
    // both point to the first element of right 
    // to get the range
    int j = mid + 1, k = mid + 1;

    // how we get the prefix sum
    // if we want the sum of nums[1, 3]
    // we go to index j + 1 (3) -> (3 + 1) 
    // at index 4 the value will be the sum of all the previous values
    // but if want the sum of [1, 3] we will subtract at index 1
    // like this 
    // prefix[4] = nums[0] + nums[1] + nums[2] + nums[3]
    // prefix[1] = nums[0]
    // we will minus the index the 1 so we can get the sum of nums[1...3]
    // that how we can get the the sum of any subarray

    // how the while loops works 
    // 1
    // when the while loop condition (prefix[k] - prefix[i] < lower) becomes 
    // false it means the values is >= lower at k
    // if not it keep increment the k until it find it 
    // means after that it will be bigger value but before that values is less
    // 2
    // and when the second while condition(prefix[j] - prefix[i] <= upper) becomes false 
    // it means the value is > upper
    // so now j will point to that value that comes before 
    // the values whne it becomes > upper means j - 1
    // if not then it will keep checking until it find 
    // 3
    // Because the array is sorted, everything between k and j - 1 is valid for that fixed i.
    // Subtract j - k to get exactly how many valid sums are there.
    // k and (j - 1)
    // then we subtract both 
    // k - (j - 1)
    // and we will get the range in the range of 
    // lower and upper (or actual count duh)
    
    // we loop i from left to mid
    for (int i = left; i <= mid; ++i) {
        
        while (k <= right && prefix[k] - prefix[i] < lower) k++;
        while (j <= right && prefix[j] - prefix[i] <= upper) j++;

        count += (j - k);
    }

    // Merge sorted halves
    std::vector<long long> temp;
    int l = left, r = mid + 1;
    while (l <= mid && r <= right) {
        if (prefix[l] <= prefix[r]) temp.push_back(prefix[l++]);
        else temp.push_back(prefix[r++]);
    }
    while (l <= mid) temp.push_back(prefix[l++]);
    while (r <= right) temp.push_back(prefix[r++]);
    for (int i = left; i <= right; ++i) prefix[i] = temp[i - left];

    return count;
}

int mergeCount(std::vector<long long> &prefix, int left, int right, int lower, int upper) {
    if (left >= right) return 0;
    int mid = (left + right) / 2;

    int count = 0;
    count += mergeCount(prefix, left, mid, lower, upper);
    count += mergeCount(prefix, mid + 1, right, lower, upper);
    count += countWhileMerge(prefix, left, mid, right, lower, upper);

    return count;
}

int countRangeSum(std::vector<int>& nums, int lower, int upper) {
    int n = nums.size();

    // prefix sum
    // prefix array start with zero because
    // when we sum it we have to start somewhere prefix 
    // is the sum of that previous value 
    // for suppose if we want sumof nums[1, 4]
    // at 1 index nums sum is + nums[0]
    // and at 4 the nums sum is nums[0] + nums[1] + nums[2] + nums[3];
    // that how prefix some works
    // so that why we need a base to start the prefix sums 
    // and that is also how prefix some works
    // prefix[0] = 0
    // prefix[1] = nums[0] = -2
    // prefix[2] = nums[0] + nums[1] = 0
    // prefix[3] = nums[0] + nums[1] + nums[2] = 3

    std::vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    return mergeCount(prefix, 0, n, lower, upper);
}

int main() {
    std::vector<int> nums = {-2, 2, 3, 4, 1, 7};
    int lower = -2;
    int upper = 2;
    std::cout << countRangeSum(nums, lower, upper) << std::endl; // Output: 3
    return 0;
}
