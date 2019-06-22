#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::Jogo(string Title)
{
	janela.create(VideoMode(1280, 720), Title);
	//janela.create(VideoMode(1280, 720), Title, Style::Fullscreen);
}

Jogo::~Jogo()
{
}

void Jogo::carregaJogo()
{
	inicializar();
	while (janela.isOpen())
	{
		executar();
	}
	finalizar();
}

void Jogo::finalizar()
{
	
	/*while (!minhasBuild.empty())
	{
		minhasBuild.erase(minhasBuild.begin());
	}
	while (!minhasUnit.empty())
	{
		minhasUnit.erase(minhasUnit.begin());
	}*/
	
}

void Jogo::inicializar()
{
	srand(time(0));

	if (!txtBatalha.loadFromFile("bin/batalha.png"))
	{
		cout << "Erro, nao rolou a batalha." << endl;
	}
	sprBatalha.setTexture(txtBatalha);
	sprBatalha.setPosition(0, 0);
	if (!txtUIbatalha.loadFromFile("bin/interface.png"))
	{
		cout << "Erro, nao rolou a UI da batalha." << endl;
	}
	sprUIbatalha.setTexture(txtUIbatalha);
	sprUIbatalha.setPosition(0, 0);
	//filaPerso.getPrimeiro()->inicializar(3);
	tresPerso[0].inicializar(1, 300, 300);
	tresPerso[1].inicializar(3, 200, 300);
	tresPerso[2].inicializar(4, 100, 300);
	filaPerso.insereInicio(&tresPerso[2]);
	filaPerso.insereInicio(&tresPerso[1]);
	filaPerso.insereInicio(&tresPerso[0]);

	persoDinam = new Ferreiro;
	persoDinam->inicializar(300, 300);
	filaPerso.insereInicio(persoDinam);

	//	TESTE HERANÇA
	//persTeste = new Ferreiro;
	//persTeste->
	//filaPerso.insereInicio(persTeste);
	//	CONFIRMED

	//reloginho.contaAte(4.0);
	podeCima = true;
	podeBaixo = true;
	podeEsquerda = true;
	podeDireita = true;
	playerAtacando = false;
	correndo = false;
	cacadorAtacou = false;
	andou = false;
	delayPassou = false;
	magoMagiou = false;
	for (int x = 0; x < 3; x++)
	{
		iniBeta[x].inicializar(x);
	}
}

void Jogo::maoManager(Event eventinho)
{
	Event eventto;
	eventto = eventinho;

	//if (!waiting)
	//{
	//	if (eventto.type == Event::MouseButtonReleased)
	//	{
	//		Vector2f gCoordinates;
	//		if (eventto.mouseButton.button == Mouse::Left)
	//		{
	//			cout << "larguei o esquerdo" << endl;
	//			cout << Mouse::getPosition(janela).x;
	//			//cout << xx;
	//			cout << " ";
	//			cout << Mouse::getPosition(janela).y;
	//			//cout << yy;
	//			cout << endl;
	//			if (Mouse::getPosition(janela).y > 400)
	//			{
	//				
	//			}
	//			else
	//			{
	//				cout << Mouse::getPosition(janela).x;
	//				//cout << xx;
	//				cout << " ";
	//				cout << Mouse::getPosition(janela).y;
	//				//cout << yy;
	//				cout << endl;
	//			}

	//		}
	//		if (eventto.mouseButton.button == Mouse::Right)
	//		{
	//			unsigned int xx, yy;
	//			cout << "larguei o direito" << endl;
	//		}
	//	}
	//}
	
	if (eventto.type == Event::KeyReleased)
	{
		switch (eventto.key.code)
		{
		case Keyboard::Escape:
			janela.close();
			break;
		case Keyboard::Num3:
			trocaTerceiro();
			break;
		case Keyboard::Num2:
			trocaSegundo();
			break;
		case Keyboard::Num1:

			break;
		default:

			break;
		}
	}
	
}

