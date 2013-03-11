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
	
	/*perspective_matrix.operator[](0)  = f/aspect;
	perspective_matrix.operator[](1)  = 0;
	perspective_matrix.operator[](2)  = 0;
	perspective_matrix.operator[](3)  = 0;
	perspective_matrix.operator[](4)  = 0;
	perspective_matrix.operator[](5)  = f;
	perspective_matrix.operator[](6)  = 0;
	perspective_matrix.operator[](7)  = 0;
	perspective_matrix.operator[](8)  = 0;
	perspective_matrix.operator[](9)  = 0;
	perspective_matrix.operator[](10) = (zfar+znear)/(znear-zfar);
	perspective_matrix.operator[](11) = (2*zfar*znear)/(znear-zfar);
	perspective_matrix.operator[](12) = 0;
	perspective_matrix.operator[](13) = 0;
	perspective_matrix.operator[](14) = -1;
	perspective_matrix.operator[](15) = 0;*/

	//perspective_matrix.operator[](0)  = f;
	//perspective_matrix.operator[](1)  = 0;
	//perspective_matrix.operator[](2)  = 0;
	//perspective_matrix.operator[](3)  = 0;
	//perspective_matrix.operator[](4)  = 0;
	//perspective_matrix.operator[](5)  = f*aspect;
	//perspective_matrix.operator[](6)  = 0;
	//perspective_matrix.operator[](7)  = 0;
	//perspective_matrix.operator[](8)  = 0;
	//perspective_matrix.operator[](9)  = 0;
	//perspective_matrix.operator[](10) = (zfar+znear)/(zfar-znear);
	//perspective_matrix.operator[](11) = -(2*zfar*znear)/(zfar-znear);
	//perspective_matrix.operator[](12) = 0;
	//perspective_matrix.operator[](13) = 0;
	//perspective_matrix.operator[](14) = 1;
	//perspective_matrix.operator[](15) = 0;

	/*perspective_matrix.operator[](0)  = f/aspect;
	perspective_matrix.operator[](1)  = 0;
	perspective_matrix.operator[](2)  = 0;
	perspective_matrix.operator[](3)  = 0;
	perspective_matrix.operator[](4)  = 0;
	perspective_matrix.operator[](5)  = f;
	perspective_matrix.operator[](6)  = 0;
	perspective_matrix.operator[](7)  = 0;
	perspective_matrix.operator[](8)  = 0;
	perspective_matrix.operator[](9)  = 0;
	perspective_matrix.operator[](10) = zfar/(zfar-znear);
	perspective_matrix.operator[](11) = -(zfar*znear)/(zfar-znear);
	perspective_matrix.operator[](12) = 0;
	perspective_matrix.operator[](13) = 0;
	perspective_matrix.operator[](14) = 1;
	perspective_matrix.operator[](15) = 0;*/


	
	float yScale = 1/tan(fovy*pi/360);
	float xScale = yScale / aspect;

	perspective_matrix.operator[](0)  = f/aspect;
	perspective_matrix.operator[](1)  = 0;
	perspective_matrix.operator[](2)  = 0;
	perspective_matrix.operator[](3)  = 0;
	perspective_matrix.operator[](4)  = 0;
	perspective_matrix.operator[](5)  = f;
	perspective_matrix.operator[](6)  = 0;
	perspective_matrix.operator[](7)  = 0;
	perspective_matrix.operator[](8)  = 0;
	perspective_matrix.operator[](9)  = 0;
	perspective_matrix.operator[](10) = zfar/(znear-zfar);
	perspective_matrix.operator[](11) = -1;
	perspective_matrix.operator[](12) = 0;
	perspective_matrix.operator[](13) = 0;
	perspective_matrix.operator[](14) = znear*zfar/(znear-zfar);
	perspective_matrix.operator[](15) = 0;

	/*float ymax = znear * tan(fovy * pi/360);
	float ymin = -ymax;
	float xmax = ymax * aspect;
	float xmin = ymin * aspect;
	float width = xmax - xmin;
	float height = ymax - ymin;
	float depth = zfar - znear;
	float q = -(zfar + znear) / depth;
	float qn = -2 * (zfar * znear) / depth;
	float w = 2 * znear / width;
	w = w / aspect;
	float h = 2 * znear / height;

	perspective_matrix.operator[](0)  = w;
	perspective_matrix.operator[](1)  = 0;
	perspective_matrix.operator[](2)  = 0;
	perspective_matrix.operator[](3)  = 0;
	perspective_matrix.operator[](4)  = 0;
	perspective_matrix.operator[](5)  = h;
	perspective_matrix.operator[](6)  = 0;
	perspective_matrix.operator[](7)  = 0;
	perspective_matrix.operator[](8)  = 0;
	perspective_matrix.operator[](9)  = 0;
	perspective_matrix.operator[](10) = q;
	perspective_matrix.operator[](11) = -1;
	perspective_matrix.operator[](12) = 0;
	perspective_matrix.operator[](13) = 0;
	perspective_matrix.operator[](14) = qn;
	perspective_matrix.operator[](15) = 0;*/

	//float fh = tan(fovy/360*pi)*znear;
	//float fw = fh * aspect;
	//perspective_matrix.operator[](0) = znear/fw; //00
	//perspective_matrix.operator[](1) = 0; //01
	//perspective_matrix.operator[](2) = 0; //02
	//perspective_matrix.operator[](3) = 0; //03
	//perspective_matrix.operator[](4) = 0; //10
	//perspective_matrix.operator[](5) = znear/fh; //11
	//perspective_matrix.operator[](6) = 0; //12
	//perspective_matrix.operator[](7) = 0; //13
	//perspective_matrix.operator[](8) = 0; //20
	//perspective_matrix.operator[](9) = 0; //21
	//perspective_matrix.operator[](10) = -(zfar+znear)/(zfar-znear); //22
	//perspective_matrix.operator[](11) = -2.0f*(zfar*znear)/(zfar-znear); //23
	//perspective_matrix.operator[](12) = 0; //30
	//perspective_matrix.operator[](13) = 0; //31
	//perspective_matrix.operator[](14) = 1; //32
	//perspective_matrix.operator[](15) = 0; //33
}

// FIM DA IMPLEMENTA��O DOS PROCEDIMENTOS ASSOCIADOS COM A TAREFA RELACIONADA A ESTE ARQUIVO ////////////////////////////////

#endif
