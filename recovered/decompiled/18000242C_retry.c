__int64 __fastcall sub_18000242C(__int64 a1, __int64 *a2, __int64 a3)
{
  __int64 v3; // rcx
  int v4; // r11d
  _WORD *v5; // rax
  __int16 v6; // r15
  unsigned __int16 v7; // r12
  __int16 v8; // di
  __int16 v9; // bx
  __int16 v10; // r14
  __int16 v11; // si
  __int64 v12; // rax
  int v13; // r11d
  __int64 v14; // r13
  int v15; // r10d
  __int64 v16; // rcx
  char v17; // al
  int v18; // r15d
  unsigned int v19; // ebx
  unsigned __int8 v20; // r10
  __int16 v21; // r11
  unsigned __int16 v22; // ax
  __int64 result; // rax
  int v24; // r10d
  int v25; // ecx
  int v26; // r13d
  int v27; // r9d
  int v28; // r10d
  int v29; // r11d
  unsigned __int16 v30; // r8
  void *v31; // rcx
  __int64 v32; // r11
  unsigned int v33; // ecx
  __int64 v34; // rax
  char v35; // r8
  int v36; // edx
  __int16 v37; // r12
  int v38; // r8d
  int v39; // r10d
  int v40; // ecx
  int v41; // ebx
  __int64 v42; // rax
  int v43; // ecx
  int v44; // r8d
  int v45; // r8d
  int v46; // r10d
  int v47; // ecx
  unsigned __int8 *v48; // rcx
  unsigned __int8 v49; // r10
  unsigned __int8 v50; // r11
  unsigned int v51; // r8d
  int v52; // kr00_4
  char v53; // r8
  unsigned int v54; // r9d
  unsigned int v55; // r8d
  char v56; // dl
  int v57; // eax
  char v58; // cl
  __int64 v59; // rcx
  char v60; // al
  int v61; // r13d
  int v62; // ebx
  int v63; // ecx
  int v64; // r8d
  unsigned int v65; // ebx
  __int64 v66; // rax
  int v67; // ecx
  int v68; // r8d
  int v69; // r10d
  unsigned int v70; // ebx
  __int64 v71; // rax
  int v72; // ecx
  int v73; // r8d
  int v74; // r11d
  unsigned __int16 v75; // [rsp+40h] [rbp-59h]
  unsigned __int16 v76; // [rsp+42h] [rbp-57h]
  int v77; // [rsp+44h] [rbp-55h]
  int v78; // [rsp+44h] [rbp-55h]
  unsigned int v79; // [rsp+44h] [rbp-55h]
  int v80; // [rsp+44h] [rbp-55h]
  unsigned __int16 v81; // [rsp+48h] [rbp-51h]
  __int16 v82; // [rsp+48h] [rbp-51h]
  __int16 v83; // [rsp+4Ch] [rbp-4Dh]
  __int16 v84; // [rsp+50h] [rbp-49h] BYREF
  __int16 v85; // [rsp+54h] [rbp-45h] BYREF
  int v86; // [rsp+58h] [rbp-41h] BYREF
  int v87; // [rsp+5Ch] [rbp-3Dh] BYREF
  __int16 v88; // [rsp+60h] [rbp-39h] BYREF
  _BYTE v89[4]; // [rsp+64h] [rbp-35h] BYREF
  _WORD v90[2]; // [rsp+68h] [rbp-31h] BYREF
  int v91; // [rsp+6Ch] [rbp-2Dh]
  __int16 v92; // [rsp+70h] [rbp-29h]
  __int16 v93; // [rsp+74h] [rbp-25h]
  _BYTE v94[4]; // [rsp+78h] [rbp-21h] BYREF
  _BYTE v95[4]; // [rsp+7Ch] [rbp-1Dh] BYREF
  _BYTE v96[4]; // [rsp+80h] [rbp-19h] BYREF
  _BYTE v97[4]; // [rsp+84h] [rbp-15h] BYREF
  int v98; // [rsp+88h] [rbp-11h]
  __int64 v99; // [rsp+90h] [rbp-9h]
  __int64 v100; // [rsp+98h] [rbp-1h] BYREF
  __int64 v101; // [rsp+A0h] [rbp+7h] BYREF
  __int64 v102; // [rsp+A8h] [rbp+Fh] BYREF
  __int64 v103; // [rsp+100h] [rbp+67h] BYREF
  __int64 *v104; // [rsp+108h] [rbp+6Fh]
  __int64 v105; // [rsp+110h] [rbp+77h]
  int v106; // [rsp+118h] [rbp+7Fh] BYREF

  v105 = a3;
  v104 = a2;
  v103 = a1;
  v3 = 0;
  *(_QWORD *)(a3 + 16) = 0;
  v4 = *((_DWORD *)a2 + 2);
  if ( !v4 )
    return 0;
  v5 = (_WORD *)*a2;
  v6 = 0;
  LOWORD(v106) = 0;
  v91 = 0;
  v7 = *v5 & 0x3FFF;
  v81 = v7;
  if ( v4 <= 0 )
    return 0;
  v8 = v106;
  v9 = 0;
  v10 = v106;
  v11 = v103;
  v99 = 0;
  while ( 1 )
  {
    v12 = sub_180001C38(*a2 + 4 * v3 + 2);
    v14 = v12;
    if ( !v12 )
      return 102;
    v15 = *(unsigned __int8 *)(v12 + 3);
    LOBYTE(v103) = *(_BYTE *)(v12 + 3);
    v16 = *v104;
    v76 = *(_WORD *)(*v104 + 4 * v99) & 0xC000;
    v75 = *(_WORD *)(*v104 + 4 * v99) & 0x3FFF;
    v17 = *(_BYTE *)(v12 + 2);
    switch ( v17 )
    {
      case 1:
        if ( (unsigned __int8)v15 > 1u )
          v92 = *(_WORD *)sub_180001B74(v14, &v100, 1);
        v18 = v15;
        v19 = 0;
        if ( (_BYTE)v15 )
        {
          do
          {
            v8 = *(_WORD *)sub_180001B74(v14, (char *)&v100 + 2, v19);
            LOWORD(v106) = v8;
            v93 = sub_180001C04(v14, v19);
            if ( v19 || v20 <= 1u || BYTE1(v106) <= (unsigned __int8)v21 || HIBYTE(v92) != (_BYTE)v21 )
              v22 = v7 + (v75 - v7) * (unsigned __int16)((int)(v19 << 8) / v18) / 256;
            else
              v22 = v21;
            result = sub_180001C78(v105, v76, v22, (unsigned int)&v106, v21, v93, v93);
            if ( (_DWORD)result )
              return result;
          }
          while ( (int)++v19 < v18 );
        }
        v6 = v93;
        v9 = v8;
        goto LABEL_94;
      case 3:
        LOWORD(v103) = *(_WORD *)(v14 + 4);
        sub_180001B74(v14, &v88, 0xFFFFFFFFLL);
        v9 = v88;
        v25 = v24;
        v26 = 0;
        v77 = v24;
        if ( (_BYTE)v24 )
        {
          v27 = (unsigned __int8)v88 - (unsigned __int8)v106;
          v28 = HIBYTE(v88) - BYTE1(v106);
          v86 = v27;
          v29 = v75 - v7;
          v87 = v28;
          do
          {
            v30 = (v26 << 8) / v25;
            v89[0] = v106 + v30 * v27 / 256;
            v89[1] = BYTE1(v106) + v30 * v28 / 256;
            result = sub_180001C78(
                       v105,
                       v76,
                       (unsigned __int16)(v7 + v29 * v30 / 256),
                       (unsigned int)v89,
                       v30,
                       v6,
                       v103);
            if ( (_DWORD)result )
              return result;
            v25 = v77;
            ++v26;
            v27 = v86;
            v28 = v87;
            v29 = v75 - v7;
          }
          while ( v26 < v77 );
        }
        v6 = v103;
        goto LABEL_94;
      case 2:
        if ( v91 + 1 >= v13 )
          v31 = &unk_18002FD88;
        else
          v31 = (void *)(v16 + 4LL * (v91 + 1) + 2);
        v32 = sub_180001C38(v31);
        if ( !v32 )
          return 102;
        v33 = (unsigned int)v104;
        v34 = *v104 + 4 * v99;
        v35 = *(_BYTE *)(v34 + 2);
        if ( v35 == 43
          && (LOBYTE(v33) = *(_BYTE *)(v34 + 3) - 98, (unsigned __int8)v33 <= 0xFu)
          && (v36 = 33313, _bittest(&v36, v33))
          || v35 == 44 && *(_BYTE *)(v34 + 3) == 107 )
        {
          if ( *(_BYTE *)(v32 + 2) == 1 )
          {
            v37 = *(_WORD *)(v32 + 4) + 4;
          }
          else if ( *(_BYTE *)(v32 + 2) == 3 )
          {
            v37 = *(_WORD *)(v32 + 4);
          }
          else
          {
            v37 = 0;
          }
          LOWORD(v87) = v9;
          sub_180001B74(v14, v94, 0);
          v38 = (unsigned __int8)v103;
          v40 = v39;
          v78 = v39;
          if ( (_BYTE)v103 )
          {
            v86 = v75 - v81;
            do
            {
              v41 = (v40 << 8) / v38;
              v42 = sub_180001B74(v14, (char *)&v100 + 4, (unsigned int)v40);
              v10 = *(_WORD *)sub_180002D64(v43, (unsigned int)&v100 + 6, (unsigned int)&v87, (unsigned int)v94, v42);
              LOWORD(v106) = v10;
              v44 = v86 * (unsigned __int16)v41 / 256;
              LOWORD(v44) = v81 + v44;
              result = sub_180001C78(v105, v76, v44, (unsigned int)&v106, v41, v6, v37);
              if ( (_DWORD)result )
                return result;
              v38 = (unsigned __int8)v103;
              v40 = v78 + 1;
              v78 = v40;
            }
            while ( v40 < (unsigned __int8)v103 );
          }
          v9 = v10;
          v6 = v37;
        }
        else
        {
          if ( *(_BYTE *)(v32 + 2) == 1 )
          {
            v82 = *(_WORD *)(v32 + 4);
          }
          else if ( *(_BYTE *)(v32 + 2) == 3 )
          {
            v82 = *(_WORD *)(v32 + 4);
          }
          else
          {
            v82 = 0;
          }
          sub_180001B74(v32, &v84, 0);
          v45 = (unsigned __int8)v103;
          v47 = v46;
          v9 = v84;
          v79 = v46;
          if ( (_BYTE)v103 )
          {
            v98 = v75 - v7;
            do
            {
              HIDWORD(v102) = (v47 << 8) / v45;
              LOWORD(v87) = *(_WORD *)sub_180001B74(v14, &v101, 0);
              LOWORD(v86) = *(_WORD *)sub_180001B74(v14, (char *)&v101 + 2, 0xFFFFFFFFLL);
              v48 = (unsigned __int8 *)sub_180001B74(v14, (char *)&v101 + 4, v79);
              if ( v49 == v50
                || (v51 = (((unsigned __int8)v9 - (unsigned __int8)v106) << 10) / (v50 - v49), v51 > 0x1000) )
              {
                v54 = v79;
                LOBYTE(v83) = v106
                            + (int)(v79 * ((unsigned __int8)v9 - (unsigned __int8)v106)) / *(unsigned __int8 *)(v14 + 3);
              }
              else
              {
                v52 = v51 * (*v48 - v49);
                v53 = 0;
                v54 = v79;
                if ( (unsigned __int8)v106 + v52 / 1024 > 0 )
                  v53 = v106 + v52 / 1024;
                LOBYTE(v83) = v53;
              }
              if ( BYTE1(v87) == BYTE1(v86)
                || (v55 = ((HIBYTE(v84) - BYTE1(v106)) << 10) / (BYTE1(v86) - BYTE1(v87)), v55 > 0x1000) )
              {
                HIBYTE(v83) = BYTE1(v106) + (int)(v54 * (HIBYTE(v84) - BYTE1(v106))) / *(unsigned __int8 *)(v14 + 3);
              }
              else
              {
                v56 = 0;
                v57 = BYTE1(v106) + (int)(v55 * (HIBYTE(*(unsigned __int16 *)v48) - BYTE1(v87))) / 1024;
                v58 = BYTE1(v106) + (int)(v55 * (HIBYTE(*(unsigned __int16 *)v48) - BYTE1(v87))) / 1024;
                if ( v57 > 0 )
                  v56 = v58;
                HIBYTE(v83) = v56;
              }
              LOWORD(v86) = v83;
              result = sub_180001C78(
                         v105,
                         v76,
                         (unsigned __int16)(v7 + v98 * WORD2(v102) / 256),
                         (unsigned int)&v86,
                         SBYTE4(v102),
                         v6,
                         v82);
              if ( (_DWORD)result )
                return result;
              v45 = (unsigned __int8)v103;
              v47 = v79 + 1;
              v79 = v47;
            }
            while ( v47 < (unsigned __int8)v103 );
          }
          v6 = v82;
        }
        goto LABEL_94;
      case 4:
        v59 = sub_180001C38(v16 + 4LL * v91 + 6);
        if ( !v59 )
          return 102;
        if ( *(_BYTE *)(*v104 + 4 * v99 + 2) == 59
          && ((v60 = *(_BYTE *)(*v104 + 4 * v99 + 3), v60 == 107) || v60 == 118) )
        {
          if ( *(_BYTE *)(v59 + 2) == 1 || *(_BYTE *)(v59 + 2) == 3 )
            v6 = *(_WORD *)(v59 + 4);
          else
            v6 = 0;
          v61 = (unsigned __int8)v103;
          v62 = 0;
          v85 = 0;
          if ( (_BYTE)v103 )
          {
            v63 = v75 - v7;
            LODWORD(v103) = v63;
            do
            {
              v64 = v63 * (unsigned __int16)((v62 << 8) / v61) / 256;
              LOWORD(v64) = v7 + v64;
              result = sub_180001C78(v105, v76, v64, (unsigned int)&v85, 0, v6, v6);
              if ( (_DWORD)result )
                return result;
              v63 = v103;
            }
            while ( ++v62 < v61 );
          }
          v9 = v85;
        }
        else
        {
          if ( *(_BYTE *)(v59 + 2) == 1 || (v6 = 0, *(_BYTE *)(v59 + 2) == 3) )
            v6 = *(_WORD *)(v59 + 4);
          sub_180001B74(v59, v95, 0);
          sub_180001B74(v14, v90, 0xFFFFFFFFLL);
          v65 = 0;
          if ( (_BYTE)v103 )
          {
            v106 = v75 - v7;
            do
            {
              v66 = sub_180001B74(v14, (char *)&v101 + 6, v65);
              sub_180002D64(v67, (unsigned int)v96, (unsigned int)v95, (unsigned int)v90, v66);
              v68 = v106 * (unsigned __int16)((int)(v65 << 8) / (unsigned __int8)v103) / 256;
              LOWORD(v68) = v7 + v68;
              result = sub_180001C78(v105, v76, v68, (unsigned int)v96, 0, v6, v6);
              if ( (_DWORD)result )
                return result;
            }
            while ( (int)++v65 < (unsigned __int8)v103 );
          }
          v9 = v90[0];
        }
        goto LABEL_94;
    }
    if ( v17 == 5 )
      break;
LABEL_95:
    a2 = v104;
    v3 = v99 + 1;
    v7 = v75;
    v81 = v75;
    ++v91;
    v74 = *((_DWORD *)v104 + 2);
    ++v99;
    if ( v91 >= v74 )
      return 0;
  }
  LOWORD(v106) = v9;
  sub_180001B74(v14, v97, 0);
  v80 = v69;
  v70 = 0;
  if ( !(_BYTE)v69 )
  {
LABEL_93:
    v9 = v11;
LABEL_94:
    LOWORD(v106) = v9;
    goto LABEL_95;
  }
  v98 = v75 - v7;
  while ( 1 )
  {
    v71 = sub_180001B74(v14, &v102, v70);
    v11 = *(_WORD *)sub_180002D64(v72, (unsigned int)&v102 + 2, (unsigned int)&v106, (unsigned int)v97, v71);
    LOWORD(v103) = v11;
    v73 = v98 * (unsigned __int16)((int)(v70 << 8) / v80) / 256;
    LOWORD(v73) = v7 + v73;
    result = sub_180001C78(v105, v76, v73, (unsigned int)&v103, 0, v6, v6);
    if ( (_DWORD)result )
      return result;
    if ( (int)++v70 >= v80 )
      goto LABEL_93;
  }
}