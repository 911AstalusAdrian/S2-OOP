#pragma once
#ifndef A10_911ASTALUSADRIAN_1_COMMAND_H
#define A10_911ASTALUSADRIAN_1_COMMAND_H
#endif //A10_911ASTALUSADRIAN_1_COMMAND_H

class Command{
public:
    virtual void undo() = 0;
    virtual void redo() = 0;
    virtual void execute() = 0;
};