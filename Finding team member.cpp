#include <iostream>
#include <vector>
#include <algorithm>

struct team{
    int member1;
    int member2;
    int strength;

    team(int m1, int m2, int s) 
        : member1(m1)
        , member2(m2)
        , strength(s) {}
};

int main(){
    int n; std::cin >> n;
    std::vector<team> teams;

    for (int i = 1; i < 2*n; ++i){
        for (int j = 0; j < i; ++j){
            int strength; std::cin >> strength;
            teams.emplace_back(i, j, strength);
        }
    }

    sort(teams.begin(),
        teams.end(), 
        [](team t1, team t2){
            return t1.strength > t2.strength;
        }
    );

    std::vector<int> assign(2*n);
    for (team &t : teams){
        if (assign[t.member1] == 0 && assign[t.member2] == 0){
            assign[t.member1] = t.member2 + 1;
            assign[t.member2] = t.member1 + 1;
        }
    }

    for (auto assigned : assign)
        std::cout << assigned << " ";
    std::cout << std::endl;

    return 0;
}