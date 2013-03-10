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

#if defined(ICGL_ASSIGNMENT_01_ROTATION_SCALE_TRANSLATION)


// IN�CIO DA IMPLEMENTA��O DOS PROCEDIMENTOS ASSOCIADOS COM A TAREFA RELACIONADA A ESTE ARQUIVO /////////////////////////////

/* Atribui ao argumento de sa�da 'rotation_matrix' uma matriz de rota��o que rota��o.
 *
 *   Argumentos de entrada:
 *     'angle_degrees'          : �ngulo de rota��o (em graus).
 *     'axisx', 'axisy', 'axisz': Coordenadas do eixo de rota��o em 3D. A normaliza��o do eixo informado n�o � garantida.
 *
 *   Argumentos de sa�da:
 *     'rotation_matrix'        : Matriz 4x4 que codifica a rota��o de 'angle_degrees' graus ao redor do eixo
 *                                ('axisx', 'axisy', 'axisz').
 */
void make_rotation_matrix(float angle_degrees, float axisx, float axisy, float axisz, matrix_struct &rotation_matrix) {
    // Calcular 'rotation_matrix'.
}

/* Atribui ao argumento de sa�da 'scale_matrix' uma matriz de escala.
 *
 *   Argumentos de entrada:
 *     'scalex', 'scaley', 'scalez': Escala, respectivamente, nos eixos x, y e z do espa�o.
 *
 *   Argumentos de sa�da:
 *     'scale_matrix'              : Matriz 4x4 que codifica a escala n�o uniforme pretendida.
 */
void make_scale_matrix(float scalex, float scaley, float scalez, matrix_struct &scale_matrix) {
    // Calcular 'scale_matrix'.
}

/* Atribui ao argumento de sa�da 'translation_matrix' uma matriz de transla��o.
 *
 *   Argumentos de entrada:
 *     'deltax', 'deltay', 'deltaz': Deslocamento, respectivamente, nos eixos x, y e z do espa�o.
 *
 *   Argumentos de sa�da:
 *     'translation_matrix'         : Matriz 4x4 que codifica a transla��o pretendida.
 */
void make_translation_matrix(float deltax, float deltay, float deltaz, matrix_struct &translation_matrix) {
    // Calcular 'translation_matrix'.
}

// FIM DA IMPLEMENTA��O DOS PROCEDIMENTOS ASSOCIADOS COM A TAREFA RELACIONADA A ESTE ARQUIVO ////////////////////////////////

#endif
