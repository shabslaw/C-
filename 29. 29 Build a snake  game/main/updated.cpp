#include <iostream>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <random>
#include <chrono>

using namespace std;

class SnakeGame {
private:
    struct Position {
        int x, y;
        bool operator==(const Position& other) const {
            return x == other.x && y == other.y;
        }
    };

    bool gameOver;
    const int width;
    const int height;
    Position head;
    Position fruit;
    int score;
    vector<Position> tail;
    
    enum class Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
    Direction dir;

    mt19937 gen;

public:
    SnakeGame(int w, int h) : width(w), height(h), gameOver(false), dir(Direction::STOP), score(0) {
        // Initialize random number generator
        random_device rd;
        gen.seed(rd());
        
        Setup();
    }

    void Setup() {
        gameOver = false;
        dir = Direction::STOP;
        head = {width / 2, height / 2};
        spawnFruit();
        score = 0;
        tail.clear();
    }

    void spawnFruit() {
        uniform_int_distribution<int> distX(0, width - 1);
        uniform_int_distribution<int> distY(0, height - 1);
        fruit = {distX(gen), distY(gen)};
        
        // Make sure fruit doesn't spawn on snake
        while (fruit == head || find(tail.begin(), tail.end(), fruit) != tail.end()) {
            fruit = {distX(gen), distY(gen)};
        }
    }

    void Draw() {
        system("cls");

        // Draw top border
        cout << string(width + 2, '#') << endl;

        for (int y = 0; y < height; y++) {
            cout << "#"; // Left border
            
            for (int x = 0; x < width; x++) {
                Position current{x, y};
                
                if (current == head) {
                    cout << "O";
                } else if (current == fruit) {
                    cout << "F";
                } else {
                    bool isTailSegment = false;
                    for (const auto& segment : tail) {
                        if (current == segment) {
                            cout << "o";
                            isTailSegment = true;
                            break;
                        }
                    }
                    if (!isTailSegment) {
                        cout << " ";
                    }
                }
            }
            
            cout << "#" << endl; // Right border
        }

        // Draw bottom border
        cout << string(width + 2, '#') << endl;
        cout << "Score: " << score << endl;
    }

    void Input() {
        if (_kbhit()) {
            switch (_getch()) {
                case 'a': dir = Direction::LEFT; break;
                case 'd': dir = Direction::RIGHT; break;
                case 'w': dir = Direction::UP; break;
                case 's': dir = Direction::DOWN; break;
                case 'x': gameOver = true; break;
                case 'r': Setup(); break; // Reset game
            }
        }
    }

    void Logic() {
        if (dir == Direction::STOP) return;

        // Save previous head position
        Position prev = head;

        // Move head
        switch (dir) {
            case Direction::LEFT:  head.x--; break;
            case Direction::RIGHT: head.x++; break;
            case Direction::UP:    head.y--; break;
            case Direction::DOWN:  head.y++; break;
        }

        // Wrap around screen edges
        if (head.x >= width) head.x = 0;
        else if (head.x < 0) head.x = width - 1;
        if (head.y >= height) head.y = 0;
        else if (head.y < 0) head.y = height - 1;

        // Check for collision with tail
        for (const auto& segment : tail) {
            if (head == segment) {
                gameOver = true;
                return;
            }
        }

        // Move tail
        if (!tail.empty()) {
            Position prev2;
            for (auto& segment : tail) {
                prev2 = segment;
                segment = prev;
                prev = prev2;
            }
        }

        // Check for fruit collision
        if (head == fruit) {
            score += 10;
            spawnFruit();
            // Add new tail segment at the end
            if (tail.empty()) {
                tail.push_back(prev);
            } else {
                tail.push_back(tail.back());
            }
        }
    }

    void Run() {
        cout << "Snake Game! (WASD to move, X to quit, R to reset)" << endl;

        auto lastTime = chrono::steady_clock::now();
        const chrono::milliseconds frameDelay(100); // ~10 FPS

        while (!gameOver) {
            auto currentTime = chrono::steady_clock::now();
            auto elapsed = currentTime - lastTime;

            if (elapsed >= frameDelay) {
                Draw();
                Input();
                Logic();
                lastTime = currentTime;
            }
        }

        cout << "Game Over! Final Score: " << score << endl;
    }
};

int main() {
    SnakeGame game(20, 20);
    game.Run();
    return 0;
}