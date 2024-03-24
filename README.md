# Projetando um Sistema Escolar em Linguagem C

O projeto é baseado em CRUD (Create, Read, Update, Delete), uma forma de manter o cadastro de alunos, professores e disciplinas. O desenvolvimento bruto está nas funções de listagens de cada um desses parâmetros, utiliza-se separação de códigos em diferentes arquivos para maior manutenção do sistema, além de fazer uso da estrutura struct.
Este é um sistema proposto pelo Instituto Federal da Bahia (IFBA) no curso de Análise e Desenvolvimento de Sistemas na matéria de Laboratório de Programação. É um desenvolvimento feito em trios em foco em aprimorar técnicas de modularização, o que envolve a reutilização de blocos de código.

![Apresentação do Sistema](https://imgur.com/nqHAyZY.gif)

```c
#define tamMaximo 100

#ifndef DATA_STRUCT
#define DATA_STRUCT
typedef struct {
  int dia, mes, ano;
} Data;
#endif

#ifndef PROFESSOR_STRUCT
#define PROFESSOR_STRUCT
typedef struct Professor {
  char nome[50];
  int idade, matricula;;
  char cpf[12], sexo;
  Data dataNascimento;
} Professor;
#endif

#ifndef ALUNO_STRUCT
#define ALUNO_STRUCT
typedef struct {
  char nome[50];
  int idade, matricula;
  char cpf[12], sexo;
  Data dataNascimento;
} Aluno;
#endif

#ifndef DISCIPLINA_STRUCT
#define DISCIPLINA_STRUCT
typedef struct {
  char nome[50];
  int codigo, semestre;
  int matriculaProfessor;
  Aluno alunos[tamMaximo];
} Disciplina;
#endif
```

O formato padrão de resposta é sempre no console, planeja-se como implementação futura o armazenamento de dados em JSON ou em um banco de dados, a variar da escalabilidade do sistema. Tornando o sistema mais viável para as instituições.

