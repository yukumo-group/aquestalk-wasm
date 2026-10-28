__int64 __fastcall sub_1800034F0(__int64 a1, __int64 a2, unsigned __int8 a3, __int64 a4, unsigned __int16 a5)
{
  unsigned int v5; // r14d
  __int64 v7; // r15
  _BYTE *v8; // rsi
  int v9; // ecx
  char *v10; // rdx
  __int64 v12; // r8
  __int64 v13; // r8
  __int64 v14; // r8
  unsigned __int64 v15; // rax
  unsigned __int64 v16; // r12
  int v17; // ecx
  __int64 v18; // rcx
  __int64 v19; // rcx
  __int64 v20; // rdx
  __int64 v21; // rcx
  unsigned __int64 v22; // rcx
  char v23; // [rsp+20h] [rbp-10h] BYREF
  char v24; // [rsp+21h] [rbp-Fh]
  char v25; // [rsp+22h] [rbp-Eh]

  v5 = 0;
  v25 = 0;
  v7 = (__int64)*(&off_18001B8C0 + 3 * (unsigned __int8)a2 + 1);
  LOBYTE(a2) = *(_BYTE *)(v7 + 1);
  v8 = *(&off_18001B8C0 + 3 * a3 + 1);
  if ( (unsigned __int8)(a2 - 97) <= 0x17u )
  {
    v9 = 9453841;
    if ( _bittest(&v9, a2 - 97) )
    {
      if ( a3 <= 9u )
      {
LABEL_4:
        v23 = a2;
        v24 = 59;
LABEL_5:
        v10 = &v23;
        return sub_180002164(a4, v10, a5);
      }
      LOBYTE(v9) = *v8;
      v23 = 43;
      if ( (unsigned __int8)(v9 - 75) <= 0x29u )
      {
        v12 = 0x22101000263LL;
        if ( _bittest64(&v12, (unsigned int)(v9 - 75)) )
        {
          v24 = 107;
          goto LABEL_5;
        }
      }
      if ( (unsigned __int8)(v9 - 70) <= 0x2Du )
      {
        v13 = 0x200100002001LL;
        if ( _bittest64(&v13, (unsigned int)(v9 - 70)) )
        {
          v24 = 115;
          goto LABEL_5;
        }
      }
      if ( (((_BYTE)v9 - 77) & 0xDE) == 0 )
      {
        v24 = 110;
        goto LABEL_5;
      }
      if ( (((_BYTE)v9 - 72) & 0xDF) == 0 )
      {
        v24 = 104;
        goto LABEL_5;
      }
      if ( (((_BYTE)v9 - 82) & 0xDF) == 0 )
      {
        v24 = 114;
        goto LABEL_5;
      }
      if ( (unsigned __int8)(v9 - 68) <= 0x23u )
      {
        v14 = 0x900080009LL;
        if ( _bittest64(&v14, (unsigned int)(v9 - 68)) )
        {
          v24 = 103;
          goto LABEL_5;
        }
      }
      if ( (((_BYTE)v9 - 66) & 0xDF) == 0 )
      {
        v24 = 98;
        goto LABEL_5;
      }
      if ( (((_BYTE)v9 - 106) & 0xEF) == 0 )
      {
        v24 = 122;
        goto LABEL_5;
      }
      if ( (((_BYTE)v9 - 86) & 0xDF) == 0 )
      {
        v24 = 118;
        goto LABEL_5;
      }
      if ( (((_BYTE)v9 - 119) & 0xFD) == 0 )
      {
        v24 = 119;
        goto LABEL_5;
      }
    }
  }
  v15 = (unsigned int)(a2 - 65);
  v16 = 0x8000500000000000uLL;
  if ( (unsigned __int8)(a2 - 65) <= 0x14u )
  {
    v17 = 1065217;
    if ( _bittest(&v17, v15) )
    {
      if ( *v8 <= 0x3Fu )
      {
        v15 = (char)*v8;
        if ( _bittest64((const __int64 *)&v16, v15) )
          goto LABEL_4;
      }
      LOBYTE(v15) = *v8 - 75;
      if ( (unsigned __int8)v15 <= 0x29u )
      {
        v18 = 0x22101000223LL;
        if ( _bittest64(&v18, v15) )
        {
          v10 = (char *)&unk_180030044;
          return sub_180002164(a4, v10, a5);
        }
      }
      LOBYTE(v15) = *v8 - 72;
      if ( (unsigned __int8)v15 <= 0x2Bu )
      {
        v19 = 0x80140000801LL;
        if ( _bittest64(&v19, v15) )
        {
          v10 = (char *)&unk_180030048;
          return sub_180002164(a4, v10, a5);
        }
      }
      if ( *v8 == 45 )
        return 0;
      v23 = a2;
      v24 = 59;
      sub_180002164(a4, &v23, a5);
      LOBYTE(v20) = *v8;
      v23 = 59;
      v24 = sub_180003784(v21, v20);
      if ( v24 )
        v5 = sub_180002164(a4, &v23, a5);
    }
  }
  if ( *(_BYTE *)(v7 + 1) <= 0x3Fu )
  {
    v22 = *(char *)(v7 + 1);
    if ( _bittest64((const __int64 *)&v16, v22) )
    {
      LOBYTE(a2) = *v8;
      v23 = 59;
      v24 = sub_180003784(v22, a2);
      if ( v24 )
        return (unsigned int)sub_180002164(a4, &v23, a5);
    }
  }
  return v5;
}