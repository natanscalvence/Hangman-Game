#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

std::string retornaPalavraAleatoria()
{
	std::string palavras[10] = {"Melancia", "Melão", "Carvalho", "Carvão", "Ouro", "Quadro-Negro", "Entulho", "Elon Musk", "Linux", "Radiação"};
	int indice = rand() % 10;
	//std::cout << palavras[indice] << '\n';

	return palavras[indice];
}

std::string retornaPalavraComMascara( std::string palavras, int tamanhoDaPalavra )
{
	int cont = 0;
	std::string palavraComMascara;

	while( cont < tamanhoDaPalavra )
	{
		palavraComMascara += "_";
		cont++;
	}

	return palavraComMascara;
}

void exibeStatus( std::string palavraComMascara, int tamanhoDaPalavra, int tentativasRestantes, std::string letrasArriscadas, std::string mensagem )
{
	std::cout << mensagem << '\n';
	std::cout << "Palavra: " << palavraComMascara << "\nTamanho > " << tamanhoDaPalavra << '\n';
	std::cout << "Tentativas: " << tentativasRestantes << '\n';

	std::cout << "Letras arriscadas: ";
	for( int cont = 0; cont < letrasArriscadas.size(); cont++ )
	{
		std::cout << letrasArriscadas[cont] << ", ";
	}
}

void jogaSozinho()
{
	std::string palavras = retornaPalavraAleatoria();
	int tamanhoDaPalavra = palavras.size();
	int tentativas = 0, maximoDeTentativas = 13;
	std::string palavraComMascara = retornaPalavraComMascara( palavras, tamanhoDaPalavra );
	char letra;
	std::string letrasArriscadas;
	std::string mensagem;
	bool mesmoDigito = false;


	while(palavras != palavraComMascara && maximoDeTentativas - tentativas > 0)
	{
		system("clear");
		exibeStatus( palavraComMascara, tamanhoDaPalavra, maximoDeTentativas - tentativas, letrasArriscadas, mensagem );
		std::cout << "\nDigite uma letra: ";
		std::cin >> letra;

		for( int cont = 0; cont < tentativas; cont++ )
		{
			if( letrasArriscadas[cont] == letra )
			{
				mensagem = "Essa letra já foi digitada, tente novamente!";
				mesmoDigito = true;
			}
		}

		if( mesmoDigito == false )
		{
			letrasArriscadas += letra;
			for( int cont = 0; cont < tamanhoDaPalavra; cont++)
			{
				if( palavras[cont] == letra)
				{
					palavraComMascara[cont] = palavras[cont];
				}

			}

			tentativas++;
		}

	}


	if( palavras == palavraComMascara )
	{
		std::cout << "\n\e[32;5mParabéns, você venceu!" << "\e[m\n";
	} else {
		std::cout << "\e[31;1mSuas tentativas acabaram, tente novamente." << "\e[m\n";
	}

}


void menuInicial()
{

	int option = 0;

	while( option < 1 || option > 4 ){

	std::cout << "\n\r\t\e[32;1mSeja Bem-Vindo ao Jogo!" << "\e[m\n";
	std::cout << "\n1 - Jogar" << '\n';
	std::cout << "2 - Sobre" << '\n';
	std::cout << "3 - Criador" << '\n';
	std::cout << "4 - Sair" << '\n';
	std::cout << "\e[32;5m>> " << "\e[m";
	std::cin >> option;

	switch( option )
	{
		case 1:
		system("clear");
		std::cout << "\n\e[32;1mJogo iniciado!" << "\e[m\n";
		jogaSozinho();
		break;

		case 2:
		break;

		case 3:
		break;

		case 4:
		system("clear");
		std::cout << "\e[36;1mVocê saiu, até mais." << '\n';
		exit(0);
		break;

		default:
		system("clear");
		std::cout << "\e[31;1mOops... Algo deu errado, tente novamente!" << '\n';
		}

	}

} 




int main( int argc, char **argv )
{
	srand((unsigned)time(NULL));
	menuInicial(); 

	return 0;
}
