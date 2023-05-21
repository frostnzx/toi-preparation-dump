#include<bits/stdc++.h>

using namespace std;

using pii = pair<int,int> ;

const int N = 1005 ;

int n , m , va[N] , vb[N] ;
pii dp[N][N] ; // {day , sum}

pii solve(int a , int b){
    if(a == 0 && b == 0){
        return dp[a][b] = {1 , 0} ;
    }
    else if(a == 0){
        pii t = solve(a , b-1) ;
        int nd , ns ;
        nd = t.first ;
        if((t.second + vb[b]) > m){
            nd++;
            ns = vb[b] ;
        }
        else ns = t.second + vb[b] ;
        return dp[a][b] = {nd , ns} ;
    }
    else if(b == 0){
        pii t = solve(a-1 , b) ;
        int nd , ns ;
        nd = t.first ;
        if((t.second + va[a]) > m){
            nd++;
            ns = va[a] ;
        }
        else ns = t.second + va[a] ;
        return dp[a][b] = {nd , ns} ;
    }
    if(dp[a][b].first != -1){
        return dp[a][b] ;
    }
    int d1 , s1 , d2 , s2 ;
    pii t1 = solve(a-1 , b) , t2 = solve(a , b-1) ;

    d1 = t1.first ;
    if(t1.second + va[a] > m){
        d1++;
        s1 = va[a] ;
    }
    else {
        s1 = t1.second + va[a] ;
    }

    d2 = t2.first ;
    if(t2.second + vb[b] > m){
        d2++;
        s2 = vb[b] ;
    }
    else {
        s2 = t2.second + vb[b] ;
    }
    return dp[a][b] = min(pii(d1 , s1) , pii(d2 ,s2)) ;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n ;
    for(int i=1;i<=n;i++){
        cin >> va[i] ;
    }
    for(int i=1;i<=n;i++){
        cin >> vb[i] ;
    }
    memset(dp , -1 , sizeof(dp));
    solve(n , n) ;

    cout << dp[n][n].first << "\n" << dp[n][n].second ;
}

//keypoint : ต้องเขียนให้เริ่้ม recursive จากตัวท้าย ไปตัวแรก เพราะโจทย์ต้องการบวกตั้งแต่ ตัวแรก ไป ตัวท้าย ดังนั้นถุ้าเรา recursive จากท้ายไปแรก ตัวแรกก็จะเป็นตัวที่ได้บวกก่อน
//warining : การเพิ่มค่าวัน ไม่สามารถนำงานที่เหลือไปทำวันถัดไปได้ ถ้าเวลาเกิน ก็ยกไปอีกวันทั้งดุ้นเลย



