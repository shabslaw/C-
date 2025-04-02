#include <iostream>
#include <deque>
#include <vector>
#include <conio.h>
#include <chrono>
#include <thread>

using namespace std;

class cPlayer {
public:
    int x, y;
    cPlayer(int width) : x(width / 2), y(0) {}
};

class cLane {
private:
    deque<bool> cars;
    bool right;
    int width;

public:
    cLane(int w) : width(w), right(rand() % 2) {
        for (int i = 0; i < width; i++)
            cars.push_back(rand() % 5 == 0); // 20% chance of a car
    }

    void Update() {
        if (right) {
            cars.pop_back();
            cars.push_front(rand() % 5 == 0); // Add new car at front
        } else {
            cars.pop_front();
            cars.push_back(rand() % 5 == 0); // Add new car at back
        }
    }

    bool CheckCollision(int pos) const { return cars[pos]; }
    void ChangeDirection() { right = !right; }
};

class cGame {
private:
    bool quit;
    int width, height, score;
    cPlayer* player;
    vector<cLane*> lanes;
    chrono::steady_clock::time_point lastTime;

public:
    cGame(int w = 20, int h = 10) : width(w), height(h), quit(false), score(0) {
        player = new cPlayer(width);
        for (int i = 0; i < height; i++)
            lanes.push_back(new cLane(width));
        lastTime = chrono::steady_clock::now();
    }

    ~cGame() {
        delete player;
        for (auto lane : lanes) delete lane;
    }

    void Draw() {
        system("cls");
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i == 0 && (j == 0 || j == width - 1)) cout << "S";
                else if (i == height - 1 && (j == 0 || j == width - 1)) cout << "F";
                else if (lanes[i]->CheckCollision(j) && i != 0 && i != height - 1) cout << "#";
                else if (player->x == j && player->y == i) cout << "V";
                else cout << " ";
            }
            cout << endl;
        }
        cout << "Score: " << score << endl;
    }

    void Input() {
        if (_kbhit()) {
            switch (_getch()) {
                case 'a': player->x = max(0, player->x - 1); break;
                case 'd': player->x = min(width - 1, player->x + 1); break;
                case 'w': player->y = max(0, player->y - 1); break;
                case 's': player->y = min(height - 1, player->y + 1); break;
                case 'q': quit = true; break;
            }
        }
    }

    void Logic() {
        auto now = chrono::steady_clock::now();
        float deltaTime = chrono::duration<float>(now - lastTime).count();
        lastTime = now;

        // Update lanes (cars move automatically)
        for (int i = 1; i < height - 1; i++) {
            lanes[i]->Update();
            if (lanes[i]->CheckCollision(player->x) && player->y == i)
                quit = true;
        }

        // Score increase when reaching the finish line
        if (player->y == height - 1) {
            score++;
            player->y = 0;
            lanes[rand() % height]->ChangeDirection();
        }
    }

    void Run() {
        while (!quit) {
            Input();
            Logic();
            Draw();
            this_thread::sleep_for(chrono::milliseconds(100)); // Control game speed
        }
        cout << "Game Over! Final Score: " << score << endl;
    }
};

int main() {
    srand(time(NULL));
    cGame game(30, 10);
    game.Run();
    return 0;
}