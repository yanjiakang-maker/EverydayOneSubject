#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


int getValue(vector<int> gifts, int n) {
    sort(gifts.begin(), gifts.end());
    int ret = 0; //��¼���ִ���
    int retnum = 0; //��¼���ֵ
    for (int i = 0; i < gifts.size(); i++) {
        if (gifts[i] == gifts[i + 1]) {
            //���ظ�Ԫ��, ��¼, ����
            int num = gifts[i]; //��¼Ԫ�ص�ֵ
            int tmp = 0; //��¼���ִ���
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