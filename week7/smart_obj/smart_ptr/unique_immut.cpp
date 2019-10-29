#include "unique_immut.h"


namespace ptr{
unique_immut::unique_immut(){
	_mgr = new mgr();
};

unique_immut::unique_immut(Object* obj){
	_mgr = new mgr(obj);
};

unique_immut::unique_immut(const unique_immut &immut){
	if(immut._mgr){
		int val = immut._mgr->ptr->get();
		_mgr = new mgr(val);
		
	}
};

unique_immut::~unique_immut(){
	release();
};

void unique_immut::release(){
	if(_mgr != nullptr){		
		delete(_mgr);
		_mgr = nullptr;
	}
};

Object* unique_immut::get() const{
	if(_mgr == nullptr){
		return nullptr;
	}
	return _mgr->ptr;
};

	
unique_immut unique_immut::operator+(unique_immut &unique){
	   int val = this->_mgr->ptr->get() + unique._mgr->ptr->get(); 
	   release();
	   unique.release();
           mgr* new_mgr = new mgr(val);
           unique_immut new_u = unique_immut();
           new_u._mgr = new_mgr;
	   return new_u;

};
unique_immut unique_immut::operator-(unique_immut &unique){

           int val = this->_mgr->ptr->get() - unique._mgr->ptr->get(); 
	   this->release();
           unique.release();
           mgr* new_mgr = new mgr(val);
           unique_immut new_u = unique_immut();
           new_u._mgr = new_mgr;
           return new_u;

};
unique_immut unique_immut::operator*(unique_immut &unique){
           int val = this->_mgr->ptr->get() * unique._mgr->ptr->get(); 
	   this->release();
           unique.release();
           mgr* new_mgr = new mgr(val);
           unique_immut new_u = unique_immut();
           new_u._mgr = new_mgr;
           return new_u;

};
unique_immut unique_immut::operator/(unique_immut &unique){
           int val = this->_mgr->ptr->get() / unique._mgr->ptr->get(); 
	   this->release();
           unique.release();
           mgr* new_mgr = new mgr(val);
           unique_immut new_u = unique_immut();
           new_u._mgr = new_mgr;
           return new_u;

};

Object* unique_immut::operator->(){
	return _mgr->ptr;
};


unique_immut&unique_immut::operator=(unique_immut& r){
	//if(_mgr != r._mgr){
	if(this != &r){
		release();
		_mgr = r._mgr;
		//r._mgr = _mgr; 
	}
	return *this;
	
};

}
