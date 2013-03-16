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

#if defined(ICGL_ASSIGNMENT_05_VERTEX_LIGHTING)


// INÍCIO DA IMPLEMENTAÇÃO DOS PROCEDIMENTOS ASSOCIADOS COM A TAREFA RELACIONADA A ESTE ARQUIVO /////////////////////////////

/* Aplica o modelo de iluminação para o cálculo da cor do vértice corrente.
 *
 *   Argumentos de entrada:
 *     'vertex_ec'         : Localização do vértice representada no sistema de coordenadas da câmera (eye coordinates, EC).
 *     'unit_normal_ec'    : Vetor normal à superfície representado no sistema de coordenadas da câmera (EC). Assume-se que
 *                           a norma deste vetor é igual a 1.0f.
 *     'base_color'        : Cor base para o vértice. Utilizada quando a iluminação está desabilitada.
 *     'lighting_enabled'  : Indica se a iluminação está habilitada.
 *     'material_ambient'  : Cor da componente ambiente do material.
 *     'material_diffuse'  : Cor da componente difusa do material.
 *     'material_specular' : Cor da componente especular do material.
 *     'material_shininess': Expoente que define o tamanho do brilho especular do material.
 *     'light_ec'          : Localização da fonte de luz no sistema de coordenadas da câmera (EC).
 *     'light_ambient'     : Intensidade da componente ambiente da fonte de luz.
 *     'light_diffuse'     : Intensidade da componente difusa da fonte de luz.
 *     'light_specular'    : Intensidade da componente especular da fonte de luz.
 *
 *   Argumentos de saída:
 *     'vertex_color'      : Cor do vértice corrente. É igual a 'base_color' caso a iluminação esteja desabilitada ou é
 *                           calculada por meio de modelo de reflexão de Blin-Phong, caso contrário.
 */
void vertex_lighting(const location_struct &vertex_ec, const direction_struct &unit_normal_ec, const color_struct &base_color, bool lighting_enabled, const color_struct &material_ambient, const color_struct &material_diffuse, const color_struct &material_specular, float material_shininess, const location_struct &light_ec, const color_struct &light_ambient, const color_struct &light_diffuse, const color_struct &light_specular, color_struct &vertex_color) {
    if(lighting_enabled){
		float materialAmbientLength = sqrt(material_ambient.r*material_ambient.r + material_ambient.g*material_ambient.g + material_ambient.b*material_ambient.b + material_ambient.a*material_ambient.a);
		float lightAmbientLength = sqrt(light_ambient.r*light_ambient.r + light_ambient.g*light_ambient.g + light_ambient.b*light_ambient.b + light_ambient.a*light_ambient.a);
		float Ka = materialAmbientLength/lightAmbientLength;
		color_struct Ia = color_struct();
		for(int i = 0; i < Ia.channels_count; i++)
			Ia[i] = Ka * material_ambient[i];

		float materialdiffuseLength = sqrt(material_diffuse.r*material_diffuse.r + material_diffuse.g*material_diffuse.g + material_diffuse.b*material_diffuse.b + material_diffuse.a*material_diffuse.a);
		float lightdiffuseLength = sqrt(light_diffuse.r*light_diffuse.r + light_diffuse.g*light_diffuse.g + light_diffuse.b*light_diffuse.b + light_diffuse.a*light_diffuse.a);
		float Kd = materialdiffuseLength/lightdiffuseLength;

		float normalizeFactor = sqrtf(light_ec.x*light_ec.x + light_ec.y*light_ec.y + light_ec.z*light_ec.z);
		direction_struct lightDir = direction_struct(-light_ec.x, -light_ec.y, -light_ec.z);
		for(int i = 0; i < lightDir.coords_count; i++)
			lightDir[i] /= normalizeFactor;
		float aux = lightDir.x*unit_normal_ec.x + lightDir.y*unit_normal_ec.y + lightDir.z*unit_normal_ec.z;
		float ldotn = aux > 0 ? aux : 0;
		color_struct Id = color_struct();
		for(int i = 0; i < Id.channels_count; i++)	
			Id[i] = Kd * material_diffuse[i] * ldotn;

		float materialspecularLength = sqrt(material_specular.r*material_specular.r + material_specular.g*material_specular.g + material_specular.b*material_specular.b + material_specular.a*material_specular.a);
		float lightspecularLength = sqrt(light_specular.r*light_specular.r + light_specular.g*light_specular.g + light_specular.b*light_specular.b + light_specular.a*light_specular.a);
		float Ks = materialspecularLength/lightspecularLength;
		normalizeFactor = sqrtf(vertex_ec.x*vertex_ec.x + vertex_ec.y*vertex_ec.y + vertex_ec.z*vertex_ec.z);		
		direction_struct eyeDir = direction_struct(vertex_ec.x, vertex_ec.y, vertex_ec.z);
		for(int i = 0; i < eyeDir.coords_count; i++)
			eyeDir[i] /= normalizeFactor;
		direction_struct eplusl = direction_struct(eyeDir.x + lightDir.x, eyeDir.y + lightDir.y, eyeDir.z + lightDir.z);
		normalizeFactor = sqrt(eplusl.x*eplusl.x + eplusl.y*eplusl.y + eplusl.z*eplusl.z);
		direction_struct half = direction_struct(-eplusl.x, -eplusl.y, -eplusl.z);
		aux = half.x*unit_normal_ec.x + half.y*unit_normal_ec.y + half.z*unit_normal_ec.z;
		float hdotn = aux > 0 ? aux : 0;
		color_struct Is = color_struct();
		for(int i = 0; i < Is.channels_count; i++)
			Is[i] = Ks * material_specular[i] * pow(hdotn, material_shininess);
		
		vertex_color = color_struct(Ia[0] + Id[0] + Is[0], Ia[1] + Id[1] + Is[1], Ia[2] + Id[2] + Is[2], 1.0f);
	}else
		vertex_color = base_color;

}

// FIM DA IMPLEMENTAÇÃO DOS PROCEDIMENTOS ASSOCIADOS COM A TAREFA RELACIONADA A ESTE ARQUIVO ////////////////////////////////

#endif
