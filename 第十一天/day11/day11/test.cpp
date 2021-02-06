#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>

using namespace std;



//1. �����������   -->  100%
int getLCA(int a, int b) {
    // write code here
    if (a == b)
        return a;

    int parent1 = a / 2;
    int parent2 = b / 2;

    while (parent1 > 0 && parent2 > 0) {
        if (parent1 == parent2) {
            break;
        }

        //����parent
        while (parent1 != 1 && parent1 > parent2)
            parent1 /= 2;

        while (parent2 != 1 && parent2 > parent1)
            parent2 /= 2;

    }
    return parent1;
}

void test() {
    int a, b;
    cin >> a >> b;
    cout << getLCA(a, b) << endl;
}


//2. ���������bit��    100%
void getMax1() {
    int n;
    while (cin >> n) {
        stack<int> st; //������ת���õ���ջ
        //priority_queue<int> pq; //���ȼ�����, ����1��������
        int count = 0; //������
        int max = 0; //�������ֵ

        st.push(0);

        //ת���ɶ�����, ������ջ��
        while (n > 0) {
            int tmp = n % 2;
            st.push(tmp);
            n /= 2;
        }

        //��������������, ��¼����1�ĸ���
        while (!st.empty()) {
            if (st.top() == 1) {
                count++;
            }
            else {
                //��ǰλ��0, ��¼max, ������count��0
                //pq.push(count);
                if (count > max)
                    max = count;
                count = 0;
            }
            st.pop();
        }
        cout << max << endl;
    }
}



int main() {
	test();
    //getMax1();


	return 0;
}