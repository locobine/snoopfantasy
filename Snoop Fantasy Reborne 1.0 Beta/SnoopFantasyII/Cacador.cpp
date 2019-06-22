#include "Cacador.h"



Cacador::Cacador()
{
}


Cacador::~Cacador()
{
}

void Cacador::inicializar()
{
	if (!txtChar.loadFromFile("bin/cacador.png"))
	{
		cout << "Nao rolou cacador." << endl;
		system("pause"); return;
	}

	animParado.setSpriteSheet(txtChar);
	animAndando.setSpriteSheet(txtChar);
	animAtacando.setSpriteSheet(txtChar);
	animTomaDano.setSpriteSheet(txtChar);
	animMorrer.setSpriteSheet(txtChar);
	animMorto.setSpriteSheet(txtChar);
	animEspecial.setSpriteSheet(txtChar);
	animEspecial2.setSpriteSheet(txtChar);
	animEspecial3.setSpriteSheet(txtChar);

	//animParado
	animParado.addFrame(IntRect(0, 0, 96, 96));
	animParado.addFrame(IntRect(96, 0, 96, 96));
	animParado.addFrame(IntRect(192, 0, 96, 96));
	animParado.addFrame(IntRect(288, 0, 96, 96));

	//animAndando
	animAndando.addFrame(IntRect(0, 96, 96, 96));
	animAndando.addFrame(IntRect(96, 96, 96, 96));
	animAndando.addFrame(IntRect(192, 96, 96, 96));
	animAndando.addFrame(IntRect(288, 96, 96, 96));

	//animAtacando
	animAtacando.addFrame(IntRect(0, 192, 96, 96));
	animAtacando.addFrame(IntRect(96, 192, 96, 96));
	animAtacando.addFrame(IntRect(192, 192, 96, 96));
	animAtacando.addFrame(IntRect(288, 192, 96, 96));

	//animTomaDano
	animTomaDano.addFrame(IntRect(0, 288, 96, 96));
	animTomaDano.addFrame(IntRect(96, 288, 96, 96));
	animTomaDano.addFrame(IntRect(192, 288, 96, 96));
	animTomaDano.addFrame(IntRect(288, 288, 96, 96));
	animTomaDano.addFrame(IntRect(384, 288, 96, 96));
	animTomaDano.addFrame(IntRect(480, 288, 96, 96));

	//animMorrer
	animMorrer.addFrame(IntRect(0, 384, 96, 96));
	animMorrer.addFrame(IntRect(96, 384, 96, 96));
	animMorrer.addFrame(IntRect(192, 384, 96, 96));
	animMorrer.addFrame(IntRect(288, 384, 96, 96));
	animMorrer.addFrame(IntRect(384, 384, 96, 96));
	animMorrer.addFrame(IntRect(480, 384, 96, 96));
	animMorrer.addFrame(IntRect(576, 384, 96, 96));
	animMorrer.addFrame(IntRect(672, 384, 96, 96));

	//animMorto
	animMorto.addFrame(IntRect(672, 384, 96, 96));

	//animEspecial
	animEspecial.addFrame(IntRect(0, 480, 96, 96));
	animEspecial.addFrame(IntRect(96, 480, 96, 96));
	animEspecial.addFrame(IntRect(192, 480, 96, 96));
	animEspecial.addFrame(IntRect(288, 480, 96, 96));

	//animEspecial2

	//animEspecial3


	spChar.setPosition(x, y);
	spChar.setFrameTime(seconds(0.2));
	spChar.setLooped(true);

	animaAtual = &animParado;
	nAnimacaoAtual = 0;
	atacando = false;
	podeAndar = true;

	deveRecuar = false;
	cooldownCacador = false;
	speedRecuo = 0.7;
	//speedRecuo = 0.1;
	//speedAtual = 0.05;
	speedAtual = 0.4;
	vida = 100;
	ataque = 20;
	morrer = false;
	especializando = false;
	andando = false;
	morto = false;
}

void Cacador::atualizar()
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