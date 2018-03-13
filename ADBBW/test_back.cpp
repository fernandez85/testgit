#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

void myfunction (unsigned int i) {  // function:
  cout << ' ' << i;
}

int main() {
	ios::sync_with_stdio(false);
	
	vector<set<unsigned int>> doubleAreas;
    set<unsigned int> t, x;
	
	t.insert(1);
    t.insert(2);

    doubleAreas.push_back(t);

    t.clear();    
    t.insert(3);
    t.insert(4);
	
    doubleAreas.push_back(t);

    x = doubleAreas[0];
    cout << "first: ";
    for_each(x.begin(), x.end(), myfunction);
    cout << "\n";

    x = doubleAreas[1];
    cout << "second: ";
    for_each(x.begin(), x.end(), myfunction);
    cout << "\n";
	
	return 0;
}