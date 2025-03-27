#ifndef PLAYER_H
#define PLAYER_H

#include <string_view>
#include <iostream>
#include "person.h"

// class Person;  // Forward declaration.

class Player : public Person {

    // OUTPUT Stream Operator
    friend std::ostream& operator<<(std::ostream& out, const Player& player){
        out << "Playing = [ game : " << player.m_game << ", names : " << player.get_first_name() << " " << player.get_last_name() << "]";
        return out;
    };

    public :
        Player() = default;
        Player(std::string_view game_param, std::string_view f_name_param, std::string_view l_name_param)
            // : m_game{game_param}, first_name{f_name_param}, last_name{l_name_param}     //  Only if this class variables are from this class then you can use this method
            {
                // *****     Declearation on the Protected Basic Variables
                // first_name = "f_name_param";
                // last_name = "l_name_param";
                
                m_game = game_param;
                first_name = f_name_param;
                last_name = l_name_param;
            };
        ~Player(){};

        // Getters

    private :
        std::string m_game{"None"};
};

#endif