#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define DEBUG

#define MAX_HOLES 50000

typedef struct
{
	unsigned int from;
	unsigned int to;
	unsigned long long int cost;
} offer_t;

int main() {
	ios::sync_with_stdio(false);

	long long int costsCounter, layerCnt, layerCntHolder, offersSize, minCost;
	unsigned int t, holesCnt, offersCnt, h, holeIdx, tmp;
	vector<unsigned int> holes;
	queue<offer_t> helper;
	vector<offer_t> offers;
	vector<offer_t> offersPostRemove;
	offer_t offer, offerHelper, minOffer;

	holes.reserve(MAX_HOLES);
	offers.reserve(MAX_HOLES);
	offersPostRemove.reserve(MAX_HOLES);
	
	cin >> t;
	
	while (t--)
	{
		cin >> holesCnt;
		cin >> offersCnt;
		holes.clear();
		for (unsigned int i=0u; i<holesCnt; i++)
		{
			cin >> h;
			holes.push_back(h);
		}

		layerCnt = 0;
		offers.clear();
		for (unsigned int i=0u; i<offersCnt; i++)
		{
			cin >> offer.from;
			cin >> offer.to;
			cin >> offer.cost;
		
			if (holes[0] >= offer.from && holes[0] <= offer.to)
			{
				helper.push(offer);
#ifdef DEBUG
				cout << ">> push queue, cost = " << offer.cost << "\n";
#endif //DEBUG
				++layerCnt;
				continue;
			}

			offers.push_back(offer);
#ifdef DEBUG
			cout << ">> push offers, cost = " << offer.cost << ", from = " << offer.from << ", to = " << offer.to << "\n";
#endif //DEBUG			
		}
		layerCntHolder = layerCnt;
		for (unsigned int holeIdx=1u; holeIdx<holesCnt; holeIdx++)
		{
			tmp = holes[holeIdx];
#ifdef DEBUG
			cout << "> HOLE = " << tmp<< "\n";
#endif //DEBUG
			offersPostRemove.clear();
			layerCnt = 0;
			while (layerCntHolder--)
			{
				offer = helper.front();
				helper.pop();
#ifdef DEBUG
				cout << ">> pop queue, cost = " << offer.cost << ", from = " << offer.from << ", to = " << offer.to << "\n";
#endif //DEBUG

				if (tmp >= offer.from && tmp <= offer.to)
				{
					helper.push(offer);
					++layerCnt;
#ifdef DEBUG
					cout << ">> push queue, cost = " << offer.cost << "\n";
#endif //DEBUG	
				}
				else
				{
					offersSize = offersPostRemove.size();
#ifdef DEBUG
					cout << ">> offersPostRemove size = " << offersPostRemove.size() << "\n";
#endif //DEBUG

					for (unsigned int i=0u; i<offersSize; i++)
					{
						offerHelper = offersPostRemove[i];
						if (tmp >= offerHelper.from && tmp <= offerHelper.to)
						{
#ifdef DEBUG
							cout << ">>> matched [RM] cost = " << offerHelper.cost << ", from = " << offerHelper.from << ", to = " << offerHelper.to << "\n";
#endif //DEBUG
							offerHelper.cost += offer.cost;
							if (offerHelper.from > offer.from) offerHelper.from = offer.from;
							if (offerHelper.to < offer.to) offerHelper.to = offer.to;
							
							helper.push(offerHelper);
							++layerCnt;
#ifdef DEBUG
							cout << ">> push queue, cost = " << offerHelper.cost << ", from = " << offerHelper.from << ", to = " << offerHelper.to << "\n";
#endif //DEBUG*/

						}
					}

					offersSize = offers.size();
#ifdef DEBUG
					cout << ">> offers size = " << offers.size() << "\n";
#endif //DEBUG

					for (unsigned int i=0u; i<offersSize; i++)
					{
						offerHelper = offers[i];
						if (tmp >= offerHelper.from && tmp <= offerHelper.to)
						{
#ifdef DEBUG
							cout << ">>> matched cost = " << offers[i].cost << ", from = " << offers[i].from << ", to = " << offers[i].to << "\n";
#endif //DEBUG

							offersPostRemove.push_back(offerHelper);
							swap(offers[i], offers.back());
							offers.pop_back();
							--i;
							--offersSize;

							offerHelper.cost += offer.cost;
							if (offerHelper.from > offer.from) offerHelper.from = offer.from;
							if (offerHelper.to < offer.to) offerHelper.to = offer.to;
							
							helper.push(offerHelper);
							++layerCnt;
#ifdef DEBUG
							cout << ">> push queue, cost = " << offerHelper.cost << ", from = " << offerHelper.from << ", to = " << offerHelper.to << "\n";
#endif //DEBUG*/
						}
					}
				}
			}
#ifdef DEBUG
			cout << "> layer [ " << holeIdx << " ], cnt = " << layerCnt << "\n";
#endif //DEBUG
			if (layerCnt == 0) break;
			layerCntHolder = layerCnt;
		}

		if (layerCnt == 0)
		{
			cout << "NIE\n";
//			while (!helper.empty()) helper.pop();
		}
		else
		{
			minCost = helper.front().cost;
			helper.pop();
#ifdef DEBUG
			cout << "End Q: " << minCost;
#endif //DEBUG
			while (--layerCnt)
			{
				offer = helper.front();
				helper.pop();
#ifdef DEBUG
				cout << ", " << offer.cost;	
#endif //DEBUG
				if (offer.cost < minCost) minCost = offer.cost;
			}
#ifdef DEBUG
			cout << "\n";
#endif //DEBUG

			cout << minCost << "\n";
		}
		
	}

	return 0;
}