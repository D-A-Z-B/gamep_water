#include "TitleScene.h"
#include "console.h"

int main() {
	SetCursorVis(false, 1);
	if (!TitleScene()) {
		return 0;
	}
}