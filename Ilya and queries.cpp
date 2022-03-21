#include <iostream>
#include <vector>
#include <string>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::string s;
    std::cin >> s;

    int n = s.length();
    std::vector<int> sums(n + 1);
    sums[0] = 0;
    for (int i = 1; i < n; ++i){
        sums[i] = s[i] == s[i-1] ? sums[i-1] + 1 : sums[i-1];
    }
    sums[n] = sums[n-1];

    int q;
    std::cin >> q;
    for (int i = 0; i < q; ++i){
        int l, r;
        std::cin >> l >> r;
        std::cout << sums[r-1] - sums[l-1] << std::endl;
    }
    return 0;
}