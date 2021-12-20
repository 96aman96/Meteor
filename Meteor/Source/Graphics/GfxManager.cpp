#include "acpch.h"
#include "GfxManager.h"

namespace meteor
{
    void GfxManger::Initialize()
    {
        m_renderer->Initialize();
    }
    
    void GfxManger::Shutdown()
    {
        m_renderer->Shutdown();
    }
    
    void GfxManger::PreRender()
    {
        m_renderer->PreRender();
    }
    
    void GfxManger::Render()
    {
        m_renderer->Render();
    }
    
    void GfxManger::PostRender()
    {
        m_renderer->PostRender();
    }
}