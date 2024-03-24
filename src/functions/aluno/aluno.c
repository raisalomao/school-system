#include "../../struct.h"
#include "../validations/validations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int iteradorMatriculaAluno = 0;

int buscarAluno(Aluno *alunos, int tamanho, int matricula) {
  int inicio = 0;
  int fim = tamanho - 1;
  while (inicio <= fim) {
    int meio = inicio + (fim - inicio) / 2;
    if (alunos[meio].matricula == matricula) {
      return meio;
    }
    if (alunos[meio].matricula < matricula) {
      inicio = meio + 1;
    } else {
      fim = meio - 1;
    }
  }
  return -1;
}

void apagarAluno(Aluno *alunos, int *tamanho, int matricula) {
  int indice = buscarAluno(alunos, *tamanho, matricula);
  if (indice < 0 || indice >= *tamanho) {
    printf("\n\nEste aluno(a) não foi encontrado.\n");
    return;
  }
  for (int i = indice; i < *tamanho - 1; ++i)
    alunos[i] = alunos[i + 1];
  (*tamanho)--;
  system("clear");
  printf("Aluno(a): %s, apagado com sucesso!\n\n", alunos[indice].nome);
}

int atualizarAluno(int matricula, Aluno listaAlunos[],
                   Professor listaProfessores[], int tamanhoUsado,
                   int tamanhoUsadoProfessor) {
  char sexo;
  matricula = buscarAluno(listaAlunos, tamanhoUsado, matricula);
  if (matricula > tamanhoUsado || matricula == -1) {
    printf("Matricula não encontrada\n");
    return 1;
  }
  char dataNascimento[11];
  printf("\nDigite o novo nome do aluno(a): ");
  scanf("%[^\n]", listaAlunos[matricula].nome);
  flush_in();
  printf("\nDigite a nova idade do aluno(a): ");
  scanf("%d", &listaAlunos[matricula].idade);

  do {
    printf("\nDigite o novo sexo do aluno(M/F): ");
    scanf(" %c", &sexo);
    flush_in();
    if (!CheckSexo(sexo))
      printf("\nSexo inválido.\n");
    else {
      listaAlunos[matricula].sexo = sexo;
      break;
    }
  } while (1);

  do {
    printf("\nDigite a nova data de nascimento do aluno: ");
    scanf("%s", dataNascimento);
    flush_in();
    if (CheckDate(stringParaData(dataNascimento)))
      printf("\nA data foi digitada de forma incorreta, tente dia/mês/ano.\n");
    else {
      if(!VerificaIdade(dataNascimento, listaAlunos[matricula].idade))
        printf("\nHá divergências entre a idade e data de nascimento.\n");
      else{
        listaAlunos[matricula].dataNascimento = stringParaData(dataNascimento);
        break;
      }
    }
  } while (1);

  char cpf[12];
  strcpy(listaAlunos[matricula].cpf, "00000000000");
  do {
    printf("\nDigite o novo CPF do aluno: ");
    scanf("%s",cpf);
    flush_in();
    if (checkCadastroAluno(cpf, listaAlunos, tamanhoUsado))
      printf("\nCPF já cadastrado no sistema.\n");
    else if (!CheckCPF(cpf))
      printf("\nVerifique se digitou o CPF corretamente.\n");
    else {
      if (checkCadastroProfessor(cpf, listaProfessores, tamanhoUsadoProfessor))
        printf("\nEste CPF já está vinculado a um professor.\n");
      else{
        strcpy(listaAlunos[matricula].cpf, cpf);
        break;
      }
    }
  } while (1);
  system("clear");
  printf("Pronto! Aluno atualizado com sucesso.\nCom o nome de: %s \n",
         listaAlunos[matricula].nome);
  return 0;
}

