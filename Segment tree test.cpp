#include <iostream>
#include <vector>
#include "segment_tree.hpp"

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> arr = {1, 3, -2, 8, -7};
    segment_tree<int> st(arr.size());

    cout << "Building the segment tree" << endl;
    st.build(arr, 1, 0, arr.size()-1);

    cout << "The sum [0..4]: " << st.sum(1, 0, arr.size()-1, 0, arr.size()-1) << endl;
    cout << "The sum [0..2]: " << st.sum(1, 0, arr.size()-1, 0, 2) << endl;
    cout << "The sum [1..2]: " << st.sum(1, 0, arr.size()-1, 1, 2) << endl;

    cout << "Updating arr[2] to 0" << endl;
    st.update(1, 0, arr.size()-1, 2, 0);

    cout << "The sum [0..4]: " << st.sum(1, 0, arr.size()-1, 0, arr.size()-1) << endl;
    cout << "The sum [0..2]: " << st.sum(1, 0, arr.size()-1, 0, 2) << endl;
    cout << "The sum [1..2]: " << st.sum(1, 0, arr.size()-1, 1, 2) << endl;

    return 0;
}