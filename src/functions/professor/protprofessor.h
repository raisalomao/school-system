#include "../../struct.h"

int buscarProfessor(Professor *professores, int tamanho, int matricula);
void apagarProfessor(Professor *professores, int *tamanho, int matricula);
int atualizarProfessor(int matricula, Professor listaProfessores[], Aluno listaAlunos[], int tamanhoUsado, int tamanhoUsadoAluno);
int checkProfessor(const char *cpf, Professor listaProfessores[], int tamanhoUsado);
void cadastraProfessor(Professor listaProfessores[], Aluno listaAlunos[], int tamanhoUsadoProfessor, int tamanhoUsadoAluno);
void listarProfessor(Professor listaProfessores[], int tamanhoUsado);
void ordenarProfNome(Professor listaDeProfessores[], int tamanhoUsado);
void ordenarProfData(Professor listaDeProfessores[], int tamanhoUsado);
void ordenarProfSexo(Professor listaDeProfessores[], int tamanhoUsado, char sexo);
void aniversariantesDoMesProfessor(Professor listaDeProfessores[], int tamanhoUsado, int mes_atual);