#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>

using namespace std;


void test() {
	char dog[] = "wang\0miao";
	cout << sizeof(dog) << " " << strlen(dog) << endl;

	strcpy(dog, "No");
}




// 1.日期到天数的转换
    //每月的天数表
static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool isRightDate(int& year, int& month, int& day) {
    if (year <= 0 || month >= 13)
        return false;

    //判断是否为闰年
    if ((year % 4 == 0 && year % 100 != 0)
        || (year % 400 == 0)) {
        //闰年二月加一天
        days[2] = 29;
    }
    if (day <= 0 || day > days[month])
        return false;

    return true;
}

void dateTodays() {
    int year, month, day;
    while (cin >> year >> month >> day) {
        if (!isRightDate(year, month, day)) {
            //日期错误
            cout << -1 << endl;
        }
        else {
            //日期正确, 算天数
            int ret = 0;
            for (int i = 1; i < month; i++)
                ret += days[i];
            ret += day;
            cout << ret << endl;
        }
    }
}



int main() {
	test();

	return 0;
}