#include <iostream>
#include <vector>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::string a;
    std::string b;
    std::cin >> a;
    std::cin >> b;

    std::vector<std::vector<int>> d(a.size()+1, std::vector<int>(b.size()+1));

    for (int i = 1; i < a.size()+1; ++i){
        for (int j = 1; j < b.size()+1; ++j){
            if (a[i-1] == b[j-1])
                d[i][j] = d[i-1][j-1] + 1;
            else
                d[i][j] = std::max(d[i-1][j], d[i][j-1]);
        }
    }
    std::cout << "The length of the LCS is " << d[a.size()][b.size()] << std::endl;

    return 0;
}