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


//1. 쳲���������̵��������



//2. ����ƥ��  -->  100%
    //�ж��Ƿ�Ϊ��Ч�ַ�
bool isEfcChar(const char& ch) {
    if (ch == '(' || ch == ')')
        return true;
    return false;
}

bool chkParenthesis(string A, int n) {
    // write code here
    //�п�
    if (n == 0)
        return true;
    //����Ϊ�����ı���һ��û�ж�Ӧ
    if (n % 2 == 1)
        return false;

    stack<char> st;
    //����
    for (const auto& ch : A) {
        if (isEfcChar(ch)) {
            //��Ч�ַ�, ����'('��ջ, ����')'��ȡջ��Ԫ�ز���ջ, ֱ�����
            if (ch == '(')
                st.push(ch);
            else {
                // ch��')', ���ջ��Ԫ����'('�Ļ���ջ, ���ǵĻ�����false
                if (!st.empty() && st.top() == '(')
                    st.pop();
                else
                    return false;
            }
        }
        else {
            //������Ч�ַ�
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