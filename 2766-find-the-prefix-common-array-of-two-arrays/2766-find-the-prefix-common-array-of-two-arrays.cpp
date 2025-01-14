class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        int n = A.size() ;

        map<int, int> mpB ;
        for(int i=0; i<n; ++i) {
            mpB[B[i]] = i ;
        }

        vector<int> ans(n) ;
        int cnt ;

        for(int i=0; i<n; ++i) {

            cnt = 0 ;

            for(int j=0; j<=i; ++j) {
                if(mpB[A[j]] <= i) {
                    ++cnt ;
                }
            }

            ans[i] = cnt ;

        }

        return ans ;

    }
};