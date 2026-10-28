/**********************************************************************
	HelloTalk.c - AquesTalk10 Linux 規則音声合成 サンプルプログラム

	標準入力から音声記号列を１行読み込み、
	標準出力に音声波形(.wavフォーマット）を出力

	COPYRIGHT (C) 2017 AQUEST CORP.

	使用方法は、付属のマニュアルを参照ください。
	
	2017/10/11	N.Yamazaki	Creation
**********************************************************************/
#include <stdio.h>
#include <AquesTalk.h>

int main(int ac, char **av)
{
	int 	size;
	int 	iret;
	char	str[1024];
	AQTK_VOICE voice;
/*	
	// 開発ライセンスキーのセットで評価版の制限(ナ行、マ行がヌになる)が解除
	if(AquesTalk_SetDevKey("xxx-xxx-xxx")!=0) {
		fprintf(stderr, "# ERR DEV LICENCE KEY\n");
		return 999;
	}
	if(AquesTalk_SetUsrKey("xxx-xxx-xxx")!=0) {
		fprintf(stderr, "# ERR USR LICENCE KEY\n");
	}
*/
	// 音声記号列を入力
	if(fgets(str, 1024-1, stdin)==0) return 0;

	// 声質パラメータ
	voice = gVoice_F1;
	voice.spd = 120;	

	// 音声合成
	unsigned char *wav = AquesTalk_Synthe_Utf8(&voice, str, &size);
	if(wav==0){
		fprintf(stderr, "ERR:%d\n",size);
		return -1;
	}

	// 音声データ(wavフォーマット)の出力
	fwrite(wav, 1, size, stdout);

	// 音声データバッファの開放
	AquesTalk_FreeWave(wav);
 
	return 0;
}
