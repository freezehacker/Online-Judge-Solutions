#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<string, vector<string> > related;
map<string, int> weight;
map<string, bool> visited;
int numOfRelation, threshold;
int num;
int sum;
string gangHead;
int gangWeight;
map<string, int> answer;

void dfs(const string &person) {
    visited[person] = true;
    ++num;
    sum += weight[person];
    if (weight[person] > gangWeight) {
        gangHead = person;
        gangWeight = weight[person];
    }

    for (int i = 0, len = related[person].size(); i < len; ++i) {
        const string &other = related[person].at(i);
        if (!visited[other]) {
            dfs(other);
        }
    }
}


int main() {
    //ifstream cin("in.txt");

    cin >> numOfRelation >> threshold;
    
    string person1, person2;
    int callTime;
    for (int i = 0; i < numOfRelation; ++i) {
        cin >> person1 >> person2 >> callTime;

        related[person1].push_back(person2);
        weight[person1] += callTime;
        weight[person2] += callTime;
        visited[person1] = visited[person2] = false;
    }

    
    for (map<string, bool>::iterator iter = visited.begin(); iter != visited.end(); ++iter) {
        num = sum = 0;
        gangWeight = -1;
        if (iter->second == false) {
            dfs(iter->first);
        }

        // If it satisfies the condition of a "gang"...
        if (num > 2 && sum / 2 > threshold) {   // Note: point weights = edge weight * 2.
            //cout << gangHead << " " << num << endl;
            answer[gangHead] = num;
        }
    }


    cout << answer.size() << endl;
    for (map<string, int>::iterator iter = answer.begin(); iter != answer.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }

    return 0;
}
