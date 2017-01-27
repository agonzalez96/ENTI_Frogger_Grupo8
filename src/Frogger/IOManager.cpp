#include "IOManager.hh"
#include "LevelSelect.h"
#include "ID.hh"
#include <string>
#include "LevelSelect.h"
#include "SceneManager.hh"
#include "RankingScene.h"
#include "RankingDiffSelect.hh"
#include "GameScene.hh"
#include "SceneManager.hh"

std::vector<Sprite> IOManager::LoadLevelXML(std::string && filename)
{
	xml_document<> doc;    // character type defaults to char
	std::ifstream file(RESOURCE_FILE(filename));
	std::stringstream buffer;

	std::vector<Sprite> lvlData;
	Sprite temp;
	std::string name;
	std::string value;

	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	//std::cout << "Nombre raiz: " << doc.first_node()->name() << '\n';
	xml_node<> *pRoot = doc.first_node();
	if (LevelSelect::_diff == "Easy") {
		for (xml_node<> *pNode = pRoot->first_node("Easy"); pNode < pRoot->first_node("Medium"); pNode = pNode->next_sibling()) {
				//std::cout << pNode->name() << ':' << '\n';
			for (xml_node<> *pNodeI = pNode->first_node(); pNodeI; pNodeI = pNodeI->next_sibling()) {
						//std::cout << "  " << pNodeI->name() << "-" << pNodeI->value() << '\n';
				for (xml_node<> *pNode2 = pNodeI->first_node(); pNode2; pNode2 = pNode2->next_sibling()) {
								//std::cout << "    " << pNode2->name() << "-" << pNode2->value() << '\n';
					for (xml_node<> *pNode3 = pNode2->first_node(); pNode3; pNode3 = pNode3->next_sibling()) {
						//std::cout << "      " << pNode3->name() << "-" << pNode3->value() << '\n';
						name = pNode3->name();
						value = pNode3->value();
						//std::cout << "name" << name << std::endl;
						//std::cout << "value" << value << std::endl;
						if (name == "ID") {
							temp.objectID = SwitchTextrue(atoi(pNode3->value()));
						}
						else if (name == "x") {
							temp.transform.x = atoi(pNode3->value());
							//std::cout << "temp x" << temp.transform.x << std::endl;
						}
						else if (name == "y") {
							temp.transform.y = atoi(pNode3->value());
							//std::cout << "temp y" << temp.transform.y << std::endl;
						}
					}
					lvlData.push_back(temp);
				}
			}
		}
	}
	else if (LevelSelect::_diff == "Medium") {
		for (xml_node<> *pNode = pRoot->first_node("Medium"); pNode < pRoot->first_node("Hard"); pNode = pNode->next_sibling()) {
			//std::cout << pNode->name() << ':' << '\n';
			for (xml_node<> *pNodeI = pNode->first_node(); pNodeI; pNodeI = pNodeI->next_sibling()) {
				//std::cout << "  " << pNodeI->name() << "-" << pNodeI->value() << '\n';
				for (xml_node<> *pNode2 = pNodeI->first_node(); pNode2; pNode2 = pNode2->next_sibling()) {
					//std::cout << "    " << pNode2->name() << "-" << pNode2->value() << '\n';
					for (xml_node<> *pNode3 = pNode2->first_node(); pNode3; pNode3 = pNode3->next_sibling()) {
						//std::cout << "      " << pNode3->name() << "-" << pNode3->value() << '\n';
						name = pNode3->name();
						value = pNode3->value();
						//std::cout << "name" << name << std::endl;
						//std::cout << "value" << value << std::endl;
						if (name == "ID") {
							temp.objectID = SwitchTextrue(atoi(pNode3->value()));
						}
						else if (name == "x") {
							temp.transform.x = atoi(pNode3->value());
							//std::cout << "temp x" << temp.transform.x << std::endl;
						}
						else if (name == "y") {
							temp.transform.y = atoi(pNode3->value());
							//std::cout << "temp y" << temp.transform.y << std::endl;
						}
					}
					lvlData.push_back(temp);
				}
			}
		}
	}
	else if (LevelSelect::_diff == "Hard") {
		for (xml_node<> *pNode = pRoot->first_node("Hard"); pNode; pNode = pNode->next_sibling()) {
			//std::cout << pNode->name() << ':' << '\n';
			for (xml_node<> *pNodeI = pNode->first_node(); pNodeI; pNodeI = pNodeI->next_sibling()) {
				//std::cout << "  " << pNodeI->name() << "-" << pNodeI->value() << '\n';
				for (xml_node<> *pNode2 = pNodeI->first_node(); pNode2; pNode2 = pNode2->next_sibling()) {
					//std::cout << "    " << pNode2->name() << "-" << pNode2->value() << '\n';
					for (xml_node<> *pNode3 = pNode2->first_node(); pNode3; pNode3 = pNode3->next_sibling()) {
						//std::cout << "      " << pNode3->name() << "-" << pNode3->value() << '\n';
						name = pNode3->name();
						value = pNode3->value();
						//std::cout << "name" << name << std::endl;
						//std::cout << "value" << value << std::endl;
						if (name == "ID") {
							temp.objectID = SwitchTextrue(atoi(pNode3->value()));
						}
						else if (name == "x") {
							temp.transform.x = atoi(pNode3->value());
							//std::cout << "temp x" << temp.transform.x << std::endl;
						}
						else if (name == "y") {
							temp.transform.y = atoi(pNode3->value());
							//std::cout << "temp y" << temp.transform.y << std::endl;
						}
					}
					lvlData.push_back(temp);
				}
			}
		}
	}
	else {
		std::cout << "Difficulty not found" << std::endl;
	}
	return lvlData;
}

