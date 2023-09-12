#pragma once
#ifndef A10_911ASTALUSADRIAN_1_REPOCOMMANDS_H
#define A10_911ASTALUSADRIAN_1_REPOCOMMANDS_H
#endif //A10_911ASTALUSADRIAN_1_REPOCOMMANDS_H
#include "command.h"
#include "service.h"
#include "userservice.h"

class AddCommand: public Command{
public:
    AddCommand(Service* serv, const string& breed, const string& name, int age, const string& link);
    void undo() override;
    void redo() override;
    void execute() override;

private:
    Service* service;
    std::string breed, name, link;
    int age;
};

class RemoveCommand: public Command{
public:
    RemoveCommand(Service* serv, int position, const Dog& d);
    void undo() override;
    void redo() override;
    void execute() override;

private:
    Service* service;
    Dog dog;
    int position;
};

class UpdateCommand: public Command{
public:
    UpdateCommand(Service* serv, const Dog& d, const string& new_breed, const string& new_name, int new_age, const string& new_link);
    void undo() override;
    void redo() override;
    void execute() override;

private:
    Service* service;
    Dog dog;
    std::string breed, name, link;
    int age;
};

class AdoptCommand: public Command{
public:
    AdoptCommand(userService* userv, const Dog& d);
    void undo() override;
    void redo() override;
    void execute() override;

private:
    userService* uservice;
    Dog dog;
};