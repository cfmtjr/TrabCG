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

#if defined(ICGL_ASSIGNMENT_02_LOOK_AT)


// INÍCIO DA IMPLEMENTAÇÃO DOS PROCEDIMENTOS ASSOCIADOS COM A TAREFA RELACIONADA A ESTE ARQUIVO /////////////////////////////

/* Atribui ao argumento de saída 'lookat_matrix' uma matriz de visualização a partir de um visualizador em um ponto (eye), um
 * ponto de referência indicando um alvo na cena (center) e um vetor indicando a direção assumida para cima (up).
 *
 *   Argumentos de entrada:
 *     'eyex', 'eyey', 'eyez'         : Coordenadas x, y e z do ponto onde está localizado o centro de projeção da câmera.
 *     'centerx', 'centery', 'centerz': Coordenadas x, y e z do ponto de referência indicando um alvo na cena.
 *     'upx', 'upy', 'upz'            : Coordenadas x, y e z do vetor que indica a direção assumida como sendo para cima.
 *
 *   Argumentos de saída:
 *     'lookat_matrix'                : Matriz 4x4 de visualização.
 */
void make_lookat_matrix(float eyex, float eyey, float eyez, float centerx, float centery, float centerz, float upx, float upy, float upz, matrix_struct &lookat_matrix) {
    // Calcular 'lookat_matrix'.
	float axisz_x = -(centerx - eyex);
	float axisz_y = -(centery - eyey);
	float axisz_z = -(centerz - eyez);
	float normalizationFactor;
	normalizationFactor = sqrtf(axisz_x*axisz_x + axisz_y*axisz_y + axisz_z*axisz_z);
	axisz_x /= normalizationFactor;
	axisz_y /= normalizationFactor;
	axisz_z /= normalizationFactor;
	
	float axisx_x = upy*axisz_z - upz*axisz_y;
	float axisx_y = upz*axisz_x - upx*axisz_z;
	float axisx_z = upx*axisz_y - upy*axisz_x;
	normalizationFactor = sqrtf(axisx_x*axisx_x + axisx_y*axisx_y + axisx_z*axisx_z);
	axisx_x /= normalizationFactor;
	axisx_y /= normalizationFactor;
	axisx_z /= normalizationFactor;
	
	float axisy_x = axisz_y*axisx_z - axisz_z*axisx_y;
	float axisy_y = axisz_z*axisx_x - axisz_x*axisx_z;
	float axisy_z = axisz_x*axisx_y - axisz_y*axisx_x;
	normalizationFactor = sqrtf(axisy_x*axisy_x + axisy_y*axisy_y + axisy_z*axisy_z);
	axisy_x /= normalizationFactor;
	axisy_y /= normalizationFactor;
	axisy_z /= normalizationFactor;

	lookat_matrix.operator[](0) = axisx_x;
	lookat_matrix.operator[](1) = axisy_x;
	lookat_matrix.operator[](2) = axisz_x;
	lookat_matrix.operator[](3) = 0;
	lookat_matrix.operator[](4) = axisx_y;
	lookat_matrix.operator[](5) = axisy_y;
	lookat_matrix.operator[](6) = axisz_y;
	lookat_matrix.operator[](7) = 0;
	lookat_matrix.operator[](8) = axisx_z;
	lookat_matrix.operator[](9) = axisy_z;
	lookat_matrix.operator[](10) = axisz_z;	
	lookat_matrix.operator[](11) = 0;
	lookat_matrix.operator[](12) = (-eyex*axisx_x) + (-eyey*axisx_y) + (-eyez*axisx_z);
	lookat_matrix.operator[](13) = (-eyex*axisy_x) + (-eyey*axisy_y) + (-eyez*axisy_z);
	lookat_matrix.operator[](14) = (-eyex*axisz_x) + (-eyey*axisz_y) + (-eyez*axisz_z);
	lookat_matrix.operator[](15) = 1;

	//lookat_matrix.operator[](0) = axisx_x;
	//lookat_matrix.operator[](1) = axisx_y;
	//lookat_matrix.operator[](2) = axisx_z;
	//lookat_matrix.operator[](3) = (-eyex*axisx_x) + (-eyey*axisx_y) + (-eyez*axisx_z);
	//lookat_matrix.operator[](4) = axisy_x;
	//lookat_matrix.operator[](5) = axisy_y;
	//lookat_matrix.operator[](6) = axisy_z;
	//lookat_matrix.operator[](7) = (-eyex*axisy_x) + (-eyey*axisy_y) + (-eyez*axisy_z);
	//lookat_matrix.operator[](8) = axisz_x;
	//lookat_matrix.operator[](9) = axisz_y;
	//lookat_matrix.operator[](10) = axisz_z;	
	//lookat_matrix.operator[](11) = (-eyex*axisz_x) + (-eyey*axisz_y) + (-eyez*axisz_z);
	//lookat_matrix.operator[](12) = 0;
	//lookat_matrix.operator[](13) = 0;
	//lookat_matrix.operator[](14) = 0;
	//lookat_matrix.operator[](15) = 1;
}

// FIM DA IMPLEMENTAÇÃO DOS PROCEDIMENTOS ASSOCIADOS COM A TAREFA RELACIONADA A ESTE ARQUIVO ////////////////////////////////

#endif
