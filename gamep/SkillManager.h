#pragma once
#include "define.h"
#include "BlockGenSkill.h"
class SkillManager
{
private:
	SkillManager() = default;
public:
	void Init();
	void Render();
private:
	void SkillInfoRender();
public:
	static SkillManager* GetInst()
	{
		if (m_pInst == nullptr)
			m_pInst = new SkillManager;
		return m_pInst;
	}
	static void DestroyInst()
	{
		SAFE_DELETE(m_pInst);
		/*if (m_pInst != nullptr)
		{
			delete m_pInst;
			m_pInst = nullptr;
		}*/
	}
public:
	BlockGenSkill blockGen;
private:
	static SkillManager* m_pInst;
};

