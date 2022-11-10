#include <vector>
#include <string>
#include <iostream>

std::string reverse(const std::vector<int>& v) {
    std::string reversed="";
    for(int i:v) {
        reversed.insert(0, 1, '0'+i);
    }
    return reversed;
}

int main() {
    std::vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    std::string inv = reverse(v);
    std::cout << inv << std::endl;
    return 0;
}