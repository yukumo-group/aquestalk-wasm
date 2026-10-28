//===== _DT_INIT @ 00100d50 size=24 =====

void _DT_INIT(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  entry(param_3,0x100d59);
  FUN_00100e60();
  FUN_0010c990();
  return;
}


//===== FUN_00100d68 @ 00100d68 size=12 =====

void FUN_00100d68(void)

{
  (*(code *)PTR_00316ff8)();
  return;
}


//===== malloc @ 00100d78 size=6 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_malloc_00317000)();
  return pvVar1;
}


//===== free @ 00100d88 size=6 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
  (*(code *)PTR_free_00317008)();
  return;
}


//===== __cxa_finalize @ 00100d98 size=6 =====

void __cxa_finalize(void)

{
  (*(code *)PTR___cxa_finalize_00317010)();
  return;
}


//===== memcpy @ 00100da8 size=6 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memcpy_00317018)();
  return pvVar1;
}


//===== entry @ 00100dc0 size=23 =====

void processEntry entry(void)

{
  if (PTR___gmon_start___00316fb8 != (undefined *)0x0) {
    (*(code *)PTR___gmon_start___00316fb8)();
  }
  return;
}


//===== FUN_00100de0 @ 00100de0 size=116 =====

/* WARNING: Removing unreachable block (ram,0x00100e2b) */
/* WARNING: Removing unreachable block (ram,0x00100e30) */

void FUN_00100de0(void)

{
  if (DAT_00317028 == '\0') {
    if (PTR___cxa_finalize_00316fd0 != (undefined *)0x0) {
      __cxa_finalize(PTR_LOOP_00317020);
    }
    DAT_00317028 = '\x01';
  }
  return;
}


//===== FUN_00100e60 @ 00100e60 size=38 =====

void FUN_00100e60(void)

{
  if ((DAT_00316690 != 0) && (PTR__Jv_RegisterClasses_00316fc0 != (undefined *)0x0)) {
    (*(code *)PTR__Jv_RegisterClasses_00316fc0)(&DAT_00316690);
    return;
  }
  return;
}


//===== AquesTalk2_Synthe @ 00100e8c size=206 =====

undefined8 AquesTalk2_Synthe(undefined8 param_1,undefined4 param_2,int *param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_1c;
  
  local_1c = 0;
  local_28 = 0;
  local_30 = (void *)0x0;
  iVar1 = FUN_00102be4(param_1);
  if (iVar1 == 0) {
    local_1c = 0;
  }
  else {
    local_30 = malloc((long)(iVar1 + 1));
    if (local_30 == (void *)0x0) {
      local_1c = 0x65;
    }
    else {
      FUN_00102d33(local_30,param_1);
      local_28 = FUN_001012f4(local_30,param_2,param_3,param_4);
    }
  }
  if (local_30 != (void *)0x0) {
    free(local_30);
  }
  if (local_1c != 0) {
    *param_3 = local_1c;
  }
  return local_28;
}


//===== AquesTalk2_Synthe_Euc @ 00100f5a size=224 =====

undefined8
AquesTalk2_Synthe_Euc(undefined8 param_1,undefined4 param_2,int *param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_1c;
  
  local_28 = 0;
  local_30 = (void *)0x0;
  iVar1 = FUN_00102be4(param_1);
  if (iVar1 == 0) {
    local_1c = 0;
  }
  else {
    local_30 = malloc((long)(iVar1 + 1));
    if (local_30 == (void *)0x0) {
      local_1c = 0x65;
    }
    else {
      local_1c = FUN_001019f0(param_1,local_30,iVar1 + 1);
      if (local_1c == 0) {
        local_28 = FUN_001012f4(local_30,param_2,param_3,param_4);
      }
    }
  }
  if (local_30 != (void *)0x0) {
    free(local_30);
  }
  if (local_1c != 0) {
    *param_3 = local_1c;
  }
  return local_28;
}


//===== AquesTalk2_Synthe_Utf8 @ 0010103a size=224 =====

undefined8
AquesTalk2_Synthe_Utf8(undefined8 param_1,undefined4 param_2,int *param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_1c;
  
  local_28 = 0;
  local_30 = (void *)0x0;
  iVar1 = FUN_00102be4(param_1);
  if (iVar1 == 0) {
    local_1c = 0;
  }
  else {
    local_30 = malloc((long)(iVar1 + 1));
    if (local_30 == (void *)0x0) {
      local_1c = 0x65;
    }
    else {
      local_1c = FUN_00101b2f(param_1,local_30,iVar1 + 1);
      if (local_1c == 0) {
        local_28 = FUN_001012f4(local_30,param_2,param_3,param_4);
      }
    }
  }
  if (local_30 != (void *)0x0) {
    free(local_30);
  }
  if (local_1c != 0) {
    *param_3 = local_1c;
  }
  return local_28;
}


//===== AquesTalk2_Synthe_Utf16 @ 0010111a size=247 =====

undefined8 AquesTalk2_Synthe_Utf16(long param_1,undefined4 param_2,int *param_3,undefined8 param_4)

{
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_28 = 0;
  local_30 = (void *)0x0;
  local_20 = 0;
  while (*(short *)((long)local_20 * 2 + param_1) != 0) {
    local_20 = local_20 + 1;
  }
  if (local_20 == 0) {
    local_1c = 0;
  }
  else {
    local_30 = malloc((long)(local_20 * 2 + 1));
    if (local_30 == (void *)0x0) {
      local_1c = 0x65;
    }
    else {
      local_1c = FUN_00101c6e(param_1,local_30,local_20 * 2 + 1);
      if (local_1c == 0) {
        local_28 = FUN_001012f4(local_30,param_2,param_3,param_4);
      }
    }
  }
  if (local_30 != (void *)0x0) {
    free(local_30);
  }
  if (local_1c != 0) {
    *param_3 = local_1c;
  }
  return local_28;
}


//===== AquesTalk2_Synthe_Roman @ 00101211 size=227 =====

undefined8
AquesTalk2_Synthe_Roman(undefined8 param_1,undefined4 param_2,int *param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_1c;
  
  local_28 = 0;
  local_30 = (void *)0x0;
  iVar1 = FUN_00102be4(param_1);
  if (iVar1 == 0) {
    local_1c = 0;
  }
  else {
    local_30 = malloc((long)(iVar1 * 2 + 1));
    if (local_30 == (void *)0x0) {
      local_1c = 0x65;
    }
    else {
      local_1c = FUN_00101dd6(param_1,local_30,iVar1 * 2 + 1);
      if (local_1c == 0) {
        local_28 = FUN_001012f4(local_30,param_2,param_3,param_4);
      }
    }
  }
  if (local_30 != (void *)0x0) {
    free(local_30);
  }
  if (local_1c != 0) {
    *param_3 = local_1c;
  }
  return local_28;
}


//===== FUN_001012f4 @ 001012f4 size=661 =====

undefined8 FUN_001012f4(undefined8 param_1,undefined2 param_2,int *param_3,long param_4)

{
  undefined1 local_3c8 [320];
  undefined1 local_288 [288];
  undefined1 local_168 [288];
  undefined1 local_48 [24];
  void *local_30;
  void *local_28;
  undefined8 local_20;
  int local_14;
  int local_10;
  undefined2 local_a;
  
  local_10 = 0;
  local_20 = 0;
  local_28 = (void *)0x0;
  local_30 = (void *)0x0;
  FUN_001015ac(local_48);
  local_30 = malloc(0x8000);
  if (local_30 == (void *)0x0) {
    *param_3 = 0xcb;
  }
  else {
    local_10 = FUN_00103004(local_168,local_30);
    if (local_10 == 0) {
      FUN_00105f40(local_288);
      if (param_4 == 0) {
        local_10 = FUN_0010602d(local_288,PTR_DAT_00316fc8,1);
      }
      else {
        local_10 = FUN_0010602d(local_288,param_4,1);
      }
      if (local_10 == 0) {
        FUN_00103063(local_168,local_288);
        local_14 = FUN_00102be4(param_1);
        if (local_14 == 0) {
          local_10 = 0x6f;
        }
        else {
          local_28 = malloc((long)(local_14 + 1));
          if (local_28 == (void *)0x0) {
            local_10 = 0x65;
          }
          else {
            FUN_00102d33(local_28,param_1);
            FUN_001030e7(local_168,param_2);
            FUN_0010312f(local_168,0x100);
            local_10 = FUN_0010314b(local_168,local_28);
            if (local_10 == 0) {
              while (local_10 = FUN_001032ad(local_168,local_3c8,&local_a), local_10 != 1) {
                if (local_10 != 0) goto LAB_0010153f;
                FUN_001015f1(local_48,local_3c8,local_a);
              }
              local_20 = FUN_00101648(local_48,param_3);
              local_10 = 0;
            }
          }
        }
      }
    }
    else {
      *param_3 = local_10;
    }
  }
LAB_0010153f:
  FUN_001015d7(local_48);
  if (local_28 != (void *)0x0) {
    free(local_28);
  }
  if (local_30 != (void *)0x0) {
    free(local_30);
  }
  if (local_10 != 0) {
    *param_3 = local_10;
  }
  return local_20;
}


//===== AquesTalk2_FreeWave @ 00101589 size=33 =====

void AquesTalk2_FreeWave(void *param_1)

{
  if (param_1 != (void *)0x0) {
    free(param_1);
  }
  return;
}


//===== FUN_001015ac @ 001015ac size=43 =====

void FUN_001015ac(undefined8 *param_1)

{
  *param_1 = 0;
  *(undefined4 *)(param_1 + 1) = 0;
  *(undefined4 *)((long)param_1 + 0xc) = 0;
  return;
}


//===== FUN_001015d7 @ 001015d7 size=26 =====

void FUN_001015d7(undefined8 param_1)

{
  FUN_001017dc(param_1);
  return;
}


//===== FUN_001015f1 @ 001015f1 size=43 =====

void FUN_001015f1(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  FUN_00101826(param_1,param_2,param_3);
  return;
}


//===== FUN_0010161c @ 0010161c size=44 =====

void FUN_0010161c(undefined8 param_1,undefined2 param_2)

{
  undefined2 local_14 [2];
  undefined8 local_10;
  
  local_14[0] = param_2;
  local_10 = param_1;
  FUN_00101826(param_1,local_14,1);
  return;
}


//===== FUN_00101648 @ 00101648 size=404 =====

undefined8 FUN_00101648(undefined8 *param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined8 uVar3;
  
  uVar1 = *(uint *)((long)param_1 + 0xc);
  puVar2 = (undefined1 *)*param_1;
  *puVar2 = 0x52;
  puVar2[1] = 0x49;
  puVar2[2] = 0x46;
  puVar2[3] = 0x46;
  puVar2[8] = 0x57;
  puVar2[9] = 0x41;
  puVar2[10] = 0x56;
  puVar2[0xb] = 0x45;
  puVar2[0xc] = 0x66;
  puVar2[0xd] = 0x6d;
  puVar2[0xe] = 0x74;
  puVar2[0xf] = 0x20;
  puVar2[0x24] = 100;
  puVar2[0x25] = 0x61;
  puVar2[0x26] = 0x74;
  puVar2[0x27] = 0x61;
  *(undefined4 *)(puVar2 + 0x10) = 0x10;
  *(undefined2 *)(puVar2 + 0x14) = 1;
  *(undefined2 *)(puVar2 + 0x16) = 1;
  *(undefined2 *)(puVar2 + 0x22) = 0x10;
  *(undefined4 *)(puVar2 + 0x18) = 8000;
  *(uint *)(puVar2 + 0x1c) =
       (uint)*(ushort *)(puVar2 + 0x16) * *(int *)(puVar2 + 0x18) *
       (uint)(*(ushort *)(puVar2 + 0x22) >> 3);
  *(ushort *)(puVar2 + 0x20) = *(short *)(puVar2 + 0x16) * (*(ushort *)(puVar2 + 0x22) >> 3);
  *(uint *)(puVar2 + 0x28) = (uint)*(ushort *)(puVar2 + 0x20) * (int)((ulong)uVar1 - 0x2c >> 1);
  *(int *)(puVar2 + 4) = *(int *)(puVar2 + 0x28) + 0x24;
  *param_2 = *(undefined4 *)((long)param_1 + 0xc);
  uVar3 = *param_1;
  *param_1 = 0;
  *(undefined4 *)((long)param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 1) = 0;
  return uVar3;
}


//===== FUN_001017dc @ 001017dc size=74 =====

void FUN_001017dc(long *param_1)

