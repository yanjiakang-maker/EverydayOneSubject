// write your code here cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


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

//2. 쳲���������
void program2() {
    vector<string> v;
    v.resize(81);
    v[0] = "0";
    v[1] = "1";
    v[2] = "1";

    for (int i = 3; i <= 80; i++) {
        v[i] = addStrings(v[i - 1], v[i - 2]);
    }

    int start, end;
    while (cin >> start >> end) {
        string ret = "";
        for (int i = start; i <= end; i++) {
            ret = addStrings(ret, v[i]);
        }
        cout << ret << endl;
    }
}



void program1() {
    string str, sub;
    while (cin >> str >> sub) {
        size_t pos = 0;
        int flag = 0; //��ʾ�Ƿ��ǵ�һ�β���
        int ret = 0;
        while (pos < str.size()) {
            for (auto ch : sub) {
                /*
                if (flag == 0) {
                    //���ǵ�һ�β���
                    pos = str.find(ch);
                    flag = 1;
                }
                else
                    pos = str.find(ch, pos + 1);

                if (pos == string::npos) {
                    //û�ҵ�
                    break;
                }
                */
                pos = str.find(ch);

                if (pos == string::npos) {
                    //û�ҵ�
                    break;
                }
                else {
                    //�ҵ���, ������
                    str.erase(pos, 1);
                }
            }

            //û�ҵ����˳���
            if (pos == string::npos)
                break;
            else
                ret++;
        }
        cout << ret << endl;
    }
}


int main() {
    program1();
    //program2();

    return 0;
}