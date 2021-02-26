#include<iostream>
#include<string>

using namespace std;

void sameStr() {
    string s1, s2;
    string ret = "";
    cin >> s1;
    cin >> s2;
    string::iterator it = s1.size() < s2.size() ? s1.begin() : s2.begin();
    int begin = 0;
    int end = 0;
    //有一个字符遍历完即结束
    while (begin < s1.size() && begin < s2.size()) {
        if (s1[begin] == s2[begin]) {
            //如果有相等了
            end = begin + 1;
            //向后遍历, 找出子串
            while (s1[end] == s2[end]) {
                end++;
            }
            //如果这次找到的子串比之前的长, 则赋值给ret
            if (end - begin > ret.size()) {
                ret.append(it + begin, it + end);
            }
        }
        else {
            //不相等, 向后遍历
            begin++;
        }
    }

    cout << ret << endl;
}


int main() {

	sameStr();

	return 0;
}