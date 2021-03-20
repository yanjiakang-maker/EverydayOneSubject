// write your code here cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


string addStrings(string num1, string num2) {
    //两个索引
    int len1 = num1.size() - 1;
    int len2 = num2.size() - 1;

    int step = 0; //进位信息
    int curnum = 0; //当前位的数值
    string ret; //保存结果

    //优化: 用reverse提前开好空间, 避免之后位数不够重新开空间和拷贝
    int len = len1 > len2 ? len1 + 1 : len2 + 1;
    ret.reserve(len);

    //遍历所有位, 从个位开始相加, 依次向高位
    while (len1 >= 0 || len2 >= 0) {
        //先加上上一位的进位
        curnum = step;
        if (len1 >= 0) {
            //num1还没遍历完
            curnum += num1[len1] - '0';
            --len1;
        }
        if (len2 >= 0) {
            //num2还没遍历完
            curnum += num2[len2] - '0';
            --len2;
        }
        //判断是否有进位
        if (curnum >= 10) {
            curnum -= 10;
            step = 1;
        }
        else {
            //没有进位
            step = 0;
        }
        //先逆置保存
        ret.push_back(curnum + '0');
    }

    //循环结束后, 判断最高位是否有进位
    if (step == 1) {
        //有进位, 给最高位进位
        ret.push_back(step + '0');
    }

    //逆置, 得到正确顺序的结果
    reverse(ret.begin(), ret.end());

    return ret;
}

//2. 斐波那契变形
void program2() {
    vector<string> v;
    v.resize(81);
    v[0] = "0";
    v[1] = "1";
    v[2] = "1";

    for (int i = 3; i <= 80; i++) {
        v[i] = addStrings(v[i - 1], v[i - 2]);
    }

    int start, end;
    while (cin >> start >> end) {
        string ret = "";
        for (int i = start; i <= end; i++) {
            ret = addStrings(ret, v[i]);
        }
        cout << ret << endl;
    }
}



void program1() {
    string str, sub;
    while (cin >> str >> sub) {
        size_t pos = 0;
        int flag = 0; //表示是否是第一次查找
        int ret = 0;
        while (pos < str.size()) {
            for (auto ch : sub) {
                /*
                if (flag == 0) {
                    //这是第一次查找
                    pos = str.find(ch);
                    flag = 1;
                }
                else
                    pos = str.find(ch, pos + 1);

                if (pos == string::npos) {
                    //没找到
                    break;
                }
                */
                pos = str.find(ch);

                if (pos == string::npos) {
                    //没找到
                    break;
                }
                else {
                    //找到了, 剪下来
                    str.erase(pos, 1);
                }
            }

            //没找到就退出吧
            if (pos == string::npos)
                break;
            else
                ret++;
        }
        cout << ret << endl;
    }
}


int main() {
    program1();
    //program2();

    return 0;
}