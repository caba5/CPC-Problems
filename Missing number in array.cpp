#include <iostream>
#include <vector>

void miss(std::vector<int> const& v){
    int sum = 0;
    int expected_sum = v.size() * (v.size() + 1) / 2;
    for (int x : v)
        sum += x;
    std::cout << "The missing number is: " << expected_sum - sum << std::endl;
}

int main(){
    int n; std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n - 1; ++i)
        std::cin >> arr[i];

    miss(arr);
    return 0;
}