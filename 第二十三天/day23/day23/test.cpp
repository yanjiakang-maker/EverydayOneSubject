#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


int getValue(vector<int> gifts, int n) {
    sort(gifts.begin(), gifts.end());
    int ret = 0; //记录出现次数
    int retnum = 0; //记录结果值
    for (int i = 0; i < gifts.size(); i++) {
        if (gifts[i] == gifts[i + 1]) {
            //有重复元素, 记录, 计数
            int num = gifts[i]; //记录元素的值
            int tmp = 0; //记录出现次数
            while (gifts[i] == num) {
                tmp++;
                i++;
            }
            if (tmp > ret)
                retnum = num;
        }
    }
    if (ret > gifts.size() / 2)
        return retnum;
    else
        return 0;
}


void program1() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << getValue(v, n) << endl;
}


int main() {
	program1();

	return 0;
}