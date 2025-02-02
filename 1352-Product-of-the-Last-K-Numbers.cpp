class ProductOfNumbers {
    vector<int> product;

public:
    ProductOfNumbers() {
        product.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            product.clear();
            product.push_back(1);
        } else {
            product.push_back(product.back() * num);
        }
    }
    
    int getProduct(int k) {
        if (k > int(product.size()) - 1)
            return 0;
        else 
            return product.back() / product[int(product.size()) - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */