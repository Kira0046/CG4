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
	/// �R���X�g���N�^
	/// </summary>
	PostEffect();

	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �`��R�}���h�̔��s
	/// </summary>
	/// <param name="cmdList"></param>
	void Draw(ID3D12GraphicsCommandList* cmdList);

	/// <summary>
	/// �V�[���`��O����
	/// </summary>
	/// <param name="cmdList"></param>
	void PreDrawScene(ID3D12GraphicsCommandList* cmdList);

	/// <summary>
	/// �V�[���`��㏈��
	/// </summary>
	/// <param name="cmdList"></param>
	void PostDrawScene(ID3D12GraphicsCommandList* cmdList);

	/// <summary>
	/// �p�C�v���C������
	/// </summary>
	void CreateGraphicPipelineState();
private://�ÓI�����o�ϐ�
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

