#include "bibliotecas.h"
#include <time.h>
#define TF 50


// ---* TRABALHO DE ATP2 DO RAUL MAMACO E DUDA ORANGOS *--- teste


struct TpAlunos {
	
	char RA[10] , Nome[30]; // ---* CHAVE PRIMARIA RA
	
};

struct TpDisciplinas {
	
	char Disciplina[30]; // ---* CHAVE PRIMARIA CodDisc
	int CodDisc;
	
};

struct TpAlunosDisciplinas { // ---* tabela de muitos para muitos
	
	char RA[10];
	int CodDisc;  // ---* CHAVE ESTRANGEIRA RA e CodDisc;
	float Nota;
	
};


void Moldura (int CI, int LI, int CF, int LF) {	
	
	//gotoxy(col,lin);
	
	// --*Inicio Moldura
	
	int i;
	clrscr();
	textcolor(1);
	gotoxy(CI,LI);
	printf("%c", 201);
	gotoxy(CF,LI);
	printf("%c", 187);
	gotoxy(CI,LF);
	printf("%c", 200);
	gotoxy(CF,LF);
	printf("%c", 188);
	
	for(i = CI+1; i< CF; i++) {
		
		gotoxy(i,LI);
		printf("%c", 205);
		gotoxy(i,LF);
		printf("%c", 205);
		
	}
	
	for(i = LI+1; i< LF; i++) {
		
		gotoxy(CI,i);
		printf("%c", 186);
		gotoxy(CF,i);
		printf("%c", 186);
		
	}
	
	// --*Fim Moldura
	
	// --* Inicio Menu
	
	textcolor(15);
	gotoxy(2,2);  
	printf("%c", 201);	
	gotoxy(34,2);
	printf("%c", 187);
	gotoxy(2,24);
	printf("%c", 200);
	gotoxy(34,24);
	printf("%c", 188);
	
	for(i = 3; i < 34; i++) {
		
		gotoxy(i,2);
		printf("%c", 205);
		gotoxy(i,24);
		printf("%c", 205);
		
	}
	
	for(i = 3; i < 24; i++) {
		
		gotoxy(2,i);
		printf("%c", 186);
		gotoxy(34,i);
		printf("%c", 186);
		
	}
	
	gotoxy(13,2);
	printf("%c%c%c MENU %c%c%c", 175,175,175,174,174,174);
	
//	for(i = 4; i < 25; i++) {
//		
//		gotoxy(i,4);
//		printf("%c", 205);
//		
//	}
	
	// --* Fim do Menu
	
	// --* Inicio do Layout
	textcolor(14);
	gotoxy(35,2);
	printf("%c", 201);
	gotoxy(84,2);
	printf("%c", 187);
	gotoxy(35,4);
	printf("%c", 200);
	gotoxy(84,4);
	printf("%c", 188);
	
	for(i = 36; i < 84; i++) {
		
		gotoxy(i, 2);
		printf("%c", 205);
		gotoxy(i, 4);
		printf("%c", 205);
		
	}
	
	for(i = 3; i < 4; i++) { 
	
		gotoxy(35,i);
		printf("%c", 186);
		gotoxy(84,i);
		printf("%c", 186);
		
	}
	
	gotoxy(50,3);
	textcolor(15);
	printf("%c Sistema Escolar %c", 175, 174);
	
	// --* Fim do Layout
	
	// --* Inicio dos Dados
	
	textcolor(15);
	gotoxy(35,5);
	printf("%c", 201);
	gotoxy(84,5);
	printf("%c", 187);
	gotoxy(35,24);
	printf("%c", 200);
	gotoxy(84,24);
	printf("%c", 188);
	
	for(i = 36; i < 84; i++) {
		
		gotoxy(i,5);
		printf("%c", 205);
		gotoxy(i,24);
		printf("%c", 205);
		
	}
	
	for(i = 6; i < 24; i++ ) {
		
		gotoxy(35,i);
		printf("%c", 186);
		gotoxy(84,i);
		printf("%c", 186);
		
	}
	
	for( i = 36; i < 84; i++) {
		
		textcolor(14);
		gotoxy(i,22);
		printf("%c", 205);
		
	}
	
	// --* Fim dos Dados
		
		
}

void ClearScreen (void) {
	
	int i; 
	for(i = 6; i < 22; i++) {
		
		gotoxy(36,i);
		printf("                                                ");
		
	}
	
	
}

int BuscaAlunos (TpAlunos TabAlunos[TF], int TLA, char RAaluno[10]) {
	
	int i = 0;
	
	while(i < TLA && stricmp(RAaluno, TabAlunos[i].RA) != 0)
		i++;
	
	if(i<TLA)
		return i;
	else
		return -1;
	
}


