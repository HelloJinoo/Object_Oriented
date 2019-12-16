#ifndef BIG_BLOCK_H
#define BIG_BLOCK_H

class big_block{
	protected :
		int W_index, H_index;
		int x[4] = { 1,0,-1,0 };
		int y[4] = { 0,1,0,-1 };
		int x_anticlock[4] = {1, 0, -1, 0};
		int y_anticlock[4] = {0, -1, 0, 1};

	public :
		enum _type{
			FOLD, TREE, CROSS
		};

		static big_block* b;
		int bot = 1;	
		big_block();
		virtual bool can_left() = 0;
		virtual bool can_right() =0;
		virtual bool can_down() = 0;


		virtual void left() = 0;
		virtual void right() = 0;
		virtual void down() = 0;
		virtual void down_all() = 0;

		virtual void clock_rotate() = 0;
		virtual void nonclock_rotate() = 0;



	
};
#endif
