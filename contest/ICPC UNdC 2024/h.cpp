#include <bits/stdc++.h>
#define int long long int
using namespace std;

int getRank(int rating) {
  if (rating < 1200) {
    return 0;
  } else if (rating < 1400) {
    return 1;
  } else if (rating < 1600) {
    return 2;
  } else if (rating < 1900) {
    return 3;
  } else if (rating < 2100) {
    return 4;
  } else if (rating < 2400) {
    return 5;
  } else {
    return 6;
  }
}

string convertRank(int rank) {
  switch (rank)
  {
  case 0:
    return "newbie";
    break;
  case 1:
    return "pupil";
    break;
  case 2:
    return "specialist";
    break;
  case 3:
    return "expert";
    break;
  case 4:
    return "candidate master";
    break;
  case 5:
    return "master";
    break;
  case 6:
    return "grandmaster";
    break;
  default:
    return "newbie";
  }
}

int32_t main() {
  string s;
  int mx, curr, delta;
  
  cin >> s >> curr >> mx >> delta;

  curr += delta;

  int mxRank = getRank(mx);
  int currRank = getRank(curr);

  if (currRank > mxRank) {
    cout << convertRank(currRank) << '\n'; 
  } else {
    cout << "Think about it, you can do it!" << '\n';
  }

  return 0;
}