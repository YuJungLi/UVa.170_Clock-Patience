#include <iostream>
#include <iomanip>
#include <string>
#pragma warning( disable : 4996 )
using namespace std;

int main()
{
	freopen("Input.txt", "rt", stdin);
	freopen("Output.txt", "w+t", stdout);
	while (1)
	{
		char card[52][2];
		int face_down[13] = { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3 };
		cin >> card[51][0];
		if (card[51][0] == '#')
			break;
		cin >> card[51][1];
		for (int i = 50; i >= 0; i--)
		{
			cin >> card[i][0];
			cin >> card[i][1];
		}
		int step = 51, cnt = 1;
		while (1)
		{
			int next = card[step][0] - '0';
			switch (next)
			{
				case 17:	next = 1;	break;
				case 36:	next = 10;	break;
				case 26:	next = 11;	break;
				case 33:	next = 12;	break;
				case 27:	next = 13;	break;
				default:	next = next;
			}
			if (face_down[next - 1] == 0)
				break;
			step = (face_down[next - 1] - 1) * 13 + next - 1;
			face_down[next - 1]--;
			cnt++;
		}
		if (cnt < 10)
			cout << 0;
		cout << cnt << "," << card[step][0] << card[step][1] << endl;
	}
	return 0;
}