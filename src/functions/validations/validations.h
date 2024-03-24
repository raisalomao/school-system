#include "../../struct.h"
#include <stdbool.h>

void flush_in();
bool CheckCPF(char cpf[]);
char *dataParaString(Data data);
bool CheckDate(Data data);
Data stringParaData(char *date_str);
bool verificaIdade(Data data, int idade);
int checkCadastroAluno(const char *cpf, Aluno listaAlunos[], int tamanhoUsado);
int checkCadastroProfessor(const char *cpf, Professor listaProfessores[], int tamanhoUsado);
void buscarPessoas(Professor Professores[], Aluno Alunos[], int tamanhoProfessor, int tamanhoAluno, char busca[]);
bool CheckSexo(char sexo);
bool VerificaIdade(char dataNascimento[], int informeIdade);