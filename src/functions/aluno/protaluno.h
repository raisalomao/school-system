#include "../../struct.h"

int checkAluno(const char *cpf, Aluno listaAlunos[], int tamanhoUsado);
int buscarAluno(Aluno *alunos, int tamanho, int matricula);
void apagarAluno(Aluno *alunos, int *tamanho, int matricula);
void cadastraAluno(Aluno listaAlunos[], Professor listaProfessores[], int tamanhoUsado, int tamanhoUsadoProfessor);
int atualizarAluno(int matricula, Aluno listaAlunos[], Professor listaProfessores[], int tamanhoUsado, int tamanhoUsadoProfessor);
void listarAlunos(Aluno listaAlunos[], int tamanhoUsado);
void ordenarAlunoNome(Aluno listaDeAlunos[], int tamanhoUsado);
void ordenarAlunoData(Aluno listaDeAlunos[], int tamanhoUsado);
void ordenarAlunoSexo(Aluno listaDeAlunos[], int tamanhoUsado, char sexo);
void buscaAlunosCadastradosEmMenosDetresDisciplinas(Aluno alunos[], Disciplina disciplinas[], int tamanhoUsadoAluno, int tamanhoUsadoDisciplina);
void aniversariantesDoMesAluno(Aluno listaDeAlunos[], int tamanhoUsado, int mes_atual);