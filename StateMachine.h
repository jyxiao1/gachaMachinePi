//
// Created by feyfo on 3/7/2020.
//

#ifndef GACHAMACHINEPI_STATEMACHINE_H
#define GACHAMACHINEPI_STATEMACHINE_H

#include "State.h"

class StateMachine {

private:
//    Object *m_p_owner;         /// Owner of this state machine.
    State *m_p_state;          /// Current state.
    State *m_p_previous_state; /// Previous{} state.
    State *m_p_global_state;   /// Global {}state (reachable from any state).

public:
    StateMachine();

    /// Set current state.
    void setState(State *p_new_state);

    /// Get current state.
    State *getState() const;

    /// Set previous state.
    void setPreviousState(State *p_new_state);

    /// Get previous state.
    State *getPreviousState() const;

    /// Set global state.
    void setGlobalState(State *p_new_state);

    /// Get global state.
    State *getGlobalState() const;

    /// Update state machine (calling Execute() for current state).
    void Update();

    /// Update state machine
    void ButtonPressed(int button);

    /// Change current state.
    void changeState(State *p_new_state);

    /// Revert to previous state.
    void revertToPrevious();
};

#endif //GACHAMACHINEPI_STATEMACHINE_H
