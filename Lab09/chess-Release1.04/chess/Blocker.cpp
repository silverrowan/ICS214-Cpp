#include "Blocker.h"
#include "Gameboard.h"
#include "Constants.h"
#include <sstream>

Blocker::Blocker() : GameboardItem("blocker", "#")
{
    loadImage(getImageFilepath());
}

std::string Blocker::getImageFilepath() {
	std::stringstream ss;
	ss << Constants::pathToImages << name << ".png";
	return ss.str();
}