{
  if (*param_1 != 0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  *(undefined4 *)((long)param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 1) = 0;
  return;
}


//===== FUN_00101826 @ 00101826 size=215 =====

int FUN_00101826(long *param_1,undefined2 *param_2,int param_3)

{
  int iVar1;
  undefined2 *local_28;
  int local_10;
  
  if (((*param_1 != 0) || (iVar1 = FUN_001018fd(param_1), iVar1 == 0)) &&
     (((ulong)*(uint *)((long)param_1 + 0xc) + (long)param_3 * 2 < (ulong)*(uint *)(param_1 + 1) ||
      (iVar1 = FUN_00101954(param_1,param_3 * 2), iVar1 == 0)))) {
    local_28 = param_2;
    for (local_10 = 0; local_10 < param_3; local_10 = local_10 + 1) {
      *(undefined2 *)(*param_1 + (ulong)*(uint *)((long)param_1 + 0xc)) = *local_28;
      local_28 = local_28 + 1;
      *(int *)((long)param_1 + 0xc) = *(int *)((long)param_1 + 0xc) + 2;
    }
    iVar1 = 0;
  }
  return iVar1;
}


//===== FUN_001018fd @ 001018fd size=87 =====

undefined8 FUN_001018fd(long *param_1)

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


//===== FUN_00101954 @ 00101954 size=153 =====

undefined8 FUN_00101954(undefined8 *param_1,int param_2)

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


//===== FUN_001019f0 @ 001019f0 size=319 =====

int FUN_001019f0(char *param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  undefined1 *puVar2;
  char *local_30;
  int local_c;
  
  local_c = 0;
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    iVar1 = -2;
  }
  else if ((param_2 == (undefined1 *)0x0) || (param_3 < 2)) {
    iVar1 = -2;
  }
  else {
    *param_2 = 0;
    local_30 = param_1;
    while (*local_30 != '\0') {
      if (*local_30 < '\0') {
        puVar2 = (undefined1 *)FUN_00102488(local_30);
        if (puVar2 == (undefined1 *)0x0) {
          return ((int)local_30 - (int)param_1) + 1;
        }
        if (param_3 < local_c + 3) {
          return -1;
        }
        param_2[local_c] = *puVar2;
        param_2[local_c + 1] = puVar2[1];
        local_c = local_c + 2;
        param_2[local_c] = 0;
        local_30 = local_30 + 2;
      }
      else {
        if (param_3 < local_c + 2) {
          return -1;
        }
        param_2[local_c] = *local_30;
        local_c = local_c + 1;
        local_30 = local_30 + 1;
        param_2[local_c] = 0;
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}


//===== FUN_00101b2f @ 00101b2f size=319 =====

int FUN_00101b2f(char *param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  undefined1 *puVar2;
  char *local_30;
  int local_c;
  
  local_c = 0;
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    iVar1 = -2;
  }
  else if ((param_2 == (undefined1 *)0x0) || (param_3 < 2)) {
    iVar1 = -2;
  }
  else {
    *param_2 = 0;
    local_30 = param_1;
    while (*local_30 != '\0') {
      if (*local_30 < '\0') {
        puVar2 = (undefined1 *)FUN_0010252a(local_30);
        if (puVar2 == (undefined1 *)0x0) {
          return ((int)local_30 - (int)param_1) + 1;
        }
        if (param_3 < local_c + 3) {
          return -1;
        }
        param_2[local_c] = *puVar2;
        param_2[local_c + 1] = puVar2[1];
        local_c = local_c + 2;
        param_2[local_c] = 0;
        local_30 = local_30 + 3;
      }
      else {
        if (param_3 < local_c + 2) {
          return -1;
        }
        param_2[local_c] = *local_30;
        local_c = local_c + 1;
        local_30 = local_30 + 1;
        param_2[local_c] = 0;
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}


//===== FUN_00101c6e @ 00101c6e size=360 =====

int FUN_00101c6e(ushort *param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  undefined1 *puVar2;
  ushort *local_30;
  int local_c;
  
  local_c = 0;
  if ((param_1 == (ushort *)0x0) || (*param_1 == 0)) {
    iVar1 = -2;
  }
  else if ((param_2 == (undefined1 *)0x0) || (param_3 < 2)) {
    iVar1 = -2;
  }
  else {
    *param_2 = 0;
    local_30 = param_1;
    if (*param_1 == 0xfeff) {
      local_30 = param_1 + 1;
    }
    while (*local_30 != 0) {
      if (*local_30 < 0x80) {
        if (param_3 < local_c + 2) {
          return -1;
        }
        param_2[local_c] = (char)*local_30;
        local_c = local_c + 1;
        local_30 = local_30 + 1;
        param_2[local_c] = 0;
      }
      else {
        puVar2 = (undefined1 *)FUN_00102606(*local_30);
        if (puVar2 == (undefined1 *)0x0) {
          return (int)((long)local_30 - (long)param_1 >> 1) + 1;
        }
        if (param_3 < local_c + 3) {
          return -1;
        }
        param_2[local_c] = *puVar2;
        param_2[local_c + 1] = puVar2[1];
        local_c = local_c + 2;
        param_2[local_c] = 0;
        local_30 = local_30 + 1;
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}


//===== FUN_00101dd6 @ 00101dd6 size=769 =====

int FUN_00101dd6(char *param_1,undefined1 *param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int local_24;
  int local_20;
  int local_1c [3];
  
  local_1c[0] = 0;
  local_20 = 0;
  local_24 = 1;
  bVar1 = false;
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    iVar2 = -2;
  }
  else if ((param_2 == (undefined1 *)0x0) || (param_3 < 2)) {
    iVar2 = -2;
  }
  else {
    *param_2 = 0;
    do {
      while( true ) {
        while( true ) {
          while( true ) {
            while( true ) {
              while( true ) {
                if (param_1[local_20] == '\0') {
                  param_2[local_1c[0]] = 0;
                  return 0;
                }
                if (param_3 < local_1c[0] + 2) {
                  param_2[local_1c[0]] = 0;
                  return -1;
                }
                if ('\x1f' < param_1[local_20]) break;
                local_20 = local_20 + 1;
              }
              if (param_1[local_20] != '\"') break;
              bVar1 = !bVar1;
              param_2[local_1c[0]] = param_1[local_20];
              local_1c[0] = local_1c[0] + 1;
              local_20 = local_20 + 1;
            }
            if (local_24 != 0) break;
            if (!bVar1) {
              if (param_1[local_20] == '>') {
                local_24 = 1;
              }
              else if (((param_1[local_20] == '=') && (6 < local_20)) &&
                      (iVar2 = FUN_00102e00("counter",param_1 + (long)local_20 + -7), iVar2 == 0)) {
                local_24 = 2;
              }
            }
            param_2[local_1c[0]] = param_1[local_20];
            local_1c[0] = local_1c[0] + 1;
            local_20 = local_20 + 1;
          }
          if (local_24 != 2) break;
          if ((param_1[local_20] != '>') || (bVar1)) {
            if ((param_1[local_20] != ' ') || (bVar1)) {
              iVar2 = FUN_001020d7(param_1,&local_20,param_2,local_1c,param_3);
              if (iVar2 != 0) {
                return iVar2;
              }
            }
            else {
              param_2[local_1c[0]] = param_1[local_20];
              local_1c[0] = local_1c[0] + 1;
              local_20 = local_20 + 1;
              local_24 = 0;
            }
          }
          else {
            param_2[local_1c[0]] = param_1[local_20];
            local_1c[0] = local_1c[0] + 1;
            local_20 = local_20 + 1;
            local_24 = 1;
          }
        }
        if ((param_1[local_20] != '<') || (bVar1)) break;
        param_2[local_1c[0]] = param_1[local_20];
        local_1c[0] = local_1c[0] + 1;
        local_20 = local_20 + 1;
        local_24 = 0;
      }
      iVar2 = FUN_001020d7(param_1,&local_20,param_2,local_1c,param_3);
    } while (iVar2 == 0);
  }
  return iVar2;
}


//===== FUN_001020d7 @ 001020d7 size=945 =====

int FUN_001020d7(long param_1,int *param_2,long param_3,int *param_4,int param_5)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  long lVar4;
  char *local_30;
  int local_24;
  int local_20;
  int local_14;
  int local_10;
  
  local_10 = *param_4;
  local_30 = (char *)(*param_2 + param_1);
  if ((((*local_30 == '\'') || (*local_30 == '\"')) || (*local_30 == '+')) ||
     ((*local_30 == '/' || (*local_30 == ';')))) {
    *(char *)(local_10 + param_3) = *local_30;
    local_10 = local_10 + 1;
    local_30._0_4_ = (int)local_30 + 1;
  }
  else if (*local_30 == '\\') {
    *(char *)(local_10 + param_3) = local_30[1];
    local_10 = local_10 + 1;
    local_30._0_4_ = (int)local_30 + 2;
  }
  else if ((*local_30 == local_30[1]) &&
          (((((*local_30 == 'p' || (*local_30 == 't')) ||
             ((*local_30 == 'k' ||
              (((*local_30 == 'q' || (*local_30 == 'c')) || (*local_30 == 's')))))) ||
            ((*local_30 == 'P' || (*local_30 == 'T')))) ||
           ((*local_30 == 'K' || (((*local_30 == 'Q' || (*local_30 == 'C')) || (*local_30 == 'S'))))
           )))) {
    if (param_5 < local_10 + 3) {
      *(undefined1 *)(local_10 + param_3) = 0;
      return -1;
    }
    *(undefined1 *)(local_10 + param_3) = 0x82;
    *(undefined1 *)((local_10 + 1) + param_3) = 0xc1;
    local_10 = local_10 + 2;
    *(undefined1 *)(local_10 + param_3) = 0;
    local_30._0_4_ = (int)local_30 + 1;
  }
  else {
    cVar1 = *local_30;
    if (cVar1 == '_') {
      *(char *)(local_10 + param_3) = *local_30;
      local_10 = local_10 + 1;
      local_30 = local_30 + 1;
    }
    lVar4 = FUN_00102673(local_30,&local_14);
    if (lVar4 == 0) {
      return ((int)local_30 - (int)param_1) + 1;
    }
    iVar3 = FUN_00102be4(lVar4);
    if (param_5 < local_10 + iVar3 + 1) {
      *(undefined1 *)(local_10 + param_3) = 0;
      return -1;
    }
    if (cVar1 == '_') {
      for (local_20 = 0; local_20 < iVar3; local_20 = local_20 + 1) {
        uVar2 = CONCAT11(*(undefined1 *)(local_20 + lVar4),
                         *(undefined1 *)((long)local_20 + 1 + lVar4));
        if ((uVar2 < 0x829f) || (0x82dd < uVar2)) {
          if ((uVar2 < 0x82de) || (0x82f1 < uVar2)) {
            *(undefined1 *)(local_10 + param_3) = *(undefined1 *)(local_20 + lVar4);
            local_10 = local_10 + 1;
          }
          else {
            *(char *)(local_10 + param_3) = (char)((ushort)(uVar2 + 0xa2) >> 8);
            *(char *)((local_10 + 1) + param_3) = (char)(uVar2 + 0xa2);
            local_10 = local_10 + 2;
            local_20 = local_20 + 1;
          }
        }
        else {
          *(char *)(local_10 + param_3) = (char)((ushort)(uVar2 + 0xa1) >> 8);
          *(char *)((local_10 + 1) + param_3) = (char)(uVar2 + 0xa1);
          local_10 = local_10 + 2;
          local_20 = local_20 + 1;
        }
      }
    }
    else {
      for (local_24 = 0; local_24 < iVar3; local_24 = local_24 + 1) {
        *(undefined1 *)(local_10 + param_3) = *(undefined1 *)(local_24 + lVar4);
        local_10 = local_10 + 1;
      }
    }
    local_30._0_4_ = (int)local_30 + local_14;
  }
  *param_4 = local_10;
  *param_2 = (int)local_30 - (int)param_1;
  return 0;
}


//===== FUN_00102488 @ 00102488 size=162 =====

undefined * FUN_00102488(char *param_1)

{
  uint local_c;
  
  local_c = 0;
  while( true ) {
    if (0xa1 < local_c) {
      return (undefined *)0x0;
    }
    if ((*param_1 == (&DAT_00110644)[(long)(int)local_c * 0xe]) &&
       (param_1[1] == (&DAT_00110645)[(long)(int)local_c * 0xe])) break;
    local_c = local_c + 1;
  }
  return &DAT_00110640 + (long)(int)local_c * 0xe;
}


//===== FUN_0010252a @ 0010252a size=220 =====

undefined * FUN_0010252a(char *param_1)

{
  uint local_c;
  
  local_c = 0;
  while( true ) {
    if (0xa1 < local_c) {
      return (undefined *)0x0;
    }
    if (((*param_1 == (&DAT_00110648)[(long)(int)local_c * 0xe]) &&
        (param_1[1] == (&DAT_00110649)[(long)(int)local_c * 0xe])) &&
       (param_1[2] == (&DAT_00110648)[((long)(int)local_c * 7 + 1) * 2])) break;
    local_c = local_c + 1;
  }
  return &DAT_00110640 + (long)(int)local_c * 0xe;
}


//===== FUN_00102606 @ 00102606 size=109 =====

undefined * FUN_00102606(short param_1)

{
  uint local_c;
  
  local_c = 0;
  while( true ) {
    if (0xa1 < local_c) {
      return (undefined *)0x0;
    }
    if (*(short *)(&DAT_0011064c + (long)(int)local_c * 0xe) == param_1) break;
    local_c = local_c + 1;
  }
  return &DAT_00110640 + (long)(int)local_c * 0xe;
}


//===== FUN_00102673 @ 00102673 size=182 =====

undefined * FUN_00102673(undefined8 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint local_c;
  
  local_c = 0;
  while( true ) {
    if (0x115 < local_c) {
      return (undefined *)0x0;
    }
    iVar1 = FUN_00102e00(&DAT_00110f20 + (long)(int)local_c * 0xc,param_1);
    if (iVar1 == 0) break;
    local_c = local_c + 1;
  }
  uVar2 = FUN_00102be4(&DAT_00110f20 + (long)(int)local_c * 0xc);
  *param_2 = uVar2;
  return &UNK_00110f24 + (long)(int)local_c * 0xc;
}


//===== FUN_0010272c @ 0010272c size=250 =====

int FUN_0010272c(char *param_1,undefined8 param_2)

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
            local_c = FUN_001029a8(&local_18,param_2);
          }
          else {
            local_c = FUN_001028f3(&local_18,param_2);
          }
        }
        else {
          local_c = FUN_00102826(&local_18,param_2);
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


//===== FUN_00102826 @ 00102826 size=205 =====

int FUN_00102826(undefined8 *param_1,undefined8 param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *local_18;
  
  pcVar2 = (char *)*param_1;
  local_18 = pcVar2;
LAB_0010284d:
  do {
    local_18 = local_18 + 1;
    if ('@' < *local_18) {
      if (*local_18 < '[') goto LAB_0010284d;
    }
    if ((*local_18 < 'a') || ('z' < *local_18)) {
      cVar1 = *local_18;
      *local_18 = '\0';
      iVar3 = FUN_00102a69(pcVar2,param_2);
      if ((iVar3 == 0) && ((cVar1 == '\0' || (iVar3 = FUN_00104463(param_2,7), iVar3 == 0)))) {
        *local_18 = cVar1;
        *param_1 = local_18;
        iVar3 = 0;
      }
      return iVar3;
    }
  } while( true );
}


//===== FUN_001028f3 @ 001028f3 size=181 =====

int FUN_001028f3(undefined8 *param_1,undefined8 param_2)

{
  char cVar1;
  char *pcVar2;
  char *local_18;
  int local_10;
  
  pcVar2 = (char *)*param_1;
  local_18 = pcVar2;
  do {
    local_18 = local_18 + 1;
    if (*local_18 < '0') break;
  } while (*local_18 < ':');
  cVar1 = *local_18;
  *local_18 = '\0';
  local_10 = FUN_0010b132(pcVar2,param_2);
  if ((local_10 == 0) && ((cVar1 == '\0' || (local_10 = FUN_00104463(param_2,7), local_10 == 0)))) {
    *local_18 = cVar1;
    *param_1 = local_18;
  }
  return local_10;
}


//===== FUN_001029a8 @ 001029a8 size=193 =====

int FUN_001029a8(long *param_1,undefined8 param_2)

{
  char *pcVar1;
  int iVar2;
  char *local_18;
  uint local_10;
  
  pcVar1 = (char *)*param_1;
  local_18 = &DAT_00111c40;
  local_10 = 0;
  do {
    if (0x14 < local_10) {
LAB_00102a53:
      *param_1 = (long)(pcVar1 + 1);
      return 0;
    }
    if (*pcVar1 == *local_18) {
      iVar2 = FUN_001044b3(param_2,local_18 + 1);
      if (iVar2 != 0) {
        return iVar2;
      }
      if ((pcVar1[1] != '\0') && (iVar2 = FUN_00104463(param_2,7), iVar2 != 0)) {
        return iVar2;
      }
      goto LAB_00102a53;
    }
    local_18 = local_18 + 8;
    local_10 = local_10 + 1;
  } while( true );
}


//===== FUN_00102a69 @ 00102a69 size=376 =====

int FUN_00102a69(char *param_1,undefined8 param_2)

{
  int iVar1;
  char *local_30;
  uint local_14;
  int local_10;
  
  local_10 = 0;
  local_30 = param_1;
  do {
    if (*local_30 < '[') {
      local_14 = (int)*local_30 - 0x41;
    }
    else {
      local_14 = (int)*local_30 - 0x61;
    }
    if (local_30[1] == '\0') {
      iVar1 = FUN_001044b3(param_2,&UNK_00111d06 + (ulong)local_14 * 0xc);
      return iVar1;
    }
    if (local_10 == 3) {
      iVar1 = FUN_001044b3(param_2,&UNK_00111d06 + (ulong)local_14 * 0xc);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_00104463(param_2,7);
      if (iVar1 != 0) {
        return iVar1;
      }
      local_10 = 0;
    }
    else {
      iVar1 = FUN_001044b3(param_2,&DAT_00111d00 + (ulong)local_14 * 0xc);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_00104463(param_2,4);
      if (iVar1 != 0) {
        return iVar1;
      }
      local_10 = local_10 + 1;
    }
    local_30 = local_30 + 1;
  } while( true );
}


//===== FUN_00102be4 @ 00102be4 size=47 =====

int FUN_00102be4(char *param_1)

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


//===== FUN_00102c13 @ 00102c13 size=86 =====

int FUN_00102c13(char *param_1,char *param_2)

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


//===== FUN_00102c69 @ 00102c69 size=115 =====

int FUN_00102c69(char *param_1,char *param_2,int param_3)

{
  char *local_28;
  char *local_20;
  int local_c;
  
  local_c = 0;
  local_28 = param_2;
  local_20 = param_1;
  while( true ) {
    if (param_3 <= local_c) {
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
    local_c = local_c + 1;
  }
  return 0;
}


//===== FUN_00102cdc @ 00102cdc size=87 =====

char * FUN_00102cdc(char *param_1,char *param_2)

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


//===== FUN_00102d33 @ 00102d33 size=69 =====

char * FUN_00102d33(char *param_1,char *param_2)

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


//===== FUN_00102d78 @ 00102d78 size=80 =====

char * FUN_00102d78(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  int local_2c;
  char *local_28;
  char *local_20;
  
  local_2c = param_3;
  local_28 = param_2;
  local_20 = param_1;
  while( true ) {
    if (local_2c < 1) {
      return param_1;
    }
    cVar1 = *local_28;
    local_28 = local_28 + 1;
    *local_20 = cVar1;
    local_20 = local_20 + 1;
    if (cVar1 == '\0') break;
    local_2c = local_2c + -1;
  }
  return param_1;
}


//===== FUN_00102dc8 @ 00102dc8 size=56 =====

char * FUN_00102dc8(char *param_1,char param_2)

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


//===== FUN_00102e00 @ 00102e00 size=154 =====

int FUN_00102e00(char *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  char *local_28;
  char *local_20;
  
  local_28 = param_2;
  local_20 = param_1;
  do {
    if ((*local_20 < '[') && ('@' < *local_20)) {
      cVar1 = *local_20 + ' ';
    }
    else {
      cVar1 = *local_20;
    }
    if ((*local_28 < '[') && ('@' < *local_28)) {
      cVar2 = *local_28 + ' ';
    }
    else {
      cVar2 = *local_28;
    }
    local_20 = local_20 + 1;
    local_28 = local_28 + 1;
  } while ((cVar1 != '\0') && (cVar1 == cVar2));
  if (cVar1 == '\0') {
    iVar3 = 0;
  }
  else {
    iVar3 = (int)cVar1 - (int)cVar2;
  }
  return iVar3;
}


//===== FUN_00102e9a @ 00102e9a size=117 =====

int FUN_00102e9a(char *param_1,char *param_2)

{
  char *local_20;
  char *local_18;
  int local_c;
  
  local_c = 0;
  local_18 = param_1;
  while( true ) {
    local_20 = param_2;
    if (*local_18 == '\0') {
      return local_c;
    }
    for (; (*local_20 != '\0' && (*local_18 != *local_20)); local_20 = local_20 + 1) {
    }
    if (*local_20 == '\0') break;
    local_c = local_c + 1;
    local_18 = local_18 + 1;
  }
  return local_c;
}


//===== FUN_00102f0f @ 00102f0f size=95 =====

char * FUN_00102f0f(char *param_1,char *param_2)

{
  char *local_18;
  char *local_10;
  
  local_10 = param_1;
  do {
    local_18 = param_2;
    if (*local_10 == '\0') {
      return (char *)0x0;
    }
    for (; *local_18 != '\0'; local_18 = local_18 + 1) {
      if (*local_10 == *local_18) {
        return local_10;
      }
    }
    local_10 = local_10 + 1;
  } while( true );
}


//===== FUN_00102f6e @ 00102f6e size=148 =====

long FUN_00102f6e(long param_1,undefined8 param_2,long *param_3)

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
    uVar1 = FUN_00102e9a(local_20,param_2);
    local_20 = local_20 + (ulong)uVar1;
    puVar2 = (undefined1 *)FUN_00102f0f(local_20,param_2);
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


//===== FUN_00103004 @ 00103004 size=95 =====

undefined8 FUN_00103004(undefined2 *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if (DAT_00111e38 == -0x7e) {
    *param_1 = 0x100;
    param_1[1] = 0xffff;
    *(undefined8 *)(param_1 + 4) = 0;
    *(undefined8 *)(param_1 + 8) = param_2;
    *(undefined4 *)(param_1 + 0xc) = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = 0x71;
  }
  return uVar1;
}


//===== FUN_00103063 @ 00103063 size=132 =====

void FUN_00103063(long param_1,long param_2)

{
  undefined8 uVar1;
  
  *(long *)(param_1 + 8) = param_2;
  FUN_00107bce(param_2);
  uVar1 = FUN_00106dc2(param_2);
  FUN_0010a3cd(param_1 + 0x90,uVar1);
  uVar1 = FUN_00106dd4(param_2);
  FUN_00105f07(param_1 + 0xb8,uVar1);
  *(undefined2 *)(param_1 + 0x98) = *(undefined2 *)(param_2 + 0x118);
  return;
}


//===== FUN_001030e7 @ 001030e7 size=72 =====

void FUN_001030e7(undefined2 *param_1,ushort param_2)

{
  undefined2 local_14;
  
  local_14 = param_2;
  if (param_2 < 0x32) {
    local_14 = 0x32;
  }
  if (300 < local_14) {
    local_14 = 300;
  }
  *param_1 = (short)(0x6400 / (ulong)(long)(int)(uint)local_14);
  return;
}


//===== FUN_0010312f @ 0010312f size=28 =====

void FUN_0010312f(long param_1,undefined2 param_2)

{
  *(undefined2 *)(param_1 + 2) = param_2;
  return;
}


//===== FUN_0010314b @ 0010314b size=354 =====

int FUN_0010314b(ushort *param_1,undefined8 param_2)

{
  ushort uVar1;
  int iVar2;
  
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  FUN_0010441c(param_1 + 0x10,*(undefined8 *)(param_1 + 8));
  iVar2 = FUN_0010a628(param_2,param_1 + 0x10);
  if (iVar2 == 0) {
    uVar1 = FUN_00107c48(param_1 + 0x28,param_1 + 0x10);
    param_1[0xe] = uVar1;
    FUN_00104f38(param_1 + 0x18,*(long *)(param_1 + 8) + 0x800);
    FUN_00105720(param_1 + 0x20,*(long *)(param_1 + 8) + 0x1800,0x200);
    iVar2 = FUN_00107d68(param_1 + 0x28);
    if (iVar2 == 0) {
      iVar2 = FUN_00103512(param_1);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    else {
      param_1[0xe] = (ushort)((uint)*param_1 * (uint)param_1[0xe] >> 8);
      if (param_1[0xe] == 0) {
        return 0x6f;
      }
      FUN_001057bc(param_1 + 0x20,param_1[0xe]);
      param_1[0xc] = 4;
      param_1[0xd] = 0;
    }
    iVar2 = 0;
  }
  return iVar2;
}


//===== FUN_001032ad @ 001032ad size=613 =====

int FUN_001032ad(long param_1,undefined8 param_2,ushort *param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint local_10;
  
  *param_3 = 0;
  if (*(int *)(param_1 + 0x18) == 0) {
    iVar2 = -1;
  }
  else if (*(int *)(param_1 + 0x18) == 5) {
    iVar2 = 1;
  }
  else if (*(int *)(param_1 + 0x18) == 1) {
    do {
      uVar3 = FUN_001057d8(param_1 + 0x40);
      if (0x9f < uVar3) {
        uVar1 = FUN_001057f7(param_1 + 0x40,0xa0,param_2);
        *param_3 = uVar1;
        return 0;
      }
      iVar2 = FUN_001036d3(param_1);
      if (iVar2 == 1) {
        FUN_001057bc(param_1 + 0x40,*(undefined2 *)(param_1 + 0x1c));
        uVar1 = FUN_001057f7(param_1 + 0x40,0xa0,param_2);
        *param_3 = uVar1;
        iVar2 = FUN_00107d68(param_1 + 0x50);
        if (iVar2 == 0) {
          *(undefined4 *)(param_1 + 0x18) = 3;
        }
        else {
          *(undefined4 *)(param_1 + 0x18) = 4;
        }
        return 0;
      }
    } while (iVar2 == 0);
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  else if (*(int *)(param_1 + 0x18) == 3) {
    uVar1 = FUN_001057f7(param_1 + 0x40,0xa0,param_2);
    *param_3 = uVar1;
    uVar3 = FUN_001057d8(param_1 + 0x40);
    if (uVar3 < 0xa0) {
      iVar2 = FUN_00103512(param_1);
      if (iVar2 == 0) {
        FUN_001057bc(param_1 + 0x40,0);
        for (local_10 = 0; local_10 < uVar3; local_10 = local_10 + 1) {
          FUN_00105760(param_1 + 0x40,0);
        }
        iVar2 = 0;
      }
      else {
        *(undefined4 *)(param_1 + 0x18) = 0;
      }
    }
    else {
      iVar2 = 0;
    }
  }
  else if (*(int *)(param_1 + 0x18) == 4) {
    uVar1 = FUN_001057f7(param_1 + 0x40,0xa0,param_2);
    *param_3 = uVar1;
    if (*param_3 < 0xa0) {
      *(undefined4 *)(param_1 + 0x18) = 5;
    }
    iVar2 = 0;
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}


//===== FUN_00103512 @ 00103512 size=449 =====

int FUN_00103512(ushort *param_1)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  undefined1 local_38 [28];
  int local_1c;
  
  FUN_001051c0(local_38,*(long *)(param_1 + 8) + 0x1800);
  local_1c = FUN_00107db6(param_1 + 0x28,local_38,param_1 + 0x18,param_1 + 0xe,
                          *(undefined8 *)(param_1 + 4));
  if (local_1c == 0) {
    if (((short)param_1[1] < 0) || (iVar3 = FUN_00107d68(param_1 + 0x28), iVar3 == 0)) {
      param_1[0xe] = (ushort)((uint)*param_1 * (uint)param_1[0xe] >> 8);
    }
    else {
      param_1[0xe] = param_1[1];
    }
    sVar1 = FUN_00105038(param_1 + 0x18);
    if (sVar1 == 0) {
      FUN_001057bc(param_1 + 0x20,param_1[0xe]);
      param_1[0xc] = 3;
      param_1[0xd] = 0;
    }
    else {
      uVar2 = FUN_0010504a(param_1 + 0x18,0);
      param_1[0x39] = uVar2;
      FUN_00103a42(param_1,0);
      param_1[0xf] = 1;
      FUN_0010a36a(param_1 + 0x48);
      FUN_00105f2a(param_1 + 0x5c);
      FUN_001059ae(param_1 + 100);
      FUN_001059ae(param_1 + 0x77);
      FUN_00107bce(*(undefined8 *)(param_1 + 4));
      param_1[0xc] = 1;
      param_1[0xd] = 0;
    }
    return 0;
  }
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  return local_1c;
}


//===== FUN_001036d3 @ 001036d3 size=879 =====

undefined8 FUN_001036d3(long param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  undefined2 uVar4;
  ushort uVar5;
  short sVar6;
  undefined1 local_48 [20];
  int local_34;
  int local_30;
  int local_2c;
  undefined4 local_28;
  short local_22;
  ushort local_20;
  short local_1e;
  short local_1c;
  short local_1a;
  
  if (*(ushort *)(param_1 + 0x76) <= *(ushort *)(param_1 + 0x7a)) {
    uVar1 = *(ushort *)(param_1 + 0x1e);
    uVar3 = FUN_00105038(param_1 + 0x30);
    if (uVar3 <= uVar1) {
      return 1;
    }
    FUN_00103a42(param_1,*(undefined2 *)(param_1 + 0x1e));
    *(short *)(param_1 + 0x1e) = *(short *)(param_1 + 0x1e) + 1;
  }
  uVar1 = *(ushort *)(param_1 + 0x78);
  uVar3 = FUN_00106de6(*(undefined8 *)(param_1 + 8));
  if (uVar3 < uVar1) {
    uVar4 = FUN_00106de6(*(undefined8 *)(param_1 + 8));
    *(undefined2 *)(param_1 + 0x78) = uVar4;
  }
  sVar6 = *(short *)(param_1 + 0x70);
  uVar1 = *(ushort *)(param_1 + 0x72);
  uVar3 = *(ushort *)(param_1 + 0x70);
  uVar2 = *(ushort *)(param_1 + 0x78);
  uVar5 = FUN_00106de6(*(undefined8 *)(param_1 + 8));
  local_22 = sVar6 + (short)((int)(((uint)uVar1 - (uint)uVar3) * (uint)uVar2) / (int)(uint)uVar5);
  FUN_0010a3e6(param_1 + 0x90,local_22);
  local_28 = FUN_00106f16(*(undefined8 *)(param_1 + 8),*(undefined2 *)(param_1 + 0x78),&local_1a,
                          &local_1c,local_48);
  FUN_00105a0e(param_1 + 200,local_28,local_48);
  local_28 = FUN_001075af(*(undefined8 *)(param_1 + 8),*(undefined2 *)(param_1 + 0x78),&local_1e,
                          local_48);
  FUN_00105a0e(param_1 + 0xee,local_28,local_48);
  local_20 = 0;
  while ((local_20 < *(ushort *)(param_1 + 0x74) &&
         (*(ushort *)(param_1 + 0x7a) < *(ushort *)(param_1 + 0x76)))) {
    local_2c = FUN_0010a402(param_1 + 0x90);
    sVar6 = FUN_00105eb8(param_1 + 0xb8);
    local_30 = (int)sVar6;
    sVar6 = FUN_00105a53(param_1 + 200,local_1c * local_30 + local_1a * local_2c >> 6);
    local_34 = (int)sVar6;
    sVar6 = FUN_00105a53(param_1 + 0xee,local_1e * local_30 >> 6);
    local_34 = local_34 + sVar6;
    if ((*(long *)(param_1 + 0x80) != 0) &&
       (*(short *)(param_1 + 0x7c) == *(short *)(param_1 + 0x7a))) {
      *(undefined2 *)(param_1 + 0x88) = 0;
    }
    if (*(ushort *)(param_1 + 0x88) < 0x50) {
      local_34 = local_34 +
                 ((int)((uint)*(byte *)(param_1 + 0x7e) *
                       (int)(short)(*(ushort *)
                                     (*(long *)(param_1 + 0x80) +
                                     (ulong)*(ushort *)(param_1 + 0x88) * 2) ^ 0x3c5a)) >> 6);
      *(short *)(param_1 + 0x88) = *(short *)(param_1 + 0x88) + 1;
    }
    if (local_34 < 0x8000) {
      if (local_34 < -0x8000) {
        local_34 = -0x8000;
      }
    }
    else {
      local_34 = 0x7fff;
    }
    FUN_00105760(param_1 + 0x40,(int)(short)local_34);
    local_20 = local_20 + 1;
    *(short *)(param_1 + 0x7a) = *(short *)(param_1 + 0x7a) + 1;
  }
  *(short *)(param_1 + 0x78) = *(short *)(param_1 + 0x78) + 0x28;
  return 0;
}


//===== FUN_00103a42 @ 00103a42 size=417 =====

void FUN_00103a42(ushort *param_1,short param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  ushort uVar3;
  short sVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  uint local_1c;
  
  uVar5 = FUN_00105001(param_1 + 0x18,param_2);
  uVar6 = FUN_00105001(param_1 + 0x18,param_2 + 1);
  uVar1 = FUN_00105116(uVar6);
  uVar2 = FUN_00105116(uVar5);
  FUN_00106d43(*(undefined8 *)(param_1 + 4),uVar2,uVar1);
  param_1[0x38] = param_1[0x39];
  uVar3 = FUN_00105136(uVar5);
  param_1[0x39] = uVar3;
  sVar4 = FUN_0010517b(uVar5);
  if (sVar4 == -0x8000) {
    local_1c = ((uint)*param_1 * 2 + (uint)*param_1) / 2;
  }
  else {
    local_1c = (uint)*param_1;
  }
  param_1[0x3a] = (ushort)(local_1c * 0x28 >> 8);
  uVar3 = FUN_00106de6(*(undefined8 *)(param_1 + 4));
  param_1[0x3b] = (ushort)(uVar3 * local_1c >> 8);
  uVar5 = FUN_00106dfb(*(undefined8 *)(param_1 + 4),param_1 + 0x3e,param_1 + 0x3f);
  *(undefined8 *)(param_1 + 0x40) = uVar5;
  param_1[0x44] = 0x50;
  if (*(long *)(param_1 + 0x40) != 0) {
    param_1[0x3e] = (ushort)(param_1[0x3e] * local_1c >> 8);
  }
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  return;
}


//===== FUN_00103be4 @ 00103be4 size=971 =====

byte FUN_00103be4(byte *param_1,undefined4 *param_2)

{
  byte bVar1;
  byte bVar2;
  byte *local_18;
  int local_10;
  
  if ((param_1 != (byte *)0x0) && (*param_1 != 0)) {
    bVar1 = *param_1;
    bVar2 = param_1[1];
    if (bVar1 < 0x82) {
      if ((char)bVar1 < '\0') {
        local_10 = 0x115;
      }
      else if (bVar1 < 0x40) {
        local_10 = 299;
      }
      else {
        local_10 = 0x11a;
      }
    }
    else if (bVar1 == 0x82) {
      if ((byte)PTR_DAT_00316fd8[0x671] < bVar2) {
        if ((byte)PTR_DAT_00316fd8[0x549] < bVar2) {
          if ((byte)PTR_DAT_00316fd8[0x4d1] < bVar2) {
            local_10 = 0x8f;
          }
          else {
            local_10 = 0x9a;
          }
        }
        else if ((byte)PTR_DAT_00316fd8[0x5f1] < bVar2) {
          local_10 = 0xa9;
        }
        else {
          local_10 = 0xbe;
        }
      }
      else if ((byte)PTR_DAT_00316fd8[0x799] < bVar2) {
        if ((byte)PTR_DAT_00316fd8[0x6f9] < bVar2) {
          local_10 = 0xce;
        }
        else {
          local_10 = 0xdf;
        }
      }
      else if ((byte)PTR_DAT_00316fd8[0x829] < bVar2) {
        local_10 = 0xf3;
      }
      else {
        local_10 = 0x105;
      }
    }
    else if ((byte)PTR_DAT_00316fd8[0x1f9] < bVar2) {
      if ((byte)PTR_DAT_00316fd8[0xd1] < bVar2) {
        if ((byte)PTR_DAT_00316fd8[0x59] < bVar2) {
          local_10 = 0;
        }
        else {
          local_10 = 0xb;
        }
      }
      else if ((byte)PTR_DAT_00316fd8[0x179] < bVar2) {
        local_10 = 0x1a;
      }
      else {
        local_10 = 0x2f;
      }
    }
    else if ((byte)PTR_DAT_00316fd8[0x321] < bVar2) {
      if ((byte)PTR_DAT_00316fd8[0x281] < bVar2) {
        local_10 = 0x3f;
      }
      else {
        local_10 = 0x50;
      }
    }
    else if ((byte)PTR_DAT_00316fd8[0x3c9] < bVar2) {
      local_10 = 100;
    }
    else {
      local_10 = 0x79;
    }
    local_18 = PTR_DAT_00316fd8 + (long)local_10 * 8;
    for (; local_10 < 0x133; local_10 = local_10 + 1) {
      if (*local_18 == bVar1) {
        if (local_18[6] == 1) {
          *param_2 = 1;
          return local_18[7];
        }
        if (local_18[1] == bVar2) {
          if (local_18[6] == 2) {
            *param_2 = 2;
            return local_18[7];
          }
          if (param_1[2] == local_18[2]) {
            if (local_18[6] == 3) {
              *param_2 = 3;
              return local_18[7];
            }
            if (param_1[3] == local_18[3]) {
              if (local_18[6] == 4) {
                *param_2 = 4;
                return local_18[7];
              }
              if (param_1[4] == local_18[4]) {
                if (local_18[6] == 5) {
                  *param_2 = 5;
                  return local_18[7];
                }
                if ((param_1[5] == local_18[5]) && (local_18[6] == 6)) {
                  *param_2 = 6;
                  return local_18[7];
                }
              }
            }
          }
        }
      }
      local_18 = local_18 + 8;
    }
    *param_2 = 1;
  }
  return 0;
}


//===== FUN_00103faf @ 00103faf size=138 =====

int FUN_00103faf(char *param_1)

{
  char *local_18;
  int local_c;
  
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    local_18 = PTR_DAT_00316fb0 + 0x32c;
    for (local_c = 0xcb; -1 < local_c; local_c = local_c + -1) {
      if ((*param_1 == *local_18) && (param_1[1] == local_18[1])) {
        return local_c;
      }
      local_18 = local_18 + -4;
    }
  }
  return 0;
}


//===== FUN_00104039 @ 00104039 size=36 =====

undefined * FUN_00104039(byte param_1)

{
  return PTR_DAT_00316fb0 + (long)(int)(uint)param_1 * 4;
}


//===== FUN_0010405d @ 0010405d size=35 =====

undefined8 FUN_0010405d(byte param_1)

{
  undefined8 uVar1;
  
  if ((param_1 < 2) || (9 < param_1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


//===== FUN_00104080 @ 00104080 size=35 =====

undefined8 FUN_00104080(byte param_1)

{
  undefined8 uVar1;
  
  if ((param_1 < 6) || (9 < param_1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


//===== FUN_001040a3 @ 001040a3 size=35 =====

undefined8 FUN_001040a3(byte param_1)

{
  undefined8 uVar1;
  
  if ((param_1 < 0xac) || (0xbc < param_1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


//===== FUN_001040c6 @ 001040c6 size=35 =====

undefined8 FUN_001040c6(byte param_1)

{
  undefined8 uVar1;
  
  if ((param_1 < 0x99) || (0xab < param_1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


//===== FUN_001040e9 @ 001040e9 size=38 =====

byte FUN_001040e9(byte param_1)

{
  return PTR_DAT_00316fb0[(long)(int)(uint)param_1 * 4 + 2] & 0x80;
}


//===== FUN_0010410f @ 0010410f size=77 =====

undefined8 FUN_0010410f(char param_1)

{
  undefined8 uVar1;
  
  if ((((((param_1 == '\n') || (param_1 == '\v')) || (param_1 == '\f')) ||
       ((param_1 == '\r' || (param_1 == '\x0e')))) ||
      ((param_1 == -0x6a || ((param_1 == -0x37 || (param_1 == -0x36)))))) || (param_1 == -0x35)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


//===== FUN_0010415c @ 0010415c size=188 =====

ulong FUN_0010415c(byte param_1)

{
  ulong uVar1;
  
  switch(param_1) {
  case 0xac:
    uVar1 = 0xffffff99;
    break;
  case 0xad:
    uVar1 = 0xffffff9a;
    break;
  case 0xae:
    uVar1 = 0xffffff9b;
    break;
  case 0xaf:
    uVar1 = 0xffffff9c;
    break;
  case 0xb0:
    uVar1 = 0xffffff9d;
    break;
  case 0xb1:
    uVar1 = 0xffffff9e;
    break;
  case 0xb2:
    uVar1 = 0xffffff9f;
    break;
  case 0xb3:
    uVar1 = 0xffffffa0;
    break;
  case 0xb4:
    uVar1 = 0xffffffa1;
    break;
  case 0xb5:
    uVar1 = 0xffffffa2;
    break;
  case 0xb6:
    uVar1 = 0xffffffa3;
    break;
  case 0xb7:
    uVar1 = 0xffffffa4;
    break;
  case 0xb8:
    uVar1 = 0xffffffa5;
    break;
  case 0xb9:
    uVar1 = 0xffffffa6;
    break;
  case 0xba:
    uVar1 = 0xffffffa7;
    break;
  case 0xbb:
    uVar1 = 0xffffffa8;
    break;
  case 0xbc:
    uVar1 = 0xffffffa9;
    break;
  default:
    uVar1 = (ulong)param_1;
  }
  return uVar1;
}


//===== FUN_00104218 @ 00104218 size=188 =====

ulong FUN_00104218(byte param_1)

{
  ulong uVar1;
  
  switch(param_1) {
  case 0xac:
    uVar1 = 0x10;
    break;
  case 0xad:
    uVar1 = 0x11;
    break;
  case 0xae:
    uVar1 = 0x15;
    break;
  case 0xaf:
    uVar1 = 0x16;
    break;
  case 0xb0:
    uVar1 = 0x1c;
    break;
  case 0xb1:
    uVar1 = 0x1d;
    break;
  case 0xb2:
    uVar1 = 0x24;
    break;
  case 0xb3:
    uVar1 = 0xffffff91;
    break;
  case 0xb4:
    uVar1 = 0x4b;
    break;
  case 0xb5:
    uVar1 = 0x4c;
    break;
  case 0xb6:
    uVar1 = 0x57;
    break;
  case 0xb7:
    uVar1 = 0x59;
    break;
  case 0xb8:
    uVar1 = 0x5c;
    break;
  case 0xb9:
    uVar1 = 0x5e;
    break;
  case 0xba:
    uVar1 = 0xffffff8c;
    break;
  case 0xbb:
    uVar1 = 0xffffff8e;
    break;
  case 0xbc:
    uVar1 = 0xffffff93;
    break;
  default:
    uVar1 = (ulong)param_1;
  }
  return uVar1;
}


//===== FUN_001042d4 @ 001042d4 size=128 =====

undefined1 FUN_001042d4(undefined1 param_1)

{
  switch(param_1) {
  case 0xbd:
    param_1 = 0x36;
    break;
  case 0xbe:
    param_1 = 0x37;
    break;
  case 0xbf:
    param_1 = 0x38;
    break;
  case 0xc0:
    param_1 = 0x39;
    break;
  case 0xc1:
    param_1 = 0x3a;
    break;
  case 0xc2:
    param_1 = 0x75;
    break;
  case 0xc3:
    param_1 = 0x76;
    break;
  case 0xc4:
    param_1 = 0x77;
    break;
  case 0xc5:
    param_1 = 0x78;
  }
  return param_1;
}


//===== FUN_00104354 @ 00104354 size=128 =====

undefined1 FUN_00104354(undefined1 param_1)

{
  switch(param_1) {
  case 0xbd:
    param_1 = 0x31;
    break;
  case 0xbe:
    param_1 = 0x32;
    break;
  case 0xbf:
    param_1 = 0x33;
    break;
  case 0xc0:
    param_1 = 0x34;
    break;
  case 0xc1:
    param_1 = 0x35;
    break;
  case 0xc2:
    param_1 = 0x71;
    break;
  case 0xc3:
    param_1 = 0x72;
    break;
  case 0xc4:
    param_1 = 0x73;
    break;
  case 0xc5:
    param_1 = 0x74;
  }
  return param_1;
}


//===== FUN_001043d4 @ 001043d4 size=36 =====

byte FUN_001043d4(byte param_1)

{
  return PTR_DAT_00316fb0[(long)(int)(uint)param_1 * 4 + 2] & 0x7f;
}


//===== FUN_001043f8 @ 001043f8 size=33 =====

undefined1 FUN_001043f8(byte param_1)

{
  return PTR_DAT_00316fb0[(long)(int)(uint)param_1 * 4 + 3];
}


//===== FUN_0010441c @ 0010441c size=41 =====

void FUN_0010441c(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  FUN_00104445(param_1);
  return;
}


//===== FUN_00104445 @ 00104445 size=30 =====

void FUN_00104445(undefined8 *param_1)

{
  *(undefined2 *)(param_1 + 1) = 0;
  *(undefined1 *)*param_1 = 0;
  return;
}


//===== FUN_00104463 @ 00104463 size=80 =====

undefined8 FUN_00104463(long *param_1,undefined1 param_2)

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
    uVar2 = 200;
  }
  return uVar2;
}


//===== FUN_001044b3 @ 001044b3 size=100 =====

undefined8 FUN_001044b3(long *param_1,char *param_2)

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
  return 200;
}


//===== FUN_00104517 @ 00104517 size=127 =====

int FUN_00104517(undefined8 param_1,char *param_2)

{
  int iVar1;
  char *local_28;
  int local_14;
  undefined4 local_10;
  char local_9;
  
  local_28 = param_2;
  if (param_2 != (char *)0x0) {
    for (; *local_28 != '\0'; local_28 = local_28 + local_14) {
      local_9 = FUN_00103be4(local_28,&local_14);
      if (local_9 == '\0') {
        return 0x69;
      }
      iVar1 = FUN_00104463(param_1,local_9);
      if (iVar1 != 0) {
        return iVar1;
      }
      local_10 = 0;
    }
  }
  return 0;
}


//===== FUN_00104596 @ 00104596 size=231 =====

void FUN_00104596(long param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = FUN_0010467d(param_1,*(short *)(param_1 + 8) + -1);
  if ((-1 < iVar1) && (iVar2 = FUN_0010467d(param_1,iVar1 + -2), -1 < iVar2)) {
    if ((param_2 == 1) &&
       (iVar3 = FUN_001046f2(param_1,iVar1,(int)*(short *)(param_1 + 8),1), iVar3 < 0)) {
      FUN_0010473d(param_1,iVar1 + -1);
    }
    else {
      FUN_0010473d(param_1,iVar1 + -1);
      uVar4 = FUN_001046f2(param_1,iVar2,iVar1,1);
      FUN_0010473d(param_1,uVar4);
    }
  }
  return;
}


//===== FUN_0010467d @ 0010467d size=117 =====

int FUN_0010467d(long *param_1,int param_2)

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


//===== FUN_001046f2 @ 001046f2 size=75 =====

int FUN_001046f2(long *param_1,int param_2,int param_3,char param_4)

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


//===== FUN_0010473d @ 0010473d size=124 =====

void FUN_0010473d(long *param_1,int param_2)

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


//===== FUN_001047b9 @ 001047b9 size=155 =====

void FUN_001047b9(long *param_1,int param_2,undefined1 param_3)

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


//===== FUN_00104854 @ 00104854 size=144 =====

void FUN_00104854(long param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0010467d(param_1,*(short *)(param_1 + 8) + -2);
  if (-1 < iVar1) {
    uVar2 = FUN_001046f2(param_1,iVar1,(int)*(short *)(param_1 + 8),1);
    FUN_0010473d(param_1,uVar2);
    if (param_2 != 0) {
      FUN_001047b9(param_1,iVar1 + param_2,1);
    }
  }
  return;
}


//===== FUN_001048e4 @ 001048e4 size=19 =====

int FUN_001048e4(long param_1)

{
  return (int)*(short *)(param_1 + 8);
}


//===== FUN_001048f7 @ 001048f7 size=39 =====

void FUN_001048f7(long *param_1,int param_2,undefined1 param_3)

{
  *(undefined1 *)(*param_1 + (long)param_2) = param_3;
  return;
}


//===== FUN_0010491e @ 0010491e size=59 =====

undefined1 FUN_0010491e(long *param_1,int param_2)

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


//===== FUN_00104959 @ 00104959 size=153 =====

void FUN_00104959(undefined8 param_1)

{
  int iVar1;
  undefined4 local_10;
  undefined1 local_a;
  undefined1 local_9;
  
  local_9 = 8;
  local_10 = 0;
  while( true ) {
    iVar1 = FUN_001048e4(param_1);
    if (iVar1 <= local_10) break;
    local_a = FUN_0010491e(param_1,local_10);
    if ((0xbc < local_a) && (local_a < 0xc6)) {
      iVar1 = FUN_0010405d(local_9);
      if (iVar1 == 0) {
        local_a = FUN_00104354(local_a);
      }
      else {
        local_a = FUN_001042d4(local_a);
      }
      FUN_001048f7(param_1,local_10,local_a);
    }
    local_9 = local_a;
    local_10 = local_10 + 1;
  }
  return;
}


//===== FUN_001049f2 @ 001049f2 size=441 =====

void FUN_001049f2(undefined8 param_1)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  
  local_9 = '\b';
  local_14 = 0;
  local_18 = 0;
  local_10 = 0;
  while( true ) {
    iVar1 = FUN_001048e4(param_1);
    if (iVar1 <= local_10) break;
    local_a = FUN_0010491e(param_1,local_10);
    if (local_a == '\x01') {
      local_18 = local_14;
    }
    else {
      iVar1 = FUN_0010405d(local_a);
      if (iVar1 == 0) {
        iVar1 = FUN_001040a3(local_a);
        if (iVar1 != 0) {
          local_b = FUN_0010491e(param_1,local_10 + 1);
          iVar1 = FUN_001040c6(local_9);
          if (iVar1 == 0) {
            if ((local_b == 7) || (local_b == 6)) {
              local_a = FUN_00104218(local_a);
            }
            else if ((local_b == 8) || (local_b == 9)) {
              if ((local_14 == 0) || (local_18 == 0)) {
                local_a = FUN_00104218(local_a);
              }
              else {
                local_a = FUN_0010415c(local_a);
              }
            }
            else {
              local_1c = 0;
              while ((local_b != 0 && (local_b < 10))) {
                local_b = FUN_0010491e(param_1,local_10 + 1 + local_1c);
                local_1c = local_1c + 1;
              }
              iVar1 = FUN_001040e9(local_b);
              if (iVar1 == 0) {
                local_a = FUN_00104218(local_a);
              }
              else {
                local_a = FUN_0010415c(local_a);
              }
            }
          }
          else {
            local_a = FUN_00104218(local_a);
          }
          FUN_001048f7(param_1,local_10,local_a);
        }
        local_14 = local_14 + 1;
        local_9 = local_a;
      }
      else {
        local_14 = 0;
        local_18 = 0;
        local_9 = local_a;
      }
    }
    local_10 = local_10 + 1;
  }
  return;
}


//===== FUN_00104bab @ 00104bab size=390 =====

void FUN_00104bab(undefined8 param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 local_14;
  int local_10;
  
  local_14 = 0;
  for (local_10 = 0; iVar2 = FUN_001048e4(param_1), local_10 < iVar2; local_10 = local_10 + 1) {
    bVar1 = FUN_0010491e(param_1,local_10);
    if (bVar1 == 0x98) {
      switch(local_14) {
      default:
        FUN_001048f7(param_1,local_10,0x97);
        break;
      case 1:
        FUN_001048f7(param_1,local_10,10);
        break;
      case 2:
        FUN_001048f7(param_1,local_10,0xb);
        break;
      case 3:
        FUN_001048f7(param_1,local_10,0xc);
        break;
      case 4:
        FUN_001048f7(param_1,local_10,0xd);
        break;
      case 5:
        FUN_001048f7(param_1,local_10,0xe);
        break;
      case 6:
        FUN_001048f7(param_1,local_10,0x96);
        break;
      case 0xc:
        FUN_001048f7(param_1,local_10,0xaa);
        break;
      case 0xd:
        FUN_001048f7(param_1,local_10,0xab);
      }
    }
    else if ((9 < bVar1) && (bVar1 < 0xc6)) {
      local_14 = FUN_001043f8(bVar1);
    }
  }
  return;
}


//===== FUN_00104d31 @ 00104d31 size=406 =====

void FUN_00104d31(undefined8 param_1)

{
  byte bVar1;
  int local_14;
  int local_10;
  
  local_14 = 0;
  local_10 = FUN_001048e4(param_1);
  while (local_10 = local_10 + -1, -1 < local_10) {
    bVar1 = FUN_0010491e(param_1,local_10);
    if (bVar1 == 0x97) {
      if (local_14 == 10) {
        FUN_001048f7(param_1,local_10,200);
      }
      else if (local_14 == 0xb) {
        FUN_001048f7(param_1,local_10,199);
      }
      else {
        FUN_001048f7(param_1,local_10,0xc6);
      }
    }
    else if (bVar1 == 0x96) {
      if (((((local_14 == 0xe) || (local_14 == 0xf)) || (local_14 == 0x1b)) ||
          ((local_14 == 0x1c || (local_14 == 0x1f)))) || (local_14 == 0x20)) {
        FUN_001048f7(param_1,local_10,0xca);
      }
      else if (((((local_14 == 0x11) || (local_14 == 0x12)) ||
                ((local_14 == 0x18 ||
                 (((local_14 == 0x1d || (local_14 == 0x1e)) || (local_14 == 0x21)))))) ||
               ((local_14 == 0x22 || (local_14 == 0xb)))) ||
              ((local_14 == 10 ||
               (((local_14 == 0x23 || (local_14 == 0x24)) ||
                ((local_14 == 0x25 || (local_14 == 0x28)))))))) {
        FUN_001048f7(param_1,local_10,0xcb);
      }
      else {
        FUN_001048f7(param_1,local_10,0xc9);
      }
      local_14 = 6;
    }
    else if ((9 < bVar1) && (bVar1 < 0xc6)) {
      local_14 = FUN_001043d4(bVar1);
    }
  }
  return;
}


//===== FUN_00104ec7 @ 00104ec7 size=70 =====

void FUN_00104ec7(undefined8 param_1)

{
  int iVar1;
  undefined4 local_10;
  
  local_10 = 0;
  while( true ) {
    iVar1 = FUN_001048e4(param_1);
    if (iVar1 <= local_10) break;
    FUN_0010491e(param_1,local_10);
    local_10 = local_10 + 1;
  }
  return;
}


//===== FUN_00104f38 @ 00104f38 size=45 =====

void FUN_00104f38(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  *(undefined2 *)((long)param_1 + 10) = 0x400;
  *(undefined2 *)(param_1 + 1) = 0;
  return;
}


//===== FUN_00104f65 @ 00104f65 size=136 =====

int FUN_00104f65(long *param_1,undefined2 param_2,undefined2 param_3)

{
  undefined2 *puVar1;
  int iVar2;
  
  if (*(ushort *)(param_1 + 1) < *(ushort *)((long)param_1 + 10)) {
    puVar1 = (undefined2 *)(*param_1 + (ulong)*(ushort *)(param_1 + 1) * 4);
    puVar1[1] = param_2;
    *puVar1 = param_3;
    *(short *)(param_1 + 1) = (short)param_1[1] + 1;
    iVar2 = *(ushort *)(param_1 + 1) - 1;
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}


//===== FUN_00104fed @ 00104fed size=20 =====

void FUN_00104fed(long param_1)

{
  *(undefined2 *)(param_1 + 8) = 0;
  return;
}


//===== FUN_00105001 @ 00105001 size=55 =====

long FUN_00105001(long *param_1,ushort param_2)

{
  long lVar1;
  
  if (param_2 < *(ushort *)(param_1 + 1)) {
    lVar1 = *param_1 + (ulong)param_2 * 4;
  }
  else {
    lVar1 = 0;
  }
  return lVar1;
}


//===== FUN_00105038 @ 00105038 size=18 =====

undefined2 FUN_00105038(long param_1)

{
  return *(undefined2 *)(param_1 + 8);
}


//===== FUN_0010504a @ 0010504a size=45 =====

void FUN_0010504a(long *param_1,int param_2)

{
  FUN_00105136(*param_1 + (long)param_2 * 4);
  return;
}


//===== FUN_00105077 @ 00105077 size=57 =====

void FUN_00105077(long *param_1,int param_2,undefined2 param_3)

{
  FUN_0010514b(*param_1 + (long)param_2 * 4,param_3);
  return;
}


//===== FUN_001050b0 @ 001050b0 size=45 =====

void FUN_001050b0(long *param_1,int param_2)

{
  FUN_0010517b(*param_1 + (long)param_2 * 4);
  return;
}


//===== FUN_001050dd @ 001050dd size=57 =====

void FUN_001050dd(long *param_1,int param_2,undefined2 param_3)

{
  FUN_00105190(*param_1 + (long)param_2 * 4,param_3);
  return;
}


//===== FUN_00105116 @ 00105116 size=32 =====

undefined2 FUN_00105116(long param_1)

{
  undefined2 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined2 *)(param_1 + 2);
  }
  return uVar1;
}


//===== FUN_00105136 @ 00105136 size=21 =====

ushort FUN_00105136(ushort *param_1)

{
  return *param_1 & 0x3fff;
}


//===== FUN_0010514b @ 0010514b size=48 =====

void FUN_0010514b(ushort *param_1,ushort param_2)

{
  *param_1 = *param_1 & 0xc000 | param_2;
  return;
}


//===== FUN_0010517b @ 0010517b size=21 =====

ushort FUN_0010517b(ushort *param_1)

{
  return *param_1 & 0xc000;
}


//===== FUN_00105190 @ 00105190 size=45 =====

void FUN_00105190(ushort *param_1,ushort param_2)

{
  ushort uVar1;
  
  uVar1 = FUN_00105136(param_1);
  *param_1 = uVar1 | param_2;
  return;
}


//===== FUN_001051c0 @ 001051c0 size=25 =====

void FUN_001051c0(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return;
}


//===== FUN_001051d9 @ 001051d9 size=42 =====

void FUN_001051d9(long param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined2 *)(param_1 + 0x10) = 0x280;
  return;
}


//===== FUN_00105203 @ 00105203 size=297 =====

int FUN_00105203(long *param_1,byte param_2)

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
    iVar2 = FUN_00105655(param_1);
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  lVar1 = *param_1 + (long)*(int *)((long)param_1 + 0xc);
  if (param_2 < 10) {
    if (param_2 == 1) {
      *(undefined1 *)(lVar1 + 2) = *(undefined1 *)(lVar1 + 1);
    }
    else {
      *(byte *)(lVar1 + 3) = param_2;
      FUN_001056d0(param_1);
    }
  }
  else {
    *(byte *)(lVar1 + 8 + (long)(int)(uint)*(byte *)(lVar1 + 1) * 4) = param_2;
    *(undefined2 *)(lVar1 + 6 + (long)(int)(uint)*(byte *)(lVar1 + 1) * 4) = 0;
    *(char *)(lVar1 + 1) = *(char *)(lVar1 + 1) + '\x01';
    *(int *)(param_1 + 1) = (int)param_1[1] + 4;
    if (0x6800 < (int)param_1[1]) {
      return 0xca;
    }
  }
  return 0;
}


//===== FUN_0010532c @ 0010532c size=21 =====

void FUN_0010532c(long param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}


//===== FUN_00105341 @ 00105341 size=42 =====

void FUN_00105341(undefined8 *param_1,int param_2)

{
  *(int *)((long)param_1 + 0xc) = param_2 - (int)*param_1;
  return;
}


//===== FUN_0010536b @ 0010536b size=82 =====

long FUN_0010536b(long *param_1)

{
  long lVar1;
  
  if (*(int *)((long)param_1 + 0xc) < (int)param_1[1]) {
    lVar1 = *param_1 + (long)*(int *)((long)param_1 + 0xc);
    FUN_001056d0(param_1);
  }
  else {
    lVar1 = 0;
  }
  return lVar1;
}


//===== FUN_001053bd @ 001053bd size=43 =====

char FUN_001053bd(char *param_1)

{
  char cVar1;
  
  if ((param_1 == (char *)0x0) || (*param_1 != -0x55)) {
    cVar1 = '\b';
  }
  else {
    cVar1 = param_1[3];
  }
  return cVar1;
}


//===== FUN_001053e8 @ 001053e8 size=205 =====

char FUN_001053e8(long *param_1,char *param_2)

{
  char *local_28;
  
  if ((((param_2 != (char *)0x0) && (*param_2 == -0x55)) && ((char *)*param_1 <= param_2)) &&
     (local_28 = param_2, param_2 < (char *)(*param_1 + (long)(int)param_1[1]))) {
    do {
      if (local_28[3] != '\x03') {
        return local_28[3];
      }
      local_28 = local_28 + (long)(int)((byte)local_28[1] - 1) * 4 + 10;
    } while (((char *)*param_1 <= local_28) &&
            (local_28 < (char *)(*param_1 + (long)(int)param_1[1])));
  }
  return '\b';
}


//===== FUN_001054b5 @ 001054b5 size=374 =====

long FUN_001054b5(long *param_1,long param_2,long param_3)

{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  int local_10;
  
  uVar2 = *(undefined4 *)((long)param_1 + 0xc);
  *(int *)((long)param_1 + 0xc) = (int)param_1[1];
  lVar1 = *param_1 + (long)*(int *)((long)param_1 + 0xc);
  for (local_10 = 0; local_10 < (int)(uint)*(byte *)(param_2 + 1); local_10 = local_10 + 1) {
    iVar3 = FUN_00105203(param_1,*(undefined1 *)(param_2 + 8 + (long)local_10 * 4));
    if (iVar3 != 0) {
      *(undefined4 *)((long)param_1 + 0xc) = uVar2;
      return 0;
    }
  }
  local_10 = 0;
  while( true ) {
    if ((int)(uint)*(byte *)(param_3 + 1) <= local_10) {
      if (*(char *)(param_2 + 2) == '\0') {
        if (*(char *)(param_3 + 2) == '\0') {
          *(undefined1 *)(lVar1 + 2) = 0;
        }
        else {
          *(char *)(lVar1 + 2) = *(char *)(param_2 + 1) + *(char *)(param_3 + 2);
        }
      }
      else {
        *(undefined1 *)(lVar1 + 2) = *(undefined1 *)(param_2 + 2);
      }
      *(undefined2 *)(lVar1 + 4) = *(undefined2 *)(param_2 + 4);
      *(undefined1 *)(lVar1 + 3) = *(undefined1 *)(param_3 + 3);
      *(undefined4 *)((long)param_1 + 0xc) = uVar2;
      return lVar1;
    }
    iVar3 = FUN_00105203(param_1,*(undefined1 *)(param_3 + 8 + (long)local_10 * 4));
    if (iVar3 != 0) break;
    local_10 = local_10 + 1;
  }
  *(undefined4 *)((long)param_1 + 0xc) = uVar2;
  return 0;
}


//===== FUN_0010562b @ 0010562b size=42 =====

void FUN_0010562b(undefined8 *param_1,int param_2)

{
  *(int *)(param_1 + 1) = param_2 - (int)*param_1;
  return;
}


//===== FUN_00105655 @ 00105655 size=123 =====

undefined8 FUN_00105655(long *param_1)

{
  undefined1 *puVar1;
  undefined8 uVar2;
  
  puVar1 = (undefined1 *)(*param_1 + (long)*(int *)((long)param_1 + 0xc));
  *puVar1 = 0xab;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 8;
  *(undefined2 *)(puVar1 + 4) = 0x400;
  *(int *)(param_1 + 1) = (int)param_1[1] + 6;
  if ((int)param_1[1] < 0x6801) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xca;
  }
  return uVar2;
}


//===== FUN_001056d0 @ 001056d0 size=80 =====

void FUN_001056d0(long *param_1)

{
  *(uint *)((long)param_1 + 0xc) =
       *(int *)((long)param_1 + 0xc) +
       (*(byte *)(*param_1 + (long)*(int *)((long)param_1 + 0xc) + 1) - 1) * 4 + 10;
  return;
}


//===== FUN_00105720 @ 00105720 size=64 =====

void FUN_00105720(undefined8 *param_1,undefined8 param_2,undefined2 param_3)

{
  *param_1 = param_2;
  *(undefined2 *)(param_1 + 1) = param_3;
  *(undefined2 *)((long)param_1 + 10) = 0;
  *(undefined4 *)((long)param_1 + 0xc) = 0;
  return;
}


//===== FUN_00105760 @ 00105760 size=92 =====

undefined8 FUN_00105760(long *param_1,undefined2 param_2)

{
  ushort uVar1;
  undefined8 uVar2;
  
  uVar1 = *(ushort *)((long)param_1 + 10);
  *(undefined2 *)(*param_1 + (ulong)uVar1 * 2) = param_2;
  *(ushort *)((long)param_1 + 10) = uVar1 + 1;
  if (*(ushort *)((long)param_1 + 10) < *(ushort *)(param_1 + 1)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


//===== FUN_001057bc @ 001057bc size=28 =====

undefined8 FUN_001057bc(long param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  return 0;
}


//===== FUN_001057d8 @ 001057d8 size=31 =====

int FUN_001057d8(long param_1)

{
  return *(int *)(param_1 + 0xc) + (uint)*(ushort *)(param_1 + 10);
}


//===== FUN_001057f7 @ 001057f7 size=302 =====

ushort FUN_001057f7(long *param_1,ushort param_2,long param_3)

{
  ushort local_c;
  ushort local_a;
  
  if (*(ushort *)((long)param_1 + 10) < param_2) {
    for (local_a = 0; local_a < *(ushort *)((long)param_1 + 10); local_a = local_a + 1) {
      *(undefined2 *)((ulong)local_a * 2 + param_3) = *(undefined2 *)(*param_1 + (ulong)local_a * 2)
      ;
    }
    *(undefined2 *)((long)param_1 + 10) = 0;
    while ((local_a < param_2 && (*(int *)((long)param_1 + 0xc) != 0))) {
      *(undefined2 *)((ulong)local_a * 2 + param_3) = 0;
      *(int *)((long)param_1 + 0xc) = *(int *)((long)param_1 + 0xc) + -1;
      local_a = local_a + 1;
    }
    for (local_c = local_a; local_c < param_2; local_c = local_c + 1) {
      *(undefined2 *)((ulong)local_c * 2 + param_3) = 0;
    }
  }
  else {
    for (local_a = 0; local_a < param_2; local_a = local_a + 1) {
      *(undefined2 *)((ulong)local_a * 2 + param_3) = *(undefined2 *)(*param_1 + (ulong)local_a * 2)
      ;
    }
    FUN_00105925(param_1,param_2);
    local_a = param_2;
  }
  return local_a;
}


//===== FUN_00105925 @ 00105925 size=109 =====

void FUN_00105925(long *param_1,ushort param_2)

{
  undefined2 local_c;
  undefined2 local_a;
  
  local_a = 0;
  for (local_c = param_2; local_c < *(ushort *)((long)param_1 + 10); local_c = local_c + 1) {
    *(undefined2 *)(*param_1 + (ulong)local_a * 2) = *(undefined2 *)(*param_1 + (ulong)local_c * 2);
    local_a = local_a + 1;
  }
  *(ushort *)((long)param_1 + 10) = local_a;
  return;
}


//===== FUN_00105994 @ 00105994 size=26 =====

void FUN_00105994(undefined8 param_1)

{
  FUN_001059ae(param_1);
  return;
}


//===== FUN_001059ae @ 001059ae size=96 =====

void FUN_001059ae(undefined2 *param_1)

{
  int local_c;
  
  param_1[0x12] = 0;
  for (local_c = 0; local_c < 8; local_c = local_c + 1) {
    param_1[(long)local_c + 1] = 0;
    param_1[(long)local_c + 10] = 0;
  }
  param_1[9] = 0;
  *param_1 = 0;
  return;
}


//===== FUN_00105a0e @ 00105a0e size=69 =====

void FUN_00105a0e(ushort *param_1,ushort param_2,undefined8 param_3)

{
  *param_1 = param_2 & 1;
  if ((param_2 & 2) != 0) {
    FUN_00105bb9(param_3,param_1 + 1);
  }
  return;
}


//===== FUN_00105a53 @ 00105a53 size=358 =====

short FUN_00105a53(short *param_1,int param_2)

{
  short *local_28;
  short *local_20;
  int local_18;
  short local_12;
  
  if (*param_1 == 0) {
    local_12 = 0;
  }
  else {
    local_18 = param_1[1] * param_2;
    local_20 = param_1 + 10;
    for (local_28 = param_1 + (9 - (long)param_1[0x12]); local_28 <= param_1 + 9;
        local_28 = local_28 + 1) {
      local_18 = local_18 - (int)*local_28 * (int)*local_20;
      local_20 = local_20 + 1;
    }
    local_28 = param_1 + 2;
    for (; local_20 < param_1 + 0x12; local_20 = local_20 + 1) {
      local_18 = local_18 - (int)*local_28 * (int)*local_20;
      local_28 = local_28 + 1;
    }
    if (local_18 < 0x7fff800) {
      if (local_18 < -0x80007ff) {
        local_12 = -0x8000;
      }
      else {
        local_12 = (short)((long)local_18 + 0x800 >> 0xc);
      }
    }
    else {
      local_12 = 0x7fff;
    }
    param_1[(long)(int)param_1[0x12] + 10] = local_12;
    if (param_1[0x12] == 0) {
      param_1[0x12] = 7;
    }
    else {
      param_1[0x12] = param_1[0x12] + -1;
    }
  }
  return local_12;
}


//===== FUN_00105bb9 @ 00105bb9 size=350 =====

void FUN_00105bb9(long param_1,undefined2 *param_2)

{
  int local_48 [8];
  int local_28 [5];
  int local_14;
  int local_10;
  uint local_c;
  
  FUN_00105d17(param_1,local_28);
  FUN_00105d17(param_1 + 2,local_48);
  for (local_10 = 4; 0 < local_10; local_10 = local_10 + -1) {
    local_28[local_10] = local_28[local_10] + local_28[local_10 + -1];
    local_48[local_10] = local_48[local_10] - local_48[local_10 + -1];
  }
  *param_2 = 0x1000;
  local_14 = 8;
  for (local_10 = 1; local_10 < 5; local_10 = local_10 + 1) {
    local_c = local_28[local_10] + local_48[local_10];
    param_2[local_10] = (short)((int)local_c >> 0xd);
    if ((local_c & 0x1000) != 0) {
      param_2[local_10] = param_2[local_10] + 1;
    }
    local_c = local_28[local_10] - local_48[local_10];
    param_2[local_14] = (short)((int)local_c >> 0xd);
    if ((local_c & 0x1000) != 0) {
      param_2[local_14] = param_2[local_14] + 1;
    }
    local_14 = local_14 + -1;
  }
  return;
}


//===== FUN_00105d17 @ 00105d17 size=417 =====

void FUN_00105d17(short *param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  uVar3 = *param_1 * -0x400;
  iVar5 = (int)param_1[2];
  iVar6 = (int)param_1[4];
  iVar7 = (int)param_1[6];
  iVar4 = (((int)uVar3 >> 0x10) * iVar5 + ((int)((uVar3 & 0xfffe) * iVar5) >> 0x10)) * -4;
  uVar1 = iVar4 + 0x2000000;
  uVar3 = uVar3 + iVar5 * -0x400;
  uVar1 = uVar3 * 2 +
          (((int)uVar1 >> 0x10) * iVar6 + ((int)((uVar1 & 0xfffe) * iVar6) >> 0x10)) * -4;
  uVar2 = iVar4 + 0x3000000 +
          (((int)uVar3 >> 0x10) * iVar6 + ((int)((uVar3 & 0xfffe) * iVar6) >> 0x10)) * -4;
  uVar3 = uVar3 + iVar6 * -0x400;
  *param_2 = 0x1000000;
  param_2[1] = uVar3 + iVar7 * -0x400;
  param_2[2] = uVar2 + 0x1000000 +
               (((int)uVar3 >> 0x10) * iVar7 + ((int)((uVar3 & 0xfffe) * iVar7) >> 0x10)) * -4;
  param_2[3] = uVar1 + uVar3 +
               (((int)uVar2 >> 0x10) * iVar7 + ((int)((uVar2 & 0xfffe) * iVar7) >> 0x10)) * -4;
  param_2[4] = uVar2 * 2 +
               (((int)uVar1 >> 0x10) * iVar7 + ((int)((uVar1 & 0xfffe) * iVar7) >> 0x10)) * -4;
  return;
}


//===== FUN_00105eb8 @ 00105eb8 size=79 =====

ushort FUN_00105eb8(long *param_1)

{
  ushort uVar1;
  
  if (0x3ff < *(ushort *)(param_1 + 1)) {
    *(undefined2 *)(param_1 + 1) = 0;
  }
  uVar1 = *(ushort *)(*param_1 + (ulong)*(ushort *)(param_1 + 1) * 2);
  *(ushort *)(param_1 + 1) = *(ushort *)(param_1 + 1) + 1;
  return uVar1 ^ 0x3c5a;
}


//===== FUN_00105f07 @ 00105f07 size=35 =====

void FUN_00105f07(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  *(undefined2 *)(param_1 + 1) = 0;
  return;
}


//===== FUN_00105f2a @ 00105f2a size=20 =====

void FUN_00105f2a(long param_1)

{
  *(undefined2 *)(param_1 + 8) = 0;
  return;
}


//===== FUN_00105f40 @ 00105f40 size=237 =====

void FUN_00105f40(long param_1)

{
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(undefined8 *)(param_1 + 0x18) = 0;
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(undefined8 *)(param_1 + 0x48) = 0;
  *(undefined8 *)(param_1 + 0x50) = 0;
  *(undefined8 *)(param_1 + 0x58) = 0;
  *(undefined8 *)(param_1 + 0x60) = 0;
  *(undefined2 *)(param_1 + 0x114) = 0;
  *(undefined2 *)(param_1 + 0x116) = 0;
  *(undefined2 *)(param_1 + 0x118) = 0x80;
  *(undefined1 *)(param_1 + 0x11a) = 1;
  *(undefined1 *)(param_1 + 0x11b) = 1;
  *(undefined1 *)(param_1 + 0x11c) = 1;
  *(undefined1 *)(param_1 + 0x6a) = 0;
  *(undefined1 *)(param_1 + 0x6b) = 0;
  *(undefined1 *)(param_1 + 0xae) = 0xff;
  *(undefined1 *)(param_1 + 0xf3) = 0;
  *(undefined1 *)(param_1 + 0xf2) = 0xff;
  *(undefined1 *)(param_1 + 0x11d) = 0xff;
  *(undefined1 *)(param_1 + 0x11e) = 0xff;
  return;
}


//===== FUN_0010602d @ 0010602d size=802 =====

undefined8 FUN_0010602d(long param_1,short *param_2,int param_3)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  undefined8 uVar4;
  
  if (param_2[1] == -0x55ac) {
    *(short **)(param_1 + 0x10) = param_2 + 2;
    psVar1 = (short *)((long)param_2 + (long)*param_2);
    if ((param_3 != 0) &&
       (iVar3 = FUN_00107b06(param_1,param_2,*(undefined8 *)(param_1 + 0x10)), iVar3 != 0)) {
      return 1000;
    }
    if (psVar1[1] == -0x45a9) {
      *(short **)(param_1 + 0x18) = psVar1 + 2;
      *(undefined8 *)(param_1 + 0x20) = 0;
    }
    else {
      if (psVar1[1] != -0x45af) {
        return 0x3ea;
      }
      *(undefined8 *)(param_1 + 0x18) = 0;
      *(short **)(param_1 + 0x20) = psVar1 + 2;
    }
    psVar1 = (short *)((long)psVar1 + (long)*psVar1);
    if (psVar1[1] == -0x75a9) {
      *(short **)(param_1 + 0x28) = psVar1 + 2;
      *(long *)(param_1 + 0x30) = *(long *)(param_1 + 0x28) + 6;
      *(ulong *)(param_1 + 0x38) =
           *(long *)(param_1 + 0x30) +
           ((ulong)**(byte **)(param_1 + 0x28) + (ulong)*(byte *)(*(long *)(param_1 + 0x28) + 1)) *
           8;
      *(ulong *)(param_1 + 0x40) =
           *(long *)(param_1 + 0x38) + (ulong)*(ushort *)(*(long *)(param_1 + 0x28) + 2) * 4;
      if (*(long *)(param_1 + 0x40) + (ulong)*(ushort *)(*(long *)(param_1 + 0x28) + 4) ==
          (long)*psVar1 + (long)psVar1) {
        psVar1 = (short *)((long)psVar1 + (long)*psVar1);
        if (psVar1[1] == -0x65ac) {
          *(short *)(param_1 + 0x114) = psVar1[2];
          *(short **)(param_1 + 0x48) = psVar1 + 3;
          psVar1 = (short *)((long)psVar1 + (long)*psVar1);
          if (psVar1[1] == -0x15ac) {
            *(short *)(param_1 + 0x118) = psVar1[2];
            *(short **)(param_1 + 0x50) = psVar1 + 3;
            psVar1 = (short *)((long)psVar1 + (long)*psVar1);
            if (psVar1[1] == -0x5ac) {
              *(short **)(param_1 + 0x58) = psVar1 + 2;
              sVar2 = *psVar1;
              if (*(short *)((long)psVar1 + (long)sVar2 + 2) == -0x35ac) {
                *(undefined2 *)(param_1 + 0x116) = *(undefined2 *)((long)psVar1 + (long)sVar2 + 4);
                *(long *)(param_1 + 0x60) = (long)psVar1 + (long)sVar2 + 6;
                uVar4 = 0;
              }
              else {
                uVar4 = 0x3ef;
              }
            }
            else {
              uVar4 = 0x3ee;
            }
          }
          else {
            uVar4 = 0x3ed;
          }
        }
        else {
          uVar4 = 0x3ec;
        }
      }
      else {
        uVar4 = 0x3f0;
      }
    }
    else {
      uVar4 = 0x3eb;
    }
  }
  else {
    uVar4 = 0x3e9;
  }
  return uVar4;
}


//===== FUN_0010634f @ 0010634f size=24 =====

ushort FUN_0010634f(long *param_1)

{
  return *(ushort *)(*param_1 + 6) & 0xf;
}


//===== FUN_00106367 @ 00106367 size=24 =====

ushort FUN_00106367(long *param_1)

{
  return *(ushort *)(*param_1 + 4) & 7;
}


//===== FUN_0010637f @ 0010637f size=35 =====

bool FUN_0010637f(long *param_1)

{
  return (*(ushort *)(*param_1 + 4) & 8) != 0;
}


//===== FUN_001063a2 @ 001063a2 size=2465 =====

void FUN_001063a2(long *param_1)

{
  long lVar1;
  char *pcVar2;
  ushort uVar3;
  short sVar4;
  ushort uVar5;
  char *local_20;
  short *local_18;
  ushort local_a;
  
  *(undefined1 *)((long)param_1 + 0x6a) =
       *(undefined1 *)
        ((long)param_1 + ((long)(int)(*(byte *)((long)param_1 + 0x11a) - 1) + 0x18) * 4 + 10);
  *(undefined1 *)((long)param_1 + 0x6b) =
       *(undefined1 *)
        ((long)param_1 + ((long)(int)(*(byte *)((long)param_1 + 0x11a) - 1) + 0x18) * 4 + 0xb);
  *(undefined2 *)(param_1 + 0xd) = 0;
  *(undefined1 *)((long)param_1 + 0xae) =
       *(undefined1 *)
        ((long)param_1 + ((long)(int)(*(byte *)((long)param_1 + 0x11b) - 1) + 0x28) * 4 + 0xe);
  *(undefined2 *)((long)param_1 + 0xac) = 0;
  *(undefined1 *)((long)param_1 + 0xf3) =
       *(undefined1 *)
        ((long)param_1 + ((long)(int)(*(byte *)((long)param_1 + 0x11c) - 1) + 0x3c) * 4 + 3);
  *(undefined1 *)((long)param_1 + 0xf2) =
       *(undefined1 *)
        ((long)param_1 + ((long)(int)(*(byte *)((long)param_1 + 0x11c) - 1) + 0x3c) * 4 + 2);
  *(undefined2 *)(param_1 + 0x1e) = 0;
  local_18 = (short *)(param_1[7] + (ulong)(*(ushort *)(*param_1 + 6) >> 4) * 4);
  local_20 = (char *)(param_1[8] + (ulong)(*(ushort *)(*param_1 + 4) >> 4));
  sVar4 = FUN_0010634f(param_1);
  if ((sVar4 == 0) || (*local_18 != 0)) {
    *(undefined1 *)((long)param_1 + 0x11a) = 1;
    *(undefined1 *)((long)param_1 + 0x11b) = 1;
  }
  else {
    *(undefined1 *)((long)param_1 + 0x11a) = 0;
    *(undefined1 *)((long)param_1 + 0x11b) = 0;
  }
  local_a = 0;
  while( true ) {
    uVar5 = FUN_0010634f(param_1);
    if (uVar5 <= local_a) break;
    *(short *)((long)param_1 + ((long)(int)(uint)*(byte *)((long)param_1 + 0x11a) + 0x18) * 4 + 8) =
         *local_18;
    *(char *)((long)param_1 + ((long)(int)(uint)*(byte *)((long)param_1 + 0x11a) + 0x18) * 4 + 10) =
         (char)local_18[1];
    *(undefined1 *)
     ((long)param_1 + ((long)(int)(uint)*(byte *)((long)param_1 + 0x11a) + 0x18) * 4 + 0xb) =
         *(undefined1 *)((long)local_18 + 3);
    *(char *)((long)param_1 + 0x11a) = *(char *)((long)param_1 + 0x11a) + '\x01';
    if (*local_20 == -4) {
      if (*(char *)((long)param_1 + 0x11b) == '\0') {
        *(undefined1 *)((long)param_1 + 0x11b) = 1;
      }
      else {
        *(undefined1 *)
         ((long)param_1 + ((long)(int)(uint)*(byte *)((long)param_1 + 0x11b) + 0x28) * 4 + 0xe) =
             *(undefined1 *)
              ((long)param_1 + ((long)(int)(*(byte *)((long)param_1 + 0x11b) - 1) + 0x28) * 4 + 0xe)
        ;
        *(short *)((long)param_1 +
                  ((long)(int)(uint)*(byte *)((long)param_1 + 0x11b) + 0x28) * 4 + 0xc) = *local_18;
        *(char *)((long)param_1 + 0x11b) = *(char *)((long)param_1 + 0x11b) + '\x01';
      }
    }
    else if (*local_20 != -2) {
      if (*local_20 == -3) {
        *(undefined1 *)
         ((long)param_1 + ((long)(int)(uint)*(byte *)((long)param_1 + 0x11b) + 0x28) * 4 + 0xe) =
             *(undefined1 *)(param_1[8] + (ulong)(*(ushort *)(param_1[1] + 4) >> 4));
        *(short *)((long)param_1 +
                  ((long)(int)(uint)*(byte *)((long)param_1 + 0x11b) + 0x28) * 4 + 0xc) = *local_18;
        *(char *)((long)param_1 + 0x11b) = *(char *)((long)param_1 + 0x11b) + '\x01';
      }
      else {
        *(char *)((long)param_1 +
                 ((long)(int)(uint)*(byte *)((long)param_1 + 0x11b) + 0x28) * 4 + 0xe) = *local_20;
        *(short *)((long)param_1 +
                  ((long)(int)(uint)*(byte *)((long)param_1 + 0x11b) + 0x28) * 4 + 0xc) = *local_18;
        *(char *)((long)param_1 + 0x11b) = *(char *)((long)param_1 + 0x11b) + '\x01';
      }
    }
    local_a = local_a + 1;
    local_18 = local_18 + 2;
    local_20 = local_20 + 1;
  }
  sVar4 = FUN_00106367(param_1);
  if ((sVar4 == 0) || (*local_18 != 0)) {
    *(undefined1 *)((long)param_1 + 0x11c) = 1;
  }
  else {
    *(undefined1 *)((long)param_1 + 0x11c) = 0;
  }
  local_a = 0;
  while( true ) {
    uVar5 = FUN_00106367(param_1);
    if (uVar5 <= local_a) break;
    *(short *)((long)param_1 + ((long)(int)(uint)*(byte *)((long)param_1 + 0x11c) + 0x3c) * 4) =
         *local_18;
    *(char *)((long)param_1 + ((long)(int)(uint)*(byte *)((long)param_1 + 0x11c) + 0x3c) * 4 + 3) =
         (char)local_18[1];
    if (*local_20 == -4) {
      if (*(char *)((long)param_1 + 0x11c) != '\0') {
        *(undefined1 *)
         ((long)param_1 + ((long)(int)(uint)*(byte *)((long)param_1 + 0x11c) + 0x3c) * 4 + 2) =
             *(undefined1 *)
              ((long)param_1 + ((long)(int)(*(byte *)((long)param_1 + 0x11c) - 1) + 0x3c) * 4 + 2);
      }
    }
    else if (*local_20 == -3) {
      *(undefined1 *)
       ((long)param_1 + ((long)(int)(uint)*(byte *)((long)param_1 + 0x11c) + 0x3c) * 4 + 2) =
           *(undefined1 *)
            (param_1[8] +
            (ulong)(*(ushort *)(param_1[1] + 4) >> 4) + (ulong)(*(ushort *)(param_1[1] + 6) & 0xf));
    }
    else {
      *(char *)((long)param_1 + ((long)(int)(uint)*(byte *)((long)param_1 + 0x11c) + 0x3c) * 4 + 2)
           = *local_20;
    }
    local_a = local_a + 1;
    local_18 = local_18 + 2;
    local_20 = local_20 + 1;
    *(char *)((long)param_1 + 0x11c) = *(char *)((long)param_1 + 0x11c) + '\x01';
  }
  if (*(short *)((long)param_1 + ((long)(int)(*(byte *)((long)param_1 + 0x11a) - 1) + 0x18) * 4 + 8)
      != *(short *)(*param_1 + 2)) {
    lVar1 = param_1[7] + (ulong)(*(ushort *)(param_1[1] + 6) >> 4) * 4;
    *(undefined2 *)
     ((long)param_1 + ((long)(int)(uint)*(byte *)((long)param_1 + 0x11a) + 0x18) * 4 + 8) =
         *(undefined2 *)(*param_1 + 2);
    *(undefined1 *)
     ((long)param_1 + ((long)(int)(uint)*(byte *)((long)param_1 + 0x11a) + 0x18) * 4 + 10) =
         *(undefined1 *)(lVar1 + 2);
    *(undefined1 *)
     ((long)param_1 + ((long)(int)(uint)*(byte *)((long)param_1 + 0x11a) + 0x18) * 4 + 0xb) =
         *(undefined1 *)(lVar1 + 3);
    *(char *)((long)param_1 + 0x11a) = *(char *)((long)param_1 + 0x11a) + '\x01';
  }
  if (*(short *)((long)param_1 +
                ((long)(int)(*(byte *)((long)param_1 + 0x11b) - 1) + 0x28) * 4 + 0xc) !=
      *(short *)(*param_1 + 2)) {
    *(undefined1 *)
     ((long)param_1 + ((long)(int)(uint)*(byte *)((long)param_1 + 0x11b) + 0x28) * 4 + 0xe) =
         *(undefined1 *)(param_1[8] + (ulong)(*(ushort *)(param_1[1] + 4) >> 4));
    *(undefined2 *)
     ((long)param_1 + ((long)(int)(uint)*(byte *)((long)param_1 + 0x11b) + 0x28) * 4 + 0xc) =
         *(undefined2 *)(*param_1 + 2);
    *(char *)((long)param_1 + 0x11b) = *(char *)((long)param_1 + 0x11b) + '\x01';
  }
  if (*(short *)((long)param_1 + ((long)(int)(*(byte *)((long)param_1 + 0x11c) - 1) + 0x3c) * 4) !=
      *(short *)(*param_1 + 2)) {
    if ((*(ushort *)(param_1[1] + 4) & 7) == 0) {
      *(undefined2 *)
       ((long)param_1 + ((long)(int)(uint)*(byte *)((long)param_1 + 0x11c) + 0x3c) * 4) =
           *(undefined2 *)(*param_1 + 2);
      *(undefined1 *)
       ((long)param_1 + ((long)(int)(uint)*(byte *)((long)param_1 + 0x11c) + 0x3c) * 4 + 2) = 0xff;
      *(undefined1 *)
       ((long)param_1 + ((long)(int)(uint)*(byte *)((long)param_1 + 0x11c) + 0x3c) * 4 + 3) = 0;
      *(char *)((long)param_1 + 0x11c) = *(char *)((long)param_1 + 0x11c) + '\x01';
    }
    else {
      pcVar2 = (char *)(param_1[8] +
                       (ulong)(*(ushort *)(param_1[1] + 4) >> 4) +
                       (ulong)(*(ushort *)(param_1[1] + 6) & 0xf));
      lVar1 = param_1[7];
      uVar5 = *(ushort *)(param_1[1] + 6);
      uVar3 = *(ushort *)(param_1[1] + 6);
      *(undefined2 *)
       ((long)param_1 + ((long)(int)(uint)*(byte *)((long)param_1 + 0x11c) + 0x3c) * 4) =
           *(undefined2 *)(*param_1 + 2);
      if (*pcVar2 == -4) {
        *(undefined1 *)
         ((long)param_1 + ((long)(int)(uint)*(byte *)((long)param_1 + 0x11c) + 0x3c) * 4 + 2) =
             *(undefined1 *)
              ((long)param_1 + ((long)(int)(*(byte *)((long)param_1 + 0x11c) - 1) + 0x3c) * 4 + 2);
      }
      else if (*pcVar2 == -3) {
        *(undefined1 *)
         ((long)param_1 + ((long)(int)(uint)*(byte *)((long)param_1 + 0x11c) + 0x3c) * 4 + 2) = 0xff
        ;
      }
      else {
        *(char *)((long)param_1 + ((long)(int)(uint)*(byte *)((long)param_1 + 0x11c) + 0x3c) * 4 + 2
                 ) = *pcVar2;
      }
      *(undefined1 *)
       ((long)param_1 + ((long)(int)(uint)*(byte *)((long)param_1 + 0x11c) + 0x3c) * 4 + 3) =
           *(undefined1 *)(lVar1 + ((ulong)(uVar5 >> 4) + (ulong)(uVar3 & 0xf)) * 4 + 2);
      *(char *)((long)param_1 + 0x11c) = *(char *)((long)param_1 + 0x11c) + '\x01';
    }
  }
  return;
}


//===== FUN_00106d43 @ 00106d43 size=93 =====

void FUN_00106d43(long *param_1,ushort param_2,ushort param_3)

{
  *param_1 = param_1[6] + (ulong)param_2 * 8;
  param_1[1] = param_1[6] + (ulong)param_3 * 8;
  FUN_001063a2(param_1);
  return;
}


//===== FUN_00106da0 @ 00106da0 size=34 =====

long FUN_00106da0(long param_1,int param_2)

{
  return *(long *)(param_1 + 0x30) + (long)param_2 * 8;
}


//===== FUN_00106dc2 @ 00106dc2 size=18 =====

undefined8 FUN_00106dc2(long param_1)

{
  return *(undefined8 *)(param_1 + 0x50);
}


//===== FUN_00106dd4 @ 00106dd4 size=18 =====

undefined8 FUN_00106dd4(long param_1)

{
  return *(undefined8 *)(param_1 + 0x58);
}


//===== FUN_00106de6 @ 00106de6 size=21 =====

undefined2 FUN_00106de6(long *param_1)

{
  return *(undefined2 *)(*param_1 + 2);
}


//===== FUN_00106dfb @ 00106dfb size=283 =====

long FUN_00106dfb(long *param_1,undefined2 *param_2,undefined1 *param_3)

{
  undefined2 *puVar1;
  ushort uVar2;
  short sVar3;
  ushort uVar4;
  ushort uVar5;
  long lVar6;
  
  sVar3 = FUN_0010637f(param_1);
  if (sVar3 == 0) {
    *param_2 = 0;
    *param_3 = 0;
    lVar6 = 0;
  }
  else {
    lVar6 = param_1[7];
    uVar2 = *(ushort *)(*param_1 + 6);
    uVar4 = FUN_0010634f(param_1);
    uVar5 = FUN_00106367(param_1);
    puVar1 = (undefined2 *)(lVar6 + ((ulong)(uVar2 >> 4) + (ulong)uVar4 + (ulong)uVar5) * 4);
    *param_2 = *puVar1;
    *param_3 = *(undefined1 *)(puVar1 + 1);
    lVar6 = param_1[8];
    uVar2 = *(ushort *)(*param_1 + 4);
    uVar4 = FUN_0010634f(param_1);
    uVar5 = FUN_00106367(param_1);
    lVar6 = param_1[0xc] +
            (ulong)*(byte *)(lVar6 + (ulong)(uVar2 >> 4) + (ulong)uVar4 + (ulong)uVar5) * 0xa0;
  }
  return lVar6;
}


//===== FUN_00106f16 @ 00106f16 size=1689 =====

undefined4
FUN_00106f16(long param_1,ushort param_2,undefined2 *param_3,undefined2 *param_4,long param_5)

{
  ushort *puVar1;
  long lVar2;
  long lVar3;
  uint uVar4;
  int iVar5;
  ushort *puVar6;
  undefined4 local_20;
  short local_1a;
  short local_18;
  ushort local_16;
  byte local_12;
  byte local_11;
  
  local_20 = 1;
  local_16 = 1;
  while ((local_16 < *(byte *)(param_1 + 0x11a) &&
         (*(ushort *)(param_1 + 8 + ((long)(int)(uint)local_16 + 0x18) * 4) < param_2))) {
    local_16 = local_16 + 1;
  }
  if (local_16 < *(byte *)(param_1 + 0x11a)) {
    puVar1 = (ushort *)(param_1 + 0x68 + (ulong)local_16 * 4);
    puVar6 = puVar1 + -2;
    if (((((char)puVar1[-1] == '\0') && (*(char *)((long)puVar1 + -1) == '\0')) &&
        ((char)puVar1[1] == '\0')) && (*(char *)((long)puVar1 + 3) == '\0')) {
      *param_3 = 0;
      *param_4 = 0;
      local_20 = 0;
    }
    else {
      if (*puVar6 == param_2) {
        local_11 = (byte)puVar1[-1];
        local_12 = *(byte *)((long)puVar1 + -1);
      }
      else if ((*puVar1 == param_2) || (*puVar1 == *puVar6)) {
        local_11 = (byte)puVar1[1];
        local_12 = *(byte *)((long)puVar1 + 3);
      }
      else if (((char)puVar1[-1] == (char)puVar1[1]) &&
              (*(char *)((long)puVar1 + -1) == *(char *)((long)puVar1 + 3))) {
        local_11 = (byte)puVar1[1];
        local_12 = *(byte *)((long)puVar1 + 3);
      }
      else {
        uVar4 = (int)(((uint)param_2 - (uint)*puVar6) * 0x80) / (int)((uint)*puVar1 - (uint)*puVar6)
        ;
        local_11 = (byte)((int)((0x80 - (uVar4 & 0xff)) * (uint)(byte)puVar1[-1] +
                               (uVar4 & 0xff) * (uint)(byte)puVar1[1]) >> 7);
        local_12 = (byte)((int)((0x80 - (uVar4 & 0xff)) * (uint)*(byte *)((long)puVar1 + -1) +
                               (uVar4 & 0xff) * (uint)*(byte *)((long)puVar1 + 3)) >> 7);
      }
      local_16 = 1;
      while ((local_16 < *(byte *)(param_1 + 0x11b) &&
             (*(ushort *)(param_1 + 0xc + ((long)(int)(uint)local_16 + 0x28) * 4) < param_2))) {
        local_16 = local_16 + 1;
      }
      if (local_16 < *(byte *)(param_1 + 0x11b)) {
        puVar1 = (ushort *)(param_1 + 0xac + (ulong)local_16 * 4);
        puVar6 = puVar1 + -2;
        if ((((char)puVar1[-1] == -1) || ((char)puVar1[1] == -1)) &&
           ((*puVar1 != param_2 || ((char)puVar1[1] == -1)))) {
          *param_3 = 0;
          *param_4 = 0;
          local_20 = 0;
        }
        else {
          if (((char)puVar1[-1] == (char)puVar1[1]) || (*puVar1 == param_2)) {
            lVar2 = *(long *)(param_1 + 0x48) + (ulong)(byte)puVar1[1] * 0x1c;
            if (*(char *)(param_1 + 0x11d) != (char)puVar1[1]) {
              for (local_16 = 0; local_16 < 8; local_16 = local_16 + 1) {
                *(undefined2 *)((ulong)local_16 * 2 + param_5) =
                     *(undefined2 *)(lVar2 + (long)(int)(uint)local_16 * 2);
              }
              *(char *)(param_1 + 0x11d) = (char)puVar1[1];
              local_20 = 3;
            }
            local_18 = *(short *)(lVar2 + 0x10);
            local_1a = *(short *)(lVar2 + 0x12);
          }
          else if (*puVar6 == param_2) {
            lVar2 = *(long *)(param_1 + 0x48) + (ulong)(byte)puVar1[-1] * 0x1c;
            if (*(char *)(param_1 + 0x11d) != (char)puVar1[-1]) {
              for (local_16 = 0; local_16 < 8; local_16 = local_16 + 1) {
                *(undefined2 *)((ulong)local_16 * 2 + param_5) =
                     *(undefined2 *)(lVar2 + (long)(int)(uint)local_16 * 2);
              }
              *(char *)(param_1 + 0x11d) = (char)puVar1[-1];
              local_20 = 3;
            }
            local_18 = *(short *)(lVar2 + 0x10);
            local_1a = *(short *)(lVar2 + 0x12);
          }
          else {
            uVar4 = (int)(((uint)param_2 - (uint)*puVar6) * 0x80) /
                    (int)((uint)*puVar1 - (uint)*puVar6);
            lVar2 = *(long *)(param_1 + 0x48) + (ulong)(byte)puVar1[-1] * 0x1c;
            lVar3 = *(long *)(param_1 + 0x48) + (ulong)(byte)puVar1[1] * 0x1c;
            for (local_16 = 0; local_16 < 8; local_16 = local_16 + 1) {
              *(short *)((ulong)local_16 * 2 + param_5) =
                   *(short *)((ulong)local_16 * 2 + lVar2) +
                   (short)((int)(((int)*(short *)((ulong)local_16 * 2 + lVar3) -
                                 (int)*(short *)((ulong)local_16 * 2 + lVar2)) * (uVar4 & 0xff)) >>
                          7);
            }
            *(undefined1 *)(param_1 + 0x11d) = 0xff;
            local_20 = 3;
            local_18 = (short)((int)((0x80 - (uVar4 & 0xff)) * (int)*(short *)(lVar2 + 0x10) +
                                    (uVar4 & 0xff) * (int)*(short *)(lVar3 + 0x10)) >> 7);
            local_1a = (short)((int)((0x80 - (uVar4 & 0xff)) * (int)*(short *)(lVar2 + 0x12) +
                                    (uVar4 & 0xff) * (int)*(short *)(lVar3 + 0x12)) >> 7);
          }
          iVar5 = (int)local_18 * (uint)local_11;
          if (iVar5 < 0) {
            iVar5 = iVar5 + 0xfff;
          }
          *param_3 = (short)(iVar5 >> 0xc);
          iVar5 = (int)local_1a * (uint)local_12;
          if (iVar5 < 0) {
            iVar5 = iVar5 + 0xfff;
          }
          *param_4 = (short)(iVar5 >> 0xc);
        }
      }
      else {
        local_20 = 0;
      }
    }
  }
  else {
    local_20 = 0;
  }
  return local_20;
}


//===== FUN_001075af @ 001075af size=680 =====

undefined8 FUN_001075af(long param_1,ushort param_2,undefined2 *param_3,long param_4)

{
  ushort *puVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  ushort *puVar6;
  ushort local_16;
  byte local_12;
  byte local_11;
  
  local_16 = 1;
  while ((local_16 < *(byte *)(param_1 + 0x11c) &&
         (*(ushort *)(param_1 + ((long)(int)(uint)local_16 + 0x3c) * 4) < param_2))) {
    local_16 = local_16 + 1;
  }
  if (local_16 < *(byte *)(param_1 + 0x11c)) {
    puVar1 = (ushort *)(param_1 + 0xf0 + (ulong)local_16 * 4);
    puVar6 = puVar1 + -2;
    if (((char)puVar1[-1] == -1) || ((char)puVar1[1] == -1)) {
      *param_3 = 0;
      uVar5 = 0;
    }
    else if ((*(char *)((long)puVar1 + -1) == '\0') && (*(char *)((long)puVar1 + 3) == '\0')) {
      *param_3 = 0;
      uVar5 = 0;
    }
    else {
      if (*puVar6 == param_2) {
        local_11 = *(byte *)((long)puVar1 + -1);
        local_12 = (byte)puVar1[-1];
      }
      else if ((*puVar1 == param_2) || (*puVar1 == *puVar6)) {
        local_11 = *(byte *)((long)puVar1 + 3);
        local_12 = (byte)puVar1[1];
      }
      else if (*(char *)((long)puVar1 + -1) == *(char *)((long)puVar1 + 3)) {
        local_11 = *(byte *)((long)puVar1 + 3);
        local_12 = (byte)puVar1[1];
      }
      else {
        uVar3 = (int)(((uint)param_2 - (uint)*puVar6) * 0x80) / (int)((uint)*puVar1 - (uint)*puVar6)
        ;
        local_11 = (byte)((int)((0x80 - (uVar3 & 0xff)) * (uint)*(byte *)((long)puVar1 + -1) +
                               (uVar3 & 0xff) * (uint)*(byte *)((long)puVar1 + 3)) >> 7);
        local_12 = (byte)puVar1[1];
      }
      lVar2 = *(long *)(param_1 + 0x48) + (ulong)local_12 * 0x1c;
      iVar4 = (int)*(short *)(lVar2 + 0x12) * (uint)local_11;
      if (iVar4 < 0) {
        iVar4 = iVar4 + 0xfff;
      }
      *param_3 = (short)(iVar4 >> 0xc);
      if (*(byte *)(param_1 + 0x11e) == local_12) {
        uVar5 = 1;
      }
      else {
        for (local_16 = 0; local_16 < 8; local_16 = local_16 + 1) {
          *(undefined2 *)((ulong)local_16 * 2 + param_4) =
               *(undefined2 *)(lVar2 + (long)(int)(uint)local_16 * 2);
        }
        *(byte *)(param_1 + 0x11e) = local_12;
        uVar5 = 3;
      }
    }
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}


//===== FUN_00107857 @ 00107857 size=152 =====

ushort FUN_00107857(long param_1,uint param_2,uint param_3)

{
  uint local_28;
  ushort local_a;
  
  local_28 = param_3;
  if ((param_2 == 0) && (((param_3 == 7 || (param_3 == 8)) || (param_3 == 9)))) {
    local_28 = 6;
  }
  local_a = 0;
  while( true ) {
    if (**(byte **)(param_1 + 0x28) <= local_a) {
      return 0;
    }
    if ((*(byte *)(*(long *)(param_1 + 0x30) + (ulong)local_a * 8) == param_2) &&
       (*(byte *)(*(long *)(param_1 + 0x30) + (ulong)local_a * 8 + 1) == local_28)) break;
    local_a = local_a + 1;
  }
  return local_a;
}


//===== FUN_001078ef @ 001078ef size=322 =====

ushort FUN_001078ef(long param_1,uint param_2,uint param_3)

{
  uint local_28;
  uint local_24;
  ushort local_a;
  
  if (((param_2 == 7) || (param_2 == 8)) || (local_24 = param_2, param_2 == 9)) {
    local_24 = 6;
  }
  local_28 = param_3;
  switch(param_3) {
  case 0xf:
    local_28 = 0xe;
    break;
  case 0x12:
    local_28 = 0x11;
    break;
  case 0x15:
    local_28 = 0x14;
    break;
  case 0x17:
    local_28 = 0x16;
    break;
  case 0x1a:
    local_28 = 0x19;
    break;
  case 0x1c:
    local_28 = 0x1b;
    break;
  case 0x1e:
    local_28 = 0x1d;
    break;
  case 0x20:
    local_28 = 0x1f;
    break;
  case 0x22:
    local_28 = 0x21;
    break;
  case 0x25:
    local_28 = 0x23;
  }
  local_a = (ushort)**(byte **)(param_1 + 0x28);
  while( true ) {
    if ((ushort)((ushort)**(byte **)(param_1 + 0x28) +
                (ushort)*(byte *)(*(long *)(param_1 + 0x28) + 1)) <= local_a) {
      return (ushort)**(byte **)(param_1 + 0x28);
    }
    if ((*(byte *)(*(long *)(param_1 + 0x30) + (ulong)local_a * 8) == local_24) &&
       (*(byte *)(*(long *)(param_1 + 0x30) + (ulong)local_a * 8 + 1) == local_28)) break;
    local_a = local_a + 1;
  }
  return local_a;
}


//===== FUN_00107a31 @ 00107a31 size=88 =====

void FUN_00107a31(long param_1,int param_2,uint *param_3,uint *param_4)

{
  *param_3 = (uint)*(byte *)(*(long *)(param_1 + 0x30) + (long)param_2 * 8);
  *param_4 = (uint)*(byte *)(*(long *)(param_1 + 0x30) + (long)param_2 * 8 + 1);
  return;
}


//===== FUN_00107a89 @ 00107a89 size=125 =====

int FUN_00107a89(long param_1,undefined8 param_2)

{
  int iVar1;
  int local_1c;
  
  local_1c = 0;
  while( true ) {
    if (*(short *)(param_1 + 0x114) <= local_1c) {
      return -1;
    }
    iVar1 = FUN_00102c13(*(long *)(param_1 + 0x48) + (long)local_1c * 0x1c + 0x14,param_2);
    if (iVar1 == 0) break;
    local_1c = local_1c + 1;
  }
  return local_1c;
}


//===== FUN_00107b06 @ 00107b06 size=200 =====

undefined8 FUN_00107b06(undefined8 param_1,short *param_2,long param_3)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  short *local_20;
  int local_10;
  short local_a;
  
  iVar1 = FUN_00102be4(param_3);
  local_10 = 0;
  while ((local_10 < iVar1 + -5 && (iVar2 = FUN_00102c69(param_3 + local_10,"AQUEST",6), iVar2 != 0)
         )) {
    local_10 = local_10 + 1;
  }
  if (iVar1 + -5 == local_10) {
    uVar3 = 1;
  }
  else {
    local_a = 0;
    local_20 = param_2;
    for (local_10 = 0; local_10 < (int)(uint)(*(ushort *)(param_3 + 0x38) >> 1);
        local_10 = local_10 + 1) {
      local_a = local_a + *local_20;
      local_20 = local_20 + 1;
    }
    if (local_a == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = 2;
    }
  }
  return uVar3;
}


//===== FUN_00107bce @ 00107bce size=32 =====

void FUN_00107bce(long param_1)

{
  *(undefined1 *)(param_1 + 0x11d) = 0xff;
  *(undefined1 *)(param_1 + 0x11e) = 0xff;
  return;
}


//===== FUN_00107bee @ 00107bee size=55 =====

undefined8 FUN_00107bee(long param_1)

{
  undefined8 uVar1;
  
  if (*(long *)(param_1 + 0x20) == 0) {
    if (*(long *)(param_1 + 0x18) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 2;
    }
  }
  else {
    uVar1 = 4;
  }
  return uVar1;
}


//===== FUN_00107c28 @ 00107c28 size=32 =====

void FUN_00107c28(undefined4 *param_1)

{
  *(undefined8 *)(param_1 + 2) = 0;
  *param_1 = 0;
  return;
}


//===== FUN_00107c48 @ 00107c48 size=91 =====

undefined2 FUN_00107c48(undefined4 *param_1,undefined8 param_2)

{
  undefined2 uVar1;
  
  *(undefined8 *)(param_1 + 2) = param_2;
  *param_1 = 0;
  uVar1 = FUN_00107ca3(param_1,param_1 + 6);
  if (*(char *)(param_1 + 6) == '\x02') {
    *(undefined1 *)(param_1 + 6) = 3;
  }
  return uVar1;
}


//===== FUN_00107ca3 @ 00107ca3 size=197 =====

short FUN_00107ca3(int *param_1,byte *param_2)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  short local_1c;
  
  local_1c = 0;
  *param_2 = 8;
  while ((iVar1 = *param_1, iVar3 = FUN_001048e4(*(undefined8 *)(param_1 + 2)), iVar1 < iVar3 &&
         (bVar2 = FUN_0010491e(*(undefined8 *)(param_1 + 2),*param_1), bVar2 < 10))) {
    if (1 < bVar2) {
      *param_2 = bVar2;
      if (bVar2 == 6) {
        local_1c = local_1c + 700;
      }
      else if (bVar2 == 7) {
        local_1c = local_1c + 0xaf0;
      }
      else if (bVar2 == 8) {
        local_1c = local_1c + 4000;
      }
      else if (bVar2 == 9) {
        local_1c = local_1c + 4000;
      }
    }
    *param_1 = *param_1 + 1;
  }
  return local_1c;
}


//===== FUN_00107d68 @ 00107d68 size=78 =====

undefined8 FUN_00107d68(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (*(long *)(param_1 + 2) == 0) {
    uVar3 = 1;
  }
  else {
    iVar1 = *param_1;
    iVar2 = FUN_001048e4(*(undefined8 *)(param_1 + 2));
    if (iVar1 < iVar2) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
  }
  return uVar3;
}


//===== FUN_00107db6 @ 00107db6 size=342 =====

int FUN_00107db6(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined8 param_5)

{
  undefined1 local_38 [20];
  int local_24;
  int local_20;
  undefined1 local_19 [9];
  
  *(undefined8 *)(param_1 + 0x10) = param_5;
  local_20 = FUN_00107f0c(param_1,param_2,local_19,param_4);
  if (local_20 == 0) {
    local_24 = FUN_00107bee(param_5);
    if (local_24 == 2) {
      FUN_00108478(local_38,param_5);
      local_20 = FUN_00108495(local_38,param_2,*(undefined1 *)(param_1 + 0x18));
    }
    else {
      if (local_24 != 4) {
        return 0x3ea;
      }
      FUN_001093f8(local_38,param_5);
      local_20 = FUN_00109415(local_38,param_2,*(undefined1 *)(param_1 + 0x18));
    }
    if (local_20 == 0) {
      FUN_00104fed(param_3);
      local_20 = FUN_00108000(param_1,param_2,param_3,local_24);
      if (local_20 == 0) {
        FUN_00108225(param_1,param_3);
        *(undefined1 *)(param_1 + 0x18) = local_19[0];
        local_20 = 0;
      }
    }
  }
  return local_20;
}


//===== FUN_00107f0c @ 00107f0c size=244 =====

int FUN_00107f0c(int *param_1,undefined8 param_2,undefined8 param_3,undefined2 *param_4)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  
  if ((*(long *)(param_1 + 2) == 0) ||
     (iVar4 = *param_1, iVar3 = FUN_001048e4(*(undefined8 *)(param_1 + 2)), iVar3 <= iVar4)) {
    iVar4 = 100;
  }
  else {
    FUN_001051d9(param_2);
    while (iVar4 = *param_1, iVar3 = FUN_001048e4(*(undefined8 *)(param_1 + 2)), iVar4 < iVar3) {
      uVar1 = FUN_0010491e(*(undefined8 *)(param_1 + 2),*param_1);
      iVar4 = FUN_00105203(param_2,uVar1);
      if (iVar4 != 0) {
        return iVar4;
      }
      iVar4 = FUN_00104080(uVar1);
      if (iVar4 != 0) break;
      *param_1 = *param_1 + 1;
    }
    uVar2 = FUN_00107ca3(param_1,param_3);
    *param_4 = uVar2;
    iVar4 = 0;
  }
  return iVar4;
}


//===== FUN_00108000 @ 00108000 size=549 =====

undefined8 FUN_00108000(undefined8 param_1,long param_2,undefined8 param_3,int param_4)

{
  undefined1 uVar1;
  ushort uVar2;
  bool bVar3;
  int iVar4;
  long lVar5;
  long local_38;
  int local_30;
  ushort local_20;
  ushort local_1c;
  undefined1 local_19;
  
  local_38 = 0;
  local_19 = 8;
  bVar3 = true;
  FUN_0010532c(param_2);
  local_1c = *(ushort *)(param_2 + 0x10);
  while (lVar5 = FUN_0010536b(param_2), lVar5 != 0) {
    for (local_30 = 0; local_38 = lVar5, local_30 < (int)(uint)*(byte *)(lVar5 + 1);
        local_30 = local_30 + 1) {
      uVar2 = *(ushort *)(lVar5 + 6 + (long)local_30 * 4);
      uVar1 = *(undefined1 *)(lVar5 + 8 + (long)local_30 * 4);
      iVar4 = FUN_0010410f(uVar1);
      if (iVar4 == 0) {
        local_20 = (ushort)(((uint)local_1c + (uint)uVar2) / 2);
      }
      else if (bVar3) {
        local_20 = (ushort)(((uint)local_1c + (uint)uVar2) / 2);
      }
      else {
        local_20 = local_1c;
      }
      iVar4 = FUN_00108397(param_1,local_19,uVar1,param_3,local_20);
      if (iVar4 < 0) {
        return 0xc9;
      }
      iVar4 = FUN_001082aa(param_1,local_19,uVar1,param_3,uVar2);
      if (iVar4 < 0) {
        return 0xc9;
      }
      bVar3 = false;
      local_1c = uVar2;
      local_19 = uVar1;
    }
  }
  if (local_38 != 0) {
    if (*(char *)(local_38 + 3) == '\t') {
      if (param_4 == 2) {
        local_1c = 64000 / (ushort)(64000 / local_1c + *(short *)(param_2 + 0x12));
      }
      else {
        local_1c = *(ushort *)(param_2 + 0x12);
      }
    }
    iVar4 = FUN_00108397(param_1,local_19,*(undefined1 *)(local_38 + 3),param_3,local_1c);
    if (iVar4 < 0) {
      return 0xc9;
    }
  }
  return 0;
}


//===== FUN_00108225 @ 00108225 size=133 =====

void FUN_00108225(undefined8 param_1,undefined8 param_2)

{
  ushort uVar1;
  
  uVar1 = FUN_00105038(param_2);
  if (uVar1 != 0) {
    FUN_001050dd(param_2,uVar1 - 1,0x8000);
  }
  if (1 < uVar1) {
    FUN_001050dd(param_2,uVar1 - 2,0x8000);
  }
  if (2 < uVar1) {
    FUN_001050dd(param_2,uVar1 - 3,0x8000);
  }
  return;
}


//===== FUN_001082aa @ 001082aa size=237 =====

void FUN_001082aa(long param_1,undefined1 param_2,undefined1 param_3,undefined8 param_4,
                 undefined2 param_5)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 local_24;
  undefined4 local_20;
  
  local_20 = FUN_001043d4(param_3);
  local_24 = FUN_001043f8(param_3);
  iVar2 = FUN_0010410f(param_3);
  if (iVar2 != 0) {
    iVar2 = FUN_0010405d(param_2);
    if (iVar2 == 0) {
      iVar2 = FUN_001040c6(param_2);
      if (iVar2 == 0) {
        local_20 = FUN_001043f8(param_2);
        if ((((local_20 == 7) || (local_20 == 9)) || (local_20 == 8)) &&
           (((local_20 = 6, local_24 == 7 || (local_24 == 9)) || (local_24 == 8)))) {
          local_24 = 6;
        }
        goto LAB_0010835e;
      }
    }
    local_20 = 0;
  }
LAB_0010835e:
  uVar1 = FUN_00107857(*(undefined8 *)(param_1 + 0x10),local_20,local_24);
  FUN_00104f65(param_4,uVar1,param_5);
  return;
}


//===== FUN_00108397 @ 00108397 size=204 =====

void FUN_00108397(long param_1,undefined1 param_2,undefined1 param_3,undefined8 param_4,
                 undefined2 param_5)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 local_24;
  undefined4 local_20;
  
  local_20 = FUN_001043f8(param_2);
  local_24 = FUN_001043d4(param_3);
  if (((local_20 == 7) || (local_20 == 9)) || (local_20 == 8)) {
    local_20 = 6;
  }
  iVar2 = FUN_001040c6(param_2);
  if (iVar2 != 0) {
    iVar2 = FUN_0010410f(param_3);
    if (iVar2 != 0) {
      local_24 = 0;
      goto LAB_0010842a;
    }
  }
  iVar2 = FUN_0010410f(param_3);
  if (iVar2 != 0) {
    local_24 = local_20;
  }
LAB_0010842a:
  uVar1 = FUN_001078ef(*(undefined8 *)(param_1 + 0x10),local_20,local_24);
  FUN_00104f65(param_4,uVar1,param_5);
  return;
}


//===== FUN_00108463 @ 00108463 size=18 =====

undefined1 FUN_00108463(long param_1)

{
  return *(undefined1 *)(param_1 + 0x18);
}


//===== FUN_00108478 @ 00108478 size=29 =====

void FUN_00108478(undefined8 *param_1,long param_2)

{
  *param_1 = *(undefined8 *)(param_2 + 0x18);
  return;
}


//===== FUN_00108495 @ 00108495 size=847 =====

undefined8 FUN_00108495(long *param_1,long param_2,byte param_3)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  long lVar4;
  long local_28;
  short local_1c;
  byte local_19;
  
  FUN_0010532c(param_2);
  lVar4 = FUN_0010536b(param_2);
  if (lVar4 != 0) {
    local_1c = *(short *)(*param_1 + 8 + ((long)(int)(param_3 - 3) + 600) * 2);
    sVar1 = *(short *)(*param_1 + 0x4b8);
    if ((5 < param_3) && (param_3 < 10)) {
      if ((*(char *)(lVar4 + 3) == '\x06') || (*(char *)(lVar4 + 3) == '\a')) {
        local_1c = *(short *)(*param_1 + 0x4be);
      }
      else if (*(char *)(lVar4 + 3) == '\b') {
        local_1c = *(short *)(*param_1 + 0x4ba);
      }
    }
    while (local_28 = lVar4, local_28 != 0) {
      *(short *)(local_28 + 4) = local_1c;
      lVar4 = FUN_0010536b(param_2);
      if (lVar4 == 0) break;
      if (*(char *)(local_28 + 3) == '\x05') {
        local_1c = *(short *)(*param_1 + 0x4bc);
      }
      else if ((*(char *)(local_28 + 3) != '\x03') &&
              (((*(char *)(local_28 + 3) != '\x04' || (*(char *)(local_28 + 2) != '\0')) ||
               (*(char *)(lVar4 + 2) != '\x01')))) {
        iVar3 = (int)*(short *)(*param_1 + 4) * (int)local_1c;
        if (iVar3 < 0) {
          iVar3 = iVar3 + 0x3ff;
        }
        local_1c = (short)(iVar3 >> 10);
        if (local_1c < sVar1) {
          local_1c = sVar1;
        }
      }
    }
    FUN_0010532c(param_2);
    lVar4 = FUN_0010536b(param_2);
    while (local_28 = lVar4, local_28 != 0) {
      lVar4 = FUN_0010536b(param_2);
      for (local_19 = 0; local_19 < *(byte *)(local_28 + 1); local_19 = local_19 + 1) {
        if (*(short *)(local_28 + 6 + (long)(int)(uint)local_19 * 4) == 0) {
          uVar2 = FUN_00108bc4(param_1,local_19,local_28,lVar4);
          *(short *)(local_28 + 6 + (long)(int)(uint)local_19 * 4) =
               (short)(0x3e8000 / (ulong)(long)(int)(uint)uVar2);
        }
      }
      iVar3 = FUN_00104080(*(undefined1 *)(local_28 + 3));
      if (((((iVar3 == 0) && (lVar4 != 0)) &&
           ((*(char *)(lVar4 + 1) != '\x02' || (*(char *)(lVar4 + 2) != '\x01')))) &&
          ((*(char *)(local_28 + 3) != '\x05' || (*(char *)(lVar4 + 2) != '\x01')))) &&
         (*(short *)(lVar4 + 6) == 0)) {
        uVar2 = FUN_00108bc4(param_1,*(undefined1 *)(local_28 + 1),local_28,lVar4);
        *(short *)(lVar4 + 6) = (short)(0x3e8000 / (ulong)(long)(int)(uint)uVar2);
      }
    }
    FUN_0010916c(param_1,param_2);
    *(short *)(param_2 + 0x10) = (short)(64000 / (ulong)(uint)(int)*(short *)(*param_1 + 2));
    *(undefined2 *)(param_2 + 0x12) = *(undefined2 *)(*param_1 + 6);
  }
  return 0;
}


//===== FUN_001087e4 @ 001087e4 size=198 =====

byte FUN_001087e4(undefined8 param_1,byte param_2,byte param_3,byte param_4)

{
  byte local_34;
  byte local_30;
  byte local_2c;
  byte local_11;
  
  local_2c = param_2;
  if (param_2 == 0) {
    local_2c = 1;
  }
  if (6 < local_2c) {
    local_2c = 6;
  }
  local_30 = param_3;
  if (local_2c == param_3) {
    local_30 = 0;
  }
  if (5 < local_30) {
    local_30 = 5;
  }
  local_34 = param_4;
  if (2 < param_4) {
    local_34 = 2;
  }
  local_11 = 0;
  while( true ) {
    if (0x3b < local_11) {
      return 0;
    }
    if ((((&DAT_00112c81)[(long)(int)(uint)local_11 * 4] == local_2c) &&
        ((&DAT_00112c82)[(long)(int)(uint)local_11 * 4] == local_30)) &&
       ((&DAT_00112c83)[(long)(int)(uint)local_11 * 4] == local_34)) break;
    local_11 = local_11 + 1;
  }
  return local_11;
}


//===== FUN_001088aa @ 001088aa size=794 =====

ulong FUN_001088aa(long *param_1,byte param_2,long param_3,undefined1 param_4)

{
  short sVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  ulong uVar5;
  undefined1 local_54;
  undefined1 local_38;
  char local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined2 local_34;
  undefined1 local_1a;
  undefined1 local_19;
  
  if (*(byte *)(param_3 + 1) < 2) {
    if (*(char *)(param_3 + 2) == '\0') {
      bVar2 = FUN_001087e4(param_1,2,0,0);
      iVar4 = ((int)*(char *)((long)(int)(uint)bVar2 * 10 + 10 + *param_1) * (int)*(char *)*param_1
              + *(char *)(*param_1 + 1) * 0x40) * (int)*(short *)(param_3 + 4);
      if (iVar4 < 0) {
        iVar4 = iVar4 + 0x3ff;
      }
      return (ulong)(uint)(iVar4 >> 10);
    }
    bVar2 = FUN_001087e4(param_1,2,1,0);
    iVar4 = ((int)*(char *)((long)(int)(uint)bVar2 * 10 + 10 + *param_1) * (int)*(char *)*param_1 +
            *(char *)(*param_1 + 1) * 0x40) * (int)*(short *)(param_3 + 4);
    if (iVar4 < 0) {
      iVar4 = iVar4 + 0x3ff;
    }
    return (ulong)(uint)(iVar4 >> 10);
  }
  if ((6 < *(byte *)(param_3 + 1)) && (3 < *(byte *)(param_3 + 2))) {
    if (param_2 < *(byte *)(param_3 + 2)) {
      local_36 = 0;
      local_35 = 3;
      local_34 = *(undefined2 *)(param_3 + 4);
      local_37 = *(char *)(param_3 + 2) + -1;
      uVar5 = FUN_001088aa(param_1,param_2,&local_38,1);
      return uVar5;
    }
    local_36 = 1;
    local_35 = *(undefined1 *)(param_3 + 3);
    local_34 = *(undefined2 *)(param_3 + 4);
    local_37 = (*(char *)(param_3 + 1) - *(char *)(param_3 + 2)) + '\x01';
    uVar5 = FUN_001088aa(param_1,(param_2 - *(char *)(param_3 + 2)) + '\x01',&local_38,param_4);
    return uVar5;
  }
  bVar2 = *(byte *)(param_3 + 3);
  if (bVar2 == 8) {
    local_19 = 1;
    local_54 = 1;
  }
  else {
    if (bVar2 < 9) {
      if (5 < bVar2) {
        local_19 = 1;
        local_54 = 0;
        goto LAB_00108b15;
      }
    }
    else if (bVar2 == 9) {
      local_19 = 1;
      local_54 = 2;
      goto LAB_00108b15;
    }
    local_19 = 0;
    local_54 = param_4;
  }
LAB_00108b15:
  local_1a = FUN_001087e4(param_1,*(undefined1 *)(param_3 + 1),*(undefined1 *)(param_3 + 2),local_54
                         );
  sVar1 = *(short *)(param_3 + 4);
  sVar3 = FUN_00108cab(param_1,local_19,local_1a,param_2,*(undefined1 *)(param_3 + 1),
                       *(undefined1 *)(param_3 + 2));
  iVar4 = ((int)sVar3 * (int)*(char *)*param_1 + *(char *)(*param_1 + 1) * 0x40) * (int)sVar1;
  if (iVar4 < 0) {
    iVar4 = iVar4 + 0x3ff;
  }
  return (ulong)(uint)(iVar4 >> 10);
}


//===== FUN_00108bc4 @ 00108bc4 size=231 =====

int FUN_00108bc4(long *param_1,undefined1 param_2,undefined8 param_3,long param_4)

{
  short sVar1;
  undefined4 local_1c;
  
  if (param_4 == 0) {
    sVar1 = FUN_001088aa(param_1,param_2,param_3,0);
    local_1c = (int)sVar1 + ((int)*(short *)(*param_1 + 2) - (int)*(char *)(*param_1 + 1)) * 0x40;
  }
  else {
    sVar1 = FUN_001088aa(param_1,param_2,param_3,*(undefined1 *)(param_4 + 2));
    local_1c = (int)sVar1 + ((int)*(short *)(*param_1 + 2) - (int)*(char *)(*param_1 + 1)) * 0x40;
  }
  if (local_1c < 0x280) {
    local_1c = 0x280;
  }
  else if (64000 < local_1c) {
    local_1c = 64000;
  }
  return local_1c;
}


//===== FUN_00108cab @ 00108cab size=1217 =====

uint FUN_00108cab(long *param_1,byte param_2,byte param_3,byte param_4,byte param_5,byte param_6)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  
  if (param_5 < 7) {
    uVar3 = (uint)(ushort)(short)*(char *)((long)(int)(uint)param_2 * 600 +
                                           (long)(int)(uint)param_3 * 10 + *param_1 + 10 +
                                          (long)(int)(uint)param_4);
  }
  else {
    bVar1 = *(byte *)((long)(int)(uint)param_3 * 10 + (long)(int)(uint)param_2 * 600 + 9 + *param_1)
    ;
    if (param_6 < 6) {
      if (bVar1 < param_4) {
        if ((int)((uint)bVar1 + (uint)param_5 + -6) < (int)(uint)param_4) {
          uVar3 = (uint)(ushort)(short)*(char *)((long)(int)(uint)param_2 * 600 +
                                                 (long)(int)(uint)param_3 * 10 + *param_1 + 10 +
                                                (long)(int)((uint)param_4 + (6 - (uint)param_5)));
        }
        else {
          uVar2 = (ushort)*(char *)((long)(int)(uint)param_2 * 600 + (long)(int)(uint)param_3 * 10 +
                                    *param_1 + 10 + (long)(int)(uint)bVar1);
          uVar3 = (int)((uint)(byte)(param_4 - bVar1) *
                       ((int)(short)*(char *)((long)(int)(uint)param_2 * 600 +
                                              (long)(int)(uint)param_3 * 10 + *param_1 + 10 +
                                             (long)(int)(bVar1 + 1)) - (int)(short)uVar2)) /
                  (int)(uint)(byte)(param_5 - 5) + (uint)uVar2;
        }
      }
      else {
        uVar3 = (uint)(ushort)(short)*(char *)((long)(int)(uint)param_2 * 600 +
                                               (long)(int)(uint)param_3 * 10 + *param_1 + 10 +
                                              (long)(int)(uint)param_4);
      }
    }
    else if (param_4 < 4) {
      uVar3 = (uint)(ushort)(short)*(char *)((long)(int)(uint)param_2 * 600 +
                                             (long)(int)(uint)param_3 * 10 + *param_1 + 10 +
                                            (long)(int)(uint)param_4);
    }
    else if ((int)(uint)param_4 < (int)(param_6 - 1)) {
      uVar2 = (ushort)*(char *)((long)(int)(uint)param_3 * 10 + (long)(int)(uint)param_2 * 600 +
                                *param_1 + 0xd);
      uVar3 = (int)((uint)(byte)(param_4 - 3) *
                   ((int)(short)*(char *)((long)(int)(uint)param_3 * 10 +
                                          (long)(int)(uint)param_2 * 600 + *param_1 + 0xe) -
                   (int)(short)uVar2)) / (int)(uint)(byte)(param_6 - 4) + (uint)uVar2;
    }
    else if ((uint)param_4 == param_6 - 1) {
      uVar3 = (uint)(ushort)(short)*(char *)((long)(int)(uint)param_3 * 10 +
                                             (long)(int)(uint)param_2 * 600 + *param_1 + 0xe);
    }
    else if (param_4 + 1 < (uint)param_5) {
      uVar2 = (ushort)*(char *)((long)(int)(uint)param_3 * 10 + (long)(int)(uint)param_2 * 600 +
                                *param_1 + 0xe);
      uVar3 = (int)((uint)(byte)(param_4 - param_6) *
                   ((int)(short)*(char *)((long)(int)(uint)param_3 * 10 +
                                          (long)(int)(uint)param_2 * 600 + *param_1 + 0xf) -
                   (int)(short)uVar2)) / (int)(uint)(byte)(param_5 - param_6) + (uint)uVar2;
    }
    else {
      uVar3 = (uint)(ushort)(short)*(char *)((long)(int)(uint)param_2 * 600 +
                                             (long)(int)(uint)param_3 * 10 + *param_1 + 10 +
                                            (long)(int)(((uint)param_4 - (uint)param_5) + 6));
    }
  }
  return uVar3;
}


//===== FUN_0010916c @ 0010916c size=651 =====

undefined8 FUN_0010916c(undefined8 param_1,undefined8 param_2)

{
  ushort uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  ushort local_1c;
  byte local_1a;
  byte local_19;
  
  FUN_0010532c(param_2);
  do {
    lVar3 = FUN_0010536b(param_2);
    lVar4 = FUN_0010536b(param_2);
    if (lVar4 == 0) {
      return 0;
    }
    if (*(char *)(lVar3 + 3) == '\x03') {
      lVar5 = FUN_0010536b(param_2);
      lVar6 = FUN_001054b5(param_2,lVar3,lVar4);
      if (lVar6 == 0) {
        return 0xca;
      }
      *(undefined2 *)(lVar6 + 6) = *(undefined2 *)(lVar3 + 6);
      *(undefined2 *)(lVar6 + 10) = *(undefined2 *)(lVar3 + 10);
      for (local_19 = 2; local_19 < *(byte *)(lVar6 + 1); local_19 = local_19 + 1) {
        uVar1 = FUN_00108bc4(param_1,local_19,lVar6,lVar5);
        *(short *)(lVar6 + 6 + (long)(int)(uint)local_19 * 4) =
             (short)(0x3e8000 / (ulong)(long)(int)(uint)uVar1);
      }
      local_1c = 0;
      iVar2 = FUN_00104080(*(undefined1 *)(lVar6 + 3));
      if (((iVar2 == 0) && (lVar5 != 0)) &&
         ((*(char *)(lVar5 + 1) != '\x02' || (*(char *)(lVar5 + 2) != '\x01')))) {
        uVar1 = FUN_00108bc4(param_1,*(undefined1 *)(lVar6 + 1),lVar6,lVar5);
        local_1c = (ushort)(0x3e8000 / (ulong)(long)(int)(uint)uVar1);
      }
      for (local_19 = 2; local_19 < *(byte *)(lVar3 + 1); local_19 = local_19 + 1) {
        *(short *)(lVar3 + 6 + (long)(int)(uint)local_19 * 4) =
             (short)((int)((uint)*(ushort *)(lVar3 + 6 + (long)(int)(uint)local_19 * 4) +
                          (uint)*(ushort *)(lVar6 + 6 + (long)(int)(uint)local_19 * 4)) >> 1);
      }
      local_1a = 0;
      for (; local_19 < *(byte *)(lVar6 + 1); local_19 = local_19 + 1) {
        *(short *)(lVar4 + 6 + (long)(int)(uint)local_1a * 4) =
             (short)((int)((uint)*(ushort *)(lVar4 + 6 + (long)(int)(uint)local_1a * 4) +
                          (uint)*(ushort *)(lVar6 + 6 + (long)(int)(uint)local_19 * 4)) >> 1);
        local_1a = local_1a + 1;
      }
      if (local_1c != 0) {
        *(short *)(lVar5 + 6) = (short)((int)((uint)*(ushort *)(lVar5 + 6) + (uint)local_1c) >> 1);
      }
      FUN_0010562b(param_2,lVar6);
    }
    FUN_00105341(param_2,lVar4);
  } while( true );
}


//===== FUN_001093f8 @ 001093f8 size=29 =====

void FUN_001093f8(undefined8 *param_1,long param_2)

{
  *param_1 = *(undefined8 *)(param_2 + 0x20);
  return;
}


//===== FUN_00109415 @ 00109415 size=993 =====

undefined8 FUN_00109415(long *param_1,long param_2,undefined1 param_3)

{
  undefined1 uVar1;
  undefined2 uVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  long lVar8;
  undefined2 *puVar9;
  undefined1 local_6c;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined2 local_20;
  undefined2 local_1c;
  undefined1 local_19;
  
  local_19 = 8;
  FUN_0010532c(param_2);
  local_28 = 0;
  while( true ) {
    lVar8 = FUN_0010536b(param_2);
    if (lVar8 == 0) break;
    local_19 = *(undefined1 *)(lVar8 + 3);
    local_28 = local_28 + 1;
  }
  puVar9 = (undefined2 *)(*param_1 + 2);
  *(undefined2 *)(param_2 + 0x12) = *puVar9;
  FUN_0010532c(param_2);
  local_1c = 0;
  local_2c = 0xffffffff;
  local_6c = param_3;
  for (local_30 = 0; local_30 < local_28; local_30 = local_30 + 1) {
    lVar8 = FUN_0010536b(param_2);
    uVar1 = *(undefined1 *)(lVar8 + 3);
    uVar5 = (uint)*(byte *)(lVar8 + 2);
    uVar6 = (uint)*(byte *)(lVar8 + 1);
    uVar3 = FUN_0010989d(puVar9,local_6c,uVar1,local_28,uVar5,local_19);
    for (local_34 = 0; local_34 < (int)(uint)*(byte *)(lVar8 + 1); local_34 = local_34 + 1) {
      if (local_1c == 0) {
        uVar4 = FUN_00109aa0(puVar9,uVar5);
        local_20 = (ushort)((int)((uint)uVar4 * (uint)uVar3) >> 10);
        if (local_20 < 0x40) {
          local_20 = 0x40;
        }
        else if (0x1900 < local_20) {
          local_20 = 0x1900;
        }
        *(ushort *)(param_2 + 0x10) = local_20;
      }
      else {
        iVar7 = FUN_001097f6(local_34,uVar5,local_2c);
        uVar2 = (undefined2)(((uint)local_1c << 10) / (uint)uVar3);
        if (iVar7 == 0) {
          uVar4 = FUN_00109b38(puVar9,local_6c,uVar5,uVar2);
          local_20 = (ushort)((int)((uint)uVar4 * (uint)local_1c) >> 10);
        }
        else if (iVar7 == 1) {
          uVar4 = FUN_00109c00(puVar9,local_6c,uVar2);
          local_20 = (ushort)((int)((uint)uVar4 * (uint)local_1c) >> 10);
        }
        else if (iVar7 == 2) {
          uVar4 = FUN_00109c87(puVar9,uVar2);
          local_20 = (ushort)((int)((uint)uVar4 * (uint)uVar3) >> 10);
        }
        else if (iVar7 == 3) {
          uVar4 = FUN_00109ccd(puVar9,uVar2);
          local_20 = (ushort)((int)((uint)uVar4 * (uint)uVar3) >> 10);
        }
        else if (iVar7 == 4) {
          uVar4 = FUN_00109d13(puVar9,local_6c,uVar6 - 1 == local_34,uVar1,uVar2);
          local_20 = (ushort)((int)((uint)uVar4 * (uint)local_1c) >> 10);
        }
        else if (iVar7 == 5) {
          uVar4 = FUN_00109f73(puVar9,uVar5,uVar6 - 1 == local_34,uVar1,uVar2);
          local_20 = (ushort)((int)((uint)uVar4 * (uint)uVar3) >> 10);
        }
        else if (iVar7 == 6) {
          uVar4 = FUN_0010a157(puVar9,uVar5,uVar6 - 1 == local_34,uVar2);
          local_20 = (ushort)((int)((uint)uVar4 * (uint)uVar3) >> 10);
        }
        else if (iVar7 == 7) {
          uVar4 = FUN_0010a247(puVar9,uVar5,local_34,uVar2);
          local_20 = (ushort)((int)((uint)uVar4 * (uint)uVar3) >> 10);
        }
      }
      if (local_20 < uVar3) {
        local_20 = uVar3;
      }
      if (local_20 < 0x40) {
        local_20 = 0x40;
      }
      else if (0x1900 < local_20) {
        local_20 = 0x1900;
      }
      *(ushort *)(lVar8 + 6 + (long)local_34 * 4) = local_20;
      local_1c = local_20;
    }
    local_6c = uVar1;
    local_2c = uVar5;
  }
  return 0;
}


//===== FUN_001097f6 @ 001097f6 size=167 =====

undefined8 FUN_001097f6(int param_1,int param_2,int param_3)

{
  undefined8 uVar1;
  
  if (param_1 == 0) {
    if ((param_3 == 0) || (param_2 == 1)) {
      if ((param_3 == 0) && (param_2 != 1)) {
        uVar1 = 1;
      }
      else if ((param_3 == 0) || (param_2 != 1)) {
        uVar1 = 3;
      }
      else {
        uVar1 = 2;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else if ((param_2 == 0) || (param_1 + 1 <= param_2 + 1)) {
    if ((param_2 == 0) || (param_1 + 1 != param_2 + 1)) {
      if ((param_2 == 1) || (param_1 != 1)) {
        uVar1 = 7;
      }
      else {
        uVar1 = 6;
      }
    }
    else {
      uVar1 = 5;
    }
  }
  else {
    uVar1 = 4;
  }
  return uVar1;
}


//===== FUN_0010989d @ 0010989d size=515 =====

int FUN_0010989d(long param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  undefined4 local_c;
  
  local_c = (int)*(short *)(param_1 + 2);
  if (((param_4 == 2) && (param_6 == 8)) && (param_2 == 7)) {
    local_c = local_c + *(short *)(param_1 + 4);
  }
  else if (param_2 == 3) {
    local_c = local_c + *(short *)(param_1 + 6);
  }
  else if (param_2 == 4) {
    local_c = local_c + *(short *)(param_1 + 8);
  }
  else if (param_2 == 5) {
    local_c = local_c + *(short *)(param_1 + 10);
  }
  else if (param_2 == 6) {
    local_c = local_c + *(short *)(param_1 + 0xc);
  }
  else if (param_2 == 7) {
    local_c = local_c + *(short *)(param_1 + 0xe);
  }
  else if (param_2 == 8) {
    local_c = local_c + *(short *)(param_1 + 0x10);
  }
  else if (param_2 == 9) {
    local_c = local_c + *(short *)(param_1 + 0x12);
  }
  if (param_4 == 1) {
    local_c = local_c + *(short *)(param_1 + 0x14);
  }
  if (param_3 == 3) {
    local_c = local_c + *(short *)(param_1 + 0x16);
  }
  else if (param_3 == 4) {
    local_c = local_c + *(short *)(param_1 + 0x18);
  }
  else if (param_3 == 5) {
    local_c = local_c + *(short *)(param_1 + 0x1a);
  }
  else if (param_3 == 6) {
    local_c = local_c + *(short *)(param_1 + 0x1c);
  }
  else if (param_3 == 7) {
    local_c = local_c + *(short *)(param_1 + 0x1e);
  }
  else if (param_3 == 8) {
    local_c = local_c + *(short *)(param_1 + 0x20);
  }
  else if (param_3 == 9) {
    local_c = local_c + *(short *)(param_1 + 0x22);
  }
  if (param_5 == 0) {
    local_c = local_c + *(short *)(param_1 + 0x24);
  }
  else if (param_5 == 1) {
    local_c = local_c + *(short *)(param_1 + 0x26);
  }
  else if (param_5 == 2) {
    local_c = local_c + *(short *)(param_1 + 0x28);
  }
  else {
    local_c = local_c + *(short *)(param_1 + 0x2a);
  }
  return local_c >> 6;
}


//===== FUN_00109aa0 @ 00109aa0 size=152 =====

short FUN_00109aa0(long param_1,int param_2)

{
  undefined2 local_a;
  
  local_a = *(short *)(param_1 + 0x2c);
  if (param_2 == 0) {
    local_a = *(short *)(param_1 + 0x2e) + local_a;
  }
  else if (param_2 == 1) {
    local_a = *(short *)(param_1 + 0x30) + local_a;
  }
  else if (param_2 == 2) {
    local_a = *(short *)(param_1 + 0x32) + local_a;
  }
  else {
    local_a = *(short *)(param_1 + 0x34) + local_a;
  }
  return local_a;
}


//===== FUN_00109b38 @ 00109b38 size=200 =====

short FUN_00109b38(long param_1,int param_2,int param_3,ushort param_4)

{
  undefined2 local_a;
  
  local_a = *(short *)(param_1 + 0x36);
  if (param_2 == 3) {
    local_a = *(short *)(param_1 + 0x38) + local_a;
  }
  else if (param_2 == 4) {
    local_a = *(short *)(param_1 + 0x3a) + local_a;
  }
  else if (param_2 == 5) {
    local_a = *(short *)(param_1 + 0x3c) + local_a;
  }
  if (param_3 == 2) {
    local_a = *(short *)(param_1 + 0x3e) + local_a;
  }
  return (short)((int)((int)*(short *)(param_1 + 0x40) * (uint)param_4) >> 10) + local_a;
}


//===== FUN_00109c00 @ 00109c00 size=135 =====

short FUN_00109c00(long param_1,int param_2,ushort param_3)

{
  undefined2 local_a;
  
  local_a = *(short *)(param_1 + 0x42);
  if (param_2 == 3) {
    local_a = *(short *)(param_1 + 0x44) + local_a;
  }
  else if (param_2 == 5) {
    local_a = *(short *)(param_1 + 0x46) + local_a;
  }
  return (short)((int)((int)*(short *)(param_1 + 0x48) * (uint)param_3) >> 10) + local_a;
}


//===== FUN_00109c87 @ 00109c87 size=70 =====

short FUN_00109c87(long param_1,ushort param_2)

{
  return (short)((int)((int)*(short *)(param_1 + 0x4c) * (uint)param_2) >> 10) +
         *(short *)(param_1 + 0x4a);
}


//===== FUN_00109ccd @ 00109ccd size=70 =====

short FUN_00109ccd(long param_1,ushort param_2)

{
  return (short)((int)((int)*(short *)(param_1 + 0x50) * (uint)param_2) >> 10) +
         *(short *)(param_1 + 0x4e);
}


//===== FUN_00109d13 @ 00109d13 size=608 =====

short FUN_00109d13(long param_1,int param_2,int param_3,int param_4,ushort param_5)

{
  undefined2 local_a;
  
  local_a = *(short *)(param_1 + 0x52);
  if (param_2 == 3) {
    local_a = *(short *)(param_1 + 0x54) + local_a;
  }
  else if (param_2 == 4) {
    local_a = *(short *)(param_1 + 0x56) + local_a;
  }
  else if (param_2 == 5) {
    local_a = *(short *)(param_1 + 0x58) + local_a;
  }
  else if (param_2 == 6) {
    local_a = *(short *)(param_1 + 0x5a) + local_a;
  }
  else if (param_2 == 7) {
    local_a = *(short *)(param_1 + 0x5c) + local_a;
  }
  else if (param_2 == 8) {
    local_a = *(short *)(param_1 + 0x5e) + local_a;
  }
  else if (param_2 == 9) {
    local_a = *(short *)(param_1 + 0x60) + local_a;
  }
  if ((param_3 != 0) && (param_4 != 5)) {
    local_a = *(short *)(param_1 + 0x62) + local_a;
  }
  if (param_4 == 3) {
    local_a = *(short *)(param_1 + 100) + local_a;
  }
  else if (param_4 == 4) {
    local_a = *(short *)(param_1 + 0x66) + local_a;
  }
  else if (param_4 == 5) {
    local_a = *(short *)(param_1 + 0x68) + local_a;
  }
  else if (param_4 == 6) {
    local_a = *(short *)(param_1 + 0x6a) + local_a;
  }
  else if (param_4 == 7) {
    local_a = *(short *)(param_1 + 0x6c) + local_a;
  }
  else if (param_4 == 8) {
    local_a = *(short *)(param_1 + 0x6e) + local_a;
  }
  else if (param_4 == 9) {
    local_a = *(short *)(param_1 + 0x70) + local_a;
  }
  if ((param_4 == 9) && (param_3 != 0)) {
    local_a = *(short *)(param_1 + 0x72) + local_a;
  }
  return (short)((int)((int)*(short *)(param_1 + 0x74) * (uint)param_5) >> 10) + local_a;
}


//===== FUN_00109f73 @ 00109f73 size=484 =====

short FUN_00109f73(long param_1,int param_2,int param_3,int param_4,ushort param_5)

{
  undefined2 local_a;
  
  local_a = *(short *)(param_1 + 0x76);
  if (param_2 == 1) {
    local_a = *(short *)(param_1 + 0x78) + local_a;
  }
  else if (param_2 == 2) {
    local_a = *(short *)(param_1 + 0x7a) + local_a;
  }
  else if (param_2 == 3) {
    local_a = *(short *)(param_1 + 0x7c) + local_a;
  }
  else {
    local_a = *(short *)(param_1 + 0x7e) + local_a;
  }
  if ((param_3 != 0) && (local_a = *(short *)(param_1 + 0x80) + local_a, param_4 == 7)) {
    local_a = *(short *)(param_1 + 0x82) + local_a;
  }
  if (param_4 == 3) {
    local_a = *(short *)(param_1 + 0x84) + local_a;
  }
  else if (param_4 == 4) {
    local_a = *(short *)(param_1 + 0x86) + local_a;
  }
  else if (param_4 == 5) {
    local_a = *(short *)(param_1 + 0x88) + local_a;
  }
  else if ((param_4 == 7) || (param_4 == 6)) {
    local_a = *(short *)(param_1 + 0x8a) + local_a;
  }
  else if (param_4 == 8) {
    local_a = *(short *)(param_1 + 0x8c) + local_a;
  }
  else if (param_4 == 9) {
    local_a = *(short *)(param_1 + 0x8e) + local_a;
  }
  return (short)((int)((int)*(short *)(param_1 + 0x90) * (uint)param_5) >> 10) + local_a;
}


//===== FUN_0010a157 @ 0010a157 size=240 =====

short FUN_0010a157(long param_1,int param_2,int param_3,ushort param_4)

{
  undefined2 local_a;
  
  local_a = *(short *)(param_1 + 0x92);
  if (param_2 == 0) {
    local_a = *(short *)(param_1 + 0x94) + local_a;
  }
  else if (param_2 == 2) {
    local_a = *(short *)(param_1 + 0x96) + local_a;
  }
  else if (param_2 == 3) {
    local_a = *(short *)(param_1 + 0x98) + local_a;
  }
  else {
    local_a = *(short *)(param_1 + 0x9a) + local_a;
  }
  if (param_3 != 0) {
    local_a = *(short *)(param_1 + 0x9c) + local_a;
  }
  return (short)((int)((int)*(short *)(param_1 + 0x9e) * (uint)param_4) >> 10) + local_a;
}


//===== FUN_0010a247 @ 0010a247 size=265 =====

short FUN_0010a247(long param_1,int param_2,int param_3,ushort param_4)

{
  undefined2 local_c;
  undefined2 local_a;
  
  local_c = *(short *)(param_1 + 0xa0);
  if (param_2 == 0) {
    local_c = *(short *)(param_1 + 0xa2) + local_c;
  }
  else if (param_2 == 3) {
    local_c = *(short *)(param_1 + 0xa4) + local_c;
  }
  else {
    local_c = *(short *)(param_1 + 0xa6) + local_c;
  }
  local_a = (short)param_3 + -1;
  if (4 < local_a) {
    local_a = 4;
  }
  local_c = *(short *)(param_1 + 0xa8) * local_a + local_c;
  if (param_2 + -1 == param_3) {
    local_c = *(short *)(param_1 + 0xaa) + local_c;
  }
  return (short)((int)((int)*(short *)(param_1 + 0xac) * (uint)param_4) >> 10) + local_c;
}


//===== FUN_0010a350 @ 0010a350 size=26 =====

void FUN_0010a350(undefined8 param_1)

{
  FUN_0010a36a(param_1);
  return;
}


//===== FUN_0010a36a @ 0010a36a size=99 =====

void FUN_0010a36a(long param_1)

{
  undefined4 local_c;
  
  *(undefined2 *)(param_1 + 0xc) = 0;
  *(undefined2 *)(param_1 + 0xe) = 0;
  *(undefined2 *)(param_1 + 8) = 0x80;
  *(undefined2 *)(param_1 + 0x20) = 0;
  *(undefined2 *)(param_1 + 0x22) = 4;
  for (local_c = 0; local_c < 4; local_c = local_c + 1) {
    *(undefined2 *)(param_1 + ((long)local_c + 8) * 2) = 600;
  }
  return;
}


//===== FUN_0010a3cd @ 0010a3cd size=25 =====

void FUN_0010a3cd(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return;
}


//===== FUN_0010a3e6 @ 0010a3e6 size=28 =====

void FUN_0010a3e6(long param_1,undefined2 param_2)

{
  *(undefined2 *)(param_1 + 10) = param_2;
  return;
}


//===== FUN_0010a402 @ 0010a402 size=550 =====

int FUN_0010a402(long *param_1)

{
  int iVar1;
  int local_10;
  int local_c;
  
  local_10 = 0;
  for (local_c = 0; local_c < 4; local_c = local_c + 1) {
    if (*(ushort *)((long)param_1 + ((long)local_c + 8) * 2) < 600) {
      iVar1 = (int)*(short *)((long)param_1 + ((long)local_c + 8) * 2 + 8) *
              (int)(short)(*(ushort *)
                            (*param_1 +
                            (ulong)*(ushort *)((long)param_1 + ((long)local_c + 8) * 2) * 2) ^
                          0x3c5a);
      if (iVar1 < 0) {
        iVar1 = iVar1 + 0x1f;
      }
      local_10 = local_10 + (iVar1 >> 5);
      *(short *)((long)param_1 + ((long)local_c + 8) * 2) =
           *(short *)((long)param_1 + ((long)local_c + 8) * 2) + 8;
    }
  }
  *(short *)((long)param_1 + 0xc) = *(short *)((long)param_1 + 0xc) + 8;
  if (*(ushort *)((long)param_1 + 10) <= *(ushort *)((long)param_1 + 0xc)) {
    *(short *)((long)param_1 + 0xc) =
         *(short *)((long)param_1 + 0xc) - *(short *)((long)param_1 + 10);
    if ((short)param_1[1] == 0x80) {
      *(undefined2 *)
       ((long)param_1 + ((long)(int)(uint)*(ushort *)((long)param_1 + 0xe) + 8) * 2 + 8) = 0x80;
    }
    else if ((int)(uint)*(ushort *)(param_1 + 4) < (int)(*(ushort *)((long)param_1 + 0x22) - 1)) {
      *(undefined2 *)
       ((long)param_1 + ((long)(int)(uint)*(ushort *)((long)param_1 + 0xe) + 8) * 2 + 8) = 0x80;
      *(short *)(param_1 + 4) = (short)param_1[4] + 1;
    }
    else {
      *(undefined2 *)(param_1 + 4) = 0;
      *(short *)((long)param_1 + ((long)(int)(uint)*(ushort *)((long)param_1 + 0xe) + 8) * 2 + 8) =
           (short)param_1[1];
      if (*(short *)((long)param_1 + 0x22) == 4) {
        *(undefined2 *)((long)param_1 + 0x22) = 5;
      }
      else {
        *(undefined2 *)((long)param_1 + 0x22) = 4;
      }
    }
    *(undefined2 *)((long)param_1 + ((long)(int)(uint)*(ushort *)((long)param_1 + 0xe) + 8) * 2) =
         *(undefined2 *)((long)param_1 + 0xc);
    *(short *)((long)param_1 + 0xe) = *(short *)((long)param_1 + 0xe) + 1;
    if (3 < *(ushort *)((long)param_1 + 0xe)) {
      *(undefined2 *)((long)param_1 + 0xe) = 0;
    }
  }
  return local_10;
}


//===== FUN_0010a628 @ 0010a628 size=276 =====

int FUN_0010a628(byte *param_1,undefined8 param_2)

{
  int iVar1;
  byte *local_20;
  int local_14;
  undefined4 local_10;
  char local_9;
  
  FUN_00104445(param_2);
  local_9 = '\b';
  local_14 = 0;
  local_20 = param_1;
  while( true ) {
    if ((*local_20 == 0) || (*local_20 < 0x21)) {
      FUN_00104959(param_2);
      FUN_001049f2(param_2);
      FUN_00104bab(param_2);
      FUN_00104d31(param_2);
      FUN_00104ec7(param_2);
      return 0;
    }
    if (*local_20 == 0x3c) {
      iVar1 = FUN_0010a73c(local_20,&local_14,param_2);
    }
    else {
      local_9 = FUN_00103be4(local_20,&local_14);
      if (local_9 == '\0') {
        return 0x69;
      }
      iVar1 = FUN_00104463(param_2,local_9);
    }
    if (iVar1 != 0) break;
    local_20 = local_20 + local_14;
    local_10 = 0;
  }
  return iVar1;
}


//===== FUN_0010a73c @ 0010a73c size=812 =====

ulong FUN_0010a73c(long param_1,int *param_2,undefined8 param_3)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  long local_b8 [4];
  long local_98 [5];
  long local_70;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  long local_50;
  undefined1 local_48 [8];
  long local_40;
  undefined4 local_38;
  undefined2 local_34;
  uint local_28;
  int local_24;
  int local_20;
  
  local_38 = 0x93e3d20;
  local_34 = 10;
  local_28 = 0;
  local_20 = 1;
  while( true ) {
    if (*(char *)(local_20 + param_1) == '\"') {
      local_28 = (uint)(local_28 == 0);
    }
    if ((*(char *)(local_20 + param_1) == '>') && (local_28 == 0)) break;
    if (*(char *)(local_20 + param_1) == '\0') {
      return 0x6b;
    }
    local_20 = local_20 + 1;
  }
  *(undefined1 *)(local_20 + param_1) = 0;
  *param_2 = local_20 + 1;
  local_40 = FUN_00102f6e(param_1 + 1,&local_38,local_48);
  if (local_40 == 0) {
    return 0x6a;
  }
  for (local_24 = 0; iVar1 = local_24, local_24 < 4; local_24 = local_24 + 1) {
    lVar3 = FUN_00102f6e(0,&local_38,local_48);
    local_98[iVar1] = lVar3;
    iVar1 = local_24;
    if ((local_98[local_24] == 0) || (*(char *)local_98[local_24] == '\0')) break;
    lVar3 = FUN_0010aa68(0,&local_38,local_48);
    local_b8[iVar1] = lVar3;
    if (local_b8[local_24] == 0) {
      return 0x6a;
    }
  }
  iVar1 = FUN_00102c13(local_40,&DAT_00112d70);
  if (iVar1 == 0) {
    local_50 = FUN_0010ab26(&DAT_00112d74,local_98,local_b8,local_24);
    if (local_50 == 0) {
      return 0x6a;
    }
    uVar2 = FUN_0010ac24(local_50,param_3);
    return (ulong)uVar2;
  }
  iVar1 = FUN_00102c13(local_40,&DAT_00112d78);
  if (iVar1 == 0) {
    local_58 = FUN_0010ab26(&DAT_00112d74,local_98,local_b8,local_24);
    local_60 = FUN_0010ab26("COUNTER",local_98,local_b8,local_24);
    local_68 = FUN_0010ab26(&DAT_00112d85,local_98,local_b8,local_24);
    if (local_58 == 0) {
      return 0x6a;
    }
    uVar4 = FUN_0010ad54(local_58,local_60,local_68,param_3);
    return uVar4;
  }
  iVar1 = FUN_00102c13(local_40,"ALPHA");
  if (iVar1 != 0) {
    return 0x6a;
  }
  local_70 = FUN_0010ab26(&DAT_00112d74,local_98,local_b8,local_24);
  if (local_70 == 0) {
    return 0x6a;
  }
  uVar4 = FUN_0010272c(local_70,param_3);
  return uVar4;
}


//===== FUN_0010aa68 @ 0010aa68 size=190 =====

char * FUN_0010aa68(long param_1,undefined8 param_2,long *param_3)

{
  uint uVar1;
  char *local_20;
  undefined1 *local_10;
  
  local_20 = (char *)param_1;
  if (param_1 == 0) {
    local_20 = (char *)*param_3;
  }
  if (local_20 == (char *)0x0) {
    local_20 = (char *)0x0;
  }
  else {
    uVar1 = FUN_00102e9a(local_20,param_2);
    local_20 = (char *)((long)local_20 + (ulong)uVar1);
    if (*local_20 == '\"') {
      local_20 = local_20 + 1;
      local_10 = (undefined1 *)FUN_00102dc8(local_20,0x22);
    }
    else {
      local_10 = (undefined1 *)FUN_00102f0f(local_20,param_2);
    }
    if (local_10 == (undefined1 *)0x0) {
      *param_3 = 0;
    }
    else {
      *param_3 = (long)(local_10 + 1);
      *local_10 = 0;
    }
  }
  return local_20;
}


//===== FUN_0010ab26 @ 0010ab26 size=104 =====

undefined8 FUN_0010ab26(undefined8 param_1,long param_2,long param_3,int param_4)

{
  int iVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (param_4 <= local_c) {
      return 0;
    }
    iVar1 = FUN_0010ab8e(param_1,*(undefined8 *)((long)local_c * 8 + param_2));
    if (iVar1 == 0) break;
    local_c = local_c + 1;
  }
  return *(undefined8 *)((long)local_c * 8 + param_3);
}


//===== FUN_0010ab8e @ 0010ab8e size=150 =====

int FUN_0010ab8e(char *param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  char *local_28;
  char *local_20;
  
  local_28 = param_2;
  local_20 = param_1;
  do {
    if ((*local_20 < '[') && ('@' < *local_20)) {
      iVar1 = *local_20 + 0x20;
    }
    else {
      iVar1 = (int)*local_20;
    }
    if ((*local_28 < '[') && ('@' < *local_28)) {
      iVar2 = *local_28 + 0x20;
    }
    else {
      iVar2 = (int)*local_28;
    }
    local_20 = local_20 + 1;
    local_28 = local_28 + 1;
  } while ((iVar1 != 0) && (iVar1 == iVar2));
  return iVar1 - iVar2;
}


//===== FUN_0010ac24 @ 0010ac24 size=304 =====

ulong FUN_0010ac24(char *param_1,undefined8 param_2)

{
  uint uVar1;
  ulong uVar2;
  char *local_20;
  char *local_18;
  
  if (param_1 == (char *)0x0) {
    uVar2 = 100;
  }
  else {
    local_20 = param_1;
    local_18 = param_1;
    if (*param_1 == '\0') {
      uVar2 = 0;
    }
    else {
      for (; *local_18 != '\0'; local_18 = local_18 + 1) {
        if (*local_18 == '.') {
          *local_18 = '\0';
          uVar1 = FUN_0010b157(local_20,param_2);
          if (uVar1 != 0) {
            return (ulong)uVar1;
          }
          uVar1 = FUN_001044b3(param_2,&DAT_00112da0);
          if (uVar1 != 0) {
            return (ulong)uVar1;
          }
          local_20 = local_18 + 1;
        }
        else if (*local_18 == '-') {
          *local_18 = '\0';
          uVar1 = FUN_0010b157(local_20,param_2);
          if (uVar1 != 0) {
            return (ulong)uVar1;
          }
          uVar1 = FUN_00104463(param_2,7);
          if (uVar1 != 0) {
            return (ulong)uVar1;
          }
          local_20 = local_18 + 1;
        }
      }
      uVar2 = FUN_0010b157(local_20,param_2);
    }
  }
  return uVar2;
}


//===== FUN_0010ad54 @ 0010ad54 size=387 =====

ulong FUN_0010ad54(char *param_1,char *param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  ulong uVar2;
  undefined1 *puVar3;
  undefined1 local_28 [12];
  uint local_1c;
  
  if (param_1 == (char *)0x0) {
    uVar2 = 100;
  }
  else if (*param_1 == '\0') {
    uVar2 = 0;
  }
  else {
    puVar3 = (undefined1 *)FUN_00102dc8(param_1,0x2e);
    if (puVar3 == (undefined1 *)0x0) {
      uVar2 = FUN_0010aed7(param_1,param_2,param_3,param_4);
    }
    else {
      *puVar3 = 0;
      FUN_00102d33(local_28,&DAT_001135d0);
      if (*param_1 == '\0') {
        local_1c = FUN_0010b5ae(param_4,&DAT_001135d9,0,local_28,&DAT_001135d5,0);
      }
      else {
        local_1c = FUN_0010aed7(param_1,local_28,&DAT_001135d5,param_4);
      }
      if (local_1c == 0) {
        local_1c = FUN_00104463(param_4,5);
        if (local_1c == 0) {
          local_1c = FUN_0010ac24(puVar3 + 1,param_4);
          if (local_1c == 0) {
            if (((param_2 != (char *)0x0) && (*param_2 != '\0')) &&
               (uVar1 = FUN_00104517(param_4,param_2), uVar1 != 0)) {
              return (ulong)uVar1;
            }
            uVar2 = 0;
          }
          else {
            uVar2 = (ulong)local_1c;
          }
        }
        else {
          uVar2 = (ulong)local_1c;
        }
      }
      else {
        uVar2 = (ulong)local_1c;
      }
    }
  }
  return uVar2;
}


//===== FUN_0010aed7 @ 0010aed7 size=603 =====

ulong FUN_0010aed7(char *param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  char local_38 [4];
  undefined1 local_34;
  int local_2c;
  int local_28;
  int local_24;
  uint local_20;
  int local_1c;
  
  if (param_1 == (char *)0x0) {
    uVar3 = 100;
  }
  else if (*param_1 == '\0') {
    uVar3 = 0;
  }
  else {
    if (param_3 == 0) {
      iVar1 = FUN_0010c599(param_4,param_1,param_2,&local_20);
      if (iVar1 != 0) {
        return (ulong)local_20;
      }
      if (local_20 != 0) {
        return (ulong)local_20;
      }
    }
    local_24 = FUN_00102be4(param_1);
    if ((local_24 == 1) && (*param_1 == '0')) {
      uVar2 = FUN_0010b5ae(param_4,&DAT_001135d9,0,param_2,param_3,0);
      uVar3 = (ulong)uVar2;
    }
    else {
      local_28 = 0;
      local_1c = local_24;
      do {
        local_1c = local_1c + -1;
        if (local_1c < 0) goto LAB_0010afea;
      } while (param_1[local_1c] == '0');
      local_28 = (local_24 - local_1c) + -1;
LAB_0010afea:
      for (local_2c = 0xc; -1 < local_2c; local_2c = local_2c + -4) {
        if (local_2c < local_24) {
          local_34 = 0;
          for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
            if ((local_24 - local_2c) + -4 + local_1c < 0) {
              local_38[local_1c] = '0';
            }
            else {
              local_38[local_1c] = param_1[(local_24 - local_2c) + -4 + local_1c];
            }
            if ((local_38[local_1c] < '0') || ('9' < local_38[local_1c])) {
              return 0x6c;
            }
          }
          if ((local_2c <= local_28) && (local_28 < local_2c + 4)) {
            uVar3 = FUN_0010b940(param_4,local_38,local_2c,param_2,param_3,1);
            return uVar3;
          }
          local_20 = FUN_0010b940(param_4,local_38,local_2c,0,0,0);
          if (local_20 != 0) {
            return (ulong)local_20;
          }
          local_20 = FUN_00104463(param_4,7);
          if (local_20 != 0) {
            return (ulong)local_20;
          }
        }
      }
      uVar3 = 0;
    }
  }
  return uVar3;
}


//===== FUN_0010b132 @ 0010b132 size=37 =====

void FUN_0010b132(undefined8 param_1,undefined8 param_2)

{
  FUN_0010b157(param_1,param_2);
  return;
}


//===== FUN_0010b157 @ 0010b157 size=479 =====

int FUN_0010b157(long param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long local_30;
  int local_20;
  int local_1c [3];
  
  iVar1 = FUN_00102be4(param_1);
  for (local_20 = 0; local_20 < iVar1; local_20 = local_20 + 1) {
    if ((*(char *)(local_20 + param_1) < '0') || ('9' < *(char *)(local_20 + param_1))) {
      return 0x6c;
    }
  }
  local_20 = 0;
  local_30 = param_1;
  while( true ) {
    if (0x13 < local_20) {
      return 100;
    }
    iVar1 = FUN_00102be4(local_30);
    if (iVar1 < 4) {
      FUN_0010b336(iVar1,local_30,0,local_1c,param_2);
      return local_1c[0];
    }
    if (iVar1 == 4) {
      uVar2 = FUN_0010b336(2,local_30,4,local_1c,param_2);
      FUN_0010b336(2,uVar2,0,local_1c,param_2);
      return local_1c[0];
    }
    if (iVar1 == 5) break;
    uVar2 = FUN_0010b336(2,local_30,4,local_1c,param_2);
    if (local_1c[0] != 0) {
      return local_1c[0];
    }
    local_30 = FUN_0010b336(2,uVar2,7,local_1c,param_2);
    if (local_1c[0] != 0) {
      return local_1c[0];
    }
    local_20 = local_20 + 1;
  }
  uVar2 = FUN_0010b336(2,local_30,4,local_1c,param_2);
  FUN_0010b336(3,uVar2,0,local_1c,param_2);
  return local_1c[0];
}


//===== FUN_0010b336 @ 0010b336 size=632 =====

char * FUN_0010b336(int param_1,char *param_2,char param_3,int *param_4,undefined8 param_5)

{
  int iVar1;
  
  *param_4 = 0;
  if (param_1 == 0) {
    return param_2;
  }
  if (param_1 == 1) {
    iVar1 = FUN_001044b3(param_5,&DAT_00112e00 + (long)(*param_2 + -0x30) * 4);
    *param_4 = iVar1;
    if (*param_4 != 0) {
      return param_2;
    }
    param_2 = param_2 + 1;
  }
  else if (param_1 == 2) {
    iVar1 = FUN_001044b3(param_5,&DAT_00112e30 + (long)(*param_2 + -0x30) * 3);
    *param_4 = iVar1;
    if (*param_4 != 0) {
      return param_2;
    }
    iVar1 = FUN_001044b3(param_5,&DAT_00112e60 + (long)(param_2[1] + -0x30) * 4);
    *param_4 = iVar1;
    if (*param_4 != 0) {
      return param_2;
    }
    param_2 = param_2 + 2;
  }
  else {
    iVar1 = FUN_001044b3(param_5,&DAT_00112e30 + (long)(*param_2 + -0x30) * 3);
    *param_4 = iVar1;
    if (*param_4 != 0) {
      return param_2;
    }
    iVar1 = FUN_001044b3(param_5,&DAT_00112e60 + (long)(param_2[1] + -0x30) * 4);
    *param_4 = iVar1;
    if (*param_4 != 0) {
      return param_2;
    }
    iVar1 = FUN_001044b3(param_5,&DAT_00112e30 + (long)(param_2[2] + -0x30) * 3);
    *param_4 = iVar1;
    if (*param_4 != 0) {
      return param_2;
    }
    param_2 = param_2 + 3;
  }
  if (param_3 != '\0') {
    iVar1 = FUN_00104463(param_5,param_3);
    *param_4 = iVar1;
  }
  return param_2;
}


//===== FUN_0010b5ae @ 0010b5ae size=868 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong FUN_0010b5ae(undefined8 param_1,long param_2,undefined4 param_3,long param_4,
                  undefined8 param_5,int param_6)

{
  ulong uVar1;
  undefined *local_50;
  undefined *local_48;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  int local_24;
  uint local_20;
  ushort local_1c;
  ushort local_1a;
  
  local_50 = (undefined *)0x0;
  local_1a = (ushort)param_3 & 3;
  local_1c = (short)*(char *)((int)(3 - (uint)local_1a) + param_2) - 0x30;
  local_2c = FUN_0010b912(param_3,local_1c);
  local_48 = &DAT_00112ea0 + (long)(int)(uint)local_1c * 0xc + (long)(int)(uint)local_1a * 0x78;
  local_24 = (int)*(short *)(&DAT_00112eaa +
                            (long)(int)(uint)local_1c * 0xc + (long)(int)(uint)local_1a * 0x78);
  if ((((param_6 == 0) || (local_2c < 0xd)) || (local_1a != 3)) || (local_1c != 1)) {
    if (local_2c == 0xf) {
      if (local_1a == 0) {
        if ((&PTR_DAT_003166a0)[(long)(int)(uint)local_1c + 0x30] == (undefined *)0x0) {
          local_48 = (&PTR_DAT_003166a0)[(int)(uint)local_1c];
        }
        else {
          local_48 = (&PTR_DAT_003166a0)[(long)(int)(uint)local_1c + 0x30];
        }
      }
      else if (local_1a == 1) {
        local_48 = &DAT_00113080 + (ulong)local_1c * 9;
      }
    }
  }
  else {
    local_48 = &UNK_00113008;
    if (local_2c == 0xf) {
      local_24 = 0;
    }
    else {
      local_24 = (int)_UNK_00113012;
    }
  }
  if (local_2c == 0xd) {
    local_50 = &DAT_001135de;
    uVar1 = FUN_00102be4(local_48);
    local_24 = ((int)(((uint)(uVar1 >> 0x1f) & 1) + (int)uVar1) >> 1) + 1;
  }
  else if (local_2c == 0xe) {
    local_50 = &DAT_001135e3;
    uVar1 = FUN_00102be4(local_48);
    local_24 = (int)(((uint)(uVar1 >> 0x1f) & 1) + (int)uVar1) >> 1;
  }
  else if (local_2c == 0xf) {
    local_50 = &DAT_001135e8;
  }
  local_28 = 0;
  if (param_4 != 0) {
    local_20 = FUN_0010bb45(param_4,&local_3c);
    if (local_20 != 0) {
      return (ulong)local_20;
    }
    local_20 = FUN_0010be71(param_4,local_3c,param_5,&local_30,&local_34,&local_38);
    if (local_20 != 0) {
      return (ulong)local_20;
    }
    local_48 = (undefined *)FUN_0010c04c(local_2c,local_30,local_48,&local_28);
    FUN_0010c161(param_4,local_2c,local_34);
    local_24 = FUN_0010c31f(param_2,local_1a,local_2c,local_48,local_50,param_4,local_38,local_3c);
  }
  uVar1 = FUN_0010bc49(param_1,local_48,local_50,param_4,local_24,local_28);
  return uVar1;
}


//===== FUN_0010b912 @ 0010b912 size=46 =====

int FUN_0010b912(uint param_1,int param_2)

{
  if (param_1 != 0) {
    if (param_1 < 4) {
      param_2 = param_1 + 9;
    }
    else {
      param_2 = (param_1 >> 2) + 0xc;
    }
  }
  return param_2;
}


//===== FUN_0010b940 @ 0010b940 size=517 =====

int FUN_0010b940(undefined8 param_1,long param_2,int param_3,long param_4,undefined8 param_5,
                undefined4 param_6)

{
  int iVar1;
  int local_24;
  int local_1c;
  
  local_24 = 4;
  for (local_1c = 3; -1 < local_1c; local_1c = local_1c + -1) {
    if (*(char *)(local_1c + param_2) != '0') {
      local_24 = local_1c;
      break;
    }
  }
  local_1c = 0;
  do {
    if (3 < local_1c) {
LAB_0010ba6c:
      if ((((param_3 == 0) && (param_4 == 0)) && (*(char *)(param_2 + 2) == '1')) &&
         (*(char *)(param_2 + 3) == '5')) {
        FUN_00104596(param_1,1);
        FUN_00104854(param_1,1);
      }
      else if ((((*(char *)(param_2 + 2) == '1') || (*(char *)(param_2 + 2) == '5')) ||
               ((*(char *)(param_2 + 2) == '6' || (*(char *)(param_2 + 2) == '8')))) &&
              (*(char *)(param_2 + 3) != '0')) {
        if (*(char *)(param_2 + 2) == '1') {
          FUN_00104596(param_1,1);
        }
        else {
          FUN_00104596(param_1,0);
        }
      }
      return 0;
    }
    if (local_1c == local_24) {
      iVar1 = FUN_0010b5ae(param_1,param_2,(param_3 + 3) - local_1c,param_4,param_5,param_6);
      if (iVar1 != 0) {
        return iVar1;
      }
      goto LAB_0010ba6c;
    }
    if (*(char *)(local_1c + param_2) != '0') {
      iVar1 = FUN_0010b5ae(param_1,param_2,3 - local_1c,0,0,0);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_00104463(param_1,4);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
    local_1c = local_1c + 1;
  } while( true );
}


//===== FUN_0010bb45 @ 0010bb45 size=260 =====

undefined8 FUN_0010bb45(char *param_1,int *param_2)

{
  char *pcVar1;
  char *local_28;
  char *local_20;
  int local_14;
  int local_10;
  char local_9;
  
  local_14 = 0;
  *param_2 = 0;
  local_28 = param_1;
  local_20 = param_1;
  while( true ) {
    if (*local_20 == '\0') {
      *local_28 = '\0';
      return 0;
    }
    local_9 = FUN_00103be4(local_20,&local_10);
    if (local_9 == '\0') break;
    if (local_9 == '\x01') {
      *param_2 = local_14;
      pcVar1 = local_28;
    }
    else {
      pcVar1 = (char *)FUN_00104039(local_9);
      *local_28 = *pcVar1;
      local_28[1] = pcVar1[1];
      pcVar1 = local_28 + 2;
      if (*local_28 == 'g') {
        *local_28 = 'v';
      }
      else if (*local_28 == 'G') {
        *local_28 = 'V';
      }
    }
    local_28 = pcVar1;
    local_20 = local_20 + local_10;
    local_14 = local_14 + 1;
  }
  return 0x6a;
}


//===== FUN_0010bc49 @ 0010bc49 size=291 =====

int FUN_0010bc49(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined4 param_5,int param_6)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 local_20;
  int local_1c;
  
  local_20 = 0;
  local_1c = FUN_0010bd6c(param_1,param_2,param_5,&local_20);
  if (local_1c == 0) {
    if (param_6 != 0) {
      iVar2 = FUN_001048e4(param_1);
      iVar3 = iVar2 + -1;
      cVar1 = FUN_0010491e(param_1,iVar3);
      if (cVar1 == '\x01') {
        FUN_001048f7(param_1,iVar2 + -2,1);
        FUN_001048f7(param_1,iVar3,0x97);
      }
      else {
        FUN_001048f7(param_1,iVar3,0x97);
      }
    }
    local_1c = FUN_0010bd6c(param_1,param_3,param_5,&local_20);
    if ((local_1c == 0) &&
       (local_1c = FUN_0010bd6c(param_1,param_4,param_5,&local_20), local_1c == 0)) {
      local_1c = 0;
    }
  }
  return local_1c;
}


//===== FUN_0010bd6c @ 0010bd6c size=261 =====

int FUN_0010bd6c(undefined8 param_1,char *param_2,int param_3,int *param_4)

{
  char cVar1;
  char *local_28;
  int local_10;
  
  local_28 = param_2;
  if (param_2 != (char *)0x0) {
    for (; *local_28 != '\0'; local_28 = local_28 + 2) {
      cVar1 = FUN_00103faf(local_28);
      if (cVar1 == '\0') {
        return 100;
      }
      *param_4 = *param_4 + 1;
      if (*param_4 == param_3) {
        if (((cVar1 == -0x68) || (cVar1 == -0x69)) || (cVar1 == -0x6a)) {
          FUN_00104463(param_1,1);
          local_10 = FUN_00104463(param_1,cVar1);
        }
        else {
          FUN_00104463(param_1,cVar1);
          local_10 = FUN_00104463(param_1,1);
        }
      }
      else {
        local_10 = FUN_00104463(param_1,cVar1);
      }
      if (local_10 != 0) {
        return local_10;
      }
    }
  }
  return 0;
}


//===== FUN_0010be71 @ 0010be71 size=475 =====

undefined8
FUN_0010be71(undefined8 param_1,int param_2,char *param_3,int *param_4,int *param_5,int *param_6)

{
  int iVar1;
  undefined8 uVar2;
  int local_c;
  
  *param_6 = 0;
  *param_5 = *param_6;
  *param_4 = *param_5;
  if (param_3 == (char *)0x0) {
    local_c = 0;
    while ((local_c < 0x1b &&
           ((*(int *)(&DAT_00113138 + (long)local_c * 0x1c) != param_2 ||
            (iVar1 = FUN_00102c13(param_1,&DAT_00113120 + (long)local_c * 0x1c), iVar1 != 0))))) {
      local_c = local_c + 1;
    }
    if (local_c < 0x1b) {
      *param_4 = *(int *)(&DAT_0011312c + (long)local_c * 0x1c);
      *param_5 = *(int *)(&DAT_00113130 + (long)local_c * 0x1c);
      *param_6 = *(int *)(&DAT_00113134 + (long)local_c * 0x1c);
    }
    uVar2 = 0;
  }
  else {
    *param_4 = *param_3 + -0x41;
    if ((((*param_4 < 0) || (0x13 < *param_4)) || (*param_5 = param_3[1] + -0x61, *param_5 < 0)) ||
       (((0xf < *param_5 || (*param_6 = param_3[2] + -0x41, *param_6 < 0)) || (0xf < *param_6)))) {
      uVar2 = 0x6a;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


//===== FUN_0010c04c @ 0010c04c size=277 =====

undefined * FUN_0010c04c(int param_1,int param_2,undefined *param_3,undefined4 *param_4)

{
  *param_4 = 0;
  if ((param_2 != 0) && (param_1 < 0xc)) {
    if (param_1 < 10) {
      if ((&PTR_DAT_003166a0)[(long)param_2 * 0xc + (long)param_1] != (undefined *)0x0) {
        param_3 = (&PTR_DAT_003166a0)[(long)param_2 * 0xc + (long)param_1];
      }
    }
    else if (param_1 == 10) {
      if ((&PTR_DAT_003166f0)[(long)param_2 * 0xc] != (undefined *)0x0) {
        *param_4 = 1;
      }
    }
    else if ((&PTR_DAT_003166f8)[(long)param_2 * 0xc] != (undefined *)0x0) {
      *param_4 = 1;
    }
  }
  return param_3;
}


//===== FUN_0010c161 @ 0010c161 size=128 =====

void FUN_0010c161(undefined8 param_1,int param_2,int param_3)

{
  if ((((0 < param_3) && (param_3 < 5)) && (0 < param_2)) && (param_2 < 0x10)) {
    if ((&DAT_001134a0)[(long)param_2 * 5 + (long)param_3] == '\x01') {
      FUN_0010c1e1(param_1);
    }
    else if ((&DAT_001134a0)[(long)param_2 * 5 + (long)param_3] == '\x02') {
      FUN_0010c295(param_1);
    }
  }
  return;
}


//===== FUN_0010c1e1 @ 0010c1e1 size=180 =====

void FUN_0010c1e1(char *param_1)

{
  if ((*param_1 == 'w') && (param_1[1] == 'a')) {
    *param_1 = 'b';
    param_1[1] = 'a';
  }
  else {
    switch(*param_1) {
    case 'H':
      *param_1 = 'B';
      break;
    case 'K':
      *param_1 = 'V';
      break;
    case 'S':
      *param_1 = 'j';
      break;
    case 'c':
      *param_1 = 'j';
      break;
    case 'h':
      *param_1 = 'b';
      break;
    case 'k':
      *param_1 = 'v';
      break;
    case 's':
      *param_1 = 'z';
      break;
    case 't':
      *param_1 = 'd';
    }
  }
  return;
}


//===== FUN_0010c295 @ 0010c295 size=138 =====

void FUN_0010c295(char *param_1)

{
  if ((*param_1 == 'w') && (param_1[1] == 'a')) {
    *param_1 = 'p';
    param_1[1] = 'a';
  }
  else if ((*param_1 == 'f') && (param_1[1] == 'u')) {
    *param_1 = 'p';
    param_1[1] = 'u';
  }
  else if (*param_1 == 'H') {
    *param_1 = 'P';
  }
  else if (*param_1 == 'h') {
    *param_1 = 'p';
  }
  return;
}


//===== FUN_0010c31f @ 0010c31f size=634 =====

uint FUN_0010c31f(char *param_1,int param_2,int param_3,undefined8 param_4,long param_5,long param_6
                 ,int param_7,int param_8)

{
  int iVar1;
  int iVar2;
  int local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  int local_10;
  
  if (param_7 == 0) {
    if (param_8 == 0) {
      local_20 = 0;
    }
    else {
      local_18 = FUN_00102be4(param_4);
      if (param_5 != 0) {
        iVar1 = FUN_00102be4(param_5);
        local_18 = local_18 + iVar1;
      }
      local_20 = (local_18 >> 1) + param_8;
    }
  }
  else {
    iVar1 = param_1[3 - param_2] + -0x30;
    local_10 = param_3;
    if (9 < param_3) {
      if ((param_3 < 0xc) && (iVar1 == 1)) {
        local_10 = 10;
      }
      else if ((param_3 < 0xc) && (iVar1 != 1)) {
        local_10 = 0xb;
      }
      else {
        if ((param_3 != 0xc) || (iVar1 != 1)) {
          if ((param_3 == 0xc) && (iVar1 != 1)) {
            return 0;
          }
          if ((((param_1[2] != '1') || (param_1[3] == '0')) &&
              ((param_1[2] == '0' || ((param_1[2] == '1' || (param_1[3] != '0')))))) &&
             ((*param_1 < '1' ||
              (((param_1[1] != '0' || (param_1[2] != '0')) || (param_1[3] != '0')))))) {
            return 0;
          }
          local_1c = FUN_00102be4(param_4);
          if (param_5 != 0) {
            iVar1 = FUN_00102be4(param_5);
            local_1c = local_1c + iVar1;
          }
          return (local_1c >> 1) - 1;
        }
        local_10 = 0xc;
      }
    }
    iVar2 = (int)(char)(&DAT_00113500)[(long)param_7 * 0xd + (long)local_10];
    if (iVar2 == -1) {
      local_20 = FUN_00102be4(param_4);
      if (param_5 != 0) {
        iVar1 = FUN_00102be4(param_5);
        local_20 = local_20 + iVar1;
      }
      if (param_6 != 0) {
        iVar1 = FUN_00102be4(param_6);
        local_20 = local_20 + iVar1;
      }
      local_20 = local_20 >> 1;
    }
    else if (iVar2 == 0) {
      local_20 = 0;
    }
    else {
      local_24 = 0;
      if (((9 < param_3) && (param_3 < 0xd)) && (iVar1 != 1)) {
        local_24 = *(int *)(&DAT_001130e0 + (long)iVar1 * 4);
      }
      local_20 = local_24 + iVar2;
    }
  }
  return local_20;
}


//===== FUN_0010c599 @ 0010c599 size=1002 =====

undefined8 FUN_0010c599(undefined8 param_1,char *param_2,char *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  char *local_18;
  
  *param_4 = 0;
  if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
    return 0;
  }
  iVar1 = FUN_00102c13(param_3,&DAT_001136a4);
  if (iVar1 == 0) {
    iVar1 = FUN_00102c13(param_2,&DAT_001136a9);
    if (iVar1 == 0) {
      uVar2 = FUN_001044b3(param_1,&DAT_00112da4);
      *param_4 = uVar2;
      return 1;
    }
    iVar1 = FUN_00102c13(param_2,&DAT_001136ab);
    if (iVar1 == 0) {
      uVar2 = FUN_001044b3(param_1,&DAT_00112da9);
      *param_4 = uVar2;
      return 1;
    }
  }
  else {
    iVar1 = FUN_00102c13(param_3,&DAT_001136ad);
    local_18 = param_2;
    if (iVar1 == 0) {
      for (; *local_18 == '0'; local_18 = local_18 + 1) {
      }
      iVar1 = FUN_00102c13(local_18,&DAT_001136a9);
      if (iVar1 == 0) {
        uVar2 = FUN_001044b3(param_1,&DAT_00112dad);
        *param_4 = uVar2;
        return 1;
      }
      iVar1 = FUN_00102c13(local_18,&DAT_001136ab);
      if (iVar1 == 0) {
        uVar2 = FUN_001044b3(param_1,&DAT_00112db2);
        *param_4 = uVar2;
        return 1;
      }
      iVar1 = FUN_00102c13(local_18,&DAT_001136b2);
      if (iVar1 == 0) {
        uVar2 = FUN_001044b3(param_1,&DAT_00112db6);
        *param_4 = uVar2;
        return 1;
      }
      iVar1 = FUN_00102c13(local_18,&DAT_001136b4);
      if (iVar1 == 0) {
        uVar2 = FUN_001044b3(param_1,&DAT_00112dba);
        *param_4 = uVar2;
        return 1;
      }
      iVar1 = FUN_00102c13(local_18,&DAT_001136b6);
      if (iVar1 == 0) {
        uVar2 = FUN_001044b3(param_1,&DAT_00112dbe);
        *param_4 = uVar2;
        return 1;
      }
      iVar1 = FUN_00102c13(local_18,&DAT_001136b8);
      if (iVar1 == 0) {
        uVar2 = FUN_001044b3(param_1,&DAT_00112dc2);
        *param_4 = uVar2;
        return 1;
      }
      iVar1 = FUN_00102c13(local_18,&DAT_001136ba);
      if (iVar1 == 0) {
        uVar2 = FUN_001044b3(param_1,&DAT_00112dc6);
        *param_4 = uVar2;
        return 1;
      }
      iVar1 = FUN_00102c13(local_18,&DAT_001136bc);
      if (iVar1 == 0) {
        uVar2 = FUN_001044b3(param_1,&DAT_00112dca);
        *param_4 = uVar2;
        return 1;
      }
      iVar1 = FUN_00102c13(local_18,&DAT_001136be);
      if (iVar1 == 0) {
        uVar2 = FUN_001044b3(param_1,&DAT_00112dce);
        *param_4 = uVar2;
        return 1;
      }
      iVar1 = FUN_00102c13(local_18,&DAT_001136c0);
      if (iVar1 == 0) {
        uVar2 = FUN_001044b3(param_1,&DAT_00112dd3);
        *param_4 = uVar2;
        return 1;
      }
      iVar1 = FUN_00102c13(local_18,&DAT_001136c3);
      if (iVar1 == 0) {
        uVar2 = FUN_001044b3(param_1,&DAT_00112dd7);
        *param_4 = uVar2;
        return 1;
      }
      iVar1 = FUN_00102c13(local_18,&DAT_001136c6);
      if (iVar1 == 0) {
        uVar2 = FUN_001044b3(param_1,&DAT_00112dde);
        *param_4 = uVar2;
        return 1;
      }
      iVar1 = FUN_00102c13(local_18,&DAT_001136c9);
      if (iVar1 == 0) {
        uVar2 = FUN_001044b3(param_1,&DAT_00112de2);
        *param_4 = uVar2;
        return 1;
      }
    }
  }
  return 0;
}


//===== FUN_0010c990 @ 0010c990 size=53 =====

void FUN_0010c990(void)

{
  code *pcVar1;
  long *plVar2;
  
  if (DAT_00316670 != (code *)0xffffffffffffffff) {
    plVar2 = (long *)&DAT_00316670;
    pcVar1 = DAT_00316670;
    do {
      plVar2 = plVar2 + -1;
      (*pcVar1)();
      pcVar1 = (code *)*plVar2;
    } while (pcVar1 != (code *)0xffffffffffffffff);
  }
  return;
}


//===== _DT_FINI @ 0010c9c8 size=14 =====

void _DT_FINI(void)

{
  FUN_00100de0();
  return;
}


//===== __gmon_start__ @ 00318000 size=1 =====

/* WARNING: Control flow encountered bad instruction data */

void __gmon_start__(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== _Jv_RegisterClasses @ 00318008 size=1 =====

/* WARNING: Control flow encountered bad instruction data */

void _Jv_RegisterClasses(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== malloc @ 00318010 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== free @ 00318018 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== __cxa_finalize @ 00318020 size=1 =====

/* WARNING: Control flow encountered bad instruction data */

void __cxa_finalize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== memcpy @ 00318028 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


