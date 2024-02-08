#include <bits/stdc++.h>

using namespace std;

struct TPoint {
  double x, y;
};

double dis(TPoint p1, TPoint p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}
double dissq(TPoint p1, TPoint p2) {
  return pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2);
}
int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  TPoint A, B, C, D;
  cin >> A.x >> A.y;
  cin >> B.x >> B.y;
  cin >> C.x >> C.y;
  cin >> D.x >> D.y;
  int res = 0;
  // TH1: AB // DC
  bool th1 = false;
  // (A.x - B.x) / (A.y - B.y) == (D.x - C.x) / (D.y - C.y)
  if ((A.x - B.x) * (D.y - C.y) == (D.x - C.x) * (A.y - B.y)) {
    th1 = true;
  }
  // TH2: AD // BC
  bool th2 = false;
  if ((A.x - D.x) * (B.y - C.y) == (B.x - C.x) * (A.y - D.y)) {
    th2 = true;
  }
  if ((th1 == true && th2 == false) || (th1 == false && th2 == true)) {
    res = 1;
  }
  else if ((th1 == true && th2 == true)) { // hinh binh hanh, thoi, hcn, hv
    res = 2;
    // neu la hinh thoi
    if (dissq(A, B) == dissq(B, C) && dissq(B, C) == dissq(C, D) && dissq(C, D) == dissq(D, A)) {
      res = 3;
    }
    if (dissq(A, B) == dissq(C, D) && dissq(B, C) == dissq(A, D) && dissq(A, B) + dissq(B, C) == dissq(C, A)) {
      res = 4;
    }

    if (dissq(A, B) == dissq(B, C) && dissq(B, C) == dissq(C, D) && dissq(C, D) == dissq(D, A) && dissq(A, B) + dissq(B, C) == dissq(C, A)) {
      res = 5;
    }
  }
  cout << res << '\n';
}