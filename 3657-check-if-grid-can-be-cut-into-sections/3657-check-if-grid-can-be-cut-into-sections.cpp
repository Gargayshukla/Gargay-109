class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> for_vertical_cuts, for_horizontal_cuts;

        for(auto rect: rectangles){
            for_vertical_cuts.push_back({rect[0],rect[2]});
            for_horizontal_cuts.push_back({rect[1],rect[3]});
        }

        sort(for_vertical_cuts.begin(),for_vertical_cuts.end());
        sort(for_horizontal_cuts.begin(),for_horizontal_cuts.end());

        int end_vertical = for_vertical_cuts[0][1], end_horizontal=for_horizontal_cuts[0][1];
        int cnt_vertical=0, cnt_horizontal=0;
        for(int i=1;i<for_vertical_cuts.size();i++){
            if(for_vertical_cuts[i][0] >= end_vertical){
                cnt_vertical++;
                if(cnt_vertical>=2) return true;
            }
            if(for_horizontal_cuts[i][0] >= end_horizontal){
                cnt_horizontal++;
                if(cnt_horizontal>=2) return true;
            }
            end_horizontal = max(end_horizontal, for_horizontal_cuts[i][1]);
            end_vertical = max(end_vertical, for_vertical_cuts[i][1]);
        }

        return false;

    }
};