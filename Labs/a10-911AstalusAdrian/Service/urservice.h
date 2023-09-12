#pragma once
#ifndef A10_911ASTALUSADRIAN_1_URSERVICE_H
#define A10_911ASTALUSADRIAN_1_URSERVICE_H
#endif //A10_911ASTALUSADRIAN_1_URSERVICE_H
#include "../UndoRedo/repocommands.h"
#include <stack>

class URException{
public:
    URException(std::string message);
    std::string print();

private:
    std::string error;
};

class URService{
private:
    std::stack<Command*> undoStack;
    std::stack<Command*> redoStack;
public:
    URService();
    void Execute(Command* c);
    void Undo();
    void Redo();

};