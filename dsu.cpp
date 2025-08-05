#include<bits/stdc++.h>
using namespace std;


#define int long long 
#define N 100001

vector<int> parent(N); 

int find(int u) {
    if (parent[u]==u) return u; 
    return parent[u]=find(parent[u]);
}

void unite(int u,int v) {
    u=find(u);
    v=find(v); 
    if (u!=v) {
        parent[u]=v; 
    }
} 

void soln() {
    int n,q; cin>>n>>q;
    for (int i=1;i<=n;i++) parent[i]=i;

    while (q--) {
        string s; cin>>s;  
        if (s=="union") {
            int a,b; cin>>a>>b; 
            unite(a,b);
        } 
        else {
            int a; cin>>a; 
            cout<<find(a)<<endl;
        }
    }

}       



signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif



    int tc=1; 
    while (tc--) { 
        soln();
    }
    
    
 
    return 0;

}   
 

 
