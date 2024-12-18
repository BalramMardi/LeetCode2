class ProductOfNumbers {
public:
    vector<int> vec;
    vector<int> zeroCount;
    vector<long long> prod;

    ProductOfNumbers() {
        vec.clear();
        zeroCount.clear();
        prod.clear();
    }

    void add(int num) {
        if (vec.empty()) {
            zeroCount.push_back(num == 0 ? 1 : 0);
            prod.push_back(num == 0 ? 1 : num);
        } else {
            zeroCount.push_back(zeroCount.back() + (num == 0 ? 1 : 0));
            prod.push_back(num == 0 ? 1 : prod.back() * num);
        }
        vec.push_back(num);
    }

    int getProduct(int k) {
        int n = vec.size();
        if (k > n) {
            return 0;
        }
        int endIdx = n - 1;
        int startIdx = n - k;

        int zerosInRange = zeroCount[endIdx] - (startIdx > 0 ? zeroCount[startIdx - 1] : 0);
        if (zerosInRange > 0) {
            return 0; 
        }

        if (startIdx == 0) {
            return prod[endIdx];
        } else {
            return prod[endIdx] / prod[startIdx - 1];
        }
    }
};
