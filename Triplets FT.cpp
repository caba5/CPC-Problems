#include <iostream>
#include <vector>
#include "fenwick_tree.hpp"

using namespace std;

template <typename T>
class fenwick
{
  int N;
  std::vector<T> ft;

  public:

    fenwick(int size) : N(size){ 
        ft = std::vector<T>(N+1, 0); 
    }

    void update(int k, T v){ 
        for (; k <= N; k += (k&(-k))) 
            ft[k] += v; 
    }

    T query(int b, T sum = 0){
        for (; b; b -= b & -b) 
            sum += ft[b];
        return sum;
    }

};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    fenwick<int> L(n);
    fenwick<int> R(n);
    int ans = 0;

    for (int i = 0; i < n; ++i)
        R.update(arr[i], 1);
    
    for (int i = 0; i < n; ++i){
        int left = L.query(arr[i]-1);
        int right = R.query(n) - R.query(arr[i]);
        ans += left * right;
        L.update(arr[i], 1);
        R.update(arr[i], -1);
    }

    cout << ans << endl;

    return 0;
}