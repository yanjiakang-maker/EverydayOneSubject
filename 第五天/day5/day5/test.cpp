#include<iostream>
#include<vector>
#include<string>

using namespace std;


void test() {
	int n[][3] = { 10, 20, 30, 40, 50, 60 };
	int(*p)[3];
	p = n;
	cout << p[0][0] << " " << *(p[0] + 1) << " " << (*p)[2];
}



//1. 统计回文

//判断是否为回文串
bool isPalindrome(const string& str) {
    size_t begin = 0;
    size_t end = str.size() - 1;

    while (begin < end) {
        //如果有不相等的, 直接返回false
        if (str[begin] != str[end])
            return false;
        begin++;
        end--;
    }
    //遍历完能走到这, 说明是回文串, 返回true
    return true;
}


//获取一个字母可以的插入方法个数
int getNum(string& str1, char& ch) {
    //保存结果
    int ret = 0;
    //遍历每一个位置
    for (int pos = 0; pos <= str1.size(); pos++) {
        string tmp = str1;
        //插入字符
        tmp.insert(tmp.begin() + pos, ch);
        //判断是否构成回文
        if (isPalindrome(tmp))
            ret++;
    }
    return ret;
}


int getNum(string& str1, const string& str2) {
    //保存结果
    int ret = 0;
    //遍历每一个位置
    for (size_t pos = 0; pos <= str1.size(); pos++) {
        string tmp = str1;
        //插入字符串
        tmp.insert(pos, str2);
        //判断是否构成回文
        if (isPalindrome(tmp))
            ret++;
    }
    return ret;
}


void statistics() {
    string str1;
    string str2;
    //输入两个字符串
    cin >> str1;
    cin >> str2;

    int ret = getNum(str1, str2);
    cout << ret << endl;

    //下面完全是我傻币...我以为要一个字符一个字符的数...结果人家是一串全插进去
    //注意看题啊~
    /*
    //创建两个映射表, 一个存str2的字母出现次数, 一个存相应字母插入str1之后可以构成回文串的方法数
    int charTable[256] = {0};
    int numTable[256] = {0};

    //遍历str2, 记录字母出现次数
    for(const auto& ch : str2) {
        charTable[ch]++;
    }

    int i = 0;
    //再次遍历str2
    while (i < str2.size()) {
        //如果num表中这个位置为0, 说明这个字母没有进行过判断
        if(numTable[str2[i]] == 0) {
            //获取该字母插入可以构成回文串的方法数,
            int num = getNum(str1, str2[i]);
            //并计入num表
            numTable[str2[i]] = num;
            i++;
        }
        else {
            //如果num表不为0, 说明这个字母已经知道有多少种方法了
            //避免重复计算, 直接向后继续遍历
            i++;
            continue;
        }
    }

    //保存结果
    int ret = 0;
    //计算总方法数
    for (int i = 'a'; i <= 'z'; i++) {
        ret += charTable[i] * numTable[i];
    }
    cout << ret << endl;
    */
}



//2. 求连续子串的最大和
void getMaxSum() {
    int n;
    vector<int> v;
    //多组测试样例
    while (cin >> n) {
        v.resize(n);
        //输入数据
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int max = v[0];
        int tmp = v[0];
        //从首元素的下一个位置开始遍历
        vector<int>::iterator it = v.begin() + 1;
        while (it != v.end()) {
            tmp += *it;
            //如果相加后的值小于当前it指向的值, 那么直接舍弃, 使用当前it指向的值作为新的最大值
            if (tmp < *it)
                tmp = *it;
            //如果tmp 大于 max , 将tmp赋给max, 保存最大值
            if (tmp > max)
                max = tmp;

            it++;
        }

        cout << max << endl;
    }
}


int main() {
	//test();
    statistics();

	return 0;
}