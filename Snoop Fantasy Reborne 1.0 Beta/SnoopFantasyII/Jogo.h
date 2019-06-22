#pragma once
#include <SFML\Graphics.hpp>
#include "Personagem.h"
#include <SFML\Audio.hpp>
#include <fstream>
#include <iostream>
#include <time.h>
#include "Timer.h"
#include "Inimigo.h"
#include "Projetil.h"
#include "ListaPersonagens.h"
#include "Ferreiro.h"
#include "Collision.h"

//enum Menu
//{
//	Logo, NovoJogo, ContinuarJogo, Creditos, Sair,
//	Inicial, CriarTime, SelecionarTime, InicializarServidor, ConectarServidor,
//	preBatalha, Batalha, AcaoAtacar, AcaoDefender, AcaoItem, AcaoMagia, GameOver
//};

using namespace std;
using namespace sf;

enum MomentoAtualDoJogo
{
	MenuIni, Editor, TelaJogo
};

class Jogo
{
public:
	Jogo();
	Jogo(string Title);
	~Jogo();

	void carregaJogo();

private:
	void inicializar();
	void executar();
	void finalizar();
	void maoManager(Event eventinho);
	void checaCliques();
	void coliseia();
	void moveAFK();
	void trocaSegundo();
	void trocaTerceiro();
	void interpretaMagia();
	RenderWindow janela;
	Mouse mouse;
	Clock frameClock;
	Sprite sprBatalha, sprUIbatalha;
	Texture txtBatalha, txtUIbatalha;
	Personagem persBeta;
	Personagem *persoDinam;
	Personagem tresPerso[3];
	bool correndo, playerAtacando, cacadorAtacou, andou, delayPassou;
	bool podeCima, podeBaixo, podeEsquerda, podeDireita, magoMagiou;
	//bool direita, cima, esquerda, baixo;
	Timer reloginho, relogioAtaque, relogioAtaqueCacador, relogioDelayCaminhada, relogioMagia;
	Inimigo iniBeta[3];
	ListaPersonagens filaPerso;
	vector<Projetil*> projeteis;
};