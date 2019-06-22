#include "Personagem.h"


Personagem::Personagem()
{
}

Personagem::~Personagem()
{
}

void Personagem::inicializar(int tipoPersonagem_, int x_, int y_)
{
	x = x_;
	y = y_;
	tipoPersonagem = tipoPersonagem_;
	andando = false;
	morto = false;
}

AnimatedSprite Personagem::desenhar()
{
	return spChar;
}

void Personagem::andaDireita()
{
	if (podeAndar)
	{
		if (tipoPersonagem != 3)
		{
			if (nAnimacaoAtual != Andando)
			{
				nAnimacaoAtual = Andando;
				animaAtual = &animAndando;
			}
			x += speedAtual;
		}
		else
		{
			if (nAnimacaoAtual != Andando)
			{
				nAnimacaoAtual = Andando;
				animaAtual = &animAndando;
			}
			x += speedAtual;
		}
		andando = true;
	}
	
}

void Personagem::andaEsquerda()
{
	if (podeAndar)
	{
		if (tipoPersonagem != 3)
		{
			if (nAnimacaoAtual != Andando)
			{
				nAnimacaoAtual = Andando;
				animaAtual = &animAndando;
			}
			x -= speedAtual;
		}
		else
		{
			if (deveRecuar && !cooldownCacador)
			{
				recuar();
				x -= (speedAtual + speedRecuo);
			}
			else
			{
				if (nAnimacaoAtual != Andando)
				{
					nAnimacaoAtual = Andando;
					animaAtual = &animAndando;
				}
				x -= speedAtual;
			}
		}
		andando = true;
	}
}

void Personagem::andaCima()
{
	if (podeAndar)
	{
		if (tipoPersonagem != 3)
		{
			if (nAnimacaoAtual != Andando)
			{
				nAnimacaoAtual = Andando;
				animaAtual = &animAndando;
			}
			y -= speedAtual;
		}
		else
		{
			if (especializando)
			{
				/*if (nAnimacaoAtual != Especial)
				{
					nAnimacaoAtual = Especial;
					animaAtual = &animEspecial;
				}*/
				y -= speedAtual;
			}
			else
			{
				if (nAnimacaoAtual != Andando)
				{
					nAnimacaoAtual = Andando;
					animaAtual = &animAndando;
				}
				y -= speedAtual;
			}
		}
		andando = true;
	}
}

void Personagem::andaBaixo()
{
	if (podeAndar)
	{
		if (tipoPersonagem != 3)
		{
			if (nAnimacaoAtual != Andando)
			{
				nAnimacaoAtual = Andando;
				animaAtual = &animAndando;
			}
			y += speedAtual;
		}
		else
		{
			if (especializando)
			{
				/*if (nAnimacaoAtual != Especial)
				{
					nAnimacaoAtual = Especial;
					animaAtual = &animEspecial;
				}*/
				y += speedAtual;
			}
			else
			{
				if (nAnimacaoAtual != Andando)
				{
					nAnimacaoAtual = Andando;
					animaAtual = &animAndando;
				}
				y += speedAtual;
			}
		}
		andando = true;
	}
}

void Personagem::setAnima(int qual)
{
	if (qual != nAnimacaoAtual)
	{
		switch (qual)
		{
		case 0:
			animaAtual = &animParado;
			nAnimacaoAtual = 0;
			spChar.setFrameTime(seconds(0.2));
			spChar.setLooped(true);
			break;
		case 1:
			animaAtual = &animAndando;
			nAnimacaoAtual = 1;
			spChar.setFrameTime(seconds(0.2));
			spChar.setLooped(true);
			break;
		case 2:
			animaAtual = &animAtacando;
			nAnimacaoAtual = 2;
			break;
		default:
			animaAtual = &animParado;
			nAnimacaoAtual = 0;
			spChar.setFrameTime(seconds(0.2));
			spChar.setLooped(true);
			break;
		}
	}
}

void Personagem::ataca()
{
	if (!atacando && !morrer)
	{
		double segs = 0.2;
		if (nAnimacaoAtual != Atacando)
		{
			nAnimacaoAtual = Atacando;
			animaAtual = &animAtacando;
			spChar.setFrameTime(seconds(segs));
			spChar.setLooped(false);
			if (spChar.isPlaying())
			{
				cout << "Ta tocando" << endl;
			}
		}
		atacando = true;
		podeAndar = false;
	}
}

bool Personagem::getAtacando()
{
	return atacando;
}

