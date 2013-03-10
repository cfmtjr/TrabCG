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
 * A fim de presentar o funcionamento esperado para o programa, este arquivo n�o deve ser modificado.
 *
 * Copyright (C) 2013 - A.Montenegro, L.A.F.Fernandes, M.Lage.
 */

#ifndef _ICGL_HEADER_
#define _ICGL_HEADER_


// INCLUDES /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* - STL - Standard Template Library
 * API padr�o que estabelece padr�es e estruturas de dados para aplica��es C++.
 * Geralmente disponibilizada com o sistema operacional ou plataforma de desenvolvimento.
 */
#include <cmath>
#include <string>
#include <vector>


// ROTINAS �TEIS DEFINIDAS PELO ALUNO ///////////////////////////////////////////////////////////////////////////////////////

/* - ICGL - IC-UFF Graphics Library
 * Defini��o das tarefas aceitas pelo aluno.
 */
#include <icgl_assignment.h>


// CONSTANTES �TEIS /////////////////////////////////////////////////////////////////////////////////////////////////////////

// Constante pi.
static const float pi = 3.1415926535897932384626433832795028841971693993751f;


// DECLARA��O DAS ESTRUTURAS UTILIZADAS PARA REPRESENTA��O DOS DADOS ////////////////////////////////////////////////////////

/* Tipo que define as duas orienta��es poss�veis no plano.
 */
enum orientation_type {
    cw_orientation = 0, // Clockwise
    ccw_orientation = 1 // Counterclockwise
};

/* Classe que representa uma cor no sistema de cores RGBA.
 */
class color_struct {
public:

    // N�mero de canais da cor.
    static const size_t channels_count = 4;

    // Apelido dado aos canais de cor.
    float &r, &g, &b, &a;

public:

    // Construtor padr�o da classe.
    color_struct();

    // Construtor de inicializa��o.
    color_struct(float r, float g, float b, float a);

    // Construtor de c�pia da classe.
    color_struct(const color_struct &other);

    // Retorna o ponteiro para os dados.
    float* data();

    // Retorna o ponteiro para os dados.
    const float* data() const;

    // Operador de atribui��o.
    color_struct& operator = (const color_struct &other);

    // Operador de acesso indexado aos canais de cor.
    float& operator [] (size_t i);

    // Operador de acesso indexado aos canais de cor.
    const float& operator [] (size_t i) const;

private:

    // Canais de cor.
    float m_channels[channels_count];
};

/* Classe que representa uma dire��o.
 */
class direction_struct {
public:

    // N�mero de coordenadas da dire��o.
    static const size_t coords_count = 3;

    // Apelido dado �s coordenadas da dire��o.
    float &x, &y, &z;

public:

    // Construtor padr�o da classe.
    direction_struct();

    // Construtor de inicializa��o.
    direction_struct(float x, float y, float z);

    // Construtor de c�pia da classe.
    direction_struct(const direction_struct &other);

    // Retorna o ponteiro para os dados.
    float* data();

    // Retorna o ponteiro para os dados.
    const float* data() const;

    // Operador de atribui��o.
    direction_struct& operator = (const direction_struct &other);

    // Operador de acesso indexado �s coordenadas da dire��o.
    float& operator [] (size_t i);

    // Operador de acesso indexado �s coordenadas da dire��o.
    const float& operator [] (size_t i) const;

private:

    // Coordenadas da dire��o.
    float m_coords[coords_count];
};

/* Classe que representa coordenadas de textura.
 */
class texcoord_struct {
public:

    // N�mero de coordenadas de textura.
    static const size_t coords_count = 2;

    // Apelido dado �s coordenadas de textura.
    float &u, &v;

public:

    // Construtor padr�o da classe.
    texcoord_struct();

    // Construtor de inicializa��o.
    texcoord_struct(float u, float v);

    // Construtor de c�pia da classe.
    texcoord_struct(const texcoord_struct &other);

    // Retorna o ponteiro para os dados.
    float* data();

    // Retorna o ponteiro para os dados.
    const float* data() const;

    // Operador de atribui��o.
    texcoord_struct& operator = (const texcoord_struct &other);

    // Operador de acesso indexado �s coordenadas de textura.
    float& operator [] (size_t i);

    // Operador de acesso indexado �s coordenadas de textura.
    const float& operator [] (size_t i) const;

private:

    // Coordenadas de textura.
    float m_coords[coords_count];
};

/* Classe que representa a localiza��o de um ponto em um espa�o homog�neo tridimensional.
 */
class location_struct {
public:

    // N�mero de coordenadas do ponto.
    static const size_t coords_count = 4;

    // Apelido dado �s coordenadas do ponto.
    float &x, &y, &z, &w;

public:

    // Construtor padr�o da classe.
    location_struct();

    // Construtor de inicializa��o.
    location_struct(float x, float y, float z, float w);

