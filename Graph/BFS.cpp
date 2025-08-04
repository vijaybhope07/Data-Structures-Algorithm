#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>bfs_of_graph(vector<vector<int>>& adj, int V){
    vector<int> ans;
    vector<int> vis(V,0);
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        vis[curr] = 1;
        ans.push_back(curr);
        for(auto & it : adj[curr]){
            if(vis[it] == 0){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return ans;
}
int main(){
    int V = 5;
    vector<vector<int>> adj(V);
    adj[0] = {1,2};
    adj[1] = {0,3};
    adj[2] = {0,4};
    adj[3] = {1};
    adj[4] = {2};
    vector<int> result = bfs_of_graph(adj,V);
    cout <<"BFS Traversal: " ;
    for(int node : result){
        cout << node << " ";
    }
    cout << endl;
    return 0;
}