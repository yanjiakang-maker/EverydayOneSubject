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



// 1. 计算整数二进制中1的个数
void getBinary1() {
	int num;
	while (cin >> num) {
		//使用栈存放num的二进制数
		stack<int> st;
		int count = 0; //保存1的个数

		//把num转换为二进制并存放进st
		while (num > 0) {
			int tmp = num % 2;
			st.push(tmp);
			num /= 2;
		}

		//遍历栈, 记录1的个数
		while (!st.empty()) {
			if (st.top() == 1)
				count++;
			st.pop();
		}

		cout << count << endl;
	}
}


// 2. 手套配套



int main() {
	test();


	return 0;
}