#include "Loading.h"

using namespace std;

bool Minecraftattach() { //Check If foreground Window is (Check Process Hacker->JavaW->Miscellaneous->Windows to understand LWJGL) LWGJL or Lunar
	HWND hWnd = GetForegroundWindow();
	char filename[256];
	GetWindowTextA(hWnd, filename, sizeof(filename));
	if (std::string(filename).find("Minecraft") != std::string::npos || std::string(filename).find("Lunar") != std::string::npos) { //Or add other Clients
		return true;
	}
	else {
		return false;
	}
}

bool cursor_visibility(){ //Checks if Cursor is Visible
	CURSORINFO ci{ sizeof(CURSORINFO) };
	if (!GetCursorInfo(&ci)) {
		return false;
	}

	const auto handle = ci.hCursor;
	if ((handle > (HCURSOR)50000) && (handle < (HCURSOR)100000)) {
		return true;
	}
	else {
		return false;
	}
}