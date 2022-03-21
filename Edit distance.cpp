#include <iostream>
#include <vector>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::string s, t;
    std::cin >> s >> t;

    std::vector<std::vector<int>> d(s.size()+1, std::vector<int>(t.size()+1));
    for (int i = 0; i < s.size() + 1; ++i){
        for (int j = 0; j < t.size() + 1; ++j){
            if (i == 0)
                d[i][j] = j;
            else if (j == 0)
                d[i][j] == i;
            else if (s[i-1] == t[j-1])
                d[i][j] = d[i-1][j-1];
            else
                d[i][j] = 1 + std::min(std::min(d[i-1][j], d[i][j-1]), d[i-1][j-1]);
        }
    }

    std::cout << d[s.size()][t.size()] << std::endl;

    return 0;
}