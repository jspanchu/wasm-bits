#include "Renderer.h"

void Renderer::init()
{
    // x, y, r, g, b
    m_vertices_and_colors.push_back(-0.6f);
    m_vertices_and_colors.push_back(-0.6f);
    m_vertices_and_colors.push_back(1);
    m_vertices_and_colors.push_back(0);
    m_vertices_and_colors.push_back(0);
    
    m_vertices_and_colors.push_back(0.6f);
    m_vertices_and_colors.push_back(-0.6f);
    m_vertices_and_colors.push_back(0);
    m_vertices_and_colors.push_back(1);
    m_vertices_and_colors.push_back(0);
    
    m_vertices_and_colors.push_back(0.0);
    m_vertices_and_colors.push_back(0.6f);
    m_vertices_and_colors.push_back(0);
    m_vertices_and_colors.push_back(0);
    m_vertices_and_colors.push_back(1);
}
