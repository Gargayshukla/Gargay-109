class Solution {
public:
    bool rotateString(string s, string goal) {
        
        if(s.size() != goal.size())
        {
            return false;
        }

        string d = s + s;

        return d.find(goal) != string::npos;
    }
};