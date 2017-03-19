#include <iostream>
#include <fstream>
#include <string>
//using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

int main(int argc, const char* argv[]) {
    
    ifstream cin("in.txt");
    ofstream cout("out.txt");

    string str;
    cin >> str;

    int n1, n2, n3;
    int size = str.size();
    n1 = n3 = (size + 2) / 3;
    n2 = size + 2 - n1 - n3;

    for (int i = 0; i < n1 - 1; ++i) {
        cout << str[i];
        for (int j = 0; j < n2 - 2; ++j) {
            cout << " ";
        }
        cout << str[size - 1 - i];
        cout << endl;
    }
    cout << str.substr(n1 - 1, n2);
    cout << endl;

    return 0;
}
