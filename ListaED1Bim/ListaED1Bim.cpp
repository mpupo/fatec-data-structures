// ListaED1Bim.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "pilha.h"
#include "fila.h"

#define EX09
#ifdef EX06

	//6.	Utilizando as implementações de uma estrutura de dados pilha, elabore um programa que converta um número decimal em número binário.

int main()
{

	Stack<int> p = Stack<int>(10000);
	int num = 0;
	int resto = 0;

	std::cout << "Digite um numero decimal que deseja converter para binario: " << std::endl;
	std::cin >> num;
	while (num > 0) {
		resto = num % 2;
		num = num / 2;
		p.push(resto);
	}

	std::cout << "O numero em binario eh: ";
	p.showElements();


	return 0;
}
#endif // EX06


#ifdef EX07
/*7.	Considerando uma pilha e uma fila, de números inteiros, construa uma aplicação que transfere todos os elementos da pilha para a fila.
*/

Queue<int> convertFromPilhaToFila(Stack<int> *pilha) {
	Queue<int>fila = Queue<int>(pilha->size);
	while (!pilha->is_empty()) {
		fila.insert(pilha->pop());
	}

	return fila;
}

int main()
{
	std::string opcao = "";

	do {
		int num;
		int numCont = 5;
		system("cls");

		Stack<int> p = Stack<int>(5);

		std::cout << "Pilha para Fila." << std::endl;

		while (numCont != 0) {
			std::cout << "Digite um numero para enfileirar (restantes: " << numCont << "): ";
			std::cin >> num;
			std::cin.clear();
			std::cin.ignore();
			p.push(num);
			numCont--;
		}

		Queue<int> f = convertFromPilhaToFila(&p);

		f.showElements();
		std::cout << std::endl;
		std::cout << "Deseja continuar (S/N)? : ";
		std::cin.clear();
		std::getline(std::cin, opcao);
	} while (opcao == "S" or opcao == "s");

	return 0;
}


#endif // EX07

#ifdef EX08
/*8.	Considerando uma pilha e uma fila, de números inteiros, construa uma aplicação que transfere todos os elementos da fila para a pilha*/

Stack<int> convertFromFilaToPilha(Queue<int> *fila) {
	Stack<int> pilha = Stack<int>(fila->size);
	while (!fila->isEmpty()) {
		pilha.push(fila->remove());
	}

	return pilha;
}

int main()
{
	std::string opcao = "";

	do {
		int num;
		int numCont = 0;
		system("cls");

		Queue<int> f = Queue<int>(5);

		std::cout << "Fila para Pilha." << std::endl;

			while (numCont != 5) {
				std::cout << "Digite um numero para empilhar (Limite: 5. Contador: " << numCont << "): ";
				std::cin >> num;
				std::cin.clear();
				std::cin.ignore();
				f.insert(num);
				numCont++;
			}

		Stack<int> p = convertFromFilaToPilha(&f);

		p.showElements();
		std::cout << std::endl;
		std::cout << "Deseja continuar (S/N)? : ";
		std::cin.clear();
		std::getline(std::cin, opcao);
	} while (opcao == "S" or opcao == "s");

	return 0;
}


#endif // EX08

#ifdef EX09
/*9.	Considerando uma pilha e uma fila, de números inteiros, inicialmente vazia, construa uma aplicação que:
•	preenche a fila com números aleatórios compreendidos entre 20 e 30, inclusive.
•	Transfere os elementos da fila para pilha de forma que os elementos fiquem ordenados de forma crescente sem a utilização do recurso de sort() implementado na linguagem Python.
•	Mostre os elementos da pilha.
*/

