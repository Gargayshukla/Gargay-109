class Solution {
public:
    int minimumLength(string s) {
        int present = 0;
        int parity = 0;
        int placevalue;
        for (int k = 0; k < s.size(); k++) {
            placevalue = 1 << (s[k] - 'a');
            present |= placevalue;
            parity ^= placevalue;
        }
        int count = 0;
        while (present) {
            placevalue = present & (present - 1);
            count += 2 - ((parity & (present - placevalue)) != 0);
            present = placevalue;
        }
        return count;
    }
};