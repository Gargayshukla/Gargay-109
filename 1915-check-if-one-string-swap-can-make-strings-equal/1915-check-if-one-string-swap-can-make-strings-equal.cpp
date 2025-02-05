class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int left = 0;
        int right = s1.size()-1;

        while(left < right){
            if(s1[left] == s2[left]){
                left++;
                continue;
            }
            break;
        }
        while(left < right){
            if(s1[right] == s2[right]){
                right--;
                continue;
            }
            break;
        }
        swap(s2[left],s2[right]);
        if(s1 == s2){
            return true;
        }
        return false;
    }
};