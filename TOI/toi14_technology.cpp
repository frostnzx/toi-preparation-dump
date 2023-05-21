#include<bits/stdc++.h>
#define DEBUG 0

using namespace std;

const int N = 1e5+5 ;

int n , k , t , indeg[N] , lvl[N] , lvl_cnt[N] , ans;

vector<int> G[N] ;
queue<int> q ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k >> t ;
    for(int i=1 , l , p;i<=n;i++){
        cin >> l >> p ;
        for(int j=1 , x;j<=p;j++){
            cin >> x ;
            G[x].push_back(i);
        }
        indeg[i] = p ;
        lvl[i] = l ;
        lvl_cnt[l]++;

        if(indeg[i] == 0){
            q.push(i);
        }
    }
    int cnt = 0 ;
    while(!q.empty() && cnt++ < t){
        int u = q.front(); q.pop();

        lvl_cnt[lvl[u]]--;

        for(int v : G[u]){
            indeg[v]--;
            if(indeg[v] == 0){
                q.push(v);
            }
        }
    }
    if(DEBUG){
        for(int i=1;i<=k;i++){
            cout << "lvl_cnt[" << i << "] = " << lvl_cnt[i] << "\n" ;
        }
    }

    for(int i=1;i<=k;i++){
        if(lvl_cnt[i] == 0){
            ans = i ;
        }
        else break;
    }
    if(ans == 0){
        ans--;
    }

    cout << ans;
}

