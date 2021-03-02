#include<iostream>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;


void getOnceChar(string& str) {
    char table[128] = { 0 }; //ӳ���
    int flag = 0; //���
    //��һ��ѭ��, ch��Ӧλ��++
    for (auto& ch : str) {
        table[ch]++;
    }
    //�ڶ���ѭ��, Ѱ��ֻ����һ�ε��ַ�
    for (auto& ch : str) {
        if (table[ch] == 1) {
            flag = 1;
            cout << ch << endl;
            break;
        }
    }
    if (flag == 0) {
        cout << -1 << endl;
    }
}

//�ҵ��ַ����е�һ��ֻ����һ�ε��ַ�
void program2() {
	string str;
	while (cin >> str) {
		getOnceChar(str);
	}
}


int gcd(int x, int y) {
    int z = y;
    while (x % y != 0) {
        z = x % y;
        x = y;
        y = z;
    }
    return z;

}

//С�׵Ĵ������֮·
void program1() {
    //������������ͳ�ʼ����ֵ
    int num, begin;
    while (cin >> num >> begin) {
        //�������ķ�����
        vector<int> v(num, 0);
        for (int i = 0; i < num; i++) {
            cin >> v[i];
        }
        //��¼����ֵ
        int ret = begin;
        //����v, ��������ֵ
        for (auto& e : v) {
            //e:����ķ�����
            if (e <= ret) {
                ret += e;
            }
            else {
                ret += gcd(ret, e);
            }
        }
        cout << ret << endl;
    }
}

int main() {
	//program2();
    program1();
	
	return 0;
}