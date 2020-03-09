//
// Created by feyfo on 3/5/2020.
//

#include "StateMachine.h"
#include <thread>
#include <random>
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
    int array[11] = {};
    const unsigned int num_pokemon = 11;    //NUMBER OF UNIQUE POKEMON IN THE MACHINE
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> first_num_dist(0,num_pokemon - 1);
    std::uniform_int_distribution<int> second_num_dist(0,num_pokemon - 2);
    std::uniform_int_distribution<int> third_num_dist(0,num_pokemon - 3);

    for(int j = 0; j < 100000000; j++){
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

        for(int i = 0; i < num_pokemon; i++){
            if(first_num == i){
                array[i]++;
            }
            if(second_num == i){
                array[i]++;
            }
            if(third_num == i){
                array[i]++;
            }
        }
    }

    for(int i : array){
        std::cout << i << std::endl;
    }

    //First thread
//    auto *mainState = new StateMachine;
//    std::thread mainThread(&mainState::);
//    std::thread buttonThread();

//    mainThread().join();
//    buttonThread().join();

    //Second thread
    //printf("hi");
}
