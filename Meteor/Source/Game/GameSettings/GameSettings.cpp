#include "acpch.h"

#include <iterator>

#include "GameSettings.h"

namespace meteor::game
{
    void GameSettings::AddShaderFileToList(string fileName, HLSLShaderDesc shaderDesc, bool isInDeaultLocation)
    {
        HLSLShader shader(fileName, shaderDesc, isInDeaultLocation);
        
        // TODO: shader.Validate() before adding to vector.
        m_shaderList.emplace_back(shader);
    }
}
