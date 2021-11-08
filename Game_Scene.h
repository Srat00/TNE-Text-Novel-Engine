/*
  _______        _     _   _                _   ______             _             
 |__   __|      | |   | \ | |              | | |  ____|           (_)            
    | | _____  _| |_  |  \| | _____   _____| | | |__   _ __   __ _ _ _ __   ___  
    | |/ _ \ \/ / __| | . ` |/ _ \ \ / / _ \ | |  __| | '_ \ / _` | | '_ \ / _ \ 
    | |  __/>  <| |_  | |\  | (_) \ V /  __/ | | |____| | | | (_| | | | | |  __/ 
    |_|\___/_/\_\\__| |_| \_|\___/ \_/ \___|_| |______|_| |_|\__, |_|_| |_|\___| 
                                                              __/ |              
                                                             |___/               

	TNE (Text Novel Engine) v1.0 by 92Tars
	Copyright 2018~2021.
*/

#pragma once
#define _CRT_SECURE_NO_WARNINGS

#define DEFAULT_SCRIPT_SPEED 10;

#define FLUSH i = 0
#define ENTER printf("\n");
#define DOUBLE_ENTER printf("\n\n");
#define WINDOW_CLEAR system("cls");

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <Windows.h>

using std::vector;

struct Game_Framework
{
	int room = 0;
	int next_room = 0;
	char room_char;
};

struct Route_Framework
{
  int target_room; //현재 있는 방 번호
  int select_route; // 선택한 루트 번호
  int return_room; // 이동할 방 번호
};

char Script_Buffer[500];
char Route_Buffer[1000];
char buffer;
int my_select = 0;
int script_speed = DEFAULT_SCRIPT_SPEED;

FILE *Game_Script;
FILE *Game_Route;
Game_Framework Status;
vector<Route_Framework> Route_List;

int Game_Loop();
int Route_Select(int room, int select);
int Load_Save();
int main_menu();
int ending_menu();

void Route_Init();
void route_check();
void Auto_Save(int room_no);
void intro();

void DEBUG_ROUTE_PRINT();

