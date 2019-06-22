#include <iostream>
#include <string>
#include "Personagem.h"
using namespace std;

struct Nodo
{
	Personagem valor;
	Nodo *proximo;
	Nodo *anterior;
};

class ListaPersonagens
{
public:
	ListaPersonagens();
	ListaPersonagens(Personagem *novo);
	~ListaPersonagens() {};
	void insereInicio(Personagem *novo);
	void insereFim(Personagem *novo);
	void insereAntes(Personagem *ref, Personagem *novo);
	void insereDepois(Personagem *ref, Personagem *novo);
	bool removeInicio();
	void removeFim();
	void removePersonagem(Personagem *n);
	void imprime();
	bool existeRef(Personagem *ref);
	Personagem *getPrimeiro();
	Personagem *getUltimo();
protected:
	Personagem *primeiro;
	Personagem *ultimo;
	int tamanho;
private:
	void imprime(Personagem *atual);

};