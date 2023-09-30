#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <d3d12.h>
#include "TextureConverter.h"

//�R�}���h���C������
enum Argument {
	ApplicationPath, //�A�v���P�[�V�����̃p�X
	FilePath,		 //�n���ꂽ�t�@�C���̃p�X

	NumArgument
};

int main(int argc, char* argv[]) {
	assert(argc >= NumArgument);

	//COM ���C�u�����̏�����
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	//�e�N�X�`���R���o�[�^
	TextureConverter converter;

	//�e�N�X�`���ϊ�
	converter.ConvertTextureWICToDDS(argv[FilePath]);

	//COM ���C�u�����̏I��
	CoUninitialize();

	system("pause");

	return 0;
}