cbuffer cbPerObject
{
    float4x4 WVP; 
};
// Vertex Shader
float4 VS( float4 Pos : POSITION ) : SV_POSITION
{
    return mul(Pos, WVP);    //multiply the pos of the vertex by the world matrix
}

// Pixel Shader
float4 PS( float4 Pos : SV_POSITION ) : SV_Target
{
    return float4( 1.0f, 1.0f, 1.0f, 1.0f );    // All pixels put through the pixel shader here will be white.
}

technique10 Tech
{
    pass P0
    {
        SetVertexShader( CompileShader( vs_4_0, VS() ) );
        SetPixelShader( CompileShader( ps_4_0, PS() ) );
    }
}