void Personagem::setCorrendo(bool estaCorrendo)
{
	if (estaCorrendo)
	{
		if (speedAtual != 0.6)
		{
			speedAtual = 0.6;
		}
	}
	else
	{
		if (speedAtual != 0.4)
		{
			speedAtual = 0.4;
		}
	}
	/*if (estaCorrendo)
	{
		if (speedAtual != 0.08)
		{
			speedAtual = 0.08;
		}
	}
	else
	{
		if (speedAtual != 0.05)
		{
			speedAtual = 0.05;
		}
	}*/
}

int Personagem::getXbotas()
{
	return x;
}

int Personagem::getYbotas()
{
	return y + 66;
}

int Personagem::getVida()
{
	return vida;
}

int Personagem::getAtaque()
{
	return ataque;
}

float Personagem::getTempoFrames()
{
	return spChar.getFrameTime().asSeconds();
}

void Personagem::recebeDano(int dano)
{
	if (nAnimacaoAtual != TomaDano)
	{
		nAnimacaoAtual = TomaDano;
		animaAtual = &animTomaDano;
		spChar.setLooped(false);
		podeAndar = false;
		vida -= dano;
		
		cout << "player foi machucado" << endl;
	}
	if (vida <= 0)
	{
		morrer = true;
	}
}

int Personagem::getXatacando()
{
	return x + 80;
}

int Personagem::getYatacando()
{
	return y + 45;
}

int Personagem::getXmeio()
{
	return x + 30;
}

int Personagem::getYmeio()
{
	return y + 50;
}

int Personagem::getAnimacaoAtual()
{
	return nAnimacaoAtual;
}

bool Personagem::getMorto()
{
	return morto;
}

void Personagem::especial()
{
	if (!especializando)
	{
		atacando = false;
		switch (tipoPersonagem) //1 = ferreiro 2 = barbeiro 3 = cacador 4 = musico
		{
		case 1:
			defender();
			break;
		case 2:
			castar();
			break;
		case 3:
			if (!deveRecuar)
			{
				deveRecuar = true;
			}
			break;
		case 4:
			castar();
			break;
		}
		
	}
}

bool Personagem::getEspecializando()
{
	return especializando;
}

void Personagem::desEspecial()
{
	especializando = false;
	podeAndar = true;
	setAnima(Parado);
	if (tipoPersonagem == 3)
	{
		tempoCooldownCacador.contaAte(3.0);
		cooldownCacador = true;
		deveRecuar = false;
	}
}

void Personagem::defender()
{
	if (nAnimacaoAtual != Especial)
	{
		nAnimacaoAtual = Especial;
		especializando = true;
		animaAtual = &animEspecial;
		double segs = 0.15;
		spChar.setFrameTime(seconds(segs));
		spChar.setLooped(false);
		podeAndar = false;
	}
}

void Personagem::recuar()
{
	if (nAnimacaoAtual != Especial)
	{
		nAnimacaoAtual = Especial;
		especializando = true;
		animaAtual = &animEspecial;
		double segs = 0.15;
		spChar.setFrameTime(seconds(segs));
		spChar.setLooped(false);
	}
}

void Personagem::castar()
{
	if (nAnimacaoAtual != Especial)
	{
		nAnimacaoAtual = Especial;
		especializando = true;
		animaAtual = &animEspecial;
		double segs = 0.15;
		spChar.setFrameTime(seconds(segs));
		spChar.setLooped(false);
		podeAndar = false;
	}
}

int Personagem::getTipoPersonagem()
{
	return tipoPersonagem;
}

int Personagem::movePara(int x_, int y_)
{
	int xAlvo, yAlvo, xAtual, yAtual;
	xAlvo = x_ - 50;
	yAlvo = y_;
	xAtual = x;
	yAtual = y;
	int andou = 0;
	//speedAtual = 0.04;
	speedAtual = 0.3;
	if (xAtual > xAlvo)
	{
		andaEsquerda();
		andou++;
	}
	else if (xAtual < xAlvo)
	{
		andaDireita();
		andou++;
	}
	if (yAtual < yAlvo)
	{
		andaBaixo();
		andou++;
	}
	else if (yAtual > yAlvo)
	{
		andaCima();
		andou++;
	}
	if (andou == 0)
	{
		setAnima(Parado);
	}
	return andou;
}

float Personagem::getXReal()
{
	return x;
}

float Personagem::getYReal()
{
	return y;
}

void Personagem::paraAndar()
{
	andando = false;
}

bool Personagem::getAndando()
{
	return andando;
}

bool Personagem::getCooldownCacador()
{
	return cooldownCacador;
}

Magia Personagem::getMagia()
{
	return magiazinha;
}