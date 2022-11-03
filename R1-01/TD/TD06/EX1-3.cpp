#include <iostream>
#include <vector>
#include <algorithm>

void display_vector(const std::vector<int>& v) {
    std::vector<int> templist = v;
    std::sort(templist.begin(), templist.end());
    
    for(int i : v)
        std::cout << i << std::endl;
}

int main(int argc, char* argv[]) {

    return 0;
}