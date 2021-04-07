
#pragma once
#include <iostream>
#include "Direction.hpp"
#include <map> 
#include <string>

using namespace std;
typedef unsigned int uint;

namespace ariel
{
    class Board
    {
    public:
        map<uint ,map<uint,char>> board;
        // std::map<std::string, int> m;
        uint max_row=0;
        uint max_col=0;
        uint min_row=0;
        uint min_col=0;
       
   
        // string s;
        Board();
        ~Board();
        void post(uint row, uint col, ariel::Direction direction, string message_post);
        string read(uint row, uint col, ariel::Direction direction, uint size);
        void show();
        void init_Iboard(uint row , uint col);
    };

}