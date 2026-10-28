__int64 __fastcall sub_180003290(__int64 a1, __int64 *a2)
{
  int v2; // ecx
  __int64 v4; // r9
  int v5; // r8d
  int v6; // r11d
  __int64 v7; // r10
  int v8; // ebp
  __int16 v9; // dx
  __int16 v10; // cx
  __int64 v11; // rax
  int v12; // ebx
  _WORD *v13; // rdx
  __int16 v14; // ax
  __int16 v15; // cx
  int v16; // edx
  unsigned __int16 v17; // cx

  v2 = *((_DWORD *)a2 + 2);
  if ( v2 > 0 )
  {
    v4 = 0;
    v5 = *((_DWORD *)a2 + 2);
    v6 = 1;
    do
    {
      v7 = *a2;
      v8 = v6;
      v9 = *(_WORD *)(*a2 + 4 * v4);
      if ( (v9 & 0x3FFF) == 0 )
      {
        if ( v6 - 1 == v5 - 1 )
        {
          v10 = *(_WORD *)(v7 + 4 * v4 - 4) & 0x3FFF;
          if ( v6 - 3 >= 0 )
            v10 = 2 * v10 - (*(_WORD *)(v7 + 4 * v4 - 8) & 0x3FFF);
          if ( v10 > 309 )
            v10 = 309;
          *(_WORD *)(v7 + 4 * v4) = v10 | v9 & 0xC000;
        }
        else
        {
          v11 = v4 + 1;
          v12 = v6;
          if ( v6 < v5 )
          {
            v13 = (_WORD *)(v7 + 4 + 4 * v4);
            do
            {
              if ( (*v13 & 0x3FFF) != 0 )
                break;
              ++v12;
              ++v11;
              v13 += 2;
            }
            while ( v11 < v5 );
          }
          if ( v12 < v2 )
          {
            v16 = *(_WORD *)(v7 + 4 * v11) & 0x3FFF;
            if ( v6 - 2 >= 0 )
            {
              v17 = *(_WORD *)(v7 + 4 * v4 - 4) & 0x3FFF;
              *(_WORD *)(v7 + 4 * v4) &= 0xC000u;
              *(_WORD *)(v7 + 4 * v4) |= v17 + (unsigned __int16)((v16 - v17) / (v12 - (v6 - 1) + 1));
            }
            else
            {
              *(_WORD *)(v7 + 4 * v4) &= 0xC000u;
              *(_WORD *)(v7 + 4 * v4) |= (unsigned __int16)(5 * (v16 - 309) / 6) + 309;
            }
          }
          else
          {
            if ( v4 >= 2 )
            {
              v15 = 2 * (*(_WORD *)(v7 + 4 * v4 - 4) & 0x3FFF) - (*(_WORD *)(v7 + 4 * v4 - 8) & 0x3FFF);
              if ( v15 > 309 )
                v15 = 309;
              v14 = v15 | *(_WORD *)(v7 + 4 * v4) & 0xC000;
            }
            else
            {
              v14 = *(_WORD *)(v7 + 4 * v4) & 0xC000 | 0x135;
            }
            *(_WORD *)(v7 + 4 * v4) = v14;
          }
        }
      }
      v2 = *((_DWORD *)a2 + 2);
      ++v6;
      ++v4;
      v5 = v2;
    }
    while ( v8 < v2 );
  }
  return 0;
}