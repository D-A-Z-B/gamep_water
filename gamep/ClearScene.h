#pragma once
void ClearRender();
enum class ClearSceneMenu {
	GOTITLE, QUIT
};
ClearSceneMenu ClearScene();
ClearSceneMenu ClearMenuRender();
enum class CLEARKEY {
	UP, DOWN, SPACE, NONE
};
CLEARKEY ClearkeyControllr();