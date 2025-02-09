class NumberContainers {
public:
    unordered_map<int, priority_queue<int, vector<int>, greater<>>> ntoi;
    unordered_map<int, int> iton;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        iton[index] = number;
        if(ntoi.find(number) != ntoi.end()){
            ntoi[number].push(index);
        } else{
            priority_queue<int, vector<int>, greater<>> pq;
            pq.push(index);
            ntoi[number] = pq;
        }
    }
    
    int find(int number) {
        if(ntoi.find(number) != ntoi.end()) {
            priority_queue<int, vector<int>, greater<>> pq = ntoi[number];
            while(!pq.empty()){
                if(iton[pq.top()] == number){
                    return pq.top();
                }
                pq.pop();
            }
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */