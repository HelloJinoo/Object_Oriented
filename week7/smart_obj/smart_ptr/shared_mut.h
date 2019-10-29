#ifndef SMART_PTR_SHARED_MUT_H
#define SMART_PTR_SHARED_MUT_H


#include "smart_obj.h"

namespace ptr{
class shared_mut : public smart_obj {
	private :
		mgr* _mgr;
		void increase();	
	public :
		shared_mut();
		explicit shared_mut(Object* obj);
		~shared_mut();
		void release();

		int count();
		Object* get() const;

		shared_mut operator+(const shared_mut &shared);
		shared_mut operator-(const shared_mut &shared);
		shared_mut operator*(const shared_mut &shared);
		shared_mut operator/(const shared_mut &shared);
		Object* operator->();
		shared_mut&operator=(const shared_mut &r);
};
}

#endif
