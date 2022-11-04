#include <iostream>
#include <vector>

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

int main(int argc, char* argv[]) {
    std::vector<int> list= ask_list();

    for(int i : list) {
        std::cout << i << std::endl;
    }

    return 0;
}