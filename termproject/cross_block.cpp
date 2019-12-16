
#include "array_2d.h"
#include "cross_block.h"
#include "big_block.h"


cross_block::cross_block(int c1, int c2, int c3, int c4, int c5){
	array_2d::block_array[0][2] = c1;
	array_2d::block_array[1][2] = c2;
	array_2d::block_array[1][1] = c3;
	array_2d::block_array[1][3] = c4;
	array_2d::block_array[2][2] = c5;
	bot = 0;
}


bool cross_block::can_left() {
	if (W_index - 2 >= 0 && array_2d::block_array[H_index][W_index-2] == 0 && array_2d::block_array[H_index-1][W_index-1] ==0 && array_2d::block_array[H_index+1][W_index-1] == 0 ) {
		return true;
	}
	else{
		return false;
	}
}

bool cross_block::can_right() {
	if(W_index + 2 < W && array_2d::block_array[H_index][W_index+2] == 0 && array_2d::block_array[H_index+1][W_index+1] == 0 && array_2d::block_array[H_index-1][W_index+1] == 0 ){
		return true;
	}
	else{
		return false;
	}
}
bool cross_block::can_down() {
	if (H_index+ 2 < H && array_2d::block_array[H_index+2][W_index] == 0 && array_2d::block_array[H_index+1][W_index+1] == 0 && array_2d::block_array[H_index+1][W_index-1] == 0 ){
		return true;
	}		
	else{
		return false;
	}
}

void cross_block::left() {
	if (can_left()) {
		int center_block = array_2d::block_array[H_index][W_index];
		for (int i = 0; i < 4; i++) {
			array_2d::block_array[H_index + y[i]][W_index + x[i] - 1] = array_2d::block_array[H_index + y[i]][W_index + x[i]];
			array_2d::block_array[H_index + y[i]][W_index + x[i]] = 0;
		}		
		array_2d::block_array[H_index][W_index - 1] = center_block;
		W_index--;
	}
	else{
		std::cout << "더이상 이동할 수 없습니다."<< std::endl;
	}
}
void cross_block::right() {
	if (can_right()) {
		int center_block = array_2d::block_array[H_index][W_index];
		for (int i = 0; i < 4; i++) {
			array_2d::block_array[H_index + y[i]][W_index + x[i] + 1] = array_2d::block_array[H_index + y[i]][W_index + x[i]];
			array_2d::block_array[H_index + y[i]][W_index + x[i]] = 0;
		}
		array_2d::block_array[H_index][W_index + 1] = center_block;
		W_index++;
	}
	else{
		std::cout << "더이상 이동할 수 없습니다."<< std::endl;
	}
}
void cross_block::down() {
	if (can_down()) {
		int center_block = array_2d::block_array[H_index][W_index];		
		for (int i = 0; i < 4; i++) {
			array_2d::block_array[H_index + y[i]+1][W_index + x[i]] = array_2d::block_array[H_index + y[i]][W_index + x[i]];
			array_2d::block_array[H_index + y[i]][W_index + x[i]] = 0;
		}
		array_2d::block_array[H_index+1][W_index] = center_block;
		H_index++;
	}
	else{

		down_all();
		bot = 1;
			
	}
}



void cross_block::down_all(){
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

void cross_block::clock_rotate(){
	
	int stand_block = array_2d::block_array[H_index+y[3]][W_index+x[3]];
	for (int i = 3; i >= 1; i--){ 
		array_2d::block_array[H_index + y[i]][W_index + x[i]] = array_2d::block_array[H_index + y[i-1]][W_index + x[i-1]];
	}
	array_2d::block_array[H_index + y[0]][W_index + x[0]] = stand_block;
}

void cross_block::nonclock_rotate(){
		

        int stand_block = array_2d::block_array[H_index+y_anticlock[3]][W_index+x_anticlock[3]];
        for (int i = 3; i >= 1; i--){
                array_2d::block_array[H_index + y_anticlock[i]][W_index + x_anticlock[i]] = array_2d::block_array[H_index + y_anticlock[i-1]][W_index + x_anticlock[i-1]];
        }
        array_2d::block_array[H_index + y_anticlock[0]][W_index + x_anticlock[0]] = stand_block;

}
