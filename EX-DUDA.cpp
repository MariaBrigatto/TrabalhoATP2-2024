#include "bibliotecas.h"
#define TF 50


// ---* TRABALHO DE ATP2 DO RAUL MAMACO E DUDA ORANGOS *--- teste



struct TpAlunos {
	
	char RA[10] , Nome[30]; // ---* CHAVE PRIMARIA RA
	
};

struct TpDisciplinas {
	
	char CodDisc[10], Disciplina[30]; // ---* CHAVE PRIMARIA CodDisc
	
};

struct TpAlunosDisciplinas { // ---* tabela de muitos para muitos
	
	char RA[10], CodDisc[10]; // ---* CHAVE PRIMARIA RA e CodDisc;
	float Nota;
	
};


