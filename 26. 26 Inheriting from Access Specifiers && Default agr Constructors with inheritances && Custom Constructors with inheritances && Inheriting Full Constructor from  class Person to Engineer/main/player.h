#ifndef PLAYER_H
#define PLAYER_H

#include <string_view>
#include <iostream>
#include "person.h"

// class Person;  // Forward declaration.

class Player : private Person {

    // OUTPUT Stream Operator
    friend std::ostream& operator<<(std::ostream& out, const Player& player){
        out << "Playing = [ game : " << player.m_game << ", names : " << player.get_first_name() << " " << player.get_last_name() << "]";
        return out;
    };

    public :
        Player() = default;
        Player(std::string first_name_param, std::string last_name_param, std::string game_param){
            first_name = first_name_param;
            last_name = last_name_param;
            m_game = game_param;
        }
        ~Player(){};

    protected :
        using Person::get_first_name;
        using Person::get_last_name;

        // Getters

    public :
        using Person::first_name;
        using Person::last_name;

        std::string m_game{"None"};
};

#endif