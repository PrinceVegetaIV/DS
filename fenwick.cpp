#include<bits/stdc++.h>
using namespace std;


#define int long long 
#define N 100001

vector<int> a(N);
vector<int> fenwick(N);
int n,q; 

int lsb(int x) {
    return x & -x; 
}

void update(int i,int val) {
    while (i<=n) {
        fenwick[i]+=val; 
        i+=lsb(i);
    }
}

int query(int i) {
    int sum=0; 
    while (i>0) {
        sum+=fenwick[i];
        i-=lsb(i); 
    }
    return sum;
}

void soln() {
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
       cin>>a[i]; 
       update(i,a[i]);
    }

    while (q--) {
        int qr; cin>>qr;
        if (qr==1) {
            int l,r; cin>>l>>r; 
            cout<<query(r)-query(l-1)<<endl;
        }
        else {
            int id,val; cin>>id>>val; 
            update(id,val); 
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
 

 
