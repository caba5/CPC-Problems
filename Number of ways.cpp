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
	
	int S = 0;
	for (int x : arr)
		S += x;
	
	if (S % 3 != 0){
		std::cout << "0\n";
		return 0;
	}

	S /= 3;
	std::vector<int> c(n);
	int L = 0;
	for (int i = n-1; i >= 0; --i){
		L += arr[i];
		if (L == S)
			c[i] = 1;
	}

	for (int i = n-2; i >= 0; --i)
		c[i] += c[i+1];
	for (auto x : c)
		std::cout << x << " ";
	std::cout << std::endl;

	
	int result = 0;
	L = 0;
	for (int i = 0; i+2 < n; ++i){
		L += arr[i];
		if (L == S)
			result += c[i+2];
	}

	std::cout << result << std::endl;

	return 0;
}