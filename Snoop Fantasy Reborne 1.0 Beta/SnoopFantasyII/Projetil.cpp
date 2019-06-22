#include "Projetil.h"



Projetil::Projetil()
{
}


Projetil::~Projetil()
{
}

//TIPOS MAGIA 0 = flecha 1 = bola de fogo 2 = heal em area

void Projetil::inicializar(int tipoMagia_, bool alvo_, int tipoAlvo_, int x_, int y_)
{
	x = x_;
	y = y_;
	xInicial = x;
	yInicial = y;
	tipoMagia = tipoMagia_;
	alvo = alvo_;
	tipoAlvo = tipoAlvo_;
	switch (tipoMagia)
	{
	case 0:
		if (!txtProjetil.loadFromFile("bin/cacador.png"))
		{
			cout << "Nao rolou cacador." << endl;
			system("pause"); return;
		}

		animEfeito.setSpriteSheet(txtProjetil);

		animEfeito.addFrame(IntRect(576, 0, 96, 96));
		animEfeito.addFrame(IntRect(672, 0, 96, 96));

		spProjetil.setPosition(x, y);
		spProjetil.setFrameTime(seconds(0.15));
		spProjetil.setLooped(true);

		animaAtual = &animEfeito;
		nAnimacaoAtual = Efeito;

		speed = 1.2;

		break;
	case 1:
		if (!txtProjetil.loadFromFile("bin/musico.png"))
		{
			cout << "Nao rolou musico." << endl;
			system("pause"); return;
		}

		animEfeito.setSpriteSheet(txtProjetil);
		animCriacao.setSpriteSheet(txtProjetil);

		animCriacao.addFrame(IntRect(480, 0, 96, 96));
		animCriacao.addFrame(IntRect(576, 0, 96, 96));
		animCriacao.addFrame(IntRect(672, 0, 96, 96));

		animEfeito.addFrame(IntRect(576, 96, 96, 96));
		animEfeito.addFrame(IntRect(672, 96, 96, 96));

		spProjetil.setPosition(x, y);
		spProjetil.setFrameTime(seconds(0.15));
		spProjetil.setLooped(false);
		nAnimacaoAtual = Criacao;

		animaAtual = &animCriacao;

		speed = 0.7;

		break;
	case 2:
		if (!txtProjetil.loadFromFile("bin/barbeiro.png"))
		{
			cout << "Nao rolou barbeiro." << endl;
			system("pause"); return;
		}

		animEfeito.setSpriteSheet(txtProjetil);

		animEfeito.addFrame(IntRect(384, 0, 96, 96));
		animEfeito.addFrame(IntRect(480, 0, 96, 96));
		animEfeito.addFrame(IntRect(576, 0, 96, 96));
		animEfeito.addFrame(IntRect(672, 0, 96, 96));
		animEfeito.addFrame(IntRect(768, 0, 96, 96));
		break;
	}
	deleteMe = false;
}

void Projetil::atualizar()
{
	Time frameTime = frameClock.restart();

	switch (tipoMagia)
	{
	case 0:
		x += speed;
		if (x > (xInicial + 600))
		{
			deleteMe = true;
		}
		break;
	case 1:
		x += speed;
		if (!spProjetil.isPlaying() && nAnimacaoAtual == Criacao)
		{
			nAnimacaoAtual = Efeito;
			animaAtual = &animEfeito;
		}
		if (x > (xInicial + 600))
		{
			deleteMe = true;
		}
		break;

	case 2:

		break;
	}

	spProjetil.setPosition(x, y);

	spProjetil.play(*animaAtual);

	spProjetil.update(frameTime);
}

AnimatedSprite Projetil::desenhar()
{
	return spProjetil;
}

int Projetil::getX()
{
	return x;
}

int Projetil::getY()
{
	return y;
}

bool Projetil::getDeleteMe()
{
	return deleteMe;
}

void Projetil::setDeleteMeTrue()
{
	deleteMe = true;
}