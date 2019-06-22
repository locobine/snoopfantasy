#include "Inimigo.h"



Inimigo::Inimigo()
{
}


Inimigo::~Inimigo()
{
}

void Inimigo::inicializar(int tipo)
{
	switch (tipo)
	{
	case Cobra1:
		if (!txtIni.loadFromFile("bin/snake1.png"))
		{
			cout << "Nao rolou cobra1." << endl;
			system("pause"); return;
		}
		animParado.setSpriteSheet(txtIni);
		animAndando.setSpriteSheet(txtIni);
		animAtacando.setSpriteSheet(txtIni);

		//animParado
		animParado.addFrame(IntRect(0, 0, 219, 110));
		animParado.addFrame(IntRect(219, 0, 219, 110));
		animParado.addFrame(IntRect(438, 0, 219, 110));
		animParado.addFrame(IntRect(657, 0, 219, 110));

		//animAndando
		animAndando.addFrame(IntRect(0, 110, 219, 110));
		animAndando.addFrame(IntRect(219, 110, 219, 110));
		animAndando.addFrame(IntRect(438, 110, 219, 110));
		animAndando.addFrame(IntRect(657, 110, 219, 110));

		//animAtacando
		animAtacando.addFrame(IntRect(0, 220, 219, 110));
		animAtacando.addFrame(IntRect(219, 220, 219, 110));
		animAtacando.addFrame(IntRect(438, 220, 219, 110));
		animAtacando.addFrame(IntRect(657, 220, 219, 110));
		animAtacando.addFrame(IntRect(876, 220, 219, 110));

		x = 800;
		y = 200;

		spIni.setPosition(x, y);
		spIni.setFrameTime(seconds(0.2));
		spIni.setLooped(true);

		animaAtual = &animParado;
		nAnimacaoAtual = 0;
		vida = 100;
		ataque = 10;
		break;
	case Cobra2:
		if (!txtIni.loadFromFile("bin/snake2.png"))
		{
			cout << "Nao rolou cobra2." << endl;
			system("pause"); return;
		}
		animParado.setSpriteSheet(txtIni);
		animAndando.setSpriteSheet(txtIni);
		animAtacando.setSpriteSheet(txtIni);

		//animParado
		animParado.addFrame(IntRect(0, 0, 219, 110));
		animParado.addFrame(IntRect(219, 0, 219, 110));
		animParado.addFrame(IntRect(438, 0, 219, 110));
		animParado.addFrame(IntRect(657, 0, 219, 110));

		//animAndando
		animAndando.addFrame(IntRect(0, 110, 219, 110));
		animAndando.addFrame(IntRect(219, 110, 219, 110));
		animAndando.addFrame(IntRect(438, 110, 219, 110));
		animAndando.addFrame(IntRect(657, 110, 219, 110));

		//animAtacando
		animAtacando.addFrame(IntRect(0, 220, 219, 110));
		animAtacando.addFrame(IntRect(219, 220, 219, 110));
		animAtacando.addFrame(IntRect(438, 220, 219, 110));
		animAtacando.addFrame(IntRect(657, 220, 219, 110));
		animAtacando.addFrame(IntRect(876, 220, 219, 110));

		x = 800;
		y = 400;

		spIni.setPosition(x, y);
		spIni.setFrameTime(seconds(0.2));
		spIni.setLooped(true);

		animaAtual = &animParado;
		nAnimacaoAtual = 0;
		vida = 150;
		ataque = 15;
		break;
	case Cobra3:
		if (!txtIni.loadFromFile("bin/snake3.png"))
		{
			cout << "Nao rolou cobra3." << endl;
			system("pause"); return;
		}
		animParado.setSpriteSheet(txtIni);
		animAndando.setSpriteSheet(txtIni);
		animAtacando.setSpriteSheet(txtIni);

		//animParado
		animParado.addFrame(IntRect(0, 0, 219, 110));
		animParado.addFrame(IntRect(219, 0, 219, 110));
		animParado.addFrame(IntRect(438, 0, 219, 110));
		animParado.addFrame(IntRect(657, 0, 219, 110));

		//animAndando
		animAndando.addFrame(IntRect(0, 110, 219, 110));
		animAndando.addFrame(IntRect(219, 110, 219, 110));
		animAndando.addFrame(IntRect(438, 110, 219, 110));
		animAndando.addFrame(IntRect(657, 110, 219, 110));

		//animAtacando
		animAtacando.addFrame(IntRect(0, 220, 219, 110));
		animAtacando.addFrame(IntRect(219, 220, 219, 110));
		animAtacando.addFrame(IntRect(438, 220, 219, 110));
		animAtacando.addFrame(IntRect(657, 220, 219, 110));
		animAtacando.addFrame(IntRect(876, 220, 219, 110));

		x = 1100;
		y = 300;

		spIni.setPosition(x, y);
		spIni.setFrameTime(seconds(0.2));
		spIni.setLooped(true);

		animaAtual = &animParado;
		nAnimacaoAtual = 0;
		vida = 200;
		ataque = 25;
		break;
	}
	morto = false;
	podeAtacar = false;
	atacando = false;
}

void Inimigo::atualizar()
{
	Time frameTime = frameClock.restart();
	if (podeAtacar && !atacando)
	{
		ataca();
	}
	if (atacando && !spIni.isPlaying())
	{
		cout << "entrou em atacando pelo menos?" << endl;
		animaAtual = &animParado;
		spIni.setFrameTime(seconds(0.2));
		spIni.setLooped(true);
		/*if (tempoAtaque.checaConta() == true)
		{
			cout << "REALMENTE ATACOU CARALHO" << endl;
			animaAtual = &animParado;
			spIni.setFrameTime(seconds(0.2));
			spIni.setLooped(true);
		}*/
		/*if (!spIni.isPlaying())
		{
			cout << "realmente atacou" << endl;
			animaAtual = &animParado;
			spIni.setFrameTime(seconds(0.2));
			spIni.setLooped(true);
		}*/
		atacando = false;
		podeAtacar = false;
		atacou = true;
	}

	spIni.setPosition(x, y);

	spIni.play(*animaAtual);

	spIni.update(frameTime);
}

AnimatedSprite Inimigo::desenhar()
{
	return spIni;
}

int Inimigo::getVida()
{
	return vida;
}

int Inimigo::getAtaque()
{
	return ataque;
}

void Inimigo::recebeDano(int dano)
{
	vida -= dano;
	podeAtacar = true;
	if (vida <= 0)
	{
		morto = true;
	}
	cout << "Cobra grita" << endl;
}

int Inimigo::getXcolisao()
{
	return x + 160;
}

int Inimigo::getYcolisao()
{
	return y + 55;
}

bool Inimigo::getMorto()
{
	return morto;
}

void Inimigo::ataca()
{
	if (!atacando && podeAtacar)
	{
		cout << "entrou aqui dentro do naoatacando ee podeatacar" << endl;
		float segs = 0.2;
		spIni.setFrameTime(seconds(segs));
		spIni.setLooped(false);
		animaAtual = &animAtacando;
		if (spIni.isPlaying())
		{
			cout << "Ta tocando essa bagaca" << endl;
		}
		if (!spIni.isLooped())
		{
			cout << "puta que pariu n ta loopado" << endl;
		}
		atacando = true;
		podeAtacar = false;
		nAnimacaoAtual = 2;
		tempoAtaque.contaAte(1.0);
	}
}

bool Inimigo::getAtacou()
{
	return atacou;
}

void Inimigo::setAtacou(bool att)
{
	atacou = att;
}