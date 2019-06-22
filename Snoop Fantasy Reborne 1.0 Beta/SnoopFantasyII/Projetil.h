#pragma once
#include <SFML\Graphics.hpp>
#include "AnimatedSprite.h"
#include <iostream>
#include "Timer.h"

using namespace std;
using namespace sf;

enum AnimacaoMagia
{
	Criacao, Efeito
};

class Projetil
{
public:
	Projetil();
	~Projetil();
	void inicializar(int tipoMagia_, bool alvo_, int tipoAlvo_, int x_, int y_);
	void atualizar();
	AnimatedSprite desenhar();
	int getX();
	int getY();
	bool getDeleteMe();
	void setDeleteMeTrue();

private:
	Clock frameClock;
	Texture txtProjetil;
	AnimatedSprite spProjetil;
	Animation animEfeito, *animaAtual, animCriacao;
	float x, y, xInicial, yInicial;
	int tipoMagia, tipoAlvo, nAnimacaoAtual;
	bool alvo, deleteMe;
	float speed;
};

