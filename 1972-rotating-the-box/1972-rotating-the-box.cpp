class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        
        int n1 = box.size();
        int n2 = box[0].size();

        vector<vector<char>> b;

        for(int i=0; i<n1; i++)
        {
            bool flag = false;
            for(int j = n2-1; j>0; j--)
            {
                if(box[i][j] == '.' && box[i][j-1] == '#')
                {
                    swap(box[i][j], box[i][j-1]);
                    flag = true;
                }
                }
                if(flag) i=i-1;
            }

            for(int i=0; i<n2; i++)
            {
                vector<char> v;
                for(int j = n1 - 1; j >= 0; j--)
                {
                    v.push_back(box[j][i]);
                }
                b.push_back(v);
            
            }

        return b;
    }
};