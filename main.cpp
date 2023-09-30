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
	assert(argc >= NumArgument);

	//COM ライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	//テクスチャコンバータ
	TextureConverter converter;

	//テクスチャ変換
	converter.ConvertTextureWICToDDS(argv[FilePath]);

	//COM ライブラリの終了
	CoUninitialize();

	system("pause");

	return 0;
}