#include <cmath>
#include <array>
#include "Board.hpp"
#include "doctest.h"
using namespace ariel;

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

const Direction HORI = Direction::Horizontal;
const Direction VER = Direction::Vertical;

// a func to get a random positive int
u_int getrandom(u_int min, u_int max){
	// just to be sure
	if(min > max){
		u_int temp = min;
		min = max;
		max = temp;
	}

	u_int i = rand() % 10;
	i %= 5;
	u_int k = pow(10, i);
	u_int r =(u_int) rand() % k;
	return r;
}

// a func to get a random string
string randString()
{
	u_int len = (u_int) (rand() % 20); 
	string s = "";
	for (size_t i = 0; i < len; i++)
	{
		s += (char)(65+ ( rand() % 57) );
	}
	return s;
	
}

// first of all we check a specific test
TEST_CASE("read right specfic"){
	ariel::Board b;
	b.post(0, 0, HORI, "abc");
	string sRead = b.read(0, 0, HORI, 4);

	string sComp = "abc_";
	for (size_t i = 0; i < 4; i++)
	{
		CHECK_EQ(sRead.at(i), sComp.at(i));
	}
	b.post(0, 5, HORI, "fghi ");
	sRead = b.read(0, 0, HORI, 10);
	sComp = "abc__fghi ";
	for (size_t i = 0; i < 10; i++)
	{
		CHECK_EQ(sRead.at(i), sComp.at(i));
	}

	b.post(2, 1, VER, "shani");
	sRead = b.read(0, 1, VER, 8);
	sComp = "b_shani_";
	for (size_t i = 0; i < 8; i++)
	{
		CHECK_EQ(sRead.at(i), sComp.at(i));
	}

	// to check drissa
	b.post(4, 0, HORI, " u");
	b.post(5, 0, HORI, "+v");
	sRead = b.read(2, 1, VER, 4);
	sComp = "shuv";
	for (size_t i = 0; i < 4; i++)
	{
		CHECK_EQ(sRead.at(i), sComp.at(i));
	}

}

TEST_CASE("read right random"){
	ariel::Board b;

	// 20 so the board won't be too big and it would take more time to read
	u_int rowSR = rand() % 20;
	u_int colSR = rand() % 15;

	u_int rowSC = rand() % 20;
	u_int colSC = rand() % 15;
	const u_int lengthS = 10; 

	std::array<char, 10> sr;
	std::array<char, 10> sc;
	for (size_t i = 0; i < lengthS; i++)
	{
		sr.at(i) = '_';
		sc.at(i) = '_';
	}


	for (size_t i = 0; i < lengthS; i++)
	{
		string t = randString();
		u_int rowT = getrandom( rand()%20, rand()%20);
		u_int colT =  getrandom( rand()%20, rand()%20);
        
        u_int d = rand() % 2;
        if(d == 0)
        {
            b.post(rowT, colT, HORI, t);
        }
        else
        {
            b.post(rowT, colT, VER, t);
        }
		

		if(d==0)
		{
			// starting row init
			if(rowSR == rowT)
			{
				//checks if start before our row string and there's hafifa beneihen
				if(colT <= colSR && colSR <= colT + t.length())
				{
					u_int copy_length;

					// if the temp ends before the original string
					if (colSR + lengthS >= colT + t.length())
					{
						copy_length = colT + t.length() - colSR;
					}

					// if the original string end before the
					else
					{
						copy_length = lengthS;
					}


					for (size_t i = 0; i < copy_length; i++)
					{
						sr.at(i) = t.at(i - colT + colSR);
					}
				}


				// if the temp start after the row string we would like to check
				// and if there's hafifa
				if(colSR + lengthS >= colT && colT >= colSR)
				{
					size_t copy_length;


					// if the temp string ends before the original string
					if(t.length() + colT <= lengthS + colSR)
					{
						copy_length = t.length();
					}

					else
					{
						copy_length = - colT + colSR + lengthS;
					}

					// if the temp ends after the og string
					for (size_t i = 0; i < copy_length; i++)
					{
						sr.at(i - colSR + colT) = t.at(i);
					}
				}
			}// done with row init
			if(colT <= colSC && colSC <= colT + t.length() && rowSC + lengthS >= rowT && rowT >= rowSC)
			{
				sc.at(rowT - rowSC) = t.at(colT - colSC);
			}
		} // end of if d==0

		if(d==1)
		{
			// start of row init
			if(rowT <= rowSR &&  rowSR <= rowT + t.length() && colSR +  lengthS >= colT && colT >= colSR)
			{
				sr.at(colT - colSR) = t.at(rowSR - rowT);
			}
			// end of init the row string

			// init for col string
			if(colSC == colT)
			{

				//checks if start before our row string and if there's hafifa beneihen
				if(rowT <= rowSC && rowSC <= rowT + t.length())
				{
					size_t copy_length;

					// if the temp ends before the original string
					if (rowSC + lengthS >= rowT + t.length())
					{
						copy_length = rowT + t.length() - rowSC;
					}

					// if the original string end before the
					else
					{
						copy_length = lengthS;
					}


					for (size_t i = 0; i < copy_length; i++)
					{
						sc.at(i) = t.at(i - rowT + rowSC);
					}
				}

				// if the temp start after the row string we would like to check
				// and if there's hafifa
				if(rowSC + lengthS >= rowT && rowT >= rowSC)
				{
					size_t copy_length;


					// if the temp string ends before the original string
					if(t.length() + rowT <= lengthS + rowSC){
						copy_length = t.length();
					}

					else{
						copy_length = rowT - rowSC + lengthS;
					}

					// if the temp ends after the og string
					for (size_t i = 0; i < copy_length; i++)
					{
						sc.at(i - rowSC + rowT) = t.at(i);
					}
				}
            }
            // end of init the col string
        } // end of if d==1


		string srComp = b.read(rowSR, colSR, HORI, lengthS);
		string scComp = b.read(rowSC, colSC, VER, lengthS);
		for (size_t i = 0; i < lengthS; i++)
		{
			CHECK_EQ(sr.at(i), srComp.at(i));
			CHECK_EQ(sc.at(i), scComp.at(i));
		}
    }// end of for

    // string srComp = b.read(rowSR, colSR, HORI, lengthS);
    // string scComp = b.read(rowSC, colSC, VER, lengthS);
    // for (size_t i = 0; i < lengthS; i++)
    // {
    //     CHECK_EQ(sr.at(i), srComp.at(i));
    //     CHECK_EQ(sc.at(i), scComp.at(i));
    // }
}   