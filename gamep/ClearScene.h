#pragma once
void ClearRender();
enum class ClearScenMenu {
	RESTART, GOTITLE, QUIT
};
ClearScenMenu ClearScene();
ClearScenMenu ClearMenuRender();
enum class CLEARKEY {
	UP, DOWN, SPACE, NONE
};
CLEARKEY ClearkeyControllr();