#include "acpch.h"

#include "GameSpecificCommands.h"

namespace meteor::game
{
    void GameSpecificCommands::InitializeSettings()
    {
        AddAllShaders();
    }

    void GameSpecificCommands::AddAllShaders()
    {
        // Parse All Shaders from the .ini or whatever file maybe?

        HLSLShaderDesc empty_vs_desc;
        empty_vs_desc.shaderEntryPoint = "VertexMain";
        empty_vs_desc.shaderTarget = HLSLShaderTarget::vs_5_0;
        m_settings->AddShaderFileToList("PhongLighting.hlsl", empty_vs_desc, true);

        HLSLShaderDesc empty_ps_desc;
        empty_ps_desc.shaderEntryPoint = "PixelMain";
        empty_ps_desc.shaderTarget = HLSLShaderTarget::ps_5_0;
        m_settings->AddShaderFileToList("PhongLighting.hlsl", empty_ps_desc, true);
    }
}
