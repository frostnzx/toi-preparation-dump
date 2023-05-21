#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;
using i3 = tuple<ll , ll , ll> ;

const int N = 2e5+5 ;

int n , m , ans[N] , downPath[N] , mxans ;

vector<int> G[N] ;

//length of the longest path in a tree


// calculate best down path (height of subtree) of each subtree first
int cal_subtree(int u , int p){
    for(int v : G[u]){
        if(v == p) continue ;
        downPath[u] = max(downPath[u] , cal_subtree(v , u) + 1) ;
    }
    return downPath[u] ;
}

void cal_ans(int u , int p){ // need to go through every node in case the longest path cross that node
    int mx1 , mx2 , child_cnt = 0 ;
    mx1 = mx2 = -1e9 ;

    for(int v : G[u]){
        if(v == p) continue ;
        cal_ans(v , u) ;

        if(downPath[v] > mx2) {
            mx2 = downPath[v] ;
        }
        if(mx2 > mx1){
            swap(mx1 , mx2) ;
        }
        child_cnt++;
    }

    if(child_cnt == 0){
        ans[u] = 0 ;
    }
    else if(child_cnt == 1){
        ans[u] = 1 + mx1 ;
    }
    else {
        ans[u] = 2 + mx1 + mx2 ;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;
    for(int i=1;i<=n-1;i++){
        ll u , v , w ;
        cin >> u >> v ;
        G[u].push_back(v) , G[v].push_back(u) ;
    }

    cal_subtree(1 , 1); // calculate height of each subtree
    // let 1 be the root

    cal_ans(1 , 1) ;
    for(int i=1;i<=n;i++){
        mxans = max(mxans , ans[i]) ;
    }
    cout << mxans ;
}
