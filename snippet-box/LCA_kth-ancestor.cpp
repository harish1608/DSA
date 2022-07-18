//Calculates LCA of a tree using binary lifting method.
//Can also calculate kth-ancestor(independent of LCA function)
//preprocess-O(NlogN)
//LCA(u,v)- O(logN)
//kthparent- O(logK)
//parent[i][k] stores the 2^k th parent of node i, 0<=k<=logN

#include <vector>
#include <cmath>
using namespace std;

const int N=1e5;
const int M=log2(N)+2;
vector<int>adj[N+1];
int parent[N+1][M];
vector<int> depth;

int kthparent(int u, int k) {
    int i=0;
    while(k>0) {
        if(k&1)
            u=parent[u][i];
        k=k>>1;
        i++;
    }
    return u;
}

int lca(int u, int v, int m) {
    if(depth[u]>depth[v])
        swap(u,v);
    v=kthparent(v,depth[v]-depth[u]);
    if(u==v)
        return u;
    for(int i=m;i>=0;i--) {
        if(parent[u][i]!=parent[v][i]) {
            u=parent[u][i];
            v=parent[v][i];
        }
    }
    return parent[u][0];
}

void dfs(int v) {
    for(int c: adj[v]) {
        if(c==parent[v][0])
            continue;
        parent[c][0]=v;
        depth[c]=depth[v]+1;
        dfs(c);
    }
}

void init(int n) {
    depth.resize(n+1);
    dfs(1); //call by root

    int m=log2(n)+1;
    for(int j=1;j<=m;j++)
        for(int i=1;i<=n;i++)
            parent[i][j]=parent[parent[i][j-1]][j-1];
    
    //Call lca(u,v,m) for lca of u,v.
    //Call kthparent(u,k) for kth parent of u.
}