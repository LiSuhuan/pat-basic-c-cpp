#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct School {
    string abbreviation;
    int teamCount;
};

int main()
{
    int schoolCount, capacity;
    cin >> schoolCount >> capacity;
    int totalRooms = 0;

    priority_queue<int> remainingPlayers;
    vector<School> schools(schoolCount);

    for (int i = 0; i < schoolCount; i++)
    {
        cin >> schools[i].abbreviation >> schools[i].teamCount;
        cout << schools[i].abbreviation << " " << (schools[i].teamCount + capacity - 1) / capacity << endl;
        totalRooms += schools[i].teamCount / capacity;
        if (schools[i].teamCount % capacity != 0)
            remainingPlayers.push(schools[i].teamCount % capacity);
    }

    vector<int> rooms;
    while (!remainingPlayers.empty())
    {
        int players = remainingPlayers.top();
        remainingPlayers.pop();
        bool assigned = false;
        for (int i = 0; i < rooms.size(); i++)
        {
            if (players <= capacity - rooms[i])
            {
                assigned = true;
                rooms[i] += players;
                break;
            }
        }
        if (!assigned)
        {
            rooms.push_back(players);
            totalRooms++;
        }
    }

    cout << totalRooms;

    return 0;
}
