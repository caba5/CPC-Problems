#include <iostream>
#include <vector>
#include "fenwick_tree.hpp"

using namespace std;

/*
    General rule is to first add all elems to FT when operating right and then -1 at each cycle.
    Instead, when working left, elements have to be added at each cycle.
    When computing greater elems take the sum of the whole array sum(n-1) and subtract from it
    the element.
*/

int main(){
    int n = 5;
    vector<int> arr = {0, 4, 2, 3, 1};
    fenwick_tree<int> F(n);

    /* Number of greater elements on right */
    for (int i = 0; i < n; ++i)
        F.add(arr[i], 1);

    for (int i = 0; i < n; ++i){
        cout << (F.sum(n-1) - F.sum(arr[i])) << " ";
        F.add(arr[i], -1);
    }
    F.init();
    cout << endl;
    
    /* Number of lower elements on right */
    for (int i = 0; i < n; ++i)
        F.add(arr[i], 1);

    for (int i = 0; i < n; ++i){
        F.add(arr[i], -1);
        cout << (F.sum(arr[i]) - F.sum(0)) << " ";
    }
    F.init();
    cout << endl;

    /* Number of lower elements on left */
    for (int i = 0; i < n; ++i){
        cout << F.sum(arr[i]) << " ";
        F.add(arr[i], 1);
    }
    F.init();
    cout << endl;

    /* Number of greater elements on left */    
    for (int i = 0; i < n; ++i){
        cout << (F.sum(n-1) - F.sum(arr[i])) << " ";
        F.add(arr[i], 1);
    }   
    F.init();
    cout << endl;

    return 0;
}