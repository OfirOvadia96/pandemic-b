#include "FieldDoctor.hpp"

namespace pandemic{
    
    Player& FieldDoctor::treat(City city){
        if(this->board.level_disese_in_the_city(city) == 0){
            throw std::invalid_argument("A city free of disease!");
        }
        
        if(this->board.is_neighbors(this->current_city , city) || this->current_city == city){
            //if cure already exists
            if(this->board.exists_cure(this->board.get_color(city))){
                this->board[city] = 0;
            }
            else{ //if cure not exists
                this->board[city] = (this->board[city]-1);
            }
        }
        return *this;
    }
}