#include<bits/stdc++.h>

using namespace std;

const int N = 5e5+5 ;

int n , a[N] , b[N] , c[N] , ans ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;
    for(int i=1;i<=n;i++){
        cin >> a[i] ;
    }
    for(int i=1;i<=n;i++){
        cin >> b[i] ;
    }

    sort(a+1 , a+n+1) , sort(b+1 , b+n+1) ;
    reverse(b+1 , b+n+1);

    for(int i=1;i<=n;i++){
        c[i] = a[i] + b[i] ;
    }
    sort(c+1 , c+n+1);
    for(int i=1;i<n;i++){
        ans += abs(c[i] - c[i+1]) ;
    }

    cout << ans ;
}

//keypoint : เอาตัวมากมาเจอตัวน้อยเอาตัวน้อยมาเจอตัวมาก บวกกัน ก็จะได้ทุกค่า พอๆกัน


