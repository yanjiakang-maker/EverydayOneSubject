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



//1. 字符串中找出连续最长的数字串
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
            //如果是数字的话, 向后找到最后一个数字
            while (str[i] >= '0' && str[i] <= '9')
                i++;
            string tmp(it + start, it + i);
            if (tmp.size() > ret.size())
                ret = tmp;
        }
        else {
            //不是数字, 继续向后找
            i++;
        }
    }
    cout << ret << endl;
}


//2. 数组中出现次数超过一半的数字
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        //排序取中间的元素即可
        sort(numbers.begin(), numbers.end());

        int mid = numbers.size() / 2;
        int ret = numbers[mid];

        //验证
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