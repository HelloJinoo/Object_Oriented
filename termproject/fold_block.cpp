
#include "fold_block.h"
#include "array_2d.h"

fold_block::fold_block(int c1, int c2, int c3){

	array_2d::block_array[H_index][W_index] = c1;
	array_2d::block_array[H_index-1][W_index] = c2;
	array_2d::block_array[H_index][W_index-1] = c3;
	state = 0;
	bot = 0;
}


bool fold_block::can_left() {
	if (state == 0 && W_index - 2 >= 0 && array_2d::block_array[H_index][W_index-2] == 0 ) {
		return true;
	}
	else if (state == 1 && W_index -1 >= 0 && array_2d::block_array[H_index][W_index-1] == 0 && array_2d::block_array[H_index-1][W_index-1] == 0 ) {
		return true;
	}
	else if (state == 2 && W_index - 1 >= 0 && array_2d::block_array[H_index][W_index-1] == 0 && array_2d::block_array[H_index+1][W_index-1] == 0 ) {
		return true;
	}
	else if (state == 3 && W_index -2 >= 0 && array_2d::block_array[H_index][W_index-2] == 0 && array_2d::block_array[H_index+1][W_index-1] == 0 ) {
		return true;
	}
	return false;
}

bool fold_block::can_right(){
	if (state == 0 && W_index+1 < W && array_2d::block_array[H_index][W_index+1] == 0 ) {
		return true;
	}
	else if (state == 1 && W_index+ 2 < W && array_2d::block_array[H_index][W_index+2] == 0) {
		return true;
	}
	else if (state == 2 && W_index + 2 < W && array_2d::block_array[H_index][W_index+2] == 0 && array_2d::block_array[H_index+1][W_index+1] == 0 ) {
		return true;
	}
	else if (state == 3 && W_index+1 < W && array_2d::block_array[H_index+1][W_index+1] == 0  && array_2d::block_array[H_index][W_index+1] == 0 ) {
		return true;
	}
	return false;
}

bool fold_block::can_down(){

	if (state == 0 && H_index + 1 < H && array_2d::block_array[H_index+1][W_index] == 0 && array_2d::block_array[H_index+1][W_index-1] == 0 ) {
		return true;
	}
	else if (state == 1 && H_index + 1 < H && array_2d::block_array[H_index+1][W_index] == 0 && array_2d::block_array[H_index+1][W_index+1] == 0) {
		return true;
	}
	else if (state == 2 && H_index + 2 < H && array_2d::block_array[H_index+2][W_index] ==0 && array_2d::block_array[H_index+1][W_index+1] == 0 ) {
		return true;
	}
	else if (state == 3 && H_index+2 < H && array_2d::block_array[H_index+2][W_index] == 0 && array_2d::block_array[H_index+1][W_index-1] == 0 ) {
		return true;
	}
	return false;


}
void fold_block::left(){
	if(can_left()){
	int center_block = array_2d::block_array[H_index][W_index];
	array_2d::block_array[H_index][W_index] = 0;
	for (int idx = 0; idx < 4; idx++) {
		if (state == 0 && (idx == 2 || idx == 3)) {
			array_2d::block_array[H_index + y[idx]][W_index + x[idx] - 1] = array_2d::block_array[H_index + y[idx]][W_index + x[idx]];
				array_2d::block_array[H_index + y[idx]][W_index + x[idx]] = 0;
			}
			else if (state == 1&& (idx == 0 || idx == 3)) {
				array_2d::block_array[H_index + y[idx]][W_index + x[idx] - 1] = array_2d::block_array[H_index + y[idx]][W_index + x[idx]];
				array_2d::block_array[H_index + y[idx]][W_index + x[idx]] = 0;
			}
			else if (state == 2 && (idx == 0 || idx == 1)) {
				array_2d::block_array[H_index+ y[idx]][W_index + x[idx] - 1] = array_2d::block_array[H_index + y[idx]][W_index + x[idx]];
				array_2d::block_array[H_index + y[idx]][W_index + x[idx]] = 0;
			}
			else if (state == 3 && (idx == 1 || idx == 2)) {
				array_2d::block_array[H_index + y[idx]][W_index + x[idx] - 1] = array_2d::block_array[H_index + y[idx]][W_index + x[idx]];
				array_2d::block_array[H_index + y[idx]][W_index + x[idx]] = 0;
			}
		}
		array_2d::block_array[H_index][W_index - 1] = center_block;
		W_index--;

	}
	else{
		std::cout << "더이상 이동할 수 없습니다." << std::endl;
	}	
}

