/*
    EXAM 14/02/2018
    n logn
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    multiset<int> S;
    vector<int> R(n);
    vector<int> L(n);

    for (int i = n - 1; i >= 0; --i){
        S.insert(arr[i]);
        auto it = S.upper_bound(arr[i]);
        R[i] = distance(it, S.end());
    }

    S.clear();

    for (int i = 0; i < n; ++i){
        S.insert(arr[i]);
        auto it = S.lower_bound(arr[i]);
        L[i] = distance(S.begin(), it);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans += L[i] * R[i];

    cout << ans << endl;

    return 0;
}