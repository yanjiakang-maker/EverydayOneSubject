#include<iostream>
#include<string>

using namespace std;

void sameStr() {
    string s1, s2;
    string ret = "";
    cin >> s1;
    cin >> s2;
    string::iterator it = s1.size() < s2.size() ? s1.begin() : s2.begin();
    int begin = 0;
    int end = 0;
    //��һ���ַ������꼴����
    while (begin < s1.size() && begin < s2.size()) {
        if (s1[begin] == s2[begin]) {
            //����������
            end = begin + 1;
            //������, �ҳ��Ӵ�
            while (s1[end] == s2[end]) {
                end++;
            }
            //�������ҵ����Ӵ���֮ǰ�ĳ�, ��ֵ��ret
            if (end - begin > ret.size()) {
                ret.append(it + begin, it + end);
            }
        }
        else {
            //�����, ������
            begin++;
        }
    }

    cout << ret << endl;
}


int main() {

	sameStr();

	return 0;
}