void fold_block::right(){
	if(can_right()){
		int center_block = array_2d::block_array[H_index][W_index];
		array_2d::block_array[H_index][W_index] = 0;
		for (int idx = 0; idx < 4; idx++) {
			if (state == 0 && (idx == 2 || idx == 3)) {
				array_2d::block_array[H_index + y[idx]][W_index + x[idx] + 1] = array_2d::block_array[H_index + y[idx]][W_index + x[idx]];
				array_2d::block_array[H_index + y[idx]][W_index + x[idx]] = 0;
			}
			else if (state == 1 && (idx == 0 || idx == 3)) {
				array_2d::block_array[H_index + y[idx]][W_index + x[idx] + 1] = array_2d::block_array[H_index + y[idx]][W_index + x[idx]];
				array_2d::block_array[H_index + y[idx]][W_index + x[idx]] = 0;
			}
			else if (state == 2 && (idx == 0 || idx == 1)) {
				array_2d::block_array[H_index + y[idx]][W_index + x[idx] + 1] = array_2d::block_array[ H_index + y[idx]][W_index + x[idx]];
				array_2d::block_array[H_index + y[idx]][W_index + x[idx]] = 0;
			}
			else if (state == 3 && (idx == 1 || idx == 2)) {
				array_2d::block_array[H_index + y[idx]][W_index + x[idx] + 1] = array_2d::block_array[H_index + y[idx]][W_index + x[idx]];
				array_2d::block_array[H_index + y[idx]][W_index + x[idx]] = 0;
			}
		}
		array_2d::block_array[H_index][W_index + 1] = center_block;
		W_index++;
			
	}
	else{
		std::cout <<"더이상 이동할 수 없습니다." << std::endl;
	}

}

void fold_block::down(){

	if(can_down()){
		int center_block = array_2d::block_array[H_index][W_index];
                array_2d::block_array[H_index][W_index] = 0;
                for (int idx = 0; idx < 4; idx++) {
                        if (state == 0 && (idx == 2 || idx == 3)) {
                                array_2d::block_array[H_index + y[idx]+1][W_index + x[idx]] = array_2d::block_array[H_index + y[idx]][W_index + x[idx]];
                                array_2d::block_array[H_index + y[idx]][W_index + x[idx]] = 0;
                        }
                        else if (state == 1 && (idx == 0 || idx == 3)) {
                                array_2d::block_array[H_index + y[idx]+1][W_index + x[idx]] = array_2d::block_array[H_index + y[idx]][W_index + x[idx]];
                                array_2d::block_array[H_index + y[idx]][W_index + x[idx]] = 0;
                        }
                        else if (state == 2 && (idx == 0 || idx == 1)) {
                                array_2d::block_array[H_index + y[idx]+1][W_index + x[idx]] = array_2d::block_array[ H_index + y[idx]][W_index + x[idx]];
                                array_2d::block_array[H_index + y[idx]][W_index + x[idx]] = 0;
                        }
                        else if (state == 3 && (idx == 1 || idx == 2)) {
                                array_2d::block_array[H_index + y[idx]+1][W_index + x[idx]] = array_2d::block_array[H_index + y[idx]][W_index + x[idx]];
                                array_2d::block_array[H_index + y[idx]][W_index + x[idx]] = 0;
                        }
                }
                array_2d::block_array[H_index+1][W_index] = center_block;
		

		H_index++;
	}
	else{
		down_all();
		bot = 1;
	}
}

