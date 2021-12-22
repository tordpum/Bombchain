#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  int N, M;
  int x, y;
  int e;
  scanf("%d%d", &N, &M);
  vector<pair<int, int>> bombv;
  map<int, pair<int, int>> bombm;
  for (int i=0; i<M; i++) {
    scanf("%d%d", &x, &y);
    // �� (x,y) ���� bombv
    // �� (key -> (x,y) ���� bombm ����� key = y*N + x
  }
  set<int> exploding_set;
  scanf("%d", &e);
  // �� key �ͧ���Դ��� e-1 � bombv ���� exploding_set
  while (!exploding_set.empty()) {
    int b = *exploding_set.begin(); // ��� key �ͧ���Դ����á�૵�͡��
    exploding_set.erase(b); // ź�͡�ҡ૵�

    // ��������Դ����ǹ͹ (x-axis) ����仢��
    pair<int, int> cb = bombm[b];
    int xs = max(0, cb.first-3);
    int xe = min(N-1, cb.first+3);
    for (int x=xs; x<=xe; x++) {
      int key = cb.second * N + x;
      if (key != b ) {
        auto bomb = bombm.find(key);
        if (bomb != bombm.end())  {
          exploding_set.insert(key);
        }
      }
    }

    // ��������Դ����ǵ�� (y-axis) �ҡ��ŧ��ҧ
    // TODO
    //

    // ź���Դ�͡�ҡ bombm ��颹Ҵ㹡�ä�Ŵŧ
    bombm.erase(b);
  }

  //printf("bombm.size(): %ld\n", bombm.size());
  if (bombm.size()) {
    // �������Դ��褧����ͨҡ�ӴѺ��� bombv
    for (int i=0; i<bombv.size(); i++) {
      int key = bombv[i].second*N + bombv[i].first;
      auto b = bombm.find(key);
      if (b != bombm.end()) {
        cout << i+1 << '\n';
      }
    }
  } else {
    cout << "0" << '\n';
  }
  return 0;
}
