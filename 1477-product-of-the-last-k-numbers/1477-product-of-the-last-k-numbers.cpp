class ProductOfNumbers {
public:
    int prevProduct = 1;
    vector<int> v;

    ProductOfNumbers() {}

    void add(int num) {
        if (num == 0) {
            v.clear();
            prevProduct = 1;
        } else {
            int currProduct = prevProduct * num;
            v.push_back(currProduct);
            prevProduct = currProduct;
        }
    }

    int getProduct(int k) {
        if (k > v.size()) return 0;
        if (k == v.size()) return v[v.size() - 1];
        return v[v.size() - 1] / v[v.size() - k - 1];
    }
};