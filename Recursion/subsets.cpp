#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
void createSubset(vector<int>& nums, int index, vector<vector<int>>& res, vector<int>& subset){
    if(index == nums.size()){
        res.push_back(subset);
        return;
    }
    subset.push_back(nums[index]);
    createSubset(nums,index+1, res, subset);
    subset.pop_back();
    createSubset(nums,index+1, res, subset);
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> subset;
    createSubset(nums,0, res, subset);
    return res;
}
int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);
    cout << "All subsets:" << endl;
    for (const auto& s : result) {
        cout << "[";
        for (size_t i = 0; i < s.size(); ++i) {
            cout << s[i];
            if (i < s.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    vector<int> nums2 = {0};
    vector<vector<int>> result2 = subsets(nums2);
    cout << "\nAll subsets for {0}:" << endl;
    for (const auto& s : result2) {
        cout << "[";
        for (size_t i = 0; i < s.size(); ++i) {
            cout << s[i];
            if (i < s.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    return 0;
}
