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

#if defined(ICGL_ASSIGNMENT_04_VERTEX_TRANSFORMATION)


// INÍCIO DA IMPLEMENTAÇÃO DOS PROCEDIMENTOS ASSOCIADOS COM A TAREFA RELACIONADA A ESTE ARQUIVO /////////////////////////////

/* Aplica transformações geométrica à localização do vértice corrente e ao vetor normal associado a ele.
 *
 *   Argumentos de entrada:
 *     'vertex_oc'        : Localização do vértice representada no sistema de coordenadas do objeto (object coordinates, OC).
 *     'normal_oc'        : Vetor normal à superfície representada no sistema de coordenadas do objeto (OC).
 *     'modelview_matrix' : Matriz 4x4 composta pelas transformações de modelo e visualização (view_matrix * model_matrix).
 *     'projection_matrix': Matriz 4x4 de projeção.
 *
 *   Argumentos de saída:
 *     'vertex_ec'        : Localização do vértice representada no sistema de coordenadas da câmera (eye coordinates, EC).
 *     'vertex_cc'        : Localização do vértice representada no sistema coordenadas de recorte (clip coordinates, CC).
 *     'unit_normal_ec'   : Vetor normal à superfície representado no sistema de coordenadas da câmera (EC). Assume-se que
 *                          a norma deste vetor é igual a 1.0f.
 */
void vertex_transformation(const location_struct &vertex_oc, const direction_struct &normal_oc, const matrix_struct &modelview_matrix, const matrix_struct &projection_matrix, location_struct &vertex_ec, location_struct &vertex_cc, direction_struct &unit_normal_ec) {
    // Calcular 'vertex_ec'.
	for(int i = 0; i < vertex_ec.coords_count; i++)
		vertex_ec[i] = vertex_oc.x * modelview_matrix(i,0) + vertex_oc.y * modelview_matrix(i,1) + vertex_oc.z * modelview_matrix(i,2) + vertex_oc.w * modelview_matrix(i,3);
    // Calcular 'vertex_cc'.	
	for(int i = 0; i < vertex_cc.coords_count; i++)
		vertex_cc[i] = vertex_ec.x * projection_matrix(i,0) + vertex_ec.y * projection_matrix(i,1) + vertex_ec.z * projection_matrix(i,2) + vertex_ec.w * projection_matrix(i,3);
    // Calcular 'unit_normal_ec'.
	//float inverseW = 1/vertex_cc.w;
	//for(int i = 0; i < unit_normal_ec.coords_count; i++)
	//	unit_normal_ec[i] = vertex_cc[i] * inverseW;
	matrix_struct inverse = matrix_struct(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
	invert(modelview_matrix, inverse);
	matrix_struct transpost = matrix_struct(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
	transpose(inverse, transpost);
	unit_normal_ec = direction_struct(0,0,0);
	for(int i = 0; i < transpost.rows_count - 1; i++)
		for(int j = 0; j < normal_oc.coords_count; j++)
			unit_normal_ec[i] += normal_oc[j]*transpost(j,i);
	normalize(unit_normal_ec);
}

// FIM DA IMPLEMENTAÇÃO DOS PROCEDIMENTOS ASSOCIADOS COM A TAREFA RELACIONADA A ESTE ARQUIVO ////////////////////////////////

#endif