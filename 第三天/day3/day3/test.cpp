#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


int func() {
	int i, j, k = 0;
	for (i = 0, j = -1; j = 0; i++, j++) {
		k++;
	}
	return k;
}

void test() {
	cout << (func());
}



//1. �ַ������ҳ�����������ִ�
void longestnum() {
    string str;
    cin >> str;

    string ret;
    int i = 0;
    int start = 0;
    string::iterator it = str.begin();
    while (i < str.size()) {
        if (str[i] >= '0' && str[i] <= '9') {
            start = i;
            //��������ֵĻ�, ����ҵ����һ������
            while (str[i] >= '0' && str[i] <= '9')
                i++;
            string tmp(it + start, it + i);
            if (tmp.size() > ret.size())
                ret = tmp;
        }
        else {
            //��������, ���������
            i++;
        }
    }
    cout << ret << endl;
}


//2. �����г��ִ�������һ�������
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        //����ȡ�м��Ԫ�ؼ���
        sort(numbers.begin(), numbers.end());

        int mid = numbers.size() / 2;
        int ret = numbers[mid];

        //��֤
        int count = 0;
        for (const auto& e : numbers) {
            if (e == ret)
                count++;
        }
        if (count > mid)
            return ret;
        else
            return 0;
    }
};



int main() {
	test();

	return 0;
}