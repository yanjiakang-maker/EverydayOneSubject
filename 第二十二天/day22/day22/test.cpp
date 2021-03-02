#include<iostream>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;


void getOnceChar(string& str) {
    char table[128] = { 0 }; //映射表
    int flag = 0; //标记
    //第一次循环, ch相应位置++
    for (auto& ch : str) {
        table[ch]++;
    }
    //第二次循环, 寻找只出现一次的字符
    for (auto& ch : str) {
        if (table[ch] == 1) {
            flag = 1;
            cout << ch << endl;
            break;
        }
    }
    if (flag == 0) {
        cout << -1 << endl;
    }
}

//找到字符串中第一个只出现一次的字符
void program2() {
	string str;
	while (cin >> str) {
		getOnceChar(str);
	}
}


int gcd(int x, int y) {
    int z = y;
    while (x % y != 0) {
        z = x % y;
        x = y;
        y = z;
    }
    return z;

}

//小易的打怪升级之路
void program1() {
    //定义怪物数量和初始能力值
    int num, begin;
    while (cin >> num >> begin) {
        //输入怪物的防御力
        vector<int> v(num, 0);
        for (int i = 0; i < num; i++) {
            cin >> v[i];
        }
        //记录能力值
        int ret = begin;
        //遍历v, 计算最后的值
        for (auto& e : v) {
            //e:怪物的防御力
            if (e <= ret) {
                ret += e;
            }
            else {
                ret += gcd(ret, e);
            }
        }
        cout << ret << endl;
    }
}

int main() {
	//program2();
    program1();
	
	return 0;
}