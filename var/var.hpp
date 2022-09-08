//
//  var.hpp
//  var v_1.1
//
//  Created by Dima on 08.07.2022.
//

#ifndef var_hpp
#define var_hpp

#include <iostream>

#define VAR_BOOL 1
#define VAR_INT 2
#define VAR_LONG 3
#define VAR_DOUBLE 4
#define VAR_CHAR 5
#define VAR_STRING 6
#define VAR_STRING_STR ""

#define VAR_VERSION "1.1.3"

class var
{
private:
    
    bool b_bool;
    int i_int;
    long l_long;
    double d_double;
    char c_char;
    char *cs_tr;
    
private:
    
    short type_id;
    size_t length;
    size_t capacit_y;
    
public:
    
    var()
    {
        this->b_bool = false;
        this->i_int = 0;
        this->l_long = 0;
        this->d_double = 0;
        this->c_char = '\0';
        this->cs_tr = nullptr;
        
        this->type_id = 0;
        this->length = 0;
        this->capacit_y = 0;
    }

    var(const var &in) : var()
    {
        if (in.type_id == 1){
            this->b_bool = in.b_bool;
            this->type_id = in.type_id;
        }
        else if (in.type_id == 2){
            this->i_int = in.i_int;
            this->type_id = in.type_id;
        }
        else if (in.type_id == 3){
            this->l_long = in.l_long;
            this->type_id = in.type_id;
        }
        else if (in.type_id == 4){
            this->d_double = in.d_double;
            this->type_id = in.type_id;
        }
        else if (in.type_id == 5){
            this->c_char = in.c_char;
            this->type_id = in.type_id;
        }
        else if (in.type_id == 6){
            this->length = in.length;
            this->type_id = in.type_id;
            reall_size(this->length +1);
            reall_str(capacit_y);
            copy_data_str(this->cs_tr, in.cs_tr, this->length);
        }
    }
    
    var(const bool in) : var(){
        this->b_bool = in;
        this->type_id = 1;
    }
    
    var(const int in) : var(){
        this->i_int = in;
        this->type_id = 2;
    }
    
    var(const long in) : var(){
        this->l_long = in;
        this->type_id = 3;
    }
    
    var(const double in) : var(){
        this->d_double = in;
        this->type_id = 4;
    }
    
    var(const char in) : var(){
        this->c_char = in;
        this->type_id = 5;
    }
    
    var(const char *in) : var(){
        if (in == nullptr){
            return;
        }
        else{
            this->type_id = 6;
        }
        
        while (in[this->length] != '\0') {
            this->length++;
        }
        
        if (this->cs_tr == nullptr){
            reall_size(this->length +1);
            this->cs_tr = new char [this->capacit_y];
            copy_data_str(this->cs_tr, in, this->length +1);
        }
    }
    
    
    var &operator= (const var &other);
    
    var &operator+= (const var &other);
    
    var &operator-= (const var &other);
    
    var operator+ (const var &other);
    
    var operator- (const var &other);
    
    var operator* (const var &other);
    
    var operator/ (const var &other);
    
    var operator% (const var &other);
    
    var operator++ (int);
    
    var operator-- (int);
    
    
    char &operator[] (const size_t &other);
    
    char &operator[] (const var &other);
    
    bool operator< (const var &other);
    
    bool operator> (const var &other);
    
    bool operator<= (const var &other);
    
    bool operator>= (const var &other);
    
    bool operator== (const var &other);
    
    bool operator!= (const var &other);
    
    friend var operator+ (var in, var &other);
    friend var operator- (var in, var &other);
    friend var operator* (var in, var &other);
    friend var operator/ (var in, var &other);
    friend var operator% (var in, var &other);
    
    friend bool operator< (var &other1, var &other2);
    friend bool operator> (var &other1, var &other2);
    friend bool operator<= (var &other1, var &other2);
    friend bool operator>= (var &other1, var &other2);
    
    
    friend std::ostream& operator << (std::ostream& out, const var &other);
    friend std::istream& operator >> (std::istream& stream, var &other);
    
    
public:
    
    const bool getBool(){
        return this->b_bool;
    }
    
    const int getInt(){
        return this->i_int;
    }
    
    const long getLong(){
        return this->l_long;
    }
    
    const double getDouble(){
        return this->d_double;
    }
    
    const char getChar(){
        return this->c_char;
    }
    
    const var type_t(var i = 0) const;

    const char *typeVar();
    
    const char *c_str(){
        return this->cs_tr;
    }
    
    const size_t capacity(){
        return this->capacit_y;
    }
    
    const size_t size() const{
        return this->length;
    }
    
    const int size_i() const{
        return (int)this->length;
    }
    
    void setType(const short &in){
        this->type_id = in;
    }
    
    long find(const char *in, long where = 0){
        return findr(in, where);
    }
    
    long find(const var in, long where = 0){
        return findr(in, where);
    }
    
    long rfind(const char *in){
        return rfindr(in);
    }
    
    long rfind(const var in){
        return rfindr(in);
    }
    
    long rfind(const char *in, const long where){
        return rfindr(in, where);
    }
    
    long rfind(const var in, const long where){
        return rfindr(in, where);
    }
    
    const char *replace(long start, const char *in){
        return replacer(start, in);
    }
    
    const char *replace(long start, const var in){
        return replacer(start, in.cs_tr);
    }
    
    const char *replace(long start, long len, const char *in){
        return replacer(start, len, in);
    }
    
    const char *replace(long start, long len, const var in){
        return replacer(start, len, in.cs_tr);
    }
    
    const char *findAndReplace(const char *find, const char *replace){
        return findr_and_replacer(find, replace);
    }
    
    const char *findAndReplace(const var find, const char *replace){
        return findr_and_replacer(find.cs_tr, replace);
    }
    
    const char *findAndReplace(const char *find, const var replace){
        return findr_and_replacer(find, replace.cs_tr);
    }
    
    const char *findAndReplace(const var find, const var replace){
        return findr_and_replacer(find.cs_tr, replace.cs_tr);
    }
    
    const char *findAndReplace(const char *find, const char *replace, const char whole){
        return findr_and_replacer(find, replace, whole);
    }
    
    const char *findAndReplace(const var find, const char *replace, const char whole){
        return findr_and_replacer(find.cs_tr, replace, whole);
    }
    
    const char *findAndReplace(const char *find, const var replace, const char whole){
        return findr_and_replacer(find, replace.cs_tr, whole);
    }
    
    const char *findAndReplace(const var find, const var replace, const char whole){
        return findr_and_replacer(find.cs_tr, replace.cs_tr, whole);
    }
    
    const char *append(const char *in){
        return appen_d(in);
    }
    
    const char *append(const var in){
        return appen_d(in);
    }
    
    const char *append(const char *in, size_t len){
        return appen_d(in, len);
    }
    
    const char *append(const var in, size_t len){
        return appen_d(in, len);
    }
    
    void clear(){
        clea_r();
    }
    
    const char *erase(){
        return eras_e();
    }
    
    const char *erase(const size_t start){
        return eras_e(start);
    }
    
    const char *erase(const size_t start, const size_t end){
        return eras_e(start, end);
    }
    
private:
    
    void copy_data_str(char*, const char*, const size_t&);
    void reall_size(const size_t &len = 10);
    void reall_str(const size_t&);
    void reall_size_str(const size_t&);
    void override_datatype_more();
    void override_datatype_less();
    void clea_unused_data(const short&);
    bool resize(const size_t &);
    long findr(const char*, const long&);
    long findr(const var&, const long&);
    long rfindr(const char*);
    long rfindr(const var&);
    long rfindr(const char*, const long&);
    long rfindr(const var&, const long&);
    const char *findr_and_replacer(const char*, const char*);
    const char *findr_and_replacer(const char*, const char*, const char&);
    const char *replacer(long&, const char*);
    const char *replacer(long&, long &, const char*);
    const char *appen_d(const char*);
    const char *appen_d(const var&);
    const char *appen_d(const char*, const size_t&);
    const char *appen_d(const var&, const size_t&);
    void clea_r();
    const char *eras_e();
    const char *eras_e(const size_t&);
    const char *eras_e(const size_t&, const size_t&);
    
public:
   // const char *appen_d(const char*);
public:
    
    ~var()
    {
        delete [] this->cs_tr;
    }
    
};

void getline(std::istream &stream, var &other);

#endif /* var_hpp */
