#pragma once
#include <string>
#include <DirectXTex.h>

//�e�N�X�`���R���o�[�^�[
class TextureConverter
{
public:
	/// <summary>
	/// �e�N�X�`����WIC����DDS�ɕϊ�����
	/// </summary>
	/// <param name="filePath">�t�@�C���p�X</param>
	/// <param name="numOptions">�I�v�V�����̐�</param>
	/// <param name="options">�I�v�V�����z��</param>
	void ConvertTextureWICToDDS(const std::string& filePath, int numOptions = 0, char* options[] = nullptr);

	/// <summary>
	/// �g�p���@���o�́i�\���j����
	/// </summary>
	static void OutputUsage();

private:
	/// <summary>
	/// �e�N�X�`���t�@�C���ǂݍ���
	/// </summary>
	/// <param name="filePath">�t�@�C���p�X</param>
	void LoadWICTextureFromFile(const std::string& filePath);

	/// <summary>
	/// �ӂ����邾�ς��ƃt�@�C�����𕪗�����
	/// </summary>
	/// <param name="filePath">�t�@�C���p�X</param>
	void SeparateFilePath(const std::wstring& filePath);

	/// <summary>
	/// DDS�e�N�X�`���Ƃ��ăt�@�C�������o��
	/// </summary>
	void SaveDDSTextureToFile(int numOptions, char* options[]);

private:
	/// <summary>
	/// �}���`�o�C�g����������C�h������ɕϊ�
	/// </summary>
	/// <param name="mString">�}���`�o�C�g������</param>
	/// <returns>���C�h������</returns>
	static std::wstring ConverterMultiByteStringToWideString(const std::string& mString);


private:
	//�摜�̏��
	DirectX::TexMetadata metadata_;
	//�摜�̃C���[�W�̃R���e�i
	DirectX::ScratchImage scratchImage_;

	//�f�B���N�g���p�X
	std::wstring directoryPath_;
	//�t�@�C����
	std::wstring fileName_;
	//�t�@�C���g���q
	std::wstring fileExt_;
};

