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