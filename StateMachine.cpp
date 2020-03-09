//
// Created by feyfo on 3/7/2020.
//

#include "StateMachine.h"

StateMachine::StateMachine(){
    m_p_state = new StartMenu;
    m_p_previous_state = nullptr;
    m_p_global_state = new GlobalState;
}

/// Set current state.
void StateMachine::setState(State *p_new_state) {
    m_p_state = p_new_state;
}

/// Get current state.
State *StateMachine::getState() const{
    return m_p_state;
}

/// Set previous state.
void StateMachine::setPreviousState(State *p_new_state){
    m_p_previous_state = p_new_state;
}

/// Get previous state.
State *StateMachine::getPreviousState() const{
    return m_p_previous_state;
}

/// Set global state.
void StateMachine::setGlobalState(State *p_new_state){
    m_p_global_state = p_new_state;
}

/// Get global state.
State *StateMachine::getGlobalState() const{
    return m_p_global_state;
}

/// Update state machine (calling Execute() for current state).
void StateMachine::Update(){
//    m_p_state->Execute();
}

/// Change current state.
void StateMachine::changeState(State *p_new_state){

}

/// Revert to previous state.
void StateMachine::revertToPrevious(){
    m_p_state = m_p_previous_state;
}

void StateMachine::ButtonPressed(int button) {
    switch (button){
        case 1:
            m_p_state->ExecuteLeft();
            break;
        case 2:
            m_p_state->ExecuteCenter();
            break;
        case 3:
            m_p_state->ExecuteRight();

            break;
        default:
            break;
    }
}
