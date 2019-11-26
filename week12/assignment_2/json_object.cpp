

#include "json_object.h"
#include "json_list.h"
#include "data/String.h"
#include "data/Integer.h"
#include "json_dict.h"

int json_object::_index = 0;

json_object* json_object::parse(const char* c, int len){
	
	while(_index<len){
		char ch = c[_index];
		if(ch == '['){         //list start
			return json_list::parse(c, len );	
		}
			
		else if( ch == '\''|| ch == '\"' ){    //letter start
			return String::parse(c , len, ch);
		}
		else if(ch == '{'){    //dict start
			return json_dict::parse(c, len);
		}
		else if( ch >= '0' && ch <= '9'){  // digit start
			return Integer::parse(c, len);
		}
		else{
			_index++;
		}

	}

}

json_object* json_object::parse(const std::string& s){
	json_object::_index =0;

	int len = s.length();
	return json_object::parse(s.c_str(), len);


}

