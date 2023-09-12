
#include "validation.h"

void Validation::check_measurement(Measurement *m) {
}
void Validation::check_date(std::string date) {
    if(date.length() != 10)
        throw Exception("Invalid date!\n");
}
