#pragma once
void DeadTextRender();
bool DeadScene();
enum class DeadMENU {
	RETRY, GOTITLE, QUIT
};
DeadMENU DeadSceneMenuRender();
enum class DEADKEY {
	UP, DOWN, SPACE, NONE
};
DEADKEY DeadKeyController();