//
// Created by feyfo on 3/5/2020.
//

#ifndef GACHAMACHINEPI_STATE_H
#define GACHAMACHINEPI_STATE_H
#include <string>

//State machine
class State {
        const std::string UNDEFINED_STATE = "__undefined state__";

    private:
        std::string m_state_type;      /// Name of state.

    public:
        State();
        virtual ~State();

        /// Set name of state.
        void setType(std::string new_type);

        /// Get name of state.
        std::string getType() const;

        /// Invoked when state first entered.
        virtual void Enter()=0;

        virtual void ExecuteLeft()=0;

        virtual void ExecuteCenter()=0;

        virtual void ExecuteRight()=0;

    /// Invoked when state exited.
        virtual void Exit()=0;

};

class GlobalState : public State {
    void GlobalState::Enter();

    void GlobalState::ExecuteLeft();

    void GlobalState::ExecuteCenter();

    void GlobalState::ExecuteRight();

    /// Invoked when state exited.
    void GlobalState::Exit();

private:
    int m_num_tokens = 0;

};

class StartMenu : public State {
    void Enter();

    void ExecuteLeft();

    void ExecuteCenter();

    void ExecuteRight();

    /// Invoked when state exited.
    void Exit();

};


class HelpMenu : public State {
    void Enter()=0;

    void ExecuteLeft()=0;

    void ExecuteCenter()=0;

    void ExecuteRight()=0;

    /// Invoked when state exited.
    void Exit()=0;

};

class GameStart : public State {
    void Enter();

    void ExecuteLeft();

    void ExecuteCenter();

    void ExecuteRight();

    /// Invoked when state exited.
    void Exit();

};

class LeftSelected : public State {
    void Enter();
    void LeftSelected::ExecuteLeft();
    void LeftSelected::ExecuteCenter();
    void LeftSelected::ExecuteRight();

};

class CenterSelected : public State {
    void CenterSelected::ExecuteLeft();
    void CenterSelected::ExecuteCenter();
    void CenterSelected::ExecuteRight();

};

class RightSelected : public State {
    void RightSelected::ExecuteLeft();
    void RightSelected::ExecuteCenter();
    void RightSelected::ExecuteRight();

};

class EndScreen : public State{
    void Enter()=0;

    void ExecuteLeft()=0;

    void ExecuteCenter()=0;

    void ExecuteRight()=0;

    /// Invoked when state exited.
    void Exit()=0;

};

//Game state

#endif //GACHAMACHINEPI_STATE_H
