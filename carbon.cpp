// Carbon's otuA-rekcilC - https://twitter.com/CarbonatedCPU - Contact me
#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;

const float INTERVAL = 49;

void getMousePos (long&, long&);
void printMenu (HWND, char []);

int main ()
{
	SetConsoleTitle("Carbon's rekcilC"); 
	
	static bool isClickerOn = false;	
	
	while (!GetAsyncKeyState(VK_F8))
	{
		HWND hwnd;
		char str[50] = "Minecraft Client";
		
		printMenu(hwnd, str);
		cout << ((isClickerOn == false) ? "otuA-rekcilC is: [OFF]" : "otuA-rekcilC is: [ON]") << endl;	
		
		static long xPos = 0, yPos= 0;
			
		if (GetAsyncKeyState(VK_F4))
		{	 	 	 
				isClickerOn = ((isClickerOn == true) ? false : true);
				
				while (isClickerOn == true)
				{
					if (GetAsyncKeyState(VK_F4))
					{
						isClickerOn = false;
						break;
					}
					else
					{	
						printMenu(hwnd, str);
						cout << ((isClickerOn == false) ? "otuA-rekcilC is: [OFF]" : "otuA-rekcilC is: [ON]") << endl;
						mouse_event(MOUSEEVENTF_LEFTDOWN, xPos, yPos, 0, 0);
						mouse_event(MOUSEEVENTF_LEFTUP, xPos, yPos, 0, 0);
						Sleep(INTERVAL);	
					} 	  
				}
		}	
			
		Sleep(600);
	}

}

void getMousePos (long &x, long &y)
{
	POINT p;
	GetCursorPos(&p);
	
	x = p.x;
	y = p.y;
	
	GetCursorPos(&p);
	if (p.x != x && p.y != y)
	{
		x = p.x;
		y = p.y;
		cout << x << ", " << y << endl;
	}	
}

void printMenu (HWND hwnd, char str[])
{
	system("cls");
		
	cout << "==================================" << endl
		 << "==\tSeekedNow's otuA-rekcilC\t==" << endl 
		 << "==================================" << endl;
		
	hwnd = FindWindow(NULL, str);
	
	cout << "\nTarget window is: '" << str << "'"<< endl;
	if (hwnd != NULL)
		cout << "Target status: [FOUND]" << endl;
	else
		cout << "Target status: [NOT FOUND]" << endl;
		
	cout << "--------------------------------------" << endl	  
		 << "\nPress F4 to start otuA-gnikcilC" << endl
		 << "Press F8 to exit\n" << endl 
		 << "--------------------------------------" << endl;
		 
	cout << "\nClicking interval is: " << INTERVAL/1000 << "s" << endl;  
}

//This is just a simple line of strings <3
//Expect changes!
//It's in reverse to stop string finders from finding the Reversed word to this file...
//<3


