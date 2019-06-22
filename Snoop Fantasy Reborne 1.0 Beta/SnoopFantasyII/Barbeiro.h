#pragma once
#include "Personagem.h"
class Barbeiro :
	public Personagem
{
public:
	Barbeiro();
	~Barbeiro();
	void inicializar(int x_, int y_);
	void atualizar();
};

