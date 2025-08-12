#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
    vector<string> result;  
    void solve(int idx, string &digits, string &temp, unordered_map<char, string> &mp) {
        if (idx >= digits.length()) {
            result.push_back(temp);
            return;
        }   
        char ch = digits[idx];
        string str = mp[ch];
        for (int i = 0; i < str.length(); i++) {
            temp.push_back(str[i]);
            solve(idx + 1, digits, temp, mp);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        result.clear();
        if (digits.length() == 0) {
            return {};
        }
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        string temp = "";
        solve(0, digits, temp, mp);
        return result;
    }
};
int main() {
    Solution sol;
    string digits;
    cout << "Enter digits: ";
    cin >> digits;
    vector<string> combos = sol.letterCombinations(digits);
    cout << "Letter combinations are:" << endl;
    for (const string &combo : combos) {
        cout << combo << endl;
    }
    return 0;
}
