#include "FBX.hlsli"

SkinOutput ComputeSkin(VSInput input)
{
    SkinOutput output = (SkinOutput) 0;
    
    uint iBone;
    float weight;
    matrix m;
    
    //�{�[��0
    iBone = input.boneIndices.x;
    weight = input.boneWeight.x;
    m = matSkinning[iBone];
    output.pos += weight * mul(m, input.pos);
    output.normal += weight * mul((float3x3) m, input.normal);
    
    //�{�[��1
    iBone = input.boneIndices.y;
    weight = input.boneWeight.y;
    m = matSkinning[iBone];
    output.pos += weight * mul(m, input.pos);
    output.normal += weight * mul((float3x3) m, input.normal);
    
    //�{�[��2
    iBone = input.boneIndices.z;
    weight = input.boneWeight.z;
    m = matSkinning[iBone];
    output.pos += weight * (m, input.pos);
    output.normal += weight * mul((float3x3) m, input.normal);
    
    //�{�[��3
    iBone = input.boneIndices.w;
    weight = input.boneWeight.w;
    m = matSkinning[iBone];
    output.pos += weight * mul(m, input.pos);
    output.normal += weight * mul((float3x3) m, input.normal);
    
    return output;
}


VSOutput main(VSInput input)
{
    SkinOutput skinned = ComputeSkin(input);
    
    float4 wnormal = normalize(mul(world, float4(input.normal, 0)));
    
    VSOutput output;
    
    output.svpos = mul(mul(viewproj, world), input.pos);
    
    output.normal = wnormal.xyz;
    
    output.uv = input.uv;
    
    return output;
}

