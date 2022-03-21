#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n; std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];

    std::vector<int> LIS(n,0);
    std::vector<int> tail1(n,0);    // Keeps track of how many elements < to its left
    LIS[0] = arr[0];
    int length = 1;
    for (int i = 0; i < n; ++i){
        auto b = LIS.begin();
        auto e = b + length;
        auto it = std::lower_bound(b, e, arr[i]);
        if (it == e)
            LIS[length++] = arr[i],
            tail1[i] = length - 1;
        else
            *it = arr[i],
            tail1[i] = it - b;
    }

    std::reverse(arr.begin(), arr.end());

    std::vector<int> LDS(n,0);
    std::vector<int> tail2(n,0);    // Keeps track of how many elements < to its right
    LDS[0] = arr[0];
    length = 1;
    for (int i = 0; i < n; ++i){
        auto b = LDS.begin();
        auto e = b + length;
        auto it = std::lower_bound(b, e, arr[i]);
        if (it == e)
            LDS[length++] = arr[i],
            tail2[i] = length - 1;
        else
            *it = arr[i],
            tail2[i] = it - b;
    }

    std::reverse(tail2.begin(), tail2.end());

    int ans = 0;
    for (int i = 0; i < n; ++i){
        if (ans < tail1[i] + tail2[i] + 1)
            ans = tail1[i] + tail2[i] + 1;
    }

    for (auto x : tail1)
        std::cout << x << " ";
    std::cout << std::endl;

    for (auto x : tail2)
        std::cout << x << " ";
    std::cout << std::endl;

    std::cout << ans << std::endl;

    return 0;
}