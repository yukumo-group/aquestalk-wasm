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
 * Same three synthesize entry points with an optional voice preset.
 * presetPath NULL or "" uses the tables compiled into the library.
 * A missing or malformed file returns NULL and sets *pSize to 109
 * (OT_ERR_PRESET). The original functions above always use the built-in tables.
 *
 * File layout (little-endian), magic "OTPR", version 1:
 *   char magic[4]; uint16 version; uint16 chunk_count;
 *   then chunk_count records of uint16 id, uint16 reserved (0),
 *   uint32 length, uint8 payload[length].
 * Ids: 1 formant int16[N] (25476 in f1..dvd, 25584 in f3), 2 symbols N*6
 * (209 in f1..dvd, 211 in f3), 3 phoneme_word int16[N] (392, or 328 in f3),
 * 4 period int16[4096], 5 pulse int16[0x255], 6 dur_scale int16[121],
 * 7 dur_key int16[240], 8 dur_val int16[1200].
 * 5 may also be int16[0x87B] when that DLL's pulse limit is 0x87B.
 * 9 constants: uint16 base_pitch, uint16 question_add, uint16 render_mode,
 * uint16 dur_base (13248 in the root; the pitch ceiling is 0x3E8000/dur_base),
 * optional uint16 dur_scale (163 in the root, i.e. delta unchanged; the 163
 * denominator is fixed by the code). An 8-byte chunk keeps 163.
 * render_mode 0 is the root sample loop, 1 is the dvd sign/gain loop,
 * 2 is the jgr mute/gain loop. A missing chunk keeps the compiled-in table
 * (base pitch 309, question add 6400, render mode 0, pulse length 0x255).
 */
unsigned char *__stdcall Open_Talk_Synthe_Preset(const char *koe, int iSpeed, int *pSize,
                                                 const char *presetPath);
unsigned char *__stdcall Open_Talk_Synthe_Utf8_Preset(const char *koe, int iSpeed, int *pSize,
                                                      const char *presetPath);
unsigned char *__stdcall Open_Talk_Synthe_Utf16_Preset(const unsigned short *koe, int iSpeed, int *pSize,
                                                       const char *presetPath);

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
