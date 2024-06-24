#include "TitleScene.h"
#include "console.h"
#include "DeadScene.h"
#include "Core.h"

int main()
{
	DeadMENU isDead = DeadMENU::GOTITLE;
	system("title WATER | mode con cols=100 lines=30");
	LockResize();
	SetCursorVis(false, 1);
	while (true)
	{
		if (isDead == DeadMENU::GOTITLE)
		{
 			if (!TitleScene()) 
			{
				return 0;
			}
		}

		if (Core::GetInst()->Init())
		{
			cout << "Game Init Error" << endl;
			Core::DestroyInst();
			return 0;
		}
		Core::GetInst()->Run();
		isDead = DeadScene();
		if (isDead == DeadMENU::QUIT)
			return 0;
		Core::DestroyInst();
	}
}