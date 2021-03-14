#include<iostream>

using namespace std;


//1. 不用加减乘除做加法
int Add(int num1, int num2)
{
    while (num2 != 0) {
        int tmp = num1 ^ num2;
        num2 = (num1 & num2) << 1;
        num1 = tmp;
    }
    return num1;
}


//2. 给定三个值, 判断能否构成一个三角形
void program2() {
    //double的范围是10^-308到10^308
    double a, b, c;
    while (cin >> a >> b >> c) {
        if (a + b > c && a + c > b && b + c > a
            && a - b < c && a - c < b && b - c < a) {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
}


int main() {



	return 0;
}