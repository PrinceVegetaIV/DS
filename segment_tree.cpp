#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define N 100001

const int NEUTRAL=-INT_MAX;

int n,q; 
vector<int> a(N); 
vector<int> tree(4*N);

int op(int x,int y) {
    return max(x,y); 
}

void build (int l,int r,int node) {
    if (l==r) {
        tree[node]=a[l];
        return; 
    }
    int mid=(l+r)/2; 
    build(l,mid,2*node+1);  
    build(mid+1,r,2*node+2);  
    tree[node]=op(tree[2*node+1],tree[2*node+2]);
}

void update(int l,int r,int node,int id,int val) {
    if (l==r) {
        tree[node]=val;  
        return; 
    }
    int mid=(l+r)/2; 
    if (id<=mid) update(l,mid,2*node+1,id,val); 
    else update(mid+1,r,2*node+2,id,val); 
    tree[node]=op(tree[2*node+1],tree[2*node+2]); 
}

int query(int l,int r,int node,int i,int j) {
    if (i<=l && r<=j) {
        return tree[node]; 
    }
    int mid=(l+r)/2;
    int ans=NEUTRAL;
    int leftval=NEUTRAL,rightval=NEUTRAL; 
    if (i<=mid) leftval=query(l,mid,2*node+1,i,j); 
    if (j>mid) rightval=query(mid+1,r,2*node+2,i,j);
    ans=op(leftval,rightval);
    return ans; 
}

void soln() {
    cin>>n>>q; 
    for (int i=0;i<n;i++) cin>>a[i]; 
    build(0,n-1,0); 
    while (q--) {
        int qr; cin>>qr;
        if (qr==1) {
            int l,r; cin>>l>>r; 
            cout<<query(0,n-1,0,l-1,r-1)<<endl;
        }
        else {
            int id,val; cin>>id>>val; 
            update(0,n-1,0,id-1,val); 
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
 

 
