#include<bits/stdc++.h>
using namespace std;


#define int long long 
#define N 100001

int n,q;  
vector<int> a(N); 
int sz;  
int res=0,cl=0,cr=-1;  

struct query{
    int l,r,idx; 
};

void add(int idx) {
    res+=a[idx]; 
} 
void remove(int idx) {
    res-=a[idx]; 
}

void soln() {
    cin>>n>>q; 
    for (int i=0;i<n;i++) cin>>a[i]; 

    sz=sqrt(n); 

    vector<query> queries(q); 
    for (int i=0;i<q;i++) {
        int l,r; cin>>l>>r; 
        --l,--r; 
        queries[i]={l,r,i}; 
    } 

    sort(queries.begin(),queries.end(),[&](const query &x,const query&y) {
        int blockx=x.l/sz; 
        int blocky=y.l/sz; 
        if (blockx!=blocky) return blockx<blocky;  
        return x.r<y.r; 
    });

    vector<int> ans(q); 

    for (auto query:queries) {
        int l=query.l;  
        int r=query.r; 

        while (cr<r) add(++cr); 
        while (cr>r) remove(cr--);
        while (cl>l) add(--cl);
        while (cl<l) remove(cl++);

        ans[query.idx]=res; 
    }

    for (int i=0;i<q;i++) {
        cout<<ans[i]<<endl;
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
 

 
