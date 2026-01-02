#include<iostream>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include <time.h>

#define LARGURA_TELA 90
#define ALTURA_TELA 26
#define LARGURA_JANELA 70
#define LARGURA_MENU 20
#define TAMANHO_ABERTURA 7
#define DIFERENCA_CANO 45

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD PosicaoCursor;

int posicaoCano[3];
int posicaoAbertura[3];
int canoAtivo[3];
char passaro[2][6] = { '/','-','-','o','\\',' ',
					   '|','_','_','_',' ','>' };
int posicaoPassaro = 6;
int pontuacao = 0;

void irPara(int x, int y)
{
	PosicaoCursor.X = x;
	PosicaoCursor.Y = y;
	SetConsoleCursorPosition(console, PosicaoCursor);
}

void configurarCursor(bool visivel, DWORD tamanho)
{
	if(tamanho == 0)
		tamanho = 20;

	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visivel;
	lpCursor.dwSize = tamanho;
	SetConsoleCursorInfo(console,&lpCursor);
}

void desenharBorda(){

	for(int i=0; i<LARGURA_TELA; i++){
		irPara(i,0); cout<<"\xB1";
		irPara(i,ALTURA_TELA); cout<<"\xB1";
	}

	for(int i=0; i<ALTURA_TELA; i++){
		irPara(0,i); cout<<"\xB1";
		irPara(LARGURA_TELA,i); cout<<"\xB1";
	}
	for(int i=0; i<ALTURA_TELA; i++){
		irPara(LARGURA_JANELA,i); cout<<"\xB1";
	}
}

void gerarCano(int indice){
	posicaoAbertura[indice] = 3 + rand()%14;
}

void desenharCano(int indice){
	if( canoAtivo[indice] == true ){
		for(int i=0; i<posicaoAbertura[indice]; i++){
			irPara(LARGURA_JANELA-posicaoCano[indice],i+1); cout<<"***";
		}
		for(int i=posicaoAbertura[indice]+TAMANHO_ABERTURA; i<ALTURA_TELA-1; i++){
			irPara(LARGURA_JANELA-posicaoCano[indice],i+1); cout<<"***";
		}
	}
}

void apagarCano(int indice){
	if( canoAtivo[indice] == true ){
		for(int i=0; i<posicaoAbertura[indice]; i++){
			irPara(LARGURA_JANELA-posicaoCano[indice],i+1); cout<<"   ";
		}
		for(int i=posicaoAbertura[indice]+TAMANHO_ABERTURA; i<ALTURA_TELA-1; i++){
			irPara(LARGURA_JANELA-posicaoCano[indice],i+1); cout<<"   ";
		}
	}
}

void desenharPassaro(){
	for(int i=0; i<2; i++){
		for(int j=0; j<6; j++){
			irPara(j+2,i+posicaoPassaro); cout<<passaro[i][j];
		}
	}
}

void apagarPassaro(){
	for(int i=0; i<2; i++){
		for(int j=0; j<6; j++){
			irPara(j+2,i+posicaoPassaro); cout<<" ";
		}
	}
}

int colisao(){
	if( posicaoCano[0] >= 61  ){
		if( posicaoPassaro<posicaoAbertura[0] || posicaoPassaro >posicaoAbertura[0]+TAMANHO_ABERTURA ){
			return 1;
		}
	}
	return 0;
}

void depurar(){
	// irPara(LARGURA_TELA + 3, 4); cout<<"Pos Cano: "<<posicaoCano[0];
}

void fimDeJogo(){
	system("cls");
	cout<<endl;
	cout<<"\t\t--------------------------"<<endl;
	cout<<"\t\t------- Fim de Jogo ------"<<endl;
	cout<<"\t\t--------------------------"<<endl<<endl;
	cout<<"\t\tPressione qualquer tecla para voltar ao menu.";
	getch();
}

void atualizarPontuacao(){
	irPara(LARGURA_JANELA + 7, 5);cout<<"Pontuacao: "<<pontuacao<<endl;
}

void instrucoes(){

	system("cls");
	cout<<"Instrucoes";
	cout<<"\n----------------";
	cout<<"\n Pressione espaco para fazer o passaro voar";
	cout<<"\n\nPressione qualquer tecla para voltar ao menu";
	getch();
}

void jogar(){

	posicaoPassaro = 6;
	pontuacao = 0;
	canoAtivo[0] = 1;
	canoAtivo[1] = 0;
	posicaoCano[0] = posicaoCano[1] = 4;

	system("cls");
	desenharBorda();
	gerarCano(0);
	atualizarPontuacao();

	irPara(LARGURA_JANELA + 5, 2);cout<<"PASSARO VOADOR";
	irPara(LARGURA_JANELA + 6, 4);cout<<"--------------";
	irPara(LARGURA_JANELA + 6, 6);cout<<"--------------";
	irPara(LARGURA_JANELA + 7, 12);cout<<"Controle ";
	irPara(LARGURA_JANELA + 7, 13);cout<<"-------- ";
	irPara(LARGURA_JANELA + 2, 14);cout<<" Espaco = pular";

	irPara(10, 5);cout<<"Pressione qualquer tecla para iniciar";
	getch();
	irPara(10, 5);cout<<"                                      ";

	while(1){

		if(kbhit()){
			char tecla = getch();
			if(tecla==32){
				if( posicaoPassaro > 3 )
					posicaoPassaro-=3;
			}
			if(tecla==27){
				break;
			}
		}

		desenharPassaro();
		desenharCano(0);
		desenharCano(1);
		depurar();
		if( colisao() == 1 ){
			fimDeJogo();
			return;
		}
		Sleep(100);
		apagarPassaro();
		apagarCano(0);
		apagarCano(1);
		posicaoPassaro += 1;

		if( posicaoPassaro > ALTURA_TELA - 2 ){
			fimDeJogo();
			return;
		}

		if( canoAtivo[0] == 1 )
			posicaoCano[0] += 2;

		if( canoAtivo[1] == 1 )
			posicaoCano[1] += 2;

		if( posicaoCano[0] >= 40 && posicaoCano[0] < 42 ){
			canoAtivo[1] = 1;
			posicaoCano[1] = 4;
			gerarCano(1);
		}
		if( posicaoCano[0] > 68 ){
			pontuacao++;
			atualizarPontuacao();
			canoAtivo[1] = 0;
			posicaoCano[0] = posicaoCano[1];
			posicaoAbertura[0] = posicaoAbertura[1];
		}

	}

}

int main()
{
	configurarCursor(0,0);
	srand( (unsigned)time(NULL));

	do{
		system("cls");
		irPara(10,5); cout<<" -------------------------- ";
		irPara(10,6); cout<<" |    Passaro Fogo        | ";
		irPara(10,7); cout<<" --------------------------";
		irPara(10,9); cout<<"1. Iniciar Jogo";
		irPara(10,10); cout<<"2. Instrucoes";
		irPara(10,11); cout<<"3. Sair";
		irPara(10,13); cout<<"Selecione uma opcao: ";
		char opcao = getche();

		if( opcao=='1') jogar();
		else if( opcao=='2') instrucoes();
		else if( opcao=='3') exit(0);

	}while(1);

	return 0;
}