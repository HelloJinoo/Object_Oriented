#include "array_2d.h"
#include "big_block.h"
#include <iostream>
#include <stdio.h>
using namespace std;

array_2d *a;
big_block* big_block::b;
int main(){
	
	a = new array_2d();
	char ch;
	bool nomake_flag = false;	
	bool can_make_ = a->can_make();
	while( a->can_make()){	
		big_block::b = a->make_bigblock();
		
		std::cout << " ********** CURRENT-SCORE = " << a->get_score() << " ************" << std::endl;
		a->print();
		std::cout << std::endl;
		bool down_flag = (big_block::b->can_down() || big_block::b->can_left() || big_block::b->can_right());
		bool x_flag = false;
		while(down_flag){
		
			std::cout << "---------> INPUT : ";
			ch = getchar();
			std::cout << std::endl;

			if( ch == 'd'){
				big_block::b->right();	

			}	
			else if( ch == 'a'){
				big_block::b->left();	
			}		
			else if( ch == 'x' ){
				big_block::b->down_all();	
				x_flag = true;			
			}	
			else if( ch == 'e') {
				big_block::b->clock_rotate();	
			}
			else if( ch == 'q'){
				big_block::b->nonclock_rotate();	
			}
			else if( ch == 's'){
				big_block::b->down();
			}
			else{
				std::cout << "WARNING : no correct input \n" << std::endl;
			}

			if(x_flag || big_block::b->bot == 1){
				down_flag = false;
			}
			else{
				down_flag =  (big_block::b->can_down() ||big_block::b->can_left() || big_block::b->can_right());
			}
			if(down_flag){
				
				std::cout << " ********** CURRENT-SCORE = " << a->get_score() << " *************" << std::endl;
				a->print();
				std::cout << std::endl;
			}
			getchar();

		}
		a->down_all();

				
		
		
	};
	
	std::cout << std::endl;
	a->print();
	std::cout << std::endl;
	std::cout << "====================RESULT=================" << std::endl;
	std::cout << " -THE END- \n TOTAL-SCORE = " << a->get_score()  << std::endl;


	return 0;
}
