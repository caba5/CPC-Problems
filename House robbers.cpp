#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    if (n == 1){
        cout << arr[0] << endl;
        return 0;
    }

    int a = arr[0];
    int b = max(arr[0], arr[1]);
    for (int i = 2; i < n; ++i){
        int supp = b;
        b = max(a+arr[i], b);
        a = supp;
    }

    cout << b << endl;

    return 0;
}