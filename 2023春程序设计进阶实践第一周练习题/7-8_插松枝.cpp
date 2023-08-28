#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int n, m, k;
queue<int> q;//推送器
stack<int> s;//盒子
void solve() {
    while (1) {
        vector<int> v;
        bool flag = 0;
        while (1) {
            if (v.empty()) {//松枝是空的
                if (!s.empty()) {//盒子不是空的
                    v.push_back(s.top());//直接放
                    s.pop();
                } else if (!q.empty()) {//盒子是空的，推送器不是
                    v.push_back(q.front());
                    q.pop();
                } else {//否则都是空的,推送器是空的
                    break;
                }
            } else {//松枝不是空的
                if (!s.empty() && s.top() <= v.back()) {//盒子不是空的，且栈顶满足要求
                    v.push_back(s.top());
                    s.pop();
                } else {//栈顶不满足要求
                    while (!q.empty() && s.size() <= m) {//找出满足要求的放到松枝上的数
                        auto t = q.front();
                        if (t <= v.back()) {//找到了
                            q.pop();
                            v.push_back(t);
                            break;
                        } else {
                            if (s.size() == m) {//满了
                                flag = 1;
                                break;
                            } else {//不满足，放到栈顶去
                                s.push(t);
                                q.pop();
                            }
                        }
                    }
                    if (q.empty() && (s.empty() || s.top() > v.back())) {//如果推送器空了但是栈顶放不了，或者推送器空了盒子也是空的。对应pta情况2
                        break;
                    }
                }
            }
            if (flag || v.size() == k) {//如果盒子满了 或者松枝插满了
                break;
            }
        }
        //输出
        for (int i = 0; i < v.size(); i++) {
            if (i != v.size() - 1) {
                cout << v[i] << ' ';
            } else {
                cout << v[i] << endl;
            }
        }
        if (s.empty() && q.empty()) {
            break;
        }
    }
}

int main() {

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    solve();

    return 0;
}