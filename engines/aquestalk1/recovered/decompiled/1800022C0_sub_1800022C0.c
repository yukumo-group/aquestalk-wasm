__int64 __fastcall sub_1800022C0(__int64 a1)
{
  __int64 v1; // rdx
  __int64 result; // rax
  int v4; // ecx

  v1 = *(int *)(a1 + 20);
  if ( (int)v1 >= *(_DWORD *)(a1 + 16) )
    return 0;
  result = v1 + *(_QWORD *)(a1 + 8);
  if ( *(_WORD *)(result + 2) )
  {
    v4 = *(unsigned __int16 *)(result + 2);
    *(_DWORD *)(a1 + 24) = 0;
    *(_DWORD *)(a1 + 20) = v1 + 4 * v4 + 8;
  }
  else
  {
    *(_DWORD *)(a1 + 16) = v1;
  }
  return result;
}