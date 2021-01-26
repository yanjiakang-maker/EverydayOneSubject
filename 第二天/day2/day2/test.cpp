#include<iostream>
#include<string>
#include<vector>

using namespace std;



class Sample {
public:
	Sample(int x = 0) {
		//p = new int (x);
		*p = x;
	}

	int show() {
		return *p;
	}

	~Sample() {
		if (p)
			delete p;
	}

private:
	int* p;
};

void test() {
	Sample s(5);
	cout << s.show() << endl;
}

struct A {
	unsigned a;
	unsigned b;
	unsigned c;
	unsigned d;
	char index;
};


//子序列
void zixulie() {
	int n;
	cin >> n;
	vector<int> v;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	
	//int num = 0;
	//int i = 1;
	//while (i < n) {
	//	if (v[i] > v[i - 1]) {
	//		while (i < n && v[i] >= v[i - 1])
	//			i++;
	//		num++;
	//		i++;
	//	}
	//	else if (v[i] < v[i - 1]) {
	//		while (i < n && v[i] <= v[i - 1])
	//			i++;
	//		num++;
	//		i++;
	//	}
	//	else {
	//		i++;
	//	}
	//}
	//cout << num << endl;
	
	
	v.resize(n + 1);
	int count = 0;
	v[n] = 0;
	int i = 0;

	while (i < n) {
		if (v[i] < v[i + 1]) {
			while (i < n && v[i] <= v[i + 1])
				i++;
			i++;
			count++;
		}
		else if (v[i] > v[i + 1]) {
			while (i < n && v[i] >= v[i + 1])
				i++;
			i++;
			count++;
		}
		else
			i++;
	}
	cout << count << endl;
}


//倒置一句话
void reverseStr() {
	string s;
	getline(cin, s);
	reverse(s.begin(), s.end());

	size_t pos = 0;
	size_t begin = 0;
	string::iterator it = s.begin();

	while (pos < s.size()) {
		begin = pos;
		pos = s.find(" ", begin);
		if (pos != string::npos) {
			//找到了空格
			reverse(it + begin, it + pos);
			pos++;
		}
		else {
			//找不到, 说明只剩最后一个单词
			break;
		}
	}
	reverse(it + begin, s.end());

	cout << s << endl;
}


int main() {
	//test();
	//cout << sizeof(A) << endl;
	zixulie();
	//reverseStr();

	return 0;
}