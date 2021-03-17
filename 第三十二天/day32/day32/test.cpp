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

//ÿ���¶�Ӧ������
static int monthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

//����һ��֮��[month1, month2] ��׬Ǯ��
int getPrice(int month1, int day1, int month2, int day2) {
    int ret = 0;
    if (month1 != month2) {
        //ret ������
        //��Ϊ3���ֽ��м��㣺1.month1�����  2.��month1��month2���������  3.month2�����
        //�����1���ֵĽ��
        ret = (monthDay[month1] - day1 + 1) * isPrimeMonth(month1);
        //�����22���ֵĽ��
        for (int i = month1 + 1; i < month2; i++) {
            ret += monthDay[i] * isPrimeMonth(i);
        }
        //�����3����
        ret += day2 * isPrimeMonth(month2);
    }
    else {
        //�·����
        ret = (day2 - day1 + 1) * isPrimeMonth(month1);
    }


    return ret;
}


void program1() {
    int year1, month1, day1;
    int year2, month2, day2;
    while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2) {
        if (year1 == year2 && month1 == month2) {
            //ֻ��day����ȣ� �Ǿͺ�˵��
            int ret = (day2 - day1 + 1) * isPrimeMonth(month1);
            cout << ret << endl;
        }
        else if (year1 == year2) {
            //year��ȣ� month����
            //�ж��Ƿ�Ϊ���꣬ �ı�2�µ�����
            if (isLeapYear(year1))
                monthDay[2] = 29;
            else
                monthDay[2] = 28;
            cout << getPrice(month1, day1, month2, day2) << endl;
        }
        else {
            //year���ȣ� ������
            //Ҳ�Ƿ�Ϊ�����֣�1.year1��һ�꣬2.��year1��year2��������䣬3.year2��һ��

            //ÿ���¶�Ӧ��Ǯ��
            static int monthPrice[13] = { 0, 62, 28, 31, 60, 31, 60, 31, 62, 60, 62, 30, 62 };
            //������Ǯ����ӣ� �õ�ƽ��һ�����׬��Ǯ
            int price = 0;
            for (int i = 1; i <= 12; i++) {
                price += monthPrice[i];
            }

            //�ж��Ƿ�Ϊ���꣬ �ı�2�µ�����
            if (isLeapYear(year1))
                monthDay[2] = 29;
            else
                monthDay[2] = 28;

            //ret������
            //��ʼ��Ϊ��1���ֵĽ��
            int ret = getPrice(month1, day1, 12, 31);
            //ѭ�������2���ֵĽ��
            for (int i = year1 + 1; i < year2; i++) {
                ret += price;
                //�����1��Ǯ
                if (isLeapYear(i))
                    ret++;
            }
            //�����3���ֵĽ��
            ret += getPrice(1, 1, month2, day2);
            cout << ret << endl;
        }
    }
}



string addStrings(string num1, string num2) {
    //��������
    int len1 = num1.size() - 1;
    int len2 = num2.size() - 1;

    int step = 0; //��λ��Ϣ
    int curnum = 0; //��ǰλ����ֵ
    string ret; //������

    //�Ż�: ��reverse��ǰ���ÿռ�, ����֮��λ���������¿��ռ�Ϳ���
    int len = len1 > len2 ? len1 + 1 : len2 + 1;
    ret.reserve(len);

    //��������λ, �Ӹ�λ��ʼ���, �������λ
    while (len1 >= 0 || len2 >= 0) {
        //�ȼ�����һλ�Ľ�λ
        curnum = step;
        if (len1 >= 0) {
            //num1��û������
            curnum += num1[len1] - '0';
            --len1;
        }
        if (len2 >= 0) {
            //num2��û������
            curnum += num2[len2] - '0';
            --len2;
        }
        //�ж��Ƿ��н�λ
        if (curnum >= 10) {
            curnum -= 10;
            step = 1;
        }
        else {
            //û�н�λ
            step = 0;
        }
        //�����ñ���
        ret.push_back(curnum + '0');
    }

    //ѭ��������, �ж����λ�Ƿ��н�λ
    if (step == 1) {
        //�н�λ, �����λ��λ
        ret.push_back(step + '0');
    }

    //����, �õ���ȷ˳��Ľ��
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
            //ȡ�������λ, ����ջ��
            int j = v[n].size() - 1;
            for (int i = 0; i < 6; i++) {              
                char ch = v[n][j];
                st.push(ch);
                j--;
            }
            //���
            while (!st.empty()) {
                cout << st.top();
                st.pop();
            }
            cout << endl;
        }
        else {
            //��������λ, ֱ�����
            cout << v[n] << endl;
        }
    }
}


int main() {
	program1();
    //program2();

	return 0;
}