#include "functions/aluno/protaluno.h"
#include "functions/disciplina/protdisciplina.h"
#include "functions/professor/protprofessor.h"
#include "functions/validations/validations.h"
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tamanhoUsadoProfessor = 0;
int tamanhoUsadoAluno = 0;
int tamanhoUsadoDisciplina = 0;

int menu(Aluno listaAlunos[], Professor listaProfessores[],
         Disciplina listaDisciplinas[], int *tamanhoUsadoProfessor, int *tamanhoUsadoAluno, int *tamanhoUsadoDisciplina) {
  int aux, aux1, i, mes;
  char option, busca[10];

  printf("a - Criar cadastro;\n"
         "b - Delatar cadastro;\n"
         "c - Atualizar cadastro;\n"
         "d - Página de relatórios;\n"
         "e - Sair do Portal.\n\n");

  printf("Digite a opção que deseja: ");
  scanf("%c", &option);
  flush_in();

  switch (option) {
  case 'a': //Cadastrar 
    printf("\n    a - Para aluno;\n"
           "    b - Pra professor;\n"
           "    c - Para disciplina;\n"
           "    d - Inserir aluno(a) na disciplina;\n"
           "    e - Sair do Portal.\n\n");

    printf("Digite a opção que deseja: ");
    scanf("%c", &option);
    flush_in();
    system("clear");
    
    switch (option) {
    case 'a':
      printf("Você está cadastrando um aluno(a):\n\n");
      cadastraAluno(listaAlunos, listaProfessores, *tamanhoUsadoAluno,* tamanhoUsadoProfessor);
      (*tamanhoUsadoAluno)++;
      break;
    case 'b':
      printf("Você está cadastrando um professor(a):\n\n");
      cadastraProfessor(listaProfessores, listaAlunos, *tamanhoUsadoProfessor, *tamanhoUsadoAluno);
      (*tamanhoUsadoProfessor)++;
      break;
    case 'c':
      printf("Você está cadastrando uma disciplina:\n\n");
      cadastraDisciplina(listaDisciplinas, *tamanhoUsadoDisciplina,
                         listaProfessores, *tamanhoUsadoProfessor);
      (*tamanhoUsadoDisciplina)++;
      break;
    case 'd':
      printf("Você está cadastrando um aluno em uma disciplina:\n\n");
      printf("Digite a matrícula do aluno: ");
      scanf("%d", &aux);
      flush_in();
      printf("Agora, digite o código da disciplina: ");
      scanf("%d", &aux1);
      flush_in();
      insereAluno(aux, aux1, listaAlunos, listaDisciplinas, *tamanhoUsadoAluno,    
                  *tamanhoUsadoDisciplina);
      break;
    case 'e':
      printf("Você escolheu sair do Portal.\n\n");
      return 0;
      break;
    default:
      printf("\n\nOpção inválida. \nEscolha novamente uma opção.\n\n");
      return 1;
    }

    return 1;
    break;
  case 'b': //Deletar cadastro
    printf("\n    a - Apagar aluno;\n"
           "    b - Apagar professor;\n"
           "    c - Apagar disciplina;\n"
           "    d - Deletar aluno(a) da disciplina.\n"
           "    e - Sair do Portal.\n\n");

    printf("Digite a opção que deseja: ");
    scanf("%c", &option);
    flush_in();
    system("clear");
    
    switch (option) {
    case 'a':
      printf("Você está deletando o cadastro de um aluno(a):\n\n");
      printf("Para isso, informe a matrícula do aluno: ");
      scanf("%d", &aux);
      flush_in();
      apagarAluno(listaAlunos, tamanhoUsadoAluno, aux);
      break;
    case 'b':
      printf("Você está deletando o cadastro de um professor(a):\n\n");
      printf("Para isso, informe a matrícula do professor: ");
      scanf("%d", &aux);
      flush_in();
      apagarProfessor(listaProfessores, tamanhoUsadoProfessor, aux);
      break;
    case 'c':
      printf("Você está deletando o cadastro de uma disciplina:\n\n");
      printf("Para isso, informe o código da disciplina: ");
      scanf("%d", &aux);
      flush_in();
      apagarDisciplina(aux, listaDisciplinas, tamanhoUsadoDisciplina);
      break;
    case 'd':
        printf("Você está deletando um aluno(a) de uma disciplina:\n\n");
        excluirAlunoDisciplina(listaDisciplinas, *tamanhoUsadoDisciplina);
        break;
    case 'e':
      printf("Você escolheu sair do Portal.\n\n");
      return 0;
      break;
    default:
      printf("\n\nOpção inválida. \nEscolha novamente uma opção.\n\n");
      return 1;
    }

    return 1;
    break;
  case 'c': //Atualizar cadastro
    printf("\n    a - De aluno;\n"
           "    b - De professor;\n"
           "    c - De disciplina;\n"
           "    e - Sair do Portal.\n\n");

    printf("Digite a opção que deseja: ");
    scanf("%c", &option);
    flush_in();
    system("clear");
    
    switch (option) {
    case 'a':
      printf("Atualizando o cadastro de um aluno(a)...\n\n");
      printf("Digite a matrícula para atualizar: ");
      scanf("%d", &aux);
      flush_in();
      atualizarAluno(aux, listaAlunos, listaProfessores, *tamanhoUsadoAluno, *tamanhoUsadoProfessor);
      break;
    case 'b':
      printf("Atualizando o cadastro de um professor(a)...\n\n");
      printf("Digite a matrícula para atualizar: ");
      scanf("%d", &aux);
      flush_in();
      atualizarProfessor(aux, listaProfessores, listaAlunos, *tamanhoUsadoProfessor, *tamanhoUsadoAluno);
      break;
    case 'c':
      printf("Atualizando o cadastro de uma disciplina...\n\n");
      printf("Digite o código para atualizar: ");
      scanf("%d", &aux);
      atualizaDisciplina(listaDisciplinas, *tamanhoUsadoDisciplina, aux, listaProfessores, 
                         *tamanhoUsadoProfessor);
      break;
    case 'e':
      printf("Você escolheu sair do Portal.\n\n");
      return 0;
      break;
    default:
      printf("\n\nOpção inválida. \nEscolha novamente uma opção.\n\n");
      return 1;
    }

    return 1;
    break;
  case 'd': //Relatórios
    printf("\n    a - Listar alunos;\n"
           "    b - Listar professores;\n"
           "    c - Listar disciplinas;\n"
           "    d - Lista por string;\n"
           "    e - Detalhe de disciplina com aluno;\n"
           "    f - Alunos em menos de 3 disciplinas;\n"
           "    g - Disciplinas Lotadas;\n"
           "    h - Aniversariantes do mês;\n");

    printf("\nDigite a opção do portal que deseja: ");
    scanf("%c", &option);
    flush_in();
    system("clear");
    
    switch (option) {
    case 'a':
      if (tamanhoUsadoAluno == 0)
        printf("\nNenhum aluno(a) cadastrado ainda.\n\n");
      else {
        printf("\nEscolha uma forma de ordenação:\n\n"
               "1 - Nome;\n"
               "2 - Sexo;\n"
               "3 - Idade;\n"
               "4 - Matricula;\n");
        printf("\nDigite a opção para ordenar: ");
        scanf("%d", &i);
        flush_in();
        system("clear");

        if (i == 1){
          printf("Você está ordenando os alunos(as) por Nome: \n\n");
          ordenarAlunoNome(listaAlunos, *tamanhoUsadoAluno);
        }else if (i == 2){
          printf("Qual sexo deseja listar?\n\n");
          scanf("%c", &option);
          flush_in();
          printf("Você está ordenando os alunos(as) por Sexo %c: \n\n", option);
          ordenarAlunoSexo(listaAlunos, *tamanhoUsadoAluno, option);
        }else if (i == 3){
          printf("Você está ordenando os alunos(as) por Idade: \n\n");
          ordenarAlunoData(listaAlunos, *tamanhoUsadoAluno);
        }else if (i == 4){
          printf("Você está listando os alunos: \n\n");
          listarAlunos(listaAlunos, *tamanhoUsadoAluno);
        }
      }
      break;
    case 'b':
      if (tamanhoUsadoProfessor == 0)
        printf("\nNenhum professor cadastrado ainda.\n\n");
      else {
        printf("\nEscolha uma forma de ordenação:\n\n"
               "1 - Nome;\n"
               "2 - Sexo;\n"
               "3 - Idade;\n"
               "4 - Matricula;\n");
        printf("\nDigite a opção para ordenar: ");
        scanf("%d", &i);
        flush_in();
        system("clear");
        
        if (i == 1){
          printf("Você está ordenando os professores(as) por Nome: \n\n");
          ordenarProfNome(listaProfessores, *tamanhoUsadoProfessor);
        }else if (i == 2){
          printf("Qual sexo deseja listar?\n\n");
          scanf("%c", &option);
          flush_in();
          printf("Você está ordenando os professores(as) por Sexo %c: \n\n", option);
          ordenarProfSexo(listaProfessores, *tamanhoUsadoProfessor, option);
        }else if (i == 3){
          printf("Você está ordenando os professores(as) por Idade: \n\n");
          ordenarProfData(listaProfessores, *tamanhoUsadoProfessor);
        }else if (i == 4){
          printf("Você está listando os professores: \n\n");
          listarProfessor(listaProfessores, *tamanhoUsadoProfessor);
        }
      }
      break;
    case 'c':
      printf("Você está listando as disciplinas: \n\n");
      listarDisciplina(listaDisciplinas, *tamanhoUsadoDisciplina, listaProfessores, *tamanhoUsadoProfessor);
      break;
    case 'd':
      printf("Digite ao menos 3 caracters para buscar: ");
      scanf("%s", busca);
      flush_in();
      buscarPessoas(listaProfessores, listaAlunos, *tamanhoUsadoProfessor, *tamanhoUsadoAluno, 
                    busca);
      break;
    case 'e':
      printf("Digite o codigo da diciplina: ");
      scanf("%d", &aux);
      flush_in();
      system("clear");
      printf("\n\nVocê está detalhando uma disciplina:\n\n");
      detalhesDiciplina(aux, listaDisciplinas, *tamanhoUsadoDisciplina, listaProfessores, 
                        *tamanhoUsadoProfessor);
      break;
    case 'f':
        printf("Aqui está(ão) os alunos cadastrados em menos de 3 disciplinas:\n\n");
        buscaAlunosCadastradosEmMenosDetresDisciplinas(listaAlunos, listaDisciplinas, 
                                                       *tamanhoUsadoAluno, 
                                                       *tamanhoUsadoDisciplina);
        break;
    case 'g':
      printf("Aqui está(ão) as disciplinas lotadas:\n\n");
      listarDisciplinasLotadas(listaDisciplinas, *tamanhoUsadoDisciplina, listaProfessores, 
                               *tamanhoUsadoProfessor);
      break;
    case 'h':
        printf("\nEscolha o tipo de cadastro à ser listado:\n\n"
         "1 - Alunos;\n"
         "2 - Professores;\n");
        printf("\nDigite a opção: ");
        scanf("%d", &aux);
        flush_in();
        printf("\nEscolha o mês para listar os aniversariantes: ");
        scanf("%d", &mes);
        flush_in();
        system("clear");
        if (aux == 1){
          printf("Você está listando os aniversariantes do mês dos alunos: \n");
          aniversariantesDoMesAluno(listaAlunos, *tamanhoUsadoAluno, mes);
        } else if(aux == 2){
          printf("Você está listando os aniversariantes do mês dos professores: \n");
          aniversariantesDoMesProfessor(listaProfessores, *tamanhoUsadoProfessor, mes);
        }
        break;
    default:
      system("clear");
      printf("\n\nOpção inválida. \nEscolha novamente uma opção.\n\n");
      return 1;
    }
    return 1;
    break;
  case 'e':
    system("clear");
    printf("Você escolheu sair do Portal.\n\n");
    return 0;
    break;
  default:
    printf("\n\nOpção inválida. \nEscolha novamente uma opção.\n\n");
    return 1;
  }
}


