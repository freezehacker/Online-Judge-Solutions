// Author:
// https://leetcode.com/derekhh/

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int real_a, imag_a, real_b, imag_b;
        sscanf(a.c_str(), "%d+%di", &real_a, &imag_a);
        sscanf(b.c_str(), "%d+%di", &real_b, &imag_b);
        int real = real_a * real_b - imag_a * imag_b;
        int imag = real_a * imag_b + real_b * imag_a;
        return to_string(real) + "+" + to_string(imag) + "i";
    }
};