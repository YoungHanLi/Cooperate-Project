/**
* @mainpage	C++팀 프로젝트
*				ChessGame Project
* @author	Chess Team
*				김나영 201811103
*				김윤재 201824446
*				이영한 201824552
*				장하림 201924659
* @date		21/04 ~ 21/05
* @version	1.0.0
* @brief	체스콘솔게임
* @see		https://github.com/ashjang/chess
*/
#include <iostream>
#include "ChessConsole.h"

int main(void)
{
	ChessConsole program;
	program.Run();
	program.Quit();
	return 0;
}
