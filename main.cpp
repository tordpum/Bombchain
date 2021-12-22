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
  
  }
  set<int> exploding_set;
  scanf("%d", &e);
  
  while (!exploding_set.empty()) {
    int b = *exploding_set.begin(); 
    exploding_set.erase(b); 

    
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

    bombm.erase(b);
  }

  if (bombm.size()) {
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
