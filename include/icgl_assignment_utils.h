/* UNIVERSIDADE FEDERAL FLUMINENSE
 * INTITUTO DE COMPUTA��O
 * DEPARTAMENTO DE CI�NCIA DA COMPUTA��O
 *
 * Este programa foi elaborado pelos professores
 *
 *   Anselmo Antunes Montenegro (anselmo@ic.uff.br),
 *   Leandro Augusto Frata Fernandes (laffernandes@ic.uff.br) e
 *   Marcos de Oliveira Lage Ferreira (mlage@ic.uff.br)
 *
 * como parte do material did�tico da disciplina de Computa��o Gr�fica (TCC-00.179) do curso de
 * Bacharelado em Ci�ncia da Computa��o ministrado no Instituto de Computa��o da Universidade Federal Fluminense.
 *
 * A fim de presentar o funcionamento esperado para o programa, apenas as defini��es das tarefas aceitas para serem
 * resolvidas devem ser modificadas. Isso implica em comentar ou descomentar as linhas que cont�m c�digo de formato
 *
 *   #define ICGL_ASSIGNMENT_[N�MERO]_[DESCRI��O].
 *
 * Rotinas �teis podem ser definidas e declaradas no arquivo icgl_assignment_utils.cpp.
 *
 * Copyright (C) 2013 - A.Montenegro, L.A.F.Fernandes, M.Lage.
 */

#ifndef _ICGL_ASSIGNMENT_UTILS_
#define _ICGL_ASSIGNMENT_UTILS_


// DEFINI��O DAS ROTINAS �TEIS IMPLEMENTADAS PELO ALUNO /////////////////////////////////////////////////////////////////////

/* Coloque aqui a defini��o de suas rotinas auxiliares.
 */
void invert(const matrix_struct &modelview_matrix,matrix_struct &matrizInvertida);
void transpose(const matrix_struct &matriz, matrix_struct &matrizTransposta);
void normalize(direction_struct& vect);
void normalize(location_struct& vect);
float dot(direction_struct vect1, direction_struct vect2);
float dot(location_struct vect1, location_struct vect2);
float maxima(float a, float b);
// FIM DA DEFINI��O DAS ROTINAS �TEIS IMPLEMENTADAS PELO ALUNO //////////////////////////////////////////////////////////////

#endif
