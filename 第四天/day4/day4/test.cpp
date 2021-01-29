#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;


void test() {
	int a[5] = { 1, 3, 5, 7, 9 };
	//&a 是一个数组指针, +1跳过整个数组
	int* p = (int*)(&a + 1);
	printf("%d,%d", *(a + 1), *(p - 1));
}


int cnt = 0;
int fib(int n) {
	cnt++;
	if (n == 0)
		return 1;
	else if (n == 1)
		return 2;
	else
		return fib(n - 1) + fib(n - 2);
}

void test2() {
	fib(8);
	cout << cnt << endl;
}



//1. 求A B C三个小朋友手里的糖个数    (90%) --> 100% 
void getSugar() {
	int arr[4];
	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
	}

	//求出a b c的值
	int a = (arr[0] + arr[2]) / 2;
	int c = (arr[3] - arr[1]) / 2;
	int b = (arr[1] + arr[3]) / 2;
	int b1 = (arr[2] - arr[0]) / 2;

	//if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1)
	if (b != b1)
		cout << "No" << endl;
	else
		cout << a / 2 << " " << b / 2 << " " << c / 2 << endl;
}


//2. 将十进制数M转换成N进制数  16 >= N >= 2   (100%)
void changeNum() {
	stack<char> st;
	//建立映射表
	string table = "0123456789ABCDEF";

	int m, n;
	cin >> m >> n;

	//标记负数, 如果是负数, flag -> -1
	int flag = 0;
	//考虑负数
	if (m < 0) {
		flag = -1;
		m = -m;
	}

	while (m != 0) {
		//取模, 得到的余数是table的下标
		int idx = m % n;
		st.push(table[idx]);
		m /= n;
	}

	//如果是负数, 输出一个负号
	if (flag == -1)
		cout << "-";
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	cout << endl;
}

int main() {
	//test();
	//test2();

	changeNum();

	return 0;
}