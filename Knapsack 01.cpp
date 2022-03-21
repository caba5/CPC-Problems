#include <iostream>
#include <vector>

struct item{
    int weight, value;

    item(int w, int v)
        : weight(w), value(v) {}
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int capacity; std::cin >> capacity;
    int n; std::cin >> n;
    std::vector<item> arr;
    arr.reserve(n);
    for (int i = 0; i < n; ++i){
        int weight, value;
        std::cin >> weight >> value;
        arr.emplace_back(weight, value);
    }

    std::vector<std::vector<int>> d(n+1, std::vector<int>(capacity+1));

    for (int i = 0; i < n + 1; ++i)
        for (int j = 0; j < capacity + 1; ++j){
            if (i == 0 or j == 0)
                d[i][j] = 0;
            else if (j - arr[i].weight >= 0)
                d[i][j] = std::max(d[i-1][j], d[i-1][j - arr[i].weight] + arr[i-1].value);
            else
                d[i][j] = d[i-1][j];
        }

    for (auto row : d){
        for (auto x : row)
            std::cout << x << " ";
        std::cout << std::endl;
    }

    std::cout << "Max obtainable value is " << d[n][capacity] << std::endl;

    return 0;
}