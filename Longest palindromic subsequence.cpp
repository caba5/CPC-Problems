#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::string s; std::cin >> s;

    std::vector<std::vector<int>> d(s.size()+1, std::vector<int>(s.size()+1));
    std::string str = s;
    std::reverse(str.begin(), str.end());

    int ans = 1;
    for (int i = 1; i <= s.size(); ++i){
        for (int j = 1; j <= s.size(); ++j){
            if (s[i-1] == str[j-1]){
                d[i][j] = d[i-1][j-1] + 1;
                ans = std::max(ans, d[i][j]);
            }
            else
                d[i][j] = std::max(d[i-1][j], d[i][j-1]);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}