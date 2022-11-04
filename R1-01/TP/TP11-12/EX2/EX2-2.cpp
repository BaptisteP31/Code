#include <iostream>

void concatenate(std::string& s1) { s1 += s1; }

bool string_check(const std::string s) {
    size_t len = s.length();
    if(len % 2 != 0)
        return false;

    std::string tmpstr1 = s.substr(0, len/2);
    std::string tmpstr2 = s.substr(len/2, len);

    return (tmpstr1 == tmpstr2);
}

int main(int argc, char* argv[]) {
    std::cout << string_check("maisonmaison") << std::endl;

    return 0;
}