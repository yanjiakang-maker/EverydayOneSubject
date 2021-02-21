#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

class A {
public:
	A() {
		cout << "A ";
	}

	void foo() {
		delete this;
	}

	~A() {
		cout << "deA ";
	}
};

class B {
public:
	B() {
		cout << "B ";
	}

	~B() {
		cout << "deB ";
	}
};

class C : public A, public B{
public:
	C() {
		cout << "C ";
	}

	~C() {
		cout << "deC ";
	}
};

void test() {
	A* a = new A();
	a->foo();
}



// 1. ����������������1�ĸ���
void getBinary1() {
	int num;
	while (cin >> num) {
		//ʹ��ջ���num�Ķ�������
		stack<int> st;
		int count = 0; //����1�ĸ���

		//��numת��Ϊ�����Ʋ���Ž�st
		while (num > 0) {
			int tmp = num % 2;
			st.push(tmp);
			num /= 2;
		}

		//����ջ, ��¼1�ĸ���
		while (!st.empty()) {
			if (st.top() == 1)
				count++;
			st.pop();
		}

		cout << count << endl;
	}
}


// 2. ��������



int main() {
	test();


	return 0;
}