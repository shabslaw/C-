// FOR MICROSOFT VIRSUAL STUDIO
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <memory>
#include <random>
#include <chrono>
#include <thread>

using namespace std;

enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };

class cBall {
private:
    int x, y;
    int originalX, originalY;
    eDir direction;
    static mt19937 gen;

public:
    cBall(int posX, int posY) {
        originalX = posX;
        originalY = posY;
        x = posX;
        y = posY;
        direction = STOP;
    }

    void Reset() {
        x = originalX;
        y = originalY;
        direction = STOP;
    }

    void changeDirection(eDir d) {
        direction = d;
    }

    void randomDirection() {
        uniform_int_distribution<int> dist(1, 6);
        direction = (eDir)dist(gen);
    }

    int getX() const { return x; }
    int getY() const { return y; }
    eDir getDirection() const { return direction; }

    void Move() {
        switch (direction) {
        case STOP: break;
        case LEFT: x--; break;
        case RIGHT: x++; break;
        case UPLEFT: x--; y--; break;
        case DOWNLEFT: x--; y++; break;
        case UPRIGHT: x++; y--; break;
        case DOWNRIGHT: x++; y++; break;
        }
    }

    friend ostream& operator<<(ostream& out, const cBall& c) {
        out << "Ball [" << c.x << "," << c.y << "][" << c.direction << "]";
        return out;
    }
};

// Initialize static random generator
mt19937 cBall::gen(random_device{}());

class cPaddle {
private:
    int x, y;
    int originalX, originalY;

public:
    cPaddle() : x(0), y(0), originalX(0), originalY(0) {}
    cPaddle(int posX, int posY) : x(posX), y(posY), originalX(posX), originalY(posY) {}

    void Reset() { x = originalX; y = originalY; }
    int getX() const { return x; }
    int getY() const { return y; }
    void moveUp() { y--; }
    void moveDown() { y++; }

    friend ostream& operator<<(ostream& out, const cPaddle& c) {
        out << "Paddle [" << c.x << "," << c.y << "]";
        return out;
    }
};

class cGameManager {
private:
    int width, height;
    int score1, score2;
    char up1, down1, up2, down2;
    bool quit;
    unique_ptr<cBall> ball;
    unique_ptr<cPaddle> player1;
    unique_ptr<cPaddle> player2;

    void clearScreen() {
        system("cls");
    }

public:
    cGameManager(int w, int h) : width(w), height(h), score1(0), score2(0),
        up1('w'), down1('s'), up2('o'), down2('l'), quit(false) {
        ball.reset(new cBall(w / 2, h / 2));
        player1.reset(new cPaddle(1, h / 2 - 3));
        player2.reset(new cPaddle(w - 2, h / 2 - 3));
    }

    void ScoreUp(const unique_ptr<cPaddle>& player) {
        if (player == player1) score1++;
        else if (player == player2) score2++;

        ball->Reset();
        player1->Reset();
        player2->Reset();
    }

    void Draw() {
        clearScreen();

        // Draw top border
        for (int i = 0; i < width + 2; i++)
            cout << "\xB2";
        cout << endl;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                int ballx = ball->getX();
                int bally = ball->getY();
                int player1x = player1->getX();
                int player2x = player2->getX();
                int player1y = player1->getY();
                int player2y = player2->getY();

                if (j == 0)
                    cout << "\xB2";

                if (ballx == j && bally == i)
                    cout << "O";
                else if (player1x == j && (i >= player1y && i <= player1y + 3))
                    cout << "\xDB";
                else if (player2x == j && (i >= player2y && i <= player2y + 3))
                    cout << "\xDB";
                else
                    cout << " ";

                if (j == width - 1)
                    cout << "\xB2";
            }
            cout << endl;
        }

        // Draw bottom border
        for (int i = 0; i < width + 2; i++)
            cout << "\xB2";
        cout << endl;

        cout << "Player 1: " << score1 << " | Player 2: " << score2 << endl;
    }

    void Input() {
        ball->Move();

        if (_kbhit()) {
            char current = _getch();
            int player1y = player1->getY();
            int player2y = player2->getY();

            if (current == up1 && player1y > 0)
                player1->moveUp();
            if (current == down1 && player1y + 4 < height)
                player1->moveDown();
            if (current == up2 && player2y > 0)
                player2->moveUp();
            if (current == down2 && player2y + 4 < height)
                player2->moveDown();

            if (ball->getDirection() == STOP)
                ball->randomDirection();

            if (current == 'q')
                quit = true;
        }
    }

    void Logic() {
        int ballx = ball->getX();
        int bally = ball->getY();
        int player1x = player1->getX(), player1y = player1->getY();
        int player2x = player2->getX(), player2y = player2->getY();

        // Paddle collisions
        if (ballx == player1x + 1 && bally >= player1y && bally <= player1y + 3)
            ball->changeDirection((eDir)((rand() % 3) + 4));

        if (ballx == player2x - 1 && bally >= player2y && bally <= player2y + 3)
            ball->changeDirection((eDir)((rand() % 3) + 1));

        // Wall collisions
        if (bally == height - 1)
            ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);

        if (bally == 0)
            ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);

        // Scoring
        if (ballx == width - 1) ScoreUp(player1);
        if (ballx == 0) ScoreUp(player2);
    }

    void Run() {
        while (!quit) {
            Draw();
            Input();
            Logic();
            this_thread::sleep_for(chrono::milliseconds(50));
        }
    }
};

int main() {
    // Set random seed
    srand(static_cast<unsigned>(time(nullptr)));

    cGameManager game(40, 20);
    game.Run();

    return 0;
}
