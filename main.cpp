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

	//�R�}���h���C�������w��Ȃ�
	if (argc < NumArgument)
	{
		//�g������\������
		TextureConverter::OutputUsage();
		return 0;
	}

	//COM���C�u�����̏�����
	HRESULT hr = CoInitializeEx(nullptr, COINITBASE_MULTITHREADED);
	assert(SUCCEEDED(hr));

	//�e�N�X�`���R���o�[�^
	TextureConverter converter;

	//�I�v�V�����̐�
	int numOptions = argc - NumArgument;
	//�I�v�V�����z��(�_�u���|�C���^)
	char** options = argv + NumArgument;

	//�e�X�N�`���ϊ�
	converter.ConvertTextureWICToDDS(argv[FilePath], numOptions, options);

	//COM���C�u�����̏I��
	CoUninitialize();

	return 0;
}