#include "array_2d.h"
#include "big_block.h"
#include "fold_block.h"
#include "tree_block.h"
#include "cross_block.h"
#include <vector>
int row;
int col;
int array_2d::block_array[H][W];
int block_shape;


using namespace std;
array_2d::array_2d(){

	for(row =0; row < H; row++){
		for(col=0; col < W; col++){
			set_color(row, col, 0); 
		}
	}
	score = 0;
}

int array_2d::get_color(int row , int col){
	return block_array[row][col];
}

void array_2d::set_color(int row, int col, int color){
	block_array[row][col] = color;
}



big_block* array_2d::make_bigblock(){
	//fold block
       if (block_shape-1 == big_block::FOLD ) {
               return new fold_block(rand() % 4 + 1, rand() % 4 + 1, rand() % 4 + 1);
        }       

	//tree block
       else if(block_shape-1 == big_block::TREE ){
		return new tree_block(rand() % 4 + 1, rand() % 4 + 1, rand() % 4 + 1);
	} 

	//cross block	
	else if (block_shape-1 == big_block::CROSS ) {
		return new cross_block(rand() % 4 + 1, rand() % 4 + 1, rand() % 4 + 1, rand() % 4 + 1, rand() % 4 + 1);
	}
}


void array_2d::set_score(int _s){
	this->score = _s;
}

void array_2d::print(){

	for(row =0; row < H; row++){
		for(col=0; col < W; col++){
			cout<< block_array[row][col] << " ";
		}
		cout << endl;	
	}

}

int array_2d::get_score(){
	return this->score;
}

bool array_2d::can_make(){
	bool flag = true;
	block_shape = rand() % 3 + 1;
	if(block_shape == 1) { 
		if(block_array[1][1] != 0 || block_array[1][2] != 0){
			flag = false;
		}
	}
	else if( block_shape == 2 ){ //tree
		if(block_array[2][2]!= 0){
			flag = false;
		}
	}
	else if( block_shape == 3) {
		if(block_array[2][2] != 0 || block_array[1][1] != 0 || block_array[1][2] != 0 ||  block_array[1][3]  != 0 ){
			flag = false;
		}
			
	}
	return flag;
}

void array_2d::search_explosion(){
	int visited[H][W] = {0};
	for (int row = H-1; row >=0; row--) {
		for (int col = 0 ; col < W; col++) {
			vector<pair<int, int>> explo_candidate;	
			vector<pair<int ,int>> gray_block;
			int count =1;
			if ((get_color(row,col) != 1 && get_color(row, col) != 0) && visited[row][col] == 0){
				queue<pair<int, int>> q;

				pair<int, int> p = make_pair(row, col);
				q.push(p);
				explo_candidate.push_back(p);

				int compare_color = get_color(row, col);
				visited[row][col] = 1;
		

				while (!q.empty()) {

					int row_f = q.front().first;
					int col_f = q.front().second;
					q.pop();
					if(get_color(row_f, col_f) != 1){
					for (int i = 0; i < 4; i++) {
						int col_s= col_f + x[i];
						int row_s = row_f + y[i];
						if ( col_s >= 0 && col_s < W && row_s >= 0 && row_s < H && visited[row_s][col_s] == 0 ) {
							if (get_color(row_s, col_s) == compare_color) {
								pair<int, int> p = make_pair(row_s, col_s);
								q.push(p);
								explo_candidate.push_back(p);
								visited[row_s][col_s] = 1;
								count++;
							}
							else if (get_color(row_s, col_s) == 1) {
								visited[row_s][col_s] = 1;
								pair<int, int> g = make_pair(row_s, col_s);
								gray_block.push_back(g);
								pair<int, int> p = make_pair(row_s, col_s);
								q.push(p);
								explo_candidate.push_back(p);

							}
						}	
					}
					}
				}

                       		 if (count > 3) {
                               		 explosion(explo_candidate);
    		                    }
				 else{
					vector<pair<int, int>>::iterator iter;

					for(auto iter= gray_block.begin(); iter!= gray_block.end(); ++iter){
						int row_idx = iter->first;
						int col_idx = iter->second;

						visited[row_idx][col_idx] = 0;
					}
					

				 }

                        explo_candidate.clear();



			}
		}
	}
}


void array_2d::explosion(vector<pair<int, int>> candidate){

	vector<pair<int, int>>::iterator iter;

	for(auto iter=candidate.begin(); iter != candidate.end(); ++iter){
		int row_ = iter->first;
		int col_ = iter->second;
		set_color(row_, col_, 0);

	}

	int current_score = get_score();
	set_score(current_score+1);
	down_all();
}


void array_2d::down_all(){
	for (int col = 0; col < W; col++) {
                int start_row = 0;
                bool select = false;
                bool down_flag = false;
                for (int row = H - 1 ; row >= 0; row--) {
                        if(block_array[row][col] == 0 && select == false){
                                        start_row = row;
                                        select = true;
                        }
                        else if( block_array[row][col] != 0  && select == true){
                                down_flag = true;
                                block_array[start_row][col] = array_2d::block_array[row][col];
                                block_array[row][col] = 0;
                                start_row--;
                        }
                }

        }
        search_explosion();


}
