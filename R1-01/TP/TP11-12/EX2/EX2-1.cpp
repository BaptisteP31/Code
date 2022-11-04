#include <iostream>
#include <map>
#include <algorithm>


void voyelle(std::string& st) {
    std::map<char, char> voy {{'a', '1'}, {'e', '2'}, {'i', '3'}, {'o', '4'}, {'u', '5'}, {'y', '6'}};

    for(char c : st) {
        std::map<char, char>::iterator got = voy.find(c);
        if(got != voy.end()) {
            char value = got->second;
            std::replace(st.begin(), st.end(), c, value);
        }
    }
}

int main(int argc, char* argv[]) {
    std::string mot = "vichyssoise";
    voyelle(mot);
    std::cout << mot << std::endl;

    return 0;
}