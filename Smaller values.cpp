/*
    EXAM 14/01/2019
    (n + m) logn
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "fenwick_tree.hpp"

using namespace std;

struct elem{
    int val, i;

    elem(int val, int i)
        : val(val), i(i)
        {}
};

struct query{
    int l, r, x, i;

    query(int l, int r, int x, int i)
        : l(l), r(r), x(x), i(i)
        {}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    int m; cin >> m;

    vector<elem> arr;
    arr.reserve(n);
    for (int i = 0; i < n; ++i){
        int val; cin >> val;
        arr.emplace_back(val, i);
    }
    
    vector<query> Q;
    Q.reserve(m);
    for (int i = 0; i < m; ++i){
        int l, r, x;
        cin >> l >> r >> x;
        Q.emplace_back(l,r,x,i);
    }

    sort(arr.begin(), arr.end(), [](const elem &x, const elem &y){
        return x.val < y.val;
    });

    sort(Q.begin(), Q.end(), [](const query &q1, const query &q2){
        return q1.x < q2.x;
    });

    fenwick_tree<int> F(n+1);
    int curr = 0;
    vector<int> answers(m);
    for (int i = 0; i < m; ++i){
        while (arr[curr].val <= Q[i].x && curr < n)
            F.add(arr[curr++].i, 1);
        answers[Q[i].i] = F.sum(Q[i].r) - F.sum(Q[i].l-1);
    }

    for (auto ans : answers)
        cout << ans << endl;

    return 0;
}