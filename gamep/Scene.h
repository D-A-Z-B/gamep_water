#pragma once
class Scene
{
public:
	virtual void TitleRender() abstract;
	virtual bool TitleScene() abstract;
	virtual void InfoRender() abstract;
};
