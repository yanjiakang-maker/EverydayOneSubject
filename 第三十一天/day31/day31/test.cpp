#include<iostream>
#include<vector>
#include<queue>
#include<math.h>


using namespace std;


bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    return false;
}

void printDate(int year, int month, int day) {
    if (month >= 10 && day >= 10) {
        printf("%4d-%2d-%2d\n", year, month, day);
    }
    else if(month < 10 && day < 10) {
        printf("%4d-0%d-0%d\n", year, month, day);
    }
    else if (month < 10) {
        printf("%4d-0%d-%d\n", year, month, day);
    }
    else {
        printf("%4d-%d-0%d\n", year, month, day);
    }
}

void program1() {
    vector<int> v;
    v.resize(10000);
    int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    //����-����:0-6
    v[2000] = 6;
    //2000�굽9999���1��1�����ڼ������
    for (int i = 2001; i < 9999; i++) {
        int year = i - 1;
        if (isLeapYear(year))
            v[i] = (v[year] + 366) % 7;
        else
            v[i] = (v[year] + 365) % 7;
    }

    int year;
    while (cin >> year) {
        if (isLeapYear(year))
            days[2] = 29;
        else
            days[2] = 28;

        //��¼ÿ���µ�һ�������
        int month[13] = { 0 };
        month[1] = v[year];

        for (int i = 1; i <= 12; i++) {
            int day = 1;
            if (i == 1) {
                //1. Ԫ��
                printDate( year, i, day);
                //2. һ�µ���������һ
                if (month[1] == 1)
                    day += 14;
                else
                    day += (8 - month[1]) + 14;
                printDate(year, i, day);
            }
            else if (i == 2) {
                //3. 2�µĵ���������һ
                int day = 1;
                month[2] = (month[1] + days[1]) % 7;
                if (month[2] == 1)
                    day += 14;
                else
                    day += (8 - month[2]) + 14;
                printDate(year, i, day);
            }
            else if (i == 5) {
                //4. 5�����һ������һ
                //��¼�������һ�������
                month[5] = (month[2] + days[2] + days[3] + days[4] + days[5]) % 7;
                int day = 31;
                while (month[5] != 1) {
                    day--;
                    month[5]--;
                    if (month[5] == -1)
                        month[5] = 6;
                }
                printDate(year, i, day + 1);
            }
            else if (i == 7) {
                //5. 7��4��
                int day = 4;
                printDate(year, i, day);
            }
            else if (i == 9) {
                //6. 9�µĵ�һ������һ
                month[9] = (month[5] + 1 + days[5] + days[6] + days[7] + days[8]) % 7;
                int day = 1;
                if (month[9] != 1)
                    day += (8 - month[9]);
                printDate(year, i, day - 2);
            }
            else if (i == 11) {
                //7. 11�µĵ��ĸ�������
                month[11] = (month[9] + days[9] +days[10]) % 7;
                int day = 1;
                if (month[1] == 4)
                    day += 21;
                else {
                    //1�Ų�������
                    if (month[11] < 3)
                        day += (4 - month[11]) + 21;
                    else
                        day += (4 + 7 - month[11]) + 21;
                }
                printDate(year, i, day - 2);
            }
            else if (i == 12) {
                //8. ʥ����
                int day = 25;
                printDate(year, i, day);
            }

        }
    }
}


bool isPrimeNum(int num) {
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

void program2() {
    int num;
    while (cin >> num) {
        int tmp = num;
        queue<int> q;
        while (!isPrimeNum(num)) {
            for (int i = 2; i <= sqrt(num); i++) {
                if (num % i == 0) {
                    q.push(i);
                    num /= i;
                    break;
                }
            }
        }
        q.push(num);

        //ȡ�������е�����
        cout << tmp << " = ";
        while (!q.empty()) {
            if (q.size() != 1)
                cout << q.front() << " * ";
            else
                cout << q.front() << endl;
            q.pop();
        }


    }
}



int main() {
	program1();
	//program2();

	return 0;
}