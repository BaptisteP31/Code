#include <iostream>
#include <vector>
#include <algorithm>

void disp_vector(std::vector<int> & v) {
    std::vector<int> s=v;
    std::sort(s.begin(), s.end());
    int last = s[0]+1;

    for(int i : v) {
        if(last != i) {
            std::cout << i << std::endl ;
            last = i;
        }
    }
}

int main() {

}