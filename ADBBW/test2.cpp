#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

void displaySetElement(unsigned int el)
{
	cout << " " << el;
}

typedef struct
{
	unsigned int from;
	unsigned int to;
} oneDirection_t;

int main() {
	ios::sync_with_stdio(false);
	
	unsigned int t, roads, points, point_from, point_to;
	char direction;
	vector<set<unsigned int>> doubleAreas;
	set<unsigned int>::iterator dblAreaSetElmnt_iter;
	vector<oneDirection_t> oneDirectionRoads;
	oneDirection_t oneDirRoadElmnt;
	int pointFromAreaFound, pointToAreaFound;
	
	cin >> t;
	while (t--)
	{
		cout << "TEST " << t << "\n";

		cin >> points;
		cin >> roads;

		doubleAreas.clear();
		oneDirectionRoads.clear();

		while (roads--)
		{
			cin >> direction;
			cin >> point_from;
			cin >> point_to;

			if (direction == 'j')
			{
				oneDirRoadElmnt.from = point_from;
				oneDirRoadElmnt.to = point_to;
				oneDirectionRoads.push_back(oneDirRoadElmnt);
			}
			else //direction == 'd'
			{
				pointFromAreaFound = 0;
				pointToAreaFound = 0;
				for (int k=1; k <= doubleAreas.size(); k++)
				{
					if (!pointFromAreaFound && doubleAreas[k-1].count(point_from))
					{
						doubleAreas[k-1].insert(point_to);
						pointFromAreaFound = k-1;
						if (pointToAreaFound) break;
						else continue;
					}

					if (!pointToAreaFound && doubleAreas[k-1].count(point_to))
					{
						doubleAreas[k-1].insert(point_from);
						pointToAreaFound = k-1;
						if (pointFromAreaFound) break;
						else continue;
					}
				}
				cout << "* pFromIdx: " << pointFromAreaFound << ", pToIdx: " << pointToAreaFound << "\n";
				cout << "* pFrom: " << point_from << ", pTo: " << point_to << "\n";
				if (!pointFromAreaFound && !pointToAreaFound)
				{
					set<unsigned int> dblAreaSetElmnt;
					dblAreaSetElmnt.insert(point_from);
					dblAreaSetElmnt.insert(point_to);
					doubleAreas.push_back(dblAreaSetElmnt);
				}
				else if (pointFromAreaFound && pointToAreaFound && (pointFromAreaFound != pointToAreaFound))
				{
					unsigned int idxMoveFrom, idxMoveTo;
					if (doubleAreas[pointFromAreaFound].size() < doubleAreas[pointToAreaFound].size())
					{
						idxMoveFrom = pointFromAreaFound;
						idxMoveTo = pointToAreaFound;
					}
					else
					{
						idxMoveFrom = pointToAreaFound;
						idxMoveTo = pointFromAreaFound;
					} 
							
					doubleAreas[idxMoveTo].insert(doubleAreas[idxMoveFrom].begin(), doubleAreas[idxMoveFrom].end());
					doubleAreas.erase(doubleAreas.begin() + idxMoveFrom);
				}
			}
		}

		for (int k=0; k < doubleAreas.size(); k++)
		{
			cout << "> da[ " << k << " ]:";
			for_each (doubleAreas[k].begin(), doubleAreas[k].end(), displaySetElement);
			cout << "\n";
		}
		cout << "> sr:";
		for (int i=0; i < oneDirectionRoads.size(); i++)
			cout << " (" << oneDirectionRoads[i].from << ", " << oneDirectionRoads[i].to << ")";
		cout << "\n";
	}
	
	return 0;
}
