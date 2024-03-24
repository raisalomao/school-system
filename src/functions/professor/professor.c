#include "../../struct.h"
#include "../aluno/protaluno.h"
#include "../validations/validations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int iteradorMatriculaProfessor = 0;

int buscarProfessor(Professor *professores, int tamanho, int matricula) {
  int inicio = 0;
  int fim = tamanho - 1;
  while (inicio <= fim) {
    int meio = inicio + (fim - inicio) / 2;
    if (professores[meio].matricula == matricula) {
      return meio;
    }
    if (professores[meio].matricula < matricula) {
      inicio = meio + 1;
    } else {
      fim = meio - 1;
    }
  }
  return -1;
}

void apagarProfessor(Professor *professores, int *tamanho, int matricula) {
  int indice = buscarProfessor(professores, *tamanho, matricula);
  if (indice < 0 || indice >= *tamanho) {
    printf("\n\nEste professor não foi encontrado.\n\n");
    return;
  }

  for (int i = indice; i < *tamanho - 1; ++i)
    professores[i] = professores[i + 1];

  (*tamanho)--;
  system("clear");
  printf("Professor(a): %s, apagado com sucesso!\n\n",
         professores[indice].nome);
}

int atualizarProfessor(int matricula, Professor listaProfessores[],
                       Aluno listaAlunos[], int tamanhoUsado,
                       int tamanhoUsadoAluno) {
  char sexo;
  matricula = buscarProfessor(listaProfessores, tamanhoUsado, matricula);
  if (matricula > tamanhoUsado || matricula == -1) {
    printf("\n\nMatricula não encontrada\n");
    return 1;
  }
  char dataNascimento[11];
  printf("\nDigite o novo nome do Professor: ");
  scanf("%[^\n]", listaProfessores[matricula].nome);
  flush_in();
  printf("\nDigite a nova idade do Professor: ");
  scanf("%d", &listaProfessores[matricula].idade);

  do {
    printf("\nDigite o novo sexo do professor(M/F): ");
    scanf(" %c", &sexo);
    flush_in();
    if (!CheckSexo(sexo))
      printf("\nSexo inválido.\n");
    else {
      listaProfessores[matricula].sexo = sexo;
      break;
    }
  } while (1);

  do {
    printf("\nDigite a nova data de nascimento do professor: ");
    scanf("%s", dataNascimento);
    flush_in();
    if (CheckDate(stringParaData(dataNascimento)))
      printf("\nHá divergências entre a idade e data de nascimento.\n");
    else {
      if (!VerificaIdade(dataNascimento, listaProfessores[matricula].idade))
        printf("\nHá divergências entre a idade e data de nascimento.\n");
      else {
        listaProfessores[matricula].dataNascimento =
            stringParaData(dataNascimento);
        break;
      }
    }
  } while (1);

  char cpf[12];
  strcpy(listaProfessores[matricula].cpf, "00000000000");
  do {
    printf("\nDigite o novo CPF do professor: ");
    scanf("%s", cpf);
    flush_in();
    if (checkCadastroProfessor(cpf, listaProfessores, tamanhoUsado))
      printf("\nCPF já cadastrado no sistema.\n");
    else if (!CheckCPF(cpf))
      printf("\nVerifique se digitou o CPF corretamente.\n");
    else {
      if (checkCadastroAluno(cpf, listaAlunos, tamanhoUsado))
        printf("\nEste CPF já está vinculado a um aluno.\n");
      else {
        strcpy(listaProfessores[matricula].cpf, cpf);
        break;
      }
    }
  } while (1);
  system("clear");
  printf("Pronto! Professor atualizado com sucesso.\nCom o nome de: %s \n",
         listaProfessores[matricula].nome);
  return 0;
}

void cadastraProfessor(Professor listaProfessores[], Aluno listaAlunos[],
                       int tamanhoUsadoProfessor, int tamanhoUsadoAluno) {
  char sexo;
  if (tamanhoUsadoProfessor == tamMaximo) {
    printf("\n\nNúmero máximo de professores cadastrados atingido.\n\n");
    return;
  } else if (tamanhoUsadoProfessor == tamMaximo - 1)
    printf("Você só tem espaço para cadastrar mais 1 Professor.\n\n");

  Professor novoProfessor;
  char dataNascimento[11];

  printf("\nNome completo: ");
  scanf("%[^\n]", novoProfessor.nome);
  flush_in();
  printf("\nIdade: ");
  scanf("%d", &novoProfessor.idade);
  flush_in();

  do {
    printf("\nSexo(M/F): ");
    scanf(" %c", &sexo);
    flush_in();
    if (!CheckSexo(sexo))
      printf("\nSexo inválido.\n");
    else {
      novoProfessor.sexo = sexo;
      break;
    }
  } while (1);

  do {
    printf("\nData de nascimento: ");
    scanf("%s", dataNascimento);
    flush_in();
    if (CheckDate(stringParaData(dataNascimento)))
      printf("\nA data foi digitada de forma incorreta, tente dia/mês/ano.\n");
    else {
      if (!VerificaIdade(dataNascimento, novoProfessor.idade))
        printf("\nHá divergências entre a idade e data de nascimento.\n");
      else {
        novoProfessor.dataNascimento = stringParaData(dataNascimento);
        break;
      }
    }
  } while (1);

  char cpf[12];
  do {
    printf("\nCPF: ");
    scanf("%s", cpf);
    flush_in();
    if (!CheckCPF(cpf)) {
      printf("\nVerifique se digitou o CPF corretamente.\n");
    } else {
      if (checkCadastroProfessor(cpf, listaProfessores, tamanhoUsadoProfessor))
        printf("\nCPF já cadastrado no sistema.\n");
      else if (checkCadastroAluno(cpf, listaAlunos, tamanhoUsadoAluno))
        printf("\nEste CPF já está vinculado a um aluno.\n");
      else {
        strcpy(novoProfessor.cpf, cpf);
        novoProfessor.matricula = iteradorMatriculaProfessor;
        listaProfessores[tamanhoUsadoProfessor] = novoProfessor;
        iteradorMatriculaProfessor++;
        system("clear");
        printf("Parabéns, Professor(a) cadastrado com sucesso com matrícula "
               "%d!\nCom o nome de: %s.\n\n",
               novoProfessor.matricula, novoProfessor.nome);
        break;
      }
    }
  } while (1);
}

