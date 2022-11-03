#include <iostream>
#include <vector>

std::vector<int> veclist() {
    std::vector<int> list;
    std::string s;

    while(std::getline(std::cin, s))
        if(!s.empty())
            list.push_back(stoi(s));
        else
            break;

    return list;
}

int main(int argc, char *arcv[]) {
    veclist();

    return 0;
}