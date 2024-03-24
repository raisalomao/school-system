#include "../../struct.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../aluno/protaluno.h"
#include "../professor/protprofessor.h"

int checkCadastroAluno(char *cpf, Aluno listaAlunos[], int tamanhoUsadoAluno) {
  for (int i = 0; i < tamanhoUsadoAluno; i++) {
    if (strcmp(listaAlunos[i].cpf, cpf) == 0) {
      return 1;
    }
  }
  return 0;
}  

int checkCadastroProfessor(char *cpf, Professor listaProfessores[], int tamanhoUsadoProfessor) {
  for (int i = 0; i < tamanhoUsadoProfessor; i++) {
    if (strcmp(listaProfessores[i].cpf, cpf) == 0) {
      return 1;
    }
  }
  return 0;
}  

bool VerificaIdade(char dataNascimento[], int informeIdade) {
    int dia, mes, ano;
    time_t t = time(NULL); 
    struct tm tm = *localtime(&t); 

    sscanf(dataNascimento, "%d/%d/%d", &dia, &mes, &ano);
    int idade = tm.tm_year + 1900 - ano; 
    if (tm.tm_mon + 1 < mes || (tm.tm_mon + 1 == mes && tm.tm_mday < dia))
        idade--;

    return idade == informeIdade;
}

void buscarPessoas(Professor Professores[], Aluno Alunos[], int tamanhoProfessor, int tamanhoAluno, char busca[]){
  if(strlen(busca) < 3){
    printf("\n\nA busca precisa de no mínimo 3 caracters.\n\n");
    return;
  }
  int i;
  Professor *listaProfessores = (Professor *)malloc(tamanhoProfessor * sizeof(Professor));
  int tamanhoNovoProfessor = 0;
  for(i = 0; i < tamanhoProfessor; i++){
    if(strstr(Professores[i].nome, busca) != NULL){
      listaProfessores[tamanhoNovoProfessor] = Professores[i];
      tamanhoNovoProfessor++;
    }
  }
  Aluno *listaAlunos = (Aluno *)malloc(tamanhoAluno * sizeof(Aluno));
  int tamanhoNovoAluno = 0;
  for(i = 0; i < tamanhoAluno; i++){
    if(strstr(Alunos[i].nome, busca) != NULL){
      listaAlunos[tamanhoNovoAluno] = Alunos[i];
      tamanhoNovoAluno++;
    }
  }
  printf("Aqui estão os resultados para '%s':\n\n", busca);
  printf("Alunos encontrados: \n\n");
  listarAlunos(listaAlunos, tamanhoNovoAluno);
  free(listaAlunos);
  printf("Professores encontrados: \n\n");
  listarProfessor(listaProfessores, tamanhoNovoProfessor);
  free(listaProfessores);
}

void flush_in() {
  int ch;
  while ((ch = fgetc(stdin)) != EOF && ch != '\n') {
  }
}

Data stringParaData(char *date_str) {
  Data date;
  char *token;
  char *copia = strdup(date_str); 
  token = strtok(copia, "/");
  date.dia = atoi(token);
  token = strtok(NULL, "/");
  date.mes = atoi(token);
  token = strtok(NULL, "/");
  date.ano = atoi(token);
  free(copia); 
  return date;
}

int CheckDate(Data data) {
  if (data.dia > 31 || data.mes > 12 || data.ano < 1900 || data.ano > 2024){
      return 1;
  }else if (data.dia > 29 && data.mes == 2){
      return 1;
  }else if (data.dia == 31 &&
           (data.mes != 1 && data.mes != 3 && data.mes != 5 && data.mes != 7 &&
            data.mes != 10 && data.mes != 12)){
      return 1;
    }else if (data.dia > 28 && data.mes == 2 && data.ano % 4 != 0 &&
             data.ano > 1900){
      return 1;
    }else
        return 0;
}

char *dataParaString(Data data) {
  char *date_str =
      (char *)malloc(11 * sizeof(char)); 
  sprintf(date_str, "%02d/%02d/%04d", data.dia, data.mes, data.ano);
  return date_str;
}


bool CheckCPF(char cpf[]) {
  int n1, n2, i, j, soma1 = 0, soma2 = 0;
  if (strlen(cpf) != 11) {
    return false;
  } else {
    if (strcmp(cpf, "00000000000") == 0 || strcmp(cpf, "11111111111") == 0 ||
        strcmp(cpf, "22222222222") == 0 || strcmp(cpf, "33333333333") == 0 ||
        strcmp(cpf, "44444444444") == 0 || strcmp(cpf, "55555555555") == 0 ||
        strcmp(cpf, "66666666666") == 0 || strcmp(cpf, "77777777777") == 0 ||
        strcmp(cpf, "88888888888") == 0 || strcmp(cpf, "99999999999") == 0) {
      return false;
    } else {
      for (i = 0, j = 10; i < 9; i++, j--)
        soma1 += (cpf[i] - 48) * j;
      soma1 = (soma1 * 10) % 11;
      if (soma1 == 10)
        n1 = 0;
      else
        n1 = soma1;

      for (i = 0, j = 11; i < 10; i++, j--)
        soma2 += (cpf[i] - 48) * j;
      soma2 = (soma2 * 10) % 11;
      if (soma2 == 10)
        n2 = 0;
      else
        n2 = soma2;
      if (n1 != cpf[9] - 48 && n2 != cpf[10] - 48)
        return false;
      else
        return true;
    }
  }
}

bool CheckSexo(char sexo){
  if(sexo == 'M' || sexo == 'F'){
    return true;
  } else{
    return false;
  }
}