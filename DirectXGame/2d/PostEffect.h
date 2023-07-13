#pragma once
#include <Windows.h>
#include <wrl.h>
#include <d3d12.h>
#include <DirectXMath.h>
#include "Sprite.h"

class PostEffect :
	public Sprite
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	PostEffect();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 描画コマンドの発行
	/// </summary>
	/// <param name="cmdList"></param>
	void Draw(ID3D12GraphicsCommandList* cmdList);

	/// <summary>
	/// シーン描画前処理
	/// </summary>
	/// <param name="cmdList"></param>
	void PreDrawScene(ID3D12GraphicsCommandList* cmdList);

	/// <summary>
	/// シーン描画後処理
	/// </summary>
	/// <param name="cmdList"></param>
	void PostDrawScene(ID3D12GraphicsCommandList* cmdList);

	/// <summary>
	/// パイプライン生成
	/// </summary>
	void CreateGraphicPipelineState();
private://静的メンバ変数
	static const float clearColor[4];
private:
	Microsoft::WRL::ComPtr<ID3D12Resource> texBuff[2];
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> descHeapSRV;

	Microsoft::WRL::ComPtr<ID3D12Resource> depthBuff;
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> descHeapRTV;
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> descHeapDSV;

	Microsoft::WRL::ComPtr<ID3D12PipelineState> pipelineState;
	Microsoft::WRL::ComPtr<ID3D12RootSignature> rootSignature;
};

