//Topological sort of a DAG - O(n+m)
//something like
//5->3->4->2->1

#include <vector>
#include <algorithm>

const int maxN=1e5;
vector<int>adj[maxN+1];
vector<int>res;

void dfs(int v, int vis[]) {
    vis[v]=1;
    for(int u: adj[v])
        if(!vis[u])
            dfs(u,vis);
    res.push_back(v);
}

void topological_sort(int n) {
    int vis[n+1]={};
    for(int i=1;i<=n;i++)
        if(!vis[i])
            dfs(i,vis);
    reverse(res.begin(),res.end());
}