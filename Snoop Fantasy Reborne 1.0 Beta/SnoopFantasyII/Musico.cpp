#include "Musico.h"



Musico::Musico()
{
}


Musico::~Musico()
{
}

void Musico::inicializar()
{

}

void Musico::atualizar()
{
	Time frameTime = frameClock.restart();

	if (!morto && !morrer)
	{
		if (especializando && !spChar.isPlaying())
		{
			desEspecial();
		}

		if (atacando)
		{
			if (!spChar.isPlaying())
			{
				if (nAnimacaoAtual != Parado)
				{
					cout << "realmente entrou aqui" << endl;
					setAnima(Parado);
				}
				atacando = false;
				podeAndar = true;
			}
		}
		else if (!especializando && nAnimacaoAtual != TomaDano)
		{
			if (!andando && nAnimacaoAtual != Parado)
			{
				setAnima(Parado);
			}
		}
		if (!spChar.isPlaying() && nAnimacaoAtual == TomaDano)
		{
			podeAndar = true;
			setAnima(Parado);
		}
		if (cooldownCacador && tempoCooldownCacador.checaConta())
		{
			cout << "entrou no cooldowncacador!" << endl;
			cooldownCacador = false;
		}
	}
	if (morrer && !morto)
	{
		nAnimacaoAtual = Morrer;
		animaAtual = &animMorrer;
		spChar.setLooped(false);
		morto = true;
	}
	if (morrer && morto)
	{
		if (nAnimacaoAtual == Morrer)
		{
			if (!spChar.isPlaying())
			{
				nAnimacaoAtual = Morto;
				animaAtual = &animMorto;
			}
		}
	}

	spChar.setPosition(x, y);

	spChar.play(*animaAtual);

	spChar.update(frameTime);
}