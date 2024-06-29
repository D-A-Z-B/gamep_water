#pragma once
void TitleRender();
bool TitleScene();
void InfoRender();
void EnterAnimation();
void HighScoreRender();
enum class MENU {
	START, INFO, QUIT
};
MENU MenuRender();
enum class KEY {
	UP, DOWN, SPACE, NONE
};
KEY KeyController();