// AREA DE TESTES

Data gerarDataNascimento() {
    Data data;
    data.dia = rand() % 28 + 1;
    data.mes = rand() % 12 + 1;
    data.ano = rand() % (2006 - 1980 + 1) + 1980;
    return data;
}

void gerarCPF(char cpf[]) {
    int i, j, digito1 = 0, digito2 = 0;
    for (i = 0; i < 9; i++) {
        cpf[i] = rand() % 10 + '0';
        digito1 += (cpf[i] - '0') * (10 - i);
        digito2 += (cpf[i] - '0') * (11 - i);
    }
    digito1 = (digito1 * 10) % 11;
    digito1 = (digito1 == 10) ? 0 : digito1;

    digito2 += digito1 * 2;
    digito2 = (digito2 * 10) % 11;
    digito2 = (digito2 == 10) ? 0 : digito2;

    cpf[9] = digito1 + '0';
    cpf[10] = digito2 + '0';
    cpf[11] = '\0';
}

char gerarSexo() {
    return rand() % 2 == 0 ? 'M' : 'F';
}

Aluno gerarAluno() {
    Aluno aluno;
    static int matricula = 0; 
    strcpy(aluno.nome, "Aluno");
    aluno.idade = 2024 - gerarDataNascimento().ano;
    aluno.matricula = matricula++;
    gerarCPF(aluno.cpf);
    aluno.sexo = gerarSexo();
    aluno.dataNascimento = gerarDataNascimento();
    return aluno;
}

