__int64 __fastcall sub_180001F00(__int64 a1, __int16 *a2, _DWORD *a3)
{
  int v3; // r10d
  int v4; // r9d
  int v5; // r11d
  int v6; // eax
  int v7; // edx
  unsigned int v8; // ecx
  unsigned int v9; // eax
  unsigned int v10; // ecx
  unsigned int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  unsigned int v15; // [rsp+4h] [rbp-Ch]
  int v16; // [rsp+38h] [rbp+28h]
  int v17; // [rsp+38h] [rbp+28h]
  int v18; // [rsp+38h] [rbp+28h]
  int v19; // [rsp+38h] [rbp+28h]
  signed int v20; // [rsp+40h] [rbp+30h]
  signed int v21; // [rsp+40h] [rbp+30h]
  signed int v22; // [rsp+48h] [rbp+38h]

  v3 = a2[4];
  v4 = a2[2];
  v5 = a2[6];
  v6 = -1024 * *a2;
  v7 = a2[8];
  v16 = v6;
  v8 = 0x2000000 - (((v4 * (v6 & 0xFFFE)) >> 14) & 0xFFFFFFFC);
  v9 = v4 * ((v6 >> 14) & 0xFFFFFFFC);
  v17 = v16 - (v4 << 10);
  v20 = 2 * v17 - (((int)(v3 * ((v8 - v9) & 0xFFFE)) >> 14) & 0xFFFFFFFC) - v3 * (((int)(v8 - v9) >> 14) & 0xFFFFFFFC);
  v10 = v8 - v9 + 0x1000000 - (((v3 * (v17 & 0xFFFE)) >> 14) & 0xFFFFFFFC);
  v11 = v3 * ((v17 >> 14) & 0xFFFFFFFC);
  v18 = v17 - (v3 << 10);
  v22 = 2 * (v10 - v11) - (((v5 * (v20 & 0xFFFE)) >> 14) & 0xFFFFFFFC) - v5 * ((v20 >> 14) & 0xFFFFFFFC);
  v21 = v18
      + v20
      - (((int)(v5 * ((v10 - v11) & 0xFFFE)) >> 14) & 0xFFFFFFFC)
      - v5 * (((int)(v10 - v11) >> 14) & 0xFFFFFFFC);
  v12 = v10 - v11 + 0x1000000 - (((v5 * (v18 & 0xFFFE)) >> 14) & 0xFFFFFFFC);
  v13 = v5 * ((v18 >> 14) & 0xFFFFFFFC);
  v19 = v18 - (v5 << 10);
  v15 = 2 * v21 - (((v7 * (v22 & 0xFFFE)) >> 14) & 0xFFFFFFFC) - v7 * ((v22 >> 14) & 0xFFFFFFFC);
  *a3 = 0x1000000;
  a3[1] = v19 - (v7 << 10);
  a3[2] = v12 - v13 + 0x1000000 - (((v7 * (v19 & 0xFFFE)) >> 14) & 0xFFFFFFFC) - v7 * ((v19 >> 14) & 0xFFFFFFFC);
  a3[3] = v19
        + v21
        - (((int)(v7 * ((v12 - v13) & 0xFFFE)) >> 14) & 0xFFFFFFFC)
        - v7 * (((int)(v12 - v13) >> 14) & 0xFFFFFFFC);
  a3[4] = v12 - v13 + v22 - (((v7 * (v21 & 0xFFFE)) >> 14) & 0xFFFFFFFC) - v7 * ((v21 >> 14) & 0xFFFFFFFC);
  a3[5] = v15;
  return v15;
}