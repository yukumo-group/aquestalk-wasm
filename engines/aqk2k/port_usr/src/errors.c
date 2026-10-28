/* errors.c -- compact stand-in for AqUsrDic's error-message formatter.
 * The original FUN_00108cf0 is a 7 KB string-building routine; the Check-only
 * wasm module only needs the observable message for each error code. */
#include "shim.h"

static const char *error_message(int code)
{
    switch (code) {
    case 100: return "ユーザ辞書のファイル名が不正";
    case 200: return "システム辞書が読み込めない";
    case 300: return "CSVの書式が不正";
    case 301: return "表記がない";
    case 302: return "表記または読みが長すぎる";
    case 303: return "読みがない";
    case 304: return "品詞コードが不正";
    case 305: return "項目数が不正";
    case 310: return "読みに定義外の文字が指定されている";
    case 311: return "読みのアクセント位置が不正";
    case 312: return "表記に半角文字が使われている";
    case 313: return "表記に空白が使われている";
    case 314: return "品詞コードの不正";
    case 315: return "表記が長すぎる(32文字未満)";
    case 316: return "読みが長すぎる";
    case 317: return "同じ表記が重複している";
    case 400: return "ユーザ辞書のパスが不正";
    case 500: return "ファイルを開けない";
    default:  return "ユーザ辞書エラー";
    }
}

void FUN_00108cf0(int code, unsigned index)
{
    AqStr *s = (AqStr *)(aq_image + 0x33220);
    char num[16];
    unsigned n = index, i = 0;
    if (n == 0) {
        num[i++] = '0';
    } else {
        char tmp[16];
        unsigned k = 0;
        while (n && k < sizeof(tmp)) {
            tmp[k++] = (char)('0' + n % 10);
            n /= 10;
        }
        while (k)
            num[i++] = tmp[--k];
    }
    num[i++] = ':';
    num[i] = 0;
    aqstr_replace(s, 0, (size_t)s->len, "");
    aqstr_append(s, num);
    aqstr_append(s, error_message(code));
}
