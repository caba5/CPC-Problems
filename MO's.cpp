/*
	O( (N+M) * sqrt N )
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

int answer = 0;

struct node{
	int L, R, i;

    node(int l, int r, int i) 
        : L(l), R(r), i(i) {}
};

void add(int position, std::vector<int> &a, std::unordered_map<int, int> &cnt) {
	cnt[a[position]]++;
	if(cnt[a[position]] == 1) {
		answer++;
	}
}

void remove(int position, std::vector<int> &a, std::unordered_map<int, int> &cnt) {
	cnt[a[position]]--;
	if(cnt[a[position]] == 0) {
		answer--;
	}
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

	int n; std::cin >> n;
    std::vector<int> arr(n);
	for(int i=0; i<n; ++i)
		std::cin >> arr[i];

    const int BLOCK = sqrt(n);
    std::unordered_map<int, int> cnt;

	int nq; std::cin >> nq;
    std::vector<node> Q;
    Q.reserve(nq);
	for(int i = 0; i < nq; ++i) {
		int l, r; std::cin >> l >> r;
        l--;    // match 0 based idx
        r--;    // match 0 based idx
        Q.emplace_back(l, r, i);
	}

	sort(Q.begin(), Q.end(), [=](const node &x, const node &y){
        if(x.L/BLOCK != y.L/BLOCK)
                return x.L/BLOCK < y.L/BLOCK;   // different blocks, so sort by block
        return x.R < y.R;   // same block, so sort by R value
    });

	int currentL = 0, currentR = 0;
    std::vector<int> ans(n);
	for(int i = 0; i < nq; ++i) {
		int L = Q[i].L, R = Q[i].R;
		while(currentL < L) {
			remove(currentL, arr, cnt);
			currentL++;
		}
		while(currentL > L) {
			add(currentL-1, arr, cnt);
			currentL--;
		}
		while(currentR <= R) {  // right bound included?
			add(currentR, arr, cnt);
			currentR++;
		}
		while(currentR > R+1) {
			remove(currentR-1, arr, cnt);
			currentR--;
		}
		ans[Q[i].i] = answer;
	}

	for(int i = 0; i < nq; ++i)
		std::cout << ans[i] << std::endl;

    return 0;
}