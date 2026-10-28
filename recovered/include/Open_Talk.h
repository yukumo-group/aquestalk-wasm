// OpenTalk1
// Public API recovered to match lib64/Open_Talk.h and the exports of
// lib64/Open_Talk.dll. This file is the reconstructed header; the binary
// copy under lib64/ is left unchanged.

#pragma once
#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////
//!	音声記号列から音声波形を生成
//!	音声波形データは内部で領域確保される。
//!	音声波形データの解放は本関数の呼び出し側でOpen_Talk_FreeWave()にて行う
//! @param	iSpeed[in]	発話速度 [%] 50-300 の間で指定
//!	@param	pSize[out]	生成した音声データのサイズ[byte]（エラーの場合はエラーコードが返る）
//!	@return	WAVフォーマットの音声データの先頭アドレス。エラー時はNULLが返る

//! @param	koe[in]		音声記号列（SJIS NULL終端）
unsigned char *__stdcall Open_Talk_Synthe(const char *koe, int iSpeed, int *pSize);

//! @param	koe[in]		音声記号列（UTF8 NULL終端 BOMはつけられない）
unsigned char *__stdcall Open_Talk_Synthe_Utf8(const char *koe, int iSpeed, int *pSize);

//! @param	koe[in]		音声記号列（UTF16 NULL終端 BOMの有無は問わない　エンディアンは実行環境に従う）
unsigned char *__stdcall Open_Talk_Synthe_Utf16(const unsigned short *koe, int iSpeed, int *pSize);

/*
 * Voice selection.  All voices are raw-dumped into the library, so there is
 * no preset file to load.  "f1".."dvd" and "f3" are accepted (case
 * insensitive); NULL or "" resets to f1.  Returns 0 on success, -1 for an
 * unknown name.  The three Synthe entry points above use the selected voice.
 * f3 currently takes the dedicated src/f3/ path, which only implements part
 * of the new symbol vocabulary.
 */
int __stdcall Open_Talk_SelectVoice(const char *name);

/* Number of embedded voices, and their names in selection order. */
int __stdcall Open_Talk_VoiceCount(void);
const char *__stdcall Open_Talk_VoiceName(int index);

/////////////////////////////////////////////
//!	音声データの領域を開放
//!	@param  wav[in]		Open_Talk_Synthe()で返されたアドレスを指定
void __stdcall Open_Talk_FreeWave(unsigned char *wav);

/////////////////////////////////////////////
//!	開発ライセンスキー設定
//!	音声波形を生成する前に一度呼び出す。
//!	これにより評価版の制限がなくなる。
//!	@param  key[in]		ライセンスキーを指定
//!	@return	ライセンスキーが正しければ0、正しくなければ1が返る
int __stdcall Open_Talk_SetDevKey(const char *key);

/////////////////////////////////////////////
//!	使用ライセンスキー設定
//!	音声波形を生成する前に一度呼び出す。
//!	以降、合成音声データに含まれる透かしが、使用ライセンス無しから取得済みに変化する
//!	@param  key[in]		ライセンスキーを指定
//!	@return	ライセンスキーが正しければ0、正しくなければ1が返る
int __stdcall Open_Talk_SetUsrKey(const char *key);

#ifdef __cplusplus
}
#endif
