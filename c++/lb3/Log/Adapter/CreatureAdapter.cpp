#include "CreatureAdapter.h"


CreatureAdapter::CreatureAdapter(Creature* crt) : curCondition(crt->getAttribute()), prevCondition(*(crt->getAttribute())) {}

bool CreatureAdapter::hasChanged() {
    if (prevCondition == (*curCondition))
        return false;
    return true;
}

std::ostream& operator<<(std::ostream& os, CreatureAdapter* adp) {
    os << "\tCurCond (PrevCond):\n";
    os << "hp:        " << adp->prevCondition.hp << " (" << adp->curCondition->hp << ")\n";
    os << "armor:     " << adp->prevCondition.armor << " (" << adp->curCondition->armor << ")\n";
    os << "damage:    " << adp->prevCondition.dmg << " (" << adp->curCondition->dmg << ")\n";
    os << "position: (" << adp->prevCondition.pos.x << ", " << adp->prevCondition.pos.y << ")" << "( " << adp->curCondition->pos.x << ", " << adp->curCondition->pos.y << ")\n";
    //os << "frame:     " << adp.prevCondition.curFrame << "\\" << adp.curCondition->curFrame << '\n';
    os << "speed:     " << adp->prevCondition.speed << " (" << adp->curCondition->speed << ")\n";
    os << "dir:       " << adp->prevCondition.dir << " (" << adp->curCondition->dir << ")\n";
    adp->prevCondition = *(adp->curCondition);
    return os;
}