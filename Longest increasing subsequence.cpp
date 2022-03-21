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

    std::vector<int> supp(n, 0);
    int length = 1;
    supp[0] = arr[0];
    for (int i = 0; i < n; ++i){
        auto begin = supp.begin();
        auto end = begin + length;
        auto it = std::lower_bound(begin, end, arr[i]);

        if (it == end)
            supp[length++] = arr[i];
        else
            *it = arr[i];
    }

    for (int i = 0; i < length; ++i)
        std::cout << supp[i] << " ";
    std::cout << std::endl;
    std::cout << length << std::endl;

    return 0;
}