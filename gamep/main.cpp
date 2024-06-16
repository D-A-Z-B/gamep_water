#include "TitleScene.h"
#include "console.h"
#include "Core.h"

int main() {
	system("title SIBAL | mode con cols=55 lines=30");
	LockResize();
	SetCursorVis(false, 1);
	if (!TitleScene()) {
		return 0;
	}
	else
	{
		if (Core::GetInst()->Init())
		{
			cout << "Game Init Error" << endl;
			Core::DestroyInst();
			return 0;
		}
		Core::GetInst()->Run();
		Core::DestroyInst();
	}
}