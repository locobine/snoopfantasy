#include "ListaPersonagens.h"

ListaPersonagens::ListaPersonagens()
{
	tamanho = 0;
	primeiro = NULL;
	ultimo = NULL;
}

ListaPersonagens::ListaPersonagens(Personagem *novo)
{
	primeiro = novo;
	ultimo = novo;

	primeiro->anterior = NULL;
	ultimo->proximo = NULL;
	tamanho = 1;
}

void ListaPersonagens::insereInicio(Personagem *novo)
{
	if (tamanho == 0)
	{
		primeiro = novo;
		ultimo = novo;

		novo->anterior = NULL;
		novo->proximo = NULL;
	}

	else
	{
		novo->proximo = primeiro;
		novo->anterior = NULL;

		primeiro->anterior = novo;
		primeiro = novo;

	}

	tamanho++;
}
void ListaPersonagens::insereFim(Personagem *novo)
{
	if (tamanho == 0)
	{
		ultimo = novo;
		primeiro = novo;

		ultimo->proximo = NULL;
		ultimo->anterior = NULL;
	}
	else
	{
		novo->anterior = ultimo;
		novo->proximo = NULL;

		ultimo->proximo = novo;
		ultimo = novo;
	}
	tamanho++;
}

bool ListaPersonagens::removeInicio()
{
	if (tamanho > 1)
	{
		primeiro = primeiro->proximo;
		primeiro->anterior = NULL;
		tamanho--;
		return true;
	}
	else if (tamanho == 1)
	{
		tamanho = 0;
		primeiro = NULL;
		ultimo = NULL;
		return true;
	}
	else
		return false;
}
void ListaPersonagens::insereAntes(Personagem *ref, Personagem *novo)
{
	if (ref == primeiro)
	{
		insereInicio(novo);
	}
	else
	{
		novo->proximo = ref;
		novo->anterior = ref->anterior;
		ref->anterior->proximo = novo;
		ref->anterior = novo;
		tamanho++;
	}


}
void ListaPersonagens::insereDepois(Personagem *ref, Personagem *novo)
{
	if (ref == ultimo)
	{
		insereFim(novo);
	}
	else
	{
		novo->anterior = ref;
		novo->proximo = ref->proximo;

		ref->proximo->anterior = novo;
		ref->proximo = novo;
		tamanho++;
	}
}
void ListaPersonagens::removeFim() {
	if (tamanho > 1)
	{
		ultimo = ultimo->anterior;
		ultimo->proximo = NULL;
		tamanho--;
	}
	else if (tamanho == 1) {
		primeiro = NULL;
		ultimo = NULL;
		tamanho = 0;
	}
	else
		cout << "Lista vazia. Impossivel deletar\n" << endl;
}

void ListaPersonagens::removePersonagem(Personagem *n)
{
	if (n == primeiro)
	{
		removeInicio();
	}
	else if (n == ultimo)
	{
		removeFim();
	}
	else
	{
		n->anterior->proximo = n->proximo;
		n->proximo->anterior = n->anterior;
		n->anterior = NULL;
		n->proximo = NULL;
		tamanho--;
	}
}

void ListaPersonagens::imprime(Personagem *atual)
{
	cout << atual << endl;
	if (atual->proximo)
		imprime(atual->proximo);
}
Personagem* ListaPersonagens::getPrimeiro()
{
	return primeiro;
}

Personagem* ListaPersonagens::getUltimo()
{
	return ultimo;
}

void ListaPersonagens::imprime()
{
	imprime(primeiro);
}

bool ListaPersonagens::existeRef(Personagem *ref)
{
	Personagem *rf = primeiro;
	bool existe = false;

	do
	{
		if (rf == ref)
		{
			existe = true;
			return existe;
		}

		else if (rf->proximo)
		{
			rf = rf->proximo;
		}

		else
		{
			return false;
		}
	} while (!(existe));

}
