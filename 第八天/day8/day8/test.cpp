#include<iostream>
#include<string>
#include<vector>

using namespace std;


class AB {
public:
	AB(int a = 0) {
		count++;
	}
	static int count;
};
int AB::count = 0;


void test() {
	AB a(4), b(5), c[3], *p[2] = { &a, &b };
	cout << AB::count << endl;

	const int* p1;
}



//1. �ַ������������򷽷�
void stringSort() {
    int n;
    cin >> n;

    vector<string> v;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    //string* str = new string[n];
    //for (int i = 0; i < n; i++) {
    //    getline(cin, str[i]);
    //}

    //���������, ��ֵ��Ϊ0,��ʾ�������ַ�������, 1��ʾ����
    int lex = 1;
    int len = 1;

    int i = 0;
    while (i < n - 1) {
        //���str[i] �� str[i+1] ��, ��˵�������ֵ�������
        if (strcmp(v[i].c_str(), v[i + 1].c_str()) > 0) {
            lex = 0;
            break;
        }
        i++;
    }

    i = 0;
    while (i < n - 1) {
        //���str[i] �� str[i+1] size��, ��˵�����ǳ�������
        if (v[i].size() > v[i + 1].size()) {
            len = 0;
            break;
        }
        i++;
    }

    if (lex == 1 && len == 1)
        cout << "both" << endl;
    else if (lex == 1 && len == 0)
        cout << "lexicographically" << endl;
    else if (lex == 0 && len == 1)
        cout << "lengths" << endl;
    else
        cout << "none" << endl;
}



// 2. ��С������
void test2() {
    int a, b;
    cin >> a >> b;

    //�Ѵ�������b, С����a
    if (a > b)
        swap(a, b);
    //���b��a�ı���, ��ô��С����������b
    if (b % a == 0)
        cout << b << endl;

    //��¼b��ֵ, ��bÿ�� += tmp, ֱ��b������a
    int tmp = b;
    while (1) {
        b += tmp;
        if (b % a == 0) {
            cout << b << endl;
            break;
        }
    }
}


int main() {
	//test();
    //test2();
    stringSort();

	return 0;
}