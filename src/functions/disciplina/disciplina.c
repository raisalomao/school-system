#include "../../struct.h"
#include "../aluno/protaluno.h"
#include "../professor/protprofessor.h"
#include "../validations/validations.h"
#include <stdio.h>
#include <stdlib.h>

int iteradorCodigo = 0;

int buscarDisciplina(Disciplina *disciplinas, int tamanho, int codigo) { 
    int inicio = 0;
    int fim = tamanho - 1;
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (disciplinas[meio].codigo == codigo) {
            return meio;
        }
        if (disciplinas[meio].codigo < codigo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

void posicionaPlaceHolders(Disciplina *disciplina) {
  int i;
  for (i = 0; i < tamMaximo; i++) {
    disciplina->alunos[i].matricula = -1;
  }
}

void apagarDisciplina(int codigo, Disciplina Disciplinas[], int *tamanho) {
  int indice = buscarDisciplina(Disciplinas, *tamanho, codigo);
  if (indice < 0 || indice >= *tamanho) {
    printf("Esta disciplina não foi encontrada.\n");
    return;
  }

  for (int i = indice; i < *tamanho - 1; ++i) {
      Disciplinas[i] = Disciplinas[i + 1];
  }

  (*tamanho)--;
  printf("\n\nDisciplina %s apagada com sucesso!\n\n", Disciplinas->nome);
}

void cadastraDisciplina(Disciplina listaDisciplinas[],int tamanhoUsadoDisciplina, Professor listaProfessores[], int tamanhoUsadoProfessor) {

  int aux;
  Disciplina novaDisciplina;
  
  if (tamanhoUsadoProfessor == 0){
    printf("\nÉ necessário cadastrar um professor(a) primeiro.\n\n");
    return;
  }else if (tamanhoUsadoDisciplina == tamMaximo - 1)
    printf("Você só tem espaço para cadastrar mais 1 disciplina.\n\n");
  else if (tamanhoUsadoDisciplina == tamMaximo)
    printf("\n\nNúmero máximo de disciplinas cadastradas atingido.\n\n");
  else{
    printf("\nNome da disciplina: ");
    scanf("%[^\n]", novaDisciplina.nome);
    flush_in();
    printf("\nSemestre: ");
    scanf("%d", &novaDisciplina.semestre);
    flush_in();
    printf("\nN° de matrícula do professor: ");
    scanf("%d", &aux);
    flush_in();
    if(buscarProfessor(listaProfessores, tamanhoUsadoProfessor, aux) == -1){
      printf("\n\nEste professor não foi encontrado.\n\n");
      return;
    }
    novaDisciplina.matriculaProfessor = aux;
    posicionaPlaceHolders(&novaDisciplina);
    novaDisciplina.codigo = iteradorCodigo;
    listaDisciplinas[tamanhoUsadoDisciplina] = novaDisciplina;
    iteradorCodigo++;
    system("clear");
    printf("Parabéns, disciplina cadastrada com sucesso com código %d!\n" 
           "Com o(a) responsável: %s.\n\n",
           novaDisciplina.codigo, listaProfessores[buscarProfessor(listaProfessores,     
           tamanhoUsadoProfessor, aux)].nome);
  }
}

void atualizaDisciplina(Disciplina listaDisciplinas[], int tamanhoUsadoDisciplina, int codigo, Professor listaProfessores[], int tamanhoUsadoProfessor){
  int indice = buscarDisciplina(listaDisciplinas, tamanhoUsadoDisciplina, codigo);
  if (indice > tamanhoUsadoDisciplina || indice == -1){
    printf("Esta disciplina não foi encontrada.\n");
    return;
  }
  int aux;
  Disciplina disciplinaAtualizada;
  printf("\nDigite o novo nome do Professor: ");
  scanf("%[^\n]", disciplinaAtualizada.nome);
  flush_in();
  printf("\nDigite o novo semestre da disciplina: ");
  scanf("%d", &disciplinaAtualizada.semestre);
  flush_in();
  printf("\nDigite a nova matricula do docente: ");
  scanf("%d", &disciplinaAtualizada.matriculaProfessor);
  flush_in();
  if(buscarProfessor(listaProfessores, tamanhoUsadoProfessor, disciplinaAtualizada.matriculaProfessor) == -1){
    printf("\n\nEste professor não foi encontrado.\n\n");
    return;
  }else{
    disciplinaAtualizada.codigo = codigo;
    for(int i = 0; i < tamMaximo; i++){
      disciplinaAtualizada.alunos[i] = listaDisciplinas[indice].alunos[i];
    }
    listaDisciplinas[indice] = disciplinaAtualizada;
    printf("\n\nDisciplina atualizada com sucesso!\n\n");
  }
}

void detalhesDiciplina(int codigoDiciplina, Disciplina listaDisciplinas[], int tamanhoUsado, Professor listaProfessores[], int tamanhoUsadoProfessores) {
  codigoDiciplina = buscarDisciplina(listaDisciplinas, tamanhoUsado, codigoDiciplina);
  if(codigoDiciplina == -1){
    printf("\n\nEsta disciplina não foi encontrada\n\n");
    return;
  }
  Disciplina disciplina = listaDisciplinas[codigoDiciplina];
  printf("\n-----------------------------------------------------------------------\n");
  printf("Código: %d\n", disciplina.codigo);
  printf("Nome da disciplina: %s\n", disciplina.nome);
  printf("Semestre da disciplina: %d\n", disciplina.semestre);
  if(buscarProfessor(listaProfessores, tamanhoUsadoProfessores, disciplina.matriculaProfessor) != -1)
  printf("Professor(a) responsável: %s\n", listaProfessores[buscarProfessor(listaProfessores, tamanhoUsadoProfessores, disciplina.matriculaProfessor)].nome);
  for (int i = 0; i < tamMaximo && disciplina.alunos[i].matricula != -1; i++)
    printf("%d° aluno: %s\n", i+1, disciplina.alunos[i].nome);
  printf("---------------------------------------------------------------"
         "-------------\n\n");
}

void insereAluno(int matricula, int codigoDiciplina, Aluno listaAlunos[], Disciplina listaDisciplinas[], int tamanhoUsadoAluno, int tamanhoUsadoDisciplina) {
  codigoDiciplina = buscarDisciplina(listaDisciplinas, tamanhoUsadoDisciplina, codigoDiciplina);
  int alunoJaCadastrado = 0;
  if (tamanhoUsadoAluno == 0 && tamanhoUsadoDisciplina == 0)
    printf("\nCadastre primeiro um aluno(a) e uma disciplina no sistema.\n\n");
  else if(matricula == -1){
      printf("\n\nEste aluno não foi encontrado.\n\n");
      return;
  }else if(codigoDiciplina == -1){
    printf("\n\nEssa disciplina não foi encontrada.\n\n");
    return;
  }        
  for (int i = 0; i < tamMaximo; i++) {
        if (listaDisciplinas[codigoDiciplina].alunos[i].matricula ==     
            listaAlunos[matricula].matricula) {
            alunoJaCadastrado = 1;
            break;
        }
    }

  if (alunoJaCadastrado) 
      printf("\nEste aluno já está cadastrado nesta disciplina.\n\n");
  else{
      matricula = buscarAluno(listaAlunos, tamanhoUsadoAluno, 
                              matricula);
      for (int i = 0; i < tamMaximo; i++) {
        if (listaDisciplinas[codigoDiciplina].alunos[i].matricula == -1){
          listaDisciplinas[codigoDiciplina].alunos[i] = listaAlunos[matricula];
          printf("\nO aluno %s, foi inserido com sucesso na disciplina %s!\n\n",listaAlunos[matricula].nome, listaDisciplinas[codigoDiciplina].nome);
        return;
      }
    }
  }
}

void excluirAlunoDisciplina(Disciplina listaDisciplinas[], int tamanhoUsadoDisciplinas) {
  int codigoDisciplina, matriculaAluno;
  printf("\nDigite o código da disciplina: ");
  scanf("%d", &codigoDisciplina);
  flush_in();
  int indiceDisciplina = buscarDisciplina(listaDisciplinas, tamanhoUsadoDisciplinas, codigoDisciplina);
  if(codigoDisciplina == -1){
    printf("\n\nEsta disciplina não foi encontrada.\n\n");
    return;
  }
  printf("\nDigite a matrícula do aluno: ");
  scanf("%d", &matriculaAluno);
  flush_in();
  
  int indiceDelecao = -1;
  for(int i = 0; i < tamMaximo; i++){
    if(listaDisciplinas[indiceDisciplina].alunos[i].matricula == matriculaAluno){
      indiceDelecao = i;
    }
  }
  if(indiceDelecao == -1){
    printf("\n\nEste aluno não foi encontrado.\n\n");
    return;
  }
  int ultimoAluno;
  for(int i = indiceDelecao; i < tamMaximo && listaDisciplinas[indiceDisciplina].alunos[i].matricula != -1; i++){
    ultimoAluno = i + 1;
  }
  for(int i = indiceDelecao; i < ultimoAluno - 1; i++){
    listaDisciplinas[indiceDisciplina].alunos[i] = listaDisciplinas[indiceDisciplina].alunos[i+1];
  }
  listaDisciplinas[indiceDisciplina].alunos[ultimoAluno-1].matricula = -1;
  printf("\n\nAluno excluído com sucesso!\n\n");
}


void listarDisciplina(Disciplina listaDisciplinas[], int tamanhoUsado, Professor listaProfessores[], int tamanhoUsadoProfessores) {
  if (tamanhoUsado == 0)
    printf("\nCadastre primeiro uma disciplina no sistema.\n");
  else {
    printf("\n\n %-10s | %-5s | %-6s \n", "Nome", "Semestre",
           "Nome do professor");
    printf("---------------------------------------------------------------"
           "------"
           "-------------\n");
    for (int i = 0; i < tamanhoUsado; i++) {
      while (listaDisciplinas[i].codigo == -1)
        i++;
      if(buscarProfessor(listaProfessores, tamanhoUsadoProfessores, listaDisciplinas[i].matriculaProfessor) != -1){
        printf(" %-10s | %-5d | %-6s \n", listaDisciplinas[i].nome,
               listaDisciplinas[i].semestre, listaProfessores[buscarProfessor(listaProfessores, tamanhoUsadoProfessores, listaDisciplinas[i].matriculaProfessor)].nome);
      }else{
        printf(" %-10s | %-5d | %-6s \n", listaDisciplinas[i].nome,
           listaDisciplinas[i].semestre, "professor não encontrado");
      }
    }
    printf("---------------------------------------------------------------"
           "------"
           "-------------\n\n");
  }
}

void listarDisciplinasLotadas(Disciplina listaDisciplinas[], int tamanhoUsado, Professor listaProfessores[], int tamanhoUsadoProfessores){
  Disciplina *disciplinasLotadas = (Disciplina *)malloc(tamanhoUsado * sizeof(Disciplina));
  int tamanho = 0;
  for(int i = 0; i < tamanhoUsado; i++){
    if(listaDisciplinas[i].alunos[39].matricula != -1){
      disciplinasLotadas[tamanho] = listaDisciplinas[i];
      tamanho++;
    }
  }
  listarDisciplina(disciplinasLotadas, tamanho, listaProfessores, tamanhoUsadoProfessores);
  free(disciplinasLotadas);
}