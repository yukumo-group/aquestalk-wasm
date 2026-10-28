//===== _DT_INIT @ 00104f28 size=24 =====

void _DT_INIT(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  entry(param_3,0x104f31);
  FUN_00105040();
  FUN_00110820();
  return;
}


//===== FUN_00104f40 @ 00104f40 size=12 =====

void FUN_00104f40(void)

{
  (*(code *)PTR_0035cf30)();
  return;
}


//===== malloc @ 00104f50 size=6 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_malloc_0035cf38)();
  return pvVar1;
}


//===== free @ 00104f60 size=6 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
  (*(code *)PTR_free_0035cf40)();
  return;
}


//===== __cxa_finalize @ 00104f70 size=6 =====

void __cxa_finalize(void)

{
  (*(code *)PTR___cxa_finalize_0035cf48)();
  return;
}


//===== memcpy @ 00104f80 size=6 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memcpy_0035cf50)();
  return pvVar1;
}


//===== _Unwind_Resume @ 00104f90 size=6 =====

void _Unwind_Resume(void)

{
  (*(code *)PTR__Unwind_Resume_0035cf58)();
  return;
}


//===== entry @ 00104fa0 size=23 =====

void processEntry entry(void)

{
  if (PTR___gmon_start___0035cf08 != (undefined *)0x0) {
    (*(code *)PTR___gmon_start___0035cf08)();
  }
  return;
}


//===== FUN_00104fc0 @ 00104fc0 size=119 =====

/* WARNING: Removing unreachable block (ram,0x0010500b) */
/* WARNING: Removing unreachable block (ram,0x00105010) */

void FUN_00104fc0(void)

{
  if (DAT_0035cf68 == '\0') {
    if (PTR___cxa_finalize_0035cf18 != (undefined *)0x0) {
      __cxa_finalize(&PTR_LOOP_0035cd60);
    }
    DAT_0035cf68 = '\x01';
  }
  return;
}


//===== FUN_00105040 @ 00105040 size=38 =====

void FUN_00105040(void)

{
  if ((DAT_0035a020 != 0) && (PTR__Jv_RegisterClasses_0035cf10 != (undefined *)0x0)) {
    (*(code *)PTR__Jv_RegisterClasses_0035cf10)(&DAT_0035a020);
    return;
  }
  return;
}


//===== AquesTalk_Synthe_Utf8 @ 0010506c size=259 =====

undefined8 AquesTalk_Synthe_Utf8(long param_1,char *param_2,int *param_3)

{
  int iVar1;
  void *__ptr;
  undefined4 local_24;
  undefined8 local_20;
  
  local_24 = 0;
  local_20 = 0;
  if (((param_1 == 0) || (param_2 == (char *)0x0)) || (param_3 == (int *)0x0)) {
    if (param_3 != (int *)0x0) {
      *param_3 = 0x6d;
    }
    local_20 = 0;
  }
  else if (*param_2 == '\0') {
    *param_3 = 0x68;
    local_20 = 0;
  }
  else {
    iVar1 = FUN_00106658(param_2);
    __ptr = malloc((long)(iVar1 + 1));
    if (__ptr == (void *)0x0) {
      local_24 = 0x65;
    }
    else {
      FUN_001067b6(__ptr,param_2);
      local_20 = FUN_00105407(param_1,__ptr,param_3);
      free(__ptr);
    }
    if (local_24 != 0) {
      *param_3 = local_24;
    }
  }
  return local_20;
}


//===== AquesTalk_Synthe @ 0010516f size=276 =====

undefined8 AquesTalk_Synthe(long param_1,char *param_2,int *param_3)

{
  int iVar1;
  void *__ptr;
  undefined4 local_24;
  undefined8 local_20;
  
  local_20 = 0;
  if (((param_1 == 0) || (param_2 == (char *)0x0)) || (param_3 == (int *)0x0)) {
    if (param_3 != (int *)0x0) {
      *param_3 = 0x6d;
    }
    local_20 = 0;
  }
  else if (*param_2 == '\0') {
    *param_3 = 0x68;
    local_20 = 0;
  }
  else {
    iVar1 = FUN_00106658(param_2);
    iVar1 = iVar1 * 2 + 1;
    __ptr = malloc((long)iVar1);
    if (__ptr == (void *)0x0) {
      local_24 = 0x65;
    }
    else {
      local_24 = FUN_00105674(param_2,__ptr,iVar1);
      if (local_24 == 0) {
        local_20 = FUN_00105407(param_1,__ptr,param_3);
      }
    }
    if (__ptr != (void *)0x0) {
      free(__ptr);
    }
    if (local_24 != 0) {
      *param_3 = local_24;
    }
  }
  return local_20;
}


//===== AquesTalk_Synthe_Utf16 @ 00105283 size=303 =====

undefined8 AquesTalk_Synthe_Utf16(long param_1,short *param_2,int *param_3)

{
  int iVar1;
  void *__ptr;
  int local_24;
  undefined8 local_20;
  int local_10;
  
  local_20 = 0;
  if (((param_1 == 0) || (param_2 == (short *)0x0)) || (param_3 == (int *)0x0)) {
    if (param_3 != (int *)0x0) {
      *param_3 = 0x6d;
    }
    local_20 = 0;
  }
  else if (*param_2 == 0) {
    *param_3 = 0x68;
    local_20 = 0;
  }
  else {
    for (local_10 = 0; param_2[local_10] != 0; local_10 = local_10 + 1) {
    }
    iVar1 = local_10 * 4 + 1;
    __ptr = malloc((long)iVar1);
    if (__ptr == (void *)0x0) {
      local_24 = 0x65;
    }
    else {
      local_24 = FUN_001057c2(param_2,__ptr,iVar1);
      if (local_24 == 0) {
        local_20 = FUN_00105407(param_1,__ptr,param_3);
      }
    }
    if (__ptr != (void *)0x0) {
      free(__ptr);
    }
    if (local_24 != 0) {
      *param_3 = local_24;
    }
  }
  return local_20;
}


//===== AquesTalk_FreeWave @ 001053b2 size=33 =====

void AquesTalk_FreeWave(void *param_1)

{
  if (param_1 != (void *)0x0) {
    free(param_1);
  }
  return;
}


//===== AquesTalk_SetDevKey @ 001053d3 size=26 =====

void AquesTalk_SetDevKey(undefined8 param_1)

{
  FUN_0010732c(param_1);
  return;
}


//===== AquesTalk_SetUsrKey @ 001053ed size=26 =====

void AquesTalk_SetUsrKey(undefined8 param_1)

{
  FUN_00107346(param_1);
  return;
}


//===== FUN_00105407 @ 00105407 size=590 =====

long FUN_00105407(undefined4 *param_1,undefined8 param_2,int *param_3)

{
  long lVar1;
  undefined1 local_2e8 [654];
  short local_5a;
  undefined1 local_58 [28];
  int local_3c;
  long local_38;
  void *local_30;
  long local_28;
  int local_20;
  int local_1c;
  
  local_3c = 0;
  local_38 = 0;
  local_30 = malloc(0x8000);
  if (local_30 == (void *)0x0) {
    *param_3 = 0x65;
    lVar1 = 0;
  }
  else {
    local_28 = FUN_00106ad0(local_30,0x8000);
    if (local_28 == 0) {
      *param_3 = 100;
      lVar1 = 0;
    }
    else {
      FUN_00105a4c(local_58);
      FUN_00106b7f(local_28,*param_1,param_1[2],param_1[1],param_1[5],param_1[3],param_1[4]);
      local_1c = param_1[6];
      if (local_1c < 0x32) {
        local_1c = 0x32;
      }
      else if (200 < local_1c) {
        local_1c = 200;
      }
      local_20 = (local_1c * 16000) / 100;
      local_3c = FUN_00106cf0(local_28,param_2);
      if (local_3c == 0) {
        FUN_00106cb0(local_28,0x200);
        while (local_3c = FUN_00106efe(local_28,local_2e8,&local_5a), local_3c != 1) {
          if (local_3c != 0) goto LAB_0010560f;
          FUN_00105a92(local_58,local_2e8,(int)local_5a);
        }
        local_38 = FUN_00105abe(local_58,local_20,param_3);
        local_3c = 0;
        if ((local_38 == 0) && (*param_3 == 0)) {
          *param_3 = 0x68;
        }
      }
LAB_0010560f:
      if (local_30 != (void *)0x0) {
        free(local_30);
      }
      lVar1 = local_38;
      if (local_3c != 0) {
        *param_3 = local_3c;
      }
      FUN_00105a78(local_58);
    }
  }
  return lVar1;
}


//===== FUN_00105674 @ 00105674 size=334 =====

undefined8 FUN_00105674(char *param_1,undefined1 *param_2,int param_3)

