#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool compare(const pair<string, int>& a, const pair<string, int>& b) {
    return a.first < b.first;
}

vector<int> suffixArray(const string& str) {
    int n = str.length();
    vector<pair<string, int>> suffixes(n);

    for (int i = 0; i < n; i++) {
        suffixes[i] = make_pair(str.substr(i), i);
    }

    sort(suffixes.begin(), suffixes.end(), compare);

    vector<int> suffixArray(n);
    for (int i = 0; i < n; i++) {
        suffixArray[i] = suffixes[i].second;
    }

    return suffixArray;
}

int main() {
    string str = "banana";
    vector<int> sa = suffixArray(str);

    cout << "Suffix Array: ";
    for (int i = 0; i < sa.size(); i++) {
        cout << sa[i] << " ";
    }
    cout << endl;

    return 0;
}
