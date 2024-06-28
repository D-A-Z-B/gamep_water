#pragma once
void DeadTextRender();
enum class DeadMENU {
	RETRY, GOTITLE, QUIT
};
DeadMENU DeadScene();
void HighScoreRender();
DeadMENU DeadSceneMenuRender();
enum class DEADKEY {
	UP, DOWN, SPACE, NONE
};
DEADKEY DeadKeyController();