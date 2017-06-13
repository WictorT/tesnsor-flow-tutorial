#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int width;
    int height;
    int myId;
    cin >> width >> height >> myId; cin.ignore();

    // game loop
    while (1) {

        string map[100]; 

        for (int i = 0; i < height; i++) {
            cin >> map[i]; cin.ignore();
        }

        int entityType[100];
        int owner[100];
        int x[100];
        int y[100];
        int param1[100];
        int param2[100];

        int entities;
        cin >> entities; cin.ignore();
        for (int i = 0; i < entities; i++) {
            cin >> entityType[i] >> owner[i] >> x[i] >> y[i] >> param1[i] >> param2[i]; cin.ignore();
        }


        int minDist = 999;
        int minX;
        int minY;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                int dist = abs(i - y[myId]) + (j - x[myId]);
                if (dist < minDist && map[i][j] == '0') {
                    minDist = dist;
                    minX = j;
                    minY = i;
                }
            }
        }

        if (minDist > 1) {
            cout << "MOVE ";
        } else {
            cout << "BOMB ";
        }
        cout << minX << " " << minY << endl;
    }
}