void Jogo::checaCliques()
{
	filaPerso.getPrimeiro()->paraAndar();
	//if (Keyboard::isKeyPressed(Keyboard::Key::Num1))
	//{
	//	//faz coisa
	//}
	//if (Keyboard::isKeyPressed(Keyboard::Key::Num2))
	//{
	//	trocaSegundo();
	//}
	//if (Keyboard::isKeyPressed(Keyboard::Key::Num3))
	//{
	//	trocaTerceiro();
	//}
	int ocupado;
	if (Mouse::isButtonPressed(Mouse::Button::Left) && !filaPerso.getPrimeiro()->getEspecializando())
	{
		if (filaPerso.getPrimeiro()->getTipoPersonagem() == 3)
		{
			if (!filaPerso.getPrimeiro()->getAtacando())
			{
				filaPerso.getPrimeiro()->ataca();
				playerAtacando = true;
				relogioAtaqueCacador.contaAte(filaPerso.getPrimeiro()->getTempoFrames() * 2);
				cacadorAtacou = true;
			}
		}
		else
		{
			filaPerso.getPrimeiro()->ataca();
			playerAtacando = true;
			relogioAtaque.contaAte(filaPerso.getPrimeiro()->getTempoFrames() * 3);
		}
	}
	else if (Mouse::isButtonPressed(Mouse::Button::Right) && !filaPerso.getPrimeiro()->getAtacando())
	{
		/*if (filaPerso.getPrimeiro()->getTipoPersonagem() == 3)
		{
			if (!filaPerso.getPrimeiro()->getCooldownCacador())
			{
				filaPerso.getPrimeiro()->especial();
			}
		}
		else
		{
			filaPerso.getPrimeiro()->especial();
		}*/
		filaPerso.getPrimeiro()->especial();
		if (filaPerso.getPrimeiro()->getTipoPersonagem() == 4 && !magoMagiou)
		{
			relogioMagia.contaAte(filaPerso.getPrimeiro()->getTempoFrames() * 4);
			magoMagiou = true;
		}
	}
	if (relogioAtaqueCacador.checaConta() && cacadorAtacou)
	{
		Projetil* magAuxiliar;
		magAuxiliar = new Projetil;
		magAuxiliar->inicializar(0, false, 0, filaPerso.getPrimeiro()->getXReal(), filaPerso.getPrimeiro()->getYReal());
		projeteis.push_back(magAuxiliar);
		cacadorAtacou = false;
		relogioAtaqueCacador.reset();
	}
	if (relogioMagia.checaConta() && magoMagiou)
	{
		Projetil* magAuxiliar;
		magAuxiliar = new Projetil;
		magAuxiliar->inicializar(1, false, 0, filaPerso.getPrimeiro()->getXReal(), filaPerso.getPrimeiro()->getYReal());
		projeteis.push_back(magAuxiliar);
		magoMagiou = false;
		relogioMagia.reset();
	}
	if (!Mouse::isButtonPressed(Mouse::Button::Right))
	{
		if (filaPerso.getPrimeiro()->getEspecializando())
		{
			filaPerso.getPrimeiro()->desEspecial();
			if (filaPerso.getPrimeiro()->getTipoPersonagem() == 4)
			{
				relogioMagia.reset();
				magoMagiou = false;
			}
		}
	}
	//if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
	//{
	//	janela.close();
	//}
	if (Keyboard::isKeyPressed(Keyboard::Key::LShift) && !filaPerso.getPrimeiro()->getEspecializando())
	{
		correndo = true;
	}
	if (correndo)
	{
		filaPerso.getPrimeiro()->setCorrendo(true);
		correndo = false;
	}
	else
	{
		filaPerso.getPrimeiro()->setCorrendo(false);
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::W) && podeCima)
	{
		filaPerso.getPrimeiro()->andaCima();
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::S) && podeBaixo)
	{
		filaPerso.getPrimeiro()->andaBaixo();
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::A) && podeEsquerda)
	{
		filaPerso.getPrimeiro()->andaEsquerda();
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::D) && podeDireita)
	{
		filaPerso.getPrimeiro()->andaDireita();
	}
	if (filaPerso.getPrimeiro()->getAndando() && !andou)
	{
		andou = true;
		relogioDelayCaminhada.contaAte(0.3);
	}
	if (!filaPerso.getPrimeiro()->getAndando())
	{
		andou = false;
	}
	
	
}