void fold_block::down_all(){
        for (int col = 0; col < W; col++) {
                int start_row = 0;
                bool select = false;
                bool down_flag = false;
                for (int row = H - 1 ; row >= 0; row--) {
                        if(array_2d::block_array[row][col] == 0 && select == false){
                                        start_row = row;
                                        select = true;
                        }
                        else if( array_2d::block_array[row][col] != 0  && select == true){
                                down_flag = true;
                                array_2d::block_array[start_row][col] = array_2d::block_array[row][col];
                                array_2d::block_array[row][col] = 0;
                                start_row--;
                        }
                }

        }



}



void fold_block::clock_rotate(){
	if(state == 0 && array_2d::block_array[H_index][W_index+1] == 0 && W_index+1 <W ){
		array_2d::block_array[H_index][W_index+1] = array_2d::block_array[H_index-1][W_index];
	        array_2d::block_array[H_index-1][W_index] = array_2d::block_array[H_index][W_index-1];
		array_2d::block_array[H_index][W_index-1] = 0;	
		state = 1;

	}
	else if( state == 1 && array_2d::block_array[H_index+1][W_index] == 0 && H_index+1 < H){
		array_2d::block_array[H_index+1][W_index] = array_2d::block_array[H_index][W_index+1];
		array_2d::block_array[H_index][W_index+1] = array_2d::block_array[H_index-1][W_index];
		array_2d::block_array[H_index-1][W_index] = 0;
		state = 2;

	}
	else if( state == 2 && array_2d::block_array[H_index][W_index-1] == 0 && W_index-1 >=0){
		array_2d::block_array[H_index][W_index-1] = array_2d::block_array[H_index+1][W_index];
		array_2d::block_array[H_index+1][W_index] = array_2d::block_array[H_index][W_index+1];
		array_2d::block_array[H_index][W_index+1] = 0;
		state =3;

	}
	else if( state == 3 && array_2d::block_array[H_index-1][W_index] == 0 && H_index-1 >= 0){
		array_2d::block_array[H_index-1][W_index] = array_2d::block_array[H_index][W_index-1];
		array_2d::block_array[H_index][W_index-1] = array_2d::block_array[H_index+1][W_index];
	      	array_2d::block_array[H_index+1][W_index] = 0;
		state = 0;

	}

}

void fold_block::nonclock_rotate(){
	if(state == 0 && array_2d::block_array[H_index+1][W_index] ==0 && H_index+1 < H ){
                array_2d::block_array[H_index+1][W_index] = array_2d::block_array[H_index][W_index-1];
                array_2d::block_array[H_index][W_index-1] = array_2d::block_array[H_index-1][W_index];
                array_2d::block_array[H_index-1][W_index] = 0;
                state = 3;

        }
        else if(state == 1 && array_2d::block_array[H_index][W_index-1] == 0 && W_index-1 >=0 ){
                array_2d::block_array[H_index][W_index-1] = array_2d::block_array[H_index-1][W_index];
                array_2d::block_array[H_index-1][W_index] = array_2d::block_array[H_index][W_index+1];
                array_2d::block_array[H_index][W_index+1] = 0;
                state = 0;

        }
        else if( state == 2 && array_2d::block_array[H_index-1][W_index] == 0 && H_index-1 >= 0 ){
                array_2d::block_array[H_index-1][W_index] = array_2d::block_array[H_index][W_index+1];
                array_2d::block_array[H_index][W_index+1] = array_2d::block_array[H_index+1][W_index];
                array_2d::block_array[H_index+1][W_index] = 0;
                state = 1;

        }
        else if( state == 3 && array_2d::block_array[H_index][W_index+1] == 0 && W_index+1 < W ){
                array_2d::block_array[H_index][W_index+1] = array_2d::block_array[H_index+1][W_index];
                array_2d::block_array[H_index+1][W_index] = array_2d::block_array[H_index][W_index-1]; 
                array_2d::block_array[H_index][W_index-1] = 0; 
                state = 2;
	}

}


