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

void display_vector(const std::vector<int> & v) {
    for(int i : v)
        std::cout << i << std::endl;
}

int main(int argc, char* argv[]) {
    std::vector<int> v = ask_list();
    display_vector(v);

    return 0;
}