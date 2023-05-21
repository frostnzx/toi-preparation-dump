#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
const int N = 2e5+5 ;

ll n , arr[N];

ll ans = 0 ;

struct DATA{
    ll a , b ;
    bool operator<(const DATA &other) const {
        return b < other.b ;
    }
};

vector<DATA> v ;

void solve(int l ,int r){
    if(l >= r){
        return ;
    }
    int mid = (l+r)/2 ;
    solve(l , mid);
    solve(mid+1 , r) ;

    int n1 = (mid-l)+1 , n2 = r - mid ;
    ll L[n1] , R[n2] , qsL[n1] ;

    for(int i=0;i<n1;i++){
        L[i] = arr[l+i] ;
    }
    for(int i=0;i<n2;i++){
        R[i] = arr[mid+1+i] ;
    }

    qsL[0] = L[0] ;
    for(int i=1;i<n1;i++){
        qsL[i] = qsL[i-1] + L[i] ;
    }

    int i=0 , j=0 , k=l ;
    while(i < n1 && j < n2){
        if(L[i] < R[j]){
            arr[k] = L[i] ;
            i++;
        }
        else {
            arr[k] = R[j] ;
            ans += (qsL[n1-1] - qsL[i]) + L[i] + ((n1 - i) * R[j]) ;
            j++;
        }
        k++;
    }
    while(i < n1){
        arr[k] = L[i] ;
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = R[j] ;
        j++;
        k++;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;
    for(int i=1 , x ,y;i<=n;i++){
        cin >> x >> y ;
        v.push_back({x ,y});
    }

    sort(v.begin() , v.end());
    int idx = 0 ;
    for(auto &[a , b] : v){
        arr[idx++] = a ;
    }

    solve(0 , n-1);

    cout << ans ;
}
