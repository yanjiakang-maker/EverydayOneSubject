#include<iostream>

using namespace std;


//1. ���üӼ��˳����ӷ�
int Add(int num1, int num2)
{
    while (num2 != 0) {
        int tmp = num1 ^ num2;
        num2 = (num1 & num2) << 1;
        num1 = tmp;
    }
    return num1;
}


//2. ��������ֵ, �ж��ܷ񹹳�һ��������
void program2() {
    //double�ķ�Χ��10^-308��10^308
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