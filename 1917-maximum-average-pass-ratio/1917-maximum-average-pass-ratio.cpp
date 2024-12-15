class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq{};
        for (int i{}; i < classes.size(); ++i) {
            if (classes[i][0] != classes[i][1]) {
                pq.push({(classes[i][0] + 1) / (double) (classes[i][1] + 1) - classes[i][0] / (double) classes[i][1], i});
            }
        }

        // everyone already passes
        if (pq.empty()) return 1;

        // assign students
        while (extraStudents--) {
            pair<double,int> p = pq.top();
            pq.pop();
            
            // add student to class at index
            ++classes[p.second][0];
            ++classes[p.second][1];

            // reheapify
            pq.push({(classes[p.second][0] + 1) / (double) (classes[p.second][1] + 1) - classes[p.second][0] / (double) classes[p.second][1], p.second});
        }

        
        double ans{};
        for (auto& c : classes) {
            ans += c[0] / (double) c[1];
        }

        return ans / classes.size();
    }
};