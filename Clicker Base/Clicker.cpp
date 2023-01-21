#include "Clicker.h"

using namespace std;
//Custom **************************************************************************************************************
void ClickerFunction(int CPS, bool ExtraR, bool Blockhitenabler, bool Spikes) {
	//Use Your Own Code There
	//Physiological AC uses a Private Method
	//Here's an example of how you can code the clicker function
	//THIS IS JUST AN EXAMPLE AND RANDOMIZATION SHOULD BE DONE BETTER FOR A BETTER BYPASS AND FOR BETTER CPS ACCURACY.
	//I DON'T SUGGEST YOU TO CODE RANDOMIZATION THIS WAY, BUT IF YOU WANT TO USE IT YOU MUST USE SPIKES TO PREVENT DETECTIONS
	int randomization = 0;
	if (ExtraR) { // If you prefer ExtraR == True, you can also decide to add a trackbar and manually choose it
		randomization = 20 + rand() % 200; // a base + a randomization
	}
	else {
		randomization = 0;
	}
	                  //base + variable     + rand
	int Sleeptime1 = ((600 + randomization) + rand() % 600) / (CPS*2); //1000 ms = 1 second, for more randomization we move 400 from the base to rand
	int Sleeptime2 = ((1000 + randomization) + rand() % 400) / (CPS*2); //1000 ms = 1 second, 250 is a random number you can choose

	SendMessageW(GetForegroundWindow(), WM_LBUTTONDOWN, MK_LBUTTON , MAKELPARAM(0, 0));
	this_thread::sleep_for(std::chrono::milliseconds(Sleeptime1));
	if (Blockhitenabler) { //If you prefer Blockhitenabler == true
		SendMessageW(GetForegroundWindow(), WM_RBUTTONDOWN, MK_RBUTTON , MAKELPARAM(0, 0));
	}
	SendMessageW(GetForegroundWindow(), WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(0, 0));
	this_thread::sleep_for(std::chrono::milliseconds(Sleeptime2));
	if (Blockhitenabler) { //If you prefer Blockhitenabler == true
		SendMessageW(GetForegroundWindow(), WM_RBUTTONUP , MK_RBUTTON, MAKELPARAM(0, 0));
	}

	if (Spikes) { //If you prefer Spikes == true
		this_thread::sleep_for(std::chrono::milliseconds(50 + rand() % 100)); //100 is a random number, you can choose your own
	}
}

//Shake Effect******************************************************************************************************************
void JitterFunction(int val) {
	//Example Of Code
	POINT pos, mov;
	int i = 0;
	if (GetAsyncKeyState(VK_LBUTTON)) {
		for (i = 0; i < 5; i++) { //5 is a random number. You can modify it.
			GetCursorPos(&pos);
			mov.x = pos.x + (rand() % val);
			mov.y = pos.y + (rand() % val);
			SetCursorPos(mov.x, mov.y);
			Sleep(20); //You can modify Sleep if you want it to be slower
		}
		for (i = 0; i < 5; i++) { //5 is a random number. You can modify it.
			GetCursorPos(&pos);
			mov.x = pos.x - (rand() % val);
			mov.y = pos.y - (rand() % val);
			SetCursorPos(mov.x, mov.y);
			Sleep(20); //You can modify Sleep if you want it to be slower
		}
	}
}