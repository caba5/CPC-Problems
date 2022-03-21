#include <iostream>
#include <vector>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n; std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];
    
    int s = 0;
    for (int x : arr)
        s += x;
    
    if (s & 1){
        std::cout << "Impossible" << std::endl;
        return 0;
    }

    s /= 2;
    std::vector<std::vector<bool>> d(n+1, std::vector<bool>(s+1));
    d[0][0] = true;
    for (int i = 1; i < n + 1; ++i)
        d[0][i] = false;

    for (int i = 1; i < n + 1; ++i)
        for (int j = 0; j < s + 1; ++j)
            d[i][j] = d[i-1][j] || d[i-1][j - arr[i]];            
    
    std::cout << (d[n][s] == true ? "True" : "False") << std::endl;

    return 0;
}