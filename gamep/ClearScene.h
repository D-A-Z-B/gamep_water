#pragma once
void ClearRender();
enum class ClearSceneMenu {
	GOTITLE, QUIT
};
ClearSceneMenu ClearScene();
ClearSceneMenu ClearMenuRender();
void ClaerHighScoreRender();
enum class CLEARKEY {
	UP, DOWN, SPACE, NONE
};
CLEARKEY ClearkeyControllr();