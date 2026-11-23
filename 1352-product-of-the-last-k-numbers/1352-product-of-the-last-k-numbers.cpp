class ProductOfNumbers {
public:
    vector<int>vec;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        vec.push_back(num);
    }
    
    int getProduct(int k) {
        
        long long ans = 1LL;
        int n = vec.size();
        for(int i=n-k;i<n;i++){
            ans *= vec[i];
        }
        
        return int(ans);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */