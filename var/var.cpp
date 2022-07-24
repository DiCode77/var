//
//  var.cpp
//  var
//
//  Created by Dima on 08.07.2022.
//

#include "var.hpp"

void var::copy_data_str(char *str, const char *in, const size_t &length){
    if( !str || !in || !length ){
        return;
    }
    
    for(size_t i = 0; i < length; i++){
        str[i] = in[i];
    }
}

void var::reall_size(const size_t &len){
    if (!resize(len)){
        if (len < 15 && this->capacit_y < 20){
            this->capacit_y = 20;
        }
        else{
            this->capacit_y += (len - this->capacit_y) + 20;
        }
    }
}

void var::reall_str(const size_t &size){
    if (this->cs_tr != nullptr){
        char *new_str = new char[size]{};
        delete [] this->cs_tr;
        this->cs_tr = new_str;
    }
    else{
        this->cs_tr = new char[size]{};
    }
}

bool var::resize(const size_t &len){
    return (this->capacit_y > len +1);
}

void var::reall_size_str(const size_t &len){
    if (!resize(len)){
        if (len < 15){
            this->capacit_y = 20;
        }
        else{
            this->capacit_y += (len - this->capacit_y) + 20;
            reall_str(this->capacit_y);
        }
    }
}

void var::clea_unused_data(const short &id){
    if (this->type_id == 1){
        this->b_bool = false;
    }
    else if (this->type_id == 2){
        this->i_int = 0;
    }
    else if (this->type_id == 3){
        this->l_long = 0;
    }
    else if (this->type_id == 4){
        this->d_double = 0;
    }
    else if (this->type_id == 5){
        this->c_char = '\0';
    }
    else if (this->type_id == 6 && id != 6){
        delete [] this->cs_tr;
        this->cs_tr = nullptr;
        this->length = 0;
        this->capacit_y = 0;
    }
}

var &var::operator= (const var &other){
    clea_unused_data(other.type_id);
    this->type_id = other.type_id;
    if (other.type_id == 1){
        this->b_bool = other.b_bool;
    }
    else if (other.type_id == 2){
        this->i_int = other.i_int;
    }
    else if(other.type_id == 3){
        this->l_long = other.l_long;
    }
    else if (other.type_id == 4){
        this->d_double = other.d_double;
    }
    else if (other.type_id == 5){
        this->c_char = other.c_char;
    }
    else if (other.type_id == 6){
        if (this->cs_tr != nullptr || other.cs_tr != nullptr){
            this->length = other.length;
            reall_size_str(this->length +1);
            copy_data_str(this->cs_tr, other.cs_tr, this->length +1);
        }
    }
    return *this;
}

var &var::operator+= (const var &other)
{
   // clea_unused_data(other.type_id);
    if (this->type_id == 1 && other.type_id == 1){
        this->b_bool += other.b_bool;
        this->type_id = other.type_id;
    }
    else if (this->type_id == 1 && other.type_id == 2){
        this->i_int = this->b_bool + other.i_int;
        this->type_id = other.type_id;
    }
    else if (this->type_id == 1 && other.type_id == 3){
        this->l_long = this->b_bool + other.l_long;
        this->type_id = other.type_id;
    }
    else if (this->type_id == 1 && other.type_id == 4){
        this->d_double = this->b_bool + other.d_double;
        this->type_id = other.type_id;
    }
    else if (this->type_id == 1 && other.type_id == 5){
        this->c_char = this->b_bool + other.c_char;
        this->type_id = other.type_id;
    }
    else if (this->type_id == 1 && other.type_id == 6){
    }
    else if (this->type_id == 2 && other.type_id == 1){
        this->i_int += other.b_bool;
        this->type_id = 2;
    }
    else if (this->type_id == 2 && other.type_id == 2){
        this->i_int += other.i_int;
        this->type_id = other.type_id;
    }
    else if (this->type_id == 2 && other.type_id == 3){
        this->l_long = this->i_int + other.l_long;
        this->type_id = other.type_id;
    }
    else if (this->type_id == 2 && other.type_id == 4){
        this->d_double = this->i_int + other.d_double;
        this->type_id = other.type_id;
    }
    else if (this->type_id == 2 && other.type_id == 5){
        this->i_int += other.c_char;
        this->type_id = 2;
    }
    else if (this->type_id == 2 && other.type_id == 6){
    }
    else if (this->type_id == 3 && other.type_id == 1){
        this->l_long += other.b_bool;
        this->type_id = 3;
    }
    else if (this->type_id == 3 && other.type_id == 2){
        this->l_long += other.i_int;
        this->type_id = 3;
    }
    else if (this->type_id == 3 && other.type_id == 3){
        this->l_long += other.l_long;
        this->type_id = other.type_id;
    }
    else if (this->type_id == 3 && other.type_id == 4){
        this->d_double += other.l_long;
        this->type_id = 4;
    }
    else if (this->type_id == 3 && other.type_id == 5){
        this->l_long += other.c_char;
        this->type_id = 3;
    }
    else if (this->type_id == 3 && other.type_id == 6){
    }
    else if (this->type_id == 4 && other.type_id == 1){
        this->d_double += other.b_bool;
        this->type_id = 4;
    }
    else if (this->type_id == 4 && other.type_id == 2){
        this->d_double += other.i_int;
        this->type_id = 4;
    }
    else if (this->type_id == 4 && other.type_id == 3){
        this->d_double += other.l_long;
        this->type_id = 4;
    }
    else if (this->type_id == 4 && other.type_id == 4){
        this->d_double += other.d_double;
        this->type_id = 4;
    }
    else if (this->type_id == 4 && other.type_id == 5){
        this->d_double += other.c_char;
        this->type_id = 4;
    }
    else if (this->type_id == 4 && other.type_id == 6){
    }
    else if (this->type_id == 5 && other.type_id == 1){
        this->c_char += other.b_bool;
        this->type_id = 5;
    }
    else if (this->type_id == 5 && other.type_id == 2){
        this->c_char += other.i_int;
        this->type_id = 5;
    }
    else if (this->type_id == 5 && other.type_id == 3){
        this->c_char += other.l_long;
        this->type_id = 5;
    }
    else if (this->type_id == 5 && other.type_id == 4){
        this->d_double += this->c_char + other.d_double;
        this->type_id = 4;
    }
    else if (this->type_id == 5 && other.type_id == 5){
        this->c_char += other.c_char;
        this->type_id = other.type_id;
    }
    else if (this->type_id == 5 && other.type_id == 6){
    }
    else if (this->type_id == 6 && other.type_id == 1){
    }
    else if (this->type_id == 6 && other.type_id == 2){
    }
    else if (this->type_id == 6 && other.type_id == 3){
    }
    else if (this->type_id == 6 && other.type_id == 4){
    }
    else if (this->type_id == 6 && other.type_id == 5){
    }
    else if (this->type_id == 6 && other.type_id == 6){
        const size_t size = this->length + other.length;
        reall_size(size);
        char *new_str = new char[this->capacit_y]{};
        for (size_t i = 0; i < size; i++){
            if (this->length > i){
                new_str[i] = this->cs_tr[i];
            }
            else{
                new_str[i] = other.cs_tr[i - this->length];
            }
        }
        delete [] this->cs_tr;
        this->cs_tr = new_str;
        this->length = size;
    }
    return *this;
}

var &var::operator-= (const var &other)
{
   // clea_unused_data(other.type_id);
    if (this->type_id == 1 && other.type_id == 1){
        this->b_bool -= other.b_bool;
        this->type_id = other.type_id;
    }
    else if (this->type_id == 1 && other.type_id == 2){
        this->i_int = this->b_bool - other.i_int;
        this->type_id = other.type_id;
    }
    else if (this->type_id == 1 && other.type_id == 3){
        this->l_long = this->b_bool - other.l_long;
        this->type_id = other.type_id;
    }
    else if (this->type_id == 1 && other.type_id == 4){
        this->d_double = this->b_bool - other.d_double;
        this->type_id = other.type_id;
    }
    else if (this->type_id == 1 && other.type_id == 5){
        this->c_char = this->b_bool - other.c_char;
        this->type_id = other.type_id;
    }
    else if (this->type_id == 1 && other.type_id == 6){
    }
    else if (this->type_id == 2 && other.type_id == 1){
        this->i_int -= other.b_bool;
        this->type_id = 2;
    }
    else if (this->type_id == 2 && other.type_id == 2){
        this->i_int -= other.i_int;
        this->type_id = other.type_id;
    }
    else if (this->type_id == 2 && other.type_id == 3){
        this->l_long = this->i_int - other.l_long;
        this->type_id = other.type_id;
    }
    else if (this->type_id == 2 && other.type_id == 4){
        this->d_double = this->i_int - other.d_double;
        this->type_id = other.type_id;
    }
    else if (this->type_id == 2 && other.type_id == 5){
        this->i_int -= other.c_char;
        this->type_id = 2;
    }
    else if (this->type_id == 2 && other.type_id == 6){
    }
    else if (this->type_id == 3 && other.type_id == 1){
        this->l_long -= other.b_bool;
        this->type_id = 3;
    }
    else if (this->type_id == 3 && other.type_id == 2){
        this->l_long -= other.i_int;
        this->type_id = 3;
    }
    else if (this->type_id == 3 && other.type_id == 3){
        this->l_long -= other.l_long;
        this->type_id = other.type_id;
    }
    else if (this->type_id == 3 && other.type_id == 4){
        this->d_double -= other.l_long;
        this->type_id = 4;
    }
    else if (this->type_id == 3 && other.type_id == 5){
        this->l_long -= other.c_char;
        this->type_id = 3;
    }
    else if (this->type_id == 3 && other.type_id == 6){
    }
    else if (this->type_id == 4 && other.type_id == 1){
        this->d_double -= other.b_bool;
        this->type_id = 4;
    }
    else if (this->type_id == 4 && other.type_id == 2){
        this->d_double -= other.i_int;
        this->type_id = 4;
    }
    else if (this->type_id == 4 && other.type_id == 3){
        this->d_double -= other.l_long;
        this->type_id = 4;
    }
    else if (this->type_id == 4 && other.type_id == 4){
        this->d_double -= other.d_double;
        this->type_id = 4;
    }
    else if (this->type_id == 4 && other.type_id == 5){
        this->d_double -= other.c_char;
        this->type_id = 4;
    }
    else if (this->type_id == 4 && other.type_id == 6){
    }
    else if (this->type_id == 5 && other.type_id == 1){
        this->c_char -= other.b_bool;
        this->type_id = 5;
    }
    else if (this->type_id == 5 && other.type_id == 2){
        this->c_char -= other.i_int;
        this->type_id = 5;
    }
    else if (this->type_id == 5 && other.type_id == 3){
        this->c_char -= other.l_long;
        this->type_id = 5;
    }
    else if (this->type_id == 5 && other.type_id == 4){
        this->d_double -= this->c_char - other.d_double;
        this->type_id = 4;
    }
    else if (this->type_id == 5 && other.type_id == 5){
        this->c_char -= other.c_char;
        this->type_id = other.type_id;
    }
    else if (this->type_id == 5 && other.type_id == 6){
    }
    else if (this->type_id == 6 && other.type_id == 1){
    }
    else if (this->type_id == 6 && other.type_id == 2){
    }
    else if (this->type_id == 6 && other.type_id == 3){
    }
    else if (this->type_id == 6 && other.type_id == 4){
    }
    else if (this->type_id == 6 && other.type_id == 5){
    }
    else if (this->type_id == 6 && other.type_id == 6){
    }
    
   // this->type_id = other.type_id;
    return *this;
}



var var::operator+ (const var &other)
{
    if (this->type_id == 1 && other.type_id == 1){
        return this->b_bool + other.b_bool;
    }
    else if (this->type_id == 1 && other.type_id == 2){
        return this->b_bool + other.i_int;
    }
    else if (this->type_id == 1 && other.type_id == 3){
        return this->b_bool + other.l_long;
    }
    else if (this->type_id == 1 && other.type_id == 4){
        return this->b_bool + other.d_double;
    }
    else if (this->type_id == 1 && other.type_id == 5){
        return this->b_bool + other.c_char;
    }
    else if (this->type_id == 1 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 2 && other.type_id == 1){
        return this->i_int + other.b_bool;
    }
    else if (this->type_id == 2 && other.type_id == 2){
        return this->i_int + other.i_int;
    }
    else if (this->type_id == 2 && other.type_id == 3){
        return this->i_int + other.l_long;
    }
    else if (this->type_id == 2 && other.type_id == 4){
        return this->i_int + other.d_double;
    }
    else if (this->type_id == 2 && other.type_id == 5){
        return this->i_int + other.c_char;
    }
    else if (this->type_id == 2 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 3 && other.type_id == 1){
        return this->l_long + other.b_bool;
    }
    else if (this->type_id == 3 && other.type_id == 2){
        return this->l_long + other.i_int;
    }
    else if (this->type_id == 3 && other.type_id == 3){
        return this->l_long + other.l_long;
    }
    else if (this->type_id == 3 && other.type_id == 4){
        return this->l_long + other.d_double;
    }
    else if (this->type_id == 3 && other.type_id == 5){
        return this->l_long + other.c_char;
    }
    else if (this->type_id == 3 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 4 && other.type_id == 1){
        return this->d_double + other.b_bool;
    }
    else if (this->type_id == 4 && other.type_id == 2){
        return this->d_double + other.i_int;
    }
    else if (this->type_id == 4 && other.type_id == 3){
        return this->d_double + other.l_long;
    }
    else if (this->type_id == 4 && other.type_id == 4){
        return this->d_double + other.d_double;
    }
    else if (this->type_id == 4 && other.type_id == 5){
        return this->d_double + other.c_char;
    }
    else if (this->type_id == 4 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 5 && other.type_id == 1){
        return this->c_char + other.b_bool;
    }
    else if (this->type_id == 5 && other.type_id == 2){
        return this->c_char + other.i_int;
    }
    else if (this->type_id == 5 && other.type_id == 3){
        return this->c_char + other.l_long;
    }
    else if (this->type_id == 5 && other.type_id == 4){
        return this->c_char + other.d_double;
    }
    else if (this->type_id == 5 && other.type_id == 5){
        return this->c_char + other.c_char;
    }
    else if (this->type_id == 5 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 6 && other.type_id == 1){

    }
    else if (this->type_id == 6 && other.type_id == 2){

    }
    else if (this->type_id == 6 && other.type_id == 3){

    }
    else if (this->type_id == 6 && other.type_id == 4){

    }
    else if (this->type_id == 6 && other.type_id == 5){

    }
    else if (this->type_id == 6 && other.type_id == 6){
        const size_t size = this->length + other.length;
        char new_str[size +1];
        for (size_t i = 0; i < size; i++){
            if (this->length > i){
                new_str[i] = this->cs_tr[i];
            }
            else{
                new_str[i] = other.cs_tr[i - this->length];
            }
        }
        new_str[size] = '\0';
        return new_str;
    }
    return *this;
}


var var::operator- (const var &other)
{
    if (this->type_id == 1 && other.type_id == 1){
        return this->b_bool - other.b_bool;
    }
    else if (this->type_id == 1 && other.type_id == 2){
        return this->b_bool - other.i_int;
    }
    else if (this->type_id == 1 && other.type_id == 3){
        return this->b_bool - other.l_long;
    }
    else if (this->type_id == 1 && other.type_id == 4){
        return this->b_bool - other.d_double;
    }
    else if (this->type_id == 1 && other.type_id == 5){
        return this->b_bool - other.c_char;
    }
    else if (this->type_id == 1 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 2 && other.type_id == 1){
        return this->i_int - other.b_bool;
    }
    else if (this->type_id == 2 && other.type_id == 2){
        return this->i_int - other.i_int;
    }
    else if (this->type_id == 2 && other.type_id == 3){
        return this->i_int - other.l_long;
    }
    else if (this->type_id == 2 && other.type_id == 4){
        return this->i_int - other.d_double;
    }
    else if (this->type_id == 2 && other.type_id == 5){
        return this->i_int - other.c_char;
    }
    else if (this->type_id == 2 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 3 && other.type_id == 1){
        return this->l_long - other.b_bool;
    }
    else if (this->type_id == 3 && other.type_id == 2){
        return this->l_long - other.i_int;
    }
    else if (this->type_id == 3 && other.type_id == 3){
        return this->l_long - other.l_long;
    }
    else if (this->type_id == 3 && other.type_id == 4){
        return this->l_long - other.d_double;
    }
    else if (this->type_id == 3 && other.type_id == 5){
        return this->l_long - other.c_char;
    }
    else if (this->type_id == 3 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 4 && other.type_id == 1){
        return this->d_double - other.b_bool;
    }
    else if (this->type_id == 4 && other.type_id == 2){
        return this->d_double - other.i_int;
    }
    else if (this->type_id == 4 && other.type_id == 3){
        return this->d_double - other.l_long;
    }
    else if (this->type_id == 4 && other.type_id == 4){
        return this->d_double - other.d_double;
    }
    else if (this->type_id == 4 && other.type_id == 5){
        return this->d_double - other.c_char;
    }
    else if (this->type_id == 4 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 5 && other.type_id == 1){
        return this->c_char - other.b_bool;
    }
    else if (this->type_id == 5 && other.type_id == 2){
        return this->c_char - other.i_int;
    }
    else if (this->type_id == 5 && other.type_id == 3){
        return this->c_char - other.l_long;
    }
    else if (this->type_id == 5 && other.type_id == 4){
        return this->c_char - other.d_double;
    }
    else if (this->type_id == 5 && other.type_id == 5){
        return this->c_char - other.c_char;
    }
    else if (this->type_id == 5 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 6 && other.type_id == 1){
        
    }
    else if (this->type_id == 6 && other.type_id == 2){
        
    }
    else if (this->type_id == 6 && other.type_id == 3){
        
    }
    else if (this->type_id == 6 && other.type_id == 4){
        
    }
    else if (this->type_id == 6 && other.type_id == 5){
        
    }
    else if (this->type_id == 6 && other.type_id == 6){
        // string
    }
    return *this;
}


var var::operator* (const var &other)
{
    if (this->type_id == 1 && other.type_id == 1){
        return this->b_bool * other.b_bool;
    }
    else if (this->type_id == 1 && other.type_id == 2){
        return this->b_bool * other.i_int;
    }
    else if (this->type_id == 1 && other.type_id == 3){
        return this->b_bool * other.l_long;
    }
    else if (this->type_id == 1 && other.type_id == 4){
        return this->b_bool * other.d_double;
    }
    else if (this->type_id == 1 && other.type_id == 5){
        return this->b_bool * other.c_char;
    }
    else if (this->type_id == 1 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 2 && other.type_id == 1){
        return this->i_int * other.b_bool;
    }
    else if (this->type_id == 2 && other.type_id == 2){
        return this->i_int * other.i_int;
    }
    else if (this->type_id == 2 && other.type_id == 3){
        return this->i_int * other.l_long;
    }
    else if (this->type_id == 2 && other.type_id == 4){
        return this->i_int * other.d_double;
    }
    else if (this->type_id == 2 && other.type_id == 5){
        return this->i_int * other.c_char;
    }
    else if (this->type_id == 2 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 3 && other.type_id == 1){
        return this->l_long * other.b_bool;
    }
    else if (this->type_id == 3 && other.type_id == 2){
        return this->l_long * other.i_int;
    }
    else if (this->type_id == 3 && other.type_id == 3){
        return this->l_long * other.l_long;
    }
    else if (this->type_id == 3 && other.type_id == 4){
        return this->l_long * other.d_double;
    }
    else if (this->type_id == 3 && other.type_id == 5){
        return this->l_long * other.c_char;
    }
    else if (this->type_id == 3 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 4 && other.type_id == 1){
        return this->d_double * other.b_bool;
    }
    else if (this->type_id == 4 && other.type_id == 2){
        return this->d_double * other.i_int;
    }
    else if (this->type_id == 4 && other.type_id == 3){
        return this->d_double * other.l_long;
    }
    else if (this->type_id == 4 && other.type_id == 4){
        return this->d_double * other.d_double;
    }
    else if (this->type_id == 4 && other.type_id == 5){
        return this->d_double * other.c_char;
    }
    else if (this->type_id == 4 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 5 && other.type_id == 1){
        return this->c_char * other.b_bool;
    }
    else if (this->type_id == 5 && other.type_id == 2){
        return this->c_char * other.i_int;
    }
    else if (this->type_id == 5 && other.type_id == 3){
        return this->c_char * other.l_long;
    }
    else if (this->type_id == 5 && other.type_id == 4){
        return this->c_char * other.d_double;
    }
    else if (this->type_id == 5 && other.type_id == 5){
        return this->c_char * other.c_char;
    }
    else if (this->type_id == 5 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 6 && other.type_id == 1){
        
    }
    else if (this->type_id == 6 && other.type_id == 2){
        
    }
    else if (this->type_id == 6 && other.type_id == 3){
        
    }
    else if (this->type_id == 6 && other.type_id == 4){
        
    }
    else if (this->type_id == 6 && other.type_id == 5){
        
    }
    else if (this->type_id == 6 && other.type_id == 6){
        // string
    }
    return *this;
}


var var::operator/ (const var &other)
{
    if (this->type_id == 1 && other.type_id == 1){
        return this->b_bool / other.b_bool;
    }
    else if (this->type_id == 1 && other.type_id == 2){
        return this->b_bool / other.i_int;
    }
    else if (this->type_id == 1 && other.type_id == 3){
        return this->b_bool / other.l_long;
    }
    else if (this->type_id == 1 && other.type_id == 4){
        return this->b_bool / other.d_double;
    }
    else if (this->type_id == 1 && other.type_id == 5){
        return this->b_bool / other.c_char;
    }
    else if (this->type_id == 1 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 2 && other.type_id == 1){
        return this->i_int / other.b_bool;
    }
    else if (this->type_id == 2 && other.type_id == 2){
        return this->i_int / other.i_int;
    }
    else if (this->type_id == 2 && other.type_id == 3){
        return this->i_int / other.l_long;
    }
    else if (this->type_id == 2 && other.type_id == 4){
        return this->i_int / other.d_double;
    }
    else if (this->type_id == 2 && other.type_id == 5){
        return this->i_int / other.c_char;
    }
    else if (this->type_id == 2 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 3 && other.type_id == 1){
        return this->l_long / other.b_bool;
    }
    else if (this->type_id == 3 && other.type_id == 2){
        return this->l_long / other.i_int;
    }
    else if (this->type_id == 3 && other.type_id == 3){
        return this->l_long / other.l_long;
    }
    else if (this->type_id == 3 && other.type_id == 4){
        return this->l_long / other.d_double;
    }
    else if (this->type_id == 3 && other.type_id == 5){
        return this->l_long / other.c_char;
    }
    else if (this->type_id == 3 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 4 && other.type_id == 1){
        return this->d_double / other.b_bool;
    }
    else if (this->type_id == 4 && other.type_id == 2){
        return this->d_double / other.i_int;
    }
    else if (this->type_id == 4 && other.type_id == 3){
        return this->d_double / other.l_long;
    }
    else if (this->type_id == 4 && other.type_id == 4){
        return this->d_double / other.d_double;
    }
    else if (this->type_id == 4 && other.type_id == 5){
        return this->d_double / other.c_char;
    }
    else if (this->type_id == 4 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 5 && other.type_id == 1){
        return this->c_char / other.b_bool;
    }
    else if (this->type_id == 5 && other.type_id == 2){
        return this->c_char / other.i_int;
    }
    else if (this->type_id == 5 && other.type_id == 3){
        return this->c_char / other.l_long;
    }
    else if (this->type_id == 5 && other.type_id == 4){
        return this->c_char / other.d_double;
    }
    else if (this->type_id == 5 && other.type_id == 5){
        return this->c_char / other.c_char;
    }
    else if (this->type_id == 5 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 6 && other.type_id == 1){
        
    }
    else if (this->type_id == 6 && other.type_id == 2){
        
    }
    else if (this->type_id == 6 && other.type_id == 3){
        
    }
    else if (this->type_id == 6 && other.type_id == 4){
        
    }
    else if (this->type_id == 6 && other.type_id == 5){
        
    }
    else if (this->type_id == 6 && other.type_id == 6){
        // string
    }
    return *this;
}


var var::operator% (const var &other)
{
    if (this->type_id == 1 && other.type_id == 1){
        return this->b_bool % other.b_bool;
    }
    else if (this->type_id == 1 && other.type_id == 2){
        return this->b_bool % other.i_int;
    }
    else if (this->type_id == 1 && other.type_id == 3){
        return this->b_bool % other.l_long;
    }
    else if (this->type_id == 1 && other.type_id == 4){
     //   return this->b_bool % other.d_double;
    }
    else if (this->type_id == 1 && other.type_id == 5){
        return this->b_bool % other.c_char;
    }
    else if (this->type_id == 1 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 2 && other.type_id == 1){
        return this->i_int % other.b_bool;
    }
    else if (this->type_id == 2 && other.type_id == 2){
        return this->i_int % other.i_int;
    }
    else if (this->type_id == 2 && other.type_id == 3){
        return this->i_int % other.l_long;
    }
    else if (this->type_id == 2 && other.type_id == 4){
 //       return this->i_int % other.d_double;
    }
    else if (this->type_id == 2 && other.type_id == 5){
        return this->i_int % other.c_char;
    }
    else if (this->type_id == 2 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 3 && other.type_id == 1){
        return this->l_long % other.b_bool;
    }
    else if (this->type_id == 3 && other.type_id == 2){
        return this->l_long % other.i_int;
    }
    else if (this->type_id == 3 && other.type_id == 3){
        return this->l_long % other.l_long;
    }
    else if (this->type_id == 3 && other.type_id == 4){
 //       return this->l_long % other.d_double;
    }
    else if (this->type_id == 3 && other.type_id == 5){
        return this->l_long % other.c_char;
    }
    else if (this->type_id == 3 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 4 && other.type_id == 1){
  //      return this->d_double % other.b_bool;
    }
    else if (this->type_id == 4 && other.type_id == 2){
   //     return this->d_double % other.i_int;
    }
    else if (this->type_id == 4 && other.type_id == 3){
   //     return this->d_double % other.l_long;
    }
    else if (this->type_id == 4 && other.type_id == 4){
    //    return this->d_double % other.d_double;
    }
    else if (this->type_id == 4 && other.type_id == 5){
    //    return this->d_double % other.c_char;
    }
    else if (this->type_id == 4 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 5 && other.type_id == 1){
        return this->c_char % other.b_bool;
    }
    else if (this->type_id == 5 && other.type_id == 2){
        return this->c_char % other.i_int;
    }
    else if (this->type_id == 5 && other.type_id == 3){
        return this->c_char % other.l_long;
    }
    else if (this->type_id == 5 && other.type_id == 4){
    //    return this->c_char % other.d_double;
    }
    else if (this->type_id == 5 && other.type_id == 5){
        return this->c_char % other.c_char;
    }
    else if (this->type_id == 5 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 6 && other.type_id == 1){
        
    }
    else if (this->type_id == 6 && other.type_id == 2){
        
    }
    else if (this->type_id == 6 && other.type_id == 3){
        
    }
    else if (this->type_id == 6 && other.type_id == 4){
        
    }
    else if (this->type_id == 6 && other.type_id == 5){
        
    }
    else if (this->type_id == 6 && other.type_id == 6){
        // string
    }
    return *this;
}

void var::override_datatype_more()
{
    this->type_id = 3;
    this->l_long = this->i_int;
    this->i_int = 0;
}

var var::operator++ (int)
{
    if (this->i_int == 2147483647){
        override_datatype_more();
    }
    
    if (this->type_id == 1){
        this->b_bool += 1;
    }
    else if (this->type_id == 2){
        this->i_int++;
    }
    else if (this->type_id == 3){
        this->l_long++;
    }
    else if (this->type_id == 4){
        this->d_double++;
    }
    else if (this->type_id == 5){
        this->c_char++;
    }
    else if (this->type_id == 6){
        // string
    }
    return *this;
}

void var::override_datatype_less()
{
    this->type_id = 2;
    this->i_int = (int)this->l_long;
    this->l_long = 0;
}


var var::operator-- (int)
{
    if (this->l_long == 2147483647){
        override_datatype_less();
    }
    
    if (this->type_id == 1){
        this->b_bool -= 1;
    }
    else if (this->type_id == 2){
        this->i_int--;
    }
    else if (this->type_id == 3){
        this->l_long--;
    }
    else if (this->type_id == 4){
        this->d_double--;
    }
    else if (this->type_id == 5){
        this->c_char--;
    }
    else if (this->type_id == 6){
        // string
    }
    return *this;
}


bool var::operator< (const var &other)
{
    if (this->type_id == 1 && other.type_id == 1){
        return (this->b_bool < other.b_bool);
    }
    else if (this->type_id == 1 && other.type_id == 2){
        return (this->b_bool < other.i_int);
    }
    else if (this->type_id == 1 && other.type_id == 3){
        return (this->b_bool < other.l_long);
    }
    else if (this->type_id == 1 && other.type_id == 4){
        return (this->b_bool < other.d_double);
    }
    else if (this->type_id == 1 && other.type_id == 5){
        return (this->b_bool < other.c_char);
    }
    else if (this->type_id == 1 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 2 && other.type_id == 1){
        return (this->i_int < other.b_bool);
    }
    else if (this->type_id == 2 && other.type_id == 2){
        return (this->i_int < other.i_int);
    }
    else if (this->type_id == 2 && other.type_id == 3){
        return (this->i_int < other.l_long);
    }
    else if (this->type_id == 2 && other.type_id == 4){
        return (this->i_int < other.d_double);
    }
    else if (this->type_id == 2 && other.type_id == 5){
        return (this->i_int < other.c_char);
    }
    else if (this->type_id == 2 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 3 && other.type_id == 1){
        return (this->l_long < other.b_bool);
    }
    else if (this->type_id == 3 && other.type_id == 2){
        return (this->l_long < other.i_int);
    }
    else if (this->type_id == 3 && other.type_id == 3){
        return (this->l_long < other.l_long);
    }
    else if (this->type_id == 3 && other.type_id == 4){
        return (this->l_long < other.d_double);
    }
    else if (this->type_id == 3 && other.type_id == 5){
        return (this->l_long < other.c_char);
    }
    else if (this->type_id == 3 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 4 && other.type_id == 1){
        return (this->d_double < other.b_bool);
    }
    else if (this->type_id == 4 && other.type_id == 2){
        return (this->d_double < other.i_int);
    }
    else if (this->type_id == 4 && other.type_id == 3){
        return (this->d_double < other.l_long);
    }
    else if (this->type_id == 4 && other.type_id == 4){
        return (this->d_double < other.d_double);
    }
    else if (this->type_id == 4 && other.type_id == 5){
        return (this->d_double < other.c_char);
    }
    else if (this->type_id == 4 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 5 && other.type_id == 1){
        return (this->c_char < other.b_bool);
    }
    else if (this->type_id == 5 && other.type_id == 2){
        return (this->c_char < other.i_int);
    }
    else if (this->type_id == 5 && other.type_id == 3){
        return (this->c_char < other.l_long);
    }
    else if (this->type_id == 5 && other.type_id == 4){
        return (this->c_char < other.d_double);
    }
    else if (this->type_id == 5 && other.type_id == 5){
        return (this->c_char < other.c_char);
    }
    else if (this->type_id == 5 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 6 && other.type_id == 1){
        
    }
    else if (this->type_id == 6 && other.type_id == 2){
        
    }
    else if (this->type_id == 6 && other.type_id == 3){
        
    }
    else if (this->type_id == 6 && other.type_id == 4){
        
    }
    else if (this->type_id == 6 && other.type_id == 5){
        
    }
    else if (this->type_id == 6 && other.type_id == 6){
        // string
    }
    
    return 0;
}

bool operator< (var &other1, var &other2){
    if (other1.type_id == 1 && other2.type_id == 1){
        return (other1.b_bool < other2.b_bool);
    }
    else if (other1.type_id == 1 && other2.type_id == 2){
        return (other1.b_bool < other2.i_int);
    }
    else if (other1.type_id == 1 && other2.type_id == 3){
        return (other1.b_bool < other2.l_long);
    }
    else if (other1.type_id == 1 && other2.type_id == 4){
        return (other1.b_bool < other2.d_double);
    }
    else if (other1.type_id == 1 && other2.type_id == 5){
        return (other1.b_bool < other2.c_char);
    }
    else if (other1.type_id == 1 && other2.type_id == 6){
        // string
    }
    else if (other1.type_id == 2 && other2.type_id == 1){
        return (other1.i_int < other2.b_bool);
    }
    else if (other1.type_id == 2 && other2.type_id == 2){
        return (other1.i_int < other2.i_int);
    }
    else if (other1.type_id == 2 && other2.type_id == 3){
        return (other1.i_int < other2.l_long);
    }
    else if (other1.type_id == 2 && other2.type_id == 4){
        return (other1.i_int < other2.d_double);
    }
    else if (other1.type_id == 2 && other2.type_id == 5){
        return (other1.i_int < other2.c_char);
    }
    else if (other1.type_id == 2 && other2.type_id == 6){
        // string
    }
    else if (other1.type_id == 3 && other2.type_id == 1){
        return (other1.l_long < other2.b_bool);
    }
    else if (other1.type_id == 3 && other2.type_id == 2){
        return (other1.l_long < other2.i_int);
    }
    else if (other1.type_id == 3 && other2.type_id == 3){
        return (other1.l_long < other2.l_long);
    }
    else if (other1.type_id == 3 && other2.type_id == 4){
        return (other1.l_long < other2.d_double);
    }
    else if (other1.type_id == 3 && other2.type_id == 5){
        return (other1.l_long < other2.c_char);
    }
    else if (other1.type_id == 3 && other2.type_id == 6){
        // string
    }
    else if (other1.type_id == 4 && other2.type_id == 1){
        return (other1.d_double < other2.b_bool);
    }
    else if (other1.type_id == 4 && other2.type_id == 2){
        return (other1.d_double < other2.i_int);
    }
    else if (other1.type_id == 4 && other2.type_id == 3){
        return (other1.d_double < other2.l_long);
    }
    else if (other1.type_id == 4 && other2.type_id == 4){
        return (other1.d_double < other2.d_double);
    }
    else if (other1.type_id == 4 && other2.type_id == 5){
        return (other1.d_double < other2.c_char);
    }
    else if (other1.type_id == 4 && other2.type_id == 6){
        // string
    }
    else if (other1.type_id == 5 && other2.type_id == 1){
        return (other1.c_char < other2.b_bool);
    }
    else if (other1.type_id == 5 && other2.type_id == 2){
        return (other1.c_char < other2.i_int);
    }
    else if (other1.type_id == 5 && other2.type_id == 3){
        return (other1.c_char < other2.l_long);
    }
    else if (other1.type_id == 5 && other2.type_id == 4){
        return (other1.c_char < other2.d_double);
    }
    else if (other1.type_id == 5 && other2.type_id == 5){
        return (other1.c_char < other2.c_char);
    }
    else if (other1.type_id == 5 && other2.type_id == 6){
        // string
    }
    else if (other1.type_id == 6 && other2.type_id == 1){
        
    }
    else if (other1.type_id == 6 && other2.type_id == 2){
        
    }
    else if (other1.type_id == 6 && other2.type_id == 3){
        
    }
    else if (other1.type_id == 6 && other2.type_id == 4){
        
    }
    else if (other1.type_id == 6 && other2.type_id == 5){
        
    }
    else if (other1.type_id == 6 && other2.type_id == 6){
        size_t size_a = 0;
        size_t size_b = 0;
        for (size_t i = 0; i < other1.length; i++){
            size_a += other1.cs_tr[i];
        }
        for (size_t i = 0; i < other2.length; i++){
            size_b += other2.cs_tr[i];
        }
        
        if (size_a < size_b){
            return true;
        }
        else{
            return false;
        }
        
    }
    return 0;
}


bool var::operator> (const var &other)
{
    if (this->type_id == 1 && other.type_id == 1){
        return (this->b_bool > other.b_bool);
    }
    else if (this->type_id == 1 && other.type_id == 2){
        return (this->b_bool > other.i_int);
    }
    else if (this->type_id == 1 && other.type_id == 3){
        return (this->b_bool > other.l_long);
    }
    else if (this->type_id == 1 && other.type_id == 4){
        return (this->b_bool > other.d_double);
    }
    else if (this->type_id == 1 && other.type_id == 5){
        return (this->b_bool > other.c_char);
    }
    else if (this->type_id == 1 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 2 && other.type_id == 1){
        return (this->i_int > other.b_bool);
    }
    else if (this->type_id == 2 && other.type_id == 2){
        return (this->i_int > other.i_int);
    }
    else if (this->type_id == 2 && other.type_id == 3){
        return (this->i_int > other.l_long);
    }
    else if (this->type_id == 2 && other.type_id == 4){
        return (this->i_int > other.d_double);
    }
    else if (this->type_id == 2 && other.type_id == 5){
        return (this->i_int > other.c_char);
    }
    else if (this->type_id == 2 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 3 && other.type_id == 1){
        return (this->l_long > other.b_bool);
    }
    else if (this->type_id == 3 && other.type_id == 2){
        return (this->l_long > other.i_int);
    }
    else if (this->type_id == 3 && other.type_id == 3){
        return (this->l_long > other.l_long);
    }
    else if (this->type_id == 3 && other.type_id == 4){
        return (this->l_long > other.d_double);
    }
    else if (this->type_id == 3 && other.type_id == 5){
        return (this->l_long > other.c_char);
    }
    else if (this->type_id == 3 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 4 && other.type_id == 1){
        return (this->d_double > other.b_bool);
    }
    else if (this->type_id == 4 && other.type_id == 2){
        return (this->d_double > other.i_int);
    }
    else if (this->type_id == 4 && other.type_id == 3){
        return (this->d_double > other.l_long);
    }
    else if (this->type_id == 4 && other.type_id == 4){
        return (this->d_double > other.d_double);
    }
    else if (this->type_id == 4 && other.type_id == 5){
        return (this->d_double > other.c_char);
    }
    else if (this->type_id == 4 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 5 && other.type_id == 1){
        return (this->c_char > other.b_bool);
    }
    else if (this->type_id == 5 && other.type_id == 2){
        return (this->c_char > other.i_int);
    }
    else if (this->type_id == 5 && other.type_id == 3){
        return (this->c_char > other.l_long);
    }
    else if (this->type_id == 5 && other.type_id == 4){
        return (this->c_char > other.d_double);
    }
    else if (this->type_id == 5 && other.type_id == 5){
        return (this->c_char > other.c_char);
    }
    else if (this->type_id == 5 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 6 && other.type_id == 1){
        
    }
    else if (this->type_id == 6 && other.type_id == 2){
        
    }
    else if (this->type_id == 6 && other.type_id == 3){
        
    }
    else if (this->type_id == 6 && other.type_id == 4){
        
    }
    else if (this->type_id == 6 && other.type_id == 5){
        
    }
    else if (this->type_id == 6 && other.type_id == 6){
        // string
    }
    
    return 0;
}

bool operator> (var &other1, var &other2){
    if (other1.type_id == 1 && other2.type_id == 1){
        return (other1.b_bool > other2.b_bool);
    }
    else if (other1.type_id == 1 && other2.type_id == 2){
        return (other1.b_bool > other2.i_int);
    }
    else if (other1.type_id == 1 && other2.type_id == 3){
        return (other1.b_bool > other2.l_long);
    }
    else if (other1.type_id == 1 && other2.type_id == 4){
        return (other1.b_bool > other2.d_double);
    }
    else if (other1.type_id == 1 && other2.type_id == 5){
        return (other1.b_bool > other2.c_char);
    }
    else if (other1.type_id == 1 && other2.type_id == 6){
        // string
    }
    else if (other1.type_id == 2 && other2.type_id == 1){
        return (other1.i_int > other2.b_bool);
    }
    else if (other1.type_id == 2 && other2.type_id == 2){
        return (other1.i_int > other2.i_int);
    }
    else if (other1.type_id == 2 && other2.type_id == 3){
        return (other1.i_int > other2.l_long);
    }
    else if (other1.type_id == 2 && other2.type_id == 4){
        return (other1.i_int > other2.d_double);
    }
    else if (other1.type_id == 2 && other2.type_id == 5){
        return (other1.i_int > other2.c_char);
    }
    else if (other1.type_id == 2 && other2.type_id == 6){
        // string
    }
    else if (other1.type_id == 3 && other2.type_id == 1){
        return (other1.l_long > other2.b_bool);
    }
    else if (other1.type_id == 3 && other2.type_id == 2){
        return (other1.l_long > other2.i_int);
    }
    else if (other1.type_id == 3 && other2.type_id == 3){
        return (other1.l_long > other2.l_long);
    }
    else if (other1.type_id == 3 && other2.type_id == 4){
        return (other1.l_long > other2.d_double);
    }
    else if (other1.type_id == 3 && other2.type_id == 5){
        return (other1.l_long > other2.c_char);
    }
    else if (other1.type_id == 3 && other2.type_id == 6){
        // string
    }
    else if (other1.type_id == 4 && other2.type_id == 1){
        return (other1.d_double > other2.b_bool);
    }
    else if (other1.type_id == 4 && other2.type_id == 2){
        return (other1.d_double > other2.i_int);
    }
    else if (other1.type_id == 4 && other2.type_id == 3){
        return (other1.d_double > other2.l_long);
    }
    else if (other1.type_id == 4 && other2.type_id == 4){
        return (other1.d_double > other2.d_double);
    }
    else if (other1.type_id == 4 && other2.type_id == 5){
        return (other1.d_double > other2.c_char);
    }
    else if (other1.type_id == 4 && other2.type_id == 6){
        // string
    }
    else if (other1.type_id == 5 && other2.type_id == 1){
        return (other1.c_char > other2.b_bool);
    }
    else if (other1.type_id == 5 && other2.type_id == 2){
        return (other1.c_char > other2.i_int);
    }
    else if (other1.type_id == 5 && other2.type_id == 3){
        return (other1.c_char > other2.l_long);
    }
    else if (other1.type_id == 5 && other2.type_id == 4){
        return (other1.c_char > other2.d_double);
    }
    else if (other1.type_id == 5 && other2.type_id == 5){
        return (other1.c_char > other2.c_char);
    }
    else if (other1.type_id == 5 && other2.type_id == 6){
        // string
    }
    else if (other1.type_id == 6 && other2.type_id == 1){
        
    }
    else if (other1.type_id == 6 && other2.type_id == 2){
        
    }
    else if (other1.type_id == 6 && other2.type_id == 3){
        
    }
    else if (other1.type_id == 6 && other2.type_id == 4){
        
    }
    else if (other1.type_id == 6 && other2.type_id == 5){
        
    }
    else if (other1.type_id == 6 && other2.type_id == 6){
        size_t size_a = 0;
        size_t size_b = 0;
        for (size_t i = 0; i < other1.length; i++){
            size_a += other1.cs_tr[i];
        }
        for (size_t i = 0; i < other2.length; i++){
            size_b += other2.cs_tr[i];
        }
        
        if (size_a > size_b){
            return true;
        }
        else{
            return false;
        }
    }
    return other1.b_bool;
}



bool var::operator<= (const var &other)
{
    if (this->type_id == 1 && other.type_id == 1){
        return (this->b_bool <= other.b_bool);
    }
    else if (this->type_id == 1 && other.type_id == 2){
        return (this->b_bool <= other.i_int);
    }
    else if (this->type_id == 1 && other.type_id == 3){
        return (this->b_bool <= other.l_long);
    }
    else if (this->type_id == 1 && other.type_id == 4){
        return (this->b_bool <= other.d_double);
    }
    else if (this->type_id == 1 && other.type_id == 5){
        return (this->b_bool <= other.c_char);
    }
    else if (this->type_id == 1 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 2 && other.type_id == 1){
        return (this->i_int <= other.b_bool);
    }
    else if (this->type_id == 2 && other.type_id == 2){
        return (this->i_int <= other.i_int);
    }
    else if (this->type_id == 2 && other.type_id == 3){
        return (this->i_int <= other.l_long);
    }
    else if (this->type_id == 2 && other.type_id == 4){
        return (this->i_int <= other.d_double);
    }
    else if (this->type_id == 2 && other.type_id == 5){
        return (this->i_int <= other.c_char);
    }
    else if (this->type_id == 2 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 3 && other.type_id == 1){
        return (this->l_long <= other.b_bool);
    }
    else if (this->type_id == 3 && other.type_id == 2){
        return (this->l_long <= other.i_int);
    }
    else if (this->type_id == 3 && other.type_id == 3){
        return (this->l_long <= other.l_long);
    }
    else if (this->type_id == 3 && other.type_id == 4){
        return (this->l_long <= other.d_double);
    }
    else if (this->type_id == 3 && other.type_id == 5){
        return (this->l_long <= other.c_char);
    }
    else if (this->type_id == 3 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 4 && other.type_id == 1){
        return (this->d_double <= other.b_bool);
    }
    else if (this->type_id == 4 && other.type_id == 2){
        return (this->d_double <= other.i_int);
    }
    else if (this->type_id == 4 && other.type_id == 3){
        return (this->d_double <= other.l_long);
    }
    else if (this->type_id == 4 && other.type_id == 4){
        return (this->d_double <= other.d_double);
    }
    else if (this->type_id == 4 && other.type_id == 5){
        return (this->d_double <= other.c_char);
    }
    else if (this->type_id == 4 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 5 && other.type_id == 1){
        return (this->c_char <= other.b_bool);
    }
    else if (this->type_id == 5 && other.type_id == 2){
        return (this->c_char <= other.i_int);
    }
    else if (this->type_id == 5 && other.type_id == 3){
        return (this->c_char <= other.l_long);
    }
    else if (this->type_id == 5 && other.type_id == 4){
        return (this->c_char <= other.d_double);
    }
    else if (this->type_id == 5 && other.type_id == 5){
        return (this->c_char <= other.c_char);
    }
    else if (this->type_id == 5 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 6 && other.type_id == 1){
        
    }
    else if (this->type_id == 6 && other.type_id == 2){
        
    }
    else if (this->type_id == 6 && other.type_id == 3){
        
    }
    else if (this->type_id == 6 && other.type_id == 4){
        
    }
    else if (this->type_id == 6 && other.type_id == 5){
        
    }
    else if (this->type_id == 6 && other.type_id == 6){

    }
    
    return 0;
}

bool operator<= (var &other1, var &other2){
    if (other1.type_id == 1 && other2.type_id == 1){
        return (other1.b_bool <= other2.b_bool);
    }
    else if (other1.type_id == 1 && other2.type_id == 2){
        return (other1.b_bool <= other2.i_int);
    }
    else if (other1.type_id == 1 && other2.type_id == 3){
        return (other1.b_bool <= other2.l_long);
    }
    else if (other1.type_id == 1 && other2.type_id == 4){
        return (other1.b_bool <= other2.d_double);
    }
    else if (other1.type_id == 1 && other2.type_id == 5){
        return (other1.b_bool <= other2.c_char);
    }
    else if (other1.type_id == 1 && other2.type_id == 6){
        // string
    }
    else if (other1.type_id == 2 && other2.type_id == 1){
        return (other1.i_int <= other2.b_bool);
    }
    else if (other1.type_id == 2 && other2.type_id == 2){
        return (other1.i_int <= other2.i_int);
    }
    else if (other1.type_id == 2 && other2.type_id == 3){
        return (other1.i_int <= other2.l_long);
    }
    else if (other1.type_id == 2 && other2.type_id == 4){
        return (other1.i_int <= other2.d_double);
    }
    else if (other1.type_id == 2 && other2.type_id == 5){
        return (other1.i_int <= other2.c_char);
    }
    else if (other1.type_id == 2 && other2.type_id == 6){
        // string
    }
    else if (other1.type_id == 3 && other2.type_id == 1){
        return (other1.l_long <= other2.b_bool);
    }
    else if (other1.type_id == 3 && other2.type_id == 2){
        return (other1.l_long <= other2.i_int);
    }
    else if (other1.type_id == 3 && other2.type_id == 3){
        return (other1.l_long <= other2.l_long);
    }
    else if (other1.type_id == 3 && other2.type_id == 4){
        return (other1.l_long <= other2.d_double);
    }
    else if (other1.type_id == 3 && other2.type_id == 5){
        return (other1.l_long <= other2.c_char);
    }
    else if (other1.type_id == 3 && other2.type_id == 6){
        // string
    }
    else if (other1.type_id == 4 && other2.type_id == 1){
        return (other1.d_double <= other2.b_bool);
    }
    else if (other1.type_id == 4 && other2.type_id == 2){
        return (other1.d_double <= other2.i_int);
    }
    else if (other1.type_id == 4 && other2.type_id == 3){
        return (other1.d_double <= other2.l_long);
    }
    else if (other1.type_id == 4 && other2.type_id == 4){
        return (other1.d_double <= other2.d_double);
    }
    else if (other1.type_id == 4 && other2.type_id == 5){
        return (other1.d_double <= other2.c_char);
    }
    else if (other1.type_id == 4 && other2.type_id == 6){
        // string
    }
    else if (other1.type_id == 5 && other2.type_id == 1){
        return (other1.c_char <= other2.b_bool);
    }
    else if (other1.type_id == 5 && other2.type_id == 2){
        return (other1.c_char <= other2.i_int);
    }
    else if (other1.type_id == 5 && other2.type_id == 3){
        return (other1.c_char <= other2.l_long);
    }
    else if (other1.type_id == 5 && other2.type_id == 4){
        return (other1.c_char <= other2.d_double);
    }
    else if (other1.type_id == 5 && other2.type_id == 5){
        return (other1.c_char <= other2.c_char);
    }
    else if (other1.type_id == 5 && other2.type_id == 6){
        // string
    }
    else if (other1.type_id == 6 && other2.type_id == 1){
        
    }
    else if (other1.type_id == 6 && other2.type_id == 2){
        
    }
    else if (other1.type_id == 6 && other2.type_id == 3){
        
    }
    else if (other1.type_id == 6 && other2.type_id == 4){
        
    }
    else if (other1.type_id == 6 && other2.type_id == 5){
        
    }
    else if (other1.type_id == 6 && other2.type_id == 6){
        size_t size_a = 0;
        size_t size_b = 0;
        for (size_t i = 0; i < other1.length; i++){
            size_a += other1.cs_tr[i];
        }
        for (size_t i = 0; i < other2.length; i++){
            size_b += other2.cs_tr[i];
        }
        
        if (size_a <= size_b){
            return true;
        }
        else{
            return false;
        }
    }
    return other1.b_bool;
}



bool var::operator>= (const var &other)
{
    if (this->type_id == 1 && other.type_id == 1){
        return (this->b_bool >= other.b_bool);
    }
    else if (this->type_id == 1 && other.type_id == 2){
        return (this->b_bool >= other.i_int);
    }
    else if (this->type_id == 1 && other.type_id == 3){
        return (this->b_bool >= other.l_long);
    }
    else if (this->type_id == 1 && other.type_id == 4){
        return (this->b_bool >= other.d_double);
    }
    else if (this->type_id == 1 && other.type_id == 5){
        return (this->b_bool >= other.c_char);
    }
    else if (this->type_id == 1 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 2 && other.type_id == 1){
        return (this->i_int >= other.b_bool);
    }
    else if (this->type_id == 2 && other.type_id == 2){
        return (this->i_int >= other.i_int);
    }
    else if (this->type_id == 2 && other.type_id == 3){
        return (this->i_int >= other.l_long);
    }
    else if (this->type_id == 2 && other.type_id == 4){
        return (this->i_int >= other.d_double);
    }
    else if (this->type_id == 2 && other.type_id == 5){
        return (this->i_int >= other.c_char);
    }
    else if (this->type_id == 2 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 3 && other.type_id == 1){
        return (this->l_long >= other.b_bool);
    }
    else if (this->type_id == 3 && other.type_id == 2){
        return (this->l_long >= other.i_int);
    }
    else if (this->type_id == 3 && other.type_id == 3){
        return (this->l_long >= other.l_long);
    }
    else if (this->type_id == 3 && other.type_id == 4){
        return (this->l_long >= other.d_double);
    }
    else if (this->type_id == 3 && other.type_id == 5){
        return (this->l_long >= other.c_char);
    }
    else if (this->type_id == 3 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 4 && other.type_id == 1){
        return (this->d_double >= other.b_bool);
    }
    else if (this->type_id == 4 && other.type_id == 2){
        return (this->d_double >= other.i_int);
    }
    else if (this->type_id == 4 && other.type_id == 3){
        return (this->d_double >= other.l_long);
    }
    else if (this->type_id == 4 && other.type_id == 4){
        return (this->d_double >= other.d_double);
    }
    else if (this->type_id == 4 && other.type_id == 5){
        return (this->d_double >= other.c_char);
    }
    else if (this->type_id == 4 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 5 && other.type_id == 1){
        return (this->c_char >= other.b_bool);
    }
    else if (this->type_id == 5 && other.type_id == 2){
        return (this->c_char >= other.i_int);
    }
    else if (this->type_id == 5 && other.type_id == 3){
        return (this->c_char >= other.l_long);
    }
    else if (this->type_id == 5 && other.type_id == 4){
        return (this->c_char >= other.d_double);
    }
    else if (this->type_id == 5 && other.type_id == 5){
        return (this->c_char >= other.c_char);
    }
    else if (this->type_id == 5 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 6 && other.type_id == 1){
        
    }
    else if (this->type_id == 6 && other.type_id == 2){
        
    }
    else if (this->type_id == 6 && other.type_id == 3){
        
    }
    else if (this->type_id == 6 && other.type_id == 4){
        
    }
    else if (this->type_id == 6 && other.type_id == 5){
        
    }
    else if (this->type_id == 6 && other.type_id == 6){
        // string
    }
    
    return 0;
}

bool operator>= (var &other1, var &other2){
    if (other1.type_id == 1 && other2.type_id == 1){
        return (other1.b_bool >= other2.b_bool);
    }
    else if (other1.type_id == 1 && other2.type_id == 2){
        return (other1.b_bool >= other2.i_int);
    }
    else if (other1.type_id == 1 && other2.type_id == 3){
        return (other1.b_bool >= other2.l_long);
    }
    else if (other1.type_id == 1 && other2.type_id == 4){
        return (other1.b_bool >= other2.d_double);
    }
    else if (other1.type_id == 1 && other2.type_id == 5){
        return (other1.b_bool >= other2.c_char);
    }
    else if (other1.type_id == 1 && other2.type_id == 6){
        // string
    }
    else if (other1.type_id == 2 && other2.type_id == 1){
        return (other1.i_int >= other2.b_bool);
    }
    else if (other1.type_id == 2 && other2.type_id == 2){
        return (other1.i_int >= other2.i_int);
    }
    else if (other1.type_id == 2 && other2.type_id == 3){
        return (other1.i_int >= other2.l_long);
    }
    else if (other1.type_id == 2 && other2.type_id == 4){
        return (other1.i_int >= other2.d_double);
    }
    else if (other1.type_id == 2 && other2.type_id == 5){
        return (other1.i_int >= other2.c_char);
    }
    else if (other1.type_id == 2 && other2.type_id == 6){
        // string
    }
    else if (other1.type_id == 3 && other2.type_id == 1){
        return (other1.l_long >= other2.b_bool);
    }
    else if (other1.type_id == 3 && other2.type_id == 2){
        return (other1.l_long >= other2.i_int);
    }
    else if (other1.type_id == 3 && other2.type_id == 3){
        return (other1.l_long >= other2.l_long);
    }
    else if (other1.type_id == 3 && other2.type_id == 4){
        return (other1.l_long >= other2.d_double);
    }
    else if (other1.type_id == 3 && other2.type_id == 5){
        return (other1.l_long >= other2.c_char);
    }
    else if (other1.type_id == 3 && other2.type_id == 6){
        // string
    }
    else if (other1.type_id == 4 && other2.type_id == 1){
        return (other1.d_double >= other2.b_bool);
    }
    else if (other1.type_id == 4 && other2.type_id == 2){
        return (other1.d_double >= other2.i_int);
    }
    else if (other1.type_id == 4 && other2.type_id == 3){
        return (other1.d_double >= other2.l_long);
    }
    else if (other1.type_id == 4 && other2.type_id == 4){
        return (other1.d_double >= other2.d_double);
    }
    else if (other1.type_id == 4 && other2.type_id == 5){
        return (other1.d_double >= other2.c_char);
    }
    else if (other1.type_id == 4 && other2.type_id == 6){
        // string
    }
    else if (other1.type_id == 5 && other2.type_id == 1){
        return (other1.c_char >= other2.b_bool);
    }
    else if (other1.type_id == 5 && other2.type_id == 2){
        return (other1.c_char >= other2.i_int);
    }
    else if (other1.type_id == 5 && other2.type_id == 3){
        return (other1.c_char >= other2.l_long);
    }
    else if (other1.type_id == 5 && other2.type_id == 4){
        return (other1.c_char >= other2.d_double);
    }
    else if (other1.type_id == 5 && other2.type_id == 5){
        return (other1.c_char >= other2.c_char);
    }
    else if (other1.type_id == 5 && other2.type_id == 6){
        // string
    }
    else if (other1.type_id == 6 && other2.type_id == 1){
        
    }
    else if (other1.type_id == 6 && other2.type_id == 2){
        
    }
    else if (other1.type_id == 6 && other2.type_id == 3){
        
    }
    else if (other1.type_id == 6 && other2.type_id == 4){
        
    }
    else if (other1.type_id == 6 && other2.type_id == 5){
        
    }
    else if (other1.type_id == 6 && other2.type_id == 6){
        size_t size_a = 0;
        size_t size_b = 0;
        for (size_t i = 0; i < other1.length; i++){
            size_a += other1.cs_tr[i];
        }
        for (size_t i = 0; i < other2.length; i++){
            size_b += other2.cs_tr[i];
        }
        
        if (size_a >= size_b){
            return true;
        }
        else{
            return false;
        }
    }
    return other1.b_bool;
}



bool var::operator== (const var &other)
{
    if (this->type_id == 1 && other.type_id == 1){
        return (this->b_bool == other.b_bool);
    }
    else if (this->type_id == 1 && other.type_id == 2){
        return (this->b_bool == other.i_int);
    }
    else if (this->type_id == 1 && other.type_id == 3){
        return (this->b_bool == other.l_long);
    }
    else if (this->type_id == 1 && other.type_id == 4){
        return (this->b_bool == other.d_double);
    }
    else if (this->type_id == 1 && other.type_id == 5){
        return (this->b_bool == other.c_char);
    }
    else if (this->type_id == 1 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 2 && other.type_id == 1){
        return (this->i_int == other.b_bool);
    }
    else if (this->type_id == 2 && other.type_id == 2){
        return (this->i_int == other.i_int);
    }
    else if (this->type_id == 2 && other.type_id == 3){
        return (this->i_int == other.l_long);
    }
    else if (this->type_id == 2 && other.type_id == 4){
        return (this->i_int == other.d_double);
    }
    else if (this->type_id == 2 && other.type_id == 5){
        return (this->i_int == other.c_char);
    }
    else if (this->type_id == 2 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 3 && other.type_id == 1){
        return (this->l_long == other.b_bool);
    }
    else if (this->type_id == 3 && other.type_id == 2){
        return (this->l_long == other.i_int);
    }
    else if (this->type_id == 3 && other.type_id == 3){
        return (this->l_long == other.l_long);
    }
    else if (this->type_id == 3 && other.type_id == 4){
        return (this->l_long == other.d_double);
    }
    else if (this->type_id == 3 && other.type_id == 5){
        return (this->l_long == other.c_char);
    }
    else if (this->type_id == 3 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 4 && other.type_id == 1){
        return (this->d_double == other.b_bool);
    }
    else if (this->type_id == 4 && other.type_id == 2){
        return (this->d_double == other.i_int);
    }
    else if (this->type_id == 4 && other.type_id == 3){
        return (this->d_double == other.l_long);
    }
    else if (this->type_id == 4 && other.type_id == 4){
        return (this->d_double == other.d_double);
    }
    else if (this->type_id == 4 && other.type_id == 5){
        return (this->d_double == other.c_char);
    }
    else if (this->type_id == 4 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 5 && other.type_id == 1){
        return (this->c_char == other.b_bool);
    }
    else if (this->type_id == 5 && other.type_id == 2){
        return (this->c_char == other.i_int);
    }
    else if (this->type_id == 5 && other.type_id == 3){
        return (this->c_char == other.l_long);
    }
    else if (this->type_id == 5 && other.type_id == 4){
        return (this->c_char == other.d_double);
    }
    else if (this->type_id == 5 && other.type_id == 5){
        return (this->c_char == other.c_char);
    }
    else if (this->type_id == 5 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 6 && other.type_id == 1){
        
    }
    else if (this->type_id == 6 && other.type_id == 2){
        
    }
    else if (this->type_id == 6 && other.type_id == 3){
        
    }
    else if (this->type_id == 6 && other.type_id == 4){
        
    }
    else if (this->type_id == 6 && other.type_id == 5){
        
    }
    else if (this->type_id == 6 && other.type_id == 6){
        if (this->length != other.length){
            return false;
        }
        for (size_t i = 0; i < this->length; i++){
            if (this->cs_tr[i] != other.cs_tr[i]){
                return false;
            }
        }
        return true;
    }
    return 0;
}


bool var::operator!= (const var &other)
{
    if (this->type_id == 1 && other.type_id == 1){
        return (this->b_bool != other.b_bool);
    }
    else if (this->type_id == 1 && other.type_id == 2){
        return (this->b_bool != other.i_int);
    }
    else if (this->type_id == 1 && other.type_id == 3){
        return (this->b_bool != other.l_long);
    }
    else if (this->type_id == 1 && other.type_id == 4){
        return (this->b_bool != other.d_double);
    }
    else if (this->type_id == 1 && other.type_id == 5){
        return (this->b_bool != other.c_char);
    }
    else if (this->type_id == 1 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 2 && other.type_id == 1){
        return (this->i_int != other.b_bool);
    }
    else if (this->type_id == 2 && other.type_id == 2){
        return (this->i_int != other.i_int);
    }
    else if (this->type_id == 2 && other.type_id == 3){
        return (this->i_int != other.l_long);
    }
    else if (this->type_id == 2 && other.type_id == 4){
        return (this->i_int != other.d_double);
    }
    else if (this->type_id == 2 && other.type_id == 5){
        return (this->i_int != other.c_char);
    }
    else if (this->type_id == 2 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 3 && other.type_id == 1){
        return (this->l_long != other.b_bool);
    }
    else if (this->type_id == 3 && other.type_id == 2){
        return (this->l_long != other.i_int);
    }
    else if (this->type_id == 3 && other.type_id == 3){
        return (this->l_long != other.l_long);
    }
    else if (this->type_id == 3 && other.type_id == 4){
        return (this->l_long != other.d_double);
    }
    else if (this->type_id == 3 && other.type_id == 5){
        return (this->l_long != other.c_char);
    }
    else if (this->type_id == 3 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 4 && other.type_id == 1){
        return (this->d_double != other.b_bool);
    }
    else if (this->type_id == 4 && other.type_id == 2){
        return (this->d_double != other.i_int);
    }
    else if (this->type_id == 4 && other.type_id == 3){
        return (this->d_double != other.l_long);
    }
    else if (this->type_id == 4 && other.type_id == 4){
        return (this->d_double != other.d_double);
    }
    else if (this->type_id == 4 && other.type_id == 5){
        return (this->d_double != other.c_char);
    }
    else if (this->type_id == 4 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 5 && other.type_id == 1){
        return (this->c_char != other.b_bool);
    }
    else if (this->type_id == 5 && other.type_id == 2){
        return (this->c_char != other.i_int);
    }
    else if (this->type_id == 5 && other.type_id == 3){
        return (this->c_char != other.l_long);
    }
    else if (this->type_id == 5 && other.type_id == 4){
        return (this->c_char != other.d_double);
    }
    else if (this->type_id == 5 && other.type_id == 5){
        return (this->c_char != other.c_char);
    }
    else if (this->type_id == 5 && other.type_id == 6){
        // string
    }
    else if (this->type_id == 6 && other.type_id == 1){
        
    }
    else if (this->type_id == 6 && other.type_id == 2){
        
    }
    else if (this->type_id == 6 && other.type_id == 3){
        
    }
    else if (this->type_id == 6 && other.type_id == 4){
        
    }
    else if (this->type_id == 6 && other.type_id == 5){
        
    }
    else if (this->type_id == 6 && other.type_id == 6){
        if (this->length != other.length){
            return true;
        }
        for (size_t i = 0; i < this->length; i++){
            if (this->cs_tr[i] != other.cs_tr[i]){
                return true;
            }
        }
        return false;
    }
    
    return 0;
}


var operator+ (var in, var &other)
{
    if(other.type_id == 1)
    {
        return in + other.b_bool;
    }
    else if(other.type_id == 2)
    {
        return in + other.i_int;
    }
    else if(other.type_id == 3)
    {
        return in + other.l_long;
    }
    else if(other.type_id == 4)
    {
        return in + other.d_double;
    }
    else if(other.type_id == 5)
    {
        return in + other.c_char;
    }
    else if(other.type_id == 6)
    {
        const size_t size = in.length + other.length;
        char new_str[size +1];
        for (size_t i = 0; i < size; i++){
            if (in.length > i){
                new_str[i] = in.cs_tr[i];
            }
            else{
                new_str[i] = other.cs_tr[i - in.length];
            }
        }
        new_str[size] = '\0';
        return new_str;
    }
    return in;
}

var operator- (var in, var &other)
{
    if(other.type_id == 1)
    {
        return in - other.b_bool;
    }
    else if(other.type_id == 2)
    {
        return in - other.i_int;
    }
    else if(other.type_id == 3)
    {
        return in - other.l_long;
    }
    else if(other.type_id == 4)
    {
        return in - other.d_double;
    }
    else if(other.type_id == 5)
    {
        return in - other.c_char;
    }
    else if(other.type_id == 6)
    {
        return in - other.cs_tr;;
    }
    return other;
}


var operator* (var in, var &other)
{
    if(other.type_id == 1)
    {
        return in * other.b_bool;
    }
    else if(other.type_id == 2)
    {
        return in * other.i_int;
    }
    else if(other.type_id == 3)
    {
        return in * other.l_long;
    }
    else if(other.type_id == 4)
    {
        return in * other.d_double;
    }
    else if(other.type_id == 5)
    {
        return in * other.c_char;
    }
    else if(other.type_id == 6)
    {
        
    }
    return other;
}


var operator/ (var in, var &other)
{
    if(other.type_id == 1)
    {
        return in / other.b_bool;
    }
    else if(other.type_id == 2)
    {
        return in / other.i_int;
    }
    else if(other.type_id == 3)
    {
        return in / other.l_long;
    }
    else if(other.type_id == 4)
    {
        return in / other.d_double;
    }
    else if(other.type_id == 5)
    {
        return in / other.c_char;
    }
    else if(other.type_id == 6)
    {
        
    }
    return other;
}


var operator% (var in, var &other)
{
    if(other.type_id == 1)
    {
        return in % other.b_bool;
    }
    else if(other.type_id == 2)
    {
        return in % other.i_int;
    }
    else if(other.type_id == 3)
    {
        return in % other.l_long;
    }
    else if(other.type_id == 4)
    {
        return in % other.d_double;
    }
    else if(other.type_id == 5)
    {
        return in % other.c_char;
    }
    else if(other.type_id == 6)
    {
        
    }
    return other;
}

void getline(std::istream &stream, var &other){
    stream >> other;
}