void CadAlunos (TpAlunos TabAlunos[TF], int &TLA) {
	
	char RaAux[10];
	int posA;
	
	ClearScreen();
	textcolor(15);
	gotoxy(48,6);
	printf(" %c%c%c CADASTRO ALUNO %c%c%c ",175,175,175,174,174,174);
	gotoxy(37,8);
	printf("Informe o RA do aluno:\n");
	fflush(stdin);
	gotoxy(37,9);
	gets(RaAux);
	
	
	while(TLA < TF && strcmp(RaAux,"\0") !=0 ) {
		
		posA = BuscaAlunos(TabAlunos, TLA, RaAux);
		
		if(posA == -1) {
			
			strcpy(TabAlunos[TLA].RA, RaAux);
			gotoxy(37,11);
			printf("Informe o nome do aluno:");
			fflush(stdin);
			gotoxy(37,12);
			gets(TabAlunos[TLA].Nome);
			TLA++;
			gotoxy(37,23);
			printf(" %c Cadastro concluido!", 175);
			Sleep(1000);
			gotoxy(37,23);
			printf("                           ");
		}
		
		else {
			
			gotoxy(37,23);
			printf(" %c Aluno ja cadastrado!", 175);
			Sleep(1000);
			gotoxy(37,23);
			printf("                           ");
				
		}
		
		
		ClearScreen();
		textcolor(15);
		gotoxy(48,6);
		printf(" %c%c%c CADASTRO ALUNO %c%c%c ",175,175,175,174,174,174);
		gotoxy(37,8);
		printf("Informe o RA do aluno:\n");
		gotoxy(37,9);
		gets(RaAux);
			
	}	
		
}



int BuscaDisciplina(TpDisciplinas TabDisciplina[TF], int TLD, int CodAuxD) {
	
	int i = 0;
	
	while(i < TLD && CodAuxD != TabDisciplina[i].CodDisc)
		i++;
	
	if(i<TLD)
		return i;
	else
		return -1;
		
}


void CadDisciplina (TpDisciplinas TabDisciplina[TF], int &TLD) {
	
	int CodAux, posD;
	
	ClearScreen();
	textcolor(15);
	gotoxy(48,6);
	printf(" %c%c%c CADASTRO DISCIPLINA %c%c%c ",175,175,175,174,174,174);
	gotoxy(36,8);
	printf("Insira o codigo da disciplina [0 para sair]:");
	scanf("%d", &CodAux);
	
	while(TLD < TF && CodAux != 0 ) {
		
		posD = BuscaDisciplina(TabDisciplina, TLD, CodAux);
		
		if(posD == -1) {
			
			TabDisciplina[TLD].CodDisc = CodAux;
			gotoxy(36,10);
			printf("Informe o nome da disciplina: ");
			fflush(stdin);
			gets(TabDisciplina[TLD].Disciplina);
			TLD++;
			gotoxy(37,23);
			printf(" %c Cadastro concluido!", 175);
			Sleep(1000);
			gotoxy(37,23);
			printf("                           ");
			
		}
		else {
			
			gotoxy(37,23);
			printf(" %c Disciplina ja cadastrada!", 175);
			Sleep(1000);
			gotoxy(37,23);
			printf("                           ");
			
			
		}
		
		ClearScreen();
		textcolor(15);
		gotoxy(48,6);
		printf(" %c%c%c CADASTRO DISCIPLINA %c%c%c ",175,175,175,174,174,174);
		gotoxy(36,8);
		printf("Insira o codigo da disciplina [0 para sair]:");
		scanf("%d", &CodAux);
			
	}
	
}	
	


