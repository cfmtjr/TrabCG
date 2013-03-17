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
#include <iostream>

#if defined(ICGL_ASSIGNMENT_06_PRIMITIVE_ASSEMBLY_CLIPPING_AND_CULLING)


// IN�CIO DA IMPLEMENTA��O DOS PROCEDIMENTOS ASSOCIADOS COM A TAREFA RELACIONADA A ESTE ARQUIVO /////////////////////////////

/* Monta segmentos de reta a partir das listas de propriedades de v�rtices informadas. Esta rotina tamb�m � respons�vel por
 * realizar o recorte (clipping) das primitivas que n�o est�o completamente contidas no volume de visualiza��o (frustum).
 *
 *   Argumentos de entrada:
 *     'vertices_cc'             : Lista de localiza��o de v�rtices no sistema de coordenadas de recorte (clip coordinates, CC).
 *                                 O tamanho desta lista � sempre um m�ltiplo de dois, sendo que cada par corresponde aos
 *                                 v�rtices de um segmento de reta.
 *     'vertices_texcoords'      : Lista de coordenadas de textura dos v�rtices. Os elementos desta lista possuem rela��o
 *                                 um-para-um com os elementos de 'vertices_cc'.
 *     'vertices_texture_ids'    : Lista de identificadores de textura dos v�rtices. Os elementos desta lista possuem rela��o
 *                                 um-para-um com os elementos de 'vertices_cc'. Os dois v�rtices de um mesmo segmento de reta
 *                                 possuem o mesmo identificador de textura.
 *
 *   Argumentos de sa�da:
 *     'primitives'              : Lista de segmentos de reta completamente contidos no volume de visualiza��o.
 */
void make_segments(const std::vector<location_struct> &vertices_cc, const std::vector<color_struct> &vertices_colors, const std::vector<texcoord_struct> &vertices_texcoords, const std::vector<int> &vertices_texture_ids, std::vector<segment_struct> &primitives) {
    // Calcular 'primitives'.
	segment_struct tmp = segment_struct();
		for(int i = 0; i < vertices_cc.size(); i++){
			int aux = i%2;
			tmp.color[aux].r = vertices_colors[i].r;
			tmp.color[aux].g = vertices_colors[i].g;
			tmp.color[aux].b = vertices_colors[i].b;
			tmp.color[aux].a = vertices_colors[i].a;
			tmp.texcoord[aux].u = vertices_texcoords[i].u;
			tmp.texcoord[aux].v = vertices_texcoords[i].v;
			tmp.vertex_cc[aux].x = vertices_cc[i].x;
			tmp.vertex_cc[aux].y = vertices_cc[i].y;
			tmp.vertex_cc[aux].z = vertices_cc[i].z;
			tmp.vertex_cc[aux].w = vertices_cc[i].w;
			tmp.texture_id = vertices_texture_ids[i];
			if(aux == 1)
				primitives.push_back(tmp);
		}
}

/* Monta tri�ngulos a partir das listas de propriedades de v�rtices informadas. Esta rotina tamb�m � respons�vel por realizar
 * o recorte (clipping) das primitivas que n�o est�o completamente contidas no volume de visualiza��o (frustum) e a supress�o
 * (culling) de tri�ngulos conforme a orienta��o assumida para as faces dos modelos geom�tricos.
 *
 *   Argumentos de entrada:
 *     'vertices_cc'             : Lista de localiza��o de v�rtices no sistema de coordenadas de recorte (clip coordinates, CC).
 *                                 O tamanho desta lista � sempre um m�ltiplo de tr�s, sendo que cada trio corresponde aos
 *                                 v�rtices de um tri�ngulo.
 *     'vertices_texcoords'      : Lista de coordenadas de textura dos v�rtices. Os elementos desta lista possuem rela��o
 *                                 um-para-um com os elementos de 'vertices_cc'.
 *     'vertices_texture_ids'    : Lista de identificadores de textura dos v�rtices. Os elementos desta lista possuem rela��o
 *                                 um-para-um com os elementos de 'vertices_cc'. Os tr�s v�rtices de um mesmo tri�ngulo possuem
 *                                 o mesmo identificador de textura.
 *     'backface_culling_enabled': Indica se a supress�o de faces traseiras est� habilitada.
 *     'front_face_orientation'  : Orienta��o assumida para as faces frontais, podendo ser sentido hor�rio (clockwise,
 *                                 'cw_orientation') ou sentido anti-hor�rio (counterclockwise, 'ccw_orientation').
 *
 *   Argumentos de sa�da:
 *     'primitives'              : Lista de tri�ngulos completamente contidos no volume de visualiza��o e orientadas conforme ap
 *                                 convens�o para faces frontais, caso a supress�o de faces traseiras esteja habilitada.
 */
void make_triangles(const std::vector<location_struct> &vertices_cc, const std::vector<color_struct> &vertices_colors, const std::vector<texcoord_struct> &vertices_texcoords, const std::vector<int> &vertices_texture_ids, bool backface_culling_enabled, orientation_type front_face_orientation, std::vector<triangle_struct> &primitives) {
    // Calcular 'primitives'.
	if(backface_culling_enabled && front_face_orientation == 0){
		
	}else{
		triangle_struct tmp = triangle_struct();
		for(int i = 0; i < vertices_cc.size(); i++){
			int aux = i%3;
			tmp.color[aux].r = vertices_colors[i].r;
			tmp.color[aux].g = vertices_colors[i].g;
			tmp.color[aux].b = vertices_colors[i].b;
			tmp.color[aux].a = vertices_colors[i].a;
			tmp.texcoord[aux].u = vertices_texcoords[i].u;
			tmp.texcoord[aux].v = vertices_texcoords[i].v;
			tmp.vertex_cc[aux].x = vertices_cc[i].x;
			tmp.vertex_cc[aux].y = vertices_cc[i].y;
			tmp.vertex_cc[aux].z = vertices_cc[i].z;
			tmp.vertex_cc[aux].w = vertices_cc[i].w;
			tmp.texture_id = vertices_texture_ids[i];
			if(aux == 2)
				primitives.push_back(tmp);
		}
	}
}

// FIM DA IMPLEMENTA��O DOS PROCEDIMENTOS ASSOCIADOS COM A TAREFA RELACIONADA A ESTE ARQUIVO ////////////////////////////////

#endif
