#include "../../struct.h"

int buscarDisciplina(Disciplina *disciplinas, int tamanho, int codigo);
void posicionaPlaceHolders(Disciplina *disciplina);
void apagarDisciplina(int codigo, Disciplina Disciplinas[], int *tamanho);
void cadastraDisciplina(Disciplina listaDisciplinas[],int tamanhoUsadoDisciplina, Professor listaProfessores[], int tamanhoUsadoProfessor);
void detalhesDiciplina(int codigoDiciplina, Disciplina listaDisciplinas[], int tamanhoUsado, Professor listaProfessores[], int tamanhoUsadoProfessores);
void insereAluno(int matricula, int codigoDiciplina, Aluno listaAlunos[], Disciplina listaDisciplinas[], int tamanhoUsadoAluno, int tamanhoUsadoDisciplina);
void listarDisciplina(Disciplina listaDisciplinas[], int tamanhoUsado, Professor listaProfessores[], int tamanhoUsadoProfessores);
void listarDisciplinasLotadas(Disciplina listaDisciplinas[], int tamanhoUsado, Professor listaProfessores[], int tamanhoUsadoProfessores);
void atualizaDisciplina(Disciplina listaDisciplinas[], int tamanhoUsadoDisciplina, int codigo, Professor listaProfessores[], int tamanhoUsadoProfessor);
void excluirAlunoDisciplina(Disciplina listaDisciplinas[], int tamanhoUsadoDisciplinas);