void cadastraAluno(Aluno listaAlunos[], Professor listaProfessores[],
                   int tamanhoUsado, int tamanhoUsadoProfessor) {
  if (tamanhoUsado == tamMaximo) {
    printf("\n\nNúmero máximo de alunos(as) cadastrados atingido.\n\n");
    return;
  } else if (tamanhoUsado == tamMaximo - 1)
    printf("Você só tem espaço para cadastrar mais 1 aluno(a).\n\n");

  Aluno novoAluno;
  char dataNascimento[11];
  char sexo;

  printf("\nNome completo: ");
  scanf("%[^\n]", novoAluno.nome);
  flush_in();
  printf("\nIdade: ");
  scanf("%d", &novoAluno.idade);
  flush_in();

  do {
    printf("\nSexo(M/F): ");
    scanf(" %c", &sexo);
    flush_in();
    if (!CheckSexo(sexo))
      printf("\nSexo inválido.\n");
    else {
      novoAluno.sexo = sexo;
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
      if(!VerificaIdade(dataNascimento, novoAluno.idade))
        printf("\nHá divergências entre a idade e data de nascimento.\n");
      else{
        novoAluno.dataNascimento = stringParaData(dataNascimento);
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
      if (checkCadastroAluno(cpf, listaAlunos, tamanhoUsado))
        printf("\nCPF já cadastrado no sistema.\n");
      else if (checkCadastroProfessor(cpf, listaProfessores,
                                      tamanhoUsadoProfessor))
        printf("\nEste CPF já está vinculado a um professor.\n");
      else {
        strcpy(novoAluno.cpf, cpf);
        novoAluno.matricula = iteradorMatriculaAluno;
        listaAlunos[tamanhoUsado] = novoAluno;
        iteradorMatriculaAluno++;
        system("clear");
        printf("Parabéns, Aluno(a) cadastrado com sucesso com matrícula "
               "%d!\nCom o nome de: %s.\n\n",
               novoAluno.matricula, novoAluno.nome);
        break;
      }
    }
  } while (1);
}


void listarAlunos(Aluno listaAlunos[], int tamanhoUsado) {
  if (tamanhoUsado == 0) {
    printf("\nCadastre primeiro um aluno no sistema.\n\n");
    return;
  }
  printf("\n\n %-10s | %-30s | %-6s | %-5s | %-15s | %-12s |\n", "Matrícula",
         "Nome", "Idade", "Sexo", "Data Nascimento", "CPF");
  printf("---------------------------------------------------------------"
         "------"
         "-------------\n");
  for (int i = 0; i < tamanhoUsado; i++) {
    while (listaAlunos[i].matricula == -1)
      i++;
    printf(" %-10d | %-30s | %-6d | %-5c | %-15s | %-12s |\n",
           listaAlunos[i].matricula, listaAlunos[i].nome, listaAlunos[i].idade,
           listaAlunos[i].sexo, dataParaString(listaAlunos[i].dataNascimento),
           listaAlunos[i].cpf);
  }
  printf("---------------------------------------------------------------"
         "------"
         "-------------\n\n");
}

void ordenarAlunoNome(Aluno listaDeAlunos[], int tamanhoUsado) {
  Aluno *listaAlunos = (Aluno *)malloc(tamanhoUsado * sizeof(Aluno));
  for (int j = 0; j < tamanhoUsado; j++) {
    listaAlunos[j] = listaDeAlunos[j];
  }
  int i, j;
  Aluno temp;
  for (i = 0; i < tamanhoUsado - 1; i++) {
    for (j = 0; j < tamanhoUsado - i - 1; j++) {
      if (strcmp(listaAlunos[j].nome, listaAlunos[j + 1].nome) > 0) {
        temp = listaAlunos[j];
        listaAlunos[j] = listaAlunos[j + 1];
        listaAlunos[j + 1] = temp;
      }
    }
  }
  listarAlunos(listaAlunos, tamanhoUsado);
  free(listaAlunos);
}

void ordenarAlunoData(Aluno listaDeAlunos[], int tamanhoUsado) {
  Aluno *listaAlunos = (Aluno *)malloc(tamanhoUsado * sizeof(Aluno));
  for (int j = 0; j < tamanhoUsado; j++) {
    listaAlunos[j] = listaDeAlunos[j];
  }
  int i, j;
  Aluno temp;
  for (i = 0; i < tamanhoUsado - 1; i++) {
    for (j = 0; j < tamanhoUsado - i - 1; j++) {
      if (listaAlunos[j].dataNascimento.ano >
              listaAlunos[j + 1].dataNascimento.ano ||
          (listaAlunos[j].dataNascimento.ano ==
               listaAlunos[j + 1].dataNascimento.ano &&
           listaAlunos[j].dataNascimento.mes >
               listaAlunos[j + 1].dataNascimento.mes) ||
          (listaAlunos[j].dataNascimento.ano ==
               listaAlunos[j + 1].dataNascimento.ano &&
           listaAlunos[j].dataNascimento.mes ==
               listaAlunos[j + 1].dataNascimento.mes &&
           listaAlunos[j].dataNascimento.dia >
               listaAlunos[j + 1].dataNascimento.dia)) {

        temp = listaAlunos[j];
        listaAlunos[j] = listaAlunos[j + 1];
        listaAlunos[j + 1] = temp;
      }
    }
  }
  listarAlunos(listaAlunos, tamanhoUsado);
  free(listaAlunos);
}

void ordenarAlunoSexo(Aluno listaDeAlunos[], int tamanhoUsado, char sexo) {
  Aluno *listaAlunos = (Aluno *)malloc(tamanhoUsado * sizeof(Aluno));
  int tamanho = 0;
  for (int j = 0; j < tamanhoUsado; j++) {
    if (listaDeAlunos[j].sexo == sexo) {
      listaAlunos[tamanho] = listaDeAlunos[j];
      tamanho++;
    }
  }
  listarAlunos(listaAlunos, tamanho);
  free(listaAlunos);
}

void buscaAlunosCadastradosEmMenosDetresDisciplinas(
    Aluno alunos[], Disciplina disciplinas[], int tamanhoUsadoAluno,
    int tamanhoUsadoDisciplina) {
  Aluno *listaAlunos = (Aluno *)malloc(tamanhoUsadoAluno * sizeof(Aluno));
  int tamanho = 0;
  int i, j, k;
  for (i = 0; i < tamanhoUsadoAluno; i++) {
    int contador = 0;
    for (j = 0; j < tamanhoUsadoDisciplina; j++) {
      for (k = 0; disciplinas[j].alunos[k].matricula != -1; k++) {
        if (alunos[i].matricula == disciplinas[j].alunos[k].matricula) {
          contador++;
        }
      }
    }
    if (contador < 3) {
      listaAlunos[tamanho] = alunos[i];
      tamanho++;
    }
    contador = 0;
  }
  listarAlunos(listaAlunos, tamanho);
  free(listaAlunos);
}

void aniversariantesDoMesAluno(Aluno listaDeAlunos[], int tamanhoUsado,
                               int mes_atual) {
  Aluno *listaAlunos = (Aluno *)malloc(tamanhoUsado * sizeof(Aluno));
  int tamanho = 0;

  for (int j = 0; j < tamanhoUsado; j++) {
    if (listaDeAlunos[j].dataNascimento.mes == mes_atual) {
      listaAlunos[tamanho] = listaDeAlunos[j];
      tamanho++;
    }
  }
  listarAlunos(listaAlunos, tamanho);
  free(listaAlunos);
}