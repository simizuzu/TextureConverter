#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <d3d12.h>
#include "TextureConverter.h"

//コマンドライン引数
enum Argument {
	ApplicationPath, //アプリケーションのパス
	FilePath,		 //渡されたファイルのパス

	NumArgument
};

int main(int argc, char* argv[]) {

	//コマンドライン引数指定なし
	if (argc < NumArgument)
	{
		//使い方を表示する
		TextureConverter::OutputUsage();
		return 0;
	}

	//COMライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINITBASE_MULTITHREADED);
	assert(SUCCEEDED(hr));

	//テクスチャコンバータ
	TextureConverter converter;

	//オプションの数
	int numOptions = argc - NumArgument;
	//オプション配列(ダブルポインタ)
	char** options = argv + NumArgument;

	//テスクチャ変換
	converter.ConvertTextureWICToDDS(argv[FilePath], numOptions, options);

	//COMライブラリの終了
	CoUninitialize();

	return 0;
}