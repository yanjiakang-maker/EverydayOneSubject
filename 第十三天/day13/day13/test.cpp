#include<iostream>
#include<string>
#include<vector>

using namespace std;

void test() {
	int i = 0, a = 1, b = 2, c = 3;
	i = ++a || ++b || ++c;
	cout << i << " " << a << " " << b << " " << c << endl;
}


// 1. ��������   (80%)
void analysis() {
    //����һ������
    string str;
    getline(cin, str);
    //�������һ���ո�, �Ա�����������һ������
    str += ' ';

    size_t begin = 0;
    string ret[4];
    int count = 0;
    string::iterator it = str.begin();
    size_t pos = str.find(' ');

    if (pos != string::npos) {
        count++;
        //ȷ������1
        ret[0].assign(it, it + pos);
        ++pos;
    }

    for (int i = 1; i <= 3; i++) {
        if (pos < str.size()) {
            // ������ ""
            if (str[pos] == '"') {
                begin = pos + 1;
                //��pos+1��λ���ҵ���һ������, ���м�����ݾ��ǲ���
                pos = str.find('"', pos + 1);
                ret[i].assign(it + begin,  it + pos);
                count++;
                pos += 2;
            }
            else {
                //û��""
                begin = pos;
                pos = str.find(' ', pos + 1);
                ret[i].assign(it + begin, it + pos);
                count++;
                pos++;
            }
            
        }
    }

    //���ĸ���������һ��
    //ret[3].assign(str, pos, str.size());

    cout << count << endl;
    for (int i = 0; i < 4; i++) {
        cout << ret[i] << endl;
    }
}




int main() {
	//test();
    analysis();


	return 0;
}