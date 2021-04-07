#include <iostream>
#include "Board.hpp"
#include <map>
// using namespace ariel;

namespace ariel
{
    void Board::post(uint row, uint col, ariel::Direction direction, string message_post)
    {
        if(message_post.empty()){
            return ;
        }
        // this->init_Iboard(row , col);

        uint message_size = message_post.length();
        switch(direction){
            case Direction::Horizontal :
            
            for(uint i=0 ; i < message_size ; i++){
                this->board[row][col]=message_post.at(i);
                col++;
            }
            break;
            
            case Direction::Vertical :
          
            for(uint i=0 ; i < message_size ; i++){
                this->board[row][col]=message_post.at(i);
                row++;
            }
            break;
        }
    }

    string Board::read(uint row, uint col, ariel::Direction direction, uint char_size)
    {
        if(char_size==0) {
            return "";
        }
        string post ;
        switch(direction){
            case Direction :: Horizontal :
            for(uint i =0 ; i<char_size ; i++){
                if (this->board[row][col]==0){
                    post+="_";
                }
                else{
                    post+=board[row][col];
                }
                col++;

            } 
            break;

            case Direction :: Vertical :
            for(uint i =0 ; i<char_size ; i++){
                if(this->board[row][col]==0)
                    post+="_";
                else{
                    post+=this->board[row][col];
                }
                row++;
                

            } 
            break;
        }

        return post;
    }


    void Board::show()
    {
        for (auto t : board) {
            cout << t.first << ":" ;
            for (auto t1 : t.second){
                //  cout << t.first << ":" << t1.first << " -> " << t1.second ;
                cout  << t1.second ;

            }    
            cout << endl ;
        }
    }
 
    Board :: Board( ){
        uint max_row=0;
        uint max_col=0;
      
    };
    Board :: ~Board(){

    };

}