    // Construtor de c�pia da classe.
    location_struct(const location_struct &other);

    // Retorna o ponteiro para os dados.
    float* data();

    // Retorna o ponteiro para os dados.
    const float* data() const;

    // Operador de atribui��o.
    location_struct& operator = (const location_struct &other);

    // Operador de acesso indexado �s coordenadas do ponto.
    float& operator [] (size_t i);

    // Operador de acesso indexado �s coordenadas do ponto.
    const float& operator [] (size_t i) const;

private:

    // Coordenadas do ponto.
    float m_coords[coords_count];
};

/* Classe que representa uma matriz 4x4.
 */
class matrix_struct {
public:

    // N�mero de colunas da matriz.
    static const size_t cols_count = 4;

    // N�mero de linhas da matriz.
    static const size_t rows_count = 4;

    // N�mero de elements da matriz.
    static const size_t elems_count = rows_count*cols_count;

public:

    // Construtor padr�o da classe.
    matrix_struct();

    // Construtor de inicializa��o.
    matrix_struct(float m00, float m10, float m20, float m30, float m01, float m11, float m21, float m31, float m02, float m12, float m22, float m32, float m03, float m13, float m23, float m33);

    // Construtor de c�pia da classe.
    matrix_struct(const matrix_struct &other);

    // Retorna o ponteiro para os dados.
    float* data();

    // Retorna o ponteiro para os dados.
    const float* data() const;

    // Operador de atribui��o.
    matrix_struct& operator = (const matrix_struct &other);

    // Operador de acesso indexado aos elementos da matriz (organizados por coluna, ou seja: i = 0 -> linha 0, coluna 0; i = 1 -> linha 1, coluna 0; i = 2 -> linha 2, coluna 0; i = 3 -> linha 3, coluna 0; i = 4 -> linha 0, coluna 1; i = 5 -> linha 1, coluna 1, etc.).
    float& operator [] (size_t i);

    // Operador de acesso indexado aos elementos da matriz (organizados por coluna, ou seja: i = 0 -> linha 0, coluna 0; i = 1 -> linha 1, coluna 0; i = 2 -> linha 2, coluna 0; i = 3 -> linha 3, coluna 0; i = 4 -> linha 0, coluna 1; i = 5 -> linha 1, coluna 1, etc.).
    const float& operator [] (size_t i) const;

    // Operador de acesso indexado aos elementos da matriz.
    float& operator () (size_t row, size_t col);

    // Operador de acesso indexado aos elementos da matriz.
    const float& operator () (size_t row, size_t col) const;

private:

    // Elementos da matriz.
    float m_elems[elems_count];
};

/* Estrutura que representa uma primitiva. O argumento do template define o n�mero de v�rtices.
 */
template<size_t nvertices>
class primitive_struct {
public:

    // N�mero de v�rtices da primitiva.
    static const size_t vertices_count = nvertices;

    // Localiza��o de cada v�rtice da primitiva, representados em coordenadas de recorte (clip coordinates, CC).
    location_struct vertex_cc[vertices_count];

    // Cor de cada v�rtice da primitiva.
    color_struct color[vertices_count];

    // Coordenada de textura associada a cada v�rtice da primitiva.
    texcoord_struct texcoord[vertices_count];

    // Identificador da textura.
    int texture_id;

public:

    // Construtor padr�o da classe.
    primitive_struct() :
        texture_id(-1) {
    }
};

/* Estrutura que representa uma primitiva segmento.
 */
typedef primitive_struct<2> segment_struct;

/* Estrutura que representa uma primitiva tri�ngulo.
 */
typedef primitive_struct<3> triangle_struct;


// PROT�TIPO DOS M�TODOS QUE COMP�EM A ICGL /////////////////////////////////////////////////////////////////////////////////

#if defined(ICGL_ASSIGNMENT_00_WARMING_UP)
    void give_me_your_name(std::string &name);
#endif

#if defined(ICGL_ASSIGNMENT_01_ROTATION_SCALE_TRANSLATION)
    void make_rotation_matrix(float angle_in_degrees, float axisx, float axisy, float axisz, matrix_struct &rotation_matrix);
    void make_scale_matrix(float scalex, float scaley, float scalez, matrix_struct &scale_matrix);
    void make_translation_matrix(float deltax, float deltay, float deltaz, matrix_struct &translation_matrix);
#endif

#if defined(ICGL_ASSIGNMENT_02_LOOK_AT)
    void make_lookat_matrix(float eyex, float eyey, float eyez, float centerx, float centery, float centerz, float upx, float upy, float upz, matrix_struct &lookat_matrix);
#endif

#if defined(ICGL_ASSIGNMENT_03_PERSPECTIVE_PROJECTION)
    void make_perspective_matrix(float fovy, float aspect, float znear, float zfar, matrix_struct &perspective_matrix);
#endif

