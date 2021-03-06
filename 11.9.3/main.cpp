#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "Vector.h"
using namespace std;
using namespace VECTOR;
int main()
{
	srand(time(0));
	double target;
	double direction;
	double stepLen;
	cout << "Enter target distance (q to quit) -> ";
	cin >> target;
	int times;
	cout << "Enter test times -> ";
	cin >> times;
	int test = times;
	cout << "Enter step length -> ";
	cin >> stepLen;
	unsigned long maxSteps = 0, minSteps = ULONG_MAX;
	double avgSteps = 0;
	while (times)
	{
		Vector step;
		Vector result(0.0, 0.0);
		unsigned long steps = 0;
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(stepLen, direction, Vector::POL);
			result = result + step;
			cout << steps << ": (x,y) = " << result << endl;
			++steps;
		}
		cout << "After " << steps << "steps, the subject has the following location:\n";
		result.rect_mode();
		cout << result << endl << "or" << endl;
		result.polar_mode();
		cout << result << endl;
		cout << "Average outward distance per step = " << result.magval() / steps << endl;
		--times;
		maxSteps = (steps > maxSteps ? steps : maxSteps);
		minSteps = (steps < minSteps ? steps : minSteps);
		avgSteps += steps;
	}
	avgSteps /= (double)test;
	cout << "After " << test << " tests, the max steps= " << maxSteps << " ,the min steps= " << minSteps << ", the average steps= " << avgSteps << endl;
	cout << "Bye." << endl;
}
//OUTPUT:
//Enter target distance(q to quit) -> 100
//Enter test times -> 3
//Enter step length -> 20
//0: (x, y) = (x, y) = (-9.69619, -9.69619)
//1 : (x, y) = (x, y) = (-4.85775, -4.85775)
//2 : (x, y) = (x, y) = (13.5523, 13.5523)
//3 : (x, y) = (x, y) = (14.9475, 14.9475)
//4 : (x, y) = (x, y) = (-0.373417, -0.373417)
//5 : (x, y) = (x, y) = (14.4895, 14.4895)
//6 : (x, y) = (x, y) = (7.64908, 7.64908)
//7 : (x, y) = (x, y) = (-4.93733, -4.93733)
//8 : (x, y) = (x, y) = (-15.8301, -15.8301)
//9 : (x, y) = (x, y) = (-33.4891, -33.4891)
//10 : (x, y) = (x, y) = (-13.5652, -13.5652)
//11 : (x, y) = (x, y) = (-33.5378, -33.5378)
//12 : (x, y) = (x, y) = (-43.234, -43.234)
//13 : (x, y) = (x, y) = (-56.8739, -56.8739)
//14 : (x, y) = (x, y) = (-73.6473, -73.6473)
//After 15steps, the subject has the following location :
//(x, y) = (-73.6473, -73.6473)
//or
//(m, a) = (104.153, -2.35619)
//Average outward distance per step = 6.94354
//0 : (x, y) = (x, y) = (10.8928, 10.8928)
//1 : (x, y) = (x, y) = (5.7164, 5.7164)
//2 : (x, y) = (x, y) = (22.6774, 22.6774)
//3 : (x, y) = (x, y) = (4.40645, 4.40645)
//4 : (x, y) = (x, y) = (-11.1365, -11.1365)
//5 : (x, y) = (x, y) = (4.18442, 4.18442)
//6 : (x, y) = (x, y) = (1.74704, 1.74704)
//7 : (x, y) = (x, y) = (-1.72593, -1.72593)
//8 : (x, y) = (x, y) = (-21.3585, -21.3585)
//9 : (x, y) = (x, y) = (-2.4481, -2.4481)
//10 : (x, y) = (x, y) = (17.5397, 17.5397)
//11 : (x, y) = (x, y) = (37.3451, 37.3451)
//12 : (x, y) = (x, y) = (17.9392, 17.9392)
//13 : (x, y) = (x, y) = (-1.08197, -1.08197)
//14 : (x, y) = (x, y) = (18.4054, 18.4054)
//15 : (x, y) = (x, y) = (19.1034, 19.1034)
//16 : (x, y) = (x, y) = (0.693327, 0.693327)
//17 : (x, y) = (x, y) = (-14.8496, -14.8496)
//18 : (x, y) = (x, y) = (2.11137, 2.11137)
//19 : (x, y) = (x, y) = (-14.662, -14.662)
//20 : (x, y) = (x, y) = (3.88164, 3.88164)
//21 : (x, y) = (x, y) = (2.83492, 2.83492)
//22 : (x, y) = (x, y) = (9.01526, 9.01526)
//23 : (x, y) = (x, y) = (-9.25565, -9.25565)
//24 : (x, y) = (x, y) = (-7.16508, -7.16508)
//25 : (x, y) = (x, y) = (-18.3489, -18.3489)
//26 : (x, y) = (x, y) = (-25.1893, -25.1893)
//27 : (x, y) = (x, y) = (-25.1893, -25.1893)
//28 : (x, y) = (x, y) = (-21.0311, -21.0311)
//29 : (x, y) = (x, y) = (-2.3595, -2.3595)
//30 : (x, y) = (x, y) = (-9.19991, -9.19991)
//31 : (x, y) = (x, y) = (-16.3673, -16.3673)
//32 : (x, y) = (x, y) = (-9.52686, -9.52686)
//33 : (x, y) = (x, y) = (-7.08947, -7.08947)
//34 : (x, y) = (x, y) = (3.21129, 3.21129)
//35 : (x, y) = (x, y) = (8.72403, 8.72403)
//36 : (x, y) = (x, y) = (26.0445, 26.0445)
//37 : (x, y) = (x, y) = (21.5455, 21.5455)
//38 : (x, y) = (x, y) = (19.1081, 19.1081)
//39 : (x, y) = (x, y) = (29.1081, 29.1081)
//40 : (x, y) = (x, y) = (40.5797, 40.5797)
//41 : (x, y) = (x, y) = (30.5797, 30.5797)
//42 : (x, y) = (x, y) = (11.9081, 11.9081)
//43 : (x, y) = (x, y) = (-6.76355, -6.76355)
//44 : (x, y) = (x, y) = (8.09934, 8.09934)
//45 : (x, y) = (x, y) = (-4.75641, -4.75641)
//46 : (x, y) = (x, y) = (9.87066, 9.87066)
//47 : (x, y) = (x, y) = (26.6441, 26.6441)
//48 : (x, y) = (x, y) = (46.4494, 46.4494)
//49 : (x, y) = (x, y) = (66.1456, 66.1456)
//50 : (x, y) = (x, y) = (49.9653, 49.9653)
//51 : (x, y) = (x, y) = (31.8391, 31.8391)
//52 : (x, y) = (x, y) = (47.5993, 47.5993)
//53 : (x, y) = (x, y) = (65.8702, 65.8702)
//54 : (x, y) = (x, y) = (52.4876, 52.4876)
//55 : (x, y) = (x, y) = (63.9591, 63.9591)
//56 : (x, y) = (x, y) = (45.549, 45.549)
//57 : (x, y) = (x, y) = (28.2285, 28.2285)
//58 : (x, y) = (x, y) = (8.53238, 8.53238)
//59 : (x, y) = (x, y) = (26.1913, 26.1913)
//60 : (x, y) = (x, y) = (13.3356, 13.3356)
//61 : (x, y) = (x, y) = (-1.05122, -1.05122)
//62 : (x, y) = (x, y) = (-21.0238, -21.0238)
//63 : (x, y) = (x, y) = (-5.26359, -5.26359)
//64 : (x, y) = (x, y) = (10.2793, 10.2793)
//65 : (x, y) = (x, y) = (3.43892, 3.43892)
//66 : (x, y) = (x, y) = (-8.03261, -8.03261)
//67 : (x, y) = (x, y) = (10.8778, 10.8778)
//68 : (x, y) = (x, y) = (-8.03261, -8.03261)
//69 : (x, y) = (x, y) = (-27.2578, -27.2578)
//70 : (x, y) = (x, y) = (-46.7452, -46.7452)
//71 : (x, y) = (x, y) = (-46.3962, -46.3962)
//72 : (x, y) = (x, y) = (-28.5761, -28.5761)
//73 : (x, y) = (x, y) = (-47.1197, -47.1197)
//74 : (x, y) = (x, y) = (-31.3595, -31.3595)
//75 : (x, y) = (x, y) = (-24.5191, -24.5191)
//76 : (x, y) = (x, y) = (-35.703, -35.703)
//77 : (x, y) = (x, y) = (-18.3825, -18.3825)
//78 : (x, y) = (x, y) = (-16.9873, -16.9873)
//79 : (x, y) = (x, y) = (-24.802, -24.802)
//80 : (x, y) = (x, y) = (-28.6181, -28.6181)
//81 : (x, y) = (x, y) = (-20.8035, -20.8035)
//82 : (x, y) = (x, y) = (-35.8977, -35.8977)
//83 : (x, y) = (x, y) = (-51.6579, -51.6579)
//84 : (x, y) = (x, y) = (-46.1452, -46.1452)
//85 : (x, y) = (x, y) = (-59.2664, -59.2664)
//86 : (x, y) = (x, y) = (-48.668, -48.668)
//87 : (x, y) = (x, y) = (-52.1409, -52.1409)
//88 : (x, y) = (x, y) = (-53.5361, -53.5361)
//89 : (x, y) = (x, y) = (-73.533, -73.533)
//After 90steps, the subject has the following location :
//(x, y) = (-73.533, -73.533)
//or
//(m, a) = (103.991, -2.35619)
//Average outward distance per step = 1.15546
//0 : (x, y) = (x, y) = (15.7602, 15.7602)
//1 : (x, y) = (x, y) = (18.5437, 18.5437)
//2 : (x, y) = (x, y) = (31.6649, 31.6649)
//3 : (x, y) = (x, y) = (13.3939, 13.3939)
//4 : (x, y) = (x, y) = (28.021, 28.021)
//5 : (x, y) = (x, y) = (42.1632, 42.1632)
//6 : (x, y) = (x, y) = (52.7615, 52.7615)
//7 : (x, y) = (x, y) = (66.6547, 66.6547)
//8 : (x, y) = (x, y) = (80.2947, 80.2947)
//After 9steps, the subject has the following location :
//(x, y) = (80.2947, 80.2947)
//or
//(m, a) = (113.554, 0.785398)
//Average outward distance per step = 12.6171
//After 3 tests, the max steps = 90, the min steps = 9, the average steps = 38
//Bye.