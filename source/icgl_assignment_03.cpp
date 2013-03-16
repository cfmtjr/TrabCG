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
 * A fim de presentar o funcionamento esperado para o programa, apenas o corpo dos procedimentos associados com a
 * tarefa relacionada a este arquivo deve ser modificado. Procedimentos auxiliares podem ser criados.
 *
 * Copyright (C) 2013 - A.Montenegro, L.A.F.Fernandes, M.Lage.
 */


// INCLUDES /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* - ICGL - IC-UFF Graphics Library
 * Conjunto de opera��es utilizadas para ensino de Pipeline Gr�fico no Instito de Computa��o (IC) da Universidade Federal Fluminense (UFF).
 */
#include <icgl.h>

#if defined(ICGL_ASSIGNMENT_03_PERSPECTIVE_PROJECTION)


// IN�CIO DA IMPLEMENTA��O DOS PROCEDIMENTOS ASSOCIADOS COM A TAREFA RELACIONADA A ESTE ARQUIVO /////////////////////////////

/* Atribui ao argumento de sa�da 'perspective_matrix' uma matriz de proje��o perspectiva.
 *
 *   Argumentos de entrada:
 *     'fovy'              : �ngulo do campo de vis�o da c�mera (em graus) na dire��o y.
 *     'aspect'            : Raio aspecto que determina o campo de vis�o da dire��o x. O raio aspecto � a taxa entre a
 *                           largura e altura da imagem.
 *     'znear', 'zfar'     : Dist�ncia dos planos de corte em rela��o ao observador. Esses valores s�o sempre positivos.
 *
 *   Argumentos de sa�da:
 *     'perspective_matrix': Matriz 4x4 de proje��o perspectiva.
 */
void make_perspective_matrix(float fovy, float aspect, float znear, float zfar, matrix_struct &perspective_matrix) {
    // Calcular 'perspective_matrix'.
	
	float f = 1/tan(fovy*pi/360);
	
	perspective_matrix(0,0)  = f/aspect;
	perspective_matrix(0,1)  = 0;
	perspective_matrix(0,2)  = 0;
	perspective_matrix(0,3)  = 0;
	perspective_matrix(1,0)  = 0;
	perspective_matrix(1,1)  = f;
	perspective_matrix(1,2)  = 0;
	perspective_matrix(1,3)  = 0;
	perspective_matrix(2,0)  = 0;
	perspective_matrix(2,1)  = 0;
	perspective_matrix(2,2) = (zfar+znear)/(znear-zfar);
	perspective_matrix(2,3) = (2*zfar*znear)/(znear-zfar);
	perspective_matrix(3,0) = 0;
	perspective_matrix(3,1) = 0;
	perspective_matrix(3,2) = -1;
	perspective_matrix(3,3) = 0;
}

// FIM DA IMPLEMENTA��O DOS PROCEDIMENTOS ASSOCIADOS COM A TAREFA RELACIONADA A ESTE ARQUIVO ////////////////////////////////

#endif
