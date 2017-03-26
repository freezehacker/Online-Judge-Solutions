#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

struct ComplexNumber {
    int real;
    int imagine;

    ComplexNumber() {}

    ComplexNumber(const string &str) {
        int plusIdx = -1;
        for (int i = 0, size = str.size(); i < size; ++i) {
            if (str[i] == '+') {
                plusIdx = i;
                break;
            }
        }

        real = __stringToInt( str.substr( 0, plusIdx ) );
        imagine = __stringToInt( str.substr( plusIdx + 1, str.size() - plusIdx - 2 ) );

        cout << toString() << endl;
    }

    static ComplexNumber mul(const ComplexNumber &cn1, const ComplexNumber &cn2) {
        ComplexNumber ret;
        ret.real = cn1.real * cn2.real - cn1.imagine * cn2.imagine;
        ret.imagine = cn1.real * cn2.imagine + cn1.imagine * cn2.real;
        return ret;
    }

    string toString() const {
        return __intToString(real) + "+" + __intToString(imagine) + "i";
    }

    static string complexNumberMultiply(string a, string b) {
        ComplexNumber cn1(a);
        ComplexNumber cn2(b);
        ComplexNumber cn = ComplexNumber::mul(cn1, cn2);
        return cn.toString();
    }

    int __stringToInt(const string &str) const {
        if (str == "0") return 0;

        bool isNegative = false;
        string tmp = str;

        if (str[0] == '-') {    // Consider a negative number.
            isNegative = true;
            tmp = str.substr(1);
        }

        int ret = 0;
        for (int i = 0, size = tmp.size(); i < size; ++i) {
            ret = ret * 10 + (tmp[i] - '0');
        }

        if (isNegative) {
            ret = -ret;
        }

        return ret;
    }

    string __intToString(int n) const {
        if (n == 0) return "0";

        bool isNegative = false;
        if (n < 0) {
            isNegative = true;
            n = -n;
        }

        stack<char> chars;

        while (n) {
            chars.push( n % 10 + '0' );
            n /= 10;
        }

        string ret;
        while ( !chars.empty() ) {
            ret.push_back( chars.top() );
            chars.pop();
        }

        if (isNegative) {
            ret = "-" + ret;
        }
        return ret;
    }
};


int main() {
    //ifstream cin("in.txt");

    ComplexNumber tmp;
    cout << tmp.__stringToInt("-520") << endl;
    cout << tmp.__intToString(-590) << endl;

    string result = ComplexNumber::complexNumberMultiply("1+-1i", "1+-1i");
    cout << result << endl;

    return 0;
}