void listarProfessor(Professor listaProfessores[], int tamanhoUsado) {
  if (tamanhoUsado == 0)
    printf("\nCadastre primeiro um professor no sistema.\n\n");
  else {
    printf("\n\n %-10s | %-30s | %-6s | %-5s | %-15s | %-12s |\n", "Matrícula",
           "Nome", "Idade", "Sexo", "Data Nascimento", "CPF");
    printf("---------------------------------------------------------------"
           "------"
           "-------------\n");
    for (int i = 0; i < tamanhoUsado; i++) {
      printf(" %-10d | %-30s | %-6d | %-5c | %-15s | %-12s |\n",
             listaProfessores[i].matricula, listaProfessores[i].nome,
             listaProfessores[i].idade, listaProfessores[i].sexo,
             dataParaString(listaProfessores[i].dataNascimento),
             listaProfessores[i].cpf);
    }
    printf("---------------------------------------------------------------"
           "------"
           "-------------\n\n");
  }
}

void ordenarProfNome(Professor listaDeProfessores[], int tamanhoUsado) {
  Professor *listaProfessores =
      (Professor *)malloc(tamanhoUsado * sizeof(Professor));
  for (int j = 0; j < tamanhoUsado; j++) {
    listaProfessores[j] = listaDeProfessores[j];
  }
  int i, j;
  Professor temp;
  for (i = 0; i < tamanhoUsado - 1; i++) {
    for (j = 0; j < tamanhoUsado - i - 1; j++) {
      if (strcmp(listaProfessores[j].nome, listaProfessores[j + 1].nome) > 0) {
        temp = listaProfessores[j];
        listaProfessores[j] = listaProfessores[j + 1];
        listaProfessores[j + 1] = temp;
      }
    }
  }
  listarProfessor(listaProfessores, tamanhoUsado);
  free(listaProfessores);
}

void ordenarProfData(Professor listaDeProfessores[], int tamanhoUsado) {
  Professor *listaProfessores =
      (Professor *)malloc(tamanhoUsado * sizeof(Professor));
  for (int j = 0; j < tamanhoUsado; j++) {
    listaProfessores[j] = listaDeProfessores[j];
  }
  int i, j;
  Professor temp;
  for (i = 0; i < tamanhoUsado - 1; i++) {
    for (j = 0; j < tamanhoUsado - i - 1; j++) {
      if (listaProfessores[j].dataNascimento.ano >
              listaProfessores[j + 1].dataNascimento.ano ||
          (listaProfessores[j].dataNascimento.ano ==
               listaProfessores[j + 1].dataNascimento.ano &&
           listaProfessores[j].dataNascimento.mes >
               listaProfessores[j + 1].dataNascimento.mes) ||
          (listaProfessores[j].dataNascimento.ano ==
               listaProfessores[j + 1].dataNascimento.ano &&
           listaProfessores[j].dataNascimento.mes ==
               listaProfessores[j + 1].dataNascimento.mes &&
           listaProfessores[j].dataNascimento.dia >
               listaProfessores[j + 1].dataNascimento.dia)) {

        temp = listaProfessores[j];
        listaProfessores[j] = listaProfessores[j + 1];
        listaProfessores[j + 1] = temp;
      }
    }
  }
  listarProfessor(listaProfessores, tamanhoUsado);
  free(listaProfessores);
}

void ordenarProfSexo(Professor listaDeProfessores[], int tamanhoUsado,
                     char sexo) {
  Professor *listaProfessores =
      (Professor *)malloc(tamanhoUsado * sizeof(Professor));
  int tamanho = 0;
  for (int j = 0; j < tamanhoUsado; j++) {
    if (listaDeProfessores[j].sexo == sexo) {
      listaProfessores[tamanho] = listaDeProfessores[j];
      tamanho++;
    }
  }
  listarProfessor(listaProfessores, tamanho);
  free(listaProfessores);
}

void aniversariantesDoMesProfessor(Professor listaDeProfessores[],
                                   int tamanhoUsado, int mes_atual) {
  Professor *listaProfessores =
      (Professor *)malloc(tamanhoUsado * sizeof(Professor));
  int tamanho = 0;

  for (int j = 0; j < tamanhoUsado; j++) {
    if (listaDeProfessores[j].dataNascimento.mes == mes_atual) {
      listaProfessores[tamanho] = listaDeProfessores[j];
      tamanho++;
    }
  }
  listarProfessor(listaProfessores, tamanho);
  free(listaProfessores);
}