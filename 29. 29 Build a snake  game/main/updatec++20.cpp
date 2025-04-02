#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <thread>
#include <concepts>
#include <ranges>
#include <algorithm>
#include <string_view>

using namespace std::chrono_literals;

class SnakeGame {
private:
    struct Position {
        int x{};
        int y{};
        
        constexpr bool operator==(const Position&) const = default;
        
        constexpr Position& wrap(int width, int height) {
            x = (x + width) % width;
            y = (y + height) % height;
            return *this;
        }
    };

    static constexpr int DEFAULT_WIDTH = 20;
    static constexpr int DEFAULT_HEIGHT = 20;
    static constexpr std::string_view CONTROLS = 
        "Controls: WASD to move, X to quit, R to reset";

    bool game_over{false};
    const int width;
    const int height;
    Position head;
    Position fruit;
    int score{0};
    std::vector<Position> tail;
    
    enum class Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
    Direction dir{Direction::STOP};

    std::mt19937 gen;
    std::uniform_int_distribution<int> dist_x;
    std::uniform_int_distribution<int> dist_y;

public:
    explicit SnakeGame(int w = DEFAULT_WIDTH, int h = DEFAULT_HEIGHT) 
        : width(w), height(h), dist_x(0, width - 1), dist_y(0, height - 1) {
        // Initialize random number generator
        std::random_device rd;
        gen.seed(rd());
        
        setup();
    }

    void setup() {
        game_over = false;
        dir = Direction::STOP;
        head = {width / 2, height / 2};
        spawn_fruit();
        score = 0;
        tail.clear();
    }

    void spawn_fruit() {
        do {
            fruit = {dist_x(gen), dist_y(gen)};
        } while (fruit == head || std::ranges::contains(tail, fruit));
    }

    void draw() const {
        // Clear screen (platform specific, consider alternatives for production)
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif

        // Draw top border
        std::cout << std::string(width + 2, '#') << '\n';

        for (int y = 0; y < height; ++y) {
            std::cout << '#'; // Left border
            
            for (int x = 0; x < width; ++x) {
                const Position current{x, y};
                
                if (current == head) {
                    std::cout << 'O';
                } else if (current == fruit) {
                    std::cout << 'F';
                } else if (std::ranges::contains(tail, current)) {
                    std::cout << 'o';
                } else {
                    std::cout << ' ';
                }
            }
            
            std::cout << "#\n"; // Right border
        }

        // Draw bottom border
        std::cout << std::string(width + 2, '#') << '\n'
                  << "Score: " << score << '\n'
                  << CONTROLS << '\n';
    }

    void process_input() {
        if (_kbhit()) {
            switch (_getch()) {
                case 'a': dir = Direction::LEFT;  break;
                case 'd': dir = Direction::RIGHT; break;
                case 'w': dir = Direction::UP;    break;
                case 's': dir = Direction::DOWN;  break;
                case 'x': game_over = true;       break;
                case 'r': setup();                 break;
            }
        }
    }

    void update() {
        if (dir == Direction::STOP) return;

        // Save previous head position
        Position prev = head;

        // Move head based on direction
        switch (dir) {
            case Direction::LEFT:  head.x--; break;
            case Direction::RIGHT: head.x++; break;
            case Direction::UP:    head.y--; break;
            case Direction::DOWN:  head.y++; break;
        }

        // Wrap around screen edges
        head.wrap(width, height);

        // Check for collision with tail
        if (std::ranges::contains(tail, head)) {
            game_over = true;
            return;
        }

        // Move tail segments
        if (!tail.empty()) {
            for (auto it = tail.rbegin(); it != tail.rend() - 1; ++it) {
                *it = *(it + 1);
            }
            tail.front() = prev;
        }

        // Check for fruit collision
        if (head == fruit) {
            score += 10;
            spawn_fruit();
            // Add new tail segment
            tail.push_back(tail.empty() ? prev : tail.back());
        }
    }

    void run() {
        std::cout << "Snake Game!\n" << CONTROLS << "\n\n";

        auto last_time = std::chrono::steady_clock::now();
        constexpr auto frame_delay = 100ms; // ~10 FPS

        while (!game_over) {
            auto current_time = std::chrono::steady_clock::now();
            auto elapsed = current_time - last_time;

            if (elapsed >= frame_delay) {
                draw();
                process_input();
                update();
                last_time = current_time;
            }
            
            std::this_thread::sleep_for(1ms); // Reduce CPU usage
        }

        std::cout << "\nGame Over! Final Score: " << score << '\n';
    }
};

int main() {
    SnakeGame game;
    game.run();
    return 0;
}