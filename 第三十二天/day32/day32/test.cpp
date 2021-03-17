#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;

bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    return false;
}

int isPrimeMonth(int month) {
    if (month == 1 || month == 4 || month == 6 || month == 8 || month == 9
        || month == 10 || month == 12)
        return 2;
    else
        return 1;
}

//每个月对应的天数
static int monthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

//计算一年之内[month1, month2] 的赚钱数
int getPrice(int month1, int day1, int month2, int day2) {
    int ret = 0;
    if (month1 != month2) {
        //ret 保存结果
        //分为3部分进行计算：1.month1这个月  2.（month1，month2）这个区间  3.month2这个月
        //计算第1部分的结果
        ret = (monthDay[month1] - day1 + 1) * isPrimeMonth(month1);
        //计算第22部分的结果
        for (int i = month1 + 1; i < month2; i++) {
            ret += monthDay[i] * isPrimeMonth(i);
        }
        //计算第3部分
        ret += day2 * isPrimeMonth(month2);
    }
    else {
        //月份相等
        ret = (day2 - day1 + 1) * isPrimeMonth(month1);
    }


    return ret;
}


void program1() {
    int year1, month1, day1;
    int year2, month2, day2;
    while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2) {
        if (year1 == year2 && month1 == month2) {
            //只有day不相等， 那就好说了
            int ret = (day2 - day1 + 1) * isPrimeMonth(month1);
            cout << ret << endl;
        }
        else if (year1 == year2) {
            //year相等， month不等
            //判断是否为闰年， 改变2月的天数
            if (isLeapYear(year1))
                monthDay[2] = 29;
            else
                monthDay[2] = 28;
            cout << getPrice(month1, day1, month2, day2) << endl;
        }
        else {
            //year不等， 最复杂情况
            //也是分为三部分：1.year1这一年，2.（year1，year2）这个区间，3.year2这一年

            //每个月对应的钱数
            static int monthPrice[13] = { 0, 62, 28, 31, 60, 31, 60, 31, 62, 60, 62, 30, 62 };
            //把上述钱数相加， 得到平年一年可以赚的钱
            int price = 0;
            for (int i = 1; i <= 12; i++) {
                price += monthPrice[i];
            }

            //判断是否为闰年， 改变2月的天数
            if (isLeapYear(year1))
                monthDay[2] = 29;
            else
                monthDay[2] = 28;

            //ret保存结果
            //初始化为第1部分的结果
            int ret = getPrice(month1, day1, 12, 31);
            //循环计算第2部分的结果
            for (int i = year1 + 1; i < year2; i++) {
                ret += price;
                //闰年加1块钱
                if (isLeapYear(i))
                    ret++;
            }
            //计算第3部分的结果
            ret += getPrice(1, 1, month2, day2);
            cout << ret << endl;
        }
    }
}



string addStrings(string num1, string num2) {
    //两个索引
    int len1 = num1.size() - 1;
    int len2 = num2.size() - 1;

    int step = 0; //进位信息
    int curnum = 0; //当前位的数值
    string ret; //保存结果

    //优化: 用reverse提前开好空间, 避免之后位数不够重新开空间和拷贝
    int len = len1 > len2 ? len1 + 1 : len2 + 1;
    ret.reserve(len);

    //遍历所有位, 从个位开始相加, 依次向高位
    while (len1 >= 0 || len2 >= 0) {
        //先加上上一位的进位
        curnum = step;
        if (len1 >= 0) {
            //num1还没遍历完
            curnum += num1[len1] - '0';
            --len1;
        }
        if (len2 >= 0) {
            //num2还没遍历完
            curnum += num2[len2] - '0';
            --len2;
        }
        //判断是否有进位
        if (curnum >= 10) {
            curnum -= 10;
            step = 1;
        }
        else {
            //没有进位
            step = 0;
        }
        //先逆置保存
        ret.push_back(curnum + '0');
    }

    //循环结束后, 判断最高位是否有进位
    if (step == 1) {
        //有进位, 给最高位进位
        ret.push_back(step + '0');
    }

    //逆置, 得到正确顺序的结果
    reverse(ret.begin(), ret.end());

    return ret;
}


void program2() {
    int n;
    vector<string> v;
    v.resize(5);
    v[0] = "0";
    v[1] = "1";
    v[2] = "2";

    while (cin >> n) {
        v.resize(n + 1);
        for (int i = 3; i <= n; i++) {
            if (v[i] != "")
                continue;
            else {
                string tmp = addStrings(v[i - 2], v[i - 1]);
                v[i] = tmp;
            }
        }

        stack<char> st;
        if (v[n].size() > 6) {
            //取出最后六位, 放入栈中
            int j = v[n].size() - 1;
            for (int i = 0; i < 6; i++) {              
                char ch = v[n][j];
                st.push(ch);
                j--;
            }
            //输出
            while (!st.empty()) {
                cout << st.top();
                st.pop();
            }
            cout << endl;
        }
        else {
            //不超过六位, 直接输出
            cout << v[n] << endl;
        }
    }
}


int main() {
	program1();
    //program2();

	return 0;
}