ObjectID IOManager::SwitchTextrue(int index)
{
	switch (index) {
	case 1:
		return ObjectID::COCHE;
		break;
	case 2:
		return ObjectID::EXCAVADORA;
		break;
	case 3:
		return ObjectID::RALLY1;
		break;
	case 4:
		return ObjectID::RALLY2;
		break;
	case 5:
		return ObjectID::CAMION;
		break;
	case 6:
		return ObjectID::TRONCO_CORTO;
		break;
	case 7:
		return ObjectID::TRONCO_LARGO;
		break;
	case 8:
		return ObjectID::TRONCO_MEDIANO;
		break;
	case 9:
		return ObjectID::COCODRILO_CERRADO;
		break;
	case 10:
		return ObjectID::NUTRIA;
		break;
	case 11:
		return ObjectID::SERPIENTE;
		break;
	case 12:
		return ObjectID::TORTUGA;
		break;
	case 13:
		return ObjectID::TRITUGA1;
		break;
	case 14:
		return ObjectID::NUTRIA2;
		break;
	default:
		std::cout << "No ID found" << std::endl;
		break;
	}
}

void IOManager::SaveRanking(Score score)
{
	LoadRanking();
	
	if (SM.GetScene<RankingScene>()->ranking[0].score < score.score) {
		SM.GetScene<RankingScene>()->ranking[0].score = score.score;
		SM.GetScene<RankingScene>()->ranking[0].name = score.name;
	}
	InsertionSort(SM.GetScene<RankingScene>()->ranking, 10);

	std::ofstream fsalida;
	
	if (SM.GetScene<LevelSelect>()->_diff == "Easy") {
		fsalida.open(RESOURCE_FILE(std::string("cfg/easyRanking.dat")), std::ios::out | std::ios::binary);
	}
	else if (SM.GetScene<LevelSelect>()->_diff == "Medium") {
		fsalida.open(RESOURCE_FILE(std::string("cfg/mediumRanking.dat")), std::ios::out | std::ios::binary);
	}
	else if (SM.GetScene<LevelSelect>()->_diff == "Hard") {
		fsalida.open(RESOURCE_FILE(std::string("cfg/hardRanking.dat")), std::ios::out | std::ios::binary);
	}
	
	fsalida.write(reinterpret_cast<char*>(&SM.GetScene<RankingScene>()->ranking), sizeof(SM.GetScene<RankingScene>()->ranking));
	fsalida.close();
	
	for (int i = 0; i < 10; i++) {
		std::cout << "i: " << i << "  Name: " << SM.GetScene<RankingScene>()->ranking[i].name << "  score: " << SM.GetScene<RankingScene>()->ranking[i].score << std::endl;
	}
}

void IOManager::LoadRanking()
{
	std::ifstream fentrada;
	if (SM.GetScene<LevelSelect>()->_diff == "Easy"  || SM.GetScene<RankingDiffSelect>()->_diff == "Easy") {
		fentrada.open(RESOURCE_FILE(std::string("cfg/easyRanking.dat")), std::ios::in | std::ios::binary);
	}
	else if (SM.GetScene<LevelSelect>()->_diff == "Medium" || SM.GetScene<RankingDiffSelect>()->_diff == "Medium") {
		fentrada.open(RESOURCE_FILE(std::string("cfg/mediumRanking.dat")), std::ios::in | std::ios::binary);
	}
	else if (SM.GetScene<LevelSelect>()->_diff == "Hard" || SM.GetScene<RankingDiffSelect>()->_diff == "Hard") {
		fentrada.open(RESOURCE_FILE(std::string("cfg/hardRanking.dat")), std::ios::in | std::ios::binary);
	}

	fentrada.read(reinterpret_cast<char*>(&SM.GetScene<RankingScene>()->ranking), sizeof(SM.GetScene<RankingScene>()->ranking));
	fentrada.close();
}

void IOManager::InsertionSort( Score rank[], int lenght)
{
	int j;
	Score temp;
	for (int i = 1; i < lenght; i++) {
		temp = rank[i];
		for (j = i - 1; j >= 0 && rank[j].score > temp.score; j--) {
			rank[j + 1] = rank[j];
		}
		rank[j + 1] = temp;
	}
}

