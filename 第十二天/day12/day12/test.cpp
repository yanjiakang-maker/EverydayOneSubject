#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<cmath>

using namespace std;


void func(const int& v1, const int& v2) {
	cout << v1 << " " << v2 << endl;
}

void test() {
	int n[][3] = { 10, 20, 30, 40, 50, 60 };
	int(*p)[3];
	p = n;
	cout << p[0][0] << " " << *(p[0] + 1) << " " << (*p)[2] << endl;
	cout << *(p + 1) << endl;


	int i = 0;
	func(++i, i++);
}


// 1. 二进制插入
void binInsert(int n, int m, int j, int i) {
    stack<int> mst; //存放m的二进制数
    stack<int> nst; //存放n的二进制数
    //stack<int> mst2; //存放逆置的m的二进制数
    stack<int> tmp; //临时存放前面的二进制位

    //n转换为2进制, 存入n栈
    while (n > 0) {
        tmp.push(n % 2);
        n /= 2;
    }
    while (!tmp.empty()) {
        int top = tmp.top();
        nst.push(top);
        tmp.pop();
    }

    //m转换为2进制, 按逆置存入m栈
    while (m > 0) {
        mst.push(m % 2);
        m /= 2;
    }


    // n栈j位置前的二进制位出栈, 保存到tmp栈, 一会儿再取回来
    int a = 0;
    while (a < j) {
        int top = nst.top();
        tmp.push(top);
        nst.pop();
        a++;
    }

    //把n从j到i位的数据删除, 
    while (a <= i) {
        nst.pop();
        a++;
    }

    //当m的二进位小于 i-j+1时, 先给n补0
    for (int b = 0; b < i - j + 1 - mst.size(); b++) {
        nst.push(0);
    }

    //把m插入
    while (!mst.empty()) {
        int top = mst.top();
        nst.push(top);
        mst.pop();
    }

    //把tmp栈中保存的数据取回来
    while (!tmp.empty()) {
        int top = tmp.top();
        nst.push(top);
        tmp.pop();
    }


    //把插入后的数据转换回十进制
    int ret = 0;  //保存结果
    int step = 1; //第n位的乘数
    while (!nst.empty()) {
        int top = nst.top();
        nst.pop();
        ret += top * step;
        step *= 2;
    }

    cout << ret << endl;
}


// 2. 查找组成一个偶数最接近的两个素数
//判断是否是素数
bool isPrimeNum(int num) {
    for (int i = 2; i < sqrt(num) + 1; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

void findNum() {
    int num;
    cin >> num;

    //从这个偶数的一半+1开始寻找, 第一组解势必是最小的
    int right = num / 2 + 1;
    int left = 0;
    while (right < num) {
        if (isPrimeNum(right)) {
            left = num - right;
            if (isPrimeNum(left)) {
                break;
            }
        }
        right++;
    }
    cout << left << endl << right << endl;
}


int main() {
	//test();
    //binInsert(1024, 19, 2, 6);
    findNum();

	return 0;
}