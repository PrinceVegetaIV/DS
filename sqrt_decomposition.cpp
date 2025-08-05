#include<bits/stdc++.h>
using namespace std;


#define int long long 
#define N 100001

int n,q; 
vector<int> a(N); 
vector<int> block; 
int sz;

void build() {
    sz=sqrt(n); 
    block.resize((n+sz-1)/sz,0); 

    for (int i=0;i<n;i++) {
        block[i/sz]+=a[i]; 
    }
}

void update(int pos,int val) {
    block[pos/sz]+=val-a[pos];
    a[pos]=val;
}

int query(int l,int r) {
    int sum=0; 
    int suru=l/sz;  
    int sesh=r/sz;  

    if (suru==sesh) {
        for (int i=l;i<=r;i++) sum+=a[i]; 
        return sum; 
    }
    for (int i=l;i<(suru+1)*sz;i++) {
        sum+=a[i]; 
    }
    for (int i=suru+1;i<sesh;i++) {
        sum+=block[i]; 
    }
    for (int i=sesh*sz;i<=r;i++) {
        sum+=a[i]; 
    }

    return sum;
}

void soln() {
    cin>>n>>q; 
    for (int i=0;i<n;i++) cin>>a[i];
    
    build(); 
    
    while (q--) {
        int qr; cin>>qr;
        if (qr==1) {
            int l,r; cin>>l>>r; 
            cout<<query(l-1,r-1)<<endl;
        }
        else {
            int id,val; cin>>id>>val; 
            update(id-1,val); 
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
 

 
