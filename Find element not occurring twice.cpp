#include <iostream>
#include <vector>

void solve(std::vector<int> const& arr){
    int accum = 0;
    for (int x : arr)
        accum ^= x;
    
    std::cout << "The number missing a second time is: " << accum << std::endl;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n; std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];

    solve(arr);
    return 0;
}