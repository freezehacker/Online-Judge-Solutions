#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

bool isPerfect(int num) {
    if (num == 1) return false;
    
    int sum = 1;
    int limit = sqrt(num);
    for (int i = 2; i <= limit; ++i) {
        if (num % i == 0) {
            sum += i + num / i;
        }
    }
    //cout << sum << endl;
    return sum == num;
}


int main() {
    //ifstream cin("in.txt");

    int n;

    while (cin >> n) {
        if ( isPerfect( n ) ) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}