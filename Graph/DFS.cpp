#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<int>& ans, vector<int>& vis, int node, vector<int> adj[]){
    vis[node] = 1;
    ans.push_back(node);
    for(auto &it : adj[node]){
        if(vis[it]){
            vis[it] = 1;
            dfs(ans,vis, it, adj);
        }
    }
}
vector<int> dfs_of_graph(int V, vector<int> adj[]){
    vector<int> ans;
    vector<int> vis(V, 0);
    for(int i = 0 ; i < V ; i++){
        if(vis[0] == 0){
            dfs(ans, vis, i adj);
        }
    }
    return ans;
}
int main() {
    int V = 5;
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(4);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[4].push_back(1);
    vector<int> result = dfs_of_graph(adj, V);
    cout << "DFS Traversal: ";
    for(auto node : result) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}
