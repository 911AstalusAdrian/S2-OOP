#pragma once
#ifndef A45_911ASTALUSADRIAN_VALIDATORS_H
#define A45_911ASTALUSADRIAN_VALIDATORS_H
#endif //A45_911ASTALUSADRIAN_VALIDATORS_H
#include <string>
#include <dog.h>

int validate_breed(const std::string& breed);
int validate_name(const std::string& name);
int validate_age(int age);
int validate_link(const std::string& link);
int validate_entity(Dog& dog);