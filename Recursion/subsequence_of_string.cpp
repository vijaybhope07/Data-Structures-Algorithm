#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void solve(vector<string>& ans, string output, string str, int index) {
    if (index >= str.length()) {
        if (output.length() > 0) {
            ans.push_back(output);
        }
        return;
    }
    solve(ans, output, str, index + 1);
    solve(ans, output + str[index], str, index + 1);
}
vector<string> subsequences(string str) {
    vector<string> ans;
    string output = "";
    solve(ans, output, str, 0);
    sort(ans.begin(), ans.end());
    return ans;
}
int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    vector<string> result = subsequences(s);
    cout << "Subsequences are: " << endl;
    for (const string& sub : result) {
        cout << sub << endl;
    }
    return 0;
}
