#pragma once
#include "Sprite.hh"
#include "Scene.hh"

// MenuScene class with the main gameplay mode
class MenuScene : public Scene {
private:
	Sprite m_background;
	Sprite titulo;
	
public:
	explicit MenuScene();
	~MenuScene() override;
	void OnEntry(void) override;
	void OnExit(void) override;
	void Update(void) override;
	void Draw(void) override;

	
};