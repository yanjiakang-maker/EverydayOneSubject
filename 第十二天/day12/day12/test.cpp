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


// 1. �����Ʋ���
void binInsert(int n, int m, int j, int i) {
    stack<int> mst; //���m�Ķ�������
    stack<int> nst; //���n�Ķ�������
    //stack<int> mst2; //������õ�m�Ķ�������
    stack<int> tmp; //��ʱ���ǰ��Ķ�����λ

    //nת��Ϊ2����, ����nջ
    while (n > 0) {
        tmp.push(n % 2);
        n /= 2;
    }
    while (!tmp.empty()) {
        int top = tmp.top();
        nst.push(top);
        tmp.pop();
    }

    //mת��Ϊ2����, �����ô���mջ
    while (m > 0) {
        mst.push(m % 2);
        m /= 2;
    }


    // nջjλ��ǰ�Ķ�����λ��ջ, ���浽tmpջ, һ�����ȡ����
    int a = 0;
    while (a < j) {
        int top = nst.top();
        tmp.push(top);
        nst.pop();
        a++;
    }

    //��n��j��iλ������ɾ��, 
    while (a <= i) {
        nst.pop();
        a++;
    }

    //��m�Ķ���λС�� i-j+1ʱ, �ȸ�n��0
    for (int b = 0; b < i - j + 1 - mst.size(); b++) {
        nst.push(0);
    }

    //��m����
    while (!mst.empty()) {
        int top = mst.top();
        nst.push(top);
        mst.pop();
    }

    //��tmpջ�б��������ȡ����
    while (!tmp.empty()) {
        int top = tmp.top();
        nst.push(top);
        tmp.pop();
    }


    //�Ѳ���������ת����ʮ����
    int ret = 0;  //������
    int step = 1; //��nλ�ĳ���
    while (!nst.empty()) {
        int top = nst.top();
        nst.pop();
        ret += top * step;
        step *= 2;
    }

    cout << ret << endl;
}


// 2. �������һ��ż����ӽ�����������
//�ж��Ƿ�������
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

    //�����ż����һ��+1��ʼѰ��, ��һ����Ʊ�����С��
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