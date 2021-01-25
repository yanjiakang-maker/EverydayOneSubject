#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

void test() {
	printf("%s, %5.3s\n", "computer", "computer");

	int cnt = 0;
	for (int x = 0, y = 0; (y = 123) && (x < 4); x++) {
		cnt++;
	}
	cout << cnt << endl;
}


void test2() {
	vector<int> v;
	v.resize(5);
	for (int i = 0; i < 5; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < 5; i++) {
		cout << v[i] << " ";
	}
}


//1. 输出最大水平值
void getMaxSum() {
    /**
    * 思路: 
    *     先对数据进行排序, 排序完之后前n个数据是最小的, 肯定不用
    *     n ~ 3n之间的2n个数字, 每两个为一组, 加次大值(也就是左边的值)
    *     综上, 只要把排序后的数组的 n, n + 2 ..... 3n - 2 加起来即可
    */

    int n;
    //多个测试样例
    while (cin >> n) {
        vector<int> v;
        v.resize(n * 3);
        for (int i = 0; i < n * 3; i++) {
            cin >> v[i];
        }

        sort(v.begin(), v.end());
        long long sum = 0;
        for (int i = n; i < 3 * n; i += 2) {
            sum += v[i];
        }
        cout << sum << endl;
    }
}


//2. 删除公共字符
void delStr() {
    /*思路:
        把要删除的字符映射到一个数组中
        然后遍历第一个字符串,
        如果第一个字符串中的字符没有出现在映射数组中
        保存在另外一个string中, 因为删除的效率太低
    */
    string str1;
    string str2;
    //使用getline, 因为cin遇到空格就结束了
    getline(cin, str1);
    getline(cin, str2);

    //创建一个映射数组
    int table[256] = { 0 };
    for (int i = 0; i < str2.size(); i++) {
        table[str2[i]]++;
    }

    //遍历第一个字符串, 如果当前字符不在映射表中, ret += 这个字符 保存结果
    string ret;
    for (int i = 0; i < str1.size(); i++) {
        if (table[str1[i]] == 0)
            ret += str1[i];
    }
    cout << ret << endl;
}


int main() {
	//test2();
    getMaxSum();

	return 0;
}