void RelacionarAlunoDisc (TpAlunosDisciplinas TabAlunosDisciplinas[TF], int TLN, int &TLA, TpAlunos TabAlunos[TF], int &TLD, TpDisciplinas TabDisciplinas[TF]) {
	
	char RaAux[13], op;
	int CodDiscAux, posA=0, posD=0;
	float NotaAux = 0;
	
		
	ClearScreen();
	textcolor(15);
	gotoxy(48,6);
	printf(" %c%c%c CADASTRO DE MATERIAS %c%c%c ",175,175,175,174,174,174);
	gotoxy(36,8);
	printf("Insira o RA do aluno :");
	fflush(stdin);
	gets(RaAux);
		
			
		while(TLN<TF && stricmp(RaAux, "\0") != 0) {
			
			posA = BuscaAlunos(TabAlunos, TLA, RaAux);
				
			if(posA == -1) {
					
				gotoxy(37,23);
				printf("Aluno nao encontrado!");
				Sleep(1000);
				gotoxy(37,23);
				printf("                           ");
				
			}
			else {
				
				gotoxy(37,23);
				printf("Aluno encontrado!");
				Sleep(1000);
				gotoxy(37,23);
				printf("                           ");
				
			}	
			
			gotoxy(36,10);
			printf("Informe o codigo da disciplina: ");
			scanf("%d",&CodDiscAux);						
			
			while(CodDiscAux != 0) {
					
					posD = BuscaDisciplina(TabDisciplinas, TLD, CodDiscAux);
				
					if(posD == -1) {
						
						CodDiscAux = 0;
						gotoxy(37,23);
						printf("Disciplina nao encontrada!");
						Sleep(1000);
						gotoxy(37,23);
						printf("                           ");
						
					}
					else {
				
						gotoxy(37,23);
						printf("Disciplina encontrada!");
						Sleep(1000);
						gotoxy(37,23);
						printf("                           ");
						
						gotoxy(36,15);
						printf("%s \t\t %d",TabAlunos[posA].RA, TabDisciplinas[posD].CodDisc);
						
						gotoxy(36,16);
						printf("Deseja cadastrar uma nota[S/N]");
						fflush(stdin);
						scanf(" %c", &op);
						fflush(stdin);
						op = toupper(op);
						
						if(op == 'S') {
							
							ClearScreen();
							textcolor(15);
							gotoxy(48,6);
							printf(" %c%c%c CADASTRO DE MATERIAS %c%c%c ",175,175,175,174,174,174);
							gotoxy(36,8);
							printf("[RA]\t[ALUNO]\t[CODIGO]\t[DISCIPLINA]");
							gotoxy(36,9);
							printf("%s\t%s\t\t%d\t%s ",TabAlunos[posA].RA, TabAlunos[posA].Nome, TabDisciplinas[posD].CodDisc, TabDisciplinas[posD].Disciplina);
							gotoxy(36,10);
							printf("Insira a nota:");
							gotoxy(36,11);
							scanf("%f",&NotaAux);
							
							strcpy(TabAlunosDisciplinas[TLN].RA, RaAux);
							TabAlunosDisciplinas[TLN].CodDisc = CodDiscAux;
							TabAlunosDisciplinas[TLN].Nota = NotaAux;
							TLN++;
						
						}else if(op!='S') {
								
								gotoxy(37,23);
								printf("Operação Cancelada!");
								Sleep(1000);
								gotoxy(37,23);
								printf("                           ");
										
						}
					}
					
					gotoxy(36,10);
					printf("Informe o codigo da disciplina: ");
					scanf("%d",&CodDiscAux);
					
				}			
			
		ClearScreen();
		textcolor(15);
		gotoxy(48,6);
		printf(" %c%c%c CADASTRO DE MATERIAS %c%c%c ",175,175,175,174,174,174);
		gotoxy(36,8);
		printf("Insira o RA do aluno :");
		fflush(stdin);
		gets(RaAux);
			
		}

}
	 


char Menu (void) {
	
	textcolor(1);
	char op;
	
	gotoxy(4,4);
	printf("[A] CADASTRO ALUNO");
	gotoxy(4,5);
	printf("[B] CADASTRO DISCIPLINA");
	gotoxy(4,6);
	printf("[C] CADASTRAR NOTA");
	gotoxy(4,7);
	printf("[ESC] - Sair");
	gotoxy(4,9);
	printf("Opcao: ");
	fflush(stdin);
	
	return toupper(getch());
	
	
}

void Executar (void) {
	
	Moldura(1,1,85,25);
//	srand(time(NULL));
	int TLAlunos = 0, TLDisciplina = 0, TLNotas = 0;
	char op;
	
	TpAlunos TabAlunos[TF];
	TpDisciplinas TabDisciplina[TF];
	TpAlunosDisciplinas TabAlunosDisciplinas[TF];
	
	do {
		
		ClearScreen();
		op =  Menu();
		
		gotoxy(4,9);
		switch(op) {
			
			case 'A': 
					CadAlunos(TabAlunos, TLAlunos);
					break;
			
			case 'B': 
					CadDisciplina(TabDisciplina, TLDisciplina);
					break;
			
			case 'C': RelacionarAlunoDisc(TabAlunosDisciplinas, TLNotas, TLAlunos, TabAlunos, TLDisciplina, TabDisciplina);
					break;
			
		}
		
	}while (op != 27);
	
	gotoxy(78,22);
	printf("\n\n");

}



int main (void) {
	
	
	Executar();
	
	return 0;
	
}


