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
 * Procedimentos auxiliares dever ser declarados neste arquivo.
 *
 * Copyright (C) 2013 - A.Montenegro, L.A.F.Fernandes, M.Lage.
 */


// INCLUDES /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* - ICGL - IC-UFF Graphics Library
 * Conjunto de operações utilizadas para ensino de Pipeline Gráfico no Instito de Computação (IC) da Universidade Federal Fluminense (UFF).
 */
#include <icgl.h>


// DECLARAÇÃO DAS ROTINAS ÚTEIS IMPLEMENTADAS PELO ALUNO ////////////////////////////////////////////////////////////////////
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

void normalize(direction_struct& vect){
	float normalizationFactor = sqrtf(pow(vect.x,2) + pow(vect.y,2) + pow(vect.z,2));
	for(int i = 0; i < vect.coords_count; i++)
		vect[i] /= normalizationFactor;
}

void normalize(location_struct& vect){
	float normalizationFactor = sqrtf(pow(vect.x,2) + pow(vect.y,2) + pow(vect.z,2) + pow(vect.w,2));
	for(int i = 0; i < vect.coords_count; i++)
		vect[i] /= normalizationFactor;
}

float dot(direction_struct vect1, direction_struct vect2){
	return vect1.x*vect2.x + vect1.y*vect2.y + vect1.z*vect2.z;
}

float dot(location_struct vect1, location_struct vect2){
	return vect1.x*vect2.x + vect1.y*vect2.y + vect1.z*vect2.z + vect1.w*vect2.w;
}

float maxValue(float a, float b){
	return a > b ? a : b;
}

// FIM DA DECLARAÇÃO DAS ROTINAS ÚTEIS IMPLEMENTADAS PELO ALUNO /////////////////////////////////////////////////////////////
