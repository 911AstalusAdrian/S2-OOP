#include "urservice.h"

URService::URService() {
    undoStack = std::stack<Command*>();
    redoStack = std::stack<Command*>();
}

void URService::Execute(Command* c) {
    redoStack = std::stack<Command*>();
    c->execute();
    undoStack.push(c);
}

void URService::Undo() {
    if(undoStack.empty())
        throw URException("No action to undo!");
    else{
        undoStack.top()->undo();
        redoStack.push(undoStack.top());
        undoStack.pop();
    }
}

void URService::Redo() {
    if (redoStack.empty())
        throw URException("No redo operations left!");
    redoStack.top()->redo();
    undoStack.push(redoStack.top());
    redoStack.pop();
}

URException::URException(std::string message) {
    this->error = message;
}

std::string URException::print() {
    return error;
}
