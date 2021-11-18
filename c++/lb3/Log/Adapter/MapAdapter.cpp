#include "MapAdapter.h"


MapAdapter::MapAdapter(Map* map) : curCond(map->getField()), prevCond(*(map->getField())) {}

bool MapAdapter::hasChanged() {
    if (prevCond == (*curCond))
        return false;
    return true;
}

std::ostream& operator<<(std::ostream& os, MapAdapter* adp) {
    os << "\tCurMapCond (PrevMapCond)\n";
    for (int i = 0; i < adp->prevCond.get_size().y; i++) {
        for (int j = 0; j < adp->prevCond.get_size().x; j++) {
            os << adp->curCond->getCells()[i][j].content() << " (" << adp->prevCond.getCells()[i][j].content() << ") ";
        }
        os << '\n';
    }
    adp->prevCond = *(adp->curCond);
    return os;
}

