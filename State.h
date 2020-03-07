//
// Created by feyfo on 3/5/2020.
//

#ifndef GACHAMACHINEPI_STATE_H
#define GACHAMACHINEPI_STATE_H

//State machine
class StateReader {
    StateReader() {
        State.getInstance();
    }
    ~StateReader(){}
private:
    State currState;
    void handle(){

    }
};

class State {
    public:
        static State& getInstance()
        {
            static State instance;
            return instance;
        }

        State (State const&) = delete;
        void operator=(State const&) = delete;

private:

        State(){

        }

        void handleTurn(){

        }

        void next(){

        }

        void prev(){

        }

        ~State() = 0;
};

class StartState : public State {



};

class GameState : public State {

};

class ConfirmState : public State {

};

class EndState : public State {

};

class SelectState : public State{

};
//Game state

#endif //GACHAMACHINEPI_STATE_H
