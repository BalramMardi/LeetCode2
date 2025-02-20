class Solution {
public:
    int countBinaryDigits(const string& binary) {
        return binary.length();
    }

    int binaryToDecimal(const string& binary) {
        int decimal = 0;
        int n = binary.length();

        for (int i = 0; i < n; i++) {
            if (binary[i] == '1') {
                decimal += (1 << (n - 1 - i)); 
            }
        }

        return decimal;
    }

    string decimalToBinary(int n, int length) {
        string binary = "";
        while (n > 0) {
            binary = (n % 2 == 0 ? "0" : "1") + binary;
            n /= 2;
        }

        while (binary.length() < length) {
            binary = "0" + binary;
        }

        return binary;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int len = countBinaryDigits(nums[0]);
        vector<bool> vec((1 << len), false);

        for (const string& num : nums) {
            int decimalValue = binaryToDecimal(num);
            vec[decimalValue] = true;
        }

        for (int i = 0; i < (1 << len); i++) {
            if (!vec[i]) {
                return decimalToBinary(i, len);
            }
        }

        return "";
    }
};
