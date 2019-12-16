

#ifndef _ARRAY_2D_H_
#define _ARRAY_2D_H_

#define W 5
#define H 12

#include "big_block.h"
#include <ctime>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class array_2d  {

	private :	
		int score;
		int x[4] = { 1,0,-1,0 };
		int y[4] = { 0,1,0,-1 };
	public : 
		static int block_array[H][W];
		array_2d();
		void print();
		int get_color(int x,  int y);
		void set_color(int x, int y, int color);
		
		bool can_make();
		big_block* make_bigblock(); 

		void set_score(int _s);
		int get_score();

		void search_explosion();
		void down_all();
		void explosion(vector<pair<int, int>> );
};

#endif