long var::findr(const char *in, const long &where){
    
    long size = 0;
    while (in[size] != '\0'){
        size++;
    }
    for (long i = where; i < this->length; i++){
        if (this->cs_tr[i] == in[0]){
            if (this->cs_tr[i + (size -1)] == in[size -1]){
                for (long l = 0; l < size; l++){
                    if (this->cs_tr[i + l] == in[l]){
                        if (l == (size -1)){
                            return i;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    return -1;
}

long var::findr(const var &in, const long &where){
    for (long i = where; i < this->length; i++){
        if (this->cs_tr[i] == in.cs_tr[0]){
            if (this->cs_tr[i + (in.length -1)] == in.cs_tr[in.length -1]){
                for (long l = 0; l < in.length; l++){
                    if (this->cs_tr[i + l] == in.cs_tr[l]){
                        if (l == (in.length -1)){
                            return i;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    return -1;
}

long var::rfindr(const char *in){
    
    long size = 0;
    while (in[size] != '\0'){
        size++;
    }
    for (long i = this->length; i >= 0; i--){
        if (this->cs_tr[i] == in[0]){
            if (this->cs_tr[i + (size -1)] == in[size -1]){
                for (long l = 0; l < size; l++){
                    if (this->cs_tr[i + l] == in[l]){
                        if (l == (size -1)){
                            return i;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    return -1;
}

long var::rfindr(const var &in){
    for (long i = this->length; i >= 0; i--){
        if (this->cs_tr[i] == in.cs_tr[0]){
            if (this->cs_tr[i + (in.length -1)] == in.cs_tr[in.length -1]){
                for (long l = 0; l < in.length; l++){
                    if (this->cs_tr[i + l] == in.cs_tr[l]){
                        if (l == (in.length -1)){
                            return i;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    return -1;
}

long var::rfindr(const char *in, const long &where){
    
    long size = 0;
    while (in[size] != '\0'){
        size++;
    }
    for (long i = where; i >= 0; i--){
        if (this->cs_tr[i] == in[0]){
            if (this->cs_tr[i + (size -1)] == in[size -1]){
                for (long l = 0; l < size; l++){
                    if (this->cs_tr[i + l] == in[l]){
                        if (l == (size -1)){
                            return i;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    return -1;
}

long var::rfindr(const var &in, const long &where){
    for (long i = where; i >= 0; i--){
        if (this->cs_tr[i] == in.cs_tr[0]){
            if (this->cs_tr[i + (in.length -1)] == in.cs_tr[in.length -1]){
                for (long l = 0; l < in.length; l++){
                    if (this->cs_tr[i + l] == in.cs_tr[l]){
                        if (l == (in.length -1)){
                            return i;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    return -1;
}

const char *var::findr_and_replacer(const char *find, const char *replace){
    if ((find != NULL || find != nullptr) && (replace != NULL || replace != nullptr)){
        long start = 0;
        while (start != -1){
            start = findr(find, start);
            if (start != -1){
                replacer(start, replace);
            }
        }
    }
    return this->cs_tr;
}

const char *var::findr_and_replacer(const char *find, const char *replace, const char &whole){
    if ((find != NULL || find != nullptr) && (replace != NULL || replace != nullptr)){
        if (whole == 'W'){
            long size = 0;
            while (find[size] != '\0'){
                size++;
            }
            
            long start = 0;
            while (start != -1){
                start = findr(find, start);
                if (start != -1){
                    replacer(start, size, replace);
                }
            }
        }
        else{
            long start = 0;
            while (start != -1){
                start = findr(find, start);
                if (start != -1){
                    replacer(start, replace);
                }
            }
        }
    }
    return this->cs_tr;
}


const char *var::replacer(long &start, const char *in)
{
    if ((start >= 0 && in[0] != '\0') && (in != nullptr || in != NULL)){
        size_t lens = 0;
        while (in[lens] != '\0'){
            lens++;
        }
        
        reall_size(this->length + lens +1);
        char *new_str = new char[this->capacit_y]{};
        
        for (long i = 0; i < this->length + lens; i++){
            if (i >= start && i < (start + lens)){
                new_str[i] = in[i - start];
            }
            else{
                if (i <= this->length){
                    new_str[i] = this->cs_tr[i];
                }
            }
        }
        size_t size = 0;
        while (new_str[size] != '\0'){
            size++;
        }
        this->length = size;
        delete [] this->cs_tr;
        this->cs_tr = new_str;
    }
    else if(in[0] == '\0'){
        char *new_str = new char[this->capacit_y]{};
        for (long i = 0; i < this->length; i++){
            if(i < start){
                new_str[i] = this->cs_tr[i];
            }
            else{
                new_str[i] = this->cs_tr[i +1];
            }
        }
        size_t size = 0;
        while (new_str[size] != '\0'){
            size++;
        }
        this->length = size;
        delete [] this->cs_tr;
        this->cs_tr = new_str;
    }
    return this->cs_tr;
}

const char *var::replacer(long &start, long &len, const char *in)
{
    if (start >= 0 && (in != nullptr || in != NULL)){
        long lens = 0;
        while (in[lens] != '\0'){
            lens++;
        }
        
        reall_size(this->length + lens +1);
        char *new_str = new char[this->capacit_y]{};
        
        long jump = 0;
        long jum2 = 0;
        for (long i = 0; i < this->length + lens; i++){
            if (i >= start && i < (start + lens)){
                new_str[i] = in[i - start];
                if ((start + lens -1) <= i)
                {
                    if (len < 0){
                        break;
                    }
                    for (; jump < (lens - len); jump++){
                        new_str[i + (jump +1)] = this->cs_tr[(start + len) + jump];
                        
                    }
                }
            }
            else{
                if (i <= this->length){
                    if (len > lens && i == (start + lens)){
                        for (long y = 0; y < (len - lens); y++){
                            new_str[i + jump] = this->cs_tr[i + (y +1)];
                            jum2++;
                        }
                    }
                    else{
                        if (this->cs_tr[i + jum2] == '\0'){
                            break;
                        }
                        else{
                            new_str[i + jump] = this->cs_tr[i + jum2];
                        }
                    }
                }
            }
        }
        size_t size = 0;
        while (new_str[size] != '\0'){
            size++;
        }
        new_str[size] = '\0';
        this->length = size;
        delete [] this->cs_tr;
        this->cs_tr = new_str;
    }
    return this->cs_tr;
}

const char *var::appen_d(const char *in){
    if (in[0] != '\0'){
        size_t len = 0;
        while (in[len] != '\0'){
            len++;
        }
        reall_size(this->length + len +1);
        char *new_str = new char[this->capacit_y]{};
        for (size_t i = 0; i < (this->length + len); i++){
            if (i < this->length){
                new_str[i] = this->cs_tr[i];
            }
            else{
                new_str[i] = in[i - this->length];
            }
        }
        this->length += len;
        delete [] this->cs_tr;
        this->cs_tr = new_str;
    }
    return this->cs_tr;
}

const char *var::appen_d(const var &in){
    if (in.cs_tr[0] != '\0'){
        reall_size(this->length + in.length +1);
        char *new_str = new char[this->capacit_y]{};
        for (size_t i = 0; i < (this->length + in.length); i++){
            if (i < this->length){
                new_str[i] = this->cs_tr[i];
            }
            else{
                new_str[i] = in.cs_tr[i - this->length];
            }
        }
        this->length += in.length;
        delete [] this->cs_tr;
        this->cs_tr = new_str;
    }
    return this->cs_tr;
}

const char *var::appen_d(const char *in, const size_t &len){
    if (in[0] != '\0'){
        reall_size(this->length + len +1);
        char *new_str = new char[this->capacit_y]{};
        for (size_t i = 0; i < (this->length + len); i++){
            if (i < this->length){
                new_str[i] = this->cs_tr[i];
            }
            else{
                new_str[i] = in[i - this->length];
            }
        }
        this->length += len;
        delete [] this->cs_tr;
        this->cs_tr = new_str;
    }
    return this->cs_tr;
}

const char *var::appen_d(const var &in, const size_t &len){
    if (in.cs_tr[0] != '\0'){
        reall_size(this->length + len +1);
        char *new_str = new char[this->capacit_y]{};
        for (size_t i = 0; i < (this->length + len); i++){
            if (i < this->length){
                new_str[i] = this->cs_tr[i];
            }
            else{
                new_str[i] = in.cs_tr[i - this->length];
            }
        }
        this->length += len;
        delete [] this->cs_tr;
        this->cs_tr = new_str;
    }
    return this->cs_tr;
}

void var::clea_r(){
    if (this->cs_tr != nullptr){
        delete [] this->cs_tr;
        char *new_str = new char[this->capacit_y]{};
        this->cs_tr = new_str;
        this->length = 0;
    }
}

const char *var::eras_e(){
    if (this->cs_tr != nullptr){
        delete [] this->cs_tr;
        char *new_str = new char[this->capacit_y]{};
        this->cs_tr = new_str;
        this->length = 0;
    }
    return this->cs_tr;
}

const char *var::eras_e(const size_t &start){
    if (start > this->length){
        errno = E2BIG;
        perror("Specified length, greater than var::string length!");
        exit(108);
    }
    else if (this->cs_tr != nullptr){
        char *new_str = new char[this->capacit_y]{};
        size_t i = 0;
        for (; i < start; i++){
            new_str[i] = this->cs_tr[i];
        }
        new_str[start] = '\0';
        delete [] this->cs_tr;
        this->cs_tr = new_str;
        this->length = i;
    }
    return this->cs_tr;
}

const char *var::eras_e(const size_t &start, const size_t &end){
    if (start > this->length){
        errno = E2BIG;
        perror("Specified length, greater than var::string length!");
        exit(109);
    }
    else if (this->cs_tr != nullptr){
        char *new_str = new char[this->capacit_y]{};
        size_t fin = 0;
        for (size_t i = 0; i < start; i++){
            new_str[fin++] = this->cs_tr[i];
        }
        for (size_t i = (end + start); i < this->length; i++){
            new_str[fin++] = this->cs_tr[i];
        }
        new_str[fin] = '\0';
        delete [] this->cs_tr;
        this->cs_tr = new_str;
        this->length = fin;
    }
    return this->cs_tr;
}
