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

std::vector<int> reversed_add(const std::vector<int>& v) {
    std::vector<int> iv = v;
    
    bool retenue = true;

    for(int& i:iv) {
        if(i < 9 && !retenue) {
            return iv;
        } else if(i < 9 && retenue) {
            i++;
            retenue = false;
        } else if(i == 9 && retenue) {
            i = 0;
            retenue = false;
        } else if(i == 9 && !retenue) {
            i = 0;
            retenue = true;
        }
    }
    return iv;
}

int main() {
    //std::vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    //std::vector<int> v = {9,8,7,6,5,4,3,2,1,0};
    std::vector<int> v = {9,9,1,3};
    std::vector<int> v2 = reversed_add(v);

    for(int i:v2) {
        std::cout << i;
    }; std::cout << std::endl;

    return 0;
}