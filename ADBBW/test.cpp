#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

#define DEBUG

int check_factory_strategy(int fh, int fl, int g, int gh, int t)
{
		int turnCnt = 0;
		int ghz = g * gh;

#ifdef DEBUG
		cout << "Turn: " << turnCnt << " |";
		cout << " fh= " << fh << ", fl= " << fl;
		cout << ", g= " << g << (ghz % gh ? "(+1)" : "(+0)") << ", ghz= " << ghz;
		cout << ", t= " << t << "\n";
#endif

		//first factory attack
		while (fh > 0)
		{
			++turnCnt;

			//mariusz turn
			fh -= t;
			if (fh <= 0)
			{
				ghz += fh;
				if (ghz <= 0)
				{
					//mariusz won
					return turnCnt;
				}
			}
			//paweł turn
			t -= ((ghz / gh) + (ghz % gh ? 1 : 0));
			ghz += gh;

			if (!--fl)
			{
				fh = 0;
			}
#ifdef DEBUG
			cout << "Turn: " << turnCnt << " |";
			cout << " fh= " << fh << ", fl= " << fl;
			cout << ", g= " << (ghz / gh) << (ghz % gh ? "(+1)" : "(+0)") << ", ghz= " << ghz;
			cout << ", t= " << t << "\n";
#endif
 
			//check t
			if (t <= 0)
			{
				break;
			}
		}

		while (t > 0)
		{
			++turnCnt;

			//mariusz turn
			ghz -= t;
			if (ghz <= 0)
			{
				//mariusz won
				return turnCnt;
			}
			//paweł turn
			t -= ((ghz / gh) + (ghz % gh ? 1 : 0));
#ifdef DEBUG
			cout << "Turn: " << turnCnt << " ||";
			cout << " fh= " << fh << ", fl= " << fl;
			cout << ", g= " << (ghz / gh) << (ghz % gh ? "(+1)" : "(+0)") << ", ghz= " << ghz;
			cout << ", t= " << t << "\n";
#endif
		}

	//paweł won	
	return 0;
}

int check_gauss_strategy(int fh, int fl, int g, int gh, int t)
{
		int turnCnt = 0;
		int ghz = g * gh;

#ifdef DEBUG
		cout << "Turn: " << turnCnt << " |";
		cout << " fh= " << fh << ", fl= " << fl;
		cout << ", g= " << g << (ghz % gh ? "(+1)" : "(+0)") << ", ghz= " << ghz;
		cout << ", t= " << t << "\n";
#endif

		//first factory attack
		while (fh > 0)
		{
			++turnCnt;

			//mariusz turn
			ghz -= t;
			if (ghz <= 0)
			{
				fh += ghz;
				if (fh <= 0)
				{
					//mariusz won
					return turnCnt;
				}
				ghz = 0;
			}
			//paweł turn
			t -= ((ghz / gh) + (ghz % gh ? 1 : 0));
			ghz += gh;

			if (!--fl)
			{
				fh = 0;
			}
#ifdef DEBUG
			cout << "Turn: " << turnCnt << " |";
			cout << " fh= " << fh << ", fl= " << fl;
			cout << ", g= " << (ghz / gh) << (ghz % gh ? "(+1)" : "(+0)") << ", ghz= " << ghz;
			cout << ", t= " << t << "\n";
#endif
 
			//check t
			if (t <= 0)
			{
				break;
			}
		}
	
		while (t > 0)
		{
			++turnCnt;

			//mariusz turn
			ghz -= t;
			if (ghz <= 0)
			{
				//mariusz won
				return turnCnt;
			}
			//paweł turn
			t -= ((ghz / gh) + (ghz % gh ? 1 : 0));

#ifdef DEBUG
			cout << "Turn: " << turnCnt << " ||";
			cout << " fh= " << fh << ", fl= " << fl;
			cout << ", g= " << (ghz / gh) << (ghz % gh ? "(+1)" : "(+0)") << ", ghz= " << ghz;
			cout << ", t= " << t << "\n";
#endif
		}

	//paweł won	
	return 0;
}

int main() {
	ios::sync_with_stdio(false);

	int fh, fl, g, gh, ghz, t, n;
	int factory_result, gauss_result;

	cin >> n;
	while (n--)
	{
		cin >> fh >> fl >> gh >> g >> t;

		factory_result = check_factory_strategy(fh, fl, g, gh, t);
		gauss_result = check_gauss_strategy(fh, fl, g, gh, t);
		if (factory_result > 0)
		{
			cout << "MARIUSZ " << (gauss_result > 0 && factory_result > gauss_result ? gauss_result : factory_result) << "\n";
		}
		else if (gauss_result > 0)
		{
			cout << "MARIUSZ " << (factory_result > 0 && factory_result < gauss_result ? factory_result : gauss_result) << "\n";
		}
		else
		{
			cout << "PAWEL\n";
		}
	}
	
	return 0;
}
