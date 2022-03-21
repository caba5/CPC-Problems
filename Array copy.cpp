#include <iostream>
#include <vector>

using namespace std;

class segment_tree{
    public:
        vector<int> t;
        vector<int> al;
        vector<int> ar;
        vector<int> a;

        segment_tree(size_t n, vector<int> arr){
            t.reserve(n << 2);
            al.reserve(n << 2);
            ar.reserve(n << 2);
            a = arr;
        }

        void push(int i, int l){
            if (al[i] != ar[i]){
                al[i*2] = al[i];
                ar[i*2] = al[i] + l - 1;
                al[i*2+1] = al[i] + l;
                al[i*2+1] = ar[i];
                al[i] = ar[i] = -1;
            }
        }

        void build(vector<int> arr, int i, int tl, int tr){
            al[i] = ar[i] = -1;
            if (tl == tr){
                t[i] = arr[tl];
                return;
            }
            int tm = (tl + tr) / 2;
            build(arr, i*2, tl, tm);
            build(arr, i*2+1, tm+1, tr);
        }

        void update(int i, int tl, int tr, int l1, int r1, int l2, int r2){
            if (l2 == tl && r2 == tr){
                al[i] = l1;
                ar[i] = r1;
                return;
            }
            int mid = (tl + tr) / 2;
            push(i, mid-tl+1);
            if (r2 <= mid)
                update(i*2, tl, mid, l1, r1, l2, r2);
            else if (l2 > mid)
                update(i*2+1, mid+1, tr, l1, r1, l2, r2);
            else{
                update(i*2, tl, mid, l1, l1+(mid-l2), l2, mid);
                update(i*2+1, mid+1, tr, l1+(mid-l2)+1, r1, mid+1, r2);
            }
        }

        int query(int i, int tl, int tr, int pos){
            if (tl == tr){
                if (al[i] != -1)
                    return a[al[i]];
                else
                    return t[i];
            }
            int mid = (tl + tr) / 2;
            push(i, mid-tl+1);
            if (pos <= mid)
                return query(i*2, tl, mid, pos);
            else
                return query(i*2+1, mid+1, tr, pos);
        }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n >> m;
    vector<int> A;
    vector<int> B;
    A.reserve(n);
    B.reserve(n);

    for (int i = 0; i < n; ++i){
        int el; cin >> el;
        A.push_back(el);
    }

    for (int i = 0; i < n; ++i){
        int el; cin >> el;
        B.push_back(el);
    }

    segment_tree st(n, A);
    st.build(B, 1, 0, n-1);

    for (int i = 0; i < m; ++i){
        int q; cin >> q;
        if (q == 1){
            int x, y, k;
            cin >> x >> y >> k;
            x--; y--;
            st.update(1, 0, n-1, x, x+k-1, y, y+k-1);
        }
        else if (q == 2){
            int i;
            cin >> i;
            i--;
            cout << st.query(1, 0, n-1, i) << endl;
        }
    }

    return 0;
}