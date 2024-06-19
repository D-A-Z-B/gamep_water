#pragma once
class Scene
{
public:
	void TitleRender();
	bool TitleScene();
	void InfoRender();
	enum class MENU {
		START, INFO, QUIT
	};
	MENU MenuRender();
	enum class KEY {
		UP, DOWN, SPACE, NONE
	};
	KEY KeyController();
};