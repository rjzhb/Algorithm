#include <iostream>
#include <string>
#include <cstring>

using namespace std;
//lintcode 13题
int strStr(string &source, string &target) {
    if (target.size() == 0) {
        return 0;
    }

    //find the first letter of target
    int start = 0;
    for (start = 0; start < source.size(); start++) {
        if (source[start] == target[0])break;
    }

    if (start == source.size()) {
        return -1;
    }

    //calculate sum_diff from source and target by using left and right pointers.
    int left = start;
    int right = 0;

    int sum_diff = 0;
    bool equal_flag = true;
    while (left < source.size() && right < target.size()) {
        sum_diff += source[left];
        sum_diff -= target[right];
        equal_flag &= source[left++] == target[right++];
    }

    //judge if corresponding to our need.
    if (right < target.size()) {
        return -1;
    } else if (equal_flag) {
        return start;
    }

    //if it doesn't meet our need, we should use a window to find the first position.
    //再来双指针，相当于一个窗口
    int sub_start = 0;
    for (sub_start = start; left < source.size(); left++) {
        sum_diff -= source[sub_start++];
        sum_diff += source[left];

        //滑动窗口判断
        if (
                sum_diff == 0
                && source[sub_start] == target[0]
                && memcmp(source.c_str() + sub_start, target.c_str(), target.size()) == 0
                ) {
            return sub_start;
        }
    }

    return -1;
}

int main() {
    string source = "tartarget";
    string target = "target";

    string source_1 = "";
    string target_1 = "";
    std::cout << strStr(source, target) << std::endl;
    return 0;
}
