#include<bits/stdc++.h>

using namespace std;

using ll = long long ;

const int N = 1e7+5 ;

ll n , m , q , A[15] , S[N] , T[15] , L[15] , Q[15] , sum[N] ;

bool vis[15] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> q ;
    for(int i=1;i<=n;i++){
        cin >> L[i] ;
    }
    for(int i=1;i<=n;i++){
        cin >> A[i] ;
    }
    for(int i=1;i<=m;i++){
        cin >> S[i] ;
        sum[i] = S[i] + sum[i-1] ;
    }
    for(int i=1;i<=q;i++){
        cin >> T[i] ;
    }
    sort(L+1 , L+n+1);

    for(int round=1;round<=q;round++){
        bool valid = false ;

        for(int i=1;i<=n;i++){
            cin >> Q[i] ;
        }
        Q[n+1] = m+1 ;
        do{
            int done_cnt = 0 ;
            for(int i=1;i<=15;i++){
                vis[i] = false ;
            }
            for(int i=1;i<=n;i++){ // each lines
                bool have_lift = false ;
                for(int lift=1;lift<=n;lift++){ // select lift for line i
                    if(vis[lift]){
                        continue ;
                    }
                    ll lo = Q[i] , hi = Q[i+1] , cnt = 0 ;
                    while(lo < hi){
                        lo = upper_bound(sum + lo , sum + hi , sum[lo - 1] + L[lift] - A[lift]) - sum ;
                        cnt++;
                        if(cnt > T[round]){ // prevent infinite loop
                            break;
                        }
                    }
                    if(cnt <= T[round]){ // if can use then use this lift for line i
                        vis[lift] = true , done_cnt++ , have_lift = true;
                        break;
                    }
                }
                if(!have_lift){
                    break;
                }
            }
            if(done_cnt == n){
                valid = true ;
            }
        }while(next_permutation(A+1 , A+n+1) && !valid); // for staff
        if(valid){
            cout << "P\n" ;
        }
        else {
            cout << "F\n" ;
        }
    }
}
