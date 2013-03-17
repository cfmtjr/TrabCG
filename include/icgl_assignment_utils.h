/* UNIVERSIDADE FEDERAL FLUMINENSE
 * INTITUTO DE COMPUTAÇÃO
 * DEPARTAMENTO DE CIÊNCIA DA COMPUTAÇÃO
 *
 * Este programa foi elaborado pelos professores
 *
 *   Anselmo Antunes Montenegro (anselmo@ic.uff.br),
 *   Leandro Augusto Frata Fernandes (laffernandes@ic.uff.br) e
 *   Marcos de Oliveira Lage Ferreira (mlage@ic.uff.br)
 *
 * como parte do material didático da disciplina de Computação Gráfica (TCC-00.179) do curso de
 * Bacharelado em Ciência da Computação ministrado no Instituto de Computação da Universidade Federal Fluminense.
 *
 * A fim de presentar o funcionamento esperado para o programa, apenas as definições das tarefas aceitas para serem
 * resolvidas devem ser modificadas. Isso implica em comentar ou descomentar as linhas que contém código de formato
 *
 *   #define ICGL_ASSIGNMENT_[NÚMERO]_[DESCRIÇÃO].
 *
 * Rotinas úteis podem ser definidas e declaradas no arquivo icgl_assignment_utils.cpp.
 *
 * Copyright (C) 2013 - A.Montenegro, L.A.F.Fernandes, M.Lage.
 */

#ifndef _ICGL_ASSIGNMENT_UTILS_
#define _ICGL_ASSIGNMENT_UTILS_


// DEFINIÇÃO DAS ROTINAS ÚTEIS IMPLEMENTADAS PELO ALUNO /////////////////////////////////////////////////////////////////////

/* Coloque aqui a definição de suas rotinas auxiliares.
 */
void invert(const matrix_struct &modelview_matrix,matrix_struct &matrizInvertida);
void transpose(const matrix_struct &matriz, matrix_struct &matrizTransposta);
void normalize(direction_struct& vect);
void normalize(location_struct& vect);
float dot(direction_struct vect1, direction_struct vect2);
float dot(location_struct vect1, location_struct vect2);
float maxima(float a, float b);
// FIM DA DEFINIÇÃO DAS ROTINAS ÚTEIS IMPLEMENTADAS PELO ALUNO //////////////////////////////////////////////////////////////

#endif
