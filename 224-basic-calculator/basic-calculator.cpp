class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int num = 0, result = 0, sign = 1;
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            
            if (isdigit(c)) {
                num = num * 10 + (c - '0');  // Form the number
            } else if (c == '+' || c == '-') {
                result += sign * num;  // Apply the previous sign
                num = 0;               // Reset number
                sign = (c == '+') ? 1 : -1;  // Update sign
            } else if (c == '(') {
                stk.push(result);  // Store previous result
                stk.push(sign);    // Store previous sign
                result = 0;        // Reset result for new expression
                sign = 1;          // Reset sign
            } else if (c == ')') {
                result += sign * num;  // Apply the last collected number
                num = 0;
                result *= stk.top();   // Multiply by stored sign
                stk.pop();
                result += stk.top();   // Add stored result
                stk.pop();
            }
        }
        return result + (sign * num);  // Apply last number if present
    }
};
