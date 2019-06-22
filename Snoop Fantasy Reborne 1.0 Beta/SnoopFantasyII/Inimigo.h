#pragma once

#include <SFML\Graphics.hpp>
#include "AnimatedSprite.h"
#include <iostream>
#include "Timer.h"

using namespace std;
using namespace sf;

enum tipoMonstro
{
	Cobra1, Cobra2, Cobra3
};

class Inimigo
{
public:
	Inimigo();
	~Inimigo();
	void inicializar(int tipo);
	void atualizar();
	AnimatedSprite desenhar();
	void andaDireita();
	void andaEsquerda();
	void andaCima();
	void andaBaixo();
	int getAtaque();
	int getVida(); //area total 120 110
	void recebeDano(int dano); //160 55
	int getXcolisao();
	int getYcolisao();
	bool getMorto();
	void ataca();
	bool getAtacou();
	void setAtacou(bool att);
private:
	Clock frameClock;
	Texture txtIni;
	AnimatedSprite spIni;
	Animation animParado, animAndando, animAtacando, *animaAtual;
	float x, y;
	int nAnimacaoAtual;
	int vida, ataque;
	bool morto;
	bool podeAtacar, atacando, atacou;
	Timer cooldownAtaque, tempoAtaque;
};

