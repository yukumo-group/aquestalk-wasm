__int64 __fastcall sub_18000521C(__int64 **a1, __int64 a2, __int64 a3, __int64 a4, int a5, unsigned int a6, int a7)
{
  __int64 result; // rax
  __int64 *v11; // rdx
  __int64 v12; // r10
  int v13; // r8d
  __int64 v14; // rax
  __int64 *v15; // rcx

  a5 = 0;
  result = sub_1800052DC(a1, a2, a6, &a5);
  if ( !(_DWORD)result )
  {
    if ( a7 )
    {
      v11 = *a1;
      v12 = *((__int16 *)*a1 + 4);
      v13 = v12 - 1;
      if ( (int)v12 - 1 >= 0 )
      {
        v14 = *v11;
        if ( *(_BYTE *)(v13 + *v11) == 1 )
        {
          v15 = *a1;
          if ( (int)v12 - 2 >= 0 && (int)v12 - 2 < (int)v12 )
          {
            *(_BYTE *)(v12 + *v11 - 2) = 1;
            v15 = *a1;
          }
          if ( v13 >= *((__int16 *)v15 + 4) )
            goto LABEL_11;
          v14 = *v15;
        }
        *(_BYTE *)(v13 + v14) = -96;
      }
    }
LABEL_11:
    result = sub_1800052DC(a1, a3, a6, &a5);
    if ( !(_DWORD)result )
      return sub_1800052DC(a1, a4, a6, &a5);
  }
  return result;
}