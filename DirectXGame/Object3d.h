#pragma once

#include "Model.h"
#include "Camera.h"

#include <Windows.h>
#include <wrl.h>
#include <d3d12.h>
#include <d3dx12.h>
#include <DirectXMath.h>
#include <string>

class Object3d {
protected: //エイリアス
	template<class T> using Comptr = Microsoft::WRL::ComPtr<T>;

	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

public: //静的メンバ関数
	static void SetDevice(ID3D12Device* device) { Object3d::device = device; }

	static void SetCamera(Camera* camera) { Object3d::camera = camera; }

	static void CreateGraphicsPipeline();

private: //静的メンバ変数
	//デバイス
	static ID3D12Device* device;
	//カメラ
	static Camera* camera;
	//ルートシグネチャ
	static Comptr<ID3D12RootSignature> rootsignature;
	//グラフィックスパイプライン
	static Comptr<ID3D12PipelineState> pipelinestate;
public:
	//サブクラス
	struct ConstBufferDataTransform {
		XMMATRIX viewproj;
		XMMATRIX world;
		XMFLOAT3 cameraPos;
	};
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// モデルのセット
	/// </summary>
	/// <param name="model"></param>
	void SetModel(Model* model) { this->model = model; }

	/// <summary>
	/// 描画
	/// </summary>
	/// <param name="cmdList"></param>
	void Draw(ID3D12GraphicsCommandList* cmdList);
protected:
	//定理バッファ
	Comptr<ID3D12Resource> constBuffTransform;
	//ローカルスケール
	XMFLOAT3 scale = { 1,1,1 };
	//ローカル回転角
	XMFLOAT3 rotation = { 0,0,0 };
	//ローカル座標
	XMFLOAT3 position = { 0,0,0 };
	//ローカルワールド変換行列
	XMMATRIX matWorld;
	//モデル
	Model* model = nullptr;
};