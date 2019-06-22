#pragma once
#include "Personagem.h"
class Ferreiro :
	public Personagem
{
public:
	Ferreiro();
	~Ferreiro();
	virtual void inicializar(int x_, int y_);
	void atualizar();

private:

};