#if defined(ICGL_ASSIGNMENT_04_VERTEX_TRANSFORMATION)
    void vertex_transformation(const location_struct &vertex_oc, const direction_struct &normal_oc, const matrix_struct &modelview_matrix, const matrix_struct &projection_matrix, location_struct &vertex_ec, location_struct &vertex_cc, direction_struct &unit_normal_ec);
#endif

#if defined(ICGL_ASSIGNMENT_05_VERTEX_LIGHTING)
    void vertex_lighting(const location_struct &vertex_ec, const direction_struct &unit_normal_ec, const color_struct &base_color, bool lighting_enabled, const color_struct &material_ambient, const color_struct &material_diffuse, const color_struct &material_specular, float material_shininess, const location_struct &light_ec, const color_struct &light_ambient, const color_struct &light_diffuse, const color_struct &light_specular, color_struct &vertex_color);
#endif

#if defined(ICGL_ASSIGNMENT_06_PRIMITIVE_ASSEMBLY_CLIPPING_AND_CULLING)
    void make_segments(const std::vector<location_struct> &vertices_cc, const std::vector<color_struct> &vertices_colors, const std::vector<texcoord_struct> &vertices_texcoords, const std::vector<int> &vertices_texture_ids, std::vector<segment_struct> &primitives);
    void make_triangles(const std::vector<location_struct> &vertices_cc, const std::vector<color_struct> &vertices_colors, const std::vector<texcoord_struct> &vertices_texcoords, const std::vector<int> &vertices_texture_ids, bool backface_culling_enabled, orientation_type front_face_orientation, std::vector<triangle_struct> &primitives);
#endif

#if defined(ICGL_ASSIGNMENT_07_RASTERIZATION)
    void rasterize_segment(const segment_struct &segment, int viewport_x, int viewport_y, int viewport_width, int viewport_height, bool texture_mapping_enabled, int texture_width, int texture_height, const float *texture_rgba, bool depth_test_enabled, int buffer_width, int buffer_height, float *framebuffer, float *depthbuffer);
    void rasterize_triangle(const triangle_struct &triangle, int viewport_x, int viewport_y, int viewport_width, int viewport_height, bool texture_mapping_enabled, int texture_width, int texture_height, const float *texture_rgba, bool depth_test_enabled, int buffer_width, int buffer_height, float *framebuffer, float *depthbuffer);
#endif


// TESTE DE SANIDADE ////////////////////////////////////////////////////////////////////////////////////////////////////////

// Verifica��o de consist�ncia entre aceite de tarefas.
#if defined(ICGL_ASSIGNMENT_01_ROTATION_SCALE_TRANSLATION) && !defined(ICGL_ASSIGNMENT_00_WARMING_UP)
    #error Antes de aceitar a primeira tarefa � preciso aceitar e concluir a tarefa de aquecimento.
#endif

#if defined(ICGL_ASSIGNMENT_02_LOOK_AT) && !defined(ICGL_ASSIGNMENT_01_ROTATION_SCALE_TRANSLATION)
    #error Antes de aceitar a segunda tarefa � preciso aceitar e concluir a primeira.
#endif

#if defined(ICGL_ASSIGNMENT_03_PERSPECTIVE_PROJECTION) && !defined(ICGL_ASSIGNMENT_02_LOOK_AT)
    #error Antes de aceitar a terceira tarefa � preciso aceitar e concluir a segunda.
#endif

#if defined(ICGL_ASSIGNMENT_04_VERTEX_TRANSFORMATION) && !defined(ICGL_ASSIGNMENT_03_PERSPECTIVE_PROJECTION)
    #error Antes de aceitar a quarta tarefa � preciso aceitar e concluir a terceira.
#endif

#if defined(ICGL_ASSIGNMENT_05_VERTEX_LIGHTING) && !defined(ICGL_ASSIGNMENT_04_VERTEX_TRANSFORMATION)
    #error Antes de aceitar a quinta tarefa � preciso aceitar e concluir a quarta.
#endif

#if defined(ICGL_ASSIGNMENT_06_PRIMITIVE_ASSEMBLY_CLIPPING_AND_CULLING) && !defined(ICGL_ASSIGNMENT_05_VERTEX_LIGHTING)
    #error Antes de aceitar a sexta tarefa � preciso aceitar e concluir a quinta.
#endif

#if defined(ICGL_ASSIGNMENT_07_RASTERIZATION) && !defined(ICGL_ASSIGNMENT_06_PRIMITIVE_ASSEMBLY_CLIPPING_AND_CULLING)
    #error Antes de aceitar a s�tima tarefa � preciso aceitar e concluir a sexta.
#endif


// ROTINAS �TEIS DEFINIDAS PELO ALUNO ///////////////////////////////////////////////////////////////////////////////////////

/* - ICGL - IC-UFF Graphics Library
 * Conjunto de rotinas �teis escritas pelo aluno para a ICGL.
 */
#include <icgl_assignment_utils.h>

#endif
