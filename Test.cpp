#include "doctest.h"
#include "Board.hpp"
#include <climits>
using namespace ariel;
using namespace std;

TEST_CASE("THROWS")
{
    Board board;
    CHECK_NOTHROW(board.post(0, 0, Direction::Horizontal, "abcde"));
    CHECK_NOTHROW(board.post(0, 0, Direction::Vertical, "abcdefghij"));
    CHECK_NOTHROW(board.read(0, 0, Direction::Horizontal, 5));
    CHECK_NOTHROW(board.read(0, 0, Direction::Vertical, 10));
    CHECK_NOTHROW(board.read(57, 25, Direction::Horizontal, 5));
    CHECK_NOTHROW(board.read(32, 48, Direction::Vertical, 10));
    CHECK_NOTHROW(board.show());
}

TEST_CASE("NORMAL TESTS")
{
    Board board;
    string a = string("ABCDE");
    string b = string("0123456789");
    string c = string("ASDFGHJK");
    string d = string("ZXCVBNM<");
    string e = string("QWERTYUIOP");
    string f = string("QAZWSXEDC");
    string g = string("!@#$%^&*()_+");
    string empty12 = string("____________");

    //random locations
    CHECK(board.post(50, 50, Direction::Horizontal, a) == 0);
    CHECK(board.read(50, 50, Direction::Horizontal, a.size()) == a);
    CHECK(board.post(80, 80, Direction::Vertical, b) == 0);
    CHECK(board.read(80, 80, Direction::Vertical, b.size()) == b);

    //edge locations
    CHECK(board.post(0, 0, Direction::Horizontal, c) == 0);
    CHECK(board.read(0, 0, Direction::Horizontal, c.size()) == c);
    CHECK(board.post(0, 0, Direction::Vertical, d) == 0);
    CHECK(board.read(0, 0, Direction::Vertical, d.size()) == d);

    CHECK(board.post(UINT_MAX, UINT_MAX - e.size(), Direction::Horizontal, e) == 0);
    CHECK(board.read(UINT_MAX, UINT_MAX - e.size(), Direction::Horizontal, e.size()) == e);
    CHECK(board.post(UINT_MAX - f.size(), UINT_MAX, Direction::Vertical, f) == 0);
    CHECK(board.read(UINT_MAX - f.size(), UINT_MAX, Direction::Vertical, f.size()) == f);

    //test change
    CHECK(board.read(100, 100, Direction::Horizontal, g.size()) == empty12);
    CHECK(board.post(100, 100, Direction::Horizontal, g) == 0);
    CHECK(board.read(100, 100, Direction::Horizontal, g.size()) == g);
}
