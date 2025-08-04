#include<bits/stdc++.h>
using namespace std;


#define int long long 
#define N 100001
#define K 26

int st[K][N]; 
int a[N];

int fun(int x,int y) {
    return min(x,y);
}

void soln() {

    int n; cin>>n;  
    for (int i=0;i<n;i++) cin>>a[i];

    for (int i=0;i<n;i++) st[0][i]=a[i]; 
    
    for (int i=1;i<K;i++) {
        for (int j=0;j+(1LL<<i)-1<n;j++) {
            st[i][j]=fun(st[i-1][j],st[i-1][j+(1LL<<(i-1))]);
        }
    }

    vector<int> lg(n+1); 
    for (int i=2;i<=n;i++) {
        lg[i]=lg[i/2]+1;
    }

    int q; cin>>q; 
    while (q--) {
        int l,r; cin>>l>>r; 
        l--,r--; 
        int i=lg[r-l+1]; 
        int ans=fun(st[i][l],st[i][r-(1LL<<i)+1]);
        cout<<ans<<endl;
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
 

 
