// Inversion count

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

long long inv_cnt;
int A[MAX_N];

void mergesort(int l, int r) {
    if(l >= r) {
        return;
    }

    int mid = (l + r) / 2;

    mergesort(l, mid);
    mergesort(mid + 1, r);

    int n1 = mid - l + 1, n2 = r - mid;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++) {
        L[i] = A[l + i];
    }
    for(int i = 0; i < n2; i++) {
        R[i] = A[mid + i + 1];
    }

    int i = 0, j = 0, k = l;
    while(i < n1 and j < n2) {
        if(L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            inv_cnt += mid - (l + i) + 1; // counting inversion
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }
    while(j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;
    
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    mergesort(1, N);

    cout << "Inversion count : " << inv_cnt << '\n';
    for(int i = 1; i <= N; i++) {
        cout << A[i] << ' ';
    }
    return 0;
}