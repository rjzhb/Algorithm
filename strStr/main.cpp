#include <iostream>
#include <string>

using namespace std;

int strStr(string &source, string &target) {
    // Write your code here
    int start = 0;
    for (start = 0; start < source.size(); start++) {
        if (source[start] == target[0])break;
    }

    if(start == source.size()){
        return -1;
    }


}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
