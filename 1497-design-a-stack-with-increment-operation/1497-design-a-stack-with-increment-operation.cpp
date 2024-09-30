class CustomStack {
public:

    int* st;
    int maxi;
    int top;

    CustomStack(int maxSize) {
        
      st = new int[maxSize];
      maxi = 0;
      top = maxSize;
    }
    
    void push(int x) {
        if(maxi < top){
        st[maxi] = x;
        maxi++;
        }
    }
    
    int pop() {
        if(maxi == 0){
        return -1;
        }
        maxi--;
        return st[maxi];
    }
    
    void increment(int k, int val) {
        for(int i=0; i< min(k, maxi); i++)
        {
         st[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */