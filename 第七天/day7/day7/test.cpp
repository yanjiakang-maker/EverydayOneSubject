#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;



template <class T> 
class BigNumber {
	long n;

public:
	BigNumber(T i)
		:n(i)
	{}
	BigNumber operator+ (BigNumber b) {
		return BigNumber(n + b.n);
	}
};

void test() {
	BigNumber<int> b1(10);
	BigNumber<int> b2(20);

	b1 + 3;
}


//1. 斐波那契数最短的运算次数



//2. 括号匹配  -->  100%
    //判断是否为有效字符
bool isEfcChar(const char& ch) {
    if (ch == '(' || ch == ')')
        return true;
    return false;
}

bool chkParenthesis(string A, int n) {
    // write code here
    //判空
    if (n == 0)
        return true;
    //长度为奇数的必有一个没有对应
    if (n % 2 == 1)
        return false;

    stack<char> st;
    //遍历
    for (const auto& ch : A) {
        if (isEfcChar(ch)) {
            //有效字符, 遇到'('入栈, 遇到')'获取栈顶元素并出栈, 直到最后
            if (ch == '(')
                st.push(ch);
            else {
                // ch是')', 如果栈顶元素是'('的话出栈, 不是的话返回false
                if (!st.empty() && st.top() == '(')
                    st.pop();
                else
                    return false;
            }
        }
        else {
            //不是有效字符
            return false;
        }
    }
    return true;

}


void test2() {
    string s = ")(";
    cout << chkParenthesis(s, s.size()) << endl;

}


int main() {
	//test();
    test2();

	return 0;
}