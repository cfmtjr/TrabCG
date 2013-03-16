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
#include <iostream>

#if defined(ICGL_ASSIGNMENT_04_VERTEX_TRANSFORMATION)


// INÍCIO DA IMPLEMENTAÇÃO DOS PROCEDIMENTOS ASSOCIADOS COM A TAREFA RELACIONADA A ESTE ARQUIVO /////////////////////////////

void invert(const matrix_struct &modelview_matrix,matrix_struct &matrizInvertida) 
{

	float s0 = modelview_matrix(0,0) * modelview_matrix(1,1) - modelview_matrix(1,0) * modelview_matrix(0,1);
	float s1 = modelview_matrix(0,0) * modelview_matrix(1,2) - modelview_matrix(1,0) * modelview_matrix(0,2);
	float s2 = modelview_matrix(0,0) * modelview_matrix(1,3) - modelview_matrix(1,0) * modelview_matrix(0,3);
	float s3 = modelview_matrix(0,1) * modelview_matrix(1,2) - modelview_matrix(1,1) * modelview_matrix(0,2);
	float s4 = modelview_matrix(0,1) * modelview_matrix(1,3) - modelview_matrix(1,1) * modelview_matrix(0,3);
	float s5 = modelview_matrix(0,2) * modelview_matrix(1,3) - modelview_matrix(1,2) * modelview_matrix(0,3);

	float c5 = modelview_matrix(2,2) * modelview_matrix(3,3) - modelview_matrix(3,2) * modelview_matrix(2,3);
	float c4 = modelview_matrix(2,1) * modelview_matrix(3,3) - modelview_matrix(3,1) * modelview_matrix(2,3);
	float c3 = modelview_matrix(2,1) * modelview_matrix(3,2) - modelview_matrix(3,1) * modelview_matrix(2,2);
	float c2 = modelview_matrix(2,0) * modelview_matrix(3,3) - modelview_matrix(3,0) * modelview_matrix(2,3);
	float c1 = modelview_matrix(2,0) * modelview_matrix(3,2) - modelview_matrix(3,0) * modelview_matrix(2,2);
	float c0 = modelview_matrix(2,0) * modelview_matrix(3,1) - modelview_matrix(3,0) * modelview_matrix(2,1);
    

    // Should check for 0 determinant

    float invdet  = 1 / (s0 * c5 - s1 * c4 + s2 * c3 + s3 * c2 - s4 * c1 + s5 * c0);

	matrizInvertida(0,0) = ( modelview_matrix(1,1) * c5 -  modelview_matrix(1,2) * c4 +  modelview_matrix(1,3) * c3) * invdet;
	matrizInvertida(0,1) = ( -modelview_matrix(0,1) * c5 +  modelview_matrix(0,2) * c4 -  modelview_matrix(0,3) * c3) * invdet;
	matrizInvertida(0,2) = ( modelview_matrix(3,1) * s5 -  modelview_matrix(3,2) * s4 +  modelview_matrix(3,3) * s3) * invdet;
	matrizInvertida(0,3) = ( -modelview_matrix(2,1) * s5 +  modelview_matrix(2,2) * s4 -  modelview_matrix(2,3) * s3) * invdet;

	matrizInvertida(1,0) = (- modelview_matrix(1,0) * c5 +  modelview_matrix(1,2) * c2 -  modelview_matrix(1,3) * c1) * invdet;
	matrizInvertida(1,1) = ( modelview_matrix(0,0) * c5 -  modelview_matrix(0,2) * c2 +  modelview_matrix(0,3) * c1) * invdet;
	matrizInvertida(1,2) = (- modelview_matrix(3,0) * s5 +  modelview_matrix(3,2) * s2 -  modelview_matrix(3,3) * s1) * invdet;
	matrizInvertida(1,3) = ( modelview_matrix(2,0) * s5 -  modelview_matrix(2,2) * s2 +  modelview_matrix(2,3) * s1) * invdet;
	
	matrizInvertida(2,0) = ( modelview_matrix(1,0) * c4 -  modelview_matrix(1,1) * c2 +  modelview_matrix(1,3) * c0) * invdet;
	matrizInvertida(2,1) = ( -modelview_matrix(0,0) * c4 +  modelview_matrix(0,1) * c2 -  modelview_matrix(0,3) *c0) * invdet;
	matrizInvertida(2,2) = ( modelview_matrix(3,0) * s4 -  modelview_matrix(3,1) * s2 +  modelview_matrix(3,3) * s0) * invdet;
	matrizInvertida(2,3) = ( -modelview_matrix(2,0) * s4 +  modelview_matrix(2,1) * s2 - modelview_matrix(2,3) * s0) * invdet;
   
	matrizInvertida(3,0) = ( -modelview_matrix(1,0) * c3 + modelview_matrix(1,1) * c1 -  modelview_matrix(1,2) * c0) * invdet;
	matrizInvertida(3,1) = ( modelview_matrix(0,0) * c3 -  modelview_matrix(0,1) * c1 +  modelview_matrix(0,2) * c0) * invdet;
	matrizInvertida(3,2) = ( -modelview_matrix(3,0) * s3 +  modelview_matrix(3,1) * s1 -  modelview_matrix(3,2) * s0) * invdet;
	matrizInvertida(3,3) = ( modelview_matrix(2,0) * s3 -  modelview_matrix(2,1) * s1 +  modelview_matrix(2,2) * s0) * invdet;
}

void transpose(const matrix_struct &matriz, matrix_struct &matrizTransposta){
	for(int i = 0; i < matrizTransposta.rows_count; i++)
		for(int j = 0; j < matrizTransposta.cols_count; j++)
			matrizTransposta(i,j) = matriz(j,i);
}


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
	matrix_struct inverse = matrix_struct();
	invert(modelview_matrix, inverse);
	matrix_struct transpost = matrix_struct();
	transpose(inverse, transpost);

	for(int i = 0; i < transpost.rows_count - 1; i++)
		for(int j = 0; j < normal_oc.coords_count; j++)
		unit_normal_ec[i] += normal_oc[j]*transpost(j,i);
	float normalizationFactor = sqrtf(unit_normal_ec.x*unit_normal_ec.x + unit_normal_ec.y*unit_normal_ec.y + unit_normal_ec.z*unit_normal_ec.z);
	for(int i = 0; i < unit_normal_ec.coords_count; i++)
		unit_normal_ec[i] /= normalizationFactor;

}

// FIM DA IMPLEMENTAÇÃO DOS PROCEDIMENTOS ASSOCIADOS COM A TAREFA RELACIONADA A ESTE ARQUIVO ////////////////////////////////

#endif