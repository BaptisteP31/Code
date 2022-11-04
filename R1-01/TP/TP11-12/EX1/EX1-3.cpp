#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> ask_list() {
    std::vector<int> list;
    std::string line;

    while(getline(std::cin, line)) {
        if(!line.empty())
            list.push_back(std::stoi(line));
        else
            break;
    }

    return list;
}

void display_vector(const std::vector<int> & v) {
    for(int i : v)
        std::cout << i << std::endl;
}

void display_sorted_vector(const std::vector<int> & v) {
    std::vector<int> tempv = v;
    std::sort(tempv.begin(), tempv.end());
    
    for(int i : tempv) {
        std::cout << i << std::endl;
    }
}

int main(int argc, char* argv[]) {
    std::vector<int> list = ask_list();
    display_sorted_vector(list);

    return 0;
}