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
 * A fim de presentar o funcionamento esperado para o programa, apenas o corpo dos procedimentos associados com a
 * tarefa relacionada a este arquivo deve ser modificado. Procedimentos auxiliares podem ser criados.
 *
 * Copyright (C) 2013 - A.Montenegro, L.A.F.Fernandes, M.Lage.
 */


// INCLUDES /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* - ICGL - IC-UFF Graphics Library
 * Conjunto de operações utilizadas para ensino de Pipeline Gráfico no Instito de Computação (IC) da Universidade Federal Fluminense (UFF).
 */
#include <icgl.h>

#if defined(ICGL_ASSIGNMENT_01_ROTATION_SCALE_TRANSLATION)


// INÍCIO DA IMPLEMENTAÇÃO DOS PROCEDIMENTOS ASSOCIADOS COM A TAREFA RELACIONADA A ESTE ARQUIVO /////////////////////////////

/* Atribui ao argumento de saída 'rotation_matrix' uma matriz de rotação que rotação.
 *
 *   Argumentos de entrada:
 *     'angle_degrees'          : Ângulo de rotação (em graus).
 *     'axisx', 'axisy', 'axisz': Coordenadas do eixo de rotação em 3D. A normalização do eixo informado não é garantida.
 *
 *   Argumentos de saída:
 *     'rotation_matrix'        : Matriz 4x4 que codifica a rotação de 'angle_degrees' graus ao redor do eixo
 *                                ('axisx', 'axisy', 'axisz').
 */
void make_rotation_matrix(float angle_degrees, float axisx, float axisy, float axisz, matrix_struct &rotation_matrix) {
    // Calcular 'rotation_matrix'.

	float normalizationFactor = sqrtf(axisx*axisx + axisy*axisy + axisz*axisz);
	axisx /= normalizationFactor;
	axisy /= normalizationFactor;
	axisz /= normalizationFactor;
	float angle_radians = -(angle_degrees * pi/180.0);
	float c = cosf(angle_radians);
	float s = sinf(angle_radians);
	float t = 1 - c;

	rotation_matrix.operator[](0) = axisx*axisx*t + c;
	rotation_matrix.operator[](1) = axisx*axisy*t - axisz*s;
	rotation_matrix.operator[](2) = axisx*axisz*t + axisy*s;
	rotation_matrix.operator[](3) = 0;
	rotation_matrix.operator[](4) = axisx*axisy*t + axisz*s;
	rotation_matrix.operator[](5) = axisy*axisy*t + c;
	rotation_matrix.operator[](6) = axisy*axisz*t - axisx*s;
	rotation_matrix.operator[](7) = 0;
	rotation_matrix.operator[](8) = axisx*axisz*t - axisy*s;
	rotation_matrix.operator[](9) = axisy*axisz*t + axisx*s;
	rotation_matrix.operator[](10) = axisz*axisz*t + c;
	rotation_matrix.operator[](11) = 0;
	rotation_matrix.operator[](12) = 0;
	rotation_matrix.operator[](13) = 0;
	rotation_matrix.operator[](14) = 0;
	rotation_matrix.operator[](15) = 1;
}

/* Atribui ao argumento de saída 'scale_matrix' uma matriz de escala.
 *
 *   Argumentos de entrada:
 *     'scalex', 'scaley', 'scalez': Escala, respectivamente, nos eixos x, y e z do espaço.
 *
 *   Argumentos de saída:
 *     'scale_matrix'              : Matriz 4x4 que codifica a escala não uniforme pretendida.
 */
void make_scale_matrix(float scalex, float scaley, float scalez, matrix_struct &scale_matrix) {
    // Calcular 'scale_matrix'.
	scale_matrix.operator[](0) = scalex;
	scale_matrix.operator[](1) = 0;
	scale_matrix.operator[](2) = 0;
	scale_matrix.operator[](3) = 0;
	scale_matrix.operator[](4) = 0;
	scale_matrix.operator[](5) = scaley;
	scale_matrix.operator[](6) = 0;
	scale_matrix.operator[](7) = 0;
	scale_matrix.operator[](8) = 0;
	scale_matrix.operator[](9) = 0;
	scale_matrix.operator[](10) = scalez;
	scale_matrix.operator[](11) = 0;
	scale_matrix.operator[](12) = 0;
	scale_matrix.operator[](13) = 0;
	scale_matrix.operator[](14) = 0;
	scale_matrix.operator[](15) = 1;
}

/* Atribui ao argumento de saída 'translation_matrix' uma matriz de translação.
 *
 *   Argumentos de entrada:
 *     'deltax', 'deltay', 'deltaz': Deslocamento, respectivamente, nos eixos x, y e z do espaço.
 *
 *   Argumentos de saída:
 *     'translation_matrix'         : Matriz 4x4 que codifica a translação pretendida.
 */
void make_translation_matrix(float deltax, float deltay, float deltaz, matrix_struct &translation_matrix) {
    // Calcular 'translation_matrix'.
	translation_matrix.operator[](0) = 1;
	translation_matrix.operator[](1) = 0;
	translation_matrix.operator[](2) = 0;
	translation_matrix.operator[](3) = 0;
	translation_matrix.operator[](4) = 0;
	translation_matrix.operator[](5) = 1;
	translation_matrix.operator[](6) = 0;
	translation_matrix.operator[](7) = 0;
	translation_matrix.operator[](8) = 0;
	translation_matrix.operator[](9) = 0;
	translation_matrix.operator[](10) = 1;
	translation_matrix.operator[](11) = 0;
	translation_matrix.operator[](12) = deltax;
	translation_matrix.operator[](13) = deltay;
	translation_matrix.operator[](14) = deltaz;
	translation_matrix.operator[](15) = 1;
}

// FIM DA IMPLEMENTAÇÃO DOS PROCEDIMENTOS ASSOCIADOS COM A TAREFA RELACIONADA A ESTE ARQUIVO ////////////////////////////////

#endif