void sortFilaInAscendingOrder(Queue<int> &fila) {
	std::vector<int> tempVector;

	// Insere os valores da fila no vetor:
	for (int i = 0; i < fila.size; i++) {
		tempVector.push_back(fila.firstElement());
		fila.remove();
	}

	// Realiza o Selection Sort para ordernar:
	int min, temp;
	for (int i = 0; i < tempVector.size() - 1; i++) {
		min = i;
		for (int j = i + 1; j < tempVector.size(); j++) {
			if (tempVector[j] < tempVector[min]) {
				min = j;
			}
		}
		temp = tempVector[i];
		tempVector[i] = tempVector[min];
		tempVector[min] = temp;
	}

	// Insere novamente na fila:
	for (int i = 0; i < tempVector.size(); i++) {
		fila.insert(tempVector.at(i));
	}
}

Stack<int> convertFromFilaToPilha(Queue<int> &fila) {
	Stack<int> pilha = Stack<int>(fila.size);

	sortFilaInAscendingOrder(fila);

	while (!fila.isEmpty()) {
		pilha.push(fila.firstElement());
		fila.remove();
	}

	return pilha;
}

int main()
{
	std::string opcao = "";
	std::vector<int> escolhasPossiveis { 20,21,22,23,24,25,26,27,28,29,30 };

	do {
		system("cls");

		Queue<int> f = Queue<int>(escolhasPossiveis.size());

		std::cout << "Fila para Pilha." << std::endl;

		for (int i = 0; i < escolhasPossiveis.size(); i++) {
			// Gerar um numero aleatorio entre o tamanho das escolhas e 1:
			int posAleatoria = rand() % escolhasPossiveis.size();
			int numAleatorio = escolhasPossiveis.at(posAleatoria);
			f.insert(numAleatorio);
			std::cout << "Escolhendo aleatoriamente o numero " << i + 1 << ". ";
			std::cout << "Escolhido: " << numAleatorio << "." << std::endl;
		}

		Stack<int> p = convertFromFilaToPilha(f);

		p.showElements();
		std::cout << std::endl;
		std::cout << "Deseja rodar novamente? (S/N) : ";
		std::cin.clear();
		std::getline(std::cin, opcao);
	} while (opcao == "S" or opcao == "s");

	return 0;
}


#endif // EX09


#ifdef EX10
/*
10.	Um pangrama é uma frase que contém pelo menos uma vez cada uma das 26 letras do novo alfabeto Português.Um exemplo de pangrama é : “um pequeno jabuti xereta chamado kya viu dez cegonhas felizes e gritou iwup, iwup!”
Construa uma aplicação que recebe uma frase e verifica se ela é pangrama(utilize os conceitos de listas e strings da linguagem Python).
Frases para teste :
•	jackdawf loves my big quartz sphinx
•	abcdefghijklmnopqrstuvwxyz
•	the quick brown fox jumps over a lazy dog
•	jackdaws loves my big sphinx of quartz
•	hello world
•	esta frase es muy larga y contiene todas las letras  abc def ghij klmnopqr stu vw x y zzzzz
•	supercalifragilistico espialidoso
•	alfa beta gamma delta epsilon iotta kappa lambda
*/

const std::string alfabeto = "abcdefghijklmnopqrstuvwxyz";

bool pangrama(std::string frase) {

	for (int i = 0; i < alfabeto.length(); i++) {
		bool temLetra = false;
		for (int j = 0; j < frase.length(); j++) {
			if (alfabeto[i] == frase[j])
				temLetra = true;
		}

		if (!temLetra) {
			return false;
		}
	}

	return true;
}

int main()
{
	std::string opcao = "";
	std::string frase = "";
	while (opcao != "N" || opcao != "n") {
		frase = "";
		system("cls");

		std::cout << "Digite uma frase para verificar se e pangrama: ";
		std::cin >> frase;

		if (pangrama(frase)) {
			std::cout << std::endl << "A frase eh um Pangrama!" << std::endl;
		}

		else {
			std::cout << std::endl << "A frase nao eh um Pangrama!" << std::endl;
		}

		std::cout << "Deseja continuar (S/N)? ";
		std::cin >> opcao;
	}

	return 0;
}

#endif //
