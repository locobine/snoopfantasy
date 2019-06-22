#pragma once

#include <SFML\Graphics.hpp>
#include "AnimatedSprite.h"
#include <iostream>
#include "Timer.h"
#include "Projetil.h"

using namespace std;
using namespace sf;

struct Magia
{
	bool magiaInimigo, efeitoSecundario;
	string nomeMagia, magiaEfeito;
	float speedMagia;
	int tipoMagia, alvoMagia;
};

enum Animacao
{
	Parado, Andando, Atacando, TomaDano, Morrer, Morto, Especial, Especial2, Especial3
};

class Personagem
{
public:
	Personagem();
	~Personagem();

	virtual void inicializar(int tipoPersonagem_, int x_, int y_);
	AnimatedSprite desenhar();
	void andaDireita();
	void andaEsquerda();
	void andaCima();
	void andaBaixo();
	void setAnima(int qual);
	void ataca();
	bool getAtacando();
	void setCorrendo(bool estaCorrendo);
	int getXbotas();
	int getYbotas();
	int getVida();
	int getAtaque();
	float getTempoFrames();
	void recebeDano(int dano); // 75 45
	int getXatacando();
	int getYatacando();
	int getXmeio(); // 50 94
	int getYmeio(); // 30 50
	int getAnimacaoAtual();
	bool getMorto();
	void especial();
	bool getEspecializando();
	void desEspecial();
	void defender();
	void recuar();
	void castar();
	int getTipoPersonagem();
	int movePara(int x_, int y_);
	float getXReal();
	float getYReal();
	void paraAndar();
	bool getAndando();
	bool getCooldownCacador();
	Magia getMagia();


	Personagem *proximo;
	Personagem *anterior;
protected:

	Clock frameClock;
	Texture txtChar;
	AnimatedSprite spChar;
	Animation animParado, animAndando, animAtacando, animTomaDano, animMorrer, animMorto, animEspecial, animEspecial2, animEspecial3, *animaAtual;
	float x, y;
	int nAnimacaoAtual;
	Timer tempoAtaque, tempoCooldownCacador;
	bool atacando, podeAndar, morrer, especializando, andando, cooldownCacador, deveRecuar, morto;
	float speedAtual, speedRecuo;
	int ataque, vida, tipoPersonagem;
	Magia magiazinha;
};

//110x85