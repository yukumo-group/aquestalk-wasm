__int64 __fastcall sub_180001000(_BYTE *a1, __int64 a2)
{
  _BYTE *v3; // r11
  __int64 result; // rax
  char v5; // cl
  _BYTE *i; // rdi
  char v7; // si
  _BYTE *v8; // rdx
  int v9; // eax
  char v10; // bp
  _BYTE *v11; // r14
  int v12; // esi
  int v13; // eax
  int v14; // ecx
  __int64 v15; // rcx
  __int64 v16; // [rsp+20h] [rbp-38h] BYREF

  v3 = a1;
  if ( !a1 )
    return 100;
  v5 = *a1;
  if ( v5 )
  {
    while ( (unsigned __int8)(v5 - 65) > 0x19u && (unsigned __int8)(v5 - 97) > 0x19u )
    {
      if ( (unsigned __int8)(v5 - 48) <= 9u )
      {
        for ( i = v3 + 1; ; ++i )
        {
          v7 = *i;
          if ( (unsigned __int8)(*i - 48) > 9u )
            break;
        }
        v16 = 0;
        *i = 0;
        result = sub_180004704(&v16, v3, a2);
        if ( (_DWORD)result )
          return result;
        if ( v7 )
        {
          if ( *(__int16 *)(a2 + 8) >= 2047 )
            return 200;
          *(_BYTE *)((__int16)(*(_WORD *)(a2 + 8))++ + *(_QWORD *)a2) = 7;
        }
        *i = v7;
        goto LABEL_46;
      }
      v8 = &unk_18001B810;
      v9 = 0;
      while ( v5 != *v8 )
      {
        v8 += 8;
        if ( (unsigned int)++v9 >= 0x15 )
          goto LABEL_23;
      }
      result = sub_1800019F8(a2, v8 + 1);
      if ( (_DWORD)result )
        return result;
      if ( v3[1] )
      {
        if ( *(__int16 *)(a2 + 8) >= 2047 )
          return 200;
        *(_BYTE *)((__int16)(*(_WORD *)(a2 + 8))++ + *(_QWORD *)a2) = 7;
      }
LABEL_23:
      ++v3;
LABEL_48:
      v5 = *v3;
      if ( !*v3 )
        return 0;
    }
    for ( i = v3 + 1; ; ++i )
    {
      v10 = *i;
      if ( (unsigned __int8)(*i - 65) > 0x19u && (unsigned __int8)(v10 - 97) > 0x19u )
        break;
    }
    *i = 0;
    v11 = v3;
    v12 = 0;
    while ( 1 )
    {
      v13 = (char)*v11;
      v14 = 65;
      ++v11;
      if ( (char)v13 > 90 )
        v14 = 97;
      v15 = 12LL * (unsigned int)(v13 - v14);
      if ( !*v11 )
        break;
      if ( v12 == 3 )
      {
        result = sub_1800019F8(a2, (char *)&unk_18001B6D6 + v15);
        if ( (_DWORD)result )
          goto LABEL_47;
        if ( *(__int16 *)(a2 + 8) >= 2047 )
          goto LABEL_39;
        *(_BYTE *)((__int16)(*(_WORD *)(a2 + 8))++ + *(_QWORD *)a2) = 7;
        v12 = 0;
      }
      else
      {
        result = sub_1800019F8(a2, (char *)&unk_18001B6D0 + v15);
        if ( (_DWORD)result )
          goto LABEL_47;
        if ( *(__int16 *)(a2 + 8) >= 2047 )
        {
LABEL_39:
          result = 200;
          goto LABEL_47;
        }
        *(_BYTE *)((__int16)(*(_WORD *)(a2 + 8))++ + *(_QWORD *)a2) = 4;
        ++v12;
      }
    }
    result = sub_1800019F8(a2, (char *)&unk_18001B6D6 + v15);
    if ( !(_DWORD)result )
    {
      if ( v10 )
      {
        if ( *(__int16 *)(a2 + 8) >= 2047 )
          return 200;
        *(_BYTE *)((__int16)(*(_WORD *)(a2 + 8))++ + *(_QWORD *)a2) = 7;
      }
      *i = v10;
LABEL_46:
      result = 0;
      v3 = i;
    }
LABEL_47:
    if ( (_DWORD)result )
      return result;
    goto LABEL_48;
  }
  return 0;
}