{
  undefined8 uVar1;
  undefined1 *puVar2;
  char *local_20;
  int local_14;
  
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    uVar1 = 0x68;
  }
  else if ((param_2 == (undefined1 *)0x0) || (param_3 < 2)) {
    uVar1 = 100;
  }
  else {
    local_14 = 0;
    *param_2 = 0;
    local_20 = param_1;
    while (*local_20 != '\0') {
      if (*local_20 < '\0') {
        puVar2 = (undefined1 *)FUN_0010592f(local_20);
        if (puVar2 == (undefined1 *)0x0) {
          return 0x69;
        }
        if (param_3 < local_14 + 4) {
          return 100;
        }
        param_2[local_14] = *puVar2;
        param_2[local_14 + 1] = puVar2[1];
        param_2[local_14 + 2] = puVar2[2];
        local_14 = local_14 + 3;
        param_2[local_14] = 0;
        local_20 = local_20 + 2;
      }
      else {
        if (param_3 < local_14 + 2) {
          return 100;
        }
        param_2[local_14] = *local_20;
        local_14 = local_14 + 1;
        local_20 = local_20 + 1;
        param_2[local_14] = 0;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


//===== FUN_001057c2 @ 001057c2 size=365 =====

undefined8 FUN_001057c2(ushort *param_1,undefined1 *param_2,int param_3)

{
  undefined8 uVar1;
  undefined1 *puVar2;
  ushort *local_20;
  int local_14;
  
  if ((param_1 == (ushort *)0x0) || (*param_1 == 0)) {
    uVar1 = 0x68;
  }
  else if ((param_2 == (undefined1 *)0x0) || (param_3 < 2)) {
    uVar1 = 100;
  }
  else {
    local_14 = 0;
    *param_2 = 0;
    local_20 = param_1;
    if (*param_1 == 0xfeff) {
      local_20 = param_1 + 1;
    }
    while (*local_20 != 0) {
      if (*local_20 < 0x80) {
        if (param_3 < local_14 + 2) {
          return 100;
        }
        param_2[local_14] = (char)*local_20;
        local_14 = local_14 + 1;
        local_20 = local_20 + 1;
        param_2[local_14] = 0;
      }
      else {
        puVar2 = (undefined1 *)FUN_001059d7(*local_20);
        if (puVar2 == (undefined1 *)0x0) {
          return 0x69;
        }
        if (param_3 < local_14 + 4) {
          return 100;
        }
        param_2[local_14] = *puVar2;
        param_2[local_14 + 1] = puVar2[1];
        param_2[local_14 + 2] = puVar2[2];
        local_14 = local_14 + 3;
        param_2[local_14] = 0;
        local_20 = local_20 + 1;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


//===== FUN_0010592f @ 0010592f size=168 =====

undefined * FUN_0010592f(char *param_1)

{
  uint local_c;
  
  local_c = 0;
  while( true ) {
    if (0xa2 < local_c) {
      return (undefined *)0x0;
    }
    if ((*param_1 == (&DAT_00110960)[(long)(int)local_c * 10]) &&
       (param_1[1] == (&DAT_00110961)[(long)(int)local_c * 10])) break;
    local_c = local_c + 1;
  }
  return &UNK_00110964 + (long)(int)local_c * 10;
}


//===== FUN_001059d7 @ 001059d7 size=117 =====

undefined * FUN_001059d7(short param_1)

{
  uint local_c;
  
  local_c = 0;
  while( true ) {
    if (0xa2 < local_c) {
      return (undefined *)0x0;
    }
    if (*(short *)(&DAT_00110968 + (long)(int)local_c * 10) == param_1) break;
    local_c = local_c + 1;
  }
  return &UNK_00110964 + (long)(int)local_c * 10;
}


//===== FUN_00105a4c @ 00105a4c size=43 =====

void FUN_00105a4c(undefined8 *param_1)

{
  *param_1 = 0;
  *(undefined4 *)(param_1 + 1) = 0;
  *(undefined4 *)((long)param_1 + 0xc) = 0;
  return;
}


//===== FUN_00105a78 @ 00105a78 size=26 =====

void FUN_00105a78(undefined8 param_1)

{
  FUN_00105c66(param_1);
  return;
}


//===== FUN_00105a92 @ 00105a92 size=43 =====

void FUN_00105a92(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  FUN_00105cb0(param_1,param_2,param_3);
  return;
}


//===== FUN_00105abe @ 00105abe size=423 =====

long FUN_00105abe(long *param_1,undefined4 param_2,undefined4 *param_3)

{
  uint uVar1;
  void *__dest;
  long lVar2;
  
  if (*param_1 == 0) {
    *param_3 = 0;
    lVar2 = 0;
  }
  else {
    uVar1 = *(uint *)((long)param_1 + 0xc);
    __dest = (void *)*param_1;
    memcpy(__dest,&DAT_00110fbe,4);
    memcpy((void *)((long)__dest + 8),&DAT_00110fc3,4);
    memcpy((void *)((long)__dest + 0xc),&DAT_00110fc8,4);
    memcpy((void *)((long)__dest + 0x24),&DAT_00110fcd,4);
    *(undefined4 *)((long)__dest + 0x10) = 0x10;
    *(undefined2 *)((long)__dest + 0x14) = 1;
    *(undefined2 *)((long)__dest + 0x16) = 1;
    *(undefined2 *)((long)__dest + 0x22) = 0x10;
    *(undefined4 *)((long)__dest + 0x18) = param_2;
    *(uint *)((long)__dest + 0x1c) =
         (uint)*(ushort *)((long)__dest + 0x16) * *(int *)((long)__dest + 0x18) *
         (uint)(*(ushort *)((long)__dest + 0x22) >> 3);
    *(ushort *)((long)__dest + 0x20) =
         *(short *)((long)__dest + 0x16) * (*(ushort *)((long)__dest + 0x22) >> 3);
    *(uint *)((long)__dest + 0x28) =
         (uint)*(ushort *)((long)__dest + 0x20) * (int)((ulong)uVar1 - 0x2c >> 1);
    *(int *)((long)__dest + 4) = *(int *)((long)__dest + 0x28) + 0x24;
    *param_3 = *(undefined4 *)((long)param_1 + 0xc);
    lVar2 = *param_1;
    *param_1 = 0;
    *(undefined4 *)((long)param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 1) = 0;
  }
  return lVar2;
}


//===== FUN_00105c66 @ 00105c66 size=74 =====

void FUN_00105c66(long *param_1)

{
  if (*param_1 != 0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  *(undefined4 *)((long)param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 1) = 0;
  return;
}


//===== FUN_00105cb0 @ 00105cb0 size=220 =====

int FUN_00105cb0(long *param_1,undefined2 *param_2,int param_3)

{
  int iVar1;
  undefined2 *local_28;
  int local_c;
  
  if (((*param_1 != 0) || (iVar1 = FUN_00105d8c(param_1), iVar1 == 0)) &&
     (((ulong)*(uint *)((long)param_1 + 0xc) + (long)param_3 * 2 < (ulong)*(uint *)(param_1 + 1) ||
      (iVar1 = FUN_00105de4(param_1,param_3 * 2), iVar1 == 0)))) {
    local_28 = param_2;
    for (local_c = 0; local_c < param_3; local_c = local_c + 1) {
      *(undefined2 *)(*param_1 + (ulong)*(uint *)((long)param_1 + 0xc)) = *local_28;
      local_28 = local_28 + 1;
      *(int *)((long)param_1 + 0xc) = *(int *)((long)param_1 + 0xc) + 2;
    }
    iVar1 = 0;
  }
  return iVar1;
}


//===== FUN_00105d8c @ 00105d8c size=87 =====

undefined8 FUN_00105d8c(long *param_1)

{
  void *pvVar1;
  undefined8 uVar2;
  
  *(undefined4 *)(param_1 + 1) = 0x8000;
  pvVar1 = malloc((ulong)*(uint *)(param_1 + 1));
  *param_1 = (long)pvVar1;
  if (*param_1 == 0) {
    uVar2 = 0x65;
  }
  else {
    *(undefined4 *)((long)param_1 + 0xc) = 0x2c;
    uVar2 = 0;
  }
  return uVar2;
}


//===== FUN_00105de4 @ 00105de4 size=153 =====

undefined8 FUN_00105de4(undefined8 *param_1,int param_2)

{
  void *__dest;
  undefined8 uVar1;
  
  if (param_2 < 0) {
    param_2 = param_2 + 0x7fff;
  }
  *(int *)(param_1 + 1) = *(int *)(param_1 + 1) + ((param_2 >> 0xf) + 1) * 0x8000;
  __dest = malloc((ulong)*(uint *)(param_1 + 1));
  if (__dest == (void *)0x0) {
    uVar1 = 0x65;
  }
  else {
    memcpy(__dest,(void *)*param_1,(ulong)*(uint *)((long)param_1 + 0xc));
    free((void *)*param_1);
    *param_1 = __dest;
    uVar1 = 0;
  }
  return uVar1;
}


//===== FUN_00105e80 @ 00105e80 size=255 =====

int FUN_00105e80(char *param_1,undefined8 param_2)

{
  int iVar1;
  char *local_18;
  int local_c;
  
  if (param_1 == (char *)0x0) {
    iVar1 = 100;
  }
  else {
    local_18 = param_1;
    if (*param_1 == '\0') {
      iVar1 = 0;
    }
    else {
      do {
        if (*local_18 == '\0') break;
        if (((*local_18 < 'A') || ('Z' < *local_18)) && ((*local_18 < 'a' || ('z' < *local_18)))) {
          if ((*local_18 < '0') || ('9' < *local_18)) {
            local_c = FUN_00106152(&local_18,param_2);
          }
          else {
            local_c = FUN_00106050(&local_18,param_2);
          }
        }
        else {
          local_c = FUN_00105f7f(&local_18,param_2);
        }
        if (local_c != 0) {
          return local_c;
        }
      } while (*local_18 != '\0');
      iVar1 = 0;
    }
  }
  return iVar1;
}


//===== FUN_00105f7f @ 00105f7f size=209 =====

int FUN_00105f7f(undefined8 *param_1,undefined8 param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *local_18;
  
  pcVar2 = (char *)*param_1;
  local_18 = pcVar2;
LAB_00105fa6:
  do {
    local_18 = local_18 + 1;
    if ('@' < *local_18) {
      if (*local_18 < '[') goto LAB_00105fa6;
    }
    if ((*local_18 < 'a') || ('z' < *local_18)) {
      cVar1 = *local_18;
      *local_18 = '\0';
      iVar3 = FUN_00106218(pcVar2,param_2);
      if ((iVar3 == 0) && ((cVar1 == '\0' || (iVar3 = FUN_00107af2(param_2,7), iVar3 == 0)))) {
        *local_18 = cVar1;
        *param_1 = local_18;
        iVar3 = 0;
      }
      return iVar3;
    }
  } while( true );
}


//===== FUN_00106050 @ 00106050 size=227 =====

int FUN_00106050(undefined8 *param_1,undefined8 param_2)

{
  int iVar1;
  undefined1 local_38 [8];
  int local_30;
  char local_29;
  char *local_28;
  char *local_20;
  
  local_20 = (char *)*param_1;
  local_28 = local_20;
  do {
    local_28 = local_28 + 1;
    if (*local_28 < '0') break;
  } while (*local_28 < ':');
  local_29 = *local_28;
  *local_28 = '\0';
  FUN_0010e3bc(local_38);
  local_30 = FUN_0010e3d0(local_38,local_20,param_2);
  if ((local_30 == 0) && ((local_29 == '\0' || (local_30 = FUN_00107af2(param_2,7), local_30 == 0)))
     ) {
    *local_28 = local_29;
    *param_1 = local_28;
  }
  iVar1 = local_30;
  FUN_0010e3c6(local_38);
  return iVar1;
}


//===== FUN_00106152 @ 00106152 size=198 =====

int FUN_00106152(long *param_1,undefined8 param_2)

{
  char *pcVar1;
  int iVar2;
  uint local_1c;
  char *local_18;
  
  pcVar1 = (char *)*param_1;
  local_18 = &DAT_00110fe0;
  local_1c = 0;
  do {
    if (0x14 < local_1c) {
LAB_00106202:
      *param_1 = (long)(pcVar1 + 1);
      return 0;
    }
    if (*pcVar1 == *local_18) {
      iVar2 = FUN_00107b42(param_2,local_18 + 1);
      if (iVar2 != 0) {
        return iVar2;
      }
      if ((pcVar1[1] != '\0') && (iVar2 = FUN_00107af2(param_2,7), iVar2 != 0)) {
        return iVar2;
      }
      goto LAB_00106202;
    }
    local_18 = local_18 + 8;
    local_1c = local_1c + 1;
  } while( true );
}


//===== FUN_00106218 @ 00106218 size=381 =====

int FUN_00106218(char *param_1,undefined8 param_2)

{
  int iVar1;
  char *local_30;
  int local_1c;
  uint local_c;
  
  local_1c = 0;
  local_30 = param_1;
  do {
    if (*local_30 < '[') {
      local_c = (int)*local_30 - 0x41;
    }
    else {
      local_c = (int)*local_30 - 0x61;
    }
    if (local_30[1] == '\0') {
      iVar1 = FUN_00107b42(param_2,&UNK_001110a6 + (ulong)local_c * 0xc);
      return iVar1;
    }
    if (local_1c == 3) {
      iVar1 = FUN_00107b42(param_2,&UNK_001110a6 + (ulong)local_c * 0xc);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_00107af2(param_2,7);
      if (iVar1 != 0) {
        return iVar1;
      }
      local_1c = 0;
    }
    else {
      iVar1 = FUN_00107b42(param_2,&DAT_001110a0 + (ulong)local_c * 0xc);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_00107af2(param_2,4);
      if (iVar1 != 0) {
        return iVar1;
      }
      local_1c = local_1c + 1;
    }
    local_30 = local_30 + 1;
  } while( true );
}


//===== FUN_00106398 @ 00106398 size=139 =====

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 FUN_00106398(undefined8 param_1)

{
  undefined8 uVar1;
  undefined1 local_18;
  undefined1 uStack_17;
  undefined2 uStack_12;
  
  uVar1 = FUN_001064f3(param_1);
  uVar1 = FUN_001065c0(uVar1);
  local_18 = (char)uVar1;
  if (local_18 == 'e') {
    uStack_17 = (byte)((ulong)uVar1 >> 8);
    if (uStack_17 < 10) {
      uVar1 = 1;
    }
    else {
      uStack_12 = (ushort)((ulong)uVar1 >> 0x30);
      if ((uStack_12 & 0xff) == 0x56) {
        DAT_0035cf78 = uStack_12;
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


//===== FUN_00106423 @ 00106423 size=164 =====

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 FUN_00106423(undefined8 param_1)

{
  undefined8 uVar1;
  undefined1 local_18;
  undefined1 uStack_17;
  undefined2 uStack_14;
  undefined2 uStack_12;
  
  uVar1 = FUN_001064f3(param_1);
  uVar1 = FUN_001065c0(uVar1);
  local_18 = (char)uVar1;
  if ((local_18 == 'e') || (local_18 == -1)) {
    uStack_17 = (byte)((ulong)uVar1 >> 8);
    if (uStack_17 < 10) {
      uVar1 = 1;
    }
    else {
      uStack_12 = (ushort)((ulong)uVar1 >> 0x30);
      if ((uStack_12 & 0xff) == 0x17) {
        if (uStack_12 == 0x517) {
          uStack_14 = (undefined2)((ulong)uVar1 >> 0x20);
          DAT_0035cf7a = uStack_14;
        }
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


//===== FUN_001064c7 @ 001064c7 size=31 =====

bool FUN_001064c7(void)

{
  return DAT_0035cf78 != 0x5856;
}


//===== FUN_001064e6 @ 001064e6 size=13 =====

undefined2 FUN_001064e6(void)

{
  return DAT_0035cf7a;
}


//===== FUN_001064f3 @ 001064f3 size=205 =====

long FUN_001064f3(char *param_1)

{
  bool bVar1;
  char *local_20;
  long local_18;
  int local_10;
  int local_c;
  
  local_18 = 0;
  local_10 = 0;
  local_20 = param_1;
  while( true ) {
    if ((local_10 < 0x10) && (*local_20 != '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) break;
    if (*local_20 != '-') {
      if ((*local_20 < '0') || ('9' < *local_20)) {
        if ((*local_20 < 'A') || ('F' < *local_20)) {
          local_c = 0;
        }
        else {
          local_c = *local_20 + -0x37;
        }
      }
      else {
        local_c = *local_20 + -0x30;
      }
      local_18 = local_18 * 0x10 + (long)local_c;
      local_10 = local_10 + 1;
    }
    local_20 = local_20 + 1;
  }
  return local_18;
}


//===== FUN_001065c0 @ 001065c0 size=151 =====

ulong FUN_001065c0(ulong param_1)

{
  ulong local_20;
  ushort local_10;
  int local_c;
  
  local_20 = param_1 ^ 0xd271ba9df61eed07;
  for (local_10 = 0; local_10 < 0x56f; local_10 = local_10 + 1) {
    local_c = 0;
    while ((local_c < 7 && ((ushort)(byte)(&DAT_001111d8)[local_c] != (ushort)(local_20 >> 0x3d))))
    {
      local_c = local_c + 1;
    }
    local_20 = local_20 << 3 | (ulong)((0x56e - (uint)local_10) + local_c & 7);
  }
  return local_20;
}


//===== FUN_00106658 @ 00106658 size=47 =====

int FUN_00106658(char *param_1)

{
  char cVar1;
  char *local_20;
  int local_c;
  
  local_c = 0;
  local_20 = param_1;
  while (cVar1 = *local_20, local_20 = local_20 + 1, cVar1 != '\0') {
    local_c = local_c + 1;
  }
  return local_c;
}


//===== FUN_00106687 @ 00106687 size=86 =====

int FUN_00106687(char *param_1,char *param_2)

{
  char *local_28;
  char *local_20;
  
  local_20 = param_1;
  for (local_28 = param_2;
      (((int)*local_20 - (int)*local_28 == 0 && (*local_20 != '\0')) && (*local_28 != '\0'));
      local_28 = local_28 + 1) {
    local_20 = local_20 + 1;
  }
  return (int)*local_20 - (int)*local_28;
}


//===== FUN_001066dd @ 001066dd size=120 =====

int FUN_001066dd(char *param_1,char *param_2,int param_3)

{
  char *local_28;
  char *local_20;
  int local_10;
  
  local_10 = 0;
  local_28 = param_2;
  local_20 = param_1;
  while( true ) {
    if (param_3 <= local_10) {
      return 0;
    }
    if ((int)*local_20 - (int)*local_28 != 0) {
      return (int)*local_20 - (int)*local_28;
    }
    if (*local_20 == '\0') {
      return 0;
    }
    if (*local_28 == '\0') break;
    local_20 = local_20 + 1;
    local_28 = local_28 + 1;
    local_10 = local_10 + 1;
  }
  return 0;
}


//===== FUN_00106755 @ 00106755 size=97 =====

char * FUN_00106755(char *param_1,char *param_2)

{
  char *local_28;
  char *local_20;
  
  for (local_20 = param_1; local_28 = param_2, *local_20 != '\0'; local_20 = local_20 + 1) {
  }
  for (; *local_28 != '\0'; local_28 = local_28 + 1) {
    *local_20 = *local_28;
    local_20 = local_20 + 1;
  }
  *local_20 = '\0';
  return param_1;
}


//===== FUN_001067b6 @ 001067b6 size=74 =====

char * FUN_001067b6(char *param_1,char *param_2)

{
  char *local_28;
  char *local_20;
  
  local_20 = param_1;
  for (local_28 = param_2; *local_28 != '\0'; local_28 = local_28 + 1) {
    *local_20 = *local_28;
    local_20 = local_20 + 1;
  }
  *local_20 = '\0';
  return param_1;
}


//===== FUN_00106800 @ 00106800 size=99 =====

char * FUN_00106800(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  bool bVar2;
  int local_2c;
  char *local_28;
  char *local_20;
  
  local_2c = param_3;
  local_28 = param_2;
  local_20 = param_1;
  do {
    bVar2 = local_2c == 0;
    local_2c = local_2c + -1;
    if (bVar2) {
LAB_00106854:
      bVar2 = false;
    }
    else {
      *local_20 = *local_28;
      cVar1 = *local_20;
      local_20 = local_20 + 1;
      local_28 = local_28 + 1;
      if (cVar1 == '\0') goto LAB_00106854;
      bVar2 = true;
    }
    if (!bVar2) {
      return param_1;
    }
  } while( true );
}


//===== FUN_00106863 @ 00106863 size=61 =====

char * FUN_00106863(char *param_1,char param_2)

{
  char *local_10;
  
  local_10 = param_1;
  while( true ) {
    if (*local_10 == param_2) {
      return local_10;
    }
    if (*local_10 == '\0') break;
    local_10 = local_10 + 1;
  }
  return (char *)0x0;
}


//===== FUN_001068a0 @ 001068a0 size=174 =====

int FUN_001068a0(char *param_1,char *param_2)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  char *local_28;
  char *local_20;
  
  local_28 = param_2;
  local_20 = param_1;
  do {
    if ((*local_20 < '[') && ('@' < *local_20)) {
      cVar2 = *local_20 + ' ';
    }
    else {
      cVar2 = *local_20;
    }
    if ((*local_28 < '[') && ('@' < *local_28)) {
      cVar3 = *local_28 + ' ';
    }
    else {
      cVar3 = *local_28;
    }
    local_20 = local_20 + 1;
    local_28 = local_28 + 1;
    if ((cVar2 == '\0') || (cVar2 != cVar3)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
  } while (bVar1);
  if (cVar2 == '\0') {
    iVar4 = 0;
  }
  else {
    iVar4 = (int)cVar2 - (int)cVar3;
  }
  return iVar4;
}


//===== FUN_0010694e @ 0010694e size=127 =====

int FUN_0010694e(char *param_1,char *param_2)

{
  char *local_20;
  char *local_18;
  int local_c;
  
  local_c = 0;
  local_20 = param_1;
  while( true ) {
    local_18 = param_2;
    if (*local_20 == '\0') {
      return local_c;
    }
    for (; (*local_18 != '\0' && (*local_20 != *local_18)); local_18 = local_18 + 1) {
    }
    if (*local_18 == '\0') break;
    local_c = local_c + 1;
    local_20 = local_20 + 1;
  }
  return local_c;
}


//===== FUN_001069cd @ 001069cd size=105 =====

char * FUN_001069cd(char *param_1,char *param_2)

{
  char *local_18;
  char *local_10;
  
  local_18 = param_1;
  do {
    local_10 = param_2;
    if (*local_18 == '\0') {
      return (char *)0x0;
    }
    for (; *local_10 != '\0'; local_10 = local_10 + 1) {
      if (*local_18 == *local_10) {
        return local_18;
      }
    }
    local_18 = local_18 + 1;
  } while( true );
}


//===== FUN_00106a36 @ 00106a36 size=153 =====

long FUN_00106a36(long param_1,undefined8 param_2,long *param_3)

{
  uint uVar1;
  undefined1 *puVar2;
  long local_20;
  
  local_20 = param_1;
  if (param_1 == 0) {
    local_20 = *param_3;
  }
  if (local_20 == 0) {
    local_20 = 0;
  }
  else {
    uVar1 = FUN_0010694e(local_20,param_2);
    local_20 = local_20 + (ulong)uVar1;
    puVar2 = (undefined1 *)FUN_001069cd(local_20,param_2);
    if (puVar2 == (undefined1 *)0x0) {
      *param_3 = 0;
    }
    else {
      *param_3 = (long)(puVar2 + 1);
      *puVar2 = 0;
    }
  }
  return local_20;
}


//===== FUN_00106ad0 @ 00106ad0 size=175 =====

undefined1  [16] FUN_00106ad0(undefined4 *param_1,int param_2,ulong param_3)

{
  undefined1 auVar1 [16];
  
  if (param_2 == 0x8000) {
    param_1[3] = 0xffffffff;
    param_1[5] = 0;
    param_1[6] = 100;
    param_1[7] = 100;
    param_1[8] = 100;
    param_1[9] = 100;
    param_1[10] = 100;
    param_1[4] = 0;
    param_3 = 0x6400 % (long)(int)param_1[7] & 0xffffffff;
    param_1[1] = (int)(0x6400 / (long)(int)param_1[7]);
    *param_1 = 0x35ca;
  }
  else {
    param_1 = (undefined4 *)0x0;
  }
  auVar1._8_8_ = param_3;
  auVar1._0_8_ = param_1;
  return auVar1;
}


//===== FUN_00106b7f @ 00106b7f size=305 =====

undefined8
FUN_00106b7f(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  undefined8 uVar1;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  if (param_1 == (int *)0x0) {
    uVar1 = 0x6d;
  }
  else if (*param_1 == 0x35ca) {
    local_14 = param_2;
    if (param_2 < 0) {
      local_14 = 0;
    }
    if (2 < local_14) {
      local_14 = 2;
    }
    local_18 = param_3;
    if (param_3 < 0) {
      local_18 = 0;
    }
    if (300 < local_18) {
      local_18 = 300;
    }
    local_1c = param_4;
    if (param_4 < 0x32) {
      local_1c = 0x32;
    }
    if (300 < local_1c) {
      local_1c = 300;
    }
    local_20 = param_5;
    if (param_5 < 0) {
      local_20 = 0;
    }
    if (200 < local_20) {
      local_20 = 200;
    }
    local_24 = param_6;
    if (param_6 < 0x14) {
      local_24 = 0x14;
    }
    if (200 < local_24) {
      local_24 = 200;
    }
    if (param_7 < 0) {
      param_7 = 0;
    }
    if (200 < param_7) {
      param_7 = 200;
    }
    param_1[5] = local_14;
    param_1[6] = local_18;
    param_1[7] = local_1c;
    param_1[8] = local_20;
    param_1[9] = local_24;
    param_1[10] = param_7;
    uVar1 = 0;
  }
  else {
    uVar1 = 0x66;
  }
  return uVar1;
}


//===== FUN_00106cb0 @ 00106cb0 size=64 =====

undefined8 FUN_00106cb0(int *param_1,int param_2)

{
  undefined8 uVar1;
  
  if (param_1 == (int *)0x0) {
    uVar1 = 0x6d;
  }
  else if (*param_1 == 0x35ca) {
    param_1[3] = param_2;
    uVar1 = 0;
  }
  else {
    uVar1 = 0x66;
  }
  return uVar1;
}


//===== FUN_00106cf0 @ 00106cf0 size=470 =====

int FUN_00106cf0(int *param_1,char *param_2)

{
  int iVar1;
  undefined1 local_38 [27];
  undefined1 local_1d;
  int local_1c;
  
  if (param_1 == (int *)0x0) {
    iVar1 = 0x6d;
  }
  else if (*param_1 == 0x35ca) {
    param_1[4] = 0;
    if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
      iVar1 = 0x68;
    }
    else {
      FUN_0010741b(param_1);
      FUN_0010dca4(&local_1d);
      iVar1 = FUN_0010dcb8(&local_1d,param_2,param_1 + 0xc);
      local_1c = iVar1;
      if ((iVar1 == 0) &&
         (iVar1 = FUN_0010ba48(param_1 + 0x18,param_1 + 0xc), local_1c = iVar1, iVar1 == 0)) {
        iVar1 = FUN_0010ba84(param_1 + 0x18);
        if (iVar1 == 0) {
          FUN_0010951c(local_38,param_1 + 0x664);
          iVar1 = FUN_0010bad8(param_1 + 0x18,local_38,param_1 + 0x20,param_1 + 2);
          local_1c = iVar1;
          if ((iVar1 == 0) &&
             (iVar1 = FUN_00109f20(param_1 + 0x24,param_1 + 0x20,param_1 + 0x28), local_1c = iVar1,
             iVar1 == 0)) {
            FUN_0010847a(param_1 + 0x28);
            param_1[4] = 1;
            iVar1 = 0;
          }
          FUN_0010954c(local_38);
        }
        else {
          param_1[4] = 5;
          iVar1 = 0;
        }
      }
      FUN_0010dcae(&local_1d);
    }
  }
  else {
    iVar1 = 0x66;
  }
  return iVar1;
}


//===== FUN_00106efe @ 00106efe size=1070 =====

int FUN_00106efe(int *param_1,undefined8 param_2,short *param_3)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  undefined1 local_28 [16];
  int local_18;
  ushort local_12;
  ulong local_10;
  
  if (param_1 == (int *)0x0) {
    local_18 = 0x6d;
  }
  else if (*param_1 == 0x35ca) {
    *param_3 = 0;
    if (param_1[4] == 0) {
      local_18 = -1;
    }
    else if (param_1[4] == 5) {
      local_18 = 1;
    }
    else if (param_1[4] == 1) {
      do {
        iVar3 = FUN_00109c08(param_1 + 0x5e);
        if (0x13f < iVar3) {
          sVar2 = FUN_00109c24(param_1 + 0x5e,0x140,param_2);
          *param_3 = sVar2;
          return 0;
        }
        local_18 = FUN_0010872c(param_1 + 0x28,local_28);
        if (local_18 != 0) {
          if ((param_1[3] < 0) || (iVar3 = FUN_0010ba84(param_1 + 0x18), iVar3 == 0)) {
            bVar1 = false;
          }
          else {
            bVar1 = true;
          }
          if (bVar1) {
            param_1[2] = param_1[3];
          }
          else {
            iVar3 = param_1[1] * param_1[2];
            if (iVar3 < 0) {
              iVar3 = iVar3 + 0x7f;
            }
            param_1[2] = iVar3 >> 7;
          }
          FUN_00109bec(param_1 + 0x5e,param_1[2]);
          sVar2 = FUN_00109c24(param_1 + 0x5e,0x140,param_2);
          *param_3 = sVar2;
          iVar3 = FUN_0010ba84(param_1 + 0x18);
          if (iVar3 != 0) {
            param_1[4] = 4;
            return 0;
          }
          iVar3 = FUN_00107360(param_1);
          if (iVar3 != 0) {
            param_1[4] = 0;
            return iVar3;
          }
          param_1[4] = 2;
          return 0;
        }
        local_18 = FUN_001104c2(param_1 + 0x3a,local_28,param_1 + 0x5e);
      } while (local_18 == 0);
      param_1[4] = 0;
    }
    else if (param_1[4] == 2) {
      local_18 = FUN_00109df0(param_1 + 0x24,param_1 + 0x20,param_1 + 0x28);
      if (local_18 == 1) {
        param_1[4] = 3;
      }
      else if (local_18 != 0) {
        param_1[4] = 0;
        return local_18;
      }
      sVar2 = FUN_00109c24(param_1 + 0x5e,0x140,param_2);
      *param_3 = sVar2;
      local_18 = 0;
    }
    else if (param_1[4] == 3) {
      sVar2 = FUN_00109c24(param_1 + 0x5e,0x140,param_2);
      *param_3 = sVar2;
      iVar3 = FUN_00109c08(param_1 + 0x5e);
      local_10 = (ulong)iVar3;
      if (local_10 < 0x140) {
        FUN_00109bec(param_1 + 0x5e,0);
        for (local_12 = 0; local_12 < local_10; local_12 = local_12 + 1) {
          FUN_00109b94(param_1 + 0x5e,0);
        }
        FUN_0010847a(param_1 + 0x28);
        FUN_0011045c(param_1 + 0x3a);
        param_1[4] = 1;
        local_18 = 0;
      }
      else {
        local_18 = 0;
      }
    }
    else if (param_1[4] == 4) {
      sVar2 = FUN_00109c24(param_1 + 0x5e,0x140,param_2);
      *param_3 = sVar2;
      if (*param_3 < 0x140) {
        param_1[4] = 5;
      }
      local_18 = 0;
    }
    else {
      local_18 = -1;
    }
  }
  else {
    local_18 = 0x66;
  }
  return local_18;
}


//===== FUN_0010732c @ 0010732c size=26 =====

void FUN_0010732c(undefined8 param_1)

{
  FUN_00106398(param_1);
  return;
}


//===== FUN_00107346 @ 00107346 size=26 =====

void FUN_00107346(undefined8 param_1)

{
  FUN_00106423(param_1);
  return;
}


//===== FUN_00107360 @ 00107360 size=156 =====

int FUN_00107360(long param_1)

{
  int iVar1;
  undefined1 local_38 [28];
  int local_1c;
  
  FUN_0010951c(local_38,param_1 + 0x1990);
  iVar1 = FUN_0010bad8(param_1 + 0x60,local_38,param_1 + 0x80,param_1 + 8);
  local_1c = iVar1;
  if (iVar1 == 0) {
    FUN_00109ddc(param_1 + 0x90);
    iVar1 = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  FUN_0010954c(local_38);
  return iVar1;
}


//===== FUN_0010741b @ 0010741b size=311 =====

void FUN_0010741b(long param_1)

{
  *(int *)(param_1 + 4) = (int)(0x6400 / (long)*(int *)(param_1 + 0x1c));
  FUN_00107ac4(param_1 + 0x30,param_1 + 400);
  FUN_00109820(param_1 + 0x40,*(undefined4 *)(param_1 + 0x14));
  FUN_0010b998(param_1 + 0x60,*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x28));
  FUN_0010922c(param_1 + 0x80,param_1 + 0x990);
  FUN_00109ddc(param_1 + 0x90);
  FUN_00108428(param_1 + 0xa0,param_1 + 0x1990,param_1 + 0x40,*(undefined4 *)(param_1 + 4));
  FUN_001103c0(param_1 + 0xe8,*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x14),
               *(undefined4 *)(param_1 + 0x18));
  FUN_00109b58(param_1 + 0x178,param_1 + 0x990,0x800);
  return;
}


//===== FUN_00107554 @ 00107554 size=10 =====

void FUN_00107554(void)

{
  return;
}


//===== FUN_0010755e @ 0010755e size=10 =====

void FUN_0010755e(void)

{
  return;
}


//===== FUN_00107568 @ 00107568 size=232 =====

undefined1 FUN_00107568(undefined8 param_1,char *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    for (local_c = 0x133; -1 < local_c; local_c = local_c + -1) {
      uVar1 = FUN_00106658((&PTR_DAT_0035a040)[(long)local_c * 2]);
      iVar2 = FUN_001066dd(param_2,(&PTR_DAT_0035a040)[(long)local_c * 2],uVar1);
      if (iVar2 == 0) {
        uVar1 = FUN_00106658((&PTR_DAT_0035a040)[(long)local_c * 2]);
        *param_3 = uVar1;
        return *(undefined1 *)((long)local_c * 0x10 + 0x35a048);
      }
    }
  }
  return 0;
}


//===== FUN_00107650 @ 00107650 size=138 =====

int FUN_00107650(undefined8 param_1,char *param_2)

{
  int iVar1;
  int local_c;
  
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    for (local_c = 0xc3; -1 < local_c; local_c = local_c + -1) {
      iVar1 = FUN_001066dd(param_2,(&PTR_DAT_0035b388)[(long)local_c * 3],2);
      if (iVar1 == 0) {
        return local_c;
      }
    }
  }
  return 0;
}


//===== FUN_001076da @ 001076da size=47 =====

undefined * FUN_001076da(undefined8 param_1,byte param_2)

{
  return (&PTR_DAT_0035b388)[(long)(int)(uint)param_2 * 3];
}


//===== FUN_0010770a @ 0010770a size=39 =====

undefined8 FUN_0010770a(undefined8 param_1,byte param_2)

{
  undefined8 uVar1;
  
  if ((param_2 < 2) || (9 < param_2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


//===== FUN_00107732 @ 00107732 size=39 =====

undefined8 FUN_00107732(undefined8 param_1,byte param_2)

{
  undefined8 uVar1;
  
  if ((param_2 < 6) || (9 < param_2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


//===== FUN_0010775a @ 0010775a size=39 =====

undefined8 FUN_0010775a(undefined8 param_1,byte param_2)

{
  undefined8 uVar1;
  
  if ((param_2 < 0xaa) || (0xba < param_2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


//===== FUN_00107782 @ 00107782 size=39 =====

undefined8 FUN_00107782(undefined8 param_1,byte param_2)

{
  undefined8 uVar1;
  
  if ((param_2 < 0x99) || (0xa9 < param_2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


//===== FUN_001077aa @ 001077aa size=45 =====

undefined4 FUN_001077aa(undefined8 param_1,byte param_2)

{
  return *(undefined4 *)(&DAT_0035b390 + (long)(int)(uint)param_2 * 0x18);
}


//===== FUN_001077d8 @ 001077d8 size=192 =====

ulong FUN_001077d8(undefined8 param_1,byte param_2)

{
  ulong uVar1;
  
  switch(param_2) {
  case 0xaa:
    uVar1 = 0xffffff99;
    break;
  case 0xab:
    uVar1 = 0xffffff9a;
    break;
  case 0xac:
    uVar1 = 0xffffff9b;
    break;
  case 0xad:
    uVar1 = 0xffffff9c;
    break;
  case 0xae:
    uVar1 = 0xffffff9d;
    break;
  case 0xaf:
    uVar1 = 0xffffff9e;
    break;
  case 0xb0:
    uVar1 = 0xffffff9f;
    break;
  case 0xb1:
    uVar1 = 0xffffffa0;
    break;
  case 0xb2:
    uVar1 = 0xffffffa1;
    break;
  case 0xb3:
    uVar1 = 0xffffffa2;
    break;
  case 0xb4:
    uVar1 = 0xffffffa3;
    break;
  case 0xb5:
    uVar1 = 0xffffffa4;
    break;
  case 0xb6:
    uVar1 = 0xffffffa5;
    break;
  case 0xb7:
    uVar1 = 0xffffffa6;
    break;
  case 0xb8:
    uVar1 = 0xffffffa7;
    break;
  case 0xb9:
    uVar1 = 0xffffffa8;
    break;
  case 0xba:
    uVar1 = 0xffffffa9;
    break;
  default:
    uVar1 = (ulong)param_2;
  }
  return uVar1;
}


//===== FUN_00107898 @ 00107898 size=192 =====

ulong FUN_00107898(undefined8 param_1,byte param_2)

{
  ulong uVar1;
  
  switch(param_2) {
  case 0xaa:
    uVar1 = 0x10;
    break;
  case 0xab:
    uVar1 = 0x11;
    break;
  case 0xac:
    uVar1 = 0x15;
    break;
  case 0xad:
    uVar1 = 0x16;
    break;
  case 0xae:
    uVar1 = 0x1c;
    break;
  case 0xaf:
    uVar1 = 0x1d;
    break;
  case 0xb0:
    uVar1 = 0x24;
    break;
  case 0xb1:
    uVar1 = 0xffffff91;
    break;
  case 0xb2:
    uVar1 = 0x4b;
    break;
  case 0xb3:
    uVar1 = 0x4c;
    break;
  case 0xb4:
    uVar1 = 0x57;
    break;
  case 0xb5:
    uVar1 = 0x59;
    break;
  case 0xb6:
    uVar1 = 0x5c;
    break;
  case 0xb7:
    uVar1 = 0x5e;
    break;
  case 0xb8:
    uVar1 = 0xffffff8c;
    break;
  case 0xb9:
    uVar1 = 0xffffff8e;
    break;
  case 0xba:
    uVar1 = 0xffffff93;
    break;
  default:
    uVar1 = (ulong)param_2;
  }
  return uVar1;
}


//===== FUN_00107958 @ 00107958 size=132 =====

undefined1 FUN_00107958(undefined8 param_1,undefined1 param_2)

{
  switch(param_2) {
  case 0xbb:
    param_2 = 0x36;
    break;
  case 0xbc:
    param_2 = 0x37;
    break;
  case 0xbd:
    param_2 = 0x38;
    break;
  case 0xbe:
    param_2 = 0x39;
    break;
  case 0xbf:
    param_2 = 0x3a;
    break;
  case 0xc0:
    param_2 = 0x75;
    break;
  case 0xc1:
    param_2 = 0x76;
    break;
  case 0xc2:
    param_2 = 0x77;
    break;
  case 0xc3:
    param_2 = 0x78;
  }
  return param_2;
}


//===== FUN_001079dc @ 001079dc size=132 =====

undefined1 FUN_001079dc(undefined8 param_1,undefined1 param_2)

{
  switch(param_2) {
  case 0xbb:
    param_2 = 0x31;
    break;
  case 0xbc:
    param_2 = 0x32;
    break;
  case 0xbd:
    param_2 = 0x33;
    break;
  case 0xbe:
    param_2 = 0x34;
    break;
  case 0xbf:
    param_2 = 0x35;
    break;
  case 0xc0:
    param_2 = 0x71;
    break;
  case 0xc1:
    param_2 = 0x72;
    break;
  case 0xc2:
    param_2 = 0x73;
    break;
  case 0xc3:
    param_2 = 0x74;
  }
  return param_2;
}


//===== FUN_00107a60 @ 00107a60 size=46 =====

undefined * FUN_00107a60(undefined8 param_1,byte param_2)

{
  return (&PTR_DAT_0035b380)[(long)(int)(uint)param_2 * 3];
}


//===== FUN_00107a90 @ 00107a90 size=26 =====

void FUN_00107a90(undefined8 param_1)

{
  FUN_00107554(param_1);
  return;
}


//===== FUN_00107aaa @ 00107aaa size=26 =====

void FUN_00107aaa(undefined8 param_1)

{
  FUN_0010755e(param_1);
  return;
}


//===== FUN_00107ac4 @ 00107ac4 size=45 =====

void FUN_00107ac4(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  *(undefined2 *)(param_1 + 1) = 0;
  *(undefined1 *)*param_1 = 0;
  return;
}


//===== FUN_00107af2 @ 00107af2 size=80 =====

undefined8 FUN_00107af2(long *param_1,undefined1 param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  if ((short)param_1[1] < 0x7ff) {
    lVar1 = param_1[1];
    *(undefined1 *)(*param_1 + (long)(short)lVar1) = param_2;
    *(short *)(param_1 + 1) = (short)lVar1 + 1;
    uVar2 = 0;
  }
  else {
    uVar2 = 0x78;
  }
  return uVar2;
}


//===== FUN_00107b42 @ 00107b42 size=105 =====

undefined8 FUN_00107b42(long *param_1,char *param_2)

{
  long lVar1;
  char *local_18;
  
  local_18 = param_2;
  while( true ) {
    if (*local_18 == '\0') {
      return 0;
    }
    if (0x7fe < (short)param_1[1]) break;
    lVar1 = param_1[1];
    *(char *)(*param_1 + (long)(short)lVar1) = *local_18;
    *(short *)(param_1 + 1) = (short)lVar1 + 1;
    local_18 = local_18 + 1;
  }
  return 0x78;
}


//===== FUN_00107bac @ 00107bac size=133 =====

int FUN_00107bac(undefined8 param_1,char *param_2)

{
  int iVar1;
  char *local_28;
  int local_14;
  char local_d;
  undefined4 local_c;
  
  local_28 = param_2;
  if (param_2 != (char *)0x0) {
    for (; *local_28 != '\0'; local_28 = local_28 + local_14) {
      local_d = FUN_00107568(param_1,local_28,&local_14);
      if (local_d == '\0') {
        return 0x69;
      }
      iVar1 = FUN_00107af2(param_1,local_d);
      if (iVar1 != 0) {
        return iVar1;
      }
      local_c = 0;
    }
  }
  return 0;
}


//===== FUN_00107c32 @ 00107c32 size=247 =====

void FUN_00107c32(long param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar2 = FUN_00107d2a(param_1,*(short *)(param_1 + 8) + -1);
  if ((-1 < iVar2) && (iVar3 = FUN_00107d2a(param_1,iVar2 + -2), -1 < iVar3)) {
    if ((param_2 == 1) &&
       (iVar4 = FUN_00107da6(param_1,iVar2,(int)*(short *)(param_1 + 8),1), iVar4 < 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_00107df6(param_1,iVar2 + -1);
    }
    else {
      FUN_00107df6(param_1,iVar2 + -1);
      uVar5 = FUN_00107da6(param_1,iVar3,iVar2,1);
      FUN_00107df6(param_1,uVar5);
    }
  }
  return;
}


//===== FUN_00107d2a @ 00107d2a size=123 =====

int FUN_00107d2a(long *param_1,int param_2)

{
  int iVar1;
  int local_c;
  
  if ((param_2 < 0) || (local_c = param_2, (short)param_1[1] <= param_2)) {
    iVar1 = -1;
  }
  else {
    for (; -1 < local_c; local_c = local_c + -1) {
      if ((2 < *(byte *)(*param_1 + (long)local_c)) && (*(byte *)(*param_1 + (long)local_c) < 10)) {
        return local_c + 1;
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}


//===== FUN_00107da6 @ 00107da6 size=80 =====

int FUN_00107da6(long *param_1,int param_2,int param_3,char param_4)

{
  int local_c;
  
  local_c = param_2;
  while( true ) {
    if (param_3 <= local_c) {
      return -1;
    }
    if (*(char *)(*param_1 + (long)local_c) == param_4) break;
    local_c = local_c + 1;
  }
  return local_c;
}


//===== FUN_00107df6 @ 00107df6 size=129 =====

void FUN_00107df6(long *param_1,int param_2)

{
  int local_c;
  
  if ((-1 < param_2) && (param_2 < (short)param_1[1])) {
    *(short *)(param_1 + 1) = (short)param_1[1] + -1;
    for (local_c = param_2; local_c < (short)param_1[1]; local_c = local_c + 1) {
      *(undefined1 *)(*param_1 + (long)local_c) = *(undefined1 *)(*param_1 + (long)local_c + 1);
    }
  }
  return;
}


//===== FUN_00107e78 @ 00107e78 size=164 =====

void FUN_00107e78(long *param_1,int param_2,undefined1 param_3)

{
  int local_c;
  
  if ((-1 < param_2) && (param_2 <= (short)param_1[1])) {
    local_c = (int)(short)param_1[1];
    while (local_c = local_c + -1, param_2 <= local_c) {
      *(undefined1 *)(*param_1 + (long)local_c + 1) = *(undefined1 *)(*param_1 + (long)local_c);
    }
    *(undefined1 *)(*param_1 + (long)param_2) = param_3;
    *(short *)(param_1 + 1) = (short)param_1[1] + 1;
  }
  return;
}


//===== FUN_00107f1c @ 00107f1c size=144 =====

void FUN_00107f1c(long param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00107d2a(param_1,*(short *)(param_1 + 8) + -2);
  if (-1 < iVar1) {
    uVar2 = FUN_00107da6(param_1,iVar1,(int)*(short *)(param_1 + 8),1);
    FUN_00107df6(param_1,uVar2);
    if (param_2 != 0) {
      FUN_00107e78(param_1,iVar1 + param_2,1);
    }
  }
  return;
}


//===== FUN_00107fac @ 00107fac size=19 =====

int FUN_00107fac(long param_1)

{
  return (int)*(short *)(param_1 + 8);
}


//===== FUN_00107fc0 @ 00107fc0 size=39 =====

void FUN_00107fc0(long *param_1,int param_2,undefined1 param_3)

{
  *(undefined1 *)(*param_1 + (long)param_2) = param_3;
  return;
}


//===== FUN_00107fe8 @ 00107fe8 size=59 =====

undefined1 FUN_00107fe8(long *param_1,int param_2)

{
  undefined1 uVar1;
  
  if ((param_2 < 0) || ((short)param_1[1] <= param_2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined1 *)(*param_1 + (long)param_2);
  }
  return uVar1;
}


//===== FUN_00108024 @ 00108024 size=191 =====

void FUN_00108024(undefined8 param_1)

{
  int iVar1;
  undefined1 local_11;
  undefined4 local_10;
  undefined1 local_9;
  
  local_11 = 8;
  local_10 = 0;
  while( true ) {
    iVar1 = FUN_00107fac(param_1);
    if (iVar1 <= local_10) break;
    local_9 = FUN_00107fe8(param_1,local_10);
    if ((0xba < local_9) && (local_9 < 0xc4)) {
      iVar1 = FUN_0010770a(param_1,local_11);
      if (iVar1 == 0) {
        local_9 = FUN_001079dc(param_1,local_9);
      }
      else {
        local_9 = FUN_00107958(param_1,local_9);
      }
      FUN_00107fc0(param_1,local_10,local_9);
    }
    local_11 = local_9;
    local_10 = local_10 + 1;
  }
  return;
}


//===== FUN_001080e4 @ 001080e4 size=546 =====

void FUN_001080e4(undefined8 param_1)

{
  int iVar1;
  char local_1d;
  int local_1c;
  int local_18;
  int local_14;
  char local_e;
  byte local_d;
  int local_c;
  
  local_1d = '\b';
  local_1c = 0;
  local_18 = 0;
  for (local_14 = 0; iVar1 = FUN_00107fac(param_1), local_14 < iVar1; local_14 = local_14 + 1) {
    local_e = FUN_00107fe8(param_1,local_14);
    if (local_e == '\x01') {
      local_18 = local_1c;
    }
    else {
      iVar1 = FUN_0010770a(param_1,local_e);
      if (iVar1 == 0) {
        iVar1 = FUN_0010775a(param_1,local_e);
        if (iVar1 != 0) {
          local_d = FUN_00107fe8(param_1,local_14 + 1);
          iVar1 = FUN_00107782(param_1,local_1d);
          if (iVar1 == 0) {
            if ((local_d == 7) || (local_d == 6)) {
              local_e = FUN_00107898(param_1,local_e);
            }
            else if ((local_d == 8) || (local_d == 9)) {
              if ((local_1c == 0) || (local_18 == 0)) {
                local_e = FUN_00107898(param_1,local_e);
              }
              else {
                local_e = FUN_001077d8(param_1,local_e);
              }
            }
            else {
              local_c = 0;
              while ((local_d != 0 && (local_d < 10))) {
                local_d = FUN_00107fe8(param_1,local_14 + 1 + local_c);
                local_c = local_c + 1;
              }
              iVar1 = FUN_001077aa(param_1,local_d);
              if (iVar1 == 0) {
                local_e = FUN_00107898(param_1,local_e);
              }
              else {
                local_e = FUN_001077d8(param_1,local_e);
              }
            }
          }
          else {
            local_e = FUN_00107898(param_1,local_e);
          }
          FUN_00107fc0(param_1,local_14,local_e);
        }
        local_1c = local_1c + 1;
        local_1d = local_e;
      }
      else {
        local_1c = 0;
        local_18 = 0;
        local_1d = local_e;
      }
    }
  }
  return;
}


//===== FUN_00108306 @ 00108306 size=132 =====

void FUN_00108306(undefined8 param_1)

{
  byte bVar1;
  int iVar2;
  int local_10;
  
  iVar2 = FUN_001064c7();
  if (iVar2 != 0) {
    for (local_10 = 0; iVar2 = FUN_00107fac(param_1), local_10 < iVar2; local_10 = local_10 + 1) {
      bVar1 = FUN_00107fe8(param_1,local_10);
      if (((0x1d < bVar1) && (bVar1 < 0x23)) || ((0x26 < bVar1 && (bVar1 < 0x2c)))) {
        FUN_00107fc0(param_1,local_10,0x20);
      }
    }
  }
  return;
}


//===== FUN_0010838c @ 0010838c size=26 =====

void FUN_0010838c(undefined8 param_1)

{
  FUN_0010840a(param_1);
  return;
}


//===== FUN_001083a6 @ 001083a6 size=10 =====

void FUN_001083a6(void)

{
  return;
}


//===== FUN_001083b0 @ 001083b0 size=90 =====

uint FUN_001083b0(long param_1,int param_2)

{
  uint uVar1;
  undefined4 local_14;
  
  local_14 = param_2;
  if (param_2 == -1) {
    local_14 = *(byte *)(param_1 + 3) - 1;
  }
  if (*(char *)(param_1 + 2) == '\x01') {
    uVar1 = (uint)*(ushort *)(param_1 + 4) + local_14;
  }
  else if (*(char *)(param_1 + 2) == '\x03') {
    uVar1 = (uint)*(ushort *)(param_1 + 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


//===== FUN_0010840a @ 0010840a size=10 =====

void FUN_0010840a(void)

{
  return;
}


//===== FUN_00108414 @ 00108414 size=10 =====

void FUN_00108414(void)

{
  return;
}


//===== FUN_0010841e @ 0010841e size=10 =====

void FUN_0010841e(void)

{
  return;
}


//===== FUN_00108428 @ 00108428 size=81 =====

void FUN_00108428(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  param_1[2] = param_2;
  *param_1 = param_3;
  *(undefined4 *)((long)param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 4) = param_4;
  FUN_0010847a(param_1);
  return;
}


//===== FUN_0010847a @ 0010847a size=41 =====

void FUN_0010847a(long param_1)

{
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined2 *)(param_1 + 8) = 0xffff;
  *(undefined2 *)(param_1 + 10) = 0xffff;
  return;
}


//===== FUN_001084a4 @ 001084a4 size=32 =====

void FUN_001084a4(long param_1)

{
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}


//===== FUN_001084c4 @ 001084c4 size=592 =====

undefined8
FUN_001084c4(long param_1,ushort param_2,ushort param_3,undefined2 *param_4,undefined1 param_5,
            short param_6,short param_7)

{
  undefined1 *puVar1;
  undefined8 uVar2;
  
  if (*(int *)(param_1 + 0x1c) + 0xc < 0x6671) {
    puVar1 = (undefined1 *)(*(long *)(param_1 + 0x10) + (long)*(int *)(param_1 + 0x1c));
    if ((*(short *)(param_1 + 8) == param_6) && (*(short *)(param_1 + 10) == param_7)) {
      *puVar1 = 0;
      puVar1[1] = param_5;
      *(undefined2 *)(puVar1 + 4) = *param_4;
      puVar1[6] = *(undefined1 *)(param_4 + 1);
      *(ushort *)(puVar1 + 2) = param_2 | param_3 & 0x3fff;
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 8;
    }
    else if (*(short *)(param_1 + 10) == param_6) {
      *puVar1 = 1;
      puVar1[1] = param_5;
      *(undefined2 *)(puVar1 + 4) = *param_4;
      puVar1[6] = *(undefined1 *)(param_4 + 1);
      *(ushort *)(puVar1 + 2) = param_2 | param_3 & 0x3fff;
      *(short *)(puVar1 + 8) = param_7;
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 10;
    }
    else if (param_6 == param_7) {
      *puVar1 = 2;
      puVar1[1] = 0;
      *(undefined2 *)(puVar1 + 4) = *param_4;
      puVar1[6] = *(undefined1 *)(param_4 + 1);
      *(ushort *)(puVar1 + 2) = param_2 | param_3 & 0x3fff;
      *(short *)(puVar1 + 8) = param_6;
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 10;
    }
    else {
      *puVar1 = 3;
      puVar1[1] = param_5;
      *(undefined2 *)(puVar1 + 4) = *param_4;
      puVar1[6] = *(undefined1 *)(param_4 + 1);
      *(ushort *)(puVar1 + 2) = param_2 | param_3 & 0x3fff;
      *(short *)(puVar1 + 8) = param_6;
      *(short *)(puVar1 + 10) = param_7;
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 0xc;
    }
    *(short *)(param_1 + 8) = param_6;
    *(short *)(param_1 + 10) = param_7;
    uVar2 = 0;
  }
  else {
    uVar2 = 0x7a;
  }
  return uVar2;
}


//===== FUN_00108714 @ 00108714 size=23 =====

void FUN_00108714(long param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x20) = param_2;
  return;
}


//===== FUN_0010872c @ 0010872c size=770 =====

undefined8 FUN_0010872c(long param_1,undefined2 *param_2)

{
  byte *pbVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x1c) <= *(int *)(param_1 + 0x18)) {
    return 0xffffffff;
  }
  pbVar1 = (byte *)(*(long *)(param_1 + 0x10) + (long)*(int *)(param_1 + 0x18));
  uVar3 = *(ushort *)(pbVar1 + 2) & 0xc000;
  if (uVar3 == 0x4000) {
    iVar4 = *(int *)(param_1 + 0x20) * 400;
    if (iVar4 < 0) {
      iVar4 = iVar4 + 0x3ff;
    }
    *param_2 = (short)(iVar4 >> 10);
  }
  else if (uVar3 == 0x8000) {
    iVar4 = *(int *)(param_1 + 0x20) * 0x1e0;
    if (iVar4 < 0) {
      iVar4 = iVar4 + 0x3ff;
    }
    *param_2 = (short)(iVar4 >> 10);
  }
  else if ((*(ushort *)(pbVar1 + 2) & 0xc000) == 0) {
    iVar4 = *(int *)(param_1 + 0x20) * 0x50;
    if (*(int *)(param_1 + 0x20) * 0x50 < 0) {
      iVar4 = iVar4 + 0xff;
    }
    *param_2 = (short)((uint)iVar4 >> 8);
  }
  else {
    iVar4 = *(int *)(param_1 + 0x20) * 0x230;
    if (iVar4 < 0) {
      iVar4 = iVar4 + 0x3ff;
    }
    *param_2 = (short)(iVar4 >> 10);
  }
  param_2[2] = *(undefined2 *)(pbVar1 + 4);
  *(byte *)(param_2 + 3) = pbVar1[6];
  param_2[1] = *(ushort *)(pbVar1 + 2) & 0x3fff;
  bVar2 = *pbVar1;
  if (bVar2 == 1) {
    *(undefined2 *)(param_1 + 8) = *(undefined2 *)(param_1 + 10);
    *(undefined2 *)(param_1 + 10) = *(undefined2 *)(pbVar1 + 8);
    FUN_00108a2e(param_1,*(undefined2 *)(param_1 + 8),*(undefined2 *)(param_1 + 10),pbVar1[1]);
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 10;
  }
  else if (bVar2 < 2) {
    if (bVar2 != 0) {
      return 0xffffffff;
    }
    FUN_00108a2e(param_1,*(undefined2 *)(param_1 + 8),*(undefined2 *)(param_1 + 10),pbVar1[1]);
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 8;
  }
  else if (bVar2 == 2) {
    *(undefined2 *)(param_1 + 8) = *(undefined2 *)(pbVar1 + 8);
    *(undefined2 *)(param_1 + 10) = *(undefined2 *)(pbVar1 + 8);
    FUN_00108a2e(param_1,*(undefined2 *)(param_1 + 8),*(undefined2 *)(param_1 + 10),0);
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 10;
  }
  else {
    if (bVar2 != 3) {
      return 0xffffffff;
    }
    *(undefined2 *)(param_1 + 8) = *(undefined2 *)(pbVar1 + 8);
    *(undefined2 *)(param_1 + 10) = *(undefined2 *)(pbVar1 + 10);
    FUN_00108a2e(param_1,*(undefined2 *)(param_1 + 8),*(undefined2 *)(param_1 + 10),pbVar1[1]);
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 0xc;
  }
  *(long *)(param_2 + 4) = param_1 + 0x24;
  return 0;
}


//===== FUN_00108a2e @ 00108a2e size=289 =====

void FUN_00108a2e(undefined8 *param_1,undefined2 param_2,undefined2 param_3,ushort param_4)

{
  int iVar1;
  undefined8 uVar2;
  short local_58 [20];
  long local_30;
  long local_28;
  int local_1c;
  
  if (param_4 == 0) {
    uVar2 = FUN_001099a8(*param_1,param_2);
    FUN_00108b50(param_1,uVar2,(long)param_1 + 0x24);
  }
  else {
    local_30 = FUN_001099a8(*param_1,param_2);
    local_28 = FUN_001099a8(*param_1,param_3);
    for (local_1c = 0; local_1c < 0xe; local_1c = local_1c + 1) {
      iVar1 = (uint)param_4 *
              ((int)*(short *)((long)local_1c * 2 + local_28) -
              (int)*(short *)((long)local_1c * 2 + local_30));
      if (iVar1 < 0) {
        iVar1 = iVar1 + 0xff;
      }
      local_58[local_1c] = *(short *)((long)local_1c * 2 + local_30) + (short)((uint)iVar1 >> 8);
    }
    FUN_00108b50(param_1,local_58,(long)param_1 + 0x24);
  }
  return;
}


//===== FUN_00108b50 @ 00108b50 size=373 =====

void FUN_00108b50(undefined8 param_1,long param_2,undefined2 *param_3)

{
  int iVar1;
  int iVar2;
  int local_58 [8];
  int local_38 [10];
  int local_10;
  int local_c;
  
  FUN_00108cc6(param_1,param_2,local_38);
  FUN_00108cc6(param_1,param_2 + 2,local_58);
  for (local_10 = 7; 0 < local_10; local_10 = local_10 + -1) {
    local_38[local_10] = local_38[local_10] + local_38[local_10 + -1];
    local_58[local_10] = local_58[local_10] - local_58[local_10 + -1];
  }
  *param_3 = 0x1000;
  local_c = 0xe;
  for (local_10 = 1; local_10 < 8; local_10 = local_10 + 1) {
    iVar1 = local_38[local_10];
    iVar2 = local_58[local_10];
    param_3[local_10] = (short)(iVar1 + iVar2 >> 0xd);
    if ((iVar1 + iVar2 & 0x1000U) != 0) {
      param_3[local_10] = param_3[local_10] + 1;
    }
    iVar1 = local_38[local_10];
    iVar2 = local_58[local_10];
    param_3[local_c] = (short)(iVar1 - iVar2 >> 0xd);
    if ((iVar1 - iVar2 & 0x1000U) != 0) {
      param_3[local_c] = param_3[local_c] + 1;
    }
    local_c = local_c + -1;
  }
  return;
}


//===== FUN_00108cc6 @ 00108cc6 size=1362 =====

void FUN_00108cc6(undefined8 param_1,short *param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  
  uVar2 = *param_2 * -0x400;
  iVar3 = (int)param_2[2];
  iVar4 = (int)param_2[4];
  iVar5 = (int)param_2[6];
  iVar6 = (int)param_2[8];
  iVar7 = (int)param_2[10];
  iVar8 = (int)param_2[0xc];
  iVar1 = (((int)uVar2 >> 0x10) * iVar3 + ((int)((uVar2 & 0xfffe) * iVar3) >> 0x10)) * -4;
  uVar9 = iVar1 + 0x2000000;
  uVar2 = uVar2 + iVar3 * -0x400;
  uVar9 = uVar2 * 2 +
          (((int)uVar9 >> 0x10) * iVar4 + ((int)((uVar9 & 0xfffe) * iVar4) >> 0x10)) * -4;
  uVar10 = iVar1 + 0x3000000 +
           (((int)uVar2 >> 0x10) * iVar4 + ((int)((uVar2 & 0xfffe) * iVar4) >> 0x10)) * -4;
  uVar2 = uVar2 + iVar4 * -0x400;
  uVar11 = uVar10 * 2 +
           (((int)uVar9 >> 0x10) * iVar5 + ((int)((uVar9 & 0xfffe) * iVar5) >> 0x10)) * -4;
  uVar9 = uVar9 + uVar2 +
          (((int)uVar10 >> 0x10) * iVar5 + ((int)((uVar10 & 0xfffe) * iVar5) >> 0x10)) * -4;
  uVar10 = uVar10 + 0x1000000 +
           (((int)uVar2 >> 0x10) * iVar5 + ((int)((uVar2 & 0xfffe) * iVar5) >> 0x10)) * -4;
  uVar2 = uVar2 + iVar5 * -0x400;
  uVar12 = uVar9 * 2 +
           (((int)uVar11 >> 0x10) * iVar6 + ((int)((uVar11 & 0xfffe) * iVar6) >> 0x10)) * -4;
  uVar11 = uVar11 + uVar10 +
           (((int)uVar9 >> 0x10) * iVar6 + ((int)((uVar9 & 0xfffe) * iVar6) >> 0x10)) * -4;
  uVar9 = uVar9 + uVar2 +
          (((int)uVar10 >> 0x10) * iVar6 + ((int)((uVar10 & 0xfffe) * iVar6) >> 0x10)) * -4;
  uVar10 = uVar10 + 0x1000000 +
           (((int)uVar2 >> 0x10) * iVar6 + ((int)((uVar2 & 0xfffe) * iVar6) >> 0x10)) * -4;
  uVar2 = uVar2 + iVar6 * -0x400;
  uVar13 = uVar11 * 2 +
           (((int)uVar12 >> 0x10) * iVar7 + ((int)((uVar12 & 0xfffe) * iVar7) >> 0x10)) * -4;
  uVar12 = uVar12 + uVar9 +
           (((int)uVar11 >> 0x10) * iVar7 + ((int)((uVar11 & 0xfffe) * iVar7) >> 0x10)) * -4;
  uVar11 = uVar11 + uVar10 +
           (((int)uVar9 >> 0x10) * iVar7 + ((int)((uVar9 & 0xfffe) * iVar7) >> 0x10)) * -4;
  uVar9 = uVar9 + uVar2 +
          (((int)uVar10 >> 0x10) * iVar7 + ((int)((uVar10 & 0xfffe) * iVar7) >> 0x10)) * -4;
  uVar10 = uVar10 + 0x1000000 +
           (((int)uVar2 >> 0x10) * iVar7 + ((int)((uVar2 & 0xfffe) * iVar7) >> 0x10)) * -4;
  uVar2 = uVar2 + iVar7 * -0x400;
  *param_3 = 0x1000000;
  param_3[1] = uVar2 + iVar8 * -0x400;
  param_3[2] = uVar10 + 0x1000000 +
               (((int)uVar2 >> 0x10) * iVar8 + ((int)((uVar2 & 0xfffe) * iVar8) >> 0x10)) * -4;
  param_3[3] = uVar9 + uVar2 +
               (((int)uVar10 >> 0x10) * iVar8 + ((int)((uVar10 & 0xfffe) * iVar8) >> 0x10)) * -4;
  param_3[4] = uVar11 + uVar10 +
               (((int)uVar9 >> 0x10) * iVar8 + ((int)((uVar9 & 0xfffe) * iVar8) >> 0x10)) * -4;
  param_3[5] = uVar12 + uVar9 +
               (((int)uVar11 >> 0x10) * iVar8 + ((int)((uVar11 & 0xfffe) * iVar8) >> 0x10)) * -4;
  param_3[6] = uVar13 + uVar11 +
               (((int)uVar12 >> 0x10) * iVar8 + ((int)((uVar12 & 0xfffe) * iVar8) >> 0x10)) * -4;
  param_3[7] = uVar12 * 2 +
               (((int)uVar13 >> 0x10) * iVar8 + ((int)((uVar13 & 0xfffe) * iVar8) >> 0x10)) * -4;
  return;
}


//===== FUN_00109218 @ 00109218 size=10 =====

void FUN_00109218(void)

{
  return;
}


//===== FUN_00109222 @ 00109222 size=10 =====

void FUN_00109222(void)

{
  return;
}


//===== FUN_0010922c @ 0010922c size=47 =====

void FUN_0010922c(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  *(undefined4 *)((long)param_1 + 0xc) = 0x400;
  *(undefined4 *)(param_1 + 1) = 0;
  return;
}


//===== FUN_0010925c @ 0010925c size=234 =====

int FUN_0010925c(long *param_1,undefined8 param_2,ushort param_3)

{
  long lVar1;
  int iVar2;
  
  if ((int)param_1[1] < *(int *)((long)param_1 + 0xc)) {
    lVar1 = *param_1 + (long)(int)param_1[1] * 4;
    FUN_00106800(lVar1 + 2,param_2,2);
    FUN_001094e4(param_1,lVar1,0);
    if (param_3 == 0) {
      FUN_00109496(param_1,lVar1,0);
    }
    else {
      FUN_00109496(param_1,lVar1,0x7d0000U / (ulong)(long)(int)(uint)param_3 & 0xffff);
    }
    *(int *)(param_1 + 1) = (int)param_1[1] + 1;
    iVar2 = (int)param_1[1] + -1;
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}


//===== FUN_00109346 @ 00109346 size=21 =====

void FUN_00109346(long param_1)

{
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}


//===== FUN_0010935c @ 0010935c size=33 =====

long FUN_0010935c(long *param_1,int param_2)

{
  return *param_1 + (long)param_2 * 4;
}


//===== FUN_0010937e @ 0010937e size=17 =====

undefined4 FUN_0010937e(long param_1)

{
  return *(undefined4 *)(param_1 + 8);
}


//===== FUN_00109390 @ 00109390 size=53 =====

void FUN_00109390(long *param_1,int param_2)

{
  FUN_0010947c(param_1,*param_1 + (long)param_2 * 4);
  return;
}


//===== FUN_001093c6 @ 001093c6 size=63 =====

void FUN_001093c6(long *param_1,int param_2,undefined2 param_3)

{
  FUN_00109496(param_1,*param_1 + (long)param_2 * 4,param_3);
  return;
}


//===== FUN_00109406 @ 00109406 size=53 =====

void FUN_00109406(long *param_1,int param_2)

{
  FUN_001094ca(param_1,*param_1 + (long)param_2 * 4);
  return;
}


//===== FUN_0010943c @ 0010943c size=63 =====

void FUN_0010943c(long *param_1,int param_2,undefined2 param_3)

{
  FUN_001094e4(param_1,*param_1 + (long)param_2 * 4,param_3);
  return;
}


//===== FUN_0010947c @ 0010947c size=25 =====

ushort FUN_0010947c(undefined8 param_1,ushort *param_2)

{
  return *param_2 & 0x3fff;
}


//===== FUN_00109496 @ 00109496 size=52 =====

void FUN_00109496(undefined8 param_1,ushort *param_2,ushort param_3)

{
  *param_2 = *param_2 & 0xc000 | param_3;
  return;
}


//===== FUN_001094ca @ 001094ca size=25 =====

ushort FUN_001094ca(undefined8 param_1,ushort *param_2)

{
  return *param_2 & 0xc000;
}


//===== FUN_001094e4 @ 001094e4 size=56 =====

void FUN_001094e4(undefined8 param_1,ushort *param_2,ushort param_3)

{
  ushort uVar1;
  
  uVar1 = FUN_0010947c(param_1,param_2);
  *param_2 = uVar1 | param_3;
  return;
}


//===== FUN_0010951c @ 0010951c size=47 =====

void FUN_0010951c(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  *(undefined4 *)((long)param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 1) = 0;
  return;
}


//===== FUN_0010954c @ 0010954c size=10 =====

void FUN_0010954c(void)

{
  return;
}


//===== FUN_00109556 @ 00109556 size=301 =====

int FUN_00109556(long *param_1,byte param_2)

{
  long lVar1;
  int iVar2;
  
  if (param_2 == 2) {
    return 0;
  }
  if (*(int *)((long)param_1 + 0xc) == (int)param_1[1]) {
    if ((1 < param_2) && (param_2 < 10)) {
      return 0;
    }
    iVar2 = FUN_0010971c(param_1);
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  lVar1 = *param_1 + (long)*(int *)((long)param_1 + 0xc);
  if (param_2 < 10) {
    if (param_2 == 1) {
      *(undefined2 *)(lVar1 + 4) = *(undefined2 *)(lVar1 + 2);
    }
    else {
      *(byte *)(lVar1 + 1) = param_2;
      FUN_0010979c(param_1);
    }
  }
  else {
    *(int *)(param_1 + 1) = (int)param_1[1] + 4;
    if (0x6670 < (int)param_1[1]) {
      return 0x78;
    }
    *(byte *)(lVar1 + 10 + (long)(int)(uint)*(ushort *)(lVar1 + 2) * 4) = param_2;
    *(undefined2 *)(lVar1 + 8 + (long)(int)(uint)*(ushort *)(lVar1 + 2) * 4) = 0;
    *(short *)(lVar1 + 2) = *(short *)(lVar1 + 2) + 1;
  }
  return 0;
}


//===== FUN_00109684 @ 00109684 size=21 =====

void FUN_00109684(long param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}


//===== FUN_0010969a @ 0010969a size=82 =====

long FUN_0010969a(long *param_1)

{
  long lVar1;
  
  if (*(int *)((long)param_1 + 0xc) < (int)param_1[1]) {
    lVar1 = *param_1 + (long)*(int *)((long)param_1 + 0xc);
    FUN_0010979c(param_1);
  }
  else {
    lVar1 = 0;
  }
  return lVar1;
}


//===== FUN_001096ec @ 001096ec size=47 =====

char FUN_001096ec(undefined8 param_1,char *param_2)

{
  char cVar1;
  
  if ((param_2 == (char *)0x0) || (*param_2 != -0x55)) {
    cVar1 = '\b';
  }
  else {
    cVar1 = param_2[1];
  }
  return cVar1;
}


//===== FUN_0010971c @ 0010971c size=127 =====

undefined8 FUN_0010971c(long *param_1)

{
  undefined1 *puVar1;
  undefined8 uVar2;
  
  *(int *)(param_1 + 1) = (int)param_1[1] + 8;
  if ((int)param_1[1] < 0x6671) {
    puVar1 = (undefined1 *)(*param_1 + (long)*(int *)((long)param_1 + 0xc));
    *puVar1 = 0xab;
    *(undefined2 *)(puVar1 + 2) = 0;
    *(undefined2 *)(puVar1 + 4) = 0;
    puVar1[1] = 8;
    *(undefined2 *)(puVar1 + 6) = 0x400;
    uVar2 = 0;
  }
  else {
    uVar2 = 0x78;
  }
  return uVar2;
}


//===== FUN_0010979c @ 0010979c size=110 =====

void FUN_0010979c(long *param_1)

{
  long lVar1;
  
  lVar1 = *param_1 + (long)*(int *)((long)param_1 + 0xc);
  if (*(short *)(lVar1 + 2) == 0) {
    *(undefined4 *)(param_1 + 1) = *(undefined4 *)((long)param_1 + 0xc);
  }
  else {
    *(uint *)((long)param_1 + 0xc) =
         *(int *)((long)param_1 + 0xc) + (*(ushort *)(lVar1 + 2) + 2) * 4;
  }
  return;
}


//===== FUN_0010980c @ 0010980c size=10 =====

void FUN_0010980c(void)

{
  return;
}


//===== FUN_00109816 @ 00109816 size=10 =====

void FUN_00109816(void)

{
  return;
}


//===== FUN_00109820 @ 00109820 size=230 =====

void FUN_00109820(undefined8 *param_1,int param_2)

{
  if (param_2 == 1) {
    *param_1 = &DAT_00123f20;
    param_1[1] = &DAT_00124400;
    param_1[2] = &DAT_00135ea0;
    *(undefined4 *)(param_1 + 3) = 0xcc;
    *(undefined4 *)((long)param_1 + 0x1c) = 0xa18;
  }
  else if (param_2 == 2) {
    *param_1 = &DAT_00136300;
    param_1[1] = &DAT_001367e0;
    param_1[2] = &DAT_001485e0;
    *(undefined4 *)(param_1 + 3) = 0xcc;
    *(undefined4 *)((long)param_1 + 0x1c) = 0xa36;
  }
  else {
    *param_1 = &DAT_00111b60;
    param_1[1] = &DAT_00112040;
    param_1[2] = &DAT_00123ac0;
    *(undefined4 *)(param_1 + 3) = 0xcc;
    *(undefined4 *)((long)param_1 + 0x1c) = 0xa16;
  }
  return;
}


//===== FUN_00109906 @ 00109906 size=161 =====

long FUN_00109906(long *param_1,char *param_2)

{
  char *pcVar1;
  int local_14;
  
  local_14 = 0;
  while( true ) {
    if ((int)param_1[3] <= local_14) {
      return 0;
    }
    pcVar1 = (char *)(*param_1 + (long)local_14 * 6);
    if ((*pcVar1 == *param_2) && (pcVar1[1] == param_2[1])) break;
    local_14 = local_14 + 1;
  }
  return *param_1 + (long)local_14 * 6;
}


//===== FUN_001099a8 @ 001099a8 size=38 =====

long FUN_001099a8(long param_1,int param_2)

{
  return *(long *)(param_1 + 8) + (long)param_2 * 0x20 + 4;
}


//===== FUN_001099ce @ 001099ce size=318 =====

ulong FUN_001099ce(long param_1,undefined8 param_2,int param_3)

{
  byte bVar1;
  undefined1 uVar2;
  ushort uVar3;
  int local_2c;
  uint3 local_18;
  
  uVar3 = FUN_00109b30(param_2);
  local_2c = param_3;
  if (param_3 == -1) {
    bVar1 = FUN_00109b1e(param_2);
    local_2c = bVar1 - 1;
  }
  uVar2 = FUN_00109b0c(param_2);
  switch(uVar2) {
  default:
    local_18 = **(uint3 **)(param_1 + 0x10);
    break;
  case 1:
    local_18 = *(uint3 *)(*(long *)(param_1 + 8) + (long)(int)((uint)uVar3 + local_2c) * 0x20);
    break;
  case 2:
  case 4:
  case 5:
    local_18 = *(uint3 *)(*(long *)(param_1 + 0x10) + (long)(int)((uint)uVar3 + local_2c) * 3);
    break;
  case 3:
    local_18 = *(uint3 *)(*(long *)(param_1 + 8) + (ulong)uVar3 * 0x20);
  }
  return (ulong)local_18;
}


//===== FUN_00109b0c @ 00109b0c size=18 =====

undefined1 FUN_00109b0c(long param_1)

{
  return *(undefined1 *)(param_1 + 2);
}


//===== FUN_00109b1e @ 00109b1e size=18 =====

undefined1 FUN_00109b1e(long param_1)

{
  return *(undefined1 *)(param_1 + 3);
}


//===== FUN_00109b30 @ 00109b30 size=18 =====

undefined2 FUN_00109b30(long param_1)

{
  return *(undefined2 *)(param_1 + 4);
}


//===== FUN_00109b44 @ 00109b44 size=10 =====

void FUN_00109b44(void)

{
  return;
}


//===== FUN_00109b4e @ 00109b4e size=10 =====

void FUN_00109b4e(void)

{
  return;
}


//===== FUN_00109b58 @ 00109b58 size=60 =====

void FUN_00109b58(undefined8 *param_1,undefined8 param_2,undefined4 param_3)

{
  *param_1 = param_2;
  *(undefined4 *)(param_1 + 1) = param_3;
  *(undefined4 *)((long)param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 2) = 0;
  return;
}


//===== FUN_00109b94 @ 00109b94 size=87 =====

undefined8 FUN_00109b94(long *param_1,undefined2 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = *(int *)((long)param_1 + 0xc);
  *(undefined2 *)(*param_1 + (long)iVar1 * 2) = param_2;
  *(int *)((long)param_1 + 0xc) = iVar1 + 1;
  if (*(int *)((long)param_1 + 0xc) < (int)param_1[1]) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


//===== FUN_00109bec @ 00109bec size=28 =====

undefined8 FUN_00109bec(long param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x10) = param_2;
  return 0;
}


//===== FUN_00109c08 @ 00109c08 size=27 =====

int FUN_00109c08(long param_1)

{
  return *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc);
}


//===== FUN_00109c24 @ 00109c24 size=311 =====

int FUN_00109c24(long *param_1,int param_2,long param_3)

{
  int local_10;
  int local_c;
  
  if (*(int *)((long)param_1 + 0xc) < param_2) {
    for (local_10 = 0; local_10 < *(int *)((long)param_1 + 0xc); local_10 = local_10 + 1) {
      *(undefined2 *)((long)local_10 * 2 + param_3) = *(undefined2 *)(*param_1 + (long)local_10 * 2)
      ;
    }
    *(undefined4 *)((long)param_1 + 0xc) = 0;
    while ((local_10 < param_2 && ((int)param_1[2] != 0))) {
      *(undefined2 *)((long)local_10 * 2 + param_3) = 0;
      *(int *)(param_1 + 2) = (int)param_1[2] + -1;
      local_10 = local_10 + 1;
    }
    for (local_c = local_10; local_c < param_2; local_c = local_c + 1) {
      *(undefined2 *)((long)local_c * 2 + param_3) = 0;
    }
  }
  else {
    for (local_10 = 0; local_10 < param_2; local_10 = local_10 + 1) {
      *(undefined2 *)((long)local_10 * 2 + param_3) = *(undefined2 *)(*param_1 + (long)local_10 * 2)
      ;
    }
    FUN_00109d5c(param_1,param_2);
    local_10 = param_2;
  }
  return local_10;
}


//===== FUN_00109d5c @ 00109d5c size=108 =====

void FUN_00109d5c(long *param_1,int param_2)

{
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = 0;
  for (local_c = param_2; local_c < *(int *)((long)param_1 + 0xc); local_c = local_c + 1) {
    *(undefined2 *)(*param_1 + (long)local_10 * 2) = *(undefined2 *)(*param_1 + (long)local_c * 2);
    local_10 = local_10 + 1;
  }
  *(int *)((long)param_1 + 0xc) = local_10;
  return;
}


//===== FUN_00109dc8 @ 00109dc8 size=10 =====

void FUN_00109dc8(void)

{
  return;
}


//===== FUN_00109dd2 @ 00109dd2 size=10 =====

void FUN_00109dd2(void)

{
  return;
}


//===== FUN_00109ddc @ 00109ddc size=20 =====

void FUN_00109ddc(long param_1)

{
  *(undefined2 *)(param_1 + 8) = 0;
  return;
}


//===== FUN_00109df0 @ 00109df0 size=304 =====

uint FUN_00109df0(undefined2 *param_1,undefined8 param_2,undefined8 param_3)

{
  ushort uVar1;
  bool bVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  int local_20;
  
  if (param_1[4] == 0) {
    FUN_001084a4(param_3);
    iVar4 = FUN_0010937e(param_2);
    if (iVar4 == 0) {
      return 1;
    }
    uVar3 = FUN_00109390(param_2,0);
    *param_1 = uVar3;
    *(undefined1 *)((long)param_1 + 5) = 0;
    *(undefined1 *)(param_1 + 2) = 0;
    *(undefined1 *)(param_1 + 3) = 0;
    param_1[1] = 0;
  }
  local_20 = 0;
  while( true ) {
    if ((local_20 < 7) &&
       (uVar1 = param_1[4], iVar4 = FUN_0010937e(param_2), (int)(uint)uVar1 < iVar4)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (!bVar2) break;
    uVar5 = FUN_0010a00a(param_1,param_2,param_3);
    if (uVar5 != 0) {
      return uVar5;
    }
    local_20 = local_20 + 1;
    param_1[4] = param_1[4] + 1;
  }
  uVar1 = param_1[4];
  iVar4 = FUN_0010937e(param_2);
  return (uint)(iVar4 <= (int)(uint)uVar1);
}


//===== FUN_00109f20 @ 00109f20 size=234 =====

int FUN_00109f20(undefined2 *param_1,undefined8 param_2,undefined8 param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  
  param_1[4] = 0;
  FUN_001084a4(param_3);
  iVar3 = FUN_0010937e(param_2);
  if (iVar3 != 0) {
    uVar2 = FUN_00109390(param_2,0);
    *param_1 = uVar2;
    *(undefined1 *)((long)param_1 + 5) = 0;
    *(undefined1 *)(param_1 + 2) = 0;
    *(undefined1 *)(param_1 + 3) = 0;
    param_1[1] = 0;
    while (uVar1 = param_1[4], iVar3 = FUN_0010937e(param_2), (int)(uint)uVar1 < iVar3) {
      iVar3 = FUN_0010a00a(param_1,param_2,param_3);
      if (iVar3 != 0) {
        return iVar3;
      }
      param_1[4] = param_1[4] + 1;
    }
  }
  return 0;
}


//===== FUN_0010a00a @ 0010a00a size=4219 =====

int FUN_0010a00a(undefined2 *param_1,undefined8 param_2,undefined8 *param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  byte bVar3;
  char cVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined4 uVar8;
  int iVar9;
  long lVar10;
  undefined2 local_208;
  undefined2 local_1d8;
  undefined1 local_1d6;
  undefined2 local_1c8;
  undefined1 local_1c6;
  undefined2 local_1b8;
  undefined1 local_1b6;
  undefined2 local_1a8;
  undefined1 local_1a6;
  undefined2 local_198;
  undefined1 local_196;
  undefined2 local_188;
  undefined1 local_186;
  undefined2 local_178;
  undefined1 local_176;
  undefined2 local_168;
  undefined1 local_166;
  undefined2 local_158;
  undefined1 local_156;
  undefined2 local_148;
  undefined1 local_146;
  undefined2 local_138;
  undefined1 local_136;
  undefined2 local_128;
  undefined1 local_126;
  undefined2 local_118;
  undefined1 local_116;
  undefined2 local_108;
  undefined1 local_106;
  undefined2 local_f8;
  undefined1 local_f6;
  undefined2 local_e8;
  undefined1 local_e6;
  undefined2 local_d8;
  undefined1 local_d6;
  undefined2 local_c8;
  undefined1 local_c6;
  undefined2 local_b8;
  undefined1 local_b6;
  undefined4 local_b4;
  undefined8 local_b0;
  long local_a8;
  char *local_a0;
  long local_98;
  undefined2 local_8c;
  undefined2 local_8a;
  ushort local_88;
  undefined2 local_86;
  int local_84;
  undefined2 local_7e;
  undefined2 local_7c;
  undefined2 local_7a;
  int local_78;
  undefined2 local_72;
  long local_70;
  undefined2 local_68;
  undefined2 local_66;
  int local_64;
  undefined2 local_5e;
  undefined2 local_5c;
  undefined2 local_5a;
  int local_58;
  undefined2 local_52;
  long local_50;
  undefined2 local_42;
  int local_40;
  undefined2 local_3c;
  undefined2 local_3a;
  int local_38;
  undefined2 local_34;
  undefined2 local_32;
  int local_30;
  undefined2 local_2a;
  
  local_b0 = *param_3;
  local_a8 = FUN_0010935c(param_2,param_1[4]);
  local_a0 = (char *)(local_a8 + 2);
  local_98 = FUN_00109906(local_b0,local_a0);
  if (local_98 == 0) {
    return 0x67;
  }
  local_8c = FUN_001094ca(param_2,local_a8);
  local_8a = FUN_0010947c(param_2,local_a8);
  bVar3 = FUN_00109b1e(local_98);
  local_88 = (ushort)bVar3;
  cVar4 = FUN_00109b0c(local_98);
  if (cVar4 == '\x01') {
    local_f8 = 0;
    local_f6 = 0;
    local_86 = 0;
    for (local_84 = 0; local_84 < (int)(uint)local_88; local_84 = local_84 + 1) {
      local_7e = (undefined2)((local_84 << 8) / (int)(uint)local_88);
      uVar8 = FUN_001099ce(local_b0,local_98,local_84);
      local_208 = (undefined2)uVar8;
      local_f6 = (undefined1)((uint)uVar8 >> 0x10);
      local_f8 = local_208;
      uVar5 = FUN_001083b0(local_98,local_84);
      local_86 = uVar5;
      uVar6 = FUN_0010b086(param_1,*param_1,local_8a,local_7e);
      iVar9 = FUN_001084c4(param_3,local_8c,uVar6,&local_f8,0,uVar5,uVar5);
      if (iVar9 != 0) {
        return iVar9;
      }
      local_b4 = 0;
    }
    param_1[2] = local_f8;
    *(undefined1 *)(param_1 + 3) = local_f6;
    param_1[1] = local_86;
  }
  else {
    cVar4 = FUN_00109b0c(local_98);
    if (cVar4 == '\x03') {
      local_7c = param_1[1];
      local_7a = FUN_001083b0(local_98,0xffffffff);
      local_108 = param_1[2];
      local_106 = *(undefined1 *)(param_1 + 3);
      uVar8 = FUN_001099ce(local_b0,local_98,0xffffffff);
      local_208 = (undefined2)uVar8;
      local_116 = (undefined1)((uint)uVar8 >> 0x10);
      local_118 = local_208;
      for (local_78 = 0; uVar6 = local_7a, uVar5 = local_7c, local_78 < (int)(uint)local_88;
          local_78 = local_78 + 1) {
        uVar2 = (undefined2)((local_78 << 8) / (int)(uint)local_88);
        local_72 = uVar2;
        uVar8 = FUN_0010b0c6(param_1,&local_108,&local_118,uVar2);
        local_208 = (undefined2)uVar8;
        local_e6 = (undefined1)((uint)uVar8 >> 0x10);
        local_e8 = local_208;
        uVar7 = FUN_0010b086(param_1,*param_1,local_8a,local_72);
        iVar9 = FUN_001084c4(param_3,local_8c,uVar7,&local_e8,uVar2,uVar5,uVar6);
        if (iVar9 != 0) {
          return iVar9;
        }
        local_b4 = 0;
      }
      param_1[2] = local_118;
      *(undefined1 *)(param_1 + 3) = local_116;
      param_1[1] = local_7a;
    }
    else {
      cVar4 = FUN_00109b0c(local_98);
      if (cVar4 == '\x02') {
        uVar1 = param_1[4];
        iVar9 = FUN_0010937e(param_2);
        if ((int)(uVar1 + 1) < iVar9) {
          lVar10 = FUN_0010935c(param_2,(ushort)param_1[4] + 1);
          local_70 = FUN_00109906(local_b0,lVar10 + 2);
        }
        else {
          local_70 = FUN_00109906(local_b0,&DAT_00148a27);
        }
        if (local_70 == 0) {
          return 0x67;
        }
        if (((*local_a0 == '+') &&
            ((((local_a0[1] == 'k' || (local_a0[1] == 'g')) || (local_a0[1] == 'b')) ||
             (local_a0[1] == 'q')))) || ((*local_a0 == ',' && (local_a0[1] == 'k')))) {
          local_68 = param_1[1];
          local_66 = FUN_001083b0(local_70,4);
          local_128 = param_1[2];
          local_126 = *(undefined1 *)(param_1 + 3);
          uVar8 = FUN_001099ce(local_b0,local_98,0);
          local_208 = (undefined2)uVar8;
          local_136 = (undefined1)((uint)uVar8 >> 0x10);
          local_138 = local_208;
          local_148 = 0;
          local_146 = 0;
          for (local_64 = 0; local_64 < (int)(uint)local_88; local_64 = local_64 + 1) {
            local_5e = (undefined2)((local_64 << 8) / (int)(uint)local_88);
            uVar8 = FUN_001099ce(local_b0,local_98,local_64);
            local_208 = (undefined2)uVar8;
            local_d6 = (undefined1)((uint)uVar8 >> 0x10);
            local_d8 = local_208;
            uVar8 = FUN_0010b1cc(param_1,&local_128,&local_138,&local_d8);
            uVar2 = local_5e;
            uVar6 = local_66;
            uVar5 = local_68;
            local_208 = (undefined2)uVar8;
            local_146 = (undefined1)((uint)uVar8 >> 0x10);
            local_148 = local_208;
            uVar7 = FUN_0010b086(param_1,*param_1,local_8a,local_5e);
            iVar9 = FUN_001084c4(param_3,local_8c,uVar7,&local_148,uVar2,uVar5,uVar6);
            if (iVar9 != 0) {
              return iVar9;
            }
            local_b4 = 0;
          }
          param_1[2] = local_148;
          *(undefined1 *)(param_1 + 3) = local_146;
          param_1[1] = local_66;
        }
        else {
          local_5c = param_1[1];
          local_5a = FUN_001083b0(local_70,0);
          uVar8 = FUN_001099ce(local_b0,local_70,0);
          local_208 = (undefined2)uVar8;
          local_156 = (undefined1)((uint)uVar8 >> 0x10);
          local_158 = local_208;
          for (local_58 = 0; local_58 < (int)(uint)local_88; local_58 = local_58 + 1) {
            local_52 = (undefined2)((local_58 << 8) / (int)(uint)local_88);
            uVar8 = FUN_0010b2ea(param_1,local_b0,local_58,local_98,param_1 + 2,&local_158);
            uVar2 = local_52;
            uVar6 = local_5a;
            uVar5 = local_5c;
            local_208 = (undefined2)uVar8;
            local_166 = (undefined1)((uint)uVar8 >> 0x10);
            local_168 = local_208;
            uVar7 = FUN_0010b086(param_1,*param_1,local_8a,local_52);
            iVar9 = FUN_001084c4(param_3,local_8c,uVar7,&local_168,uVar2,uVar5,uVar6);
            if (iVar9 != 0) {
              return iVar9;
            }
            local_b4 = 0;
          }
          param_1[2] = local_158;
          *(undefined1 *)(param_1 + 3) = local_156;
          param_1[1] = local_5a;
        }
      }
      else {
        cVar4 = FUN_00109b0c(local_98);
        if (cVar4 == '\x04') {
          lVar10 = FUN_0010935c(param_2,(ushort)param_1[4] + 1);
          local_50 = FUN_00109906(local_b0,lVar10 + 2);
          if (local_50 == 0) {
            return 0x67;
          }
          if ((*local_a0 == ';') && ((local_a0[1] == 'k' || (local_a0[1] == 'v')))) {
            local_42 = FUN_001083b0(local_50,0);
            local_178 = 0;
            local_176 = 0;
            for (local_40 = 0; uVar5 = local_42, local_40 < (int)(uint)local_88;
                local_40 = local_40 + 1) {
              local_3c = (undefined2)((local_40 << 8) / (int)(uint)local_88);
              uVar6 = FUN_0010b086(param_1,*param_1,local_8a,local_3c);
              iVar9 = FUN_001084c4(param_3,local_8c,uVar6,&local_178,0,uVar5,uVar5);
              if (iVar9 != 0) {
                return iVar9;
              }
              local_b4 = 0;
            }
            param_1[2] = local_178;
            *(undefined1 *)(param_1 + 3) = local_176;
            param_1[1] = local_42;
          }
          else {
            local_3a = FUN_001083b0(local_50,0);
            uVar8 = FUN_001099ce(local_b0,local_50,0);
            local_208 = (undefined2)uVar8;
            local_186 = (undefined1)((uint)uVar8 >> 0x10);
            local_188 = local_208;
            uVar8 = FUN_001099ce(local_b0,local_98,0xffffffff);
            local_208 = (undefined2)uVar8;
            local_196 = (undefined1)((uint)uVar8 >> 0x10);
            local_198 = local_208;
            for (local_38 = 0; local_38 < (int)(uint)local_88; local_38 = local_38 + 1) {
              local_34 = (undefined2)((local_38 << 8) / (int)(uint)local_88);
              uVar8 = FUN_001099ce(local_b0,local_98,local_38);
              local_208 = (undefined2)uVar8;
              local_c6 = (undefined1)((uint)uVar8 >> 0x10);
              local_c8 = local_208;
              uVar8 = FUN_0010b1cc(param_1,&local_188,&local_198,&local_c8);
              uVar5 = local_3a;
              local_208 = (undefined2)uVar8;
              local_1a6 = (undefined1)((uint)uVar8 >> 0x10);
              local_1a8 = local_208;
              uVar6 = FUN_0010b086(param_1,*param_1,local_8a,local_34);
              iVar9 = FUN_001084c4(param_3,local_8c,uVar6,&local_1a8,0,uVar5,uVar5);
              if (iVar9 != 0) {
                return iVar9;
              }
              local_b4 = 0;
            }
            param_1[2] = local_198;
            *(undefined1 *)(param_1 + 3) = local_196;
            param_1[1] = local_3a;
          }
        }
        else {
          cVar4 = FUN_00109b0c(local_98);
          if (cVar4 == '\x05') {
            local_32 = param_1[1];
            local_1b8 = param_1[2];
            local_1b6 = *(undefined1 *)(param_1 + 3);
            uVar8 = FUN_001099ce(local_b0,local_98,0);
            local_208 = (undefined2)uVar8;
            local_1c6 = (undefined1)((uint)uVar8 >> 0x10);
            local_1c8 = local_208;
            local_1d8 = 0;
            local_1d6 = 0;
            for (local_30 = 0; local_30 < (int)(uint)local_88; local_30 = local_30 + 1) {
              local_2a = (undefined2)((local_30 << 8) / (int)(uint)local_88);
              uVar8 = FUN_001099ce(local_b0,local_98,local_30);
              local_208 = (undefined2)uVar8;
              local_b6 = (undefined1)((uint)uVar8 >> 0x10);
              local_b8 = local_208;
              uVar8 = FUN_0010b1cc(param_1,&local_1b8,&local_1c8,&local_b8);
              uVar5 = local_32;
              local_208 = (undefined2)uVar8;
              local_1d6 = (undefined1)((uint)uVar8 >> 0x10);
              local_1d8 = local_208;
              uVar6 = FUN_0010b086(param_1,*param_1,local_8a,local_2a);
              iVar9 = FUN_001084c4(param_3,local_8c,uVar6,&local_1d8,0,uVar5,uVar5);
              if (iVar9 != 0) {
                return iVar9;
              }
              local_b4 = 0;
            }
            param_1[2] = local_1d8;
            *(undefined1 *)(param_1 + 3) = local_1d6;
            param_1[1] = local_32;
          }
        }
      }
    }
  }
  *param_1 = local_8a;
  return 0;
}


//===== FUN_0010b086 @ 0010b086 size=63 =====

undefined4 FUN_0010b086(undefined8 param_1,ushort param_2,ushort param_3,ushort param_4)

{
  int iVar1;
  
  iVar1 = (uint)param_4 * ((uint)param_3 - (uint)param_2);
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0xff;
  }
  return CONCAT22((short)(char)((uint)iVar1 >> 0x18),(short)((uint)iVar1 >> 8) + param_2);
}


//===== FUN_0010b0c6 @ 0010b0c6 size=262 =====

ulong FUN_0010b0c6(undefined8 param_1,byte *param_2,byte *param_3,ushort param_4)

{
  int iVar1;
  int iVar2;
  undefined2 local_28;
  undefined1 local_18 [16];
  
  iVar1 = (uint)param_4 * ((uint)param_3[1] - (uint)param_2[1]);
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0xff;
  }
  iVar2 = (uint)param_4 * ((uint)*param_3 - (uint)*param_2);
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xff;
  }
  local_28 = CONCAT11(param_2[1] + (char)((uint)iVar1 >> 8),*param_2 + (char)((uint)iVar2 >> 8));
  iVar1 = (uint)param_4 * ((uint)param_3[2] - (uint)param_2[2]);
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0xff;
  }
  local_18._0_3_ = CONCAT12(param_2[2] + (char)((uint)iVar1 >> 8),local_28);
  return CONCAT53(0,local_18._0_3_);
}


//===== FUN_0010b1cc @ 0010b1cc size=286 =====

ulong FUN_0010b1cc(undefined8 param_1,byte *param_2,byte *param_3,byte *param_4)

{
  byte bVar1;
  undefined2 local_28;
  undefined1 local_26;
  undefined1 local_18 [16];
  
  if (param_3[1] == 0) {
    bVar1 = 0;
  }
  else {
    bVar1 = (byte)(((uint)param_2[1] * (uint)param_4[1]) / (uint)param_3[1]);
  }
  if (*param_3 == 0) {
    local_28 = (ushort)bVar1 << 8;
  }
  else {
    local_28 = CONCAT11(bVar1,(char)(((uint)*param_2 * (uint)*param_4) / (uint)*param_3));
  }
  if (param_3[2] == 0) {
    local_26 = 0;
  }
  else {
    local_26 = (undefined1)(((uint)param_2[2] * (uint)param_4[2]) / (uint)param_3[2]);
  }
  local_18._0_3_ = CONCAT12(local_26,local_28);
  return CONCAT53(0,local_18._0_3_);
}


//===== FUN_0010b2ea @ 0010b2ea size=1218 =====

ulong FUN_0010b2ea(undefined8 param_1,undefined8 param_2,int param_3,undefined8 param_4,
                  byte *param_5,byte *param_6)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar10;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined2 local_78;
  char local_76;
  char local_48;
  undefined1 local_38 [16];
  int local_28;
  
  uVar7 = FUN_001099ce(param_2,param_4,0);
  bVar10 = (byte)(uVar7 >> 8);
  bVar2 = (byte)(uVar7 >> 0x10);
  uVar8 = FUN_001099ce(param_2,param_4,0xffffffff);
  bVar6 = (byte)(uVar8 >> 8);
  bVar3 = (byte)(uVar8 >> 0x10);
  uVar9 = FUN_001099ce(param_2,param_4,param_3);
  if (bVar10 == bVar6) {
    local_28 = -1;
  }
  else {
    local_28 = (int)(((uint)param_6[1] - (uint)param_5[1]) * 0x400) /
               (int)((uint)bVar6 - (uint)bVar10);
  }
  if ((local_28 < 0) || (0x1000 < local_28)) {
    local_78._1_1_ = param_5[1];
    bVar10 = param_6[1];
    bVar6 = param_5[1];
    bVar4 = FUN_00109b1e(param_4);
    local_78._1_1_ =
         local_78._1_1_ + (char)((int)(((uint)bVar10 - (uint)bVar6) * param_3) / (int)(uint)bVar4);
  }
  else {
    local_28 = ((uVar9 >> 8 & 0xff) - (uint)bVar10) * local_28;
    if (local_28 < 0) {
      local_28 = local_28 + 0x3ff;
    }
    iVar1 = (uint)param_5[1] + (local_28 >> 10);
    if (iVar1 < 1) {
      local_78._1_1_ = 0;
    }
    else {
      local_78._1_1_ = (byte)iVar1;
    }
  }
  local_48 = (char)uVar7;
  if (local_48 == (char)uVar8) {
    local_28 = -1;
  }
  else {
    local_28 = (int)(((uint)*param_6 - (uint)*param_5) * 0x400) /
               (int)((uVar8 & 0xff) - (uVar7 & 0xff));
  }
  if ((local_28 < 0) || (0x1000 < local_28)) {
    bVar10 = *param_5;
    bVar6 = *param_6;
    bVar4 = *param_5;
    bVar5 = FUN_00109b1e(param_4);
    local_78 = CONCAT11(local_78._1_1_,
                        bVar10 + (char)((int)(((uint)bVar6 - (uint)bVar4) * param_3) /
                                       (int)(uint)bVar5));
  }
  else {
    local_28 = ((uVar9 & 0xff) - (uVar7 & 0xff)) * local_28;
    if (local_28 < 0) {
      local_28 = local_28 + 0x3ff;
    }
    iVar1 = (uint)*param_5 + (local_28 >> 10);
    if (iVar1 < 1) {
      local_78 = (ushort)local_78._1_1_ << 8;
    }
    else {
      local_78 = CONCAT11(local_78._1_1_,(char)iVar1);
    }
  }
  if (bVar2 == bVar3) {
    local_28 = -1;
  }
  else {
    local_28 = (int)(((uint)param_6[2] - (uint)param_5[2]) * 0x400) /
               (int)((uint)bVar3 - (uint)bVar2);
  }
  if ((local_28 < 0) || (0x1000 < local_28)) {
    bVar2 = param_5[2];
    bVar3 = param_6[2];
    bVar10 = param_5[2];
    bVar6 = FUN_00109b1e(param_4);
    local_76 = bVar2 + (char)((int)(((uint)bVar3 - (uint)bVar10) * param_3) / (int)(uint)bVar6);
  }
  else {
    local_28 = ((uVar9 >> 0x10 & 0xff) - (uint)bVar2) * local_28;
    if (local_28 < 0) {
      local_28 = local_28 + 0x3ff;
    }
    iVar1 = (uint)param_5[2] + (local_28 >> 10);
    if (iVar1 < 1) {
      local_76 = '\0';
    }
    else {
      local_76 = (char)iVar1;
    }
  }
  local_38._0_3_ = CONCAT12(local_76,local_78);
  return CONCAT53(0,local_38._0_3_);
}


//===== FUN_0010b7ac @ 0010b7ac size=10 =====

void FUN_0010b7ac(void)

{
  return;
}


//===== FUN_0010b7b6 @ 0010b7b6 size=10 =====

void FUN_0010b7b6(void)

{
  return;
}


//===== FUN_0010b7c0 @ 0010b7c0 size=165 =====

void FUN_0010b7c0(undefined8 *param_1,int param_2)

{
  if (param_2 == 1) {
    *param_1 = &DAT_0014ea40;
    param_1[1] = &DAT_0014ca40;
    *(undefined4 *)(param_1 + 2) = 0x1000;
  }
  else if (param_2 == 2) {
    *param_1 = &DAT_00152a40;
    param_1[1] = &DAT_00150a40;
    *(undefined4 *)(param_1 + 2) = 0x1000;
  }
  else {
    *param_1 = &DAT_0014aa40;
    param_1[1] = &DAT_00148a40;
    *(undefined4 *)(param_1 + 2) = 0x1000;
  }
  FUN_0010b866(param_1);
  return;
}


//===== FUN_0010b866 @ 0010b866 size=48 =====

void FUN_0010b866(long param_1)

{
  ushort uVar1;
  
  uVar1 = FUN_001064e6();
  *(short *)(param_1 + 0x18) = (short)((int)(uint)uVar1 % *(int *)(param_1 + 0x10));
  return;
}


//===== FUN_0010b896 @ 0010b896 size=46 =====

void FUN_0010b896(long param_1,undefined2 param_2,undefined2 param_3)

{
  *(undefined2 *)(param_1 + 0x14) = param_2;
  *(undefined2 *)(param_1 + 0x16) = param_3;
  return;
}


//===== FUN_0010b8c4 @ 0010b8c4 size=190 =====

void FUN_0010b8c4(long *param_1,int *param_2,int *param_3)

{
  ushort uVar1;
  int iVar2;
  
  if ((int)param_1[2] <= (int)(uint)*(ushort *)(param_1 + 3)) {
    *(undefined2 *)(param_1 + 3) = 0;
  }
  iVar2 = (uint)*(ushort *)((long)param_1 + 0x14) *
          (int)*(short *)(*param_1 + (ulong)*(ushort *)(param_1 + 3) * 2);
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0x7f;
  }
  *param_2 = iVar2 >> 7;
  uVar1 = *(ushort *)(param_1 + 3);
  iVar2 = (uint)*(ushort *)((long)param_1 + 0x16) * (int)*(short *)(param_1[1] + (ulong)uVar1 * 2);
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0x7f;
  }
  *param_3 = iVar2 >> 7;
  *(ushort *)(param_1 + 3) = uVar1 + 1;
  return;
}


//===== FUN_0010b984 @ 0010b984 size=10 =====

void FUN_0010b984(void)

{
  return;
}


//===== FUN_0010b98e @ 0010b98e size=10 =====

void FUN_0010b98e(void)

{
  return;
}


//===== FUN_0010b998 @ 0010b998 size=176 =====

void FUN_0010b998(long param_1,int param_2,int param_3)

{
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(short *)(param_1 + 0x18) = (short)((param_2 * 0x100 * param_3) / 10000);
  *(short *)(param_1 + 0x1a) =
       (short)(((((100 - param_3) * 0x1460) / 100 + 0x33c0) * param_2) / 100);
  return;
}


//===== FUN_0010ba48 @ 0010ba48 size=60 =====

undefined8 FUN_0010ba48(undefined1 *param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *param_1 = 8;
  return 0;
}


//===== FUN_0010ba84 @ 0010ba84 size=84 =====

undefined8 FUN_0010ba84(long param_1)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (*(long *)(param_1 + 0x10) == 0) {
    uVar3 = 1;
  }
  else {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = FUN_00107fac(*(undefined8 *)(param_1 + 0x10));
    if (iVar1 < iVar2) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
  }
  return uVar3;
}


//===== FUN_0010bad8 @ 0010bad8 size=278 =====

int FUN_0010bad8(undefined1 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined1 local_1e;
  undefined1 local_1d;
  int local_1c;
  
  FUN_00109346(param_3);
  iVar1 = FUN_0010bc0e(param_1,param_2,&local_1d,param_4);
  if (iVar1 == 0) {
    local_1c = iVar1;
    FUN_0010ce0c(&local_1e);
    iVar1 = FUN_0010ce20(&local_1e,param_2,*param_1,(int)*(short *)(param_1 + 0x18),
                         (int)*(short *)(param_1 + 0x1a));
    local_1c = iVar1;
    if ((iVar1 == 0) &&
       (iVar1 = FUN_0010be98(param_1,param_2,param_3), local_1c = iVar1, iVar1 == 0)) {
      FUN_0010c15a(param_1,param_3);
      FUN_0010c2f2(param_1,param_3);
      *param_1 = local_1d;
      iVar1 = 0;
    }
    FUN_0010ce16(&local_1e);
  }
  return iVar1;
}


//===== FUN_0010bc0e @ 0010bc0e size=619 =====

int FUN_0010bc0e(byte *param_1,undefined8 param_2,byte *param_3,int *param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined1 local_25;
  int local_24;
  int local_20;
  byte local_1a;
  byte local_19;
  
  if ((*(long *)(param_1 + 0x10) == 0) ||
     (iVar3 = *(int *)(param_1 + 8), iVar2 = FUN_00107fac(*(undefined8 *)(param_1 + 0x10)),
     iVar2 <= iVar3)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    iVar3 = 100;
  }
  else {
    FUN_00107554(&local_25);
    local_20 = 1;
    while (iVar3 = *(int *)(param_1 + 8), iVar2 = FUN_00107fac(*(undefined8 *)(param_1 + 0x10)),
          iVar3 < iVar2) {
      local_1a = FUN_00107fe8(*(undefined8 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 8));
      if (((local_20 == 0) || (local_1a < 2)) || (9 < local_1a)) {
        local_20 = 0;
        iVar3 = FUN_00109556(param_2,local_1a);
        local_24 = iVar3;
        if (iVar3 != 0) goto LAB_0010be81;
      }
      else if (local_1a != 2) {
        *param_1 = local_1a;
      }
      iVar3 = FUN_00107732(&local_25,local_1a);
      if (iVar3 != 0) break;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    iVar3 = *(int *)(param_1 + 8);
    iVar2 = FUN_00107fac(*(undefined8 *)(param_1 + 0x10));
    if (iVar3 < iVar2) {
      *param_4 = 0;
      while ((iVar3 = *(int *)(param_1 + 8), iVar2 = FUN_00107fac(*(undefined8 *)(param_1 + 0x10)),
             iVar3 < iVar2 &&
             (local_19 = FUN_00107fe8(*(undefined8 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 8)),
             local_19 < 10))) {
        if (1 < local_19) {
          *param_3 = local_19;
          if (local_19 == 6) {
            *param_4 = *param_4 + 0x29a;
          }
          else if (local_19 == 7) {
            *param_4 = *param_4 + 2000;
          }
          else if (local_19 == 8) {
            *param_4 = *param_4 + 4000;
          }
          else if (local_19 == 9) {
            *param_4 = *param_4 + 4000;
          }
        }
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
    }
    else {
      *param_3 = 5;
      *param_4 = 0;
    }
    iVar3 = 0;
LAB_0010be81:
    FUN_0010755e(&local_25);
  }
  return iVar3;
}


//===== FUN_0010be98 @ 0010be98 size=706 =====

undefined8 FUN_0010be98(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  long local_40;
  char local_31;
  int local_24;
  char local_20;
  short local_1e;
  
  local_40 = 0;
  local_31 = '\b';
  FUN_00109684(param_2);
  do {
    lVar2 = FUN_0010969a(param_2);
    if (lVar2 == 0) {
      if (local_40 != 0) {
        local_1e = 0;
        if (*(char *)(local_40 + 1) == '\t') {
          if (*(ushort *)(local_40 + 2) != 0) {
            local_1e = *(short *)(local_40 + 8 + (long)(int)(*(ushort *)(local_40 + 2) - 1) * 4);
          }
          if (local_1e != 0) {
            local_1e = local_1e + *(short *)(param_1 + 0x18) * 0x19;
          }
        }
        iVar1 = FUN_0010c82a(param_1,local_31,*(undefined1 *)(local_40 + 1),param_3,local_1e);
        if (iVar1 < 0) {
          return 0x79;
        }
      }
      return 0;
    }
    for (local_24 = 0; local_40 = lVar2, local_24 < (int)(uint)*(ushort *)(lVar2 + 2);
        local_24 = local_24 + 1) {
      local_20 = *(char *)(lVar2 + 10 + (long)local_24 * 4);
      if (local_20 == -0x69) {
        if (local_24 + 1U == (uint)*(ushort *)(lVar2 + 2)) {
          iVar1 = FUN_0010c770(param_1,8,param_3,*(undefined2 *)(lVar2 + 8 + (long)local_24 * 4));
          if (iVar1 < 0) {
            return 0x79;
          }
        }
        else {
          local_20 = *(char *)(lVar2 + 10 + (long)(local_24 + 1) * 4);
          iVar1 = FUN_0010c770(param_1,local_20,param_3,
                               *(undefined2 *)(lVar2 + 8 + (long)local_24 * 4));
          if (iVar1 < 0) {
            return 0x79;
          }
          iVar1 = FUN_0010c5e4(param_1,0x97,local_20,param_3,
                               *(undefined2 *)(lVar2 + 8 + (long)(local_24 + 1) * 4));
          if (iVar1 < 0) {
            return 0x79;
          }
          local_24 = local_24 + 1;
        }
      }
      else {
        iVar1 = FUN_0010c82a(param_1,local_31,local_20,param_3,0);
        if (iVar1 < 0) {
          return 0x79;
        }
        iVar1 = FUN_0010c5e4(param_1,local_31,local_20,param_3,
                             *(undefined2 *)(lVar2 + 8 + (long)local_24 * 4));
        if (iVar1 < 0) {
          return 0x79;
        }
      }
      if (local_20 != -0x68) {
        local_31 = local_20;
      }
    }
  } while( true );
}


//===== FUN_0010c15a @ 0010c15a size=407 =====

void FUN_0010c15a(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  
  iVar1 = FUN_0010937e(param_2);
  if (1 < iVar1) {
    FUN_0010943c(param_2,iVar1 + -1,0x8000);
    FUN_0010943c(param_2,iVar1 + -2,0x8000);
    lVar2 = FUN_0010935c(param_2,iVar1 + -2);
    if ((*(char *)(lVar2 + 3) != '-') &&
       (((*(char *)(lVar2 + 2) != '+' ||
         (((((*(char *)(lVar2 + 3) != 'a' && (*(char *)(lVar2 + 3) != 'i')) &&
            (*(char *)(lVar2 + 3) != 'u')) &&
           ((*(char *)(lVar2 + 3) != 'e' && (*(char *)(lVar2 + 3) != 'o')))) &&
          (*(char *)(lVar2 + 3) != 'x')))) && (-1 < iVar1 + -3)))) {
      lVar2 = FUN_0010935c(param_2,iVar1 + -3);
      if (*(char *)(lVar2 + 3) != ';') {
        if ((*(char *)(lVar2 + 3) == 'Q') || (*(char *)(lVar2 + 3) == 'q')) {
          FUN_0010943c(param_2,iVar1 + -3,0x4000);
        }
        else {
          FUN_0010943c(param_2,iVar1 + -3,0x8000);
        }
      }
    }
  }
  return;
}


//===== FUN_0010c2f2 @ 0010c2f2 size=753 =====

undefined8 FUN_0010c2f2(long param_1,undefined8 param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  undefined8 uVar5;
  int local_3c;
  int local_34;
  short local_2e;
  short local_2c;
  
  sVar1 = (short)(0x7d0000 / (long)(int)*(short *)(param_1 + 0x1a));
  local_3c = 0;
  do {
    iVar4 = FUN_0010937e(param_2);
    if (iVar4 <= local_3c) {
      return 0;
    }
    sVar2 = FUN_00109390(param_2,local_3c);
    if (sVar2 == 0) {
      iVar4 = FUN_0010937e(param_2);
      local_34 = local_3c;
      if (iVar4 + -1 == local_3c) {
        if (local_3c + -2 < 0) {
          local_2e = FUN_00109390(param_2,local_3c + -1);
        }
        else {
          sVar2 = FUN_00109390(param_2,local_3c + -1);
          local_2e = FUN_00109390(param_2,local_3c + -2);
          local_2e = sVar2 * 2 - local_2e;
        }
        if (sVar1 < local_2e) {
          local_2e = sVar1;
        }
        FUN_001093c6(param_2,local_3c,local_2e);
      }
      else {
        do {
          local_34 = local_34 + 1;
          iVar4 = FUN_0010937e(param_2);
          if (iVar4 <= local_34) break;
          sVar2 = FUN_00109390(param_2,local_34);
        } while (sVar2 == 0);
        iVar4 = FUN_0010937e(param_2);
        if (local_34 < iVar4) {
          sVar2 = FUN_00109390(param_2,local_34);
          if (local_3c + -1 < 0) {
            iVar4 = ((int)sVar1 - (int)sVar2) * 5;
            FUN_001093c6(param_2,local_3c,
                         sVar1 - ((short)((ulong)((long)iVar4 * 0x2aaaaaab) >> 0x20) -
                                 (short)(iVar4 >> 0x1f)));
          }
          else {
            uVar5 = FUN_0010935c(param_2,local_3c + -1);
            sVar3 = FUN_0010947c(param_2,uVar5);
            FUN_001093c6(param_2,local_3c,
                         (short)(((int)sVar2 - (int)sVar3) / ((local_34 - local_3c) + 1)) + sVar3);
          }
        }
        else if (local_3c < 2) {
          FUN_001093c6(param_2,local_3c,sVar1);
        }
        else {
          sVar2 = FUN_00109390(param_2,local_3c + -1);
          local_2c = FUN_00109390(param_2,local_3c + -2);
          local_2c = sVar2 * 2 - local_2c;
          if (sVar1 < local_2c) {
            local_2c = sVar1;
          }
          FUN_001093c6(param_2,local_3c,local_2c);
        }
      }
    }
    local_3c = local_3c + 1;
  } while( true );
}


//===== FUN_0010c5e4 @ 0010c5e4 size=364 =====

undefined4
FUN_0010c5e4(undefined8 param_1,undefined1 param_2,char param_3,undefined8 param_4,
            undefined2 param_5)

{
  undefined4 uVar1;
  int iVar2;
  char local_38;
  char local_37;
  undefined1 local_36;
  undefined1 local_29;
  long local_28;
  char *local_20;
  
  FUN_00107554(&local_29);
  local_28 = FUN_001076da(&local_29,param_2);
  local_20 = (char *)FUN_001076da(&local_29,param_3);
  local_36 = 0;
  if (param_3 == -0x68) {
    local_38 = *(char *)(local_28 + 1);
    local_37 = *local_20;
    uVar1 = FUN_0010925c(param_4,&local_38,param_5);
  }
  else if ((((param_3 == '\n') || (param_3 == '\v')) || (param_3 == '\f')) ||
          (((param_3 == '\r' || (param_3 == '\x0e')) || (param_3 == -0x6a)))) {
    iVar2 = FUN_00107732(&local_29,param_2);
    if (iVar2 == 0) {
      if (*(char *)(local_28 + 1) == *local_20) {
        local_38 = *local_20;
        local_37 = '-';
      }
      else {
        local_38 = '+';
        local_37 = *local_20;
      }
    }
    else {
      local_38 = ';';
      local_37 = *local_20;
    }
    uVar1 = FUN_0010925c(param_4,&local_38,param_5);
  }
  else {
    uVar1 = FUN_0010925c(param_4,local_20,param_5);
  }
  FUN_0010755e(&local_29);
  return uVar1;
}


//===== FUN_0010c770 @ 0010c770 size=155 =====

undefined4 FUN_0010c770(undefined8 param_1,undefined1 param_2,undefined8 param_3,undefined2 param_4)

{
  undefined4 uVar1;
  char *pcVar2;
  undefined1 local_1a;
  char local_19;
  
  FUN_00107554(&local_1a);
  pcVar2 = (char *)FUN_001076da(&local_1a,param_2);
  local_19 = *pcVar2;
  if ((local_19 == 's') || (local_19 == 'S')) {
    uVar1 = FUN_0010925c(param_3,&DAT_00154a40,param_4);
  }
  else {
    uVar1 = FUN_0010925c(param_3,&DAT_00154a43,param_4);
  }
  FUN_0010755e(&local_1a);
  return uVar1;
}


//===== FUN_0010c82a @ 0010c82a size=929 =====

undefined4
FUN_0010c82a(undefined8 param_1,undefined1 param_2,byte param_3,undefined8 param_4,
            undefined2 param_5)

{
  undefined4 uVar1;
  undefined1 local_38;
  char local_37;
  undefined1 local_36;
  undefined1 local_31;
  long local_30;
  char *local_28;
  undefined4 local_1c;
  
  FUN_00107554(&local_31);
  local_30 = FUN_001076da(&local_31,param_2);
  local_28 = (char *)FUN_001076da(&local_31,param_3);
  local_1c = 0;
  local_36 = 0;
  if (((((*(char *)(local_30 + 1) == 'a') || (*(char *)(local_30 + 1) == 'i')) ||
       (*(char *)(local_30 + 1) == 'u')) ||
      ((*(char *)(local_30 + 1) == 'e' || (*(char *)(local_30 + 1) == 'o')))) ||
     (*(char *)(local_30 + 1) == 'x')) {
    if (param_3 < 10) {
      local_38 = *(undefined1 *)(local_30 + 1);
      local_37 = ';';
      uVar1 = FUN_0010925c(param_4,&local_38,param_5);
      goto LAB_0010cbd3;
    }
    local_38 = 0x2b;
    local_37 = FUN_0010cbea(param_1,(int)*local_28);
    if (local_37 != '\0') {
      uVar1 = FUN_0010925c(param_4,&local_38,param_5);
      goto LAB_0010cbd3;
    }
  }
  if (((*(char *)(local_30 + 1) == 'A') || (*(char *)(local_30 + 1) == 'I')) ||
     ((*(char *)(local_30 + 1) == 'U' || (*(char *)(local_30 + 1) == 'O')))) {
    if (((*local_28 == ',') || (*local_28 == '.')) || (*local_28 == '?')) {
      local_38 = *(undefined1 *)(local_30 + 1);
      local_37 = ';';
      uVar1 = FUN_0010925c(param_4,&local_38,param_5);
      goto LAB_0010cbd3;
    }
    if (((*local_28 == 'k') || (*local_28 == 't')) ||
       ((((*local_28 == 'p' || ((*local_28 == 'c' || (*local_28 == 'K')))) || (*local_28 == 'T')) ||
        ((*local_28 == 'P' || (*local_28 == 'L')))))) {
      uVar1 = FUN_0010925c(param_4,&DAT_00154a46,param_5);
      goto LAB_0010cbd3;
    }
    if ((((*local_28 == 's') || (*local_28 == 'h')) || (*local_28 == 'S')) ||
       ((*local_28 == 'H' || (*local_28 == 'f')))) {
      uVar1 = FUN_0010925c(param_4,&DAT_00154a49,param_5);
      goto LAB_0010cbd3;
    }
    if (*local_28 == '-') {
      uVar1 = 0;
      goto LAB_0010cbd3;
    }
    local_38 = *(undefined1 *)(local_30 + 1);
    local_37 = 0x3b;
    FUN_0010925c(param_4,&local_38,param_5);
    local_38 = 0x3b;
    local_37 = FUN_0010cd0a(param_1,(int)*local_28);
    if (local_37 != '\0') {
      local_1c = FUN_0010925c(param_4,&local_38,param_5);
    }
  }
  if (((*(char *)(local_30 + 1) == ',') || (*(char *)(local_30 + 1) == '.')) ||
     (uVar1 = local_1c, *(char *)(local_30 + 1) == '?')) {
    local_38 = 0x3b;
    local_37 = FUN_0010cd0a(param_1,(int)*local_28);
    uVar1 = local_1c;
    if (local_37 != '\0') {
      local_1c = FUN_0010925c(param_4,&local_38,param_5);
      uVar1 = local_1c;
    }
  }
LAB_0010cbd3:
  FUN_0010755e(&local_31);
  return uVar1;
}


//===== FUN_0010cbea @ 0010cbea size=288 =====

undefined8 FUN_0010cbea(undefined8 param_1,char param_2)

{
  undefined8 uVar1;
  
  if (((((param_2 == 'k') || (param_2 == 't')) || (param_2 == 'p')) ||
      ((param_2 == 'c' || (param_2 == 'K')))) ||
     ((param_2 == 'T' || ((param_2 == 'P' || (param_2 == 'L')))))) {
    uVar1 = 0x6b;
  }
  else if ((param_2 == 's') || ((param_2 == 'S' || (param_2 == 'f')))) {
    uVar1 = 0x73;
  }
  else if ((param_2 == 'n') || (((param_2 == 'm' || (param_2 == 'N')) || (param_2 == 'M')))) {
    uVar1 = 0x6e;
  }
  else if ((param_2 == 'h') || (param_2 == 'H')) {
    uVar1 = 0x68;
  }
  else if ((param_2 == 'r') || (param_2 == 'R')) {
    uVar1 = 0x72;
  }
  else if (((param_2 == 'g') || (param_2 == 'd')) || ((param_2 == 'G' || (param_2 == 'D')))) {
    uVar1 = 0x67;
  }
  else if ((param_2 == 'b') || (param_2 == 'B')) {
    uVar1 = 0x62;
  }
  else if ((param_2 == 'z') || (param_2 == 'j')) {
    uVar1 = 0x7a;
  }
  else if ((param_2 == 'v') || (param_2 == 'V')) {
    uVar1 = 0x76;
  }
  else if ((param_2 == 'w') || (param_2 == 'y')) {
    uVar1 = 0x77;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


//===== FUN_0010cd0a @ 0010cd0a size=258 =====

undefined8 FUN_0010cd0a(undefined8 param_1,char param_2)

{
  undefined8 uVar1;
  
  if ((((((param_2 == 'k') || (param_2 == 't')) || (param_2 == 'p')) ||
       ((param_2 == 'c' || (param_2 == 'K')))) || (param_2 == 'T')) ||
     ((((param_2 == 'P' || (param_2 == 'L')) ||
       ((param_2 == 'g' || (((param_2 == 'd' || (param_2 == 'G')) || (param_2 == 'D')))))) ||
      ((param_2 == 'b' || (param_2 == 'B')))))) {
    uVar1 = 0x6b;
  }
  else if ((param_2 == 's') ||
          (((param_2 == 'h' || (param_2 == 'H')) || ((param_2 == 'S' || (param_2 == 'f')))))) {
    uVar1 = 0x73;
  }
  else if ((((param_2 == 'n') || (param_2 == 'm')) || (param_2 == 'N')) || (param_2 == 'M')) {
    uVar1 = 0x6e;
  }
  else if ((param_2 == 'r') || (param_2 == 'R')) {
    uVar1 = 0x72;
  }
  else if ((param_2 == 'z') || (param_2 == 'j')) {
    uVar1 = 0x7a;
  }
  else if ((param_2 == 'v') || (param_2 == 'V')) {
    uVar1 = 0x76;
  }
  else if ((param_2 == 'w') || (param_2 == 'y')) {
    uVar1 = 0x79;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


//===== FUN_0010ce0c @ 0010ce0c size=10 =====

void FUN_0010ce0c(void)

{
  return;
}


//===== FUN_0010ce16 @ 0010ce16 size=10 =====

void FUN_0010ce16(void)

{
  return;
}


//===== FUN_0010ce20 @ 0010ce20 size=1066 =====

undefined8
FUN_0010ce20(undefined8 param_1,undefined8 param_2,byte param_3,short param_4,short param_5)

{
  bool bVar1;
  byte bVar2;
  undefined2 uVar3;
  short sVar4;
  int iVar5;
  undefined1 local_4d;
  int local_4c;
  long local_48;
  long local_40;
  long local_38;
  byte local_2e;
  byte local_2d;
  int local_2c;
  long local_28;
  int local_1c;
  
  FUN_00107554(&local_4d);
  local_4c = 0x400;
  local_48 = 0;
  FUN_00109684(param_2);
  while (local_38 = FUN_0010969a(param_2), local_38 != 0) {
    if (((local_48 == 0) || (*(short *)(local_48 + 4) != 0)) || (*(short *)(local_38 + 4) != 1)) {
      bVar2 = param_3;
      if (local_48 != 0) {
        bVar2 = FUN_001096ec(param_2,local_48);
      }
      local_2e = bVar2;
      local_2d = FUN_001096ec(param_2,local_38);
      local_2c = (int)*(short *)(&DAT_001555a0 +
                                ((long)(int)(local_2e - 3) * 7 + (long)(int)(local_2d - 3)) * 2);
      if ((local_48 != 0) && (*(short *)(local_48 + 4) == 0)) {
        if (*(char *)(local_48 + 1) == '\x04') {
          if (local_2c < (local_4c * 8) / 10) {
            local_2c = (local_4c * 8) / 10;
          }
        }
        else if (*(char *)(local_48 + 1) == '\x03') {
          iVar5 = local_4c * 5;
          if (iVar5 < 0) {
            iVar5 = iVar5 + 7;
          }
          if (local_2c < iVar5 >> 3) {
            local_2c = local_4c * 5;
            if (local_2c < 0) {
              local_2c = local_2c + 7;
            }
            local_2c = local_2c >> 3;
          }
        }
        else if (local_2c < local_4c) {
          local_2c = local_4c;
        }
      }
      local_4c = local_2c;
      iVar5 = *(short *)(local_38 + 6) * local_2c;
      if (iVar5 < 0) {
        iVar5 = iVar5 + 0x3ff;
      }
      *(short *)(local_38 + 6) = (short)(iVar5 >> 10);
    }
    else if (*(char *)(local_48 + 1) == '\x05') {
      iVar5 = *(short *)(local_38 + 6) * local_4c * 9;
      if (iVar5 < 0) {
        iVar5 = iVar5 + 0x1fff;
      }
      *(short *)(local_38 + 6) = (short)(iVar5 >> 0xd);
    }
    else if (*(char *)(local_48 + 1) == '\x03') {
      iVar5 = *(short *)(local_38 + 6) * local_4c * 6;
      if (iVar5 < 0) {
        iVar5 = iVar5 + 0x1fff;
      }
      *(short *)(local_38 + 6) = (short)(iVar5 >> 0xd);
    }
    else {
      iVar5 = *(short *)(local_38 + 6) * local_4c;
      if (iVar5 < 0) {
        iVar5 = iVar5 + 0x3ff;
      }
      *(short *)(local_38 + 6) = (short)(iVar5 >> 10);
    }
    local_48 = local_38;
  }
  FUN_00109684(param_2);
  local_40 = FUN_0010969a(param_2);
  while (local_40 != 0) {
    local_28 = FUN_0010969a(param_2);
    for (local_1c = 0; iVar5 = local_1c, local_1c < (int)(uint)*(ushort *)(local_40 + 2);
        local_1c = local_1c + 1) {
      if (*(short *)(local_40 + 8 + (long)local_1c * 4) == 0) {
        if (local_28 == 0) {
          uVar3 = 0;
        }
        else {
          uVar3 = *(undefined2 *)(local_28 + 4);
        }
        sVar4 = FUN_0010d35c(param_1,local_1c,local_40,uVar3);
        *(short *)(local_40 + 8 + (long)iVar5 * 4) =
             (short)((uint)((int)param_4 * (int)sVar4) >> 8) + param_5;
      }
    }
    iVar5 = FUN_00107732(&local_4d,*(undefined1 *)(local_40 + 1));
    if (((iVar5 == 0) && (local_28 != 0)) && (*(short *)(local_28 + 4) != 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (*(short *)(local_28 + 8) == 0)) {
      sVar4 = FUN_0010d35c(param_1,*(undefined2 *)(local_40 + 2),local_40,
                           *(undefined2 *)(local_28 + 4));
      *(short *)(local_28 + 8) = (short)((uint)((int)param_4 * (int)sVar4) >> 8) + param_5;
    }
    local_40 = local_28;
  }
  FUN_0010755e(&local_4d);
  return 0;
}


//===== FUN_0010d26a @ 0010d26a size=241 =====

uint FUN_0010d26a(undefined8 param_1,int param_2,int param_3,int param_4)

{
  int local_2c;
  int local_28;
  int local_24;
  uint local_c;
  
  local_24 = param_2;
  if (param_2 < 1) {
    local_24 = 1;
  }
  if (6 < local_24) {
    local_24 = 6;
  }
  local_28 = param_3;
  if (param_3 < 0) {
    local_28 = 0;
  }
  if (5 < local_28) {
    local_28 = 5;
  }
  if (local_24 == local_28) {
    local_28 = 0;
  }
  local_2c = param_4;
  if (param_4 < 0) {
    local_2c = 0;
  }
  if (2 < local_2c) {
    local_2c = 2;
  }
  local_c = 0;
  while( true ) {
    if (0x3b < local_c) {
      return 0xffffffff;
    }
    if (((*(short *)(&DAT_00154a62 + (long)(int)local_c * 8) == local_24) &&
        (*(short *)(&DAT_00154a64 + (long)(int)local_c * 8) == local_28)) &&
       (*(short *)(&DAT_00154a66 + (long)(int)local_c * 8) == local_2c)) break;
    local_c = local_c + 1;
  }
  return local_c;
}


//===== FUN_0010d35c @ 0010d35c size=563 =====

ulong FUN_0010d35c(undefined8 param_1,int param_2,long param_3,undefined4 param_4)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  ulong uVar5;
  undefined4 local_64;
  undefined1 local_48;
  undefined1 local_47;
  short local_46;
  undefined2 local_44;
  undefined2 local_42;
  undefined1 local_38;
  undefined1 local_37;
  short local_36;
  undefined2 local_34;
  undefined2 local_32;
  undefined4 local_24;
  undefined4 local_20;
  
  if (*(ushort *)(param_3 + 2) < 2) {
    if (*(short *)(param_3 + 4) == 0) {
      return 0;
    }
    iVar4 = *(short *)(param_3 + 6) * 0x1400;
    if (*(short *)(param_3 + 6) * 0x1400 < 0) {
      iVar4 = iVar4 + 0x3ff;
    }
    return (ulong)(uint)(iVar4 >> 10);
  }
  if ((6 < *(ushort *)(param_3 + 2)) && (3 < *(ushort *)(param_3 + 4))) {
    if (param_2 < (int)(uint)*(ushort *)(param_3 + 4)) {
      local_34 = 0;
      local_37 = 3;
      local_32 = *(undefined2 *)(param_3 + 6);
      local_36 = *(short *)(param_3 + 4) + -1;
      uVar5 = FUN_0010d35c(param_1,param_2,&local_38,1);
      return uVar5;
    }
    local_44 = 1;
    local_47 = *(undefined1 *)(param_3 + 1);
    local_42 = *(undefined2 *)(param_3 + 6);
    local_46 = (*(short *)(param_3 + 2) - *(short *)(param_3 + 4)) + 1;
    uVar5 = FUN_0010d35c(param_1,(1 - (uint)*(ushort *)(param_3 + 4)) + param_2,&local_48,param_4);
    return uVar5;
  }
  bVar1 = *(byte *)(param_3 + 1);
  if (bVar1 == 8) {
    local_24 = 1;
    local_64 = 1;
  }
  else {
    if (bVar1 < 9) {
      if (5 < bVar1) {
        local_24 = 1;
        local_64 = 0;
        goto LAB_0010d504;
      }
    }
    else if (bVar1 == 9) {
      local_24 = 1;
      local_64 = 2;
      goto LAB_0010d504;
    }
    local_24 = 0;
    local_64 = param_4;
  }
LAB_0010d504:
  local_20 = FUN_0010d26a(param_1,*(undefined2 *)(param_3 + 2),*(undefined2 *)(param_3 + 4),local_64
                         );
  sVar2 = *(short *)(param_3 + 6);
  sVar3 = FUN_0010d590(param_1,local_24,local_20,param_2,*(undefined2 *)(param_3 + 2),
                       *(undefined2 *)(param_3 + 4));
  iVar4 = (int)sVar3 * (int)sVar2;
  if (iVar4 < 0) {
    iVar4 = iVar4 + 0x3ff;
  }
  return (ulong)(uint)(iVar4 >> 10);
}


//===== FUN_0010d590 @ 0010d590 size=1152 =====

uint FUN_0010d590(undefined8 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  uint uVar2;
  
  if (param_5 < 7) {
    uVar2 = (uint)*(ushort *)
                   (&DAT_00154c44 + ((long)param_2 * 600 + (long)param_3 * 10 + (long)param_4) * 2);
  }
  else {
    iVar1 = (int)*(short *)(&DAT_00154c42 + (long)param_3 * 0x14 + (long)param_2 * 0x4b0);
    if (param_6 < 6) {
      if (iVar1 < param_4) {
        if (iVar1 + param_5 + -6 < param_4) {
          uVar2 = (uint)*(ushort *)
                         (&DAT_00154c44 +
                         ((long)param_2 * 600 + (long)param_3 * 10 + (long)((6 - param_5) + param_4)
                         ) * 2);
        }
        else {
          uVar2 = (((int)*(short *)(&DAT_00154c44 +
                                   ((long)param_2 * 600 + (long)param_3 * 10 + (long)(iVar1 + 1)) *
                                   2) -
                   (int)(short)*(ushort *)
                                (&DAT_00154c44 +
                                ((long)param_2 * 600 + (long)param_3 * 10 + (long)iVar1) * 2)) *
                  (param_4 - iVar1)) / (int)(short)((short)param_5 + -5) +
                  (uint)*(ushort *)
                         (&DAT_00154c44 +
                         ((long)param_2 * 600 + (long)param_3 * 10 + (long)iVar1) * 2);
        }
      }
      else {
        uVar2 = (uint)*(ushort *)
                       (&DAT_00154c44 +
                       ((long)param_2 * 600 + (long)param_3 * 10 + (long)param_4) * 2);
      }
    }
    else if (param_4 < 4) {
      uVar2 = (uint)*(ushort *)
                     (&DAT_00154c44 + ((long)param_2 * 600 + (long)param_3 * 10 + (long)param_4) * 2
                     );
    }
    else if (param_4 < param_6 + -1) {
      uVar2 = (((int)*(short *)(&DAT_00154c4c + (long)param_3 * 0x14 + (long)param_2 * 0x4b0) -
               (int)(short)*(ushort *)(&DAT_00154c4a + (long)param_3 * 0x14 + (long)param_2 * 0x4b0)
               ) * (param_4 + -3)) / (int)(short)((short)param_6 + -4) +
              (uint)*(ushort *)(&DAT_00154c4a + (long)param_3 * 0x14 + (long)param_2 * 0x4b0);
    }
    else if (param_6 + -1 == param_4) {
      uVar2 = (uint)*(ushort *)(&DAT_00154c4c + (long)param_3 * 0x14 + (long)param_2 * 0x4b0);
    }
    else if (param_4 + 1 < param_5) {
      uVar2 = (((int)*(short *)(&DAT_00154c4e + (long)param_3 * 0x14 + (long)param_2 * 0x4b0) -
               (int)(short)*(ushort *)(&DAT_00154c4c + (long)param_3 * 0x14 + (long)param_2 * 0x4b0)
               ) * (param_4 - param_6)) / (int)(short)((short)param_5 - (short)param_6) +
              (uint)*(ushort *)(&DAT_00154c4c + (long)param_3 * 0x14 + (long)param_2 * 0x4b0);
    }
    else {
      uVar2 = (uint)*(ushort *)
                     (&DAT_00154c44 +
                     ((long)param_2 * 600 + (long)param_3 * 10 + (long)((param_4 - param_5) + 6)) *
                     2);
    }
  }
  return uVar2;
}


//===== FUN_0010da10 @ 0010da10 size=10 =====

void FUN_0010da10(void)

{
  return;
}


//===== FUN_0010da1a @ 0010da1a size=10 =====

void FUN_0010da1a(void)

{
  return;
}


//===== FUN_0010da24 @ 0010da24 size=117 =====

void FUN_0010da24(undefined8 *param_1,int param_2)

{
  if (param_2 == 1) {
    *param_1 = &DAT_00155e20;
    *(undefined2 *)(param_1 + 1) = 0x400;
  }
  else if (param_2 == 2) {
    *param_1 = &DAT_00156620;
    *(undefined2 *)(param_1 + 1) = 0x400;
  }
  else {
    *param_1 = &DAT_00155620;
    *(undefined2 *)(param_1 + 1) = 0x400;
  }
  FUN_0010da9a(param_1);
  return;
}


//===== FUN_0010da9a @ 0010da9a size=81 =====

void FUN_0010da9a(long param_1)

{
  undefined4 local_c;
  
  *(undefined2 *)(param_1 + 0xe) = 0;
  *(undefined2 *)(param_1 + 0x10) = 0;
  for (local_c = 0; local_c < 4; local_c = local_c + 1) {
    *(undefined2 *)(param_1 + 2 + ((long)local_c + 8) * 2) = *(undefined2 *)(param_1 + 8);
  }
  return;
}


//===== FUN_0010daec @ 0010daec size=46 =====

void FUN_0010daec(long param_1,undefined2 param_2,undefined2 param_3)

{
  *(undefined2 *)(param_1 + 10) = param_2;
  *(undefined2 *)(param_1 + 0xc) = param_3;
  return;
}


//===== FUN_0010db1a @ 0010db1a size=394 =====

int FUN_0010db1a(long *param_1)

{
  int iVar1;
  int local_10;
  int local_c;
  
  local_10 = 0;
  for (local_c = 0; local_c < 4; local_c = local_c + 1) {
    if (*(ushort *)((long)param_1 + ((long)local_c + 8) * 2 + 2) < *(ushort *)(param_1 + 1)) {
      iVar1 = (uint)*(ushort *)((long)param_1 + ((long)local_c + 8) * 2 + 10) *
              (int)*(short *)(*param_1 +
                             (ulong)*(ushort *)((long)param_1 + ((long)local_c + 8) * 2 + 2) * 2);
      if (iVar1 < 0) {
        iVar1 = iVar1 + 0x7f;
      }
      local_10 = local_10 + (iVar1 >> 7);
      *(short *)((long)param_1 + ((long)local_c + 8) * 2 + 2) =
           *(short *)((long)param_1 + ((long)local_c + 8) * 2 + 2) + 4;
    }
  }
  *(short *)((long)param_1 + 0xe) = *(short *)((long)param_1 + 0xe) + 4;
  if (*(ushort *)((long)param_1 + 0xc) <= *(ushort *)((long)param_1 + 0xe)) {
    *(short *)((long)param_1 + 0xe) =
         *(short *)((long)param_1 + 0xe) - *(short *)((long)param_1 + 0xc);
    *(undefined2 *)((long)param_1 + ((long)(int)(uint)*(ushort *)(param_1 + 2) + 8) * 2 + 10) =
         *(undefined2 *)((long)param_1 + 10);
    *(undefined2 *)((long)param_1 + ((long)(int)(uint)*(ushort *)(param_1 + 2) + 8) * 2 + 2) =
         *(undefined2 *)((long)param_1 + 0xe);
    *(short *)(param_1 + 2) = (short)param_1[2] + 1;
    if (3 < *(ushort *)(param_1 + 2)) {
      *(undefined2 *)(param_1 + 2) = 0;
    }
  }
  return local_10;
}


//===== FUN_0010dca4 @ 0010dca4 size=10 =====

void FUN_0010dca4(void)

{
  return;
}


//===== FUN_0010dcae @ 0010dcae size=10 =====

void FUN_0010dcae(void)

{
  return;
}


//===== FUN_0010dcb8 @ 0010dcb8 size=271 =====

int FUN_0010dcb8(undefined8 param_1,byte *param_2,undefined8 param_3)

{
  bool bVar1;
  int iVar2;
  int local_2c;
  undefined4 local_28;
  char local_21;
  byte *local_20;
  
  local_21 = '\b';
  local_2c = 0;
  local_20 = param_2;
  while( true ) {
    if ((*local_20 == 0) || (*local_20 < 0x20)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00108024(param_3);
      FUN_001080e4(param_3);
      FUN_00108306(param_3);
      return 0;
    }
    if (*local_20 == 0x3c) {
      iVar2 = FUN_0010ddc8(param_1,local_20,&local_2c,param_3);
    }
    else {
      local_21 = FUN_00107568(param_3,local_20,&local_2c);
      if (local_21 == '\0') {
        return 0x69;
      }
      iVar2 = FUN_00107af2(param_3,local_21);
    }
    if (iVar2 != 0) break;
    local_20 = local_20 + local_2c;
    local_28 = 0;
  }
  return iVar2;
}


//===== FUN_0010ddc8 @ 0010ddc8 size=978 =====

undefined4 FUN_0010ddc8(undefined8 param_1,long param_2,int *param_3,undefined8 param_4)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  long local_c8 [4];
  long local_a8 [4];
  undefined1 local_88 [16];
  undefined1 local_78 [16];
  undefined1 local_68 [12];
  undefined4 local_5c;
  int local_58;
  uint local_54;
  long local_50;
  int local_44;
  long local_40;
  long local_38;
  undefined8 local_30;
  undefined8 local_28;
  long local_20;
  
  local_54 = 0;
  local_58 = 1;
  while( true ) {
    if (*(char *)(local_58 + param_2) == '\"') {
      local_54 = (uint)(local_54 == 0);
    }
    if ((*(char *)(local_58 + param_2) == '>') && (local_54 == 0)) break;
    if (*(char *)(local_58 + param_2) == '\0') {
      return 0x6b;
    }
    local_58 = local_58 + 1;
  }
  *(undefined1 *)(local_58 + param_2) = 0;
  *param_3 = local_58 + 1;
  local_50 = FUN_00106a36(param_2 + 1," =>\t\n",local_68);
  if (local_50 == 0) {
    return 0x6a;
  }
  for (local_44 = 0; iVar1 = local_44, local_44 < 4; local_44 = local_44 + 1) {
    lVar3 = FUN_00106a36(0," =>\t\n",local_68);
    local_a8[iVar1] = lVar3;
    iVar1 = local_44;
    if ((local_a8[local_44] == 0) || (*(char *)local_a8[local_44] == '\0')) break;
    lVar3 = FUN_0010e1d8(param_1,0," =>\t\n",local_68);
    local_c8[iVar1] = lVar3;
    if (local_c8[local_44] == 0) {
      return 0x6a;
    }
  }
  iVar1 = FUN_00106687(local_50,&DAT_00156e32);
  if (iVar1 == 0) {
    local_40 = FUN_0010e29a(param_1,&DAT_00156e36,local_a8,local_c8,local_44);
    if (local_40 == 0) {
      return 0x6a;
    }
    FUN_0010e3bc(local_78);
    uVar2 = FUN_0010e3d0(local_78,local_40,param_4);
    local_5c = uVar2;
    FUN_0010e3c6(local_78);
    return uVar2;
  }
  iVar1 = FUN_00106687(local_50,&DAT_00156e2d);
  if (iVar1 == 0) {
    local_38 = FUN_0010e29a(param_1,&DAT_00156e36,local_a8,local_c8,local_44);
    local_30 = FUN_0010e29a(param_1,"COUNTER",local_a8,local_c8,local_44);
    local_28 = FUN_0010e29a(param_1,&DAT_00156e28,local_a8,local_c8,local_44);
    if (local_38 == 0) {
      return 0x6a;
    }
    FUN_0010e3bc(local_88);
    uVar2 = FUN_0010e510(local_88,local_38,local_30,local_28,param_4);
    FUN_0010e3c6(local_88);
    return uVar2;
  }
  iVar1 = FUN_00106687(local_50,"ALPHA");
  if (iVar1 != 0) {
    return 0x6a;
  }
  local_20 = FUN_0010e29a(param_1,&DAT_00156e36,local_a8,local_c8,local_44);
  if (local_20 == 0) {
    return 0x6a;
  }
  uVar2 = FUN_00105e80(local_20,param_4);
  return uVar2;
}


//===== FUN_0010e1d8 @ 0010e1d8 size=194 =====

char * FUN_0010e1d8(undefined8 param_1,long param_2,undefined8 param_3,long *param_4)

{
  uint uVar1;
  char *local_28;
  undefined1 *local_10;
  
  local_28 = (char *)param_2;
  if (param_2 == 0) {
    local_28 = (char *)*param_4;
  }
  if (local_28 == (char *)0x0) {
    local_28 = (char *)0x0;
  }
  else {
    uVar1 = FUN_0010694e(local_28,param_3);
    local_28 = (char *)((long)local_28 + (ulong)uVar1);
    if (*local_28 == '\"') {
      local_28 = local_28 + 1;
      local_10 = (undefined1 *)FUN_00106863(local_28,0x22);
    }
    else {
      local_10 = (undefined1 *)FUN_001069cd(local_28,param_3);
    }
    if (local_10 == (undefined1 *)0x0) {
      *param_4 = 0;
    }
    else {
      *param_4 = (long)(local_10 + 1);
      *local_10 = 0;
    }
  }
  return local_28;
}


//===== FUN_0010e29a @ 0010e29a size=123 =====

undefined8 FUN_0010e29a(undefined8 param_1,undefined8 param_2,long param_3,long param_4,int param_5)

{
  int iVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (param_5 <= local_c) {
      return 0;
    }
    iVar1 = FUN_0010e316(param_1,param_2,*(undefined8 *)((long)local_c * 8 + param_3));
    if (iVar1 == 0) break;
    local_c = local_c + 1;
  }
  return *(undefined8 *)((long)local_c * 8 + param_4);
}


//===== FUN_0010e316 @ 0010e316 size=165 =====

int FUN_0010e316(undefined8 param_1,char *param_2,char *param_3)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  char *local_30;
  char *local_28;
  
  local_30 = param_3;
  local_28 = param_2;
  do {
    if ((*local_28 < '[') && ('@' < *local_28)) {
      cVar2 = *local_28 + ' ';
    }
    else {
      cVar2 = *local_28;
    }
    if ((*local_30 < '[') && ('@' < *local_30)) {
      cVar3 = *local_30 + ' ';
    }
    else {
      cVar3 = *local_30;
    }
    local_28 = local_28 + 1;
    local_30 = local_30 + 1;
    if ((cVar2 == '\0') || (cVar2 != cVar3)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
  } while (bVar1);
  return (int)cVar2 - (int)cVar3;
}


//===== FUN_0010e3bc @ 0010e3bc size=10 =====

void FUN_0010e3bc(void)

{
  return;
}


//===== FUN_0010e3c6 @ 0010e3c6 size=10 =====

void FUN_0010e3c6(void)

{
  return;
}


//===== FUN_0010e3d0 @ 0010e3d0 size=319 =====

ulong FUN_0010e3d0(undefined8 *param_1,char *param_2,undefined8 param_3)

{
  uint uVar1;
  ulong uVar2;
  char *local_28;
  char *local_10;
  
  if (param_2 == (char *)0x0) {
    uVar2 = 100;
  }
  else if (*param_2 == '\0') {
    uVar2 = 0;
  }
  else {
    *param_1 = param_3;
    local_28 = param_2;
    for (local_10 = param_2; *local_10 != '\0'; local_10 = local_10 + 1) {
      if (*local_10 == '.') {
        *local_10 = '\0';
        uVar1 = FUN_0010e934(param_1,local_28);
        if (uVar1 != 0) {
          return (ulong)uVar1;
        }
        uVar1 = FUN_00107b42(param_3,&DAT_00156f60);
        if (uVar1 != 0) {
          return (ulong)uVar1;
        }
        local_28 = local_10 + 1;
      }
      else if (*local_10 == '-') {
        *local_10 = '\0';
        uVar1 = FUN_0010e934(param_1,local_28);
        if (uVar1 != 0) {
          return (ulong)uVar1;
        }
        uVar1 = FUN_00107af2(param_3,7);
        if (uVar1 != 0) {
          return (ulong)uVar1;
        }
        local_28 = local_10 + 1;
      }
    }
    uVar2 = FUN_0010e934(param_1,local_28);
  }
  return uVar2;
}


//===== FUN_0010e510 @ 0010e510 size=420 =====

ulong FUN_0010e510(undefined8 *param_1,char *param_2,char *param_3,undefined8 param_4,
                  undefined8 param_5)

{
  uint uVar1;
  ulong uVar2;
  undefined1 local_38 [20];
  uint local_24;
  undefined1 *local_20;
  
  if (param_2 == (char *)0x0) {
    uVar2 = 100;
  }
  else if (*param_2 == '\0') {
    uVar2 = 0;
  }
  else {
    *param_1 = param_5;
    local_20 = (undefined1 *)FUN_00106863(param_2,0x2e);
    if (local_20 == (undefined1 *)0x0) {
      uVar2 = FUN_0010e6b4(param_1,param_2,param_3,param_4,param_5);
    }
    else {
      *local_20 = 0;
      FUN_001067b6(local_38,&DAT_00156e60);
      if (*param_2 == '\0') {
        local_24 = FUN_0010edae(param_1,&DAT_00156e6b,0,local_38,&DAT_00156e67,0);
      }
      else {
        local_24 = FUN_0010e6b4(param_1,param_2,local_38,&DAT_00156e67,param_5);
      }
      if (local_24 == 0) {
        local_24 = FUN_00107af2(param_5,5);
        if (local_24 == 0) {
          local_24 = FUN_0010e3d0(param_1,local_20 + 1,param_5);
          if (local_24 == 0) {
            if (((param_3 != (char *)0x0) && (*param_3 != '\0')) &&
               (uVar1 = FUN_00107bac(param_5,param_3), uVar1 != 0)) {
              return (ulong)uVar1;
            }
            uVar2 = 0;
          }
          else {
            uVar2 = (ulong)local_24;
          }
        }
        else {
          uVar2 = (ulong)local_24;
        }
      }
      else {
        uVar2 = (ulong)local_24;
      }
    }
  }
  return uVar2;
}


//===== FUN_0010e6b4 @ 0010e6b4 size=640 =====

ulong FUN_0010e6b4(undefined8 *param_1,char *param_2,undefined8 param_3,long param_4,
                  undefined8 param_5)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  char local_38 [4];
  undefined1 local_34;
  uint local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  if (param_2 == (char *)0x0) {
    uVar3 = 100;
  }
  else if (*param_2 == '\0') {
    uVar3 = 0;
  }
  else {
    *param_1 = param_5;
    if (param_4 == 0) {
      iVar1 = FUN_0010fe9a(param_1,param_2,param_3,&local_2c);
      if (iVar1 != 0) {
        return (ulong)local_2c;
      }
      if (local_2c != 0) {
        return (ulong)local_2c;
      }
    }
    local_24 = FUN_00106658(param_2);
    if ((local_24 == 1) && (*param_2 == '0')) {
      uVar2 = FUN_0010edae(param_1,&DAT_00156e6b,0,param_3,param_4,0);
      uVar3 = (ulong)uVar2;
    }
    else {
      local_20 = 0;
      local_28 = local_24;
      do {
        local_28 = local_28 + -1;
        if (local_28 < 0) goto LAB_0010e7e1;
      } while (param_2[local_28] == '0');
      local_20 = (local_24 - local_28) + -1;
LAB_0010e7e1:
      for (local_1c = 0xc; -1 < local_1c; local_1c = local_1c + -4) {
        if (local_1c < local_24) {
          local_34 = 0;
          for (local_28 = 0; local_28 < 4; local_28 = local_28 + 1) {
            if ((local_24 - local_1c) + -4 + local_28 < 0) {
              local_38[local_28] = '0';
            }
            else {
              local_38[local_28] = param_2[(local_24 - local_1c) + -4 + local_28];
            }
            if ((local_38[local_28] < '0') || ('9' < local_38[local_28])) {
              return 0x6c;
            }
          }
          if ((local_1c <= local_20) && (local_20 < local_1c + 4)) {
            uVar3 = FUN_0010f150(param_1,local_38,local_1c,param_3,param_4,1);
            return uVar3;
          }
          local_2c = FUN_0010f150(param_1,local_38,local_1c,0,0,0);
          if (local_2c != 0) {
            return (ulong)local_2c;
          }
          local_2c = FUN_00107af2(param_5,7);
          if (local_2c != 0) {
            return (ulong)local_2c;
          }
        }
      }
      uVar3 = 0;
    }
  }
  return uVar3;
}


//===== FUN_0010e934 @ 0010e934 size=468 =====

int FUN_0010e934(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  long local_38;
  int local_24;
  int local_20;
  int local_1c;
  
  local_1c = FUN_00106658(param_2);
  for (local_20 = 0; local_20 < local_1c; local_20 = local_20 + 1) {
    if ((*(char *)(local_20 + param_2) < '0') || ('9' < *(char *)(local_20 + param_2))) {
      return 0x6c;
    }
  }
  local_20 = 0;
  local_38 = param_2;
  while( true ) {
    if (0x13 < local_20) {
      return 100;
    }
    local_1c = FUN_00106658(local_38);
    if (local_1c < 4) {
      FUN_0010eb08(param_1,local_1c,local_38,0,&local_24);
      return local_24;
    }
    if (local_1c == 4) {
      uVar1 = FUN_0010eb08(param_1,2,local_38,4,&local_24);
      FUN_0010eb08(param_1,2,uVar1,0,&local_24);
      return local_24;
    }
    if (local_1c == 5) break;
    uVar1 = FUN_0010eb08(param_1,2,local_38,4,&local_24);
    if (local_24 != 0) {
      return local_24;
    }
    local_38 = FUN_0010eb08(param_1,2,uVar1,7,&local_24);
    if (local_24 != 0) {
      return local_24;
    }
    local_20 = local_20 + 1;
  }
  uVar1 = FUN_0010eb08(param_1,2,local_38,4,&local_24);
  FUN_0010eb08(param_1,3,uVar1,0,&local_24);
  return local_24;
}


//===== FUN_0010eb08 @ 0010eb08 size=677 =====

char * FUN_0010eb08(undefined8 *param_1,int param_2,char *param_3,char param_4,int *param_5)

{
  int iVar1;
  
  *param_5 = 0;
  if (param_2 == 0) {
    return param_3;
  }
  if (param_2 == 1) {
    iVar1 = FUN_00107b42(*param_1,&DAT_00156fc0 + (long)(*param_3 + -0x30) * 4);
    *param_5 = iVar1;
    if (*param_5 != 0) {
      return param_3;
    }
    param_3 = param_3 + 1;
  }
  else if (param_2 == 2) {
    iVar1 = FUN_00107b42(*param_1,&DAT_00156ff0 + (long)(*param_3 + -0x30) * 3);
    *param_5 = iVar1;
    if (*param_5 != 0) {
      return param_3;
    }
    iVar1 = FUN_00107b42(*param_1,&DAT_00157020 + (long)(param_3[1] + -0x30) * 4);
    *param_5 = iVar1;
    if (*param_5 != 0) {
      return param_3;
    }
    param_3 = param_3 + 2;
  }
  else {
    iVar1 = FUN_00107b42(*param_1,&DAT_00156ff0 + (long)(*param_3 + -0x30) * 3);
    *param_5 = iVar1;
    if (*param_5 != 0) {
      return param_3;
    }
    iVar1 = FUN_00107b42(*param_1,&DAT_00157020 + (long)(param_3[1] + -0x30) * 4);
    *param_5 = iVar1;
    if (*param_5 != 0) {
      return param_3;
    }
    iVar1 = FUN_00107b42(*param_1,&DAT_00156ff0 + (long)(param_3[2] + -0x30) * 3);
    *param_5 = iVar1;
    if (*param_5 != 0) {
      return param_3;
    }
    param_3 = param_3 + 3;
  }
  if (param_4 != '\0') {
    iVar1 = FUN_00107af2(*param_1,param_4);
    *param_5 = iVar1;
  }
  return param_3;
}


//===== FUN_0010edae @ 0010edae size=871 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong FUN_0010edae(undefined8 param_1,long param_2,int param_3,long param_4,undefined8 param_5,
                  int param_6)

{
  uint uVar1;
  ulong uVar2;
  undefined8 in_stack_ffffffffffffff58;
  long lVar3;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  uint local_44;
  uint local_40;
  undefined1 local_39;
  undefined *local_38;
  undefined *local_30;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 uVar4;
  
  uVar4 = (undefined4)((ulong)in_stack_ffffffffffffff58 >> 0x20);
  local_39 = 0;
  local_30 = (undefined *)0x0;
  local_24 = param_3 % 4;
  local_20 = *(char *)((3 - local_24) + param_2) + -0x30;
  local_1c = FUN_0010f116(param_1,param_3,local_20);
  local_38 = &DAT_00157060 + ((long)local_20 + (long)local_24 * 10) * 0x10;
  local_40 = *(uint *)(&DAT_0015706c + ((long)local_24 * 10 + (long)local_20) * 0x10);
  if ((((param_6 == 0) || (local_1c < 0xd)) || (local_24 != 3)) || (local_20 != 1)) {
    if (local_1c == 0xf) {
      if (local_24 == 0) {
        if ((&PTR_DAT_0035c5e0)[(long)local_20 + 0x30] == (undefined *)0x0) {
          local_38 = (&PTR_DAT_0035c5e0)[local_20];
        }
        else {
          local_38 = (&PTR_DAT_0035c5e0)[(long)local_20 + 0x30];
        }
      }
      else if (local_24 == 1) {
        local_38 = &DAT_001572e0 + (long)local_20 * 9;
      }
    }
  }
  else {
    local_38 = &UNK_00157240;
    if (local_1c == 0xf) {
      local_40 = 0;
    }
    else {
      local_40 = _UNK_0015724c;
    }
  }
  if (local_1c == 0xd) {
    local_30 = &DAT_00156e70;
    uVar1 = FUN_00106658(local_38);
    local_40 = (uVar1 >> 1) + 1;
  }
  else if (local_1c == 0xe) {
    local_30 = &DAT_00156e75;
    local_40 = FUN_00106658(local_38);
    local_40 = local_40 >> 1;
  }
  else if (local_1c == 0xf) {
    local_30 = &DAT_00156e7a;
  }
  local_48 = 0;
  if (param_4 != 0) {
    local_44 = FUN_0010f372(param_1,param_4,&local_4c);
    if (local_44 != 0) {
      return (ulong)local_44;
    }
    local_44 = FUN_0010f716(param_1,param_4,local_4c,param_5,&local_50,&local_54,&local_58);
    if (local_44 != 0) {
      return (ulong)local_44;
    }
    local_38 = (undefined *)FUN_0010f90a(param_1,local_1c,local_50,local_38,&local_48);
    FUN_0010fa24(param_1,param_4,local_1c,local_54);
    lVar3 = param_4;
    local_40 = FUN_0010fbfc(param_1,param_2,local_24,local_1c,local_38,local_30,param_4,local_58,
                            local_4c);
    uVar4 = (undefined4)((ulong)lVar3 >> 0x20);
  }
  uVar2 = FUN_0010f490(param_1,local_38,local_30,param_4,local_39,local_40,CONCAT44(uVar4,local_48))
  ;
  return uVar2;
}


//===== FUN_0010f116 @ 0010f116 size=58 =====

int FUN_0010f116(undefined8 param_1,int param_2,int param_3)

{
  if (param_2 != 0) {
    if (param_2 < 4) {
      param_3 = param_2 + 9;
    }
    else {
      if (param_2 < 0) {
        param_2 = param_2 + 3;
      }
      param_3 = (param_2 >> 2) + 0xc;
    }
  }
  return param_3;
}


//===== FUN_0010f150 @ 0010f150 size=546 =====

int FUN_0010f150(undefined8 *param_1,long param_2,int param_3,long param_4,undefined8 param_5,
                undefined4 param_6)

{
  int iVar1;
  int local_24;
  int local_1c;
  
  local_1c = 4;
  for (local_24 = 3; -1 < local_24; local_24 = local_24 + -1) {
    if (*(char *)(local_24 + param_2) != '0') {
      local_1c = local_24;
      break;
    }
  }
  local_24 = 0;
  do {
    if (3 < local_24) {
LAB_0010f28a:
      if ((((param_3 == 0) && (param_4 == 0)) && (*(char *)(param_2 + 2) == '1')) &&
         (*(char *)(param_2 + 3) == '5')) {
        FUN_00107c32(*param_1,1);
        FUN_00107f1c(*param_1,1);
      }
      else if ((((*(char *)(param_2 + 2) == '1') || (*(char *)(param_2 + 2) == '5')) ||
               ((*(char *)(param_2 + 2) == '6' || (*(char *)(param_2 + 2) == '8')))) &&
              (*(char *)(param_2 + 3) != '0')) {
        if (*(char *)(param_2 + 2) == '1') {
          FUN_00107c32(*param_1,1);
        }
        else {
          FUN_00107c32(*param_1,0);
        }
      }
      return 0;
    }
    if (local_24 == local_1c) {
      iVar1 = FUN_0010edae(param_1,param_2,(param_3 + 3) - local_24,param_4,param_5,param_6);
      if (iVar1 != 0) {
        return iVar1;
      }
      goto LAB_0010f28a;
    }
    if (*(char *)(local_24 + param_2) != '0') {
      iVar1 = FUN_0010edae(param_1,param_2,3 - local_24,0,0,0);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_00107af2(*param_1,4);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
    local_24 = local_24 + 1;
  } while( true );
}


//===== FUN_0010f372 @ 0010f372 size=286 =====

undefined8 FUN_0010f372(undefined8 *param_1,char *param_2,int *param_3)

{
  char *pcVar1;
  int local_2c;
  char *local_28;
  char *local_20;
  int local_18;
  char local_11;
  char *local_10;
  
  local_18 = 0;
  *param_3 = 0;
  local_28 = param_2;
  local_20 = param_2;
  while( true ) {
    if (*local_28 == '\0') {
      *local_20 = '\0';
      return 0;
    }
    local_11 = FUN_00107568(*param_1,local_28,&local_2c);
    if (local_11 == '\0') break;
    if (local_11 == '\x01') {
      *param_3 = local_18;
      pcVar1 = local_20;
    }
    else {
      local_10 = (char *)FUN_001076da(*param_1,local_11);
      *local_20 = *local_10;
      local_20[1] = local_10[1];
      pcVar1 = local_20 + 2;
      if (*local_20 == 'g') {
        *local_20 = 'v';
      }
      else if (*local_20 == 'G') {
        *local_20 = 'V';
      }
    }
    local_20 = pcVar1;
    local_28 = local_28 + local_2c;
    local_18 = local_18 + 1;
  }
  return 0x6a;
}


//===== FUN_0010f490 @ 0010f490 size=358 =====

int FUN_0010f490(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                char param_5,undefined4 param_6,int param_7)

{
  char cVar1;
  undefined4 local_24;
  int local_20;
  int local_1c;
  
  local_24 = 0;
  local_20 = FUN_0010f5f6(param_1,param_2,param_6,&local_24);
  if (local_20 == 0) {
    if (param_7 != 0) {
      local_1c = FUN_00107fac(*param_1);
      local_1c = local_1c + -1;
      cVar1 = FUN_00107fe8(*param_1,local_1c);
      if (cVar1 == '\x01') {
        FUN_00107fc0(*param_1,local_1c + -1,1);
        FUN_00107fc0(*param_1,local_1c,0x97);
      }
      else {
        FUN_00107fc0(*param_1,local_1c,0x97);
      }
    }
    local_20 = FUN_0010f5f6(param_1,param_3,param_6,&local_24);
    if (((local_20 == 0) &&
        (local_20 = FUN_0010f5f6(param_1,param_4,param_6,&local_24), local_20 == 0)) &&
       ((param_5 == '\0' || (local_20 = FUN_00107af2(*param_1,param_5), local_20 == 0)))) {
      local_20 = 0;
    }
  }
  return local_20;
}


//===== FUN_0010f5f6 @ 0010f5f6 size=288 =====

int FUN_0010f5f6(undefined8 *param_1,char *param_2,int param_3,int *param_4)

{
  char cVar1;
  char *local_28;
  int local_10;
  
  local_28 = param_2;
  if (param_2 != (char *)0x0) {
    for (; *local_28 != '\0'; local_28 = local_28 + 2) {
      cVar1 = FUN_00107650(*param_1,local_28);
      if (cVar1 == '\0') {
        return 100;
      }
      *param_4 = *param_4 + 1;
      if (*param_4 == param_3) {
        if (((cVar1 == -0x68) || (cVar1 == -0x69)) || (cVar1 == -0x6a)) {
          FUN_00107af2(*param_1,1);
          local_10 = FUN_00107af2(*param_1,cVar1);
        }
        else {
          FUN_00107af2(*param_1,cVar1);
          local_10 = FUN_00107af2(*param_1,1);
        }
      }
      else {
        local_10 = FUN_00107af2(*param_1,cVar1);
      }
      if (local_10 != 0) {
        return local_10;
      }
    }
  }
  return 0;
}


//===== FUN_0010f716 @ 0010f716 size=500 =====

undefined8
FUN_0010f716(undefined8 param_1,undefined8 param_2,int param_3,char *param_4,uint *param_5,
            uint *param_6,uint *param_7)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  uint local_c;
  
  *param_7 = 0;
  *param_6 = *param_7;
  *param_5 = *param_6;
  if (param_4 == (char *)0x0) {
    for (local_c = 0; local_c < 0x1b; local_c = local_c + 1) {
      if ((*(int *)(&DAT_00157398 + (long)(int)local_c * 0x1c) == param_3) &&
         (iVar2 = FUN_00106687(param_2,&DAT_00157380 + (long)(int)local_c * 0x1c), iVar2 == 0)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) break;
    }
    if (local_c < 0x1b) {
      *param_5 = *(uint *)(&DAT_0015738c + (long)(int)local_c * 0x1c);
      *param_6 = *(uint *)(&DAT_00157390 + (long)(int)local_c * 0x1c);
      *param_7 = *(uint *)(&DAT_00157394 + (long)(int)local_c * 0x1c);
    }
    uVar3 = 0;
  }
  else {
    *param_5 = (int)*param_4 - 0x41;
    if (((((int)*param_5 < 0) || (0x13 < *param_5)) ||
        (*param_6 = (int)param_4[1] - 0x61, (int)*param_6 < 0)) ||
       (((0xf < *param_6 || (*param_7 = (int)param_4[2] - 0x41, (int)*param_7 < 0)) ||
        (0xf < *param_7)))) {
      uVar3 = 0x6a;
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}


//===== FUN_0010f90a @ 0010f90a size=281 =====

undefined *
FUN_0010f90a(undefined8 param_1,int param_2,int param_3,undefined *param_4,undefined4 *param_5)

{
  *param_5 = 0;
  if ((param_3 != 0) && (param_2 < 0xc)) {
    if (param_2 < 10) {
      if ((&PTR_DAT_0035c5e0)[(long)param_3 * 0xc + (long)param_2] != (undefined *)0x0) {
        param_4 = (&PTR_DAT_0035c5e0)[(long)param_3 * 0xc + (long)param_2];
      }
    }
    else if (param_2 == 10) {
      if ((&PTR_DAT_0035c630)[(long)param_3 * 0xc] != (undefined *)0x0) {
        *param_5 = 1;
      }
    }
    else if ((&PTR_DAT_0035c638)[(long)param_3 * 0xc] != (undefined *)0x0) {
      *param_5 = 1;
    }
  }
  return param_4;
}


//===== FUN_0010fa24 @ 0010fa24 size=146 =====

void FUN_0010fa24(undefined8 param_1,undefined8 param_2,int param_3,int param_4)

{
  if ((((0 < param_4) && (param_4 < 5)) && (0 < param_3)) && (param_3 < 0x10)) {
    if ((&DAT_00157700)[(long)param_3 * 5 + (long)param_4] == '\x01') {
      FUN_0010fab6(param_1,param_2);
    }
    else if ((&DAT_00157700)[(long)param_3 * 5 + (long)param_4] == '\x02') {
      FUN_0010fb6e(param_1,param_2);
    }
  }
  return;
}


//===== FUN_0010fab6 @ 0010fab6 size=184 =====

void FUN_0010fab6(undefined8 param_1,char *param_2)

{
  if ((*param_2 == 'w') && (param_2[1] == 'a')) {
    *param_2 = 'b';
    param_2[1] = 'a';
  }
  else {
    switch(*param_2) {
    case 'H':
      *param_2 = 'B';
      break;
    case 'K':
      *param_2 = 'V';
      break;
    case 'S':
      *param_2 = 'j';
      break;
    case 'c':
      *param_2 = 'j';
      break;
    case 'h':
      *param_2 = 'b';
      break;
    case 'k':
      *param_2 = 'v';
      break;
    case 's':
      *param_2 = 'z';
      break;
    case 't':
      *param_2 = 'd';
    }
  }
  return;
}


//===== FUN_0010fb6e @ 0010fb6e size=142 =====

void FUN_0010fb6e(undefined8 param_1,char *param_2)

{
  if ((*param_2 == 'w') && (param_2[1] == 'a')) {
    *param_2 = 'p';
    param_2[1] = 'a';
  }
  else if ((*param_2 == 'f') && (param_2[1] == 'u')) {
    *param_2 = 'p';
    param_2[1] = 'u';
  }
  else if (*param_2 == 'H') {
    *param_2 = 'P';
  }
  else if (*param_2 == 'h') {
    *param_2 = 'p';
  }
  return;
}


//===== FUN_0010fbfc @ 0010fbfc size=670 =====

int FUN_0010fbfc(undefined8 param_1,char *param_2,int param_3,int param_4,undefined8 param_5,
                long param_6,long param_7,int param_8,int param_9)

{
  int iVar1;
  int local_20;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  if (param_8 == 0) {
    if (param_9 == 0) {
      param_9 = 0;
    }
    else {
      local_18 = FUN_00106658(param_5);
      if (param_6 != 0) {
        iVar1 = FUN_00106658(param_6);
        local_18 = iVar1 + local_18;
      }
      param_9 = local_18 / 2 + param_9;
    }
  }
  else {
    iVar1 = param_2[3 - param_3] + -0x30;
    local_20 = param_4;
    if (9 < param_4) {
      if ((param_4 < 0xc) && (iVar1 == 1)) {
        local_20 = 10;
      }
      else if ((param_4 < 0xc) && (iVar1 != 1)) {
        local_20 = 0xb;
      }
      else {
        if ((param_4 != 0xc) || (iVar1 != 1)) {
          if ((param_4 == 0xc) && (iVar1 != 1)) {
            return 0;
          }
          if ((((param_2[2] != '1') || (param_2[3] == '0')) &&
              ((param_2[2] == '0' || ((param_2[2] == '1' || (param_2[3] != '0')))))) &&
             ((*param_2 < '1' ||
              (((param_2[1] != '0' || (param_2[2] != '0')) || (param_2[3] != '0')))))) {
            return 0;
          }
          local_14 = FUN_00106658(param_5);
          if (param_6 != 0) {
            iVar1 = FUN_00106658(param_6);
            local_14 = iVar1 + local_14;
          }
          return local_14 / 2 + -1;
        }
        local_20 = 0xc;
      }
    }
    param_9 = (int)(char)(&DAT_00157760)[(long)param_8 * 0xd + (long)local_20];
    if (param_9 == -1) {
      local_10 = FUN_00106658(param_5);
      if (param_6 != 0) {
        iVar1 = FUN_00106658(param_6);
        local_10 = iVar1 + local_10;
      }
      if (param_7 != 0) {
        iVar1 = FUN_00106658(param_7);
        local_10 = iVar1 + local_10;
      }
      param_9 = local_10 / 2;
    }
    else if (param_9 == 0) {
      param_9 = 0;
    }
    else {
      local_c = 0;
      if (((9 < param_4) && (param_4 < 0xd)) && (iVar1 != 1)) {
        local_c = *(int *)(&DAT_00157340 + (long)iVar1 * 4);
      }
      param_9 = local_c + param_9;
    }
  }
  return param_9;
}


//===== FUN_0010fe9a @ 0010fe9a size=1144 =====

undefined8 FUN_0010fe9a(undefined8 *param_1,char *param_2,char *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  char *local_18;
  
  *param_4 = 0;
  if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
    return 0;
  }
  iVar1 = FUN_00106687(param_3,&DAT_00156f34);
  if (iVar1 == 0) {
    iVar1 = FUN_00106687(param_2,&DAT_00156f3b);
    if (iVar1 == 0) {
      uVar2 = FUN_00107b42(*param_1,&DAT_00156f64);
      *param_4 = uVar2;
      return 1;
    }
    iVar1 = FUN_00106687(param_2,&DAT_00156f3d);
    if (iVar1 == 0) {
      uVar2 = FUN_00107b42(*param_1,&DAT_00156f69);
      *param_4 = uVar2;
      return 1;
    }
  }
  else {
    iVar1 = FUN_00106687(param_3,&DAT_00156f3f);
    local_18 = param_2;
    if (iVar1 == 0) {
      for (; *local_18 == '0'; local_18 = local_18 + 1) {
      }
      iVar1 = FUN_00106687(local_18,&DAT_00156f3b);
      if (iVar1 == 0) {
        uVar2 = FUN_00107b42(*param_1,&DAT_00156f6d);
        *param_4 = uVar2;
        return 1;
      }
      iVar1 = FUN_00106687(local_18,&DAT_00156f3d);
      if (iVar1 == 0) {
        uVar2 = FUN_00107b42(*param_1,&DAT_00156f72);
        *param_4 = uVar2;
        return 1;
      }
      iVar1 = FUN_00106687(local_18,&DAT_00156f46);
      if (iVar1 == 0) {
        uVar2 = FUN_00107b42(*param_1,&DAT_00156f76);
        *param_4 = uVar2;
        return 1;
      }
      iVar1 = FUN_00106687(local_18,&DAT_00156f48);
      if (iVar1 == 0) {
        uVar2 = FUN_00107b42(*param_1,&DAT_00156f7a);
        *param_4 = uVar2;
        return 1;
      }
      iVar1 = FUN_00106687(local_18,&DAT_00156f4a);
      if (iVar1 == 0) {
        uVar2 = FUN_00107b42(*param_1,&DAT_00156f7e);
        *param_4 = uVar2;
        return 1;
      }
      iVar1 = FUN_00106687(local_18,&DAT_00156f4c);
      if (iVar1 == 0) {
        uVar2 = FUN_00107b42(*param_1,&DAT_00156f82);
        *param_4 = uVar2;
        return 1;
      }
      iVar1 = FUN_00106687(local_18,&DAT_00156f4e);
      if (iVar1 == 0) {
        uVar2 = FUN_00107b42(*param_1,&DAT_00156f86);
        *param_4 = uVar2;
        return 1;
      }
      iVar1 = FUN_00106687(local_18,&DAT_00156f50);
      if (iVar1 == 0) {
        uVar2 = FUN_00107b42(*param_1,&DAT_00156f8a);
        *param_4 = uVar2;
        return 1;
      }
      iVar1 = FUN_00106687(local_18,&DAT_00156f52);
      if (iVar1 == 0) {
        uVar2 = FUN_00107b42(*param_1,&DAT_00156f8e);
        *param_4 = uVar2;
        return 1;
      }
      iVar1 = FUN_00106687(local_18,&DAT_00156f54);
      if (iVar1 == 0) {
        uVar2 = FUN_00107b42(*param_1,&DAT_00156f93);
        *param_4 = uVar2;
        return 1;
      }
      iVar1 = FUN_00106687(local_18,&DAT_00156f57);
      if (iVar1 == 0) {
        uVar2 = FUN_00107b42(*param_1,&DAT_00156f97);
        *param_4 = uVar2;
        return 1;
      }
      iVar1 = FUN_00106687(local_18,&DAT_00156f5a);
      if (iVar1 == 0) {
        uVar2 = FUN_00107b42(*param_1,&DAT_00156f9e);
        *param_4 = uVar2;
        return 1;
      }
      iVar1 = FUN_00106687(local_18,&DAT_00156f5d);
      if (iVar1 == 0) {
        uVar2 = FUN_00107b42(*param_1,&DAT_00156fa2);
        *param_4 = uVar2;
        return 1;
      }
    }
  }
  return 0;
}


//===== FUN_00110314 @ 00110314 size=54 =====

void FUN_00110314(long param_1)

{
  FUN_0010b7ac(param_1);
  FUN_0010da10(param_1 + 0x20);
  return;
}


//===== FUN_0011036a @ 0011036a size=54 =====

void FUN_0011036a(long param_1)

{
  FUN_0010da1a(param_1 + 0x20);
  FUN_0010b7b6(param_1);
  return;
}


//===== FUN_001103c0 @ 001103c0 size=155 =====

void FUN_001103c0(long param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_0010da24(param_1 + 0x20,param_3);
  FUN_0010b7c0(param_1,param_3);
  *(int *)(param_1 + 0x48) = (param_4 << 10) / 100;
  *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x48);
  *(int *)(param_1 + 0x50) = (200 - param_2) * 0xd + 0x19a;
  FUN_0011045c(param_1);
  return;
}


//===== FUN_0011045c @ 0011045c size=102 =====

void FUN_0011045c(long param_1)

{
  undefined4 local_c;
  
  *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x48);
  for (local_c = 0; local_c < 0xf; local_c = local_c + 1) {
    *(undefined4 *)(param_1 + 4 + ((long)local_c + 0x14) * 4) = 0;
  }
  FUN_0010da9a(param_1 + 0x20);
  FUN_0010b866(param_1);
  return;
}


//===== FUN_001104c2 @ 001104c2 size=848 =====

int FUN_001104c2(long param_1,ushort *param_2,undefined8 param_3)

{
  int iVar1;
  int local_50;
  int local_4c;
  undefined4 local_48;
  int local_44;
  long local_40;
  int local_38;
  undefined4 local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  short local_1e;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  FUN_0010b896(param_1,*(undefined1 *)((long)param_2 + 5),(char)param_2[3]);
  FUN_0010daec(param_1 + 0x20,(char)param_2[2],param_2[1] >> 1);
  local_40 = *(long *)(param_2 + 4);
  local_34 = 0x10000;
  local_30 = 0;
  local_2c = 0x10000;
  for (local_44 = 1; local_44 < 0xf; local_44 = local_44 + 1) {
    local_2c = -*(int *)(param_1 + 0x50) * local_2c >> 0xc;
    local_30 = local_30 - (*(short *)((long)local_44 * 2 + local_40) * local_2c >> 0xc);
  }
  local_38 = (int)(0x10000000 / (long)(0x10000 - local_30));
  local_44 = 0;
  while( true ) {
    if ((int)(uint)*param_2 <= local_44) {
      return 0;
    }
    local_28 = FUN_0010db1a(param_1 + 0x20);
    FUN_0010b8c4(param_1,&local_4c,&local_50);
    local_18 = 0;
    local_14 = 0;
    for (local_1c = 1; local_1c < 0xf; local_1c = local_1c + 1) {
      local_10 = (*(int *)(param_1 + 0x50) * *(int *)(param_1 + 4 + ((long)local_1c + 0x14) * 4) >>
                 0xc) + local_14;
      local_14 = (-*(int *)(param_1 + 0x50) * local_10 >> 0xc) +
                 *(int *)(param_1 + 4 + ((long)local_1c + 0x14) * 4);
      local_18 = local_18 - (*(short *)((long)local_1c * 2 + local_40) * local_14 >> 0xc);
    }
    local_24 = (local_4c + local_28 + local_50 + local_18) * local_38 >> 0xc;
    local_14 = local_24;
    for (local_1c = 1; local_1c < 0xf; local_1c = local_1c + 1) {
      local_c = (*(int *)(param_1 + 0x50) * *(int *)(param_1 + 4 + ((long)local_1c + 0x14) * 4) >>
                0xc) + local_14;
      local_14 = (-*(int *)(param_1 + 0x50) * local_c >> 0xc) +
                 *(int *)(param_1 + 4 + ((long)local_1c + 0x14) * 4);
      *(int *)(param_1 + 4 + ((long)local_1c + 0x14) * 4) = local_c;
    }
    local_24 = *(int *)(param_1 + 0x4c) * local_24;
    if (0x400 < *(int *)(param_1 + 0x48)) {
      if ((local_24 < 0x1ccc934) && (-0x1ccc934 < local_24)) {
        *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
        if (*(int *)(param_1 + 0x48) < *(int *)(param_1 + 0x4c)) {
          *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x48);
        }
      }
      else {
        *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + -0x32;
        if (*(int *)(param_1 + 0x4c) < 0x400) {
          *(undefined4 *)(param_1 + 0x4c) = 0x400;
        }
      }
    }
    if (local_24 < 0x1fffc01) {
      if (local_24 < -0x2000000) {
        local_1e = -0x8000;
      }
      else {
        local_1e = (short)(local_24 >> 10);
      }
    }
    else {
      local_1e = 0x7fff;
    }
    iVar1 = FUN_00109b94(param_3,(int)local_1e);
    if (iVar1 != 0) break;
    local_44 = local_44 + 1;
    local_48 = 0;
  }
  return iVar1;
}


//===== FUN_00110820 @ 00110820 size=54 =====

void FUN_00110820(void)

{
  code *pcVar1;
  long *plVar2;
  
  if (DAT_0035a000 != (code *)0xffffffffffffffff) {
    plVar2 = (long *)&DAT_0035a000;
    pcVar1 = DAT_0035a000;
    do {
      plVar2 = plVar2 + -1;
      (*pcVar1)();
      pcVar1 = (code *)*plVar2;
    } while (pcVar1 != (code *)0xffffffffffffffff);
  }
  return;
}


//===== _DT_FINI @ 00110858 size=14 =====

void _DT_FINI(void)

{
  FUN_00104fc0();
  return;
}


//===== __gmon_start__ @ 0035d000 size=1 =====

/* WARNING: Control flow encountered bad instruction data */

void __gmon_start__(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== _Jv_RegisterClasses @ 0035d008 size=1 =====

/* WARNING: Control flow encountered bad instruction data */

void _Jv_RegisterClasses(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== malloc @ 0035d010 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== free @ 0035d018 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== __cxa_finalize @ 0035d028 size=1 =====

/* WARNING: Control flow encountered bad instruction data */

void __cxa_finalize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== memcpy @ 0035d030 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== _Unwind_Resume @ 0035d038 size=1 =====

/* WARNING: Control flow encountered bad instruction data */

void _Unwind_Resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