Professor gerarProfessor() {
    Professor Professor;
    static int matricula = 0; 
    strcpy(Professor.nome, "professor");
    Professor.idade = 2024 - gerarDataNascimento().ano;
    Professor.matricula = matricula++;
    gerarCPF(Professor.cpf);
    Professor.sexo = gerarSexo();
    Professor.dataNascimento = gerarDataNascimento();
    return Professor;
}


int main() {

  Aluno listaAlunos[tamMaximo];
  Professor listaProfessores[tamMaximo];
  Disciplina listaDisciplinas[tamMaximo];

  int tamanhoUsadoProfessor = 0;
  int tamanhoUsadoAluno = 0;
  int tamanhoUsadoDisciplina = 0;



  //AUTOMATIZAÇÃO DE TESTES

  // for(int i = 0; i < 41; i++){
  //   listaAlunos[i] = gerarAluno();
  //   listaProfessores[i] = gerarProfessor();
  // }

  // tamanhoUsadoAluno = 41;
  // tamanhoUsadoProfessor = 41;


  // strcpy(listaDisciplinas[tamanhoUsadoDisciplina].nome, "Matematica");
  // listaDisciplinas[tamanhoUsadoDisciplina].codigo = 0;
  // listaDisciplinas[tamanhoUsadoDisciplina].semestre = 1;
  // listaDisciplinas[tamanhoUsadoDisciplina].matriculaProfessor = 0;
  // posicionaPlaceHolders(listaDisciplinas);
  // for(int i = 0;i<tamanhoUsadoAluno;i++){
  //   listaDisciplinas[tamanhoUsadoDisciplina].alunos[i] = listaAlunos[i];
  // }
  // tamanhoUsadoDisciplina++;
  

  printf("Bem-vindo ao Portal da Escola!\nVamos iniciar o seu cadastro. "
         "Acesse "
         "o menu abaixo para as informações necessárias:\n\n");

  while (menu(listaAlunos, listaProfessores, listaDisciplinas, &tamanhoUsadoProfessor, &tamanhoUsadoAluno, &tamanhoUsadoDisciplina)) {
  }

  return 0;
}