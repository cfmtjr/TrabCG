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

#if defined(ICGL_ASSIGNMENT_06_PRIMITIVE_ASSEMBLY_CLIPPING_AND_CULLING)


// INÍCIO DA IMPLEMENTAÇÃO DOS PROCEDIMENTOS ASSOCIADOS COM A TAREFA RELACIONADA A ESTE ARQUIVO /////////////////////////////

/* Monta segmentos de reta a partir das listas de propriedades de vértices informadas. Esta rotina também é responsável por
 * realizar o recorte (clipping) das primitivas que não estão completamente contidas no volume de visualização (frustum).
 *
 *   Argumentos de entrada:
 *     'vertices_cc'             : Lista de localização de vértices no sistema de coordenadas de recorte (clip coordinates, CC).
 *                                 O tamanho desta lista é sempre um múltiplo de dois, sendo que cada par corresponde aos
 *                                 vértices de um segmento de reta.
 *     'vertices_texcoords'      : Lista de coordenadas de textura dos vértices. Os elementos desta lista possuem relação
 *                                 um-para-um com os elementos de 'vertices_cc'.
 *     'vertices_texture_ids'    : Lista de identificadores de textura dos vértices. Os elementos desta lista possuem relação
 *                                 um-para-um com os elementos de 'vertices_cc'. Os dois vértices de um mesmo segmento de reta
 *                                 possuem o mesmo identificador de textura.
 *
 *   Argumentos de saída:
 *     'primitives'              : Lista de segmentos de reta completamente contidos no volume de visualização.
 */
void make_segments(const std::vector<location_struct> &vertices_cc, const std::vector<color_struct> &vertices_colors, const std::vector<texcoord_struct> &vertices_texcoords, const std::vector<int> &vertices_texture_ids, std::vector<segment_struct> &primitives) {
    // Calcular 'primitives'.
	bool pertence = true;
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
			if(!((vertices_cc[i].x > -vertices_cc[i].w && vertices_cc[i].x < vertices_cc[i].w)
					&& (vertices_cc[i].y > -vertices_cc[i].w && vertices_cc[i].y < vertices_cc[i].w)
					&& (vertices_cc[i].z > -vertices_cc[i].w && vertices_cc[i].z < vertices_cc[i].w))
					&& pertence)
				pertence = false;
			if(aux == 1){
				if(pertence){
					primitives.push_back(tmp);
				} else{
					pertence = true;
				}
			}

		}
}

/* Monta triângulos a partir das listas de propriedades de vértices informadas. Esta rotina também é responsável por realizar
 * o recorte (clipping) das primitivas que não estão completamente contidas no volume de visualização (frustum) e a supressão
 * (culling) de triângulos conforme a orientação assumida para as faces dos modelos geométricos.
 *
 *   Argumentos de entrada:
 *     'vertices_cc'             : Lista de localização de vértices no sistema de coordenadas de recorte (clip coordinates, CC).
 *                                 O tamanho desta lista é sempre um múltiplo de três, sendo que cada trio corresponde aos
 *                                 vértices de um triângulo.
 *     'vertices_texcoords'      : Lista de coordenadas de textura dos vértices. Os elementos desta lista possuem relação
 *                                 um-para-um com os elementos de 'vertices_cc'.
 *     'vertices_texture_ids'    : Lista de identificadores de textura dos vértices. Os elementos desta lista possuem relação
 *                                 um-para-um com os elementos de 'vertices_cc'. Os três vértices de um mesmo triângulo possuem
 *                                 o mesmo identificador de textura.
 *     'backface_culling_enabled': Indica se a supressão de faces traseiras está habilitada.
 *     'front_face_orientation'  : Orientação assumida para as faces frontais, podendo ser sentido horário (clockwise,
 *                                 'cw_orientation') ou sentido anti-horário (counterclockwise, 'ccw_orientation').
 *
 *   Argumentos de saída:
 *     'primitives'              : Lista de triângulos completamente contidos no volume de visualização e orientadas conforme ap
 *                                 convensão para faces frontais, caso a supressão de faces traseiras esteja habilitada.
 */
void make_triangles(const std::vector<location_struct> &vertices_cc, const std::vector<color_struct> &vertices_colors, const std::vector<texcoord_struct> &vertices_texcoords, const std::vector<int> &vertices_texture_ids, bool backface_culling_enabled, orientation_type front_face_orientation, std::vector<triangle_struct> &primitives) {
    // Calcular 'primitives'.
	bool pertence = true;
	std::vector<triangle_struct> result;
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
		if(!((vertices_cc[i].x > -vertices_cc[i].w && vertices_cc[i].x < vertices_cc[i].w)
			&& (vertices_cc[i].y > -vertices_cc[i].w && vertices_cc[i].y < vertices_cc[i].w)
			&& (vertices_cc[i].z > -vertices_cc[i].w && vertices_cc[i].z < vertices_cc[i].w))
			&& pertence)
			pertence = false;
		if(aux == 2)
			if(pertence){
				result.push_back(tmp);
			}else
				pertence = true;
	}
	if(backface_culling_enabled){
		direction_struct normal, left, right;
		if(front_face_orientation == 0){
			for(int i = 0; i < result.size(); i++){
				left = direction_struct(result[i].vertex_cc[1].x - result[i].vertex_cc[0].x, result[i].vertex_cc[1].y - result[i].vertex_cc[0].y, result[i].vertex_cc[1].z - result[i].vertex_cc[0].z);
				right = direction_struct(result[i].vertex_cc[2].x - result[i].vertex_cc[0].x, result[i].vertex_cc[2].y - result[i].vertex_cc[0].y, result[i].vertex_cc[2].z - result[i].vertex_cc[0].z);
				normal = direction_struct(left.y*right.z - left.z*right.y, left.z*right.x - left.x*right.z, left.x*right.y - left.y*right.x);
				float angle = dot(normal, direction_struct(result[i].vertex_cc[0].x, result[i].vertex_cc[0].y, result[i].vertex_cc[0].z));
				if(angle < 0)
					primitives.push_back(result[i]);
			}
		}else{
			for(int i = 0; i < result.size(); i++){
				left = direction_struct(result[i].vertex_cc[1].x - result[i].vertex_cc[0].x, result[i].vertex_cc[1].y - result[i].vertex_cc[0].y, result[i].vertex_cc[1].z - result[i].vertex_cc[0].z);
				right = direction_struct(result[i].vertex_cc[2].x - result[i].vertex_cc[0].x, result[i].vertex_cc[2].y - result[i].vertex_cc[0].y, result[i].vertex_cc[2].z - result[i].vertex_cc[0].z);
				normal = direction_struct(left.y*right.z - left.z*right.y, left.z*right.x - left.x*right.z, left.x*right.y - left.y*right.x);
				float angle = dot(normal, direction_struct(result[i].vertex_cc[0].x, result[i].vertex_cc[0].y, result[i].vertex_cc[0].z));
				if(angle > 0)
					primitives.push_back(result[i]);
			}
		}
	}else
		for(int i = 0; i < result.size(); i++)
			primitives.push_back(result[i]);
}

// FIM DA IMPLEMENTAÇÃO DOS PROCEDIMENTOS ASSOCIADOS COM A TAREFA RELACIONADA A ESTE ARQUIVO ////////////////////////////////

#endif
