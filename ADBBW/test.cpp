#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	string text, pattern, subPat;
	int n, cnt, cntn, vcnt, k, l, shift, offset;
	int uPattern;
	bool b;
	vector<int> vs[4];
	vector<int> vcs[4];

	cin >> text;
	cnt = text.length();
	cntn = 0;

	for (int i=0; i<cnt; i++)
	{
		l = ((i < cnt - 3) ? 4 : (cnt - i));
		uPattern = 0;
		shift = 0;
		for (int k=0; k<l; k++)
		{
		 	uPattern |= ((int) text[i+k]) << (shift);
		 	shift += 8;

		 	b = false;
		 	cntn = vs[k].size();
		 	for (int j=0; j<cntn; j++)
		 	{
		 		if (vs[k][j] == uPattern)
		 		{
		 			++vcs[k][j];
		 			b = true;
		 			break;
		 		}
		 	}
		 	if (!b)
		 	{
		 		vs[k].push_back(uPattern);
		 		vcs[k].push_back(1);
		 	}
		}
	}

	cin >> n;
	while(n--)
	{
	 	cin >> pattern;

		uPattern = 0;
		l = pattern.length();
		shift = 0;
		for (int k=0; k<l; k++)
		{
			uPattern |= ((int) pattern[k]) << (shift);
			shift += 8;
		}

		b = false;
		cntn = vs[l-1].size();
		for (int j=0; j<cntn; j++)
		{
			if (vs[l-1][j] == uPattern)
			{
				cout << vcs[l-1][j] << "\n";
				b = true;
				break;
			}
		}

		if (!b)
		{
			cout << "0\n";
		}
	
	}

	return 0;
}
