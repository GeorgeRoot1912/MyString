#ifndef CPP_LIB_Strings_H_
#define CPP_LIB_Strings_H_ 1
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
        #ifdef STRING_MEMORY_CONTROL_BLOCK
            exit(102); // Throw exception
        #endif
    }
    // If string visible in console(printable string) return true(1), else false(0)
    inline bool isprint() const{
        for(unsigned int i=0; i<length; i++){if((str_inner[i] > 31) || (str_inner[i] == 9 || str_inner[i] == 10)){return true;}} return false;
    }
    // If all characters is numbers, return true(1), else false(0)
    inline bool isalprint() const{
        for(unsigned int i=0; i<length; i++){ if(str_inner[i] < 31 || (str_inner[i] == 9 || str_inner[i] == 10)){return false;}} return true;
    }
    // If one or bigger characters is letters, return true(1), else false(0) NOT WORK
    inline bool islet() const{
        for(unsigned int i=0; i<length; i++){if( (str_inner[i] >= 'A' && str_inner[i] <= 'Z') || (str_inner[i] >= 'a' && str_inner[i] <= 'z') ){return true; }} return false;
    }  
    // If all characters is letters, return true(1), else false(0) NOT WORK
    inline bool isalet() const{
        for(unsigned int i=0; i<length; i++){if( (str_inner[i] < 65 || str_inner[i] > 90) && (str_inner[i] < 97 || str_inner[i] > 122) ){return false; }} return true;
    }  
    // If one or bigger charactes upper return true(1), else false(0)
    inline bool isup() const{
        for(unsigned int i=0; i<length; i++){if(str_inner[i] >= 'A' && str_inner[i] <= 'Z'){return true;}} return false;
    }
    // If one or bigger charactes lower return true(1), else false(0)
    inline bool islow() const{
        for(unsigned int i=0; i<length; i++){if(str_inner[i] >= 'a' && str_inner[i] <= 'z'){return true;}} return false;
    }
    // If all charactes is space,tab or '\n' return true(1), else false(0)
    inline bool isalspace() const{
        for(unsigned int i=0; i<length; i++){if(str_inner[i] != ' ' || str_inner[i] != 10 || str_inner[i] != 9){ return false; }} return true;
    }
    // If one or bigger charactes is space,tab or '\n' return true(1), else false(0)
    inline bool ispace() const{
        for(unsigned int i=0; i<length; i++){if(str_inner[i] == ' ' || str_inner[i] == 10 || str_inner[i] == 9){ return true; }} return false;
    }
    // If all charactes upper return true(1), else false(0)
    inline bool isalup() const{
        for(unsigned int i=0; i<length; i++){if(str_inner[i] < 'A' || str_inner[i] > 'Z'){return false;}} return true;
    }
    // If all charactes is lower return true(1), else false(0)
    inline bool isalow() const{
        for(unsigned int i=0; i<length; i++){if(str_inner[i] < 'a' || str_inner[i] > 'z'){return false;}} return true;
    }
    // If all characters is decimal numbers, return true(1), else false(0)
    inline bool isalnum() const{ 
        for(unsigned int i=0; i<length; i++){ 
            if(str_inner[i] < 48 || str_inner[i] > 57){ return false; }
        } return true; 
    }
    // If one or bigger characters is decimal numbers, return true(1), else false(0)
    inline bool isnum() const{ 
        for(unsigned int i=0; i<length; i++){ 
            if(str_inner[i] > 47 && str_inner[i] < 58){ return true; }
        } return false; 
    }
    // If one or bigger characters is oct numbers, return true(1), else false(0)
    inline bool isoct() const{ 
        for(unsigned int i=0; i<length; i++){ 
            if(str_inner[i] > 47 && str_inner[i] < 56){ return true; }
        } return false; 
    }
    // If all characters is oct numbers, return true(1), else false(0)
    inline bool isaloct() const{ 
        for(unsigned int i=0; i<length; i++){ 
            if(str_inner[i] < 48 || str_inner[i] > 55){ return false; }
        } return true; 
    }
    // If all characters is hex numbers, return true(1), else false(0)
    inline bool isalhex() const{ 
        for(unsigned int i=0; i<length; i++){ 
            if( 
                (str_inner[i] < 48 || str_inner[i] > 57) && ( (str_inner[i] < 65 || str_inner[i] > 70) && (str_inner[i] <  97 || str_inner[i] > 102) ) 
            ) { return false; }
        } return true; 
    }
    // If one or bigger characters is hex numbers, return true(1), else false(0)
    inline bool ishex() const{ 
        for(unsigned int i=0; i<length; i++){ 
            if( (str_inner[i] > 47 && str_inner[i] < 58) || ( (str_inner[i] >64 && str_inner[i] < 71) || (str_inner[i] > 96 || str_inner[i] < 103) ) ){ return true; }
        } return false; 
    }
    // Compares two strings without regard to case.
    inline bool equal(const str& __string) const{
        if (__string.length != length){ return false; }
        char a = 0; char b = 0;
        for(unsigned int i=0; str_inner[i] != '\0'; i++){
            a = str_inner[i]; b = __string.str_inner[i];
            if(a >= 'a' && a<= 'z'){ a-=32; }
            if(b >= 'a' && b <= 'z'){ b-=32; }
            if (a != b){ return false; }
        }
        return true;
    }
    // Return sum all characters in string
    inline unsigned int sum() const{
        unsigned int sum = 0;
        for(unsigned int i=0; i<length; i++){
            sum += str_inner[i];
        }
        return sum;
    }
    // Like strcmp
    inline int cmp(const str& __string)const{
        return strcmp(str_inner, __string.str_inner);
    }
    // Return str value(char*)
    inline char* get() const{
        return str_inner;
    }
    // Return length.
    inline unsigned int len() const{
        return length;
    }
    // like str.get()
    inline char* operator *() const{
        return str_inner;
    }
    // Return last character in this string.
    inline char last() const{ if(str_inner == NULL){ return '\0';}
        return str_inner[length-1];
    }
    // Return first character in this string.
    inline char first() const{ if(str_inner == NULL){ return '\0';}
        return str_inner[0];
    }
    // If the sum of this string is equal to the sum of str __string returns true. Else false.
    inline bool sum_eq(const str& __string) const{
        if (__string.sum() == sum()){ return true; }
        return false;
    }
    // Copy self data to str& __string.
    inline void copy(str& __string) const{
        free(__string.str_inner); __string.str_inner = (char*) malloc(this->length);
        memcpy(__string.str_inner, str_inner, this->length);
        __string.length = length; __string.str_inner[length] = '\0';
    }
    // Moves data between two strings.
    inline void swap(str& __string){ if(str_inner == NULL){ return;}
        unsigned int __len = __string.length; char* temp = (char*) malloc(__len); memcpy(temp,__string.str_inner,__len); 
        free(__string.str_inner); __string.str_inner = (char*) malloc(this->length);
        strcpy(__string.str_inner, str_inner);
        __string.length = length;        
        free(str_inner); str_inner = (char*) malloc(__len); memcpy(str_inner, temp, __len); length = __len; free(temp);
    }
    // Set_upper first character in string
    inline void capitalize(){ if(str_inner == NULL){ return;}
        if(str_inner[0] >= 'a' && str_inner[0] <= 'z'){str_inner[0] -= 32; }
    }
    // Set_upper for all characters in string
    inline void toup(){
        for(unsigned int i=0; i<length; i++){
            if(str_inner[i] >= 'a' && str_inner[i] <= 'z'){str_inner[i] -= 32; }
        }
    }
    // Set_lower for all characters in string
    inline void tolow(){
        for(unsigned int i=0; i<length; i++){
            if(str_inner[i] >= 'A' && str_inner[i] <= 'Z'){str_inner[i] += 32; }
        }
    }
    // Return center index in string
    inline unsigned int center() const{
        return (unsigned int) (length / 2);
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








    // ERRORED:


    
    // Add str& __string to this __string str.
    inline void operator +=(const str& __string){
        if ( (char) __string.str_inner[0] == '\0'){ return; }
        str_inner = (char*) realloc(str_inner, length+__string.length+1);
        strcat(str_inner, __string.str_inner); length += __string.length; str_inner[length] = '\0';   
    }

    // Add str& __string to this char* __string.
    inline void operator +=(const char* __string){
        if ( (char) __string[0] == '\0'){ return; }
        str_inner = (char*) realloc(str_inner, length+strlen(__string)+1);
        strcat(str_inner, __string); length += strlen(__string); str_inner[length] = '\0';   
    }   
    // Return this string + str __string
    inline str operator +(const str& __string) const{
        str result((char*) this->str_inner); 
        if ( (char) __string.str_inner[0] == '\0'){ return result;}
        strcat(result.str_inner, __string.str_inner); result.length += strlen(__string.str_inner);
        return result;
    }
    // Return this string +char* __string
    inline str operator +(const char* __string) const{
        str result((char*) this->str_inner); unsigned int str_len = strlen(__string);
        if ( (char) __string[0] == '\0'){ return result; }
        strcat(result.str_inner, __string);
        result.length += str_len; result.str_inner[str_len+this->length] = '\0';
        return result;
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
    // Fill all character in string char obj.
    inline void fill(char obj){
        for(unsigned int i=0; i<length; i++){ str_inner[i] = obj; }
    }
    // Replace all characters==char if_replace to char to_replace
    inline void replace(char if_replace, char to_replace){
        for(unsigned int i=0; i<length; i++){
            if (str_inner[i] == if_replace){
                str_inner[i] = to_replace;
            }
        }
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
    // If character exist in this string return true, else return false
    inline bool exist(char char_for_test_on_exist) const{
        for(unsigned int i=0; i<length; i++){
            if (str_inner[i] == char_for_test_on_exist){
                return true;
            }
        }
        return false;
    }
    private:
    char* str_inner = NULL;
    unsigned int length = 0;
};
#endif
