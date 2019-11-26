#include "json_dict.h"
#include "data/String.h"
#include "data/Integer.h"


using namespace std;


json_dict::json_dict(){

}

void json_dict::put(json_object* key, json_object* val){
	int index = find(key);
	if(index == -1){
		v.push_back(std::make_pair(key,val));
	}	
	else{
	 	v[index] = std::make_pair(key,val);
	}
}

int json_dict::find(json_object* key){

	int index = 0;
	
	if(key->type() == INT){
		Integer* ikey = dynamic_cast<Integer*>(key);
		for(auto iter = v.begin(); iter != v.end(); iter++, index++){	
			if(iter->first->type() == INT){

				Integer* i = dynamic_cast<Integer*>(iter->first);
				if(i->val() == ikey->val())	
					return index;
			}
		}
	}
	else{
		String* skey = dynamic_cast<String*>(key);
		for(auto iter = v.begin(); iter != v.end(); iter++, index++){		
			if(iter->first->type() == STRING){
				String* s = dynamic_cast<String*>(iter->first);
				if(s->val().compare(skey->val()) == 0){	
					return index;
				}
			}
		}
	}
	return -1;


}




json_object::_type json_dict::type(){
	return json_object::_type(0); //DICT
}


	
json_object* json_dict::operator[](json_object* key) const {
	int index = 0;
	
	if(key->type() == INT){

		auto ikey = dynamic_cast<Integer*>(key);
		for(auto iter = v.begin(); iter != v.end(); iter++, index++){

			if(iter->first->type() == INT){

				Integer* i = dynamic_cast<Integer*>(iter->first);
				if(i->val() == ikey->val())	
					return iter->second;
			}
		}
	}
	else{

		auto skey = dynamic_cast<String*>(key);
		for(auto iter = v.begin(); iter != v.end(); iter++, index++){		
			if(iter->first->type() == STRING){
				String* s = dynamic_cast<String*>(iter->first);
				if(s->val().compare(skey->val()) == 0)	
					return iter->second;
			}
		}
	}
	return nullptr;
}	
	

json_object* json_dict::operator[](const std::string& key) const{

	for(auto iter = v.begin(); iter != v.end(); ++iter){
		if(iter->first->type() == STRING){

			String* s = dynamic_cast<String*>(iter->first);
			if(s->val().compare(key) == 0)
			{
				return iter->second;
			}
		}
	}
	return nullptr;
}


json_object* json_dict::operator[](int key) const{


	for(auto iter = v.begin(); iter != v.end(); ++iter){

		if(iter->first->type() == INT){

			Integer* i = dynamic_cast<Integer*>(iter->first);
			if(i->val() == key){	
				return iter->second;
			}
		}
	}
	return nullptr;
}






json_object* json_dict::parse(const char* c, int length) {

	json_dict* j_dict = new json_dict();
	_index++;  //{ ->

	while( _index < length && c[_index] != '}' ){
		
		json_object* key = json_object::parse(c, length);
		_index++;
		json_object* value = json_object::parse(c, length);
		j_dict->put(key,value);

		if(c[_index] == '}'){
			break;
		}
		_index++;
	}
	_index++;

	return j_dict;




}

std::string json_dict::to_string(){

	std::string str = std::string("{");

	for(auto iter=v.begin(); iter!= v.end(); iter++){
		str.append(iter->first->to_string());
		str.append(":");
		str.append(iter->second->to_string());
		if(iter != v.end() -1){
			str.append(", ");
		}


	}

	str.append("}");
	return str;

}
