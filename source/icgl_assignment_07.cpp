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

#if defined(ICGL_ASSIGNMENT_07_RASTERIZATION)


// IN�CIO DA IMPLEMENTA��O DOS PROCEDIMENTOS ASSOCIADOS COM A TAREFA RELACIONADA A ESTE ARQUIVO /////////////////////////////

/* Rasteriza o segmento de reta corrente e atualiza os buffers de cor (framebuffer) e de profundidade (dephtbuffer).
 *
 *   Argumentos de entrada:
 *     'segment'                        : Segmento de reta a ser rasterizado.
 *     'viewport_x', 'viewport_y', 'viewport_width', 'viewport_height': Posi��o e tamanho da janela de visualiza��o (viewport).
 *     'texture_mapping_enabled'        : Indica se o mapeamento de textura est� habilitado.
 *     'texture_width', 'texture_height': Largura e altura da imagem de textura ('texture_rgba').
 *     'texture_rgba'                   : Imagem de textura. Cada texel � representado por quatro compnentes de cor no espa�o
 *                                        RGBA, onde cada componente pode assumir valores no intervalo [0.0f, 1.0f]. A imagem
 *                                        est� organizada por linha no buffer. Ou seja, o �ndice do coponente de cor c do
 *                                        texel de posi��o (x,y) na imagem � calculado como i = (y*texture_width + x)*4 + c.
 *     'depth_test_enabled'             : Indica se o teste de profundidade (depth test) est� habilitado.
 *     'buffer_width', 'buffer_height'  : Largura e alrura dos buffers de cor ('framebuffer') de profundidade ('depthbuffer').
 *
 *   Argumentos de sa�da:
 *     'framebuffer'                    : Imagem resultante. Cada pixel � representado por quatro compnentes de cor no espa�o
 *                                        RGBA, onde cada componente pode assumir valores no intervalo [0.0f, 1.0f]. A imagem
 *                                        est� organizada por linha no buffer. Ou seja, o �ndice do coponente de cor c do
 *                                        pixel de posi��o (x,y) na imagem � calculado como i = (y*buffer_width + x)*4 + c.
 *     'depthbuffer'                    : Imagem de profundidade resultante. Cada pixel � representado uma compnentes de
 *                                        profundidade que pode assumir valores no intervalo [0.0f, 1.0f], onde 0.0f significa
 *                                        sobre o near plane e 1.0f sobre o far plane. A imagem est� organizada por linha no
 *                                        buffer. Ou seja, o �ndice do coponente de posi��o (x,y) na imagem � calculado como
 *                                        i = y*buffer_width + x.
 */
void rasterize_segment(const segment_struct &segment, int viewport_x, int viewport_y, int viewport_width, int viewport_height, bool texture_mapping_enabled, int texture_width, int texture_height, const float *texture_rgba, bool depth_test_enabled, int buffer_width, int buffer_height, float *framebuffer, float *depthbuffer) {
    // Atualizar 'framebuffer'.
    // Atualizar 'depthbuffer'.
}

/* Rasteriza o tri�ngulo corrente e atualiza os buffers de cor (framebuffer) e de profundidade (dephtbuffer).
 *
 *   Argumentos de entrada:
 *     'triangle'                       : Tri�ngulo a ser rasterizado.
 *     'viewport_x', 'viewport_y', 'viewport_width', 'viewport_height': Posi��o e tamanho da janela de visualiza��o (viewport).
 *     'texture_mapping_enabled'        : Indica se o mapeamento de textura est� habilitado.
 *     'texture_width', 'texture_height': Largura e altura da imagem de textura ('texture_rgba').
 *     'texture_rgba'                   : Imagem de textura. Cada texel � representado por quatro compnentes de cor no espa�o
 *                                        RGBA, onde cada componente pode assumir valores no intervalo [0.0f, 1.0f]. A imagem
 *                                        est� organizada por linha no buffer. Ou seja, o �ndice do coponente de cor c do
 *                                        texel de posi��o (x,y) na imagem � calculado como i = (y*texture_width + x)*4 + c.
 *     'depth_test_enabled'             : Indica se o teste de profundidade (depth test) est� habilitado.
 *     'buffer_width', 'buffer_height'  : Largura e alrura dos buffers de cor ('framebuffer') de profundidade ('depthbuffer').
 *
 *   Argumentos de sa�da:
 *     'framebuffer'                    : Imagem resultante. Cada pixel � representado por quatro compnentes de cor no espa�o
 *                                        RGBA, onde cada componente pode assumir valores no intervalo [0.0f, 1.0f]. A imagem
 *                                        est� organizada por linha no buffer. Ou seja, o �ndice do coponente de cor c do
 *                                        pixel de posi��o (x,y) na imagem � calculado como i = (y*buffer_width + x)*4 + c.
 *     'depthbuffer'                    : Imagem de profundidade resultante. Cada pixel � representado uma compnentes de
 *                                        profundidade que pode assumir valores no intervalo [0.0f, 1.0f], onde 0.0f significa
 *                                        sobre o near plane e 1.0f sobre o far plane. A imagem est� organizada por linha no
 *                                        buffer. Ou seja, o �ndice do coponente de posi��o (x,y) na imagem � calculado como
 *                                        i = y*buffer_width + x.
 */
void rasterize_triangle(const triangle_struct &triangle, int viewport_x, int viewport_y, int viewport_width, int viewport_height, bool texture_mapping_enabled, int texture_width, int texture_height, const float *texture_rgba, bool depth_test_enabled, int buffer_width, int buffer_height, float *framebuffer, float *depthbuffer) {
    // Atualizar 'framebuffer'.
    // Atualizar 'depthbuffer'.
}

// FIM DA IMPLEMENTA��O DOS PROCEDIMENTOS ASSOCIADOS COM A TAREFA RELACIONADA A ESTE ARQUIVO ////////////////////////////////

#endif
