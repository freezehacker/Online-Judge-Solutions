#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const int CASE_NUM = 1;

struct Account {
    string username;
    string password;
    bool isModified;

    Account() {
        isModified = false;
    }

    void modify() {
        string ret;

        for (int i = 0, len = password.size(); i < len; ++i) {
            char ch = password[i];
            if (ch == '1') {
                ch = '@';
            } else if (ch == '0') {
                ch = '%';
            } else if (ch == 'l') {
                ch = 'L';
            } else if (ch == 'O') {
                ch = 'o';
            }

            if (!isModified && ch != password[i]) {
                isModified = true;
            }

            ret.push_back(ch);
        }

        password = ret;
    }
};


int main() {
    //ifstream cin("in.txt");

    int t = CASE_NUM;

    while (t--) {

        int num;
        cin >> num;

        vector<Account> modifiedAccountList;    // Store those whose password will be modified.

        for (int i = 0; i < num; ++i) {
            Account account;
            cin >> account.username >> account.password;

            account.modify();

            if (account.isModified) {
                modifiedAccountList.push_back(account);
            }
        }


        // output
        int size = modifiedAccountList.size();
        if (0 == size) {
            if (1 == num) {
                cout << "There is 1 account and no account is modified" << endl;
            } else {
                cout << "There are " << num << " accounts and no account is modified" << endl;
            }
        } else {
            cout << size << endl;
            for (int i = 0; i < size; ++i) {
                cout << modifiedAccountList[i].username << " " << modifiedAccountList[i].password << endl;
            }
        }

    }

    return 0;
}
