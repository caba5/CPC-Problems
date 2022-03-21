#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, q; std::cin >> n >> q;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];
    
    std::vector<int> F(n+1);    //Prefix array
    
    int l, r;
    while(q--){
        std::cin >> l >> r;
        F[l-1] += 1;
        F[r] -= 1;
    }

    for (int i = 1; i < n; ++i)
        F[i] += F[i-1];

    sort(arr.begin(), arr.end());
    sort(F.begin(), F.end()-1);

    int result = 0;
    for (int i = 0; i < n; ++i)
        result += arr[i] * F[i];

    std::cout << result << std::endl;

    return 0;
}