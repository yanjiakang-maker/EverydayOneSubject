#include<iostream>
#include<string>
#include<vector>

using namespace std;


void test() {
	int i = 1;
	if (i <= 0)
		printf("****\n");
	else
		printf("%%%%\n");
}

void test2() {
	int x = 9999;
	int count = 0;
	while (x) {
		count++;
		x = x & (x - 1);
	}
	cout << count << endl;
}


template<class T>
class Foo {
	T val;
public:
	Foo(T t)
		:val(t) 
	{}
};
template<class T>
class FooDer : public Foo<T> {

};

//void test3() {
//	FooDer<int> d(5);
//}


//1. 井字棋
    //暴力列举完事


// 2. 密码强度等级   -->  100%

//是否是大写字母
bool isLetter(const char& ch) {
    if (ch >= 'A' && ch <= 'Z')
        return true;
    return false;
}

//是否是小写字母
bool isletter(const char& ch) {
    if (ch >= 'a' && ch <= 'z')
        return true;
    return false;
}

//是否是数字
bool isDigit(const char& ch) {
    if (ch >= '0' && ch <= '9')
        return true;
    return false;
}

//是否是字符
bool isChar(const char& ch) {
    if ((ch >= 0x21 && ch <= 0x2F)
        || (ch >= 0x3A && ch <= 0x40)
        || (ch >= 0x5B && ch <= 0x60)
        || (ch >= 0x7B && ch <= 0x7E))
        return true;
    return false;
}

void password() {
    string pass;
	while (cin >> pass) {
        int Let = 0, let = 0, Digit = 0, Char = 0;
        int size = pass.size();
        int grade = 0;

        //先看长度
        if (size <= 4)
            grade = 5;
        else if (size >= 5 && size <= 7)
            grade = 10;
        else
            grade = 25;

        //遍历, 记录各种类型的字符个数
        for (const auto& ch : pass) {
            if (isLetter(ch))
                Let++;
            else if (isletter(ch))
                let++;
            else if (isDigit(ch))
                Digit++;
            else if (isChar(ch))
                Char++;
        }

        //算分数
        if (Let > 0 && let > 0) {
            //大小字母都有
            grade += 20;
        }
        else if (Let == 0 && let == 0) {
            //没有字母, 成绩不变
        }
        else {
            grade += 10;
        }

        if (Digit > 1) {
            //大于1个数字
            grade += 20;
        }
        else if (Digit == 1) {
            //1个数字
            grade += 10;
        }

        if (Char > 1) {
            //大于个符号
            grade += 25;
        }
        else if (Char == 1) {
            //1个符号
            grade += 10;
        }

        if (Let != 0 && let != 0 && Digit != 0 && Char != 0)
            grade += 5;
        if (Let + let != 0 && Digit != 0 && Char != 0)
            grade += 3;
        if (Let + let != 0 && Digit != 0 && Char == 0)
            grade += 2;

        if (grade >= 90)
            cout << "VERY_SECURE" << endl;
        else if (grade >= 80)
            cout << "SECURE" << endl;
        else if (grade >= 70)
            cout << "VERY_STRONG" << endl;
        else if (grade >= 60)
            cout << "STRONG" << endl;
        else if (grade >= 50)
            cout << "AVERAGE" << endl;
        else if (grade >= 25)
            cout << "WEAK" << endl;
        else
            cout << "VERY_WEAK" << endl;
	}
}





int main() {
	//test();
	//test2();
    password();


	return 0;
}