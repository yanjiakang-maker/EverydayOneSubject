#include<iostream>
#include<string>
#include<vector>

using namespace std;


class A {
public:
	~A() {
		cout << "A" << endl;
	}
};

class B {
public:
	virtual ~B() {
		cout << "B" << endl;
	}
};

class C : public A, public B {
public:
	~C() {
		cout << "C" << endl;
	}
};


void test() {
	C* c = new C;
	B* b1 = dynamic_cast<B*>(c);
	A* a2 = dynamic_cast<A*>(b1);
	delete a2;
}


// 1. ������Ǳ���
void iNOC() {
    int n;

    cin >> n;
    vector<vector<int>> v;
    v.resize(n);
    int ret = -1;
    int size = 2 * n - 1;
    for (int i = 0; i < n; i++) {
        //��һ��2n - 1������������ռ�
        v[i].resize(size);
        if (i == 0) {
            //��һ��, �������м丳ֵһ��1
            v[i][size / 2] = 1;
        }
        //��n - 1֮ǰ�����ȼ������
        else if (i < n - 1) {
            //����ͼ�������, ÿһ�д�n-1-i��ʼ, һ����2i+1������, ��n+i����
            for (int j = n - 1 - i; j < n + i; j++) {
                v[i][j] = v[i - 1][j - 1] + v[i - 1][j] + v[i - 1][j + 1];
            }
        }

        if (i == n - 1) {
            //���һ��, ��¼��һ��ż����λ��
            int pos = 0;
            for (; pos < n; pos++) {
                if (pos == 0)
                    v[i][pos] = v[i - 1][pos] + v[i - 1][pos + 1];
                else if (pos == n - 1)
                    v[i][pos] = v[i - 1][pos - 1] + v[i - 1][pos];
                else
                    v[i][pos] = v[i - 1][pos - 1] + v[i - 1][pos] + v[i - 1][pos + 1];

                if (v[i][pos] % 2 == 0) {
                    ret = pos + 1;
                    break;
                }
            }
        }
    }

    cout << ret << endl;
}





int main() {
	//test();
    iNOC()
        ;
	return 0;
}