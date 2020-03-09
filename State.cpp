//
// Created by feyfo on 3/7/2020.
//

#include "State.h"
#include <random>
#include <chrono>
State::State() {

}

State::~State() {

}

void State::setType(std::string new_type) {
    m_state_type = new_type;
}

std::string State::getType() const {
    return m_state_type;
}

//Start state

//Game state
//Confirmation

//End state
void LeftSelected::ExecuteLeft() {
    //Return the leftmost ball
    printf("Dropped Left Ball");
}

void LeftSelected::ExecuteCenter() {
    this->setType("Center");
}

void LeftSelected::ExecuteRight() {
    this->setType("Right");
}

void LeftSelected::Enter() {
    //Start the left ball shaking animation
}

//CenterSelected State
void CenterSelected::ExecuteLeft() {
    this->setType("Left");
}

void CenterSelected::ExecuteCenter() {
    printf("Dropped Center Ball");
}

void CenterSelected::ExecuteRight() {
    this->setType("Right");
}

void RightSelected::ExecuteLeft() {
    this->setType("Left");
}

void RightSelected::ExecuteCenter() {
    this->setType("Center");
}

void RightSelected::ExecuteRight() {
    this->setType("Dropped Right Ball");
}

void GlobalState::Exit() {

}

void GlobalState::Enter() {

}

void GlobalState::ExecuteLeft() {

}

void GlobalState::ExecuteCenter() {

}

void GlobalState::ExecuteRight() {

}

void StartMenu::Enter() {
    // Play bootup animation
}

void StartMenu::ExecuteLeft() {
    //Open the Help menu
}

void StartMenu::ExecuteCenter() {
    //Start the game
}

void StartMenu::ExecuteRight() {
    //Show all possible charms
}

void StartMenu::Exit() {
    //do nothing
}

void GameStart::Enter() {
    const unsigned int num_pokemon = 11;    //NUMBER OF UNIQUE POKEMON IN THE MACHINE
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> first_num_dist(0,num_pokemon - 1);
    std::uniform_int_distribution<int> second_num_dist(0,num_pokemon - 2);
    std::uniform_int_distribution<int> third_num_dist(0,num_pokemon - 3);

    int first_num = first_num_dist(generator);
    int second_num = second_num_dist(generator);
    int third_num = third_num_dist(generator);

    if(second_num == first_num){
        second_num = 10;
    }

    if(third_num == first_num){
        if(second_num == 9){
            third_num = 10;
        } else {
            third_num = 9;
        }
    }else if(third_num == second_num){
        if(first_num == 10){
            third_num = 9;
        } else {
            third_num = 10;
        }
    }

    printf("Some pokemon");
//    auto dice = std::bind ( distribution, generator );
}

void GameStart::ExecuteLeft() {

}

void GameStart::ExecuteCenter() {

}

void GameStart::ExecuteRight() {

}

void GameStart::Exit() {

}
