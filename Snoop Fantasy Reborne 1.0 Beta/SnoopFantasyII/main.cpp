#pragma once
#include "Jogo.h"

int main(int ArgC, char** ArgV)
{
	Jogo game("Cevelezeition");
	game.carregaJogo();
	return 0;
}