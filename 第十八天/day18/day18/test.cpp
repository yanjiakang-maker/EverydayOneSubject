#include<iostream>
#include<string>
#include<vector>

using namespace std;

int f(int n) {
	static int i = 1;
	if (n >= 5)
		return n;
	n += i;
	i++;
	return f(n);
}


class B {
public :
	void print() {
		cout << "B::print()" << endl;
	}
};

class C : public B {
public:
	void print() {
		cout << "A::print()" << endl;
	}
};


void test() {
	cout << f(5) << endl;
	C b;
	b.print();

	cout << 'a' - 'A' << endl;
}


int main() {
	test();

	return 0;
}