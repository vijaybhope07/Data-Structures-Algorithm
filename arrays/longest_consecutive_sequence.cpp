#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int longestconsecutiveSeq(vector<int>& nums){
    unordered_map<int, bool> mp;
    for(int i = 0; i < nums.size(); i++){
        mp[nums[i]] = true;
    }
    for(int i = 0; i < nums.size(); i++){
        if(mp.find(nums[i] - 1) != mp.end()){
            mp[nums[i]] = false;
        }
    }
    int maxLen = 0;
    for(int i = 0; i < nums.size(); i++){
        if(mp[nums[i]]){
            int j = 0;
            int count = 0;
            while(mp.count(nums[i] + j) > 0){
                j++;
                count++;
            }
            if(count > maxLen){
                maxLen = count;
            }
        }
    }
    return maxLen;
}
int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int result = longestconsecutiveSeq(nums);
    cout << "Length of the longest consecutive sequence: " << result << endl;
    return 0;
}