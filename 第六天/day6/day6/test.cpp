#include<iostream>

using namespace std;


char fun(char x, char y) {
	if (x < y)
		return x;
	return y;
}


void test() {
	int a = '1', b = '1', c = '2';
	cout << fun(fun(a, b), fun(b, c)) << endl;

	int m = 0123, n = 123;
	printf("%o, %o\n", m, n);

	printf("%o\n", 100);

    cout << "unsigned: " << sizeof(unsigned) << endl;
}



// 1. 不要二 
void buyaoer() {
    int w, h;
    cin >> w >> h;

    int ret = 0;
    int table[1000][1000] = { 0 };

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {

            if (table[i][j] == 0) {
                ret++;

                if ((i + 2) < w) 
                    table[i + 2][j] = -1;
                if ((j + 2) < h) 
                    table[i][j + 2] = -1;
            }
        }
    }
    cout << ret << endl;
}



// 2. 把字符串转换成整数
class Solution {
public:
    //判断是不是有效字符
    bool isDigit(const char& ch) {
        if (ch >= '0' && ch <= '9')
            return true;
        return false;
    }

    int StrToInt(string str) {
        //判空
        if (str.empty())
            return 0;

        int i = 0;     //遍历的索引
        int flag = 1; //正负号标记
        int ret = 0;  //保存结果

        //处理第一个位置是符号的情况
        if (str[i] == '+') {
            i++;
        }
        else if (str[i] == '-') {
            //改变标记
            flag = -1;
            i++;
        }

        //开始遍历
        while (i < str.size()) {
            //如果这个位置是数字, 进行运算
            if (isDigit(str[i])) {
                ret = ret * 10 + (str[i] - '0');
                i++;
            }
            else {
                //不是有效数字, 返回0
                return 0;
            }
        }

        return ret * flag;
    }
};



int main() {
	test();

	return 0;
}