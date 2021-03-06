#ifndef _MODEL_LOADER_H_
#define _MODEL_LOADER_H_

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

namespace meteor
{
    using Buffer = byte*;

    constexpr int32_t gcx_meshLoaderImportFlags = aiProcess_CalcTangentSpace |
        aiProcess_Triangulate |
        aiProcess_ConvertToLeftHanded |
        aiProcess_JoinIdenticalVertices |
        aiProcess_RemoveRedundantMaterials | aiProcess_ValidateDataStructure |
        aiProcess_FlipUVs | aiProcess_OptimizeMeshes;

    class Entity;
    class ModelImporter
    {
        DECLARE_DEFAULT_CLASSMEMBERS(ModelImporter);
        
        std::shared_ptr<Entity> ReadEntityFromFileAndSerialize(string fileName);

    private:
        void PopulateEntityAndSerialize(const aiScene* scene, string shortFileName, string fullFileName, std::shared_ptr<Entity> entity);
        void ProcessMaterialInfo(const aiScene* scene, string fullFilePath, std::shared_ptr<Entity> entity);
        void SerializeEntity(std::shared_ptr<Entity> entity, std::string filename);

        Assimp::Importer m_importer = {}; // Assimp Lib Member
    };
}

#endif // _MODEL_LOADER_H_
