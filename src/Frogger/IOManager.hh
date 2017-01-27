#pragma once
#include "ID.hh"
#include <fstream>
#include <sstream>
#include <iterator>
#include "Logger.hh"
#include "Assert.hh"
#include "Resource.hh"
#include <XML/rapidxml_utils.hpp>
#include"Sprite.hh"
#include "Score.hh"

using namespace Logger;
using namespace rapidxml;

namespace IOManager {

	std::vector<Sprite> LoadLevelXML(std::string &&filename);
	ObjectID SwitchTextrue(int index);
	void SaveRanking(Score score);
	void LoadRanking();
	void InsertionSort(Score rank[], int lenght);
}
