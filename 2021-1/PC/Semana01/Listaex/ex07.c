/*A turma C é composta de 60 alunos, e a turma D de 20 alunos. Escreva um programa que
leia o percentual de alunos reprovados na turma C, o percentual de aprovados na turma D,
calcule e escreva: a) O número de alunos reprovados na turma C. b) O número de alunos
reprovados na turma D. c) A percentagem de alunos reprovados em relação ao total de
alunos das duas turmas.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int TotalReprovadosC(int percentualC,int totalC);
int TotalReprovadosD(int percentualD,int totalD);
void TotalReprovadosCD(int totalC, int totalD,int ReprovadosC,int ReprovadosD);

int main()
{
	int alunosC = 60, alunosD = 20,Pc_RepC,Pc_AprD;
	
	printf("Digite o percentual de alunos reprovados na turma C:");
	scanf("%d", &Pc_RepC);
	printf("Digite o percentual de aprovados na turma D:");
	scanf("%d", &Pc_AprD);
	
	printf("O número de alunos reprovados na turma C é: %d alunos\n",TotalReprovadosC(Pc_RepC,alunosC));
	printf("O número de alunos reprovados na turma D é: %d alunos\n",TotalReprovadosD(Pc_AprD,alunosD));
	
}

int TotalReprovadosC(int percentualC,int totalC){ // a)
	int reprovadosC;
	
	reprovadosC = (percentualC * totalC)/100; // == (percentualC/100) * totalC
	return reprovadosC;
}

int TotalReprovadosD(int percentualD,int totalD){ // b)
	int reprovadosD;
	
	reprovadosD = ((100 - percentualD) * totalD)/100; // == ((100 - percentualD)/100) * totalD
	return reprovadosD;
}

void TotalReprovadosCD(int totalC, int totalD,int ReprovadosC,int ReprovadosD){// c)
	int totalTurmas,reprovadoTurmas,Pc_turmas;
	
	totalTurmas = totalC + totalC;
	reprovadoTurmas = totalC + totalD;
	Pc_turmas = (reprovadoTurmas*100)* totalTurmas;
	printf("A percentagem de alunos reprovados em relação ao total de alunos das duas turmas é: %d",Pc_turmas);
	
}

