
#include "player.h"

std::istream &operator>>(std::istream &is, Player &p) {
        is >> p.name;
        return is;
}
