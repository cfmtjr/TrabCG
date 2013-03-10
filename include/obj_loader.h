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

#ifndef _OBJ_LOADER_HEADER_
#define _OBJ_LOADER_HEADER_


// INCLUDES /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* - STL - Standard Template Library
 * API padr�o que estabelece padr�es e estruturas de dados para aplica��es C++.
 * Geralmente disponibilizada com o sistema operacional ou plataforma de desenvolvimento.
 */
#include <cfloat>
#include <stdexcept>

/* - ICGL - IC-UFF Graphics Library
 * Conjunto de opera��es utilizadas para ensino de Pipeline Gr�fico no Instito de Computa��o (IC) da Universidade Federal Fluminense (UFF).
 * � responsabilidade de cada aluno de Computa��o Gr�fica do IC-UFF implementar a sua pr�pria biblioteca ICGL.
 */
#include <icgl.h>


// DECLARA��O DAS ESTRUTURAS UTILIZADAS PARA ARMAZENAR A GEOMETRIA //////////////////////////////////////////////////////////

/* Classe que representa um material.
 */
class object_material_struct {
public:

    // Nome do material.
    std::string name;

    // Componente ambiente.
    color_struct ambient;

    // Componente difusa.
    color_struct diffuse;

    // Componente especular.
    color_struct specular;

    // Brilho.
    float shininess;

    // Arquivo de textura que cont�m a componente difusa.
    std::string texture_filename;

public:

    // Construtor padr�o da classe.
    object_material_struct();

    // Construtor de c�pia.
    object_material_struct(const object_material_struct &other);

    // Construtor de inicializa��o.
    object_material_struct(const std::string &name);
};

/* Classe que representa um tri�ngulo que pertence a uma malha.
 */
class object_triangle_struct {
public:

    // N�mero de v�rtices no tri�ngulo.
    static const size_t vertex_count = 3;

    // �ndice do vetor normal associado a cada um dos v�rtices.
    size_t normal_index[vertex_count];

    // �ndice da coordenada de textura associada a cada um dos v�rtices.
    size_t texcoord_index[vertex_count];

    // �ndice da localiza��o associada a cada um dos v�rtices.
    size_t vertex_index[vertex_count];
    
    // �ndice do material associado ao tri�ngulo.
    size_t material_index;

public:

    // Default class constructor.
    object_triangle_struct();
};

/* Classe que representa um objeto definido por uma malha de tri�ngulos.
 */
class geometric_object {
public:

    // Etiqueta que indica que nenhum elemento do tipo respectivo est� sendo referenciado.
    static const size_t no_material_tag;
    static const size_t no_normal_tag;
    static const size_t no_texcoord_tag;
    static const size_t no_vertex_tag;

public:

    // Retorna se o objeto foi carregado.
    bool empty() const;

    // Limpa o objeto.
    void clear();
    
    // Carrega objeto do arquivo informado.
    void load_from_file(const std::string &path, const std::string &filename);

public:

    // Retorna o v�rtice de �ndice informado.
    const direction_struct& get_normal(const size_t i) const;

    // Retorna o material de �ndice informado.
    const object_material_struct& get_material(const size_t i) const;

    // Retorna o �ndice do material de nome informado.
    size_t get_material_index(const std::string &name) const;
    
    // Retorna a coordenada de textura de �ndice informado.
    const texcoord_struct& get_texcoord(const size_t i) const;

    // Retorna o tri�ngulo de �ndice informado.
    const object_triangle_struct& get_triangle(const size_t i) const;

    // Retorna o v�rtice de �ndice informado.
    const location_struct& get_vertex(const size_t i) const;

    // Retorna o n�mero de materiais usados na malha.
    size_t materials_count() const;

    // Retorna o n�mero de vetores normais na malha.
    size_t normals_count() const;

    // Retorna o n�mero de coordenadas de textura na malha.
    size_t texcoords_count() const;

    // Retorna o n�mero de tri�ngulos na malha.
    size_t triangles_count() const;

    // Retorna o n�mero de v�rtices na malha.
    size_t vertices_count() const;

private:

    // Caracteres "brancos".
    static const char *whitespaces;

private:

    // Converte o �ndice informado no padr�o OBJ para indexa��o absoluta. Este m�todo � utilizado por parse_triangle().
    size_t convert_from_obj_index(const size_t count, const int index) const;
    
    // M�todo auxiliar utilizado por parse_mtl_file() para leitura de canais de cor.
    color_struct parse_color() const;

    // M�todo auxiliar utilizado na leitura do arquivo MTL.
    void parse_mtl_file(const std::string &path, const std::string &filename);
    
    // M�todo auxiliar utilizado por parse_obj_file() para leitura de coordendas de vetor normal.
    direction_struct parse_normal() const;

    // M�todo auxiliar utilizado na leitura do arquivo OBJ.
    void parse_obj_file(const std::string &path, const std::string &filename);
    
    // M�todo auxiliar utilizado por parse_obj_file() para leitura de coordendas de textura.
    texcoord_struct parse_texcoord() const;

    // M�todo auxiliar utilizado por parse_obj_file() para leitura de tri�ngulo.
    object_triangle_struct parse_triangle(size_t material_id) const;

    // M�todo auxiliar utilizado por parse_obj_file() para leitura de coordendas de v�rtice.
    void parse_values(float *result, size_t count) const;

    // M�todo auxiliar utilizado por parse_color(), parse_normal(), parse_texcoord() e parse_vertex() para leitura de valures num�ricos.
    location_struct parse_vertex() const;

private:
    
    // Lista de v�rtices.
    std::vector<location_struct> m_vertices;

    // Lista de vetores normais.
    std::vector<direction_struct> m_normals;

    // Lista de coordenadas de textura.
    std::vector<texcoord_struct> m_texcoords;

    // Lista de materiais.
    std::vector<object_material_struct> m_materials;

    // Lista de tri�ngulos.
    std::vector<object_triangle_struct> m_triangles;
};

#endif
