__int64 __fastcall sub_180003440(__int64 a1, unsigned __int8 a2, unsigned __int8 a3, __int64 a4, unsigned __int16 a5)
{
  __int64 v6; // rcx
  char *v7; // r9
  char v8; // al
  char *v9; // rdx
  char v11; // [rsp+20h] [rbp-10h] BYREF
  char v12; // [rsp+21h] [rbp-Fh]
  char v13; // [rsp+22h] [rbp-Eh]

  v13 = 0;
  v6 = (__int64)*(&off_18001B8C0 + 3 * a2 + 1);
  v7 = (char *)*(&off_18001B8C0 + 3 * a3 + 1);
  if ( a3 == 0xA1 )
  {
    v11 = *(_BYTE *)(v6 + 1);
    v8 = *v7;
    goto LABEL_11;
  }
  if ( (unsigned __int8)(a3 - 10) <= 4u || a3 == 0x9F )
  {
    v8 = *v7;
    if ( (unsigned __int8)(a2 - 6) > 3u )
    {
      if ( *(_BYTE *)(v6 + 1) == v8 )
      {
        v11 = *v7;
        v12 = 45;
LABEL_12:
        v9 = &v11;
        return sub_180002164(a4, v9, a5);
      }
      v11 = 43;
    }
    else
    {
      v11 = 59;
    }
LABEL_11:
    v12 = v8;
    goto LABEL_12;
  }
  v9 = (char *)*(&off_18001B8C0 + 3 * a3 + 1);
  return sub_180002164(a4, v9, a5);
}