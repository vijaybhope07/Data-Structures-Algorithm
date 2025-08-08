#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int findKthLargest(vector<int>& nums, int k){
    priority_queue<int, vector<int>, greater<int>> minheap;
    for(int num : nums){
        minheap.push(num);
        if(minheap.size() > k){
            minheap.pop();
        }
    }
    return minheap.top();
}
int main(){
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    int result = findKthLargest(nums, k);
    cout << "The Kth largets element is " << result << endl;
    return 0;
}