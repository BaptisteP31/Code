#include <iostream>
#include <vector>
#include <set>

void disp_vector(const std::vector<int> & v) {
    std::set<int> s(v.begin(), v.end());
    for(int i : s)
        std::cout << i << std::endl;
}