void Jogo::coliseia()
{
	//COLISOES COM CIMA E BAIXO
	if (filaPerso.getPrimeiro()->getYbotas() <= 226)
	{
		podeCima = false;
	}
	else
	{
		podeCima = true;
	}
	if (filaPerso.getPrimeiro()->getYbotas() >= 494)
	{
		podeBaixo = false;
	}
	else
	{
		podeBaixo = true;
	}
	//COLISOES COM ESQUERDA E DIREITA
	if (filaPerso.getPrimeiro()->getXbotas() <= 0)
	{
		podeEsquerda = false;
	}
	else
	{
		podeEsquerda = true;
	}
	if (filaPerso.getPrimeiro()->getXbotas() >= 1208)
	{
		podeDireita = false;
	}
	else
	{
		podeDireita = true;
	}

	if (projeteis.size() > 0)
	{
		for (int u = 0; u < projeteis.size(); u++)
		{
			int xFlecha, yFlecha;
			xFlecha = projeteis[u]->getX() + 90;
			yFlecha = projeteis[u]->getY() + 25;
			for (int i = 0; i < 3; i++)
			{
				if (iniBeta[i].getXcolisao() - xFlecha <= ((iniBeta[i].desenhar().getAnimation()->getFrame(0).width / 2) - 50))
				{
					int difModulo;
					difModulo = iniBeta[i].getYcolisao() - yFlecha;
					if (difModulo < 0)
					{
						difModulo *= -1;
					}
					if (difModulo <= 60)
					{
						iniBeta[i].recebeDano(filaPerso.getPrimeiro()->getAtaque());
						cout << "cobra " << i << " recebeu dano!" << endl;
						projeteis[u]->setDeleteMeTrue();
					}
				}
			}
		}
	}

	if (filaPerso.getPrimeiro()->getXbotas() > 690)
	{
		/*if (filaPerso.getPrimeiro()->desenhar().getAnimation()->getFrame(0).intersects(iniBeta[0].desenhar().getAnimation()->getFrame(0)))
		{
			cout << "INTERSECTOU" << endl;
		}*/

		if (relogioAtaque.checaConta() && playerAtacando)
		{
			for (int i = 0; i < 3; i++)
			{
				if (filaPerso.getPrimeiro()->desenhar().getGlobalBounds().intersects(iniBeta[i].desenhar().getGlobalBounds()))
				{
					if (iniBeta[i].getXcolisao() - filaPerso.getPrimeiro()->getXatacando() <= (iniBeta[i].desenhar().getAnimation()->getFrame(0).width / 2))
					{
						iniBeta[i].recebeDano(filaPerso.getPrimeiro()->getAtaque());
						cout << "cobra " << i << " recebeu dano!" << endl;
						playerAtacando = false;
					}
				}
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (iniBeta[i].getAtacou())
			{
				if (filaPerso.getPrimeiro()->desenhar().getGlobalBounds().intersects(iniBeta[i].desenhar().getGlobalBounds()))
				{
					//if (filaPerso.getPrimeiro()->getYatacando() > (iniBeta[i].getYcolisao() - 55) && filaPerso.getPrimeiro()->getYatacando() < (iniBeta[i].getYcolisao() + 55))
					if (iniBeta[i].getYcolisao() - filaPerso.getPrimeiro()->getYmeio() <= 96 || filaPerso.getPrimeiro()->getYmeio() - iniBeta[i].getYcolisao() <= 96)
					{
						cout << "em y eles tao parelho" << endl;
						if (iniBeta[i].getXcolisao() - filaPerso.getPrimeiro()->getXmeio() <= 96 || filaPerso.getPrimeiro()->getXmeio() - iniBeta[i].getXcolisao() <= 96)
						{
							if (filaPerso.getPrimeiro()->getTipoPersonagem() == 1 && filaPerso.getPrimeiro()->getEspecializando())
							{

							}
							else
							{
								filaPerso.getPrimeiro()->recebeDano(iniBeta[i].getAtaque());
								cout << "cobra " << i << " deu dano no player xD" << endl;
							}
						}
					}
				}
				iniBeta[i].setAtacou(false);
			}
		}
		/*if (filaPerso.getPrimeiro()->desenhar().getGlobalBounds().intersects(iniBeta[1].desenhar().getGlobalBounds()))
		{
			cout << "INTERSECTOU" << endl;
			





		}
		else
		{
			cout << "NAO INTERSECTOU" << endl;
		}*/
	}

	if (filaPerso.getPrimeiro()->getXbotas() > 690)
	{
		for (int i = 0; i < 3; i++)
		{
			if (!iniBeta[i].getMorto())
			{
				if ((filaPerso.getPrimeiro()->getXmeio() + 25) >= (iniBeta[i].getXcolisao() - 63))
				{
					if ((filaPerso.getPrimeiro()->getYmeio()) <= (iniBeta[i].getYcolisao() + 56) && (filaPerso.getPrimeiro()->getYmeio()) >= (iniBeta[i].getYcolisao() - 56))
					{
						podeDireita = false;
						break;
					}
				}
				else
				{
					podeDireita = true;
				}
			}
		}
	}

	//if (relogioAtaque.checaConta() && playerAtacando)
	//{
	//	for (int i = 0; i < 3; i++)
	//	{
	//		if (iniBeta[i].getXcolisao() - filaPerso.getPrimeiro()->getXatacando() <= (iniBeta[i].desenhar().getAnimation()->getFrame(0).width / 2))
	//		{
	//			int difModulo;
	//			difModulo = iniBeta[i].getYcolisao() - filaPerso.getPrimeiro()->getYmeio();
	//			if (difModulo < 0)
	//			{
	//				difModulo *= -1;
	//			}
	//			if (difModulo <= ((iniBeta[i].getYcolisao() + filaPerso.getPrimeiro()->getYmeio()) / 2))
	//			{
	//				iniBeta[i].recebeDano(filaPerso.getPrimeiro()->getAtaque());
	//				cout << "cobra " << i << " recebeu dano!" << endl;
	//			}
	//		}
	//		/*if (filaPerso.getPrimeiro()->getXatacando() > (iniBeta[i].getXcolisao() - 60) && filaPerso.getPrimeiro()->getXatacando() < (iniBeta[i].getXcolisao() + 60))
	//		{
	//			if (filaPerso.getPrimeiro()->getYatacando() > (iniBeta[i].getYcolisao() - 55) && filaPerso.getPrimeiro()->getYatacando() < (iniBeta[i].getYcolisao() + 55))
	//			{
	//				iniBeta[i].recebeDano(filaPerso.getPrimeiro()->getAtaque());
	//				cout << "cobra " << i << " recebeu dano!" << endl;
	//			}
	//		}*/
	//	}
	//	playerAtacando = false;
	//}
	//for (int i = 0; i < 3; i++)
	//{
	//	if (iniBeta[i].getAtacou())
	//	{
	//		//if (filaPerso.getPrimeiro()->getYatacando() > (iniBeta[i].getYcolisao() - 55) && filaPerso.getPrimeiro()->getYatacando() < (iniBeta[i].getYcolisao() + 55))
	//		if (iniBeta[i].getYcolisao() - filaPerso.getPrimeiro()->getYmeio() <= 96 || filaPerso.getPrimeiro()->getYmeio() - iniBeta[i].getYcolisao() <= 96)
	//		{
	//			cout << "em y eles tao parelho" << endl;
	//			if (iniBeta[i].getXcolisao() - filaPerso.getPrimeiro()->getXmeio() <= 96 || filaPerso.getPrimeiro()->getXmeio() - iniBeta[i].getXcolisao() <= 96)
	//			{
	//				filaPerso.getPrimeiro()->recebeDano(iniBeta[i].getAtaque());
	//				cout << "cobra " << i << " deu dano no player xD" << endl;
	//			}
	//		}
	//		iniBeta[i].setAtacou(false);
	//	}
	//}
}

void Jogo::executar()
{
	Time frameTime = frameClock.restart();
	
	Event evento;
	while (janela.pollEvent(evento))
	{
		// Close window: exit
		maoManager(evento);
	}
	coliseia();
	checaCliques();
	
	

	/*if (reloginho.taRolando())
	{
		if (reloginho.checaConta())
		{
			cout << "rolou a contagem" << endl;
		}
	}*/

	janela.clear();

	janela.draw(sprBatalha);
	
	filaPerso.getPrimeiro()->atualizar();
	filaPerso.getPrimeiro()->proximo->atualizar();
	filaPerso.getUltimo()->atualizar();
	
	janela.draw(filaPerso.getUltimo()->desenhar());
	janela.draw(filaPerso.getPrimeiro()->proximo->desenhar());
	janela.draw(filaPerso.getPrimeiro()->desenhar());

	
	
	for (int i = 0; i < projeteis.size(); i++)
	{
		projeteis[i]->atualizar();
		if (projeteis[i]->getDeleteMe())
		{
			projeteis.erase(projeteis.begin() + i);
		}
		else
		{
			janela.draw(projeteis[i]->desenhar());
		}
	}

	
	moveAFK();
	
	
	for (int i = 0; i < 3; i++)
	{
		if (!iniBeta[i].getMorto())
		{
			iniBeta[i].atualizar();
			janela.draw(iniBeta[i].desenhar());
		}
	}

	janela.draw(sprUIbatalha);

	janela.display();
	
	
}

void Jogo::moveAFK()
{
	filaPerso.getPrimeiro()->proximo->movePara(filaPerso.getPrimeiro()->getXReal(), filaPerso.getPrimeiro()->getYReal());
	if (relogioDelayCaminhada.checaConta())
	{
		delayPassou = true;
	}
	if (delayPassou)
	{
		if (filaPerso.getUltimo()->movePara(filaPerso.getPrimeiro()->proximo->getXReal(), filaPerso.getPrimeiro()->proximo->getYReal()) == 0)
		{
			delayPassou = false;
		}
	}
}

void Jogo::trocaSegundo()
{
	Personagem *auxiliar;
	auxiliar = filaPerso.getPrimeiro();
	filaPerso.removeInicio();
	auxiliar->proximo = NULL;
	auxiliar->anterior = NULL;
	filaPerso.insereDepois(filaPerso.getPrimeiro(), auxiliar);
}

void Jogo::trocaTerceiro()
{
	Personagem *auxiliar;
	auxiliar = filaPerso.getPrimeiro();
	filaPerso.removeInicio();
	auxiliar->proximo = NULL;
	auxiliar->anterior = NULL;
	filaPerso.insereFim(auxiliar);
	auxiliar = filaPerso.getPrimeiro();
	filaPerso.removeInicio();
	auxiliar->proximo = NULL;
	auxiliar->anterior = NULL;
	filaPerso.insereDepois(filaPerso.getPrimeiro(), auxiliar);
}

void Jogo::interpretaMagia()
{
	Magia magiaAuxiliar = filaPerso.getPrimeiro()->getMagia();
	switch (magiaAuxiliar.tipoMagia)
	{
	case 0:

		break;
	case 1:

		break;
	case 2:

		break;
	}
}