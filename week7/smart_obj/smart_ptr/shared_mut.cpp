#include "shared_mut.h"

namespace ptr{
	shared_mut::shared_mut(){
		_mgr = new mgr();
	};
	shared_mut::shared_mut(Object* _obj){
		_mgr = new mgr(_obj);
	};
	shared_mut::~shared_mut(){
		release();
	};

	void shared_mut::release(){
		int c = _mgr->count-1;
		if(c == 0 ){
			delete(_mgr);
			_mgr = nullptr;
		}
	};

	int shared_mut::count(){
		return _mgr->count;
	};

	Object* shared_mut::get() const{
		if(_mgr == nullptr){
			return nullptr;
		}
		return _mgr->ptr;
	};
	void shared_mut::increase(){
		_mgr->count++;
	};
	

	shared_mut shared_mut::operator+(const shared_mut &shared){
		int val = this->_mgr->ptr->get() + shared._mgr->ptr->get(); 
		mgr* new_mgr = new mgr(val);	
		shared_mut new_s = shared_mut();
		new_s._mgr = new_mgr;
		return new_s;
	};
	
	
	shared_mut shared_mut::operator*(const shared_mut &shared){	
		int val = this->_mgr->ptr->get() * shared._mgr->ptr->get();
                mgr* new_mgr = new mgr(val);
                shared_mut new_s = shared_mut();
                new_s._mgr = new_mgr;

                return new_s;

	};

	shared_mut shared_mut::operator/(const shared_mut &shared){
 		int val = this->_mgr->ptr->get() / shared._mgr->ptr->get(); 
                mgr* new_mgr = new mgr(val);
                shared_mut new_s = shared_mut();
                new_s._mgr = new_mgr;

                return new_s;

	};
	
	shared_mut shared_mut::operator-(const shared_mut &shared){
	        int val = this->_mgr->ptr->get() - shared._mgr->ptr->get();
                mgr* new_mgr = new mgr(val);
                shared_mut new_s = shared_mut();
                new_s._mgr = new_mgr;
                return new_s;

	};

	Object* shared_mut::operator->(){
		return this->_mgr->ptr;
	};

	
	shared_mut shared_mut::operator=(const shared_mut &r) {
		release();
		mgr* new_mgr = new mgr(r._mgr->ptr->get());
		this->_mgr = new_mgr;
		increase();
		return *this;
	};

}
