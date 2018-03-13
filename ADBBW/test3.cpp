#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

#define MODU 1010101011

int main() {
	//std::ios::sync_with_stdio(false);

	//unsigned int rabbitPairCntTab[1000001];
	vector<unsigned long long> rrr;
	int childsMax, growsMax, val;
	unsigned int t;

	cin >> childsMax >> growsMax;
	int *childs = new int[childsMax];
	int *grows = new int[growsMax];
	for (int i=0; i < childsMax; i++) cin >> childs[i];
	for (int i=0; i < growsMax; i++)  cin >> grows[i];

	int a = childsMax, b = growsMax, iloczyn=a*b;
	while(a) swap(b%=a,a); 

	//prepare data
	std::vector<long long> grownUpLineUp(10, 0);
	std::vector<long long> generationsPairCnt(iloczyn/b, 0);

	//rabbitPairCntTab[0] = 0;
	//rabbitPairCntTab[1] = 1;
	rrr.push_back(0);
	rrr.push_back(1);

	grownUpLineUp[9] = 1;

	long long grownUps;
	long long k, rk, tmp;
	for (int i=2; i<1000000; i++)
	{
		//grow
		grownUps = grownUpLineUp.back();
		grownUpLineUp.pop_back();
		grownUpLineUp.insert(grownUpLineUp.begin(), 0);

		//produce
		rk = generationsPairCnt.size() - 1;
		for (k = 0; k < generationsPairCnt.size(); k++, rk--)
		{
			grownUpLineUp[10 - grows[k % growsMax]] += childs[k % childsMax] * generationsPairCnt[k];
		}

		tmp = generationsPairCnt.back() + grownUps;
		grownUps = (tmp  % MODU > 0) ? tmp % MODU : MODU;
		generationsPairCnt.pop_back();
		generationsPairCnt.insert(generationsPairCnt.begin(), grownUps); //put
		//calculate
		//rabbitPairCntTab[i] =

		tmp = std::accumulate(grownUpLineUp.begin(), grownUpLineUp.end(), 0ll) +
			std::accumulate(generationsPairCnt.begin(), generationsPairCnt.end(), 0ll);

		rrr.push_back(tmp % MODU);	
	}

	cin >> t;
	while (t--)
	{
		cin >> val;
        //std::cout << rabbitPairCntTab[val] << "\n";
		std::cout << rrr[val] << "\n";
	}

	//clean heap
	delete [] childs;
	delete [] grows;

	return 0;
}
