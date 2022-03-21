#include <iostream>
#include <vector>

void kad(std::vector<int> const& v){
    int sum = v[0];
    int max = sum;
    for (int i = 1; i < v.size(); ++i){
        if (sum > 0)
            sum += v[i];
        else
            sum = v[i];

        if (sum > max)
            max = sum;
    }

    std::cout << "The max contiguous sum is " << max << std::endl;
}

int main(){
    int n; std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];
    kad(arr);
    return 0;
}