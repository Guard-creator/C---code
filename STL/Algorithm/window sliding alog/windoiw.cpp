#include <iostream>
#include <deque>
#include <vector>

std::vector<int> slidingWindowMax(std::vector<int>& nums, int k) {

  // dq only save index of nums
  // it may or might have higher index value or  smaller 
  // Deque stores indices in decreasing order of their values
  // Example: After processing i=2 for nums = [1,3,-1], the deque might be [1,2] 
  // (values: [3,-1]).
  // The deque's maximum size depends directly on the window size k
  //nums = [5, 4, 3, 2, 1], k=3
  //Deque state:
  //i=0: [0] (size 1)
  //i=1: [0,1] (size 2)
  //i=2: [0,1,2] (size 3, reaches k)
  //i=3: [1,2,3] (after pop_front(), size remains 3)
  //Max deque size = k.

  std::deque<int> dq;
  std::vector<int> result;
  
  for(int i = 0; i < nums.size(); i++) {

    // i = 0;
    // this will be ignore.
    // the pop_front() operation happens when the window has reached full size 
    // (k elements) and is about to slide forward, removing the oldest element 
    // that's exiting the window. Here's the precise breakdown:
    if(!dq.empty() && dq.front() == i - k) dq.pop_front();
    // pop_front() ensures the deque only contains indices within the current window.

    // Only removes numbers that are:
    // a) Outside the window (via pop_front()), or
    // b) Smaller than the new number (via pop_back())

    // i = 0;
    // ignore too
    // we use whlie loop here because deque might have multiple 
    // element an if nums[i] is bigger then we need to from back
    // rememeber this is a loop if dq back is smaller and nums[i]
    // value is bigger its gonna remove that small value from back
    // if this condition is true the loop will run again for the second value
    // in dq to check for that.
    while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
    
    // i = 0;
    // add 0 in deque [0];
    dq.push_back(i);

    // 0 >= -1 (0 - 1)
    // ignore too will not be add in result
    // save maximum value in result when window is finished
    if(i >= k - 1) result.push_back(nums[dq.front()]);

  }

  return result;

}

int main() {

    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    std::vector<int> result = slidingWindowMax(nums, k);

    std::cout << "Window sliding Max: ";
    for(int element : result) {
      std::cout << element << " ";
    }

  return 0;
}
/*
Step-by-Step Execution:
Initial State:
dq = [] (empty deque)

result = [] (empty result)

i = 0, nums[0] = 1
Check if front is out of window:
i - k = 0 - 3 = -3 → No (since deque is empty)

Remove smaller elements from back:
Deque is empty → nothing to remove.

Add current index to deque:
dq = [0] (stores index of 1)

Check if window size reached (i ≥ k - 1):
0 >= 2 → False → Don't add to result.

State:

dq = [0]

result = []

i = 1, nums[1] = 3
Check if front is out of window:
1 - 3 = -2 → No.

Remove smaller elements from back:

Compare nums[dq.back()] = nums[0] = 1 with nums[1] = 3.

Since 1 < 3, remove 0 from deque.

Now dq = [].

Add current index to deque:
dq = [1] (stores index of 3)

Check if window size reached:
1 >= 2 → False → Don't add to result.

State:

dq = [1]

result = []

i = 2, nums[2] = -1
Check if front is out of window:
2 - 3 = -1 → No.

Remove smaller elements from back:

Compare nums[dq.back()] = nums[1] = 3 with nums[2] = -1.

Since 3 > -1, do nothing.

Add current index to deque:
dq = [1, 2] (stores indices of 3, -1)

Check if window size reached:
2 >= 2 → True → Add nums[dq.front()] = nums[1] = 3 to result.

State:

dq = [1, 2]

result = [3]

i = 3, nums[3] = -3
Check if front is out of window:
3 - 3 = 0 → dq.front() = 1 ≠ 0 → No.

Remove smaller elements from back:

Compare nums[dq.back()] = nums[2] = -1 with nums[3] = -3.

Since -1 > -3, do nothing.

Add current index to deque:
dq = [1, 2, 3] (stores indices of 3, -1, -3)

Check if window size reached:
3 >= 2 → True → Add nums[dq.front()] = nums[1] = 3 to result.

State:

dq = [1, 2, 3]

result = [3, 3]

i = 4, nums[4] = 5
Check if front is out of window:
4 - 3 = 1 → dq.front() = 1 == 1 → Remove front!
dq = [2, 3].

Remove smaller elements from back:

Compare nums[dq.back()] = nums[3] = -3 with nums[4] = 5.

Since -3 < 5, remove 3.

Now dq = [2].

Compare nums[dq.back()] = nums[2] = -1 with nums[4] = 5.

Since -1 < 5, remove 2.

Now dq = [].

Add current index to deque:
dq = [4] (stores index of 5)

Check if window size reached:
4 >= 2 → True → Add nums[dq.front()] = nums[4] = 5 to result.

State:

dq = [4]

result = [3, 3, 5]

i = 5, nums[5] = 3
Check if front is out of window:
5 - 3 = 2 → dq.front() = 4 ≠ 2 → No.

Remove smaller elements from back:

Compare nums[dq.back()] = nums[4] = 5 with nums[5] = 3.

Since 5 > 3, do nothing.

Add current index to deque:
dq = [4, 5] (stores indices of 5, 3)

Check if window size reached:
5 >= 2 → True → Add nums[dq.front()] = nums[4] = 5 to result.

State:

dq = [4, 5]

result = [3, 3, 5, 5]

i = 6, nums[6] = 6
Check if front is out of window:
6 - 3 = 3 → dq.front() = 4 ≠ 3 → No.

Remove smaller elements from back:

Compare nums[dq.back()] = nums[5] = 3 with nums[6] = 6.

Since 3 < 6, remove 5.

Now dq = [4].

Compare nums[dq.back()] = nums[4] = 5 with nums[6] = 6.

Since 5 < 6, remove 4.

Now dq = [].

Add current index to deque:
dq = [6] (stores index of 6)

Check if window size reached:
6 >= 2 → True → Add nums[dq.front()] = nums[6] = 6 to result.

State:

dq = [6]

result = [3, 3, 5, 5, 6]

i = 7, nums[7] = 7
Check if front is out of window:
7 - 3 = 4 → dq.front() = 6 ≠ 4 → No.

Remove smaller elements from back:

Compare nums[dq.back()] = nums[6] = 6 with nums[7] = 7.

Since 6 < 7, remove 6.

Now dq = [].

Add current index to deque:
dq = [7] (stores index of 7)

Check if window size reached:
7 >= 2 → True → Add nums[dq.front()] = nums[7] = 7 to result.

Final State:

dq = [7]

result = [3, 3, 5, 5, 6, 7]
*/