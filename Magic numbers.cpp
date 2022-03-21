#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int number; std::cin >> number;
    bool cont = true;
    while (number >= 1 && cont){
        int n = number % 10;
        number = number / 10;
        if (n == 1)
            continue;
        if (n == 4){
            n = number % 10;
            number /= 10;
            if (n == 1)
                continue;
            if (n == 4){
                n = number % 10;
                number /= 10;
                if (n == 1)
                    continue;
                cont = false;
            }
            cont = false;
        }
        cont = false;
    }

    std::cout << (cont ? "YES" : "NO") << std::endl;


    return 0;
}