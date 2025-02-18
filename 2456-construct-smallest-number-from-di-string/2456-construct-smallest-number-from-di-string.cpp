class Solution {
public:
    string smallestNumber(string pattern) {
        string result;
        stack<int> stk;
       
        for (int i = 0; i <= pattern.size(); i++) {
            stk.push(i + 1);
            if (i == pattern.size() || pattern[i] == 'I') {
                while (!stk.empty()) {
                    result += to_string(stk.top());
                    stk.pop();
                }
            }
        }
        return result;
    }
};
