#ifndef CPP_LIB_Strings_H_
#define CPP_LIB_Strings_H_ 2
#include <stdlib.h>
#include <string.h> 
class str{
    public:
    str(const char* text){
        length = strlen((char*) text);
        str_inner = (char*) malloc(length);
        memcpy(str_inner, (char*) text, length);
    }
    str(const str& __string){
        str_inner = (char*) malloc(__string.length); length = __string.length;
        memcpy(str_inner, (char*) __string.str_inner, __string.length);
    }
    // Frees the memory of the allocated string.
    ~str(){
        if ( str_inner != 0){ 
            free(str_inner); str_inner = NULL; return;
        }
            exit(102);
    }
    // Return str value(char*)
    inline char* get() const{
        return str_inner;
    }
    // Return length.
    inline unsigned int len() const{
        return length;
    }
    // Copy self data to str& __string.
    inline void copy(str& __string) const{
        free(__string.str_inner); __string.str_inner = (char*) malloc(this->length);
        memcpy(__string.str_inner, str_inner, this->length);
        __string.length = length; __string.str_inner[length] = '\0';
    }
    // Return index in string(char)
    inline char operator [](unsigned int index) const{
        if(index >= length){return '\0'; } // Exception or return NULL
        if(str_inner == NULL){ return '\0';}
        return str_inner[index];
    }
    // Set index in this string equal char symbol 
    inline void set(unsigned int index, char symbol){
        if (index >= length){ return; }
        str_inner[index] = symbol;
    }
    // Splice this string from start to end. Not use with NULL strings!
    inline str splice(unsigned int start, unsigned int end) const { 
        int _len = end - start; 
        str result = (char*) ""; if (_len <= 0){ return result; } 
        result.str_inner = (char*) malloc(_len); _len = 0;
        for(unsigned int i=0,d=start; d<end && str_inner[d] != '\0';i++){
            result.str_inner[i] = str_inner[d];  ++d; ++_len;
        } 
        result.length = _len; result.str_inner[_len] = '\0';
        return result;
    }
    // This object = str& obj.
    inline void operator =(const str& obj){
        free(str_inner); str_inner = (char*) malloc(obj.length);
        memcpy(str_inner, obj.str_inner, obj.length);
        length = obj.length; str_inner[obj.length] = '\0';
    }
    // This object = char* obj.
    inline void operator =(const char* obj){ unsigned int __len = strlen(obj);
        free(str_inner); str_inner = (char*) malloc(__len);
        memcpy(str_inner, obj, __len); str_inner[__len] = '\0';
        length = __len;   
    }
    // If str& obj equal this str, return true(1), else return false(0).
    inline bool operator ==(const str& obj) const{
        if (strcmp(str_inner, obj.str_inner) == 0){ return true; }
        return false;
    }
    // If char* obj equal this str, return true(1), else return false(0)
    inline bool operator ==(const char* obj) const{
        if (strcmp(obj, this->str_inner) == 0){ return true; }
        else{
        return false;
        }
    }    
    // If str& obj not equal this str, return true(1), else return false(0).
    inline bool operator !=(const str& obj) const{
        if (strcmp(str_inner, obj.str_inner) != 0){ return true; }
        return false;
    }
    // If char* obj not equal this str, return true(1), else return false(0)
    inline bool operator !=(const char* obj) const{
        if (strcmp(str_inner, obj) != 0){ return true; }
        return false;
}
    // Return index character in this string. Else character not found return -1
    inline int search(char char_for_search) const{
        for(unsigned int i=0; i<length; i++){
            if (str_inner[i] == char_for_search){
                return (int) i;
            }
        }
        return (int) -1;
    }
    private:
    char* str_inner = NULL;
    unsigned int length = 0;
};
#endif
