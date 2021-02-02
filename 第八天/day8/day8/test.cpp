#include<iostream>
#include<string>
#include<vector>

using namespace std;


class AB {
public:
	AB(int a = 0) {
		count++;
	}
	static int count;
};
int AB::count = 0;


void test() {
	AB a(4), b(5), c[3], *p[2] = { &a, &b };
	cout << AB::count << endl;

	const int* p1;
}



//1. 字符串的两种排序方法
void stringSort() {
    int n;
    cin >> n;

    vector<string> v;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    //string* str = new string[n];
    //for (int i = 0; i < n; i++) {
    //    getline(cin, str[i]);
    //}

    //给两个标记, 初值设为0,表示不是这种方法排序, 1表示可以
    int lex = 1;
    int len = 1;

    int i = 0;
    while (i < n - 1) {
        //如果str[i] 比 str[i+1] 大, 则说明不是字典序排序
        if (strcmp(v[i].c_str(), v[i + 1].c_str()) > 0) {
            lex = 0;
            break;
        }
        i++;
    }

    i = 0;
    while (i < n - 1) {
        //如果str[i] 比 str[i+1] size大, 则说明不是长度排序
        if (v[i].size() > v[i + 1].size()) {
            len = 0;
            break;
        }
        i++;
    }

    if (lex == 1 && len == 1)
        cout << "both" << endl;
    else if (lex == 1 && len == 0)
        cout << "lexicographically" << endl;
    else if (lex == 0 && len == 1)
        cout << "lengths" << endl;
    else
        cout << "none" << endl;
}



// 2. 最小公倍数
void test2() {
    int a, b;
    cin >> a >> b;

    //把大数给到b, 小数给a
    if (a > b)
        swap(a, b);
    //如果b是a的倍数, 那么最小公倍数就是b
    if (b % a == 0)
        cout << b << endl;

    //记录b的值, 让b每次 += tmp, 直到b能整除a
    int tmp = b;
    while (1) {
        b += tmp;
        if (b % a == 0) {
            cout << b << endl;
            break;
        }
    }
}


int main() {
	//test();
    //test2();
    stringSort();

	return 0;
}