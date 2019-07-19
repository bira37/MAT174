#include <bits/stdc++.h>

#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define mp make_pair
#define mt make_tuple
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector< ii >
#define EPS 1e-9
#define INF 1e18
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0) return b;
  else return gcd(b%a, a);
}

int xc,yc,r;
int l1,r1,l2,r2;

double f_add(double x){
  double a = 1.0;
  double b = -2*yc;
  double c = x*x - 2*x*xc + xc*xc - r*r + yc*yc;
  double delta = b*b - 4*a*c;
  double y1 = (-b + sqrt(delta))/2*a;
  double y2 = (-b - sqrt(delta))/2*a;
  double y = max(y1, y2);
  y = min(y, (double)max(r1,r2));
  y = max(y, (double)min(r1,r2));
  return y;
}

double f_sub(double x){
  double a = 1.0;
  double b = -2*yc;
  double c = x*x - 2*x*xc + xc*xc - r*r + yc*yc;
  double delta = b*b - 4*a*c;
  double y1 = (-b + sqrt(delta))/2*a;
  double y2 = (-b - sqrt(delta))/2*a;
  double y = min(y1, y2);
  y = max(y, (double)min(r1,r2));
  y = min(y, (double)max(r1,r2));
  return y;
}

double simps_add(double a, double b) {
  return (f_add(a) + 4*f_add((a+b)/2) + f_add(b))*(b-a)/6;
}

double integrate_add(double a, double b){
  double m = (a+b)/2;
  double l = simps_add(a,m), r = simps_add(m,b), tot=simps_add(a,b);
  if (fabs(l+r-tot) < 1e-9) return tot;
  return integrate_add(a,m)+integrate_add(m,b);
}

double simps_sub(double a, double b) {
  return (f_sub(a) + 4*f_sub((a+b)/2) + f_sub(b))*(b-a)/6;
}

double integrate_sub(double a, double b){
  double m = (a+b)/2;
  double l = simps_sub(a,m), r = simps_sub(m,b), tot=simps_sub(a,b);
  if (fabs(l+r-tot) < 1e-9) return tot;
  return integrate_sub(a,m)+integrate_sub(m,b);
}

int32_t main(){
  ifstream cin("mammoth.in");
  ofstream cout("mammoth.out");
  cin >> xc >> yc >> r;
  cin >> l1 >> r1 >> l2 >> r2;
  if(max(xc-r, min(l1,l2)) > min(xc+r, max(l1,l2))){
    cout << 0 << endl;
    return 0;
  }
  double ans1 = integrate_add(max(xc-r, min(l1,l2)), min(xc+r, max(l1,l2)));
  double ans2 = integrate_sub(max(xc-r, min(l1,l2)), min(xc+r, max(l1,l2)));
  cout << fixed << setprecision(9) << ans1 - ans2 << endl;
}
