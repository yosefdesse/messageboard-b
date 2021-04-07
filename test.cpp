#define CHECK DOCTEST_CHECK
#include "doctest.h"
using namespace doctest;
#include <iostream>




#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;
// using ariel::Board ;
using namespace ariel ;





TEST_CASE("Good board") {
    Board board ;
    board.post(/*row=*/100, /*column=*/200, Direction::Horizontal, "yosefdese") ;
    CHECK( board.read(/*row=*/100, /*column=*/200, Direction::Horizontal, /*length=*/2)== "yo" );
    CHECK( board.read(/*row=*/100, /*column=*/201, Direction::Horizontal, /*length=*/1)== "y" );
    CHECK( board.read(/*row=*/100, /*column=*/200, Direction::Horizontal, /*length=*/5)== "yosef" );
    CHECK( board.read(/*row=*/100, /*column=*/200, Direction::Horizontal, /*length=*/3)== "yos" );
    CHECK( board.read(/*row=*/100, /*column=*/200, Direction::Horizontal, /*length=*/9)== "yosefdese" );

    board.post(/*row=*/60, /*column=*/100, Direction::Vertical, "hello") ;
    CHECK( board.read(/*row=*/60, /*column=*/100, Direction::Vertical, /*length=*/1)== "h" );
    CHECK( board.read(/*row=*/60, /*column=*/100, Direction::Vertical, /*length=*/1)== "he" );
    CHECK( board.read(/*row=*/60, /*column=*/100, Direction::Vertical, /*length=*/5)== "hello" );
    CHECK( board.read(/*row=*/60, /*column=*/100, Direction::Vertical, /*length=*/6)== "hello_" );
    CHECK( board.read(/*row=*/60, /*column=*/98, Direction::Vertical, /*length=*/9)== "__hello__" );

    board.post(/*row=*/230, /*column=*/120, Direction::Horizontal, "abcdefgh") ;
    CHECK( board.read(/*row=*/230, /*column=*/120, Direction::Horizontal, /*length=*/1)== "a" );
    CHECK( board.read(/*row=*/230, /*column=*/120, Direction::Horizontal, /*length=*/2)== "ab" );
    CHECK( board.read(/*row=*/230, /*column=*/120, Direction::Horizontal, /*length=*/3)== "abc" );
    CHECK( board.read(/*row=*/230, /*column=*/120, Direction::Horizontal, /*length=*/4)== "abcd" );
    CHECK( board.read(/*row=*/230, /*column=*/120, Direction::Horizontal, /*length=*/5)== "abcde" );
    CHECK( board.read(/*row=*/230, /*column=*/120, Direction::Horizontal, /*length=*/6)== "abcdef" );
    CHECK( board.read(/*row=*/230, /*column=*/120, Direction::Horizontal, /*length=*/7)== "abcdefg" );
    CHECK( board.read(/*row=*/230, /*column=*/120, Direction::Horizontal, /*length=*/8)== "abcdefgh" );


    board.post(/*row=*/500, /*column=*/300, Direction::Horizontal, "newboard") ;
    CHECK( board.read(/*row=*/500, /*column=*/300, Direction::Horizontal, /*length=*/2)== "ne" );
    CHECK( board.read(/*row=*/500, /*column=*/300, Direction::Horizontal, /*length=*/1)== "n" );
    CHECK( board.read(/*row=*/500, /*column=*/300, Direction::Horizontal, /*length=*/5)== "newbo" );
    CHECK( board.read(/*row=*/500, /*column=*/300, Direction::Horizontal, /*length=*/3)== "new" );
    CHECK( board.read(/*row=*/500, /*column=*/300, Direction::Horizontal, /*length=*/9)== "newboard_" );




}