#include "BaseMonster.h"
#include "Level.h"

void updateLevel() {
	if (addLevel >= LimitAddLevel) {
		Level++;
		addLevel = addLevel - LimitAddLevel;
	}
}

int getLevel() {
	return Level;
}