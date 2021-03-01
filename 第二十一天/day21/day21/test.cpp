#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;


void shuffle(vector<int>& v, int n) {
    stack<int> left, right;
    //���Ʒֳ���������
    //����
    for (int i = 0; i < n; i++) {
        int back = v.back();
        right.push(back);
        v.pop_back();
    }
    //����
    for (int i = 0; i < n; i++) {
        int back = v.back();
        left.push(back);
        v.pop_back();
    }

    while (!left.empty() || !right.empty()) {
        v.push_back(left.top());
        left.pop();
        v.push_back(right.top());
        right.pop();
    }
}

// 1. ϴ��
void test() {
    int t;
    cin >> t;
    int n, k;
    vector<int> v;
    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        v.resize(2 * n);
        //��������
        for (int j = 0; j < 2 * n; j++) {
            cin >> v[j];
        }
        //����k��ϴ��
        for (int i = 0; i < k; i++) {
            shuffle(v, n);
        }
        //�������
        for (auto& e : v) {
            cout << e << " ";
        }
        cout << endl;
    }
}


int main() {
	test();

	return 0;
}