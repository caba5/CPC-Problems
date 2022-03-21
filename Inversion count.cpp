#include <iostream>
#include <vector>
#include <algorithm>

int merge_and_count(std::vector<int> &v, int l, int q, int r){
    int i = l;
    int j = q + 1;
    std::vector<int> B(r-l+1);
    int k = 0;
    int n_inversions = 0;

    while ((i <= q) and (j <= r)){
        if (v[i] < v[j])
            B[k++] = v[i++];
        else
            B[k++] = v[j++],
            n_inversions += q - i + 1;
    }

    while (i <= q)
        B[k++] = v[i++];
    
    while (j <= r)
        B[k++] = v[j++];

    copy(B.begin(), B.end(), v.begin()+l);

    return n_inversions;
}

int sort_and_count(std::vector<int> &v, int l, int r){
    if (l < r){
        int q = (l + r) / 2;
        return sort_and_count(v, l, q) + sort_and_count(v, q + 1, r) + merge_and_count(v, l, q, r);
    }
    return 0;
}

int main(){

    int n; std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];

    
    std::cout << "The number of inversions is: " 
    << sort_and_count(arr, 0, arr.size()-1) << std::endl;
    return 0;
}