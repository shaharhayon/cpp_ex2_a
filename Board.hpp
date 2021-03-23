#include "Direction.hpp"
#include <string>
#include <iostream>

namespace ariel
{
    class Board
    {


    public:
        std::string read(u_int row, u_int column, Direction direction, u_int length);
        int post(u_int row, u_int column, Direction direction, std::string message);
        void show();
    };
}