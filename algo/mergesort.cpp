#include<bits/stdc++.h>

using namespace std;

const int N = 5e5+5 ;

int n , arr[N] , inv_cnt = 0  ;

void mergesort(int l , int r){
    if(l >= r){
        return ;
    }
    int mid = (l+r)/2 ;
    mergesort(l , mid) ; mergesort(mid+1 , r) ;

    int n1 = mid-l+1 , n2 = r-mid ;
    int L[n1] , R[n2] ;
    for(int i=0;i<n1;i++){
        L[i] = arr[l+i] ;
    }
    for(int i=0;i<n2;i++){
        R[i] = arr[mid + i + 1] ;
    }

    int i=0,j=0 , k=l ;
    while(i < n1 && j < n2){
        if(L[i] < R[j]){
            arr[k] = L[i] ;
            i++;
        }
        else {
            arr[k] = R[k] ;
            j++;

            inv_cnt += mid - (l+i) + 1 ;
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

}
