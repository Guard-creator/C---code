#include <iostream>
#include <stack>

// Problem: Valid Parentheses (LeetCode 20)

// Given a string containing only ()[]{}, determine if the string is valid.
// A string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.

// EXAMPLE: 
// 1..
// Input: "()"
// Output: true
// 2..
// Input: "()[]{}"
// Output: true

/* how to solve it?

Traverse the string character by character.
If it’s an opening bracket ((, [, {), push it to stack.
If it’s a closing bracket (), ], }):
Stack must not be empty.
Pop from stack and check if it matches the correct opening.
In the end → stack should be empty for string to be valid.

*/

class Solution {
public:
    bool isValid(std::string s) {

        std::stack<char> st;

        // looping over string
        for(char c : s) {

            // if the starting bracket's exist then push it in stack
            // if in start it doesn't exist means the stack will be empty
            // and the string will be return in fasle means it in wrong order
            if(c == '[' || c == '{' || c == '(') {
                st.push(c);
            } else {
                
                // if stack is empty means it in wrong order
                if(st.empty()) return false;

                // get the top and saved it for later
                // then will pop 
                // becauase if all the starting bracket's is in stack
                // means only ending bracket's will be if not is in wrong order
                char top = st.top();
                st.pop();

                // check the condition 
                // if the ending bracket's is here 
                // and the top is NOT EQUAL to starting bracket's
                // if it's equal means condition will be ignore 
                // if not condition will be true 
                // and lead to false 
                if((c == ')' && top != '(') || 
                   (c == '}' && top != '{') || 
                   (c == ']' && top != '[')) {
                    return false;
                }
 
            }

        }

        // in the end 
        // stack should be empty 
        // because if all condition passess 
        // means we pop every single char in stack that was the starting Brackets
        return st.empty();

    }
};

int main() {
    Solution sol;

    // test cases
    std::cout << sol.isValid("()") << '\n';       // expected 1 (true)
    std::cout << sol.isValid("()[]{}") << '\n';   // expected 1 (true)
    std::cout << sol.isValid("(]") << '\n';       // expected 0 (false)
    std::cout << sol.isValid("([)]") << '\n';     // expected 0 (false)
    std::cout << sol.isValid("{[]}") << '\n';     // expected 1 (true)
}
