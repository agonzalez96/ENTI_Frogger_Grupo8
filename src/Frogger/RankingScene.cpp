#include "GUI.hh"
#include "System.hh"
#include "Logger.hh"
#include "RankingScene.h"
#include "GameScene.hh"
#include "LevelSelect.h"
using namespace Logger;


RankingScene::RankingScene(void) {
	m_background = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::BG_RANKING};
	titulo = { { W.GetWidth() / 6 - 20, W.GetHeight() / 8 - 70, W.GetWidth() - 200, W.GetHeight() - 700 }, ObjectID::TITULO };
}

RankingScene::~RankingScene(void) {

}

void RankingScene::OnEntry(void) {
	Score tempScore;
	tempScore.name = SM.GetScene<GameScene>()->name;
	tempScore.score = SM.GetScene<GameScene>()->score;
	
	
	IOManager::SaveRanking(tempScore);
}

void RankingScene::OnExit(void) {
}

void RankingScene::Update(void) {
	static MouseCoords mouseCoords(0, 0);
	
	if (IM.IsMouseDown<MOUSE_BUTTON_LEFT>() && IM.GetMouseCoords().x > 383 && IM.GetMouseCoords().x < 445 && IM.GetMouseCoords().y > 665 && IM.GetMouseCoords().y < 714) {  //Apretar el boto de exit
		IM.SetQuit();
		mouseCoords = IM.GetMouseCoords();
	}

}

void RankingScene::Draw(void) {
	m_background.Draw(); // Render background
	titulo.Draw();
	
	for (int i = 9; i >= 0; i--) {
		GUI::DrawTextBlended<FontID::ARIAL>(ranking[i].name + "   " + std::to_string(ranking[i].score),
		{ W.GetWidth() / 2 , W.GetHeight() - 180 - (50 * i), 1, 1 },
		{ 255, 255, 255 });
	}

	GUI::DrawTextShaded<FontID::ARIAL>("Exit",
	{ W.GetWidth() / 2, int(W.GetHeight()*.8f + 50), 1, 1 },
	{ 190, 0, 160 }, { 50, 200, 230 }); // Render score that will be different when updated
}
