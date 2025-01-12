class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int>st1, st2;
        for(int i = 0; i < s.size(); i++){  
           if(locked[i] == '0')st2.push(i);
           else if(s[i] == '(')st1.push(i);
            else{
                if(st1.size()) st1.pop();
                else if(st2.size()) st2.pop();
                else return 0;
            }
        }

        while(st1.size() && st2.size() && st1.top() < st2.top())
            st1.pop(), st2.pop();

        return !st1.size() && st2.size() % 2 == 0;
    }
};