

#include "big_block.h"

#ifndef _FOLD_BLOCK_H_
#define _FOLD_BLOCK_H_
class fold_block : public big_block {
	private :
		int state;
	public :
		fold_block(int c1, int c2, int c3);
		bool can_left();
		bool can_right();
		bool can_down();


		void left();
		void right();
		void down();
		void down_all();

		void clock_rotate();
		void nonclock_rotate();


};
#endif
