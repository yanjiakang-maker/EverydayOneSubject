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




// 1.���ڵ�������ת��
    //ÿ�µ�������
static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool isRightDate(int& year, int& month, int& day) {
    if (year <= 0 || month >= 13)
        return false;

    //�ж��Ƿ�Ϊ����
    if ((year % 4 == 0 && year % 100 != 0)
        || (year % 400 == 0)) {
        //������¼�һ��
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
            //���ڴ���
            cout << -1 << endl;
        }
        else {
            //������ȷ, ������
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