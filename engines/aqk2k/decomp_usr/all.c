//===== _DT_INIT @ 00104000 size=27 =====

void _DT_INIT(void)

{
  if (PTR___gmon_start___00132fd8 != (undefined *)0x0) {
    (*(code *)PTR___gmon_start___00132fd8)();
  }
  return;
}


//===== FUN_00104020 @ 00104020 size=13 =====

void FUN_00104020(void)

{
  (*(code *)PTR_00133010)();
  return;
}


//===== __cxa_finalize @ 001043a0 size=11 =====

void __cxa_finalize(void)

{
  (*(code *)PTR___cxa_finalize_00132fc0)();
  return;
}


//===== operator.new[] @ 001043b0 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * operator_new__(ulong param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_operator_new___00133018)();
  return pvVar1;
}


//===== _M_append @ 001043c0 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__cxx11::string::_M_append(char *param_1,ulong param_2)

{
  (*(code *)PTR__M_append_00133020)();
  return;
}


//===== write @ 001043d0 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t write(int __fd,void *__buf,size_t __n)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_write_00133028)();
  return sVar1;
}


//===== __throw_bad_alloc @ 001043e0 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__throw_bad_alloc(void)

{
  (*(code *)PTR___throw_bad_alloc_00133030)();
  return;
}


//===== strchr @ 001043f0 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strchr(char *__s,int __c)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strchr_00133038)();
  return pcVar1;
}


//===== __cxa_begin_catch @ 00104400 size=11 =====

void __cxa_begin_catch(void)

{
  (*(code *)PTR___cxa_begin_catch_00133040)();
  return;
}


//===== strlen @ 00104410 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_strlen_00133048)();
  return sVar1;
}


//===== strncmp @ 00104420 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strncmp_00133050)();
  return iVar1;
}


//===== __cxa_allocate_exception @ 00104430 size=11 =====

void __cxa_allocate_exception(void)

{
  (*(code *)PTR___cxa_allocate_exception_00133058)();
  return;
}


//===== __throw_length_error @ 00104440 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__throw_length_error(char *param_1)

{
  (*(code *)PTR___throw_length_error_00133060)();
  return;
}


//===== memset @ 00104450 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memset_00133068)();
  return pvVar1;
}


//===== munmap @ 00104460 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int munmap(void *__addr,size_t __len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_munmap_00133070)();
  return iVar1;
}


//===== operator.delete @ 00104470 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void operator_delete(void *param_1,nothrow_t *param_2)

{
  (*(code *)PTR_operator_delete_00133078)();
  return;
}


//===== __throw_logic_error @ 00104480 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__throw_logic_error(char *param_1)

{
  (*(code *)PTR___throw_logic_error_00133080)();
  return;
}


//===== __throw_bad_array_new_length @ 00104490 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__throw_bad_array_new_length(void)

{
  (*(code *)PTR___throw_bad_array_new_length_00133088)();
  return;
}


//===== memcpy @ 001044a0 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memcpy_00133090)();
  return pvVar1;
}


//===== perror @ 001044b0 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void perror(char *__s)

{
  (*(code *)PTR_perror_00133098)();
  return;
}


//===== __cxa_atexit @ 001044c0 size=11 =====

void __cxa_atexit(void)

{
  (*(code *)PTR___cxa_atexit_001330a0)();
  return;
}


//===== operator.delete @ 001044d0 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void operator_delete(void *param_1)

{
  (*(code *)PTR_operator_delete_001330a8)();
  return;
}


//===== mmap64 @ 001044e0 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * mmap64(void *__addr,size_t __len,int __prot,int __flags,int __fd,__off64_t __offset)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_mmap64_001330b0)();
  return pvVar1;
}


//===== fclose @ 001044f0 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fclose(FILE *__stream)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fclose_001330b8)();
  return iVar1;
}


//===== operator.new @ 00104500 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * operator_new(ulong param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_operator_new_001330c0)();
  return pvVar1;
}


//===== fseek @ 00104510 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fseek(FILE *__stream,long __off,int __whence)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fseek_001330c8)();
  return iVar1;
}


//===== __stack_chk_fail @ 00104520 size=11 =====

void __stack_chk_fail(void)

{
  (*(code *)PTR___stack_chk_fail_001330d0)();
  return;
}


//===== fopen64 @ 00104530 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * fopen64(char *__filename,char *__modes)

{
  FILE *pFVar1;
  
  pFVar1 = (FILE *)(*(code *)PTR_fopen64_001330d8)();
  return pFVar1;
}


//===== _M_construct @ 00104540 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__cxx11::string::_M_construct(ulong param_1,char param_2)

{
  (*(code *)PTR__M_construct_001330e0)();
  return;
}


//===== fflush @ 00104550 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fflush(FILE *__stream)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fflush_001330e8)();
  return iVar1;
}


//===== free @ 00104560 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
  (*(code *)PTR_free_001330f0)();
  return;
}


//===== read @ 00104570 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::istream::read(char *param_1,long param_2)

{
  (*(code *)PTR_read_001330f8)();
  return;
}


//===== operator.delete[] @ 00104580 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void operator_delete__(void *param_1)

{
  (*(code *)PTR_operator_delete___00133100)();
  return;
}


//===== write @ 00104590 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::ostream::write(char *param_1,long param_2)

{
  (*(code *)PTR_write_00133108)();
  return;
}


//===== malloc @ 001045a0 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_malloc_00133110)();
  return pvVar1;
}


//===== strcmp @ 001045b0 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strcmp_00133118)();
  return iVar1;
}


//===== strtol @ 001045c0 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long strtol(char *__nptr,char **__endptr,int __base)

{
  long lVar1;
  
  lVar1 = (*(code *)PTR_strtol_00133120)();
  return lVar1;
}


//===== read @ 001045d0 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_read_00133128)();
  return sVar1;
}


//===== __cxa_rethrow @ 001045e0 size=11 =====

void __cxa_rethrow(void)

{
  (*(code *)PTR___cxa_rethrow_00133130)();
  return;
}


//===== fread @ 001045f0 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t fread(void *__ptr,size_t __size,size_t __n,FILE *__stream)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_fread_00133138)();
  return sVar1;
}


//===== __throw_out_of_range_fmt @ 00104600 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__throw_out_of_range_fmt(char *param_1,...)

{
  (*(code *)PTR___throw_out_of_range_fmt_00133140)();
  return;
}


//===== Init @ 00104610 size=11 =====

void __thiscall std::ios_base::Init::Init(Init *this)

{
  (*(code *)PTR_Init_00133148)();
  return;
}


//===== _M_replace @ 00104620 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__cxx11::string::_M_replace(ulong param_1,ulong param_2,char *param_3,ulong param_4)

{
  (*(code *)PTR__M_replace_00133150)();
  return;
}


//===== fgets @ 00104630 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * fgets(char *__s,int __n,FILE *__stream)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_fgets_00133158)();
  return pcVar1;
}


//===== memmove @ 00104640 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memmove(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memmove_00133160)();
  return pvVar1;
}


//===== __cxa_end_catch @ 00104650 size=11 =====

void __cxa_end_catch(void)

{
  (*(code *)PTR___cxa_end_catch_00133168)();
  return;
}


//===== operator.new[] @ 00104660 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * operator_new__(ulong param_1,nothrow_t *param_2)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_operator_new___00133170)();
  return pvVar1;
}


//===== __fprintf_chk @ 00104670 size=11 =====

void __fprintf_chk(void)

{
  (*(code *)PTR___fprintf_chk_00133178)();
  return;
}


//===== __cxa_throw @ 00104680 size=11 =====

void __cxa_throw(void)

{
  (*(code *)PTR___cxa_throw_00133180)();
  return;
}


//===== stat64 @ 00104690 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int stat64(char *__file,stat64 *__buf)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_stat64_00133188)();
  return iVar1;
}


//===== open64 @ 001046a0 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int open64(char *__file,int __oflag,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_open64_00133190)();
  return iVar1;
}


//===== _Unwind_Resume @ 001046b0 size=11 =====

void _Unwind_Resume(void)

{
  (*(code *)PTR__Unwind_Resume_00133198)();
  return;
}


//===== _M_create @ 001046c0 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__cxx11::string::_M_create(ulong *param_1,ulong param_2)

{
  (*(code *)PTR__M_create_001331a0)();
  return;
}


//===== ~exception @ 001046d0 size=11 =====

void __thiscall std::exception::~exception(exception *this)

{
  (*(code *)PTR__exception_001331a8)();
  return;
}


//===== _M_replace_aux @ 001046e0 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__cxx11::string::_M_replace_aux(ulong param_1,ulong param_2,ulong param_3,char param_4)

{
  (*(code *)PTR__M_replace_aux_001331b0)();
  return;
}


//===== fwrite @ 001046f0 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t fwrite(void *__ptr,size_t __size,size_t __n,FILE *__s)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_fwrite_001331b8)();
  return sVar1;
}


//===== close @ 00104700 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_close_001331c0)();
  return iVar1;
}


//===== operator.new @ 00104710 size=11 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * operator_new(ulong param_1,nothrow_t *param_2)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_operator_new_001331c8)();
  return pvVar1;
}


//===== FUN_00104720 @ 00104720 size=63 =====

void FUN_00104720(void)

{
  void *in_stack_00000010;
  undefined1 *in_stack_00000030;
  undefined1 *in_stack_00000050;
  
  if (in_stack_00000010 != (void *)0x0) {
    operator_delete(in_stack_00000010);
  }
  if (in_stack_00000030 != &stack0x00000040) {
    operator_delete(in_stack_00000030);
  }
  if (in_stack_00000050 != &stack0x00000060) {
    operator_delete(in_stack_00000050);
  }
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume();
}


//===== FUN_0010475f @ 0010475f size=66 =====

void FUN_0010475f(void)

{
  void *in_stack_00000008;
  void *in_stack_00000010;
  void *in_stack_00000050;
  void *in_stack_00000070;
  
  FUN_0010ac40();
  FUN_00108c60();
  FUN_0010cf90();
  if (in_stack_00000070 != in_stack_00000008) {
    operator_delete(in_stack_00000070);
  }
  if (in_stack_00000050 != in_stack_00000010) {
    operator_delete(in_stack_00000050);
  }
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume();
}


//===== FUN_001047a1 @ 001047a1 size=75 =====

void FUN_001047a1(void)

{
  void *unaff_retaddr;
  void *in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  void *in_stack_00000070;
  void *in_stack_00000090;
  
  FUN_0010ac40(in_stack_00000010);
  FUN_00108c60(in_stack_00000018);
  FUN_0010cf90();
  if (in_stack_00000090 != in_stack_00000008) {
    operator_delete(in_stack_00000090);
  }
  if (in_stack_00000070 != unaff_retaddr) {
    operator_delete(in_stack_00000070);
  }
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume();
}


//===== FUN_001047fd @ 001047fd size=22 =====

void FUN_001047fd(void)

{
  void *unaff_RBX;
  void *unaff_retaddr;
  
  if (unaff_retaddr != unaff_RBX) {
    operator_delete(unaff_retaddr);
  }
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume();
}


//===== FUN_00104814 @ 00104814 size=88 =====

undefined8 FUN_00104814(void)

{
  void *unaff_R12;
  undefined8 *unaff_R13;
  long in_FS_OFFSET;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000030;
  void *in_stack_00000038;
  void *in_stack_00000050;
  void *in_stack_000000a0;
  long in_stack_00000178;
  
  if (in_stack_00000050 != (void *)*unaff_R13) {
    operator_delete((void *)*unaff_R13);
  }
  FUN_0010c2d0(in_stack_00000020);
  if (in_stack_000000a0 != in_stack_00000038) {
    operator_delete(in_stack_000000a0);
  }
  FUN_0010e3d0(in_stack_00000030);
  __cxa_begin_catch();
  free(unaff_R12);
  __cxa_end_catch();
  FUN_0010e700();
  if (in_stack_00000178 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0x195;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_00104892 @ 00104892 size=23 =====

void FUN_00104892(void)

{
  void *in_stack_00000040;
  
  if (in_stack_00000040 != (void *)0x0) {
    operator_delete(in_stack_00000040);
  }
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume();
}


//===== FUN_001048aa @ 001048aa size=26 =====

void FUN_001048aa(void)

{
  undefined8 in_stack_00000040;
  
  FUN_0010e3d0(in_stack_00000040);
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume();
}


//===== FUN_001048ea @ 001048ea size=57 =====

/* WARNING: Removing unreachable block (ram,0x0010490a) */

undefined8 FUN_001048ea(void)

{
  long in_FS_OFFSET;
  long in_stack_000000a8;
  
  FUN_0010c310();
  FUN_0010e700();
  __cxa_begin_catch();
  __cxa_end_catch();
  if (in_stack_000000a8 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0x193;
}


//===== FUN_0010493e @ 0010493e size=22 =====

void FUN_0010493e(void)

{
  undefined8 *unaff_R12;
  void *unaff_R15;
  
  if (unaff_R15 != (void *)*unaff_R12) {
    operator_delete((void *)*unaff_R12);
  }
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume();
}


//===== FUN_00104954 @ 00104954 size=22 =====

void FUN_00104954(void)

{
  undefined8 *unaff_R12;
  void *unaff_R15;
  
  if (unaff_R15 != (void *)*unaff_R12) {
    operator_delete((void *)*unaff_R12);
  }
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume();
}


//===== FUN_0010496a @ 0010496a size=22 =====

void FUN_0010496a(void)

{
  void *unaff_RBP;
  undefined8 *unaff_R12;
  
  if (unaff_RBP != (void *)*unaff_R12) {
    operator_delete((void *)*unaff_R12);
  }
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume();
}


//===== FUN_00104980 @ 00104980 size=22 =====

void FUN_00104980(void)

{
  void *unaff_RBP;
  undefined8 *unaff_R12;
  
  if (unaff_RBP != (void *)*unaff_R12) {
    operator_delete((void *)*unaff_R12);
  }
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume();
}


//===== FUN_00104996 @ 00104996 size=44 =====

void FUN_00104996(void)

{
  void *unaff_retaddr;
  undefined1 *in_stack_00000020;
  void *in_stack_00000040;
  
  if (in_stack_00000020 != &stack0x00000030) {
    operator_delete(in_stack_00000020);
  }
  if (in_stack_00000040 != unaff_retaddr) {
    operator_delete(in_stack_00000040);
  }
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume();
}


//===== FUN_001049c2 @ 001049c2 size=70 =====

undefined8 FUN_001049c2(void)

{
  long in_FS_OFFSET;
  FILE *in_stack_00000020;
  undefined1 *in_stack_00000060;
  long in_stack_000004d8;
  
  if (in_stack_00000060 != &stack0x00000070) {
    operator_delete(in_stack_00000060);
  }
  FUN_0010c2d0(&stack0x00000080);
  __cxa_begin_catch();
  fclose(in_stack_00000020);
  __cxa_end_catch();
  if (in_stack_000004d8 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0x1f6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_00104a36 @ 00104a36 size=93 =====

void FUN_00104a36(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x20000000d;
  puVar1[3] = "../src_udic/marisa_u/agent.cpp:13: MARISA_NULL_ERROR: str == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/agent.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00104a94 @ 00104a94 size=93 =====

void FUN_00104a94(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x200000015;
  puVar1[3] = "../src_udic/marisa_u/agent.cpp:21: MARISA_NULL_ERROR: (ptr == NULL) && (length != 0)"
  ;
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/agent.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00104af2 @ 00104af2 size=66 =====

void FUN_00104af2(void)

{
  undefined8 *puVar1;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = in_stack_00000010;
  puVar1[1] = in_stack_00000018;
  puVar1[2] = 0x600000013;
  puVar1[3] = 
  "../src_udic/marisa_u/scoped-ptr.h:19: MARISA_RESET_ERROR: (ptr != NULL) && (ptr == ptr_)";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00104b74 @ 00104b74 size=65 =====

void FUN_00104b74(void)

{
  undefined8 *puVar1;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = unaff_retaddr;
  puVar1[1] = in_stack_00000008;
  puVar1[2] = 0x800000026;
  puVar1[3] = "../src_udic/marisa_u/agent.cpp:38: MARISA_MEMORY_ERROR: state_.get() == NULL";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00104bb6 @ 00104bb6 size=16 =====

void FUN_00104bb6(void)

{
  FUN_0010e3d0();
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume();
}


//===== FUN_00104bc6 @ 00104bc6 size=69 =====

void FUN_00104bc6(undefined8 param_1)

{
  undefined8 *puVar1;
  undefined8 in_XMM0_Qb;
  undefined8 uStack0000000000000008;
  
  uStack0000000000000008 = in_XMM0_Qb;
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = param_1;
  puVar1[1] = uStack0000000000000008;
  puVar1[2] = 0x200000046;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:70: MARISA_NULL_ERROR: filename == NULL";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00104c60 @ 00104c60 size=69 =====

void FUN_00104c60(undefined8 param_1)

{
  undefined8 *puVar1;
  undefined8 in_XMM0_Qb;
  undefined8 uStack0000000000000008;
  
  uStack0000000000000008 = in_XMM0_Qb;
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = param_1;
  puVar1[1] = uStack0000000000000008;
  puVar1[2] = 0x50000004f;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:79: MARISA_CODE_ERROR: fd == -1";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00104cf8 @ 00104cf8 size=92 =====

void FUN_00104cf8(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x100000057;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:87: MARISA_STATE_ERROR: trie_.get() == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00104d54 @ 00104d54 size=92 =====

void FUN_00104d54(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x10000005f;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:95: MARISA_STATE_ERROR: trie_.get() == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00104db0 @ 00104db0 size=92 =====

void FUN_00104db0(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x100000067;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:103: MARISA_STATE_ERROR: trie_.get() == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00104e0c @ 00104e0c size=92 =====

void FUN_00104e0c(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x10000006f;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:111: MARISA_STATE_ERROR: trie_.get() == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00104e68 @ 00104e68 size=93 =====

void FUN_00104e68(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x100000077;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:119: MARISA_STATE_ERROR: trie_.get() == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00104ec6 @ 00104ec6 size=92 =====

void FUN_00104ec6(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x10000007c;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:124: MARISA_STATE_ERROR: trie_.get() == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00104f22 @ 00104f22 size=93 =====

void FUN_00104f22(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x100000081;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:129: MARISA_STATE_ERROR: trie_.get() == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00104f80 @ 00104f80 size=91 =====

void FUN_00104f80(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x100000086;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:134: MARISA_STATE_ERROR: trie_.get() == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00104fdc @ 00104fdc size=93 =====

void FUN_00104fdc(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x10000008b;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:139: MARISA_STATE_ERROR: trie_.get() == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_0010503a @ 0010503a size=92 =====

void FUN_0010503a(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x100000090;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:144: MARISA_STATE_ERROR: trie_.get() == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00105096 @ 00105096 size=93 =====

void FUN_00105096(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x100000095;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:149: MARISA_STATE_ERROR: trie_.get() == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_001050f4 @ 001050f4 size=91 =====

void FUN_001050f4(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x10000009a;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:154: MARISA_STATE_ERROR: trie_.get() == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00105150 @ 00105150 size=93 =====

void FUN_00105150(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x10000009f;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:159: MARISA_STATE_ERROR: trie_.get() == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_001051ae @ 001051ae size=16 =====

void FUN_001051ae(void)

{
  FUN_0010e700();
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume();
}


//===== FUN_001051be @ 001051be size=69 =====

void FUN_001051be(undefined8 param_1)

{
  undefined8 *puVar1;
  undefined8 in_XMM0_Qb;
  undefined8 uStack0000000000000008;
  
  uStack0000000000000008 = in_XMM0_Qb;
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = param_1;
  puVar1[1] = uStack0000000000000008;
  puVar1[2] = 0x1000000c1;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:193: MARISA_STATE_ERROR: trie.trie_.get() == NULL";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00105257 @ 00105257 size=92 =====

void FUN_00105257(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x1000000d5;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:213: MARISA_STATE_ERROR: trie.trie_.get() == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_001052c4 @ 001052c4 size=100 =====

void FUN_001052c4(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x80000000e;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:14: MARISA_MEMORY_ERROR: temp.get() == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00105356 @ 00105356 size=74 =====

void FUN_00105356(void)

{
  undefined8 *puVar1;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  undefined8 uStack0000000000000018;
  
  uStack0000000000000018 = 0;
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = unaff_retaddr;
  puVar1[1] = in_stack_00000008;
  puVar1[2] = 0x800000018;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:24: MARISA_MEMORY_ERROR: temp.get() == NULL";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_0010541c @ 0010541c size=74 =====

void FUN_0010541c(void)

{
  undefined8 *puVar1;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  undefined8 uStack0000000000000018;
  
  uStack0000000000000018 = 0;
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = unaff_retaddr;
  puVar1[1] = in_stack_00000008;
  puVar1[2] = 0x800000024;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:36: MARISA_MEMORY_ERROR: temp.get() == NULL";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_001054e2 @ 001054e2 size=73 =====

void FUN_001054e2(void)

{
  undefined8 *puVar1;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  undefined8 uStack0000000000000018;
  
  uStack0000000000000018 = 0;
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = unaff_retaddr;
  puVar1[1] = in_stack_00000008;
  puVar1[2] = 0x800000030;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:48: MARISA_MEMORY_ERROR: temp.get() == NULL";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_001055a6 @ 001055a6 size=74 =====

void FUN_001055a6(void)

{
  undefined8 *puVar1;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  undefined8 uStack0000000000000018;
  
  uStack0000000000000018 = 0;
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = unaff_retaddr;
  puVar1[1] = in_stack_00000008;
  puVar1[2] = 0x80000003c;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:60: MARISA_MEMORY_ERROR: temp.get() == NULL";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_0010566b @ 0010566b size=26 =====

void FUN_0010566b(void)

{
  FUN_00110710();
  FUN_0010f430(&stack0x00000018);
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume();
}


//===== FUN_00105771 @ 00105771 size=74 =====

void FUN_00105771(void)

{
  undefined8 *puVar1;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  undefined8 uStack0000000000000018;
  
  uStack0000000000000018 = 0;
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = unaff_retaddr;
  puVar1[1] = in_stack_00000008;
  puVar1[2] = 0x8000000cc;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:204: MARISA_MEMORY_ERROR: temp.get() == NULL";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00105836 @ 00105836 size=16 =====

void FUN_00105836(void)

{
  FUN_0010c310();
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume();
}


//===== FUN_00105846 @ 00105846 size=65 =====

void FUN_00105846(void)

{
  undefined8 *puVar1;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = unaff_retaddr;
  puVar1[1] = in_stack_00000008;
  puVar1[2] = 0x8000000a9;
  puVar1[3] = "../src_udic/marisa_u/keyset.cpp:169: MARISA_MEMORY_ERROR: new_blocks.get() == NULL";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_001058c8 @ 001058c8 size=65 =====

void FUN_001058c8(void)

{
  undefined8 *puVar1;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = unaff_retaddr;
  puVar1[1] = in_stack_00000008;
  puVar1[2] = 0x80000008a;
  puVar1[3] = "../src_udic/marisa_u/keyset.cpp:138: MARISA_MEMORY_ERROR: new_block.get() == NULL";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_0010596c @ 0010596c size=74 =====

void FUN_0010596c(void)

{
  undefined8 *puVar1;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  undefined8 uStack0000000000000010;
  
  uStack0000000000000010 = 0;
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = unaff_retaddr;
  puVar1[1] = in_stack_00000008;
  puVar1[2] = 0x800000097;
  puVar1[3] = "../src_udic/marisa_u/keyset.cpp:151: MARISA_MEMORY_ERROR: new_blocks.get() == NULL";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00105a10 @ 00105a10 size=69 =====

void FUN_00105a10(undefined8 param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  undefined8 in_XMM1_Qb;
  undefined8 uStack0000000000000008;
  
  uStack0000000000000008 = in_XMM1_Qb;
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = param_2;
  puVar1[1] = uStack0000000000000008;
  puVar1[2] = 0x20000003d;
  puVar1[3] = 
  "../src_udic/marisa_u/keyset.cpp:61: MARISA_NULL_ERROR: (ptr == NULL) && (length != 0)";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00105a9a @ 00105a9a size=93 =====

void FUN_00105a9a(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x200000032;
  puVar1[3] = "../src_udic/marisa_u/keyset.cpp:50: MARISA_NULL_ERROR: str == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/keyset.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00105af8 @ 00105af8 size=16 =====

void FUN_00105af8(void)

{
  FUN_00110320();
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume();
}


//===== FUN_00105b08 @ 00105b08 size=65 =====

void FUN_00105b08(void)

{
  undefined8 *puVar1;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = unaff_retaddr;
  puVar1[1] = in_stack_00000008;
  puVar1[2] = 0x100000063;
  puVar1[3] = "../src_udic/marisa_u/grimoire/io/mapper.cpp:99: MARISA_STATE_ERROR: !is_open()";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00105b8a @ 00105b8a size=65 =====

void FUN_00105b8a(void)

{
  undefined8 *puVar1;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = unaff_retaddr;
  puVar1[1] = in_stack_00000008;
  puVar1[2] = 0x100000047;
  puVar1[3] = "../src_udic/marisa_u/grimoire/io/mapper.cpp:71: MARISA_STATE_ERROR: !is_open()";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00105c0c @ 00105c0c size=65 =====

void FUN_00105c0c(void)

{
  undefined8 *puVar1;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = unaff_retaddr;
  puVar1[1] = in_stack_00000008;
  puVar1[2] = 0x900000095;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/io/mapper.cpp:149: MARISA_IO_ERROR: origin_ == MAP_FAILED";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00105cd0 @ 00105cd0 size=92 =====

void FUN_00105cd0(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x200000037;
  puVar1[3] = "../src_udic/marisa_u/grimoire/io/mapper.cpp:55: MARISA_NULL_ERROR: filename == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/io/mapper.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00105d3c @ 00105d3c size=92 =====

void FUN_00105d3c(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x20000003f;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/io/mapper.cpp:63: MARISA_NULL_ERROR: (ptr == NULL) && (size != 0)";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/io/mapper.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00105da8 @ 00105da8 size=16 =====

void FUN_00105da8(void)

{
  FUN_00110710();
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume();
}


//===== FUN_00105db8 @ 00105db8 size=92 =====

void FUN_00105db8(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x90000005e;
  puVar1[3] = "../src_udic/marisa_u/grimoire/io/reader.cpp:94: MARISA_IO_ERROR: file == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/io/reader.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00105e14 @ 00105e14 size=92 =====

void FUN_00105e14(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x20000001b;
  puVar1[3] = "../src_udic/marisa_u/grimoire/io/reader.cpp:27: MARISA_NULL_ERROR: filename == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/io/reader.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00105e80 @ 00105e80 size=92 =====

void FUN_00105e80(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x200000023;
  puVar1[3] = "../src_udic/marisa_u/grimoire/io/reader.cpp:35: MARISA_NULL_ERROR: file == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/io/reader.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00105eec @ 00105eec size=92 =====

void FUN_00105eec(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x50000002b;
  puVar1[3] = "../src_udic/marisa_u/grimoire/io/reader.cpp:43: MARISA_CODE_ERROR: fd == -1";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/io/reader.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00105f58 @ 00105f58 size=16 =====

void FUN_00105f58(void)

{
  FUN_00110710();
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume();
}


//===== FUN_00105f68 @ 00105f68 size=65 =====

void FUN_00105f68(void)

{
  undefined8 *puVar1;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = unaff_retaddr;
  puVar1[1] = in_stack_00000008;
  puVar1[2] = 0x900000086;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/io/reader.cpp:134: MARISA_IO_ERROR: ::fread(buf, 1, size, file_) != size"
  ;
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00105fa9 @ 00105fa9 size=65 =====

void FUN_00105fa9(void)

{
  undefined8 *puVar1;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = unaff_retaddr;
  puVar1[1] = in_stack_00000008;
  puVar1[2] = 0x900000089;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/io/reader.cpp:137: MARISA_IO_ERROR: !stream_->read(static_cast<char *>(buf), size)"
  ;
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_001060e0 @ 001060e0 size=91 =====

void FUN_001060e0(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x100000044;
  puVar1[3] = "../src_udic/marisa_u/grimoire/io/reader.cpp:68: MARISA_STATE_ERROR: !is_open()";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/io/reader.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_0010613c @ 0010613c size=16 =====

void FUN_0010613c(void)

{
  FUN_00110c50();
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume();
}


//===== FUN_0010614c @ 0010614c size=92 =====

void FUN_0010614c(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x90000005e;
  puVar1[3] = "../src_udic/marisa_u/grimoire/io/writer.cpp:94: MARISA_IO_ERROR: file == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/io/writer.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_001061a8 @ 001061a8 size=92 =====

void FUN_001061a8(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x20000001b;
  puVar1[3] = "../src_udic/marisa_u/grimoire/io/writer.cpp:27: MARISA_NULL_ERROR: filename == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/io/writer.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00106214 @ 00106214 size=92 =====

void FUN_00106214(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x200000023;
  puVar1[3] = "../src_udic/marisa_u/grimoire/io/writer.cpp:35: MARISA_NULL_ERROR: file == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/io/writer.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00106280 @ 00106280 size=92 =====

void FUN_00106280(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x50000002b;
  puVar1[3] = "../src_udic/marisa_u/grimoire/io/writer.cpp:43: MARISA_CODE_ERROR: fd == -1";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/io/writer.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_001062ec @ 001062ec size=16 =====

void FUN_001062ec(void)

{
  FUN_00110c50();
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume();
}


//===== FUN_001062fc @ 001062fc size=65 =====

void FUN_001062fc(void)

{
  undefined8 *puVar1;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = unaff_retaddr;
  puVar1[1] = in_stack_00000008;
  puVar1[2] = 0x900000086;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/io/writer.cpp:134: MARISA_IO_ERROR: ::fwrite(data, 1, size, file_) != size"
  ;
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_001063bf @ 001063bf size=65 =====

void FUN_001063bf(void)

{
  undefined8 *puVar1;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = unaff_retaddr;
  puVar1[1] = in_stack_00000008;
  puVar1[2] = 0x90000008a;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/io/writer.cpp:138: MARISA_IO_ERROR: !stream_->write(static_cast<const char *>(data), size)"
  ;
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_001064b0 @ 001064b0 size=91 =====

void FUN_001064b0(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x100000044;
  puVar1[3] = "../src_udic/marisa_u/grimoire/io/writer.cpp:68: MARISA_STATE_ERROR: !is_open()";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/io/writer.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_0010650c @ 0010650c size=95 =====

void FUN_0010650c(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x20000001e;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/../io/writer.h:30: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
  ;
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/trie/../io/writer.h";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_0010656c @ 0010656c size=95 =====

void FUN_0010656c(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x600000013;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/../algorithm/../../scoped-ptr.h:19: MARISA_RESET_ERROR: (ptr != NULL) && (ptr == ptr_)"
  ;
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/trie/../algorithm/../../scoped-ptr.h";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_001065cc @ 001065cc size=94 =====

void FUN_001065cc(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x100000064;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/../vector/vector.h:100: MARISA_STATE_ERROR: fixed_";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/trie/../vector/vector.h";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_0010662a @ 0010662a size=95 =====

void FUN_0010662a(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x10000006b;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/../vector/vector.h:107: MARISA_STATE_ERROR: fixed_";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/trie/../vector/vector.h";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_0010668a @ 0010668a size=95 =====

void FUN_0010668a(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x70000001d;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/../io/mapper.h:29: MARISA_SIZE_ERROR: num_objs > (MARISA_SIZE_MAX / sizeof(T))"
  ;
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/trie/../io/mapper.h";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_001066ea @ 001066ea size=95 =====

void FUN_001066ea(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0xa000000ca;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/../vector/vector.h:202: MARISA_FORMAT_ERROR: (total_size % sizeof(T)) != 0"
  ;
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/trie/../vector/vector.h";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_0010674a @ 0010674a size=94 =====

void FUN_0010674a(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x700000020;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/../io/reader.h:32: MARISA_SIZE_ERROR: num_objs > (MARISA_SIZE_MAX / sizeof(T))"
  ;
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/trie/../io/reader.h";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_001067a8 @ 001067a8 size=95 =====

void FUN_001067a8(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0xa000000d5;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/../vector/vector.h:213: MARISA_FORMAT_ERROR: (total_size % sizeof(T)) != 0"
  ;
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/trie/../vector/vector.h";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00106808 @ 00106808 size=95 =====

void FUN_00106808(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x70000001f;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/../io/writer.h:31: MARISA_SIZE_ERROR: num_objs > (MARISA_SIZE_MAX / sizeof(T))"
  ;
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/trie/../io/writer.h";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00106868 @ 00106868 size=94 =====

void FUN_00106868(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x700000040;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/../vector/bit-vector.h:64: MARISA_SIZE_ERROR: size_ == MARISA_UINT32_MAX"
  ;
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/trie/../vector/bit-vector.h";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_001068c6 @ 001068c6 size=250 =====

void FUN_001068c6(void)

{
  void *pvVar1;
  long unaff_RBP;
  
  if (*(void **)(unaff_RBP + 0x3f0) != (void *)0x0) {
    operator_delete__(*(void **)(unaff_RBP + 0x3f0));
  }
  pvVar1 = *(void **)(unaff_RBP + 1000);
  if (pvVar1 != (void *)0x0) {
    FUN_001125e0(pvVar1);
    operator_delete(pvVar1);
  }
  if (*(void **)(unaff_RBP + 0x3b8) != (void *)0x0) {
    operator_delete__(*(void **)(unaff_RBP + 0x3b8));
  }
  if (*(void **)(unaff_RBP + 0x388) != (void *)0x0) {
    operator_delete__(*(void **)(unaff_RBP + 0x388));
  }
  if (*(void **)(unaff_RBP + 0x358) != (void *)0x0) {
    operator_delete__(*(void **)(unaff_RBP + 0x358));
  }
  if (*(void **)(unaff_RBP + 0x318) != (void *)0x0) {
    operator_delete__(*(void **)(unaff_RBP + 0x318));
  }
  if (*(void **)(unaff_RBP + 0x2e8) != (void *)0x0) {
    operator_delete__(*(void **)(unaff_RBP + 0x2e8));
  }
  if (*(void **)(unaff_RBP + 0x2a0) != (void *)0x0) {
    operator_delete__(*(void **)(unaff_RBP + 0x2a0));
  }
  if (*(void **)(unaff_RBP + 0x270) != (void *)0x0) {
    operator_delete__(*(void **)(unaff_RBP + 0x270));
  }
  FUN_00119540();
  FUN_00119540();
  FUN_00119540();
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume();
}


//===== FUN_001069c0 @ 001069c0 size=16 =====

void FUN_001069c0(void)

{
  FUN_001125e0();
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume();
}


//===== FUN_001069d0 @ 001069d0 size=70 =====

void FUN_001069d0(void)

{
  undefined8 *puVar1;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  
  FUN_00106808();
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = unaff_retaddr;
  puVar1[1] = in_stack_00000008;
  puVar1[2] = 0x20000001e;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/../io/writer.h:30: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
  ;
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00106d78 @ 00106d78 size=92 =====

void FUN_00106d78(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x300000049;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/louds-trie.cpp:73: MARISA_BOUND_ERROR: agent.query().id() >= size()"
  ;
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/trie/louds-trie.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00106dd4 @ 00106dd4 size=65 =====

void FUN_00106dd4(void)

{
  undefined8 *puVar1;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = unaff_retaddr;
  puVar1[1] = in_stack_00000008;
  puVar1[2] = 0x50000008d;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/config.h:141: MARISA_CODE_ERROR: undefined node order";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00106ea7 @ 00106ea7 size=65 =====

void FUN_00106ea7(void)

{
  undefined8 *puVar1;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = unaff_retaddr;
  puVar1[1] = in_stack_00000008;
  puVar1[2] = 0x500000079;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/config.h:121: MARISA_CODE_ERROR: undefined tail mode";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00106f86 @ 00106f86 size=92 =====

void FUN_00106f86(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0xa00000015;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/header.h:21: MARISA_FORMAT_ERROR: !test_header(ptr)";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/trie/header.h";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00106ff2 @ 00106ff2 size=23 =====

void FUN_00106ff2(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,(nothrow_t *)PTR_nothrow_00132fb8);
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume();
}


//===== FUN_0010704e @ 0010704e size=66 =====

void FUN_0010704e(void)

{
  undefined8 *puVar1;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = in_stack_00000050;
  puVar1[1] = in_stack_00000058;
  puVar1[2] = 0x800000238;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/louds-trie.cpp:568: MARISA_MEMORY_ERROR: next_trie_.get() == NULL"
  ;
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00107123 @ 00107123 size=66 =====

void FUN_00107123(void)

{
  undefined8 *puVar1;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = in_stack_00000020;
  puVar1[1] = in_stack_00000028;
  puVar1[2] = 0x500000079;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/config.h:121: MARISA_CODE_ERROR: undefined tail mode";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00107165 @ 00107165 size=66 =====

void FUN_00107165(void)

{
  undefined8 *puVar1;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = in_stack_00000020;
  puVar1[1] = in_stack_00000028;
  puVar1[2] = 0x500000065;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/config.h:101: MARISA_CODE_ERROR: undefined cache level";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_001071ee @ 001071ee size=66 =====

void FUN_001071ee(void)

{
  undefined8 *puVar1;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = in_stack_00000020;
  puVar1[1] = in_stack_00000028;
  puVar1[2] = 0x50000003a;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/config.h:58: MARISA_CODE_ERROR: (config_flags & ~MARISA_CONFIG_MASK) != 0"
  ;
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_001072d8 @ 001072d8 size=92 =====

void FUN_001072d8(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0xa0000001a;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/header.h:26: MARISA_FORMAT_ERROR: !test_header(buf)";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/trie/header.h";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00107344 @ 00107344 size=92 =====

void FUN_00107344(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x8000001c3;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/louds-trie.cpp:451: MARISA_MEMORY_ERROR: next_trie_.get() == NULL"
  ;
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/trie/louds-trie.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_001073e8 @ 001073e8 size=10 =====

void FUN_001073e8(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_00106868();
}


//===== FUN_00107464 @ 00107464 size=69 =====

void FUN_00107464(undefined8 param_1)

{
  undefined8 *puVar1;
  undefined8 in_XMM0_Qb;
  undefined8 uStack0000000000000008;
  
  uStack0000000000000008 = in_XMM0_Qb;
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = param_1;
  puVar1[1] = uStack0000000000000008;
  puVar1[2] = 0x500000065;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/config.h:101: MARISA_CODE_ERROR: undefined cache level";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00107543 @ 00107543 size=69 =====

void FUN_00107543(undefined8 param_1)

{
  undefined8 *puVar1;
  undefined8 in_XMM0_Qb;
  undefined8 uStack0000000000000008;
  
  uStack0000000000000008 = in_XMM0_Qb;
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = param_1;
  puVar1[1] = uStack0000000000000008;
  puVar1[2] = 0x500000079;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/config.h:121: MARISA_CODE_ERROR: undefined tail mode";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00107588 @ 00107588 size=22 =====

void FUN_00107588(void)

{
  void *in_stack_00000010;
  
  FUN_0010656c();
  if (in_stack_00000010 != (void *)0x0) {
    operator_delete__(in_stack_00000010);
    FUN_00107609();
    return;
  }
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume();
}


//===== FUN_0010759e @ 0010759e size=92 =====

void FUN_0010759e(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x8000001d4;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/louds-trie.cpp:468: MARISA_MEMORY_ERROR: next_trie_.get() == NULL"
  ;
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/trie/louds-trie.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00107609 @ 00107609 size=8 =====

void FUN_00107609(void)

{
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume();
}


//===== FUN_00107612 @ 00107612 size=95 =====

void FUN_00107612(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x10000006b;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/../vector/vector.h:107: MARISA_STATE_ERROR: fixed_";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/trie/../vector/vector.h";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00107672 @ 00107672 size=94 =====

void FUN_00107672(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x700000040;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/../vector/bit-vector.h:64: MARISA_SIZE_ERROR: size_ == MARISA_UINT32_MAX"
  ;
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/trie/../vector/bit-vector.h";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_001076d0 @ 001076d0 size=95 =====

void FUN_001076d0(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x70000001d;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/../vector/../io/mapper.h:29: MARISA_SIZE_ERROR: num_objs > (MARISA_SIZE_MAX / sizeof(T))"
  ;
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/trie/../vector/../io/mapper.h";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00107730 @ 00107730 size=95 =====

void FUN_00107730(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0xa000000ca;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/../vector/vector.h:202: MARISA_FORMAT_ERROR: (total_size % sizeof(T)) != 0"
  ;
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/trie/../vector/vector.h";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00107790 @ 00107790 size=94 =====

void FUN_00107790(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x700000020;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/../vector/../io/reader.h:32: MARISA_SIZE_ERROR: num_objs > (MARISA_SIZE_MAX / sizeof(T))"
  ;
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/trie/../vector/../io/reader.h";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_001077ee @ 001077ee size=95 =====

void FUN_001077ee(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0xa000000d5;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/../vector/vector.h:213: MARISA_FORMAT_ERROR: (total_size % sizeof(T)) != 0"
  ;
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/trie/../vector/vector.h";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_0010784e @ 0010784e size=95 =====

void FUN_0010784e(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x70000001f;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/../vector/../io/writer.h:31: MARISA_SIZE_ERROR: num_objs > (MARISA_SIZE_MAX / sizeof(T))"
  ;
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/trie/../vector/../io/writer.h";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_001078ae @ 001078ae size=16 =====

void FUN_001078ae(void)

{
  FUN_00124290();
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume();
}


//===== FUN_001078be @ 001078be size=70 =====

void FUN_001078be(void)

{
  undefined8 *puVar1;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  
  FUN_00107672();
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = in_stack_00000050;
  puVar1[1] = in_stack_00000058;
  puVar1[2] = 0x7000000c0;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/tail.cpp:192: MARISA_SIZE_ERROR: buf_.size() > MARISA_UINT32_MAX"
  ;
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_001079b6 @ 001079b6 size=69 =====

void FUN_001079b6(undefined8 param_1)

{
  undefined8 *puVar1;
  undefined8 in_XMM0_Qb;
  undefined8 uStack0000000000000008;
  
  uStack0000000000000008 = in_XMM0_Qb;
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = param_1;
  puVar1[1] = uStack0000000000000008;
  puVar1[2] = 0x20000000d;
  puVar1[3] = "../src_udic/marisa_u/grimoire/trie/tail.cpp:13: MARISA_NULL_ERROR: offsets == NULL";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_001079fb @ 001079fb size=69 =====

void FUN_001079fb(undefined8 param_1)

{
  undefined8 *puVar1;
  undefined8 in_XMM0_Qb;
  undefined8 uStack0000000000000008;
  
  uStack0000000000000008 = in_XMM0_Qb;
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = param_1;
  puVar1[1] = uStack0000000000000008;
  puVar1[2] = 0x500000024;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/tail.cpp:36: MARISA_CODE_ERROR: undefined tail mode";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== thunk_FUN_00107730 @ 00107a50 size=5 =====

void thunk_FUN_00107730(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_00107730();
}


//===== FUN_00107ada @ 00107ada size=16 =====

void FUN_00107ada(void)

{
  FUN_00124290();
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume();
}


//===== FUN_00107aea @ 00107aea size=65 =====

void FUN_00107aea(void)

{
  undefined8 *puVar1;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = unaff_retaddr;
  puVar1[1] = in_stack_00000008;
  puVar1[2] = 0x20000001e;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/../vector/../io/writer.h:30: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
  ;
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00107c3e @ 00107c3e size=92 =====

void FUN_00107c3e(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x20000001f;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/../vector/../io/reader.h:31: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
  ;
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/trie/../vector/../io/reader.h";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00107cb0 @ 00107cb0 size=16 =====

void FUN_00107cb0(void)

{
  FUN_00124290();
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume();
}


//===== FUN_00107cc0 @ 00107cc0 size=94 =====

void FUN_00107cc0(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x100000064;
  puVar1[3] = "../src_udic/marisa_u/grimoire/vector/vector.h:100: MARISA_STATE_ERROR: fixed_";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/vector/vector.h";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== _INIT_1 @ 00107d20 size=49 =====

void _INIT_1(void)

{
  DAT_00133228 = 0;
  DAT_00133220 = &DAT_00133230;
  DAT_00133230 = 0;
  __cxa_atexit(PTR__string_00132fc8,&DAT_00133220,&PTR_LOOP_001331d0);
  return;
}


//===== _INIT_2 @ 00107d60 size=43 =====

void _INIT_2(void)

{
  std::ios_base::Init::Init((Init *)&DAT_00133240);
  __cxa_atexit(PTR__Init_00132fe8,&DAT_00133240,&PTR_LOOP_001331d0);
  return;
}


//===== _INIT_3 @ 00107d90 size=43 =====

void _INIT_3(void)

{
  std::ios_base::Init::Init((Init *)&DAT_00133241);
  __cxa_atexit(PTR__Init_00132fe8,&DAT_00133241,&PTR_LOOP_001331d0);
  return;
}


//===== _INIT_4 @ 00107dc0 size=43 =====

void _INIT_4(void)

{
  std::ios_base::Init::Init((Init *)&DAT_00133242);
  __cxa_atexit(PTR__Init_00132fe8,&DAT_00133242,&PTR_LOOP_001331d0);
  return;
}


//===== _INIT_5 @ 00107df0 size=43 =====

void _INIT_5(void)

{
  std::ios_base::Init::Init((Init *)&DAT_00133243);
  __cxa_atexit(PTR__Init_00132fe8,&DAT_00133243,&PTR_LOOP_001331d0);
  return;
}


//===== _INIT_6 @ 00107e20 size=43 =====

void _INIT_6(void)

{
  std::ios_base::Init::Init((Init *)&DAT_00133244);
  __cxa_atexit(PTR__Init_00132fe8,&DAT_00133244,&PTR_LOOP_001331d0);
  return;
}


//===== _INIT_7 @ 00107e50 size=43 =====

void _INIT_7(void)

{
  std::ios_base::Init::Init((Init *)&DAT_00133245);
  __cxa_atexit(PTR__Init_00132fe8,&DAT_00133245,&PTR_LOOP_001331d0);
  return;
}


//===== _INIT_8 @ 00107e80 size=43 =====

void _INIT_8(void)

{
  std::ios_base::Init::Init((Init *)&DAT_00133246);
  __cxa_atexit(PTR__Init_00132fe8,&DAT_00133246,&PTR_LOOP_001331d0);
  return;
}


//===== FUN_00107eb0 @ 00107eb0 size=34 =====

/* WARNING: Removing unreachable block (ram,0x00107ec3) */
/* WARNING: Removing unreachable block (ram,0x00107ecf) */

void FUN_00107eb0(void)

{
  return;
}


//===== FUN_00107ee0 @ 00107ee0 size=51 =====

/* WARNING: Removing unreachable block (ram,0x00107f04) */
/* WARNING: Removing unreachable block (ram,0x00107f10) */

void FUN_00107ee0(void)

{
  return;
}


//===== _FINI_0 @ 00107f20 size=54 =====

void _FINI_0(void)

{
  if (DAT_00133200 == '\0') {
    if (PTR___cxa_finalize_00132fc0 != (undefined *)0x0) {
      __cxa_finalize(PTR_LOOP_001331d0);
    }
    FUN_00107eb0();
    DAT_00133200 = 1;
    return;
  }
  return;
}


//===== _INIT_0 @ 00107f60 size=9 =====

void _INIT_0(void)

{
  FUN_00107ee0();
  return;
}


//===== AqUsrDic_Check @ 00107f70 size=400 =====

int AqUsrDic_Check(undefined8 param_1,undefined8 param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  ushort *puVar4;
  long in_FS_OFFSET;
  undefined1 local_8a;
  undefined1 local_89;
  undefined1 local_88 [16];
  undefined8 local_78;
  ushort *local_68;
  ulong local_60;
  ushort local_58 [8];
  undefined1 *local_48;
  long local_40;
  undefined1 local_38 [24];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_0010d930(&local_48);
  FUN_0010d930(&local_68,param_1);
  if (local_60 == 0) {
    iVar2 = 0x12d;
  }
  else if (local_40 == 0) {
    iVar2 = 0x12f;
  }
  else if (local_60 < 0x20) {
    puVar4 = local_68;
    do {
      uVar1 = *puVar4;
      if (((uVar1 < 0x7f || uVar1 == 0xa5) || (uVar1 == 0x203e)) || ((ushort)(uVar1 + 0x9f) < 0x3f))
      {
        iVar2 = 0x138;
        goto LAB_00108026;
      }
      if (uVar1 == 0x3000) {
        iVar2 = 0x139;
        goto LAB_00108026;
      }
      puVar4 = puVar4 + 1;
    } while (puVar4 != local_68 + local_60);
    local_88 = (undefined1  [16])0x0;
    local_78 = 0;
    iVar2 = FUN_0010c990(local_48,&local_8a,&local_89,local_88);
    if ((iVar2 == 0) && ((param_3 < 0 || (iVar3 = FUN_0010cfb0(), iVar3 <= param_3)))) {
      iVar2 = 0x13a;
    }
    if ((void *)local_88._0_8_ != (void *)0x0) {
      operator_delete((void *)local_88._0_8_);
    }
  }
  else {
    iVar2 = 0x13b;
  }
LAB_00108026:
  if (local_68 != local_58) {
    operator_delete(local_68);
  }
  if (local_48 != local_38) {
    operator_delete(local_48);
  }
  if (iVar2 != 0) {
    FUN_00108cf0(iVar2,0);
  }
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}


//===== AqUsrDic_GetLastError @ 00108140 size=9 =====

void AqUsrDic_GetLastError(void)

{
  FUN_00108ce0();
  return;
}


//===== AqUsrDic_Export @ 00108150 size=921 =====

int AqUsrDic_Export(char *param_1,undefined8 param_2)

{
  long lVar1;
  char cVar2;
  undefined8 uVar3;
  int iVar4;
  undefined4 uVar5;
  size_t sVar6;
  ulong uVar7;
  undefined8 *puVar8;
  long in_FS_OFFSET;
  undefined1 local_b1;
  undefined1 local_b0 [8];
  undefined1 local_a8 [16];
  undefined8 local_98;
  size_t *local_88;
  size_t local_80;
  size_t local_78 [2];
  undefined8 *local_68;
  ulong local_60;
  undefined8 local_58 [3];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if ((param_1 != (char *)0x0) && (cVar2 = *param_1, cVar2 != '\0')) {
    sVar6 = strlen(param_1);
    iVar4 = strcmp(param_1 + (sVar6 - 0xb),"aq_user.dic");
    if (iVar4 == 0) {
      local_88 = local_78;
      local_a8._0_8_ = sVar6;
      if (sVar6 < 0x10) {
        if (sVar6 == 1) {
          local_78[0] = CONCAT71(local_78[0]._1_7_,cVar2);
        }
        else if (sVar6 != 0) goto LAB_00108441;
      }
      else {
        local_88 = (size_t *)std::__cxx11::string::_M_create((ulong *)&local_88,(ulong)local_a8);
        local_78[0] = local_a8._0_8_;
LAB_00108441:
        memcpy(local_88,param_1,sVar6);
      }
      *(undefined1 *)((long)local_88 + local_a8._0_8_) = 0;
      local_80 = local_a8._0_8_;
      sVar6 = strlen(param_1);
      local_60 = sVar6 - 0xb;
      local_a8._0_8_ = local_60;
      local_68 = local_58;
      if (local_60 < 0x10) {
        if (local_60 == 1) {
          local_58[0] = CONCAT71(local_58[0]._1_7_,*param_1);
        }
        else if (local_60 != 0) goto LAB_001084c7;
      }
      else {
        local_68 = (undefined8 *)std::__cxx11::string::_M_create((ulong *)&local_68,(ulong)local_a8)
        ;
        local_58[0] = local_a8._0_8_;
LAB_001084c7:
        memcpy(local_68,param_1,local_60);
        local_60 = local_a8._0_8_;
      }
      *(undefined1 *)((long)local_68 + local_60) = 0;
      if (0x3fffffffffffffff - local_60 < 9) {
                    /* WARNING: Subroutine does not return */
        std::__throw_length_error("basic_string::append");
      }
      std::__cxx11::string::_M_append((char *)&local_68,0x127021);
      FUN_0010cf80(local_b0);
      iVar4 = FUN_0010cfc0(local_b0,local_68);
      if (iVar4 == 0) {
        local_98 = 0;
        local_a8 = (undefined1  [16])0x0;
        FUN_0010ac30(&local_b1);
        iVar4 = FUN_0010afa0(&local_b1,local_88,local_a8);
        if (iVar4 == 0) {
          uVar7 = 0;
          if (local_a8._8_8_ != local_a8._0_8_) {
            do {
              lVar1 = local_a8._0_8_ + uVar7 * 0x48;
              uVar5 = FUN_0010d180(local_b0,*(undefined4 *)(lVar1 + 0x40));
              *(undefined4 *)(lVar1 + 0x40) = uVar5;
              uVar7 = uVar7 + 1;
            } while (uVar7 < (ulong)(((long)(local_a8._8_8_ - local_a8._0_8_) >> 3) *
                                    -0x71c71c71c71c71c7));
          }
          iVar4 = FUN_0010dc30(param_2,local_a8);
          if (iVar4 != 0) goto LAB_001084e8;
        }
        else {
LAB_001084e8:
          FUN_00108cf0(iVar4,0);
        }
        FUN_0010ac40(&local_b1);
        uVar3 = local_a8._8_8_;
        puVar8 = (undefined8 *)local_a8._0_8_;
        if (local_a8._8_8_ != local_a8._0_8_) {
          do {
            while( true ) {
              if ((undefined8 *)puVar8[4] != puVar8 + 6) {
                operator_delete((undefined8 *)puVar8[4]);
              }
              if ((undefined8 *)*puVar8 == puVar8 + 2) break;
              operator_delete((undefined8 *)*puVar8);
              puVar8 = puVar8 + 9;
              if ((undefined8 *)uVar3 == puVar8) goto LAB_00108391;
            }
            puVar8 = puVar8 + 9;
          } while ((undefined8 *)uVar3 != puVar8);
LAB_00108391:
        }
        if ((undefined8 *)local_a8._0_8_ != (undefined8 *)0x0) {
          operator_delete((void *)local_a8._0_8_);
        }
      }
      else {
        FUN_00108cf0(iVar4,0);
      }
      FUN_0010cf90(local_b0);
      if (local_68 != local_58) {
        operator_delete(local_68);
      }
      if (local_88 != local_78) {
        operator_delete(local_88);
      }
      goto LAB_001083e2;
    }
  }
  iVar4 = 100;
  FUN_00108cf0(100,0);
LAB_001083e2:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}


//===== AqUsrDic_Import @ 00108550 size=1658 =====

int AqUsrDic_Import(char *param_1,undefined8 param_2)

{
  ulong uVar1;
  ushort *puVar2;
  char cVar3;
  ushort uVar4;
  ushort uVar5;
  int iVar6;
  ulong uVar7;
  long lVar8;
  undefined8 uVar9;
  int iVar10;
  undefined4 uVar11;
  size_t sVar12;
  ulong uVar13;
  ulong uVar14;
  ushort *puVar15;
  long *plVar16;
  ulong uVar17;
  undefined8 *puVar18;
  long in_FS_OFFSET;
  undefined1 *local_e8;
  undefined1 local_d2;
  undefined1 local_d1;
  undefined1 local_d0 [8];
  undefined1 local_c8 [16];
  undefined8 local_b8;
  undefined1 local_a8 [16];
  undefined8 local_98;
  size_t *local_88;
  size_t local_80;
  size_t local_78 [2];
  undefined8 *local_68;
  ulong local_60;
  undefined8 local_58 [3];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if ((param_1 != (char *)0x0) && (cVar3 = *param_1, cVar3 != '\0')) {
    sVar12 = strlen(param_1);
    iVar10 = strcmp(param_1 + (sVar12 - 0xb),"aq_user.dic");
    if (iVar10 == 0) {
      local_88 = local_78;
      local_a8._0_8_ = sVar12;
      if (sVar12 < 0x10) {
        if (sVar12 == 1) {
          local_78[0] = CONCAT71(local_78[0]._1_7_,cVar3);
        }
        else if (sVar12 != 0) goto LAB_0010888c;
      }
      else {
        local_88 = (size_t *)std::__cxx11::string::_M_create((ulong *)&local_88,(ulong)local_a8);
        local_78[0] = local_a8._0_8_;
LAB_0010888c:
        memcpy(local_88,param_1,sVar12);
      }
      *(undefined1 *)((long)local_88 + local_a8._0_8_) = 0;
      local_80 = local_a8._0_8_;
      sVar12 = strlen(param_1);
      local_60 = sVar12 - 0xb;
      local_a8._0_8_ = local_60;
      local_68 = local_58;
      if (local_60 < 0x10) {
        if (local_60 == 1) {
          local_58[0] = CONCAT71(local_58[0]._1_7_,*param_1);
        }
        else if (local_60 != 0) goto LAB_00108b7a;
      }
      else {
        local_68 = (undefined8 *)std::__cxx11::string::_M_create((ulong *)&local_68,(ulong)local_a8)
        ;
        local_58[0] = local_a8._0_8_;
LAB_00108b7a:
        memcpy(local_68,param_1,local_60);
        local_60 = local_a8._0_8_;
      }
      *(undefined1 *)((long)local_68 + local_60) = 0;
      if (0x3fffffffffffffff - local_60 < 9) {
                    /* WARNING: Subroutine does not return */
        std::__throw_length_error("basic_string::append");
      }
      std::__cxx11::string::_M_append((char *)&local_68,0x127021);
      FUN_0010cf80(local_d0);
      iVar10 = FUN_0010cfc0(local_d0,local_68);
      if (iVar10 == 0) {
        local_b8 = 0;
        local_c8 = (undefined1  [16])0x0;
        iVar10 = FUN_0010ddc0(param_2,local_c8);
        if (iVar10 == 0) {
          uVar17 = 0;
          if (local_c8._0_8_ != local_c8._8_8_) {
            do {
              puVar18 = (undefined8 *)(local_c8._0_8_ + uVar17 * 0x48);
              uVar7 = puVar18[1];
              iVar6 = *(int *)(puVar18 + 8);
              puVar15 = (ushort *)*puVar18;
              if (uVar7 == 0) {
                iVar10 = 0x12d;
LAB_00108786:
                FUN_00108cf0(iVar10,uVar17 & 0xffffffff);
                goto LAB_00108790;
              }
              if (puVar18[5] == 0) {
                iVar10 = 0x12f;
                goto LAB_00108786;
              }
              if (0x1f < uVar7) {
                iVar10 = 0x13b;
                goto LAB_00108786;
              }
              puVar2 = puVar15 + uVar7;
              do {
                uVar4 = *puVar15;
                if (((uVar4 == 0xa5 || uVar4 < 0x7f) || (uVar4 == 0x203e)) ||
                   ((ushort)(uVar4 + 0x9f) < 0x3f)) {
                  iVar10 = 0x138;
                  goto LAB_00108786;
                }
                if (uVar4 == 0x3000) {
                  iVar10 = 0x139;
                  goto LAB_00108786;
                }
                puVar15 = puVar15 + 1;
              } while (puVar2 != puVar15);
              local_98 = 0;
              local_a8 = (undefined1  [16])0x0;
              iVar10 = FUN_0010c990(puVar18[4],&local_d2,&local_d1);
              if (iVar10 != 0) {
                if ((void *)local_a8._0_8_ != (void *)0x0) {
                  operator_delete((void *)local_a8._0_8_);
                }
                goto LAB_00108786;
              }
              if (iVar6 < 0) {
LAB_00108b9c:
                if ((void *)local_a8._0_8_ != (void *)0x0) {
                  operator_delete((void *)local_a8._0_8_);
                }
                iVar10 = 0x13a;
                goto LAB_00108786;
              }
              iVar10 = FUN_0010cfb0();
              if (iVar10 <= iVar6) goto LAB_00108b9c;
              if ((void *)local_a8._0_8_ != (void *)0x0) {
                operator_delete((void *)local_a8._0_8_);
              }
              plVar16 = (long *)(uVar17 * 0x48 + local_c8._0_8_);
              uVar7 = plVar16[1];
              lVar8 = *plVar16;
              uVar14 = 0;
              if (uVar7 != 0) {
                do {
                  while( true ) {
                    uVar4 = *(ushort *)(lVar8 + uVar14 * 2);
                    if (0xff40 < uVar4) break;
                    if ((ushort)(uVar4 + 0xdf) < 0x1a) goto LAB_00108977;
LAB_001089df:
                    uVar14 = uVar14 + 1;
                    if (uVar7 <= uVar14) goto LAB_001089e8;
                  }
                  if (0xff5a < uVar4) goto LAB_001089df;
LAB_00108977:
                  uVar4 = *(ushort *)(lVar8 + 2 + uVar14 * 2);
                  uVar1 = uVar14 + 1;
                  uVar13 = uVar1;
                  if (uVar4 < 0xff41) {
                    if ((0xff20 < uVar4) && (uVar4 < 0xff3b)) goto LAB_00108997;
                  }
                  else if (uVar4 < 0xff5b) {
LAB_00108997:
                    uVar5 = *(ushort *)(lVar8 + 4 + uVar14 * 2);
                    uVar13 = uVar14 + 2;
                    if (uVar5 < 0xff41) {
                      if ((ushort)(uVar5 + 0xdf) < 0x1a) goto LAB_00108ac1;
                    }
                    else if (uVar5 < 0xff5b) {
LAB_00108ac1:
                      if (uVar4 < 0xff41) {
                        uVar13 = uVar1;
                        if ((0xff20 < uVar4) && (uVar4 < 0xff3b)) goto LAB_00108aee;
                      }
                      else {
                        uVar13 = uVar1;
                        if (uVar4 < 0xff5b) {
LAB_00108aee:
                          do {
                            uVar4 = *(ushort *)(lVar8 + uVar14 * 2);
                            uVar13 = uVar14;
                            if (uVar4 < 0xff41) {
                              if (0x19 < (ushort)(uVar4 + 0xdf)) break;
                            }
                            else {
                              if (0xff5a < uVar4) break;
                              *(ushort *)(lVar8 + uVar14 * 2) = uVar4 - 0x20;
                            }
                            uVar14 = uVar14 + 1;
                          } while( true );
                        }
                      }
                    }
                  }
                  uVar14 = uVar13;
                } while (uVar13 < uVar7);
              }
LAB_001089e8:
              uVar17 = uVar17 + 1;
            } while (uVar17 < (ulong)(((long)(local_c8._8_8_ - local_c8._0_8_) >> 3) *
                                     -0x71c71c71c71c71c7));
            if (local_c8._0_8_ != local_c8._8_8_) {
              uVar17 = 0;
              do {
                lVar8 = local_c8._0_8_ + uVar17 * 0x48;
                uVar11 = FUN_0010d1b0(local_d0,*(undefined4 *)(lVar8 + 0x40));
                *(undefined4 *)(lVar8 + 0x40) = uVar11;
                uVar17 = uVar17 + 1;
              } while (uVar17 < (ulong)(((long)(local_c8._8_8_ - local_c8._0_8_) >> 3) *
                                       -0x71c71c71c71c71c7));
            }
          }
          local_e8 = local_a8;
          FUN_0010ac30(local_e8);
          iVar10 = FUN_0010c010(local_e8,local_88,local_c8);
          if (iVar10 != 0) {
            FUN_00108cf0(iVar10,0);
          }
          FUN_0010ac40(local_e8);
        }
        else {
          FUN_00108cf0(iVar10,0);
        }
LAB_00108790:
        uVar9 = local_c8._8_8_;
        puVar18 = (undefined8 *)local_c8._0_8_;
        if (local_c8._8_8_ != local_c8._0_8_) {
          do {
            while( true ) {
              if ((undefined8 *)puVar18[4] != puVar18 + 6) {
                operator_delete((undefined8 *)puVar18[4]);
              }
              if ((undefined8 *)*puVar18 == puVar18 + 2) break;
              operator_delete((undefined8 *)*puVar18);
              puVar18 = puVar18 + 9;
              if ((undefined8 *)uVar9 == puVar18) goto LAB_001087d1;
            }
            puVar18 = puVar18 + 9;
          } while ((undefined8 *)uVar9 != puVar18);
LAB_001087d1:
        }
        if ((undefined8 *)local_c8._0_8_ != (undefined8 *)0x0) {
          operator_delete((void *)local_c8._0_8_);
        }
      }
      else {
        FUN_00108cf0(iVar10,0);
      }
      FUN_0010cf90(local_d0);
      if (local_68 != local_58) {
        operator_delete(local_68);
      }
      if (local_88 != local_78) {
        operator_delete(local_88);
      }
      goto LAB_0010882a;
    }
  }
  iVar10 = 100;
  FUN_00108cf0(100,0);
LAB_0010882a:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar10;
}


//===== FUN_00108c60 @ 00108c60 size=114 =====

void FUN_00108c60(long *param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar1 = (undefined8 *)param_1[1];
  puVar2 = (undefined8 *)*param_1;
  if (puVar1 != puVar2) {
    do {
      while( true ) {
        if ((undefined8 *)puVar2[4] != puVar2 + 6) {
          operator_delete((undefined8 *)puVar2[4]);
        }
        if ((undefined8 *)*puVar2 == puVar2 + 2) break;
        operator_delete((undefined8 *)*puVar2);
        puVar2 = puVar2 + 9;
        if (puVar1 == puVar2) goto LAB_00108cad;
      }
      puVar2 = puVar2 + 9;
    } while (puVar1 != puVar2);
LAB_00108cad:
    puVar2 = (undefined8 *)*param_1;
  }
  if (puVar2 == (undefined8 *)0x0) {
    return;
  }
  operator_delete(puVar2);
  return;
}


//===== FUN_00108ce0 @ 00108ce0 size=15 =====

undefined8 FUN_00108ce0(void)

{
  return DAT_00133220;
}


//===== FUN_00108cf0 @ 00108cf0 size=7440 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00108cf0(int param_1,uint param_2)

{
  int iVar1;
  undefined8 uVar2;
  char cVar3;
  undefined8 *puVar4;
  uint uVar5;
  uint uVar6;
  undefined *puVar7;
  undefined8 *puVar8;
  uint uVar9;
  undefined8 *puVar10;
  ulong uVar11;
  char *pcVar12;
  char cVar13;
  ulong uVar14;
  uint uVar15;
  uint uVar16;
  long in_FS_OFFSET;
  undefined1 *local_88;
  long local_80;
  undefined1 local_78 [16];
  undefined8 *local_68;
  char *local_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (0x194 < param_1) {
    if (param_1 == 500) {
      if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
        puVar7 = &DAT_00127330;
        goto LAB_00108e5c;
      }
      goto LAB_0010aa2f;
    }
    if (param_1 == 0x1f5) {
      if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
        puVar7 = &DAT_00127358;
        goto LAB_00108e5c;
      }
      goto LAB_0010aa2f;
    }
switchD_00108d3f_caseD_130:
    if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
      puVar7 = &DAT_001273c8;
LAB_00108e5c:
      std::__cxx11::string::_M_replace(0x133220,0,DAT_00133228,(ulong)puVar7);
      return;
    }
    goto LAB_0010aa2f;
  }
  if (param_1 < 300) {
    if (param_1 == 0xc9) {
      if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
        puVar7 = &DAT_001270a8;
        goto LAB_00108e5c;
      }
      goto LAB_0010aa2f;
    }
    if (param_1 < 0xca) {
      if (param_1 == 100) {
        if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
          puVar7 = &DAT_00127030;
          goto LAB_00108e5c;
        }
        goto LAB_0010aa2f;
      }
      if (param_1 == 200) {
        if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
          puVar7 = &DAT_00127078;
          goto LAB_00108e5c;
        }
        goto LAB_0010aa2f;
      }
    }
    else {
      if (param_1 == 0xd3) {
        if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
          puVar7 = &DAT_001270e8;
          goto LAB_00108e5c;
        }
        goto LAB_0010aa2f;
      }
      if (param_1 == 0xd4) {
        if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
          puVar7 = &DAT_00127118;
          goto LAB_00108e5c;
        }
        goto LAB_0010aa2f;
      }
    }
    goto switchD_00108d3f_caseD_130;
  }
  if (0x68 < param_1 - 300U) goto switchD_00108d3f_caseD_130;
  iVar1 = (int)param_2 >> 0x1f;
  switch(param_1) {
  case 300:
    uVar16 = -iVar1;
    uVar6 = -param_2;
    if ((int)-param_2 < 0) {
      uVar6 = param_2;
    }
    uVar14 = (ulong)uVar6;
    cVar13 = (char)uVar16;
    if (uVar6 < 10) {
      local_88 = local_78;
      std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + '\x01');
      pcVar12 = local_88 + (uVar16 & 0xff);
LAB_00109341:
      cVar13 = (char)uVar6 + '0';
    }
    else {
      if (uVar6 < 100) {
        cVar3 = '\x02';
        uVar15 = 1;
LAB_0010a2ee:
        local_88 = local_78;
        std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + cVar3);
        pcVar12 = local_88 + (uVar16 & 0xff);
        if (99 < uVar6) goto LAB_001092f3;
      }
      else {
        if (uVar6 < 1000) {
          uVar15 = 2;
          uVar5 = 3;
        }
        else if (uVar6 < 10000) {
          uVar15 = 3;
          uVar5 = 4;
        }
        else {
          uVar11 = uVar14;
          uVar5 = 1;
          do {
            uVar15 = uVar5;
            uVar5 = uVar15 + 4;
            if (uVar11 < 100000) {
              uVar15 = uVar15 + 3;
              goto LAB_001092b8;
            }
            uVar9 = (uint)(uVar11 / 10000);
            if (uVar9 < 100) {
              cVar3 = (char)uVar15 + '\x05';
              uVar15 = uVar5;
              goto LAB_0010a2ee;
            }
            if (uVar9 < 1000) {
              uVar5 = uVar15 + 6;
              uVar15 = uVar15 + 5;
              goto LAB_001092b8;
            }
            uVar11 = uVar11 / 10000;
          } while (9999 < uVar9);
          uVar5 = uVar15 + 7;
          uVar15 = uVar15 + 6;
        }
LAB_001092b8:
        local_88 = local_78;
        std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + (char)uVar5);
        pcVar12 = local_88 + (uVar16 & 0xff);
LAB_001092f3:
        do {
          uVar6 = (uint)(uVar14 / 100);
          uVar5 = (uint)uVar14;
          uVar16 = (uVar5 + uVar6 * -100) * 2;
          cVar13 = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
                   [uVar16];
          pcVar12[uVar15] =
               "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
               [uVar16 + 1];
          uVar16 = uVar15 - 1;
          uVar15 = uVar15 - 2;
          pcVar12[uVar16] = cVar13;
          uVar14 = uVar14 / 100;
        } while (9999 < uVar5);
        if (uVar5 < 1000) goto LAB_00109341;
      }
      cVar13 = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
               [uVar6 * 2];
      pcVar12[1] = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
                   [uVar6 * 2 + 1];
    }
    *pcVar12 = cVar13;
    if (0x3fffffffffffffffU - local_80 < 0x1e) {
                    /* WARNING: Subroutine does not return */
      std::__throw_length_error("basic_string::append");
    }
    puVar4 = (undefined8 *)std::__cxx11::string::_M_append((char *)&local_88,0x127158);
    goto LAB_00109375;
  case 0x12d:
    uVar16 = -iVar1;
    uVar6 = -param_2;
    if ((int)-param_2 < 0) {
      uVar6 = param_2;
    }
    uVar14 = (ulong)uVar6;
    cVar13 = (char)uVar16;
    if (uVar6 < 10) {
      local_88 = local_78;
      std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + '\x01');
      pcVar12 = local_88 + (uVar16 & 0xff);
LAB_00109971:
      cVar13 = (char)uVar6 + '0';
    }
    else {
      if (uVar6 < 100) {
        cVar3 = '\x02';
        uVar15 = 1;
LAB_0010a34e:
        local_88 = local_78;
        std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + cVar3);
        pcVar12 = local_88 + (uVar16 & 0xff);
        if (99 < uVar6) goto LAB_00109923;
      }
      else {
        if (uVar6 < 1000) {
          uVar15 = 2;
          uVar5 = 3;
        }
        else if (uVar6 < 10000) {
          uVar15 = 3;
          uVar5 = 4;
        }
        else {
          uVar11 = uVar14;
          uVar5 = 1;
          do {
            uVar15 = uVar5;
            uVar5 = uVar15 + 4;
            if (uVar11 < 100000) {
              uVar15 = uVar15 + 3;
              goto LAB_001098f0;
            }
            uVar9 = (uint)(uVar11 / 10000);
            if (uVar9 < 100) {
              cVar3 = (char)uVar15 + '\x05';
              uVar15 = uVar5;
              goto LAB_0010a34e;
            }
            if (uVar9 < 1000) {
              uVar5 = uVar15 + 6;
              uVar15 = uVar15 + 5;
              goto LAB_001098f0;
            }
            uVar11 = uVar11 / 10000;
          } while (9999 < uVar9);
          uVar5 = uVar15 + 7;
          uVar15 = uVar15 + 6;
        }
LAB_001098f0:
        local_88 = local_78;
        std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + (char)uVar5);
        pcVar12 = local_88 + (uVar16 & 0xff);
LAB_00109923:
        do {
          uVar6 = (uint)(uVar14 / 100);
          uVar5 = (uint)uVar14;
          uVar16 = (uVar5 + uVar6 * -100) * 2;
          cVar13 = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
                   [uVar16];
          pcVar12[uVar15] =
               "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
               [uVar16 + 1];
          uVar16 = uVar15 - 1;
          uVar15 = uVar15 - 2;
          pcVar12[uVar16] = cVar13;
          uVar14 = uVar14 / 100;
        } while (9999 < uVar5);
        if (uVar5 < 1000) goto LAB_00109971;
      }
      cVar13 = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
               [uVar6 * 2];
      pcVar12[1] = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
                   [uVar6 * 2 + 1];
    }
    *pcVar12 = cVar13;
    if (0x3fffffffffffffffU - local_80 < 0x10) {
                    /* WARNING: Subroutine does not return */
      std::__throw_length_error("basic_string::append");
    }
    puVar4 = (undefined8 *)std::__cxx11::string::_M_append((char *)&local_88,0x12737b);
    goto LAB_001091f5;
  case 0x12e:
    uVar16 = -iVar1;
    uVar6 = -param_2;
    if ((int)-param_2 < 0) {
      uVar6 = param_2;
    }
    uVar14 = (ulong)uVar6;
    cVar13 = (char)uVar16;
    if (uVar6 < 10) {
      local_88 = local_78;
      std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + '\x01');
      pcVar12 = local_88 + (uVar16 & 0xff);
LAB_00109f71:
      cVar13 = (char)uVar6 + '0';
    }
    else {
      if (uVar6 < 100) {
        cVar3 = '\x02';
        uVar15 = 1;
LAB_0010a11b:
        local_88 = local_78;
        std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + cVar3);
        pcVar12 = local_88 + (uVar16 & 0xff);
        if (99 < uVar6) goto LAB_00109f23;
      }
      else {
        if (uVar6 < 1000) {
          uVar15 = 2;
          uVar5 = 3;
        }
        else if (uVar6 < 10000) {
          uVar15 = 3;
          uVar5 = 4;
        }
        else {
          uVar11 = uVar14;
          uVar5 = 1;
          do {
            uVar15 = uVar5;
            uVar5 = uVar15 + 4;
            if (uVar11 < 100000) {
              uVar15 = uVar15 + 3;
              goto LAB_00109ee8;
            }
            uVar9 = (uint)(uVar11 / 10000);
            if (uVar9 < 100) {
              cVar3 = (char)uVar15 + '\x05';
              uVar15 = uVar5;
              goto LAB_0010a11b;
            }
            if (uVar9 < 1000) {
              uVar5 = uVar15 + 6;
              uVar15 = uVar15 + 5;
              goto LAB_00109ee8;
            }
            uVar11 = uVar11 / 10000;
          } while (9999 < uVar9);
          uVar5 = uVar15 + 7;
          uVar15 = uVar15 + 6;
        }
LAB_00109ee8:
        local_88 = local_78;
        std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + (char)uVar5);
        pcVar12 = local_88 + (uVar16 & 0xff);
LAB_00109f23:
        do {
          uVar6 = (uint)(uVar14 / 100);
          uVar5 = (uint)uVar14;
          uVar16 = (uVar5 + uVar6 * -100) * 2;
          cVar13 = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
                   [uVar16];
          pcVar12[uVar15] =
               "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
               [uVar16 + 1];
          uVar16 = uVar15 - 1;
          uVar15 = uVar15 - 2;
          pcVar12[uVar16] = cVar13;
          uVar14 = uVar14 / 100;
        } while (9999 < uVar5);
        if (uVar5 < 1000) goto LAB_00109f71;
      }
      cVar13 = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
               [uVar6 * 2];
      pcVar12[1] = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
                   [uVar6 * 2 + 1];
    }
    *pcVar12 = cVar13;
    if (0x3fffffffffffffffU - local_80 < 0x1e) {
                    /* WARNING: Subroutine does not return */
      std::__throw_length_error("basic_string::append");
    }
    puVar4 = (undefined8 *)std::__cxx11::string::_M_append((char *)&local_88,0x127178);
    goto LAB_00108fc5;
  case 0x12f:
    uVar16 = -iVar1;
    uVar6 = -param_2;
    if ((int)-param_2 < 0) {
      uVar6 = param_2;
    }
    uVar14 = (ulong)uVar6;
    cVar13 = (char)uVar16;
    if (uVar6 < 10) {
      local_88 = local_78;
      std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + '\x01');
      pcVar12 = local_88 + (uVar16 & 0xff);
LAB_00109ac1:
      cVar13 = (char)uVar6 + '0';
    }
    else {
      if (uVar6 < 100) {
        cVar3 = '\x02';
        uVar15 = 1;
LAB_0010a22e:
        local_88 = local_78;
        std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + cVar3);
        pcVar12 = local_88 + (uVar16 & 0xff);
        if (99 < uVar6) goto LAB_00109a73;
      }
      else {
        if (uVar6 < 1000) {
          uVar15 = 2;
          uVar5 = 3;
        }
        else if (uVar6 < 10000) {
          uVar15 = 3;
          uVar5 = 4;
        }
        else {
          uVar11 = uVar14;
          uVar5 = 1;
          do {
            uVar15 = uVar5;
            uVar5 = uVar15 + 4;
            if (uVar11 < 100000) {
              uVar15 = uVar15 + 3;
              goto LAB_00109a40;
            }
            uVar9 = (uint)(uVar11 / 10000);
            if (uVar9 < 100) {
              cVar3 = (char)uVar15 + '\x05';
              uVar15 = uVar5;
              goto LAB_0010a22e;
            }
            if (uVar9 < 1000) {
              uVar5 = uVar15 + 6;
              uVar15 = uVar15 + 5;
              goto LAB_00109a40;
            }
            uVar11 = uVar11 / 10000;
          } while (9999 < uVar9);
          uVar5 = uVar15 + 7;
          uVar15 = uVar15 + 6;
        }
LAB_00109a40:
        local_88 = local_78;
        std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + (char)uVar5);
        pcVar12 = local_88 + (uVar16 & 0xff);
LAB_00109a73:
        do {
          uVar6 = (uint)(uVar14 / 100);
          uVar5 = (uint)uVar14;
          uVar16 = (uVar5 + uVar6 * -100) * 2;
          cVar13 = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
                   [uVar16];
          pcVar12[uVar15] =
               "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
               [uVar16 + 1];
          uVar16 = uVar15 - 1;
          uVar15 = uVar15 - 2;
          pcVar12[uVar16] = cVar13;
          uVar14 = uVar14 / 100;
        } while (9999 < uVar5);
        if (uVar5 < 1000) goto LAB_00109ac1;
      }
      cVar13 = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
               [uVar6 * 2];
      pcVar12[1] = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
                   [uVar6 * 2 + 1];
    }
    *pcVar12 = cVar13;
    if (0x3fffffffffffffffU - local_80 < 0x10) {
                    /* WARNING: Subroutine does not return */
      std::__throw_length_error("basic_string::append");
    }
    puVar4 = (undefined8 *)std::__cxx11::string::_M_append((char *)&local_88,0x12738c);
    goto LAB_00109af5;
  default:
    goto switchD_00108d3f_caseD_130;
  case 0x131:
    uVar16 = -iVar1;
    uVar6 = -param_2;
    if ((int)-param_2 < 0) {
      uVar6 = param_2;
    }
    uVar14 = (ulong)uVar6;
    cVar13 = (char)uVar16;
    if (uVar6 < 10) {
      local_88 = local_78;
      std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + '\x01');
      pcVar12 = local_88 + (uVar16 & 0xff);
LAB_00109791:
      cVar13 = (char)uVar6 + '0';
    }
    else {
      if (uVar6 < 100) {
        cVar3 = '\x02';
        uVar15 = 1;
LAB_0010a1ce:
        local_88 = local_78;
        std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + cVar3);
        pcVar12 = local_88 + (uVar16 & 0xff);
        if (99 < uVar6) goto LAB_00109743;
      }
      else {
        if (uVar6 < 1000) {
          uVar15 = 2;
          uVar5 = 3;
        }
        else if (uVar6 < 10000) {
          uVar15 = 3;
          uVar5 = 4;
        }
        else {
          uVar11 = uVar14;
          uVar5 = 1;
          do {
            uVar15 = uVar5;
            uVar5 = uVar15 + 4;
            if (uVar11 < 100000) {
              uVar15 = uVar15 + 3;
              goto LAB_00109708;
            }
            uVar9 = (uint)(uVar11 / 10000);
            if (uVar9 < 100) {
              cVar3 = (char)uVar15 + '\x05';
              uVar15 = uVar5;
              goto LAB_0010a1ce;
            }
            if (uVar9 < 1000) {
              uVar5 = uVar15 + 6;
              uVar15 = uVar15 + 5;
              goto LAB_00109708;
            }
            uVar11 = uVar11 / 10000;
          } while (9999 < uVar9);
          uVar5 = uVar15 + 7;
          uVar15 = uVar15 + 6;
        }
LAB_00109708:
        local_88 = local_78;
        std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + (char)uVar5);
        pcVar12 = local_88 + (uVar16 & 0xff);
LAB_00109743:
        do {
          uVar6 = (uint)(uVar14 / 100);
          uVar5 = (uint)uVar14;
          uVar16 = (uVar5 + uVar6 * -100) * 2;
          cVar13 = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
                   [uVar16];
          pcVar12[uVar15] =
               "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
               [uVar16 + 1];
          uVar16 = uVar15 - 1;
          uVar15 = uVar15 - 2;
          pcVar12[uVar16] = cVar13;
          uVar14 = uVar14 / 100;
        } while (9999 < uVar5);
        if (uVar5 < 1000) goto LAB_00109791;
      }
      cVar13 = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
               [uVar6 * 2];
      pcVar12[1] = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
                   [uVar6 * 2 + 1];
    }
    *pcVar12 = cVar13;
    if (0x3fffffffffffffffU - local_80 < 0x10) {
                    /* WARNING: Subroutine does not return */
      std::__throw_length_error("basic_string::append");
    }
    puVar4 = (undefined8 *)std::__cxx11::string::_M_append((char *)&local_88,0x12739d);
    local_68 = &uStack_58;
    puVar10 = puVar4 + 2;
    puVar8 = (undefined8 *)*puVar4;
    if (puVar8 == puVar10) {
      uStack_58 = puVar4[2];
      uStack_50 = puVar4[3];
      break;
    }
    goto LAB_00108fe0;
  case 0x136:
    uVar16 = -iVar1;
    uVar6 = -param_2;
    if ((int)-param_2 < 0) {
      uVar6 = param_2;
    }
    uVar14 = (ulong)uVar6;
    cVar13 = (char)uVar16;
    if (uVar6 < 10) {
      local_88 = local_78;
      std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + '\x01');
      pcVar12 = local_88 + (uVar16 & 0xff);
LAB_00109611:
      cVar13 = (char)uVar6 + '0';
    }
    else {
      if (uVar6 < 100) {
        cVar3 = '\x02';
        uVar15 = 1;
LAB_0010a4ce:
        local_88 = local_78;
        std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + cVar3);
        pcVar12 = local_88 + (uVar16 & 0xff);
        if (99 < uVar6) goto LAB_001095c3;
      }
      else {
        if (uVar6 < 1000) {
          uVar15 = 2;
          uVar5 = 3;
        }
        else if (uVar6 < 10000) {
          uVar15 = 3;
          uVar5 = 4;
        }
        else {
          uVar11 = uVar14;
          uVar5 = 1;
          do {
            uVar15 = uVar5;
            uVar5 = uVar15 + 4;
            if (uVar11 < 100000) {
              uVar15 = uVar15 + 3;
              goto LAB_00109590;
            }
            uVar9 = (uint)(uVar11 / 10000);
            if (uVar9 < 100) {
              cVar3 = (char)uVar15 + '\x05';
              uVar15 = uVar5;
              goto LAB_0010a4ce;
            }
            if (uVar9 < 1000) {
              uVar5 = uVar15 + 6;
              uVar15 = uVar15 + 5;
              goto LAB_00109590;
            }
            uVar11 = uVar11 / 10000;
          } while (9999 < uVar9);
          uVar5 = uVar15 + 7;
          uVar15 = uVar15 + 6;
        }
LAB_00109590:
        local_88 = local_78;
        std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + (char)uVar5);
        pcVar12 = local_88 + (uVar16 & 0xff);
LAB_001095c3:
        do {
          uVar6 = (uint)(uVar14 / 100);
          uVar5 = (uint)uVar14;
          uVar16 = (uVar5 + uVar6 * -100) * 2;
          cVar13 = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
                   [uVar16];
          pcVar12[uVar15] =
               "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
               [uVar16 + 1];
          uVar16 = uVar15 - 1;
          uVar15 = uVar15 - 2;
          pcVar12[uVar16] = cVar13;
          uVar14 = uVar14 / 100;
        } while (9999 < uVar5);
        if (uVar5 < 1000) goto LAB_00109611;
      }
      cVar13 = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
               [uVar6 * 2];
      pcVar12[1] = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
                   [uVar6 * 2 + 1];
    }
    *pcVar12 = cVar13;
    if (0x3fffffffffffffffU - local_80 < 0x34) {
                    /* WARNING: Subroutine does not return */
      std::__throw_length_error("basic_string::append");
    }
    puVar4 = (undefined8 *)std::__cxx11::string::_M_append((char *)&local_88,0x127198);
    local_68 = &uStack_58;
    puVar10 = puVar4 + 2;
    puVar8 = (undefined8 *)*puVar4;
    if (puVar8 != puVar10) goto LAB_00108fe0;
    uStack_58 = puVar4[2];
    uStack_50 = puVar4[3];
    break;
  case 0x137:
    uVar16 = -iVar1;
    uVar6 = -param_2;
    if ((int)-param_2 < 0) {
      uVar6 = param_2;
    }
    uVar14 = (ulong)uVar6;
    cVar13 = (char)uVar16;
    if (uVar6 < 10) {
      local_88 = local_78;
      std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + '\x01');
      pcVar12 = local_88 + (uVar16 & 0xff);
LAB_00109df1:
      cVar13 = (char)uVar6 + '0';
    }
    else {
      if (uVar6 < 100) {
        cVar3 = '\x02';
        uVar15 = 1;
LAB_0010a46e:
        local_88 = local_78;
        std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + cVar3);
        pcVar12 = local_88 + (uVar16 & 0xff);
        if (99 < uVar6) goto LAB_00109da3;
      }
      else {
        if (uVar6 < 1000) {
          uVar15 = 2;
          uVar5 = 3;
        }
        else if (uVar6 < 10000) {
          uVar15 = 3;
          uVar5 = 4;
        }
        else {
          uVar11 = uVar14;
          uVar5 = 1;
          do {
            uVar15 = uVar5;
            uVar5 = uVar15 + 4;
            if (uVar11 < 100000) {
              uVar15 = uVar15 + 3;
              goto LAB_00109d70;
            }
            uVar9 = (uint)(uVar11 / 10000);
            if (uVar9 < 100) {
              cVar3 = (char)uVar15 + '\x05';
              uVar15 = uVar5;
              goto LAB_0010a46e;
            }
            if (uVar9 < 1000) {
              uVar5 = uVar15 + 6;
              uVar15 = uVar15 + 5;
              goto LAB_00109d70;
            }
            uVar11 = uVar11 / 10000;
          } while (9999 < uVar9);
          uVar5 = uVar15 + 7;
          uVar15 = uVar15 + 6;
        }
LAB_00109d70:
        local_88 = local_78;
        std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + (char)uVar5);
        pcVar12 = local_88 + (uVar16 & 0xff);
LAB_00109da3:
        do {
          uVar6 = (uint)(uVar14 / 100);
          uVar5 = (uint)uVar14;
          uVar16 = (uVar5 + uVar6 * -100) * 2;
          cVar13 = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
                   [uVar16];
          pcVar12[uVar15] =
               "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
               [uVar16 + 1];
          uVar16 = uVar15 - 1;
          uVar15 = uVar15 - 2;
          pcVar12[uVar16] = cVar13;
          uVar14 = uVar14 / 100;
        } while (9999 < uVar5);
        if (uVar5 < 1000) goto LAB_00109df1;
      }
      cVar13 = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
               [uVar6 * 2];
      pcVar12[1] = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
                   [uVar6 * 2 + 1];
    }
    *pcVar12 = cVar13;
    if (0x3fffffffffffffffU - local_80 < 0x27) {
                    /* WARNING: Subroutine does not return */
      std::__throw_length_error("basic_string::append");
    }
    puVar4 = (undefined8 *)std::__cxx11::string::_M_append((char *)&local_88,0x1271d0);
    local_68 = &uStack_58;
    puVar10 = puVar4 + 2;
    puVar8 = (undefined8 *)*puVar4;
    if (puVar8 != puVar10) goto LAB_00108fe0;
    uStack_58 = puVar4[2];
    uStack_50 = puVar4[3];
    break;
  case 0x138:
    uVar16 = -iVar1;
    uVar6 = -param_2;
    if ((int)-param_2 < 0) {
      uVar6 = param_2;
    }
    uVar14 = (ulong)uVar6;
    cVar13 = (char)uVar16;
    if (uVar6 < 10) {
      local_88 = local_78;
      std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + '\x01');
      pcVar12 = local_88 + (uVar16 & 0xff);
LAB_001094c1:
      cVar13 = (char)uVar6 + '0';
    }
    else {
      if (uVar6 < 100) {
        cVar3 = '\x02';
        uVar15 = 1;
LAB_0010a28e:
        local_88 = local_78;
        std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + cVar3);
        pcVar12 = local_88 + (uVar16 & 0xff);
        if (99 < uVar6) goto LAB_00109473;
      }
      else {
        if (uVar6 < 1000) {
          uVar15 = 2;
          uVar5 = 3;
        }
        else if (uVar6 < 10000) {
          uVar15 = 3;
          uVar5 = 4;
        }
        else {
          uVar11 = uVar14;
          uVar5 = 1;
          do {
            uVar15 = uVar5;
            uVar5 = uVar15 + 4;
            if (uVar11 < 100000) {
              uVar15 = uVar15 + 3;
              goto LAB_00109438;
            }
            uVar9 = (uint)(uVar11 / 10000);
            if (uVar9 < 100) {
              cVar3 = (char)uVar15 + '\x05';
              uVar15 = uVar5;
              goto LAB_0010a28e;
            }
            if (uVar9 < 1000) {
              uVar5 = uVar15 + 6;
              uVar15 = uVar15 + 5;
              goto LAB_00109438;
            }
            uVar11 = uVar11 / 10000;
          } while (9999 < uVar9);
          uVar5 = uVar15 + 7;
          uVar15 = uVar15 + 6;
        }
LAB_00109438:
        local_88 = local_78;
        std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + (char)uVar5);
        pcVar12 = local_88 + (uVar16 & 0xff);
LAB_00109473:
        do {
          uVar6 = (uint)(uVar14 / 100);
          uVar5 = (uint)uVar14;
          uVar16 = (uVar5 + uVar6 * -100) * 2;
          cVar13 = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
                   [uVar16];
          pcVar12[uVar15] =
               "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
               [uVar16 + 1];
          uVar16 = uVar15 - 1;
          uVar15 = uVar15 - 2;
          pcVar12[uVar16] = cVar13;
          uVar14 = uVar14 / 100;
        } while (9999 < uVar5);
        if (uVar5 < 1000) goto LAB_001094c1;
      }
      cVar13 = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
               [uVar6 * 2];
      pcVar12[1] = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
                   [uVar6 * 2 + 1];
    }
    *pcVar12 = cVar13;
    if (0x3fffffffffffffffU - local_80 < 0x2b) {
                    /* WARNING: Subroutine does not return */
      std::__throw_length_error("basic_string::append");
    }
    puVar4 = (undefined8 *)std::__cxx11::string::_M_append((char *)&local_88,0x1271f8);
LAB_00109375:
    local_68 = &uStack_58;
    puVar10 = puVar4 + 2;
    puVar8 = (undefined8 *)*puVar4;
    if (puVar8 == puVar10) {
      uStack_58 = puVar4[2];
      uStack_50 = puVar4[3];
    }
    else {
LAB_00108fe0:
      uStack_58 = puVar4[2];
      local_68 = puVar8;
    }
    break;
  case 0x139:
    uVar16 = -iVar1;
    uVar6 = -param_2;
    if ((int)-param_2 < 0) {
      uVar6 = param_2;
    }
    uVar14 = (ulong)uVar6;
    cVar13 = (char)uVar16;
    if (uVar6 < 10) {
      local_88 = local_78;
      std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + '\x01');
      pcVar12 = local_88 + (uVar16 & 0xff);
LAB_001091c1:
      cVar13 = (char)uVar6 + '0';
    }
    else {
      if (uVar6 < 100) {
        cVar3 = '\x02';
        uVar15 = 1;
LAB_0010a3ae:
        local_88 = local_78;
        std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + cVar3);
        pcVar12 = local_88 + (uVar16 & 0xff);
        if (99 < uVar6) goto LAB_00109173;
      }
      else {
        if (uVar6 < 1000) {
          uVar15 = 2;
          uVar5 = 3;
        }
        else if (uVar6 < 10000) {
          uVar15 = 3;
          uVar5 = 4;
        }
        else {
          uVar11 = uVar14;
          uVar5 = 1;
          do {
            uVar15 = uVar5;
            uVar5 = uVar15 + 4;
            if (uVar11 < 100000) {
              uVar15 = uVar15 + 3;
              goto LAB_00109138;
            }
            uVar9 = (uint)(uVar11 / 10000);
            if (uVar9 < 100) {
              cVar3 = (char)uVar15 + '\x05';
              uVar15 = uVar5;
              goto LAB_0010a3ae;
            }
            if (uVar9 < 1000) {
              uVar5 = uVar15 + 6;
              uVar15 = uVar15 + 5;
              goto LAB_00109138;
            }
            uVar11 = uVar11 / 10000;
          } while (9999 < uVar9);
          uVar5 = uVar15 + 7;
          uVar15 = uVar15 + 6;
        }
LAB_00109138:
        local_88 = local_78;
        std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + (char)uVar5);
        pcVar12 = local_88 + (uVar16 & 0xff);
LAB_00109173:
        do {
          uVar6 = (uint)(uVar14 / 100);
          uVar5 = (uint)uVar14;
          uVar16 = (uVar5 + uVar6 * -100) * 2;
          cVar13 = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
                   [uVar16];
          pcVar12[uVar15] =
               "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
               [uVar16 + 1];
          uVar16 = uVar15 - 1;
          uVar15 = uVar15 - 2;
          pcVar12[uVar16] = cVar13;
          uVar14 = uVar14 / 100;
        } while (9999 < uVar5);
        if (uVar5 < 1000) goto LAB_001091c1;
      }
      cVar13 = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
               [uVar6 * 2];
      pcVar12[1] = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
                   [uVar6 * 2 + 1];
    }
    *pcVar12 = cVar13;
    if (0x3fffffffffffffffU - local_80 < 0x25) {
                    /* WARNING: Subroutine does not return */
      std::__throw_length_error("basic_string::append");
    }
    puVar4 = (undefined8 *)std::__cxx11::string::_M_append((char *)&local_88,0x127228);
LAB_001091f5:
    local_68 = &uStack_58;
    puVar10 = puVar4 + 2;
    puVar8 = (undefined8 *)*puVar4;
    if (puVar8 == puVar10) {
      uStack_58 = puVar4[2];
      uStack_50 = puVar4[3];
      break;
    }
    goto LAB_00108fe0;
  case 0x13a:
    uVar16 = param_2 >> 0x1f;
    uVar6 = -param_2;
    if ((int)-param_2 < 0) {
      uVar6 = param_2;
    }
    uVar14 = (ulong)uVar6;
    cVar13 = (char)((int)param_2 >> 0x1f);
    if (uVar6 < 10) {
      local_88 = local_78;
      std::__cxx11::string::_M_construct((ulong)&local_88,'\x01' - cVar13);
      pcVar12 = local_88 + uVar16;
LAB_00108f91:
      cVar13 = (char)uVar6 + '0';
    }
    else {
      if (uVar6 < 100) {
        cVar3 = '\x02';
        uVar15 = 1;
LAB_0010a176:
        local_88 = local_78;
        std::__cxx11::string::_M_construct((ulong)&local_88,cVar3 - cVar13);
        pcVar12 = local_88 + uVar16;
        if (99 < uVar6) goto LAB_00108f43;
      }
      else {
        if (uVar6 < 1000) {
          uVar15 = 2;
          uVar5 = 3;
        }
        else if (uVar6 < 10000) {
          uVar15 = 3;
          uVar5 = 4;
        }
        else {
          uVar11 = uVar14;
          uVar5 = 1;
          do {
            uVar15 = uVar5;
            uVar5 = uVar15 + 4;
            if (uVar11 < 100000) {
              uVar15 = uVar15 + 3;
              goto LAB_00108f10;
            }
            uVar9 = (uint)(uVar11 / 10000);
            if (uVar9 < 100) {
              cVar3 = (char)uVar15 + '\x05';
              uVar15 = uVar5;
              goto LAB_0010a176;
            }
            if (uVar9 < 1000) {
              uVar5 = uVar15 + 6;
              uVar15 = uVar15 + 5;
              goto LAB_00108f10;
            }
            uVar11 = uVar11 / 10000;
          } while (9999 < uVar9);
          uVar5 = uVar15 + 7;
          uVar15 = uVar15 + 6;
        }
LAB_00108f10:
        local_88 = local_78;
        std::__cxx11::string::_M_construct((ulong)&local_88,(char)uVar5 - cVar13);
        pcVar12 = local_88 + uVar16;
LAB_00108f43:
        do {
          uVar6 = (uint)(uVar14 / 100);
          uVar5 = (uint)uVar14;
          uVar16 = (uVar5 + uVar6 * -100) * 2;
          cVar13 = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
                   [uVar16];
          pcVar12[uVar15] =
               "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
               [uVar16 + 1];
          uVar16 = uVar15 - 1;
          uVar15 = uVar15 - 2;
          pcVar12[uVar16] = cVar13;
          uVar14 = uVar14 / 100;
        } while (9999 < uVar5);
        if (uVar5 < 1000) goto LAB_00108f91;
      }
      cVar13 = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
               [uVar6 * 2];
      pcVar12[1] = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
                   [uVar6 * 2 + 1];
    }
    *pcVar12 = cVar13;
    if (0x3fffffffffffffffU - local_80 < 0x19) {
                    /* WARNING: Subroutine does not return */
      std::__throw_length_error("basic_string::append");
    }
    puVar4 = (undefined8 *)std::__cxx11::string::_M_append((char *)&local_88,0x1273ae);
LAB_00108fc5:
    local_68 = &uStack_58;
    puVar10 = puVar4 + 2;
    puVar8 = (undefined8 *)*puVar4;
    if (puVar8 == puVar10) {
      uStack_58 = puVar4[2];
      uStack_50 = puVar4[3];
      break;
    }
    goto LAB_00108fe0;
  case 0x13b:
    uVar16 = -iVar1;
    uVar6 = -param_2;
    if ((int)-param_2 < 0) {
      uVar6 = param_2;
    }
    uVar14 = (ulong)uVar6;
    cVar13 = (char)uVar16;
    if (uVar6 < 10) {
      local_88 = local_78;
      std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + '\x01');
      pcVar12 = local_88 + (uVar16 & 0xff);
LAB_00109ca1:
      cVar13 = (char)uVar6 + '0';
    }
    else {
      if (uVar6 < 100) {
        cVar3 = '\x02';
        uVar15 = 1;
LAB_0010a40e:
        local_88 = local_78;
        std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + cVar3);
        pcVar12 = local_88 + (uVar16 & 0xff);
        if (99 < uVar6) goto LAB_00109c53;
      }
      else {
        if (uVar6 < 1000) {
          uVar15 = 2;
          uVar5 = 3;
        }
        else if (uVar6 < 10000) {
          uVar15 = 3;
          uVar5 = 4;
        }
        else {
          uVar11 = uVar14;
          uVar5 = 1;
          do {
            uVar15 = uVar5;
            uVar5 = uVar15 + 4;
            if (uVar11 < 100000) {
              uVar15 = uVar15 + 3;
              goto LAB_00109c20;
            }
            uVar9 = (uint)(uVar11 / 10000);
            if (uVar9 < 100) {
              cVar3 = (char)uVar15 + '\x05';
              uVar15 = uVar5;
              goto LAB_0010a40e;
            }
            if (uVar9 < 1000) {
              uVar5 = uVar15 + 6;
              uVar15 = uVar15 + 5;
              goto LAB_00109c20;
            }
            uVar11 = uVar11 / 10000;
          } while (9999 < uVar9);
          uVar5 = uVar15 + 7;
          uVar15 = uVar15 + 6;
        }
LAB_00109c20:
        local_88 = local_78;
        std::__cxx11::string::_M_construct((ulong)&local_88,cVar13 + (char)uVar5);
        pcVar12 = local_88 + (uVar16 & 0xff);
LAB_00109c53:
        do {
          uVar6 = (uint)(uVar14 / 100);
          uVar5 = (uint)uVar14;
          uVar16 = (uVar5 + uVar6 * -100) * 2;
          cVar13 = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
                   [uVar16];
          pcVar12[uVar15] =
               "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
               [uVar16 + 1];
          uVar16 = uVar15 - 1;
          uVar15 = uVar15 - 2;
          pcVar12[uVar16] = cVar13;
          uVar14 = uVar14 / 100;
        } while (9999 < uVar5);
        if (uVar5 < 1000) goto LAB_00109ca1;
      }
      cVar13 = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
               [uVar6 * 2];
      pcVar12[1] = "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899"
                   [uVar6 * 2 + 1];
    }
    *pcVar12 = cVar13;
    if (0x3fffffffffffffffU - local_80 < 0x26) {
                    /* WARNING: Subroutine does not return */
      std::__throw_length_error("basic_string::append");
    }
    puVar4 = (undefined8 *)std::__cxx11::string::_M_append((char *)&local_88,0x127250);
LAB_00109af5:
    puVar10 = puVar4 + 2;
    puVar8 = (undefined8 *)*puVar4;
    if (puVar8 == puVar10) {
      uStack_58 = puVar4[2];
      uStack_50 = puVar4[3];
      local_68 = &uStack_58;
      break;
    }
    goto LAB_00108fe0;
  case 0x191:
    if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) goto LAB_0010aa2f;
    puVar7 = &DAT_00127278;
    goto LAB_00108e5c;
  case 0x192:
    if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
      puVar7 = &DAT_001272a0;
      goto LAB_00108e5c;
    }
    goto LAB_0010aa2f;
  case 0x193:
    if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
      puVar7 = &DAT_001272c0;
      goto LAB_00108e5c;
    }
    goto LAB_0010aa2f;
  case 0x194:
    if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
      puVar7 = &DAT_00127308;
      goto LAB_00108e5c;
    }
    goto LAB_0010aa2f;
  }
  local_60 = (char *)puVar4[1];
  *puVar4 = puVar10;
  *(undefined1 *)(puVar4 + 2) = 0;
  puVar10 = DAT_00133220;
  puVar4[1] = 0;
  uVar2 = _DAT_00133230;
  if (local_68 == &uStack_58) {
    if (local_60 != (char *)0x0) {
      if (local_60 == (char *)0x1) {
        *(undefined1 *)puVar10 = (undefined1)uStack_58;
        puVar10 = DAT_00133220;
      }
      else {
        memcpy(puVar10,&uStack_58,(size_t)local_60);
        puVar10 = DAT_00133220;
      }
    }
    DAT_00133228 = local_60;
    *(char *)((long)puVar10 + (long)local_60) = '\0';
  }
  else {
    DAT_00133228 = local_60;
    if (puVar10 != (undefined8 *)&DAT_00133230) {
      DAT_00133220 = local_68;
      _DAT_00133230 = uStack_58;
      if (puVar10 != (undefined8 *)0x0) {
        local_68 = puVar10;
        uStack_58 = uVar2;
        goto LAB_00109051;
      }
    }
    _DAT_00133230 = uStack_58;
    DAT_00133220 = local_68;
    local_68 = &uStack_58;
  }
LAB_00109051:
  local_60 = (char *)0x0;
  *(undefined1 *)local_68 = 0;
  if (local_68 != &uStack_58) {
    operator_delete(local_68);
  }
  if (local_88 != local_78) {
    operator_delete(local_88);
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
LAB_0010aa2f:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_0010ab40 @ 0010ab40 size=215 =====

void FUN_0010ab40(undefined8 *param_1,undefined2 *param_2,long param_3)

{
  undefined2 *__dest;
  ulong uVar1;
  ulong __n;
  long lVar2;
  
  if ((param_2 == (undefined2 *)0x0) && (param_3 != 0)) {
    uVar1 = std::__throw_logic_error("basic_string::_M_construct null not valid");
  }
  else {
    __n = param_3 - (long)param_2;
    lVar2 = (long)__n >> 1;
    if (__n < 0xf) {
      __dest = (undefined2 *)*param_1;
joined_r0x0010abe5:
      if (lVar2 == 1) {
        *__dest = *param_2;
      }
      else if (lVar2 != 0) {
        memcpy(__dest,param_2,__n);
        __dest = (undefined2 *)*param_1;
      }
      param_1[1] = lVar2;
      *(undefined2 *)((long)__dest + __n) = 0;
      return;
    }
    if (0x3ffffffffffffffe < __n) goto LAB_0010ac15;
    uVar1 = lVar2 + 1;
    if (uVar1 >> 0x3e == 0) {
      __dest = operator_new(__n + 2);
      param_1[2] = lVar2;
      *param_1 = __dest;
      goto joined_r0x0010abe5;
    }
  }
  if (-1 < (long)uVar1) {
    std::__throw_bad_alloc();
  }
  std::__throw_bad_array_new_length();
LAB_0010ac15:
                    /* WARNING: Subroutine does not return */
  std::__throw_length_error("basic_string::_M_create");
}


//===== FUN_0010ac30 @ 0010ac30 size=5 =====

void FUN_0010ac30(void)

{
  return;
}


//===== FUN_0010ac40 @ 0010ac40 size=5 =====

void FUN_0010ac40(void)

{
  return;
}


//===== FUN_0010ac50 @ 0010ac50 size=161 =====

ulong FUN_0010ac50(undefined8 param_1,long *param_2,ulong param_3,long param_4,uint param_5)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  ulong uVar4;
  
  uVar4 = (param_2[1] - *param_2 >> 3) * -0x71c71c71c71c71c7;
  if (uVar4 <= param_3) {
    return 0xffffffff;
  }
  plVar2 = (long *)(*param_2 + param_3 * 0x48);
  do {
    if (plVar2[1] == (ulong)param_5) {
      if ((int)param_5 < 1) {
        if (param_5 == 0) {
          return param_3;
        }
      }
      else {
        lVar1 = 1;
        do {
          lVar3 = lVar1;
          if (*(short *)(*plVar2 + -2 + lVar3 * 2) != *(short *)(param_4 + -2 + lVar3 * 2))
          goto LAB_0010ac98;
          lVar1 = lVar3 + 1;
        } while ((ulong)(param_5 - 1) + 2 != lVar3 + 1);
        if (param_5 == (uint)lVar3) {
          return param_3;
        }
      }
    }
LAB_0010ac98:
    param_3 = param_3 + 1;
    plVar2 = plVar2 + 9;
    if (param_3 == uVar4) {
      return 0xffffffff;
    }
  } while( true );
}


//===== FUN_0010ad00 @ 0010ad00 size=648 =====

undefined8
FUN_0010ad00(undefined8 param_1,char *param_2,undefined8 param_3,void *param_4,long *param_5)

{
  int __fd;
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  ulong uVar4;
  uint uVar5;
  long in_FS_OFFSET;
  undefined1 local_a1;
  uint local_a0;
  uint local_9c;
  char local_98 [8];
  char acStack_90 [8];
  char local_88 [8];
  char acStack_80 [8];
  undefined2 local_78;
  undefined1 auStack_76 [14];
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined2 local_43;
  undefined1 local_41;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_43 = 0;
  local_41 = 0;
  __fd = open64(param_2,0x241,0x80);
  uVar2 = 0x194;
  if (-1 < __fd) {
    local_68 = (undefined1  [16])0x0;
    local_58 = (undefined1  [16])0x0;
    auStack_76 = SUB1614((undefined1  [16])0x0,2);
    local_78 = 0x2e70;
    local_98[0] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[0];
    local_98[1] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[1];
    local_98[2] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[2];
    local_98[3] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[3];
    local_98[4] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[4];
    local_98[5] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[5];
    local_98[6] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[6];
    local_98[7] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[7];
    acStack_90[0] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[8];
    acStack_90[1] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[9];
    acStack_90[2] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[10];
    acStack_90[3] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[0xb];
    acStack_90[4] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[0xc];
    acStack_90[5] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[0xd];
    acStack_90[6] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[0xe];
    acStack_90[7] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[0xf];
    local_88[0] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[0x10];
    local_88[1] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[0x11];
    local_88[2] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[0x12];
    local_88[3] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[0x13];
    local_88[4] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[0x14];
    local_88[5] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[0x15];
    local_88[6] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[0x16];
    local_88[7] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[0x17];
    acStack_80[0] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[0x18];
    acStack_80[1] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[0x19];
    acStack_80[2] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[0x1a];
    acStack_80[3] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[0x1b];
    acStack_80[4] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[0x1c];
    acStack_80[5] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[0x1d];
    acStack_80[6] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[0x1e];
    acStack_80[7] = s_AqK2K_Ver_3_user_dic__AQUEST_Cor_001276f0[0x1f];
    write(__fd,&DAT_00127692,4);
    local_9c = 0x50;
    local_a0 = 0x50;
    write(__fd,&local_a0,4);
    write(__fd,local_98,(ulong)local_9c);
    write(__fd,&DAT_00127697,4);
    local_9c = FUN_0010ead0(param_3);
    if ((local_9c & 3) == 0) {
      local_a0 = local_9c + 4;
      write(__fd,&local_a0,4);
      write(__fd,&local_9c,4);
      FUN_0010e7e0(param_3,__fd);
    }
    else {
      iVar1 = -(local_9c & 3);
      local_a0 = iVar1 + 8 + local_9c;
      write(__fd,&local_a0,4);
      write(__fd,&local_9c,4);
      FUN_0010e7e0(param_3,__fd);
      write(__fd,&local_43,(ulong)(iVar1 + 4));
    }
    write(__fd,&DAT_0012769c,4);
    iVar1 = FUN_0010ea90(param_3);
    local_a0 = iVar1 << 2;
    write(__fd,&local_a0,4);
    write(__fd,param_4,(ulong)local_a0);
    write(__fd,&DAT_001276a1,4);
    local_9c = (uint)(param_5[1] - *param_5);
    uVar5 = local_9c & 3;
    local_a0 = local_9c;
    if ((param_5[1] - *param_5 & 3U) != 0) {
      uVar5 = 4 - uVar5;
      local_a0 = uVar5 + local_9c;
    }
    write(__fd,&local_a0,4);
    uVar4 = 0;
    if (local_9c != 0) {
      do {
        uVar3 = (int)uVar4 + 1;
        local_a1 = *(undefined1 *)(*param_5 + uVar4);
        write(__fd,&local_a1,1);
        uVar4 = (ulong)uVar3;
      } while (uVar3 < local_9c);
    }
    if (uVar5 != 0) {
      write(__fd,&local_43,(ulong)uVar5);
    }
    close(__fd);
    uVar2 = 0;
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_0010afa0 @ 0010afa0 size=1935 =====

undefined4 FUN_0010afa0(undefined8 param_1,char *param_2,long *param_3)

{
  undefined2 *puVar1;
  byte bVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  long *plVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  char *__s1;
  FILE *__stream;
  size_t sVar9;
  ulong uVar10;
  undefined2 *puVar11;
  size_t *psVar12;
  undefined8 uVar13;
  long lVar14;
  ulong uVar15;
  char *pcVar16;
  ulong uVar17;
  byte *pbVar18;
  byte *pbVar19;
  undefined4 uVar20;
  undefined8 *puVar21;
  long in_FS_OFFSET;
  bool bVar22;
  undefined1 local_150 [8];
  undefined1 local_148 [24];
  undefined2 *local_130;
  uint local_128;
  uint local_124;
  ulong *local_118;
  ulong local_110;
  ulong local_108 [2];
  size_t *local_f8;
  __dev_t local_f0;
  size_t local_e8 [2];
  undefined1 local_d8 [40];
  __dev_t local_b0;
  size_t asStack_a8 [2];
  uint local_98;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_0010e6f0(local_150);
  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
    uVar20 = 400;
  }
  else {
    iVar7 = stat64(param_2,(stat64 *)local_d8);
    if ((iVar7 == 0) && (__s1 = malloc(asStack_a8[0]), __s1 != (char *)0x0)) {
      __stream = fopen64(param_2,"rb");
      if (__stream == (FILE *)0x0) {
        free(__s1);
        perror(param_2);
      }
      else {
        sVar9 = fread(__s1,1,asStack_a8[0],__stream);
        if ((asStack_a8[0] & 0xffffffff) <= sVar9) {
          fclose(__stream);
          iVar7 = strncmp(__s1,"HDR1",4);
          if (iVar7 == 0) {
            pcVar16 = __s1 + (*(int *)(__s1 + 4) + 8);
            iVar7 = strncmp(pcVar16,"TRI1",4);
            if (iVar7 == 0) {
              iVar7 = *(int *)(pcVar16 + 4);
              FUN_0010eec0(local_150,pcVar16 + 0xc,*(undefined4 *)(pcVar16 + 8));
              pcVar16 = pcVar16 + (iVar7 + 8);
              iVar7 = strncmp(pcVar16,"MAP1",4);
              if (iVar7 == 0) {
                iVar7 = *(int *)(pcVar16 + 4);
                iVar8 = strncmp(pcVar16 + (iVar7 + 8),"TOK1",4);
                if (iVar8 == 0) {
                  puVar3 = (undefined8 *)*param_3;
                  puVar4 = (undefined8 *)param_3[1];
                  puVar21 = puVar3;
                  if (puVar4 != puVar3) {
                    do {
                      while( true ) {
                        if ((undefined8 *)puVar21[4] != puVar21 + 6) {
                          operator_delete((undefined8 *)puVar21[4]);
                        }
                        if ((undefined8 *)*puVar21 == puVar21 + 2) break;
                        operator_delete((undefined8 *)*puVar21);
                        puVar21 = puVar21 + 9;
                        if (puVar4 == puVar21) goto LAB_0010b170;
                      }
                      puVar21 = puVar21 + 9;
                    } while (puVar21 != puVar4);
LAB_0010b170:
                    param_3[1] = (long)puVar3;
                  }
                  FUN_0010e3a0(local_148);
                  FUN_0010e410(local_148,"");
LAB_0010b1aa:
                  cVar6 = FUN_0010e980(local_150);
                  puVar1 = local_130;
                  if (cVar6 != '\0') {
                    uVar10 = (ulong)local_128;
                    local_118 = local_108;
                    if (((long)local_130 + (uVar10 & 0xfffffffffffffffe) != 0) &&
                       (local_130 == (undefined2 *)0x0)) {
                      uVar13 = std::__throw_logic_error("basic_string::_M_construct null not valid")
                      ;
                      FUN_0010e3d0(local_148);
                      __cxa_begin_catch(uVar13);
                      free(__s1);
                      __cxa_end_catch();
                      uVar20 = 0x195;
                      goto LAB_0010b296;
                    }
                    uVar17 = (long)uVar10 >> 1;
                    if (uVar10 < 0x10) {
                      if (uVar17 != 1) goto LAB_0010b315;
                      local_108[0] = CONCAT62(local_108[0]._2_6_,*local_130);
                    }
                    else {
                      local_118 = operator_new(uVar17 * 2 + 2);
                      local_108[0] = uVar17;
LAB_0010b315:
                      if (uVar17 != 0) {
                        memcpy(local_118,puVar1,uVar10 & 0xfffffffffffffffe);
                      }
                    }
                    *(undefined2 *)((long)local_118 + uVar17 * 2) = 0;
                    pbVar18 = (byte *)(pcVar16 + (iVar7 + 8) +
                                      (ulong)*(uint *)(pcVar16 + (ulong)local_124 * 4 + 8) + 8);
                    bVar2 = pbVar18[4];
                    local_110 = uVar17;
                    if ((bVar2 & 0xf8) == 0x40) {
                      puVar1 = (undefined2 *)(local_d8 + 0x10);
                      do {
                        local_d8._16_8_ = local_d8._16_8_ & 0xffffffffffff0000;
                        pbVar19 = pbVar18 + 7;
                        if ((bVar2 & 4) != 0) {
                          pbVar19 = pbVar18 + 10;
                        }
                        asStack_a8[0] = asStack_a8[0] & 0xffffffffffff0000;
                        local_d8._8_8_ = 0;
                        local_b0 = 0;
                        local_d8._0_8_ = puVar1;
                        local_d8._32_8_ = asStack_a8;
                        FUN_0010cbe0(&local_f8,pbVar19,pbVar18[5] & 0x1f);
                        sVar9 = asStack_a8[0];
                        psVar12 = (size_t *)local_d8._32_8_;
                        if (local_f8 == local_e8) {
                          psVar12 = local_e8;
                          if (local_f0 != 0) {
                            if (local_f0 == 1) {
                              *(undefined2 *)local_d8._32_8_ = (undefined2)local_e8[0];
                            }
                            else {
                              memcpy((void *)local_d8._32_8_,local_e8,local_f0 * 2);
                              psVar12 = local_f8;
                            }
                          }
                          *(undefined2 *)(local_d8._32_8_ + local_f0 * 2) = 0;
                          local_b0 = local_f0;
LAB_0010b55b:
                          local_f0 = 0;
                          *(undefined2 *)psVar12 = 0;
                          if (psVar12 != local_e8) {
                            operator_delete(psVar12);
                          }
                        }
                        else {
                          asStack_a8[0] = local_e8[0];
                          bVar22 = (size_t *)local_d8._32_8_ != asStack_a8;
                          local_d8._32_8_ = local_f8;
                          local_b0 = local_f0;
                          if (bVar22) {
                            local_d8._32_8_ = local_f8;
                            local_b0 = local_f0;
                            if (psVar12 != (size_t *)0x0) {
                              local_f8 = psVar12;
                              local_e8[0] = sVar9;
                              goto LAB_0010b55b;
                            }
                          }
                        }
                        uVar17 = local_110;
                        local_98 = (uint)(ushort)((pbVar18[1] & 0x7f) * 0x100 + (ushort)*pbVar18);
                        uVar10 = 7;
                        if ((undefined2 *)local_d8._0_8_ != puVar1) {
                          uVar10 = local_d8._16_8_;
                        }
                        puVar11 = (undefined2 *)local_d8._0_8_;
                        uVar15 = local_d8._16_8_;
                        if (uVar10 < local_110) {
                          if (0x1fffffffffffffff < local_110) {
                    /* WARNING: Subroutine does not return */
                            std::__throw_length_error("basic_string::_M_create");
                          }
                          uVar10 = uVar10 * 2;
                          uVar15 = 0x1fffffffffffffff;
                          if (uVar10 < 0x2000000000000000) {
                            uVar15 = uVar10;
                          }
                          if (uVar10 <= local_110) {
                            uVar15 = local_110;
                          }
                          puVar11 = operator_new(uVar15 * 2 + 2);
                          if ((undefined2 *)local_d8._0_8_ != puVar1) {
                            operator_delete((void *)local_d8._0_8_);
                          }
                        }
                        local_d8._16_8_ = uVar15;
                        local_d8._0_8_ = puVar11;
                        if (uVar17 != 0) {
                          if (uVar17 == 1) {
                            *(short *)local_d8._0_8_ = (short)*local_118;
                          }
                          else {
                            memcpy((void *)local_d8._0_8_,local_118,uVar17 * 2);
                          }
                        }
                        local_d8._8_8_ = uVar17;
                        *(undefined2 *)(local_d8._0_8_ + uVar17 * 2) = 0;
                        plVar5 = (long *)param_3[1];
                        if (plVar5 == (long *)param_3[2]) {
                          FUN_0010c410(param_3,plVar5,(stat64 *)local_d8);
                        }
                        else {
                          *plVar5 = (long)(plVar5 + 2);
                          FUN_0010ab40(plVar5,local_d8._0_8_,
                                       (undefined2 *)(local_d8._0_8_ + uVar17 * 2));
                          plVar5[4] = (long)(plVar5 + 6);
                          FUN_0010ab40(plVar5 + 4,local_d8._32_8_,
                                       (undefined2 *)(local_d8._32_8_ + local_b0 * 2));
                          *(uint *)(plVar5 + 8) = local_98;
                          param_3[1] = param_3[1] + 0x48;
                        }
                        if ((char)pbVar18[1] < '\0') goto LAB_0010b6d8;
                        uVar10 = (ulong)(pbVar18[4] & 3);
                        lVar14 = uVar10 + 7;
                        if ((pbVar18[4] & 4) != 0) {
                          lVar14 = uVar10 + 10;
                        }
                        pbVar18 = pbVar18 + (ulong)(pbVar18[5] & 0x1f) + lVar14;
                        if ((size_t *)local_d8._32_8_ != asStack_a8) {
                          operator_delete((void *)local_d8._32_8_);
                        }
                        if ((undefined2 *)local_d8._0_8_ != puVar1) {
                          operator_delete((void *)local_d8._0_8_);
                        }
                        bVar2 = pbVar18[4];
                      } while( true );
                    }
                    if (local_118 != local_108) {
                      operator_delete(local_118);
                    }
                    FUN_0010e3d0(local_148);
                    goto LAB_0010b278;
                  }
                  FUN_0010e3d0(local_148);
                  free(__s1);
                  uVar20 = 0;
                  goto LAB_0010b296;
                }
              }
            }
          }
LAB_0010b278:
          uVar20 = 0x192;
          goto LAB_0010b296;
        }
        free(__s1);
        fclose(__stream);
      }
    }
    uVar20 = 0x191;
  }
LAB_0010b296:
  FUN_0010e700(local_150);
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar20;
LAB_0010b6d8:
  if ((size_t *)local_d8._32_8_ != asStack_a8) {
    operator_delete((void *)local_d8._32_8_);
  }
  if ((undefined2 *)local_d8._0_8_ != puVar1) {
    operator_delete((void *)local_d8._0_8_);
  }
  if (local_118 != local_108) {
    operator_delete(local_118);
  }
  goto LAB_0010b1aa;
}


//===== FUN_0010b7b0 @ 0010b7b0 size=912 =====

int FUN_0010b7b0(undefined8 param_1,int param_2,long param_3,long *param_4)

{
  void *__dest;
  ushort uVar1;
  int iVar2;
  long lVar3;
  void *__dest_00;
  ulong uVar4;
  void *__dest_01;
  size_t sVar6;
  void *__src;
  ulong uVar7;
  size_t sVar8;
  void *pvVar9;
  long in_FS_OFFSET;
  void *local_90;
  long local_88;
  byte local_5b;
  byte local_5a;
  byte local_59;
  undefined1 local_58 [16];
  undefined8 local_48;
  long local_40;
  size_t sVar5;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_4[1] != *param_4) {
    param_4[1] = *param_4;
  }
  uVar1 = (ushort)*(undefined4 *)(param_3 + 0x40);
  if (param_2 != 0) {
    uVar1 = uVar1 | 0x8000;
  }
  local_58[0] = (char)uVar1;
  FUN_0010c780(param_4,local_58);
  local_58[0] = (undefined1)(uVar1 >> 8);
  FUN_0010c780(param_4,local_58);
  local_58[0] = 0;
  FUN_0010c780(param_4,local_58);
  local_58[0] = 0;
  FUN_0010c780(param_4,local_58);
  local_58[0] = 0x40;
  FUN_0010c780(param_4,local_58);
  local_58 = (undefined1  [16])0x0;
  local_48 = 0;
  iVar2 = FUN_0010c990(*(undefined8 *)(param_3 + 0x20),&local_5b,&local_5a,local_58);
  if (iVar2 == 0) {
    local_59 = local_5b | 0x80;
    FUN_0010c780(param_4,&local_59);
    local_59 = local_5a | 0x80;
    FUN_0010c780(param_4,&local_59);
    pvVar9 = (void *)param_4[1];
    __dest_00 = (void *)*param_4;
    sVar8 = (long)pvVar9 - (long)__dest_00;
    uVar7 = local_58._8_8_ + (sVar8 - local_58._0_8_);
    if ((long)uVar7 < 0) {
                    /* WARNING: Subroutine does not return */
      std::__throw_length_error("vector::reserve");
    }
    lVar3 = param_4[2];
    __src = (void *)local_58._0_8_;
    if ((ulong)(lVar3 - (long)__dest_00) < uVar7) {
      __dest_00 = operator_new(uVar7);
      pvVar9 = (void *)*param_4;
      if (param_4[1] - (long)pvVar9 < 1) {
        if (pvVar9 != (void *)0x0) goto LAB_0010bab6;
      }
      else {
        __dest_00 = memmove(__dest_00,pvVar9,param_4[1] - (long)pvVar9);
LAB_0010bab6:
        operator_delete(pvVar9);
      }
      pvVar9 = (void *)((long)__dest_00 + sVar8);
      lVar3 = (long)__dest_00 + uVar7;
      param_4[2] = lVar3;
      *param_4 = (long)__dest_00;
      param_4[1] = (long)pvVar9;
      __src = (void *)local_58._0_8_;
    }
    if ((void *)local_58._8_8_ == __src) goto LAB_0010b87c;
    sVar6 = local_58._8_8_ - (long)__src;
    if (sVar6 <= (ulong)(lVar3 - (long)pvVar9)) {
      memmove(pvVar9,__src,sVar6);
      param_4[1] = param_4[1] + sVar6;
      __src = (void *)local_58._0_8_;
      goto LAB_0010b87c;
    }
    if (0x7fffffffffffffff - sVar8 < sVar6) {
                    /* WARNING: Subroutine does not return */
      std::__throw_length_error("vector::_M_range_insert");
    }
    sVar5 = sVar6;
    if (sVar6 <= sVar8) {
      sVar5 = sVar8;
    }
    uVar4 = sVar5 + sVar8;
    uVar7 = 0x7fffffffffffffff;
    if (CARRY8(sVar5,sVar8)) {
LAB_0010bb11:
      __dest_01 = operator_new(uVar7);
      __dest_00 = (void *)*param_4;
      local_88 = uVar7 + (long)__dest_01;
      sVar8 = (long)pvVar9 - (long)__dest_00;
    }
    else {
      local_88 = 0;
      __dest_01 = (void *)0x0;
      if (uVar4 != 0) {
        uVar7 = 0x7fffffffffffffff;
        if (uVar4 < 0x8000000000000000) {
          uVar7 = uVar4;
        }
        goto LAB_0010bb11;
      }
    }
    __dest = (void *)((long)__dest_01 + sVar8);
    local_90 = (void *)((long)__dest + sVar6);
    if (sVar8 == 0) {
      memcpy(__dest,__src,sVar6);
      sVar8 = param_4[1] - (long)pvVar9;
      sVar6 = 0;
      if (sVar8 != 0) {
LAB_0010bad0:
        memcpy(local_90,pvVar9,sVar8);
        sVar6 = sVar8;
      }
      local_90 = (void *)((long)local_90 + sVar6);
      if (__dest_00 != (void *)0x0) goto LAB_0010ba90;
    }
    else {
      memmove(__dest_01,__dest_00,sVar8);
      memcpy(__dest,__src,sVar6);
      sVar8 = param_4[1] - (long)pvVar9;
      if (sVar8 != 0) goto LAB_0010bad0;
LAB_0010ba90:
      operator_delete(__dest_00);
    }
    param_4[2] = local_88;
    *param_4 = (long)__dest_01;
    param_4[1] = (long)local_90;
  }
  __src = (void *)local_58._0_8_;
LAB_0010b87c:
  if (__src != (void *)0x0) {
    operator_delete(__src);
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_0010bb70 @ 0010bb70 size=1104 =====

int FUN_0010bb70(undefined8 param_1,long *param_2,undefined8 param_3,long param_4,long *param_5)

{
  void *__dest;
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  void *__dest_00;
  ulong uVar6;
  size_t __n;
  void *pvVar8;
  long lVar9;
  void *pvVar10;
  size_t sVar11;
  long in_FS_OFFSET;
  void *local_f8;
  size_t local_f0;
  void *local_d8;
  long local_d0;
  ulong local_c8;
  undefined1 local_98 [16];
  undefined8 local_88;
  undefined1 local_78 [24];
  undefined8 local_60;
  uint local_58;
  long local_40;
  ulong uVar7;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_0010e3a0(local_78);
  local_c8 = 0;
  do {
    uVar5 = FUN_0010ea90(param_3);
    if (uVar5 <= local_c8) {
      iVar4 = 0;
LAB_0010bf23:
      FUN_0010e3d0(local_78);
      if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
        return iVar4;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    FUN_0010e480(local_78,local_c8);
    FUN_0010e8e0(param_3,local_78);
    uVar2 = local_60;
    *(int *)(param_4 + local_c8 * 4) = (int)param_5[1] - (int)*param_5;
    uVar1 = local_58 >> 1;
    uVar3 = FUN_0010ac50(param_1,param_2,0);
    if ((int)uVar3 < 0) {
      iVar4 = 0x194;
      goto LAB_0010bf23;
    }
    do {
      lVar9 = (long)(int)uVar3;
      uVar3 = FUN_0010ac50(param_1,param_2,(long)(int)(uVar3 + 1),uVar2,uVar1);
      local_98 = (undefined1  [16])0x0;
      local_88 = 0;
      iVar4 = FUN_0010b7b0(param_1,uVar3 >> 0x1f,*param_2 + lVar9 * 0x48,local_98);
      if (iVar4 != 0) {
        if ((void *)local_98._0_8_ != (void *)0x0) {
          operator_delete((void *)local_98._0_8_);
        }
        goto LAB_0010bf23;
      }
      local_f8 = (void *)param_5[1];
      __dest_00 = (void *)*param_5;
      local_f0 = (long)local_f8 - (long)__dest_00;
      uVar5 = local_98._8_8_ + (local_f0 - local_98._0_8_);
      if ((long)uVar5 < 0) {
                    /* WARNING: Subroutine does not return */
        std::__throw_length_error("vector::reserve");
      }
      lVar9 = param_5[2];
      pvVar10 = (void *)local_98._0_8_;
      if ((ulong)(lVar9 - (long)__dest_00) < uVar5) {
        __dest_00 = operator_new(uVar5);
        pvVar10 = (void *)*param_5;
        if (param_5[1] - (long)pvVar10 < 1) {
          if (pvVar10 != (void *)0x0) goto LAB_0010be6e;
        }
        else {
          __dest_00 = memmove(__dest_00,pvVar10,param_5[1] - (long)pvVar10);
LAB_0010be6e:
          operator_delete(pvVar10);
        }
        local_f8 = (void *)(local_f0 + (long)__dest_00);
        lVar9 = (long)__dest_00 + uVar5;
        param_5[2] = lVar9;
        *param_5 = (long)__dest_00;
        param_5[1] = (long)local_f8;
        pvVar10 = (void *)local_98._0_8_;
      }
      pvVar8 = (void *)local_98._8_8_;
      if (pvVar10 != (void *)local_98._8_8_) {
        uVar5 = local_98._8_8_ - (long)pvVar10;
        if ((ulong)(lVar9 - (long)local_f8) < uVar5) {
          if (0x7fffffffffffffff - local_f0 < uVar5) {
                    /* WARNING: Subroutine does not return */
            std::__throw_length_error("vector::_M_range_insert");
          }
          uVar7 = local_f0;
          if (local_f0 < uVar5) {
            uVar7 = uVar5;
          }
          uVar6 = uVar7 + local_f0;
          if (CARRY8(uVar7,local_f0)) {
            local_d8 = (void *)0x7fffffffffffffff;
LAB_0010bf79:
            pvVar8 = operator_new((ulong)local_d8);
            __dest_00 = (void *)*param_5;
            local_f0 = (long)local_f8 - (long)__dest_00;
            local_d0 = (long)local_d8 + (long)pvVar8;
          }
          else {
            local_d0 = 0;
            pvVar8 = (void *)0x0;
            if (uVar6 != 0) {
              local_d8 = (void *)0x7fffffffffffffff;
              if (uVar6 < 0x8000000000000000) {
                local_d8 = (void *)uVar6;
              }
              goto LAB_0010bf79;
            }
          }
          __dest = (void *)((long)pvVar8 + local_f0);
          local_d8 = (void *)((long)__dest + uVar5);
          if (local_f0 == 0) {
            memcpy(__dest,pvVar10,uVar5);
            __n = param_5[1] - (long)local_f8;
            sVar11 = 0;
            if (__n != 0) {
LAB_0010bee0:
              memcpy(local_d8,local_f8,__n);
              sVar11 = __n;
            }
            local_d8 = (void *)((long)local_d8 + sVar11);
            if (__dest_00 != (void *)0x0) goto LAB_0010bec9;
          }
          else {
            memmove(pvVar8,__dest_00,local_f0);
            memcpy(__dest,pvVar10,uVar5);
            __n = param_5[1] - (long)local_f8;
            if (__n != 0) goto LAB_0010bee0;
LAB_0010bec9:
            operator_delete(__dest_00);
          }
          param_5[2] = local_d0;
          *param_5 = (long)pvVar8;
          param_5[1] = (long)local_d8;
          pvVar8 = (void *)local_98._0_8_;
        }
        else {
          memmove(local_f8,pvVar10,uVar5);
          param_5[1] = param_5[1] + uVar5;
          pvVar8 = (void *)local_98._0_8_;
        }
      }
      if (pvVar8 != (void *)0x0) {
        operator_delete(pvVar8);
      }
    } while (-1 < (int)uVar3);
    local_c8 = local_c8 + 1;
  } while( true );
}


//===== FUN_0010c010 @ 0010c010 size=612 =====

int FUN_0010c010(undefined8 param_1,undefined8 param_2,long *param_3)

{
  undefined8 *puVar1;
  int iVar2;
  long lVar3;
  void *__ptr;
  ulong uVar4;
  long lVar5;
  long in_FS_OFFSET;
  undefined1 local_d0 [8];
  undefined1 local_c8 [16];
  undefined8 local_b8;
  long local_a8 [3];
  long local_90;
  long local_78;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_0010e6f0(local_d0);
  FUN_0010f460(local_a8);
  lVar3 = *param_3;
  uVar4 = 0;
  if (lVar3 != param_3[1]) {
    do {
      puVar1 = (undefined8 *)(lVar3 + uVar4 * 0x48);
      FUN_0010ffd0(local_a8,*puVar1,(long)*(int *)(puVar1 + 1) * 2);
      lVar3 = *param_3;
      uVar4 = uVar4 + 1;
    } while (uVar4 < (ulong)((param_3[1] - lVar3 >> 3) * -0x71c71c71c71c71c7));
  }
  FUN_0010ecd0(local_d0,local_a8,0);
  lVar3 = FUN_0010ea90(local_d0);
  __ptr = malloc(lVar3 * 4);
  local_b8 = 0;
  local_c8 = (undefined1  [16])0x0;
  iVar2 = FUN_0010bb70(param_1,param_3,local_d0,__ptr,local_c8);
  if (iVar2 == 0) {
    iVar2 = FUN_0010ad00(param_1,param_2,local_d0,__ptr,local_c8);
  }
  if (__ptr != (void *)0x0) {
    free(__ptr);
  }
  if ((void *)local_c8._0_8_ != (void *)0x0) {
    operator_delete((void *)local_c8._0_8_);
  }
  if (local_78 != 0) {
    lVar3 = local_78 + *(long *)(local_78 + -8) * 8;
    lVar5 = local_78;
    if (local_78 != lVar3) {
      do {
        while( true ) {
          puVar1 = (undefined8 *)(lVar3 + -8);
          lVar3 = lVar3 + -8;
          if ((void *)*puVar1 == (void *)0x0) break;
          operator_delete__((void *)*puVar1);
          lVar5 = local_78;
          if (lVar3 == local_78) goto LAB_0010c16b;
        }
      } while (lVar3 != lVar5);
    }
LAB_0010c16b:
    operator_delete__((void *)(lVar5 + -8));
  }
  if (local_90 != 0) {
    lVar3 = local_90 + *(long *)(local_90 + -8) * 8;
    lVar5 = local_90;
    if (local_90 != lVar3) {
      do {
        while( true ) {
          puVar1 = (undefined8 *)(lVar3 + -8);
          lVar3 = lVar3 + -8;
          if ((void *)*puVar1 == (void *)0x0) break;
          operator_delete__((void *)*puVar1);
          lVar5 = local_90;
          if (lVar3 == local_90) goto LAB_0010c1b3;
        }
      } while (lVar3 != lVar5);
    }
LAB_0010c1b3:
    operator_delete__((void *)(lVar5 + -8));
  }
  if (local_a8[0] != 0) {
    lVar3 = local_a8[0] + *(long *)(local_a8[0] + -8) * 8;
    lVar5 = local_a8[0];
    if (local_a8[0] != lVar3) {
      do {
        while( true ) {
          puVar1 = (undefined8 *)(lVar3 + -8);
          lVar3 = lVar3 + -8;
          if ((void *)*puVar1 == (void *)0x0) break;
          operator_delete__((void *)*puVar1);
          lVar5 = local_a8[0];
          if (lVar3 == local_a8[0]) goto LAB_0010c1f7;
        }
      } while (lVar3 != lVar5);
    }
LAB_0010c1f7:
    operator_delete__((void *)(lVar5 + -8));
  }
  FUN_0010e700(local_d0);
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}


//===== FUN_0010c2d0 @ 0010c2d0 size=46 =====

void FUN_0010c2d0(undefined8 *param_1)

{
  if ((undefined8 *)param_1[4] != param_1 + 6) {
    operator_delete((undefined8 *)param_1[4]);
  }
  if ((undefined8 *)*param_1 != param_1 + 2) {
    operator_delete((undefined8 *)*param_1);
    return;
  }
  return;
}


//===== FUN_0010c310 @ 0010c310 size=239 =====

void FUN_0010c310(long *param_1)

{
  undefined8 *puVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = param_1[6];
  if (lVar2 != 0) {
    lVar3 = lVar2 + *(long *)(lVar2 + -8) * 8;
    while (lVar2 != lVar3) {
      while( true ) {
        puVar1 = (undefined8 *)(lVar3 + -8);
        lVar3 = lVar3 + -8;
        if ((void *)*puVar1 == (void *)0x0) break;
        operator_delete__((void *)*puVar1);
        lVar2 = param_1[6];
        if (lVar2 == lVar3) goto LAB_0010c34e;
      }
    }
LAB_0010c34e:
    operator_delete__((void *)(lVar3 + -8));
  }
  lVar2 = param_1[3];
  if (lVar2 != 0) {
    lVar3 = lVar2 + *(long *)(lVar2 + -8) * 8;
    if (lVar2 != lVar3) {
      do {
        while( true ) {
          puVar1 = (undefined8 *)(lVar3 + -8);
          lVar3 = lVar3 + -8;
          if ((void *)*puVar1 == (void *)0x0) break;
          operator_delete__((void *)*puVar1);
          lVar2 = param_1[3];
          if (lVar3 == lVar2) goto LAB_0010c38e;
        }
      } while (lVar3 != lVar2);
    }
LAB_0010c38e:
    operator_delete__((void *)(lVar2 + -8));
  }
  lVar2 = *param_1;
  if (lVar2 == 0) {
    return;
  }
  lVar3 = lVar2 + *(long *)(lVar2 + -8) * 8;
  if (lVar2 != lVar3) {
    do {
      while( true ) {
        puVar1 = (undefined8 *)(lVar3 + -8);
        lVar3 = lVar3 + -8;
        if ((void *)*puVar1 != (void *)0x0) break;
        if (lVar3 == lVar2) {
          operator_delete__((void *)(lVar2 + -8));
          return;
        }
      }
      operator_delete__((void *)*puVar1);
      lVar2 = *param_1;
    } while (lVar3 != lVar2);
  }
  operator_delete__((void *)(lVar2 + -8));
  return;
}


//===== FUN_0010c410 @ 0010c410 size=746 =====

void FUN_0010c410(undefined8 *param_1,undefined8 *param_2,long *param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  long lVar3;
  undefined8 uVar4;
  ulong uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  ulong uVar8;
  ulong uVar9;
  undefined8 *puVar10;
  long *plVar11;
  undefined8 *puVar12;
  undefined8 *local_58;
  ulong local_50;
  
  puVar1 = (undefined8 *)param_1[1];
  puVar2 = (undefined8 *)*param_1;
  uVar5 = ((long)puVar1 - (long)puVar2 >> 3) * -0x71c71c71c71c71c7;
  if (uVar5 == 0x1c71c71c71c71c7) {
                    /* WARNING: Subroutine does not return */
    std::__throw_length_error("vector::_M_realloc_insert");
  }
  uVar8 = 1;
  if (uVar5 != 0) {
    uVar8 = uVar5;
  }
  uVar9 = uVar8 + uVar5;
  if (CARRY8(uVar8,uVar5)) {
    local_50 = 0x7ffffffffffffff8;
  }
  else {
    if (uVar9 == 0) {
      local_58 = (undefined8 *)0x0;
      local_50 = 0;
      goto LAB_0010c497;
    }
    local_50 = 0x1c71c71c71c71c7;
    if (uVar9 < 0x1c71c71c71c71c8) {
      local_50 = uVar9;
    }
    local_50 = local_50 * 0x48;
  }
  local_58 = operator_new(local_50);
LAB_0010c497:
  plVar11 = (long *)(((long)param_2 - (long)puVar2) + (long)local_58);
  lVar3 = *param_3;
  *plVar11 = (long)(plVar11 + 2);
  FUN_0010ab40(plVar11,lVar3,lVar3 + param_3[1] * 2);
  lVar3 = param_3[4];
  plVar11[4] = (long)(plVar11 + 6);
  FUN_0010ab40(plVar11 + 4,lVar3,lVar3 + param_3[5] * 2);
  *(int *)(plVar11 + 8) = (int)param_3[8];
  puVar10 = puVar2 + 2;
  puVar12 = local_58;
  puVar6 = puVar2;
  while (param_2 != puVar6) {
    *puVar12 = puVar12 + 2;
    if (puVar10 == (undefined8 *)puVar10[-2]) {
      uVar4 = puVar10[1];
      puVar12[2] = *puVar10;
      puVar12[3] = uVar4;
    }
    else {
      *puVar12 = (undefined8 *)puVar10[-2];
      puVar12[2] = *puVar10;
    }
    uVar4 = puVar10[-1];
    puVar10[-2] = puVar10;
    puVar10[-1] = 0;
    puVar12[1] = uVar4;
    *(undefined2 *)puVar10 = 0;
    puVar12[4] = puVar12 + 6;
    if ((undefined8 *)puVar10[2] == puVar10 + 4) {
      uVar4 = puVar10[5];
      puVar12[6] = puVar10[4];
      puVar12[7] = uVar4;
    }
    else {
      puVar12[4] = (undefined8 *)puVar10[2];
      puVar12[6] = puVar10[4];
    }
    puVar6 = (undefined8 *)puVar10[-2];
    puVar12[5] = puVar10[3];
    *(undefined4 *)(puVar12 + 8) = *(undefined4 *)(puVar10 + 6);
    if (puVar10 != puVar6) {
      operator_delete(puVar6);
    }
    puVar12 = puVar12 + 9;
    puVar6 = puVar10 + 7;
    puVar10 = puVar10 + 9;
  }
  puVar10 = puVar12 + 9;
  if (param_2 != puVar1) {
    puVar6 = param_2 + 2;
    puVar7 = param_2;
    do {
      *puVar10 = puVar10 + 2;
      if (puVar6 == (undefined8 *)puVar6[-2]) {
        uVar4 = puVar6[1];
        puVar10[2] = *puVar6;
        puVar10[3] = uVar4;
      }
      else {
        *puVar10 = (undefined8 *)puVar6[-2];
        puVar10[2] = *puVar6;
      }
      uVar4 = puVar6[-1];
      puVar6[-2] = puVar6;
      puVar6[-1] = 0;
      puVar10[1] = uVar4;
      *(undefined2 *)puVar6 = 0;
      puVar10[4] = puVar10 + 6;
      if ((undefined8 *)puVar6[2] == puVar7 + 6) {
        uVar4 = puVar6[5];
        puVar10[6] = puVar6[4];
        puVar10[7] = uVar4;
      }
      else {
        puVar10[4] = (undefined8 *)puVar6[2];
        puVar10[6] = puVar6[4];
      }
      puVar7 = puVar7 + 9;
      puVar10[5] = puVar6[3];
      *(undefined4 *)(puVar10 + 8) = *(undefined4 *)(puVar6 + 6);
      puVar6 = puVar6 + 9;
      puVar10 = puVar10 + 9;
    } while (puVar7 != puVar1);
    puVar10 = (undefined8 *)
              ((long)puVar12 + ((long)puVar1 + (-0x48 - (long)param_2) & 0xfffffffffffffff8U) + 0x90
              );
  }
  if (puVar2 != (undefined8 *)0x0) {
    operator_delete(puVar2);
  }
  *param_1 = local_58;
  param_1[1] = puVar10;
  param_1[2] = (long)local_58 + local_50;
  return;
}


//===== FUN_0010c780 @ 0010c780 size=260 =====

void FUN_0010c780(undefined8 *param_1,undefined1 *param_2)

{
  undefined1 *puVar1;
  void *__src;
  ulong __n;
  ulong uVar2;
  void *__dest;
  long lVar3;
  ulong uVar4;
  
  puVar1 = (undefined1 *)param_1[1];
  if (puVar1 != (undefined1 *)param_1[2]) {
    *puVar1 = *param_2;
    param_1[1] = param_1[1] + 1;
    return;
  }
  __src = (void *)*param_1;
  __n = (long)puVar1 - (long)__src;
  if (__n == 0x7fffffffffffffff) {
                    /* WARNING: Subroutine does not return */
    std::__throw_length_error("vector::_M_realloc_insert");
  }
  uVar4 = 1;
  if (__n != 0) {
    uVar4 = __n;
  }
  uVar2 = uVar4 + __n;
  if (CARRY8(uVar4,__n)) {
    uVar4 = 0x7fffffffffffffff;
LAB_0010c861:
    __dest = operator_new(uVar4);
    lVar3 = uVar4 + (long)__dest;
  }
  else {
    lVar3 = 0;
    __dest = (void *)0x0;
    if (uVar2 != 0) {
      uVar4 = 0x7fffffffffffffff;
      if (uVar2 < 0x8000000000000000) {
        uVar4 = uVar2;
      }
      goto LAB_0010c861;
    }
  }
  *(undefined1 *)((long)__dest + __n) = *param_2;
  if ((long)__n < 1) {
    if (__src == (void *)0x0) goto LAB_0010c80e;
  }
  else {
    memmove(__dest,__src,__n);
  }
  operator_delete(__src);
LAB_0010c80e:
  param_1[2] = lVar3;
  *param_1 = __dest;
  param_1[1] = (long)__dest + __n + 1;
  return;
}


//===== FUN_0010c890 @ 0010c890 size=5 =====

void FUN_0010c890(void)

{
  return;
}


//===== FUN_0010c8a0 @ 0010c8a0 size=5 =====

void FUN_0010c8a0(void)

{
  return;
}


//===== FUN_0010c8b0 @ 0010c8b0 size=201 =====

undefined1 FUN_0010c8b0(short *param_1,int *param_2)

{
  short sVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined *puVar5;
  int iVar6;
  undefined **ppuVar7;
  
  if (param_1 == (short *)0x0) {
    return 0;
  }
  if (*param_1 == 0) {
    return 0;
  }
  ppuVar7 = &PTR_DAT_00132d70;
  iVar6 = 0x129;
  puVar5 = PTR_DAT_00132d70;
  while( true ) {
    lVar3 = 0;
    do {
      lVar3 = lVar3 + 1;
    } while (*(short *)(puVar5 + lVar3 * 2) != 0);
    iVar2 = (int)lVar3;
    lVar3 = (long)iVar2;
    if (lVar3 == 0) break;
    lVar4 = 0;
    while( true ) {
      sVar1 = *(short *)((long)param_1 + lVar4);
      if ((sVar1 != *(short *)(puVar5 + lVar4)) || (sVar1 == 0)) break;
      lVar4 = lVar4 + 2;
      lVar3 = lVar3 + -1;
      if (lVar3 == 0) goto LAB_0010c92f;
    }
    if (sVar1 == *(short *)(puVar5 + lVar4)) goto LAB_0010c92f;
    iVar6 = iVar6 + -1;
    ppuVar7 = ppuVar7 + -2;
    if (iVar6 == -1) {
      return 0;
    }
    puVar5 = *ppuVar7;
    if (*(short *)*ppuVar7 == 0) break;
  }
  iVar2 = 0;
LAB_0010c92f:
  *param_2 = iVar2;
  return (&DAT_00131ae8)[(long)iVar6 * 0x10];
}


//===== FUN_0010c990 @ 0010c990 size=493 =====

undefined8 FUN_0010c990(short *param_1,byte *param_2,byte *param_3,long *param_4)

{
  byte bVar1;
  short sVar2;
  char *pcVar3;
  void *__src;
  char cVar4;
  undefined8 uVar5;
  ulong __n;
  ulong uVar6;
  void *__dest;
  long lVar7;
  ulong uVar8;
  long in_FS_OFFSET;
  int local_44;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (*param_4 != param_4[1]) {
    param_4[1] = *param_4;
  }
  *param_3 = 0;
  *param_2 = 0;
  sVar2 = *param_1;
  do {
    if (sVar2 == 0) {
      uVar5 = 0;
LAB_0010cb12:
      if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
        return uVar5;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    cVar4 = FUN_0010c8b0(param_1,&local_44);
    if (cVar4 == '\0') {
      uVar5 = 0x136;
      goto LAB_0010cb12;
    }
    if (cVar4 == '\x01') {
      *param_3 = *param_2;
    }
    else {
      pcVar3 = (char *)param_4[1];
      if (pcVar3 == (char *)param_4[2]) {
        __src = (void *)*param_4;
        __n = (long)pcVar3 - (long)__src;
        if (__n == 0x7fffffffffffffff) {
                    /* WARNING: Subroutine does not return */
          std::__throw_length_error("vector::_M_realloc_insert");
        }
        uVar8 = 1;
        if (__n != 0) {
          uVar8 = __n;
        }
        uVar6 = uVar8 + __n;
        if (CARRY8(uVar8,__n)) {
          uVar8 = 0x7fffffffffffffff;
LAB_0010cb51:
          __dest = operator_new(uVar8);
          lVar7 = uVar8 + (long)__dest;
        }
        else {
          lVar7 = 0;
          __dest = (void *)0x0;
          if (uVar6 != 0) {
            uVar8 = 0x7fffffffffffffff;
            if (uVar6 < 0x8000000000000000) {
              uVar8 = uVar6;
            }
            goto LAB_0010cb51;
          }
        }
        *(char *)((long)__dest + __n) = cVar4;
        if ((long)__n < 1) {
          if (__src != (void *)0x0) goto LAB_0010cae7;
        }
        else {
          memmove(__dest,__src,__n);
LAB_0010cae7:
          operator_delete(__src);
        }
        param_4[2] = lVar7;
        *param_4 = (long)__dest;
        param_4[1] = (long)__dest + __n + 1;
      }
      else {
        *pcVar3 = cVar4;
        param_4[1] = param_4[1] + 1;
      }
      bVar1 = *param_2;
      *param_2 = bVar1 + 1;
      if (0x1f < (byte)(bVar1 + 1)) {
        uVar5 = 0x137;
        goto LAB_0010cb12;
      }
    }
    param_1 = param_1 + local_44;
    sVar2 = *param_1;
  } while( true );
}


//===== FUN_0010cba0 @ 0010cba0 size=60 =====

undefined * FUN_0010cba0(char param_1)

{
  long lVar1;
  char *pcVar2;
  
  pcVar2 = "\n";
  lVar1 = 0;
  do {
    if (*pcVar2 == param_1) {
      return (&PTR_DAT_00131ae0)[lVar1 * 2];
    }
    lVar1 = lVar1 + 1;
    pcVar2 = pcVar2 + 0x10;
  } while (lVar1 != 0x12a);
  return &DAT_00127714;
}


//===== FUN_0010cbe0 @ 0010cbe0 size=445 =====

long * FUN_0010cbe0(long *param_1,undefined1 *param_2,int param_3,int param_4)

{
  long *plVar1;
  short *__dest;
  undefined2 *puVar2;
  undefined1 uVar3;
  short *__src;
  long *plVar4;
  ulong uVar5;
  size_t __n;
  int iVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  
  plVar1 = param_1 + 2;
  *param_1 = (long)plVar1;
  param_1[1] = 0;
  *(undefined2 *)(param_1 + 2) = 0;
  if (0 < param_3) {
    iVar6 = 1;
    do {
      uVar3 = *param_2;
      param_2 = param_2 + 1;
      __src = (short *)FUN_0010cba0(uVar3);
      uVar5 = param_1[1];
      if (*__src == 0) {
        __n = 0;
        uVar9 = 0;
        uVar7 = uVar5;
      }
      else {
        uVar9 = 0;
        do {
          uVar9 = uVar9 + 1;
          __n = uVar9 * 2;
        } while (__src[uVar9] != 0);
        if (0x1fffffffffffffff - uVar5 < uVar9) {
                    /* WARNING: Subroutine does not return */
          std::__throw_length_error("basic_string::append");
        }
        uVar7 = uVar9 + uVar5;
      }
      plVar4 = (long *)*param_1;
      if (plVar1 == plVar4) {
        uVar8 = 7;
      }
      else {
        uVar8 = param_1[2];
      }
      if (uVar8 < uVar7) {
        FUN_0010cdd0(param_1,uVar5,0);
        plVar4 = (long *)*param_1;
      }
      else if (uVar9 != 0) {
        __dest = (short *)((long)plVar4 + uVar5 * 2);
        if (uVar9 == 1) {
          *__dest = *__src;
        }
        else {
          memcpy(__dest,__src,__n);
          plVar4 = (long *)*param_1;
        }
      }
      param_1[1] = uVar7;
      puVar2 = (undefined2 *)((long)plVar4 + uVar7 * 2);
      *puVar2 = 0;
      if (param_4 == iVar6) {
        if (uVar7 == 0x1fffffffffffffff) {
                    /* WARNING: Subroutine does not return */
          std::__throw_length_error("basic_string::append");
        }
        if (plVar1 == plVar4) {
          uVar5 = 7;
        }
        else {
          uVar5 = param_1[2];
        }
        if (uVar5 < uVar7 + 1) {
          FUN_0010cdd0(param_1,uVar7,0,&DAT_00127718);
          plVar4 = (long *)*param_1;
        }
        else {
          *puVar2 = 0x27;
        }
        param_1[1] = uVar7 + 1;
        *(undefined2 *)((long)plVar4 + uVar7 * 2 + 2) = 0;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 <= param_3);
  }
  return param_1;
}


//===== FUN_0010cdd0 @ 0010cdd0 size=404 =====

void FUN_0010cdd0(undefined8 *param_1,long param_2,long param_3,undefined2 *param_4,long param_5)

{
  undefined2 *__src;
  undefined8 *puVar1;
  undefined2 *__dest;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  ulong uVar6;
  
  uVar3 = (param_5 - param_3) + param_1[1];
  lVar5 = param_1[1] - (param_2 + param_3);
  if (param_1 + 2 == (undefined8 *)*param_1) {
    uVar2 = 7;
  }
  else {
    uVar2 = param_1[2];
  }
  if (0x1fffffffffffffff < uVar3) {
                    /* WARNING: Subroutine does not return */
    std::__throw_length_error("basic_string::_M_create");
  }
  if ((uVar2 < uVar3) && (uVar2 = uVar2 * 2, uVar3 < uVar2)) {
    uVar6 = 0x4000000000000000;
    uVar3 = uVar2;
    uVar4 = 0x1fffffffffffffff;
    if (uVar2 < 0x2000000000000000) goto LAB_0010ce58;
  }
  else {
LAB_0010ce58:
    uVar6 = uVar3 * 2 + 2;
    uVar4 = uVar3;
  }
  __dest = operator_new(uVar6);
  if (param_2 != 0) {
    if (param_2 == 1) {
      *__dest = *(undefined2 *)*param_1;
    }
    else {
      memcpy(__dest,(undefined2 *)*param_1,param_2 * 2);
    }
  }
  if ((param_4 != (undefined2 *)0x0) && (param_5 != 0)) {
    if (param_5 == 1) {
      puVar1 = (undefined8 *)*param_1;
      __dest[param_2] = *param_4;
      goto joined_r0x0010cec7;
    }
    memcpy(__dest + param_2,param_4,param_5 * 2);
  }
  puVar1 = (undefined8 *)*param_1;
joined_r0x0010cec7:
  if (lVar5 != 0) {
    __src = (undefined2 *)((long)puVar1 + (param_2 + param_3) * 2);
    if (lVar5 == 1) {
      __dest[param_2 + param_5] = *__src;
    }
    else {
      memcpy(__dest + param_2 + param_5,__src,lVar5 * 2);
    }
  }
  if (param_1 + 2 != puVar1) {
    operator_delete(puVar1);
  }
  *param_1 = __dest;
  param_1[2] = uVar4;
  return;
}


//===== FUN_0010cf80 @ 0010cf80 size=12 =====

void FUN_0010cf80(undefined8 *param_1)

{
  *param_1 = 0;
  return;
}


//===== FUN_0010cf90 @ 0010cf90 size=18 =====

void FUN_0010cf90(undefined8 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    operator_delete__((void *)*param_1);
    return;
  }
  return;
}


//===== FUN_0010cfb0 @ 0010cfb0 size=10 =====

undefined8 FUN_0010cfb0(void)

{
  return 0x1c;
}


//===== FUN_0010cfc0 @ 0010cfc0 size=434 =====

undefined4 FUN_0010cfc0(long *param_1,char *param_2)

{
  ushort uVar1;
  int iVar2;
  void *pvVar3;
  FILE *__stream;
  char *__s1;
  size_t sVar4;
  ulong uVar5;
  uint uVar6;
  ulong uVar7;
  long lVar8;
  undefined4 uVar9;
  long in_FS_OFFSET;
  int local_38;
  uint local_34;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if ((void *)*param_1 != (void *)0x0) {
    operator_delete__((void *)*param_1);
  }
  pvVar3 = operator_new__(0x70);
  *param_1 = (long)pvVar3;
  __stream = fopen64(param_2,"rb");
  if (__stream == (FILE *)0x0) {
    uVar9 = 0xc9;
    goto LAB_0010d048;
  }
  fread(&local_38,1,8,__stream);
  if (local_38 == 0x444b4e55) {
    fseek(__stream,(ulong)local_34,1);
    fread(&local_38,1,8,__stream);
    if (local_38 != 0x44534f50) goto LAB_0010d03a;
    uVar5 = (ulong)local_34;
    __s1 = operator_new__(uVar5);
    sVar4 = fread(__s1,1,uVar5,__stream);
    if ((uVar5 <= sVar4) && (iVar2 = strncmp(__s1,"POS1",4), iVar2 == 0)) {
      uVar1 = *(ushort *)(__s1 + 0x18);
      lVar8 = 0;
      uVar6 = 1;
      if (uVar1 < 2) goto LAB_0010d148;
      do {
        uVar5 = 1;
        while (uVar7 = uVar5 & 0xffffffff,
              (uint)(byte)__s1[uVar5 + 0x1a] != *(uint *)((long)&DAT_00127ce0 + lVar8)) {
          uVar6 = (int)uVar5 + 1;
          uVar5 = uVar5 + 1;
          if (uVar1 <= (ushort)uVar5) goto LAB_0010d148;
        }
        while( true ) {
          *(int *)(*param_1 + lVar8) = (int)uVar7;
          lVar8 = lVar8 + 4;
          uVar9 = 0;
          if (lVar8 == 0x70) goto LAB_0010d158;
          uVar6 = 1;
          if (1 < uVar1) break;
LAB_0010d148:
          if ((ushort)uVar6 == uVar1) {
            uVar9 = 0xd4;
            goto LAB_0010d158;
          }
          uVar7 = (ulong)(uVar6 & 0xffff);
        }
      } while( true );
    }
    uVar9 = 0xd3;
LAB_0010d158:
    operator_delete__(__s1);
  }
  else {
LAB_0010d03a:
    uVar9 = 0xd3;
  }
  fclose(__stream);
LAB_0010d048:
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9;
}


//===== FUN_0010d180 @ 0010d180 size=33 =====

long FUN_0010d180(long *param_1,int param_2)

{
  long lVar1;
  
  lVar1 = 0;
  do {
    if (*(int *)(*param_1 + lVar1 * 4) == param_2) {
      return lVar1;
    }
    lVar1 = lVar1 + 1;
  } while (lVar1 != 0x1c);
  return 0xffffffff;
}


//===== FUN_0010d1b0 @ 0010d1b0 size=25 =====

undefined4 FUN_0010d1b0(long *param_1,uint param_2)

{
  if (param_2 < 0x1c) {
    return *(undefined4 *)(*param_1 + (long)(int)param_2 * 4);
  }
  return 0xffffffff;
}


//===== FUN_0010d1d0 @ 0010d1d0 size=5 =====

void FUN_0010d1d0(void)

{
  return;
}


//===== FUN_0010d1e0 @ 0010d1e0 size=5 =====

void FUN_0010d1e0(void)

{
  return;
}


//===== FUN_0010d1f0 @ 0010d1f0 size=12 =====

undefined * FUN_0010d1f0(void)

{
  return &DAT_00127d50;
}


//===== FUN_0010d200 @ 0010d200 size=202 =====

undefined8 FUN_0010d200(long param_1,int *param_2,uint *param_3)

{
  byte bVar1;
  byte bVar2;
  long lVar3;
  byte *pbVar4;
  undefined8 uVar5;
  
  bVar1 = *(byte *)(param_1 + 4);
  uVar5 = 0;
  if ((bVar1 & 3) != 0) {
    lVar3 = param_1 + 7;
    if ((bVar1 & 4) != 0) {
      lVar3 = param_1 + 10;
    }
    pbVar4 = (byte *)(lVar3 + (ulong)(*(byte *)(param_1 + 5) & 0x1f));
    *param_2 = (*pbVar4 >> 5) - 2;
    bVar2 = *pbVar4;
    *param_3 = bVar2 & 0x1f;
    if (*param_2 != 0) {
      *param_3 = (bVar2 & 0x1f) + 0x14;
    }
    uVar5 = 1;
    if ((bVar1 & 3) != 1) {
      param_2[1] = (pbVar4[1] >> 5) - 2;
      bVar2 = pbVar4[1];
      param_3[1] = bVar2 & 0x1f;
      if (param_2[1] != 0) {
        param_3[1] = (bVar2 & 0x1f) + 0x14;
      }
      uVar5 = 2;
      if ((bVar1 & 3) == 3) {
        param_2[2] = (pbVar4[2] >> 5) - 2;
        bVar1 = pbVar4[2];
        param_3[2] = bVar1 & 0x1f;
        if (param_2[2] != 0) {
          param_3[2] = (bVar1 & 0x1f) + 0x14;
        }
        uVar5 = 3;
      }
    }
  }
  return uVar5;
}


//===== FUN_0010d2d0 @ 0010d2d0 size=46 =====

void FUN_0010d2d0(long param_1,ushort *param_2)

{
  byte bVar1;
  
  if ((*(byte *)(param_1 + 4) & 4) != 0) {
    *param_2 = (ushort)*(byte *)(param_1 + 7);
    param_2[1] = (ushort)*(byte *)(param_1 + 8);
    bVar1 = *(byte *)(param_1 + 9);
    param_2[3] = 0;
    param_2[2] = (ushort)bVar1;
    return;
  }
  *param_2 = 0;
  return;
}


//===== FUN_0010d310 @ 0010d310 size=803 =====

long * FUN_0010d310(long *param_1,undefined8 *param_2)

{
  long lVar1;
  short *psVar2;
  ulong uVar3;
  long *__dest;
  long *plVar4;
  undefined2 *puVar5;
  short *__src;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  long in_FS_OFFSET;
  bool bVar9;
  long local_58 [3];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar1 = 0;
  *param_1 = (long)(param_1 + 2);
  param_1[1] = 0;
  *(undefined2 *)(param_1 + 2) = 0;
  do {
    lVar1 = lVar1 + 1;
  } while ((&DAT_00127d58)[lVar1] != 0);
  uVar8 = param_2[1];
  if (uVar8 == 0) {
LAB_0010d3a3:
    if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
      return param_1;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  uVar6 = 0;
  __src = (short *)*param_2;
LAB_0010d378:
  psVar2 = &DAT_00127d58;
  do {
    if (*psVar2 == *__src) goto code_r0x0010d396;
    psVar2 = psVar2 + 1;
  } while (&DAT_00127d58 + lVar1 != psVar2);
  lVar1 = 0;
  do {
    lVar1 = lVar1 + 1;
  } while ((&DAT_00127d58)[lVar1] != 0);
  lVar7 = uVar8 - 1;
  do {
    psVar2 = &DAT_00127d58;
    while (*psVar2 != ((short *)*param_2)[lVar7]) {
      psVar2 = psVar2 + 1;
      if (&DAT_00127d58 + lVar1 == psVar2) goto LAB_0010d410;
    }
    bVar9 = lVar7 != 0;
    lVar7 = lVar7 + -1;
  } while (bVar9);
LAB_0010d410:
  uVar3 = (lVar7 - uVar6) + 1;
  if (uVar8 < uVar6) {
    std::__throw_out_of_range_fmt
              ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::substr",uVar6
               ,uVar8);
    plVar4 = (long *)FUN_00104954();
    return plVar4;
  }
  if (uVar8 - uVar6 <= uVar3) {
    uVar3 = uVar8 - uVar6;
  }
  uVar8 = uVar3 * 2;
  lVar1 = (long)uVar8 >> 1;
  plVar4 = local_58;
  if (uVar8 < 0xf) {
    if (lVar1 == 1) {
LAB_0010d5c1:
      local_58[0] = CONCAT62(local_58[0]._2_6_,*__src);
      puVar5 = (undefined2 *)*param_1;
      *(undefined2 *)((long)local_58 + uVar8) = 0;
      *puVar5 = (undefined2)local_58[0];
    }
    else {
      __dest = local_58;
      if (lVar1 == 0) {
        *(undefined2 *)((long)local_58 + uVar8) = 0;
        puVar5 = (undefined2 *)*param_1;
      }
      else {
LAB_0010d466:
        memcpy(__dest,__src,uVar8);
        plVar4 = (long *)*param_1;
        *(short *)((long)__dest + uVar3 * 2) = 0;
        if (__dest != local_58) goto joined_r0x0010d562;
        memcpy(plVar4,local_58,uVar8);
        puVar5 = (undefined2 *)*param_1;
        uVar8 = lVar1 * 2;
        plVar4 = __dest;
      }
    }
    param_1[1] = lVar1;
    *(undefined2 *)((long)puVar5 + uVar8) = 0;
    lVar7 = local_58[0];
  }
  else {
    if (0x3ffffffffffffffe < uVar8) {
LAB_0010d60f:
                    /* WARNING: Subroutine does not return */
      std::__throw_length_error("basic_string::_M_create");
    }
    if (lVar1 + 1U >> 0x3e != 0) {
      if ((long)(lVar1 + 1U) < 0) {
        std::__throw_bad_array_new_length();
        goto LAB_0010d60f;
      }
      lVar1 = std::__throw_bad_alloc();
      goto LAB_0010d5c1;
    }
    __dest = operator_new(uVar8 + 2);
    local_58[0] = lVar1;
    if (lVar1 == 1) {
      plVar4 = (long *)*param_1;
      *(short *)__dest = *__src;
      *(short *)((long)__dest + uVar3 * 2) = 0;
    }
    else {
      if (lVar1 != 0) goto LAB_0010d466;
      plVar4 = (long *)*param_1;
      *(short *)((long)__dest + uVar3 * 2) = 0;
    }
joined_r0x0010d562:
    if (param_1 + 2 == plVar4) {
      *param_1 = (long)__dest;
      param_1[1] = lVar1;
      param_1[2] = local_58[0];
      goto LAB_0010d3a3;
    }
    lVar7 = param_1[2];
    *param_1 = (long)__dest;
    param_1[1] = lVar1;
    param_1[2] = local_58[0];
    if (plVar4 == (long *)0x0) goto LAB_0010d3a3;
  }
  local_58[0] = lVar7;
  *(short *)plVar4 = 0;
  if (plVar4 != local_58) {
    operator_delete(plVar4);
  }
  goto LAB_0010d3a3;
code_r0x0010d396:
  uVar6 = uVar6 + 1;
  __src = __src + 1;
  if (uVar6 == uVar8) goto LAB_0010d3a3;
  goto LAB_0010d378;
}


//===== FUN_0010d650 @ 0010d650 size=215 =====

void FUN_0010d650(undefined8 *param_1,undefined2 *param_2,long param_3)

{
  undefined2 *__dest;
  ulong uVar1;
  ulong __n;
  long lVar2;
  
  if ((param_2 == (undefined2 *)0x0) && (param_3 != 0)) {
    uVar1 = std::__throw_logic_error("basic_string::_M_construct null not valid");
  }
  else {
    __n = param_3 - (long)param_2;
    lVar2 = (long)__n >> 1;
    if (__n < 0xf) {
      __dest = (undefined2 *)*param_1;
joined_r0x0010d6f5:
      if (lVar2 == 1) {
        *__dest = *param_2;
      }
      else if (lVar2 != 0) {
        memcpy(__dest,param_2,__n);
        __dest = (undefined2 *)*param_1;
      }
      param_1[1] = lVar2;
      *(undefined2 *)((long)__dest + __n) = 0;
      return;
    }
    if (0x3ffffffffffffffe < __n) goto LAB_0010d725;
    uVar1 = lVar2 + 1;
    if (uVar1 >> 0x3e == 0) {
      __dest = operator_new(__n + 2);
      param_1[2] = lVar2;
      *param_1 = __dest;
      goto joined_r0x0010d6f5;
    }
  }
  if (-1 < (long)uVar1) {
    std::__throw_bad_alloc();
  }
  std::__throw_bad_array_new_length();
LAB_0010d725:
                    /* WARNING: Subroutine does not return */
  std::__throw_length_error("basic_string::_M_create");
}


//===== FUN_0010d740 @ 0010d740 size=463 =====

void FUN_0010d740(undefined8 *param_1,long param_2,undefined2 param_3)

{
  ulong uVar1;
  undefined8 *__src;
  size_t __n;
  long lVar2;
  ulong uVar3;
  undefined8 *__dest;
  ulong uVar4;
  undefined2 *puVar5;
  
  lVar2 = param_1[1];
  if (lVar2 == 0x1fffffffffffffff) {
                    /* WARNING: Subroutine does not return */
    std::__throw_length_error("basic_string::_M_replace_aux");
  }
  __dest = (undefined8 *)*param_1;
  uVar1 = lVar2 + 1;
  lVar2 = lVar2 - param_2;
  if (__dest == param_1 + 2) {
    uVar3 = 7;
    if (7 < uVar1) goto LAB_0010d7f0;
  }
  else {
    uVar3 = param_1[2];
    if (uVar3 < uVar1) {
LAB_0010d7f0:
      if (uVar1 >> 0x3d != 0) {
                    /* WARNING: Subroutine does not return */
        std::__throw_length_error("basic_string::_M_create");
      }
      uVar3 = uVar3 * 2;
      uVar4 = 0x1fffffffffffffff;
      if (uVar3 < 0x2000000000000000) {
        uVar4 = uVar3;
      }
      if (uVar3 <= uVar1) {
        uVar4 = uVar1;
      }
      __dest = operator_new(uVar4 * 2 + 2);
      __src = (undefined8 *)*param_1;
      __n = param_2 * 2;
      if (param_2 != 0) {
        if (param_2 == 1) {
          *(undefined2 *)__dest = *(undefined2 *)__src;
        }
        else {
          memcpy(__dest,__src,__n);
        }
      }
      if (lVar2 != 0) {
        puVar5 = (undefined2 *)((long)__dest + __n + 2);
        if (lVar2 == 1) {
          *puVar5 = *(undefined2 *)((long)__src + __n);
        }
        else {
          memcpy(puVar5,(undefined2 *)((long)__src + __n),lVar2 * 2);
        }
      }
      if (param_1 + 2 != __src) {
        operator_delete(__src);
      }
      *param_1 = __dest;
      puVar5 = (undefined2 *)((long)__dest + __n);
      param_1[2] = uVar4;
      goto LAB_0010d7b9;
    }
  }
  puVar5 = (undefined2 *)((long)__dest + param_2 * 2);
  if (lVar2 != 0) {
    if (lVar2 == 1) {
      puVar5[1] = *puVar5;
    }
    else {
      memmove(puVar5 + 1,puVar5,lVar2 * 2);
      __dest = (undefined8 *)*param_1;
      puVar5 = (undefined2 *)((long)__dest + param_2 * 2);
    }
  }
LAB_0010d7b9:
  *puVar5 = param_3;
  param_1[1] = uVar1;
  *(undefined2 *)((long)__dest + uVar1 * 2) = 0;
  return;
}


//===== FUN_0010d930 @ 0010d930 size=324 =====

long * FUN_0010d930(long *param_1,byte *param_2)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  *param_1 = (long)(param_1 + 2);
  param_1[1] = 0;
  *(undefined2 *)(param_1 + 2) = 0;
  if ((param_2 != (byte *)0x0) && (uVar3 = (uint)*param_2, *param_2 != 0)) {
    uVar4 = 0;
    do {
      while( true ) {
        pbVar1 = param_2 + 1;
        param_2 = param_2 + 1;
        bVar2 = (byte)uVar3;
        uVar5 = uVar3;
        if ((char)bVar2 < '\0') break;
joined_r0x0010d982:
        if (((int)(char)*pbVar1 & 0xc0U) != 0x80) {
LAB_0010da40:
          FUN_0010d740(param_1,param_1[1],uVar5);
        }
LAB_0010d988:
        uVar3 = (uint)*param_2;
        uVar4 = uVar5;
        if (*param_2 == 0) {
          return param_1;
        }
      }
      if (0xbf < bVar2) {
        if (bVar2 < 0xe0) {
          uVar5 = uVar3 & 0x1f;
        }
        else {
          uVar5 = uVar3 & 7;
          if (bVar2 < 0xf0) {
            uVar5 = uVar3 & 0xf;
          }
        }
        goto joined_r0x0010d982;
      }
      uVar5 = uVar4 << 6 | uVar3 & 0x3f;
      if ((0x10ffff < uVar5) || (((int)(char)*pbVar1 & 0xc0U) == 0x80)) goto LAB_0010d988;
      if (uVar5 < 0x10000) {
        if (uVar5 - 0xd800 < 0x800) goto LAB_0010d988;
        goto LAB_0010da40;
      }
      FUN_0010d740(param_1,param_1[1],(short)((uVar4 & 0x3ffffff) >> 4) + -0x2800);
      FUN_0010d740(param_1,param_1[1],((ushort)uVar5 & 0x3ff) + 0xdc00);
      uVar3 = (uint)*param_2;
      uVar4 = uVar5;
    } while (*param_2 != 0);
  }
  return param_1;
}


//===== FUN_0010daa0 @ 0010daa0 size=358 =====

long * FUN_0010daa0(long *param_1,ushort *param_2)

{
  ushort *puVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  ulong uVar5;
  
  *(undefined1 *)(param_1 + 2) = 0;
  uVar2 = *param_2;
  uVar3 = (uint)uVar2;
  *param_1 = (long)(param_1 + 2);
  param_1[1] = 0;
  if (uVar2 != 0) {
    uVar4 = 0;
    do {
      while ((ushort)((short)uVar3 + 0x2800U) < 0x400) {
        param_2 = param_2 + 1;
        uVar4 = uVar3 * 0x400 + 0xfca10000;
        uVar3 = (uint)*param_2;
        if (*param_2 == 0) {
          return param_1;
        }
      }
      uVar5 = param_1[1];
      uVar4 = uVar3 - 0xdc00 | uVar4;
      if (0x3ff < (ushort)((short)uVar3 + 0x2400U)) {
        uVar4 = uVar3;
      }
      if (0x7f < uVar4) {
        if (0x7ff < uVar4) {
          if (0xffff < uVar4) {
            std::__cxx11::string::_M_replace_aux((ulong)param_1,uVar5,0,'\x01');
            uVar5 = param_1[1];
          }
          std::__cxx11::string::_M_replace_aux((ulong)param_1,uVar5,0,'\x01');
          uVar5 = param_1[1];
        }
        std::__cxx11::string::_M_replace_aux((ulong)param_1,uVar5,0,'\x01');
        uVar5 = param_1[1];
      }
      std::__cxx11::string::_M_replace_aux((ulong)param_1,uVar5,0,'\x01');
      puVar1 = param_2 + 1;
      uVar3 = (uint)*puVar1;
      param_2 = param_2 + 1;
      uVar4 = 0;
    } while (*puVar1 != 0);
  }
  return param_1;
}


//===== FUN_0010dc30 @ 0010dc30 size=374 =====

undefined8 FUN_0010dc30(char *param_1,long *param_2)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  FILE *__stream;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  long in_FS_OFFSET;
  undefined1 *local_88 [2];
  undefined1 local_78 [16];
  undefined1 *local_68 [2];
  undefined1 local_58 [24];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  __stream = fopen64(param_1,"w");
  if (__stream == (FILE *)0x0) {
    uVar4 = 500;
  }
  else {
    lVar5 = *param_2;
    if (param_2[1] != lVar5) {
      uVar6 = 0;
      do {
        while( true ) {
          lVar5 = lVar5 + uVar6 * 0x48;
          uVar1 = *(undefined4 *)(lVar5 + 0x40);
          FUN_0010daa0(local_68,*(undefined8 *)(lVar5 + 0x20));
          puVar2 = local_68[0];
          FUN_0010daa0(local_88,*(undefined8 *)(*param_2 + uVar6 * 0x48));
          __fprintf_chk(__stream,1,"%s,%s,%d\n",local_88[0],puVar2,uVar1);
          if (local_88[0] != local_78) {
            operator_delete(local_88[0]);
          }
          if (local_68[0] == local_58) break;
          operator_delete(local_68[0]);
          lVar5 = *param_2;
          uVar6 = uVar6 + 1;
          uVar3 = (param_2[1] - lVar5 >> 3) * -0x71c71c71c71c71c7;
          if (uVar3 < uVar6 || uVar3 - uVar6 == 0) goto LAB_0010dd45;
        }
        lVar5 = *param_2;
        uVar6 = uVar6 + 1;
      } while (uVar6 < (ulong)((param_2[1] - lVar5 >> 3) * -0x71c71c71c71c71c7));
    }
LAB_0010dd45:
    fclose(__stream);
    uVar4 = 0;
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}


//===== FUN_0010ddc0 @ 0010ddc0 size=1387 =====

undefined8 FUN_0010ddc0(char *param_1,long *param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  long *plVar3;
  ulong uVar4;
  FILE *__stream;
  char *pcVar5;
  char *pcVar6;
  long lVar7;
  ulong *puVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  long in_FS_OFFSET;
  bool bVar11;
  ulong *local_4d8;
  long local_4d0;
  ulong local_4c8 [2];
  undefined1 *local_4b8 [2];
  undefined1 local_4a8 [16];
  ulong *local_498;
  long local_490;
  ulong auStack_488 [2];
  ulong *local_478;
  long local_470;
  ulong auStack_468 [2];
  undefined4 local_458;
  char local_448 [1032];
  long local_40;
  
  puVar1 = (undefined8 *)*param_2;
  puVar2 = (undefined8 *)param_2[1];
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  puVar9 = puVar1;
  if (puVar1 != puVar2) {
    do {
      while( true ) {
        if ((undefined8 *)puVar9[4] != puVar9 + 6) {
          operator_delete((undefined8 *)puVar9[4]);
        }
        if ((undefined8 *)*puVar9 == puVar9 + 2) break;
        operator_delete((undefined8 *)*puVar9);
        puVar9 = puVar9 + 9;
        if (puVar2 == puVar9) goto LAB_0010de30;
      }
      puVar9 = puVar9 + 9;
    } while (puVar2 != puVar9);
LAB_0010de30:
    param_2[1] = (long)puVar1;
  }
  __stream = fopen64(param_1,"r");
  if (__stream == (FILE *)0x0) {
    uVar10 = 0x1f5;
  }
  else {
    while (pcVar5 = fgets(local_448,0x3ff,__stream), pcVar5 != (char *)0x0) {
      local_490 = 0;
      auStack_488[0] = auStack_488[0] & 0xffffffffffff0000;
      local_470 = 0;
      auStack_468[0] = auStack_468[0] & 0xffffffffffff0000;
      local_498 = auStack_488;
      local_478 = auStack_468;
      pcVar5 = strchr(local_448,0x2c);
      if (pcVar5 == (char *)0x0) {
        uVar10 = 300;
        goto LAB_0010e18e;
      }
      *pcVar5 = '\0';
      if (local_448[0] == '\0') {
        uVar10 = 0x12d;
        goto LAB_0010e18e;
      }
      FUN_0010d930(local_4b8,local_448);
      FUN_0010d310();
      uVar4 = auStack_488[0];
      puVar8 = local_498;
      if (local_4d8 == local_4c8) {
        puVar8 = local_4c8;
        if (local_4d0 != 0) {
          if (local_4d0 == 1) {
            *(undefined2 *)local_498 = (undefined2)local_4c8[0];
          }
          else {
            memcpy(local_498,local_4c8,local_4d0 * 2);
            puVar8 = local_4d8;
          }
        }
        *(undefined2 *)((long)local_498 + local_4d0 * 2) = 0;
        local_490 = local_4d0;
LAB_0010dfa3:
        local_4d0 = 0;
        *(undefined2 *)puVar8 = 0;
        if (puVar8 != local_4c8) {
          operator_delete(puVar8);
        }
      }
      else {
        auStack_488[0] = local_4c8[0];
        bVar11 = local_498 != auStack_488;
        local_498 = local_4d8;
        local_490 = local_4d0;
        if (bVar11) {
          local_498 = local_4d8;
          local_490 = local_4d0;
          if (puVar8 != (ulong *)0x0) {
            local_4d8 = puVar8;
            local_4c8[0] = uVar4;
            goto LAB_0010dfa3;
          }
        }
      }
      if (local_4b8[0] != local_4a8) {
        operator_delete(local_4b8[0]);
      }
      pcVar6 = strchr(pcVar5 + 1,0x2c);
      if (pcVar6 == (char *)0x0) {
        uVar10 = 0x12e;
LAB_0010e206:
        if (local_478 != auStack_468) {
          operator_delete(local_478);
        }
        if (local_498 != auStack_488) {
          operator_delete(local_498);
        }
        goto LAB_0010e18e;
      }
      *pcVar6 = '\0';
      if (pcVar5[1] == '\0') {
        uVar10 = 0x12f;
        goto LAB_0010e206;
      }
      FUN_0010d930(local_4b8,pcVar5 + 1);
      FUN_0010d310(&local_4d8);
      uVar4 = auStack_468[0];
      puVar8 = local_478;
      if (local_4d8 == local_4c8) {
        puVar8 = local_4c8;
        if (local_4d0 != 0) {
          if (local_4d0 == 1) {
            *(undefined2 *)local_478 = (undefined2)local_4c8[0];
          }
          else {
            memcpy(local_478,local_4c8,local_4d0 * 2);
            puVar8 = local_4d8;
          }
        }
        *(undefined2 *)((long)local_478 + local_4d0 * 2) = 0;
        local_470 = local_4d0;
LAB_0010e091:
        local_4d0 = 0;
        *(undefined2 *)puVar8 = 0;
        if (puVar8 != local_4c8) {
          operator_delete(puVar8);
        }
      }
      else {
        auStack_468[0] = local_4c8[0];
        bVar11 = local_478 != auStack_468;
        local_478 = local_4d8;
        local_470 = local_4d0;
        if (bVar11) {
          local_478 = local_4d8;
          local_470 = local_4d0;
          if (puVar8 != (ulong *)0x0) {
            local_4d8 = puVar8;
            local_4c8[0] = uVar4;
            goto LAB_0010e091;
          }
        }
      }
      if (local_4b8[0] != local_4a8) {
        operator_delete(local_4b8[0]);
      }
      if (pcVar6[1] == '\0') {
        uVar10 = 0x131;
        goto LAB_0010e206;
      }
      lVar7 = strtol(pcVar6 + 1,(char **)0x0,10);
      plVar3 = (long *)param_2[1];
      local_458 = (undefined4)lVar7;
      if (plVar3 == (long *)param_2[2]) {
        FUN_0010c410(param_2,plVar3,&local_498);
      }
      else {
        *plVar3 = (long)(plVar3 + 2);
        FUN_0010d650(plVar3,local_498,(undefined2 *)((long)local_498 + local_490 * 2));
        plVar3[4] = (long)(plVar3 + 6);
        FUN_0010d650(plVar3 + 4,local_478,(undefined2 *)((long)local_478 + local_470 * 2));
        *(undefined4 *)(plVar3 + 8) = local_458;
        param_2[1] = param_2[1] + 0x48;
      }
      if (local_478 != auStack_468) {
        operator_delete(local_478);
      }
      if (local_498 != auStack_488) {
        operator_delete(local_498);
      }
    }
    uVar10 = 0;
LAB_0010e18e:
    fclose(__stream);
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}


//===== FUN_0010e3a0 @ 0010e3a0 size=44 =====

void FUN_0010e3a0(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *(undefined1 (*) [16])(param_1 + 1) = (undefined1  [16])0x0;
  return;
}


//===== FUN_0010e3d0 @ 0010e3d0 size=53 =====

void FUN_0010e3d0(long param_1)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 0x28);
  if (puVar1 != (undefined8 *)0x0) {
    if ((void *)puVar1[6] != (void *)0x0) {
      operator_delete__((void *)puVar1[6]);
    }
    if ((void *)*puVar1 != (void *)0x0) {
      operator_delete__((void *)*puVar1);
    }
    operator_delete(puVar1);
    return;
  }
  return;
}


//===== FUN_0010e410 @ 0010e410 size=58 =====

void FUN_0010e410(undefined8 *param_1,char *param_2)

{
  char cVar1;
  undefined8 *puVar2;
  long lVar3;
  
  if (param_2 == (char *)0x0) {
    puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
    puVar2[2] = 0x20000000d;
    puVar2[3] = "../src_udic/marisa_u/agent.cpp:13: MARISA_NULL_ERROR: str == NULL";
    *puVar2 = &PTR_FUN_00132da8;
    puVar2[1] = "../src_udic/marisa_u/agent.cpp";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  if (param_1[5] != 0) {
    *(undefined4 *)(param_1[5] + 0x6c) = 0;
  }
  lVar3 = 0;
  cVar1 = *param_2;
  while (cVar1 != '\0') {
    lVar3 = lVar3 + 1;
    cVar1 = param_2[lVar3];
  }
  *param_1 = param_2;
  param_1[1] = lVar3;
  return;
}


//===== FUN_0010e450 @ 0010e450 size=42 =====

void FUN_0010e450(long *param_1,long param_2,long param_3)

{
  undefined8 *puVar1;
  
  if ((param_2 == 0) && (param_3 != 0)) {
    puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
    puVar1[2] = 0x200000015;
    puVar1[3] = 
    "../src_udic/marisa_u/agent.cpp:21: MARISA_NULL_ERROR: (ptr == NULL) && (length != 0)";
    *puVar1 = &PTR_FUN_00132da8;
    puVar1[1] = "../src_udic/marisa_u/agent.cpp";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  if (param_1[5] != 0) {
    *(undefined4 *)(param_1[5] + 0x6c) = 0;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}


//===== FUN_0010e480 @ 0010e480 size=25 =====

void FUN_0010e480(long param_1,undefined8 param_2)

{
  if (*(long *)(param_1 + 0x28) != 0) {
    *(undefined4 *)(*(long *)(param_1 + 0x28) + 0x6c) = 0;
  }
  *(undefined8 *)(param_1 + 0x10) = param_2;
  return;
}


//===== FUN_0010e4a0 @ 0010e4a0 size=324 =====

void FUN_0010e4a0(long param_1)

{
  undefined8 *puVar1;
  undefined1 (*pauVar2) [16];
  undefined1 (*pauVar3) [16];
  
  if (*(long *)(param_1 + 0x28) != 0) {
    puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar1 = &PTR_FUN_00132da8;
    puVar1[1] = "../src_udic/marisa_u/agent.cpp";
    puVar1[2] = 0x100000024;
    puVar1[3] = "../src_udic/marisa_u/agent.cpp:36: MARISA_STATE_ERROR: state_.get() != NULL";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  pauVar2 = operator_new(0x70,(nothrow_t *)PTR_nothrow_00132fb8);
  if (pauVar2 == (undefined1 (*) [16])0x0) {
    pauVar3 = *(undefined1 (**) [16])(param_1 + 0x28);
    *(undefined8 *)(param_1 + 0x28) = 0;
    if (pauVar3 == (undefined1 (*) [16])0x0) {
      FUN_00104b74();
      return;
    }
  }
  else {
    pauVar3 = *(undefined1 (**) [16])(param_1 + 0x28);
    pauVar2[2][8] = 0;
    *pauVar2 = (undefined1  [16])0x0;
    *(undefined1 (*) [16])(pauVar2[1] + 8) = (undefined1  [16])0x0;
    pauVar2[3] = (undefined1  [16])0x0;
    *(undefined1 (*) [16])(pauVar2[4] + 8) = (undefined1  [16])0x0;
    *(undefined8 *)pauVar2[1] = 0;
    *(undefined8 *)pauVar2[4] = 0;
    pauVar2[5][8] = 0;
    pauVar2[6] = (undefined1  [16])0x0;
    if (pauVar2 == pauVar3) {
      puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
      *puVar1 = &PTR_FUN_00132da8;
      puVar1[1] = "../src_udic/marisa_u/scoped-ptr.h";
      puVar1[2] = 0x600000013;
      puVar1[3] = 
      "../src_udic/marisa_u/scoped-ptr.h:19: MARISA_RESET_ERROR: (ptr != NULL) && (ptr == ptr_)";
                    /* WARNING: Subroutine does not return */
      __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
    }
    *(undefined1 (**) [16])(param_1 + 0x28) = pauVar2;
    if (pauVar3 == (undefined1 (*) [16])0x0) {
      return;
    }
  }
  if (*(void **)pauVar3[3] != (void *)0x0) {
    operator_delete__(*(void **)pauVar3[3]);
  }
  if (*(void **)*pauVar3 != (void *)0x0) {
    operator_delete__(*(void **)*pauVar3);
  }
  operator_delete(pauVar3);
  if (*(long *)(param_1 + 0x28) != 0) {
    return;
  }
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/agent.cpp";
  puVar1[2] = 0x800000026;
  puVar1[3] = "../src_udic/marisa_u/agent.cpp:38: MARISA_MEMORY_ERROR: state_.get() == NULL";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_0010e5b0 @ 0010e5b0 size=108 =====

void FUN_0010e5b0(undefined8 *param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar2 = *param_1;
  *param_1 = *param_2;
  *param_2 = uVar2;
  uVar2 = param_1[1];
  param_1[1] = param_2[1];
  param_2[1] = uVar2;
  uVar2 = param_1[2];
  param_1[2] = param_2[2];
  param_2[2] = uVar2;
  uVar2 = param_1[3];
  param_1[3] = param_2[3];
  param_2[3] = uVar2;
  uVar1 = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_2 + 4) = uVar1;
  uVar1 = *(undefined4 *)((long)param_1 + 0x24);
  *(undefined4 *)((long)param_1 + 0x24) = *(undefined4 *)((long)param_2 + 0x24);
  *(undefined4 *)((long)param_2 + 0x24) = uVar1;
  uVar2 = param_1[5];
  param_1[5] = param_2[5];
  param_2[5] = uVar2;
  return;
}


//===== FUN_0010e620 @ 0010e620 size=89 =====

void FUN_0010e620(undefined8 param_1)

{
  long in_FS_OFFSET;
  undefined1 auStack_58 [56];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_0010e3a0(auStack_58);
  FUN_0010e5b0(auStack_58,param_1);
  FUN_0010e3d0(auStack_58);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_0010e690 @ 0010e690 size=9 =====

undefined8 FUN_0010e690(long param_1)

{
  return *(undefined8 *)(param_1 + 0x18);
}


//===== FUN_0010e6a0 @ 0010e6a0 size=23 =====

void FUN_0010e6a0(exception *param_1)

{
  *(undefined ***)param_1 = &PTR_FUN_00132da8;
  std::exception::~exception(param_1);
  return;
}


//===== FUN_0010e6c0 @ 0010e6c0 size=36 =====

void FUN_0010e6c0(exception *param_1)

{
  *(undefined ***)param_1 = &PTR_FUN_00132da8;
  std::exception::~exception(param_1);
  operator_delete(param_1);
  return;
}


//===== FUN_0010e6f0 @ 0010e6f0 size=12 =====

void FUN_0010e6f0(undefined8 *param_1)

{
  *param_1 = 0;
  return;
}


//===== FUN_0010e700 @ 0010e700 size=32 =====

void FUN_0010e700(undefined8 *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)*param_1;
  if (pvVar1 != (void *)0x0) {
    FUN_001125e0(pvVar1);
    operator_delete(pvVar1);
    return;
  }
  return;
}


//===== FUN_0010e730 @ 0010e730 size=227 =====

void FUN_0010e730(long *param_1,long param_2)

{
  undefined8 *puVar1;
  long in_FS_OFFSET;
  undefined1 local_48 [40];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if (*param_1 == 0) {
    puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar1 = &PTR_FUN_00132da8;
    puVar1[1] = "../src_udic/marisa_u/trie.cpp";
    puVar1[2] = 0x100000045;
    puVar1[3] = "../src_udic/marisa_u/trie.cpp:69: MARISA_STATE_ERROR: trie_.get() == NULL";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  if (param_2 != 0) {
    FUN_00110c30(local_48);
    FUN_00110d80(local_48,param_2);
    FUN_001143a0(*param_1,local_48);
    FUN_00110c50(local_48);
    if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/trie.cpp";
  puVar1[2] = 0x200000046;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:70: MARISA_NULL_ERROR: filename == NULL";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_0010e7e0 @ 0010e7e0 size=225 =====

void FUN_0010e7e0(long *param_1,int param_2)

{
  undefined8 *puVar1;
  long in_FS_OFFSET;
  undefined1 local_48 [40];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if (*param_1 == 0) {
    puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar1 = &PTR_FUN_00132da8;
    puVar1[1] = "../src_udic/marisa_u/trie.cpp";
    puVar1[2] = 0x10000004e;
    puVar1[3] = "../src_udic/marisa_u/trie.cpp:78: MARISA_STATE_ERROR: trie_.get() == NULL";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  if (param_2 != -1) {
    FUN_00110c30(local_48);
    FUN_00110ea0(local_48,param_2);
    FUN_001143a0(*param_1,local_48);
    FUN_00110c50(local_48);
    if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/trie.cpp";
  puVar1[2] = 0x50000004f;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:79: MARISA_CODE_ERROR: fd == -1";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_0010e890 @ 0010e890 size=72 =====

void FUN_0010e890(long *param_1,long param_2)

{
  undefined8 *puVar1;
  
  if (*param_1 == 0) {
    puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
    puVar1[2] = 0x100000057;
    puVar1[3] = "../src_udic/marisa_u/trie.cpp:87: MARISA_STATE_ERROR: trie_.get() == NULL";
    *puVar1 = &PTR_FUN_00132da8;
    puVar1[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  if (*(long *)(param_2 + 0x28) != 0) {
    FUN_001150f0();
    return;
  }
  FUN_0010e4a0(param_2);
  FUN_001150f0(*param_1,param_2);
  return;
}


//===== FUN_0010e8e0 @ 0010e8e0 size=72 =====

void FUN_0010e8e0(long *param_1,long param_2)

{
  undefined8 *puVar1;
  
  if (*param_1 == 0) {
    puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
    puVar1[2] = 0x10000005f;
    puVar1[3] = "../src_udic/marisa_u/trie.cpp:95: MARISA_STATE_ERROR: trie_.get() == NULL";
    *puVar1 = &PTR_FUN_00132da8;
    puVar1[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  if (*(long *)(param_2 + 0x28) != 0) {
    FUN_00114730();
    return;
  }
  FUN_0010e4a0(param_2);
  FUN_00114730(*param_1,param_2);
  return;
}


//===== FUN_0010e930 @ 0010e930 size=72 =====

void FUN_0010e930(long *param_1,long param_2)

{
  undefined8 *puVar1;
  
  if (*param_1 == 0) {
    puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
    puVar1[2] = 0x100000067;
    puVar1[3] = "../src_udic/marisa_u/trie.cpp:103: MARISA_STATE_ERROR: trie_.get() == NULL";
    *puVar1 = &PTR_FUN_00132da8;
    puVar1[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  if (*(long *)(param_2 + 0x28) != 0) {
    FUN_00114d90();
    return;
  }
  FUN_0010e4a0(param_2);
  FUN_00114d90(*param_1,param_2);
  return;
}


//===== FUN_0010e980 @ 0010e980 size=72 =====

void FUN_0010e980(long *param_1,long param_2)

{
  undefined8 *puVar1;
  
  if (*param_1 == 0) {
    puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
    puVar1[2] = 0x10000006f;
    puVar1[3] = "../src_udic/marisa_u/trie.cpp:111: MARISA_STATE_ERROR: trie_.get() == NULL";
    *puVar1 = &PTR_FUN_00132da8;
    puVar1[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  if (*(long *)(param_2 + 0x28) != 0) {
    FUN_00115790();
    return;
  }
  FUN_0010e4a0(param_2);
  FUN_00115790(*param_1,param_2);
  return;
}


//===== FUN_0010e9d0 @ 0010e9d0 size=24 =====

undefined8 FUN_0010e9d0(long *param_1)

{
  undefined8 *puVar1;
  
  if (*param_1 != 0) {
    return *(undefined8 *)(*param_1 + 0x430);
  }
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x100000077;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:119: MARISA_STATE_ERROR: trie_.get() == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_0010e9f0 @ 0010e9f0 size=24 =====

undefined8 FUN_0010e9f0(long *param_1)

{
  undefined8 *puVar1;
  
  if (*param_1 != 0) {
    return *(undefined8 *)(*param_1 + 0x108);
  }
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x10000007c;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:124: MARISA_STATE_ERROR: trie_.get() == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_0010ea10 @ 0010ea10 size=28 =====

long FUN_0010ea10(long *param_1)

{
  undefined8 *puVar1;
  
  if (*param_1 != 0) {
    return (*(ulong *)(*param_1 + 0x30) >> 1) - 1;
  }
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x100000081;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:129: MARISA_STATE_ERROR: trie_.get() == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_0010ea30 @ 0010ea30 size=23 =====

undefined4 FUN_0010ea30(long *param_1)

{
  undefined8 *puVar1;
  
  if (*param_1 != 0) {
    return *(undefined4 *)(*param_1 + 0x43c);
  }
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x100000086;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:134: MARISA_STATE_ERROR: trie_.get() == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_0010ea50 @ 0010ea50 size=23 =====

undefined4 FUN_0010ea50(long *param_1)

{
  undefined8 *puVar1;
  
  if (*param_1 != 0) {
    return *(undefined4 *)(*param_1 + 0x440);
  }
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x10000008b;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:139: MARISA_STATE_ERROR: trie_.get() == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_0010ea70 @ 0010ea70 size=28 =====

undefined8 FUN_0010ea70(long *param_1)

{
  long lVar1;
  undefined8 *puVar2;
  
  lVar1 = *param_1;
  if (lVar1 != 0) {
    return CONCAT71((int7)((ulong)lVar1 >> 8),*(long *)(lVar1 + 0x108) == 0);
  }
  puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar2[2] = 0x100000090;
  puVar2[3] = "../src_udic/marisa_u/trie.cpp:144: MARISA_STATE_ERROR: trie_.get() == NULL";
  *puVar2 = &PTR_FUN_00132da8;
  puVar2[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_0010ea90 @ 0010ea90 size=24 =====

undefined8 FUN_0010ea90(long *param_1)

{
  undefined8 *puVar1;
  
  if (*param_1 != 0) {
    return *(undefined8 *)(*param_1 + 0x108);
  }
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x100000095;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:149: MARISA_STATE_ERROR: trie_.get() == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_0010eab0 @ 0010eab0 size=21 =====

void FUN_0010eab0(long *param_1)

{
  undefined8 *puVar1;
  
  if (*param_1 != 0) {
    FUN_001129f0();
    return;
  }
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x10000009a;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:154: MARISA_STATE_ERROR: trie_.get() == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_0010ead0 @ 0010ead0 size=21 =====

void FUN_0010ead0(long *param_1)

{
  undefined8 *puVar1;
  
  if (*param_1 != 0) {
    FUN_00112ae0();
    return;
  }
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x10000009f;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:159: MARISA_STATE_ERROR: trie_.get() == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_0010eaf0 @ 0010eaf0 size=17 =====

void FUN_0010eaf0(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = *param_1;
  *param_1 = *param_2;
  *param_2 = uVar1;
  return;
}


//===== FUN_0010eb10 @ 0010eb10 size=89 =====

void FUN_0010eb10(undefined8 param_1)

{
  long in_FS_OFFSET;
  undefined1 auStack_28 [8];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_0010e6f0(auStack_28);
  FUN_0010eaf0(auStack_28,param_1);
  FUN_0010e700(auStack_28);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_0010eb80 @ 0010eb80 size=226 =====

void FUN_0010eb80(long param_1,long *param_2)

{
  undefined8 *puVar1;
  long in_FS_OFFSET;
  undefined1 local_48 [40];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_1 == 0) {
    puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar1 = &PTR_FUN_00132da8;
    puVar1[1] = "../src_udic/marisa_u/trie.cpp";
    puVar1[2] = 0x2000000e4;
    puVar1[3] = "../src_udic/marisa_u/trie.cpp:228: MARISA_NULL_ERROR: file == NULL";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  if (*param_2 != 0) {
    FUN_00110c30(local_48);
    FUN_00110e10(local_48,param_1);
    FUN_001143a0(*param_2,local_48);
    FUN_00110c50(local_48);
    if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/trie.cpp";
  puVar1[2] = 0x1000000c1;
  puVar1[3] = "../src_udic/marisa_u/trie.cpp:193: MARISA_STATE_ERROR: trie.trie_.get() == NULL";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_0010ec30 @ 0010ec30 size=118 =====

undefined8 FUN_0010ec30(undefined8 param_1,long *param_2)

{
  undefined8 *puVar1;
  long in_FS_OFFSET;
  undefined1 auStack_48 [40];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if (*param_2 == 0) {
    puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
    puVar1[2] = 0x1000000d5;
    puVar1[3] = "../src_udic/marisa_u/trie.cpp:213: MARISA_STATE_ERROR: trie.trie_.get() == NULL";
    *puVar1 = &PTR_FUN_00132da8;
    puVar1[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  FUN_00110c30(auStack_48);
  FUN_00110f30(auStack_48,param_1);
  FUN_001143a0(*param_2,auStack_48);
  FUN_00110c50(auStack_48);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== thunk_FUN_0010ec30 @ 0010ecc0 size=9 =====

void thunk_FUN_0010ec30(void)

{
  FUN_0010ec30();
  return;
}


//===== FUN_0010ecd0 @ 0010ecd0 size=183 =====

void FUN_0010ecd0(undefined8 *param_1,undefined8 param_2,undefined4 param_3)

{
  long lVar1;
  void *pvVar2;
  undefined8 *puVar3;
  void *pvVar4;
  long in_FS_OFFSET;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  pvVar4 = operator_new(0x470,(nothrow_t *)PTR_nothrow_00132fb8);
  if (pvVar4 == (void *)0x0) {
    puVar3 = (undefined8 *)__cxa_allocate_exception(0x20);
    puVar3[2] = 0x80000000e;
    puVar3[3] = "../src_udic/marisa_u/trie.cpp:14: MARISA_MEMORY_ERROR: temp.get() == NULL";
    *puVar3 = &PTR_FUN_00132da8;
    puVar3[1] = "../src_udic/marisa_u/trie.cpp";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar3,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  FUN_00112770(pvVar4);
  FUN_00118e40(pvVar4,param_2,param_3);
  pvVar2 = (void *)*param_1;
  *param_1 = pvVar4;
  if (pvVar2 == (void *)0x0) {
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
  else {
    FUN_001125e0(pvVar2);
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      operator_delete(pvVar2);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_0010edb0 @ 0010edb0 size=293 =====

void FUN_0010edb0(undefined8 *param_1,long param_2)

{
  void *pvVar1;
  undefined8 *puVar2;
  void *pvVar3;
  long in_FS_OFFSET;
  undefined1 local_58 [40];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_2 == 0) {
    puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar2 = &PTR_FUN_00132da8;
    puVar2[1] = "../src_udic/marisa_u/trie.cpp";
    puVar2[2] = 0x200000015;
    puVar2[3] = "../src_udic/marisa_u/trie.cpp:21: MARISA_NULL_ERROR: filename == NULL";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  pvVar3 = operator_new(0x470,(nothrow_t *)PTR_nothrow_00132fb8);
  if (pvVar3 != (void *)0x0) {
    FUN_00112770(pvVar3);
    FUN_00110300(local_58);
    FUN_001105d0(local_58,param_2);
    FUN_00116800(pvVar3,local_58);
    pvVar1 = (void *)*param_1;
    *param_1 = pvVar3;
    FUN_00110320(local_58);
    if (pvVar1 != (void *)0x0) {
      FUN_001125e0(pvVar1);
      operator_delete(pvVar1);
    }
    if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar2 = &PTR_FUN_00132da8;
  puVar2[1] = "../src_udic/marisa_u/trie.cpp";
  puVar2[2] = 0x800000018;
  puVar2[3] = "../src_udic/marisa_u/trie.cpp:24: MARISA_MEMORY_ERROR: temp.get() == NULL";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_0010eec0 @ 0010eec0 size=308 =====

void FUN_0010eec0(undefined8 *param_1,long param_2,long param_3)

{
  void *pvVar1;
  undefined8 *puVar2;
  void *pvVar3;
  long in_FS_OFFSET;
  undefined1 local_58 [40];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if ((param_2 == 0) && (param_3 != 0)) {
    puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar2 = &PTR_FUN_00132da8;
    puVar2[1] = "../src_udic/marisa_u/trie.cpp";
    puVar2[2] = 0x200000021;
    puVar2[3] = "../src_udic/marisa_u/trie.cpp:33: MARISA_NULL_ERROR: (ptr == NULL) && (size != 0)";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  pvVar3 = operator_new(0x470,(nothrow_t *)PTR_nothrow_00132fb8);
  if (pvVar3 == (void *)0x0) {
    puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar2 = &PTR_FUN_00132da8;
    puVar2[1] = "../src_udic/marisa_u/trie.cpp";
    puVar2[2] = 0x800000024;
    puVar2[3] = "../src_udic/marisa_u/trie.cpp:36: MARISA_MEMORY_ERROR: temp.get() == NULL";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  FUN_00112770(pvVar3);
  FUN_00110300(local_58);
  FUN_00110660(local_58,param_2,param_3);
  FUN_00116800(pvVar3,local_58);
  pvVar1 = (void *)*param_1;
  *param_1 = pvVar3;
  FUN_00110320(local_58);
  if (pvVar1 != (void *)0x0) {
    FUN_001125e0(pvVar1);
    operator_delete(pvVar1);
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_0010efe0 @ 0010efe0 size=293 =====

void FUN_0010efe0(undefined8 *param_1,long param_2)

{
  void *pvVar1;
  undefined8 *puVar2;
  void *pvVar3;
  long in_FS_OFFSET;
  undefined1 local_58 [40];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_2 == 0) {
    puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar2 = &PTR_FUN_00132da8;
    puVar2[1] = "../src_udic/marisa_u/trie.cpp";
    puVar2[2] = 0x20000002d;
    puVar2[3] = "../src_udic/marisa_u/trie.cpp:45: MARISA_NULL_ERROR: filename == NULL";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  pvVar3 = operator_new(0x470,(nothrow_t *)PTR_nothrow_00132fb8);
  if (pvVar3 != (void *)0x0) {
    FUN_00112770(pvVar3);
    FUN_001106f0(local_58);
    FUN_00110840(local_58,param_2);
    FUN_00117050(pvVar3,local_58);
    pvVar1 = (void *)*param_1;
    *param_1 = pvVar3;
    FUN_00110710(local_58);
    if (pvVar1 != (void *)0x0) {
      FUN_001125e0(pvVar1);
      operator_delete(pvVar1);
    }
    if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar2 = &PTR_FUN_00132da8;
  puVar2[1] = "../src_udic/marisa_u/trie.cpp";
  puVar2[2] = 0x800000030;
  puVar2[3] = "../src_udic/marisa_u/trie.cpp:48: MARISA_MEMORY_ERROR: temp.get() == NULL";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_0010f0f0 @ 0010f0f0 size=293 =====

void FUN_0010f0f0(undefined8 *param_1,int param_2)

{
  void *pvVar1;
  undefined8 *puVar2;
  void *pvVar3;
  long in_FS_OFFSET;
  undefined1 local_58 [40];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_2 == -1) {
    puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar2 = &PTR_FUN_00132da8;
    puVar2[1] = "../src_udic/marisa_u/trie.cpp";
    puVar2[2] = 0x500000039;
    puVar2[3] = "../src_udic/marisa_u/trie.cpp:57: MARISA_CODE_ERROR: fd == -1";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  pvVar3 = operator_new(0x470,(nothrow_t *)PTR_nothrow_00132fb8);
  if (pvVar3 != (void *)0x0) {
    FUN_00112770(pvVar3);
    FUN_001106f0(local_58);
    FUN_00110960(local_58,param_2);
    FUN_00117050(pvVar3,local_58);
    pvVar1 = (void *)*param_1;
    *param_1 = pvVar3;
    FUN_00110710(local_58);
    if (pvVar1 != (void *)0x0) {
      FUN_001125e0(pvVar1);
      operator_delete(pvVar1);
    }
    if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar2 = &PTR_FUN_00132da8;
  puVar2[1] = "../src_udic/marisa_u/trie.cpp";
  puVar2[2] = 0x80000003c;
  puVar2[3] = "../src_udic/marisa_u/trie.cpp:60: MARISA_MEMORY_ERROR: temp.get() == NULL";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_0010f200 @ 0010f200 size=441 =====

void FUN_0010f200(long param_1,undefined8 *param_2)

{
  void *pvVar1;
  undefined8 *puVar2;
  void *pvVar3;
  long in_FS_OFFSET;
  undefined1 local_58 [40];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_1 == 0) {
    puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar2 = &PTR_FUN_00132da8;
    puVar2[1] = "../src_udic/marisa_u/trie.cpp";
    puVar2[2] = 0x2000000de;
    puVar2[3] = "../src_udic/marisa_u/trie.cpp:222: MARISA_NULL_ERROR: file == NULL";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  if (param_2 == (undefined8 *)0x0) {
    puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar2 = &PTR_FUN_00132da8;
    puVar2[1] = "../src_udic/marisa_u/trie.cpp";
    puVar2[2] = 0x2000000df;
    puVar2[3] = "../src_udic/marisa_u/trie.cpp:223: MARISA_NULL_ERROR: trie == NULL";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  pvVar3 = operator_new(0x470,(nothrow_t *)PTR_nothrow_00132fb8);
  if (pvVar3 == (void *)0x0) {
    puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar2 = &PTR_FUN_00132da8;
    puVar2[1] = "../src_udic/marisa_u/trie.cpp";
    puVar2[2] = 0x8000000b8;
    puVar2[3] = "../src_udic/marisa_u/trie.cpp:184: MARISA_MEMORY_ERROR: temp.get() == NULL";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  FUN_00112770(pvVar3);
  FUN_001106f0(local_58);
  FUN_001108d0(local_58,param_1);
  FUN_00117050(pvVar3,local_58);
  pvVar1 = (void *)*param_2;
  *param_2 = pvVar3;
  FUN_00110710(local_58);
  if (pvVar1 != (void *)0x0) {
    FUN_001125e0(pvVar1);
    operator_delete(pvVar1);
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_0010f310 @ 0010f310 size=300 =====

undefined8 FUN_0010f310(undefined8 param_1,undefined8 *param_2)

{
  void *pvVar1;
  undefined8 *puVar2;
  void *pvVar3;
  long in_FS_OFFSET;
  undefined1 local_58 [40];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_2 == (undefined8 *)0x0) {
    puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar2 = &PTR_FUN_00132da8;
    puVar2[1] = "../src_udic/marisa_u/trie.cpp";
    puVar2[2] = 0x2000000e9;
    puVar2[3] = "../src_udic/marisa_u/trie.cpp:233: MARISA_NULL_ERROR: trie == NULL";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  pvVar3 = operator_new(0x470,(nothrow_t *)PTR_nothrow_00132fb8);
  if (pvVar3 != (void *)0x0) {
    FUN_00112770(pvVar3);
    FUN_001106f0(local_58);
    FUN_001109f0(local_58,param_1);
    FUN_00117050(pvVar3,local_58);
    pvVar1 = (void *)*param_2;
    *param_2 = pvVar3;
    FUN_00110710(local_58);
    if (pvVar1 != (void *)0x0) {
      FUN_001125e0(pvVar1);
      operator_delete(pvVar1);
    }
    if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
      return param_1;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar2 = &PTR_FUN_00132da8;
  puVar2[1] = "../src_udic/marisa_u/trie.cpp";
  puVar2[2] = 0x8000000cc;
  puVar2[3] = "../src_udic/marisa_u/trie.cpp:204: MARISA_MEMORY_ERROR: temp.get() == NULL";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== thunk_FUN_0010f310 @ 0010f420 size=9 =====

void thunk_FUN_0010f310(void)

{
  FUN_0010f310();
  return;
}


//===== FUN_0010f430 @ 0010f430 size=32 =====

void FUN_0010f430(undefined8 *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)*param_1;
  if (pvVar1 != (void *)0x0) {
    FUN_001125e0(pvVar1);
    operator_delete(pvVar1);
    return;
  }
  return;
}


//===== FUN_0010f460 @ 0010f460 size=64 =====

void FUN_0010f460(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[3] = 0;
  param_1[6] = 0;
  param_1[9] = 0;
  param_1[0xc] = 0;
  *(undefined1 (*) [16])(param_1 + 1) = (undefined1  [16])0x0;
  *(undefined1 (*) [16])(param_1 + 4) = (undefined1  [16])0x0;
  *(undefined1 (*) [16])(param_1 + 7) = (undefined1  [16])0x0;
  *(undefined1 (*) [16])(param_1 + 10) = (undefined1  [16])0x0;
  return;
}


//===== FUN_0010f4a0 @ 0010f4a0 size=45 =====

void FUN_0010f4a0(long param_1)

{
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined8 *)(param_1 + 0x48) = 0;
  *(undefined8 *)(param_1 + 0x60) = 0;
  *(undefined1 (*) [16])(param_1 + 0x50) = (undefined1  [16])0x0;
  return;
}


//===== FUN_0010f4d0 @ 0010f4d0 size=212 =====

void FUN_0010f4d0(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = *param_1;
  *param_1 = *param_2;
  *param_2 = uVar1;
  uVar1 = param_1[1];
  param_1[1] = param_2[1];
  param_2[1] = uVar1;
  uVar1 = param_1[2];
  param_1[2] = param_2[2];
  param_2[2] = uVar1;
  uVar1 = param_1[3];
  param_1[3] = param_2[3];
  param_2[3] = uVar1;
  uVar1 = param_1[4];
  param_1[4] = param_2[4];
  param_2[4] = uVar1;
  uVar1 = param_1[5];
  param_1[5] = param_2[5];
  param_2[5] = uVar1;
  uVar1 = param_1[6];
  param_1[6] = param_2[6];
  param_2[6] = uVar1;
  uVar1 = param_1[7];
  param_1[7] = param_2[7];
  param_2[7] = uVar1;
  uVar1 = param_1[8];
  param_1[8] = param_2[8];
  param_2[8] = uVar1;
  uVar1 = param_1[9];
  param_1[9] = param_2[9];
  param_2[9] = uVar1;
  uVar1 = param_1[10];
  param_1[10] = param_2[10];
  param_2[10] = uVar1;
  uVar1 = param_1[0xb];
  param_1[0xb] = param_2[0xb];
  param_2[0xb] = uVar1;
  uVar1 = param_1[0xc];
  param_1[0xc] = param_2[0xc];
  param_2[0xc] = uVar1;
  return;
}


//===== FUN_0010f5b0 @ 0010f5b0 size=312 =====

void FUN_0010f5b0(undefined8 param_1)

{
  undefined8 *puVar1;
  long lVar2;
  long lVar3;
  long in_FS_OFFSET;
  long local_88 [3];
  long local_70;
  long local_58;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_0010f460(local_88);
  FUN_0010f4d0(local_88,param_1);
  if (local_58 != 0) {
    lVar3 = local_58 + *(long *)(local_58 + -8) * 8;
    lVar2 = local_58;
    if (local_58 != lVar3) {
      do {
        while( true ) {
          puVar1 = (undefined8 *)(lVar3 + -8);
          lVar3 = lVar3 + -8;
          if ((void *)*puVar1 == (void *)0x0) break;
          operator_delete__((void *)*puVar1);
          lVar2 = local_58;
          if (local_58 == lVar3) goto LAB_0010f620;
        }
      } while (lVar3 != lVar2);
    }
LAB_0010f620:
    operator_delete__((void *)(lVar3 + -8));
  }
  if (local_70 != 0) {
    lVar3 = local_70 + *(long *)(local_70 + -8) * 8;
    lVar2 = local_70;
    if (local_70 != lVar3) {
      do {
        while( true ) {
          puVar1 = (undefined8 *)(lVar3 + -8);
          lVar3 = lVar3 + -8;
          if ((void *)*puVar1 == (void *)0x0) break;
          operator_delete__((void *)*puVar1);
          lVar2 = local_70;
          if (local_70 == lVar3) goto LAB_0010f660;
        }
      } while (lVar3 != lVar2);
    }
LAB_0010f660:
    operator_delete__((void *)(lVar3 + -8));
  }
  if (local_88[0] != 0) {
    lVar3 = local_88[0] + *(long *)(local_88[0] + -8) * 8;
    lVar2 = local_88[0];
    if (local_88[0] != lVar3) {
      do {
        while( true ) {
          puVar1 = (undefined8 *)(lVar3 + -8);
          lVar3 = lVar3 + -8;
          if ((void *)*puVar1 == (void *)0x0) break;
          operator_delete__((void *)*puVar1);
          lVar2 = local_88[0];
          if (lVar3 == local_88[0]) goto LAB_0010f69e;
        }
      } while (lVar3 != lVar2);
    }
LAB_0010f69e:
    operator_delete__((void *)(lVar2 + -8));
  }
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


//===== FUN_0010f700 @ 0010f700 size=658 =====

void FUN_0010f700(long param_1)

{
  ulong *puVar1;
  void *pvVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined *puVar7;
  ulong *puVar8;
  ulong *puVar9;
  long lVar10;
  undefined8 *puVar11;
  ulong uVar12;
  size_t __n;
  undefined8 *puVar13;
  undefined8 *puVar14;
  ulong uVar15;
  ulong uVar16;
  
  puVar7 = PTR_nothrow_00132fb8;
  lVar10 = *(long *)(param_1 + 0x38);
  if (lVar10 == *(long *)(param_1 + 0x40)) {
    if (lVar10 == 0) {
      uVar15 = 0x10;
      uVar16 = 1;
    }
    else {
      uVar16 = lVar10 * 2;
      uVar15 = lVar10 * 0x10 + 8;
      if (0xfffffffffffffff < uVar16) {
        uVar15 = 0xffffffffffffffff;
      }
    }
    puVar8 = operator_new__(uVar15,(nothrow_t *)PTR_nothrow_00132fb8);
    if (puVar8 == (ulong *)0x0) {
      puVar11 = (undefined8 *)__cxa_allocate_exception(0x20);
      *puVar11 = &PTR_FUN_00132da8;
      puVar11[1] = "../src_udic/marisa_u/keyset.cpp";
      puVar11[2] = 0x8000000a9;
      puVar11[3] = 
      "../src_udic/marisa_u/keyset.cpp:169: MARISA_MEMORY_ERROR: new_blocks.get() == NULL";
                    /* WARNING: Subroutine does not return */
      __cxa_throw(puVar11,&PTR_vtable_00132d80,FUN_0010e6a0);
    }
    *puVar8 = uVar16;
    puVar9 = puVar8 + 1;
    if (-1 < (long)(uVar16 - 1)) {
      __n = uVar16 * 8;
      if ((long)(uVar16 - 2) < -1) {
        __n = 8;
      }
      puVar9 = memset(puVar9,0,__n);
    }
    uVar15 = *(ulong *)(param_1 + 0x38);
    puVar1 = *(ulong **)(param_1 + 0x30);
    if (uVar15 == 0) {
      *(ulong **)(param_1 + 0x30) = puVar9;
      *(ulong *)(param_1 + 0x40) = uVar16;
      if (puVar1 == (ulong *)0x0) goto LAB_0010f870;
    }
    else {
      if ((puVar1 < puVar8 + 3 && puVar9 < puVar1 + 2) || (uVar15 - 1 < 2)) {
        uVar12 = 0;
        do {
          uVar3 = puVar1[uVar12];
          puVar1[uVar12] = puVar8[uVar12 + 1];
          puVar8[uVar12 + 1] = uVar3;
          uVar12 = uVar12 + 1;
        } while (uVar12 != uVar15);
      }
      else {
        lVar10 = 0;
        do {
          uVar4 = *(undefined8 *)((long)puVar1 + lVar10);
          uVar5 = ((undefined8 *)((long)puVar1 + lVar10))[1];
          puVar11 = (undefined8 *)((long)puVar8 + lVar10 + 8);
          uVar6 = puVar11[1];
          *(undefined8 *)((long)puVar1 + lVar10) = *puVar11;
          ((undefined8 *)((long)puVar1 + lVar10))[1] = uVar6;
          puVar11 = (undefined8 *)((long)puVar8 + lVar10 + 8);
          *puVar11 = uVar4;
          puVar11[1] = uVar5;
          lVar10 = lVar10 + 0x10;
        } while ((uVar15 >> 1) * 0x10 != lVar10);
        if ((uVar15 & 1) != 0) {
          uVar12 = puVar1[uVar15 & 0xfffffffffffffffe];
          puVar1[uVar15 & 0xfffffffffffffffe] = puVar9[uVar15 & 0xfffffffffffffffe];
          puVar9[uVar15 & 0xfffffffffffffffe] = uVar12;
        }
      }
      *(ulong **)(param_1 + 0x30) = puVar9;
      *(ulong *)(param_1 + 0x40) = uVar16;
    }
    puVar8 = puVar1 + puVar1[-1];
    while (puVar8 != puVar1) {
      while( true ) {
        puVar9 = puVar8 + -1;
        puVar8 = puVar8 + -1;
        if ((void *)*puVar9 == (void *)0x0) break;
        operator_delete__((void *)*puVar9);
        if (puVar8 == puVar1) goto LAB_0010f867;
      }
    }
LAB_0010f867:
    operator_delete__(puVar1 + -1);
  }
LAB_0010f870:
  puVar11 = operator_new__(0x1000,(nothrow_t *)puVar7);
  if (puVar11 == (undefined8 *)0x0) {
    puVar11 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar11 = &PTR_FUN_00132da8;
    puVar11[1] = "../src_udic/marisa_u/keyset.cpp";
    puVar11[2] = 0x8000000b1;
    puVar11[3] = "../src_udic/marisa_u/keyset.cpp:177: MARISA_MEMORY_ERROR: new_block.get() == NULL"
    ;
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar11,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  puVar13 = puVar11;
  do {
    *puVar13 = 0;
    puVar14 = puVar13 + 2;
    puVar13[1] = 0;
    puVar13 = puVar14;
  } while (puVar14 != puVar11 + 0x200);
  lVar10 = *(long *)(param_1 + 0x38);
  *(long *)(param_1 + 0x38) = lVar10 + 1;
  puVar13 = (undefined8 *)(*(long *)(param_1 + 0x30) + lVar10 * 8);
  pvVar2 = (void *)*puVar13;
  *puVar13 = puVar11;
  if (pvVar2 == (void *)0x0) {
    return;
  }
  operator_delete__(pvVar2);
  return;
}


//===== FUN_0010f960 @ 0010f960 size=718 =====

void FUN_0010f960(ulong *param_1)

{
  long lVar1;
  ulong *puVar2;
  void *pvVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  ulong *puVar9;
  ulong *__s;
  long lVar10;
  void *pvVar11;
  ulong uVar12;
  size_t __n;
  ulong uVar13;
  ulong uVar14;
  long in_FS_OFFSET;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  uVar13 = param_1[1];
  if (uVar13 == param_1[2]) {
    if (uVar13 == 0) {
      uVar13 = 0x10;
      uVar14 = 1;
    }
    else {
      uVar14 = uVar13 * 2;
      uVar13 = uVar13 * 0x10 + 8;
      if (0xfffffffffffffff < uVar14) {
        uVar13 = 0xffffffffffffffff;
      }
    }
    puVar9 = operator_new__(uVar13,(nothrow_t *)PTR_nothrow_00132fb8);
    if (puVar9 == (ulong *)0x0) {
      puVar8 = (undefined8 *)__cxa_allocate_exception(0x20);
      *puVar8 = &PTR_FUN_00132da8;
      puVar8[1] = "../src_udic/marisa_u/keyset.cpp";
      puVar8[2] = 0x800000081;
      puVar8[3] = 
      "../src_udic/marisa_u/keyset.cpp:129: MARISA_MEMORY_ERROR: new_blocks.get() == NULL";
                    /* WARNING: Subroutine does not return */
      __cxa_throw(puVar8,&PTR_vtable_00132d80,FUN_0010e6a0);
    }
    *puVar9 = uVar14;
    __s = puVar9 + 1;
    if (-1 < (long)(uVar14 - 1)) {
      __n = uVar14 * 8;
      if ((long)(uVar14 - 2) < -1) {
        __n = 8;
      }
      __s = memset(__s,0,__n);
    }
    uVar13 = param_1[1];
    puVar2 = (ulong *)*param_1;
    if (uVar13 == 0) {
      *param_1 = (ulong)__s;
      param_1[2] = uVar14;
      uVar13 = 0;
      if (puVar2 == (ulong *)0x0) goto LAB_0010f9b0;
    }
    else {
      if ((puVar2 < puVar9 + 3 && __s < puVar2 + 2) || (uVar13 - 1 < 2)) {
        uVar12 = 0;
        do {
          uVar4 = puVar2[uVar12];
          puVar2[uVar12] = puVar9[uVar12 + 1];
          puVar9[uVar12 + 1] = uVar4;
          uVar12 = uVar12 + 1;
        } while (uVar12 != uVar13);
      }
      else {
        lVar10 = 0;
        do {
          uVar5 = *(undefined8 *)((long)puVar2 + lVar10);
          uVar6 = ((undefined8 *)((long)puVar2 + lVar10))[1];
          puVar8 = (undefined8 *)((long)puVar9 + lVar10 + 8);
          uVar7 = puVar8[1];
          *(undefined8 *)((long)puVar2 + lVar10) = *puVar8;
          ((undefined8 *)((long)puVar2 + lVar10))[1] = uVar7;
          puVar8 = (undefined8 *)((long)puVar9 + lVar10 + 8);
          *puVar8 = uVar5;
          puVar8[1] = uVar6;
          lVar10 = lVar10 + 0x10;
        } while ((uVar13 >> 1) * 0x10 != lVar10);
        if ((uVar13 & 1) != 0) {
          uVar12 = puVar2[uVar13 & 0xfffffffffffffffe];
          puVar2[uVar13 & 0xfffffffffffffffe] = __s[uVar13 & 0xfffffffffffffffe];
          __s[uVar13 & 0xfffffffffffffffe] = uVar12;
        }
      }
      *param_1 = (ulong)__s;
      param_1[2] = uVar14;
    }
    uVar13 = (ulong)(puVar2 + puVar2[-1]);
    while ((ulong *)uVar13 != puVar2) {
      while( true ) {
        puVar8 = (undefined8 *)(uVar13 - 8);
        uVar13 = uVar13 - 8;
        if ((void *)*puVar8 == (void *)0x0) break;
        operator_delete__((void *)*puVar8);
        if ((ulong *)uVar13 == puVar2) goto LAB_0010fb17;
      }
    }
LAB_0010fb17:
    operator_delete__(puVar2 + -1);
    uVar13 = param_1[1];
  }
  __s = (ulong *)*param_1;
LAB_0010f9b0:
  pvVar11 = (void *)__s[uVar13];
  if (pvVar11 == (void *)0x0) {
    pvVar11 = operator_new__(0x1000,(nothrow_t *)PTR_nothrow_00132fb8);
    if (pvVar11 == (void *)0x0) {
      puVar8 = (undefined8 *)__cxa_allocate_exception(0x20);
      *puVar8 = &PTR_FUN_00132da8;
      puVar8[1] = "../src_udic/marisa_u/keyset.cpp";
      puVar8[2] = 0x80000008a;
      puVar8[3] = 
      "../src_udic/marisa_u/keyset.cpp:138: MARISA_MEMORY_ERROR: new_block.get() == NULL";
                    /* WARNING: Subroutine does not return */
      __cxa_throw(puVar8,&PTR_vtable_00132d80,FUN_0010e6a0);
    }
    uVar13 = param_1[1];
    puVar8 = (undefined8 *)(*param_1 + uVar13 * 8);
    pvVar3 = (void *)*puVar8;
    *puVar8 = pvVar11;
    if (pvVar3 != (void *)0x0) {
      operator_delete__(pvVar3);
      uVar13 = param_1[1];
      pvVar11 = *(void **)(*param_1 + uVar13 * 8);
    }
  }
  param_1[9] = (ulong)pvVar11;
  param_1[1] = uVar13 + 1;
  param_1[10] = 0x1000;
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


//===== FUN_0010fc00 @ 0010fc00 size=706 =====

void FUN_0010fc00(long param_1,ulong param_2)

{
  long lVar1;
  ulong *puVar2;
  void *pvVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined *puVar8;
  undefined8 *puVar9;
  ulong *puVar10;
  ulong *puVar11;
  long lVar12;
  void *pvVar13;
  ulong uVar14;
  size_t __n;
  ulong uVar15;
  ulong uVar16;
  long in_FS_OFFSET;
  
  puVar8 = PTR_nothrow_00132fb8;
  lVar12 = *(long *)(param_1 + 0x20);
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if (lVar12 == *(long *)(param_1 + 0x28)) {
    if (lVar12 == 0) {
      uVar15 = 0x10;
      uVar16 = 1;
    }
    else {
      uVar16 = lVar12 * 2;
      uVar15 = lVar12 * 0x10 + 8;
      if (0xfffffffffffffff < uVar16) {
        uVar15 = 0xffffffffffffffff;
      }
    }
    puVar10 = operator_new__(uVar15,(nothrow_t *)PTR_nothrow_00132fb8);
    if (puVar10 == (ulong *)0x0) {
      puVar9 = (undefined8 *)__cxa_allocate_exception(0x20);
      *puVar9 = &PTR_FUN_00132da8;
      puVar9[1] = "../src_udic/marisa_u/keyset.cpp";
      puVar9[2] = 0x800000097;
      puVar9[3] = 
      "../src_udic/marisa_u/keyset.cpp:151: MARISA_MEMORY_ERROR: new_blocks.get() == NULL";
                    /* WARNING: Subroutine does not return */
      __cxa_throw(puVar9,&PTR_vtable_00132d80,FUN_0010e6a0);
    }
    *puVar10 = uVar16;
    puVar11 = puVar10 + 1;
    if (-1 < (long)(uVar16 - 1)) {
      __n = uVar16 * 8;
      if ((long)(uVar16 - 2) < -1) {
        __n = 8;
      }
      puVar11 = memset(puVar11,0,__n);
    }
    uVar15 = *(ulong *)(param_1 + 0x20);
    puVar2 = *(ulong **)(param_1 + 0x18);
    if (uVar15 == 0) {
      *(ulong **)(param_1 + 0x18) = puVar11;
      *(ulong *)(param_1 + 0x28) = uVar16;
      if (puVar2 == (ulong *)0x0) goto LAB_0010fd8c;
    }
    else {
      if ((puVar2 < puVar10 + 3 && puVar11 < puVar2 + 2) || (uVar15 - 1 < 2)) {
        uVar14 = 0;
        do {
          uVar4 = puVar2[uVar14];
          puVar2[uVar14] = puVar10[uVar14 + 1];
          puVar10[uVar14 + 1] = uVar4;
          uVar14 = uVar14 + 1;
        } while (uVar14 != uVar15);
      }
      else {
        lVar12 = 0;
        do {
          uVar5 = *(undefined8 *)((long)puVar2 + lVar12);
          uVar6 = ((undefined8 *)((long)puVar2 + lVar12))[1];
          puVar9 = (undefined8 *)((long)puVar10 + lVar12 + 8);
          uVar7 = puVar9[1];
          *(undefined8 *)((long)puVar2 + lVar12) = *puVar9;
          ((undefined8 *)((long)puVar2 + lVar12))[1] = uVar7;
          puVar9 = (undefined8 *)((long)puVar10 + lVar12 + 8);
          *puVar9 = uVar5;
          puVar9[1] = uVar6;
          lVar12 = lVar12 + 0x10;
        } while ((uVar15 >> 1) * 0x10 != lVar12);
        if ((uVar15 & 1) != 0) {
          uVar14 = puVar2[uVar15 & 0xfffffffffffffffe];
          puVar2[uVar15 & 0xfffffffffffffffe] = puVar11[uVar15 & 0xfffffffffffffffe];
          puVar11[uVar15 & 0xfffffffffffffffe] = uVar14;
        }
      }
      *(ulong **)(param_1 + 0x18) = puVar11;
      *(ulong *)(param_1 + 0x28) = uVar16;
    }
    puVar10 = puVar2 + puVar2[-1];
    while (puVar10 != puVar2) {
      while( true ) {
        puVar11 = puVar10 + -1;
        puVar10 = puVar10 + -1;
        if ((void *)*puVar11 == (void *)0x0) break;
        operator_delete__((void *)*puVar11);
        if (puVar10 == puVar2) goto LAB_0010fd83;
      }
    }
LAB_0010fd83:
    operator_delete__(puVar2 + -1);
  }
LAB_0010fd8c:
  pvVar13 = operator_new__(param_2,(nothrow_t *)puVar8);
  if (pvVar13 == (void *)0x0) {
    puVar9 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar9 = &PTR_FUN_00132da8;
    puVar9[1] = "../src_udic/marisa_u/keyset.cpp";
    puVar9[2] = 0x80000009f;
    puVar9[3] = "../src_udic/marisa_u/keyset.cpp:159: MARISA_MEMORY_ERROR: new_block.get() == NULL";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar9,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  lVar12 = *(long *)(param_1 + 0x20);
  *(long *)(param_1 + 0x20) = lVar12 + 1;
  puVar9 = (undefined8 *)(*(long *)(param_1 + 0x18) + lVar12 * 8);
  pvVar3 = (void *)*puVar9;
  *puVar9 = pvVar13;
  if (pvVar3 == (void *)0x0) {
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
  else if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    operator_delete__(pvVar3);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_0010fea0 @ 0010fea0 size=132 =====

long FUN_0010fea0(long param_1,ulong param_2)

{
  long lVar1;
  ulong uVar2;
  
  if (*(ulong *)(param_1 + 0x58) >> 8 == *(ulong *)(param_1 + 0x38)) {
    FUN_0010f700();
  }
  if (param_2 < 0x401) {
    uVar2 = *(ulong *)(param_1 + 0x50);
    if (uVar2 < param_2) {
      FUN_0010f960(param_1);
      uVar2 = *(ulong *)(param_1 + 0x50);
    }
    lVar1 = *(long *)(param_1 + 0x48);
    *(ulong *)(param_1 + 0x50) = uVar2 - param_2;
    *(ulong *)(param_1 + 0x48) = lVar1 + param_2;
    return lVar1;
  }
  FUN_0010fc00(param_1,param_2);
  return *(long *)(*(long *)(param_1 + 0x18) + -8 + *(long *)(param_1 + 0x20) * 8);
}


//===== FUN_0010ff30 @ 0010ff30 size=138 =====

void FUN_0010ff30(long param_1,long *param_2)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  long *plVar4;
  ulong uVar5;
  
  lVar1 = FUN_0010fea0();
  if ((int)param_2[1] == 0) {
    uVar5 = 0;
    uVar2 = 0;
  }
  else {
    uVar3 = 0;
    do {
      *(undefined1 *)(lVar1 + uVar3) = *(undefined1 *)(*param_2 + uVar3);
      uVar2 = *(uint *)(param_2 + 1);
      uVar5 = (ulong)uVar2;
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar5);
  }
  uVar3 = *(ulong *)(param_1 + 0x58);
  plVar4 = (long *)((uVar3 & 0xff) * 0x10 + *(long *)(*(long *)(param_1 + 0x30) + (uVar3 >> 8) * 8))
  ;
  *plVar4 = lVar1;
  plVar4[1] = CONCAT44(*(undefined4 *)((long)param_2 + 0xc),uVar2);
  *(ulong *)(param_1 + 0x58) = uVar3 + 1;
  *(long *)(param_1 + 0x60) = *(long *)(param_1 + 0x60) + uVar5;
  return;
}


//===== FUN_0010ffd0 @ 0010ffd0 size=532 =====

void FUN_0010ffd0(undefined4 param_1,long param_2,long param_3,ulong param_4)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  long *plVar6;
  
  if ((param_3 == 0) && (param_4 != 0)) {
    puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar2 = &PTR_FUN_00132da8;
    puVar2[1] = "../src_udic/marisa_u/keyset.cpp";
    puVar2[2] = 0x20000003d;
    puVar2[3] = 
    "../src_udic/marisa_u/keyset.cpp:61: MARISA_NULL_ERROR: (ptr == NULL) && (length != 0)";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  if (param_4 >> 0x20 != 0) {
    puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar2 = &PTR_FUN_00132da8;
    puVar2[1] = "../src_udic/marisa_u/keyset.cpp";
    puVar2[2] = 0x70000003e;
    puVar2[3] = "../src_udic/marisa_u/keyset.cpp:62: MARISA_SIZE_ERROR: length > MARISA_UINT32_MAX";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  lVar3 = FUN_0010fea0(param_2,param_4);
  if (param_4 == 0) goto LAB_0011013f;
  if (((ulong)(lVar3 - (param_3 + 1)) < 0xf) || (param_4 - 1 < 7)) {
    uVar4 = 0;
    do {
      *(undefined1 *)(lVar3 + uVar4) = *(undefined1 *)(param_3 + uVar4);
      uVar4 = uVar4 + 1;
    } while (param_4 != uVar4);
    goto LAB_0011013f;
  }
  if (param_4 - 1 < 0xf) {
    uVar5 = 0;
    uVar4 = param_4;
LAB_001100b3:
    *(undefined8 *)(lVar3 + uVar5) = *(undefined8 *)(param_3 + uVar5);
    uVar5 = uVar5 + (uVar4 & 0xfffffffffffffff8);
    if (uVar4 == (uVar4 & 0xfffffffffffffff8)) goto LAB_0011013f;
  }
  else {
    uVar4 = 0;
    do {
      uVar1 = ((undefined8 *)(param_3 + uVar4))[1];
      *(undefined8 *)(lVar3 + uVar4) = *(undefined8 *)(param_3 + uVar4);
      ((undefined8 *)(lVar3 + uVar4))[1] = uVar1;
      uVar4 = uVar4 + 0x10;
    } while ((param_4 & 0xfffffffffffffff0) != uVar4);
    uVar5 = param_4 & 0xfffffffffffffff0;
    if ((param_4 & 0xf) == 0) goto LAB_0011013f;
    uVar4 = param_4 - uVar5;
    if (6 < (param_4 - uVar5) - 1) goto LAB_001100b3;
  }
  *(undefined1 *)(lVar3 + uVar5) = *(undefined1 *)(param_3 + uVar5);
  if ((((uVar5 + 1 < param_4) &&
       (*(undefined1 *)(lVar3 + 1 + uVar5) = *(undefined1 *)(param_3 + 1 + uVar5),
       uVar5 + 2 < param_4)) &&
      (*(undefined1 *)(lVar3 + 2 + uVar5) = *(undefined1 *)(param_3 + 2 + uVar5),
      uVar5 + 3 < param_4)) &&
     (((*(undefined1 *)(lVar3 + 3 + uVar5) = *(undefined1 *)(param_3 + 3 + uVar5),
       uVar5 + 4 < param_4 &&
       (*(undefined1 *)(lVar3 + 4 + uVar5) = *(undefined1 *)(param_3 + 4 + uVar5),
       uVar5 + 5 < param_4)) &&
      (*(undefined1 *)(lVar3 + 5 + uVar5) = *(undefined1 *)(param_3 + 5 + uVar5),
      uVar5 + 6 < param_4)))) {
    *(undefined1 *)(lVar3 + 6 + uVar5) = *(undefined1 *)(param_3 + 6 + uVar5);
  }
LAB_0011013f:
  uVar4 = *(ulong *)(param_2 + 0x58);
  plVar6 = (long *)((uVar4 & 0xff) * 0x10 + *(long *)(*(long *)(param_2 + 0x30) + (uVar4 >> 8) * 8))
  ;
  *plVar6 = lVar3;
  *(int *)(plVar6 + 1) = (int)param_4;
  *(undefined4 *)((long)plVar6 + 0xc) = param_1;
  *(long *)(param_2 + 0x60) = *(long *)(param_2 + 0x60) + param_4;
  *(ulong *)(param_2 + 0x58) = uVar4 + 1;
  return;
}


//===== FUN_001101b0 @ 001101b0 size=47 =====

void FUN_001101b0(undefined8 param_1,char *param_2)

{
  char cVar1;
  undefined8 *puVar2;
  long lVar3;
  
  if (param_2 == (char *)0x0) {
    puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
    puVar2[2] = 0x200000032;
    puVar2[3] = "../src_udic/marisa_u/keyset.cpp:50: MARISA_NULL_ERROR: str == NULL";
    *puVar2 = &PTR_FUN_00132da8;
    puVar2[1] = "../src_udic/marisa_u/keyset.cpp";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  lVar3 = 0;
  cVar1 = *param_2;
  while (cVar1 != '\0') {
    lVar3 = lVar3 + 1;
    cVar1 = param_2[lVar3];
  }
  FUN_0010ffd0();
  return;
}


//===== FUN_001101e0 @ 001101e0 size=169 =====

void FUN_001101e0(long param_1,long *param_2,undefined1 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  ulong uVar4;
  long *plVar5;
  undefined1 *puVar6;
  
  if (*(ulong *)(param_1 + 0x58) >> 8 == *(ulong *)(param_1 + 0x38)) {
    FUN_0010f700();
  }
  puVar3 = (undefined1 *)FUN_0010fea0(param_1,(ulong)*(uint *)(param_2 + 1) + 1);
  puVar6 = puVar3;
  if ((int)param_2[1] != 0) {
    uVar4 = 0;
    do {
      puVar3[uVar4] = *(undefined1 *)(*param_2 + uVar4);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(param_2 + 1));
    puVar6 = puVar3 + *(uint *)(param_2 + 1);
  }
  *puVar6 = param_3;
  uVar4 = *(ulong *)(param_1 + 0x58);
  plVar5 = (long *)((uVar4 & 0xff) * 0x10 + *(long *)(*(long *)(param_1 + 0x30) + (uVar4 >> 8) * 8))
  ;
  uVar1 = *(uint *)(param_2 + 1);
  *plVar5 = (long)puVar3;
  uVar2 = *(undefined4 *)((long)param_2 + 0xc);
  *(uint *)(plVar5 + 1) = uVar1;
  *(undefined4 *)((long)plVar5 + 0xc) = uVar2;
  *(long *)(param_1 + 0x60) = *(long *)(param_1 + 0x60) + (ulong)uVar1;
  *(ulong *)(param_1 + 0x58) = uVar4 + 1;
  return;
}


//===== FUN_001102a0 @ 001102a0 size=86 =====

void FUN_001102a0(long *param_1)

{
  undefined8 *puVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *param_1;
  if (lVar3 == 0) {
    return;
  }
  lVar2 = lVar3 + *(long *)(lVar3 + -8) * 8;
  while (lVar3 != lVar2) {
    while( true ) {
      puVar1 = (undefined8 *)(lVar2 + -8);
      lVar2 = lVar2 + -8;
      if ((void *)*puVar1 == (void *)0x0) break;
      operator_delete__((void *)*puVar1);
      lVar3 = *param_1;
      if (lVar2 == lVar3) goto LAB_001102e0;
    }
  }
LAB_001102e0:
  operator_delete__((void *)(lVar3 + -8));
  return;
}


//===== FUN_00110300 @ 00110300 size=31 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00110300(undefined8 *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar2 = _UNK_001290b8;
  uVar1 = _DAT_001290b0;
  *(undefined4 *)(param_1 + 4) = 0xffffffff;
  *param_1 = uVar1;
  param_1[1] = uVar2;
  *(undefined1 (*) [16])(param_1 + 2) = (undefined1  [16])0x0;
  return;
}


//===== FUN_00110320 @ 00110320 size=44 =====

void FUN_00110320(long param_1)

{
  if (*(void **)(param_1 + 8) != (void *)0xffffffffffffffff) {
    munmap(*(void **)(param_1 + 8),*(size_t *)(param_1 + 0x18));
  }
  if (*(int *)(param_1 + 0x20) == -1) {
    return;
  }
  close(*(int *)(param_1 + 0x20));
  return;
}


//===== FUN_00110350 @ 00110350 size=12 =====

bool FUN_00110350(long *param_1)

{
  return *param_1 != 0;
}


//===== FUN_00110360 @ 00110360 size=77 =====

void FUN_00110360(undefined8 *param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar2 = *param_1;
  *param_1 = *param_2;
  *param_2 = uVar2;
  uVar2 = param_1[2];
  param_1[2] = param_2[2];
  param_2[2] = uVar2;
  uVar2 = param_1[1];
  param_1[1] = param_2[1];
  param_2[1] = uVar2;
  uVar2 = param_1[3];
  param_1[3] = param_2[3];
  param_2[3] = uVar2;
  uVar1 = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_2 + 4) = uVar1;
  return;
}


//===== FUN_001103b0 @ 001103b0 size=89 =====

void FUN_001103b0(undefined8 param_1)

{
  long in_FS_OFFSET;
  undefined1 auStack_48 [40];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_00110300(auStack_48);
  FUN_00110360(auStack_48,param_1);
  FUN_00110320(auStack_48);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_00110420 @ 00110420 size=170 =====

long FUN_00110420(long *param_1,ulong param_2)

{
  long lVar1;
  char cVar2;
  undefined8 *puVar3;
  
  cVar2 = FUN_00110350();
  if (cVar2 == '\0') {
    puVar3 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar3 = &PTR_FUN_00132da8;
    puVar3[1] = "../src_udic/marisa_u/grimoire/io/mapper.cpp";
    puVar3[2] = 0x100000063;
    puVar3[3] = "../src_udic/marisa_u/grimoire/io/mapper.cpp:99: MARISA_STATE_ERROR: !is_open()";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar3,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  if (param_2 <= (ulong)param_1[2]) {
    lVar1 = *param_1;
    param_1[2] = param_1[2] - param_2;
    *param_1 = lVar1 + param_2;
    return lVar1;
  }
  puVar3 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar3 = &PTR_FUN_00132da8;
  puVar3[1] = "../src_udic/marisa_u/grimoire/io/mapper.cpp";
  puVar3[2] = 0x900000064;
  puVar3[3] = "../src_udic/marisa_u/grimoire/io/mapper.cpp:100: MARISA_IO_ERROR: size > avail_";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar3,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00110490 @ 00110490 size=159 =====

void FUN_00110490(long param_1,ulong param_2)

{
  char cVar1;
  undefined8 *puVar2;
  
  cVar1 = FUN_00110350();
  if (cVar1 == '\0') {
    puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar2 = &PTR_FUN_00132da8;
    puVar2[1] = "../src_udic/marisa_u/grimoire/io/mapper.cpp";
    puVar2[2] = 0x100000047;
    puVar2[3] = "../src_udic/marisa_u/grimoire/io/mapper.cpp:71: MARISA_STATE_ERROR: !is_open()";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  if (param_2 <= *(ulong *)(param_1 + 0x10)) {
    FUN_00110420(param_1,param_2);
    return;
  }
  puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar2 = &PTR_FUN_00132da8;
  puVar2[1] = "../src_udic/marisa_u/grimoire/io/mapper.cpp";
  puVar2[2] = 0x900000048;
  puVar2[3] = "../src_udic/marisa_u/grimoire/io/mapper.cpp:72: MARISA_IO_ERROR: size > avail_";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_001104f0 @ 001104f0 size=342 =====

void FUN_001104f0(undefined8 *param_1,char *param_2)

{
  int iVar1;
  undefined8 *puVar2;
  void *pvVar3;
  long in_FS_OFFSET;
  stat64 local_b8;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = stat64(param_2,&local_b8);
  if (iVar1 != 0) {
    puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar2 = &PTR_FUN_00132da8;
    puVar2[1] = "../src_udic/marisa_u/grimoire/io/mapper.cpp";
    puVar2[2] = 0x90000008d;
    puVar2[3] = 
    "../src_udic/marisa_u/grimoire/io/mapper.cpp:141: MARISA_IO_ERROR: ::stat(filename, &st) != 0";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  param_1[3] = local_b8.st_size;
  iVar1 = open64(param_2,0);
  *(int *)(param_1 + 4) = iVar1;
  if (iVar1 == -1) {
    puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar2 = &PTR_FUN_00132da8;
    puVar2[1] = "../src_udic/marisa_u/grimoire/io/mapper.cpp";
    puVar2[2] = 0x900000092;
    puVar2[3] = "../src_udic/marisa_u/grimoire/io/mapper.cpp:146: MARISA_IO_ERROR: fd_ == -1";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  pvVar3 = mmap64((void *)0x0,param_1[3],1,1,iVar1,0);
  param_1[1] = pvVar3;
  if (pvVar3 == (void *)0xffffffffffffffff) {
    puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar2 = &PTR_FUN_00132da8;
    puVar2[1] = "../src_udic/marisa_u/grimoire/io/mapper.cpp";
    puVar2[2] = 0x900000095;
    puVar2[3] = 
    "../src_udic/marisa_u/grimoire/io/mapper.cpp:149: MARISA_IO_ERROR: origin_ == MAP_FAILED";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  *param_1 = pvVar3;
  param_1[2] = param_1[3];
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_001105d0 @ 001105d0 size=116 =====

void FUN_001105d0(undefined8 param_1,long param_2)

{
  undefined8 *puVar1;
  long in_FS_OFFSET;
  undefined1 auStack_48 [40];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_2 == 0) {
    puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
    puVar1[2] = 0x200000037;
    puVar1[3] = 
    "../src_udic/marisa_u/grimoire/io/mapper.cpp:55: MARISA_NULL_ERROR: filename == NULL";
    *puVar1 = &PTR_FUN_00132da8;
    puVar1[1] = "../src_udic/marisa_u/grimoire/io/mapper.cpp";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  FUN_00110300(auStack_48);
  FUN_001104f0(auStack_48,param_2);
  FUN_00110360(param_1,auStack_48);
  FUN_00110320(auStack_48);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_00110650 @ 00110650 size=12 =====

void FUN_00110650(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  *param_1 = param_2;
  param_1[2] = param_3;
  return;
}


//===== FUN_00110660 @ 00110660 size=131 =====

void FUN_00110660(undefined8 param_1,long param_2,long param_3)

{
  undefined8 *puVar1;
  long in_FS_OFFSET;
  undefined1 auStack_58 [40];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if ((param_2 == 0) && (param_3 != 0)) {
    puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
    puVar1[2] = 0x20000003f;
    puVar1[3] = 
    "../src_udic/marisa_u/grimoire/io/mapper.cpp:63: MARISA_NULL_ERROR: (ptr == NULL) && (size != 0)"
    ;
    *puVar1 = &PTR_FUN_00132da8;
    puVar1[1] = "../src_udic/marisa_u/grimoire/io/mapper.cpp";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  FUN_00110300(auStack_58);
  FUN_00110650(auStack_58,param_2,param_3);
  FUN_00110360(param_1,auStack_58);
  FUN_00110320(auStack_58);
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_001106f0 @ 001106f0 size=31 =====

void FUN_001106f0(undefined8 *param_1)

{
  *param_1 = 0;
  *(undefined4 *)(param_1 + 1) = 0xffffffff;
  param_1[2] = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  return;
}


//===== FUN_00110710 @ 00110710 size=28 =====

void FUN_00110710(undefined8 *param_1)

{
  if (*(char *)(param_1 + 3) == '\0') {
    return;
  }
  fclose((FILE *)*param_1);
  return;
}


//===== FUN_00110740 @ 00110740 size=59 =====

void FUN_00110740(undefined8 *param_1,undefined8 *param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = *param_1;
  *param_1 = *param_2;
  *param_2 = uVar3;
  uVar2 = *(undefined4 *)(param_1 + 1);
  *(undefined4 *)(param_1 + 1) = *(undefined4 *)(param_2 + 1);
  *(undefined4 *)(param_2 + 1) = uVar2;
  uVar3 = param_1[2];
  param_1[2] = param_2[2];
  param_2[2] = uVar3;
  uVar1 = *(undefined1 *)(param_1 + 3);
  *(undefined1 *)(param_1 + 3) = *(undefined1 *)(param_2 + 3);
  *(undefined1 *)(param_2 + 3) = uVar1;
  return;
}


//===== FUN_00110780 @ 00110780 size=89 =====

void FUN_00110780(undefined8 param_1)

{
  long in_FS_OFFSET;
  undefined1 auStack_48 [40];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_001106f0(auStack_48);
  FUN_00110740(auStack_48,param_1);
  FUN_00110710(auStack_48);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_001107f0 @ 001107f0 size=31 =====

bool FUN_001107f0(long *param_1)

{
  if ((*param_1 == 0) && ((int)param_1[1] == -1)) {
    return param_1[2] != 0;
  }
  return true;
}


//===== FUN_00110810 @ 00110810 size=41 =====

void FUN_00110810(undefined8 *param_1,char *param_2)

{
  undefined8 *puVar1;
  FILE *pFVar2;
  
  pFVar2 = fopen64(param_2,"rb");
  if (pFVar2 != (FILE *)0x0) {
    *param_1 = pFVar2;
    *(undefined1 *)(param_1 + 3) = 1;
    return;
  }
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x90000005e;
  puVar1[3] = "../src_udic/marisa_u/grimoire/io/reader.cpp:94: MARISA_IO_ERROR: file == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/io/reader.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00110840 @ 00110840 size=116 =====

void FUN_00110840(undefined8 param_1,long param_2)

{
  undefined8 *puVar1;
  long in_FS_OFFSET;
  undefined1 auStack_48 [40];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_2 == 0) {
    puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
    puVar1[2] = 0x20000001b;
    puVar1[3] = 
    "../src_udic/marisa_u/grimoire/io/reader.cpp:27: MARISA_NULL_ERROR: filename == NULL";
    *puVar1 = &PTR_FUN_00132da8;
    puVar1[1] = "../src_udic/marisa_u/grimoire/io/reader.cpp";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  FUN_001106f0(auStack_48);
  FUN_00110810(auStack_48,param_2);
  FUN_00110740(param_1,auStack_48);
  FUN_00110710(auStack_48);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_001108c0 @ 001108c0 size=8 =====

void FUN_001108c0(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return;
}


//===== FUN_001108d0 @ 001108d0 size=116 =====

void FUN_001108d0(undefined8 param_1,long param_2)

{
  undefined8 *puVar1;
  long in_FS_OFFSET;
  undefined1 auStack_48 [40];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_2 == 0) {
    puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
    puVar1[2] = 0x200000023;
    puVar1[3] = "../src_udic/marisa_u/grimoire/io/reader.cpp:35: MARISA_NULL_ERROR: file == NULL";
    *puVar1 = &PTR_FUN_00132da8;
    puVar1[1] = "../src_udic/marisa_u/grimoire/io/reader.cpp";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  FUN_001106f0(auStack_48);
  FUN_001108c0(auStack_48,param_2);
  FUN_00110740(param_1,auStack_48);
  FUN_00110710(auStack_48);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_00110950 @ 00110950 size=8 =====

void FUN_00110950(long param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 8) = param_2;
  return;
}


//===== FUN_00110960 @ 00110960 size=116 =====

void FUN_00110960(undefined8 param_1,int param_2)

{
  undefined8 *puVar1;
  long in_FS_OFFSET;
  undefined1 auStack_48 [40];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_2 == -1) {
    puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
    puVar1[2] = 0x50000002b;
    puVar1[3] = "../src_udic/marisa_u/grimoire/io/reader.cpp:43: MARISA_CODE_ERROR: fd == -1";
    *puVar1 = &PTR_FUN_00132da8;
    puVar1[1] = "../src_udic/marisa_u/grimoire/io/reader.cpp";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  FUN_001106f0(auStack_48);
  FUN_00110950(auStack_48,param_2);
  FUN_00110740(param_1,auStack_48);
  FUN_00110710(auStack_48);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_001109e0 @ 001109e0 size=9 =====

void FUN_001109e0(long param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 0x10) = param_2;
  return;
}


//===== FUN_001109f0 @ 001109f0 size=107 =====

void FUN_001109f0(undefined8 param_1,undefined8 param_2)

{
  long in_FS_OFFSET;
  undefined1 auStack_48 [40];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_001106f0(auStack_48);
  FUN_001109e0(auStack_48,param_2);
  FUN_00110740(param_1,auStack_48);
  FUN_00110710(auStack_48);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_00110a70 @ 00110a70 size=245 =====

void FUN_00110a70(undefined8 *param_1,void *param_2,size_t param_3)

{
  char cVar1;
  undefined8 *puVar2;
  ssize_t sVar3;
  size_t sVar4;
  long *plVar5;
  int __fd;
  
  cVar1 = FUN_001107f0();
  if (cVar1 == '\0') {
    puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar2 = &PTR_FUN_00132da8;
    puVar2[1] = "../src_udic/marisa_u/grimoire/io/reader.cpp";
    puVar2[2] = 0x100000071;
    puVar2[3] = "../src_udic/marisa_u/grimoire/io/reader.cpp:113: MARISA_STATE_ERROR: !is_open()";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  if (param_3 != 0) {
    __fd = *(int *)(param_1 + 1);
    if (__fd == -1) {
      if ((FILE *)*param_1 != (FILE *)0x0) {
        sVar4 = fread(param_2,1,param_3,(FILE *)*param_1);
        if (param_3 != sVar4) {
          puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
          *puVar2 = &PTR_FUN_00132da8;
          puVar2[1] = "../src_udic/marisa_u/grimoire/io/reader.cpp";
          puVar2[2] = 0x900000086;
          puVar2[3] = 
          "../src_udic/marisa_u/grimoire/io/reader.cpp:134: MARISA_IO_ERROR: ::fread(buf, 1, size, file_) != size"
          ;
                    /* WARNING: Subroutine does not return */
          __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
        }
        return;
      }
      if (((char *)param_1[2] != (char *)0x0) &&
         (plVar5 = (long *)std::istream::read((char *)param_1[2],(long)param_2),
         (*(byte *)((long)plVar5 + *(long *)(*plVar5 + -0x18) + 0x20) & 5) != 0)) {
        FUN_00105fa9();
        return;
      }
    }
    else {
      while( true ) {
        sVar4 = 0x7fffffffffffffff;
        if (param_3 < 0x7fffffffffffffff) {
          sVar4 = param_3;
        }
        sVar3 = read(__fd,param_2,sVar4);
        if (sVar3 < 1) {
          puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
          *puVar2 = &PTR_FUN_00132da8;
          puVar2[1] = "../src_udic/marisa_u/grimoire/io/reader.cpp";
          puVar2[2] = 0x900000081;
          puVar2[3] = 
          "../src_udic/marisa_u/grimoire/io/reader.cpp:129: MARISA_IO_ERROR: size_read <= 0";
                    /* WARNING: Subroutine does not return */
          __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
        }
        param_2 = (void *)((long)param_2 + sVar3);
        param_3 = param_3 - sVar3;
        if (param_3 == 0) break;
        __fd = *(int *)(param_1 + 1);
      }
    }
  }
  return;
}


//===== FUN_00110b80 @ 00110b80 size=157 =====

void FUN_00110b80(undefined8 param_1,ulong param_2)

{
  char cVar1;
  undefined8 *puVar2;
  ulong uVar3;
  long in_FS_OFFSET;
  undefined1 auStack_438 [1032];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  cVar1 = FUN_001107f0();
  if (cVar1 == '\0') {
    puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
    puVar2[2] = 0x100000044;
    puVar2[3] = "../src_udic/marisa_u/grimoire/io/reader.cpp:68: MARISA_STATE_ERROR: !is_open()";
    *puVar2 = &PTR_FUN_00132da8;
    puVar2[1] = "../src_udic/marisa_u/grimoire/io/reader.cpp";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  if (param_2 != 0) {
    if (param_2 < 0x11) {
      FUN_00110a70(param_1,auStack_438,param_2);
    }
    else {
      do {
        uVar3 = 0x400;
        if (param_2 < 0x401) {
          uVar3 = param_2;
        }
        FUN_00110a70(param_1,auStack_438,uVar3);
        param_2 = param_2 - uVar3;
      } while (param_2 != 0);
    }
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_00110c30 @ 00110c30 size=31 =====

void FUN_00110c30(undefined8 *param_1)

{
  *param_1 = 0;
  *(undefined4 *)(param_1 + 1) = 0xffffffff;
  param_1[2] = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  return;
}


//===== FUN_00110c50 @ 00110c50 size=28 =====

void FUN_00110c50(undefined8 *param_1)

{
  if (*(char *)(param_1 + 3) == '\0') {
    return;
  }
  fclose((FILE *)*param_1);
  return;
}


//===== FUN_00110c80 @ 00110c80 size=59 =====

void FUN_00110c80(undefined8 *param_1,undefined8 *param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = *param_1;
  *param_1 = *param_2;
  *param_2 = uVar3;
  uVar2 = *(undefined4 *)(param_1 + 1);
  *(undefined4 *)(param_1 + 1) = *(undefined4 *)(param_2 + 1);
  *(undefined4 *)(param_2 + 1) = uVar2;
  uVar3 = param_1[2];
  param_1[2] = param_2[2];
  param_2[2] = uVar3;
  uVar1 = *(undefined1 *)(param_1 + 3);
  *(undefined1 *)(param_1 + 3) = *(undefined1 *)(param_2 + 3);
  *(undefined1 *)(param_2 + 3) = uVar1;
  return;
}


//===== FUN_00110cc0 @ 00110cc0 size=89 =====

void FUN_00110cc0(undefined8 param_1)

{
  long in_FS_OFFSET;
  undefined1 auStack_48 [40];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_00110c30(auStack_48);
  FUN_00110c80(auStack_48,param_1);
  FUN_00110c50(auStack_48);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_00110d30 @ 00110d30 size=31 =====

bool FUN_00110d30(long *param_1)

{
  if ((*param_1 == 0) && ((int)param_1[1] == -1)) {
    return param_1[2] != 0;
  }
  return true;
}


//===== FUN_00110d50 @ 00110d50 size=41 =====

void FUN_00110d50(undefined8 *param_1,char *param_2)

{
  undefined8 *puVar1;
  FILE *pFVar2;
  
  pFVar2 = fopen64(param_2,"wb");
  if (pFVar2 != (FILE *)0x0) {
    *param_1 = pFVar2;
    *(undefined1 *)(param_1 + 3) = 1;
    return;
  }
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0x90000005e;
  puVar1[3] = "../src_udic/marisa_u/grimoire/io/writer.cpp:94: MARISA_IO_ERROR: file == NULL";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/io/writer.cpp";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00110d80 @ 00110d80 size=116 =====

void FUN_00110d80(undefined8 param_1,long param_2)

{
  undefined8 *puVar1;
  long in_FS_OFFSET;
  undefined1 auStack_48 [40];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_2 == 0) {
    puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
    puVar1[2] = 0x20000001b;
    puVar1[3] = 
    "../src_udic/marisa_u/grimoire/io/writer.cpp:27: MARISA_NULL_ERROR: filename == NULL";
    *puVar1 = &PTR_FUN_00132da8;
    puVar1[1] = "../src_udic/marisa_u/grimoire/io/writer.cpp";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  FUN_00110c30(auStack_48);
  FUN_00110d50(auStack_48,param_2);
  FUN_00110c80(param_1,auStack_48);
  FUN_00110c50(auStack_48);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_00110e00 @ 00110e00 size=8 =====

void FUN_00110e00(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return;
}


//===== FUN_00110e10 @ 00110e10 size=116 =====

void FUN_00110e10(undefined8 param_1,long param_2)

{
  undefined8 *puVar1;
  long in_FS_OFFSET;
  undefined1 auStack_48 [40];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_2 == 0) {
    puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
    puVar1[2] = 0x200000023;
    puVar1[3] = "../src_udic/marisa_u/grimoire/io/writer.cpp:35: MARISA_NULL_ERROR: file == NULL";
    *puVar1 = &PTR_FUN_00132da8;
    puVar1[1] = "../src_udic/marisa_u/grimoire/io/writer.cpp";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  FUN_00110c30(auStack_48);
  FUN_00110e00(auStack_48,param_2);
  FUN_00110c80(param_1,auStack_48);
  FUN_00110c50(auStack_48);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_00110e90 @ 00110e90 size=8 =====

void FUN_00110e90(long param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 8) = param_2;
  return;
}


//===== FUN_00110ea0 @ 00110ea0 size=116 =====

void FUN_00110ea0(undefined8 param_1,int param_2)

{
  undefined8 *puVar1;
  long in_FS_OFFSET;
  undefined1 auStack_48 [40];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_2 == -1) {
    puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
    puVar1[2] = 0x50000002b;
    puVar1[3] = "../src_udic/marisa_u/grimoire/io/writer.cpp:43: MARISA_CODE_ERROR: fd == -1";
    *puVar1 = &PTR_FUN_00132da8;
    puVar1[1] = "../src_udic/marisa_u/grimoire/io/writer.cpp";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  FUN_00110c30(auStack_48);
  FUN_00110e90(auStack_48,param_2);
  FUN_00110c80(param_1,auStack_48);
  FUN_00110c50(auStack_48);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_00110f20 @ 00110f20 size=9 =====

void FUN_00110f20(long param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 0x10) = param_2;
  return;
}


//===== FUN_00110f30 @ 00110f30 size=107 =====

void FUN_00110f30(undefined8 param_1,undefined8 param_2)

{
  long in_FS_OFFSET;
  undefined1 auStack_48 [40];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_00110c30(auStack_48);
  FUN_00110f20(auStack_48,param_2);
  FUN_00110c80(param_1,auStack_48);
  FUN_00110c50(auStack_48);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_00110fb0 @ 00110fb0 size=391 =====

void FUN_00110fb0(undefined8 *param_1,void *param_2,size_t param_3)

{
  char cVar1;
  int iVar2;
  undefined8 *puVar3;
  ssize_t sVar4;
  size_t sVar5;
  long *plVar6;
  
  cVar1 = FUN_00110d30();
  if (cVar1 == '\0') {
    puVar3 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar3 = &PTR_FUN_00132da8;
    puVar3[1] = "../src_udic/marisa_u/grimoire/io/writer.cpp";
    puVar3[2] = 0x100000071;
    puVar3[3] = "../src_udic/marisa_u/grimoire/io/writer.cpp:113: MARISA_STATE_ERROR: !is_open()";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar3,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  if (param_3 != 0) {
    iVar2 = *(int *)(param_1 + 1);
    if (iVar2 == -1) {
      if ((FILE *)*param_1 != (FILE *)0x0) {
        sVar5 = fwrite(param_2,1,param_3,(FILE *)*param_1);
        if (param_3 != sVar5) {
          puVar3 = (undefined8 *)__cxa_allocate_exception(0x20);
          *puVar3 = &PTR_FUN_00132da8;
          puVar3[1] = "../src_udic/marisa_u/grimoire/io/writer.cpp";
          puVar3[2] = 0x900000086;
          puVar3[3] = 
          "../src_udic/marisa_u/grimoire/io/writer.cpp:134: MARISA_IO_ERROR: ::fwrite(data, 1, size, file_) != size"
          ;
                    /* WARNING: Subroutine does not return */
          __cxa_throw(puVar3,&PTR_vtable_00132d80,FUN_0010e6a0);
        }
        iVar2 = fflush((FILE *)*param_1);
        if (iVar2 != 0) {
          puVar3 = (undefined8 *)__cxa_allocate_exception(0x20);
          *puVar3 = &PTR_FUN_00132da8;
          puVar3[1] = "../src_udic/marisa_u/grimoire/io/writer.cpp";
          puVar3[2] = 0x900000087;
          puVar3[3] = 
          "../src_udic/marisa_u/grimoire/io/writer.cpp:135: MARISA_IO_ERROR: ::fflush(file_) != 0";
                    /* WARNING: Subroutine does not return */
          __cxa_throw(puVar3,&PTR_vtable_00132d80,FUN_0010e6a0);
        }
        return;
      }
      if (((char *)param_1[2] != (char *)0x0) &&
         (plVar6 = (long *)std::ostream::write((char *)param_1[2],(long)param_2),
         (*(byte *)((long)plVar6 + *(long *)(*plVar6 + -0x18) + 0x20) & 5) != 0)) {
        FUN_001063bf();
        return;
      }
    }
    else {
      while( true ) {
        sVar5 = 0x7fffffffffffffff;
        if (param_3 < 0x7fffffffffffffff) {
          sVar5 = param_3;
        }
        sVar4 = write(iVar2,param_2,sVar5);
        if (sVar4 < 1) {
          puVar3 = (undefined8 *)__cxa_allocate_exception(0x20);
          *puVar3 = &PTR_FUN_00132da8;
          puVar3[1] = "../src_udic/marisa_u/grimoire/io/writer.cpp";
          puVar3[2] = 0x900000081;
          puVar3[3] = 
          "../src_udic/marisa_u/grimoire/io/writer.cpp:129: MARISA_IO_ERROR: size_written <= 0";
                    /* WARNING: Subroutine does not return */
          __cxa_throw(puVar3,&PTR_vtable_00132d80,FUN_0010e6a0);
        }
        param_2 = (void *)((long)param_2 + sVar4);
        param_3 = param_3 - sVar4;
        if (param_3 == 0) break;
        iVar2 = *(int *)(param_1 + 1);
      }
    }
  }
  return;
}


//===== FUN_001110d0 @ 001110d0 size=181 =====

void FUN_001110d0(undefined8 param_1,ulong param_2)

{
  char cVar1;
  undefined8 *puVar2;
  long lVar3;
  ulong uVar4;
  long in_FS_OFFSET;
  byte bVar5;
  undefined1 local_438 [16];
  undefined8 local_428 [127];
  long local_30;
  
  bVar5 = 0;
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  cVar1 = FUN_00110d30();
  if (cVar1 == '\0') {
    puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
    puVar2[2] = 0x100000044;
    puVar2[3] = "../src_udic/marisa_u/grimoire/io/writer.cpp:68: MARISA_STATE_ERROR: !is_open()";
    *puVar2 = &PTR_FUN_00132da8;
    puVar2[1] = "../src_udic/marisa_u/grimoire/io/writer.cpp";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  if (param_2 != 0) {
    local_438 = (undefined1  [16])0x0;
    if (param_2 < 0x11) {
      FUN_00110fb0(param_1,local_438,param_2);
    }
    else {
      puVar2 = local_428;
      for (lVar3 = 0x7e; lVar3 != 0; lVar3 = lVar3 + -1) {
        *puVar2 = 0;
        puVar2 = puVar2 + (ulong)bVar5 * -2 + 1;
      }
      do {
        uVar4 = 0x400;
        if (param_2 < 0x401) {
          uVar4 = param_2;
        }
        FUN_00110fb0(param_1,local_438,uVar4);
        param_2 = param_2 - uVar4;
      } while (param_2 != 0);
    }
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_00111190 @ 00111190 size=366 =====

undefined8 * FUN_00111190(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  
  if (param_1 != param_2) {
    if (param_2 == param_3) {
      return param_1;
    }
    lVar5 = (long)param_3 - (long)param_1;
    param_3 = (undefined8 *)(((long)param_3 - (long)param_2) + (long)param_1);
    lVar5 = lVar5 >> 4;
    lVar10 = (long)param_2 - (long)param_1 >> 4;
    puVar6 = param_2;
    if (lVar10 == lVar5 - lVar10) {
      do {
        uVar4 = puVar6[1];
        uVar2 = *param_1;
        puVar7 = param_1 + 2;
        uVar3 = *(undefined4 *)(param_1 + 1);
        uVar1 = *(undefined4 *)((long)param_1 + 0xc);
        *param_1 = *puVar6;
        param_1[1] = uVar4;
        *puVar6 = uVar2;
        *(undefined4 *)(puVar6 + 1) = uVar3;
        *(undefined4 *)((long)puVar6 + 0xc) = uVar1;
        puVar6 = puVar6 + 2;
        param_1 = puVar7;
      } while (param_2 != puVar7);
      return param_2;
    }
    lVar11 = lVar5 - lVar10;
    lVar9 = lVar10;
    if (lVar11 <= lVar10) goto LAB_0011124f;
    while( true ) {
      if (0 < lVar11) {
        lVar10 = 0;
        puVar6 = param_1 + lVar9 * 2;
        puVar7 = param_1;
        do {
          uVar2 = *puVar7;
          uVar3 = *(undefined4 *)(puVar7 + 1);
          lVar10 = lVar10 + 1;
          uVar4 = puVar6[1];
          uVar1 = *(undefined4 *)((long)puVar7 + 0xc);
          *puVar7 = *puVar6;
          puVar7[1] = uVar4;
          *puVar6 = uVar2;
          *(undefined4 *)(puVar6 + 1) = uVar3;
          *(undefined4 *)((long)puVar6 + 0xc) = uVar1;
          puVar6 = puVar6 + 2;
          puVar7 = puVar7 + 2;
        } while (lVar11 != lVar10);
        param_1 = param_1 + lVar11 * 2;
      }
      if (lVar5 % lVar9 == 0) break;
      lVar10 = lVar9 - lVar5 % lVar9;
      lVar5 = lVar9;
      while (lVar11 = lVar5 - lVar10, lVar9 = lVar10, lVar11 <= lVar10) {
LAB_0011124f:
        puVar6 = param_1 + lVar5 * 2;
        param_1 = puVar6 + lVar11 * -2;
        if (0 < lVar10) {
          lVar9 = 0;
          puVar7 = param_1;
          do {
            uVar3 = *(undefined4 *)(puVar7 + -1);
            uVar1 = *(undefined4 *)((long)puVar7 + -4);
            lVar9 = lVar9 + 1;
            puVar8 = puVar7 + -2;
            uVar2 = *puVar8;
            uVar4 = puVar6[-1];
            *puVar8 = puVar6[-2];
            puVar7[-1] = uVar4;
            *(undefined4 *)(puVar6 + -1) = uVar3;
            puVar6[-2] = uVar2;
            *(undefined4 *)((long)puVar6 + -4) = uVar1;
            puVar6 = puVar6 + -2;
            puVar7 = puVar8;
          } while (lVar10 != lVar9);
          param_1 = param_1 + lVar10 * -2;
        }
        lVar10 = lVar5 % lVar11;
        lVar5 = lVar11;
        if (lVar10 == 0) {
          return param_3;
        }
      }
    }
  }
  return param_3;
}


//===== FUN_00111300 @ 00111300 size=448 =====

void FUN_00111300(undefined8 *param_1,undefined8 *param_2,long param_3,long param_4,long param_5)

{
  float *pfVar1;
  float fVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  long lVar11;
  
  if ((param_5 != 0) && (param_4 != 0)) {
    if (param_4 + param_5 != 2) {
      puVar8 = param_2;
      if (param_4 <= param_5) goto LAB_00111411;
      do {
        lVar11 = param_4 / 2;
        lVar6 = param_3 - (long)puVar8 >> 4;
        puVar10 = param_1 + lVar11 * 2;
        param_2 = puVar8;
        while (lVar7 = lVar6, 0 < lVar6) {
          while (lVar6 = lVar7 >> 1, fVar2 = *(float *)((long)param_2 + lVar6 * 0x10 + 0xc),
                *(float *)((long)puVar10 + 0xc) <= fVar2 && fVar2 != *(float *)((long)puVar10 + 0xc)
                ) {
            param_2 = param_2 + lVar6 * 2 + 2;
            lVar7 = (lVar7 - lVar6) + -1;
            if (lVar7 < 1) goto LAB_001113a5;
          }
        }
LAB_001113a5:
        lVar6 = (long)param_2 - (long)puVar8 >> 4;
        puVar9 = param_1;
        while( true ) {
          param_5 = param_5 - lVar6;
          param_1 = (undefined8 *)FUN_00111190(puVar10,puVar8,param_2);
          FUN_00111300(puVar9,puVar10,param_1,lVar11,lVar6);
          param_4 = param_4 - lVar11;
          if (param_4 == 0) {
            return;
          }
          if (param_5 == 0) {
            return;
          }
          if (param_5 + param_4 == 2) goto LAB_00111496;
          puVar8 = param_2;
          if (param_5 < param_4) break;
LAB_00111411:
          lVar11 = (long)puVar8 - (long)param_1 >> 4;
          lVar6 = param_5 / 2;
          param_2 = puVar8 + lVar6 * 2;
          puVar10 = param_1;
          while (lVar7 = lVar11, 0 < lVar11) {
            while (lVar11 = lVar7 >> 1, pfVar1 = (float *)((long)puVar10 + lVar11 * 0x10 + 0xc),
                  *(float *)((long)param_2 + 0xc) < *pfVar1 ||
                  *(float *)((long)param_2 + 0xc) == *pfVar1) {
              puVar10 = puVar10 + lVar11 * 2 + 2;
              lVar7 = (lVar7 - lVar11) + -1;
              if (lVar7 < 1) goto LAB_00111468;
            }
          }
LAB_00111468:
          lVar11 = (long)puVar10 - (long)param_1 >> 4;
          puVar9 = param_1;
        }
      } while( true );
    }
LAB_00111496:
    if (*(float *)((long)param_1 + 0xc) <= *(float *)((long)param_2 + 0xc) &&
        *(float *)((long)param_2 + 0xc) != *(float *)((long)param_1 + 0xc)) {
      uVar3 = *param_1;
      uVar4 = param_1[1];
      uVar5 = param_2[1];
      *param_1 = *param_2;
      param_1[1] = uVar5;
      *param_2 = uVar3;
      param_2[1] = uVar4;
    }
  }
  return;
}


//===== FUN_001114e0 @ 001114e0 size=213 =====

void FUN_001114e0(undefined8 *param_1,undefined8 *param_2)

{
  float fVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  
  puVar6 = param_1;
  if (param_1 == param_2) {
    return;
  }
  do {
    puVar6 = puVar6 + 2;
    if (param_2 == puVar6) {
      return;
    }
    while( true ) {
      fVar1 = *(float *)((long)puVar6 + 0xc);
      uVar3 = *puVar6;
      uVar2 = *(undefined4 *)(puVar6 + 1);
      if (*(float *)((long)param_1 + 0xc) <= fVar1 && fVar1 != *(float *)((long)param_1 + 0xc))
      break;
      puVar5 = puVar6;
      if (fVar1 < *(float *)((long)puVar6 + -4) || fVar1 == *(float *)((long)puVar6 + -4)) {
        *puVar6 = uVar3;
        *(undefined4 *)(puVar6 + 1) = uVar2;
        *(float *)((long)puVar6 + 0xc) = fVar1;
      }
      else {
        do {
          puVar4 = puVar5;
          puVar5 = puVar4 + -2;
          *puVar4 = *puVar5;
          puVar4[1] = puVar4[-1];
        } while (*(float *)((long)puVar4 + -0x14) <= fVar1 &&
                 fVar1 != *(float *)((long)puVar4 + -0x14));
        *puVar5 = uVar3;
        *(undefined4 *)(puVar4 + -1) = uVar2;
        *(float *)((long)puVar4 + -4) = fVar1;
      }
      puVar6 = puVar6 + 2;
      if (param_2 == puVar6) {
        return;
      }
    }
    if (param_1 != puVar6) {
      memmove(param_1 + 2,param_1,(long)puVar6 - (long)param_1);
    }
    *param_1 = uVar3;
    *(undefined4 *)(param_1 + 1) = uVar2;
    *(float *)((long)param_1 + 0xc) = fVar1;
  } while( true );
}


//===== FUN_001115d0 @ 001115d0 size=187 =====

void FUN_001115d0(uint *param_1,uint *param_2)

{
  undefined8 uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  bool bVar7;
  uint uVar8;
  uint uVar9;
  
  if ((param_1 != param_2) && (puVar5 = param_1 + 2, param_2 != puVar5)) {
    puVar6 = param_1 + 4;
    do {
      while( true ) {
        uVar1 = *(undefined8 *)puVar5;
        uVar8 = (uint)uVar1;
        uVar9 = (uint)((ulong)uVar1 >> 0x20);
        if ((*param_1 <= uVar8) && ((puVar3 = puVar5, *param_1 != uVar8 || (param_1[1] <= uVar9))))
        break;
        puVar3 = puVar5;
        if (0 < (long)puVar5 - (long)param_1) {
          do {
            puVar4 = puVar3 + -2;
            *(undefined8 *)puVar3 = *(undefined8 *)(puVar3 + -2);
            puVar3 = puVar4;
          } while ((uint *)((long)puVar5 - ((long)puVar5 - (long)param_1 & 0xfffffffffffffff8U)) !=
                   puVar4);
        }
        *(undefined8 *)param_1 = uVar1;
        puVar5 = puVar5 + 2;
        bVar7 = param_2 == puVar6;
        puVar6 = puVar6 + 2;
        if (bVar7) {
          return;
        }
      }
      while( true ) {
        uVar2 = puVar3[-2];
        if ((uVar2 <= uVar8) && ((uVar8 != uVar2 || (puVar3[-1] <= uVar9)))) break;
        *puVar3 = uVar2;
        puVar3[1] = puVar3[-1];
        puVar3 = puVar3 + -2;
      }
      *(undefined8 *)puVar3 = uVar1;
      puVar5 = puVar5 + 2;
      bVar7 = param_2 != puVar6;
      puVar6 = puVar6 + 2;
    } while (bVar7);
  }
  return;
}


//===== FUN_001116a0 @ 001116a0 size=422 =====

void FUN_001116a0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,long param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 *__dest;
  undefined8 *puVar4;
  undefined8 *puVar5;
  void *__dest_00;
  undefined8 *puVar6;
  
  lVar3 = (long)param_2 - (long)param_1 >> 4;
  if (param_4 * 2 <= lVar3) {
    puVar5 = param_1 + param_4 * 2;
    puVar4 = param_1;
    do {
      param_1 = puVar4 + param_4 * 4;
      __dest = param_3;
      puVar6 = puVar5;
      if (puVar4 != puVar5) {
        while (__dest = param_3, param_1 != puVar6) {
          if (*(float *)((long)puVar4 + 0xc) <= *(float *)((long)puVar6 + 0xc) &&
              *(float *)((long)puVar6 + 0xc) != *(float *)((long)puVar4 + 0xc)) {
            uVar1 = *puVar6;
            uVar2 = puVar6[1];
            puVar6 = puVar6 + 2;
            *param_3 = uVar1;
            param_3[1] = uVar2;
          }
          else {
            uVar1 = *puVar4;
            uVar2 = puVar4[1];
            puVar4 = puVar4 + 2;
            *param_3 = uVar1;
            param_3[1] = uVar2;
          }
          __dest = param_3 + 2;
          if (puVar4 == puVar5) break;
          param_3 = param_3 + 2;
        }
      }
      if (puVar5 != puVar4) {
        __dest = memmove(__dest,puVar4,(long)puVar5 - (long)puVar4);
      }
      __dest_00 = (void *)((long)__dest + ((long)puVar5 - (long)puVar4));
      if (param_1 != puVar6) {
        __dest_00 = memmove(__dest_00,puVar6,(long)param_1 - (long)puVar6);
      }
      param_3 = (undefined8 *)((long)__dest_00 + ((long)param_1 - (long)puVar6));
      puVar5 = puVar5 + param_4 * 4;
      lVar3 = (long)param_2 - (long)param_1 >> 4;
      puVar4 = param_1;
    } while (param_4 * 2 <= lVar3);
  }
  if (param_4 < lVar3) {
    lVar3 = param_4;
  }
  puVar6 = param_1 + lVar3 * 2;
  puVar5 = puVar6;
  puVar4 = param_3;
  if (puVar6 != param_1) {
    while (puVar4 = param_3, param_2 != puVar5) {
      if (*(float *)((long)param_1 + 0xc) <= *(float *)((long)puVar5 + 0xc) &&
          *(float *)((long)puVar5 + 0xc) != *(float *)((long)param_1 + 0xc)) {
        uVar1 = *puVar5;
        uVar2 = puVar5[1];
        puVar5 = puVar5 + 2;
        *param_3 = uVar1;
        param_3[1] = uVar2;
      }
      else {
        uVar1 = *param_1;
        uVar2 = param_1[1];
        param_1 = param_1 + 2;
        *param_3 = uVar1;
        param_3[1] = uVar2;
      }
      puVar4 = param_3 + 2;
      if (puVar6 == param_1) break;
      param_3 = param_3 + 2;
    }
  }
  if (puVar6 != param_1) {
    puVar4 = memmove(puVar4,param_1,(long)puVar6 - (long)param_1);
  }
  if (param_2 != puVar5) {
    memmove((void *)((long)puVar4 + ((long)puVar6 - (long)param_1)),puVar5,
            (long)param_2 - (long)puVar5);
    return;
  }
  return;
}


//===== FUN_00111860 @ 00111860 size=331 =====

void FUN_00111860(uint *param_1,ulong param_2,undefined8 param_3)

{
  long lVar1;
  uint uVar2;
  uint *puVar3;
  long lVar4;
  uint uVar5;
  long lVar6;
  
  if ((long)param_2 < 3) {
    puVar3 = param_1;
    if (((param_2 & 1) != 0) || (2 < param_2 - 1)) goto LAB_0011190e;
    lVar4 = 0;
  }
  else {
    lVar6 = 0;
    do {
      lVar1 = lVar6 + 1;
      lVar4 = lVar1 * 2;
      puVar3 = param_1 + lVar1 * 4;
      uVar5 = *puVar3;
      uVar2 = param_1[lVar1 * 4 + -2];
      if ((uVar5 < uVar2) || ((uVar5 == uVar2 && (puVar3[1] < (param_1 + lVar1 * 4 + -2)[1])))) {
        lVar4 = lVar4 + -1;
        puVar3 = param_1 + lVar4 * 2;
        uVar5 = *puVar3;
      }
      param_1[lVar6 * 2] = uVar5;
      (param_1 + lVar6 * 2)[1] = puVar3[1];
      lVar6 = lVar4;
    } while (lVar4 < (long)(param_2 - 1) / 2);
    if ((param_2 & 1) != 0) {
      lVar6 = lVar4 + -1 >> 1;
      goto LAB_001118f7;
    }
    lVar6 = lVar4 + -1 >> 1;
    if (lVar4 != (long)(param_2 - 2) >> 1) goto LAB_001118f7;
  }
  lVar6 = (lVar4 + 1) * 2;
  *puVar3 = param_1[(lVar4 + 1) * 4 + -2];
  puVar3[1] = (param_1 + (lVar4 + 1) * 4 + -2)[1];
  lVar4 = lVar6 + -2 >> 1;
  puVar3 = param_1 + lVar4 * 2;
  uVar2 = *puVar3;
  lVar1 = lVar6 + -1;
  while ((uVar2 < (uint)param_3 ||
         ((uVar2 == (uint)param_3 && (puVar3[1] < (uint)((ulong)param_3 >> 0x20)))))) {
    param_1[lVar1 * 2] = uVar2;
    (param_1 + lVar1 * 2)[1] = puVar3[1];
    lVar6 = (lVar4 + -1) / 2;
    if (lVar4 == 0) goto LAB_0011190e;
LAB_001118f7:
    puVar3 = param_1 + lVar6 * 2;
    uVar2 = *puVar3;
    lVar1 = lVar4;
    lVar4 = lVar6;
  }
  puVar3 = param_1 + lVar1 * 2;
LAB_0011190e:
  *(undefined8 *)puVar3 = param_3;
  return;
}


//===== FUN_001119c0 @ 001119c0 size=900 =====

void FUN_001119c0(uint *param_1,uint *param_2,long param_3)

{
  undefined8 uVar1;
  uint uVar2;
  long lVar3;
  uint *puVar4;
  uint *puVar5;
  long lVar6;
  uint uVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  uint uVar11;
  uint uVar12;
  long lVar13;
  uint *puVar14;
  
  lVar3 = (long)param_2 - (long)param_1;
  if (lVar3 < 0x81) {
    return;
  }
  do {
    if (param_3 == 0) {
      lVar3 = lVar3 >> 3;
      lVar10 = lVar3 + -2 >> 1;
      puVar14 = param_1 + lVar10 * 2;
      lVar13 = lVar10;
      do {
        uVar1 = *(undefined8 *)puVar14;
        lVar9 = lVar13;
        puVar5 = puVar14;
        while (lVar9 < lVar3 + -1 >> 1) {
          lVar6 = lVar9 + 1;
          lVar8 = lVar6 * 2;
          puVar5 = param_1 + lVar6 * 4;
          uVar7 = *puVar5;
          uVar2 = param_1[lVar6 * 4 + -2];
          if ((uVar7 < uVar2) || ((uVar7 == uVar2 && (puVar5[1] < (param_1 + lVar6 * 4 + -2)[1]))))
          {
            lVar8 = lVar8 + -1;
            puVar5 = param_1 + lVar8 * 2;
            uVar7 = *puVar5;
          }
          param_1[lVar9 * 2] = uVar7;
          (param_1 + lVar9 * 2)[1] = puVar5[1];
          lVar9 = lVar8;
        }
        if ((lVar10 == lVar9) && ((~(uint)lVar3 & 1) != 0)) {
          lVar6 = lVar9 + 1;
          lVar9 = lVar9 + lVar6;
          *puVar5 = param_1[lVar6 * 4 + -2];
          puVar5[1] = (param_1 + lVar6 * 4 + -2)[1];
          puVar5 = param_1 + lVar9 * 2;
        }
        lVar6 = lVar9 + -1;
        if (lVar13 < lVar9) {
          do {
            lVar8 = lVar6 >> 1;
            puVar5 = param_1 + lVar8 * 2;
            uVar2 = *puVar5;
            if (((uint)uVar1 <= uVar2) &&
               ((uVar2 != (uint)uVar1 || ((uint)((ulong)uVar1 >> 0x20) <= puVar5[1])))) {
              puVar5 = param_1 + lVar9 * 2;
              break;
            }
            param_1[lVar9 * 2] = uVar2;
            (param_1 + lVar9 * 2)[1] = puVar5[1];
            lVar6 = (lVar8 + -1) - (lVar8 + -1 >> 0x3f);
            lVar9 = lVar8;
          } while (lVar13 < lVar8);
          *(undefined8 *)puVar5 = uVar1;
          if (lVar13 == 0) {
            do {
              puVar14 = param_2 + -2;
              uVar1 = *(undefined8 *)puVar14;
              *puVar14 = *param_1;
              param_2[-1] = param_1[1];
              FUN_00111860(param_1,(long)puVar14 - (long)param_1 >> 3,uVar1);
              param_2 = puVar14;
            } while (8 < (long)puVar14 - (long)param_1);
            return;
          }
        }
        else {
          *(undefined8 *)puVar5 = uVar1;
        }
        puVar14 = puVar14 + -2;
        lVar13 = lVar13 + -1;
      } while( true );
    }
    uVar7 = param_1[2];
    param_3 = param_3 + -1;
    puVar14 = param_1 + (lVar3 >> 4) * 2;
    uVar2 = *puVar14;
    puVar4 = param_2;
    puVar5 = param_1;
    if ((uVar7 < uVar2) || ((uVar7 == uVar2 && (param_1[3] < puVar14[1])))) {
      uVar11 = param_2[-2];
      if ((uVar2 < uVar11) || ((uVar2 == uVar11 && (puVar14[1] < param_2[-1])))) {
LAB_00111ae0:
        uVar7 = *param_1;
        *param_1 = uVar2;
        *puVar14 = uVar7;
        uVar2 = param_1[1];
        param_1[1] = puVar14[1];
        puVar14[1] = uVar2;
        uVar7 = *param_1;
      }
      else if ((uVar7 < uVar11) || ((uVar7 == uVar11 && (param_1[3] < param_2[-1])))) {
LAB_00111b1c:
        uVar2 = *param_1;
        *param_1 = uVar11;
        param_2[-2] = uVar2;
        uVar2 = param_1[1];
        param_1[1] = param_2[-1];
        param_2[-1] = uVar2;
        uVar7 = *param_1;
      }
      else {
        uVar1 = *(undefined8 *)param_1;
        *(ulong *)param_1 = CONCAT44(param_1[3],uVar7);
        *(undefined8 *)(param_1 + 2) = uVar1;
      }
    }
    else {
      uVar11 = param_2[-2];
      if (uVar7 < uVar11) {
        uVar12 = param_1[3];
      }
      else if ((uVar7 != uVar11) || (uVar12 = param_1[3], param_2[-1] <= uVar12)) {
        if ((uVar2 < uVar11) || ((uVar2 == uVar11 && (puVar14[1] < param_2[-1]))))
        goto LAB_00111b1c;
        goto LAB_00111ae0;
      }
      uVar1 = *(undefined8 *)param_1;
      *(ulong *)param_1 = CONCAT44(uVar12,uVar7);
      *(undefined8 *)(param_1 + 2) = uVar1;
    }
    while( true ) {
      puVar5 = puVar5 + 2;
      uVar2 = *puVar5;
      for (; (uVar2 < uVar7 || ((uVar2 == uVar7 && (puVar5[1] < param_1[1])))); puVar5 = puVar5 + 2)
      {
        uVar2 = puVar5[2];
      }
      do {
        do {
          puVar14 = puVar4;
          uVar11 = puVar14[-2];
          puVar4 = puVar14 + -2;
        } while (uVar7 < uVar11);
      } while ((uVar11 == uVar7) && (param_1[1] < puVar14[-1]));
      if (puVar4 <= puVar5) break;
      *puVar5 = uVar11;
      *puVar4 = uVar2;
      uVar2 = puVar5[1];
      puVar5[1] = puVar14[-1];
      puVar14[-1] = uVar2;
      uVar7 = *param_1;
    }
    FUN_001119c0(puVar5,param_2,param_3);
    lVar3 = (long)puVar5 - (long)param_1;
    param_2 = puVar5;
    if (lVar3 < 0x81) {
      return;
    }
  } while( true );
}


//===== FUN_00111d60 @ 00111d60 size=2084 =====

void FUN_00111d60(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  long lVar10;
  ulong uVar11;
  ulong uVar12;
  
  if (0xe0 < param_2 - param_1) {
    uVar2 = (param_2 - param_1 >> 5) * 0x10;
    lVar1 = param_1 + uVar2;
    if (uVar2 < 0xe1) {
      FUN_001114e0(param_1,lVar1);
    }
    else {
      uVar8 = ((long)uVar2 >> 5) * 0x10;
      lVar9 = param_1 + uVar8;
      if (uVar8 < 0xe1) {
        FUN_001114e0(param_1,lVar9);
      }
      else {
        uVar12 = ((long)uVar8 >> 5) * 0x10;
        lVar3 = param_1 + uVar12;
        if (uVar12 < 0xe1) {
          FUN_001114e0(param_1,lVar3);
        }
        else {
          lVar4 = ((long)uVar12 >> 5) * 0x10;
          lVar10 = param_1 + lVar4;
          FUN_00111d60(param_1,lVar10);
          FUN_00111d60(lVar10,lVar3);
          FUN_00111300(param_1,lVar10,lVar3,lVar4 >> 4,
                       (long)(uVar12 + ((long)uVar12 >> 5) * -0x10) >> 4);
        }
        lVar10 = uVar8 + ((long)uVar8 >> 5) * -0x10;
        if (lVar10 < 0xe1) {
          FUN_001114e0(lVar3,lVar9);
        }
        else {
          uVar11 = (lVar10 >> 5) * 0x10;
          lVar4 = lVar3 + uVar11;
          if (uVar11 < 0xe1) {
            FUN_001114e0(lVar3,lVar4);
          }
          else {
            lVar5 = ((long)uVar11 >> 5) * 0x10;
            lVar6 = lVar3 + lVar5;
            FUN_00111d60(lVar3,lVar6);
            FUN_00111d60(lVar6,lVar4);
            FUN_00111300(lVar3,lVar6,lVar4,lVar5 >> 4,
                         (long)(uVar11 + ((long)uVar11 >> 5) * -0x10) >> 4);
          }
          lVar6 = lVar9 - lVar4;
          if (lVar6 < 0xe1) {
            FUN_001114e0(lVar4,lVar9);
          }
          else {
            lVar7 = (lVar6 >> 5) * 0x10;
            lVar5 = lVar4 + lVar7;
            FUN_00111d60(lVar4,lVar5);
            FUN_00111d60(lVar5,lVar9);
            FUN_00111300(lVar4,lVar5,lVar9,lVar7 >> 4,lVar9 - lVar5 >> 4);
          }
          FUN_00111300(lVar3,lVar4,lVar9,(long)uVar11 >> 4,lVar6 >> 4);
        }
        FUN_00111300(param_1,lVar3,lVar9,(long)uVar12 >> 4,lVar10 >> 4);
      }
      lVar3 = uVar2 + ((long)uVar2 >> 5) * -0x10;
      if (lVar3 < 0xe1) {
        FUN_001114e0(lVar9,lVar1);
      }
      else {
        uVar12 = (lVar3 >> 5) * 0x10;
        lVar10 = lVar9 + uVar12;
        if (uVar12 < 0xe1) {
          FUN_001114e0(lVar9,lVar10);
        }
        else {
          lVar6 = ((long)uVar12 >> 5) * 0x10;
          lVar4 = lVar9 + lVar6;
          FUN_00111d60(lVar9,lVar4);
          FUN_00111d60(lVar4,lVar10);
          FUN_00111300(lVar9,lVar4,lVar10,lVar6 >> 4,
                       (long)(uVar12 + ((long)uVar12 >> 5) * -0x10) >> 4);
        }
        lVar4 = lVar1 - lVar10;
        if (lVar4 < 0xe1) {
          FUN_001114e0(lVar10,lVar1);
        }
        else {
          lVar5 = (lVar4 >> 5) * 0x10;
          lVar6 = lVar10 + lVar5;
          FUN_00111d60(lVar10,lVar6);
          FUN_00111d60(lVar6,lVar1);
          FUN_00111300(lVar10,lVar6,lVar1,lVar5 >> 4,lVar1 - lVar6 >> 4);
        }
        FUN_00111300(lVar9,lVar10,lVar1,(long)uVar12 >> 4,lVar4 >> 4);
      }
      FUN_00111300(param_1,lVar9,lVar1,(long)uVar8 >> 4,lVar3 >> 4);
    }
    lVar9 = param_2 - lVar1;
    if (lVar9 < 0xe1) {
      FUN_001114e0(lVar1,param_2);
    }
    else {
      uVar8 = (lVar9 >> 5) * 0x10;
      lVar3 = lVar1 + uVar8;
      if (uVar8 < 0xe1) {
        FUN_001114e0(lVar1,lVar3);
      }
      else {
        uVar12 = ((long)uVar8 >> 5) * 0x10;
        lVar10 = lVar1 + uVar12;
        if (uVar12 < 0xe1) {
          FUN_001114e0(lVar1,lVar10);
        }
        else {
          lVar6 = ((long)uVar12 >> 5) * 0x10;
          lVar4 = lVar1 + lVar6;
          FUN_00111d60(lVar1,lVar4);
          FUN_00111d60(lVar4,lVar10);
          FUN_00111300(lVar1,lVar4,lVar10,lVar6 >> 4,
                       (long)(uVar12 + ((long)uVar12 >> 5) * -0x10) >> 4);
        }
        lVar4 = uVar8 + ((long)uVar8 >> 5) * -0x10;
        if (lVar4 < 0xe1) {
          FUN_001114e0(lVar10,lVar3);
        }
        else {
          lVar5 = (lVar4 >> 5) * 0x10;
          lVar6 = lVar10 + lVar5;
          FUN_00111d60(lVar10,lVar6);
          FUN_00111d60(lVar6,lVar3);
          FUN_00111300(lVar10,lVar6,lVar3,lVar5 >> 4,lVar3 - lVar6 >> 4);
        }
        FUN_00111300(lVar1,lVar10,lVar3,(long)uVar12 >> 4,lVar4 >> 4);
      }
      lVar10 = param_2 - lVar3;
      if (lVar10 < 0xe1) {
        FUN_001114e0(lVar3,param_2);
      }
      else {
        uVar12 = (lVar10 >> 5) * 0x10;
        lVar4 = lVar3 + uVar12;
        if (uVar12 < 0xe1) {
          FUN_001114e0(lVar3,lVar4);
        }
        else {
          lVar5 = ((long)uVar12 >> 5) * 0x10;
          lVar6 = lVar3 + lVar5;
          FUN_00111d60(lVar3,lVar6);
          FUN_00111d60(lVar6,lVar4);
          FUN_00111300(lVar3,lVar6,lVar4,lVar5 >> 4,
                       (long)(uVar12 + ((long)uVar12 >> 5) * -0x10) >> 4);
        }
        lVar6 = param_2 - lVar4;
        if (lVar6 < 0xe1) {
          FUN_001114e0(lVar4,param_2);
        }
        else {
          lVar7 = (lVar6 >> 5) * 0x10;
          lVar5 = lVar4 + lVar7;
          FUN_00111d60(lVar4,lVar5);
          FUN_00111d60(lVar5,param_2);
          FUN_00111300(lVar4,lVar5,param_2,lVar7 >> 4,param_2 - lVar5 >> 4);
        }
        FUN_00111300(lVar3,lVar4,param_2,(long)uVar12 >> 4,lVar6 >> 4);
      }
      FUN_00111300(lVar1,lVar3,param_2,(long)uVar8 >> 4,lVar10 >> 4);
    }
    FUN_00111300(param_1,lVar1,param_2,(long)uVar2 >> 4,lVar9 >> 4);
    return;
  }
  FUN_001114e0();
  return;
}


//===== FUN_001125e0 @ 001125e0 size=396 =====

void FUN_001125e0(undefined8 *param_1)

{
  void *pvVar1;
  
  FUN_00110320(param_1 + 0x89);
  if ((void *)param_1[0x7e] != (void *)0x0) {
    operator_delete__((void *)param_1[0x7e]);
  }
  pvVar1 = (void *)param_1[0x7d];
  if (pvVar1 != (void *)0x0) {
    FUN_001125e0(pvVar1);
    operator_delete(pvVar1);
  }
  if ((void *)param_1[0x77] != (void *)0x0) {
    operator_delete__((void *)param_1[0x77]);
  }
  if ((void *)param_1[0x71] != (void *)0x0) {
    operator_delete__((void *)param_1[0x71]);
  }
  if ((void *)param_1[0x6b] != (void *)0x0) {
    operator_delete__((void *)param_1[0x6b]);
  }
  if ((void *)param_1[99] != (void *)0x0) {
    operator_delete__((void *)param_1[99]);
  }
  if ((void *)param_1[0x5d] != (void *)0x0) {
    operator_delete__((void *)param_1[0x5d]);
  }
  if ((void *)param_1[0x54] != (void *)0x0) {
    operator_delete__((void *)param_1[0x54]);
  }
  if ((void *)param_1[0x4e] != (void *)0x0) {
    operator_delete__((void *)param_1[0x4e]);
  }
  if ((void *)param_1[0x48] != (void *)0x0) {
    operator_delete__((void *)param_1[0x48]);
  }
  if ((void *)param_1[0x42] != (void *)0x0) {
    operator_delete__((void *)param_1[0x42]);
  }
  if ((void *)param_1[0x3c] != (void *)0x0) {
    operator_delete__((void *)param_1[0x3c]);
  }
  if ((void *)param_1[0x34] != (void *)0x0) {
    operator_delete__((void *)param_1[0x34]);
  }
  if ((void *)param_1[0x2e] != (void *)0x0) {
    operator_delete__((void *)param_1[0x2e]);
  }
  if ((void *)param_1[0x28] != (void *)0x0) {
    operator_delete__((void *)param_1[0x28]);
  }
  if ((void *)param_1[0x22] != (void *)0x0) {
    operator_delete__((void *)param_1[0x22]);
  }
  if ((void *)param_1[0x1a] != (void *)0x0) {
    operator_delete__((void *)param_1[0x1a]);
  }
  if ((void *)param_1[0x14] != (void *)0x0) {
    operator_delete__((void *)param_1[0x14]);
  }
  if ((void *)param_1[0xe] != (void *)0x0) {
    operator_delete__((void *)param_1[0xe]);
  }
  if ((void *)param_1[8] != (void *)0x0) {
    operator_delete__((void *)param_1[8]);
  }
  if ((void *)*param_1 != (void *)0x0) {
    operator_delete__((void *)*param_1);
    return;
  }
  return;
}


//===== FUN_00112770 @ 00112770 size=607 =====

void FUN_00112770(undefined1 (*param_1) [16])

{
  undefined8 uVar1;
  
  *param_1 = (undefined1  [16])0x0;
  *(undefined8 *)param_1[1] = 0;
  *(undefined1 (*) [16])(param_1[1] + 8) = (undefined1  [16])0x0;
  param_1[2][8] = 0;
  param_1[3] = (undefined1  [16])0x0;
  param_1[4] = (undefined1  [16])0x0;
  *(undefined8 *)param_1[5] = 0;
  *(undefined1 (*) [16])(param_1[5] + 8) = (undefined1  [16])0x0;
  param_1[6][8] = 0;
  param_1[7] = (undefined1  [16])0x0;
  *(undefined8 *)param_1[8] = 0;
  *(undefined1 (*) [16])(param_1[8] + 8) = (undefined1  [16])0x0;
  param_1[9][8] = 0;
  param_1[10] = (undefined1  [16])0x0;
  *(undefined8 *)param_1[0xb] = 0;
  *(undefined1 (*) [16])(param_1[0xb] + 8) = (undefined1  [16])0x0;
  param_1[0xc][8] = 0;
  param_1[0xd] = (undefined1  [16])0x0;
  *(undefined8 *)param_1[0xe] = 0;
  *(undefined1 (*) [16])(param_1[0xe] + 8) = (undefined1  [16])0x0;
  param_1[0xf][8] = 0;
  param_1[0x10] = (undefined1  [16])0x0;
  param_1[0x11] = (undefined1  [16])0x0;
  *(undefined8 *)param_1[0x12] = 0;
  *(undefined1 (*) [16])(param_1[0x12] + 8) = (undefined1  [16])0x0;
  param_1[0x13][8] = 0;
  param_1[0x14] = (undefined1  [16])0x0;
  *(undefined8 *)param_1[0x15] = 0;
  *(undefined1 (*) [16])(param_1[0x15] + 8) = (undefined1  [16])0x0;
  param_1[0x16][8] = 0;
  param_1[0x17] = (undefined1  [16])0x0;
  *(undefined8 *)param_1[0x18] = 0;
  *(undefined1 (*) [16])(param_1[0x18] + 8) = (undefined1  [16])0x0;
  param_1[0x19][8] = 0;
  param_1[0x1a] = (undefined1  [16])0x0;
  *(undefined8 *)param_1[0x1b] = 0;
  *(undefined1 (*) [16])(param_1[0x1b] + 8) = (undefined1  [16])0x0;
  param_1[0x1c][8] = 0;
  param_1[0x1d] = (undefined1  [16])0x0;
  param_1[0x1e] = (undefined1  [16])0x0;
  *(undefined8 *)param_1[0x1f] = 0;
  *(undefined1 (*) [16])(param_1[0x1f] + 8) = (undefined1  [16])0x0;
  param_1[0x20][8] = 0;
  param_1[0x21] = (undefined1  [16])0x0;
  *(undefined8 *)param_1[0x22] = 0;
  *(undefined1 (*) [16])(param_1[0x22] + 8) = (undefined1  [16])0x0;
  param_1[0x23][8] = 0;
  param_1[0x24] = (undefined1  [16])0x0;
  *(undefined8 *)param_1[0x25] = 0;
  *(undefined1 (*) [16])(param_1[0x25] + 8) = (undefined1  [16])0x0;
  param_1[0x26][8] = 0;
  param_1[0x27] = (undefined1  [16])0x0;
  *(undefined8 *)param_1[0x28] = 0;
  *(undefined1 (*) [16])(param_1[0x28] + 8) = (undefined1  [16])0x0;
  param_1[0x29][8] = 0;
  param_1[0x2a] = (undefined1  [16])0x0;
  *(undefined8 *)param_1[0x2b] = 0;
  *(undefined1 (*) [16])(param_1[0x2b] + 8) = (undefined1  [16])0x0;
  param_1[0x2c][8] = 0;
  *(undefined8 *)param_1[0x2d] = 0;
  *(undefined4 *)(param_1[0x2d] + 8) = 0;
  *(undefined8 *)param_1[0x2e] = 0;
  FUN_001220d0();
  uVar1 = DAT_0012a630;
  param_1[0x41][8] = 0;
  *(undefined8 *)param_1[0x43] = 3;
  *(undefined8 *)(param_1[0x43] + 8) = uVar1;
  *(undefined4 *)param_1[0x44] = 0x20000;
  *(undefined1 (*) [16])(param_1[0x3e] + 8) = (undefined1  [16])0x0;
  *(undefined1 (*) [16])(param_1[0x3f] + 8) = (undefined1  [16])0x0;
  *(undefined1 (*) [16])(param_1[0x40] + 8) = (undefined1  [16])0x0;
  param_1[0x42] = (undefined1  [16])0x0;
  FUN_00110300(param_1[0x44] + 8);
  return;
}


//===== FUN_001129f0 @ 001129f0 size=233 =====

long FUN_001129f0(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  long lVar16;
  long lVar17;
  long lVar18;
  long lVar19;
  long lVar20;
  
  lVar1 = *(long *)(param_1 + 0xb8);
  lVar2 = *(long *)(param_1 + 0x18);
  lVar3 = *(long *)(param_1 + 0x288);
  lVar4 = *(long *)(param_1 + 0x88);
  lVar5 = *(long *)(param_1 + 0x300);
  lVar6 = *(long *)(param_1 + 0x158);
  lVar7 = *(long *)(param_1 + 0xe8);
  lVar8 = *(long *)(param_1 + 0x188);
  lVar9 = *(long *)(param_1 + 0x1b8);
  lVar10 = *(long *)(param_1 + 0x228);
  lVar11 = *(long *)(param_1 + 0x2b8);
  lVar12 = *(long *)(param_1 + 600);
  lVar13 = *(long *)(param_1 + 0x330);
  lVar14 = *(long *)(param_1 + 0x3a0);
  lVar15 = *(long *)(param_1 + 0x58);
  lVar16 = *(long *)(param_1 + 0x3d0);
  lVar20 = 0;
  lVar17 = *(long *)(param_1 + 0x128);
  lVar18 = *(long *)(param_1 + 0x1f8);
  lVar19 = *(long *)(param_1 + 0x370);
  if (*(long *)(param_1 + 1000) != 0) {
    lVar20 = FUN_001129f0();
  }
  return lVar3 + lVar5 + (lVar2 + lVar7 + lVar9 + lVar11 + lVar13) * 8 +
         (lVar17 + lVar15 + lVar18 + lVar19 + *(long *)(param_1 + 0x408)) * 0xc +
         (lVar1 + lVar4 + lVar6 + lVar8 + lVar10 + lVar12 + lVar14 + lVar16) * 4 + lVar20;
}


//===== FUN_00112ae0 @ 00112ae0 size=447 =====

long FUN_00112ae0(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  long lVar16;
  long lVar17;
  long lVar18;
  long lVar19;
  long lVar20;
  
  lVar1 = *(long *)(param_1 + 0x3a0);
  lVar2 = *(long *)(param_1 + 0x3d0);
  lVar3 = *(long *)(param_1 + 0x300);
  lVar4 = *(long *)(param_1 + 0x288);
  lVar5 = *(long *)(param_1 + 0x18);
  lVar6 = *(long *)(param_1 + 0x58);
  lVar7 = *(long *)(param_1 + 0x88);
  lVar8 = *(long *)(param_1 + 0xb8);
  lVar9 = *(long *)(param_1 + 0xe8);
  lVar10 = *(long *)(param_1 + 0x128);
  lVar11 = *(long *)(param_1 + 0x158);
  lVar12 = *(long *)(param_1 + 0x188);
  lVar13 = *(long *)(param_1 + 0x1b8);
  lVar14 = *(long *)(param_1 + 0x1f8);
  lVar15 = *(long *)(param_1 + 0x228);
  lVar16 = *(long *)(param_1 + 600);
  lVar17 = *(long *)(param_1 + 0x2b8);
  lVar18 = *(long *)(param_1 + 0x330);
  lVar19 = *(long *)(param_1 + 0x370);
  lVar20 = 0;
  if (*(long *)(param_1 + 1000) != 0) {
    lVar20 = FUN_00112ae0();
    lVar20 = lVar20 + -0x10;
  }
  return (*(long *)(param_1 + 0x408) * 0xc + 7U & 0xfffffffffffffff8) +
         (lVar1 * 4 + 7U & 0xfffffffffffffff8) +
         (lVar3 + 7U & 0xfffffffffffffff8) + 0xe8 + (lVar4 + 7U & 0xfffffffffffffff8) + lVar5 * 8 +
         (lVar6 * 0xc + 7U & 0xfffffffffffffff8) + (lVar7 * 4 + 7U & 0xfffffffffffffff8) +
         (lVar8 * 4 + 7U & 0xfffffffffffffff8) + lVar9 * 8 +
         (lVar10 * 0xc + 7U & 0xfffffffffffffff8) + (lVar11 * 4 + 7U & 0xfffffffffffffff8) +
         (lVar12 * 4 + 7U & 0xfffffffffffffff8) + lVar13 * 8 +
         (lVar14 * 0xc + 7U & 0xfffffffffffffff8) + (lVar15 * 4 + 7U & 0xfffffffffffffff8) +
         (lVar16 * 4 + 7U & 0xfffffffffffffff8) + lVar17 * 8 + lVar18 * 8 +
         (lVar19 * 0xc + 7U & 0xfffffffffffffff8) + (lVar2 * 4 + 7U & 0xfffffffffffffff8) + lVar20;
}


//===== FUN_00112ca0 @ 00112ca0 size=2790 =====

void FUN_00112ca0(undefined8 *param_1,undefined8 *param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = *param_1;
  *param_1 = *param_2;
  *param_2 = uVar3;
  uVar3 = param_1[1];
  param_1[1] = param_2[1];
  param_2[1] = uVar3;
  uVar3 = param_1[2];
  param_1[2] = param_2[2];
  param_2[2] = uVar3;
  uVar3 = param_1[3];
  param_1[3] = param_2[3];
  param_2[3] = uVar3;
  uVar3 = param_1[4];
  param_1[4] = param_2[4];
  param_2[4] = uVar3;
  uVar1 = *(undefined1 *)(param_1 + 5);
  *(undefined1 *)(param_1 + 5) = *(undefined1 *)(param_2 + 5);
  *(undefined1 *)(param_2 + 5) = uVar1;
  uVar3 = param_1[6];
  param_1[6] = param_2[6];
  param_2[6] = uVar3;
  uVar3 = param_1[7];
  param_1[7] = param_2[7];
  param_2[7] = uVar3;
  uVar3 = param_1[8];
  param_1[8] = param_2[8];
  param_2[8] = uVar3;
  uVar3 = param_1[9];
  param_1[9] = param_2[9];
  param_2[9] = uVar3;
  uVar3 = param_1[10];
  param_1[10] = param_2[10];
  param_2[10] = uVar3;
  uVar3 = param_1[0xb];
  param_1[0xb] = param_2[0xb];
  param_2[0xb] = uVar3;
  uVar3 = param_1[0xc];
  param_1[0xc] = param_2[0xc];
  param_2[0xc] = uVar3;
  uVar1 = *(undefined1 *)(param_1 + 0xd);
  *(undefined1 *)(param_1 + 0xd) = *(undefined1 *)(param_2 + 0xd);
  *(undefined1 *)(param_2 + 0xd) = uVar1;
  uVar3 = param_1[0xe];
  param_1[0xe] = param_2[0xe];
  param_2[0xe] = uVar3;
  uVar3 = param_1[0xf];
  param_1[0xf] = param_2[0xf];
  param_2[0xf] = uVar3;
  uVar3 = param_1[0x10];
  param_1[0x10] = param_2[0x10];
  param_2[0x10] = uVar3;
  uVar3 = param_1[0x11];
  param_1[0x11] = param_2[0x11];
  param_2[0x11] = uVar3;
  uVar3 = param_1[0x12];
  param_1[0x12] = param_2[0x12];
  param_2[0x12] = uVar3;
  uVar1 = *(undefined1 *)(param_1 + 0x13);
  *(undefined1 *)(param_1 + 0x13) = *(undefined1 *)(param_2 + 0x13);
  *(undefined1 *)(param_2 + 0x13) = uVar1;
  uVar3 = param_1[0x14];
  param_1[0x14] = param_2[0x14];
  param_2[0x14] = uVar3;
  uVar3 = param_1[0x15];
  param_1[0x15] = param_2[0x15];
  param_2[0x15] = uVar3;
  uVar3 = param_1[0x16];
  param_1[0x16] = param_2[0x16];
  param_2[0x16] = uVar3;
  uVar3 = param_1[0x17];
  param_1[0x17] = param_2[0x17];
  param_2[0x17] = uVar3;
  uVar3 = param_1[0x18];
  param_1[0x18] = param_2[0x18];
  param_2[0x18] = uVar3;
  uVar1 = *(undefined1 *)(param_1 + 0x19);
  *(undefined1 *)(param_1 + 0x19) = *(undefined1 *)(param_2 + 0x19);
  *(undefined1 *)(param_2 + 0x19) = uVar1;
  uVar3 = param_1[0x1a];
  param_1[0x1a] = param_2[0x1a];
  param_2[0x1a] = uVar3;
  uVar3 = param_1[0x1b];
  param_1[0x1b] = param_2[0x1b];
  param_2[0x1b] = uVar3;
  uVar3 = param_1[0x1c];
  param_1[0x1c] = param_2[0x1c];
  param_2[0x1c] = uVar3;
  uVar3 = param_1[0x1d];
  param_1[0x1d] = param_2[0x1d];
  param_2[0x1d] = uVar3;
  uVar3 = param_1[0x1e];
  param_1[0x1e] = param_2[0x1e];
  param_2[0x1e] = uVar3;
  uVar1 = *(undefined1 *)(param_1 + 0x1f);
  *(undefined1 *)(param_1 + 0x1f) = *(undefined1 *)(param_2 + 0x1f);
  *(undefined1 *)(param_2 + 0x1f) = uVar1;
  uVar3 = param_1[0x20];
  param_1[0x20] = param_2[0x20];
  param_2[0x20] = uVar3;
  uVar3 = param_1[0x21];
  param_1[0x21] = param_2[0x21];
  param_2[0x21] = uVar3;
  uVar3 = param_1[0x22];
  param_1[0x22] = param_2[0x22];
  param_2[0x22] = uVar3;
  uVar3 = param_1[0x23];
  param_1[0x23] = param_2[0x23];
  param_2[0x23] = uVar3;
  uVar3 = param_1[0x24];
  param_1[0x24] = param_2[0x24];
  param_2[0x24] = uVar3;
  uVar3 = param_1[0x25];
  param_1[0x25] = param_2[0x25];
  param_2[0x25] = uVar3;
  uVar3 = param_1[0x26];
  param_1[0x26] = param_2[0x26];
  param_2[0x26] = uVar3;
  uVar1 = *(undefined1 *)(param_1 + 0x27);
  *(undefined1 *)(param_1 + 0x27) = *(undefined1 *)(param_2 + 0x27);
  *(undefined1 *)(param_2 + 0x27) = uVar1;
  uVar3 = param_1[0x28];
  param_1[0x28] = param_2[0x28];
  param_2[0x28] = uVar3;
  uVar3 = param_1[0x29];
  param_1[0x29] = param_2[0x29];
  param_2[0x29] = uVar3;
  uVar3 = param_1[0x2a];
  param_1[0x2a] = param_2[0x2a];
  param_2[0x2a] = uVar3;
  uVar3 = param_1[0x2b];
  param_1[0x2b] = param_2[0x2b];
  param_2[0x2b] = uVar3;
  uVar3 = param_1[0x2c];
  param_1[0x2c] = param_2[0x2c];
  param_2[0x2c] = uVar3;
  uVar1 = *(undefined1 *)(param_1 + 0x2d);
  *(undefined1 *)(param_1 + 0x2d) = *(undefined1 *)(param_2 + 0x2d);
  *(undefined1 *)(param_2 + 0x2d) = uVar1;
  uVar3 = param_1[0x2e];
  param_1[0x2e] = param_2[0x2e];
  param_2[0x2e] = uVar3;
  uVar3 = param_1[0x2f];
  param_1[0x2f] = param_2[0x2f];
  param_2[0x2f] = uVar3;
  uVar3 = param_1[0x30];
  param_1[0x30] = param_2[0x30];
  param_2[0x30] = uVar3;
  uVar3 = param_1[0x31];
  param_1[0x31] = param_2[0x31];
  param_2[0x31] = uVar3;
  uVar3 = param_1[0x32];
  param_1[0x32] = param_2[0x32];
  param_2[0x32] = uVar3;
  uVar1 = *(undefined1 *)(param_1 + 0x33);
  *(undefined1 *)(param_1 + 0x33) = *(undefined1 *)(param_2 + 0x33);
  *(undefined1 *)(param_2 + 0x33) = uVar1;
  uVar3 = param_1[0x34];
  param_1[0x34] = param_2[0x34];
  param_2[0x34] = uVar3;
  uVar3 = param_1[0x35];
  param_1[0x35] = param_2[0x35];
  param_2[0x35] = uVar3;
  uVar3 = param_1[0x36];
  param_1[0x36] = param_2[0x36];
  param_2[0x36] = uVar3;
  uVar3 = param_1[0x37];
  param_1[0x37] = param_2[0x37];
  param_2[0x37] = uVar3;
  uVar3 = param_1[0x38];
  param_1[0x38] = param_2[0x38];
  param_2[0x38] = uVar3;
  uVar1 = *(undefined1 *)(param_1 + 0x39);
  *(undefined1 *)(param_1 + 0x39) = *(undefined1 *)(param_2 + 0x39);
  *(undefined1 *)(param_2 + 0x39) = uVar1;
  uVar3 = param_1[0x3a];
  param_1[0x3a] = param_2[0x3a];
  param_2[0x3a] = uVar3;
  uVar3 = param_1[0x3b];
  param_1[0x3b] = param_2[0x3b];
  param_2[0x3b] = uVar3;
  uVar3 = param_1[0x3c];
  param_1[0x3c] = param_2[0x3c];
  param_2[0x3c] = uVar3;
  uVar3 = param_1[0x3d];
  param_1[0x3d] = param_2[0x3d];
  param_2[0x3d] = uVar3;
  uVar3 = param_1[0x3e];
  param_1[0x3e] = param_2[0x3e];
  param_2[0x3e] = uVar3;
  uVar3 = param_1[0x3f];
  param_1[0x3f] = param_2[0x3f];
  param_2[0x3f] = uVar3;
  uVar3 = param_1[0x40];
  param_1[0x40] = param_2[0x40];
  param_2[0x40] = uVar3;
  uVar1 = *(undefined1 *)(param_1 + 0x41);
  *(undefined1 *)(param_1 + 0x41) = *(undefined1 *)(param_2 + 0x41);
  *(undefined1 *)(param_2 + 0x41) = uVar1;
  uVar3 = param_1[0x42];
  param_1[0x42] = param_2[0x42];
  param_2[0x42] = uVar3;
  uVar3 = param_1[0x43];
  param_1[0x43] = param_2[0x43];
  param_2[0x43] = uVar3;
  uVar3 = param_1[0x44];
  param_1[0x44] = param_2[0x44];
  param_2[0x44] = uVar3;
  uVar3 = param_1[0x45];
  param_1[0x45] = param_2[0x45];
  param_2[0x45] = uVar3;
  uVar3 = param_1[0x46];
  param_1[0x46] = param_2[0x46];
  param_2[0x46] = uVar3;
  uVar1 = *(undefined1 *)(param_1 + 0x47);
  *(undefined1 *)(param_1 + 0x47) = *(undefined1 *)(param_2 + 0x47);
  *(undefined1 *)(param_2 + 0x47) = uVar1;
  uVar3 = param_1[0x48];
  param_1[0x48] = param_2[0x48];
  param_2[0x48] = uVar3;
  uVar3 = param_1[0x49];
  param_1[0x49] = param_2[0x49];
  param_2[0x49] = uVar3;
  uVar3 = param_1[0x4a];
  param_1[0x4a] = param_2[0x4a];
  param_2[0x4a] = uVar3;
  uVar3 = param_1[0x4b];
  param_1[0x4b] = param_2[0x4b];
  param_2[0x4b] = uVar3;
  uVar3 = param_1[0x4c];
  param_1[0x4c] = param_2[0x4c];
  param_2[0x4c] = uVar3;
  uVar1 = *(undefined1 *)(param_1 + 0x4d);
  *(undefined1 *)(param_1 + 0x4d) = *(undefined1 *)(param_2 + 0x4d);
  *(undefined1 *)(param_2 + 0x4d) = uVar1;
  uVar3 = param_1[0x4e];
  param_1[0x4e] = param_2[0x4e];
  param_2[0x4e] = uVar3;
  uVar3 = param_1[0x4f];
  param_1[0x4f] = param_2[0x4f];
  param_2[0x4f] = uVar3;
  uVar3 = param_1[0x50];
  param_1[0x50] = param_2[0x50];
  param_2[0x50] = uVar3;
  uVar3 = param_1[0x51];
  param_1[0x51] = param_2[0x51];
  param_2[0x51] = uVar3;
  uVar3 = param_1[0x52];
  param_1[0x52] = param_2[0x52];
  param_2[0x52] = uVar3;
  uVar1 = *(undefined1 *)(param_1 + 0x53);
  *(undefined1 *)(param_1 + 0x53) = *(undefined1 *)(param_2 + 0x53);
  *(undefined1 *)(param_2 + 0x53) = uVar1;
  uVar3 = param_1[0x54];
  param_1[0x54] = param_2[0x54];
  param_2[0x54] = uVar3;
  uVar3 = param_1[0x55];
  param_1[0x55] = param_2[0x55];
  param_2[0x55] = uVar3;
  uVar3 = param_1[0x56];
  param_1[0x56] = param_2[0x56];
  param_2[0x56] = uVar3;
  uVar3 = param_1[0x57];
  param_1[0x57] = param_2[0x57];
  param_2[0x57] = uVar3;
  uVar3 = param_1[0x58];
  param_1[0x58] = param_2[0x58];
  param_2[0x58] = uVar3;
  uVar1 = *(undefined1 *)(param_1 + 0x59);
  *(undefined1 *)(param_1 + 0x59) = *(undefined1 *)(param_2 + 0x59);
  *(undefined1 *)(param_2 + 0x59) = uVar1;
  uVar3 = param_1[0x5a];
  param_1[0x5a] = param_2[0x5a];
  param_2[0x5a] = uVar3;
  uVar2 = *(undefined4 *)(param_1 + 0x5b);
  *(undefined4 *)(param_1 + 0x5b) = *(undefined4 *)(param_2 + 0x5b);
  *(undefined4 *)(param_2 + 0x5b) = uVar2;
  uVar3 = param_1[0x5c];
  param_1[0x5c] = param_2[0x5c];
  param_2[0x5c] = uVar3;
  FUN_00122860();
  uVar3 = param_1[0x7d];
  param_1[0x7d] = param_2[0x7d];
  param_2[0x7d] = uVar3;
  uVar3 = param_1[0x7e];
  param_1[0x7e] = param_2[0x7e];
  param_2[0x7e] = uVar3;
  uVar3 = param_1[0x7f];
  param_1[0x7f] = param_2[0x7f];
  param_2[0x7f] = uVar3;
  uVar3 = param_1[0x80];
  param_1[0x80] = param_2[0x80];
  param_2[0x80] = uVar3;
  uVar3 = param_1[0x81];
  param_1[0x81] = param_2[0x81];
  param_2[0x81] = uVar3;
  uVar3 = param_1[0x82];
  param_1[0x82] = param_2[0x82];
  param_2[0x82] = uVar3;
  uVar1 = *(undefined1 *)(param_1 + 0x83);
  *(undefined1 *)(param_1 + 0x83) = *(undefined1 *)(param_2 + 0x83);
  *(undefined1 *)(param_2 + 0x83) = uVar1;
  uVar3 = param_1[0x84];
  param_1[0x84] = param_2[0x84];
  param_2[0x84] = uVar3;
  uVar3 = param_1[0x85];
  param_1[0x85] = param_2[0x85];
  param_2[0x85] = uVar3;
  uVar3 = param_1[0x86];
  param_1[0x86] = param_2[0x86];
  param_2[0x86] = uVar3;
  uVar2 = *(undefined4 *)(param_1 + 0x87);
  *(undefined4 *)(param_1 + 0x87) = *(undefined4 *)(param_2 + 0x87);
  *(undefined4 *)(param_2 + 0x87) = uVar2;
  uVar2 = *(undefined4 *)((long)param_1 + 0x43c);
  *(undefined4 *)((long)param_1 + 0x43c) = *(undefined4 *)((long)param_2 + 0x43c);
  *(undefined4 *)((long)param_2 + 0x43c) = uVar2;
  uVar2 = *(undefined4 *)(param_1 + 0x88);
  *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(param_2 + 0x88);
  *(undefined4 *)(param_2 + 0x88) = uVar2;
  FUN_00110360(param_1 + 0x89,param_2 + 0x89);
  return;
}


//===== FUN_00113790 @ 00113790 size=101 =====

void FUN_00113790(undefined8 param_1)

{
  long in_FS_OFFSET;
  undefined1 auStack_498 [1144];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_00112770(auStack_498);
  FUN_00112ca0(auStack_498,param_1);
  FUN_001125e0(auStack_498);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_00113810 @ 00113810 size=77 =====

void FUN_00113810(float param_1,long param_2,ulong param_3,undefined4 param_4,uint param_5)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)
           (*(long *)(param_2 + 0x3f8) +
           ((param_3 << 5 ^ param_3 ^ (ulong)param_5 & 0xff) & *(ulong *)(param_2 + 0x420)) * 0xc);
  if (*(float *)(puVar1 + 1) <= param_1 && param_1 != *(float *)(puVar1 + 1)) {
    *(float *)(puVar1 + 1) = param_1;
    *puVar1 = CONCAT44(param_4,(int)param_3);
  }
  return;
}


//===== FUN_00113860 @ 00113860 size=406 =====

void FUN_00113860(long param_1,long param_2,long param_3,ulong param_4)

{
  void *pvVar1;
  long lVar2;
  undefined4 uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  long lVar11;
  ulong uVar12;
  
  lVar11 = 0xff;
  uVar8 = 0x100;
  if (param_3 != 1) {
    lVar11 = 0;
    uVar8 = 1;
  }
  param_4 = param_4 / (ulong)(long)*(int *)(param_2 + 8);
  if (uVar8 < param_4) {
    do {
      uVar8 = uVar8 * 2;
    } while (uVar8 < param_4);
    lVar11 = uVar8 - 1;
  }
  uVar10 = *(ulong *)(param_1 + 0x410);
  if (uVar10 < uVar8) {
    if (uVar8 >> 1 < uVar10) {
      uVar9 = 0xfffffffffffffffc;
      uVar12 = 0x1555555555555555;
      if (uVar10 < 0xaaaaaaaaaaaaaab) {
        uVar12 = uVar10 * 2;
        uVar9 = uVar10 * 0x18;
      }
    }
    else {
      uVar9 = uVar8 * 0xc;
      uVar12 = uVar8;
    }
    puVar4 = operator_new__(uVar9,(nothrow_t *)PTR_nothrow_00132fb8);
    uVar10 = *(ulong *)(param_1 + 0x408);
    if (uVar10 != 0) {
      puVar5 = *(undefined8 **)(param_1 + 0x3f8);
      puVar6 = puVar4;
      do {
        puVar7 = (undefined8 *)((long)puVar6 + 0xc);
        *puVar6 = *puVar5;
        *(undefined4 *)(puVar6 + 1) = *(undefined4 *)(puVar5 + 1);
        puVar5 = (undefined8 *)((long)puVar5 + 0xc);
        puVar6 = puVar7;
      } while (puVar7 != (undefined8 *)((long)puVar4 + uVar10 * 0xc));
    }
    pvVar1 = *(void **)(param_1 + 0x3f0);
    *(undefined8 **)(param_1 + 0x400) = puVar4;
    *(ulong *)(param_1 + 0x410) = uVar12;
    *(undefined8 **)(param_1 + 0x3f0) = puVar4;
    *(undefined8 **)(param_1 + 0x3f8) = puVar4;
    if (pvVar1 == (void *)0x0) goto LAB_00113962;
    operator_delete__(pvVar1);
  }
  uVar10 = *(ulong *)(param_1 + 0x408);
LAB_00113962:
  uVar3 = DAT_0012a648;
  if (uVar10 < uVar8) {
    lVar2 = *(long *)(param_1 + 0x3f8);
    puVar4 = (undefined8 *)(lVar2 + uVar10 * 0xc);
    do {
      *puVar4 = 0;
      puVar5 = (undefined8 *)((long)puVar4 + 0xc);
      *(undefined4 *)(puVar4 + 1) = uVar3;
      puVar4 = puVar5;
    } while ((undefined8 *)(lVar2 + uVar8 * 0xc) != puVar5);
  }
  *(ulong *)(param_1 + 0x408) = uVar8;
  *(long *)(param_1 + 0x420) = lVar11;
  return;
}


//===== FUN_00113a00 @ 00113a00 size=57 =====

void FUN_00113a00(float param_1,long param_2,undefined4 param_3,ulong param_4)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)
           (*(long *)(param_2 + 0x3f8) + (*(ulong *)(param_2 + 0x420) & param_4) * 0xc);
  if (*(float *)(puVar1 + 1) <= param_1 && param_1 != *(float *)(puVar1 + 1)) {
    *(float *)(puVar1 + 1) = param_1;
    *puVar1 = CONCAT44((int)param_4,param_3);
  }
  return;
}


//===== FUN_00113a40 @ 00113a40 size=298 =====

void FUN_00113a40(long param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  sbyte sVar6;
  uint uVar7;
  ulong uVar8;
  
  uVar2 = DAT_0012a638;
  if (*(long *)(param_1 + 0x408) != 0) {
    uVar8 = 0;
    do {
      while( true ) {
        puVar1 = (undefined8 *)(*(long *)(param_1 + 0x3f8) + uVar8 * 0xc);
        uVar5 = (ulong)*(uint *)((long)puVar1 + 4);
        if (uVar5 != 0) break;
        *puVar1 = uVar2;
        uVar8 = uVar8 + 1;
        if (*(ulong *)(param_1 + 0x408) <= uVar8) {
          return;
        }
      }
      uVar3 = CONCAT31((int3)((uint)*(undefined4 *)(puVar1 + 1) >> 8),
                       *(undefined1 *)(*(long *)(param_1 + 0x278) + uVar5));
      lVar4 = *(long *)(param_1 + 0x1b0);
      *(uint *)(puVar1 + 1) = uVar3;
      uVar7 = 0xffffff00;
      if ((*(ulong *)(lVar4 + (ulong)(*(uint *)((long)puVar1 + 4) >> 6) * 8) >> (uVar5 & 0x3f) & 1)
          != 0) {
        lVar4 = FUN_00124bd0(param_1 + 0x1a0);
        uVar5 = lVar4 * *(long *)(param_1 + 0x2d0);
        uVar3 = (uint)uVar5 & 0x3f;
        uVar5 = uVar5 >> 6;
        sVar6 = (sbyte)uVar3;
        if (*(long *)(param_1 + 0x2d0) + (ulong)uVar3 < 0x41) {
          uVar7 = (uint)(*(ulong *)(*(long *)(param_1 + 0x2b0) + uVar5 * 8) >> sVar6) &
                  *(uint *)(param_1 + 0x2d8);
        }
        else {
          uVar7 = ((uint)(*(long *)(*(long *)(param_1 + 0x2b0) + 8 + uVar5 * 8) <<
                         (0x40U - sVar6 & 0x3f)) |
                  (uint)(*(ulong *)(*(long *)(param_1 + 0x2b0) + uVar5 * 8) >> sVar6)) &
                  *(uint *)(param_1 + 0x2d8);
        }
        uVar3 = *(uint *)(puVar1 + 1);
        uVar7 = uVar7 << 8;
      }
      uVar8 = uVar8 + 1;
      *(uint *)(puVar1 + 1) = uVar3 & 0xff | uVar7;
    } while (uVar8 < *(ulong *)(param_1 + 0x408));
  }
  return;
}


//===== FUN_00113b80 @ 00113b80 size=2068 =====

void FUN_00113b80(long param_1,undefined8 param_2)

{
  ulong uVar1;
  undefined8 *puVar2;
  long in_FS_OFFSET;
  long local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_28 = *(long *)(param_1 + 0x18) << 3;
  FUN_00110fb0(param_2,&local_28,8);
  uVar1 = *(ulong *)(param_1 + 0x18);
  if ((*(long *)(param_1 + 0x10) == 0) && (uVar1 != 0)) goto LAB_00106d36;
  if (uVar1 >> 0x3d != 0) goto LAB_00106d31;
  FUN_00110fb0(param_2,*(long *)(param_1 + 0x10),uVar1 << 3);
  FUN_001110d0(param_2,0);
  local_28._0_4_ = (int)*(undefined8 *)(param_1 + 0x30);
  FUN_00110fb0(param_2,&local_28,4);
  local_28 = CONCAT44(local_28._4_4_,(int)*(undefined8 *)(param_1 + 0x38));
  FUN_00110fb0(param_2,&local_28,4);
  local_28 = *(long *)(param_1 + 0x58) * 0xc;
  FUN_00110fb0(param_2,&local_28,8);
  uVar1 = *(ulong *)(param_1 + 0x58);
  if ((*(long *)(param_1 + 0x50) == 0) && (uVar1 != 0)) goto LAB_00106cf0;
  if (0x1555555555555555 < uVar1) goto LAB_00106ceb;
  FUN_00110fb0(param_2,*(long *)(param_1 + 0x50),uVar1 * 0xc);
  FUN_001110d0(param_2,(int)*(undefined8 *)(param_1 + 0x58) * 4 & 4);
  local_28 = *(long *)(param_1 + 0x88) << 2;
  FUN_00110fb0(param_2,&local_28,8);
  uVar1 = *(ulong *)(param_1 + 0x88);
  if ((*(long *)(param_1 + 0x80) == 0) && (uVar1 != 0)) goto LAB_00106caa;
  if (uVar1 >> 0x3e == 0) {
    FUN_00110fb0(param_2,*(long *)(param_1 + 0x80),uVar1 << 2);
    FUN_001110d0(param_2,(int)*(undefined8 *)(param_1 + 0x88) * -4 & 7);
    local_28 = *(long *)(param_1 + 0xb8) << 2;
    FUN_00110fb0(param_2,&local_28,8);
    uVar1 = *(ulong *)(param_1 + 0xb8);
    if ((*(long *)(param_1 + 0xb0) == 0) && (uVar1 != 0)) {
      puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
      *puVar2 = &PTR_FUN_00132da8;
      puVar2[1] = "../src_udic/marisa_u/grimoire/trie/../io/writer.h";
      puVar2[2] = 0x20000001e;
      puVar2[3] = 
      "../src_udic/marisa_u/grimoire/trie/../io/writer.h:30: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
      ;
                    /* WARNING: Subroutine does not return */
      __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
    }
    if (uVar1 >> 0x3e == 0) {
      FUN_00110fb0(param_2,*(long *)(param_1 + 0xb0),uVar1 << 2);
      FUN_001110d0(param_2,(int)*(undefined8 *)(param_1 + 0xb8) * -4 & 7);
      local_28 = *(long *)(param_1 + 0xe8) << 3;
      FUN_00110fb0(param_2,&local_28,8);
      uVar1 = *(ulong *)(param_1 + 0xe8);
      if ((*(long *)(param_1 + 0xe0) == 0) && (uVar1 != 0)) {
        puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
        *puVar2 = &PTR_FUN_00132da8;
        puVar2[1] = "../src_udic/marisa_u/grimoire/trie/../io/writer.h";
        puVar2[2] = 0x20000001e;
        puVar2[3] = 
        "../src_udic/marisa_u/grimoire/trie/../io/writer.h:30: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
        ;
                    /* WARNING: Subroutine does not return */
        __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
      }
      if (uVar1 >> 0x3d != 0) {
LAB_00106d31:
        FUN_00106808();
LAB_00106d36:
        puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
        *puVar2 = &PTR_FUN_00132da8;
        puVar2[1] = "../src_udic/marisa_u/grimoire/trie/../io/writer.h";
        puVar2[2] = 0x20000001e;
        puVar2[3] = 
        "../src_udic/marisa_u/grimoire/trie/../io/writer.h:30: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
        ;
                    /* WARNING: Subroutine does not return */
        __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
      }
      FUN_00110fb0(param_2,*(long *)(param_1 + 0xe0),uVar1 << 3);
      FUN_001110d0(param_2,0);
      local_28._0_4_ = (int)*(undefined8 *)(param_1 + 0x100);
      FUN_00110fb0(param_2,&local_28,4);
      local_28 = CONCAT44(local_28._4_4_,(int)*(undefined8 *)(param_1 + 0x108));
      FUN_00110fb0(param_2,&local_28,4);
      local_28 = *(long *)(param_1 + 0x128) * 0xc;
      FUN_00110fb0(param_2,&local_28,8);
      uVar1 = *(ulong *)(param_1 + 0x128);
      if ((*(long *)(param_1 + 0x120) == 0) && (uVar1 != 0)) {
        puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
        *puVar2 = &PTR_FUN_00132da8;
        puVar2[1] = "../src_udic/marisa_u/grimoire/trie/../io/writer.h";
        puVar2[2] = 0x20000001e;
        puVar2[3] = 
        "../src_udic/marisa_u/grimoire/trie/../io/writer.h:30: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
        ;
                    /* WARNING: Subroutine does not return */
        __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
      }
      if (0x1555555555555555 < uVar1) {
LAB_00106ceb:
        FUN_00106808();
LAB_00106cf0:
        puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
        *puVar2 = &PTR_FUN_00132da8;
        puVar2[1] = "../src_udic/marisa_u/grimoire/trie/../io/writer.h";
        puVar2[2] = 0x20000001e;
        puVar2[3] = 
        "../src_udic/marisa_u/grimoire/trie/../io/writer.h:30: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
        ;
                    /* WARNING: Subroutine does not return */
        __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
      }
      FUN_00110fb0(param_2,*(long *)(param_1 + 0x120),uVar1 * 0xc);
      FUN_001110d0(param_2,(int)*(undefined8 *)(param_1 + 0x128) * 4 & 4);
      local_28 = *(long *)(param_1 + 0x158) << 2;
      FUN_00110fb0(param_2,&local_28,8);
      uVar1 = *(ulong *)(param_1 + 0x158);
      if ((*(long *)(param_1 + 0x150) == 0) && (uVar1 != 0)) {
        puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
        *puVar2 = &PTR_FUN_00132da8;
        puVar2[1] = "../src_udic/marisa_u/grimoire/trie/../io/writer.h";
        puVar2[2] = 0x20000001e;
        puVar2[3] = 
        "../src_udic/marisa_u/grimoire/trie/../io/writer.h:30: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
        ;
                    /* WARNING: Subroutine does not return */
        __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
      }
      if (uVar1 >> 0x3e == 0) {
        FUN_00110fb0(param_2,*(long *)(param_1 + 0x150),uVar1 << 2);
        FUN_001110d0(param_2,(int)*(undefined8 *)(param_1 + 0x158) * -4 & 7);
        local_28 = *(long *)(param_1 + 0x188) << 2;
        FUN_00110fb0(param_2,&local_28,8);
        uVar1 = *(ulong *)(param_1 + 0x188);
        if ((*(long *)(param_1 + 0x180) == 0) && (uVar1 != 0)) {
          puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
          *puVar2 = &PTR_FUN_00132da8;
          puVar2[1] = "../src_udic/marisa_u/grimoire/trie/../io/writer.h";
          puVar2[2] = 0x20000001e;
          puVar2[3] = 
          "../src_udic/marisa_u/grimoire/trie/../io/writer.h:30: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
          ;
                    /* WARNING: Subroutine does not return */
          __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
        }
        if (uVar1 >> 0x3e == 0) {
          FUN_00110fb0(param_2,*(long *)(param_1 + 0x180),uVar1 << 2);
          FUN_001110d0(param_2,(int)*(undefined8 *)(param_1 + 0x188) * -4 & 7);
          local_28 = *(long *)(param_1 + 0x1b8) << 3;
          FUN_00110fb0(param_2,&local_28,8);
          uVar1 = *(ulong *)(param_1 + 0x1b8);
          if ((*(long *)(param_1 + 0x1b0) == 0) && (uVar1 != 0)) {
            puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
            *puVar2 = &PTR_FUN_00132da8;
            puVar2[1] = "../src_udic/marisa_u/grimoire/trie/../io/writer.h";
            puVar2[2] = 0x20000001e;
            puVar2[3] = 
            "../src_udic/marisa_u/grimoire/trie/../io/writer.h:30: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
            ;
                    /* WARNING: Subroutine does not return */
            __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
          }
          if (uVar1 >> 0x3d != 0) goto LAB_00106d31;
          FUN_00110fb0(param_2,*(long *)(param_1 + 0x1b0),uVar1 << 3);
          FUN_001110d0(param_2,0);
          local_28._0_4_ = (int)*(undefined8 *)(param_1 + 0x1d0);
          FUN_00110fb0(param_2,&local_28,4);
          local_28 = CONCAT44(local_28._4_4_,(int)*(undefined8 *)(param_1 + 0x1d8));
          FUN_00110fb0(param_2,&local_28,4);
          local_28 = *(long *)(param_1 + 0x1f8) * 0xc;
          FUN_00110fb0(param_2,&local_28,8);
          uVar1 = *(ulong *)(param_1 + 0x1f8);
          if ((*(long *)(param_1 + 0x1f0) == 0) && (uVar1 != 0)) {
            puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
            *puVar2 = &PTR_FUN_00132da8;
            puVar2[1] = "../src_udic/marisa_u/grimoire/trie/../io/writer.h";
            puVar2[2] = 0x20000001e;
            puVar2[3] = 
            "../src_udic/marisa_u/grimoire/trie/../io/writer.h:30: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
            ;
                    /* WARNING: Subroutine does not return */
            __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
          }
          if (0x1555555555555555 < uVar1) goto LAB_00106ceb;
          FUN_00110fb0(param_2,*(long *)(param_1 + 0x1f0),uVar1 * 0xc);
          FUN_001110d0(param_2,(int)*(undefined8 *)(param_1 + 0x1f8) * 4 & 4);
          local_28 = *(long *)(param_1 + 0x228) << 2;
          FUN_00110fb0(param_2,&local_28,8);
          uVar1 = *(ulong *)(param_1 + 0x228);
          if ((*(long *)(param_1 + 0x220) == 0) && (uVar1 != 0)) {
            puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
            *puVar2 = &PTR_FUN_00132da8;
            puVar2[1] = "../src_udic/marisa_u/grimoire/trie/../io/writer.h";
            puVar2[2] = 0x20000001e;
            puVar2[3] = 
            "../src_udic/marisa_u/grimoire/trie/../io/writer.h:30: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
            ;
                    /* WARNING: Subroutine does not return */
            __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
          }
          if (uVar1 >> 0x3e == 0) {
            FUN_00110fb0(param_2,*(long *)(param_1 + 0x220),uVar1 << 2);
            FUN_001110d0(param_2,(int)*(undefined8 *)(param_1 + 0x228) * -4 & 7);
            local_28 = *(long *)(param_1 + 600) << 2;
            FUN_00110fb0(param_2,&local_28,8);
            uVar1 = *(ulong *)(param_1 + 600);
            if ((*(long *)(param_1 + 0x250) == 0) && (uVar1 != 0)) {
LAB_00106a5c:
              puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
              *puVar2 = &PTR_FUN_00132da8;
              puVar2[1] = "../src_udic/marisa_u/grimoire/trie/../io/writer.h";
              puVar2[2] = 0x20000001e;
              puVar2[3] = 
              "../src_udic/marisa_u/grimoire/trie/../io/writer.h:30: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
              ;
                    /* WARNING: Subroutine does not return */
              __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
            }
            if (uVar1 >> 0x3e == 0) {
              FUN_00110fb0(param_2,*(long *)(param_1 + 0x250),uVar1 << 2);
              FUN_001110d0(param_2,(int)*(undefined8 *)(param_1 + 600) * -4 & 7);
              local_28 = *(long *)(param_1 + 0x288);
              FUN_00110fb0(param_2,&local_28,8);
              if ((*(long *)(param_1 + 0x280) == 0) && (*(long *)(param_1 + 0x288) != 0)) {
                FUN_0010650c();
                goto LAB_00106a5c;
              }
              FUN_00110fb0(param_2);
              FUN_001110d0(param_2,-(int)*(undefined8 *)(param_1 + 0x288) & 7);
              local_28 = *(long *)(param_1 + 0x2b8) << 3;
              FUN_00110fb0(param_2,&local_28,8);
              uVar1 = *(ulong *)(param_1 + 0x2b8);
              if ((*(long *)(param_1 + 0x2b0) == 0) && (uVar1 != 0)) {
                puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
                *puVar2 = &PTR_FUN_00132da8;
                puVar2[1] = "../src_udic/marisa_u/grimoire/trie/../io/writer.h";
                puVar2[2] = 0x20000001e;
                puVar2[3] = 
                "../src_udic/marisa_u/grimoire/trie/../io/writer.h:30: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
                ;
                    /* WARNING: Subroutine does not return */
                __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
              }
              if (uVar1 >> 0x3d == 0) {
                FUN_00110fb0(param_2,*(long *)(param_1 + 0x2b0),uVar1 << 3);
                FUN_001110d0(param_2,0);
                local_28._0_4_ = (int)*(undefined8 *)(param_1 + 0x2d0);
                FUN_00110fb0(param_2,&local_28,4);
                local_28 = CONCAT44(local_28._4_4_,*(undefined4 *)(param_1 + 0x2d8));
                FUN_00110fb0(param_2,&local_28,4);
                local_28 = *(long *)(param_1 + 0x2e0);
                FUN_00110fb0(param_2,&local_28,8);
                thunk_FUN_00123de0(param_1 + 0x2e8,param_2);
                if (*(long *)(param_1 + 1000) != 0) {
                  FUN_00113b80(*(long *)(param_1 + 1000),param_2);
                }
                local_28 = *(long *)(param_1 + 0x408) * 0xc;
                FUN_00110fb0(param_2,&local_28,8);
                uVar1 = *(ulong *)(param_1 + 0x408);
                if ((*(long *)(param_1 + 0x400) != 0) || (uVar1 == 0)) {
                  if (uVar1 < 0x1555555555555556) {
                    FUN_00110fb0(param_2,*(long *)(param_1 + 0x400),uVar1 * 0xc);
                    FUN_001110d0(param_2,(int)*(undefined8 *)(param_1 + 0x408) * 4 & 4);
                    local_28._0_4_ = (int)*(undefined8 *)(param_1 + 0x428);
                    FUN_00110fb0(param_2,&local_28,4);
                    local_28 = CONCAT44(local_28._4_4_,
                                        *(uint *)(param_1 + 0x43c) | *(uint *)(param_1 + 0x440) |
                                        *(uint *)(param_1 + 0x430));
                    FUN_00110fb0(param_2,&local_28,4);
                    if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
                      return;
                    }
                    /* WARNING: Subroutine does not return */
                    __stack_chk_fail();
                  }
                  FUN_00106808();
                }
                puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
                *puVar2 = &PTR_FUN_00132da8;
                puVar2[1] = "../src_udic/marisa_u/grimoire/trie/../io/writer.h";
                puVar2[2] = 0x20000001e;
                puVar2[3] = 
                "../src_udic/marisa_u/grimoire/trie/../io/writer.h:30: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
                ;
                    /* WARNING: Subroutine does not return */
                __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
              }
              goto LAB_00106d31;
            }
          }
        }
      }
    }
  }
  FUN_00106808();
LAB_00106caa:
  puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar2 = &PTR_FUN_00132da8;
  puVar2[1] = "../src_udic/marisa_u/grimoire/trie/../io/writer.h";
  puVar2[2] = 0x20000001e;
  puVar2[3] = 
  "../src_udic/marisa_u/grimoire/trie/../io/writer.h:30: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
  ;
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_001143a0 @ 001143a0 size=55 =====

void FUN_001143a0(undefined8 param_1,undefined8 param_2)

{
  FUN_00110fb0(param_2,"We love Marisa.",0x10);
  FUN_00113b80(param_1,param_2);
  return;
}


//===== FUN_001143e0 @ 001143e0 size=794 =====

void FUN_001143e0(long param_1,long param_2,ulong param_3)

{
  byte bVar1;
  undefined8 *puVar2;
  void *pvVar3;
  uint uVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  void *pvVar8;
  sbyte sVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  
  puVar2 = *(undefined8 **)(param_2 + 0x28);
  lVar6 = *(long *)(param_1 + 0x400);
  while( true ) {
    while( true ) {
      uVar5 = *(ulong *)(param_1 + 0x420) & param_3;
      lVar6 = lVar6 + uVar5 * 0xc;
      if (param_3 != *(uint *)(lVar6 + 4)) break;
      uVar4 = *(uint *)(lVar6 + 8);
      if (uVar4 >> 8 == 0xffffff) {
        uVar10 = puVar2[4];
        uVar11 = puVar2[3] + 1;
        if (uVar10 < uVar11) {
          if (uVar11 >> 1 < uVar10) {
            uVar11 = 0xffffffffffffffff;
            if (-1 < (long)uVar10) {
              uVar11 = uVar10 * 2;
            }
          }
          pvVar8 = operator_new__(uVar11,(nothrow_t *)PTR_nothrow_00132fb8);
          uVar10 = 0;
          if (puVar2[3] != 0) {
            uVar12 = 0;
            do {
              *(undefined1 *)((long)pvVar8 + uVar12) = *(undefined1 *)(puVar2[1] + uVar12);
              uVar10 = puVar2[3];
              uVar12 = uVar12 + 1;
            } while (uVar12 < uVar10);
          }
          pvVar3 = (void *)*puVar2;
          puVar2[2] = pvVar8;
          puVar2[4] = uVar11;
          *puVar2 = pvVar8;
          puVar2[1] = pvVar8;
          if (pvVar3 != (void *)0x0) {
            operator_delete__(pvVar3);
            pvVar8 = (void *)puVar2[1];
            uVar10 = puVar2[3];
          }
          *(char *)((long)pvVar8 + uVar10) = (char)uVar4;
          puVar2[3] = puVar2[3] + 1;
        }
        else {
          *(char *)(puVar2[1] + puVar2[3]) = (char)uVar4;
          puVar2[3] = puVar2[3] + 1;
        }
      }
      else if (*(long *)(param_1 + 1000) == 0) {
        FUN_00122170(param_1 + 0x2e8,param_2,uVar4);
      }
      else {
        FUN_001143e0(*(long *)(param_1 + 1000),param_2);
      }
      lVar6 = *(long *)(param_1 + 0x400);
      param_3 = (ulong)*(uint *)(lVar6 + uVar5 * 0xc);
      if (param_3 == 0) {
        return;
      }
    }
    bVar1 = *(byte *)(*(long *)(param_1 + 0x280) + param_3);
    if ((*(ulong *)(*(long *)(param_1 + 0x1b0) + (param_3 >> 6) * 8) >> (param_3 & 0x3f) & 1) == 0)
    {
      uVar10 = puVar2[3];
      uVar11 = puVar2[4];
      uVar5 = uVar10 + 1;
      if (uVar11 < uVar5) {
        if (uVar5 >> 1 < uVar11) {
          uVar5 = 0xffffffffffffffff;
          if (-1 < (long)uVar11) {
            uVar5 = uVar11 * 2;
          }
        }
        pvVar8 = operator_new__(uVar5,(nothrow_t *)PTR_nothrow_00132fb8);
        uVar10 = 0;
        if (puVar2[3] != 0) {
          uVar11 = 0;
          do {
            *(undefined1 *)((long)pvVar8 + uVar11) = *(undefined1 *)(puVar2[1] + uVar11);
            uVar10 = puVar2[3];
            uVar11 = uVar11 + 1;
          } while (uVar11 < uVar10);
        }
        pvVar3 = (void *)*puVar2;
        puVar2[2] = pvVar8;
        puVar2[4] = uVar5;
        *puVar2 = pvVar8;
        puVar2[1] = pvVar8;
        if (pvVar3 != (void *)0x0) {
          operator_delete__(pvVar3);
          pvVar8 = (void *)puVar2[1];
          uVar10 = puVar2[3];
        }
      }
      else {
        pvVar8 = (void *)puVar2[1];
      }
      *(byte *)((long)pvVar8 + uVar10) = bVar1;
      puVar2[3] = puVar2[3] + 1;
    }
    else {
      lVar6 = FUN_00124bd0(param_1 + 0x1a0,param_3);
      uVar5 = lVar6 * *(long *)(param_1 + 0x2d0);
      uVar4 = (uint)uVar5 & 0x3f;
      uVar5 = uVar5 >> 6;
      sVar9 = (sbyte)uVar4;
      if (*(long *)(param_1 + 0x2d0) + (ulong)uVar4 < 0x41) {
        uVar4 = (uint)(*(ulong *)(*(long *)(param_1 + 0x2b0) + uVar5 * 8) >> sVar9) &
                *(uint *)(param_1 + 0x2d8);
      }
      else {
        uVar4 = ((uint)(*(long *)(*(long *)(param_1 + 0x2b0) + 8 + uVar5 * 8) <<
                       (0x40U - sVar9 & 0x3f)) |
                (uint)(*(ulong *)(*(long *)(param_1 + 0x2b0) + uVar5 * 8) >> sVar9)) &
                *(uint *)(param_1 + 0x2d8);
      }
      if (*(long *)(param_1 + 1000) == 0) {
        FUN_00122170(param_1 + 0x2e8,param_2,uVar4 << 8 | (uint)bVar1);
      }
      else {
        FUN_001143e0(*(long *)(param_1 + 1000),param_2);
      }
    }
    if (param_3 <= *(ulong *)(param_1 + 0x428)) break;
    lVar7 = FUN_00124f80(param_1,param_3);
    lVar6 = *(long *)(param_1 + 0x400);
    param_3 = (lVar7 - param_3) - 1;
  }
  return;
}


//===== FUN_00114730 @ 00114730 size=861 =====

void FUN_00114730(long param_1,long param_2)

{
  byte bVar1;
  undefined1 uVar2;
  void *pvVar3;
  undefined8 uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined8 *puVar8;
  void *pvVar9;
  long lVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  sbyte sVar13;
  ulong uVar14;
  ulong uVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  ulong uVar18;
  
  uVar18 = *(ulong *)(param_2 + 0x10);
  if (*(ulong *)(param_1 + 0x108) <= uVar18) {
    puVar8 = (undefined8 *)__cxa_allocate_exception(0x20);
    puVar8[2] = 0x300000049;
    puVar8[3] = 
    "../src_udic/marisa_u/grimoire/trie/louds-trie.cpp:73: MARISA_BOUND_ERROR: agent.query().id() >= size()"
    ;
    *puVar8 = &PTR_FUN_00132da8;
    puVar8[1] = "../src_udic/marisa_u/grimoire/trie/louds-trie.cpp";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar8,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  puVar8 = *(undefined8 **)(param_2 + 0x28);
  puVar8[3] = 0;
  uVar14 = puVar8[4];
  if (uVar14 < 0x20) {
    uVar18 = uVar14 * 2;
    if (uVar14 < 0x11) {
      uVar18 = 0x20;
    }
    pvVar9 = operator_new__(uVar18,(nothrow_t *)PTR_nothrow_00132fb8);
    uVar14 = 0;
    if (puVar8[3] != 0) {
      do {
        *(undefined1 *)((long)pvVar9 + uVar14) = *(undefined1 *)(puVar8[1] + uVar14);
        uVar14 = uVar14 + 1;
      } while (uVar14 < (ulong)puVar8[3]);
    }
    pvVar3 = (void *)*puVar8;
    puVar8[2] = pvVar9;
    puVar8[4] = uVar18;
    *puVar8 = pvVar9;
    puVar8[1] = pvVar9;
    if (pvVar3 != (void *)0x0) {
      operator_delete__(pvVar3);
    }
    uVar18 = *(ulong *)(param_2 + 0x10);
  }
  *(undefined4 *)((long)puVar8 + 0x6c) = 0;
  uVar5 = FUN_00124f80(param_1 + 0xd0,uVar18);
  *(uint *)(puVar8 + 0xc) = uVar5;
  if (uVar5 != 0) {
    do {
      uVar18 = puVar8[3];
      bVar1 = *(byte *)(*(long *)(param_1 + 0x280) + (ulong)uVar5);
      if ((*(ulong *)(*(long *)(param_1 + 0x1b0) + (ulong)(uVar5 >> 6) * 8) >> ((ulong)uVar5 & 0x3f)
          & 1) == 0) {
        uVar15 = puVar8[4];
        uVar14 = uVar18 + 1;
        if (uVar15 < uVar14) {
          if (uVar14 >> 1 < uVar15) {
            uVar14 = 0xffffffffffffffff;
            if (-1 < (long)uVar15) {
              uVar14 = uVar15 * 2;
            }
          }
          pvVar9 = operator_new__(uVar14,(nothrow_t *)PTR_nothrow_00132fb8);
          uVar18 = 0;
          if (puVar8[3] != 0) {
            uVar15 = 0;
            do {
              *(undefined1 *)((long)pvVar9 + uVar15) = *(undefined1 *)(puVar8[1] + uVar15);
              uVar18 = puVar8[3];
              uVar15 = uVar15 + 1;
            } while (uVar15 < uVar18);
          }
          pvVar3 = (void *)*puVar8;
          puVar8[2] = pvVar9;
          puVar8[4] = uVar14;
          *puVar8 = pvVar9;
          puVar8[1] = pvVar9;
          if (pvVar3 != (void *)0x0) {
            operator_delete__(pvVar3);
            pvVar9 = (void *)puVar8[1];
            uVar18 = puVar8[3];
          }
        }
        else {
          pvVar9 = (void *)puVar8[1];
        }
        *(byte *)((long)pvVar9 + uVar18) = bVar1;
        puVar8[3] = puVar8[3] + 1;
LAB_001148d6:
        if ((ulong)*(uint *)(puVar8 + 0xc) <= *(ulong *)(param_1 + 0x428)) goto LAB_001149ec;
      }
      else {
        lVar10 = FUN_00124bd0(param_1 + 0x1a0);
        uVar14 = lVar10 * *(long *)(param_1 + 0x2d0);
        uVar5 = (uint)uVar14 & 0x3f;
        uVar14 = uVar14 >> 6;
        sVar13 = (sbyte)uVar5;
        if (*(long *)(param_1 + 0x2d0) + (ulong)uVar5 < 0x41) {
          uVar5 = (uint)(*(ulong *)(*(long *)(param_1 + 0x2b0) + uVar14 * 8) >> sVar13) &
                  *(uint *)(param_1 + 0x2d8);
        }
        else {
          uVar5 = ((uint)(*(long *)(*(long *)(param_1 + 0x2b0) + 8 + uVar14 * 8) <<
                         (0x40U - sVar13 & 0x3f)) |
                  (uint)(*(ulong *)(*(long *)(param_1 + 0x2b0) + uVar14 * 8) >> sVar13)) &
                  *(uint *)(param_1 + 0x2d8);
        }
        if (*(long *)(param_1 + 1000) == 0) {
          FUN_00122170(param_1 + 0x2e8,param_2,uVar5 << 8 | (uint)bVar1);
        }
        else {
          FUN_001143e0(*(long *)(param_1 + 1000),param_2);
        }
        puVar16 = (undefined1 *)(puVar8[3] + puVar8[1]);
        puVar11 = (undefined1 *)(puVar8[1] + uVar18);
        if ((puVar11 == puVar16) || (puVar16 = puVar16 + -1, puVar16 <= puVar11)) goto LAB_001148d6;
        do {
          uVar2 = *puVar11;
          puVar12 = puVar11 + 1;
          puVar17 = puVar16 + -1;
          *puVar11 = *puVar16;
          *puVar16 = uVar2;
          puVar11 = puVar12;
          puVar16 = puVar17;
        } while (puVar12 < puVar17);
        if ((ulong)*(uint *)(puVar8 + 0xc) <= *(ulong *)(param_1 + 0x428)) goto LAB_001149ec;
      }
      iVar7 = FUN_00124f80(param_1);
      uVar5 = (iVar7 - *(int *)(puVar8 + 0xc)) - 1;
      *(uint *)(puVar8 + 0xc) = uVar5;
    } while( true );
  }
  uVar4 = puVar8[3];
  *(undefined8 *)(param_2 + 0x18) = puVar8[1];
  *(int *)(param_2 + 0x20) = (int)uVar4;
  uVar6 = *(undefined4 *)(param_2 + 0x10);
LAB_00114818:
  *(undefined4 *)(param_2 + 0x24) = uVar6;
  return;
LAB_001149ec:
  puVar16 = (undefined1 *)puVar8[1];
  lVar10 = puVar8[3];
  puVar11 = puVar16 + lVar10;
  puVar12 = puVar11;
  if ((puVar16 != puVar11) && (puVar12 = puVar16, puVar17 = puVar11 + -1, puVar16 < puVar11 + -1)) {
    do {
      uVar2 = *puVar16;
      puVar12 = puVar16 + 1;
      puVar11 = puVar17 + -1;
      *puVar16 = *puVar17;
      *puVar17 = uVar2;
      puVar17 = puVar11;
      puVar16 = puVar12;
    } while (puVar12 < puVar11);
    lVar10 = puVar8[3];
    puVar12 = (undefined1 *)puVar8[1];
  }
  *(undefined1 **)(param_2 + 0x18) = puVar12;
  uVar6 = *(undefined4 *)(param_2 + 0x10);
  *(int *)(param_2 + 0x20) = (int)lVar10;
  goto LAB_00114818;
}


//===== FUN_00114ab0 @ 00114ab0 size=689 =====

undefined8 FUN_00114ab0(long param_1,long *param_2,ulong param_3)

{
  byte bVar1;
  long lVar2;
  char cVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  uint *puVar7;
  sbyte sVar8;
  long lVar9;
  
  lVar2 = param_2[5];
  lVar5 = *(long *)(param_1 + 0x400);
  while( true ) {
    while( true ) {
      lVar9 = (*(ulong *)(param_1 + 0x420) & param_3) * 0xc;
      puVar7 = (uint *)(lVar5 + lVar9);
      if (param_3 != puVar7[1]) break;
      if (puVar7[2] >> 8 == 0xffffff) {
        if (*(char *)(*param_2 + (ulong)*(uint *)(lVar2 + 100)) != (char)puVar7[2]) {
          return 0;
        }
        *(uint *)(lVar2 + 100) = *(uint *)(lVar2 + 100) + 1;
      }
      else {
        if (*(long *)(param_1 + 1000) == 0) {
          cVar3 = FUN_00122380(param_1 + 0x2e8,param_2);
        }
        else {
          cVar3 = FUN_00114ab0(*(long *)(param_1 + 1000),param_2);
        }
        if (cVar3 == '\0') {
          return 0;
        }
        lVar5 = *(long *)(param_1 + 0x400);
        puVar7 = (uint *)(lVar5 + lVar9);
      }
      param_3 = (ulong)*puVar7;
      if (param_3 == 0) {
        return 1;
      }
      if ((ulong)param_2[1] <= (ulong)*(uint *)(lVar2 + 100)) {
        return 0;
      }
    }
    bVar1 = *(byte *)(*(long *)(param_1 + 0x280) + param_3);
    if ((*(ulong *)(*(long *)(param_1 + 0x1b0) + (param_3 >> 6) * 8) >> (param_3 & 0x3f) & 1) == 0)
    {
      if (*(byte *)(*param_2 + (ulong)*(uint *)(lVar2 + 100)) != bVar1) {
        return 0;
      }
      *(uint *)(lVar2 + 100) = *(uint *)(lVar2 + 100) + 1;
    }
    else {
      if (*(long *)(param_1 + 1000) == 0) {
        lVar5 = FUN_00124bd0(param_1 + 0x1a0,param_3);
        uVar6 = lVar5 * *(long *)(param_1 + 0x2d0);
        uVar4 = (uint)uVar6 & 0x3f;
        uVar6 = uVar6 >> 6;
        sVar8 = (sbyte)uVar4;
        if (*(long *)(param_1 + 0x2d0) + (ulong)uVar4 < 0x41) {
          uVar4 = (uint)(*(ulong *)(*(long *)(param_1 + 0x2b0) + uVar6 * 8) >> sVar8) &
                  *(uint *)(param_1 + 0x2d8);
        }
        else {
          uVar4 = ((uint)(*(long *)(*(long *)(param_1 + 0x2b0) + 8 + uVar6 * 8) <<
                         (0x40U - sVar8 & 0x3f)) |
                  (uint)(*(ulong *)(*(long *)(param_1 + 0x2b0) + uVar6 * 8) >> sVar8)) &
                  *(uint *)(param_1 + 0x2d8);
        }
        cVar3 = FUN_00122380(param_1 + 0x2e8,param_2,uVar4 << 8 | (uint)bVar1);
      }
      else {
        lVar5 = FUN_00124bd0(param_1 + 0x1a0,param_3);
        uVar6 = lVar5 * *(long *)(param_1 + 0x2d0);
        uVar4 = (uint)uVar6 & 0x3f;
        uVar6 = uVar6 >> 6;
        sVar8 = (sbyte)uVar4;
        if (*(long *)(param_1 + 0x2d0) + (ulong)uVar4 < 0x41) {
          uVar4 = (uint)(*(ulong *)(*(long *)(param_1 + 0x2b0) + uVar6 * 8) >> sVar8) &
                  *(uint *)(param_1 + 0x2d8);
        }
        else {
          uVar4 = ((uint)(*(long *)(*(long *)(param_1 + 0x2b0) + 8 + uVar6 * 8) <<
                         (0x40U - sVar8 & 0x3f)) |
                  (uint)(*(ulong *)(*(long *)(param_1 + 0x2b0) + uVar6 * 8) >> sVar8)) &
                  *(uint *)(param_1 + 0x2d8);
        }
        if (*(long *)(param_1 + 1000) == 0) {
          cVar3 = FUN_00122380(param_1 + 0x2e8,param_2,uVar4 << 8 | (uint)bVar1);
        }
        else {
          cVar3 = FUN_00114ab0(*(long *)(param_1 + 1000),param_2);
        }
      }
      if (cVar3 == '\0') {
        return 0;
      }
    }
    if (param_3 <= *(ulong *)(param_1 + 0x428)) {
      return 1;
    }
    if ((ulong)param_2[1] <= (ulong)*(uint *)(lVar2 + 100)) break;
    lVar9 = FUN_00124f80(param_1,param_3);
    lVar5 = *(long *)(param_1 + 0x400);
    param_3 = (lVar9 - param_3) - 1;
  }
  return 0;
}


//===== FUN_00114d90 @ 00114d90 size=821 =====

uint FUN_00114d90(long param_1,long *param_2)

{
  int iVar1;
  long lVar2;
  ulong *puVar3;
  long lVar4;
  char cVar5;
  undefined4 uVar6;
  ulong uVar7;
  uint *puVar8;
  long lVar9;
  ulong uVar10;
  ulong uVar11;
  sbyte sVar12;
  uint uVar13;
  uint uVar14;
  long lVar15;
  ulong uVar16;
  
  lVar2 = param_2[5];
  if (*(int *)(lVar2 + 0x6c) == 3) {
    return 0;
  }
  if (*(int *)(lVar2 + 0x6c) == 1) {
    uVar16 = (ulong)*(uint *)(lVar2 + 100);
  }
  else {
    puVar3 = *(ulong **)(param_1 + 0xe0);
    *(undefined8 *)(lVar2 + 0x60) = 0;
    uVar16 = 0;
    *(undefined4 *)(lVar2 + 0x6c) = 1;
    uVar7 = *puVar3;
    if ((uVar7 & 1) != 0) {
      *(undefined4 *)(param_2 + 4) = 0;
      param_2[3] = *param_2;
      uVar6 = FUN_00124bd0(param_1 + 0xd0,0);
      *(undefined4 *)((long)param_2 + 0x24) = uVar6;
      return (uint)uVar7 & 1;
    }
  }
LAB_00114e95:
  if ((ulong)param_2[1] <= uVar16) {
LAB_00115058:
    *(undefined4 *)(lVar2 + 0x6c) = 3;
    return 0;
  }
  lVar4 = param_2[5];
  uVar16 = (ulong)*(uint *)(lVar4 + 0x60);
  lVar15 = (((ulong)*(byte *)(*param_2 + (ulong)*(uint *)(lVar4 + 100)) ^ uVar16 << 5 ^ uVar16) &
           *(ulong *)(param_1 + 0x420)) * 0xc;
  puVar8 = (uint *)(*(long *)(param_1 + 0x400) + lVar15);
  if (uVar16 != *puVar8) {
    lVar9 = FUN_00124d20(param_1);
    lVar15 = *(long *)(param_1 + 0x10);
    uVar16 = lVar9 + 1;
    if ((*(ulong *)(lVar15 + (uVar16 >> 6) * 8) >> (uVar16 & 0x3f) & 1) != 0) {
      lVar9 = 0xffffffff;
      uVar14 = ((int)uVar16 - *(int *)(lVar4 + 0x60)) - 1;
      *(uint *)(lVar4 + 0x60) = uVar14;
      do {
        uVar7 = (ulong)uVar14;
        if ((*(ulong *)(*(long *)(param_1 + 0x1b0) + (ulong)(uVar14 >> 6) * 8) >> (uVar7 & 0x3f) & 1
            ) == 0) {
          if (*(char *)(*(long *)(param_1 + 0x280) + uVar7) ==
              *(char *)(*param_2 + (ulong)*(uint *)(lVar4 + 100))) goto code_r0x00115032;
        }
        else {
          if (lVar9 == 0xffffffff) {
            lVar9 = FUN_00124bd0(param_1 + 0x1a0);
            uVar7 = (ulong)*(uint *)(lVar4 + 0x60);
          }
          else {
            lVar9 = lVar9 + 1;
          }
          iVar1 = *(int *)(lVar4 + 100);
          uVar10 = lVar9 * *(long *)(param_1 + 0x2d0);
          uVar11 = uVar10 >> 6;
          uVar13 = (uint)uVar10 & 0x3f;
          sVar12 = (sbyte)uVar13;
          uVar14 = (uint)(*(ulong *)(*(long *)(param_1 + 0x2b0) + uVar11 * 8) >> sVar12);
          if (0x40 < *(long *)(param_1 + 0x2d0) + (ulong)uVar13) {
            uVar14 = uVar14 | (uint)(*(long *)(*(long *)(param_1 + 0x2b0) + 8 + uVar11 * 8) <<
                                    (0x40U - sVar12 & 0x3f));
          }
          if (*(long *)(param_1 + 1000) == 0) {
            cVar5 = FUN_00122380(param_1 + 0x2e8,param_2,
                                 (*(uint *)(param_1 + 0x2d8) & uVar14) << 8 |
                                 (uint)*(byte *)(*(long *)(param_1 + 0x280) + uVar7));
          }
          else {
            cVar5 = FUN_00114ab0(*(long *)(param_1 + 1000),param_2);
          }
          if (cVar5 != '\0') goto LAB_00114e65;
          if (iVar1 != *(int *)(lVar4 + 100)) break;
          uVar14 = *(uint *)(lVar4 + 0x60);
          lVar15 = *(long *)(param_1 + 0x10);
        }
        uVar16 = uVar16 + 1;
        uVar14 = uVar14 + 1;
        *(uint *)(lVar4 + 0x60) = uVar14;
        if ((*(ulong *)(lVar15 + (uVar16 >> 6) * 8) >> (uVar16 & 0x3f) & 1) == 0) break;
      } while( true );
    }
    goto LAB_00115058;
  }
  if (puVar8[2] >> 8 == 0xffffff) {
    *(uint *)(lVar4 + 100) = *(uint *)(lVar4 + 100) + 1;
  }
  else {
    if (*(long *)(param_1 + 1000) == 0) {
      cVar5 = FUN_00122380(param_1 + 0x2e8,param_2);
    }
    else {
      cVar5 = FUN_00114ab0(*(long *)(param_1 + 1000),param_2);
    }
    if (cVar5 == '\0') goto LAB_00115058;
    puVar8 = (uint *)(*(long *)(param_1 + 0x400) + lVar15);
  }
  *(uint *)(lVar4 + 0x60) = puVar8[1];
  goto LAB_00114e65;
code_r0x00115032:
  *(uint *)(lVar4 + 100) = *(uint *)(lVar4 + 100) + 1;
LAB_00114e65:
  uVar16 = (ulong)*(uint *)(lVar2 + 100);
  uVar7 = *(ulong *)(*(long *)(param_1 + 0xe0) + (ulong)(*(uint *)(lVar2 + 0x60) >> 6) * 8) >>
          ((byte)*(uint *)(lVar2 + 0x60) & 0x3f);
  if ((uVar7 & 1) != 0) {
    *(uint *)(param_2 + 4) = *(uint *)(lVar2 + 100);
    param_2[3] = *param_2;
    uVar6 = FUN_00124bd0(param_1 + 0xd0);
    *(undefined4 *)((long)param_2 + 0x24) = uVar6;
    return (uint)uVar7 & 1;
  }
  goto LAB_00114e95;
}


//===== FUN_001150f0 @ 001150f0 size=766 =====

uint FUN_001150f0(long param_1,long *param_2)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  uint *puVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  sbyte sVar9;
  byte bVar10;
  uint uVar11;
  long lVar12;
  ulong uVar13;
  uint uVar14;
  ulong uVar15;
  long lVar16;
  
  lVar8 = param_2[5];
  uVar13 = param_2[1];
  *(undefined8 *)(lVar8 + 0x60) = 0;
  *(undefined4 *)(lVar8 + 0x6c) = 0;
  if (uVar13 == 0) {
    lVar8 = 0;
    uVar11 = 0;
    bVar10 = 0;
  }
  else {
    uVar6 = 0;
    uVar15 = 0;
    lVar16 = lVar8;
LAB_0011519e:
    lVar12 = (((ulong)*(byte *)(*param_2 + uVar15) ^ uVar6 << 5 ^ uVar6) &
             *(ulong *)(param_1 + 0x420)) * 0xc;
    puVar4 = (uint *)(*(long *)(param_1 + 0x400) + lVar12);
    if (uVar6 != *puVar4) {
      lVar5 = FUN_00124d20(param_1);
      lVar12 = *(long *)(param_1 + 0x10);
      uVar13 = lVar5 + 1;
      if ((*(ulong *)(lVar12 + (uVar13 >> 6) * 8) >> (uVar13 & 0x3f) & 1) != 0) {
        lVar5 = 0xffffffff;
        uVar11 = ((int)uVar13 - *(int *)(lVar16 + 0x60)) - 1;
        *(uint *)(lVar16 + 0x60) = uVar11;
        do {
          uVar15 = (ulong)uVar11;
          if ((*(ulong *)(*(long *)(param_1 + 0x1b0) + (ulong)(uVar11 >> 6) * 8) >> (uVar15 & 0x3f)
              & 1) == 0) {
            if (*(char *)(*(long *)(param_1 + 0x280) + uVar15) ==
                *(char *)(*param_2 + (ulong)*(uint *)(lVar16 + 100))) goto code_r0x00115322;
          }
          else {
            if (lVar5 == 0xffffffff) {
              lVar5 = FUN_00124bd0(param_1 + 0x1a0);
              uVar15 = (ulong)*(uint *)(lVar16 + 0x60);
            }
            else {
              lVar5 = lVar5 + 1;
            }
            iVar1 = *(int *)(lVar16 + 100);
            uVar6 = lVar5 * *(long *)(param_1 + 0x2d0);
            uVar7 = uVar6 >> 6;
            uVar14 = (uint)uVar6 & 0x3f;
            sVar9 = (sbyte)uVar14;
            uVar11 = (uint)(*(ulong *)(*(long *)(param_1 + 0x2b0) + uVar7 * 8) >> sVar9);
            if (0x40 < *(long *)(param_1 + 0x2d0) + (ulong)uVar14) {
              uVar11 = uVar11 | (uint)(*(long *)(*(long *)(param_1 + 0x2b0) + 8 + uVar7 * 8) <<
                                      (0x40U - sVar9 & 0x3f));
            }
            if (*(long *)(param_1 + 1000) == 0) {
              cVar2 = FUN_00122380(param_1 + 0x2e8,param_2,
                                   (*(uint *)(param_1 + 0x2d8) & uVar11) << 8 |
                                   (uint)*(byte *)(*(long *)(param_1 + 0x280) + uVar15));
            }
            else {
              cVar2 = FUN_00114ab0(*(long *)(param_1 + 1000),param_2);
            }
            if (cVar2 != '\0') goto LAB_00115329;
            if (iVar1 != *(int *)(lVar16 + 100)) break;
            uVar11 = *(uint *)(lVar16 + 0x60);
            lVar12 = *(long *)(param_1 + 0x10);
          }
          uVar13 = uVar13 + 1;
          uVar11 = uVar11 + 1;
          *(uint *)(lVar16 + 0x60) = uVar11;
          if ((*(ulong *)(lVar12 + (uVar13 >> 6) * 8) >> (uVar13 & 0x3f) & 1) == 0) break;
        } while( true );
      }
      goto LAB_001153a8;
    }
    if (puVar4[2] >> 8 == 0xffffff) {
      *(int *)(lVar16 + 100) = (int)uVar15 + 1;
    }
    else {
      if (*(long *)(param_1 + 1000) == 0) {
        cVar2 = FUN_00122380(param_1 + 0x2e8,param_2);
      }
      else {
        cVar2 = FUN_00114ab0(*(long *)(param_1 + 1000),param_2);
      }
      if (cVar2 == '\0') goto LAB_001153a8;
      uVar13 = param_2[1];
      puVar4 = (uint *)(*(long *)(param_1 + 0x400) + lVar12);
    }
    *(uint *)(lVar16 + 0x60) = puVar4[1];
    if (*(uint *)(lVar8 + 100) < uVar13) goto LAB_00115192;
LAB_0011533e:
    uVar11 = *(uint *)(lVar8 + 0x60);
    bVar10 = (byte)uVar11 & 0x3f;
    lVar8 = (ulong)(uVar11 >> 6) << 3;
  }
  uVar15 = *(ulong *)(*(long *)(param_1 + 0xe0) + lVar8) >> bVar10;
  uVar14 = (uint)uVar15 & 1;
  if ((uVar15 & 1) == 0) {
LAB_001153a8:
    uVar14 = 0;
  }
  else {
    *(int *)(param_2 + 4) = (int)uVar13;
    param_2[3] = *param_2;
    uVar3 = FUN_00124bd0(param_1 + 0xd0,uVar11);
    *(undefined4 *)((long)param_2 + 0x24) = uVar3;
  }
  return uVar14;
code_r0x00115322:
  *(uint *)(lVar16 + 100) = *(uint *)(lVar16 + 100) + 1;
LAB_00115329:
  uVar13 = param_2[1];
  if (uVar13 <= *(uint *)(lVar8 + 100)) goto LAB_0011533e;
LAB_00115192:
  lVar16 = param_2[5];
  uVar15 = (ulong)*(uint *)(lVar16 + 100);
  uVar6 = (ulong)*(uint *)(lVar16 + 0x60);
  goto LAB_0011519e;
}


//===== FUN_00115410 @ 00115410 size=844 =====

undefined8 FUN_00115410(long param_1,long *param_2,ulong param_3)

{
  byte bVar1;
  undefined8 *puVar2;
  void *pvVar3;
  char cVar4;
  uint uVar5;
  ulong uVar6;
  void *pvVar7;
  long lVar8;
  sbyte sVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  
  puVar2 = (undefined8 *)param_2[5];
  do {
    uVar6 = *(ulong *)(param_1 + 0x420) & param_3;
    lVar8 = *(long *)(param_1 + 0x400) + uVar6 * 0xc;
    if (param_3 == *(uint *)(lVar8 + 4)) {
      uVar5 = *(uint *)(lVar8 + 8);
      if (uVar5 >> 8 == 0xffffff) {
        if ((char)uVar5 != *(char *)(*param_2 + (ulong)*(uint *)((long)puVar2 + 100))) {
          return 0;
        }
        uVar10 = puVar2[3];
        uVar12 = puVar2[4];
        uVar11 = uVar10 + 1;
        if (uVar12 < uVar11) {
          if (uVar11 >> 1 < uVar12) {
            uVar11 = 0xffffffffffffffff;
            if (-1 < (long)uVar12) {
              uVar11 = uVar12 * 2;
            }
          }
          pvVar7 = operator_new__(uVar11,(nothrow_t *)PTR_nothrow_00132fb8);
          uVar10 = 0;
          if (puVar2[3] != 0) {
            uVar12 = 0;
            do {
              *(undefined1 *)((long)pvVar7 + uVar12) = *(undefined1 *)(puVar2[1] + uVar12);
              uVar10 = puVar2[3];
              uVar12 = uVar12 + 1;
            } while (uVar12 < uVar10);
          }
          pvVar3 = (void *)*puVar2;
          puVar2[2] = pvVar7;
          puVar2[4] = uVar11;
          *puVar2 = pvVar7;
          puVar2[1] = pvVar7;
          if (pvVar3 != (void *)0x0) {
            operator_delete__(pvVar3);
            pvVar7 = (void *)puVar2[1];
            uVar10 = puVar2[3];
          }
        }
        else {
          pvVar7 = (void *)puVar2[1];
        }
        *(char *)((long)pvVar7 + uVar10) = (char)uVar5;
        puVar2[3] = puVar2[3] + 1;
        *(int *)((long)puVar2 + 100) = *(int *)((long)puVar2 + 100) + 1;
      }
      else {
        if (*(long *)(param_1 + 1000) == 0) {
          cVar4 = FUN_00122420(param_1 + 0x2e8,param_2,uVar5);
        }
        else {
          cVar4 = FUN_00115410(*(long *)(param_1 + 1000),param_2);
        }
        if (cVar4 == '\0') {
          return 0;
        }
      }
      param_3 = (ulong)*(uint *)(*(long *)(param_1 + 0x400) + uVar6 * 0xc);
      if (param_3 == 0) {
        return 1;
      }
    }
    else {
      bVar1 = *(byte *)(*(long *)(param_1 + 0x280) + param_3);
      if ((*(ulong *)(*(long *)(param_1 + 0x1b0) + (param_3 >> 6) * 8) >> (param_3 & 0x3f) & 1) == 0
         ) {
        if (*(byte *)(*param_2 + (ulong)*(uint *)((long)puVar2 + 100)) != bVar1) {
          return 0;
        }
        uVar12 = puVar2[3];
        uVar11 = puVar2[4];
        uVar6 = uVar12 + 1;
        if (uVar11 < uVar6) {
          if (uVar6 >> 1 < uVar11) {
            uVar6 = 0xffffffffffffffff;
            if (-1 < (long)uVar11) {
              uVar6 = uVar11 * 2;
            }
          }
          pvVar7 = operator_new__(uVar6,(nothrow_t *)PTR_nothrow_00132fb8);
          uVar12 = 0;
          if (puVar2[3] != 0) {
            uVar11 = 0;
            do {
              *(undefined1 *)((long)pvVar7 + uVar11) = *(undefined1 *)(puVar2[1] + uVar11);
              uVar12 = puVar2[3];
              uVar11 = uVar11 + 1;
            } while (uVar11 < uVar12);
          }
          pvVar3 = (void *)*puVar2;
          puVar2[2] = pvVar7;
          puVar2[4] = uVar6;
          *puVar2 = pvVar7;
          puVar2[1] = pvVar7;
          if (pvVar3 != (void *)0x0) {
            operator_delete__(pvVar3);
            pvVar7 = (void *)puVar2[1];
            uVar12 = puVar2[3];
          }
        }
        else {
          pvVar7 = (void *)puVar2[1];
        }
        *(byte *)((long)pvVar7 + uVar12) = bVar1;
        puVar2[3] = puVar2[3] + 1;
        *(int *)((long)puVar2 + 100) = *(int *)((long)puVar2 + 100) + 1;
      }
      else {
        lVar8 = FUN_00124bd0(param_1 + 0x1a0,param_3);
        uVar6 = lVar8 * *(long *)(param_1 + 0x2d0);
        uVar5 = (uint)uVar6 & 0x3f;
        uVar6 = uVar6 >> 6;
        sVar9 = (sbyte)uVar5;
        if (*(long *)(param_1 + 0x2d0) + (ulong)uVar5 < 0x41) {
          uVar5 = (uint)(*(ulong *)(*(long *)(param_1 + 0x2b0) + uVar6 * 8) >> sVar9) &
                  *(uint *)(param_1 + 0x2d8);
        }
        else {
          uVar5 = ((uint)(*(long *)(*(long *)(param_1 + 0x2b0) + 8 + uVar6 * 8) <<
                         (0x40U - sVar9 & 0x3f)) |
                  (uint)(*(ulong *)(*(long *)(param_1 + 0x2b0) + uVar6 * 8) >> sVar9)) &
                  *(uint *)(param_1 + 0x2d8);
        }
        if (*(long *)(param_1 + 1000) == 0) {
          cVar4 = FUN_00122420(param_1 + 0x2e8,param_2,uVar5 << 8 | (uint)bVar1);
        }
        else {
          cVar4 = FUN_00115410(*(long *)(param_1 + 1000),param_2);
        }
        if (cVar4 == '\0') {
          return 0;
        }
      }
      if (param_3 <= *(ulong *)(param_1 + 0x428)) {
        return 1;
      }
      lVar8 = FUN_00124f80(param_1,param_3);
      param_3 = (lVar8 - param_3) - 1;
    }
    if ((ulong)param_2[1] <= (ulong)*(uint *)((long)puVar2 + 100)) {
      FUN_001143e0(param_1,param_2,param_3);
      return 1;
    }
  } while( true );
}


//===== FUN_00115790 @ 00115790 size=2908 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00115790(long param_1,long *param_2)

{
  int *piVar1;
  undefined8 *puVar2;
  undefined1 uVar3;
  int iVar4;
  undefined8 *puVar5;
  void *pvVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  char cVar9;
  undefined4 uVar10;
  int iVar11;
  ulong uVar12;
  ulong uVar13;
  long lVar14;
  void *pvVar15;
  uint *puVar16;
  long lVar17;
  long lVar18;
  sbyte sVar19;
  uint uVar20;
  uint uVar21;
  ulong uVar22;
  ulong uVar23;
  
  puVar5 = (undefined8 *)param_2[5];
  if (*(int *)((long)puVar5 + 0x6c) == 4) {
    return 0;
  }
  if (*(int *)((long)puVar5 + 0x6c) == 2) {
    uVar12 = (ulong)*(uint *)(puVar5 + 0xd);
    uVar22 = puVar5[9];
    pvVar15 = (void *)puVar5[7];
    goto LAB_001158dc;
  }
  uVar22 = puVar5[4];
  puVar5[3] = 0;
  if (uVar22 < 0x40) {
    uVar12 = uVar22 * 2;
    if (uVar22 < 0x21) {
      uVar12 = 0x40;
    }
    pvVar15 = operator_new__(uVar12,(nothrow_t *)PTR_nothrow_00132fb8);
    uVar22 = 0;
    if (puVar5[3] != 0) {
      do {
        *(undefined1 *)((long)pvVar15 + uVar22) = *(undefined1 *)(puVar5[1] + uVar22);
        uVar22 = uVar22 + 1;
      } while (uVar22 < (ulong)puVar5[3]);
    }
    pvVar6 = (void *)*puVar5;
    puVar5[2] = pvVar15;
    puVar5[4] = uVar12;
    *puVar5 = pvVar15;
    puVar5[1] = pvVar15;
    if (pvVar6 != (void *)0x0) {
      operator_delete__(pvVar6);
    }
  }
  uVar22 = puVar5[10];
  puVar5[9] = 0;
  if (uVar22 < 4) {
    uVar12 = 0x50;
    if (uVar22 == 3) {
      uVar12 = 0x78;
    }
    pvVar15 = operator_new__(uVar12,(nothrow_t *)PTR_nothrow_00132fb8);
    lVar14 = puVar5[9];
    if (lVar14 != 0) {
      lVar17 = puVar5[7];
      lVar18 = 0;
      do {
        puVar2 = (undefined8 *)(lVar17 + lVar18);
        uVar7 = puVar2[1];
        *(undefined8 *)((long)pvVar15 + lVar18) = *puVar2;
        ((undefined8 *)((long)pvVar15 + lVar18))[1] = uVar7;
        *(undefined4 *)((long)pvVar15 + lVar18 + 0x10) = *(undefined4 *)(lVar17 + 0x10 + lVar18);
        lVar18 = lVar18 + 0x14;
      } while (lVar18 != lVar14 * 0x14);
    }
    pvVar6 = (void *)puVar5[6];
    puVar5[8] = pvVar15;
    puVar5[10] = (ulong)(uVar22 == 3) * 2 + 4;
    puVar5[6] = pvVar15;
    puVar5[7] = pvVar15;
    if (pvVar6 != (void *)0x0) {
      operator_delete__(pvVar6);
    }
  }
  uVar7 = _UNK_0012a658;
  puVar5[0xc] = _DAT_0012a650;
  puVar5[0xd] = uVar7;
  if (param_2[1] != 0) {
LAB_00115b57:
    do {
      puVar2 = (undefined8 *)param_2[5];
      uVar22 = (ulong)*(uint *)(puVar2 + 0xc);
      lVar14 = (((ulong)*(byte *)(*param_2 + (ulong)*(uint *)((long)puVar2 + 100)) ^
                uVar22 << 5 ^ uVar22) & *(ulong *)(param_1 + 0x420)) * 0xc;
      puVar16 = (uint *)(*(long *)(param_1 + 0x400) + lVar14);
      if (uVar22 != *puVar16) {
        lVar17 = FUN_00124d20(param_1);
        lVar14 = *(long *)(param_1 + 0x10);
        uVar22 = lVar17 + 1;
        if ((*(ulong *)(lVar14 + (uVar22 >> 6) * 8) >> (uVar22 & 0x3f) & 1) != 0) {
          lVar17 = 0xffffffff;
          uVar21 = ((int)uVar22 - *(int *)(puVar2 + 0xc)) - 1;
          *(uint *)(puVar2 + 0xc) = uVar21;
          do {
            uVar12 = (ulong)uVar21;
            if ((*(ulong *)(*(long *)(param_1 + 0x1b0) + (ulong)(uVar21 >> 6) * 8) >>
                 (uVar12 & 0x3f) & 1) == 0) {
              cVar9 = *(char *)(*(long *)(param_1 + 0x280) + uVar12);
              if (cVar9 == *(char *)(*param_2 + (ulong)*(uint *)((long)puVar2 + 100)))
              goto code_r0x00115cf2;
            }
            else {
              if (lVar17 == 0xffffffff) {
                lVar17 = FUN_00124bd0(param_1 + 0x1a0);
                uVar12 = (ulong)*(uint *)(puVar2 + 0xc);
              }
              else {
                lVar17 = lVar17 + 1;
              }
              iVar4 = *(int *)((long)puVar2 + 100);
              uVar13 = lVar17 * *(long *)(param_1 + 0x2d0);
              uVar23 = uVar13 >> 6;
              uVar20 = (uint)uVar13 & 0x3f;
              sVar19 = (sbyte)uVar20;
              uVar21 = (uint)(*(ulong *)(*(long *)(param_1 + 0x2b0) + uVar23 * 8) >> sVar19);
              if (0x40 < *(long *)(param_1 + 0x2d0) + (ulong)uVar20) {
                uVar21 = uVar21 | (uint)(*(long *)(*(long *)(param_1 + 0x2b0) + 8 + uVar23 * 8) <<
                                        (0x40U - sVar19 & 0x3f));
              }
              if (*(long *)(param_1 + 1000) == 0) {
                cVar9 = FUN_00122420(param_1 + 0x2e8,param_2,
                                     (*(uint *)(param_1 + 0x2d8) & uVar21) << 8 |
                                     (uint)*(byte *)(*(long *)(param_1 + 0x280) + uVar12));
              }
              else {
                cVar9 = FUN_00115410(*(long *)(param_1 + 1000),param_2);
              }
              if (cVar9 != '\0') goto LAB_00115b49;
              if (iVar4 != *(int *)((long)puVar2 + 100)) break;
              uVar21 = *(uint *)(puVar2 + 0xc);
              lVar14 = *(long *)(param_1 + 0x10);
            }
            uVar22 = uVar22 + 1;
            uVar21 = uVar21 + 1;
            *(uint *)(puVar2 + 0xc) = uVar21;
            if ((*(ulong *)(lVar14 + (uVar22 >> 6) * 8) >> (uVar22 & 0x3f) & 1) == 0) break;
          } while( true );
        }
LAB_001159c0:
        *(undefined4 *)((long)puVar5 + 0x6c) = 4;
        return 0;
      }
      uVar21 = puVar16[2];
      if (uVar21 >> 8 == 0xffffff) {
        uVar12 = puVar2[4];
        uVar22 = puVar2[3] + 1;
        if (uVar12 < uVar22) {
          if ((uVar22 >> 1 < uVar12) && (uVar22 = uVar12 * 2, (long)uVar12 < 0)) {
            uVar22 = 0xffffffffffffffff;
          }
          pvVar15 = operator_new__(uVar22,(nothrow_t *)PTR_nothrow_00132fb8);
          uVar12 = 0;
          if (puVar2[3] != 0) {
            uVar13 = 0;
            do {
              *(undefined1 *)((long)pvVar15 + uVar13) = *(undefined1 *)(puVar2[1] + uVar13);
              uVar12 = puVar2[3];
              uVar13 = uVar13 + 1;
            } while (uVar13 < uVar12);
          }
          pvVar6 = (void *)*puVar2;
          puVar2[2] = pvVar15;
          puVar2[4] = uVar22;
          *puVar2 = pvVar15;
          puVar2[1] = pvVar15;
          if (pvVar6 != (void *)0x0) {
            operator_delete__(pvVar6);
            pvVar15 = (void *)puVar2[1];
            uVar12 = puVar2[3];
          }
          *(char *)((long)pvVar15 + uVar12) = (char)uVar21;
          puVar2[3] = puVar2[3] + 1;
          *(int *)((long)puVar2 + 100) = *(int *)((long)puVar2 + 100) + 1;
        }
        else {
          *(char *)(puVar2[1] + puVar2[3]) = (char)uVar21;
          puVar2[3] = puVar2[3] + 1;
          *(int *)((long)puVar2 + 100) = *(int *)((long)puVar2 + 100) + 1;
        }
      }
      else {
        if (*(long *)(param_1 + 1000) == 0) {
          cVar9 = FUN_00122420(param_1 + 0x2e8,param_2,uVar21);
        }
        else {
          cVar9 = FUN_00115410(*(long *)(param_1 + 1000),param_2);
        }
        if (cVar9 == '\0') goto LAB_001159c0;
      }
      *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)(*(long *)(param_1 + 0x400) + 4 + lVar14);
LAB_00115b49:
    } while ((ulong)*(uint *)((long)puVar5 + 100) < (ulong)param_2[1]);
    goto LAB_00115da5;
  }
  uVar21 = 0;
LAB_00115da9:
  lVar14 = puVar5[9];
  uVar12 = puVar5[10];
  uVar7 = puVar5[3];
  uVar22 = lVar14 + 1;
  if (uVar12 < uVar22) {
    if (uVar22 >> 1 < uVar12) {
      uVar13 = 0xfffffffffffffff0;
      uVar22 = 0xccccccccccccccc;
      if (uVar12 < 0x666666666666667) {
        uVar22 = uVar12 * 2;
        uVar13 = uVar12 * 0x28;
      }
    }
    else {
      uVar13 = uVar22 * 0x14;
    }
    pvVar15 = operator_new__(uVar13,(nothrow_t *)PTR_nothrow_00132fb8);
    lVar14 = puVar5[9];
    if (lVar14 != 0) {
      lVar17 = puVar5[7];
      lVar18 = 0;
      do {
        puVar2 = (undefined8 *)(lVar17 + lVar18);
        uVar8 = puVar2[1];
        *(undefined8 *)((long)pvVar15 + lVar18) = *puVar2;
        ((undefined8 *)((long)pvVar15 + lVar18))[1] = uVar8;
        *(undefined4 *)((long)pvVar15 + lVar18 + 0x10) = *(undefined4 *)(lVar17 + 0x10 + lVar18);
        lVar18 = lVar18 + 0x14;
      } while (lVar18 != lVar14 * 0x14);
    }
    pvVar6 = (void *)puVar5[6];
    puVar5[8] = pvVar15;
    puVar5[10] = uVar22;
    puVar5[6] = pvVar15;
    puVar5[7] = pvVar15;
    if (pvVar6 == (void *)0x0) {
      uVar13 = (ulong)*(uint *)(puVar5 + 0xc);
      uVar22 = lVar14 + 1;
    }
    else {
      operator_delete__(pvVar6);
      lVar14 = puVar5[9];
      uVar13 = (ulong)*(uint *)(puVar5 + 0xc);
      pvVar15 = (void *)puVar5[7];
      uVar22 = lVar14 + 1;
    }
  }
  else {
    pvVar15 = (void *)puVar5[7];
    uVar13 = (ulong)uVar21;
  }
  puVar16 = (uint *)((long)pvVar15 + lVar14 * 0x14);
  *puVar16 = uVar21;
  puVar16[1] = 0;
  puVar16[2] = (uint)uVar7;
  puVar16[3] = 0xffffffff;
  puVar16[4] = 0xffffffff;
  lVar14 = *(long *)(param_1 + 0xe0);
  puVar5[9] = uVar22;
  uVar23 = *(ulong *)(lVar14 + (uVar13 >> 6) * 8);
  *(undefined4 *)(puVar5 + 0xd) = 1;
  uVar12 = 1;
  uVar23 = uVar23 >> ((byte)uVar13 & 0x3f);
  if ((uVar23 & 1) != 0) {
    uVar7 = puVar5[3];
    param_2[3] = puVar5[1];
    *(int *)(param_2 + 4) = (int)uVar7;
    uVar10 = FUN_00124bd0(param_1 + 0xd0,uVar13);
    *(undefined4 *)((long)param_2 + 0x24) = uVar10;
    return (uint)((byte)uVar23 & 1);
  }
LAB_001158dc:
  do {
    uVar21 = (uint)uVar12;
    if (uVar12 == uVar22) {
      piVar1 = (int *)((long)pvVar15 + uVar22 * 0x14 + -0x14);
      iVar11 = FUN_00124d20(param_1,*piVar1);
      iVar4 = *piVar1;
      lVar14 = puVar5[9];
      uVar12 = puVar5[10];
      uVar22 = lVar14 + 1;
      if (uVar12 < uVar22) {
        if (uVar22 >> 1 < uVar12) {
          uVar13 = 0xfffffffffffffff0;
          uVar22 = 0xccccccccccccccc;
          if (uVar12 < 0x666666666666667) {
            uVar22 = uVar12 * 2;
            uVar13 = uVar12 * 0x28;
          }
        }
        else {
          uVar13 = uVar22 * 0x14;
        }
        pvVar15 = operator_new__(uVar13,(nothrow_t *)PTR_nothrow_00132fb8);
        lVar14 = puVar5[9];
        if (lVar14 != 0) {
          lVar17 = puVar5[7];
          lVar18 = 0;
          do {
            puVar2 = (undefined8 *)(lVar17 + lVar18);
            uVar7 = puVar2[1];
            *(undefined8 *)((long)pvVar15 + lVar18) = *puVar2;
            ((undefined8 *)((long)pvVar15 + lVar18))[1] = uVar7;
            *(undefined4 *)((long)pvVar15 + lVar18 + 0x10) = *(undefined4 *)(lVar17 + 0x10 + lVar18)
            ;
            lVar18 = lVar18 + 0x14;
          } while (lVar18 != lVar14 * 0x14);
        }
        pvVar6 = (void *)puVar5[6];
        puVar5[8] = pvVar15;
        puVar5[10] = uVar22;
        puVar5[6] = pvVar15;
        puVar5[7] = pvVar15;
        if (pvVar6 != (void *)0x0) {
          operator_delete__(pvVar6);
          pvVar15 = (void *)puVar5[7];
          lVar14 = puVar5[9];
        }
        uVar22 = lVar14 + 1;
      }
      else {
        pvVar15 = (void *)puVar5[7];
      }
      uVar7 = DAT_0012a640;
      puVar2 = (undefined8 *)((long)pvVar15 + lVar14 * 0x14);
      *puVar2 = CONCAT44(iVar11 + 1,((iVar11 + 1) - iVar4) + -1);
      puVar2[1] = uVar7;
      *(undefined4 *)(puVar2 + 2) = 0xffffffff;
      uVar21 = *(uint *)(puVar5 + 0xd);
      uVar12 = (ulong)uVar21;
      puVar5[9] = uVar22;
    }
    puVar16 = (uint *)((long)pvVar15 + uVar12 * 0x14);
    uVar20 = puVar16[1];
    uVar22 = *(ulong *)(*(long *)(param_1 + 0x10) + (ulong)(uVar20 >> 6) * 8) >>
             ((byte)uVar20 & 0x3f);
    puVar16[1] = uVar20 + 1;
    if ((uVar22 & 1) == 0) {
      if (uVar12 == 1) {
        *(undefined4 *)((long)puVar5 + 0x6c) = 4;
        return (uint)uVar22 & 1;
      }
      lVar14 = (uVar12 * 5 + -5) * 4;
      piVar1 = (int *)((long)pvVar15 + lVar14);
      *piVar1 = *piVar1 + 1;
      uVar20 = *(uint *)((long)pvVar15 + lVar14 + -0xc);
      uVar12 = (ulong)uVar20;
      uVar22 = puVar5[4];
      if (uVar22 < uVar12) {
        uVar13 = uVar22 * 2;
        if (uVar22 <= uVar20 >> 1) {
          uVar13 = uVar12;
        }
        pvVar15 = operator_new__(uVar13,(nothrow_t *)PTR_nothrow_00132fb8);
        uVar22 = 0;
        if (puVar5[3] != 0) {
          do {
            *(undefined1 *)((long)pvVar15 + uVar22) = *(undefined1 *)(puVar5[1] + uVar22);
            uVar22 = uVar22 + 1;
          } while (uVar22 < (ulong)puVar5[3]);
        }
        pvVar6 = (void *)*puVar5;
        puVar5[2] = pvVar15;
        puVar5[4] = uVar13;
        *puVar5 = pvVar15;
        puVar5[1] = pvVar15;
        if (pvVar6 != (void *)0x0) {
          operator_delete__(pvVar6);
        }
        uVar21 = *(uint *)(puVar5 + 0xd);
        pvVar15 = (void *)puVar5[7];
      }
      uVar21 = uVar21 - 1;
      puVar5[3] = uVar12;
      *(uint *)(puVar5 + 0xd) = uVar21;
    }
    else {
      lVar14 = *(long *)(param_1 + 0x1b0);
      *(uint *)(puVar5 + 0xd) = uVar21 + 1;
      uVar22 = (ulong)*puVar16;
      if ((*(ulong *)(lVar14 + (ulong)(*puVar16 >> 6) * 8) >> (uVar22 & 0x3f) & 1) == 0) {
        uVar13 = puVar5[3];
        uVar3 = *(undefined1 *)(*(long *)(param_1 + 0x280) + uVar22);
        uVar12 = puVar5[4];
        uVar22 = uVar13 + 1;
        if (uVar12 < uVar22) {
          if ((uVar22 >> 1 < uVar12) && (uVar22 = uVar12 * 2, (long)uVar12 < 0)) {
            uVar22 = 0xffffffffffffffff;
          }
          pvVar15 = operator_new__(uVar22,(nothrow_t *)PTR_nothrow_00132fb8);
          uVar13 = 0;
          if (puVar5[3] != 0) {
            uVar12 = 0;
            do {
              *(undefined1 *)((long)pvVar15 + uVar12) = *(undefined1 *)(puVar5[1] + uVar12);
              uVar13 = puVar5[3];
              uVar12 = uVar12 + 1;
            } while (uVar12 < uVar13);
          }
          pvVar6 = (void *)*puVar5;
          puVar5[2] = pvVar15;
          puVar5[4] = uVar22;
          *puVar5 = pvVar15;
          puVar5[1] = pvVar15;
          if (pvVar6 != (void *)0x0) {
            operator_delete__(pvVar6);
            pvVar15 = (void *)puVar5[1];
            uVar13 = puVar5[3];
          }
        }
        else {
          pvVar15 = (void *)puVar5[1];
        }
        *(undefined1 *)((long)pvVar15 + uVar13) = uVar3;
        lVar14 = puVar5[3] + 1;
        puVar5[3] = lVar14;
      }
      else {
        uVar12 = (ulong)puVar16[3] + 1;
        uVar13 = uVar12;
        if ((ulong)puVar16[3] == 0xffffffff) {
          uVar13 = FUN_00124bd0(param_1 + 0x1a0);
          uVar22 = (ulong)*puVar16;
          uVar12 = uVar13 & 0xffffffff;
        }
        puVar16[3] = (uint)uVar13;
        uVar12 = uVar12 * *(long *)(param_1 + 0x2d0);
        uVar13 = uVar12 >> 6;
        uVar20 = (uint)uVar12 & 0x3f;
        sVar19 = (sbyte)uVar20;
        uVar21 = (uint)(*(ulong *)(*(long *)(param_1 + 0x2b0) + uVar13 * 8) >> sVar19);
        if (0x40 < *(long *)(param_1 + 0x2d0) + (ulong)uVar20) {
          uVar21 = uVar21 | (uint)(*(long *)(*(long *)(param_1 + 0x2b0) + 8 + uVar13 * 8) <<
                                  (0x40U - sVar19 & 0x3f));
        }
        if (*(long *)(param_1 + 1000) == 0) {
          FUN_00122170(param_1 + 0x2e8,param_2,
                       (*(uint *)(param_1 + 0x2d8) & uVar21) << 8 |
                       (uint)*(byte *)(*(long *)(param_1 + 0x280) + uVar22));
          lVar14 = puVar5[3];
        }
        else {
          FUN_001143e0(*(long *)(param_1 + 1000),param_2);
          lVar14 = puVar5[3];
        }
      }
      puVar16[2] = (uint)lVar14;
      uVar22 = *(ulong *)(*(long *)(param_1 + 0xe0) + (ulong)(*puVar16 >> 6) * 8) >>
               ((byte)*puVar16 & 0x3f);
      if ((uVar22 & 1) != 0) {
        if (puVar16[4] == 0xffffffff) {
          uVar21 = FUN_00124bd0(param_1 + 0xd0);
          uVar10 = *(undefined4 *)(puVar5 + 3);
          puVar16[4] = uVar21;
          lVar14 = CONCAT44(uVar21,uVar10);
        }
        else {
          uVar21 = puVar16[4] + 1;
          puVar16[4] = uVar21;
          lVar14 = CONCAT44(uVar21,(uint)lVar14);
        }
        lVar17 = puVar5[1];
        param_2[4] = lVar14;
        param_2[3] = lVar17;
        return (uint)uVar22 & 1;
      }
      uVar21 = *(uint *)(puVar5 + 0xd);
      pvVar15 = (void *)puVar5[7];
    }
    uVar12 = (ulong)uVar21;
    uVar22 = puVar5[9];
  } while( true );
code_r0x00115cf2:
  uVar13 = puVar2[3];
  uVar12 = puVar2[4];
  uVar22 = uVar13 + 1;
  if (uVar12 < uVar22) {
    if ((uVar22 >> 1 < uVar12) && (uVar22 = uVar12 * 2, (long)uVar12 < 0)) {
      uVar22 = 0xffffffffffffffff;
    }
    pvVar15 = operator_new__(uVar22,(nothrow_t *)PTR_nothrow_00132fb8);
    uVar13 = 0;
    if (puVar2[3] != 0) {
      uVar12 = 0;
      do {
        *(undefined1 *)((long)pvVar15 + uVar12) = *(undefined1 *)(puVar2[1] + uVar12);
        uVar13 = puVar2[3];
        uVar12 = uVar12 + 1;
      } while (uVar12 < uVar13);
    }
    pvVar6 = (void *)*puVar2;
    puVar2[2] = pvVar15;
    puVar2[4] = uVar22;
    *puVar2 = pvVar15;
    puVar2[1] = pvVar15;
    if (pvVar6 != (void *)0x0) {
      operator_delete__(pvVar6);
      pvVar15 = (void *)puVar2[1];
      uVar13 = puVar2[3];
    }
  }
  else {
    pvVar15 = (void *)puVar2[1];
  }
  *(char *)((long)pvVar15 + uVar13) = cVar9;
  *(int *)((long)puVar2 + 100) = *(int *)((long)puVar2 + 100) + 1;
  uVar21 = *(uint *)((long)puVar5 + 100);
  puVar2[3] = puVar2[3] + 1;
  if ((ulong)param_2[1] <= (ulong)uVar21) goto LAB_00115da5;
  goto LAB_00115b57;
LAB_00115da5:
  uVar21 = *(uint *)(puVar5 + 0xc);
  goto LAB_00115da9;
}


//===== FUN_00116340 @ 00116340 size=1318 =====

void FUN_00116340(long param_1,undefined8 param_2)

{
  uint uVar1;
  ulong uVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  ulong *puVar5;
  undefined8 uVar6;
  uint *puVar7;
  undefined4 *puVar8;
  void *pvVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  ulong uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  void *pvVar16;
  char *pcStack_50;
  undefined **local_48;
  char *pcStack_40;
  
  FUN_00119590();
  FUN_00119590(param_1 + 0xd0,param_2);
  FUN_00119590(param_1 + 0x1a0,param_2);
  puVar3 = (undefined8 *)FUN_00110420(param_2,8);
  uVar6 = *puVar3;
  uVar4 = FUN_00110420(param_2,uVar6);
  FUN_00110490(param_2,-(int)uVar6 & 7);
  pvVar9 = *(void **)(param_1 + 0x270);
  *(undefined8 *)(param_1 + 0x280) = uVar4;
  *(undefined8 *)(param_1 + 0x288) = uVar6;
  *(undefined8 *)(param_1 + 0x290) = 0;
  *(undefined1 *)(param_1 + 0x298) = 1;
  *(undefined1 (*) [16])(param_1 + 0x270) = (undefined1  [16])0x0;
  if (pvVar9 != (void *)0x0) {
    operator_delete__(pvVar9);
  }
  puVar5 = (ulong *)FUN_00110420(param_2,8);
  uVar2 = *puVar5;
  if ((uVar2 & 7) != 0) {
    FUN_001066ea();
    goto LAB_00106e1a;
  }
  uVar6 = FUN_00110420(param_2,uVar2 & 0xfffffffffffffff8);
  FUN_00110490(param_2,-(int)uVar2 & 7);
  puVar7 = (uint *)FUN_00110420(param_2,4);
  uVar1 = *puVar7;
  if (0x20 < uVar1) {
    puVar3 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar3 = &PTR_FUN_00132da8;
    puVar3[1] = "../src_udic/marisa_u/grimoire/trie/../vector/flat-vector.h";
    puVar3[2] = 0xa00000091;
    puVar3[3] = 
    "../src_udic/marisa_u/grimoire/trie/../vector/flat-vector.h:145: MARISA_FORMAT_ERROR: temp_value_size > 32"
    ;
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar3,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  puVar8 = (undefined4 *)FUN_00110420(param_2,4);
  uVar12 = *puVar8;
  puVar3 = (undefined8 *)FUN_00110420(param_2,8);
  pvVar9 = *(void **)(param_1 + 0x2a0);
  uVar4 = *puVar3;
  *(undefined8 *)(param_1 + 0x2b0) = uVar6;
  *(ulong *)(param_1 + 0x2b8) = uVar2 >> 3;
  *(undefined8 *)(param_1 + 0x2c0) = 0;
  *(undefined1 *)(param_1 + 0x2c8) = 1;
  *(ulong *)(param_1 + 0x2d0) = (ulong)uVar1;
  *(undefined4 *)(param_1 + 0x2d8) = uVar12;
  *(undefined8 *)(param_1 + 0x2e0) = uVar4;
  local_48 = &PTR_FUN_00132da8;
  pcStack_40 = "../src_udic/marisa_u/grimoire/trie/louds-trie.cpp";
  *(undefined1 (*) [16])(param_1 + 0x2a0) = (undefined1  [16])0x0;
  if (pvVar9 != (void *)0x0) {
    operator_delete__(pvVar9);
  }
  FUN_00123d10(param_1 + 0x2e8,param_2);
  if ((*(long *)(param_1 + 0x1d8) == 0) || (*(long *)(param_1 + 0x300) != 0)) {
LAB_0011651d:
    puVar5 = (ulong *)FUN_00110420(param_2,8);
    uVar2 = *puVar5;
    if ((uVar2 * -0x5555555555555555 >> 2 | uVar2 * -0x5555555555555555 << 0x3e) <
        0x1555555555555556) {
      uVar13 = uVar2 / 0xc;
      uVar6 = FUN_00110420(param_2,uVar13 * 0xc);
      FUN_00110490(param_2,-(int)uVar2 & 7);
      pvVar9 = *(void **)(param_1 + 0x3f0);
      *(undefined8 *)(param_1 + 0x400) = uVar6;
      *(ulong *)(param_1 + 0x408) = uVar13;
      *(undefined8 *)(param_1 + 0x410) = 0;
      *(undefined1 *)(param_1 + 0x418) = 1;
      pcStack_50 = "../src_udic/marisa_u/grimoire/trie/config.h";
      *(undefined1 (*) [16])(param_1 + 0x3f0) = (undefined1  [16])0x0;
      if (pvVar9 != (void *)0x0) {
        operator_delete__(pvVar9);
        uVar13 = *(ulong *)(param_1 + 0x408);
      }
      *(ulong *)(param_1 + 0x420) = uVar13 - 1;
      puVar7 = (uint *)FUN_00110420(param_2,4);
      *(ulong *)(param_1 + 0x428) = (ulong)*puVar7;
      puVar7 = (uint *)FUN_00110420(param_2,4);
      uVar1 = *puVar7;
      if ((uVar1 & 0xfff00000) != 0) {
        puVar3 = (undefined8 *)__cxa_allocate_exception(0x20);
        *puVar3 = &PTR_FUN_00132da8;
        puVar3[1] = "../src_udic/marisa_u/grimoire/trie/config.h";
        puVar3[2] = 0x50000003a;
        puVar3[3] = 
        "../src_udic/marisa_u/grimoire/trie/config.h:58: MARISA_CODE_ERROR: (config_flags & ~MARISA_CONFIG_MASK) != 0"
        ;
                    /* WARNING: Subroutine does not return */
        __cxa_throw(puVar3,&PTR_vtable_00132d80,FUN_0010e6a0);
      }
      uVar10 = uVar1 & 0x7f;
      if (uVar10 == 0) {
        uVar10 = 3;
      }
      uVar11 = uVar1 & 0xf80;
      if (uVar11 != 0x200) {
        if (0x200 < uVar11) {
          if (uVar11 == 0x400) {
            uVar12 = 0x400;
            goto joined_r0x001166ec;
          }
          if (uVar11 == 0x800) {
            uVar12 = 0x800;
            goto joined_r0x001166ec;
          }
          goto LAB_00106e66;
        }
        if (uVar11 == 0x80) {
          uVar12 = 0x80;
          goto joined_r0x001166ec;
        }
        if (uVar11 == 0x100) {
          uVar12 = 0x100;
          goto joined_r0x001166ec;
        }
        if (uVar11 != 0) goto LAB_00106e66;
      }
      uVar12 = 0x200;
joined_r0x001166ec:
      if ((uVar1 & 0xf000) == 0x1000) {
        uVar15 = 0x1000;
      }
      else {
        uVar15 = 0x2000;
        if (((uVar1 & 0xf000) != 0x2000) && (uVar15 = 0x1000, (uVar1 & 0xf000) != 0)) {
          FUN_00106ea7();
          return;
        }
      }
      if ((uVar1 & 0xf0000) == 0x10000) {
        uVar14 = 0x10000;
      }
      else {
        uVar14 = 0x20000;
        if ((uVar1 & 0xd0000) != 0) {
          puVar3 = (undefined8 *)__cxa_allocate_exception(0x20);
          *puVar3 = &PTR_FUN_00132da8;
          puVar3[1] = "../src_udic/marisa_u/grimoire/trie/config.h";
          puVar3[2] = 0x50000008d;
          puVar3[3] = 
          "../src_udic/marisa_u/grimoire/trie/config.h:141: MARISA_CODE_ERROR: undefined node order"
          ;
                    /* WARNING: Subroutine does not return */
          __cxa_throw(puVar3,&PTR_vtable_00132d80,FUN_0010e6a0);
        }
      }
      *(long *)(param_1 + 0x430) = (long)(int)uVar10;
      *(undefined4 *)(param_1 + 0x440) = uVar14;
      *(ulong *)(param_1 + 0x438) = CONCAT44(uVar15,uVar12);
      return;
    }
  }
  else {
    pvVar9 = operator_new(0x470,(nothrow_t *)PTR_nothrow_00132fb8);
    if (pvVar9 == (void *)0x0) {
      pvVar16 = *(void **)(param_1 + 1000);
      *(undefined8 *)(param_1 + 1000) = 0;
      if (pvVar16 == (void *)0x0) goto LAB_00106e1a;
LAB_001167c8:
      FUN_001125e0(pvVar16);
      operator_delete(pvVar16);
      pvVar9 = *(void **)(param_1 + 1000);
      if (pvVar9 == (void *)0x0) {
LAB_00106e1a:
        puVar3 = (undefined8 *)__cxa_allocate_exception(0x20);
        *puVar3 = local_48;
        puVar3[1] = pcStack_40;
        puVar3[2] = 0x80000021e;
        puVar3[3] = 
        "../src_udic/marisa_u/grimoire/trie/louds-trie.cpp:542: MARISA_MEMORY_ERROR: next_trie_.get() == NULL"
        ;
                    /* WARNING: Subroutine does not return */
        __cxa_throw(puVar3,&PTR_vtable_00132d80,FUN_0010e6a0);
      }
LAB_0011677d:
      FUN_00116340(pvVar9,param_2);
      goto LAB_0011651d;
    }
    FUN_00112770(pvVar9);
    pvVar16 = *(void **)(param_1 + 1000);
    if (pvVar9 != pvVar16) {
      *(void **)(param_1 + 1000) = pvVar9;
      if (pvVar16 != (void *)0x0) goto LAB_001167c8;
      goto LAB_0011677d;
    }
    FUN_0010656c();
  }
  FUN_001066ea();
LAB_00106e66:
  puVar3 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar3 = &PTR_FUN_00132da8;
  puVar3[1] = pcStack_50;
  puVar3[2] = 0x500000065;
  puVar3[3] = 
  "../src_udic/marisa_u/grimoire/trie/config.h:101: MARISA_CODE_ERROR: undefined cache level";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar3,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00116800 @ 00116800 size=307 =====

void FUN_00116800(undefined8 param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  char *pcVar2;
  long in_FS_OFFSET;
  undefined1 auStack_498 [1096];
  undefined1 local_50 [48];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  pcVar2 = (char *)FUN_00110420(param_2,0x10);
  if (((((*pcVar2 == 'W') && (pcVar2[1] == 'e')) && (pcVar2[2] == ' ')) &&
      (((pcVar2[3] == 'l' && (pcVar2[4] == 'o')) &&
       ((pcVar2[5] == 'v' && ((pcVar2[6] == 'e' && (pcVar2[7] == ' ')))))))) &&
     ((pcVar2[8] == 'M' &&
      (((((pcVar2[9] == 'a' && (pcVar2[10] == 'r')) && (pcVar2[0xb] == 'i')) &&
        ((pcVar2[0xc] == 's' && (pcVar2[0xd] == 'a')))) &&
       ((pcVar2[0xe] == '.' && (pcVar2[0xf] == '\0')))))))) {
    FUN_00112770(auStack_498);
    FUN_00116340(auStack_498,param_2);
    FUN_00110360(local_50,param_2);
    FUN_00112ca0(param_1,auStack_498);
    FUN_001125e0(auStack_498);
    if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0xa00000015;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/header.h:21: MARISA_FORMAT_ERROR: !test_header(ptr)";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/trie/header.h";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_00116940 @ 00116940 size=1667 =====

void FUN_00116940(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  void *pvVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  void *pvVar9;
  ulong uVar10;
  ulong uVar11;
  long in_FS_OFFSET;
  undefined8 *puStack_b0;
  void *pvStack_a0;
  undefined4 local_4c;
  uint local_48;
  undefined4 uStack_44;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_001199f0();
  FUN_001199f0(param_1 + 0xd0,param_2);
  FUN_001199f0(param_1 + 0x1a0,param_2);
  FUN_00110a70(param_2,&local_48,8);
  puStack_b0 = (undefined8 *)CONCAT44(uStack_44,local_48);
  if (puStack_b0 == (undefined8 *)0x0) {
    FUN_00110a70(param_2,0,0);
    pvStack_a0 = (void *)0x0;
    puStack_b0 = (undefined8 *)0x0;
  }
  else {
    pvStack_a0 = operator_new__((ulong)puStack_b0,(nothrow_t *)PTR_nothrow_00132fb8);
    if (pvStack_a0 == (void *)0x0) {
      puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
      *puVar2 = &PTR_FUN_00132da8;
      puVar2[1] = "../src_udic/marisa_u/grimoire/trie/../io/reader.h";
      puVar2[2] = 0x20000001f;
      puVar2[3] = 
      "../src_udic/marisa_u/grimoire/trie/../io/reader.h:31: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
      ;
                    /* WARNING: Subroutine does not return */
      __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
    }
    FUN_00110a70(param_2,pvStack_a0,puStack_b0);
  }
  FUN_00110b80(param_2,-local_48 & 7);
  pvVar3 = *(void **)(param_1 + 0x270);
  *(void **)(param_1 + 0x280) = pvStack_a0;
  *(undefined1 *)(param_1 + 0x298) = 0;
  *(void **)(param_1 + 0x270) = pvStack_a0;
  *(void **)(param_1 + 0x278) = pvStack_a0;
  *(undefined8 **)(param_1 + 0x288) = puStack_b0;
  *(undefined8 **)(param_1 + 0x290) = puStack_b0;
  if (pvVar3 != (void *)0x0) {
    operator_delete__(pvVar3);
  }
  FUN_00110a70(param_2,&local_48,8);
  if ((local_48 & 7) != 0) {
    uVar1 = FUN_001067a8();
                    /* WARNING: Subroutine does not return */
    _Unwind_Resume(uVar1);
  }
  uVar10 = CONCAT44(uStack_44,local_48) & 0xfffffffffffffff8;
  pvStack_a0 = (void *)(CONCAT44(uStack_44,local_48) >> 3);
  if (pvStack_a0 == (void *)0x0) {
    FUN_00110a70(param_2,0,0);
    pvStack_a0 = (void *)0x0;
    puStack_b0 = (void *)0x0;
  }
  else {
    puStack_b0 = operator_new__(uVar10,(nothrow_t *)PTR_nothrow_00132fb8);
    if (puStack_b0 == (void *)0x0) goto LAB_0010728d;
    FUN_00110a70(param_2,puStack_b0,uVar10);
  }
  FUN_00110b80(param_2,-local_48 & 7);
  FUN_00110a70(param_2,&local_48,4);
  if (0x20 < local_48) {
LAB_001071ac:
    puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar2 = &PTR_FUN_00132da8;
    puVar2[1] = "../src_udic/marisa_u/grimoire/trie/../vector/flat-vector.h";
    puVar2[2] = 0xa000000a6;
    puVar2[3] = 
    "../src_udic/marisa_u/grimoire/trie/../vector/flat-vector.h:166: MARISA_FORMAT_ERROR: temp_value_size > 32"
    ;
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  uVar10 = (ulong)local_48;
  FUN_00110a70(param_2,&local_4c,4);
  FUN_00110a70(param_2,&local_48,8);
  pvVar3 = *(void **)(param_1 + 0x2a0);
  *(undefined8 **)(param_1 + 0x2b0) = puStack_b0;
  *(undefined1 *)(param_1 + 0x2c8) = 0;
  *(ulong *)(param_1 + 0x2d0) = uVar10;
  *(undefined4 *)(param_1 + 0x2d8) = local_4c;
  *(ulong *)(param_1 + 0x2e0) = CONCAT44(uStack_44,local_48);
  *(undefined8 **)(param_1 + 0x2a0) = puStack_b0;
  *(undefined8 **)(param_1 + 0x2a8) = puStack_b0;
  *(void **)(param_1 + 0x2b8) = pvStack_a0;
  *(void **)(param_1 + 0x2c0) = pvStack_a0;
  if (pvVar3 != (void *)0x0) {
    operator_delete__(pvVar3);
  }
  FUN_001241c0(param_1 + 0x2e8,param_2);
  if ((*(long *)(param_1 + 0x1d8) != 0) && (*(long *)(param_1 + 0x300) == 0)) {
    pvVar3 = operator_new(0x470,(nothrow_t *)PTR_nothrow_00132fb8);
    if (pvVar3 == (void *)0x0) {
      pvVar9 = *(void **)(param_1 + 1000);
      *(undefined8 *)(param_1 + 1000) = 0;
      if (pvVar9 == (void *)0x0) {
        puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
        *puVar2 = &PTR_FUN_00132da8;
        puVar2[1] = "../src_udic/marisa_u/grimoire/trie/louds-trie.cpp";
        puVar2[2] = 0x800000238;
        puVar2[3] = 
        "../src_udic/marisa_u/grimoire/trie/louds-trie.cpp:568: MARISA_MEMORY_ERROR: next_trie_.get() == NULL"
        ;
                    /* WARNING: Subroutine does not return */
        __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
      }
LAB_00116fad:
      FUN_001125e0(pvVar9);
      operator_delete(pvVar9);
      pvVar3 = *(void **)(param_1 + 1000);
      if (pvVar3 == (void *)0x0) {
        FUN_0010704e();
        return;
      }
    }
    else {
      FUN_00112770(pvVar3);
      pvVar9 = *(void **)(param_1 + 1000);
      if (pvVar3 == pvVar9) {
        FUN_0010656c();
        goto LAB_001071ac;
      }
      *(void **)(param_1 + 1000) = pvVar3;
      if (pvVar9 != (void *)0x0) goto LAB_00116fad;
    }
    FUN_00116940(pvVar3,param_2);
  }
  FUN_00110a70(param_2,&local_48,8);
  uVar11 = CONCAT44(uStack_44,local_48);
  uVar10 = uVar11 / 0xc;
  if (uVar11 % 0xc != 0) {
    FUN_001067a8();
LAB_0010728d:
    puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar2 = &PTR_FUN_00132da8;
    puVar2[1] = "../src_udic/marisa_u/grimoire/trie/../io/reader.h";
    puVar2[2] = 0x20000001f;
    puVar2[3] = 
    "../src_udic/marisa_u/grimoire/trie/../io/reader.h:31: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
    ;
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  if (uVar11 < 0xc) {
    pvStack_a0 = (void *)0x0;
    puStack_b0 = (undefined8 *)0x0;
  }
  else {
    puStack_b0 = operator_new__(uVar10 * 0xc,(nothrow_t *)PTR_nothrow_00132fb8);
    uVar6 = DAT_0012a648;
    uVar11 = 0;
    puVar2 = puStack_b0;
    do {
      uVar11 = uVar11 + 1;
      *puVar2 = 0;
      *(undefined4 *)(puVar2 + 1) = uVar6;
      puVar2 = (undefined8 *)((long)puVar2 + 0xc);
    } while (uVar11 < uVar10);
    pvStack_a0 = (void *)uVar10;
    if (puStack_b0 == (undefined8 *)0x0) {
      puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
      *puVar2 = &PTR_FUN_00132da8;
      puVar2[1] = "../src_udic/marisa_u/grimoire/trie/../io/reader.h";
      puVar2[2] = 0x20000001f;
      puVar2[3] = 
      "../src_udic/marisa_u/grimoire/trie/../io/reader.h:31: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
      ;
                    /* WARNING: Subroutine does not return */
      __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
    }
  }
  FUN_00110a70(param_2,puStack_b0,uVar10 * 0xc);
  FUN_00110b80(param_2,-local_48 & 7);
  pvVar3 = *(void **)(param_1 + 0x3f0);
  *(undefined8 **)(param_1 + 0x400) = puStack_b0;
  *(undefined1 *)(param_1 + 0x418) = 0;
  *(undefined8 **)(param_1 + 0x3f0) = puStack_b0;
  *(undefined8 **)(param_1 + 0x3f8) = puStack_b0;
  *(ulong *)(param_1 + 0x408) = uVar10;
  *(void **)(param_1 + 0x410) = pvStack_a0;
  if (pvVar3 != (void *)0x0) {
    operator_delete__(pvVar3);
    uVar10 = *(ulong *)(param_1 + 0x408);
  }
  *(ulong *)(param_1 + 0x420) = uVar10 - 1;
  FUN_00110a70(param_2,&local_48,4);
  *(ulong *)(param_1 + 0x428) = (ulong)local_48;
  FUN_00110a70(param_2,&local_48,4);
  if ((local_48 & 0xfff00000) != 0) {
    FUN_001071ee();
    return;
  }
  uVar4 = local_48 & 0x7f;
  if (uVar4 == 0) {
    uVar4 = 3;
  }
  uVar5 = local_48 & 0xf80;
  if (uVar5 != 0x200) {
    if (0x200 < uVar5) {
      if (uVar5 == 0x400) {
        uVar6 = 0x400;
      }
      else {
        if (uVar5 != 0x800) {
          puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
          *puVar2 = &PTR_FUN_00132da8;
          puVar2[1] = "../src_udic/marisa_u/grimoire/trie/config.h";
          puVar2[2] = 0x500000065;
          puVar2[3] = 
          "../src_udic/marisa_u/grimoire/trie/config.h:101: MARISA_CODE_ERROR: undefined cache level"
          ;
                    /* WARNING: Subroutine does not return */
          __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
        }
        uVar6 = 0x800;
      }
      goto joined_r0x00116e4f;
    }
    if (uVar5 == 0x80) {
      uVar6 = 0x80;
      goto joined_r0x00116e4f;
    }
    if (uVar5 == 0x100) {
      uVar6 = 0x100;
      goto joined_r0x00116e4f;
    }
    if (uVar5 != 0) {
      FUN_00107165();
      return;
    }
  }
  uVar6 = 0x200;
joined_r0x00116e4f:
  if ((local_48 & 0xf000) == 0x1000) {
    uVar8 = 0x1000;
  }
  else {
    uVar8 = 0x2000;
    if (((local_48 & 0xf000) != 0x2000) && (uVar8 = 0x1000, (local_48 & 0xf000) != 0)) {
      FUN_00107123();
      return;
    }
  }
  if ((local_48 & 0xf0000) == 0x10000) {
    uVar7 = 0x10000;
  }
  else {
    uVar7 = 0x20000;
    if ((local_48 & 0xd0000) != 0) {
      puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
      *puVar2 = &PTR_FUN_00132da8;
      puVar2[1] = "../src_udic/marisa_u/grimoire/trie/config.h";
      puVar2[2] = 0x50000008d;
      puVar2[3] = 
      "../src_udic/marisa_u/grimoire/trie/config.h:141: MARISA_CODE_ERROR: undefined node order";
                    /* WARNING: Subroutine does not return */
      __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
    }
  }
  *(long *)(param_1 + 0x430) = (long)(int)uVar4;
  *(undefined4 *)(param_1 + 0x440) = uVar7;
  *(ulong *)(param_1 + 0x438) = CONCAT44(uVar8,uVar6);
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


//===== FUN_00117050 @ 00117050 size=364 =====

void FUN_00117050(undefined8 param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  long in_FS_OFFSET;
  undefined1 auStack_4a8 [1136];
  char local_38;
  char local_37;
  char local_36;
  char local_35;
  char local_34;
  char local_33;
  char local_32;
  char local_31;
  char local_30;
  char local_2f;
  char local_2e;
  char local_2d;
  char local_2c;
  char local_2b;
  char local_2a;
  char local_29;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_00110a70(param_2,&local_38,0x10);
  if (((((local_38 == 'W') && (local_37 == 'e')) && (local_36 == ' ')) &&
      (((local_35 == 'l' && (local_34 == 'o')) &&
       ((local_33 == 'v' && ((local_32 == 'e' && (local_31 == ' ')))))))) &&
     ((local_30 == 'M' &&
      (((((local_2f == 'a' && (local_2e == 'r')) && (local_2d == 'i')) &&
        ((local_2c == 's' && (local_2b == 'a')))) && ((local_2a == '.' && (local_29 == '\0'))))))))
  {
    FUN_00112770(auStack_4a8);
    FUN_00116940(auStack_4a8,param_2);
    FUN_00112ca0(param_1,auStack_4a8);
    FUN_001125e0(auStack_4a8);
    if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  puVar1[2] = 0xa0000001a;
  puVar1[3] = 
  "../src_udic/marisa_u/grimoire/trie/header.h:26: MARISA_FORMAT_ERROR: !test_header(buf)";
  *puVar1 = &PTR_FUN_00132da8;
  puVar1[1] = "../src_udic/marisa_u/grimoire/trie/header.h";
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== FUN_001171d0 @ 001171d0 size=838 =====

void FUN_001171d0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,long param_4,
                 long param_5,undefined8 *param_6,long param_7)

{
  float *pfVar1;
  undefined8 *puVar2;
  float fVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  undefined8 *puVar8;
  size_t __n;
  undefined8 *puVar10;
  undefined8 *puVar11;
  long lVar12;
  undefined8 *puVar9;
  
  lVar12 = param_5;
  if (param_7 <= param_5) {
    lVar12 = param_7;
  }
  puVar2 = param_1;
  puVar11 = param_2;
  if (lVar12 < param_4) {
    do {
      if (param_5 <= param_7) {
        __n = (long)param_3 - (long)puVar11;
        if (param_3 != puVar11) {
          memmove(param_6,puVar11,__n);
        }
        puVar8 = (undefined8 *)((long)param_6 + __n);
        if (puVar11 != puVar2) {
          if (param_6 == puVar8) {
            return;
          }
          puVar11 = puVar11 + -2;
          do {
            puVar9 = puVar8 + -2;
            param_3 = param_3 + -2;
            puVar10 = puVar11;
            if (*(float *)((long)puVar11 + 0xc) <= *(float *)((long)puVar8 + -4) &&
                *(float *)((long)puVar8 + -4) != *(float *)((long)puVar11 + 0xc)) {
              do {
                uVar4 = puVar10[1];
                *param_3 = *puVar10;
                param_3[1] = uVar4;
                if (puVar10 == puVar2) {
                  if (param_6 == puVar8) {
                    return;
                  }
                  __n = (long)puVar8 - (long)param_6;
                  param_1 = (undefined8 *)((long)param_3 - __n);
                  goto LAB_00117462;
                }
                puVar11 = puVar10 + -2;
                param_3 = param_3 + -2;
                pfVar1 = (float *)((long)puVar10 + -4);
                puVar10 = puVar11;
              } while (*pfVar1 <= *(float *)((long)puVar8 + -4) &&
                       *(float *)((long)puVar8 + -4) != *pfVar1);
            }
            uVar4 = puVar8[-1];
            *param_3 = *puVar9;
            param_3[1] = uVar4;
            puVar8 = puVar9;
            if (param_6 == puVar9) {
              return;
            }
          } while( true );
        }
        if (param_6 == puVar8) {
          return;
        }
        param_1 = (undefined8 *)((long)param_3 - __n);
        goto LAB_00117462;
      }
      if (param_5 < param_4) {
        lVar12 = param_4 / 2;
        lVar6 = (long)param_3 - (long)puVar11 >> 4;
        puVar8 = puVar2 + lVar12 * 2;
        param_2 = puVar11;
        while (lVar7 = lVar6, 0 < lVar6) {
          while (lVar6 = lVar7 >> 1, fVar3 = *(float *)((long)param_2 + lVar6 * 0x10 + 0xc),
                *(float *)((long)puVar8 + 0xc) <= fVar3 && fVar3 != *(float *)((long)puVar8 + 0xc))
          {
            param_2 = param_2 + lVar6 * 2 + 2;
            lVar7 = (lVar7 - lVar6) + -1;
            if (lVar7 < 1) goto LAB_00117285;
          }
        }
LAB_00117285:
        lVar6 = (long)param_2 - (long)puVar11 >> 4;
      }
      else {
        lVar12 = (long)puVar11 - (long)puVar2 >> 4;
        lVar6 = param_5 / 2;
        param_2 = puVar11 + lVar6 * 2;
        puVar8 = puVar2;
        while (lVar7 = lVar12, 0 < lVar12) {
          while (lVar12 = lVar7 >> 1, pfVar1 = (float *)((long)puVar8 + lVar12 * 0x10 + 0xc),
                *(float *)((long)param_2 + 0xc) < *pfVar1 ||
                *(float *)((long)param_2 + 0xc) == *pfVar1) {
            puVar8 = puVar8 + lVar12 * 2 + 2;
            lVar7 = (lVar7 - lVar12) + -1;
            if (lVar7 < 1) goto LAB_001174d0;
          }
        }
LAB_001174d0:
        lVar12 = (long)puVar8 - (long)puVar2 >> 4;
      }
      param_4 = param_4 - lVar12;
      param_5 = param_5 - lVar6;
      param_1 = (undefined8 *)FUN_0011b240(puVar8,puVar11,param_2,param_4,lVar6,param_6,param_7);
      FUN_001171d0(puVar2,puVar8,param_1,lVar12,lVar6,param_6,param_7);
      lVar12 = param_5;
      if (param_7 <= param_5) {
        lVar12 = param_7;
      }
      puVar2 = param_1;
      puVar11 = param_2;
    } while (lVar12 < param_4);
  }
  if (param_2 != param_1) {
    memmove(param_6,param_1,(long)param_2 - (long)param_1);
  }
  puVar2 = (undefined8 *)((long)param_6 + ((long)param_2 - (long)param_1));
  if (param_6 == puVar2) {
LAB_00117450:
    if (puVar2 != param_6) {
      __n = (long)puVar2 - (long)param_6;
LAB_00117462:
      memmove(param_1,param_6,__n);
      return;
    }
  }
  else {
    do {
      while( true ) {
        if (param_3 == param_2) goto LAB_00117450;
        if (*(float *)((long)param_6 + 0xc) <= *(float *)((long)param_2 + 0xc) &&
            *(float *)((long)param_2 + 0xc) != *(float *)((long)param_6 + 0xc)) break;
        uVar4 = *param_6;
        uVar5 = param_6[1];
        param_6 = param_6 + 2;
        *param_1 = uVar4;
        param_1[1] = uVar5;
        param_1 = param_1 + 2;
        if (puVar2 == param_6) {
          return;
        }
      }
      uVar4 = *param_2;
      uVar5 = param_2[1];
      param_2 = param_2 + 2;
      *param_1 = uVar4;
      param_1[1] = uVar5;
      param_1 = param_1 + 2;
    } while (puVar2 != param_6);
  }
  return;
}


//===== FUN_00117550 @ 00117550 size=487 =====

void FUN_00117550(long param_1,long param_2,long param_3,long param_4)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  
  lVar2 = ((param_2 - param_1 >> 4) + 1) / 2;
  lVar3 = lVar2 * 0x10;
  lVar1 = param_1 + lVar3;
  lVar4 = param_2 - lVar1;
  if (param_4 < lVar2) {
    FUN_00117550(param_1,lVar1,param_3);
    FUN_00117550(lVar1,param_2,param_3,param_4);
  }
  else {
    lVar2 = param_1;
    if (lVar3 < 0x61) {
      FUN_001114e0(param_1,lVar1);
    }
    else {
      do {
        lVar5 = lVar2 + 0x70;
        FUN_001114e0(lVar2,lVar5);
        lVar2 = lVar5;
      } while (0x60 < lVar1 - lVar5);
      FUN_001114e0(lVar5,lVar1);
      if (0x70 < lVar3) {
        lVar2 = 7;
        do {
          FUN_001116a0(param_1,lVar1,param_3,lVar2);
          lVar5 = lVar2 * 2;
          lVar2 = lVar2 * 4;
          FUN_001116a0(param_3,param_3 + lVar3,param_1,lVar5);
        } while (lVar2 < lVar3 >> 4);
      }
    }
    lVar2 = lVar1;
    if (lVar4 < 0x61) {
      FUN_001114e0(lVar1,param_2);
    }
    else {
      do {
        lVar5 = lVar2 + 0x70;
        FUN_001114e0(lVar2,lVar5);
        lVar2 = lVar5;
      } while (0x60 < param_2 - lVar5);
      FUN_001114e0(lVar5,param_2);
      if (0x70 < lVar4) {
        lVar2 = 7;
        do {
          FUN_001116a0(lVar1,param_2,param_3,lVar2);
          lVar5 = lVar2 * 2;
          lVar2 = lVar2 * 4;
          FUN_001116a0(param_3,param_3 + lVar4,lVar1,lVar5);
        } while (lVar2 < lVar4 >> 4);
      }
    }
  }
  FUN_001171d0(param_1,lVar1,param_2,lVar3 >> 4,lVar4 >> 4,param_3,param_4);
  return;
}


//===== FUN_00117750 @ 00117750 size=1654 =====

void FUN_00117750(long param_1,undefined1 (*param_2) [16],undefined8 param_3,long *param_4,
                 long param_5)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  ulong uVar4;
  long lVar5;
  void *pvVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  long lVar12;
  long lVar13;
  long lVar14;
  undefined *puVar15;
  undefined8 *puVar16;
  long *plVar17;
  nothrow_t *pnVar18;
  long *plVar19;
  long *plVar20;
  ulong uVar21;
  long *plVar22;
  uint *puVar23;
  long lVar24;
  ulong uVar25;
  ulong uVar26;
  nothrow_t *pnVar27;
  long in_FS_OFFSET;
  bool bVar28;
  long *local_78;
  long *plStack_70;
  long *local_68;
  undefined1 local_60 [16];
  undefined1 local_50;
  long local_40;
  
  puVar15 = PTR_nothrow_00132fb8;
  uVar4 = *(ulong *)(param_2[1] + 8);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_78 = (long *)0x0;
  plStack_70 = (long *)0x0;
  local_68 = (long *)0x0;
  local_50 = 0;
  local_60 = (undefined1  [16])0x0;
  if (param_5 == *param_4) {
    if (uVar4 == 0) {
      local_60 = ZEXT816(0) << 0x40;
    }
    else {
      local_68 = operator_new__(uVar4 << 4,(nothrow_t *)PTR_nothrow_00132fb8);
      plVar20 = local_78;
      uVar21 = local_60._0_8_;
      if (local_60._0_8_ == 0) {
        auVar11._8_8_ = 0;
        auVar11._0_8_ = uVar4;
        local_60 = auVar11 << 0x40;
        if (local_78 != (long *)0x0) goto LAB_00117b6f;
        lVar24 = *(long *)(param_2[1] + 8);
        local_78 = local_68;
        plStack_70 = local_68;
LAB_00117b95:
        uVar26 = uVar21 + 1;
        uVar25 = 1;
        if (uVar26 <= uVar4) {
          uVar25 = uVar4 - uVar21;
        }
        if ((2 < (uVar4 - uVar21) - 1) && (uVar26 <= uVar4)) {
          plVar20 = plStack_70 + uVar21 * 2;
          plVar19 = plStack_70 + uVar21 * 2 + 1;
          do {
            *plVar20 = -1;
            plVar22 = plVar20 + 8;
            plVar20[2] = -1;
            plVar20[4] = -1;
            plVar20[6] = -1;
            *plVar19 = 0;
            plVar19[2] = 0;
            plVar19[4] = 0;
            plVar19[6] = 0;
            plVar20 = plVar22;
            plVar19 = plVar19 + 8;
          } while (plStack_70 + uVar21 * 2 + (uVar25 >> 2) * 8 != plVar22);
          uVar21 = uVar21 + (uVar25 & 0xfffffffffffffffc);
          if (uVar25 == (uVar25 & 0xfffffffffffffffc)) goto LAB_00117c97;
          uVar26 = uVar21 + 1;
        }
        plStack_70[uVar21 * 2] = -1;
        (plStack_70 + uVar21 * 2)[1] = 0;
        if (uVar26 < uVar4) {
          plStack_70[uVar21 * 2 + 2] = -1;
          (plStack_70 + uVar21 * 2 + 2)[1] = 0;
          if (uVar21 + 2 < uVar4) {
            plStack_70[uVar21 * 2 + 4] = -1;
            (plStack_70 + uVar21 * 2 + 4)[1] = 0;
          }
        }
      }
      else {
        uVar26 = local_60._0_8_ - 1;
        if (((ulong)((long)local_68 - (long)(plStack_70 + 2)) < 0x21 || uVar26 < 4) ||
           ((ulong)((long)(local_68 + 1) - (long)(plStack_70 + 3)) < 0x21)) {
          plVar19 = local_68;
          do {
            plVar22 = plVar19 + 2;
            *plVar19 = *plStack_70;
            plVar19[1] = plStack_70[1];
            plStack_70 = plStack_70 + 2;
            plVar19 = plVar22;
          } while (plVar22 != local_68 + local_60._0_8_ * 2);
        }
        else {
          plVar19 = plStack_70;
          plVar22 = local_68 + 1;
          do {
            lVar5 = plVar19[1];
            uVar9 = *(undefined4 *)((long)plVar19 + 0xc);
            plVar17 = plVar19 + 8;
            lVar12 = plVar19[3];
            uVar2 = *(undefined4 *)((long)plVar19 + 0x1c);
            lVar13 = plVar19[5];
            uVar8 = *(undefined4 *)((long)plVar19 + 0x2c);
            plVar22[-1] = *plVar19;
            lVar24 = plVar19[2];
            lVar14 = plVar19[7];
            uVar7 = *(undefined4 *)((long)plVar19 + 0x3c);
            *(int *)plVar22 = (int)lVar5;
            *(undefined4 *)((long)plVar22 + 4) = uVar9;
            plVar22[1] = lVar24;
            lVar24 = plVar19[4];
            *(int *)(plVar22 + 2) = (int)lVar12;
            *(undefined4 *)((long)plVar22 + 0x14) = uVar2;
            plVar22[3] = lVar24;
            lVar24 = plVar19[6];
            *(int *)(plVar22 + 4) = (int)lVar13;
            *(undefined4 *)((long)plVar22 + 0x24) = uVar8;
            plVar22[5] = lVar24;
            *(int *)(plVar22 + 6) = (int)lVar14;
            *(undefined4 *)((long)plVar22 + 0x34) = uVar7;
            plVar19 = plVar17;
            plVar22 = plVar22 + 8;
          } while (plStack_70 + (uVar26 >> 2) * 8 != plVar17);
          uVar26 = uVar26 & 0xfffffffffffffffc;
          lVar24 = (plStack_70 + uVar26 * 2)[1];
          local_68[uVar26 * 2] = plStack_70[uVar26 * 2];
          (local_68 + uVar26 * 2)[1] = lVar24;
          if (uVar26 + 1 < (ulong)local_60._0_8_) {
            lVar24 = plStack_70[uVar26 * 2 + 2];
            (local_68 + uVar26 * 2 + 2)[1] = (plStack_70 + uVar26 * 2 + 2)[1];
            local_68[uVar26 * 2 + 2] = lVar24;
            if (uVar26 + 2 < (ulong)local_60._0_8_) {
              lVar24 = (plStack_70 + uVar26 * 2 + 4)[1];
              local_68[uVar26 * 2 + 4] = plStack_70[uVar26 * 2 + 4];
              (local_68 + uVar26 * 2 + 4)[1] = lVar24;
              if (uVar26 + 3 < (ulong)local_60._0_8_) {
                lVar24 = (plStack_70 + uVar26 * 2 + 6)[1];
                local_68[uVar26 * 2 + 6] = plStack_70[uVar26 * 2 + 6];
                (local_68 + uVar26 * 2 + 6)[1] = lVar24;
              }
            }
          }
        }
        local_60._8_8_ = uVar4;
        bVar28 = local_78 != (long *)0x0;
        local_78 = local_68;
        plStack_70 = local_68;
        if (bVar28) {
LAB_00117b6f:
          local_60._8_8_ = uVar4;
          local_60 = CONCAT88(local_60._8_8_,uVar21);
          local_78 = local_68;
          plStack_70 = local_68;
          operator_delete__(plVar20);
          uVar21 = local_60._0_8_;
        }
        lVar24 = *(long *)(param_2[1] + 8);
        if (uVar21 < uVar4) goto LAB_00117b95;
      }
LAB_00117c97:
      local_60._0_8_ = uVar4;
      if (lVar24 != 0) {
        puVar23 = (uint *)(*(long *)(*param_2 + 8) + 8);
        plVar20 = plStack_70;
        do {
          uVar3 = *puVar23;
          puVar1 = puVar23 + -2;
          plVar19 = plVar20 + 2;
          puVar23 = puVar23 + 6;
          *plVar20 = *(long *)puVar1 + -1 + (ulong)uVar3;
          *(uint *)(plVar20 + 1) = uVar3;
          plVar20 = plVar19;
        } while (plStack_70 + lVar24 * 2 != plVar19);
      }
    }
    FUN_00123720(param_1 + 0x2e8,&local_78,param_3,*(undefined4 *)((long)param_4 + 0xc));
    goto LAB_00117963;
  }
  if (uVar4 == 0) {
    local_60 = ZEXT816(0) << 0x40;
  }
  else {
    local_68 = operator_new__(uVar4 * 0x18,(nothrow_t *)PTR_nothrow_00132fb8);
    plVar20 = local_78;
    uVar21 = local_60._0_8_;
    if (local_60._0_8_ == 0) {
      auVar10._8_8_ = 0;
      auVar10._0_8_ = uVar4;
      local_60 = auVar10 << 0x40;
      bVar28 = local_78 != (long *)0x0;
      local_78 = local_68;
      plStack_70 = local_68;
      if (bVar28) goto LAB_00117844;
LAB_00117869:
      plVar20 = plStack_70 + uVar21 * 3;
      do {
        uVar21 = uVar21 + 1;
        *plVar20 = -1;
        *(undefined4 *)(plVar20 + 2) = 0;
        plVar20[1] = 0;
        plVar20 = plVar20 + 3;
      } while (uVar21 < uVar4);
      lVar24 = *(long *)(param_2[1] + 8);
    }
    else {
      plVar19 = local_68;
      do {
        plVar22 = plVar19 + 3;
        *plVar19 = *plStack_70;
        *(int *)(plVar19 + 1) = (int)plStack_70[1];
        *(undefined4 *)((long)plVar19 + 0xc) = *(undefined4 *)((long)plStack_70 + 0xc);
        *(int *)(plVar19 + 2) = (int)plStack_70[2];
        plVar19 = plVar22;
        plStack_70 = plStack_70 + 3;
      } while (plVar22 != local_68 + local_60._0_8_ * 3);
      local_60._8_8_ = uVar4;
      bVar28 = local_78 != (long *)0x0;
      local_78 = local_68;
      plStack_70 = local_68;
      if (bVar28) {
LAB_00117844:
        local_60._8_8_ = uVar4;
        local_60 = CONCAT88(local_60._8_8_,uVar21);
        local_78 = local_68;
        plStack_70 = local_68;
        operator_delete__(plVar20);
        uVar21 = local_60._0_8_;
      }
      lVar24 = *(long *)(param_2[1] + 8);
      if (uVar21 < uVar4) goto LAB_00117869;
    }
    local_60._0_8_ = uVar4;
    if (lVar24 != 0) {
      plVar20 = *(long **)(*param_2 + 8);
      plVar19 = plVar20;
      plVar22 = plStack_70;
      do {
        uVar3 = *(uint *)(plVar19 + 1);
        lVar5 = *plVar19;
        plVar17 = plVar19 + 3;
        *(uint *)(plVar22 + 1) = uVar3;
        uVar2 = *(undefined4 *)((long)plVar19 + 0xc);
        *plVar22 = lVar5 + -1 + (ulong)uVar3;
        *(undefined4 *)((long)plVar22 + 0xc) = uVar2;
        plVar19 = plVar17;
        plVar22 = plVar22 + 3;
      } while (plVar17 != plVar20 + lVar24 * 3);
    }
  }
  pvVar6 = *(void **)*param_2;
  param_2[2][8] = 0;
  *(undefined8 *)param_2[1] = 0;
  *param_2 = (undefined1  [16])0x0;
  *(undefined1 (*) [16])(param_2[1] + 8) = (undefined1  [16])0x0;
  if (pvVar6 != (void *)0x0) {
    operator_delete__(pvVar6);
  }
  pnVar18 = operator_new(0x470,(nothrow_t *)puVar15);
  if (pnVar18 == (nothrow_t *)0x0) {
    pnVar27 = *(nothrow_t **)(param_1 + 1000);
    *(undefined8 *)(param_1 + 1000) = 0;
    if (pnVar27 == (nothrow_t *)0x0) {
      puVar16 = (undefined8 *)__cxa_allocate_exception(0x20);
      puVar16[2] = 0x8000001c3;
      puVar16[3] = 
      "../src_udic/marisa_u/grimoire/trie/louds-trie.cpp:451: MARISA_MEMORY_ERROR: next_trie_.get() == NULL"
      ;
      *puVar16 = &PTR_FUN_00132da8;
      puVar16[1] = "../src_udic/marisa_u/grimoire/trie/louds-trie.cpp";
                    /* WARNING: Subroutine does not return */
      __cxa_throw(puVar16,&PTR_vtable_00132d80,FUN_0010e6a0);
    }
LAB_001179b0:
    FUN_001125e0(pnVar27);
    operator_delete(pnVar27);
    pnVar18 = *(nothrow_t **)(param_1 + 1000);
    if (pnVar18 == (nothrow_t *)0x0) {
      FUN_00107344();
      return;
    }
  }
  else {
    FUN_00112770(pnVar18);
    pnVar27 = *(nothrow_t **)(param_1 + 1000);
    if (pnVar18 == pnVar27) {
      FUN_0010656c();
      operator_delete(pnVar18,pnVar27);
      if (local_78 != (long *)0x0) {
        operator_delete__(local_78);
      }
                    /* WARNING: Subroutine does not return */
      _Unwind_Resume(param_5);
    }
    *(nothrow_t **)(param_1 + 1000) = pnVar18;
    if (pnVar27 != (nothrow_t *)0x0) goto LAB_001179b0;
  }
  FUN_001200d0(pnVar18,&local_78,param_3,param_4,param_5 + 1);
LAB_00117963:
  if (local_78 != (long *)0x0) {
    operator_delete__(local_78);
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


//===== FUN_00117dd0 @ 00117dd0 size=4128 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00117dd0(long param_1,long param_2,undefined8 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  ulong *puVar3;
  uint uVar4;
  long lVar5;
  void *pvVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  long lVar18;
  undefined1 uVar19;
  undefined4 uVar20;
  undefined8 uVar21;
  undefined8 *puVar22;
  undefined8 *puVar23;
  undefined8 *puVar24;
  undefined1 (*pauVar25) [16];
  undefined1 (*pauVar26) [16];
  long lVar27;
  undefined1 (*pauVar28) [16];
  void *pvVar29;
  long lVar30;
  ulong uVar31;
  ulong uVar32;
  long lVar33;
  ulong uVar34;
  ulong uVar35;
  undefined1 (*pauVar36) [16];
  ulong uVar37;
  ulong uVar38;
  ulong uVar39;
  long in_FS_OFFSET;
  bool bVar40;
  long lVar41;
  long lVar42;
  undefined8 *local_178;
  undefined8 *puStack_170;
  undefined8 *local_168;
  undefined1 local_160 [16];
  undefined1 local_150;
  undefined1 local_148 [16];
  undefined8 local_138;
  undefined1 local_130 [16];
  undefined1 local_120;
  undefined1 local_118 [16];
  undefined8 local_108;
  undefined1 local_100 [16];
  undefined8 local_f0;
  undefined1 local_e8 [16];
  undefined1 local_d8 [16];
  undefined8 local_c8;
  undefined1 local_c0 [16];
  undefined8 local_b0;
  undefined1 local_a8 [16];
  undefined8 local_98;
  undefined1 local_90 [16];
  undefined8 local_80;
  undefined1 local_78 [16];
  undefined8 local_68;
  undefined1 local_60 [16];
  undefined8 local_50;
  long local_40;
  
  uVar32 = *(ulong *)(param_2 + 0x58);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_150 = 0;
  local_168 = (undefined8 *)0x0;
  local_178 = (undefined8 *)0x0;
  puStack_170 = (undefined8 *)0x0;
  local_160 = (undefined1  [16])0x0;
  if (uVar32 == 0) {
    local_160 = ZEXT816(0) << 0x40;
  }
  else {
    local_168 = operator_new__(uVar32 * 0x18,(nothrow_t *)PTR_nothrow_00132fb8);
    puVar23 = local_178;
    uVar31 = local_160._0_8_;
    if (local_160._0_8_ == 0) {
      auVar11._8_8_ = 0;
      auVar11._0_8_ = uVar32;
      local_160 = auVar11 << 0x40;
      bVar40 = local_178 != (undefined8 *)0x0;
      local_178 = local_168;
      puStack_170 = local_168;
      if (bVar40) goto LAB_00117eb4;
LAB_00117ed4:
      puVar23 = puStack_170 + uVar31 * 3;
      do {
        uVar31 = uVar31 + 1;
        *puVar23 = 0;
        *(undefined4 *)(puVar23 + 2) = 0;
        puVar23[1] = 0;
        puVar23 = puVar23 + 3;
      } while (uVar31 < uVar32);
      uVar37 = *(ulong *)(param_2 + 0x58);
    }
    else {
      puVar24 = local_168;
      do {
        puVar22 = puVar24 + 3;
        *puVar24 = *puStack_170;
        *(undefined4 *)(puVar24 + 1) = *(undefined4 *)(puStack_170 + 1);
        *(undefined4 *)((long)puVar24 + 0xc) = *(undefined4 *)((long)puStack_170 + 0xc);
        *(undefined4 *)(puVar24 + 2) = *(undefined4 *)(puStack_170 + 2);
        puVar24 = puVar22;
        puStack_170 = puStack_170 + 3;
      } while (local_168 + local_160._0_8_ * 3 != puVar22);
      local_160._8_8_ = uVar32;
      bVar40 = local_178 != (undefined8 *)0x0;
      local_178 = local_168;
      puStack_170 = local_168;
      if (bVar40) {
LAB_00117eb4:
        local_160._8_8_ = uVar32;
        local_160 = CONCAT88(local_160._8_8_,uVar31);
        local_178 = local_168;
        puStack_170 = local_168;
        operator_delete__(puVar23);
        uVar31 = local_160._0_8_;
      }
      uVar37 = *(ulong *)(param_2 + 0x58);
      if (uVar31 < uVar32) goto LAB_00117ed4;
    }
    local_160._0_8_ = uVar32;
    if (uVar37 != 0) {
      lVar5 = *(long *)(param_2 + 0x30);
      puVar23 = puStack_170;
      uVar32 = 0;
      do {
        uVar31 = uVar32 + 1;
        puVar24 = (undefined8 *)((uVar32 & 0xff) * 0x10 + *(long *)(lVar5 + (uVar32 >> 8) * 8));
        uVar21 = *puVar24;
        *(undefined4 *)(puVar23 + 1) = *(undefined4 *)(puVar24 + 1);
        uVar20 = *(undefined4 *)((long)puVar24 + 0xc);
        *puVar23 = uVar21;
        *(undefined4 *)((long)puVar23 + 0xc) = uVar20;
        puVar23 = puVar23 + 3;
        uVar32 = uVar31;
      } while (uVar31 != uVar37);
    }
  }
  local_138 = 0;
  local_120 = 0;
  local_148 = (undefined1  [16])0x0;
  local_130 = (undefined1  [16])0x0;
  FUN_00120d60(param_1,&local_178,local_148,param_3,1);
  uVar7 = local_130._0_8_;
  uVar21 = local_148._0_8_;
  if (local_130._0_8_ == 0) {
    local_120 = 0;
    local_138 = 0;
    local_148 = (undefined1  [16])0x0;
    local_130 = (undefined1  [16])0x0;
    if ((void *)uVar21 != (void *)0x0) {
      pauVar25 = (undefined1 (*) [16])0x0;
      operator_delete__((void *)uVar21);
      goto LAB_0011820b;
    }
    uVar32 = *(ulong *)(param_1 + 0x100);
    pauVar25 = (undefined1 (*) [16])0x0;
LAB_00118d28:
    uVar31 = 0;
  }
  else {
    uVar32 = local_130._0_8_ * 8;
    pauVar25 = operator_new__(uVar32,(nothrow_t *)PTR_nothrow_00132fb8);
    if (uVar7 == 1) {
      uVar31 = 0;
LAB_0011801d:
      *(undefined8 *)(*pauVar25 + uVar31 * 8) = 0;
    }
    else {
      pauVar26 = pauVar25;
      do {
        *pauVar26 = (undefined1  [16])0x0;
        pauVar26 = pauVar26 + 1;
      } while (pauVar25 + ((ulong)uVar7 >> 1) != pauVar26);
      uVar31 = uVar7 & 0xfffffffffffffffe;
      if ((uVar7 & 1) != 0) goto LAB_0011801d;
    }
    lVar18 = _UNK_0012a6a8;
    lVar30 = _DAT_0012a6a0;
    lVar33 = _UNK_0012a698;
    lVar5 = _DAT_0012a690;
    pauVar26 = (undefined1 (*) [16])(*pauVar25 + uVar32);
    if ((pauVar25 < (undefined1 (*) [16])((undefined1 *)local_148._8_8_ + uVar7 * 4) &&
         (ulong)local_148._8_8_ < pauVar26) || (uVar7 - 1 < 3)) {
      uVar31 = 0;
      do {
        *(ulong *)(*pauVar25 + uVar31 * 8) =
             CONCAT44((int)uVar31,*(undefined4 *)((undefined1 *)local_148._8_8_ + uVar31 * 4));
        uVar31 = uVar31 + 1;
      } while (uVar7 != uVar31);
    }
    else {
      lVar27 = 0;
      lVar41 = _DAT_0012a680;
      lVar42 = _UNK_0012a688;
      do {
        puVar1 = (undefined4 *)((undefined1 *)local_148._8_8_ + lVar27);
        uVar20 = *puVar1;
        uVar9 = puVar1[1];
        uVar10 = puVar1[3];
        puVar2 = (undefined4 *)(pauVar25[1] + lVar27 * 2);
        *puVar2 = puVar1[2];
        puVar2[1] = (int)(lVar41 + lVar30);
        puVar2[2] = uVar10;
        puVar2[3] = (int)(lVar42 + lVar18);
        puVar1 = (undefined4 *)(*pauVar25 + lVar27 * 2);
        *puVar1 = uVar20;
        puVar1[1] = (int)lVar41;
        puVar1[2] = uVar9;
        puVar1[3] = (int)lVar42;
        lVar27 = lVar27 + 0x10;
        lVar41 = lVar41 + lVar5;
        lVar42 = lVar42 + lVar33;
      } while (((ulong)uVar7 >> 2) << 4 != lVar27);
      uVar31 = uVar7 & 0xfffffffffffffffc;
      if ((uVar7 & 3) != 0) {
        *(ulong *)(*pauVar25 + uVar31 * 8) =
             CONCAT44((int)uVar31,*(undefined4 *)((undefined1 *)local_148._8_8_ + uVar31 * 4));
        if (uVar31 + 1 < (ulong)uVar7) {
          *(ulong *)(*pauVar25 + uVar31 * 8 + 8) =
               CONCAT44((int)(uVar31 + 1),
                        *(undefined4 *)((undefined1 *)local_148._8_8_ + uVar31 * 4 + 4));
          if (uVar31 + 2 < (ulong)uVar7) {
            *(ulong *)(pauVar25[1] + uVar31 * 8) =
                 CONCAT44((int)(uVar31 + 2),
                          *(undefined4 *)((undefined1 *)local_148._8_8_ + uVar31 * 4 + 8));
          }
        }
      }
    }
    local_120 = 0;
    local_138 = 0;
    local_148 = (undefined1  [16])0x0;
    local_130 = (undefined1  [16])0x0;
    if ((void *)uVar21 == (void *)0x0) {
      if (pauVar25 != pauVar26) goto LAB_00118160;
      uVar32 = *(ulong *)(param_1 + 0x100);
    }
    else {
      operator_delete__((void *)uVar21);
      if (pauVar26 == pauVar25) goto LAB_0011820b;
LAB_00118160:
      lVar5 = 0x3f;
      if ((long)uVar32 >> 3 != 0) {
        for (; (ulong)((long)uVar32 >> 3) >> lVar5 == 0; lVar5 = lVar5 + -1) {
        }
      }
      FUN_001119c0(pauVar25,pauVar26,(long)(int)(0x3f - ((uint)lVar5 ^ 0x3f)) * 2);
      if ((long)uVar32 < 0x81) {
        FUN_001115d0(pauVar25);
      }
      else {
        pauVar36 = pauVar25 + 8;
        FUN_001115d0(pauVar25);
        for (; pauVar36 != pauVar26; pauVar36 = (undefined1 (*) [16])(*pauVar36 + 8)) {
          uVar21 = *(undefined8 *)*pauVar36;
          pauVar28 = pauVar36;
          while( true ) {
            uVar4 = *(uint *)(pauVar28[-1] + 8);
            if ((uVar4 <= (uint)uVar21) &&
               ((uVar4 != (uint)uVar21 ||
                (*(uint *)(pauVar28[-1] + 0xc) <= (uint)((ulong)uVar21 >> 0x20))))) break;
            *(uint *)*pauVar28 = uVar4;
            *(undefined4 *)(*pauVar28 + 4) = *(undefined4 *)(pauVar28[-1] + 0xc);
            pauVar28 = (undefined1 (*) [16])(pauVar28[-1] + 8);
          }
          *(undefined8 *)*pauVar28 = uVar21;
        }
      }
LAB_0011820b:
      uVar32 = *(ulong *)(param_1 + 0x100);
      if (uVar7 == 0) goto LAB_00118d28;
    }
    uVar37 = 0;
    uVar31 = 0;
    do {
      uVar39 = (ulong)*(uint *)(*pauVar25 + uVar37 * 8);
      if (uVar31 < uVar39) {
        do {
          if (uVar32 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
            FUN_00106868();
          }
          uVar34 = *(ulong *)(param_1 + 0xe8);
          if (uVar34 << 6 == uVar32) {
            uVar35 = *(ulong *)(param_1 + 0xf0);
            uVar32 = uVar34 + 1;
            if (uVar35 < uVar32) {
              if (uVar32 >> 1 < uVar35) {
                uVar39 = 0xfffffffffffffff8;
                uVar38 = 0x1fffffffffffffff;
                if (uVar35 < 0x1000000000000000) {
                  uVar38 = uVar35 * 2;
                  uVar39 = uVar35 << 4;
                }
              }
              else {
                uVar39 = uVar32 * 8;
                uVar38 = uVar32;
              }
              pvVar29 = operator_new__(uVar39,(nothrow_t *)PTR_nothrow_00132fb8);
              uVar34 = *(ulong *)(param_1 + 0xe8);
              if (uVar34 != 0) {
                lVar5 = *(long *)(param_1 + 0xd8);
                if ((pvVar29 == (void *)(lVar5 + 8)) || (uVar34 - 1 < 3)) {
                  uVar39 = 0;
                  do {
                    *(undefined8 *)((long)pvVar29 + uVar39 * 8) =
                         *(undefined8 *)(lVar5 + uVar39 * 8);
                    uVar39 = uVar39 + 1;
                  } while (uVar39 != uVar34);
                }
                else {
                  lVar33 = 0;
                  do {
                    uVar21 = ((undefined8 *)(lVar5 + lVar33))[1];
                    *(undefined8 *)((long)pvVar29 + lVar33) = *(undefined8 *)(lVar5 + lVar33);
                    ((undefined8 *)((long)pvVar29 + lVar33))[1] = uVar21;
                    lVar33 = lVar33 + 0x10;
                  } while (lVar33 != (uVar34 >> 1) * 0x10);
                  if ((uVar34 & 1) != 0) {
                    *(undefined8 *)((long)pvVar29 + (uVar34 & 0xfffffffffffffffe) * 8) =
                         *(undefined8 *)(lVar5 + (uVar34 & 0xfffffffffffffffe) * 8);
                  }
                }
              }
              pvVar6 = *(void **)(param_1 + 0xd0);
              *(void **)(param_1 + 0xe0) = pvVar29;
              *(ulong *)(param_1 + 0xf0) = uVar38;
              *(void **)(param_1 + 0xd0) = pvVar29;
              *(void **)(param_1 + 0xd8) = pvVar29;
              if (pvVar6 != (void *)0x0) {
                operator_delete__(pvVar6);
                uVar34 = *(ulong *)(param_1 + 0xe8);
              }
              uVar39 = (ulong)*(uint *)(*pauVar25 + uVar37 * 8);
            }
            if (uVar34 < uVar32) {
              memset((void *)(*(long *)(param_1 + 0xd8) + uVar34 * 8),0,(uVar32 - uVar34) * 8);
            }
            *(ulong *)(param_1 + 0xe8) = uVar32;
            uVar32 = *(ulong *)(param_1 + 0x100);
          }
          uVar32 = uVar32 + 1;
          uVar31 = uVar31 + 1;
          *(ulong *)(param_1 + 0x100) = uVar32;
        } while (uVar31 < uVar39);
      }
      if (uVar39 == uVar31) {
        if (uVar32 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
          FUN_00106868();
        }
        uVar39 = *(ulong *)(param_1 + 0xe8);
        if (uVar39 << 6 == uVar32) {
          uVar34 = *(ulong *)(param_1 + 0xf0);
          uVar32 = uVar39 + 1;
          if (uVar34 < uVar32) {
            if (uVar32 >> 1 < uVar34) {
              uVar39 = 0xfffffffffffffff8;
              uVar35 = 0x1fffffffffffffff;
              if (uVar34 < 0x1000000000000000) {
                uVar39 = uVar34 << 4;
                uVar35 = uVar34 * 2;
              }
            }
            else {
              uVar39 = uVar32 * 8;
              uVar35 = uVar32;
            }
            pvVar29 = operator_new__(uVar39,(nothrow_t *)PTR_nothrow_00132fb8);
            uVar39 = *(ulong *)(param_1 + 0xe8);
            if (uVar39 != 0) {
              lVar5 = *(long *)(param_1 + 0xd8);
              if ((pvVar29 == (void *)(lVar5 + 8)) || (uVar39 - 1 < 3)) {
                uVar34 = 0;
                do {
                  *(undefined8 *)((long)pvVar29 + uVar34 * 8) = *(undefined8 *)(lVar5 + uVar34 * 8);
                  uVar34 = uVar34 + 1;
                } while (uVar34 != uVar39);
              }
              else {
                lVar33 = 0;
                do {
                  uVar21 = ((undefined8 *)(lVar5 + lVar33))[1];
                  *(undefined8 *)((long)pvVar29 + lVar33) = *(undefined8 *)(lVar5 + lVar33);
                  ((undefined8 *)((long)pvVar29 + lVar33))[1] = uVar21;
                  lVar33 = lVar33 + 0x10;
                } while ((uVar39 >> 1) * 0x10 != lVar33);
                if ((uVar39 & 1) != 0) {
                  *(undefined8 *)((long)pvVar29 + (uVar39 & 0xfffffffffffffffe) * 8) =
                       *(undefined8 *)(lVar5 + (uVar39 & 0xfffffffffffffffe) * 8);
                }
              }
            }
            pvVar6 = *(void **)(param_1 + 0xd0);
            *(void **)(param_1 + 0xe0) = pvVar29;
            *(ulong *)(param_1 + 0xf0) = uVar35;
            *(void **)(param_1 + 0xd0) = pvVar29;
            *(void **)(param_1 + 0xd8) = pvVar29;
            if (pvVar6 != (void *)0x0) {
              operator_delete__(pvVar6);
              uVar39 = *(ulong *)(param_1 + 0xe8);
              pvVar29 = *(void **)(param_1 + 0xd8);
            }
          }
          else {
            pvVar29 = *(void **)(param_1 + 0xd8);
          }
          if (uVar39 < uVar32) {
            memset((void *)((long)pvVar29 + uVar39 * 8),0,(uVar32 - uVar39) * 8);
          }
          *(ulong *)(param_1 + 0xe8) = uVar32;
          uVar32 = *(ulong *)(param_1 + 0x100);
        }
        else {
          pvVar29 = *(void **)(param_1 + 0xd8);
        }
        uVar31 = uVar31 + 1;
        puVar3 = (ulong *)((long)pvVar29 + (uVar32 >> 6) * 8);
        *puVar3 = *puVar3 | 1L << ((byte)uVar32 & 0x3f);
        *(long *)(param_1 + 0x108) = *(long *)(param_1 + 0x108) + 1;
        uVar32 = *(long *)(param_1 + 0x100) + 1;
        *(ulong *)(param_1 + 0x100) = uVar32;
      }
      uVar37 = uVar37 + 1;
    } while (uVar37 != uVar7);
  }
  uVar37 = *(ulong *)(param_1 + 0x288);
  if (uVar31 < uVar37) {
    do {
      if (uVar32 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
        FUN_00106868();
      }
      uVar39 = *(ulong *)(param_1 + 0xe8);
      if (uVar39 << 6 == uVar32) {
        uVar37 = *(ulong *)(param_1 + 0xf0);
        uVar32 = uVar39 + 1;
        if (uVar37 < uVar32) {
          if (uVar32 >> 1 < uVar37) {
            uVar39 = 0xfffffffffffffff8;
            uVar34 = 0x1fffffffffffffff;
            if (uVar37 < 0x1000000000000000) {
              uVar34 = uVar37 * 2;
              uVar39 = uVar37 << 4;
            }
          }
          else {
            uVar39 = uVar32 * 8;
            uVar34 = uVar32;
          }
          pvVar29 = operator_new__(uVar39,(nothrow_t *)PTR_nothrow_00132fb8);
          uVar39 = *(ulong *)(param_1 + 0xe8);
          if (uVar39 != 0) {
            lVar5 = *(long *)(param_1 + 0xd8);
            if ((pvVar29 == (void *)(lVar5 + 8)) || (uVar39 - 1 < 3)) {
              uVar37 = 0;
              do {
                *(undefined8 *)((long)pvVar29 + uVar37 * 8) = *(undefined8 *)(lVar5 + uVar37 * 8);
                uVar37 = uVar37 + 1;
              } while (uVar39 != uVar37);
            }
            else {
              lVar33 = 0;
              do {
                uVar21 = ((undefined8 *)(lVar5 + lVar33))[1];
                *(undefined8 *)((long)pvVar29 + lVar33) = *(undefined8 *)(lVar5 + lVar33);
                ((undefined8 *)((long)pvVar29 + lVar33))[1] = uVar21;
                lVar33 = lVar33 + 0x10;
              } while ((uVar39 >> 1) * 0x10 != lVar33);
              if ((uVar39 & 1) != 0) {
                *(undefined8 *)((long)pvVar29 + (uVar39 & 0xfffffffffffffffe) * 8) =
                     *(undefined8 *)(lVar5 + (uVar39 & 0xfffffffffffffffe) * 8);
              }
            }
          }
          pvVar6 = *(void **)(param_1 + 0xd0);
          *(void **)(param_1 + 0xe0) = pvVar29;
          *(ulong *)(param_1 + 0xf0) = uVar34;
          *(void **)(param_1 + 0xd0) = pvVar29;
          *(void **)(param_1 + 0xd8) = pvVar29;
          if (pvVar6 != (void *)0x0) {
            operator_delete__(pvVar6);
            uVar39 = *(ulong *)(param_1 + 0xe8);
          }
        }
        if (uVar39 < uVar32) {
          memset((void *)(*(long *)(param_1 + 0xd8) + uVar39 * 8),0,(uVar32 - uVar39) * 8);
        }
        *(ulong *)(param_1 + 0xe8) = uVar32;
        uVar37 = *(ulong *)(param_1 + 0x288);
        uVar32 = *(ulong *)(param_1 + 0x100);
      }
      uVar32 = uVar32 + 1;
      uVar31 = uVar31 + 1;
      *(ulong *)(param_1 + 0x100) = uVar32;
    } while (uVar31 < uVar37);
  }
  if (uVar32 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_00106868();
  }
  uVar31 = *(ulong *)(param_1 + 0xe8);
  if (uVar31 << 6 == uVar32) {
    uVar37 = *(ulong *)(param_1 + 0xf0);
    uVar32 = uVar31 + 1;
    if (uVar37 < uVar32) {
      if (uVar32 >> 1 < uVar37) {
        uVar31 = 0xfffffffffffffff8;
        uVar39 = 0x1fffffffffffffff;
        if (uVar37 >> 0x3c == 0) {
          uVar39 = uVar37 * 2;
          uVar31 = uVar37 << 4;
        }
      }
      else {
        uVar31 = uVar32 * 8;
        uVar39 = uVar32;
      }
      pvVar29 = operator_new__(uVar31,(nothrow_t *)PTR_nothrow_00132fb8);
      uVar31 = *(ulong *)(param_1 + 0xe8);
      if (uVar31 != 0) {
        lVar5 = *(long *)(param_1 + 0xd8);
        if ((pvVar29 == (void *)(lVar5 + 8)) || (uVar31 - 1 < 3)) {
          uVar37 = 0;
          do {
            *(undefined8 *)((long)pvVar29 + uVar37 * 8) = *(undefined8 *)(lVar5 + uVar37 * 8);
            uVar37 = uVar37 + 1;
          } while (uVar31 != uVar37);
        }
        else {
          lVar33 = 0;
          do {
            uVar21 = ((undefined8 *)(lVar5 + lVar33))[1];
            *(undefined8 *)((long)pvVar29 + lVar33) = *(undefined8 *)(lVar5 + lVar33);
            ((undefined8 *)((long)pvVar29 + lVar33))[1] = uVar21;
            lVar33 = lVar33 + 0x10;
          } while (lVar33 != (uVar31 >> 1) * 0x10);
          if ((uVar31 & 1) != 0) {
            *(undefined8 *)((long)pvVar29 + (uVar31 & 0xfffffffffffffffe) * 8) =
                 *(undefined8 *)(lVar5 + (uVar31 & 0xfffffffffffffffe) * 8);
          }
        }
      }
      pvVar6 = *(void **)(param_1 + 0xd0);
      *(void **)(param_1 + 0xe0) = pvVar29;
      *(ulong *)(param_1 + 0xf0) = uVar39;
      *(void **)(param_1 + 0xd0) = pvVar29;
      *(void **)(param_1 + 0xd8) = pvVar29;
      if (pvVar6 != (void *)0x0) {
        operator_delete__(pvVar6);
        uVar31 = *(ulong *)(param_1 + 0xe8);
      }
    }
    if (uVar31 < uVar32) {
      memset((void *)(*(long *)(param_1 + 0xd8) + uVar31 * 8),0,(uVar32 - uVar31) * 8);
    }
    *(ulong *)(param_1 + 0xe8) = uVar32;
    uVar32 = *(ulong *)(param_1 + 0x100);
  }
  *(ulong *)(param_1 + 0x100) = uVar32 + 1;
  local_108 = 0;
  local_f0 = 0;
  local_c8 = 0;
  local_b0 = 0;
  local_98 = 0;
  local_80 = 0;
  local_68 = 0;
  local_50 = 0;
  local_118 = (undefined1  [16])0x0;
  local_100 = (undefined1  [16])0x0;
  local_e8 = (undefined1  [16])0x0;
  local_d8 = (undefined1  [16])0x0;
  local_c0 = (undefined1  [16])0x0;
  local_a8 = (undefined1  [16])0x0;
  local_90 = (undefined1  [16])0x0;
  local_78 = (undefined1  [16])0x0;
  local_60 = (undefined1  [16])0x0;
  FUN_00126020(local_118,param_1 + 0xd0,0,1);
  if (*(char *)(param_1 + 0xf8) != '\0') {
    uVar21 = FUN_001065cc();
    operator_delete__(pauVar25);
    if ((void *)local_148._0_8_ != (void *)0x0) {
      operator_delete__((void *)local_148._0_8_);
    }
    if (local_178 != (undefined8 *)0x0) {
      operator_delete__(local_178);
    }
                    /* WARNING: Subroutine does not return */
    _Unwind_Resume(uVar21);
  }
  lVar5 = *(long *)(param_1 + 0xe8);
  uVar19 = 0;
  if (lVar5 != *(long *)(param_1 + 0xf0)) {
    pvVar29 = operator_new__(lVar5 * 8,(nothrow_t *)PTR_nothrow_00132fb8);
    uVar32 = *(ulong *)(param_1 + 0xe8);
    if (uVar32 != 0) {
      lVar33 = *(long *)(param_1 + 0xd8);
      if ((uVar32 - 1 < 3) || (pvVar29 == (void *)(lVar33 + 8))) {
        uVar31 = 0;
        do {
          *(undefined8 *)((long)pvVar29 + uVar31 * 8) = *(undefined8 *)(lVar33 + uVar31 * 8);
          uVar31 = uVar31 + 1;
        } while (uVar32 != uVar31);
      }
      else {
        lVar30 = 0;
        do {
          uVar21 = ((undefined8 *)(lVar33 + lVar30))[1];
          *(undefined8 *)((long)pvVar29 + lVar30) = *(undefined8 *)(lVar33 + lVar30);
          ((undefined8 *)((long)pvVar29 + lVar30))[1] = uVar21;
          lVar30 = lVar30 + 0x10;
        } while ((uVar32 >> 1) * 0x10 != lVar30);
        if ((uVar32 & 1) != 0) {
          *(undefined8 *)((long)pvVar29 + (uVar32 & 0xfffffffffffffffe) * 8) =
               *(undefined8 *)(lVar33 + (uVar32 & 0xfffffffffffffffe) * 8);
        }
      }
    }
    pvVar6 = *(void **)(param_1 + 0xd0);
    *(void **)(param_1 + 0xe0) = pvVar29;
    *(long *)(param_1 + 0xf0) = lVar5;
    *(void **)(param_1 + 0xd0) = pvVar29;
    *(void **)(param_1 + 0xd8) = pvVar29;
    if (pvVar6 != (void *)0x0) {
      operator_delete__(pvVar6);
    }
    uVar19 = *(undefined1 *)(param_1 + 0xf8);
  }
  auVar11 = *(undefined1 (*) [16])(param_1 + 0x100);
  *(undefined1 *)(param_1 + 0xf8) = uVar19;
  uVar21 = *(undefined8 *)(param_1 + 0x120);
  auVar12 = *(undefined1 (*) [16])(param_1 + 0x110);
  *(undefined8 *)(param_1 + 0x120) = local_c8;
  auVar13 = *(undefined1 (*) [16])(param_1 + 0x128);
  uVar19 = *(undefined1 *)(param_1 + 0x138);
  pvVar29 = *(void **)*(undefined1 (*) [16])(param_1 + 0x140);
  auVar14 = *(undefined1 (*) [16])(param_1 + 0x140);
  *(undefined1 *)(param_1 + 0x138) = (undefined1)local_b0;
  local_b0 = CONCAT71(local_b0._1_7_,uVar19);
  uVar7 = *(undefined8 *)(param_1 + 0x150);
  *(undefined8 *)(param_1 + 0x100) = local_e8._0_8_;
  *(undefined8 *)(param_1 + 0x108) = local_e8._8_8_;
  *(undefined8 *)(param_1 + 0x110) = local_d8._0_8_;
  *(undefined8 *)(param_1 + 0x118) = local_d8._8_8_;
  auVar15 = *(undefined1 (*) [16])(param_1 + 0x158);
  *(undefined8 *)(param_1 + 0x150) = local_98;
  *(undefined8 *)(param_1 + 0x128) = local_c0._0_8_;
  *(undefined8 *)(param_1 + 0x130) = local_c0._8_8_;
  *(undefined8 *)(param_1 + 0x140) = local_a8._0_8_;
  *(undefined8 *)(param_1 + 0x148) = local_a8._8_8_;
  *(undefined8 *)(param_1 + 0x158) = local_90._0_8_;
  *(undefined8 *)(param_1 + 0x160) = local_90._8_8_;
  uVar19 = *(undefined1 *)(param_1 + 0x168);
  pvVar6 = *(void **)*(undefined1 (*) [16])(param_1 + 0x170);
  auVar16 = *(undefined1 (*) [16])(param_1 + 0x170);
  *(undefined1 *)(param_1 + 0x168) = (undefined1)local_80;
  local_80 = CONCAT71(local_80._1_7_,uVar19);
  uVar8 = *(undefined8 *)(param_1 + 0x180);
  auVar17 = *(undefined1 (*) [16])(param_1 + 0x188);
  *(undefined8 *)(param_1 + 0x180) = local_68;
  uVar19 = *(undefined1 *)(param_1 + 0x198);
  *(undefined8 *)(param_1 + 0x170) = local_78._0_8_;
  *(undefined8 *)(param_1 + 0x178) = local_78._8_8_;
  *(undefined1 *)(param_1 + 0x198) = (undefined1)local_50;
  local_50 = CONCAT71(local_50._1_7_,uVar19);
  *(undefined8 *)(param_1 + 0x188) = local_60._0_8_;
  *(undefined8 *)(param_1 + 400) = local_60._8_8_;
  local_e8 = auVar11;
  local_d8 = auVar12;
  local_c8 = uVar21;
  local_c0 = auVar13;
  local_a8 = auVar14;
  local_98 = uVar7;
  local_90 = auVar15;
  local_78 = auVar16;
  local_68 = uVar8;
  local_60 = auVar17;
  if (pvVar6 != (void *)0x0) {
    operator_delete__(pvVar6);
    pvVar29 = (void *)local_a8._0_8_;
  }
  if (pvVar29 != (void *)0x0) {
    operator_delete__(pvVar29);
  }
  if ((void *)local_d8._0_8_ != (void *)0x0) {
    operator_delete__((void *)local_d8._0_8_);
  }
  if ((void *)local_118._0_8_ != (void *)0x0) {
    operator_delete__((void *)local_118._0_8_);
  }
  uVar32 = 0;
  if (*(long *)(param_2 + 0x58) == 0) {
    if (pauVar25 == (undefined1 (*) [16])0x0) goto LAB_001189f2;
  }
  else {
    do {
      uVar4 = *(uint *)(*pauVar25 + uVar32 * 8 + 4);
      lVar5 = *(long *)(*(long *)(param_2 + 0x30) + (ulong)(uVar4 >> 8) * 8);
      uVar20 = FUN_00124bd0(param_1 + 0xd0,*(undefined4 *)(*pauVar25 + uVar32 * 8));
      *(undefined4 *)((ulong)(byte)uVar4 * 0x10 + lVar5 + 0xc) = uVar20;
      uVar32 = uVar32 + 1;
    } while (uVar32 < *(ulong *)(param_2 + 0x58));
  }
  operator_delete__(pauVar25);
LAB_001189f2:
  if (local_178 != (undefined8 *)0x0) {
    operator_delete__(local_178);
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_00118e40 @ 00118e40 size=641 =====

void FUN_00118e40(undefined8 param_1,undefined8 param_2,uint param_3)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  long in_FS_OFFSET;
  long local_4b8;
  undefined8 local_4b0;
  undefined4 local_4a8;
  undefined1 local_498 [1144];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_4b8 = 3;
  local_4a8 = 0x20000;
  local_4b0 = DAT_0012a630;
  if ((param_3 & 0xfff00000) != 0) {
    puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar2 = &PTR_FUN_00132da8;
    puVar2[1] = "../src_udic/marisa_u/grimoire/trie/config.h";
    puVar2[2] = 0x50000003a;
    puVar2[3] = 
    "../src_udic/marisa_u/grimoire/trie/config.h:58: MARISA_CODE_ERROR: (config_flags & ~MARISA_CONFIG_MASK) != 0"
    ;
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  uVar3 = param_3 & 0x7f;
  if (uVar3 == 0) {
    uVar3 = 3;
  }
  uVar4 = param_3 & 0xf80;
  if (uVar4 != 0x200) {
    if (0x200 < uVar4) {
      if (uVar4 == 0x400) {
        uVar5 = 0x400;
      }
      else {
        if (uVar4 != 0x800) {
          puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
          *puVar2 = &PTR_FUN_00132da8;
          puVar2[1] = "../src_udic/marisa_u/grimoire/trie/config.h";
          puVar2[2] = 0x500000065;
          puVar2[3] = 
          "../src_udic/marisa_u/grimoire/trie/config.h:101: MARISA_CODE_ERROR: undefined cache level"
          ;
                    /* WARNING: Subroutine does not return */
          __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
        }
        uVar5 = 0x800;
      }
      goto joined_r0x00118fcf;
    }
    if (uVar4 == 0x80) {
      uVar5 = 0x80;
      goto joined_r0x00118fcf;
    }
    if (uVar4 == 0x100) {
      uVar5 = 0x100;
      goto joined_r0x00118fcf;
    }
    if (uVar4 != 0) {
      FUN_00107464();
      return;
    }
  }
  uVar5 = 0x200;
joined_r0x00118fcf:
  if ((param_3 & 0xf000) == 0x1000) {
    uVar6 = 0x1000;
  }
  else {
    uVar6 = 0x2000;
    if (((param_3 & 0xf000) != 0x2000) && (uVar6 = 0x1000, (param_3 & 0xf000) != 0)) {
      FUN_00107543();
      return;
    }
  }
  if ((param_3 & 0xf0000) == 0x10000) {
    uVar1 = 0x10000;
  }
  else {
    uVar1 = 0x20000;
    if ((param_3 & 0xd0000) != 0) {
      puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
      *puVar2 = &PTR_FUN_00132da8;
      puVar2[1] = "../src_udic/marisa_u/grimoire/trie/config.h";
      puVar2[2] = 0x50000008d;
      puVar2[3] = 
      "../src_udic/marisa_u/grimoire/trie/config.h:141: MARISA_CODE_ERROR: undefined node order";
                    /* WARNING: Subroutine does not return */
      __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
    }
  }
  local_4a8 = uVar1;
  local_4b8 = (long)(int)uVar3;
  local_4b0 = CONCAT44(uVar6,uVar5);
  FUN_00112770(local_498);
  FUN_00117dd0(local_498,param_2,&local_4b8);
  FUN_00112ca0(param_1,local_498);
  FUN_001125e0(local_498);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_00119060 @ 00119060 size=1201 =====

void FUN_00119060(long param_1,long param_2,undefined8 param_3,long *param_4,long param_5)

{
  undefined4 uVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined1 auVar11 [16];
  undefined8 uVar12;
  undefined8 *puVar13;
  void *pvVar14;
  undefined8 *puVar15;
  undefined8 *puVar16;
  ulong uVar17;
  undefined8 *puVar18;
  undefined4 *puVar19;
  void *pvVar20;
  long lVar21;
  ulong uVar22;
  ulong uVar23;
  long in_FS_OFFSET;
  undefined1 local_78 [16];
  undefined8 *local_68;
  undefined1 local_60 [16];
  undefined1 local_50;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_5 == *param_4) {
    uVar2 = *(ulong *)(param_2 + 0x18);
    local_50 = 0;
    local_68 = (undefined8 *)0x0;
    local_78 = (undefined1  [16])0x0;
    local_60 = (undefined1  [16])0x0;
    if (uVar2 == 0) {
      local_60 = ZEXT816(0) << 0x40;
    }
    else {
      puVar13 = operator_new__(uVar2 << 4,(nothrow_t *)PTR_nothrow_00132fb8);
      uVar17 = local_60._0_8_;
      uVar12 = local_78._0_8_;
      local_68 = puVar13;
      if (local_60._0_8_ == 0) {
        auVar11._8_8_ = 0;
        auVar11._0_8_ = uVar2;
        local_60 = auVar11 << 0x40;
        local_78._8_8_ = puVar13;
        local_78._0_8_ = puVar13;
        if ((void *)uVar12 != (void *)0x0) goto LAB_001192ff;
        lVar21 = *(long *)(param_2 + 0x18);
LAB_0011931b:
        uVar23 = uVar17 + 1;
        uVar22 = 1;
        if (uVar23 <= uVar2) {
          uVar22 = uVar2 - uVar17;
        }
        if ((2 < (uVar2 - uVar17) - 1) && (uVar23 <= uVar2)) {
          puVar16 = puVar13 + uVar17 * 2 + 1;
          puVar18 = puVar13 + uVar17 * 2;
          do {
            *puVar18 = 0xffffffffffffffff;
            puVar15 = puVar16 + 8;
            puVar18[2] = 0xffffffffffffffff;
            puVar18[4] = 0xffffffffffffffff;
            puVar18[6] = 0xffffffffffffffff;
            *puVar16 = 0;
            puVar16[2] = 0;
            puVar16[4] = 0;
            puVar16[6] = 0;
            puVar16 = puVar15;
            puVar18 = puVar18 + 8;
          } while (puVar15 != puVar13 + uVar17 * 2 + 1 + (uVar22 >> 2) * 8);
          uVar17 = uVar17 + (uVar22 & 0xfffffffffffffffc);
          if (uVar22 == (uVar22 & 0xfffffffffffffffc)) goto LAB_0011941f;
          uVar23 = uVar17 + 1;
        }
        puVar13[uVar17 * 2] = 0xffffffffffffffff;
        (puVar13 + uVar17 * 2)[1] = 0;
        if (uVar23 < uVar2) {
          puVar13[uVar17 * 2 + 2] = 0xffffffffffffffff;
          (puVar13 + uVar17 * 2 + 2)[1] = 0;
          if (uVar17 + 2 < uVar2) {
            puVar13[uVar17 * 2 + 4] = 0xffffffffffffffff;
            (puVar13 + uVar17 * 2 + 4)[1] = 0;
          }
        }
      }
      else {
        uVar23 = local_60._0_8_ - 1;
        if (((ulong)((long)puVar13 - (long)(local_78._8_8_ + 0x10)) < 0x21 || uVar23 < 4) ||
           ((ulong)((long)(puVar13 + 1) - (long)(local_78._8_8_ + 0x18)) < 0x21)) {
          puVar16 = puVar13;
          do {
            puVar18 = puVar16 + 2;
            *puVar16 = *(undefined8 *)local_78._8_8_;
            puVar16[1] = *(undefined8 *)(local_78._8_8_ + 8);
            local_78._8_8_ = (undefined8 *)(local_78._8_8_ + 0x10);
            puVar16 = puVar18;
          } while (puVar18 != puVar13 + local_60._0_8_ * 2);
        }
        else {
          puVar16 = (undefined8 *)local_78._8_8_;
          puVar18 = puVar13 + 1;
          do {
            uVar9 = *(undefined4 *)(puVar16 + 1);
            uVar10 = *(undefined4 *)((long)puVar16 + 0xc);
            puVar15 = puVar16 + 8;
            uVar1 = *(undefined4 *)(puVar16 + 3);
            uVar4 = *(undefined4 *)((long)puVar16 + 0x1c);
            uVar7 = *(undefined4 *)(puVar16 + 5);
            uVar8 = *(undefined4 *)((long)puVar16 + 0x2c);
            puVar18[-1] = *puVar16;
            uVar3 = puVar16[2];
            uVar5 = *(undefined4 *)(puVar16 + 7);
            uVar6 = *(undefined4 *)((long)puVar16 + 0x3c);
            *(undefined4 *)puVar18 = uVar9;
            *(undefined4 *)((long)puVar18 + 4) = uVar10;
            puVar18[1] = uVar3;
            uVar3 = puVar16[4];
            *(undefined4 *)(puVar18 + 2) = uVar1;
            *(undefined4 *)((long)puVar18 + 0x14) = uVar4;
            puVar18[3] = uVar3;
            uVar3 = puVar16[6];
            *(undefined4 *)(puVar18 + 4) = uVar7;
            *(undefined4 *)((long)puVar18 + 0x24) = uVar8;
            puVar18[5] = uVar3;
            *(undefined4 *)(puVar18 + 6) = uVar5;
            *(undefined4 *)((long)puVar18 + 0x34) = uVar6;
            puVar16 = puVar15;
            puVar18 = puVar18 + 8;
          } while ((undefined8 *)(local_78._8_8_ + (uVar23 >> 2) * 8 * 8) != puVar15);
          uVar23 = uVar23 & 0xfffffffffffffffc;
          uVar3 = ((undefined8 *)(local_78._8_8_ + uVar23 * 2 * 8))[1];
          puVar13[uVar23 * 2] = *(undefined8 *)(local_78._8_8_ + uVar23 * 2 * 8);
          (puVar13 + uVar23 * 2)[1] = uVar3;
          if (uVar23 + 1 < (ulong)local_60._0_8_) {
            uVar3 = *(undefined8 *)(local_78._8_8_ + (uVar23 * 2 + 2) * 8);
            (puVar13 + uVar23 * 2 + 2)[1] =
                 ((undefined8 *)(local_78._8_8_ + (uVar23 * 2 + 2) * 8))[1];
            puVar13[uVar23 * 2 + 2] = uVar3;
            if (uVar23 + 2 < (ulong)local_60._0_8_) {
              uVar3 = ((undefined8 *)(local_78._8_8_ + (uVar23 * 2 + 4) * 8))[1];
              puVar13[uVar23 * 2 + 4] = *(undefined8 *)(local_78._8_8_ + (uVar23 * 2 + 4) * 8);
              (puVar13 + uVar23 * 2 + 4)[1] = uVar3;
              if (uVar23 + 3 < (ulong)local_60._0_8_) {
                uVar3 = ((undefined8 *)(local_78._8_8_ + (uVar23 * 2 + 6) * 8))[1];
                puVar13[uVar23 * 2 + 6] = *(undefined8 *)(local_78._8_8_ + (uVar23 * 2 + 6) * 8);
                (puVar13 + uVar23 * 2 + 6)[1] = uVar3;
              }
            }
          }
        }
        local_78._8_8_ = puVar13;
        local_78._0_8_ = puVar13;
        local_60._8_8_ = uVar2;
        if ((void *)uVar12 != (void *)0x0) {
LAB_001192ff:
          local_78._8_8_ = puVar13;
          local_78._0_8_ = puVar13;
          local_60._8_8_ = uVar2;
          local_60 = CONCAT88(local_60._8_8_,uVar17);
          operator_delete__((void *)uVar12);
          uVar17 = local_60._0_8_;
        }
        lVar21 = *(long *)(param_2 + 0x18);
        if (uVar17 < uVar2) {
          puVar13 = (undefined8 *)local_78._8_8_;
          goto LAB_0011931b;
        }
      }
LAB_0011941f:
      local_60._0_8_ = uVar2;
      if (lVar21 != 0) {
        puVar19 = (undefined4 *)(*(long *)(param_2 + 8) + 8);
        puVar13 = (undefined8 *)local_78._8_8_;
        do {
          uVar1 = *puVar19;
          puVar16 = (undefined8 *)(puVar19 + -2);
          puVar18 = puVar13 + 2;
          puVar19 = puVar19 + 6;
          *puVar13 = *puVar16;
          *(undefined4 *)(puVar13 + 1) = uVar1;
          puVar13 = puVar18;
        } while ((undefined8 *)(local_78._8_8_ + lVar21 * 2 * 8) != puVar18);
      }
    }
    FUN_00123720(param_1 + 0x2e8,local_78,param_3,*(undefined4 *)((long)param_4 + 0xc));
    if ((void *)local_78._0_8_ != (void *)0x0) {
      operator_delete__((void *)local_78._0_8_);
    }
    if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
    goto LAB_00119517;
  }
  pvVar14 = operator_new(0x470,(nothrow_t *)PTR_nothrow_00132fb8);
  if (pvVar14 == (void *)0x0) {
    pvVar20 = *(void **)(param_1 + 1000);
    *(undefined8 *)(param_1 + 1000) = 0;
    if (pvVar20 == (void *)0x0) {
      puVar13 = (undefined8 *)__cxa_allocate_exception(0x20);
      puVar13[2] = 0x8000001d4;
      puVar13[3] = 
      "../src_udic/marisa_u/grimoire/trie/louds-trie.cpp:468: MARISA_MEMORY_ERROR: next_trie_.get() == NULL"
      ;
      *puVar13 = &PTR_FUN_00132da8;
      puVar13[1] = "../src_udic/marisa_u/grimoire/trie/louds-trie.cpp";
                    /* WARNING: Subroutine does not return */
      __cxa_throw(puVar13,&PTR_vtable_00132d80,FUN_0010e6a0);
    }
LAB_00119130:
    FUN_001125e0();
    operator_delete(pvVar20);
    pvVar14 = *(void **)(param_1 + 1000);
    if (pvVar14 == (void *)0x0) {
      FUN_0010759e();
      return;
    }
  }
  else {
    FUN_00112770(pvVar14);
    pvVar20 = *(void **)(param_1 + 1000);
    if (pvVar14 == pvVar20) {
      FUN_0010656c();
      if ((void *)local_78._0_8_ == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        _Unwind_Resume(param_2);
      }
      operator_delete__((void *)local_78._0_8_);
      FUN_00107609();
      return;
    }
    *(void **)(param_1 + 1000) = pvVar14;
    if (pvVar20 != (void *)0x0) goto LAB_00119130;
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    FUN_001200d0(pvVar14,param_2,param_3,param_4,param_5 + 1);
    return;
  }
LAB_00119517:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_00119540 @ 00119540 size=69 =====

void FUN_00119540(undefined8 *param_1)

{
  if ((void *)param_1[0x14] != (void *)0x0) {
    operator_delete__((void *)param_1[0x14]);
  }
  if ((void *)param_1[0xe] != (void *)0x0) {
    operator_delete__((void *)param_1[0xe]);
  }
  if ((void *)param_1[8] != (void *)0x0) {
    operator_delete__((void *)param_1[8]);
  }
  if ((void *)*param_1 != (void *)0x0) {
    operator_delete__((void *)*param_1);
    return;
  }
  return;
}


//===== FUN_00119590 @ 00119590 size=1114 =====

void FUN_00119590(undefined1 (*param_1) [16],undefined8 param_2)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  void *pvVar5;
  void *pvVar6;
  void *pvVar7;
  void *pvVar8;
  ulong *puVar9;
  undefined8 uVar10;
  uint *puVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 *puVar15;
  ulong uVar16;
  ulong uVar17;
  long in_FS_OFFSET;
  undefined1 local_118 [16];
  undefined8 local_108;
  undefined1 local_100 [16];
  undefined8 local_f0;
  undefined1 local_e8 [16];
  undefined1 local_d8 [16];
  undefined8 local_c8;
  undefined1 local_c0 [16];
  undefined8 local_b0;
  undefined1 local_a8 [16];
  undefined8 local_98;
  undefined1 local_90 [16];
  undefined8 local_80;
  undefined1 local_78 [16];
  undefined8 local_68;
  undefined1 local_60 [16];
  undefined8 local_50;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_118 = (undefined1  [16])0x0;
  local_108 = 0;
  local_f0 = 0;
  local_c8 = 0;
  local_b0 = 0;
  local_98 = 0;
  local_80 = 0;
  local_68 = 0;
  local_50 = 0;
  local_100 = (undefined1  [16])0x0;
  local_e8 = (undefined1  [16])0x0;
  local_d8 = (undefined1  [16])0x0;
  local_c0 = (undefined1  [16])0x0;
  local_a8 = (undefined1  [16])0x0;
  local_90 = (undefined1  [16])0x0;
  local_78 = (undefined1  [16])0x0;
  local_60 = (undefined1  [16])0x0;
  puVar9 = (ulong *)FUN_00110420(param_2,8);
  uVar2 = *puVar9;
  if ((uVar2 & 7) != 0) {
    FUN_001066ea();
    goto LAB_001199db;
  }
  uVar10 = FUN_00110420(param_2,uVar2 & 0xfffffffffffffff8);
  FUN_00110490(param_2,-(int)uVar2 & 7);
  local_100._0_8_ = uVar2 >> 3;
  local_f0 = CONCAT71(local_f0._1_7_,1);
  local_108 = uVar10;
  puVar11 = (uint *)FUN_00110420(param_2,4);
  uVar17 = CONCAT44(0,*puVar11);
  local_e8._0_8_ = uVar17;
  puVar11 = (uint *)FUN_00110420(param_2,4);
  uVar1 = *puVar11;
  if (uVar17 < uVar1) {
    puVar15 = (undefined8 *)__cxa_allocate_exception(0x20);
    puVar15[2] = 0xa00000091;
    puVar15[3] = 
    "../src_udic/marisa_u/grimoire/trie/../vector/bit-vector.h:145: MARISA_FORMAT_ERROR: temp_num_1s > size_"
    ;
    *puVar15 = &PTR_FUN_00132da8;
    puVar15[1] = "../src_udic/marisa_u/grimoire/trie/../vector/bit-vector.h";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar15,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  local_e8._8_4_ = uVar1;
  local_e8._12_4_ = 0;
  puVar9 = (ulong *)FUN_00110420(param_2,8);
  uVar3 = *puVar9;
  if ((uVar3 * -0x5555555555555555 >> 2 | uVar3 * -0x5555555555555555 << 0x3e) < 0x1555555555555556)
  {
    uVar16 = uVar3 / 0xc;
    uVar12 = FUN_00110420(param_2,uVar16 * 0xc);
    FUN_00110490(param_2,-(int)uVar3 & 7);
    local_c0._0_8_ = uVar16;
    local_b0 = CONCAT71(local_b0._1_7_,1);
    local_c8 = uVar12;
    puVar9 = (ulong *)FUN_00110420(param_2,8);
    uVar3 = *puVar9;
    if ((uVar3 & 3) != 0) {
      FUN_001066ea();
      goto LAB_00119967;
    }
    uVar13 = FUN_00110420(param_2,uVar3 & 0xfffffffffffffffc);
    FUN_00110490(param_2,-(int)uVar3 & 7);
    local_80 = CONCAT71(local_80._1_7_,1);
    local_90._0_8_ = uVar3 >> 2;
    local_98 = uVar13;
    puVar9 = (ulong *)FUN_00110420(param_2,8);
    uVar4 = *puVar9;
    if ((uVar4 & 3) == 0) {
      uVar14 = FUN_00110420(param_2,uVar4 & 0xfffffffffffffffc);
      FUN_00110490(param_2,-(int)uVar4 & 7);
      *(ulong *)(param_1[5] + 8) = uVar16;
      pvVar5 = *(void **)param_1[10];
      *(undefined8 *)param_1[1] = uVar10;
      pvVar6 = *(void **)*param_1;
      *param_1 = (undefined1  [16])0x0;
      pvVar7 = *(void **)param_1[4];
      pvVar8 = *(void **)param_1[7];
      *(ulong *)(param_1[1] + 8) = uVar2 >> 3;
      *(undefined8 *)param_1[2] = 0;
      param_1[2][8] = 1;
      *(undefined8 *)param_1[8] = uVar13;
      *(undefined8 *)param_1[5] = uVar12;
      *(undefined8 *)param_1[6] = 0;
      param_1[6][8] = 1;
      *(ulong *)(param_1[8] + 8) = uVar3 >> 2;
      *(undefined8 *)param_1[9] = 0;
      param_1[9][8] = 1;
      *(undefined8 *)param_1[0xb] = uVar14;
      *(ulong *)(param_1[0xb] + 8) = uVar4 >> 2;
      *(undefined8 *)param_1[0xc] = 0;
      param_1[0xc][8] = 1;
      *(ulong *)param_1[3] = uVar17;
      *(ulong *)(param_1[3] + 8) = (ulong)uVar1;
      param_1[4] = (undefined1  [16])0x0;
      param_1[7] = (undefined1  [16])0x0;
      param_1[10] = (undefined1  [16])0x0;
      if (pvVar5 != (void *)0x0) {
        operator_delete__(pvVar5);
      }
      if (pvVar8 != (void *)0x0) {
        operator_delete__(pvVar8);
      }
      if (pvVar7 != (void *)0x0) {
        operator_delete__(pvVar7);
      }
      if (pvVar6 == (void *)0x0) {
        if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
          return;
        }
      }
      else if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
        operator_delete__(pvVar6);
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
  }
  else {
LAB_00119967:
    FUN_001066ea();
  }
  param_2 = FUN_001066ea();
LAB_001199db:
  FUN_00119540(local_118);
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume(param_2);
}


//===== FUN_001199f0 @ 001199f0 size=2194 =====

void FUN_001199f0(undefined8 *param_1,undefined8 param_2)

{
  void *pvVar1;
  void *pvVar2;
  void *pvVar3;
  void *pvVar4;
  uint uVar5;
  ulong uVar6;
  undefined1 (*pauVar7) [16];
  undefined1 (*pauVar8) [16];
  long lVar9;
  ulong uVar10;
  undefined8 *puVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  long in_FS_OFFSET;
  undefined1 local_1c8 [16];
  undefined1 (*pauStack_1a0) [16];
  void *pvStack_190;
  ulong uStack_160;
  undefined1 local_158 [8];
  void *pvStack_150;
  ulong uStack_140;
  uint local_120;
  undefined4 uStack_11c;
  void *local_118;
  void *pvStack_110;
  void *local_108;
  undefined1 local_100 [16];
  undefined8 local_f0;
  undefined1 local_e8 [16];
  undefined1 local_d8 [16];
  undefined1 (*local_c8) [16];
  ulong local_c0;
  ulong uStack_b8;
  undefined8 local_b0;
  void *local_a8;
  void *pvStack_a0;
  void *local_98;
  undefined1 local_90 [16];
  undefined8 local_80;
  undefined1 local_78 [16];
  undefined8 local_68;
  undefined1 local_60 [16];
  undefined8 local_50;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_108 = (void *)0x0;
  local_f0 = 0;
  local_c8 = (undefined1 (*) [16])0x0;
  local_b0 = 0;
  local_98 = (void *)0x0;
  local_80 = 0;
  local_68 = 0;
  local_50 = 0;
  local_118 = (void *)0x0;
  pvStack_110 = (void *)0x0;
  local_100 = (undefined1  [16])0x0;
  local_e8 = (undefined1  [16])0x0;
  local_d8 = (undefined1  [16])0x0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_a8 = (void *)0x0;
  pvStack_a0 = (void *)0x0;
  local_90 = (undefined1  [16])0x0;
  local_78 = (undefined1  [16])0x0;
  local_60 = (undefined1  [16])0x0;
  FUN_00110a70(param_2,&local_120,8);
  if ((local_120 & 7) != 0) {
    param_1 = (undefined8 *)FUN_001067a8();
    goto LAB_0011a109;
  }
  uVar12 = CONCAT44(uStack_11c,local_120) & 0xfffffffffffffff8;
  uVar6 = CONCAT44(uStack_11c,local_120) >> 3;
  if (uVar6 == 0) {
    FUN_00110a70(param_2,0,0);
    pvStack_190 = (void *)0x0;
    local_1c8 = (undefined1  [16])0x0;
  }
  else {
    pvStack_190 = operator_new__(uVar12,(nothrow_t *)PTR_nothrow_00132fb8);
    if (pvStack_190 == (void *)0x0) {
      puVar11 = (undefined8 *)__cxa_allocate_exception(0x20);
      *puVar11 = &PTR_FUN_00132da8;
      puVar11[1] = "../src_udic/marisa_u/grimoire/trie/../io/reader.h";
      puVar11[2] = 0x20000001f;
      puVar11[3] = 
      "../src_udic/marisa_u/grimoire/trie/../io/reader.h:31: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
      ;
                    /* WARNING: Subroutine does not return */
      __cxa_throw(puVar11,&PTR_vtable_00132d80,FUN_0010e6a0);
    }
    local_1c8._8_8_ = uVar6;
    local_1c8._0_8_ = uVar6;
    FUN_00110a70(param_2,pvStack_190,uVar12);
  }
  FUN_00110b80(param_2,-local_120 & 7);
  local_108 = pvStack_190;
  local_118 = pvStack_190;
  pvStack_110 = pvStack_190;
  local_100 = local_1c8;
  FUN_00110a70(param_2,&local_120,4);
  uVar12 = CONCAT44(0,local_120);
  local_e8._0_8_ = uVar12;
  FUN_00110a70(param_2,&local_120,4);
  uVar5 = local_120;
  if (uVar12 < local_120) {
    puVar11 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar11 = &PTR_FUN_00132da8;
    puVar11[1] = "../src_udic/marisa_u/grimoire/trie/../vector/bit-vector.h";
    puVar11[2] = 0xa000000a3;
    puVar11[3] = 
    "../src_udic/marisa_u/grimoire/trie/../vector/bit-vector.h:163: MARISA_FORMAT_ERROR: temp_num_1s > size_"
    ;
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar11,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  local_e8._8_4_ = local_120;
  local_e8._12_4_ = 0;
  FUN_00110a70(param_2,&local_120,8);
  uVar10 = CONCAT44(uStack_11c,local_120);
  uVar13 = uVar10 / 0xc;
  if (uVar10 % 0xc != 0) {
    param_1 = (undefined8 *)FUN_001067a8();
    goto LAB_0011a109;
  }
  if (uVar10 < 0xc) {
    local_1c8._8_8_ = 0;
    pauStack_1a0 = (undefined1 (*) [16])0x0;
  }
  else {
    pauStack_1a0 = operator_new__(uVar13 * 0xc,(nothrow_t *)PTR_nothrow_00132fb8);
    uVar14 = 0;
    if (uVar10 < 0x30) {
LAB_00119cd8:
      lVar9 = uVar14 * 0xc;
      *(undefined8 *)(*pauStack_1a0 + lVar9) = 0;
      *(undefined4 *)((long)(*pauStack_1a0 + lVar9) + 8) = 0;
      if (uVar14 + 1 < uVar13) {
        *(undefined8 *)(*pauStack_1a0 + lVar9 + 0xc) = 0;
        *(undefined4 *)((long)(*pauStack_1a0 + lVar9 + 0xc) + 8) = 0;
        if (uVar14 + 2 < uVar13) {
          *(undefined8 *)(pauStack_1a0[1] + lVar9 + 8) = 0;
          *(undefined4 *)((long)(pauStack_1a0[1] + lVar9 + 8) + 8) = 0;
        }
      }
    }
    else {
      pauVar7 = pauStack_1a0;
      do {
        *pauVar7 = (undefined1  [16])0x0;
        pauVar8 = pauVar7 + 3;
        pauVar7[1] = (undefined1  [16])0x0;
        pauVar7[2] = (undefined1  [16])0x0;
        pauVar7 = pauVar8;
      } while (pauStack_1a0 + (uVar10 / 0x30) * 3 != pauVar8);
      uVar14 = uVar13 & 0xfffffffffffffffc;
      if (uVar13 != uVar14) goto LAB_00119cd8;
    }
    local_1c8._8_8_ = uVar13;
    if (pauStack_1a0 == (undefined1 (*) [16])0x0) {
      puVar11 = (undefined8 *)__cxa_allocate_exception(0x20);
      *puVar11 = &PTR_FUN_00132da8;
      puVar11[1] = "../src_udic/marisa_u/grimoire/trie/../io/reader.h";
      puVar11[2] = 0x20000001f;
      puVar11[3] = 
      "../src_udic/marisa_u/grimoire/trie/../io/reader.h:31: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
      ;
                    /* WARNING: Subroutine does not return */
      __cxa_throw(puVar11,&PTR_vtable_00132d80,FUN_0010e6a0);
    }
  }
  FUN_00110a70(param_2,pauStack_1a0,uVar13 * 0xc);
  FUN_00110b80(param_2,-local_120 & 7);
  uStack_b8 = local_1c8._8_8_;
  local_d8._8_8_ = pauStack_1a0;
  local_d8._0_8_ = pauStack_1a0;
  local_c8 = pauStack_1a0;
  local_c0 = uVar13;
  FUN_00110a70(param_2,&local_120,8);
  if ((local_120 & 3) == 0) {
    uVar10 = CONCAT44(uStack_11c,local_120) >> 2;
    if (uVar10 == 0) {
      FUN_00110a70(param_2,0,0);
      local_1c8._0_8_ = (void *)0x0;
      _local_158 = (undefined1  [16])0x0;
    }
    else {
      local_1c8._0_8_ =
           operator_new__(CONCAT44(uStack_11c,local_120) & 0xfffffffffffffffc,
                          (nothrow_t *)PTR_nothrow_00132fb8);
      if ((void *)local_1c8._0_8_ == (void *)0x0) {
        puVar11 = (undefined8 *)__cxa_allocate_exception(0x20);
        *puVar11 = &PTR_FUN_00132da8;
        puVar11[1] = "../src_udic/marisa_u/grimoire/trie/../io/reader.h";
        puVar11[2] = 0x20000001f;
        puVar11[3] = 
        "../src_udic/marisa_u/grimoire/trie/../io/reader.h:31: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
        ;
                    /* WARNING: Subroutine does not return */
        __cxa_throw(puVar11,&PTR_vtable_00132d80,FUN_0010e6a0);
      }
      pvStack_150 = (void *)uVar10;
      local_158 = (undefined1  [8])uVar10;
      FUN_00110a70(param_2,local_1c8._0_8_);
    }
    FUN_00110b80(param_2,-local_120 & 7);
    local_98 = (void *)local_1c8._0_8_;
    local_a8 = (void *)local_1c8._0_8_;
    pvStack_a0 = (void *)local_1c8._0_8_;
    local_90 = _local_158;
    FUN_00110a70(param_2,&local_120,8);
    if ((local_120 & 3) == 0) {
      uStack_140 = CONCAT44(uStack_11c,local_120) >> 2;
      if (uStack_140 == 0) {
        FUN_00110a70(param_2,0,0);
        pvStack_150 = (void *)0x0;
        uStack_140 = 0;
      }
      else {
        pvStack_150 = operator_new__(CONCAT44(uStack_11c,local_120) & 0xfffffffffffffffc,
                                     (nothrow_t *)PTR_nothrow_00132fb8);
        if (pvStack_150 == (void *)0x0) {
          puVar11 = (undefined8 *)__cxa_allocate_exception(0x20);
          *puVar11 = &PTR_FUN_00132da8;
          puVar11[1] = "../src_udic/marisa_u/grimoire/trie/../io/reader.h";
          puVar11[2] = 0x20000001f;
          puVar11[3] = 
          "../src_udic/marisa_u/grimoire/trie/../io/reader.h:31: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
          ;
                    /* WARNING: Subroutine does not return */
          __cxa_throw(puVar11,&PTR_vtable_00132d80,FUN_0010e6a0);
        }
        FUN_00110a70(param_2,pvStack_150);
      }
      FUN_00110b80(param_2,-local_120 & 7);
      param_1[10] = pauStack_1a0;
      uStack_160 = (ulong)uVar5;
      *(undefined1 *)(param_1 + 5) = 0;
      param_1[2] = pvStack_190;
      pvVar1 = (void *)param_1[0x14];
      param_1[0xb] = uVar13;
      pvVar2 = (void *)*param_1;
      param_1[0xc] = local_1c8._8_8_;
      pvVar3 = (void *)param_1[8];
      pvVar4 = (void *)param_1[0xe];
      param_1[3] = uVar6;
      param_1[4] = uVar6;
      *(undefined1 *)(param_1 + 0xd) = 0;
      param_1[0x10] = local_1c8._0_8_;
      *(undefined1 *)(param_1 + 0x13) = 0;
      param_1[0x11] = uVar10;
      param_1[0x12] = uVar10;
      param_1[0x16] = pvStack_150;
      *param_1 = pvStack_190;
      param_1[1] = pvStack_190;
      param_1[6] = uVar12;
      param_1[7] = uStack_160;
      param_1[8] = pauStack_1a0;
      param_1[9] = pauStack_1a0;
      param_1[0xe] = local_1c8._0_8_;
      param_1[0xf] = local_1c8._0_8_;
      param_1[0x14] = pvStack_150;
      param_1[0x15] = pvStack_150;
      param_1[0x17] = uStack_140;
      param_1[0x18] = uStack_140;
      *(undefined1 *)(param_1 + 0x19) = 0;
      if (pvVar1 != (void *)0x0) {
        operator_delete__(pvVar1);
      }
      if (pvVar4 != (void *)0x0) {
        operator_delete__(pvVar4);
      }
      if (pvVar3 != (void *)0x0) {
        operator_delete__(pvVar3);
      }
      if (pvVar2 == (void *)0x0) {
        if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
          return;
        }
      }
      else if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
        operator_delete__(pvVar2);
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    FUN_001067a8();
    operator_delete__(&local_120);
  }
  else {
    param_1 = (undefined8 *)FUN_001067a8();
  }
LAB_0011a109:
  FUN_00119540(&local_118);
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume(param_1);
}


//===== FUN_0011a3a0 @ 0011a3a0 size=83 =====

void FUN_0011a3a0(long *param_1)

{
  long lVar1;
  undefined8 *puVar2;
  void *pvVar3;
  
  pvVar3 = (void *)*param_1;
  if (pvVar3 == (void *)0x0) {
    return;
  }
  lVar1 = param_1[9];
  puVar2 = (undefined8 *)param_1[5];
  if (puVar2 < (undefined8 *)(lVar1 + 8U)) {
    do {
      pvVar3 = (void *)*puVar2;
      puVar2 = puVar2 + 1;
      operator_delete(pvVar3);
    } while (puVar2 < (undefined8 *)(lVar1 + 8U));
    pvVar3 = (void *)*param_1;
  }
  operator_delete(pvVar3);
  return;
}


//===== FUN_0011a400 @ 0011a400 size=295 =====

void FUN_0011a400(undefined8 *param_1,ulong param_2)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  void *pvVar6;
  ulong uVar7;
  long *plVar8;
  ulong uVar9;
  
  lVar1 = param_2 / 0x2a + 1;
  uVar7 = param_2 / 0x2a + 3;
  if (uVar7 < 9) {
    uVar7 = 8;
    uVar9 = 0x40;
  }
  else {
    uVar9 = uVar7 * 8;
  }
  param_1[1] = uVar7;
  pvVar6 = operator_new(uVar9);
  *param_1 = pvVar6;
  plVar2 = (long *)((long)pvVar6 + ((ulong)(param_1[1] - lVar1) >> 1) * 8);
  plVar3 = plVar2 + lVar1;
  for (plVar8 = plVar2; plVar8 < plVar3; plVar8 = plVar8 + 1) {
    pvVar6 = operator_new(0x1f8);
    *plVar8 = (long)pvVar6;
  }
  lVar1 = *plVar2;
  lVar4 = *plVar2;
  lVar5 = plVar3[-1];
  param_1[2] = lVar1;
  param_1[3] = lVar1;
  param_1[4] = lVar4 + 0x1f8;
  param_1[5] = plVar2;
  param_1[6] = lVar5 + (param_2 % 0x2a) * 0xc;
  param_1[7] = lVar5;
  param_1[8] = lVar5 + 0x1f8;
  param_1[9] = plVar3 + -1;
  return;
}


//===== FUN_0011a5a0 @ 0011a5a0 size=231 =====

long FUN_0011a5a0(long *param_1,long *param_2,ulong param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  long *plVar6;
  long lVar7;
  ulong uVar8;
  long *plVar9;
  long *plVar10;
  long lVar11;
  long lVar12;
  ulong uVar13;
  long lVar14;
  ulong uVar15;
  
  lVar14 = 1;
  plVar6 = param_1;
joined_r0x0011a5bb:
  do {
    plVar6 = plVar6 + 3;
    if (param_2 <= plVar6) {
      return lVar14;
    }
    uVar3 = *(uint *)(plVar6 + 1);
    uVar13 = (ulong)uVar3;
    plVar9 = plVar6;
    do {
      uVar4 = *(uint *)(plVar9 + -2);
      uVar15 = (ulong)uVar4;
      if (param_3 < uVar15) {
        lVar12 = plVar9[-3];
        lVar11 = *plVar9;
        uVar8 = param_3;
        do {
          if (uVar8 == uVar13) goto LAB_0011a61c;
          bVar1 = *(byte *)(lVar12 + uVar8);
          bVar2 = *(byte *)(lVar11 + uVar8);
          if (bVar2 != bVar1) {
            if (0 < (int)((uint)bVar1 - (uint)bVar2)) goto LAB_0011a61c;
            if ((uint)bVar1 == (uint)bVar2) goto joined_r0x0011a5bb;
            goto LAB_0011a651;
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 != uVar15);
      }
      if (uVar13 == uVar15) goto joined_r0x0011a5bb;
      if (uVar15 <= uVar13) break;
      lVar12 = plVar9[-3];
      lVar11 = *plVar9;
LAB_0011a61c:
      uVar5 = *(undefined4 *)((long)plVar9 + -0xc);
      lVar7 = plVar9[-1];
      plVar9[-3] = lVar11;
      plVar10 = plVar9 + -3;
      *(uint *)(plVar9 + -2) = uVar3;
      *(undefined4 *)((long)plVar9 + -0xc) = *(undefined4 *)((long)plVar9 + 0xc);
      *(undefined4 *)((long)plVar9 + 0xc) = uVar5;
      *(int *)(plVar9 + -1) = (int)plVar9[2];
      *(int *)(plVar9 + 2) = (int)lVar7;
      *plVar9 = lVar12;
      *(uint *)(plVar9 + 1) = uVar4;
      plVar9 = plVar10;
    } while (param_1 < plVar10);
LAB_0011a651:
    lVar14 = lVar14 + 1;
  } while( true );
}


//===== FUN_0011a690 @ 0011a690 size=1292 =====

long FUN_0011a690(long *param_1,long *param_2,ulong param_3)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  long *plVar5;
  long *plVar6;
  long lVar7;
  uint uVar8;
  long *plVar9;
  long *plVar10;
  uint uVar11;
  uint uVar12;
  ulong uVar13;
  long lVar14;
  long *plVar15;
  uint uVar16;
  uint uVar17;
  long *plVar18;
  long *plVar19;
  long *plVar20;
  long lVar21;
  long lVar22;
  long lVar23;
  
  lVar21 = 0;
  lVar22 = (long)param_2 - (long)param_1;
joined_r0x0011a6bb:
  do {
    plVar6 = param_2;
    plVar5 = param_1;
    if (lVar22 < 0xf1) {
      if (0x18 < lVar22) {
        lVar22 = FUN_0011a5a0(plVar5,plVar6,param_3);
        lVar21 = lVar21 + lVar22;
      }
      return lVar21;
    }
    uVar13 = (lVar22 >> 3) * -0x5555555555555555;
    if (param_3 < *(uint *)(plVar5 + 1)) {
      uVar11 = (uint)*(byte *)(*plVar5 + param_3);
    }
    else {
      uVar11 = 0xffffffff;
    }
    plVar9 = plVar6;
    plVar15 = plVar5;
    plVar19 = plVar6;
    plVar20 = plVar5;
    if (param_3 < *(uint *)(plVar5 + ((long)uVar13 >> 1) + (uVar13 & 0xfffffffffffffffe) + 1)) {
      bVar1 = *(byte *)(plVar5[((long)uVar13 >> 1) + (uVar13 & 0xfffffffffffffffe)] + param_3);
      uVar16 = (uint)bVar1;
      if (param_3 < *(uint *)(plVar6 + -2)) {
        bVar2 = *(byte *)(plVar6[-3] + param_3);
        uVar8 = (uint)bVar2;
        uVar12 = (uint)bVar1;
        if ((int)uVar16 <= (int)uVar11) goto LAB_0011aa1e;
        uVar17 = (uint)bVar1;
        if (bVar2 <= uVar16) goto LAB_0011a72f;
      }
      else {
        uVar12 = 0xffffffff;
        uVar8 = 0xffffffff;
        if ((int)uVar16 <= (int)uVar11) goto LAB_0011aa22;
LAB_0011a72f:
        uVar17 = uVar8;
        if ((int)uVar8 <= (int)uVar11) {
          uVar17 = uVar11;
        }
      }
    }
    else {
      if (param_3 < *(uint *)(plVar6 + -2)) {
        uVar8 = (uint)*(byte *)(plVar6[-3] + param_3);
        uVar12 = 0xffffffff;
LAB_0011aa1e:
        uVar16 = uVar12;
        uVar12 = uVar8;
        uVar17 = uVar11;
        if ((int)uVar11 < (int)uVar8) goto LAB_0011a7b4;
      }
      else {
        uVar12 = 0xffffffff;
        uVar16 = 0xffffffff;
      }
LAB_0011aa22:
      uVar17 = uVar16;
      if ((int)uVar16 < (int)uVar12) {
        uVar17 = uVar12;
      }
    }
LAB_0011a7b4:
    for (; plVar15 < plVar19; plVar15 = plVar15 + 3) {
      uVar11 = *(uint *)(plVar15 + 1);
      plVar10 = plVar9;
      if (param_3 < uVar11) {
        uVar12 = (uint)*(byte *)(*plVar15 + param_3);
        plVar18 = plVar19;
        if ((int)(uint)*(byte *)(*plVar15 + param_3) <= (int)uVar17) goto LAB_0011a767;
        while( true ) {
          uVar11 = *(uint *)(plVar18 + -2);
          plVar19 = plVar18 + -3;
          if (param_3 < uVar11) {
            uVar12 = (uint)*(byte *)(*plVar19 + param_3);
          }
          else {
            uVar12 = 0xffffffff;
          }
          plVar9 = plVar10;
          if ((int)uVar12 < (int)uVar17) break;
          if (uVar12 == uVar17) {
            lVar22 = *plVar19;
            plVar9 = plVar10 + -3;
            uVar4 = *(undefined4 *)((long)plVar18 + -0xc);
            lVar14 = plVar18[-1];
            *plVar19 = plVar10[-3];
            *(int *)(plVar18 + -2) = (int)plVar10[-2];
            *(undefined4 *)((long)plVar18 + -0xc) = *(undefined4 *)((long)plVar10 + -0xc);
            *(int *)(plVar18 + -1) = (int)plVar10[-1];
            *plVar9 = lVar22;
            *(uint *)(plVar10 + -2) = uVar11;
            *(undefined4 *)((long)plVar10 + -0xc) = uVar4;
            *(int *)(plVar10 + -1) = (int)lVar14;
          }
          plVar10 = plVar9;
          plVar18 = plVar19;
          if (plVar19 <= plVar15) goto LAB_0011a8c8;
        }
        if (plVar19 <= plVar15) break;
        lVar23 = plVar15[1];
        lVar22 = *plVar19;
        *(uint *)(plVar15 + 1) = uVar11;
        uVar4 = *(undefined4 *)((long)plVar18 + -0xc);
        uVar3 = *(undefined4 *)((long)plVar15 + 0xc);
        lVar14 = *plVar15;
        lVar7 = plVar15[2];
        *plVar15 = lVar22;
        *(undefined4 *)((long)plVar15 + 0xc) = uVar4;
        *(int *)(plVar15 + 2) = (int)plVar18[-1];
        *plVar19 = lVar14;
        *(int *)(plVar18 + -2) = (int)lVar23;
        *(undefined4 *)((long)plVar18 + -0xc) = uVar3;
        *(int *)(plVar18 + -1) = (int)lVar7;
      }
      else {
        uVar12 = 0xffffffff;
LAB_0011a767:
        if (uVar17 == uVar12) {
          lVar22 = *plVar15;
          uVar4 = *(undefined4 *)((long)plVar15 + 0xc);
          lVar14 = plVar15[2];
          *plVar15 = *plVar20;
          *(int *)(plVar15 + 1) = (int)plVar20[1];
          *(undefined4 *)((long)plVar15 + 0xc) = *(undefined4 *)((long)plVar20 + 0xc);
          *(int *)(plVar15 + 2) = (int)plVar20[2];
          *plVar20 = lVar22;
          *(uint *)(plVar20 + 1) = uVar11;
          *(undefined4 *)((long)plVar20 + 0xc) = uVar4;
          *(int *)(plVar20 + 2) = (int)lVar14;
          plVar20 = plVar20 + 3;
        }
      }
      plVar9 = plVar10;
    }
LAB_0011a8c8:
    while (plVar5 < plVar20) {
      lVar22 = plVar20[-3];
      lVar14 = plVar20[-2];
      uVar4 = *(undefined4 *)((long)plVar20 + -0xc);
      plVar20[-3] = plVar15[-3];
      lVar23 = plVar20[-1];
      *(int *)(plVar20 + -2) = (int)plVar15[-2];
      *(undefined4 *)((long)plVar20 + -0xc) = *(undefined4 *)((long)plVar15 + -0xc);
      *(int *)(plVar20 + -1) = (int)plVar15[-1];
      plVar15[-3] = lVar22;
      *(int *)(plVar15 + -2) = (int)lVar14;
      *(undefined4 *)((long)plVar15 + -0xc) = uVar4;
      *(int *)(plVar15 + -1) = (int)lVar23;
      plVar20 = plVar20 + -3;
      plVar15 = plVar15 + -3;
    }
    for (; plVar9 < plVar6; plVar9 = plVar9 + 3) {
      lVar22 = *plVar9;
      lVar14 = plVar9[1];
      uVar4 = *(undefined4 *)((long)plVar9 + 0xc);
      *plVar9 = *plVar19;
      lVar23 = plVar9[2];
      *(int *)(plVar9 + 1) = (int)plVar19[1];
      *(undefined4 *)((long)plVar9 + 0xc) = *(undefined4 *)((long)plVar19 + 0xc);
      *(int *)(plVar9 + 2) = (int)plVar19[2];
      *plVar19 = lVar22;
      *(int *)(plVar19 + 1) = (int)lVar14;
      *(undefined4 *)((long)plVar19 + 0xc) = uVar4;
      *(int *)(plVar19 + 2) = (int)lVar23;
      plVar19 = plVar19 + 3;
    }
    lVar14 = (long)plVar15 - (long)plVar5;
    lVar22 = (long)plVar19 - (long)plVar15;
    lVar23 = (long)plVar6 - (long)plVar19;
    if ((lVar22 < lVar14) || (lVar22 < lVar23)) {
      if (lVar22 == 0x18) {
LAB_0011a9e7:
        lVar21 = lVar21 + 1;
      }
      else if (0x18 < lVar22) {
        if (uVar17 == 0xffffffff) goto LAB_0011a9e7;
        lVar22 = FUN_0011a690(plVar15,plVar19,param_3 + 1);
        lVar21 = lVar21 + lVar22;
      }
      if (lVar14 < lVar23) {
        lVar22 = lVar23;
        param_1 = plVar19;
        param_2 = plVar6;
        if (lVar14 == 0x18) {
          lVar21 = lVar21 + 1;
        }
        else if (0x18 < lVar14) {
          lVar14 = FUN_0011a690(plVar5,plVar15,param_3);
          lVar21 = lVar21 + lVar14;
        }
      }
      else {
        lVar22 = lVar14;
        param_1 = plVar5;
        param_2 = plVar15;
        if (lVar23 == 0x18) {
          lVar21 = lVar21 + 1;
        }
        else if (0x18 < lVar23) {
          lVar14 = FUN_0011a690(plVar19,plVar6,param_3);
          lVar21 = lVar21 + lVar14;
        }
      }
      goto joined_r0x0011a6bb;
    }
    if (lVar14 == 0x18) {
      lVar21 = lVar21 + 1;
      if (lVar23 != 0x18) goto LAB_0011a960;
LAB_0011aac7:
      lVar21 = lVar21 + 1;
    }
    else {
      if (0x18 < lVar14) {
        lVar14 = FUN_0011a690(plVar5,plVar15,param_3);
        lVar21 = lVar21 + lVar14;
      }
      if (lVar23 == 0x18) goto LAB_0011aac7;
LAB_0011a960:
      if (0x18 < lVar23) {
        lVar14 = FUN_0011a690(plVar19,plVar6,param_3);
        lVar21 = lVar21 + lVar14;
      }
    }
    if (lVar22 == 0x18) goto LAB_0011aa8b;
    param_1 = plVar15;
    param_2 = plVar19;
    if (0x18 < lVar22) {
      if (uVar17 == 0xffffffff) {
LAB_0011aa8b:
        return lVar21 + 1;
      }
      param_3 = param_3 + 1;
    }
  } while( true );
}


//===== FUN_0011abc0 @ 0011abc0 size=277 =====

long FUN_0011abc0(long *param_1,long *param_2,ulong param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  long lVar6;
  long *plVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  long *plVar11;
  long *plVar12;
  ulong uVar13;
  long local_60;
  
  local_60 = 1;
  plVar7 = param_1;
joined_r0x0011abee:
  do {
    plVar7 = plVar7 + 3;
    if (param_2 <= plVar7) {
      return local_60;
    }
    uVar3 = *(uint *)(plVar7 + 1);
    uVar13 = (ulong)uVar3;
    plVar11 = plVar7;
    do {
      uVar4 = *(uint *)(plVar11 + -2);
      uVar10 = (ulong)uVar4;
      plVar12 = plVar11 + -3;
      lVar6 = *plVar12;
      if (param_3 < uVar10) {
        if (param_3 != uVar13) {
          lVar8 = -param_3;
          do {
            bVar1 = *(byte *)(lVar6 + lVar8);
            bVar2 = *(byte *)(*plVar11 + lVar8);
            if (bVar2 != bVar1) {
              if ((int)((uint)bVar1 - (uint)bVar2) < 1) {
                if ((uint)bVar1 != (uint)bVar2) goto LAB_0011aca2;
                goto joined_r0x0011abee;
              }
              break;
            }
            if (lVar8 == 1 - uVar10) goto LAB_0011acd0;
            uVar9 = 1 - lVar8;
            lVar8 = lVar8 + -1;
          } while (uVar13 != uVar9);
        }
      }
      else {
LAB_0011acd0:
        if (uVar13 == uVar10) goto joined_r0x0011abee;
        if (uVar10 < uVar13) break;
      }
      uVar5 = *(undefined4 *)((long)plVar11 + -0xc);
      *plVar12 = *plVar11;
      lVar8 = plVar11[-1];
      *(uint *)(plVar11 + -2) = uVar3;
      *(undefined4 *)((long)plVar11 + -0xc) = *(undefined4 *)((long)plVar11 + 0xc);
      *(int *)(plVar11 + -1) = (int)plVar11[2];
      *plVar11 = lVar6;
      *(uint *)(plVar11 + 1) = uVar4;
      *(undefined4 *)((long)plVar11 + 0xc) = uVar5;
      *(int *)(plVar11 + 2) = (int)lVar8;
      plVar11 = plVar12;
    } while (param_1 < plVar12);
LAB_0011aca2:
    local_60 = local_60 + 1;
  } while( true );
}


//===== FUN_0011ace0 @ 0011ace0 size=1350 =====

long FUN_0011ace0(long *param_1,long *param_2,ulong param_3)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  long *plVar4;
  long *plVar5;
  uint uVar6;
  long *plVar7;
  long *plVar8;
  uint uVar9;
  ulong uVar10;
  long lVar11;
  long *plVar12;
  uint uVar13;
  uint uVar14;
  long *plVar15;
  long *plVar16;
  long *plVar17;
  long *plVar18;
  long lVar19;
  uint uVar20;
  long lVar21;
  long lVar22;
  
  lVar19 = 0;
  lVar21 = (long)param_2 - (long)param_1;
joined_r0x0011ad0b:
  do {
    plVar5 = param_2;
    plVar4 = param_1;
    if (lVar21 < 0xf1) {
      if (0x18 < lVar21) {
        lVar21 = FUN_0011abc0(plVar4,plVar5,param_3);
        lVar19 = lVar19 + lVar21;
      }
      return lVar19;
    }
    uVar10 = (lVar21 >> 3) * -0x5555555555555555;
    if (param_3 < *(uint *)(plVar4 + 1)) {
      uVar9 = (uint)*(byte *)(*plVar4 - param_3);
    }
    else {
      uVar9 = 0xffffffff;
    }
    if (param_3 < *(uint *)(plVar4 + ((long)uVar10 >> 1) + (uVar10 & 0xfffffffffffffffe) + 1)) {
      bVar1 = *(byte *)(plVar4[((long)uVar10 >> 1) + (uVar10 & 0xfffffffffffffffe)] + -param_3);
      uVar13 = (uint)bVar1;
      if (param_3 < *(uint *)(plVar5 + -2)) {
        bVar2 = *(byte *)(plVar5[-3] + -param_3);
        uVar6 = (uint)bVar2;
        uVar20 = (uint)bVar1;
        if ((int)uVar13 <= (int)uVar9) goto LAB_0011b0b0;
        uVar14 = (uint)bVar1;
        if (bVar2 <= uVar13) goto LAB_0011ad84;
      }
      else {
        uVar20 = 0xffffffff;
        uVar6 = 0xffffffff;
        if ((int)uVar13 <= (int)uVar9) goto LAB_0011b0b4;
LAB_0011ad84:
        uVar14 = uVar6;
        if ((int)uVar6 <= (int)uVar9) {
          uVar14 = uVar9;
        }
      }
    }
    else {
      if (param_3 < *(uint *)(plVar5 + -2)) {
        uVar6 = (uint)*(byte *)(plVar5[-3] - param_3);
        uVar20 = 0xffffffff;
LAB_0011b0b0:
        uVar13 = uVar20;
        uVar14 = uVar9;
        uVar20 = uVar6;
        if ((int)uVar9 < (int)uVar6) goto LAB_0011ad8b;
      }
      else {
        uVar20 = 0xffffffff;
        uVar13 = 0xffffffff;
      }
LAB_0011b0b4:
      uVar14 = uVar13;
      if ((int)uVar13 < (int)uVar20) {
        uVar14 = uVar20;
      }
    }
LAB_0011ad8b:
    plVar8 = plVar5;
    plVar16 = plVar5;
    plVar18 = plVar4;
    for (plVar12 = plVar4; plVar7 = plVar8, plVar12 < plVar16; plVar12 = plVar12 + 3) {
      uVar9 = *(uint *)(plVar12 + 1);
      plVar17 = plVar18;
      if (param_3 < uVar9) {
        bVar1 = *(byte *)(*plVar12 + -param_3);
        uVar20 = (uint)bVar1;
        plVar15 = plVar16;
        if ((int)(uint)bVar1 <= (int)uVar14) goto LAB_0011b010;
        while( true ) {
          uVar9 = *(uint *)(plVar15 + -2);
          plVar16 = plVar15 + -3;
          if (param_3 < uVar9) {
            uVar20 = (uint)*(byte *)(*plVar16 + -param_3);
          }
          else {
            uVar20 = 0xffffffff;
          }
          plVar7 = plVar8;
          if ((int)uVar20 < (int)uVar14) break;
          if (uVar20 == uVar14) {
            lVar21 = *plVar16;
            plVar7 = plVar8 + -3;
            uVar3 = *(undefined4 *)((long)plVar15 + -0xc);
            lVar11 = plVar15[-1];
            *plVar16 = plVar8[-3];
            *(int *)(plVar15 + -2) = (int)plVar8[-2];
            *(undefined4 *)((long)plVar15 + -0xc) = *(undefined4 *)((long)plVar8 + -0xc);
            *(int *)(plVar15 + -1) = (int)plVar8[-1];
            *plVar7 = lVar21;
            *(uint *)(plVar8 + -2) = uVar9;
            *(undefined4 *)((long)plVar8 + -0xc) = uVar3;
            *(int *)(plVar8 + -1) = (int)lVar11;
          }
          plVar8 = plVar7;
          plVar15 = plVar16;
          if (plVar16 <= plVar12) goto LAB_0011aeee;
        }
        if (plVar16 <= plVar12) break;
        lVar21 = *plVar12;
        lVar11 = plVar12[1];
        uVar3 = *(undefined4 *)((long)plVar12 + 0xc);
        *plVar12 = *plVar16;
        lVar22 = plVar12[2];
        *(uint *)(plVar12 + 1) = uVar9;
        *(undefined4 *)((long)plVar12 + 0xc) = *(undefined4 *)((long)plVar15 + -0xc);
        *(int *)(plVar12 + 2) = (int)plVar15[-1];
        *plVar16 = lVar21;
        *(int *)(plVar15 + -2) = (int)lVar11;
        *(undefined4 *)((long)plVar15 + -0xc) = uVar3;
        *(int *)(plVar15 + -1) = (int)lVar22;
      }
      else {
        uVar20 = 0xffffffff;
LAB_0011b010:
        if (uVar14 == uVar20) {
          lVar21 = *plVar12;
          plVar17 = plVar18 + 3;
          uVar3 = *(undefined4 *)((long)plVar12 + 0xc);
          lVar11 = plVar12[2];
          *plVar12 = *plVar18;
          *(int *)(plVar12 + 1) = (int)plVar18[1];
          *(undefined4 *)((long)plVar12 + 0xc) = *(undefined4 *)((long)plVar18 + 0xc);
          *(int *)(plVar12 + 2) = (int)plVar18[2];
          *plVar18 = lVar21;
          *(uint *)(plVar18 + 1) = uVar9;
          *(undefined4 *)((long)plVar18 + 0xc) = uVar3;
          *(int *)(plVar18 + 2) = (int)lVar11;
        }
      }
      plVar18 = plVar17;
    }
LAB_0011aeee:
    while (plVar4 < plVar18) {
      lVar11 = plVar18[-2];
      plVar8 = plVar18 + -3;
      lVar21 = *plVar8;
      uVar3 = *(undefined4 *)((long)plVar18 + -0xc);
      *plVar8 = plVar12[-3];
      lVar22 = plVar18[-1];
      *(int *)(plVar18 + -2) = (int)plVar12[-2];
      *(undefined4 *)((long)plVar18 + -0xc) = *(undefined4 *)((long)plVar12 + -0xc);
      *(int *)(plVar18 + -1) = (int)plVar12[-1];
      plVar12[-3] = lVar21;
      *(int *)(plVar12 + -2) = (int)lVar11;
      *(undefined4 *)((long)plVar12 + -0xc) = uVar3;
      *(int *)(plVar12 + -1) = (int)lVar22;
      plVar18 = plVar8;
      plVar12 = plVar12 + -3;
    }
    for (; plVar7 < plVar5; plVar7 = plVar7 + 3) {
      lVar21 = *plVar7;
      lVar11 = plVar7[1];
      uVar3 = *(undefined4 *)((long)plVar7 + 0xc);
      *plVar7 = *plVar16;
      lVar22 = plVar7[2];
      *(int *)(plVar7 + 1) = (int)plVar16[1];
      *(undefined4 *)((long)plVar7 + 0xc) = *(undefined4 *)((long)plVar16 + 0xc);
      *(int *)(plVar7 + 2) = (int)plVar16[2];
      *plVar16 = lVar21;
      *(int *)(plVar16 + 1) = (int)lVar11;
      *(undefined4 *)((long)plVar16 + 0xc) = uVar3;
      *(int *)(plVar16 + 2) = (int)lVar22;
      plVar16 = plVar16 + 3;
    }
    lVar11 = (long)plVar12 - (long)plVar4;
    lVar21 = (long)plVar16 - (long)plVar12;
    lVar22 = (long)plVar5 - (long)plVar16;
    if ((lVar21 < lVar11) || (lVar21 < lVar22)) {
      if (lVar21 == 0x18) {
LAB_0011b078:
        lVar19 = lVar19 + 1;
      }
      else if (0x18 < lVar21) {
        if (uVar14 == 0xffffffff) goto LAB_0011b078;
        lVar21 = FUN_0011ace0(plVar12,plVar16,param_3 + 1);
        lVar19 = lVar19 + lVar21;
      }
      if (lVar11 < lVar22) {
        lVar21 = lVar22;
        param_1 = plVar16;
        param_2 = plVar5;
        if (lVar11 == 0x18) {
          lVar19 = lVar19 + 1;
        }
        else if (0x18 < lVar11) {
          lVar11 = FUN_0011ace0(plVar4,plVar12,param_3);
          lVar19 = lVar19 + lVar11;
        }
      }
      else {
        lVar21 = lVar11;
        param_1 = plVar4;
        param_2 = plVar12;
        if (lVar22 == 0x18) {
          lVar19 = lVar19 + 1;
        }
        else if (0x18 < lVar22) {
          lVar11 = FUN_0011ace0(plVar16,plVar5,param_3);
          lVar19 = lVar19 + lVar11;
        }
      }
      goto joined_r0x0011ad0b;
    }
    if (lVar11 == 0x18) {
      lVar19 = lVar19 + 1;
      if (lVar22 != 0x18) goto LAB_0011af88;
LAB_0011b14e:
      lVar19 = lVar19 + 1;
    }
    else {
      if (0x18 < lVar11) {
        lVar11 = FUN_0011ace0(plVar4,plVar12,param_3);
        lVar19 = lVar19 + lVar11;
      }
      if (lVar22 == 0x18) goto LAB_0011b14e;
LAB_0011af88:
      if (0x18 < lVar22) {
        lVar11 = FUN_0011ace0(plVar16,plVar5,param_3);
        lVar19 = lVar19 + lVar11;
      }
    }
    if (lVar21 == 0x18) goto LAB_0011b11c;
    param_1 = plVar12;
    param_2 = plVar16;
    if (0x18 < lVar21) {
      if (uVar14 == 0xffffffff) {
LAB_0011b11c:
        return lVar19 + 1;
      }
      param_3 = param_3 + 1;
    }
  } while( true );
}


//===== FUN_0011b240 @ 0011b240 size=259 =====

void * FUN_0011b240(void *param_1,void *param_2,void *param_3,long param_4,long param_5,
                   void *param_6,long param_7)

{
  size_t sVar1;
  void *pvVar2;
  
  if ((param_5 < param_4) && (param_5 <= param_7)) {
    pvVar2 = param_1;
    if (param_5 != 0) {
      sVar1 = (long)param_3 - (long)param_2;
      if (param_2 != param_3) {
        memmove(param_6,param_2,sVar1);
      }
      if (param_1 != param_2) {
        memmove((void *)((long)param_3 - ((long)param_2 - (long)param_1)),param_1,
                (long)param_2 - (long)param_1);
      }
      if (sVar1 != 0) {
        memmove(param_1,param_6,sVar1);
      }
      pvVar2 = (void *)((long)param_1 + sVar1);
    }
  }
  else {
    if (param_7 < param_4) {
      pvVar2 = (void *)FUN_00111190(param_1,param_2,param_3);
      return pvVar2;
    }
    pvVar2 = param_3;
    if (param_4 != 0) {
      sVar1 = (long)param_2 - (long)param_1;
      if (param_1 != param_2) {
        memmove(param_6,param_1,sVar1);
      }
      if (param_2 != param_3) {
        memmove(param_1,param_2,(long)param_3 - (long)param_2);
      }
      pvVar2 = (void *)((long)param_3 - sVar1);
      if (sVar1 != 0) {
        pvVar2 = memmove(pvVar2,param_6,sVar1);
      }
    }
  }
  return pvVar2;
}


//===== FUN_0011b350 @ 0011b350 size=408 =====

void FUN_0011b350(long *param_1,ulong param_2,char param_3)

{
  ulong uVar1;
  long lVar2;
  long *plVar3;
  ulong uVar4;
  void *pvVar5;
  void *pvVar6;
  size_t __n;
  long lVar7;
  long *plVar8;
  long lVar9;
  long *__src;
  
  __src = (long *)param_1[5];
  uVar1 = param_1[1];
  lVar9 = param_1[9] - (long)__src;
  lVar7 = param_2 + 1 + (lVar9 >> 3);
  if ((ulong)(lVar7 * 2) < uVar1) {
    lVar7 = (uVar1 - lVar7 >> 1) * 8;
    if (param_3 != '\0') {
      lVar7 = lVar7 + param_2 * 8;
    }
    plVar3 = (long *)(param_1[9] + 8);
    plVar8 = (long *)(lVar7 + *param_1);
    __n = (long)plVar3 - (long)__src;
    if (plVar8 < __src) {
      if (__src != plVar3) {
        memmove(plVar8,__src,__n);
      }
    }
    else if (__src != plVar3) {
      memmove((void *)(((lVar9 + 8) - __n) + (long)plVar8),__src,__n);
    }
  }
  else {
    uVar4 = param_2;
    if (param_2 <= uVar1) {
      uVar4 = uVar1;
    }
    uVar4 = uVar1 + 2 + uVar4;
    if (uVar4 >> 0x3c != 0) {
      if (uVar4 >> 0x3d != 0) {
        std::__throw_bad_array_new_length();
      }
      std::__throw_bad_alloc();
      lVar7 = param_1[9];
      if ((param_1[4] - param_1[2] >> 2) * -0x5555555555555555 +
          (param_1[6] - param_1[7] >> 2) * -0x5555555555555555 +
          ((lVar7 - param_1[5] >> 3) + -1 + (ulong)(lVar7 == 0)) * 0x2a != 0xaaaaaaaaaaaaaaa) {
        if ((ulong)(param_1[1] - (lVar7 - *param_1 >> 3)) < 2) {
          FUN_0011b350();
          lVar7 = param_1[9];
        }
        pvVar6 = operator_new(0x1f8);
        lVar9 = *__src;
        *(void **)(lVar7 + 8) = pvVar6;
        plVar8 = (long *)param_1[6];
        *plVar8 = lVar9;
        *(int *)(plVar8 + 1) = (int)__src[1];
        lVar7 = *(long *)(param_1[9] + 8);
        param_1[6] = lVar7;
        param_1[7] = lVar7;
        param_1[8] = lVar7 + 0x1f8;
        param_1[9] = param_1[9] + 8;
        return;
      }
                    /* WARNING: Subroutine does not return */
      std::__throw_length_error("cannot create std::deque larger than max_size()");
    }
    pvVar5 = operator_new(uVar4 * 8);
    pvVar6 = (void *)param_1[5];
    lVar7 = (uVar4 - lVar7 >> 1) * 8;
    if (param_3 != '\0') {
      lVar7 = lVar7 + param_2 * 8;
    }
    plVar8 = (long *)(lVar7 + (long)pvVar5);
    if ((void *)(param_1[9] + 8) != pvVar6) {
      memmove(plVar8,pvVar6,(param_1[9] + 8) - (long)pvVar6);
    }
    operator_delete((void *)*param_1);
    param_1[1] = uVar4;
    *param_1 = (long)pvVar5;
  }
  lVar2 = *plVar8;
  lVar7 = *plVar8;
  param_1[5] = (long)plVar8;
  param_1[9] = (long)plVar8 + lVar9;
  param_1[3] = lVar7;
  param_1[4] = lVar2 + 0x1f8;
  lVar7 = *(long *)((long)plVar8 + lVar9);
  param_1[7] = lVar7;
  param_1[8] = lVar7 + 0x1f8;
  return;
}


//===== FUN_0011b500 @ 0011b500 size=252 =====

void FUN_0011b500(long *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  void *pvVar3;
  long lVar4;
  
  lVar4 = param_1[9];
  if ((param_1[4] - param_1[2] >> 2) * -0x5555555555555555 +
      (param_1[6] - param_1[7] >> 2) * -0x5555555555555555 +
      ((lVar4 - param_1[5] >> 3) + -1 + (ulong)(lVar4 == 0)) * 0x2a != 0xaaaaaaaaaaaaaaa) {
    if ((ulong)(param_1[1] - (lVar4 - *param_1 >> 3)) < 2) {
      FUN_0011b350(param_1,1,0);
      lVar4 = param_1[9];
    }
    pvVar3 = operator_new(0x1f8);
    uVar1 = *param_2;
    *(void **)(lVar4 + 8) = pvVar3;
    puVar2 = (undefined8 *)param_1[6];
    *puVar2 = uVar1;
    *(undefined4 *)(puVar2 + 1) = *(undefined4 *)(param_2 + 1);
    lVar4 = *(long *)(param_1[9] + 8);
    param_1[6] = lVar4;
    param_1[7] = lVar4;
    param_1[8] = lVar4 + 0x1f8;
    param_1[9] = param_1[9] + 8;
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_length_error("cannot create std::deque larger than max_size()");
}


//===== FUN_0011b600 @ 0011b600 size=283 =====

void FUN_0011b600(long *param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  void *pvVar3;
  long lVar4;
  
  puVar1 = (undefined8 *)param_1[6];
  if (puVar1 != (undefined8 *)(param_1[8] + -0xc)) {
    *puVar1 = *param_2;
    *(undefined4 *)(puVar1 + 1) = *(undefined4 *)(param_2 + 1);
    param_1[6] = (long)puVar1 + 0xc;
    return;
  }
  lVar4 = param_1[9];
  if ((param_1[4] - param_1[2] >> 2) * -0x5555555555555555 +
      ((long)puVar1 - param_1[7] >> 2) * -0x5555555555555555 +
      ((lVar4 - param_1[5] >> 3) + -1 + (ulong)(lVar4 == 0)) * 0x2a != 0xaaaaaaaaaaaaaaa) {
    if ((ulong)(param_1[1] - (lVar4 - *param_1 >> 3)) < 2) {
      FUN_0011b350(param_1,1,0);
      lVar4 = param_1[9];
    }
    pvVar3 = operator_new(0x1f8);
    uVar2 = *param_2;
    *(void **)(lVar4 + 8) = pvVar3;
    puVar1 = (undefined8 *)param_1[6];
    *puVar1 = uVar2;
    *(undefined4 *)(puVar1 + 1) = *(undefined4 *)(param_2 + 1);
    lVar4 = *(long *)(param_1[9] + 8);
    param_1[9] = param_1[9] + 8;
    param_1[6] = lVar4;
    param_1[7] = lVar4;
    param_1[8] = lVar4 + 0x1f8;
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_length_error("cannot create std::deque larger than max_size()");
}


//===== FUN_0011b730 @ 0011b730 size=9177 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0011b730(undefined1 (*param_1) [16],undefined8 *param_2,undefined8 *param_3,long param_4,
                 long param_5)

{
  ulong *puVar1;
  long *plVar2;
  char *pcVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  void *pvVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined1 auVar13 [16];
  undefined *puVar14;
  undefined1 uVar15;
  long lVar16;
  undefined8 uVar17;
  void *pvVar18;
  ulong uVar19;
  ulong uVar20;
  long lVar21;
  undefined1 (*pauVar22) [16];
  undefined1 (*pauVar23) [16];
  undefined8 *puVar24;
  undefined8 *puVar25;
  undefined8 *puVar26;
  undefined4 *puVar27;
  undefined1 (*pauVar28) [16];
  undefined1 (*pauVar29) [16];
  ulong uVar30;
  long *plVar31;
  ulong uVar32;
  undefined8 *puVar33;
  uint *puVar34;
  ulong uVar35;
  ulong uVar36;
  ulong uVar37;
  ulong uVar38;
  ulong uVar39;
  ulong uVar40;
  long in_FS_OFFSET;
  long lVar41;
  long lVar48;
  undefined1 auVar42 [16];
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  undefined1 auVar45 [16];
  undefined1 auVar46 [16];
  undefined1 auVar47 [16];
  undefined4 uVar49;
  float fVar50;
  ulong local_218;
  ulong local_208;
  undefined8 *local_1f8;
  ulong local_1f0;
  void *local_168;
  undefined8 local_160;
  uint *local_158;
  uint *puStack_150;
  uint *local_148;
  undefined8 *puStack_140;
  undefined1 local_138 [16];
  undefined1 local_128 [16];
  undefined1 local_118 [16];
  undefined8 local_108;
  undefined1 local_100 [16];
  undefined8 local_f0;
  undefined1 local_e8 [16];
  undefined1 local_d8 [16];
  undefined8 local_c8;
  undefined1 local_c0 [16];
  undefined8 local_b0;
  undefined1 local_a8 [16];
  undefined8 local_98;
  undefined1 local_90 [16];
  undefined8 local_80;
  undefined1 local_78 [16];
  undefined8 local_68;
  undefined1 local_60 [16];
  undefined8 local_50;
  long local_40;
  
  lVar41 = param_2[1];
  lVar48 = param_2[3];
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar16 = 0;
  lVar21 = lVar41;
  if (lVar48 != 0) {
    puVar27 = (undefined4 *)(lVar41 + 0x10);
    do {
      *puVar27 = (int)lVar16;
      lVar16 = lVar16 + 1;
      puVar27 = puVar27 + 6;
    } while (lVar16 != lVar48);
    lVar21 = lVar41 + lVar16 * 0x18;
  }
  uVar17 = FUN_0011a690(lVar41,lVar21,0);
  FUN_00113860(param_1,param_4,param_5,uVar17);
  uVar37 = *(ulong *)param_1[3];
  if (uVar37 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_00106868();
  }
  uVar19 = *(ulong *)(param_1[1] + 8);
  if (uVar37 == uVar19 << 6) {
    uVar38 = *(ulong *)param_1[2];
    uVar37 = uVar19 + 1;
    if (uVar38 < uVar37) {
      if (uVar37 >> 1 < uVar38) {
        uVar19 = 0xfffffffffffffff8;
        uVar20 = 0x1fffffffffffffff;
        if (uVar38 >> 0x3c == 0) {
          uVar20 = uVar38 * 2;
          uVar19 = uVar38 << 4;
        }
      }
      else {
        uVar19 = uVar37 * 8;
        uVar20 = uVar37;
      }
      pvVar18 = operator_new__(uVar19,(nothrow_t *)PTR_nothrow_00132fb8);
      uVar19 = *(ulong *)(param_1[1] + 8);
      if (uVar19 != 0) {
        lVar41 = *(long *)(*param_1 + 8);
        if ((uVar19 - 1 < 3) || (pvVar18 == (void *)(lVar41 + 8))) {
          uVar38 = 0;
          do {
            *(undefined8 *)((long)pvVar18 + uVar38 * 8) = *(undefined8 *)(lVar41 + uVar38 * 8);
            uVar38 = uVar38 + 1;
          } while (uVar19 != uVar38);
        }
        else {
          lVar48 = 0;
          do {
            *(undefined1 (*) [16])((long)pvVar18 + lVar48) = *(undefined1 (*) [16])(lVar41 + lVar48)
            ;
            lVar48 = lVar48 + 0x10;
          } while ((uVar19 >> 1) * 0x10 != lVar48);
          if ((uVar19 & 1) != 0) {
            *(undefined8 *)((long)pvVar18 + (uVar19 & 0xfffffffffffffffe) * 8) =
                 *(undefined8 *)(lVar41 + (uVar19 & 0xfffffffffffffffe) * 8);
          }
        }
      }
      pvVar8 = *(void **)*param_1;
      *(void **)param_1[1] = pvVar18;
      *(ulong *)param_1[2] = uVar20;
      *(void **)*param_1 = pvVar18;
      *(void **)(*param_1 + 8) = pvVar18;
      if (pvVar8 != (void *)0x0) {
        operator_delete__(pvVar8);
        uVar19 = *(ulong *)(param_1[1] + 8);
        goto LAB_0011d360;
      }
    }
    else {
LAB_0011d360:
      pvVar18 = *(void **)(*param_1 + 8);
    }
    if (uVar19 < uVar37) {
      memset((void *)((long)pvVar18 + uVar19 * 8),0,(uVar37 - uVar19) * 8);
    }
    *(ulong *)(param_1[1] + 8) = uVar37;
    uVar37 = *(ulong *)param_1[3];
  }
  else {
    pvVar18 = *(void **)(*param_1 + 8);
  }
  puVar1 = (ulong *)((long)pvVar18 + (uVar37 >> 6) * 8);
  *puVar1 = *puVar1 | 1L << ((byte)uVar37 & 0x3f);
  lVar41 = *(long *)param_1[3] + _DAT_0012a660;
  lVar48 = *(long *)(param_1[3] + 8) + _UNK_0012a668;
  *(long *)param_1[3] = lVar41;
  *(long *)(param_1[3] + 8) = lVar48;
  if (lVar41 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_00106868();
  }
  uVar37 = *(ulong *)(param_1[1] + 8);
  if (uVar37 << 6 == lVar41) {
    uVar38 = *(ulong *)param_1[2];
    uVar19 = uVar37 + 1;
    if (uVar38 < uVar19) {
      if (uVar19 >> 1 < uVar38) {
        uVar37 = 0xfffffffffffffff8;
        uVar20 = 0x1fffffffffffffff;
        if (uVar38 >> 0x3c == 0) {
          uVar20 = uVar38 * 2;
          uVar37 = uVar38 << 4;
        }
      }
      else {
        uVar37 = uVar19 * 8;
        uVar20 = uVar19;
      }
      pvVar18 = operator_new__(uVar37,(nothrow_t *)PTR_nothrow_00132fb8);
      uVar37 = *(ulong *)(param_1[1] + 8);
      if (uVar37 != 0) {
        lVar41 = *(long *)(*param_1 + 8);
        if ((pvVar18 == (void *)(lVar41 + 8)) || (uVar37 - 1 < 3)) {
          uVar38 = 0;
          do {
            *(undefined8 *)((long)pvVar18 + uVar38 * 8) = *(undefined8 *)(lVar41 + uVar38 * 8);
            uVar38 = uVar38 + 1;
          } while (uVar37 != uVar38);
        }
        else {
          lVar48 = 0;
          do {
            puVar27 = (undefined4 *)(lVar41 + lVar48);
            uVar49 = puVar27[1];
            uVar11 = puVar27[2];
            uVar12 = puVar27[3];
            puVar4 = (undefined4 *)((long)pvVar18 + lVar48);
            *puVar4 = *puVar27;
            puVar4[1] = uVar49;
            puVar4[2] = uVar11;
            puVar4[3] = uVar12;
            lVar48 = lVar48 + 0x10;
          } while ((uVar37 >> 1) * 0x10 != lVar48);
          if ((uVar37 & 1) != 0) {
            *(undefined8 *)((long)pvVar18 + (uVar37 & 0xfffffffffffffffe) * 8) =
                 *(undefined8 *)(lVar41 + (uVar37 & 0xfffffffffffffffe) * 8);
          }
        }
      }
      pvVar8 = *(void **)*param_1;
      *(void **)param_1[1] = pvVar18;
      *(ulong *)param_1[2] = uVar20;
      *(void **)*param_1 = pvVar18;
      *(void **)(*param_1 + 8) = pvVar18;
      if (pvVar8 != (void *)0x0) {
        operator_delete__(pvVar8);
        uVar37 = *(ulong *)(param_1[1] + 8);
      }
    }
    if (uVar37 < uVar19) {
      memset((void *)(*(long *)(*param_1 + 8) + uVar37 * 8),0,(uVar19 - uVar37) * 8);
    }
    *(ulong *)(param_1[1] + 8) = uVar19;
    lVar41 = *(long *)param_1[3];
  }
  uVar19 = *(ulong *)param_1[0x29];
  *(long *)param_1[3] = lVar41 + 1;
  uVar38 = *(ulong *)(param_1[0x28] + 8);
  uVar37 = uVar38 + 1;
  if (uVar19 < uVar37) {
    if ((uVar37 >> 1 < uVar19) && (uVar37 = uVar19 * 2, (long)uVar19 < 0)) {
      uVar37 = 0xffffffffffffffff;
    }
    pvVar18 = operator_new__(uVar37,(nothrow_t *)PTR_nothrow_00132fb8);
    uVar38 = *(ulong *)(param_1[0x28] + 8);
    if (uVar38 != 0) {
      lVar41 = *(long *)(param_1[0x27] + 8);
      if (((ulong)((long)pvVar18 - (lVar41 + 1)) < 0xf) || (uVar38 - 1 < 7)) {
        uVar19 = 0;
        do {
          *(undefined1 *)((long)pvVar18 + uVar19) = *(undefined1 *)(lVar41 + uVar19);
          uVar19 = uVar19 + 1;
        } while (uVar19 != uVar38);
      }
      else if (uVar38 - 1 < 0xf) {
        uVar20 = 0;
        uVar19 = uVar38;
LAB_0011b906:
        *(undefined8 *)((long)pvVar18 + uVar20) = *(undefined8 *)(lVar41 + uVar20);
        uVar20 = uVar20 + (uVar19 & 0xfffffffffffffff8);
        if ((uVar19 & 0xfffffffffffffff8) != uVar19) {
LAB_0011b91d:
          *(undefined1 *)((long)pvVar18 + uVar20) = *(undefined1 *)(lVar41 + uVar20);
          if ((((uVar20 + 1 < uVar38) &&
               (*(undefined1 *)((long)pvVar18 + uVar20 + 1) = *(undefined1 *)(lVar41 + 1 + uVar20),
               uVar20 + 2 < uVar38)) &&
              (*(undefined1 *)((long)pvVar18 + uVar20 + 2) = *(undefined1 *)(lVar41 + 2 + uVar20),
              uVar20 + 3 < uVar38)) &&
             (((*(undefined1 *)((long)pvVar18 + uVar20 + 3) = *(undefined1 *)(lVar41 + 3 + uVar20),
               uVar20 + 4 < uVar38 &&
               (*(undefined1 *)((long)pvVar18 + uVar20 + 4) = *(undefined1 *)(lVar41 + 4 + uVar20),
               uVar20 + 5 < uVar38)) &&
              (*(undefined1 *)((long)pvVar18 + uVar20 + 5) = *(undefined1 *)(lVar41 + 5 + uVar20),
              uVar20 + 6 < uVar38)))) {
            *(undefined1 *)((long)pvVar18 + uVar20 + 6) = *(undefined1 *)(lVar41 + 6 + uVar20);
          }
        }
      }
      else {
        uVar19 = 0;
        do {
          *(undefined1 (*) [16])((long)pvVar18 + uVar19) = *(undefined1 (*) [16])(lVar41 + uVar19);
          uVar19 = uVar19 + 0x10;
        } while ((uVar38 & 0xfffffffffffffff0) != uVar19);
        uVar20 = uVar38 & 0xfffffffffffffff0;
        if ((uVar38 & 0xf) != 0) {
          uVar19 = uVar38 - uVar20;
          if (6 < (uVar38 - uVar20) - 1) goto LAB_0011b906;
          goto LAB_0011b91d;
        }
      }
    }
    pvVar8 = *(void **)param_1[0x27];
    *(void **)param_1[0x28] = pvVar18;
    *(ulong *)param_1[0x29] = uVar37;
    *(void **)param_1[0x27] = pvVar18;
    *(void **)(param_1[0x27] + 8) = pvVar18;
    if (pvVar8 != (void *)0x0) {
      operator_delete__(pvVar8);
      pvVar18 = *(void **)(param_1[0x27] + 8);
      uVar38 = *(ulong *)(param_1[0x28] + 8);
    }
  }
  else {
    pvVar18 = *(void **)(param_1[0x27] + 8);
  }
  *(undefined1 *)((long)pvVar18 + uVar38) = 0;
  lVar41 = *(long *)param_1[0x1d];
  *(long *)(param_1[0x28] + 8) = *(long *)(param_1[0x28] + 8) + 1;
  if (lVar41 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_00106868();
  }
  uVar37 = *(ulong *)(param_1[0x1b] + 8);
  if (lVar41 == uVar37 << 6) {
    uVar38 = *(ulong *)param_1[0x1c];
    uVar19 = uVar37 + 1;
    if (uVar38 < uVar19) {
      if (uVar19 >> 1 < uVar38) {
        uVar37 = 0xfffffffffffffff8;
        uVar20 = 0x1fffffffffffffff;
        if (uVar38 >> 0x3c == 0) {
          uVar20 = uVar38 * 2;
          uVar37 = uVar38 << 4;
        }
      }
      else {
        uVar37 = uVar19 * 8;
        uVar20 = uVar19;
      }
      pvVar18 = operator_new__(uVar37,(nothrow_t *)PTR_nothrow_00132fb8);
      uVar37 = *(ulong *)(param_1[0x1b] + 8);
      if (uVar37 != 0) {
        lVar41 = *(long *)(param_1[0x1a] + 8);
        if ((pvVar18 == (void *)(lVar41 + 8)) || (uVar37 - 1 < 3)) {
          uVar38 = 0;
          do {
            *(undefined8 *)((long)pvVar18 + uVar38 * 8) = *(undefined8 *)(lVar41 + uVar38 * 8);
            uVar38 = uVar38 + 1;
          } while (uVar38 != uVar37);
        }
        else {
          lVar48 = 0;
          do {
            puVar27 = (undefined4 *)(lVar41 + lVar48);
            uVar49 = puVar27[1];
            uVar11 = puVar27[2];
            uVar12 = puVar27[3];
            puVar4 = (undefined4 *)((long)pvVar18 + lVar48);
            *puVar4 = *puVar27;
            puVar4[1] = uVar49;
            puVar4[2] = uVar11;
            puVar4[3] = uVar12;
            lVar48 = lVar48 + 0x10;
          } while ((uVar37 >> 1) * 0x10 != lVar48);
          if ((uVar37 & 1) != 0) {
            *(undefined8 *)((long)pvVar18 + (uVar37 & 0xfffffffffffffffe) * 8) =
                 *(undefined8 *)(lVar41 + (uVar37 & 0xfffffffffffffffe) * 8);
          }
        }
      }
      pvVar8 = *(void **)param_1[0x1a];
      *(void **)param_1[0x1b] = pvVar18;
      *(ulong *)param_1[0x1c] = uVar20;
      *(void **)param_1[0x1a] = pvVar18;
      *(void **)(param_1[0x1a] + 8) = pvVar18;
      if (pvVar8 != (void *)0x0) {
        operator_delete__(pvVar8);
        uVar37 = *(ulong *)(param_1[0x1b] + 8);
      }
    }
    if (uVar37 < uVar19) {
      memset((void *)(*(long *)(param_1[0x1a] + 8) + uVar37 * 8),0,(uVar19 - uVar37) * 8);
    }
    *(ulong *)(param_1[0x1b] + 8) = uVar19;
    lVar41 = *(long *)param_1[0x1d];
  }
  *(long *)param_1[0x1d] = lVar41 + 1;
  local_168 = (void *)0x0;
  local_160 = 0;
  local_158 = (uint *)0x0;
  puStack_150 = (uint *)0x0;
  local_148 = (uint *)0x0;
  puStack_140 = (undefined8 *)0x0;
  local_138 = (undefined1  [16])0x0;
  local_128 = (undefined1  [16])0x0;
  FUN_0011a400(&local_168,0);
  auVar13 = local_118;
  local_118._0_8_ = local_118._4_8_ << 0x20;
  local_118._12_4_ = auVar13._12_4_;
  local_118._8_4_ = 0;
  auVar13._4_8_ = local_118._8_8_;
  auVar13._0_4_ = (int)param_2[3];
  auVar13._12_4_ = 0;
  local_118 = auVar13 << 0x20;
  FUN_0011b600(&local_168);
  if ((uint *)local_138._0_8_ == local_158) {
    local_1f0 = 0;
    lVar41 = *(long *)param_1[3];
    pauVar23 = (undefined1 (*) [16])0x0;
    uVar37 = 0;
    local_1f8 = (undefined8 *)0x0;
  }
  else {
    local_1f0 = 0;
    pauVar23 = (undefined1 (*) [16])0x0;
    uVar37 = 0;
    local_1f8 = (undefined8 *)0x0;
    puVar34 = local_158;
    do {
      puVar24 = puStack_140;
      uVar19 = (ulong)*puVar34;
      lVar48 = *(long *)param_1[0x1d] -
               (((long)local_148 - (long)puVar34 >> 2) * -0x5555555555555555 +
               ((long)(local_138._0_8_ - local_138._8_8_) >> 2) * -0x5555555555555555 +
               ((local_128._8_8_ - (long)puStack_140 >> 3) + -1 + (ulong)(local_128._8_8_ == 0)) *
               0x2a);
      uVar5 = puVar34[1];
      uVar6 = puVar34[2];
      if (puVar34 == local_148 + -3) {
        operator_delete(puStack_150);
        puVar34 = (uint *)puVar24[1];
        puStack_140 = puVar24 + 1;
        local_148 = puVar34 + 0x7e;
        puStack_150 = puVar34;
      }
      else {
        puVar34 = puVar34 + 3;
      }
      uVar38 = (ulong)uVar5;
      local_158 = puVar34;
      if (uVar19 < uVar38) {
        lVar41 = param_2[1];
        do {
          lVar21 = uVar19 * 0x18;
          if (uVar6 != *(uint *)(lVar41 + lVar21 + 8)) goto LAB_0011bbbc;
          uVar19 = (ulong)((int)uVar19 + 1);
          *(int *)(lVar41 + lVar21 + 0xc) = (int)lVar48;
        } while (uVar19 < uVar38);
      }
      if (uVar38 == uVar19) {
        lVar41 = *(long *)param_1[3];
        if (lVar41 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
          FUN_00106868();
        }
        uVar19 = *(ulong *)(param_1[1] + 8);
        if (lVar41 == uVar19 << 6) {
          uVar20 = *(ulong *)param_1[2];
          uVar38 = uVar19 + 1;
          if (uVar20 < uVar38) {
            if (uVar38 >> 1 < uVar20) {
              uVar19 = 0xfffffffffffffff8;
              uVar30 = 0x1fffffffffffffff;
              if (uVar20 < 0x1000000000000000) {
                uVar19 = uVar20 << 4;
                uVar30 = uVar20 * 2;
              }
            }
            else {
              uVar19 = uVar38 * 8;
              uVar30 = uVar38;
            }
            pvVar18 = operator_new__(uVar19,(nothrow_t *)PTR_nothrow_00132fb8);
            uVar19 = *(ulong *)(param_1[1] + 8);
            auVar47._8_8_ = pvVar18;
            auVar47._0_8_ = pvVar18;
            if (uVar19 != 0) {
              lVar41 = *(long *)(*param_1 + 8);
              if ((pvVar18 == (void *)(lVar41 + 8)) || (uVar19 - 1 < 3)) {
                uVar20 = 0;
                do {
                  *(undefined8 *)((long)pvVar18 + uVar20 * 8) = *(undefined8 *)(lVar41 + uVar20 * 8)
                  ;
                  uVar20 = uVar20 + 1;
                } while (uVar19 != uVar20);
              }
              else {
                lVar48 = 0;
                do {
                  *(undefined1 (*) [16])((long)pvVar18 + lVar48) =
                       *(undefined1 (*) [16])(lVar41 + lVar48);
                  lVar48 = lVar48 + 0x10;
                } while ((uVar19 >> 1) * 0x10 != lVar48);
                if ((uVar19 & 1) != 0) {
                  *(undefined8 *)((long)pvVar18 + (uVar19 & 0xfffffffffffffffe) * 8) =
                       *(undefined8 *)(lVar41 + (uVar19 & 0xfffffffffffffffe) * 8);
                }
              }
            }
            *(void **)param_1[1] = pvVar18;
            *(ulong *)param_1[2] = uVar30;
            *param_1 = auVar47;
            if (*(void **)*param_1 != (void *)0x0) {
              operator_delete__(*(void **)*param_1);
              uVar19 = *(ulong *)(param_1[1] + 8);
            }
          }
          if (uVar19 < uVar38) {
            memset((void *)(*(long *)(*param_1 + 8) + uVar19 * 8),0,(uVar38 - uVar19) * 8);
          }
          *(ulong *)(param_1[1] + 8) = uVar38;
          lVar41 = *(long *)param_1[3];
        }
        lVar41 = lVar41 + 1;
        *(long *)param_1[3] = lVar41;
      }
      else {
        lVar21 = uVar19 * 0x18;
LAB_0011bbbc:
        uVar49 = (undefined4)uVar19;
        if (pauVar23 != (undefined1 (*) [16])0x0) {
          operator_delete__(pauVar23);
        }
        uVar20 = uVar19 + 1;
        lVar41 = param_2[1];
        fVar50 = *(float *)(lVar41 + 0xc + lVar21);
        auVar42._0_8_ = (double)fVar50;
        auVar42._8_8_ = 0;
        if (uVar20 < uVar38) {
          lVar21 = uVar19 * 0x18;
          uVar35 = 0;
          pauVar23 = (undefined1 (*) [16])0x0;
          uVar40 = 0;
          do {
            plVar2 = (long *)(lVar41 + lVar21);
            lVar21 = lVar21 + 0x18;
            plVar31 = (long *)(lVar41 + lVar21);
            uVar39 = uVar40 * 0x10;
            uVar36 = uVar35;
            uVar32 = uVar39;
            pauVar22 = pauVar23;
            uVar30 = uVar40;
            if (*(char *)(*plVar31 + (ulong)uVar6) != *(char *)(*plVar2 + (ulong)uVar6)) {
              uVar30 = uVar40 + 1;
              uVar49 = (undefined4)uVar19;
              uVar32 = uVar39 + 0x10;
              if (uVar35 < uVar30) {
                uVar36 = uVar30;
                uVar19 = uVar32;
                if (uVar30 >> 1 < uVar35) {
                  if (uVar35 < 0x800000000000000) {
                    uVar36 = uVar35 * 2;
                    uVar19 = uVar35 << 5;
                  }
                  else {
                    uVar36 = 0xfffffffffffffff;
                    uVar19 = 0xfffffffffffffff0;
                  }
                }
                pauVar22 = operator_new__(uVar19,(nothrow_t *)PTR_nothrow_00132fb8);
                uVar19 = 0;
                if (uVar40 == 0) {
                  if (pauVar23 == (undefined1 (*) [16])0x0) {
                    lVar41 = param_2[1];
                    plVar31 = (long *)(lVar41 + lVar21);
                    goto LAB_0011bd83;
                  }
                }
                else {
                  do {
                    uVar17 = *(undefined8 *)((long)(*pauVar23 + uVar19) + 8);
                    *(undefined8 *)(*pauVar22 + uVar19) = *(undefined8 *)(*pauVar23 + uVar19);
                    *(undefined8 *)((long)(*pauVar22 + uVar19) + 8) = uVar17;
                    uVar19 = uVar19 + 0x10;
                  } while (uVar19 != uVar39);
                }
                operator_delete__(pauVar23);
                lVar41 = param_2[1];
                plVar31 = (long *)(lVar41 + lVar21);
              }
LAB_0011bd83:
              pauVar23 = pauVar22 + uVar40;
              *(float *)(*pauVar23 + 0xc) = (float)auVar42._0_8_;
              auVar42 = (undefined1  [16])0x0;
              *(uint *)(*pauVar23 + 8) = uVar6;
              uVar19 = uVar20 & 0xffffffff;
              *(ulong *)*pauVar23 = CONCAT44((int)uVar20,uVar49);
            }
            uVar49 = (undefined4)uVar19;
            uVar20 = uVar20 + 1;
            auVar42._0_8_ = auVar42._0_8_ + (double)*(float *)((long)plVar31 + 0xc);
            uVar35 = uVar36;
            pauVar23 = pauVar22;
            uVar40 = uVar30;
          } while (uVar20 < uVar38);
          local_208 = uVar30 + 1;
          fVar50 = (float)auVar42._0_8_;
          if (uVar36 < local_208) {
            if (uVar36 <= local_208 >> 1) goto LAB_0011ce98;
            if (uVar36 >> 0x3b == 0) {
              uVar36 = uVar36 << 5;
            }
            else {
              uVar36 = 0xfffffffffffffff0;
            }
            goto LAB_0011be1b;
          }
        }
        else {
          local_208 = 1;
          uVar32 = 0;
          pauVar22 = (undefined1 (*) [16])0x0;
          uVar30 = 0;
LAB_0011ce98:
          uVar36 = local_208 << 4;
LAB_0011be1b:
          pauVar23 = operator_new__(uVar36,(nothrow_t *)PTR_nothrow_00132fb8);
          if (uVar30 == 0) {
            if (pauVar22 == (undefined1 (*) [16])0x0) goto LAB_0011be57;
          }
          else {
            memcpy(pauVar23,pauVar22,uVar30 << 4);
          }
          operator_delete__(pauVar22);
        }
LAB_0011be57:
        puVar24 = (undefined8 *)(*pauVar23 + uVar32);
        *(uint *)(puVar24 + 1) = uVar6;
        *puVar24 = CONCAT44(uVar5,uVar49);
        iVar7 = *(int *)(param_4 + 0x10);
        *(float *)((long)puVar24 + 0xc) = fVar50;
        puVar14 = PTR_nothrow_00132fb8;
        if (iVar7 == 0x20000) {
          if (pauVar23 + local_208 != pauVar23) {
            lVar41 = ((long)(local_208 * 0x10) >> 4) + 1;
            lVar41 = lVar41 - (lVar41 >> 0x3f);
            if ((long)(local_208 * 0x10) < 1) {
LAB_0011d39a:
              pauVar22 = (undefined1 (*) [16])0x0;
              FUN_00111d60(pauVar23);
            }
            else {
              while( true ) {
                lVar41 = lVar41 >> 1;
                pauVar22 = operator_new(lVar41 * 0x10,(nothrow_t *)puVar14);
                if (pauVar22 != (undefined1 (*) [16])0x0) break;
                if (lVar41 == 1) goto LAB_0011d39a;
                lVar41 = lVar41 + 1;
              }
              uVar17 = *(undefined8 *)(*pauVar23 + 8);
              *(undefined8 *)*pauVar22 = *(undefined8 *)*pauVar23;
              *(undefined8 *)(*pauVar22 + 8) = uVar17;
              pauVar29 = pauVar22;
              pauVar28 = pauVar22 + 1;
              if (pauVar22 + lVar41 != pauVar22 + 1) {
                do {
                  uVar49 = *(undefined4 *)(pauVar28[-1] + 4);
                  uVar11 = *(undefined4 *)(pauVar28[-1] + 8);
                  uVar12 = *(undefined4 *)(pauVar28[-1] + 0xc);
                  pauVar29 = pauVar28 + 1;
                  *(undefined4 *)*pauVar28 = *(undefined4 *)pauVar28[-1];
                  *(undefined4 *)(*pauVar28 + 4) = uVar49;
                  *(undefined4 *)(*pauVar28 + 8) = uVar11;
                  *(undefined4 *)(*pauVar28 + 0xc) = uVar12;
                  pauVar28 = pauVar29;
                } while (pauVar22 + lVar41 != pauVar29);
                pauVar29 = pauVar22 + lVar41 + -1;
              }
              *pauVar23 = *pauVar29;
              FUN_00117550(pauVar23,pauVar23 + local_208,pauVar22,lVar41);
            }
            operator_delete(pauVar22);
          }
        }
        if (lVar48 == 0) {
          *(ulong *)(param_1[0x42] + 8) = local_208;
        }
        if (local_208 == 0) {
          lVar41 = *(long *)param_1[3];
        }
        else {
          local_218 = 0;
          pauVar22 = pauVar23;
          do {
            uVar19 = (ulong)*(uint *)(*pauVar22 + 8) + 1;
            plVar2 = (long *)(param_2[1] + (ulong)*(uint *)*pauVar22 * 0x18);
            if (uVar19 < *(uint *)(plVar2 + 1)) {
              uVar38 = (ulong)*(uint *)*pauVar22 + 1;
              do {
                if (uVar38 < *(uint *)(*pauVar22 + 4)) {
                  lVar41 = *plVar2;
                  uVar20 = uVar38;
                  plVar31 = (long *)(param_2[1] + uVar38 * 0x18);
                  do {
                    pcVar3 = (char *)(lVar41 + uVar19);
                    lVar41 = *plVar31;
                    if (*(char *)(lVar41 + uVar19) != *pcVar3) goto LAB_0011bf36;
                    uVar20 = uVar20 + 1;
                    plVar31 = plVar31 + 3;
                  } while (uVar20 < *(uint *)(*pauVar22 + 4));
                }
                uVar19 = uVar19 + 1;
              } while (uVar19 < *(uint *)(plVar2 + 1));
            }
LAB_0011bf36:
            FUN_00113810(param_1,lVar48,*(undefined8 *)(param_1[0x28] + 8),
                         (int)*(char *)(*plVar2 + (ulong)*(uint *)(*pauVar22 + 8)));
            uVar30 = *(ulong *)(param_1[0x28] + 8);
            uVar20 = *(ulong *)param_1[0x29];
            uVar38 = uVar30 + 1;
            if ((ulong)*(uint *)(*pauVar22 + 8) + 1 == uVar19) {
              uVar15 = *(undefined1 *)
                        (*(long *)((ulong)*(uint *)*pauVar22 * 0x18 + param_2[1]) +
                        (ulong)*(uint *)(*pauVar22 + 8));
              if (uVar20 < uVar38) {
                if ((uVar38 >> 1 < uVar20) && (uVar38 = uVar20 * 2, (long)uVar20 < 0)) {
                  uVar38 = 0xffffffffffffffff;
                }
                pvVar18 = operator_new__(uVar38,(nothrow_t *)PTR_nothrow_00132fb8);
                uVar30 = *(ulong *)(param_1[0x28] + 8);
                auVar43._8_8_ = pvVar18;
                auVar43._0_8_ = pvVar18;
                if (uVar30 != 0) {
                  lVar41 = *(long *)(param_1[0x27] + 8);
                  if (((ulong)((long)pvVar18 - (lVar41 + 1)) < 0xf) || (uVar30 - 1 < 7)) {
                    uVar20 = 0;
                    do {
                      *(undefined1 *)((long)pvVar18 + uVar20) = *(undefined1 *)(lVar41 + uVar20);
                      uVar20 = uVar20 + 1;
                    } while (uVar20 != uVar30);
                  }
                  else if (uVar30 - 1 < 0xf) {
                    uVar32 = 0;
                    uVar20 = uVar30;
LAB_0011c8c1:
                    *(undefined8 *)((long)pvVar18 + uVar32) = *(undefined8 *)(lVar41 + uVar32);
                    uVar32 = uVar32 + (uVar20 & 0xfffffffffffffff8);
                    if (uVar20 != (uVar20 & 0xfffffffffffffff8)) {
LAB_0011c8d8:
                      *(undefined1 *)((long)pvVar18 + uVar32) = *(undefined1 *)(lVar41 + uVar32);
                      if (((((uVar32 + 1 < uVar30) &&
                            (*(undefined1 *)((long)pvVar18 + uVar32 + 1) =
                                  *(undefined1 *)(lVar41 + 1 + uVar32), uVar32 + 2 < uVar30)) &&
                           (*(undefined1 *)((long)pvVar18 + uVar32 + 2) =
                                 *(undefined1 *)(lVar41 + 2 + uVar32), uVar32 + 3 < uVar30)) &&
                          ((*(undefined1 *)((long)pvVar18 + uVar32 + 3) =
                                 *(undefined1 *)(lVar41 + 3 + uVar32), uVar32 + 4 < uVar30 &&
                           (*(undefined1 *)((long)pvVar18 + uVar32 + 4) =
                                 *(undefined1 *)(lVar41 + 4 + uVar32), uVar32 + 5 < uVar30)))) &&
                         (*(undefined1 *)((long)pvVar18 + uVar32 + 5) =
                               *(undefined1 *)(lVar41 + 5 + uVar32), uVar32 + 6 < uVar30)) {
                        *(undefined1 *)((long)pvVar18 + uVar32 + 6) =
                             *(undefined1 *)(lVar41 + 6 + uVar32);
                      }
                    }
                  }
                  else {
                    uVar20 = 0;
                    do {
                      uVar17 = ((undefined8 *)(lVar41 + uVar20))[1];
                      *(undefined8 *)((long)pvVar18 + uVar20) = *(undefined8 *)(lVar41 + uVar20);
                      ((undefined8 *)((long)pvVar18 + uVar20))[1] = uVar17;
                      uVar20 = uVar20 + 0x10;
                    } while ((uVar30 & 0xfffffffffffffff0) != uVar20);
                    uVar32 = uVar30 & 0xfffffffffffffff0;
                    if ((uVar30 & 0xf) != 0) {
                      uVar20 = uVar30 - uVar32;
                      if (6 < (uVar30 - uVar32) - 1) goto LAB_0011c8c1;
                      goto LAB_0011c8d8;
                    }
                  }
                }
                pvVar8 = *(void **)param_1[0x27];
                *(void **)param_1[0x28] = pvVar18;
                *(ulong *)param_1[0x29] = uVar38;
                param_1[0x27] = auVar43;
                if (pvVar8 != (void *)0x0) {
                  operator_delete__(pvVar8);
                  pvVar18 = *(void **)(param_1[0x27] + 8);
                  uVar30 = *(ulong *)(param_1[0x28] + 8);
                }
              }
              else {
                pvVar18 = *(void **)(param_1[0x27] + 8);
              }
              *(undefined1 *)((long)pvVar18 + uVar30) = uVar15;
              lVar41 = *(long *)param_1[0x1d];
              *(long *)(param_1[0x28] + 8) = *(long *)(param_1[0x28] + 8) + 1;
              if (lVar41 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
                FUN_00106868();
              }
              uVar38 = *(ulong *)(param_1[0x1b] + 8);
              if (lVar41 == uVar38 << 6) {
                uVar30 = *(ulong *)param_1[0x1c];
                uVar20 = uVar38 + 1;
                if (uVar30 < uVar20) {
                  if (uVar20 >> 1 < uVar30) {
                    uVar38 = 0xfffffffffffffff8;
                    uVar32 = 0x1fffffffffffffff;
                    if (uVar30 < 0x1000000000000000) {
                      uVar32 = uVar30 * 2;
                      uVar38 = uVar30 << 4;
                    }
                  }
                  else {
                    uVar38 = uVar20 * 8;
                    uVar32 = uVar20;
                  }
                  pvVar18 = operator_new__(uVar38,(nothrow_t *)PTR_nothrow_00132fb8);
                  uVar38 = *(ulong *)(param_1[0x1b] + 8);
                  auVar45._8_8_ = pvVar18;
                  auVar45._0_8_ = pvVar18;
                  if (uVar38 != 0) {
                    lVar41 = *(long *)(param_1[0x1a] + 8);
                    if ((pvVar18 == (void *)(lVar41 + 8)) || (uVar38 - 1 < 3)) {
                      uVar30 = 0;
                      do {
                        *(undefined8 *)((long)pvVar18 + uVar30 * 8) =
                             *(undefined8 *)(lVar41 + uVar30 * 8);
                        uVar30 = uVar30 + 1;
                      } while (uVar38 != uVar30);
                    }
                    else {
                      lVar21 = 0;
                      do {
                        puVar27 = (undefined4 *)(lVar41 + lVar21);
                        uVar49 = puVar27[1];
                        uVar11 = puVar27[2];
                        uVar12 = puVar27[3];
                        puVar4 = (undefined4 *)((long)pvVar18 + lVar21);
                        *puVar4 = *puVar27;
                        puVar4[1] = uVar49;
                        puVar4[2] = uVar11;
                        puVar4[3] = uVar12;
                        lVar21 = lVar21 + 0x10;
                      } while ((uVar38 >> 1) * 0x10 != lVar21);
                      if ((uVar38 & 1) != 0) {
                        *(undefined8 *)((long)pvVar18 + (uVar38 & 0xfffffffffffffffe) * 8) =
                             *(undefined8 *)(lVar41 + (uVar38 & 0xfffffffffffffffe) * 8);
                      }
                    }
                  }
                  pvVar8 = *(void **)param_1[0x1a];
                  *(void **)param_1[0x1b] = pvVar18;
                  *(ulong *)param_1[0x1c] = uVar32;
                  param_1[0x1a] = auVar45;
                  if (pvVar8 != (void *)0x0) {
                    operator_delete__(pvVar8);
                    uVar38 = *(ulong *)(param_1[0x1b] + 8);
                  }
                }
                if (uVar38 < uVar20) {
                  memset((void *)(*(long *)(param_1[0x1a] + 8) + uVar38 * 8),0,(uVar20 - uVar38) * 8
                        );
                }
                *(ulong *)(param_1[0x1b] + 8) = uVar20;
                lVar41 = *(long *)param_1[0x1d];
              }
              *(long *)param_1[0x1d] = lVar41 + 1;
            }
            else {
              if (uVar20 < uVar38) {
                if ((uVar38 >> 1 < uVar20) && (uVar38 = uVar20 * 2, (long)uVar20 < 0)) {
                  uVar38 = 0xffffffffffffffff;
                }
                pvVar18 = operator_new__(uVar38,(nothrow_t *)PTR_nothrow_00132fb8);
                uVar30 = *(ulong *)(param_1[0x28] + 8);
                if (uVar30 != 0) {
                  lVar41 = *(long *)(param_1[0x27] + 8);
                  if (((ulong)((long)pvVar18 - (lVar41 + 1)) < 0xf) || (uVar30 - 1 < 7)) {
                    uVar20 = 0;
                    do {
                      *(undefined1 *)((long)pvVar18 + uVar20) = *(undefined1 *)(lVar41 + uVar20);
                      uVar20 = uVar20 + 1;
                    } while (uVar30 != uVar20);
                  }
                  else if (uVar30 - 1 < 0xf) {
                    uVar32 = 0;
                    uVar20 = uVar30;
LAB_0011c041:
                    *(undefined8 *)((long)pvVar18 + uVar32) = *(undefined8 *)(lVar41 + uVar32);
                    uVar32 = uVar32 + (uVar20 & 0xfffffffffffffff8);
                    if ((uVar20 & 0xfffffffffffffff8) != uVar20) {
LAB_0011c058:
                      *(undefined1 *)((long)pvVar18 + uVar32) = *(undefined1 *)(lVar41 + uVar32);
                      if ((((uVar32 + 1 < uVar30) &&
                           (*(undefined1 *)((long)pvVar18 + uVar32 + 1) =
                                 *(undefined1 *)(lVar41 + 1 + uVar32), uVar32 + 2 < uVar30)) &&
                          (*(undefined1 *)((long)pvVar18 + uVar32 + 2) =
                                *(undefined1 *)(lVar41 + 2 + uVar32), uVar32 + 3 < uVar30)) &&
                         (((*(undefined1 *)((long)pvVar18 + uVar32 + 3) =
                                 *(undefined1 *)(lVar41 + 3 + uVar32), uVar32 + 4 < uVar30 &&
                           (*(undefined1 *)((long)pvVar18 + uVar32 + 4) =
                                 *(undefined1 *)(lVar41 + 4 + uVar32), uVar32 + 5 < uVar30)) &&
                          (*(undefined1 *)((long)pvVar18 + uVar32 + 5) =
                                *(undefined1 *)(lVar41 + 5 + uVar32), uVar32 + 6 < uVar30)))) {
                        *(undefined1 *)((long)pvVar18 + uVar32 + 6) =
                             *(undefined1 *)(lVar41 + 6 + uVar32);
                      }
                    }
                  }
                  else {
                    uVar20 = 0;
                    do {
                      uVar17 = ((undefined8 *)(lVar41 + uVar20))[1];
                      *(undefined8 *)((long)pvVar18 + uVar20) = *(undefined8 *)(lVar41 + uVar20);
                      ((undefined8 *)((long)pvVar18 + uVar20))[1] = uVar17;
                      uVar20 = uVar20 + 0x10;
                    } while (uVar20 != (uVar30 & 0xfffffffffffffff0));
                    uVar32 = uVar30 & 0xfffffffffffffff0;
                    if ((uVar30 & 0xf) != 0) {
                      uVar20 = uVar30 - uVar32;
                      if (6 < (uVar30 - uVar32) - 1) goto LAB_0011c041;
                      goto LAB_0011c058;
                    }
                  }
                }
                pvVar8 = *(void **)param_1[0x27];
                *(void **)param_1[0x28] = pvVar18;
                *(ulong *)param_1[0x29] = uVar38;
                *(void **)param_1[0x27] = pvVar18;
                *(void **)(param_1[0x27] + 8) = pvVar18;
                if (pvVar8 != (void *)0x0) {
                  operator_delete__(pvVar8);
                  pvVar18 = *(void **)(param_1[0x27] + 8);
                  uVar30 = *(ulong *)(param_1[0x28] + 8);
                }
              }
              else {
                pvVar18 = *(void **)(param_1[0x27] + 8);
              }
              *(undefined1 *)((long)pvVar18 + uVar30) = 0;
              uVar38 = *(ulong *)param_1[0x1d];
              *(long *)(param_1[0x28] + 8) = *(long *)(param_1[0x28] + 8) + 1;
              if (uVar38 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
                FUN_00106868();
              }
              uVar20 = *(ulong *)(param_1[0x1b] + 8);
              if (uVar38 == uVar20 << 6) {
                uVar30 = *(ulong *)param_1[0x1c];
                uVar38 = uVar20 + 1;
                if (uVar30 < uVar38) {
                  if (uVar38 >> 1 < uVar30) {
                    uVar20 = 0xfffffffffffffff8;
                    uVar32 = 0x1fffffffffffffff;
                    if (uVar30 < 0x1000000000000000) {
                      uVar32 = uVar30 * 2;
                      uVar20 = uVar30 << 4;
                    }
                  }
                  else {
                    uVar20 = uVar38 * 8;
                    uVar32 = uVar38;
                  }
                  pvVar18 = operator_new__(uVar20,(nothrow_t *)PTR_nothrow_00132fb8);
                  uVar20 = *(ulong *)(param_1[0x1b] + 8);
                  if (uVar20 != 0) {
                    lVar41 = *(long *)(param_1[0x1a] + 8);
                    if ((pvVar18 == (void *)(lVar41 + 8)) || (uVar20 - 1 < 3)) {
                      uVar30 = 0;
                      do {
                        *(undefined8 *)((long)pvVar18 + uVar30 * 8) =
                             *(undefined8 *)(lVar41 + uVar30 * 8);
                        uVar30 = uVar30 + 1;
                      } while (uVar20 != uVar30);
                    }
                    else {
                      lVar21 = 0;
                      do {
                        *(undefined1 (*) [16])((long)pvVar18 + lVar21) =
                             *(undefined1 (*) [16])(lVar41 + lVar21);
                        lVar21 = lVar21 + 0x10;
                      } while (lVar21 != (uVar20 >> 1) * 0x10);
                      if ((uVar20 & 1) != 0) {
                        *(undefined8 *)((long)pvVar18 + (uVar20 & 0xfffffffffffffffe) * 8) =
                             *(undefined8 *)(lVar41 + (uVar20 & 0xfffffffffffffffe) * 8);
                      }
                    }
                  }
                  pvVar8 = *(void **)param_1[0x1a];
                  *(void **)param_1[0x1b] = pvVar18;
                  *(ulong *)param_1[0x1c] = uVar32;
                  *(void **)param_1[0x1a] = pvVar18;
                  *(void **)(param_1[0x1a] + 8) = pvVar18;
                  if (pvVar8 != (void *)0x0) {
                    operator_delete__(pvVar8);
                    uVar20 = *(ulong *)(param_1[0x1b] + 8);
                    pvVar18 = *(void **)(param_1[0x1a] + 8);
                  }
                }
                else {
                  pvVar18 = *(void **)(param_1[0x1a] + 8);
                }
                if (uVar20 < uVar38) {
                  memset((void *)((long)pvVar18 + uVar20 * 8),0,(uVar38 - uVar20) * 8);
                }
                *(ulong *)(param_1[0x1b] + 8) = uVar38;
                uVar38 = *(ulong *)param_1[0x1d];
              }
              else {
                pvVar18 = *(void **)(param_1[0x1a] + 8);
              }
              puVar1 = (ulong *)((long)pvVar18 + (uVar38 >> 6) * 8);
              *puVar1 = *puVar1 | 1L << ((byte)uVar38 & 0x3f);
              uVar38 = uVar37 + 1;
              uVar5 = *(uint *)(*pauVar22 + 8);
              lVar21 = *(long *)(param_1[0x1d] + 8) + _UNK_0012a668;
              lVar41 = *(long *)((ulong)*(uint *)*pauVar22 * 0x18 + param_2[1]);
              *(long *)param_1[0x1d] = *(long *)param_1[0x1d] + _DAT_0012a660;
              *(long *)(param_1[0x1d] + 8) = lVar21;
              uVar49 = *(undefined4 *)(*pauVar22 + 0xc);
              puVar24 = local_1f8;
              if (local_1f0 < uVar38) {
                if (uVar38 >> 1 < local_1f0) {
                  if (local_1f0 < 0x555555555555556) {
                    uVar20 = local_1f0 * 0x30;
                    local_1f0 = local_1f0 * 2;
                  }
                  else {
                    uVar20 = 0xfffffffffffffff0;
                    local_1f0 = 0xaaaaaaaaaaaaaaa;
                  }
                }
                else {
                  uVar20 = uVar38 * 0x18;
                  local_1f0 = uVar38;
                }
                puVar24 = operator_new__(uVar20,(nothrow_t *)PTR_nothrow_00132fb8);
                if (uVar37 != 0) {
                  puVar25 = puVar24;
                  puVar33 = local_1f8;
                  do {
                    puVar26 = puVar25 + 3;
                    *puVar25 = *puVar33;
                    *(undefined4 *)(puVar25 + 1) = *(undefined4 *)(puVar33 + 1);
                    *(undefined4 *)((long)puVar25 + 0xc) = *(undefined4 *)((long)puVar33 + 0xc);
                    *(undefined4 *)(puVar25 + 2) = *(undefined4 *)(puVar33 + 2);
                    puVar25 = puVar26;
                    puVar33 = puVar33 + 3;
                  } while (puVar24 + uVar37 * 3 != puVar26);
                }
                if (local_1f8 != (undefined8 *)0x0) {
                  operator_delete__(local_1f8);
                }
              }
              local_1f8 = puVar24;
              plVar2 = local_1f8 + uVar37 * 3;
              *plVar2 = lVar41 + (ulong)uVar5;
              *(uint *)(plVar2 + 1) = (int)uVar19 - uVar5;
              *(undefined4 *)(plVar2 + 2) = 0;
              *(undefined4 *)((long)plVar2 + 0xc) = uVar49;
              uVar37 = uVar38;
            }
            *(int *)(*pauVar22 + 8) = (int)uVar19;
            if ((undefined8 *)local_138._0_8_ == (undefined8 *)(local_128._0_8_ + -0xc)) {
              FUN_0011b500(&local_168);
            }
            else {
              *(undefined8 *)local_138._0_8_ = *(undefined8 *)*pauVar22;
              *(undefined4 *)(local_138._0_8_ + 8) = *(undefined4 *)(*pauVar22 + 8);
              local_138._0_8_ = local_138._0_8_ + 0xc;
            }
            uVar19 = *(ulong *)param_1[3];
            if (uVar19 == 0xffffffff) goto LAB_0011daee;
            uVar38 = *(ulong *)(param_1[1] + 8);
            if (uVar19 == uVar38 << 6) {
              uVar20 = *(ulong *)param_1[2];
              uVar19 = uVar38 + 1;
              if (uVar20 < uVar19) {
                if (uVar19 >> 1 < uVar20) {
                  uVar38 = 0xfffffffffffffff8;
                  uVar30 = 0x1fffffffffffffff;
                  if (uVar20 < 0x1000000000000000) {
                    uVar30 = uVar20 * 2;
                    uVar38 = uVar20 << 4;
                  }
                }
                else {
                  uVar38 = uVar19 * 8;
                  uVar30 = uVar19;
                }
                pvVar18 = operator_new__(uVar38,(nothrow_t *)PTR_nothrow_00132fb8);
                uVar38 = *(ulong *)(param_1[1] + 8);
                auVar44._8_8_ = pvVar18;
                auVar44._0_8_ = pvVar18;
                if (uVar38 != 0) {
                  lVar41 = *(long *)(*param_1 + 8);
                  if ((pvVar18 == (void *)(lVar41 + 8)) || (uVar38 - 1 < 3)) {
                    uVar20 = 0;
                    do {
                      *(undefined8 *)((long)pvVar18 + uVar20 * 8) =
                           *(undefined8 *)(lVar41 + uVar20 * 8);
                      uVar20 = uVar20 + 1;
                    } while (uVar38 != uVar20);
                  }
                  else {
                    lVar21 = 0;
                    do {
                      *(undefined1 (*) [16])((long)pvVar18 + lVar21) =
                           *(undefined1 (*) [16])(lVar41 + lVar21);
                      lVar21 = lVar21 + 0x10;
                    } while ((uVar38 >> 1) * 0x10 != lVar21);
                    if ((uVar38 & 1) != 0) {
                      *(undefined8 *)((long)pvVar18 + (uVar38 & 0xfffffffffffffffe) * 8) =
                           *(undefined8 *)(lVar41 + (uVar38 & 0xfffffffffffffffe) * 8);
                    }
                  }
                }
                *(void **)param_1[1] = pvVar18;
                *(ulong *)param_1[2] = uVar30;
                *param_1 = auVar44;
                if (*(void **)*param_1 != (void *)0x0) {
                  operator_delete__(*(void **)*param_1);
                  uVar38 = *(ulong *)(param_1[1] + 8);
                  goto LAB_0011cad1;
                }
              }
              else {
LAB_0011cad1:
                pvVar18 = *(void **)(*param_1 + 8);
              }
              if (uVar38 < uVar19) {
                memset((void *)((long)pvVar18 + uVar38 * 8),0,(uVar19 - uVar38) * 8);
              }
              *(ulong *)(param_1[1] + 8) = uVar19;
              uVar19 = *(ulong *)param_1[3];
            }
            else {
              pvVar18 = *(void **)(*param_1 + 8);
            }
            local_218 = local_218 + 1;
            pauVar22 = pauVar22 + 1;
            puVar1 = (ulong *)((long)pvVar18 + (uVar19 >> 6) * 8);
            *puVar1 = *puVar1 | 1L << ((byte)uVar19 & 0x3f);
            lVar41 = *(long *)param_1[3];
            *(long *)(param_1[3] + 8) = *(long *)(param_1[3] + 8) + 1;
            lVar41 = lVar41 + 1;
            *(long *)param_1[3] = lVar41;
          } while (local_218 != local_208);
        }
        if (lVar41 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
          FUN_00106868();
        }
        uVar19 = *(ulong *)(param_1[1] + 8);
        if (uVar19 << 6 == lVar41) {
          uVar20 = *(ulong *)param_1[2];
          uVar38 = uVar19 + 1;
          if (uVar20 < uVar38) {
            if (uVar38 >> 1 < uVar20) {
              uVar19 = 0xfffffffffffffff8;
              uVar30 = 0x1fffffffffffffff;
              if (uVar20 < 0x1000000000000000) {
                uVar30 = uVar20 * 2;
                uVar19 = uVar20 << 4;
              }
            }
            else {
              uVar19 = uVar38 * 8;
              uVar30 = uVar38;
            }
            pvVar18 = operator_new__(uVar19,(nothrow_t *)PTR_nothrow_00132fb8);
            uVar19 = *(ulong *)(param_1[1] + 8);
            auVar46._8_8_ = pvVar18;
            auVar46._0_8_ = pvVar18;
            if (uVar19 != 0) {
              lVar41 = *(long *)(*param_1 + 8);
              if ((pvVar18 == (void *)(lVar41 + 8)) || (uVar19 - 1 < 3)) {
                uVar20 = 0;
                do {
                  *(undefined8 *)((long)pvVar18 + uVar20 * 8) = *(undefined8 *)(lVar41 + uVar20 * 8)
                  ;
                  uVar20 = uVar20 + 1;
                } while (uVar19 != uVar20);
              }
              else {
                lVar48 = 0;
                do {
                  *(undefined1 (*) [16])((long)pvVar18 + lVar48) =
                       *(undefined1 (*) [16])(lVar41 + lVar48);
                  lVar48 = lVar48 + 0x10;
                } while (lVar48 != (uVar19 >> 1) * 0x10);
                if ((uVar19 & 1) != 0) {
                  *(undefined8 *)((long)pvVar18 + (uVar19 & 0xfffffffffffffffe) * 8) =
                       *(undefined8 *)(lVar41 + (uVar19 & 0xfffffffffffffffe) * 8);
                }
              }
            }
            *(void **)param_1[1] = pvVar18;
            *(ulong *)param_1[2] = uVar30;
            *param_1 = auVar46;
            if (*(void **)*param_1 != (void *)0x0) {
              operator_delete__(*(void **)*param_1);
              uVar19 = *(ulong *)(param_1[1] + 8);
            }
          }
          if (uVar19 < uVar38) {
            memset((void *)(*(long *)(*param_1 + 8) + uVar19 * 8),0,(uVar38 - uVar19) * 8);
          }
          *(ulong *)(param_1[1] + 8) = uVar38;
          lVar41 = *(long *)param_1[3];
        }
        lVar41 = lVar41 + 1;
        *(long *)param_1[3] = lVar41;
        puVar34 = local_158;
      }
    } while ((uint *)local_138._0_8_ != puVar34);
  }
  if (lVar41 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_00106868();
  }
  uVar19 = *(ulong *)(param_1[1] + 8);
  if (uVar19 << 6 == lVar41) {
    uVar20 = *(ulong *)param_1[2];
    uVar38 = uVar19 + 1;
    if (uVar20 < uVar38) {
      if (uVar38 >> 1 < uVar20) {
        uVar19 = 0xfffffffffffffff8;
        uVar30 = 0x1fffffffffffffff;
        if (uVar20 >> 0x3c == 0) {
          uVar30 = uVar20 * 2;
          uVar19 = uVar20 << 4;
        }
      }
      else {
        uVar19 = uVar38 * 8;
        uVar30 = uVar38;
      }
      pvVar18 = operator_new__(uVar19,(nothrow_t *)PTR_nothrow_00132fb8);
      uVar19 = *(ulong *)(param_1[1] + 8);
      if (uVar19 != 0) {
        lVar41 = *(long *)(*param_1 + 8);
        if ((pvVar18 == (void *)(lVar41 + 8)) || (uVar19 - 1 < 3)) {
          uVar20 = 0;
          do {
            *(undefined8 *)((long)pvVar18 + uVar20 * 8) = *(undefined8 *)(lVar41 + uVar20 * 8);
            uVar20 = uVar20 + 1;
          } while (uVar19 != uVar20);
        }
        else {
          lVar48 = 0;
          do {
            uVar17 = ((undefined8 *)(lVar41 + lVar48))[1];
            *(undefined8 *)((long)pvVar18 + lVar48) = *(undefined8 *)(lVar41 + lVar48);
            ((undefined8 *)((long)pvVar18 + lVar48))[1] = uVar17;
            lVar48 = lVar48 + 0x10;
          } while (lVar48 != (uVar19 >> 1) * 0x10);
          if ((uVar19 & 1) != 0) {
            *(undefined8 *)((long)pvVar18 + (uVar19 & 0xfffffffffffffffe) * 8) =
                 *(undefined8 *)(lVar41 + (uVar19 & 0xfffffffffffffffe) * 8);
          }
        }
      }
      pvVar8 = *(void **)*param_1;
      *(void **)param_1[1] = pvVar18;
      *(ulong *)param_1[2] = uVar30;
      *(void **)*param_1 = pvVar18;
      *(void **)(*param_1 + 8) = pvVar18;
      if (pvVar8 != (void *)0x0) {
        operator_delete__(pvVar8);
        uVar19 = *(ulong *)(param_1[1] + 8);
      }
    }
    if (uVar19 < uVar38) {
      memset((void *)(*(long *)(*param_1 + 8) + uVar19 * 8),0,(uVar38 - uVar19) * 8);
    }
    *(ulong *)(param_1[1] + 8) = uVar38;
    lVar41 = *(long *)param_1[3];
  }
  *(long *)param_1[3] = lVar41 + 1;
  local_108 = 0;
  local_f0 = 0;
  local_c8 = 0;
  local_b0 = 0;
  local_98 = 0;
  local_80 = 0;
  local_68 = 0;
  local_50 = 0;
  local_118 = (undefined1  [16])0x0;
  local_100 = (undefined1  [16])0x0;
  local_e8 = (undefined1  [16])0x0;
  local_d8 = (undefined1  [16])0x0;
  local_c0 = (undefined1  [16])0x0;
  local_a8 = (undefined1  [16])0x0;
  local_90 = (undefined1  [16])0x0;
  local_78 = (undefined1  [16])0x0;
  local_60 = (undefined1  [16])0x0;
  FUN_00126020(local_118,param_1,param_5 == 1,1);
  if (param_1[2][8] != '\0') {
LAB_0011dae9:
    FUN_001065cc();
LAB_0011daee:
                    /* WARNING: Subroutine does not return */
    FUN_00106868();
  }
  lVar41 = *(long *)(param_1[1] + 8);
  uVar15 = 0;
  if (lVar41 != *(long *)param_1[2]) {
    pvVar18 = operator_new__(lVar41 * 8,(nothrow_t *)PTR_nothrow_00132fb8);
    uVar19 = *(ulong *)(param_1[1] + 8);
    if (uVar19 != 0) {
      lVar48 = *(long *)(*param_1 + 8);
      if ((pvVar18 == (void *)(lVar48 + 8)) || (uVar19 - 1 < 3)) {
        uVar38 = 0;
        do {
          *(undefined8 *)((long)pvVar18 + uVar38 * 8) = *(undefined8 *)(lVar48 + uVar38 * 8);
          uVar38 = uVar38 + 1;
        } while (uVar19 != uVar38);
      }
      else {
        lVar21 = 0;
        do {
          uVar17 = ((undefined8 *)(lVar48 + lVar21))[1];
          *(undefined8 *)((long)pvVar18 + lVar21) = *(undefined8 *)(lVar48 + lVar21);
          ((undefined8 *)((long)pvVar18 + lVar21))[1] = uVar17;
          lVar21 = lVar21 + 0x10;
        } while (lVar21 != (uVar19 >> 1) * 0x10);
        if ((uVar19 & 1) != 0) {
          *(undefined8 *)((long)pvVar18 + (uVar19 & 0xfffffffffffffffe) * 8) =
               *(undefined8 *)(lVar48 + (uVar19 & 0xfffffffffffffffe) * 8);
        }
      }
    }
    pvVar8 = *(void **)*param_1;
    *(void **)param_1[1] = pvVar18;
    *(long *)param_1[2] = lVar41;
    *(void **)*param_1 = pvVar18;
    *(void **)(*param_1 + 8) = pvVar18;
    if (pvVar8 != (void *)0x0) {
      operator_delete__(pvVar8);
    }
    uVar15 = param_1[2][8];
  }
  auVar13 = param_1[3];
  param_1[2][8] = uVar15;
  uVar17 = *(undefined8 *)param_1[5];
  auVar47 = param_1[4];
  *(undefined8 *)param_1[5] = local_c8;
  auVar42 = *(undefined1 (*) [16])(param_1[5] + 8);
  uVar15 = param_1[6][8];
  pvVar18 = *(void **)param_1[7];
  auVar43 = param_1[7];
  param_1[6][8] = (undefined1)local_b0;
  local_b0 = CONCAT71(local_b0._1_7_,uVar15);
  uVar9 = *(undefined8 *)param_1[8];
  *(undefined8 *)param_1[3] = local_e8._0_8_;
  *(undefined8 *)(param_1[3] + 8) = local_e8._8_8_;
  auVar45 = *(undefined1 (*) [16])(param_1[8] + 8);
  *(undefined8 *)param_1[8] = local_98;
  *(undefined8 *)param_1[4] = local_d8._0_8_;
  *(undefined8 *)(param_1[4] + 8) = local_d8._8_8_;
  *(undefined8 *)(param_1[5] + 8) = local_c0._0_8_;
  *(undefined8 *)param_1[6] = local_c0._8_8_;
  *(undefined8 *)param_1[7] = local_a8._0_8_;
  *(undefined8 *)(param_1[7] + 8) = local_a8._8_8_;
  *(undefined8 *)(param_1[8] + 8) = local_90._0_8_;
  *(undefined8 *)param_1[9] = local_90._8_8_;
  uVar15 = param_1[9][8];
  pvVar8 = *(void **)param_1[10];
  auVar44 = param_1[10];
  param_1[9][8] = (undefined1)local_80;
  local_80 = CONCAT71(local_80._1_7_,uVar15);
  uVar10 = *(undefined8 *)param_1[0xb];
  auVar46 = *(undefined1 (*) [16])(param_1[0xb] + 8);
  *(undefined8 *)param_1[0xb] = local_68;
  uVar15 = param_1[0xc][8];
  *(undefined8 *)param_1[10] = local_78._0_8_;
  *(undefined8 *)(param_1[10] + 8) = local_78._8_8_;
  param_1[0xc][8] = (undefined1)local_50;
  local_50 = CONCAT71(local_50._1_7_,uVar15);
  *(undefined8 *)(param_1[0xb] + 8) = local_60._0_8_;
  *(undefined8 *)param_1[0xc] = local_60._8_8_;
  local_e8 = auVar13;
  local_d8 = auVar47;
  local_c8 = uVar17;
  local_c0 = auVar42;
  local_a8 = auVar43;
  local_98 = uVar9;
  local_90 = auVar45;
  local_78 = auVar44;
  local_68 = uVar10;
  local_60 = auVar46;
  if (pvVar8 != (void *)0x0) {
    operator_delete__(pvVar8);
    pvVar18 = (void *)local_a8._0_8_;
  }
  if (pvVar18 != (void *)0x0) {
    operator_delete__(pvVar18);
  }
  if ((void *)local_d8._0_8_ != (void *)0x0) {
    operator_delete__((void *)local_d8._0_8_);
  }
  if ((void *)local_118._0_8_ != (void *)0x0) {
    operator_delete__((void *)local_118._0_8_);
  }
  if (param_1[0x29][8] != '\0') {
    FUN_001065cc();
    goto LAB_0011dae9;
  }
  uVar19 = *(ulong *)(param_1[0x28] + 8);
  if (uVar19 == *(ulong *)param_1[0x29]) goto LAB_0011c682;
  pvVar18 = operator_new__(uVar19,(nothrow_t *)PTR_nothrow_00132fb8);
  uVar38 = *(ulong *)(param_1[0x28] + 8);
  if (uVar38 != 0) {
    lVar41 = *(long *)(param_1[0x27] + 8);
    if (((ulong)((long)pvVar18 - (lVar41 + 1)) < 0xf) || (uVar38 - 1 < 7)) {
      uVar20 = 0;
      do {
        *(undefined1 *)((long)pvVar18 + uVar20) = *(undefined1 *)(lVar41 + uVar20);
        uVar20 = uVar20 + 1;
      } while (uVar20 != uVar38);
    }
    else if (uVar38 - 1 < 0xf) {
      uVar30 = 0;
      uVar20 = uVar38;
LAB_0011d6a2:
      *(undefined8 *)((long)pvVar18 + uVar30) = *(undefined8 *)(lVar41 + uVar30);
      uVar30 = uVar30 + (uVar20 & 0xfffffffffffffff8);
      if (uVar20 != (uVar20 & 0xfffffffffffffff8)) {
LAB_0011d6b9:
        *(undefined1 *)((long)pvVar18 + uVar30) = *(undefined1 *)(lVar41 + uVar30);
        if ((((uVar30 + 1 < uVar38) &&
             (*(undefined1 *)((long)pvVar18 + uVar30 + 1) = *(undefined1 *)(lVar41 + 1 + uVar30),
             uVar30 + 2 < uVar38)) &&
            (*(undefined1 *)((long)pvVar18 + uVar30 + 2) = *(undefined1 *)(lVar41 + 2 + uVar30),
            uVar30 + 3 < uVar38)) &&
           (((*(undefined1 *)((long)pvVar18 + uVar30 + 3) = *(undefined1 *)(lVar41 + 3 + uVar30),
             uVar30 + 4 < uVar38 &&
             (*(undefined1 *)((long)pvVar18 + uVar30 + 4) = *(undefined1 *)(lVar41 + 4 + uVar30),
             uVar30 + 5 < uVar38)) &&
            (*(undefined1 *)((long)pvVar18 + uVar30 + 5) = *(undefined1 *)(lVar41 + 5 + uVar30),
            uVar30 + 6 < uVar38)))) {
          *(undefined1 *)((long)pvVar18 + uVar30 + 6) = *(undefined1 *)(lVar41 + 6 + uVar30);
        }
      }
    }
    else {
      uVar20 = 0;
      do {
        uVar17 = ((undefined8 *)(lVar41 + uVar20))[1];
        *(undefined8 *)((long)pvVar18 + uVar20) = *(undefined8 *)(lVar41 + uVar20);
        ((undefined8 *)((long)pvVar18 + uVar20))[1] = uVar17;
        uVar20 = uVar20 + 0x10;
      } while ((uVar38 & 0xfffffffffffffff0) != uVar20);
      uVar30 = uVar38 & 0xfffffffffffffff0;
      if ((uVar38 & 0xf) != 0) {
        uVar20 = uVar38 - uVar30;
        if (6 < (uVar38 - uVar30) - 1) goto LAB_0011d6a2;
        goto LAB_0011d6b9;
      }
    }
  }
  pvVar8 = *(void **)param_1[0x27];
  *(void **)param_1[0x28] = pvVar18;
  *(ulong *)param_1[0x29] = uVar19;
  *(void **)param_1[0x27] = pvVar18;
  *(void **)(param_1[0x27] + 8) = pvVar18;
  if (pvVar8 != (void *)0x0) {
    operator_delete__(pvVar8);
  }
LAB_0011c682:
  lVar41 = param_2[3];
  if (lVar41 == 0) {
    local_218 = 0;
    pvVar18 = (void *)0x0;
  }
  else {
    pvVar18 = operator_new__(lVar41 * 4,(nothrow_t *)PTR_nothrow_00132fb8);
    lVar48 = param_2[3];
    local_218 = lVar41;
    if (lVar48 != 0) {
      lVar21 = param_2[2];
      puVar27 = (undefined4 *)(lVar21 + 0xc);
      do {
        uVar49 = *puVar27;
        puVar34 = puVar27 + 1;
        puVar27 = puVar27 + 6;
        *(undefined4 *)((long)pvVar18 + (ulong)*puVar34 * 4) = uVar49;
      } while (puVar27 != (undefined4 *)(lVar21 + 0xc + lVar48 * 0x18));
    }
  }
  pvVar8 = (void *)*param_3;
  *param_3 = pvVar18;
  param_3[1] = pvVar18;
  param_3[2] = pvVar18;
  *(undefined1 *)(param_3 + 5) = 0;
  param_3[3] = lVar41;
  param_3[4] = local_218;
  if (pvVar8 != (void *)0x0) {
    operator_delete__(pvVar8);
  }
  param_2[2] = local_1f8;
  pvVar18 = (void *)*param_2;
  param_2[3] = uVar37;
  param_2[4] = local_1f0;
  *(undefined1 *)(param_2 + 5) = 0;
  *param_2 = local_1f8;
  param_2[1] = local_1f8;
  if (pauVar23 != (undefined1 (*) [16])0x0) {
    operator_delete__(pauVar23);
  }
  pvVar8 = local_168;
  if (local_168 != (void *)0x0) {
    puVar24 = (undefined8 *)(local_128._8_8_ + 8);
    for (puVar25 = puStack_140; puVar25 < puVar24; puVar25 = puVar25 + 1) {
      operator_delete((void *)*puVar25);
    }
    operator_delete(pvVar8);
  }
  if (pvVar18 == (void *)0x0) {
    if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
  else if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    operator_delete__(pvVar18);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_0011dc10 @ 0011dc10 size=9122 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0011dc10(undefined1 (*param_1) [16],undefined8 *param_2,undefined8 *param_3,long param_4,
                 long param_5)

{
  ulong *puVar1;
  long *plVar2;
  char *pcVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  void *pvVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined1 auVar13 [16];
  undefined *puVar14;
  undefined1 uVar15;
  long lVar16;
  undefined8 uVar17;
  void *pvVar18;
  ulong uVar19;
  ulong uVar20;
  undefined1 (*__dest) [16];
  undefined8 *puVar21;
  undefined8 *puVar22;
  undefined8 *puVar23;
  undefined4 *puVar24;
  undefined1 (*pauVar25) [16];
  undefined1 (*pauVar26) [16];
  undefined1 (*pauVar27) [16];
  ulong uVar28;
  long *plVar29;
  ulong uVar30;
  undefined8 *puVar31;
  ulong uVar32;
  uint *puVar33;
  ulong uVar34;
  ulong uVar35;
  ulong uVar36;
  ulong uVar37;
  long lVar38;
  long in_FS_OFFSET;
  long lVar39;
  long lVar46;
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  undefined1 auVar45 [16];
  undefined4 uVar47;
  float fVar48;
  ulong local_210;
  ulong local_208;
  ulong local_1f8;
  undefined8 *local_1e8;
  ulong local_1e0;
  void *local_168;
  undefined8 local_160;
  uint *local_158;
  uint *puStack_150;
  uint *local_148;
  undefined8 *puStack_140;
  undefined1 local_138 [16];
  undefined1 local_128 [16];
  undefined1 local_118 [16];
  undefined8 local_108;
  undefined1 local_100 [16];
  undefined8 local_f0;
  undefined1 local_e8 [16];
  undefined1 local_d8 [16];
  undefined8 local_c8;
  undefined1 local_c0 [16];
  undefined8 local_b0;
  undefined1 local_a8 [16];
  undefined8 local_98;
  undefined1 local_90 [16];
  undefined8 local_80;
  undefined1 local_78 [16];
  undefined8 local_68;
  undefined1 local_60 [16];
  undefined8 local_50;
  long local_40;
  
  lVar39 = param_2[1];
  lVar46 = param_2[3];
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar16 = 0;
  lVar38 = lVar39;
  if (lVar46 != 0) {
    puVar24 = (undefined4 *)(lVar39 + 0x10);
    do {
      *puVar24 = (int)lVar16;
      lVar16 = lVar16 + 1;
      puVar24 = puVar24 + 6;
    } while (lVar16 != lVar46);
    lVar38 = lVar39 + lVar16 * 0x18;
  }
  uVar17 = FUN_0011ace0(lVar39,lVar38,0);
  FUN_00113860(param_1,param_4,param_5,uVar17);
  uVar35 = *(ulong *)param_1[3];
  if (uVar35 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_00106868();
  }
  uVar19 = *(ulong *)(param_1[1] + 8);
  if (uVar35 == uVar19 << 6) {
    uVar34 = *(ulong *)param_1[2];
    uVar35 = uVar19 + 1;
    if (uVar34 < uVar35) {
      if (uVar35 >> 1 < uVar34) {
        uVar19 = 0xfffffffffffffff8;
        uVar20 = 0x1fffffffffffffff;
        if (uVar34 >> 0x3c == 0) {
          uVar20 = uVar34 * 2;
          uVar19 = uVar34 << 4;
        }
      }
      else {
        uVar19 = uVar35 * 8;
        uVar20 = uVar35;
      }
      pvVar18 = operator_new__(uVar19,(nothrow_t *)PTR_nothrow_00132fb8);
      uVar19 = *(ulong *)(param_1[1] + 8);
      if (uVar19 != 0) {
        lVar39 = *(long *)(*param_1 + 8);
        if ((pvVar18 == (void *)(lVar39 + 8)) || (uVar19 - 1 < 3)) {
          uVar34 = 0;
          do {
            *(undefined8 *)((long)pvVar18 + uVar34 * 8) = *(undefined8 *)(lVar39 + uVar34 * 8);
            uVar34 = uVar34 + 1;
          } while (uVar34 != uVar19);
        }
        else {
          lVar46 = 0;
          do {
            *(undefined1 (*) [16])((long)pvVar18 + lVar46) = *(undefined1 (*) [16])(lVar39 + lVar46)
            ;
            lVar46 = lVar46 + 0x10;
          } while ((uVar19 >> 1) * 0x10 != lVar46);
          if ((uVar19 & 1) != 0) {
            *(undefined8 *)((long)pvVar18 + (uVar19 & 0xfffffffffffffffe) * 8) =
                 *(undefined8 *)(lVar39 + (uVar19 & 0xfffffffffffffffe) * 8);
          }
        }
      }
      pvVar8 = *(void **)*param_1;
      *(void **)param_1[1] = pvVar18;
      *(ulong *)param_1[2] = uVar20;
      *(void **)*param_1 = pvVar18;
      *(void **)(*param_1 + 8) = pvVar18;
      if (pvVar8 != (void *)0x0) {
        operator_delete__(pvVar8);
        uVar19 = *(ulong *)(param_1[1] + 8);
        goto LAB_0011f81c;
      }
    }
    else {
LAB_0011f81c:
      pvVar18 = *(void **)(*param_1 + 8);
    }
    if (uVar19 < uVar35) {
      memset((void *)((long)pvVar18 + uVar19 * 8),0,(uVar35 - uVar19) * 8);
    }
    *(ulong *)(param_1[1] + 8) = uVar35;
    uVar35 = *(ulong *)param_1[3];
  }
  else {
    pvVar18 = *(void **)(*param_1 + 8);
  }
  puVar1 = (ulong *)((long)pvVar18 + (uVar35 >> 6) * 8);
  *puVar1 = *puVar1 | 1L << ((byte)uVar35 & 0x3f);
  lVar39 = *(long *)param_1[3] + _DAT_0012a660;
  lVar46 = *(long *)(param_1[3] + 8) + _UNK_0012a668;
  *(long *)param_1[3] = lVar39;
  *(long *)(param_1[3] + 8) = lVar46;
  if (lVar39 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_00106868();
  }
  uVar35 = *(ulong *)(param_1[1] + 8);
  if (uVar35 << 6 == lVar39) {
    uVar34 = *(ulong *)param_1[2];
    uVar19 = uVar35 + 1;
    if (uVar34 < uVar19) {
      if (uVar19 >> 1 < uVar34) {
        uVar35 = 0xfffffffffffffff8;
        uVar20 = 0x1fffffffffffffff;
        if (uVar34 >> 0x3c == 0) {
          uVar20 = uVar34 * 2;
          uVar35 = uVar34 << 4;
        }
      }
      else {
        uVar35 = uVar19 * 8;
        uVar20 = uVar19;
      }
      pvVar18 = operator_new__(uVar35,(nothrow_t *)PTR_nothrow_00132fb8);
      uVar35 = *(ulong *)(param_1[1] + 8);
      if (uVar35 != 0) {
        lVar39 = *(long *)(*param_1 + 8);
        if ((pvVar18 == (void *)(lVar39 + 8)) || (uVar35 - 1 < 3)) {
          uVar34 = 0;
          do {
            *(undefined8 *)((long)pvVar18 + uVar34 * 8) = *(undefined8 *)(lVar39 + uVar34 * 8);
            uVar34 = uVar34 + 1;
          } while (uVar35 != uVar34);
        }
        else {
          lVar46 = 0;
          do {
            puVar24 = (undefined4 *)(lVar39 + lVar46);
            uVar47 = puVar24[1];
            uVar11 = puVar24[2];
            uVar12 = puVar24[3];
            puVar4 = (undefined4 *)((long)pvVar18 + lVar46);
            *puVar4 = *puVar24;
            puVar4[1] = uVar47;
            puVar4[2] = uVar11;
            puVar4[3] = uVar12;
            lVar46 = lVar46 + 0x10;
          } while ((uVar35 >> 1) * 0x10 != lVar46);
          if ((uVar35 & 1) != 0) {
            *(undefined8 *)((long)pvVar18 + (uVar35 & 0xfffffffffffffffe) * 8) =
                 *(undefined8 *)(lVar39 + (uVar35 & 0xfffffffffffffffe) * 8);
          }
        }
      }
      pvVar8 = *(void **)*param_1;
      *(void **)param_1[1] = pvVar18;
      *(ulong *)param_1[2] = uVar20;
      *(void **)*param_1 = pvVar18;
      *(void **)(*param_1 + 8) = pvVar18;
      if (pvVar8 != (void *)0x0) {
        operator_delete__(pvVar8);
        uVar35 = *(ulong *)(param_1[1] + 8);
      }
    }
    if (uVar35 < uVar19) {
      memset((void *)(*(long *)(*param_1 + 8) + uVar35 * 8),0,(uVar19 - uVar35) * 8);
    }
    *(ulong *)(param_1[1] + 8) = uVar19;
    lVar39 = *(long *)param_1[3];
  }
  uVar19 = *(ulong *)param_1[0x29];
  *(long *)param_1[3] = lVar39 + 1;
  uVar34 = *(ulong *)(param_1[0x28] + 8);
  uVar35 = uVar34 + 1;
  if (uVar19 < uVar35) {
    if ((uVar35 >> 1 < uVar19) && (uVar35 = uVar19 * 2, (long)uVar19 < 0)) {
      uVar35 = 0xffffffffffffffff;
    }
    pvVar18 = operator_new__(uVar35,(nothrow_t *)PTR_nothrow_00132fb8);
    uVar34 = *(ulong *)(param_1[0x28] + 8);
    if (uVar34 != 0) {
      lVar39 = *(long *)(param_1[0x27] + 8);
      if (((ulong)((long)pvVar18 - (lVar39 + 1)) < 0xf) || (uVar34 - 1 < 7)) {
        uVar19 = 0;
        do {
          *(undefined1 *)((long)pvVar18 + uVar19) = *(undefined1 *)(lVar39 + uVar19);
          uVar19 = uVar19 + 1;
        } while (uVar19 != uVar34);
      }
      else if (uVar34 - 1 < 0xf) {
        uVar20 = 0;
        uVar19 = uVar34;
LAB_0011dde6:
        *(undefined8 *)((long)pvVar18 + uVar20) = *(undefined8 *)(lVar39 + uVar20);
        uVar20 = uVar20 + (uVar19 & 0xfffffffffffffff8);
        if ((uVar19 & 0xfffffffffffffff8) != uVar19) {
LAB_0011ddfd:
          *(undefined1 *)((long)pvVar18 + uVar20) = *(undefined1 *)(lVar39 + uVar20);
          if ((((uVar20 + 1 < uVar34) &&
               (*(undefined1 *)((long)pvVar18 + uVar20 + 1) = *(undefined1 *)(lVar39 + 1 + uVar20),
               uVar20 + 2 < uVar34)) &&
              (*(undefined1 *)((long)pvVar18 + uVar20 + 2) = *(undefined1 *)(lVar39 + 2 + uVar20),
              uVar20 + 3 < uVar34)) &&
             (((*(undefined1 *)((long)pvVar18 + uVar20 + 3) = *(undefined1 *)(lVar39 + 3 + uVar20),
               uVar20 + 4 < uVar34 &&
               (*(undefined1 *)((long)pvVar18 + uVar20 + 4) = *(undefined1 *)(lVar39 + 4 + uVar20),
               uVar20 + 5 < uVar34)) &&
              (*(undefined1 *)((long)pvVar18 + uVar20 + 5) = *(undefined1 *)(lVar39 + 5 + uVar20),
              uVar20 + 6 < uVar34)))) {
            *(undefined1 *)((long)pvVar18 + uVar20 + 6) = *(undefined1 *)(lVar39 + 6 + uVar20);
          }
        }
      }
      else {
        uVar19 = 0;
        do {
          *(undefined1 (*) [16])((long)pvVar18 + uVar19) = *(undefined1 (*) [16])(lVar39 + uVar19);
          uVar19 = uVar19 + 0x10;
        } while ((uVar34 & 0xfffffffffffffff0) != uVar19);
        uVar20 = uVar34 & 0xfffffffffffffff0;
        if ((uVar34 & 0xf) != 0) {
          uVar19 = uVar34 - uVar20;
          if (6 < (uVar34 - uVar20) - 1) goto LAB_0011dde6;
          goto LAB_0011ddfd;
        }
      }
    }
    pvVar8 = *(void **)param_1[0x27];
    *(void **)param_1[0x28] = pvVar18;
    *(ulong *)param_1[0x29] = uVar35;
    *(void **)param_1[0x27] = pvVar18;
    *(void **)(param_1[0x27] + 8) = pvVar18;
    if (pvVar8 != (void *)0x0) {
      operator_delete__(pvVar8);
      pvVar18 = *(void **)(param_1[0x27] + 8);
      uVar34 = *(ulong *)(param_1[0x28] + 8);
    }
  }
  else {
    pvVar18 = *(void **)(param_1[0x27] + 8);
  }
  *(undefined1 *)((long)pvVar18 + uVar34) = 0;
  lVar39 = *(long *)param_1[0x1d];
  *(long *)(param_1[0x28] + 8) = *(long *)(param_1[0x28] + 8) + 1;
  if (lVar39 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_00106868();
  }
  uVar35 = *(ulong *)(param_1[0x1b] + 8);
  if (lVar39 == uVar35 << 6) {
    uVar34 = *(ulong *)param_1[0x1c];
    uVar19 = uVar35 + 1;
    if (uVar34 < uVar19) {
      if (uVar19 >> 1 < uVar34) {
        uVar35 = 0xfffffffffffffff8;
        uVar20 = 0x1fffffffffffffff;
        if (uVar34 >> 0x3c == 0) {
          uVar20 = uVar34 * 2;
          uVar35 = uVar34 << 4;
        }
      }
      else {
        uVar35 = uVar19 * 8;
        uVar20 = uVar19;
      }
      pvVar18 = operator_new__(uVar35,(nothrow_t *)PTR_nothrow_00132fb8);
      uVar35 = *(ulong *)(param_1[0x1b] + 8);
      if (uVar35 != 0) {
        lVar39 = *(long *)(param_1[0x1a] + 8);
        if ((pvVar18 == (void *)(lVar39 + 8)) || (uVar35 - 1 < 3)) {
          uVar34 = 0;
          do {
            *(undefined8 *)((long)pvVar18 + uVar34 * 8) = *(undefined8 *)(lVar39 + uVar34 * 8);
            uVar34 = uVar34 + 1;
          } while (uVar34 != uVar35);
        }
        else {
          lVar46 = 0;
          do {
            puVar24 = (undefined4 *)(lVar39 + lVar46);
            uVar47 = puVar24[1];
            uVar11 = puVar24[2];
            uVar12 = puVar24[3];
            puVar4 = (undefined4 *)((long)pvVar18 + lVar46);
            *puVar4 = *puVar24;
            puVar4[1] = uVar47;
            puVar4[2] = uVar11;
            puVar4[3] = uVar12;
            lVar46 = lVar46 + 0x10;
          } while ((uVar35 >> 1) * 0x10 != lVar46);
          if ((uVar35 & 1) != 0) {
            *(undefined8 *)((long)pvVar18 + (uVar35 & 0xfffffffffffffffe) * 8) =
                 *(undefined8 *)(lVar39 + (uVar35 & 0xfffffffffffffffe) * 8);
          }
        }
      }
      pvVar8 = *(void **)param_1[0x1a];
      *(void **)param_1[0x1b] = pvVar18;
      *(ulong *)param_1[0x1c] = uVar20;
      *(void **)param_1[0x1a] = pvVar18;
      *(void **)(param_1[0x1a] + 8) = pvVar18;
      if (pvVar8 != (void *)0x0) {
        operator_delete__(pvVar8);
        uVar35 = *(ulong *)(param_1[0x1b] + 8);
      }
    }
    if (uVar35 < uVar19) {
      memset((void *)(*(long *)(param_1[0x1a] + 8) + uVar35 * 8),0,(uVar19 - uVar35) * 8);
    }
    *(ulong *)(param_1[0x1b] + 8) = uVar19;
    lVar39 = *(long *)param_1[0x1d];
  }
  *(long *)param_1[0x1d] = lVar39 + 1;
  local_168 = (void *)0x0;
  local_160 = 0;
  local_158 = (uint *)0x0;
  puStack_150 = (uint *)0x0;
  local_148 = (uint *)0x0;
  puStack_140 = (undefined8 *)0x0;
  local_138 = (undefined1  [16])0x0;
  local_128 = (undefined1  [16])0x0;
  FUN_0011a400(&local_168,0);
  auVar13 = local_118;
  local_118._0_8_ = local_118._4_8_ << 0x20;
  local_118._12_4_ = auVar13._12_4_;
  local_118._8_4_ = 0;
  auVar13._4_8_ = local_118._8_8_;
  auVar13._0_4_ = (int)param_2[3];
  auVar13._12_4_ = 0;
  local_118 = auVar13 << 0x20;
  FUN_0011b600(&local_168);
  if ((uint *)local_138._0_8_ == local_158) {
    local_1e0 = 0;
    lVar39 = *(long *)param_1[3];
    __dest = (undefined1 (*) [16])0x0;
    local_208 = 0;
    local_1e8 = (undefined8 *)0x0;
  }
  else {
    local_1e0 = 0;
    __dest = (undefined1 (*) [16])0x0;
    local_208 = 0;
    local_1e8 = (undefined8 *)0x0;
    puVar33 = local_158;
    do {
      puVar21 = puStack_140;
      uVar35 = (ulong)*puVar33;
      uVar5 = puVar33[2];
      lVar46 = *(long *)param_1[0x1d] -
               (((long)local_148 - (long)puVar33 >> 2) * -0x5555555555555555 +
               ((long)(local_138._0_8_ - local_138._8_8_) >> 2) * -0x5555555555555555 +
               ((local_128._8_8_ - (long)puStack_140 >> 3) + -1 + (ulong)(local_128._8_8_ == 0)) *
               0x2a);
      uVar6 = puVar33[1];
      if (puVar33 == local_148 + -3) {
        operator_delete(puStack_150);
        puVar33 = (uint *)puVar21[1];
        puStack_140 = puVar21 + 1;
        local_148 = puVar33 + 0x7e;
        puStack_150 = puVar33;
      }
      else {
        puVar33 = puVar33 + 3;
      }
      uVar19 = (ulong)uVar6;
      local_158 = puVar33;
      if (uVar35 < uVar19) {
        lVar39 = param_2[1];
        do {
          lVar38 = uVar35 * 0x18;
          if (uVar5 != *(uint *)(lVar39 + lVar38 + 8)) goto LAB_0011e0a5;
          uVar35 = (ulong)((int)uVar35 + 1);
          *(int *)(lVar39 + lVar38 + 0xc) = (int)lVar46;
        } while (uVar35 < uVar19);
      }
      if (uVar19 == uVar35) {
        lVar39 = *(long *)param_1[3];
        if (lVar39 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
          FUN_00106868();
        }
        uVar35 = *(ulong *)(param_1[1] + 8);
        if (lVar39 == uVar35 << 6) {
          uVar34 = *(ulong *)param_1[2];
          uVar19 = uVar35 + 1;
          if (uVar34 < uVar19) {
            if (uVar19 >> 1 < uVar34) {
              uVar35 = 0xfffffffffffffff8;
              uVar20 = 0x1fffffffffffffff;
              if (uVar34 < 0x1000000000000000) {
                uVar35 = uVar34 << 4;
                uVar20 = uVar34 * 2;
              }
            }
            else {
              uVar35 = uVar19 * 8;
              uVar20 = uVar19;
            }
            pvVar18 = operator_new__(uVar35,(nothrow_t *)PTR_nothrow_00132fb8);
            uVar35 = *(ulong *)(param_1[1] + 8);
            auVar45._8_8_ = pvVar18;
            auVar45._0_8_ = pvVar18;
            if (uVar35 != 0) {
              lVar39 = *(long *)(*param_1 + 8);
              if ((pvVar18 == (void *)(lVar39 + 8)) || (uVar35 - 1 < 3)) {
                uVar34 = 0;
                do {
                  *(undefined8 *)((long)pvVar18 + uVar34 * 8) = *(undefined8 *)(lVar39 + uVar34 * 8)
                  ;
                  uVar34 = uVar34 + 1;
                } while (uVar35 != uVar34);
              }
              else {
                lVar46 = 0;
                do {
                  *(undefined1 (*) [16])((long)pvVar18 + lVar46) =
                       *(undefined1 (*) [16])(lVar39 + lVar46);
                  lVar46 = lVar46 + 0x10;
                } while ((uVar35 >> 1) * 0x10 != lVar46);
                if ((uVar35 & 1) != 0) {
                  *(undefined8 *)((long)pvVar18 + (uVar35 & 0xfffffffffffffffe) * 8) =
                       *(undefined8 *)(lVar39 + (uVar35 & 0xfffffffffffffffe) * 8);
                }
              }
            }
            *(void **)param_1[1] = pvVar18;
            *(ulong *)param_1[2] = uVar20;
            *param_1 = auVar45;
            if (*(void **)*param_1 != (void *)0x0) {
              operator_delete__(*(void **)*param_1);
              uVar35 = *(ulong *)(param_1[1] + 8);
            }
          }
          if (uVar35 < uVar19) {
            memset((void *)(*(long *)(*param_1 + 8) + uVar35 * 8),0,(uVar19 - uVar35) * 8);
          }
          *(ulong *)(param_1[1] + 8) = uVar19;
          lVar39 = *(long *)param_1[3];
        }
        lVar39 = lVar39 + 1;
        *(long *)param_1[3] = lVar39;
      }
      else {
        lVar38 = uVar35 * 0x18;
LAB_0011e0a5:
        uVar47 = (undefined4)uVar35;
        if (__dest != (undefined1 (*) [16])0x0) {
          operator_delete__(__dest);
        }
        uVar34 = uVar35 + 1;
        lVar39 = param_2[1];
        fVar48 = *(float *)(lVar39 + 0xc + lVar38);
        auVar40._0_8_ = (double)fVar48;
        auVar40._8_8_ = 0;
        if (uVar34 < uVar19) {
          lVar38 = uVar35 * 0x18;
          uVar28 = 0;
          pauVar25 = (undefined1 (*) [16])0x0;
          uVar37 = 0;
          do {
            plVar2 = (long *)(lVar39 + lVar38);
            lVar38 = lVar38 + 0x18;
            plVar29 = (long *)(lVar39 + lVar38);
            uVar36 = uVar28 * 0x10;
            uVar20 = uVar28;
            uVar30 = uVar36;
            __dest = pauVar25;
            uVar32 = uVar37;
            if (*(char *)(*plVar29 + -(ulong)uVar5) != *(char *)(*plVar2 + -(ulong)uVar5)) {
              uVar20 = uVar28 + 1;
              uVar47 = (undefined4)uVar35;
              uVar30 = uVar36 + 0x10;
              if (uVar37 < uVar20) {
                uVar35 = uVar30;
                uVar32 = uVar20;
                if (uVar20 >> 1 < uVar37) {
                  if (uVar37 < 0x800000000000000) {
                    uVar35 = uVar37 << 5;
                    uVar32 = uVar37 * 2;
                  }
                  else {
                    uVar35 = 0xfffffffffffffff0;
                    uVar32 = 0xfffffffffffffff;
                  }
                }
                __dest = operator_new__(uVar35,(nothrow_t *)PTR_nothrow_00132fb8);
                uVar35 = 0;
                if (uVar28 == 0) {
                  if (pauVar25 == (undefined1 (*) [16])0x0) {
                    lVar39 = param_2[1];
                    plVar29 = (long *)(lVar39 + lVar38);
                    goto LAB_0011e269;
                  }
                }
                else {
                  do {
                    uVar17 = *(undefined8 *)((long)(*pauVar25 + uVar35) + 8);
                    *(undefined8 *)(*__dest + uVar35) = *(undefined8 *)(*pauVar25 + uVar35);
                    *(undefined8 *)((long)(*__dest + uVar35) + 8) = uVar17;
                    uVar35 = uVar35 + 0x10;
                  } while (uVar35 != uVar36);
                }
                operator_delete__(pauVar25);
                lVar39 = param_2[1];
                plVar29 = (long *)(lVar39 + lVar38);
              }
LAB_0011e269:
              pauVar25 = __dest + uVar28;
              *(float *)(*pauVar25 + 0xc) = (float)auVar40._0_8_;
              auVar40 = (undefined1  [16])0x0;
              *(uint *)(*pauVar25 + 8) = uVar5;
              uVar35 = uVar34 & 0xffffffff;
              *(ulong *)*pauVar25 = CONCAT44((int)uVar34,uVar47);
            }
            uVar47 = (undefined4)uVar35;
            uVar34 = uVar34 + 1;
            auVar40._0_8_ = auVar40._0_8_ + (double)*(float *)((long)plVar29 + 0xc);
            uVar28 = uVar20;
            pauVar25 = __dest;
            uVar37 = uVar32;
          } while (uVar34 < uVar19);
          local_1f8 = uVar20 + 1;
          fVar48 = (float)auVar40._0_8_;
          if (uVar32 < local_1f8) {
            if (uVar32 <= local_1f8 >> 1) goto LAB_0011f361;
            if (uVar32 >> 0x3b == 0) {
              uVar32 = uVar32 << 5;
            }
            else {
              uVar32 = 0xfffffffffffffff0;
            }
            goto LAB_0011e2fc;
          }
        }
        else {
          local_1f8 = 1;
          uVar30 = 0;
          __dest = (undefined1 (*) [16])0x0;
          uVar20 = 0;
LAB_0011f361:
          uVar32 = local_1f8 << 4;
          pauVar25 = __dest;
LAB_0011e2fc:
          __dest = operator_new__(uVar32,(nothrow_t *)PTR_nothrow_00132fb8);
          if (uVar20 == 0) {
            if (pauVar25 == (undefined1 (*) [16])0x0) goto LAB_0011e356;
          }
          else {
            memcpy(__dest,pauVar25,uVar20 << 4);
          }
          operator_delete__(pauVar25);
        }
LAB_0011e356:
        puVar21 = (undefined8 *)(*__dest + uVar30);
        *(uint *)(puVar21 + 1) = uVar5;
        iVar7 = *(int *)(param_4 + 0x10);
        *puVar21 = CONCAT44(uVar6,uVar47);
        *(float *)((long)puVar21 + 0xc) = fVar48;
        puVar14 = PTR_nothrow_00132fb8;
        if (iVar7 == 0x20000) {
          if (__dest + local_1f8 != __dest) {
            lVar39 = ((long)(local_1f8 * 0x10) >> 4) + 1;
            lVar39 = lVar39 - (lVar39 >> 0x3f);
            if ((long)(local_1f8 * 0x10) < 1) {
LAB_0011f84c:
              pauVar25 = (undefined1 (*) [16])0x0;
              FUN_00111d60(__dest);
            }
            else {
              while( true ) {
                lVar39 = lVar39 >> 1;
                pauVar25 = operator_new(lVar39 * 0x10,(nothrow_t *)puVar14);
                if (pauVar25 != (undefined1 (*) [16])0x0) break;
                if (lVar39 == 1) goto LAB_0011f84c;
                lVar39 = lVar39 + 1;
              }
              uVar17 = *(undefined8 *)(*__dest + 8);
              *(undefined8 *)*pauVar25 = *(undefined8 *)*__dest;
              *(undefined8 *)(*pauVar25 + 8) = uVar17;
              pauVar27 = pauVar25;
              pauVar26 = pauVar25 + 1;
              if (pauVar25 + lVar39 != pauVar25 + 1) {
                do {
                  uVar47 = *(undefined4 *)(pauVar26[-1] + 4);
                  uVar11 = *(undefined4 *)(pauVar26[-1] + 8);
                  uVar12 = *(undefined4 *)(pauVar26[-1] + 0xc);
                  pauVar27 = pauVar26 + 1;
                  *(undefined4 *)*pauVar26 = *(undefined4 *)pauVar26[-1];
                  *(undefined4 *)(*pauVar26 + 4) = uVar47;
                  *(undefined4 *)(*pauVar26 + 8) = uVar11;
                  *(undefined4 *)(*pauVar26 + 0xc) = uVar12;
                  pauVar26 = pauVar27;
                } while (pauVar25 + lVar39 != pauVar27);
                pauVar27 = pauVar25 + lVar39 + -1;
              }
              *__dest = *pauVar27;
              FUN_00117550(__dest,__dest + local_1f8,pauVar25,lVar39);
            }
            operator_delete(pauVar25);
          }
        }
        if (lVar46 == 0) {
          *(ulong *)(param_1[0x42] + 8) = local_1f8;
        }
        if (local_1f8 == 0) {
          lVar39 = *(long *)param_1[3];
        }
        else {
          local_210 = 0;
          pauVar25 = __dest;
          do {
            uVar35 = (ulong)*(uint *)(*pauVar25 + 8) + 1;
            plVar2 = (long *)(param_2[1] + (ulong)*(uint *)*pauVar25 * 0x18);
            if (uVar35 < *(uint *)(plVar2 + 1)) {
              uVar19 = (ulong)*(uint *)*pauVar25 + 1;
              do {
                if (uVar19 < *(uint *)(*pauVar25 + 4)) {
                  lVar39 = *plVar2;
                  uVar34 = uVar19;
                  plVar29 = (long *)(param_2[1] + uVar19 * 0x18);
                  do {
                    pcVar3 = (char *)(lVar39 + -uVar35);
                    lVar39 = *plVar29;
                    if (*(char *)(lVar39 + -uVar35) != *pcVar3) goto LAB_0011e43e;
                    uVar34 = uVar34 + 1;
                    plVar29 = plVar29 + 3;
                  } while (uVar34 < *(uint *)(*pauVar25 + 4));
                }
                uVar35 = uVar35 + 1;
              } while (uVar35 < *(uint *)(plVar2 + 1));
            }
LAB_0011e43e:
            FUN_00113a00(param_1,lVar46,*(undefined8 *)(param_1[0x28] + 8),
                         (int)*(char *)(*plVar2 - (ulong)*(uint *)(*pauVar25 + 8)));
            uVar20 = *(ulong *)(param_1[0x28] + 8);
            uVar34 = *(ulong *)param_1[0x29];
            uVar19 = uVar20 + 1;
            if ((ulong)*(uint *)(*pauVar25 + 8) + 1 == uVar35) {
              uVar15 = *(undefined1 *)
                        (*(long *)((ulong)*(uint *)*pauVar25 * 0x18 + param_2[1]) -
                        (ulong)*(uint *)(*pauVar25 + 8));
              if (uVar34 < uVar19) {
                if ((uVar19 >> 1 < uVar34) && (uVar19 = uVar34 * 2, (long)uVar34 < 0)) {
                  uVar19 = 0xffffffffffffffff;
                }
                pvVar18 = operator_new__(uVar19,(nothrow_t *)PTR_nothrow_00132fb8);
                uVar20 = *(ulong *)(param_1[0x28] + 8);
                auVar41._8_8_ = pvVar18;
                auVar41._0_8_ = pvVar18;
                if (uVar20 != 0) {
                  lVar39 = *(long *)(param_1[0x27] + 8);
                  if (((ulong)((long)pvVar18 - (lVar39 + 1)) < 0xf) || (uVar20 - 1 < 7)) {
                    uVar34 = 0;
                    do {
                      *(undefined1 *)((long)pvVar18 + uVar34) = *(undefined1 *)(lVar39 + uVar34);
                      uVar34 = uVar34 + 1;
                    } while (uVar20 != uVar34);
                  }
                  else if (uVar20 - 1 < 0xf) {
                    uVar30 = 0;
                    uVar34 = uVar20;
LAB_0011edd1:
                    *(undefined8 *)((long)pvVar18 + uVar30) = *(undefined8 *)(lVar39 + uVar30);
                    uVar30 = uVar30 + (uVar34 & 0xfffffffffffffff8);
                    if (uVar34 != (uVar34 & 0xfffffffffffffff8)) {
LAB_0011ede8:
                      *(undefined1 *)((long)pvVar18 + uVar30) = *(undefined1 *)(lVar39 + uVar30);
                      if (((((uVar30 + 1 < uVar20) &&
                            (*(undefined1 *)((long)pvVar18 + uVar30 + 1) =
                                  *(undefined1 *)(lVar39 + 1 + uVar30), uVar30 + 2 < uVar20)) &&
                           (*(undefined1 *)((long)pvVar18 + uVar30 + 2) =
                                 *(undefined1 *)(lVar39 + 2 + uVar30), uVar30 + 3 < uVar20)) &&
                          ((*(undefined1 *)((long)pvVar18 + uVar30 + 3) =
                                 *(undefined1 *)(lVar39 + 3 + uVar30), uVar30 + 4 < uVar20 &&
                           (*(undefined1 *)((long)pvVar18 + uVar30 + 4) =
                                 *(undefined1 *)(lVar39 + 4 + uVar30), uVar30 + 5 < uVar20)))) &&
                         (*(undefined1 *)((long)pvVar18 + uVar30 + 5) =
                               *(undefined1 *)(lVar39 + 5 + uVar30), uVar30 + 6 < uVar20)) {
                        *(undefined1 *)((long)pvVar18 + uVar30 + 6) =
                             *(undefined1 *)(lVar39 + 6 + uVar30);
                      }
                    }
                  }
                  else {
                    uVar34 = 0;
                    do {
                      uVar17 = ((undefined8 *)(lVar39 + uVar34))[1];
                      *(undefined8 *)((long)pvVar18 + uVar34) = *(undefined8 *)(lVar39 + uVar34);
                      ((undefined8 *)((long)pvVar18 + uVar34))[1] = uVar17;
                      uVar34 = uVar34 + 0x10;
                    } while ((uVar20 & 0xfffffffffffffff0) != uVar34);
                    uVar30 = uVar20 & 0xfffffffffffffff0;
                    if ((uVar20 & 0xf) != 0) {
                      uVar34 = uVar20 - uVar30;
                      if (6 < (uVar20 - uVar30) - 1) goto LAB_0011edd1;
                      goto LAB_0011ede8;
                    }
                  }
                }
                pvVar8 = *(void **)param_1[0x27];
                *(void **)param_1[0x28] = pvVar18;
                *(ulong *)param_1[0x29] = uVar19;
                param_1[0x27] = auVar41;
                if (pvVar8 != (void *)0x0) {
                  operator_delete__(pvVar8);
                  pvVar18 = *(void **)(param_1[0x27] + 8);
                  uVar20 = *(ulong *)(param_1[0x28] + 8);
                }
              }
              else {
                pvVar18 = *(void **)(param_1[0x27] + 8);
              }
              *(undefined1 *)((long)pvVar18 + uVar20) = uVar15;
              lVar39 = *(long *)param_1[0x1d];
              *(long *)(param_1[0x28] + 8) = *(long *)(param_1[0x28] + 8) + 1;
              if (lVar39 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
                FUN_00106868();
              }
              uVar19 = *(ulong *)(param_1[0x1b] + 8);
              if (lVar39 == uVar19 << 6) {
                uVar20 = *(ulong *)param_1[0x1c];
                uVar34 = uVar19 + 1;
                if (uVar20 < uVar34) {
                  if (uVar34 >> 1 < uVar20) {
                    uVar19 = 0xfffffffffffffff8;
                    uVar30 = 0x1fffffffffffffff;
                    if (uVar20 < 0x1000000000000000) {
                      uVar30 = uVar20 * 2;
                      uVar19 = uVar20 << 4;
                    }
                  }
                  else {
                    uVar19 = uVar34 * 8;
                    uVar30 = uVar34;
                  }
                  pvVar18 = operator_new__(uVar19,(nothrow_t *)PTR_nothrow_00132fb8);
                  uVar19 = *(ulong *)(param_1[0x1b] + 8);
                  auVar43._8_8_ = pvVar18;
                  auVar43._0_8_ = pvVar18;
                  if (uVar19 != 0) {
                    lVar39 = *(long *)(param_1[0x1a] + 8);
                    if ((pvVar18 == (void *)(lVar39 + 8)) || (uVar19 - 1 < 3)) {
                      uVar20 = 0;
                      do {
                        *(undefined8 *)((long)pvVar18 + uVar20 * 8) =
                             *(undefined8 *)(lVar39 + uVar20 * 8);
                        uVar20 = uVar20 + 1;
                      } while (uVar19 != uVar20);
                    }
                    else {
                      lVar38 = 0;
                      do {
                        puVar24 = (undefined4 *)(lVar39 + lVar38);
                        uVar47 = puVar24[1];
                        uVar11 = puVar24[2];
                        uVar12 = puVar24[3];
                        puVar4 = (undefined4 *)((long)pvVar18 + lVar38);
                        *puVar4 = *puVar24;
                        puVar4[1] = uVar47;
                        puVar4[2] = uVar11;
                        puVar4[3] = uVar12;
                        lVar38 = lVar38 + 0x10;
                      } while ((uVar19 >> 1) * 0x10 != lVar38);
                      if ((uVar19 & 1) != 0) {
                        *(undefined8 *)((long)pvVar18 + (uVar19 & 0xfffffffffffffffe) * 8) =
                             *(undefined8 *)(lVar39 + (uVar19 & 0xfffffffffffffffe) * 8);
                      }
                    }
                  }
                  pvVar8 = *(void **)param_1[0x1a];
                  *(void **)param_1[0x1b] = pvVar18;
                  *(ulong *)param_1[0x1c] = uVar30;
                  param_1[0x1a] = auVar43;
                  if (pvVar8 != (void *)0x0) {
                    operator_delete__(pvVar8);
                    uVar19 = *(ulong *)(param_1[0x1b] + 8);
                  }
                }
                if (uVar19 < uVar34) {
                  memset((void *)(*(long *)(param_1[0x1a] + 8) + uVar19 * 8),0,(uVar34 - uVar19) * 8
                        );
                }
                *(ulong *)(param_1[0x1b] + 8) = uVar34;
                lVar39 = *(long *)param_1[0x1d];
              }
              *(long *)param_1[0x1d] = lVar39 + 1;
            }
            else {
              if (uVar34 < uVar19) {
                if ((uVar19 >> 1 < uVar34) && (uVar19 = uVar34 * 2, (long)uVar34 < 0)) {
                  uVar19 = 0xffffffffffffffff;
                }
                pvVar18 = operator_new__(uVar19,(nothrow_t *)PTR_nothrow_00132fb8);
                uVar20 = *(ulong *)(param_1[0x28] + 8);
                if (uVar20 != 0) {
                  lVar39 = *(long *)(param_1[0x27] + 8);
                  if (((ulong)((long)pvVar18 - (lVar39 + 1)) < 0xf) || (uVar20 - 1 < 7)) {
                    uVar34 = 0;
                    do {
                      *(undefined1 *)((long)pvVar18 + uVar34) = *(undefined1 *)(lVar39 + uVar34);
                      uVar34 = uVar34 + 1;
                    } while (uVar20 != uVar34);
                  }
                  else if (uVar20 - 1 < 0xf) {
                    uVar30 = 0;
                    uVar34 = uVar20;
LAB_0011e549:
                    *(undefined8 *)((long)pvVar18 + uVar30) = *(undefined8 *)(lVar39 + uVar30);
                    uVar30 = uVar30 + (uVar34 & 0xfffffffffffffff8);
                    if ((uVar34 & 0xfffffffffffffff8) != uVar34) {
LAB_0011e560:
                      *(undefined1 *)((long)pvVar18 + uVar30) = *(undefined1 *)(lVar39 + uVar30);
                      if ((((uVar30 + 1 < uVar20) &&
                           (*(undefined1 *)((long)pvVar18 + uVar30 + 1) =
                                 *(undefined1 *)(lVar39 + 1 + uVar30), uVar30 + 2 < uVar20)) &&
                          (*(undefined1 *)((long)pvVar18 + uVar30 + 2) =
                                *(undefined1 *)(lVar39 + 2 + uVar30), uVar30 + 3 < uVar20)) &&
                         (((*(undefined1 *)((long)pvVar18 + uVar30 + 3) =
                                 *(undefined1 *)(lVar39 + 3 + uVar30), uVar30 + 4 < uVar20 &&
                           (*(undefined1 *)((long)pvVar18 + uVar30 + 4) =
                                 *(undefined1 *)(lVar39 + 4 + uVar30), uVar30 + 5 < uVar20)) &&
                          (*(undefined1 *)((long)pvVar18 + uVar30 + 5) =
                                *(undefined1 *)(lVar39 + 5 + uVar30), uVar30 + 6 < uVar20)))) {
                        *(undefined1 *)((long)pvVar18 + uVar30 + 6) =
                             *(undefined1 *)(lVar39 + 6 + uVar30);
                      }
                    }
                  }
                  else {
                    uVar34 = 0;
                    do {
                      uVar17 = ((undefined8 *)(lVar39 + uVar34))[1];
                      *(undefined8 *)((long)pvVar18 + uVar34) = *(undefined8 *)(lVar39 + uVar34);
                      ((undefined8 *)((long)pvVar18 + uVar34))[1] = uVar17;
                      uVar34 = uVar34 + 0x10;
                    } while (uVar34 != (uVar20 & 0xfffffffffffffff0));
                    uVar30 = uVar20 & 0xfffffffffffffff0;
                    if ((uVar20 & 0xf) != 0) {
                      uVar34 = uVar20 - uVar30;
                      if (6 < (uVar20 - uVar30) - 1) goto LAB_0011e549;
                      goto LAB_0011e560;
                    }
                  }
                }
                pvVar8 = *(void **)param_1[0x27];
                *(void **)param_1[0x28] = pvVar18;
                *(ulong *)param_1[0x29] = uVar19;
                *(void **)param_1[0x27] = pvVar18;
                *(void **)(param_1[0x27] + 8) = pvVar18;
                if (pvVar8 != (void *)0x0) {
                  operator_delete__(pvVar8);
                  pvVar18 = *(void **)(param_1[0x27] + 8);
                  uVar20 = *(ulong *)(param_1[0x28] + 8);
                }
              }
              else {
                pvVar18 = *(void **)(param_1[0x27] + 8);
              }
              *(undefined1 *)((long)pvVar18 + uVar20) = 0;
              uVar19 = *(ulong *)param_1[0x1d];
              *(long *)(param_1[0x28] + 8) = *(long *)(param_1[0x28] + 8) + 1;
              if (uVar19 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
                FUN_00106868();
              }
              uVar34 = *(ulong *)(param_1[0x1b] + 8);
              if (uVar19 == uVar34 << 6) {
                uVar20 = *(ulong *)param_1[0x1c];
                uVar19 = uVar34 + 1;
                if (uVar20 < uVar19) {
                  if (uVar19 >> 1 < uVar20) {
                    uVar34 = 0xfffffffffffffff8;
                    uVar30 = 0x1fffffffffffffff;
                    if (uVar20 < 0x1000000000000000) {
                      uVar30 = uVar20 * 2;
                      uVar34 = uVar20 << 4;
                    }
                  }
                  else {
                    uVar34 = uVar19 * 8;
                    uVar30 = uVar19;
                  }
                  pvVar18 = operator_new__(uVar34,(nothrow_t *)PTR_nothrow_00132fb8);
                  uVar34 = *(ulong *)(param_1[0x1b] + 8);
                  if (uVar34 != 0) {
                    lVar39 = *(long *)(param_1[0x1a] + 8);
                    if ((pvVar18 == (void *)(lVar39 + 8)) || (uVar34 - 1 < 3)) {
                      uVar20 = 0;
                      do {
                        *(undefined8 *)((long)pvVar18 + uVar20 * 8) =
                             *(undefined8 *)(lVar39 + uVar20 * 8);
                        uVar20 = uVar20 + 1;
                      } while (uVar34 != uVar20);
                    }
                    else {
                      lVar38 = 0;
                      do {
                        *(undefined1 (*) [16])((long)pvVar18 + lVar38) =
                             *(undefined1 (*) [16])(lVar39 + lVar38);
                        lVar38 = lVar38 + 0x10;
                      } while (lVar38 != (uVar34 >> 1) * 0x10);
                      if ((uVar34 & 1) != 0) {
                        *(undefined8 *)((long)pvVar18 + (uVar34 & 0xfffffffffffffffe) * 8) =
                             *(undefined8 *)(lVar39 + (uVar34 & 0xfffffffffffffffe) * 8);
                      }
                    }
                  }
                  pvVar8 = *(void **)param_1[0x1a];
                  *(void **)param_1[0x1b] = pvVar18;
                  *(ulong *)param_1[0x1c] = uVar30;
                  *(void **)param_1[0x1a] = pvVar18;
                  *(void **)(param_1[0x1a] + 8) = pvVar18;
                  if (pvVar8 != (void *)0x0) {
                    operator_delete__(pvVar8);
                    uVar34 = *(ulong *)(param_1[0x1b] + 8);
                    goto LAB_0011f11c;
                  }
                }
                else {
LAB_0011f11c:
                  pvVar18 = *(void **)(param_1[0x1a] + 8);
                }
                if (uVar34 < uVar19) {
                  memset((void *)((long)pvVar18 + uVar34 * 8),0,(uVar19 - uVar34) * 8);
                }
                *(ulong *)(param_1[0x1b] + 8) = uVar19;
                uVar19 = *(ulong *)param_1[0x1d];
              }
              else {
                pvVar18 = *(void **)(param_1[0x1a] + 8);
              }
              puVar1 = (ulong *)((long)pvVar18 + (uVar19 >> 6) * 8);
              *puVar1 = *puVar1 | 1L << ((byte)uVar19 & 0x3f);
              uVar5 = *(uint *)(*pauVar25 + 8);
              lVar38 = *(long *)(param_1[0x1d] + 8) + _UNK_0012a668;
              lVar39 = *(long *)((ulong)*(uint *)*pauVar25 * 0x18 + param_2[1]);
              *(long *)param_1[0x1d] = *(long *)param_1[0x1d] + _DAT_0012a660;
              *(long *)(param_1[0x1d] + 8) = lVar38;
              uVar47 = *(undefined4 *)(*pauVar25 + 0xc);
              uVar19 = local_208 + 1;
              puVar21 = local_1e8;
              if (local_1e0 < uVar19) {
                if (uVar19 >> 1 < local_1e0) {
                  if (local_1e0 < 0x555555555555556) {
                    uVar34 = local_1e0 * 0x30;
                    local_1e0 = local_1e0 * 2;
                  }
                  else {
                    uVar34 = 0xfffffffffffffff0;
                    local_1e0 = 0xaaaaaaaaaaaaaaa;
                  }
                }
                else {
                  uVar34 = uVar19 * 0x18;
                  local_1e0 = uVar19;
                }
                puVar21 = operator_new__(uVar34,(nothrow_t *)PTR_nothrow_00132fb8);
                if (local_208 != 0) {
                  puVar22 = puVar21;
                  puVar31 = local_1e8;
                  do {
                    puVar23 = puVar22 + 3;
                    *puVar22 = *puVar31;
                    *(undefined4 *)(puVar22 + 1) = *(undefined4 *)(puVar31 + 1);
                    *(undefined4 *)((long)puVar22 + 0xc) = *(undefined4 *)((long)puVar31 + 0xc);
                    *(undefined4 *)(puVar22 + 2) = *(undefined4 *)(puVar31 + 2);
                    puVar22 = puVar23;
                    puVar31 = puVar31 + 3;
                  } while (puVar21 + local_208 * 3 != puVar23);
                }
                if (local_1e8 != (undefined8 *)0x0) {
                  operator_delete__(local_1e8);
                }
              }
              local_1e8 = puVar21;
              plVar2 = local_1e8 + local_208 * 3;
              *plVar2 = lVar39 - (ulong)uVar5;
              *(uint *)(plVar2 + 1) = (int)uVar35 - uVar5;
              *(undefined4 *)(plVar2 + 2) = 0;
              *(undefined4 *)((long)plVar2 + 0xc) = uVar47;
              local_208 = uVar19;
            }
            *(int *)(*pauVar25 + 8) = (int)uVar35;
            if ((undefined8 *)local_138._0_8_ == (undefined8 *)(local_128._0_8_ + -0xc)) {
              FUN_0011b500(&local_168);
            }
            else {
              *(undefined8 *)local_138._0_8_ = *(undefined8 *)*pauVar25;
              *(undefined4 *)(local_138._0_8_ + 8) = *(undefined4 *)(*pauVar25 + 8);
              local_138._0_8_ = local_138._0_8_ + 0xc;
            }
            uVar35 = *(ulong *)param_1[3];
            if (uVar35 == 0xffffffff) goto LAB_0011ffae;
            uVar19 = *(ulong *)(param_1[1] + 8);
            if (uVar35 == uVar19 << 6) {
              uVar34 = *(ulong *)param_1[2];
              uVar35 = uVar19 + 1;
              if (uVar34 < uVar35) {
                if (uVar35 >> 1 < uVar34) {
                  uVar19 = 0xfffffffffffffff8;
                  uVar20 = 0x1fffffffffffffff;
                  if (uVar34 < 0x1000000000000000) {
                    uVar20 = uVar34 * 2;
                    uVar19 = uVar34 << 4;
                  }
                }
                else {
                  uVar19 = uVar35 * 8;
                  uVar20 = uVar35;
                }
                pvVar18 = operator_new__(uVar19,(nothrow_t *)PTR_nothrow_00132fb8);
                uVar19 = *(ulong *)(param_1[1] + 8);
                auVar42._8_8_ = pvVar18;
                auVar42._0_8_ = pvVar18;
                if (uVar19 != 0) {
                  lVar39 = *(long *)(*param_1 + 8);
                  if ((pvVar18 == (void *)(lVar39 + 8)) || (uVar19 - 1 < 3)) {
                    uVar34 = 0;
                    do {
                      *(undefined8 *)((long)pvVar18 + uVar34 * 8) =
                           *(undefined8 *)(lVar39 + uVar34 * 8);
                      uVar34 = uVar34 + 1;
                    } while (uVar19 != uVar34);
                  }
                  else {
                    lVar38 = 0;
                    do {
                      *(undefined1 (*) [16])((long)pvVar18 + lVar38) =
                           *(undefined1 (*) [16])(lVar39 + lVar38);
                      lVar38 = lVar38 + 0x10;
                    } while ((uVar19 >> 1) * 0x10 != lVar38);
                    if ((uVar19 & 1) != 0) {
                      *(undefined8 *)((long)pvVar18 + (uVar19 & 0xfffffffffffffffe) * 8) =
                           *(undefined8 *)(lVar39 + (uVar19 & 0xfffffffffffffffe) * 8);
                    }
                  }
                }
                *(void **)param_1[1] = pvVar18;
                *(ulong *)param_1[2] = uVar20;
                *param_1 = auVar42;
                if (*(void **)*param_1 != (void *)0x0) {
                  operator_delete__(*(void **)*param_1);
                  uVar19 = *(ulong *)(param_1[1] + 8);
                  goto LAB_0011efcc;
                }
              }
              else {
LAB_0011efcc:
                pvVar18 = *(void **)(*param_1 + 8);
              }
              if (uVar19 < uVar35) {
                memset((void *)((long)pvVar18 + uVar19 * 8),0,(uVar35 - uVar19) * 8);
              }
              *(ulong *)(param_1[1] + 8) = uVar35;
              uVar35 = *(ulong *)param_1[3];
            }
            else {
              pvVar18 = *(void **)(*param_1 + 8);
            }
            local_210 = local_210 + 1;
            pauVar25 = pauVar25 + 1;
            puVar1 = (ulong *)((long)pvVar18 + (uVar35 >> 6) * 8);
            *puVar1 = *puVar1 | 1L << ((byte)uVar35 & 0x3f);
            lVar39 = *(long *)param_1[3];
            *(long *)(param_1[3] + 8) = *(long *)(param_1[3] + 8) + 1;
            lVar39 = lVar39 + 1;
            *(long *)param_1[3] = lVar39;
          } while (local_210 != local_1f8);
        }
        if (lVar39 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
          FUN_00106868();
        }
        uVar35 = *(ulong *)(param_1[1] + 8);
        if (uVar35 << 6 == lVar39) {
          uVar34 = *(ulong *)param_1[2];
          uVar19 = uVar35 + 1;
          if (uVar34 < uVar19) {
            if (uVar19 >> 1 < uVar34) {
              uVar35 = 0xfffffffffffffff8;
              uVar20 = 0x1fffffffffffffff;
              if (uVar34 < 0x1000000000000000) {
                uVar20 = uVar34 * 2;
                uVar35 = uVar34 << 4;
              }
            }
            else {
              uVar35 = uVar19 * 8;
              uVar20 = uVar19;
            }
            pvVar18 = operator_new__(uVar35,(nothrow_t *)PTR_nothrow_00132fb8);
            uVar35 = *(ulong *)(param_1[1] + 8);
            auVar44._8_8_ = pvVar18;
            auVar44._0_8_ = pvVar18;
            if (uVar35 != 0) {
              lVar39 = *(long *)(*param_1 + 8);
              if ((pvVar18 == (void *)(lVar39 + 8)) || (uVar35 - 1 < 3)) {
                uVar34 = 0;
                do {
                  *(undefined8 *)((long)pvVar18 + uVar34 * 8) = *(undefined8 *)(lVar39 + uVar34 * 8)
                  ;
                  uVar34 = uVar34 + 1;
                } while (uVar35 != uVar34);
              }
              else {
                lVar46 = 0;
                do {
                  *(undefined1 (*) [16])((long)pvVar18 + lVar46) =
                       *(undefined1 (*) [16])(lVar39 + lVar46);
                  lVar46 = lVar46 + 0x10;
                } while (lVar46 != (uVar35 >> 1) * 0x10);
                if ((uVar35 & 1) != 0) {
                  *(undefined8 *)((long)pvVar18 + (uVar35 & 0xfffffffffffffffe) * 8) =
                       *(undefined8 *)(lVar39 + (uVar35 & 0xfffffffffffffffe) * 8);
                }
              }
            }
            *(void **)param_1[1] = pvVar18;
            *(ulong *)param_1[2] = uVar20;
            *param_1 = auVar44;
            if (*(void **)*param_1 != (void *)0x0) {
              operator_delete__(*(void **)*param_1);
              uVar35 = *(ulong *)(param_1[1] + 8);
            }
          }
          if (uVar35 < uVar19) {
            memset((void *)(*(long *)(*param_1 + 8) + uVar35 * 8),0,(uVar19 - uVar35) * 8);
          }
          *(ulong *)(param_1[1] + 8) = uVar19;
          lVar39 = *(long *)param_1[3];
        }
        lVar39 = lVar39 + 1;
        *(long *)param_1[3] = lVar39;
        puVar33 = local_158;
      }
    } while ((uint *)local_138._0_8_ != puVar33);
  }
  if (lVar39 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_00106868();
  }
  uVar35 = *(ulong *)(param_1[1] + 8);
  if (uVar35 << 6 == lVar39) {
    uVar34 = *(ulong *)param_1[2];
    uVar19 = uVar35 + 1;
    if (uVar34 < uVar19) {
      if (uVar19 >> 1 < uVar34) {
        uVar35 = 0xfffffffffffffff8;
        uVar20 = 0x1fffffffffffffff;
        if (uVar34 >> 0x3c == 0) {
          uVar20 = uVar34 * 2;
          uVar35 = uVar34 << 4;
        }
      }
      else {
        uVar35 = uVar19 * 8;
        uVar20 = uVar19;
      }
      pvVar18 = operator_new__(uVar35,(nothrow_t *)PTR_nothrow_00132fb8);
      uVar35 = *(ulong *)(param_1[1] + 8);
      if (uVar35 != 0) {
        lVar39 = *(long *)(*param_1 + 8);
        if ((pvVar18 == (void *)(lVar39 + 8)) || (uVar35 - 1 < 3)) {
          uVar34 = 0;
          do {
            *(undefined8 *)((long)pvVar18 + uVar34 * 8) = *(undefined8 *)(lVar39 + uVar34 * 8);
            uVar34 = uVar34 + 1;
          } while (uVar35 != uVar34);
        }
        else {
          lVar46 = 0;
          do {
            uVar17 = ((undefined8 *)(lVar39 + lVar46))[1];
            *(undefined8 *)((long)pvVar18 + lVar46) = *(undefined8 *)(lVar39 + lVar46);
            ((undefined8 *)((long)pvVar18 + lVar46))[1] = uVar17;
            lVar46 = lVar46 + 0x10;
          } while (lVar46 != (uVar35 >> 1) * 0x10);
          if ((uVar35 & 1) != 0) {
            *(undefined8 *)((long)pvVar18 + (uVar35 & 0xfffffffffffffffe) * 8) =
                 *(undefined8 *)(lVar39 + (uVar35 & 0xfffffffffffffffe) * 8);
          }
        }
      }
      pvVar8 = *(void **)*param_1;
      *(void **)param_1[1] = pvVar18;
      *(ulong *)param_1[2] = uVar20;
      *(void **)*param_1 = pvVar18;
      *(void **)(*param_1 + 8) = pvVar18;
      if (pvVar8 != (void *)0x0) {
        operator_delete__(pvVar8);
        uVar35 = *(ulong *)(param_1[1] + 8);
      }
    }
    if (uVar35 < uVar19) {
      memset((void *)(*(long *)(*param_1 + 8) + uVar35 * 8),0,(uVar19 - uVar35) * 8);
    }
    *(ulong *)(param_1[1] + 8) = uVar19;
    lVar39 = *(long *)param_1[3];
  }
  *(long *)param_1[3] = lVar39 + 1;
  local_108 = 0;
  local_f0 = 0;
  local_c8 = 0;
  local_b0 = 0;
  local_98 = 0;
  local_80 = 0;
  local_68 = 0;
  local_50 = 0;
  local_118 = (undefined1  [16])0x0;
  local_100 = (undefined1  [16])0x0;
  local_e8 = (undefined1  [16])0x0;
  local_d8 = (undefined1  [16])0x0;
  local_c0 = (undefined1  [16])0x0;
  local_a8 = (undefined1  [16])0x0;
  local_90 = (undefined1  [16])0x0;
  local_78 = (undefined1  [16])0x0;
  local_60 = (undefined1  [16])0x0;
  FUN_00126020(local_118,param_1,param_5 == 1,1);
  if (param_1[2][8] != '\0') {
LAB_0011ffa9:
    FUN_001065cc();
LAB_0011ffae:
                    /* WARNING: Subroutine does not return */
    FUN_00106868();
  }
  lVar39 = *(long *)(param_1[1] + 8);
  uVar15 = 0;
  if (lVar39 != *(long *)param_1[2]) {
    pvVar18 = operator_new__(lVar39 * 8,(nothrow_t *)PTR_nothrow_00132fb8);
    uVar35 = *(ulong *)(param_1[1] + 8);
    if (uVar35 != 0) {
      lVar46 = *(long *)(*param_1 + 8);
      if ((pvVar18 == (void *)(lVar46 + 8)) || (uVar35 - 1 < 3)) {
        uVar19 = 0;
        do {
          *(undefined8 *)((long)pvVar18 + uVar19 * 8) = *(undefined8 *)(lVar46 + uVar19 * 8);
          uVar19 = uVar19 + 1;
        } while (uVar35 != uVar19);
      }
      else {
        lVar38 = 0;
        do {
          uVar17 = ((undefined8 *)(lVar46 + lVar38))[1];
          *(undefined8 *)((long)pvVar18 + lVar38) = *(undefined8 *)(lVar46 + lVar38);
          ((undefined8 *)((long)pvVar18 + lVar38))[1] = uVar17;
          lVar38 = lVar38 + 0x10;
        } while (lVar38 != (uVar35 >> 1) * 0x10);
        if ((uVar35 & 1) != 0) {
          *(undefined8 *)((long)pvVar18 + (uVar35 & 0xfffffffffffffffe) * 8) =
               *(undefined8 *)(lVar46 + (uVar35 & 0xfffffffffffffffe) * 8);
        }
      }
    }
    pvVar8 = *(void **)*param_1;
    *(void **)param_1[1] = pvVar18;
    *(long *)param_1[2] = lVar39;
    *(void **)*param_1 = pvVar18;
    *(void **)(*param_1 + 8) = pvVar18;
    if (pvVar8 != (void *)0x0) {
      operator_delete__(pvVar8);
    }
    uVar15 = param_1[2][8];
  }
  auVar13 = param_1[3];
  param_1[2][8] = uVar15;
  uVar17 = *(undefined8 *)param_1[5];
  auVar45 = param_1[4];
  *(undefined8 *)param_1[5] = local_c8;
  auVar40 = *(undefined1 (*) [16])(param_1[5] + 8);
  uVar15 = param_1[6][8];
  pvVar18 = *(void **)param_1[7];
  auVar41 = param_1[7];
  param_1[6][8] = (undefined1)local_b0;
  local_b0 = CONCAT71(local_b0._1_7_,uVar15);
  uVar9 = *(undefined8 *)param_1[8];
  *(undefined8 *)param_1[3] = local_e8._0_8_;
  *(undefined8 *)(param_1[3] + 8) = local_e8._8_8_;
  auVar43 = *(undefined1 (*) [16])(param_1[8] + 8);
  *(undefined8 *)param_1[8] = local_98;
  *(undefined8 *)param_1[4] = local_d8._0_8_;
  *(undefined8 *)(param_1[4] + 8) = local_d8._8_8_;
  *(undefined8 *)(param_1[5] + 8) = local_c0._0_8_;
  *(undefined8 *)param_1[6] = local_c0._8_8_;
  *(undefined8 *)param_1[7] = local_a8._0_8_;
  *(undefined8 *)(param_1[7] + 8) = local_a8._8_8_;
  *(undefined8 *)(param_1[8] + 8) = local_90._0_8_;
  *(undefined8 *)param_1[9] = local_90._8_8_;
  uVar15 = param_1[9][8];
  pvVar8 = *(void **)param_1[10];
  auVar42 = param_1[10];
  param_1[9][8] = (undefined1)local_80;
  local_80 = CONCAT71(local_80._1_7_,uVar15);
  uVar10 = *(undefined8 *)param_1[0xb];
  auVar44 = *(undefined1 (*) [16])(param_1[0xb] + 8);
  *(undefined8 *)param_1[0xb] = local_68;
  uVar15 = param_1[0xc][8];
  *(undefined8 *)param_1[10] = local_78._0_8_;
  *(undefined8 *)(param_1[10] + 8) = local_78._8_8_;
  param_1[0xc][8] = (undefined1)local_50;
  local_50 = CONCAT71(local_50._1_7_,uVar15);
  *(undefined8 *)(param_1[0xb] + 8) = local_60._0_8_;
  *(undefined8 *)param_1[0xc] = local_60._8_8_;
  local_e8 = auVar13;
  local_d8 = auVar45;
  local_c8 = uVar17;
  local_c0 = auVar40;
  local_a8 = auVar41;
  local_98 = uVar9;
  local_90 = auVar43;
  local_78 = auVar42;
  local_68 = uVar10;
  local_60 = auVar44;
  if (pvVar8 != (void *)0x0) {
    operator_delete__(pvVar8);
    pvVar18 = (void *)local_a8._0_8_;
  }
  if (pvVar18 != (void *)0x0) {
    operator_delete__(pvVar18);
  }
  if ((void *)local_d8._0_8_ != (void *)0x0) {
    operator_delete__((void *)local_d8._0_8_);
  }
  if ((void *)local_118._0_8_ != (void *)0x0) {
    operator_delete__((void *)local_118._0_8_);
  }
  if (param_1[0x29][8] != '\0') {
    FUN_001065cc();
    goto LAB_0011ffa9;
  }
  uVar35 = *(ulong *)(param_1[0x28] + 8);
  if (uVar35 == *(ulong *)param_1[0x29]) goto LAB_0011eb91;
  pvVar18 = operator_new__(uVar35,(nothrow_t *)PTR_nothrow_00132fb8);
  uVar19 = *(ulong *)(param_1[0x28] + 8);
  if (uVar19 != 0) {
    lVar39 = *(long *)(param_1[0x27] + 8);
    if (((ulong)((long)pvVar18 - (lVar39 + 1)) < 0xf) || (uVar19 - 1 < 7)) {
      uVar34 = 0;
      do {
        *(undefined1 *)((long)pvVar18 + uVar34) = *(undefined1 *)(lVar39 + uVar34);
        uVar34 = uVar34 + 1;
      } while (uVar34 != uVar19);
    }
    else if (uVar19 - 1 < 0xf) {
      uVar20 = 0;
      uVar34 = uVar19;
LAB_0011fb55:
      *(undefined8 *)((long)pvVar18 + uVar20) = *(undefined8 *)(lVar39 + uVar20);
      uVar20 = uVar20 + (uVar34 & 0xfffffffffffffff8);
      if ((uVar34 & 0xfffffffffffffff8) != uVar34) {
LAB_0011fb6c:
        *(undefined1 *)((long)pvVar18 + uVar20) = *(undefined1 *)(lVar39 + uVar20);
        if ((((uVar20 + 1 < uVar19) &&
             (*(undefined1 *)((long)pvVar18 + uVar20 + 1) = *(undefined1 *)(lVar39 + 1 + uVar20),
             uVar20 + 2 < uVar19)) &&
            (*(undefined1 *)((long)pvVar18 + uVar20 + 2) = *(undefined1 *)(lVar39 + 2 + uVar20),
            uVar20 + 3 < uVar19)) &&
           (((*(undefined1 *)((long)pvVar18 + uVar20 + 3) = *(undefined1 *)(lVar39 + 3 + uVar20),
             uVar20 + 4 < uVar19 &&
             (*(undefined1 *)((long)pvVar18 + uVar20 + 4) = *(undefined1 *)(lVar39 + 4 + uVar20),
             uVar20 + 5 < uVar19)) &&
            (*(undefined1 *)((long)pvVar18 + uVar20 + 5) = *(undefined1 *)(lVar39 + 5 + uVar20),
            uVar20 + 6 < uVar19)))) {
          *(undefined1 *)((long)pvVar18 + uVar20 + 6) = *(undefined1 *)(lVar39 + 6 + uVar20);
        }
      }
    }
    else {
      uVar34 = 0;
      do {
        uVar17 = ((undefined8 *)(lVar39 + uVar34))[1];
        *(undefined8 *)((long)pvVar18 + uVar34) = *(undefined8 *)(lVar39 + uVar34);
        ((undefined8 *)((long)pvVar18 + uVar34))[1] = uVar17;
        uVar34 = uVar34 + 0x10;
      } while ((uVar19 & 0xfffffffffffffff0) != uVar34);
      uVar20 = uVar19 & 0xfffffffffffffff0;
      if ((uVar19 & 0xf) != 0) {
        uVar34 = uVar19 - uVar20;
        if (6 < (uVar19 - uVar20) - 1) goto LAB_0011fb55;
        goto LAB_0011fb6c;
      }
    }
  }
  pvVar8 = *(void **)param_1[0x27];
  *(void **)param_1[0x28] = pvVar18;
  *(ulong *)param_1[0x29] = uVar35;
  *(void **)param_1[0x27] = pvVar18;
  *(void **)(param_1[0x27] + 8) = pvVar18;
  if (pvVar8 != (void *)0x0) {
    operator_delete__(pvVar8);
  }
LAB_0011eb91:
  lVar39 = param_2[3];
  if (lVar39 == 0) {
    local_210 = 0;
    pvVar18 = (void *)0x0;
  }
  else {
    pvVar18 = operator_new__(lVar39 * 4,(nothrow_t *)PTR_nothrow_00132fb8);
    lVar46 = param_2[3];
    local_210 = lVar39;
    if (lVar46 != 0) {
      lVar38 = param_2[2];
      puVar24 = (undefined4 *)(lVar38 + 0xc);
      do {
        uVar47 = *puVar24;
        puVar33 = puVar24 + 1;
        puVar24 = puVar24 + 6;
        *(undefined4 *)((long)pvVar18 + (ulong)*puVar33 * 4) = uVar47;
      } while (puVar24 != (undefined4 *)(lVar38 + 0xc + lVar46 * 0x18));
    }
  }
  pvVar8 = (void *)*param_3;
  *param_3 = pvVar18;
  param_3[1] = pvVar18;
  param_3[2] = pvVar18;
  *(undefined1 *)(param_3 + 5) = 0;
  param_3[3] = lVar39;
  param_3[4] = local_210;
  if (pvVar8 != (void *)0x0) {
    operator_delete__(pvVar8);
  }
  param_2[2] = local_1e8;
  pvVar18 = (void *)*param_2;
  *(undefined1 *)(param_2 + 5) = 0;
  param_2[3] = local_208;
  *param_2 = local_1e8;
  param_2[1] = local_1e8;
  param_2[4] = local_1e0;
  if (__dest != (undefined1 (*) [16])0x0) {
    operator_delete__(__dest);
  }
  pvVar8 = local_168;
  if (local_168 != (void *)0x0) {
    puVar21 = (undefined8 *)(local_128._8_8_ + 8);
    for (puVar22 = puStack_140; puVar22 < puVar21; puVar22 = puVar22 + 1) {
      operator_delete((void *)*puVar22);
    }
    operator_delete(pvVar8);
  }
  if (pvVar18 == (void *)0x0) {
    if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
  else if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    operator_delete__(pvVar18);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_001200d0 @ 001200d0 size=3170 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_001200d0(long param_1,long param_2,undefined8 param_3,long param_4,undefined8 param_5)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  void *pvVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 uVar15;
  uint uVar16;
  undefined4 uVar17;
  ulong uVar18;
  uint *puVar19;
  undefined8 *puVar20;
  void *pvVar21;
  undefined8 *puVar22;
  undefined8 uVar23;
  sbyte sVar24;
  uint uVar25;
  uint uVar26;
  long lVar27;
  long lVar28;
  undefined4 uVar29;
  ulong uVar30;
  undefined4 uVar31;
  long in_FS_OFFSET;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  ulong local_168;
  undefined1 local_148 [16];
  uint *local_138;
  undefined1 local_130 [16];
  undefined1 local_120;
  undefined1 local_118 [16];
  undefined8 local_108;
  undefined1 local_100 [16];
  undefined8 local_f0;
  undefined1 local_e8 [16];
  undefined1 local_d8 [16];
  undefined8 local_c8;
  undefined1 local_c0 [16];
  undefined8 local_b0;
  undefined1 local_a8 [16];
  undefined8 local_98;
  undefined1 local_90 [16];
  undefined8 local_80;
  undefined1 local_78 [16];
  undefined8 local_68;
  undefined1 local_60 [16];
  undefined8 local_50;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_0011dc10();
  local_138 = (uint *)0x0;
  local_120 = 0;
  local_148 = (undefined1  [16])0x0;
  local_130 = (undefined1  [16])0x0;
  if (*(long *)(param_2 + 0x18) != 0) {
    FUN_00119060(param_1,param_2,local_148,param_4,param_5);
  }
  lVar28 = *(long *)(param_1 + 1000);
  if (lVar28 == 0) {
    uVar16 = *(uint *)(param_4 + 0x10) | *(uint *)(param_4 + 8);
    uVar25 = uVar16 | (-(uint)(*(long *)(param_1 + 0x348) == 0) & 0xfffff000) + 0x2000;
    if ((uVar25 & 0xfff00000) != 0) {
      puVar20 = (undefined8 *)__cxa_allocate_exception(0x20);
      *puVar20 = &PTR_FUN_00132da8;
      puVar20[1] = "../src_udic/marisa_u/grimoire/trie/config.h";
      puVar20[2] = 0x50000003a;
      puVar20[3] = 
      "../src_udic/marisa_u/grimoire/trie/config.h:58: MARISA_CODE_ERROR: (config_flags & ~MARISA_CONFIG_MASK) != 0"
      ;
                    /* WARNING: Subroutine does not return */
      __cxa_throw(puVar20,&PTR_vtable_00132d80,FUN_0010e6a0);
    }
    uVar26 = uVar16 & 0xf80;
    if (uVar26 == 0x200) {
LAB_00120a18:
      uVar17 = 0x200;
      if ((uVar25 & 0xf000) != 0x1000) goto LAB_001209b2;
LAB_00120a2d:
      uVar31 = 0x1000;
    }
    else {
      if (uVar26 < 0x201) {
        if (uVar26 == 0x80) {
          uVar17 = 0x80;
        }
        else {
          if (uVar26 != 0x100) {
            if (uVar26 != 0) goto LAB_00120c73;
            goto LAB_00120a18;
          }
          uVar17 = 0x100;
        }
      }
      else if (uVar26 == 0x400) {
        uVar17 = 0x400;
      }
      else {
        if (uVar26 != 0x800) {
LAB_00120c73:
          puVar20 = (undefined8 *)__cxa_allocate_exception(0x20);
          *puVar20 = &PTR_FUN_00132da8;
          puVar20[1] = "../src_udic/marisa_u/grimoire/trie/config.h";
          puVar20[2] = 0x500000065;
          puVar20[3] = 
          "../src_udic/marisa_u/grimoire/trie/config.h:101: MARISA_CODE_ERROR: undefined cache level"
          ;
                    /* WARNING: Subroutine does not return */
          __cxa_throw(puVar20,&PTR_vtable_00132d80,FUN_0010e6a0);
        }
        uVar17 = 0x800;
      }
      if ((uVar25 & 0xf000) == 0x1000) goto LAB_00120a2d;
LAB_001209b2:
      uVar31 = 0x2000;
      if (((uVar25 & 0xf000) != 0x2000) && (uVar31 = 0x1000, (uVar25 & 0xf000) != 0)) {
        puVar20 = (undefined8 *)__cxa_allocate_exception(0x20);
        *puVar20 = &PTR_FUN_00132da8;
        puVar20[1] = "../src_udic/marisa_u/grimoire/trie/config.h";
        puVar20[2] = 0x500000079;
        puVar20[3] = 
        "../src_udic/marisa_u/grimoire/trie/config.h:121: MARISA_CODE_ERROR: undefined tail mode";
                    /* WARNING: Subroutine does not return */
        __cxa_throw(puVar20,&PTR_vtable_00132d80,FUN_0010e6a0);
      }
    }
    if ((uVar25 & 0xf0000) == 0x10000) {
      uVar29 = 0x10000;
    }
    else {
      uVar29 = 0x20000;
      if ((uVar25 & 0xd0000) != 0) {
        puVar20 = (undefined8 *)__cxa_allocate_exception(0x20);
        *puVar20 = &PTR_FUN_00132da8;
        puVar20[1] = "../src_udic/marisa_u/grimoire/trie/config.h";
        puVar20[2] = 0x50000008d;
        puVar20[3] = 
        "../src_udic/marisa_u/grimoire/trie/config.h:141: MARISA_CODE_ERROR: undefined node order";
                    /* WARNING: Subroutine does not return */
        __cxa_throw(puVar20,&PTR_vtable_00132d80,FUN_0010e6a0);
      }
    }
    *(ulong *)(param_1 + 0x430) = (ulong)(uVar16 & 0x7f | 1);
    *(undefined4 *)(param_1 + 0x440) = uVar29;
    *(ulong *)(param_1 + 0x438) = CONCAT44(uVar31,uVar17);
  }
  else {
    uVar16 = *(uint *)(lVar28 + 0x43c) | *(uint *)(lVar28 + 0x440) |
             (int)*(undefined8 *)(lVar28 + 0x430) + 1U;
    if ((uVar16 & 0xfff00000) != 0) {
      puVar20 = (undefined8 *)__cxa_allocate_exception(0x20);
      *puVar20 = &PTR_FUN_00132da8;
      puVar20[1] = "../src_udic/marisa_u/grimoire/trie/config.h";
      puVar20[2] = 0x50000003a;
      puVar20[3] = 
      "../src_udic/marisa_u/grimoire/trie/config.h:58: MARISA_CODE_ERROR: (config_flags & ~MARISA_CONFIG_MASK) != 0"
      ;
                    /* WARNING: Subroutine does not return */
      __cxa_throw(puVar20,&PTR_vtable_00132d80,FUN_0010e6a0);
    }
    uVar25 = uVar16 & 0x7f;
    if (uVar25 == 0) {
      uVar25 = 3;
    }
    uVar26 = uVar16 & 0xf80;
    if (uVar26 == 0x200) {
LAB_00120877:
      uVar17 = 0x200;
LAB_001201d0:
      if ((uVar16 & 0xf000) != 0x1000) goto LAB_001201e4;
LAB_00120865:
      uVar31 = 0x1000;
    }
    else {
      if (uVar26 < 0x201) {
        if (uVar26 == 0x80) {
          uVar17 = 0x80;
        }
        else {
          if (uVar26 != 0x100) {
            if (uVar26 != 0) goto LAB_00120cd3;
            goto LAB_00120877;
          }
          uVar17 = 0x100;
        }
        goto LAB_001201d0;
      }
      if (uVar26 == 0x400) {
        uVar17 = 0x400;
        goto LAB_001201d0;
      }
      if (uVar26 != 0x800) {
LAB_00120cd3:
        puVar20 = (undefined8 *)__cxa_allocate_exception(0x20);
        *puVar20 = &PTR_FUN_00132da8;
        puVar20[1] = "../src_udic/marisa_u/grimoire/trie/config.h";
        puVar20[2] = 0x500000065;
        puVar20[3] = 
        "../src_udic/marisa_u/grimoire/trie/config.h:101: MARISA_CODE_ERROR: undefined cache level";
                    /* WARNING: Subroutine does not return */
        __cxa_throw(puVar20,&PTR_vtable_00132d80,FUN_0010e6a0);
      }
      uVar17 = 0x800;
      if ((uVar16 & 0xf000) == 0x1000) goto LAB_00120865;
LAB_001201e4:
      uVar31 = 0x2000;
      if (((uVar16 & 0xf000) != 0x2000) && (uVar31 = 0x1000, (uVar16 & 0xf000) != 0)) {
        puVar20 = (undefined8 *)__cxa_allocate_exception(0x20);
        *puVar20 = &PTR_FUN_00132da8;
        puVar20[1] = "../src_udic/marisa_u/grimoire/trie/config.h";
        puVar20[2] = 0x500000079;
        puVar20[3] = 
        "../src_udic/marisa_u/grimoire/trie/config.h:121: MARISA_CODE_ERROR: undefined tail mode";
                    /* WARNING: Subroutine does not return */
        __cxa_throw(puVar20,&PTR_vtable_00132d80,FUN_0010e6a0);
      }
    }
    if ((uVar16 & 0xf0000) == 0x10000) {
      uVar29 = 0x10000;
    }
    else {
      uVar29 = 0x20000;
      if ((uVar16 & 0xd0000) != 0) {
        puVar20 = (undefined8 *)__cxa_allocate_exception(0x20);
        *puVar20 = &PTR_FUN_00132da8;
        puVar20[1] = "../src_udic/marisa_u/grimoire/trie/config.h";
        puVar20[2] = 0x50000008d;
        puVar20[3] = 
        "../src_udic/marisa_u/grimoire/trie/config.h:141: MARISA_CODE_ERROR: undefined node order";
                    /* WARNING: Subroutine does not return */
        __cxa_throw(puVar20,&PTR_vtable_00132d80,FUN_0010e6a0);
      }
    }
    *(long *)(param_1 + 0x430) = (long)(int)uVar25;
    *(undefined4 *)(param_1 + 0x440) = uVar29;
    *(ulong *)(param_1 + 0x438) = CONCAT44(uVar31,uVar17);
  }
  local_108 = 0;
  local_f0 = 0;
  local_c8 = 0;
  local_b0 = 0;
  local_98 = 0;
  local_80 = 0;
  local_68 = 0;
  local_50 = 0;
  local_118 = (undefined1  [16])0x0;
  local_100 = (undefined1  [16])0x0;
  local_e8 = (undefined1  [16])0x0;
  local_d8 = (undefined1  [16])0x0;
  local_c0 = (undefined1  [16])0x0;
  local_a8 = (undefined1  [16])0x0;
  local_90 = (undefined1  [16])0x0;
  local_78 = (undefined1  [16])0x0;
  local_60 = (undefined1  [16])0x0;
  FUN_00126020(local_118,param_1 + 0x1a0,0,0);
  if (*(char *)(param_1 + 0x1c8) != '\0') {
    uVar23 = FUN_001065cc();
    FUN_00119540(local_118);
    if ((void *)local_148._0_8_ != (void *)0x0) {
      operator_delete__((void *)local_148._0_8_);
    }
                    /* WARNING: Subroutine does not return */
    _Unwind_Resume(uVar23);
  }
  lVar28 = *(long *)(param_1 + 0x1b8);
  uVar15 = 0;
  if (lVar28 != *(long *)(param_1 + 0x1c0)) {
    pvVar21 = operator_new__(lVar28 * 8,(nothrow_t *)PTR_nothrow_00132fb8);
    uVar18 = *(ulong *)(param_1 + 0x1b8);
    if (uVar18 != 0) {
      lVar3 = *(long *)(param_1 + 0x1a8);
      if ((pvVar21 == (void *)(lVar3 + 8)) || (uVar18 - 1 < 3)) {
        uVar30 = 0;
        do {
          *(undefined8 *)((long)pvVar21 + uVar30 * 8) = *(undefined8 *)(lVar3 + uVar30 * 8);
          uVar30 = uVar30 + 1;
        } while (uVar18 != uVar30);
      }
      else {
        lVar27 = 0;
        do {
          uVar23 = ((undefined8 *)(lVar3 + lVar27))[1];
          *(undefined8 *)((long)pvVar21 + lVar27) = *(undefined8 *)(lVar3 + lVar27);
          ((undefined8 *)((long)pvVar21 + lVar27))[1] = uVar23;
          lVar27 = lVar27 + 0x10;
        } while ((uVar18 >> 1) * 0x10 != lVar27);
        if ((uVar18 & 1) != 0) {
          *(undefined8 *)((long)pvVar21 + (uVar18 & 0xfffffffffffffffe) * 8) =
               *(undefined8 *)(lVar3 + (uVar18 & 0xfffffffffffffffe) * 8);
        }
      }
    }
    pvVar4 = *(void **)(param_1 + 0x1a0);
    *(void **)(param_1 + 0x1b0) = pvVar21;
    *(long *)(param_1 + 0x1c0) = lVar28;
    *(void **)(param_1 + 0x1a0) = pvVar21;
    *(void **)(param_1 + 0x1a8) = pvVar21;
    if (pvVar4 != (void *)0x0) {
      operator_delete__(pvVar4);
    }
    uVar15 = *(undefined1 *)(param_1 + 0x1c8);
  }
  auVar8 = *(undefined1 (*) [16])(param_1 + 0x1d0);
  *(undefined1 *)(param_1 + 0x1c8) = uVar15;
  uVar23 = *(undefined8 *)(param_1 + 0x1f0);
  *(undefined8 *)(param_1 + 0x1f0) = local_c8;
  auVar9 = *(undefined1 (*) [16])(param_1 + 0x1e0);
  *(undefined8 *)(param_1 + 0x1d0) = local_e8._0_8_;
  *(undefined8 *)(param_1 + 0x1d8) = local_e8._8_8_;
  auVar10 = *(undefined1 (*) [16])(param_1 + 0x1f8);
  uVar15 = *(undefined1 *)(param_1 + 0x208);
  pvVar21 = *(void **)*(undefined1 (*) [16])(param_1 + 0x210);
  auVar11 = *(undefined1 (*) [16])(param_1 + 0x210);
  *(undefined1 *)(param_1 + 0x208) = (undefined1)local_b0;
  local_b0 = CONCAT71(local_b0._1_7_,uVar15);
  uVar1 = *(undefined8 *)(param_1 + 0x220);
  *(undefined8 *)(param_1 + 0x1e0) = local_d8._0_8_;
  *(undefined8 *)(param_1 + 0x1e8) = local_d8._8_8_;
  auVar12 = *(undefined1 (*) [16])(param_1 + 0x228);
  *(undefined8 *)(param_1 + 0x220) = local_98;
  *(undefined8 *)(param_1 + 0x1f8) = local_c0._0_8_;
  *(undefined8 *)(param_1 + 0x200) = local_c0._8_8_;
  *(undefined8 *)(param_1 + 0x210) = local_a8._0_8_;
  *(undefined8 *)(param_1 + 0x218) = local_a8._8_8_;
  *(undefined8 *)(param_1 + 0x228) = local_90._0_8_;
  *(undefined8 *)(param_1 + 0x230) = local_90._8_8_;
  uVar15 = *(undefined1 *)(param_1 + 0x238);
  pvVar4 = *(void **)*(undefined1 (*) [16])(param_1 + 0x240);
  auVar13 = *(undefined1 (*) [16])(param_1 + 0x240);
  *(undefined1 *)(param_1 + 0x238) = (undefined1)local_80;
  local_80 = CONCAT71(local_80._1_7_,uVar15);
  uVar2 = *(undefined8 *)(param_1 + 0x250);
  auVar14 = *(undefined1 (*) [16])(param_1 + 600);
  *(undefined8 *)(param_1 + 0x250) = local_68;
  uVar15 = *(undefined1 *)(param_1 + 0x268);
  *(undefined8 *)(param_1 + 0x240) = local_78._0_8_;
  *(undefined8 *)(param_1 + 0x248) = local_78._8_8_;
  *(undefined1 *)(param_1 + 0x268) = (undefined1)local_50;
  local_50 = CONCAT71(local_50._1_7_,uVar15);
  *(undefined8 *)(param_1 + 600) = local_60._0_8_;
  *(undefined8 *)(param_1 + 0x260) = local_60._8_8_;
  local_e8 = auVar8;
  local_d8 = auVar9;
  local_c8 = uVar23;
  local_c0 = auVar10;
  local_a8 = auVar11;
  local_98 = uVar1;
  local_90 = auVar12;
  local_78 = auVar13;
  local_68 = uVar2;
  local_60 = auVar14;
  if (pvVar4 != (void *)0x0) {
    operator_delete__(pvVar4);
    pvVar21 = (void *)local_a8._0_8_;
  }
  if (pvVar21 != (void *)0x0) {
    operator_delete__(pvVar21);
  }
  if ((void *)local_d8._0_8_ != (void *)0x0) {
    operator_delete__((void *)local_d8._0_8_);
  }
  if ((void *)local_118._0_8_ != (void *)0x0) {
    operator_delete__((void *)local_118._0_8_);
  }
  if (local_130._0_8_ != 0) {
    uVar30 = 0;
    uVar18 = 0;
    do {
      for (; (*(ulong *)(*(long *)(param_1 + 0x1b0) + (uVar18 >> 6) * 8) >> (uVar18 & 0x3f) & 1) ==
             0; uVar18 = uVar18 + 1) {
      }
      *(char *)(*(long *)(param_1 + 0x278) + uVar18) =
           (char)*(undefined4 *)(local_148._8_8_ + uVar30 * 4);
      uVar18 = uVar18 + 1;
      puVar19 = (uint *)(local_148._8_8_ + uVar30 * 4);
      *puVar19 = *puVar19 >> 8;
      uVar30 = uVar30 + 1;
    } while (uVar30 < (ulong)local_130._0_8_);
    if (local_130._0_8_ != 0) {
      if (local_130._0_8_ - 1 < 3) {
        uVar16 = 0;
        uVar18 = 0;
LAB_00120633:
        if (uVar16 < local_138[uVar18]) {
          uVar16 = local_138[uVar18];
        }
        if (uVar18 + 1 < (ulong)local_130._0_8_) {
          if (uVar16 < local_138[uVar18 + 1]) {
            uVar16 = local_138[uVar18 + 1];
          }
          if ((uVar18 + 2 < (ulong)local_130._0_8_) && (uVar16 < local_138[uVar18 + 2])) {
            uVar16 = local_138[uVar18 + 2];
          }
        }
      }
      else {
        uVar16 = 0;
        uVar25 = 0;
        uVar26 = 0;
        uVar37 = 0;
        puVar19 = local_138;
        do {
          uVar36 = *puVar19;
          puVar5 = puVar19 + 1;
          puVar6 = puVar19 + 2;
          puVar7 = puVar19 + 3;
          puVar19 = puVar19 + 4;
          uVar32 = -(uint)((int)(uVar16 - _DAT_0012a670) < (int)(uVar36 - _DAT_0012a670));
          uVar33 = -(uint)((int)(uVar25 - _UNK_0012a674) < (int)(*puVar5 - _UNK_0012a674));
          uVar34 = -(uint)((int)(uVar26 - _UNK_0012a678) < (int)(*puVar6 - _UNK_0012a678));
          uVar35 = -(uint)((int)(uVar37 - _UNK_0012a67c) < (int)(*puVar7 - _UNK_0012a67c));
          uVar16 = ~uVar32 & uVar16 | uVar36 & uVar32;
          uVar25 = ~uVar33 & uVar25 | *puVar5 & uVar33;
          uVar26 = ~uVar34 & uVar26 | *puVar6 & uVar34;
          uVar37 = ~uVar35 & uVar37 | *puVar7 & uVar35;
        } while (puVar19 != local_138 + (local_130._0_8_ & 0xfffffffffffffffc));
        uVar18 = local_130._0_8_ & 0xfffffffffffffffc;
        uVar36 = -(uint)((int)(uVar16 - _DAT_0012a670) < (int)(uVar26 - _DAT_0012a670));
        uVar32 = -(uint)((int)(uVar25 - _UNK_0012a674) < (int)(uVar37 - _UNK_0012a674));
        uVar26 = ~uVar36 & uVar16 | uVar26 & uVar36;
        uVar25 = ~uVar32 & uVar25 | uVar37 & uVar32;
        uVar16 = -(uint)((int)(uVar26 - _DAT_0012a670) < (int)(uVar25 - _DAT_0012a670));
        uVar16 = ~uVar16 & uVar26 | uVar25 & uVar16;
        if ((local_130._0_8_ & 3) != 0) goto LAB_00120633;
      }
      if (uVar16 == 0) {
LAB_00120681:
        lVar28 = 0;
        uVar18 = 0;
        puVar20 = operator_new__(8,(nothrow_t *)PTR_nothrow_00132fb8);
        *puVar20 = 0;
        local_168 = local_130._0_8_;
        puVar22 = (undefined8 *)0x1;
      }
      else {
        lVar28 = 0;
        do {
          lVar28 = lVar28 + 1;
          uVar16 = uVar16 >> 1;
        } while (uVar16 != 0);
        if (lVar28 == 0) goto LAB_00120681;
        puVar22 = (undefined8 *)(local_130._0_8_ * lVar28 + 0x3fU >> 6);
        if (puVar22 == (undefined8 *)0x0) {
          puVar20 = (undefined8 *)0x0;
        }
        else {
          puVar20 = operator_new__((long)puVar22 * 8,(nothrow_t *)PTR_nothrow_00132fb8);
          puVar20[(long)puVar22 + -1] = 0;
        }
        uVar18 = (ulong)(0xffffffff >> (0x20U - (char)lVar28 & 0x1f));
        local_168 = local_130._0_8_;
      }
      uVar16 = (uint)uVar18;
      if (local_168 != 0) {
        uVar30 = 0;
        puVar19 = local_138;
        do {
          uVar26 = (uint)uVar30 & 0x3f;
          uVar25 = *puVar19;
          sVar24 = (sbyte)uVar26;
          puVar20[uVar30 >> 6] =
               ~(uVar18 << sVar24) & puVar20[uVar30 >> 6] | (ulong)(uVar16 & uVar25) << sVar24;
          if (0x40 < (ulong)uVar26 + lVar28) {
            puVar20[(uVar30 >> 6) + 1] =
                 ~(uVar18 >> (-sVar24 & 0x3fU)) & puVar20[(uVar30 >> 6) + 1] |
                 (ulong)((uVar16 & uVar25) >> (-sVar24 & 0x3fU));
          }
          puVar19 = puVar19 + 1;
          uVar30 = uVar30 + lVar28;
        } while (puVar19 != local_138 + local_168);
      }
      goto LAB_0012075f;
    }
  }
  puVar22 = (undefined8 *)0x0;
  lVar28 = 0;
  uVar16 = 0;
  local_168 = 0;
  puVar20 = puVar22;
LAB_0012075f:
  pvVar21 = *(void **)(param_1 + 0x2a0);
  *(undefined8 **)(param_1 + 0x2b0) = puVar20;
  *(undefined1 *)(param_1 + 0x2c8) = 0;
  *(long *)(param_1 + 0x2d0) = lVar28;
  *(uint *)(param_1 + 0x2d8) = uVar16;
  *(ulong *)(param_1 + 0x2e0) = local_168;
  *(undefined8 **)(param_1 + 0x2a0) = puVar20;
  *(undefined8 **)(param_1 + 0x2a8) = puVar20;
  *(undefined8 **)(param_1 + 0x2b8) = puVar22;
  *(undefined8 **)(param_1 + 0x2c0) = puVar22;
  if (pvVar21 != (void *)0x0) {
    operator_delete__(pvVar21);
  }
  FUN_00113a40(param_1);
  if ((void *)local_148._0_8_ != (void *)0x0) {
    operator_delete__((void *)local_148._0_8_);
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


//===== FUN_00120d60 @ 00120d60 size=3170 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00120d60(long param_1,long param_2,undefined8 param_3,long param_4,undefined8 param_5)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  void *pvVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 uVar15;
  uint uVar16;
  undefined4 uVar17;
  ulong uVar18;
  uint *puVar19;
  undefined8 *puVar20;
  void *pvVar21;
  undefined8 *puVar22;
  undefined8 uVar23;
  sbyte sVar24;
  uint uVar25;
  uint uVar26;
  long lVar27;
  long lVar28;
  undefined4 uVar29;
  ulong uVar30;
  undefined4 uVar31;
  long in_FS_OFFSET;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  ulong local_168;
  undefined1 local_148 [16];
  uint *local_138;
  undefined1 local_130 [16];
  undefined1 local_120;
  undefined1 local_118 [16];
  undefined8 local_108;
  undefined1 local_100 [16];
  undefined8 local_f0;
  undefined1 local_e8 [16];
  undefined1 local_d8 [16];
  undefined8 local_c8;
  undefined1 local_c0 [16];
  undefined8 local_b0;
  undefined1 local_a8 [16];
  undefined8 local_98;
  undefined1 local_90 [16];
  undefined8 local_80;
  undefined1 local_78 [16];
  undefined8 local_68;
  undefined1 local_60 [16];
  undefined8 local_50;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_0011b730();
  local_138 = (uint *)0x0;
  local_120 = 0;
  local_148 = (undefined1  [16])0x0;
  local_130 = (undefined1  [16])0x0;
  if (*(long *)(param_2 + 0x18) != 0) {
    FUN_00117750(param_1,param_2,local_148,param_4,param_5);
  }
  lVar28 = *(long *)(param_1 + 1000);
  if (lVar28 == 0) {
    uVar16 = *(uint *)(param_4 + 0x10) | *(uint *)(param_4 + 8);
    uVar25 = uVar16 | (-(uint)(*(long *)(param_1 + 0x348) == 0) & 0xfffff000) + 0x2000;
    if ((uVar25 & 0xfff00000) != 0) {
      puVar20 = (undefined8 *)__cxa_allocate_exception(0x20);
      *puVar20 = &PTR_FUN_00132da8;
      puVar20[1] = "../src_udic/marisa_u/grimoire/trie/config.h";
      puVar20[2] = 0x50000003a;
      puVar20[3] = 
      "../src_udic/marisa_u/grimoire/trie/config.h:58: MARISA_CODE_ERROR: (config_flags & ~MARISA_CONFIG_MASK) != 0"
      ;
                    /* WARNING: Subroutine does not return */
      __cxa_throw(puVar20,&PTR_vtable_00132d80,FUN_0010e6a0);
    }
    uVar26 = uVar16 & 0xf80;
    if (uVar26 == 0x200) {
LAB_001216a8:
      uVar17 = 0x200;
      if ((uVar25 & 0xf000) != 0x1000) goto LAB_00121642;
LAB_001216bd:
      uVar31 = 0x1000;
    }
    else {
      if (uVar26 < 0x201) {
        if (uVar26 == 0x80) {
          uVar17 = 0x80;
        }
        else {
          if (uVar26 != 0x100) {
            if (uVar26 != 0) goto LAB_00121903;
            goto LAB_001216a8;
          }
          uVar17 = 0x100;
        }
      }
      else if (uVar26 == 0x400) {
        uVar17 = 0x400;
      }
      else {
        if (uVar26 != 0x800) {
LAB_00121903:
          puVar20 = (undefined8 *)__cxa_allocate_exception(0x20);
          *puVar20 = &PTR_FUN_00132da8;
          puVar20[1] = "../src_udic/marisa_u/grimoire/trie/config.h";
          puVar20[2] = 0x500000065;
          puVar20[3] = 
          "../src_udic/marisa_u/grimoire/trie/config.h:101: MARISA_CODE_ERROR: undefined cache level"
          ;
                    /* WARNING: Subroutine does not return */
          __cxa_throw(puVar20,&PTR_vtable_00132d80,FUN_0010e6a0);
        }
        uVar17 = 0x800;
      }
      if ((uVar25 & 0xf000) == 0x1000) goto LAB_001216bd;
LAB_00121642:
      uVar31 = 0x2000;
      if (((uVar25 & 0xf000) != 0x2000) && (uVar31 = 0x1000, (uVar25 & 0xf000) != 0)) {
        puVar20 = (undefined8 *)__cxa_allocate_exception(0x20);
        *puVar20 = &PTR_FUN_00132da8;
        puVar20[1] = "../src_udic/marisa_u/grimoire/trie/config.h";
        puVar20[2] = 0x500000079;
        puVar20[3] = 
        "../src_udic/marisa_u/grimoire/trie/config.h:121: MARISA_CODE_ERROR: undefined tail mode";
                    /* WARNING: Subroutine does not return */
        __cxa_throw(puVar20,&PTR_vtable_00132d80,FUN_0010e6a0);
      }
    }
    if ((uVar25 & 0xf0000) == 0x10000) {
      uVar29 = 0x10000;
    }
    else {
      uVar29 = 0x20000;
      if ((uVar25 & 0xd0000) != 0) {
        puVar20 = (undefined8 *)__cxa_allocate_exception(0x20);
        *puVar20 = &PTR_FUN_00132da8;
        puVar20[1] = "../src_udic/marisa_u/grimoire/trie/config.h";
        puVar20[2] = 0x50000008d;
        puVar20[3] = 
        "../src_udic/marisa_u/grimoire/trie/config.h:141: MARISA_CODE_ERROR: undefined node order";
                    /* WARNING: Subroutine does not return */
        __cxa_throw(puVar20,&PTR_vtable_00132d80,FUN_0010e6a0);
      }
    }
    *(ulong *)(param_1 + 0x430) = (ulong)(uVar16 & 0x7f | 1);
    *(undefined4 *)(param_1 + 0x440) = uVar29;
    *(ulong *)(param_1 + 0x438) = CONCAT44(uVar31,uVar17);
  }
  else {
    uVar16 = *(uint *)(lVar28 + 0x43c) | *(uint *)(lVar28 + 0x440) |
             (int)*(undefined8 *)(lVar28 + 0x430) + 1U;
    if ((uVar16 & 0xfff00000) != 0) {
      puVar20 = (undefined8 *)__cxa_allocate_exception(0x20);
      *puVar20 = &PTR_FUN_00132da8;
      puVar20[1] = "../src_udic/marisa_u/grimoire/trie/config.h";
      puVar20[2] = 0x50000003a;
      puVar20[3] = 
      "../src_udic/marisa_u/grimoire/trie/config.h:58: MARISA_CODE_ERROR: (config_flags & ~MARISA_CONFIG_MASK) != 0"
      ;
                    /* WARNING: Subroutine does not return */
      __cxa_throw(puVar20,&PTR_vtable_00132d80,FUN_0010e6a0);
    }
    uVar25 = uVar16 & 0x7f;
    if (uVar25 == 0) {
      uVar25 = 3;
    }
    uVar26 = uVar16 & 0xf80;
    if (uVar26 == 0x200) {
LAB_00121507:
      uVar17 = 0x200;
LAB_00120e60:
      if ((uVar16 & 0xf000) != 0x1000) goto LAB_00120e74;
LAB_001214f5:
      uVar31 = 0x1000;
    }
    else {
      if (uVar26 < 0x201) {
        if (uVar26 == 0x80) {
          uVar17 = 0x80;
        }
        else {
          if (uVar26 != 0x100) {
            if (uVar26 != 0) goto LAB_00121963;
            goto LAB_00121507;
          }
          uVar17 = 0x100;
        }
        goto LAB_00120e60;
      }
      if (uVar26 == 0x400) {
        uVar17 = 0x400;
        goto LAB_00120e60;
      }
      if (uVar26 != 0x800) {
LAB_00121963:
        puVar20 = (undefined8 *)__cxa_allocate_exception(0x20);
        *puVar20 = &PTR_FUN_00132da8;
        puVar20[1] = "../src_udic/marisa_u/grimoire/trie/config.h";
        puVar20[2] = 0x500000065;
        puVar20[3] = 
        "../src_udic/marisa_u/grimoire/trie/config.h:101: MARISA_CODE_ERROR: undefined cache level";
                    /* WARNING: Subroutine does not return */
        __cxa_throw(puVar20,&PTR_vtable_00132d80,FUN_0010e6a0);
      }
      uVar17 = 0x800;
      if ((uVar16 & 0xf000) == 0x1000) goto LAB_001214f5;
LAB_00120e74:
      uVar31 = 0x2000;
      if (((uVar16 & 0xf000) != 0x2000) && (uVar31 = 0x1000, (uVar16 & 0xf000) != 0)) {
        puVar20 = (undefined8 *)__cxa_allocate_exception(0x20);
        *puVar20 = &PTR_FUN_00132da8;
        puVar20[1] = "../src_udic/marisa_u/grimoire/trie/config.h";
        puVar20[2] = 0x500000079;
        puVar20[3] = 
        "../src_udic/marisa_u/grimoire/trie/config.h:121: MARISA_CODE_ERROR: undefined tail mode";
                    /* WARNING: Subroutine does not return */
        __cxa_throw(puVar20,&PTR_vtable_00132d80,FUN_0010e6a0);
      }
    }
    if ((uVar16 & 0xf0000) == 0x10000) {
      uVar29 = 0x10000;
    }
    else {
      uVar29 = 0x20000;
      if ((uVar16 & 0xd0000) != 0) {
        puVar20 = (undefined8 *)__cxa_allocate_exception(0x20);
        *puVar20 = &PTR_FUN_00132da8;
        puVar20[1] = "../src_udic/marisa_u/grimoire/trie/config.h";
        puVar20[2] = 0x50000008d;
        puVar20[3] = 
        "../src_udic/marisa_u/grimoire/trie/config.h:141: MARISA_CODE_ERROR: undefined node order";
                    /* WARNING: Subroutine does not return */
        __cxa_throw(puVar20,&PTR_vtable_00132d80,FUN_0010e6a0);
      }
    }
    *(long *)(param_1 + 0x430) = (long)(int)uVar25;
    *(undefined4 *)(param_1 + 0x440) = uVar29;
    *(ulong *)(param_1 + 0x438) = CONCAT44(uVar31,uVar17);
  }
  local_108 = 0;
  local_f0 = 0;
  local_c8 = 0;
  local_b0 = 0;
  local_98 = 0;
  local_80 = 0;
  local_68 = 0;
  local_50 = 0;
  local_118 = (undefined1  [16])0x0;
  local_100 = (undefined1  [16])0x0;
  local_e8 = (undefined1  [16])0x0;
  local_d8 = (undefined1  [16])0x0;
  local_c0 = (undefined1  [16])0x0;
  local_a8 = (undefined1  [16])0x0;
  local_90 = (undefined1  [16])0x0;
  local_78 = (undefined1  [16])0x0;
  local_60 = (undefined1  [16])0x0;
  FUN_00126020(local_118,param_1 + 0x1a0,0,0);
  if (*(char *)(param_1 + 0x1c8) != '\0') {
    uVar23 = FUN_001065cc();
    FUN_00119540(local_118);
    if ((void *)local_148._0_8_ != (void *)0x0) {
      operator_delete__((void *)local_148._0_8_);
    }
                    /* WARNING: Subroutine does not return */
    _Unwind_Resume(uVar23);
  }
  lVar28 = *(long *)(param_1 + 0x1b8);
  uVar15 = 0;
  if (lVar28 != *(long *)(param_1 + 0x1c0)) {
    pvVar21 = operator_new__(lVar28 * 8,(nothrow_t *)PTR_nothrow_00132fb8);
    uVar18 = *(ulong *)(param_1 + 0x1b8);
    if (uVar18 != 0) {
      lVar3 = *(long *)(param_1 + 0x1a8);
      if ((pvVar21 == (void *)(lVar3 + 8)) || (uVar18 - 1 < 3)) {
        uVar30 = 0;
        do {
          *(undefined8 *)((long)pvVar21 + uVar30 * 8) = *(undefined8 *)(lVar3 + uVar30 * 8);
          uVar30 = uVar30 + 1;
        } while (uVar18 != uVar30);
      }
      else {
        lVar27 = 0;
        do {
          uVar23 = ((undefined8 *)(lVar3 + lVar27))[1];
          *(undefined8 *)((long)pvVar21 + lVar27) = *(undefined8 *)(lVar3 + lVar27);
          ((undefined8 *)((long)pvVar21 + lVar27))[1] = uVar23;
          lVar27 = lVar27 + 0x10;
        } while ((uVar18 >> 1) * 0x10 != lVar27);
        if ((uVar18 & 1) != 0) {
          *(undefined8 *)((long)pvVar21 + (uVar18 & 0xfffffffffffffffe) * 8) =
               *(undefined8 *)(lVar3 + (uVar18 & 0xfffffffffffffffe) * 8);
        }
      }
    }
    pvVar4 = *(void **)(param_1 + 0x1a0);
    *(void **)(param_1 + 0x1b0) = pvVar21;
    *(long *)(param_1 + 0x1c0) = lVar28;
    *(void **)(param_1 + 0x1a0) = pvVar21;
    *(void **)(param_1 + 0x1a8) = pvVar21;
    if (pvVar4 != (void *)0x0) {
      operator_delete__(pvVar4);
    }
    uVar15 = *(undefined1 *)(param_1 + 0x1c8);
  }
  auVar8 = *(undefined1 (*) [16])(param_1 + 0x1d0);
  *(undefined1 *)(param_1 + 0x1c8) = uVar15;
  uVar23 = *(undefined8 *)(param_1 + 0x1f0);
  *(undefined8 *)(param_1 + 0x1f0) = local_c8;
  auVar9 = *(undefined1 (*) [16])(param_1 + 0x1e0);
  *(undefined8 *)(param_1 + 0x1d0) = local_e8._0_8_;
  *(undefined8 *)(param_1 + 0x1d8) = local_e8._8_8_;
  auVar10 = *(undefined1 (*) [16])(param_1 + 0x1f8);
  uVar15 = *(undefined1 *)(param_1 + 0x208);
  pvVar21 = *(void **)*(undefined1 (*) [16])(param_1 + 0x210);
  auVar11 = *(undefined1 (*) [16])(param_1 + 0x210);
  *(undefined1 *)(param_1 + 0x208) = (undefined1)local_b0;
  local_b0 = CONCAT71(local_b0._1_7_,uVar15);
  uVar1 = *(undefined8 *)(param_1 + 0x220);
  *(undefined8 *)(param_1 + 0x1e0) = local_d8._0_8_;
  *(undefined8 *)(param_1 + 0x1e8) = local_d8._8_8_;
  auVar12 = *(undefined1 (*) [16])(param_1 + 0x228);
  *(undefined8 *)(param_1 + 0x220) = local_98;
  *(undefined8 *)(param_1 + 0x1f8) = local_c0._0_8_;
  *(undefined8 *)(param_1 + 0x200) = local_c0._8_8_;
  *(undefined8 *)(param_1 + 0x210) = local_a8._0_8_;
  *(undefined8 *)(param_1 + 0x218) = local_a8._8_8_;
  *(undefined8 *)(param_1 + 0x228) = local_90._0_8_;
  *(undefined8 *)(param_1 + 0x230) = local_90._8_8_;
  uVar15 = *(undefined1 *)(param_1 + 0x238);
  pvVar4 = *(void **)*(undefined1 (*) [16])(param_1 + 0x240);
  auVar13 = *(undefined1 (*) [16])(param_1 + 0x240);
  *(undefined1 *)(param_1 + 0x238) = (undefined1)local_80;
  local_80 = CONCAT71(local_80._1_7_,uVar15);
  uVar2 = *(undefined8 *)(param_1 + 0x250);
  auVar14 = *(undefined1 (*) [16])(param_1 + 600);
  *(undefined8 *)(param_1 + 0x250) = local_68;
  uVar15 = *(undefined1 *)(param_1 + 0x268);
  *(undefined8 *)(param_1 + 0x240) = local_78._0_8_;
  *(undefined8 *)(param_1 + 0x248) = local_78._8_8_;
  *(undefined1 *)(param_1 + 0x268) = (undefined1)local_50;
  local_50 = CONCAT71(local_50._1_7_,uVar15);
  *(undefined8 *)(param_1 + 600) = local_60._0_8_;
  *(undefined8 *)(param_1 + 0x260) = local_60._8_8_;
  local_e8 = auVar8;
  local_d8 = auVar9;
  local_c8 = uVar23;
  local_c0 = auVar10;
  local_a8 = auVar11;
  local_98 = uVar1;
  local_90 = auVar12;
  local_78 = auVar13;
  local_68 = uVar2;
  local_60 = auVar14;
  if (pvVar4 != (void *)0x0) {
    operator_delete__(pvVar4);
    pvVar21 = (void *)local_a8._0_8_;
  }
  if (pvVar21 != (void *)0x0) {
    operator_delete__(pvVar21);
  }
  if ((void *)local_d8._0_8_ != (void *)0x0) {
    operator_delete__((void *)local_d8._0_8_);
  }
  if ((void *)local_118._0_8_ != (void *)0x0) {
    operator_delete__((void *)local_118._0_8_);
  }
  if (local_130._0_8_ != 0) {
    uVar30 = 0;
    uVar18 = 0;
    do {
      for (; (*(ulong *)(*(long *)(param_1 + 0x1b0) + (uVar18 >> 6) * 8) >> (uVar18 & 0x3f) & 1) ==
             0; uVar18 = uVar18 + 1) {
      }
      *(char *)(*(long *)(param_1 + 0x278) + uVar18) =
           (char)*(undefined4 *)(local_148._8_8_ + uVar30 * 4);
      uVar18 = uVar18 + 1;
      puVar19 = (uint *)(local_148._8_8_ + uVar30 * 4);
      *puVar19 = *puVar19 >> 8;
      uVar30 = uVar30 + 1;
    } while (uVar30 < (ulong)local_130._0_8_);
    if (local_130._0_8_ != 0) {
      if (local_130._0_8_ - 1 < 3) {
        uVar16 = 0;
        uVar18 = 0;
LAB_001212c3:
        if (uVar16 < local_138[uVar18]) {
          uVar16 = local_138[uVar18];
        }
        if (uVar18 + 1 < (ulong)local_130._0_8_) {
          if (uVar16 < local_138[uVar18 + 1]) {
            uVar16 = local_138[uVar18 + 1];
          }
          if ((uVar18 + 2 < (ulong)local_130._0_8_) && (uVar16 < local_138[uVar18 + 2])) {
            uVar16 = local_138[uVar18 + 2];
          }
        }
      }
      else {
        uVar16 = 0;
        uVar25 = 0;
        uVar26 = 0;
        uVar37 = 0;
        puVar19 = local_138;
        do {
          uVar36 = *puVar19;
          puVar5 = puVar19 + 1;
          puVar6 = puVar19 + 2;
          puVar7 = puVar19 + 3;
          puVar19 = puVar19 + 4;
          uVar32 = -(uint)((int)(uVar16 - _DAT_0012a670) < (int)(uVar36 - _DAT_0012a670));
          uVar33 = -(uint)((int)(uVar25 - _UNK_0012a674) < (int)(*puVar5 - _UNK_0012a674));
          uVar34 = -(uint)((int)(uVar26 - _UNK_0012a678) < (int)(*puVar6 - _UNK_0012a678));
          uVar35 = -(uint)((int)(uVar37 - _UNK_0012a67c) < (int)(*puVar7 - _UNK_0012a67c));
          uVar16 = ~uVar32 & uVar16 | uVar36 & uVar32;
          uVar25 = ~uVar33 & uVar25 | *puVar5 & uVar33;
          uVar26 = ~uVar34 & uVar26 | *puVar6 & uVar34;
          uVar37 = ~uVar35 & uVar37 | *puVar7 & uVar35;
        } while (puVar19 != local_138 + (local_130._0_8_ & 0xfffffffffffffffc));
        uVar18 = local_130._0_8_ & 0xfffffffffffffffc;
        uVar36 = -(uint)((int)(uVar16 - _DAT_0012a670) < (int)(uVar26 - _DAT_0012a670));
        uVar32 = -(uint)((int)(uVar25 - _UNK_0012a674) < (int)(uVar37 - _UNK_0012a674));
        uVar26 = ~uVar36 & uVar16 | uVar26 & uVar36;
        uVar25 = ~uVar32 & uVar25 | uVar37 & uVar32;
        uVar16 = -(uint)((int)(uVar26 - _DAT_0012a670) < (int)(uVar25 - _DAT_0012a670));
        uVar16 = ~uVar16 & uVar26 | uVar25 & uVar16;
        if ((local_130._0_8_ & 3) != 0) goto LAB_001212c3;
      }
      if (uVar16 == 0) {
LAB_00121311:
        lVar28 = 0;
        uVar18 = 0;
        puVar20 = operator_new__(8,(nothrow_t *)PTR_nothrow_00132fb8);
        *puVar20 = 0;
        local_168 = local_130._0_8_;
        puVar22 = (undefined8 *)0x1;
      }
      else {
        lVar28 = 0;
        do {
          lVar28 = lVar28 + 1;
          uVar16 = uVar16 >> 1;
        } while (uVar16 != 0);
        if (lVar28 == 0) goto LAB_00121311;
        puVar22 = (undefined8 *)(local_130._0_8_ * lVar28 + 0x3fU >> 6);
        if (puVar22 == (undefined8 *)0x0) {
          puVar20 = (undefined8 *)0x0;
        }
        else {
          puVar20 = operator_new__((long)puVar22 * 8,(nothrow_t *)PTR_nothrow_00132fb8);
          puVar20[(long)puVar22 + -1] = 0;
        }
        uVar18 = (ulong)(0xffffffff >> (0x20U - (char)lVar28 & 0x1f));
        local_168 = local_130._0_8_;
      }
      uVar16 = (uint)uVar18;
      if (local_168 != 0) {
        uVar30 = 0;
        puVar19 = local_138;
        do {
          uVar26 = (uint)uVar30 & 0x3f;
          uVar25 = *puVar19;
          sVar24 = (sbyte)uVar26;
          puVar20[uVar30 >> 6] =
               ~(uVar18 << sVar24) & puVar20[uVar30 >> 6] | (ulong)(uVar16 & uVar25) << sVar24;
          if (0x40 < (ulong)uVar26 + lVar28) {
            puVar20[(uVar30 >> 6) + 1] =
                 ~(uVar18 >> (-sVar24 & 0x3fU)) & puVar20[(uVar30 >> 6) + 1] |
                 (ulong)((uVar16 & uVar25) >> (-sVar24 & 0x3fU));
          }
          puVar19 = puVar19 + 1;
          uVar30 = uVar30 + lVar28;
        } while (puVar19 != local_138 + local_168);
      }
      goto LAB_001213ef;
    }
  }
  puVar22 = (undefined8 *)0x0;
  lVar28 = 0;
  uVar16 = 0;
  local_168 = 0;
  puVar20 = puVar22;
LAB_001213ef:
  pvVar21 = *(void **)(param_1 + 0x2a0);
  *(undefined8 **)(param_1 + 0x2b0) = puVar20;
  *(undefined1 *)(param_1 + 0x2c8) = 0;
  *(long *)(param_1 + 0x2d0) = lVar28;
  *(uint *)(param_1 + 0x2d8) = uVar16;
  *(ulong *)(param_1 + 0x2e0) = local_168;
  *(undefined8 **)(param_1 + 0x2a0) = puVar20;
  *(undefined8 **)(param_1 + 0x2a8) = puVar20;
  *(undefined8 **)(param_1 + 0x2b8) = puVar22;
  *(undefined8 **)(param_1 + 0x2c0) = puVar22;
  if (pvVar21 != (void *)0x0) {
    operator_delete__(pvVar21);
  }
  FUN_00113a40(param_1);
  if ((void *)local_148._0_8_ != (void *)0x0) {
    operator_delete__((void *)local_148._0_8_);
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


//===== FUN_001219f0 @ 001219f0 size=1720 =====

void FUN_001219f0(long *param_1,long *param_2,ulong param_3)

{
  undefined8 *puVar1;
  byte bVar2;
  byte bVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  bool bVar7;
  undefined4 uVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  long *plVar18;
  long lVar19;
  long lVar20;
  long lVar21;
  long lVar22;
  long lVar23;
  long lVar24;
  long lVar25;
  long lVar26;
  uint uVar27;
  long *plVar28;
  long lVar29;
  uint uVar30;
  long *plVar31;
  long lVar32;
  long *plVar33;
  undefined8 *puVar34;
  long *plVar35;
  uint uVar36;
  long *plVar37;
  ulong uVar38;
  long lVar39;
  long *plVar40;
  long *plVar41;
  uint uVar42;
  uint uVar43;
  long *plVar44;
  long *plVar45;
  
  lVar29 = (long)param_2 - (long)param_1;
LAB_00121a0d:
  lVar32 = lVar29;
  plVar44 = param_1;
  plVar45 = param_1;
  plVar37 = param_2;
  plVar35 = param_2;
  if (0xa0 < lVar29) {
    do {
      if (param_3 < *(uint *)(plVar44 + 1)) {
        uVar30 = (uint)*(byte *)(*plVar44 - param_3);
      }
      else {
        uVar30 = 0xffffffff;
      }
      if (param_3 < *(uint *)(plVar44 + (lVar32 >> 5) * 2 + 1)) {
        bVar2 = *(byte *)(plVar44[(lVar32 >> 5) * 2] + -param_3);
        uVar42 = (uint)bVar2;
        if (param_3 < *(uint *)(plVar37 + -1)) {
          bVar3 = *(byte *)(plVar37[-2] + -param_3);
          uVar27 = (uint)bVar3;
          uVar36 = (uint)bVar2;
          if ((int)uVar42 <= (int)uVar30) goto LAB_00121e8c;
          uVar43 = (uint)bVar2;
          if (bVar3 <= uVar42) goto LAB_00121a78;
        }
        else {
          uVar36 = 0xffffffff;
          uVar27 = 0xffffffff;
          if ((int)uVar42 <= (int)uVar30) goto LAB_00121e90;
LAB_00121a78:
          uVar43 = uVar27;
          if ((int)uVar27 <= (int)uVar30) {
            uVar43 = uVar30;
          }
        }
      }
      else {
        if (param_3 < *(uint *)(plVar37 + -1)) {
          uVar27 = (uint)*(byte *)(plVar37[-2] - param_3);
          uVar36 = 0xffffffff;
LAB_00121e8c:
          uVar42 = uVar36;
          uVar43 = uVar30;
          uVar36 = uVar27;
          if ((int)uVar30 < (int)uVar27) goto LAB_00121a80;
        }
        else {
          uVar36 = 0xffffffff;
          uVar42 = 0xffffffff;
        }
LAB_00121e90:
        uVar43 = uVar42;
        if ((int)uVar42 < (int)uVar36) {
          uVar43 = uVar36;
        }
      }
LAB_00121a80:
      plVar35 = plVar37;
      if (plVar44 < plVar37) {
        plVar31 = plVar44;
        plVar33 = plVar37;
        plVar40 = plVar44;
        plVar28 = plVar44;
        do {
          plVar28 = plVar28 + 2;
          uVar30 = *(uint *)(plVar31 + 1);
          plVar41 = plVar40;
          if (param_3 < uVar30) {
            bVar2 = *(byte *)(*plVar31 + -param_3);
            uVar36 = (uint)bVar2;
            if ((int)(uint)bVar2 <= (int)uVar43) goto LAB_00121df8;
            while( true ) {
              plVar18 = plVar35;
              plVar35 = plVar18;
              plVar45 = plVar31;
              if (plVar18 <= plVar31) goto LAB_00121b65;
              uVar30 = *(uint *)(plVar18 + -1);
              plVar35 = plVar18 + -2;
              if (param_3 < uVar30) {
                uVar36 = (uint)*(byte *)(*plVar35 + -param_3);
              }
              else {
                uVar36 = 0xffffffff;
              }
              if ((int)uVar36 < (int)uVar43) break;
              if (uVar36 == uVar43) {
                lVar29 = *plVar35;
                uVar4 = *(undefined4 *)((long)plVar18 + -4);
                *plVar35 = plVar33[-2];
                plVar18[-1] = plVar33[-1];
                plVar33[-2] = lVar29;
                plVar33[-1] = CONCAT44(uVar4,uVar30);
                plVar33 = plVar33 + -2;
              }
            }
            if (plVar35 <= plVar31) break;
            uVar4 = *(undefined4 *)((long)plVar18 + -4);
            lVar29 = *plVar31;
            lVar32 = plVar31[1];
            *plVar31 = *plVar35;
            plVar31[1] = CONCAT44(uVar4,uVar30);
            *plVar35 = lVar29;
            plVar18[-1] = lVar32;
          }
          else {
            uVar36 = 0xffffffff;
LAB_00121df8:
            if (uVar43 == uVar36) {
              uVar4 = *(undefined4 *)((long)plVar31 + 0xc);
              plVar41 = plVar40 + 2;
              lVar29 = *plVar31;
              *plVar31 = *plVar40;
              plVar31[1] = plVar40[1];
              *plVar40 = lVar29;
              plVar40[1] = CONCAT44(uVar4,uVar30);
            }
          }
          plVar31 = plVar31 + 2;
          plVar40 = plVar41;
          plVar45 = plVar28;
        } while (plVar28 < plVar35);
LAB_00121b65:
        plVar28 = plVar40;
        plVar31 = plVar45;
        if (plVar44 < plVar40) {
          do {
            lVar29 = plVar28[-2];
            plVar41 = plVar28 + -2;
            lVar32 = plVar28[-1];
            *plVar41 = plVar31[-2];
            plVar28[-1] = plVar31[-1];
            plVar31[-2] = lVar29;
            plVar31[-1] = lVar32;
            plVar28 = plVar41;
            plVar31 = plVar31 + -2;
          } while (plVar44 < plVar41);
          plVar45 = (long *)((long)plVar45 + ((long)plVar44 - (long)plVar40 & 0xfffffffffffffff0U));
        }
        lVar39 = (long)plVar45 - (long)plVar44;
        if (plVar33 < plVar37) {
          uVar38 = (long)plVar37 + (-1 - (long)plVar33);
          plVar28 = plVar35;
          if ((plVar33 + 1 < plVar35 + 8 && plVar35 + 1 < plVar33 + 8 ||
               (ulong)((long)plVar33 + (0x37 - (long)plVar35)) < 0x6f) || (uVar38 < 0x40)) {
            do {
              lVar29 = *plVar33;
              plVar31 = plVar33 + 2;
              lVar32 = plVar33[1];
              *plVar33 = *plVar28;
              plVar33[1] = plVar28[1];
              *plVar28 = lVar29;
              plVar28[1] = lVar32;
              plVar28 = plVar28 + 2;
              plVar33 = plVar31;
            } while (plVar31 < plVar37);
          }
          else {
            plVar28 = plVar33;
            plVar31 = plVar35 + 1;
            do {
              lVar19 = plVar28[3];
              uVar4 = *(undefined4 *)((long)plVar28 + 0x1c);
              lVar20 = plVar28[1];
              uVar15 = *(undefined4 *)((long)plVar28 + 0xc);
              plVar40 = plVar28 + 8;
              lVar21 = plVar28[5];
              uVar14 = *(undefined4 *)((long)plVar28 + 0x2c);
              lVar22 = plVar28[7];
              uVar8 = *(undefined4 *)((long)plVar28 + 0x3c);
              lVar29 = plVar31[-1];
              lVar32 = plVar31[3];
              lVar9 = plVar28[4];
              lVar10 = plVar28[6];
              lVar11 = plVar31[1];
              plVar28[6] = plVar31[5];
              plVar28[4] = lVar32;
              lVar23 = plVar31[2];
              uVar12 = *(undefined4 *)((long)plVar31 + 0x14);
              lVar24 = *plVar31;
              uVar17 = *(undefined4 *)((long)plVar31 + 4);
              lVar25 = plVar31[6];
              uVar13 = *(undefined4 *)((long)plVar31 + 0x34);
              lVar32 = *plVar28;
              *plVar28 = lVar29;
              lVar26 = plVar31[4];
              uVar16 = *(undefined4 *)((long)plVar31 + 0x24);
              lVar29 = plVar28[2];
              *(int *)(plVar28 + 1) = (int)lVar24;
              *(undefined4 *)((long)plVar28 + 0xc) = uVar17;
              plVar28[2] = lVar11;
              *(int *)(plVar28 + 3) = (int)lVar23;
              *(undefined4 *)((long)plVar28 + 0x1c) = uVar12;
              *(int *)(plVar28 + 5) = (int)lVar26;
              *(undefined4 *)((long)plVar28 + 0x2c) = uVar16;
              *(int *)(plVar28 + 7) = (int)lVar25;
              *(undefined4 *)((long)plVar28 + 0x3c) = uVar13;
              plVar31[-1] = lVar32;
              plVar31[1] = lVar29;
              plVar31[3] = lVar9;
              plVar31[5] = lVar10;
              *(int *)plVar31 = (int)lVar20;
              *(undefined4 *)((long)plVar31 + 4) = uVar15;
              *(int *)(plVar31 + 2) = (int)lVar19;
              *(undefined4 *)((long)plVar31 + 0x14) = uVar4;
              *(int *)(plVar31 + 4) = (int)lVar21;
              *(undefined4 *)((long)plVar31 + 0x24) = uVar14;
              *(int *)(plVar31 + 6) = (int)lVar22;
              *(undefined4 *)((long)plVar31 + 0x34) = uVar8;
              plVar28 = plVar40;
              plVar31 = plVar31 + 8;
            } while (plVar40 != (long *)((uVar38 & 0xffffffffffffffc0) + (long)plVar33));
            puVar1 = (undefined8 *)((long)plVar35 + (uVar38 & 0xffffffffffffffc0));
            puVar34 = (undefined8 *)((long)plVar33 + (uVar38 & 0xffffffffffffffc0));
            uVar5 = puVar34[1];
            uVar6 = *puVar34;
            *puVar34 = *puVar1;
            puVar34[1] = puVar1[1];
            puVar1[1] = uVar5;
            *puVar1 = uVar6;
            if (puVar34 + 2 < plVar37) {
              uVar5 = puVar34[3];
              uVar6 = puVar34[2];
              puVar34[2] = puVar1[2];
              puVar34[3] = puVar1[3];
              puVar1[3] = uVar5;
              puVar1[2] = uVar6;
              if (puVar34 + 4 < plVar37) {
                uVar5 = puVar34[5];
                uVar6 = puVar34[4];
                puVar34[4] = puVar1[4];
                puVar34[5] = puVar1[5];
                puVar1[5] = uVar5;
                puVar1[4] = uVar6;
                if (puVar34 + 6 < plVar37) {
                  uVar5 = puVar34[6];
                  uVar6 = puVar34[7];
                  puVar34[6] = puVar1[6];
                  puVar34[7] = puVar1[7];
                  puVar1[6] = uVar5;
                  puVar1[7] = uVar6;
                }
              }
            }
          }
          plVar35 = (long *)((long)plVar35 + (uVar38 & 0xfffffffffffffff0) + 0x10);
        }
      }
      else {
        lVar39 = 0;
        plVar45 = plVar44;
      }
      lVar32 = (long)plVar35 - (long)plVar45;
      lVar29 = (long)plVar37 - (long)plVar35;
      if ((lVar32 < lVar39) || (lVar32 < lVar29)) {
        if ((uVar43 != 0xffffffff) && (0x10 < lVar32)) {
          FUN_001219f0(plVar45,plVar35,param_3 + 1);
        }
        if (lVar39 < lVar29) {
          param_1 = plVar35;
          param_2 = plVar37;
          if (0x10 < lVar39) {
            FUN_001219f0(plVar44,plVar45,param_3);
          }
        }
        else {
          bVar7 = 0x10 < lVar29;
          lVar29 = lVar39;
          param_1 = plVar44;
          param_2 = plVar45;
          if (bVar7) {
            FUN_001219f0(plVar35,plVar37,param_3);
          }
        }
        goto LAB_00121a0d;
      }
      if (0x10 < lVar39) {
        FUN_001219f0(plVar44,plVar45,param_3);
      }
      if (0x10 < lVar29) {
        FUN_001219f0(plVar35,plVar37,param_3);
      }
      if (0x10 < lVar32) goto LAB_00121ff7;
      plVar44 = plVar45;
      plVar37 = plVar35;
      if (lVar32 < 0xa1) break;
    } while( true );
  }
  if ((lVar32 < 0x11) || (plVar44 = plVar45 + 2, plVar35 <= plVar44)) {
    return;
  }
  do {
    uVar30 = *(uint *)(plVar44 + 1);
    plVar37 = plVar44;
    do {
      uVar36 = *(uint *)(plVar37 + -1);
      plVar28 = plVar37 + -2;
      lVar29 = *plVar28;
      if (param_3 < uVar36) {
        if (param_3 != uVar30) {
          lVar32 = -param_3;
          do {
            bVar2 = *(byte *)(lVar29 + lVar32);
            bVar3 = *(byte *)(*plVar37 + lVar32);
            if (bVar3 != bVar2) {
              if (bVar2 <= bVar3) goto joined_r0x00121fef;
              break;
            }
            if (lVar32 == 1 - (ulong)uVar36) goto LAB_00121fe0;
            uVar38 = 1 - lVar32;
            lVar32 = lVar32 + -1;
          } while (uVar30 != uVar38);
        }
      }
      else {
LAB_00121fe0:
        if (uVar36 <= uVar30) break;
      }
      *plVar28 = *plVar37;
      *plVar37 = lVar29;
      plVar37[1] = plVar37[-1];
      plVar37[-1] = CONCAT44(*(undefined4 *)((long)plVar37 + 0xc),uVar30);
      plVar37 = plVar28;
    } while (plVar45 < plVar28);
joined_r0x00121fef:
    plVar44 = plVar44 + 2;
    if (plVar35 <= plVar44) {
      return;
    }
  } while( true );
LAB_00121ff7:
  if (uVar43 == 0xffffffff) {
    return;
  }
  param_3 = param_3 + 1;
  lVar29 = lVar32;
  param_1 = plVar45;
  param_2 = plVar35;
  goto LAB_00121a0d;
}


//===== FUN_001220d0 @ 001220d0 size=145 =====

void FUN_001220d0(undefined1 (*param_1) [16])

{
  *(undefined8 *)param_1[1] = 0;
  param_1[2][8] = 0;
  *(undefined8 *)param_1[4] = 0;
  param_1[5][8] = 0;
  *(undefined8 *)param_1[8] = 0;
  param_1[9][8] = 0;
  *(undefined8 *)param_1[0xb] = 0;
  param_1[0xc][8] = 0;
  *(undefined8 *)param_1[0xe] = 0;
  param_1[0xf][8] = 0;
  *param_1 = (undefined1  [16])0x0;
  *(undefined1 (*) [16])(param_1[1] + 8) = (undefined1  [16])0x0;
  param_1[3] = (undefined1  [16])0x0;
  *(undefined1 (*) [16])(param_1[4] + 8) = (undefined1  [16])0x0;
  param_1[6] = (undefined1  [16])0x0;
  param_1[7] = (undefined1  [16])0x0;
  *(undefined1 (*) [16])(param_1[8] + 8) = (undefined1  [16])0x0;
  param_1[10] = (undefined1  [16])0x0;
  *(undefined1 (*) [16])(param_1[0xb] + 8) = (undefined1  [16])0x0;
  param_1[0xd] = (undefined1  [16])0x0;
  *(undefined1 (*) [16])(param_1[0xe] + 8) = (undefined1  [16])0x0;
  return;
}


//===== FUN_00122170 @ 00122170 size=514 =====

void FUN_00122170(long param_1,long param_2,ulong param_3)

{
  undefined8 *puVar1;
  void *pvVar2;
  long lVar3;
  long lVar4;
  void *pvVar5;
  char cVar6;
  ulong uVar7;
  ulong uVar8;
  char *pcVar9;
  undefined1 *puVar10;
  ulong uVar11;
  
  puVar1 = *(undefined8 **)(param_2 + 0x28);
  if (*(long *)(param_1 + 0x60) == 0) {
    pcVar9 = (char *)(*(long *)(param_1 + 0x10) + param_3);
    cVar6 = *pcVar9;
    if (cVar6 != '\0') {
      uVar8 = puVar1[3];
      do {
        uVar7 = puVar1[4];
        uVar11 = uVar8 + 1;
        if (uVar7 < uVar11) {
          if ((uVar11 >> 1 < uVar7) && (uVar11 = uVar7 * 2, (long)uVar7 < 0)) {
            uVar11 = 0xffffffffffffffff;
          }
          pvVar5 = operator_new__(uVar11,(nothrow_t *)PTR_nothrow_00132fb8);
          uVar8 = 0;
          if (puVar1[3] != 0) {
            uVar7 = 0;
            do {
              *(undefined1 *)((long)pvVar5 + uVar7) = *(undefined1 *)(puVar1[1] + uVar7);
              uVar8 = puVar1[3];
              uVar7 = uVar7 + 1;
            } while (uVar7 < uVar8);
          }
          pvVar2 = (void *)*puVar1;
          puVar1[2] = pvVar5;
          puVar1[4] = uVar11;
          *puVar1 = pvVar5;
          puVar1[1] = pvVar5;
          if (pvVar2 != (void *)0x0) {
            operator_delete__(pvVar2);
            pvVar5 = (void *)puVar1[1];
            uVar8 = puVar1[3];
          }
          cVar6 = *pcVar9;
        }
        else {
          pvVar5 = (void *)puVar1[1];
        }
        *(char *)((long)pvVar5 + uVar8) = cVar6;
        pcVar9 = pcVar9 + 1;
        uVar8 = puVar1[3] + 1;
        puVar1[3] = uVar8;
        cVar6 = *pcVar9;
      } while (cVar6 != '\0');
    }
    return;
  }
  uVar8 = puVar1[3];
  uVar7 = puVar1[4];
  puVar10 = (undefined1 *)(*(long *)(param_1 + 0x10) + param_3);
  uVar11 = uVar8 + 1;
  if (uVar11 <= uVar7) goto LAB_00122366;
  do {
    if ((uVar11 >> 1 < uVar7) && (uVar11 = uVar7 * 2, (long)uVar7 < 0)) {
      uVar11 = 0xffffffffffffffff;
    }
    pvVar5 = operator_new__(uVar11,(nothrow_t *)PTR_nothrow_00132fb8);
    uVar8 = 0;
    if (puVar1[3] != 0) {
      uVar7 = 0;
      do {
        *(undefined1 *)((long)pvVar5 + uVar7) = *(undefined1 *)(puVar1[1] + uVar7);
        uVar8 = puVar1[3];
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar8);
    }
    pvVar2 = (void *)*puVar1;
    puVar1[2] = pvVar5;
    puVar1[4] = uVar11;
    *puVar1 = pvVar5;
    puVar1[1] = pvVar5;
    uVar11 = param_3;
    if (pvVar2 != (void *)0x0) {
      operator_delete__(pvVar2);
      pvVar5 = (void *)puVar1[1];
      uVar8 = puVar1[3];
    }
    while( true ) {
      *(undefined1 *)((long)pvVar5 + uVar8) = *puVar10;
      lVar3 = puVar1[3];
      param_3 = uVar11 + 1;
      uVar8 = lVar3 + 1;
      lVar4 = *(long *)(param_1 + 0x40);
      puVar1[3] = uVar8;
      if ((*(ulong *)(lVar4 + (uVar11 >> 6) * 8) >> ((byte)uVar11 & 0x3f) & 1) != 0) {
        return;
      }
      uVar7 = puVar1[4];
      uVar11 = lVar3 + 2;
      puVar10 = (undefined1 *)(*(long *)(param_1 + 0x10) + param_3);
      if (uVar7 < uVar11) break;
LAB_00122366:
      pvVar5 = (void *)puVar1[1];
      uVar11 = param_3;
    }
  } while( true );
}


//===== FUN_00122380 @ 00122380 size=137 =====

undefined8 FUN_00122380(long param_1,long *param_2,ulong param_3)

{
  long lVar1;
  long lVar2;
  long lVar3;
  uint uVar4;
  ulong uVar5;
  char cVar6;
  long lVar7;
  
  lVar1 = param_2[5];
  lVar2 = *param_2;
  lVar3 = *(long *)(param_1 + 0x10);
  uVar4 = *(uint *)(lVar1 + 100);
  uVar5 = (ulong)uVar4;
  if (*(long *)(param_1 + 0x60) == 0) {
    cVar6 = *(char *)(lVar3 + param_3);
    lVar7 = param_3 - uVar5;
    do {
      if (*(char *)(lVar2 + uVar5) != cVar6) {
        return 0;
      }
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulong)uVar4;
      *(uint *)(lVar1 + 100) = uVar4;
      cVar6 = *(char *)(lVar3 + uVar5 + lVar7);
      if (cVar6 == '\0') {
        return 1;
      }
    } while (uVar5 < (ulong)param_2[1]);
  }
  else {
    do {
      if (*(char *)(lVar3 + param_3) != *(char *)(lVar2 + uVar5)) {
        return 0;
      }
      lVar7 = *(long *)(param_1 + 0x40);
      uVar4 = uVar4 + 1;
      *(uint *)(lVar1 + 100) = uVar4;
      if ((*(ulong *)(lVar7 + (param_3 >> 6) * 8) >> (param_3 & 0x3f) & 1) != 0) {
        return 1;
      }
      param_3 = param_3 + 1;
      uVar5 = (ulong)uVar4;
    } while (uVar5 < (ulong)param_2[1]);
  }
  return 0;
}


//===== FUN_00122420 @ 00122420 size=1033 =====

undefined8 FUN_00122420(long param_1,long *param_2,ulong param_3)

{
  uint uVar1;
  undefined8 *puVar2;
  void *pvVar3;
  void *pvVar4;
  byte bVar5;
  ulong uVar6;
  char *pcVar7;
  char cVar8;
  ulong uVar9;
  long lVar10;
  ulong uVar11;
  ulong uVar12;
  
  puVar2 = (undefined8 *)param_2[5];
  lVar10 = *(long *)(param_1 + 0x10);
  uVar11 = (ulong)*(uint *)((long)puVar2 + 100);
  if (*(long *)(param_1 + 0x60) != 0) {
    while( true ) {
      cVar8 = *(char *)(lVar10 + param_3);
      if (cVar8 != *(char *)(*param_2 + uVar11)) {
        return 0;
      }
      uVar12 = puVar2[3];
      uVar6 = puVar2[4];
      uVar11 = uVar12 + 1;
      if (uVar6 < uVar11) {
        if ((uVar11 >> 1 < uVar6) && (uVar11 = uVar6 * 2, (long)uVar6 < 0)) {
          uVar11 = 0xffffffffffffffff;
        }
        pvVar4 = operator_new__(uVar11,(nothrow_t *)PTR_nothrow_00132fb8);
        uVar12 = 0;
        if (puVar2[3] != 0) {
          uVar6 = 0;
          do {
            *(undefined1 *)((long)pvVar4 + uVar6) = *(undefined1 *)(puVar2[1] + uVar6);
            uVar12 = puVar2[3];
            uVar6 = uVar6 + 1;
          } while (uVar6 < uVar12);
        }
        pvVar3 = (void *)*puVar2;
        puVar2[2] = pvVar4;
        puVar2[4] = uVar11;
        *puVar2 = pvVar4;
        puVar2[1] = pvVar4;
        if (pvVar3 != (void *)0x0) {
          operator_delete__(pvVar3);
          pvVar4 = (void *)puVar2[1];
          uVar12 = puVar2[3];
        }
        cVar8 = *(char *)(lVar10 + param_3);
      }
      else {
        pvVar4 = (void *)puVar2[1];
      }
      *(char *)((long)pvVar4 + uVar12) = cVar8;
      uVar12 = param_3 + 1;
      uVar6 = puVar2[3] + 1;
      puVar2[3] = uVar6;
      uVar1 = *(int *)((long)puVar2 + 100) + 1;
      uVar11 = (ulong)uVar1;
      lVar10 = *(long *)(param_1 + 0x40);
      *(uint *)((long)puVar2 + 100) = uVar1;
      if ((*(ulong *)(lVar10 + (param_3 >> 6) * 8) >> (param_3 & 0x3f) & 1) != 0) break;
      if ((ulong)param_2[1] <= uVar11) {
        do {
          lVar10 = *(long *)(param_1 + 0x10);
          uVar9 = puVar2[4];
          uVar11 = uVar6 + 1;
          if (uVar9 < uVar11) {
            if ((uVar11 >> 1 < uVar9) && (uVar11 = uVar9 * 2, (long)uVar9 < 0)) {
              uVar11 = 0xffffffffffffffff;
            }
            pvVar4 = operator_new__(uVar11,(nothrow_t *)PTR_nothrow_00132fb8);
            uVar6 = 0;
            if (puVar2[3] != 0) {
              uVar9 = 0;
              do {
                *(undefined1 *)((long)pvVar4 + uVar9) = *(undefined1 *)(puVar2[1] + uVar9);
                uVar6 = puVar2[3];
                uVar9 = uVar9 + 1;
              } while (uVar9 < uVar6);
            }
            pvVar3 = (void *)*puVar2;
            puVar2[2] = pvVar4;
            puVar2[4] = uVar11;
            *puVar2 = pvVar4;
            puVar2[1] = pvVar4;
            if (pvVar3 != (void *)0x0) {
              operator_delete__(pvVar3);
              pvVar4 = (void *)puVar2[1];
              uVar6 = puVar2[3];
            }
          }
          else {
            pvVar4 = (void *)puVar2[1];
          }
          *(undefined1 *)((long)pvVar4 + uVar6) = *(undefined1 *)(lVar10 + uVar12);
          uVar11 = uVar12 >> 6;
          uVar6 = puVar2[3] + 1;
          lVar10 = *(long *)(param_1 + 0x40);
          puVar2[3] = uVar6;
          bVar5 = (byte)uVar12;
          uVar12 = uVar12 + 1;
        } while ((*(ulong *)(lVar10 + uVar11 * 8) >> (bVar5 & 0x3f) & 1) == 0);
        return 1;
      }
      lVar10 = *(long *)(param_1 + 0x10);
      param_3 = uVar12;
    }
    return 1;
  }
  cVar8 = *(char *)(lVar10 + param_3);
  lVar10 = (param_3 - uVar11) + lVar10;
  while( true ) {
    if (*(char *)(*param_2 + uVar11) != cVar8) {
      return 0;
    }
    uVar9 = puVar2[3];
    uVar6 = puVar2[4];
    uVar12 = uVar9 + 1;
    if (uVar6 < uVar12) {
      if ((uVar12 >> 1 < uVar6) && (uVar12 = uVar6 * 2, (long)uVar6 < 0)) {
        uVar12 = 0xffffffffffffffff;
      }
      pvVar4 = operator_new__(uVar12,(nothrow_t *)PTR_nothrow_00132fb8);
      uVar9 = 0;
      if (puVar2[3] != 0) {
        uVar6 = 0;
        do {
          *(undefined1 *)((long)pvVar4 + uVar6) = *(undefined1 *)(puVar2[1] + uVar6);
          uVar9 = puVar2[3];
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar9);
      }
      pvVar3 = (void *)*puVar2;
      puVar2[2] = pvVar4;
      pcVar7 = (char *)(uVar11 + lVar10);
      puVar2[4] = uVar12;
      *puVar2 = pvVar4;
      puVar2[1] = pvVar4;
      if (pvVar3 == (void *)0x0) {
        cVar8 = *pcVar7;
      }
      else {
        operator_delete__(pvVar3);
        cVar8 = *pcVar7;
        pvVar4 = (void *)puVar2[1];
        uVar9 = puVar2[3];
      }
    }
    else {
      pvVar4 = (void *)puVar2[1];
    }
    *(char *)((long)pvVar4 + uVar9) = cVar8;
    uVar12 = puVar2[3] + 1;
    puVar2[3] = uVar12;
    uVar1 = *(int *)((long)puVar2 + 100) + 1;
    uVar11 = (ulong)uVar1;
    pcVar7 = (char *)(lVar10 + uVar11);
    *(uint *)((long)puVar2 + 100) = uVar1;
    cVar8 = *pcVar7;
    if (cVar8 == '\0') break;
    if ((ulong)param_2[1] <= uVar11) {
      do {
        uVar6 = puVar2[4];
        uVar11 = uVar12 + 1;
        if (uVar6 < uVar11) {
          if ((uVar11 >> 1 < uVar6) && (uVar11 = uVar6 * 2, (long)uVar6 < 0)) {
            uVar11 = 0xffffffffffffffff;
          }
          pvVar4 = operator_new__(uVar11,(nothrow_t *)PTR_nothrow_00132fb8);
          uVar12 = 0;
          if (puVar2[3] != 0) {
            uVar6 = 0;
            do {
              *(undefined1 *)((long)pvVar4 + uVar6) = *(undefined1 *)(puVar2[1] + uVar6);
              uVar12 = puVar2[3];
              uVar6 = uVar6 + 1;
            } while (uVar6 < uVar12);
          }
          pvVar3 = (void *)*puVar2;
          puVar2[2] = pvVar4;
          puVar2[4] = uVar11;
          *puVar2 = pvVar4;
          puVar2[1] = pvVar4;
          if (pvVar3 != (void *)0x0) {
            operator_delete__(pvVar3);
            pvVar4 = (void *)puVar2[1];
            uVar12 = puVar2[3];
          }
          cVar8 = *pcVar7;
        }
        else {
          pvVar4 = (void *)puVar2[1];
        }
        *(char *)((long)pvVar4 + uVar12) = cVar8;
        pcVar7 = pcVar7 + 1;
        uVar12 = puVar2[3] + 1;
        puVar2[3] = uVar12;
        cVar8 = *pcVar7;
      } while (cVar8 != '\0');
      return 1;
    }
  }
  return 1;
}


//===== FUN_00122860 @ 00122860 size=703 =====

void FUN_00122860(undefined8 *param_1,undefined8 *param_2)

{
  undefined1 uVar1;
  undefined8 uVar2;
  
  uVar2 = *param_1;
  *param_1 = *param_2;
  *param_2 = uVar2;
  uVar2 = param_1[1];
  param_1[1] = param_2[1];
  param_2[1] = uVar2;
  uVar2 = param_1[2];
  param_1[2] = param_2[2];
  param_2[2] = uVar2;
  uVar2 = param_1[3];
  param_1[3] = param_2[3];
  param_2[3] = uVar2;
  uVar2 = param_1[4];
  param_1[4] = param_2[4];
  param_2[4] = uVar2;
  uVar1 = *(undefined1 *)(param_1 + 5);
  *(undefined1 *)(param_1 + 5) = *(undefined1 *)(param_2 + 5);
  *(undefined1 *)(param_2 + 5) = uVar1;
  uVar2 = param_1[6];
  param_1[6] = param_2[6];
  param_2[6] = uVar2;
  uVar2 = param_1[7];
  param_1[7] = param_2[7];
  param_2[7] = uVar2;
  uVar2 = param_1[8];
  param_1[8] = param_2[8];
  param_2[8] = uVar2;
  uVar2 = param_1[9];
  param_1[9] = param_2[9];
  param_2[9] = uVar2;
  uVar2 = param_1[10];
  param_1[10] = param_2[10];
  param_2[10] = uVar2;
  uVar1 = *(undefined1 *)(param_1 + 0xb);
  *(undefined1 *)(param_1 + 0xb) = *(undefined1 *)(param_2 + 0xb);
  *(undefined1 *)(param_2 + 0xb) = uVar1;
  uVar2 = param_1[0xc];
  param_1[0xc] = param_2[0xc];
  param_2[0xc] = uVar2;
  uVar2 = param_1[0xd];
  param_1[0xd] = param_2[0xd];
  param_2[0xd] = uVar2;
  uVar2 = param_1[0xe];
  param_1[0xe] = param_2[0xe];
  param_2[0xe] = uVar2;
  uVar2 = param_1[0xf];
  param_1[0xf] = param_2[0xf];
  param_2[0xf] = uVar2;
  uVar2 = param_1[0x10];
  param_1[0x10] = param_2[0x10];
  param_2[0x10] = uVar2;
  uVar2 = param_1[0x11];
  param_1[0x11] = param_2[0x11];
  param_2[0x11] = uVar2;
  uVar2 = param_1[0x12];
  param_1[0x12] = param_2[0x12];
  param_2[0x12] = uVar2;
  uVar1 = *(undefined1 *)(param_1 + 0x13);
  *(undefined1 *)(param_1 + 0x13) = *(undefined1 *)(param_2 + 0x13);
  *(undefined1 *)(param_2 + 0x13) = uVar1;
  uVar2 = param_1[0x14];
  param_1[0x14] = param_2[0x14];
  param_2[0x14] = uVar2;
  uVar2 = param_1[0x15];
  param_1[0x15] = param_2[0x15];
  param_2[0x15] = uVar2;
  uVar2 = param_1[0x16];
  param_1[0x16] = param_2[0x16];
  param_2[0x16] = uVar2;
  uVar2 = param_1[0x17];
  param_1[0x17] = param_2[0x17];
  param_2[0x17] = uVar2;
  uVar2 = param_1[0x18];
  param_1[0x18] = param_2[0x18];
  param_2[0x18] = uVar2;
  uVar1 = *(undefined1 *)(param_1 + 0x19);
  *(undefined1 *)(param_1 + 0x19) = *(undefined1 *)(param_2 + 0x19);
  *(undefined1 *)(param_2 + 0x19) = uVar1;
  uVar2 = param_1[0x1a];
  param_1[0x1a] = param_2[0x1a];
  param_2[0x1a] = uVar2;
  uVar2 = param_1[0x1b];
  param_1[0x1b] = param_2[0x1b];
  param_2[0x1b] = uVar2;
  uVar2 = param_1[0x1c];
  param_1[0x1c] = param_2[0x1c];
  param_2[0x1c] = uVar2;
  uVar2 = param_1[0x1d];
  param_1[0x1d] = param_2[0x1d];
  param_2[0x1d] = uVar2;
  uVar2 = param_1[0x1e];
  param_1[0x1e] = param_2[0x1e];
  param_2[0x1e] = uVar2;
  uVar1 = *(undefined1 *)(param_1 + 0x1f);
  *(undefined1 *)(param_1 + 0x1f) = *(undefined1 *)(param_2 + 0x1f);
  *(undefined1 *)(param_2 + 0x1f) = uVar1;
  return;
}


//===== FUN_00122b20 @ 00122b20 size=173 =====

void FUN_00122b20(undefined8 param_1)

{
  long in_FS_OFFSET;
  void *local_128 [6];
  void *local_f8;
  void *local_b8;
  void *local_88;
  void *local_58;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_001220d0(local_128);
  FUN_00122860(local_128,param_1);
  if (local_58 != (void *)0x0) {
    operator_delete__(local_58);
  }
  if (local_88 != (void *)0x0) {
    operator_delete__(local_88);
  }
  if (local_b8 != (void *)0x0) {
    operator_delete__(local_b8);
  }
  if (local_f8 != (void *)0x0) {
    operator_delete__(local_f8);
  }
  if (local_128[0] != (void *)0x0) {
    operator_delete__(local_128[0]);
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_00122be0 @ 00122be0 size=2978 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00122be0(undefined8 *param_1,long param_2,undefined8 *param_3,int param_4)

{
  ulong *puVar1;
  undefined1 uVar2;
  uint uVar3;
  void *pvVar4;
  undefined8 uVar5;
  undefined *puVar6;
  undefined8 *puVar7;
  ulong uVar8;
  ulong uVar9;
  void *pvVar10;
  ulong uVar11;
  ulong uVar12;
  int *piVar13;
  ulong uVar14;
  long lVar15;
  long *plVar16;
  long *plVar17;
  ulong uVar18;
  long in_FS_OFFSET;
  long lVar19;
  long local_c8;
  void *pvStack_a0;
  long lStack_90;
  long local_58 [3];
  long local_40;
  
  lVar19 = *(long *)(param_2 + 8);
  lVar15 = *(long *)(param_2 + 0x18);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (lVar15 == 0) {
    FUN_001219f0(lVar19,lVar19,0);
    local_58[0] = -1;
    local_58[1] = 0;
    lStack_90 = 0;
    pvStack_a0 = (void *)0x0;
  }
  else {
    lStack_90 = 0;
    do {
      *(int *)(lVar19 + 0xc + lStack_90 * 0x10) = (int)lStack_90;
      lStack_90 = lStack_90 + 1;
    } while (lStack_90 != lVar15);
    FUN_001219f0(lVar19,lStack_90 * 0x10 + lVar19,0);
    puVar6 = PTR_nothrow_00132fb8;
    pvStack_a0 = operator_new__(lStack_90 * 4,(nothrow_t *)PTR_nothrow_00132fb8);
    memset(pvStack_a0,0,lStack_90 * 4);
    local_58[0] = -1;
    local_58[1] = 0;
    local_c8 = *(long *)(param_2 + 0x18);
    if (local_c8 != 0) {
      plVar17 = local_58;
      do {
        local_c8 = local_c8 + -1;
        plVar16 = (long *)(local_c8 * 0x10 + *(long *)(param_2 + 8));
        uVar9 = (ulong)*(uint *)(plVar16 + 1);
        if (uVar9 == 0) {
          puVar7 = (undefined8 *)__cxa_allocate_exception(0x20);
          *puVar7 = &PTR_FUN_00132da8;
          puVar7[1] = "../src_udic/marisa_u/grimoire/trie/tail.cpp";
          puVar7[2] = 0x4000000aa;
          puVar7[3] = 
          "../src_udic/marisa_u/grimoire/trie/tail.cpp:170: MARISA_RANGE_ERROR: current.length() == 0"
          ;
                    /* WARNING: Subroutine does not return */
          __cxa_throw(puVar7,&PTR_vtable_00132d80,FUN_0010e6a0);
        }
        uVar3 = *(uint *)(plVar17 + 1);
        uVar8 = 0;
        do {
          if ((uVar3 == uVar8) || (*(char *)(*plVar16 + -uVar8) != *(char *)(*plVar17 + -uVar8))) {
            piVar13 = (int *)((long)pvStack_a0 + (ulong)*(uint *)((long)plVar16 + 0xc) * 4);
            if (uVar9 == uVar8) goto LAB_00122d81;
            goto LAB_00122e36;
          }
          uVar8 = uVar8 + 1;
        } while (uVar9 != uVar8);
        piVar13 = (int *)((long)pvStack_a0 + (ulong)*(uint *)((long)plVar16 + 0xc) * 4);
LAB_00122d81:
        if (uVar3 == 0) {
LAB_00122e36:
          uVar9 = param_1[3];
          uVar11 = 1;
          *piVar13 = (int)uVar9;
          uVar8 = (ulong)*(uint *)(plVar16 + 1);
          if (uVar8 == 0) {
            if (param_4 != 0x1000) {
              uVar9 = param_1[0xc];
              goto LAB_00123195;
            }
LAB_0012320e:
            uVar11 = param_1[4];
            uVar8 = uVar9 + 1;
            if (uVar11 < uVar8) {
              if ((uVar8 >> 1 < uVar11) && (uVar8 = uVar11 * 2, (long)uVar11 < 0)) {
                uVar8 = 0xffffffffffffffff;
              }
              pvVar10 = operator_new__(uVar8,(nothrow_t *)puVar6);
              uVar9 = param_1[3];
              if (uVar9 != 0) {
                lVar19 = param_1[1];
                if (((ulong)((long)pvVar10 - (lVar19 + 1)) < 0xf) || (uVar9 - 1 < 7)) {
                  uVar11 = 0;
                  do {
                    *(undefined1 *)((long)pvVar10 + uVar11) = *(undefined1 *)(lVar19 + uVar11);
                    uVar11 = uVar11 + 1;
                  } while (uVar9 != uVar11);
                }
                else if (uVar9 - 1 < 0xf) {
                  uVar12 = 0;
                  uVar11 = uVar9;
LAB_001232d1:
                  *(undefined8 *)((long)pvVar10 + uVar12) = *(undefined8 *)(lVar19 + uVar12);
                  uVar12 = uVar12 + (uVar11 & 0xfffffffffffffff8);
                  if ((uVar11 & 0xfffffffffffffff8) != uVar11) {
LAB_001232e8:
                    *(undefined1 *)((long)pvVar10 + uVar12) = *(undefined1 *)(lVar19 + uVar12);
                    if (((((uVar12 + 1 < uVar9) &&
                          (*(undefined1 *)((long)pvVar10 + uVar12 + 1) =
                                *(undefined1 *)(lVar19 + 1 + uVar12), uVar12 + 2 < uVar9)) &&
                         (*(undefined1 *)((long)pvVar10 + uVar12 + 2) =
                               *(undefined1 *)(lVar19 + 2 + uVar12), uVar12 + 3 < uVar9)) &&
                        ((*(undefined1 *)((long)pvVar10 + uVar12 + 3) =
                               *(undefined1 *)(lVar19 + 3 + uVar12), uVar12 + 4 < uVar9 &&
                         (*(undefined1 *)((long)pvVar10 + uVar12 + 4) =
                               *(undefined1 *)(lVar19 + 4 + uVar12), uVar12 + 5 < uVar9)))) &&
                       (*(undefined1 *)((long)pvVar10 + uVar12 + 5) =
                             *(undefined1 *)(lVar19 + 5 + uVar12), uVar12 + 6 < uVar9)) {
                      *(undefined1 *)((long)pvVar10 + uVar12 + 6) =
                           *(undefined1 *)(lVar19 + 6 + uVar12);
                    }
                  }
                }
                else {
                  uVar11 = 0;
                  do {
                    uVar5 = ((undefined8 *)(lVar19 + uVar11))[1];
                    *(undefined8 *)((long)pvVar10 + uVar11) = *(undefined8 *)(lVar19 + uVar11);
                    ((undefined8 *)((long)pvVar10 + uVar11))[1] = uVar5;
                    uVar11 = uVar11 + 0x10;
                  } while (uVar11 != (uVar9 & 0xfffffffffffffff0));
                  uVar12 = uVar9 & 0xfffffffffffffff0;
                  if ((uVar9 & 0xf) != 0) {
                    uVar11 = uVar9 - uVar12;
                    if (6 < (uVar9 - uVar12) - 1) goto LAB_001232d1;
                    goto LAB_001232e8;
                  }
                }
              }
              pvVar4 = (void *)*param_1;
              param_1[2] = pvVar10;
              param_1[4] = uVar8;
              *param_1 = pvVar10;
              param_1[1] = pvVar10;
              if (pvVar4 != (void *)0x0) {
                operator_delete__(pvVar4);
                pvVar10 = (void *)param_1[1];
                uVar9 = param_1[3];
              }
            }
            else {
              pvVar10 = (void *)param_1[1];
            }
            *(undefined1 *)((long)pvVar10 + uVar9) = 0;
            uVar9 = param_1[3] + 1;
            param_1[3] = uVar9;
          }
          else {
            do {
              uVar12 = uVar9 + 1;
              uVar2 = *(undefined1 *)(*plVar16 + (uVar11 - uVar8));
              uVar8 = param_1[4];
              if (uVar8 < uVar12) {
                if ((uVar12 >> 1 < uVar8) && (uVar12 = uVar8 * 2, (long)uVar8 < 0)) {
                  uVar12 = 0xffffffffffffffff;
                }
                pvVar10 = operator_new__(uVar12,(nothrow_t *)puVar6);
                uVar9 = param_1[3];
                if (uVar9 != 0) {
                  lVar19 = param_1[1];
                  if (((ulong)((long)pvVar10 - (lVar19 + 1)) < 0xf) || (uVar9 - 1 < 7)) {
                    uVar8 = 0;
                    do {
                      *(undefined1 *)((long)pvVar10 + uVar8) = *(undefined1 *)(lVar19 + uVar8);
                      uVar8 = uVar8 + 1;
                    } while (uVar9 != uVar8);
                  }
                  else if (uVar9 - 1 < 0xf) {
                    uVar14 = 0;
                    uVar8 = uVar9;
LAB_00122f21:
                    *(undefined8 *)((long)pvVar10 + uVar14) = *(undefined8 *)(lVar19 + uVar14);
                    uVar14 = uVar14 + (uVar8 & 0xfffffffffffffff8);
                    if (uVar8 != (uVar8 & 0xfffffffffffffff8)) {
LAB_00122f38:
                      *(undefined1 *)((long)pvVar10 + uVar14) = *(undefined1 *)(lVar19 + uVar14);
                      if ((((uVar14 + 1 < uVar9) &&
                           (*(undefined1 *)((long)pvVar10 + uVar14 + 1) =
                                 *(undefined1 *)(lVar19 + 1 + uVar14), uVar14 + 2 < uVar9)) &&
                          (*(undefined1 *)((long)pvVar10 + uVar14 + 2) =
                                *(undefined1 *)(lVar19 + 2 + uVar14), uVar14 + 3 < uVar9)) &&
                         (((*(undefined1 *)((long)pvVar10 + uVar14 + 3) =
                                 *(undefined1 *)(lVar19 + 3 + uVar14), uVar14 + 4 < uVar9 &&
                           (*(undefined1 *)((long)pvVar10 + uVar14 + 4) =
                                 *(undefined1 *)(lVar19 + 4 + uVar14), uVar14 + 5 < uVar9)) &&
                          (*(undefined1 *)((long)pvVar10 + uVar14 + 5) =
                                *(undefined1 *)(lVar19 + 5 + uVar14), uVar14 + 6 < uVar9)))) {
                        *(undefined1 *)((long)pvVar10 + uVar14 + 6) =
                             *(undefined1 *)(lVar19 + 6 + uVar14);
                      }
                    }
                  }
                  else {
                    uVar8 = 0;
                    do {
                      uVar5 = ((undefined8 *)(lVar19 + uVar8))[1];
                      *(undefined8 *)((long)pvVar10 + uVar8) = *(undefined8 *)(lVar19 + uVar8);
                      ((undefined8 *)((long)pvVar10 + uVar8))[1] = uVar5;
                      uVar8 = uVar8 + 0x10;
                    } while ((uVar9 & 0xfffffffffffffff0) != uVar8);
                    uVar14 = uVar9 & 0xfffffffffffffff0;
                    if ((uVar9 & 0xf) != 0) {
                      uVar8 = uVar9 - uVar14;
                      if (6 < (uVar9 - uVar14) - 1) goto LAB_00122f21;
                      goto LAB_00122f38;
                    }
                  }
                }
                pvVar4 = (void *)*param_1;
                param_1[2] = pvVar10;
                param_1[4] = uVar12;
                *param_1 = pvVar10;
                param_1[1] = pvVar10;
                if (pvVar4 != (void *)0x0) {
                  operator_delete__(pvVar4);
                  pvVar10 = (void *)param_1[1];
                  uVar9 = param_1[3];
                }
              }
              else {
                pvVar10 = (void *)param_1[1];
              }
              *(undefined1 *)((long)pvVar10 + uVar9) = uVar2;
              uVar11 = uVar11 + 1;
              uVar3 = *(uint *)(plVar16 + 1);
              uVar8 = (ulong)uVar3;
              uVar9 = param_1[3] + 1;
              param_1[3] = uVar9;
            } while (uVar11 <= uVar8);
            if (param_4 == 0x1000) goto LAB_0012320e;
            uVar9 = param_1[0xc];
            if (1 < uVar3) {
              uVar11 = 1;
              do {
                if (uVar9 == 0xffffffff) {
                  FUN_00107672();
                  goto LAB_001078c3;
                }
                uVar12 = param_1[9];
                if (uVar12 << 6 == uVar9) {
                  uVar14 = param_1[10];
                  uVar9 = uVar12 + 1;
                  if (uVar14 < uVar9) {
                    if (uVar9 >> 1 < uVar14) {
                      uVar8 = 0xfffffffffffffff8;
                      uVar18 = 0x1fffffffffffffff;
                      if (uVar14 < 0x1000000000000000) {
                        uVar18 = uVar14 * 2;
                        uVar8 = uVar14 << 4;
                      }
                    }
                    else {
                      uVar8 = uVar9 * 8;
                      uVar18 = uVar9;
                    }
                    pvVar10 = operator_new__(uVar8,(nothrow_t *)puVar6);
                    uVar12 = param_1[9];
                    if (uVar12 != 0) {
                      lVar19 = param_1[7];
                      if ((uVar12 - 1 < 3) || (pvVar10 == (void *)(lVar19 + 8))) {
                        uVar8 = 0;
                        do {
                          *(undefined8 *)((long)pvVar10 + uVar8 * 8) =
                               *(undefined8 *)(lVar19 + uVar8 * 8);
                          uVar8 = uVar8 + 1;
                        } while (uVar12 != uVar8);
                      }
                      else {
                        lVar15 = 0;
                        do {
                          uVar5 = ((undefined8 *)(lVar19 + lVar15))[1];
                          *(undefined8 *)((long)pvVar10 + lVar15) = *(undefined8 *)(lVar19 + lVar15)
                          ;
                          ((undefined8 *)((long)pvVar10 + lVar15))[1] = uVar5;
                          lVar15 = lVar15 + 0x10;
                        } while (lVar15 != (uVar12 >> 1) * 0x10);
                        if ((uVar12 & 1) != 0) {
                          *(undefined8 *)((long)pvVar10 + (uVar12 & 0xfffffffffffffffe) * 8) =
                               *(undefined8 *)(lVar19 + (uVar12 & 0xfffffffffffffffe) * 8);
                        }
                      }
                    }
                    pvVar4 = (void *)param_1[6];
                    param_1[8] = pvVar10;
                    param_1[10] = uVar18;
                    param_1[6] = pvVar10;
                    param_1[7] = pvVar10;
                    if (pvVar4 != (void *)0x0) {
                      operator_delete__(pvVar4);
                      uVar12 = param_1[9];
                    }
                    uVar8 = (ulong)*(uint *)(plVar16 + 1);
                  }
                  if (uVar12 < uVar9) {
                    memset((void *)(param_1[7] + uVar12 * 8),0,(uVar9 - uVar12) * 8);
                  }
                  param_1[9] = uVar9;
                  uVar9 = param_1[0xc];
                }
                uVar9 = uVar9 + 1;
                uVar11 = uVar11 + 1;
                param_1[0xc] = uVar9;
              } while (uVar11 < uVar8);
            }
LAB_00123195:
            if (uVar9 == 0xffffffff) {
              FUN_00107672();
              goto LAB_00107964;
            }
            uVar8 = param_1[9];
            if (uVar8 << 6 == uVar9) {
              uVar11 = param_1[10];
              uVar9 = uVar8 + 1;
              if (uVar11 < uVar9) {
                if (uVar9 >> 1 < uVar11) {
                  uVar8 = 0xfffffffffffffff8;
                  uVar12 = 0x1fffffffffffffff;
                  if (uVar11 < 0x1000000000000000) {
                    uVar12 = uVar11 * 2;
                    uVar8 = uVar11 << 4;
                  }
                }
                else {
                  uVar8 = uVar9 * 8;
                  uVar12 = uVar9;
                }
                pvVar10 = operator_new__(uVar8,(nothrow_t *)puVar6);
                uVar8 = param_1[9];
                if (uVar8 != 0) {
                  lVar19 = param_1[7];
                  if ((uVar8 - 1 < 3) || (pvVar10 == (void *)(lVar19 + 8))) {
                    uVar11 = 0;
                    do {
                      *(undefined8 *)((long)pvVar10 + uVar11 * 8) =
                           *(undefined8 *)(lVar19 + uVar11 * 8);
                      uVar11 = uVar11 + 1;
                    } while (uVar8 != uVar11);
                  }
                  else {
                    lVar15 = 0;
                    do {
                      uVar5 = ((undefined8 *)(lVar19 + lVar15))[1];
                      *(undefined8 *)((long)pvVar10 + lVar15) = *(undefined8 *)(lVar19 + lVar15);
                      ((undefined8 *)((long)pvVar10 + lVar15))[1] = uVar5;
                      lVar15 = lVar15 + 0x10;
                    } while (lVar15 != (uVar8 >> 1) * 0x10);
                    if ((uVar8 & 1) != 0) {
                      *(undefined8 *)((long)pvVar10 + (uVar8 & 0xfffffffffffffffe) * 8) =
                           *(undefined8 *)(lVar19 + (uVar8 & 0xfffffffffffffffe) * 8);
                    }
                  }
                }
                pvVar4 = (void *)param_1[6];
                param_1[8] = pvVar10;
                param_1[10] = uVar12;
                param_1[6] = pvVar10;
                param_1[7] = pvVar10;
                if (pvVar4 != (void *)0x0) {
                  operator_delete__(pvVar4);
                  uVar8 = param_1[9];
                  goto LAB_00123493;
                }
              }
              else {
LAB_00123493:
                pvVar10 = (void *)param_1[7];
              }
              if (uVar8 < uVar9) {
                memset((void *)((long)pvVar10 + uVar8 * 8),0,(uVar9 - uVar8) * 8);
              }
              param_1[9] = uVar9;
              uVar9 = param_1[0xc];
            }
            else {
              pvVar10 = (void *)param_1[7];
            }
            puVar1 = (ulong *)((long)pvVar10 + (uVar9 >> 6) * 8);
            *puVar1 = *puVar1 | 1L << ((byte)uVar9 & 0x3f);
            lVar19 = param_1[0xd] + _UNK_0012a668;
            uVar9 = param_1[3];
            param_1[0xc] = param_1[0xc] + _DAT_0012a660;
            param_1[0xd] = lVar19;
          }
          if (0xffffffff < uVar9) {
LAB_001078c3:
            puVar7 = (undefined8 *)__cxa_allocate_exception(0x20);
            *puVar7 = &PTR_FUN_00132da8;
            puVar7[1] = "../src_udic/marisa_u/grimoire/trie/tail.cpp";
            puVar7[2] = 0x7000000c0;
            puVar7[3] = 
            "../src_udic/marisa_u/grimoire/trie/tail.cpp:192: MARISA_SIZE_ERROR: buf_.size() > MARISA_UINT32_MAX"
            ;
                    /* WARNING: Subroutine does not return */
            __cxa_throw(puVar7,&PTR_vtable_00132d80,FUN_0010e6a0);
          }
        }
        else {
          *piVar13 = (uVar3 + *(int *)((long)pvStack_a0 + (ulong)*(uint *)((long)plVar17 + 0xc) * 4)
                     ) - (int)uVar8;
        }
        plVar17 = plVar16;
      } while (local_c8 != 0);
    }
  }
  if (*(char *)(param_1 + 5) != '\0') {
LAB_00107964:
    puVar7 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar7 = &PTR_FUN_00132da8;
    puVar7[1] = "../src_udic/marisa_u/grimoire/trie/../vector/vector.h";
    puVar7[2] = 0x100000064;
    puVar7[3] = 
    "../src_udic/marisa_u/grimoire/trie/../vector/vector.h:100: MARISA_STATE_ERROR: fixed_";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar7,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  uVar9 = param_1[3];
  if (uVar9 == param_1[4]) goto LAB_00122dc0;
  pvVar10 = operator_new__(uVar9,(nothrow_t *)PTR_nothrow_00132fb8);
  uVar8 = param_1[3];
  if (uVar8 != 0) {
    lVar19 = param_1[1];
    if (((ulong)((long)pvVar10 - (lVar19 + 1)) < 0xf) || (uVar8 - 1 < 7)) {
      uVar11 = 0;
      do {
        *(undefined1 *)((long)pvVar10 + uVar11) = *(undefined1 *)(lVar19 + uVar11);
        uVar11 = uVar11 + 1;
      } while (uVar11 != uVar8);
    }
    else if (uVar8 - 1 < 0xf) {
      uVar12 = 0;
      uVar11 = uVar8;
LAB_00123573:
      *(undefined8 *)((long)pvVar10 + uVar12) = *(undefined8 *)(lVar19 + uVar12);
      uVar12 = uVar12 + (uVar11 & 0xfffffffffffffff8);
      if (uVar11 != (uVar11 & 0xfffffffffffffff8)) {
LAB_0012358a:
        *(undefined1 *)((long)pvVar10 + uVar12) = *(undefined1 *)(lVar19 + uVar12);
        if ((((uVar12 + 1 < uVar8) &&
             (*(undefined1 *)((long)pvVar10 + uVar12 + 1) = *(undefined1 *)(lVar19 + 1 + uVar12),
             uVar12 + 2 < uVar8)) &&
            (*(undefined1 *)((long)pvVar10 + uVar12 + 2) = *(undefined1 *)(lVar19 + 2 + uVar12),
            uVar12 + 3 < uVar8)) &&
           (((*(undefined1 *)((long)pvVar10 + uVar12 + 3) = *(undefined1 *)(lVar19 + 3 + uVar12),
             uVar12 + 4 < uVar8 &&
             (*(undefined1 *)((long)pvVar10 + uVar12 + 4) = *(undefined1 *)(lVar19 + 4 + uVar12),
             uVar12 + 5 < uVar8)) &&
            (*(undefined1 *)((long)pvVar10 + uVar12 + 5) = *(undefined1 *)(lVar19 + 5 + uVar12),
            uVar12 + 6 < uVar8)))) {
          *(undefined1 *)((long)pvVar10 + uVar12 + 6) = *(undefined1 *)(lVar19 + 6 + uVar12);
        }
      }
    }
    else {
      uVar11 = 0;
      do {
        uVar5 = ((undefined8 *)(lVar19 + uVar11))[1];
        *(undefined8 *)((long)pvVar10 + uVar11) = *(undefined8 *)(lVar19 + uVar11);
        ((undefined8 *)((long)pvVar10 + uVar11))[1] = uVar5;
        uVar11 = uVar11 + 0x10;
      } while (uVar11 != (uVar8 & 0xfffffffffffffff0));
      uVar12 = uVar8 & 0xfffffffffffffff0;
      if ((uVar8 & 0xf) != 0) {
        uVar11 = uVar8 - uVar12;
        if (6 < (uVar8 - uVar12) - 1) goto LAB_00123573;
        goto LAB_0012358a;
      }
    }
  }
  pvVar4 = (void *)*param_1;
  param_1[2] = pvVar10;
  param_1[4] = uVar9;
  *param_1 = pvVar10;
  param_1[1] = pvVar10;
  if (pvVar4 != (void *)0x0) {
    operator_delete__(pvVar4);
  }
LAB_00122dc0:
  pvVar10 = (void *)*param_3;
  *(undefined1 *)(param_3 + 5) = 0;
  param_3[2] = pvStack_a0;
  *param_3 = pvStack_a0;
  param_3[1] = pvStack_a0;
  param_3[3] = lStack_90;
  param_3[4] = lStack_90;
  if (pvVar10 == (void *)0x0) {
    if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
  else if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    operator_delete__(pvVar10);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_00123720 @ 00123720 size=386 =====

void FUN_00123720(undefined8 param_1,long param_2,long param_3,int param_4)

{
  undefined8 *puVar1;
  char *pcVar2;
  long lVar3;
  long in_FS_OFFSET;
  bool bVar4;
  void *local_138 [6];
  void *local_108;
  void *local_c8;
  void *local_98;
  void *local_68;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_3 == 0) {
    puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar1 = &PTR_FUN_00132da8;
    puVar1[1] = "../src_udic/marisa_u/grimoire/trie/tail.cpp";
    puVar1[2] = 0x20000000d;
    puVar1[3] = "../src_udic/marisa_u/grimoire/trie/tail.cpp:13: MARISA_NULL_ERROR: offsets == NULL"
    ;
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar1,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  if (param_4 == 0x1000) {
    if (*(long *)(param_2 + 0x18) != 0) {
      puVar1 = *(undefined8 **)(param_2 + 8);
      lVar3 = 0;
      do {
        if ((ulong)*(uint *)(puVar1 + 1) != 0) {
          pcVar2 = (char *)*puVar1 + (1 - (ulong)*(uint *)(puVar1 + 1));
          do {
            if (*pcVar2 == '\0') {
              param_4 = 0x2000;
              goto LAB_001237db;
            }
            bVar4 = pcVar2 != (char *)*puVar1;
            pcVar2 = pcVar2 + 1;
          } while (bVar4);
        }
        lVar3 = lVar3 + 1;
        puVar1 = puVar1 + 2;
      } while (lVar3 != *(long *)(param_2 + 0x18));
    }
  }
  else if (param_4 != 0x2000) {
    FUN_001079fb();
    return;
  }
LAB_001237db:
  FUN_001220d0(local_138);
  FUN_00122be0(local_138,param_2,param_3,param_4);
  FUN_00122860(param_1,local_138);
  if (local_68 != (void *)0x0) {
    operator_delete__(local_68);
  }
  if (local_98 != (void *)0x0) {
    operator_delete__(local_98);
  }
  if (local_c8 != (void *)0x0) {
    operator_delete__(local_c8);
  }
  if (local_108 != (void *)0x0) {
    operator_delete__(local_108);
  }
  if (local_138[0] != (void *)0x0) {
    operator_delete__(local_138[0]);
  }
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


//===== FUN_001238c0 @ 001238c0 size=1189 =====

void FUN_001238c0(undefined1 (*param_1) [16],undefined8 param_2)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  void *pvVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  void *pvVar9;
  void *pvVar10;
  void *pvVar11;
  undefined8 *puVar12;
  undefined8 uVar13;
  ulong *puVar14;
  undefined8 uVar15;
  uint *puVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  long in_FS_OFFSET;
  
  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
  puVar12 = (undefined8 *)FUN_00110420(param_2,8);
  uVar15 = *puVar12;
  uVar13 = FUN_00110420(param_2,uVar15);
  FUN_00110490(param_2,-(int)uVar15 & 7);
  pvVar4 = *(void **)*param_1;
  *(undefined8 *)param_1[1] = uVar13;
  *(undefined8 *)(param_1[1] + 8) = uVar15;
  *(undefined8 *)param_1[2] = 0;
  param_1[2][8] = 1;
  *param_1 = (undefined1  [16])0x0;
  if (pvVar4 != (void *)0x0) {
    operator_delete__(pvVar4);
  }
  puVar14 = (ulong *)FUN_00110420(param_2,8);
  uVar5 = *puVar14;
  if ((uVar5 & 7) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_00107730();
  }
  uVar15 = FUN_00110420(param_2,uVar5 & 0xfffffffffffffff8);
  FUN_00110490(param_2,-(int)uVar5 & 7);
  puVar16 = (uint *)FUN_00110420(param_2,4);
  uVar1 = *puVar16;
  puVar16 = (uint *)FUN_00110420(param_2,4);
  uVar2 = *puVar16;
  if ((ulong)uVar1 < (ulong)uVar2) {
    puVar12 = (undefined8 *)__cxa_allocate_exception(0x20);
    puVar12[2] = 0xa00000091;
    puVar12[3] = 
    "../src_udic/marisa_u/grimoire/trie/../vector/bit-vector.h:145: MARISA_FORMAT_ERROR: temp_num_1s > size_"
    ;
    *puVar12 = &PTR_FUN_00132da8;
    puVar12[1] = "../src_udic/marisa_u/grimoire/trie/../vector/bit-vector.h";
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar12,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  puVar14 = (ulong *)FUN_00110420(param_2,8);
  uVar6 = *puVar14;
  if ((uVar6 * -0x5555555555555555 >> 2 | uVar6 * -0x5555555555555555 << 0x3e) < 0x1555555555555556)
  {
    uVar13 = FUN_00110420(param_2,(uVar6 / 0xc) * 0xc);
    FUN_00110490(param_2,-(int)uVar6 & 7);
    puVar14 = (ulong *)FUN_00110420(param_2,8);
    uVar7 = *puVar14;
    if ((uVar7 & 3) != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_00107730();
    }
    uVar17 = FUN_00110420(param_2,uVar7 & 0xfffffffffffffffc);
    FUN_00110490(param_2,-(int)uVar7 & 7);
    puVar14 = (ulong *)FUN_00110420(param_2,8);
    uVar8 = *puVar14;
    if ((uVar8 & 3) == 0) {
      uVar18 = FUN_00110420(param_2,uVar8 & 0xfffffffffffffffc);
      FUN_00110490(param_2,-(int)uVar8 & 7);
      *(ulong *)(param_1[8] + 8) = uVar6 / 0xc;
      pvVar4 = *(void **)param_1[0xd];
      *(undefined8 *)param_1[4] = uVar15;
      *(ulong *)(param_1[4] + 8) = uVar5 >> 3;
      pvVar9 = *(void **)param_1[3];
      *(undefined8 *)param_1[5] = 0;
      pvVar10 = *(void **)param_1[7];
      pvVar11 = *(void **)param_1[10];
      param_1[5][8] = 1;
      *(undefined8 *)param_1[0xb] = uVar17;
      *(undefined8 *)param_1[8] = uVar13;
      *(undefined8 *)param_1[9] = 0;
      param_1[9][8] = 1;
      *(ulong *)(param_1[0xb] + 8) = uVar7 >> 2;
      *(undefined8 *)param_1[0xc] = 0;
      param_1[0xc][8] = 1;
      *(undefined8 *)param_1[0xe] = uVar18;
      *(ulong *)(param_1[0xe] + 8) = uVar8 >> 2;
      *(undefined8 *)param_1[0xf] = 0;
      param_1[0xf][8] = 1;
      param_1[3] = (undefined1  [16])0x0;
      *(ulong *)param_1[6] = (ulong)uVar1;
      *(ulong *)(param_1[6] + 8) = (ulong)uVar2;
      param_1[7] = (undefined1  [16])0x0;
      param_1[10] = (undefined1  [16])0x0;
      param_1[0xd] = (undefined1  [16])0x0;
      if (pvVar4 != (void *)0x0) {
        operator_delete__(pvVar4);
      }
      if (pvVar11 != (void *)0x0) {
        operator_delete__(pvVar11);
      }
      if (pvVar10 != (void *)0x0) {
        operator_delete__(pvVar10);
      }
      if (pvVar9 == (void *)0x0) {
        if (lVar3 == *(long *)(in_FS_OFFSET + 0x28)) {
          return;
        }
      }
      else if (lVar3 == *(long *)(in_FS_OFFSET + 0x28)) {
        operator_delete__(pvVar9);
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
                    /* WARNING: Subroutine does not return */
    FUN_00107730();
  }
                    /* WARNING: Subroutine does not return */
  FUN_00107730();
}


//===== FUN_00123d10 @ 00123d10 size=191 =====

void FUN_00123d10(undefined8 param_1,undefined8 param_2)

{
  long in_FS_OFFSET;
  void *local_128 [6];
  void *local_f8;
  void *local_b8;
  void *local_88;
  void *local_58;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_001220d0(local_128);
  FUN_001238c0(local_128,param_2);
  FUN_00122860(param_1,local_128);
  if (local_58 != (void *)0x0) {
    operator_delete__(local_58);
  }
  if (local_88 != (void *)0x0) {
    operator_delete__(local_88);
  }
  if (local_b8 != (void *)0x0) {
    operator_delete__(local_b8);
  }
  if (local_f8 != (void *)0x0) {
    operator_delete__(local_f8);
  }
  if (local_128[0] != (void *)0x0) {
    operator_delete__(local_128[0]);
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_00123de0 @ 00123de0 size=933 =====

void FUN_00123de0(long param_1,undefined8 param_2)

{
  ulong uVar1;
  undefined8 *puVar2;
  long in_FS_OFFSET;
  long local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_28 = *(long *)(param_1 + 0x18);
  FUN_00110fb0(param_2,&local_28,8);
  if ((*(long *)(param_1 + 0x10) == 0) && (*(long *)(param_1 + 0x18) != 0)) {
    puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
    *puVar2 = &PTR_FUN_00132da8;
    puVar2[1] = "../src_udic/marisa_u/grimoire/trie/../vector/../io/writer.h";
    puVar2[2] = 0x20000001e;
    puVar2[3] = 
    "../src_udic/marisa_u/grimoire/trie/../vector/../io/writer.h:30: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
    ;
                    /* WARNING: Subroutine does not return */
    __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
  }
  FUN_00110fb0(param_2);
  FUN_001110d0(param_2,-(int)*(undefined8 *)(param_1 + 0x18) & 7);
  local_28 = *(long *)(param_1 + 0x48) << 3;
  FUN_00110fb0(param_2,&local_28,8);
  uVar1 = *(ulong *)(param_1 + 0x48);
  if ((*(long *)(param_1 + 0x40) != 0) || (uVar1 == 0)) {
    if (uVar1 >> 0x3d == 0) {
      FUN_00110fb0(param_2,*(long *)(param_1 + 0x40),uVar1 << 3);
      FUN_001110d0(param_2,0);
      local_28._0_4_ = (int)*(undefined8 *)(param_1 + 0x60);
      FUN_00110fb0(param_2,&local_28,4);
      local_28 = CONCAT44(local_28._4_4_,(int)*(undefined8 *)(param_1 + 0x68));
      FUN_00110fb0(param_2,&local_28,4);
      local_28 = *(long *)(param_1 + 0x88) * 0xc;
      FUN_00110fb0(param_2,&local_28,8);
      uVar1 = *(ulong *)(param_1 + 0x88);
      if ((*(long *)(param_1 + 0x80) != 0) || (uVar1 == 0)) {
        if (uVar1 < 0x1555555555555556) {
          FUN_00110fb0(param_2,*(long *)(param_1 + 0x80),uVar1 * 0xc);
          FUN_001110d0(param_2,(int)*(undefined8 *)(param_1 + 0x88) * 4 & 4);
          local_28 = *(long *)(param_1 + 0xb8) << 2;
          FUN_00110fb0(param_2,&local_28,8);
          uVar1 = *(ulong *)(param_1 + 0xb8);
          if ((*(long *)(param_1 + 0xb0) != 0) || (uVar1 == 0)) {
            if (uVar1 >> 0x3e == 0) {
              FUN_00110fb0(param_2,*(long *)(param_1 + 0xb0),uVar1 << 2);
              FUN_001110d0(param_2,(int)*(undefined8 *)(param_1 + 0xb8) * -4 & 7);
              local_28 = *(long *)(param_1 + 0xe8) << 2;
              FUN_00110fb0(param_2,&local_28,8);
              uVar1 = *(ulong *)(param_1 + 0xe8);
              if ((*(long *)(param_1 + 0xe0) == 0) && (uVar1 != 0)) {
                puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
                *puVar2 = &PTR_FUN_00132da8;
                puVar2[1] = "../src_udic/marisa_u/grimoire/trie/../vector/../io/writer.h";
                puVar2[2] = 0x20000001e;
                puVar2[3] = 
                "../src_udic/marisa_u/grimoire/trie/../vector/../io/writer.h:30: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
                ;
                    /* WARNING: Subroutine does not return */
                __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
              }
              if (uVar1 >> 0x3e == 0) {
                FUN_00110fb0(param_2,*(long *)(param_1 + 0xe0),uVar1 << 2);
                if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
                  FUN_001110d0(param_2,-(int)(*(long *)(param_1 + 0xe8) << 2) & 7);
                  return;
                }
                    /* WARNING: Subroutine does not return */
                __stack_chk_fail();
              }
            }
            FUN_0010784e();
          }
          puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
          *puVar2 = &PTR_FUN_00132da8;
          puVar2[1] = "../src_udic/marisa_u/grimoire/trie/../vector/../io/writer.h";
          puVar2[2] = 0x20000001e;
          puVar2[3] = 
          "../src_udic/marisa_u/grimoire/trie/../vector/../io/writer.h:30: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
          ;
                    /* WARNING: Subroutine does not return */
          __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
        }
        FUN_0010784e();
      }
      puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
      *puVar2 = &PTR_FUN_00132da8;
      puVar2[1] = "../src_udic/marisa_u/grimoire/trie/../vector/../io/writer.h";
      puVar2[2] = 0x20000001e;
      puVar2[3] = 
      "../src_udic/marisa_u/grimoire/trie/../vector/../io/writer.h:30: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
      ;
                    /* WARNING: Subroutine does not return */
      __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
    }
    FUN_0010784e();
  }
  puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
  *puVar2 = &PTR_FUN_00132da8;
  puVar2[1] = "../src_udic/marisa_u/grimoire/trie/../vector/../io/writer.h";
  puVar2[2] = 0x20000001e;
  puVar2[3] = 
  "../src_udic/marisa_u/grimoire/trie/../vector/../io/writer.h:30: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
  ;
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
}


//===== thunk_FUN_00123de0 @ 00124080 size=9 =====

void thunk_FUN_00123de0(void)

{
  FUN_00123de0();
  return;
}


//===== FUN_00124090 @ 00124090 size=270 =====

void FUN_00124090(undefined8 *param_1,undefined8 param_2)

{
  void *pvVar1;
  undefined8 *puVar2;
  long in_FS_OFFSET;
  ulong uStack_50;
  void *pvStack_40;
  ulong local_38;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_00110a70(param_2,&local_38,8);
  uStack_50 = local_38;
  if (local_38 == 0) {
    FUN_00110a70(param_2,0,0);
    pvStack_40 = (void *)0x0;
    uStack_50 = 0;
  }
  else {
    pvStack_40 = operator_new__(local_38,(nothrow_t *)PTR_nothrow_00132fb8);
    if (pvStack_40 == (void *)0x0) {
      puVar2 = (undefined8 *)__cxa_allocate_exception(0x20);
      puVar2[2] = 0x20000001f;
      puVar2[3] = 
      "../src_udic/marisa_u/grimoire/trie/../vector/../io/reader.h:31: MARISA_NULL_ERROR: (objs == NULL) && (num_objs != 0)"
      ;
      *puVar2 = &PTR_FUN_00132da8;
      puVar2[1] = "../src_udic/marisa_u/grimoire/trie/../vector/../io/reader.h";
                    /* WARNING: Subroutine does not return */
      __cxa_throw(puVar2,&PTR_vtable_00132d80,FUN_0010e6a0);
    }
    FUN_00110a70(param_2,pvStack_40,uStack_50);
  }
  FUN_00110b80(param_2,-(int)local_38 & 7);
  pvVar1 = (void *)*param_1;
  param_1[2] = pvStack_40;
  *(undefined1 *)(param_1 + 5) = 0;
  *param_1 = pvStack_40;
  param_1[1] = pvStack_40;
  param_1[3] = uStack_50;
  param_1[4] = uStack_50;
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    FUN_001199f0(param_1 + 6,param_2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_001241c0 @ 001241c0 size=191 =====

void FUN_001241c0(undefined8 param_1,undefined8 param_2)

{
  long in_FS_OFFSET;
  void *local_128 [6];
  void *local_f8;
  void *local_b8;
  void *local_88;
  void *local_58;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_001220d0(local_128);
  FUN_00124090(local_128,param_2);
  FUN_00122860(param_1,local_128);
  if (local_58 != (void *)0x0) {
    operator_delete__(local_58);
  }
  if (local_88 != (void *)0x0) {
    operator_delete__(local_88);
  }
  if (local_b8 != (void *)0x0) {
    operator_delete__(local_b8);
  }
  if (local_f8 != (void *)0x0) {
    operator_delete__(local_f8);
  }
  if (local_128[0] != (void *)0x0) {
    operator_delete__(local_128[0]);
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


//===== FUN_00124290 @ 00124290 size=86 =====

void FUN_00124290(undefined8 *param_1)

{
  if ((void *)param_1[0x1a] != (void *)0x0) {
    operator_delete__((void *)param_1[0x1a]);
  }
  if ((void *)param_1[0x14] != (void *)0x0) {
    operator_delete__((void *)param_1[0x14]);
  }
  if ((void *)param_1[0xe] != (void *)0x0) {
    operator_delete__((void *)param_1[0xe]);
  }
  if ((void *)param_1[6] != (void *)0x0) {
    operator_delete__((void *)param_1[6]);
  }
  if ((void *)*param_1 != (void *)0x0) {
    operator_delete__((void *)*param_1);
    return;
  }
  return;
}


//===== FUN_001242f0 @ 001242f0 size=305 =====

long FUN_001242f0(ulong param_1,long param_2,ulong param_3)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar1 = (param_3 >> 1 & 0x5555555555555555) + (param_3 & 0x5555555555555555);
  uVar1 = (uVar1 & 0x3333333333333333) + (uVar1 >> 2 & 0x3333333333333333);
  uVar1 = ((uVar1 & 0xf0f0f0f0f0f0f0f) + (uVar1 >> 4 & 0xf0f0f0f0f0f0f0f)) * 0x101010101010101;
  uVar2 = uVar1 >> 0x18 & 0xff;
  if (param_1 < uVar2) {
    uVar2 = uVar1 >> 8 & 0xff;
    if (param_1 < uVar2) {
      if ((uVar1 & 0xff) <= param_1) {
        param_2 = param_2 + 8;
        param_3 = param_3 >> 8;
        param_1 = param_1 - (uVar1 & 0xff);
      }
    }
    else {
      uVar1 = uVar1 >> 0x10 & 0xff;
      if (param_1 < uVar1) {
        param_2 = param_2 + 0x10;
        param_3 = param_3 >> 0x10;
        param_1 = param_1 - uVar2;
      }
      else {
        param_2 = param_2 + 0x18;
        param_3 = param_3 >> 0x18;
        param_1 = param_1 - uVar1;
      }
    }
  }
  else {
    uVar3 = uVar1 >> 0x28 & 0xff;
    if (param_1 < uVar3) {
      uVar1 = uVar1 >> 0x20 & 0xff;
      if (param_1 < uVar1) {
        param_2 = param_2 + 0x20;
        param_3 = param_3 >> 0x20;
        param_1 = param_1 - uVar2;
      }
      else {
        param_2 = param_2 + 0x28;
        param_3 = param_3 >> 0x28;
        param_1 = param_1 - uVar1;
      }
    }
    else {
      uVar1 = uVar1 >> 0x30 & 0xff;
      if (param_1 < uVar1) {
        param_2 = param_2 + 0x30;
        param_3 = param_3 >> 0x30;
        param_1 = param_1 - uVar3;
      }
      else {
        param_2 = param_2 + 0x38;
        param_3 = param_3 >> 0x38;
        param_1 = param_1 - uVar1;
      }
    }
  }
  return (ulong)(byte)PTR_DAT_00132fb0[(param_3 & 0xff) + param_1 * 0x100] + param_2;
}


//===== FUN_00124440 @ 00124440 size=345 =====

long FUN_00124440(long param_1,ulong param_2)

{
  uint *puVar1;
  uint uVar2;
  ulong uVar3;
  
  puVar1 = (uint *)(*(long *)(param_1 + 0x50) + (param_2 >> 9) * 0xc);
  uVar3 = (ulong)*puVar1;
  switch((uint)(param_2 >> 6) & 7) {
  case 1:
    uVar3 = uVar3 + (puVar1[1] & 0x7f);
    break;
  case 2:
    uVar3 = uVar3 + (puVar1[1] >> 7 & 0xff);
    break;
  case 3:
    uVar3 = uVar3 + (puVar1[1] >> 0xf & 0xff);
    break;
  case 4:
    uVar3 = uVar3 + (puVar1[1] >> 0x17);
    break;
  case 5:
    uVar3 = uVar3 + (puVar1[2] & 0x1ff);
    break;
  case 6:
    uVar3 = uVar3 + (puVar1[2] >> 9 & 0x1ff);
    break;
  case 7:
    uVar3 = uVar3 + (puVar1[2] >> 0x12 & 0x1ff);
  }
  if ((param_2 & 0x20) != 0) {
    uVar2 = *(uint *)(*(long *)(param_1 + 0x10) + -4 + (param_2 >> 5) * 4);
    uVar2 = (uVar2 >> 1 & 0x55555555) + (uVar2 & 0x55555555);
    uVar2 = (uVar2 & 0x33333333) + (uVar2 >> 2 & 0x33333333);
    uVar3 = uVar3 + (((uVar2 & 0xf0f0f0f) + (uVar2 >> 4 & 0xf0f0f0f)) * 0x1010101 >> 0x18);
  }
  uVar2 = ~(-1 << ((byte)param_2 & 0x1f)) &
          *(uint *)(*(long *)(param_1 + 0x10) + (param_2 >> 5) * 4);
  uVar2 = (uVar2 >> 1 & 0x55555555) + (uVar2 & 0x55555555);
  uVar2 = (uVar2 & 0x33333333) + (uVar2 >> 2 & 0x33333333);
  return (((uVar2 & 0xf0f0f0f) + (uVar2 >> 4 & 0xf0f0f0f)) * 0x1010101 >> 0x18) + uVar3;
}


//===== FUN_001245c0 @ 001245c0 size=770 =====

ulong FUN_001245c0(long param_1,ulong param_2)

{
  long lVar1;
  ulong uVar2;
  uint uVar3;
  ulong uVar4;
  uint *puVar5;
  uint uVar6;
  ulong uVar7;
  long lVar8;
  
  uVar3 = *(uint *)(*(long *)(param_1 + 0x80) + (param_2 >> 9) * 4);
  if ((param_2 & 0x1ff) == 0) {
    return (ulong)uVar3;
  }
  lVar8 = *(long *)(param_1 + 0x50);
  uVar2 = (ulong)(uVar3 >> 9);
  uVar4 = (ulong)(*(int *)(*(long *)(param_1 + 0x80) + 4 + (param_2 >> 9) * 4) + 0x1ffU >> 9);
  if (uVar2 + 10 < uVar4) {
    do {
      uVar7 = uVar2;
      uVar2 = uVar4;
      do {
        uVar4 = uVar2;
        if (uVar4 <= uVar7 + 1) goto LAB_0012464a;
        uVar2 = uVar4 + uVar7 >> 1;
      } while (param_2 < uVar2 * 0x200 - (ulong)*(uint *)(lVar8 + uVar2 * 0xc));
    } while( true );
  }
  puVar5 = (uint *)(lVar8 + (uVar2 * 3 + 3) * 4);
  do {
    uVar7 = uVar2;
    uVar3 = *puVar5;
    puVar5 = puVar5 + 3;
    uVar2 = uVar7 + 1;
  } while ((uVar7 + 1) * 0x200 - (ulong)uVar3 <= param_2);
LAB_0012464a:
  puVar5 = (uint *)(lVar8 + uVar7 * 0xc);
  lVar8 = uVar7 * 0x10;
  uVar3 = puVar5[1];
  uVar2 = (ulong)*puVar5 + param_2 + uVar7 * -0x200;
  if (uVar2 < 0x100 - (ulong)(uVar3 >> 0x17)) {
    uVar4 = (ulong)(uVar3 >> 7 & 0xff);
    if (uVar2 < 0x80 - uVar4) {
      if (0x40 - (ulong)(uVar3 & 0x7f) <= uVar2) {
        lVar8 = lVar8 + 2;
        uVar2 = (uVar2 - 0x40) + (ulong)(uVar3 & 0x7f);
      }
    }
    else {
      uVar7 = (ulong)(uVar3 >> 0xf & 0xff);
      if (uVar2 < 0xc0 - uVar7) {
        lVar8 = lVar8 + 4;
        uVar2 = (uVar2 - 0x80) + uVar4;
      }
      else {
        lVar8 = lVar8 + 6;
        uVar2 = (uVar2 - 0xc0) + uVar7;
      }
    }
  }
  else {
    uVar6 = puVar5[2];
    uVar4 = (ulong)(uVar6 >> 9 & 0x1ff);
    if (uVar2 < 0x180 - uVar4) {
      if (uVar2 < 0x140 - (ulong)(uVar6 & 0x1ff)) {
        lVar8 = lVar8 + 8;
        uVar2 = (uVar2 - 0x100) + (ulong)(uVar3 >> 0x17);
      }
      else {
        lVar8 = lVar8 + 10;
        uVar2 = (uVar2 - 0x140) + (ulong)(uVar6 & 0x1ff);
      }
    }
    else {
      uVar7 = (ulong)(uVar6 >> 0x12 & 0x1ff);
      if (uVar2 < 0x1c0 - uVar7) {
        lVar8 = lVar8 + 0xc;
        uVar2 = (uVar2 - 0x180) + uVar4;
      }
      else {
        lVar8 = lVar8 + 0xe;
        uVar2 = (uVar2 - 0x1c0) + uVar7;
      }
    }
  }
  lVar1 = lVar8 * 4;
  uVar3 = ~*(uint *)(*(long *)(param_1 + 0x10) + lVar8 * 4);
  uVar6 = (uVar3 >> 1 & 0x55555555) + (uVar3 & 0x55555555);
  uVar6 = (uVar6 & 0x33333333) + (uVar6 >> 2 & 0x33333333);
  uVar6 = ((uVar6 & 0xf0f0f0f) + (uVar6 >> 4 & 0xf0f0f0f)) * 0x1010101;
  if (uVar6 >> 0x18 <= uVar2) {
    uVar2 = uVar2 - (uVar6 >> 0x18);
    lVar8 = lVar8 + 1;
    uVar3 = ~*(uint *)(*(long *)(param_1 + 0x10) + 4 + lVar1);
    uVar6 = (uVar3 >> 1 & 0x55555555) + (uVar3 & 0x55555555);
    uVar6 = (uVar6 & 0x33333333) + (uVar6 >> 2 & 0x33333333);
    uVar6 = ((uVar6 & 0xf0f0f0f) + (uVar6 >> 4 & 0xf0f0f0f)) * 0x1010101;
  }
  lVar8 = lVar8 * 0x20;
  uVar4 = (ulong)(uVar6 >> 8 & 0xff);
  if (uVar2 < uVar4) {
    if ((uVar6 & 0xff) <= uVar2) {
      lVar8 = lVar8 + 8;
      uVar2 = uVar2 - (uVar6 & 0xff);
      uVar3 = uVar3 >> 8 & 0xff;
      goto LAB_001247d2;
    }
  }
  else {
    uVar7 = (ulong)(uVar6 >> 0x10 & 0xff);
    if (uVar7 <= uVar2) {
      lVar8 = lVar8 + 0x18;
      uVar3 = uVar3 >> 0x18;
      uVar2 = uVar2 - uVar7;
      goto LAB_001247d2;
    }
    lVar8 = lVar8 + 0x10;
    uVar2 = uVar2 - uVar4;
    uVar3 = uVar3 >> 0x10;
  }
  uVar3 = uVar3 & 0xff;
LAB_001247d2:
  return (ulong)(byte)PTR_DAT_00132fb0[(long)(int)uVar3 + uVar2 * 0x100] + lVar8;
}


//===== FUN_00124910 @ 00124910 size=632 =====

ulong FUN_00124910(long param_1,ulong param_2)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  uint uVar4;
  uint *puVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  
  uVar4 = *(uint *)(*(long *)(param_1 + 0xb0) + (param_2 >> 9) * 4);
  if ((param_2 & 0x1ff) == 0) {
    return (ulong)uVar4;
  }
  lVar1 = *(long *)(param_1 + 0x50);
  uVar8 = (ulong)(uVar4 >> 9);
  uVar3 = (ulong)(*(int *)(*(long *)(param_1 + 0xb0) + 4 + (param_2 >> 9) * 4) + 0x1ffU >> 9);
  if (uVar8 + 10 < uVar3) {
    do {
      uVar6 = uVar8;
      uVar8 = uVar3;
      do {
        uVar3 = uVar8;
        if (uVar3 <= uVar6 + 1) goto LAB_00124996;
        uVar8 = uVar3 + uVar6 >> 1;
      } while (param_2 < *(uint *)(lVar1 + ((uVar3 + uVar6 & 0xfffffffffffffffe) + uVar8) * 4));
    } while( true );
  }
  puVar5 = (uint *)(lVar1 + (uVar8 * 3 + 3) * 4);
  do {
    uVar6 = uVar8;
    uVar4 = *puVar5;
    puVar5 = puVar5 + 3;
    uVar8 = uVar6 + 1;
  } while (uVar4 <= param_2);
LAB_00124996:
  lVar7 = uVar6 * 0x10;
  puVar5 = (uint *)(lVar1 + uVar6 * 0xc);
  param_2 = param_2 - *puVar5;
  uVar4 = puVar5[1];
  if (param_2 < uVar4 >> 0x17) {
    uVar8 = (ulong)(uVar4 >> 7 & 0xff);
    if (param_2 < uVar8) {
      if ((uVar4 & 0x7f) <= param_2) {
        lVar7 = lVar7 + 2;
        param_2 = param_2 - (uVar4 & 0x7f);
      }
    }
    else {
      uVar3 = (ulong)(uVar4 >> 0xf & 0xff);
      if (param_2 < uVar3) {
        lVar7 = lVar7 + 4;
        param_2 = param_2 - uVar8;
      }
      else {
        lVar7 = lVar7 + 6;
        param_2 = param_2 - uVar3;
      }
    }
  }
  else {
    uVar2 = puVar5[2];
    uVar8 = (ulong)(uVar2 >> 9 & 0x1ff);
    if (param_2 < uVar8) {
      if (param_2 < (uVar2 & 0x1ff)) {
        lVar7 = lVar7 + 8;
        param_2 = param_2 - (uVar4 >> 0x17);
      }
      else {
        lVar7 = lVar7 + 10;
        param_2 = param_2 - (uVar2 & 0x1ff);
      }
    }
    else {
      uVar3 = (ulong)(uVar2 >> 0x12 & 0x1ff);
      if (param_2 < uVar3) {
        lVar7 = lVar7 + 0xc;
        param_2 = param_2 - uVar8;
      }
      else {
        lVar7 = lVar7 + 0xe;
        param_2 = param_2 - uVar3;
      }
    }
  }
  uVar4 = *(uint *)(*(long *)(param_1 + 0x10) + lVar7 * 4);
  uVar2 = (uVar4 >> 1 & 0x55555555) + (uVar4 & 0x55555555);
  uVar2 = (uVar2 & 0x33333333) + (uVar2 >> 2 & 0x33333333);
  uVar2 = ((uVar2 & 0xf0f0f0f) + (uVar2 >> 4 & 0xf0f0f0f)) * 0x1010101;
  if (uVar2 >> 0x18 <= param_2) {
    uVar4 = *(uint *)(*(long *)(param_1 + 0x10) + 4 + lVar7 * 4);
    param_2 = param_2 - (uVar2 >> 0x18);
    lVar7 = lVar7 + 1;
    uVar2 = (uVar4 >> 1 & 0x55555555) + (uVar4 & 0x55555555);
    uVar2 = (uVar2 & 0x33333333) + (uVar2 >> 2 & 0x33333333);
    uVar2 = ((uVar2 & 0xf0f0f0f) + (uVar2 >> 4 & 0xf0f0f0f)) * 0x1010101;
  }
  lVar7 = lVar7 * 0x20;
  uVar8 = (ulong)(uVar2 >> 8 & 0xff);
  if (param_2 < uVar8) {
    if ((uVar2 & 0xff) <= param_2) {
      lVar7 = lVar7 + 8;
      param_2 = param_2 - (uVar2 & 0xff);
      uVar4 = uVar4 >> 8 & 0xff;
      goto LAB_00124ad8;
    }
  }
  else {
    uVar3 = (ulong)(uVar2 >> 0x10 & 0xff);
    if (uVar3 <= param_2) {
      lVar7 = lVar7 + 0x18;
      uVar4 = uVar4 >> 0x18;
      param_2 = param_2 - uVar3;
      goto LAB_00124ad8;
    }
    lVar7 = lVar7 + 0x10;
    param_2 = param_2 - uVar8;
    uVar4 = uVar4 >> 0x10;
  }
  uVar4 = uVar4 & 0xff;
LAB_00124ad8:
  return (ulong)(byte)PTR_DAT_00132fb0[(long)(int)uVar4 + param_2 * 0x100] + lVar7;
}


//===== FUN_00124bd0 @ 00124bd0 size=300 =====

long FUN_00124bd0(long param_1,ulong param_2)

{
  uint *puVar1;
  ulong uVar2;
  ulong uVar3;
  
  puVar1 = (uint *)(*(long *)(param_1 + 0x50) + (param_2 >> 9) * 0xc);
  uVar3 = (ulong)*puVar1;
  switch((uint)(param_2 >> 6) & 7) {
  case 1:
    uVar3 = uVar3 + (puVar1[1] & 0x7f);
    break;
  case 2:
    uVar3 = uVar3 + (puVar1[1] >> 7 & 0xff);
    break;
  case 3:
    uVar3 = uVar3 + (puVar1[1] >> 0xf & 0xff);
    break;
  case 4:
    uVar3 = uVar3 + (puVar1[1] >> 0x17);
    break;
  case 5:
    uVar3 = uVar3 + (puVar1[2] & 0x1ff);
    break;
  case 6:
    uVar3 = uVar3 + (puVar1[2] >> 9 & 0x1ff);
    break;
  case 7:
    uVar3 = uVar3 + (puVar1[2] >> 0x12 & 0x1ff);
  }
  uVar2 = ~(-1L << ((byte)param_2 & 0x3f)) &
          *(ulong *)(*(long *)(param_1 + 0x10) + (param_2 >> 6) * 8);
  uVar2 = (uVar2 >> 1 & 0x5555555555555555) + (uVar2 & 0x5555555555555555);
  uVar2 = (uVar2 & 0x3333333333333333) + (uVar2 >> 2 & 0x3333333333333333);
  return (((uVar2 & 0xf0f0f0f0f0f0f0f) + (uVar2 >> 4 & 0xf0f0f0f0f0f0f0f)) * 0x101010101010101 >>
         0x38) + uVar3;
}


//===== FUN_00124d20 @ 00124d20 size=549 =====

ulong FUN_00124d20(long param_1,ulong param_2)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  uint *puVar6;
  ulong uVar7;
  long lVar8;
  
  uVar1 = *(uint *)(*(long *)(param_1 + 0x80) + (param_2 >> 9) * 4);
  if ((param_2 & 0x1ff) == 0) {
    return (ulong)uVar1;
  }
  uVar7 = (ulong)(uVar1 >> 9);
  lVar8 = *(long *)(param_1 + 0x50);
  uVar4 = (ulong)(*(int *)(*(long *)(param_1 + 0x80) + 4 + (param_2 >> 9) * 4) + 0x1ffU >> 9);
  if (uVar4 <= uVar7 + 10) {
    puVar6 = (uint *)(lVar8 + (uVar7 * 3 + 3) * 4);
    do {
      uVar3 = uVar7;
      uVar1 = *puVar6;
      puVar6 = puVar6 + 3;
      uVar7 = uVar3 + 1;
    } while ((uVar3 + 1) * 0x200 - (ulong)uVar1 <= param_2);
LAB_00124daa:
    lVar5 = uVar3 * 8;
    puVar6 = (uint *)(lVar8 + uVar3 * 0xc);
    lVar8 = uVar3 * 0x200;
    uVar7 = param_2 + uVar3 * -0x200 + (ulong)*puVar6;
    uVar1 = puVar6[1];
    if (uVar7 < 0x100 - (ulong)(uVar1 >> 0x17)) {
      uVar4 = (ulong)(uVar1 >> 7 & 0xff);
      if (uVar7 < 0x80 - uVar4) {
        if (0x40 - (ulong)(uVar1 & 0x7f) <= uVar7) {
          lVar5 = lVar5 + 1;
          uVar7 = (uVar7 - 0x40) + (ulong)(uVar1 & 0x7f);
          lVar8 = lVar5 * 0x40;
        }
      }
      else {
        uVar3 = (ulong)(uVar1 >> 0xf & 0xff);
        if (uVar7 < 0xc0 - uVar3) {
          lVar5 = lVar5 + 2;
          uVar7 = (uVar7 - 0x80) + uVar4;
          lVar8 = lVar5 * 0x40;
        }
        else {
          lVar5 = lVar5 + 3;
          uVar7 = (uVar7 - 0xc0) + uVar3;
          lVar8 = lVar5 * 0x40;
        }
      }
    }
    else {
      uVar2 = puVar6[2];
      uVar4 = (ulong)(uVar2 >> 9 & 0x1ff);
      if (uVar7 < 0x180 - uVar4) {
        if (uVar7 < 0x140 - (ulong)(uVar2 & 0x1ff)) {
          lVar5 = lVar5 + 4;
          uVar7 = (uVar7 - 0x100) + (ulong)(uVar1 >> 0x17);
          lVar8 = lVar5 * 0x40;
        }
        else {
          lVar5 = lVar5 + 5;
          uVar7 = (uVar7 - 0x140) + (ulong)(uVar2 & 0x1ff);
          lVar8 = lVar5 * 0x40;
        }
      }
      else {
        uVar3 = (ulong)(uVar2 >> 0x12 & 0x1ff);
        if (uVar7 < 0x1c0 - uVar3) {
          lVar5 = lVar5 + 6;
          uVar7 = (uVar7 - 0x180) + uVar4;
          lVar8 = lVar5 * 0x40;
        }
        else {
          lVar5 = lVar5 + 7;
          uVar7 = (uVar7 - 0x1c0) + uVar3;
          lVar8 = lVar5 * 0x40;
        }
      }
    }
    uVar7 = FUN_001242f0(uVar7,lVar8,~*(ulong *)(*(long *)(param_1 + 0x10) + lVar5 * 8));
    return uVar7;
  }
  do {
    uVar3 = uVar7;
    uVar7 = uVar4;
    do {
      uVar4 = uVar7;
      if (uVar4 <= uVar3 + 1) goto LAB_00124daa;
      uVar7 = uVar4 + uVar3 >> 1;
    } while (param_2 < uVar7 * 0x200 - (ulong)*(uint *)(lVar8 + uVar7 * 0xc));
  } while( true );
}


//===== FUN_00124f80 @ 00124f80 size=360 =====

ulong FUN_00124f80(long param_1,ulong param_2)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  uint *puVar5;
  ulong uVar6;
  long lVar7;
  
  uVar1 = *(uint *)(*(long *)(param_1 + 0xb0) + (param_2 >> 9) * 4);
  if ((param_2 & 0x1ff) == 0) {
    return (ulong)uVar1;
  }
  uVar4 = (ulong)(uVar1 >> 9);
  lVar7 = *(long *)(param_1 + 0x50);
  uVar3 = (ulong)(*(int *)(*(long *)(param_1 + 0xb0) + 4 + (param_2 >> 9) * 4) + 0x1ffU >> 9);
  if (uVar3 <= uVar4 + 10) {
    puVar5 = (uint *)(lVar7 + (uVar4 * 3 + 3) * 4);
    do {
      uVar6 = uVar4;
      uVar1 = *puVar5;
      puVar5 = puVar5 + 3;
      uVar4 = uVar6 + 1;
    } while (uVar1 <= param_2);
LAB_00124ff6:
    puVar5 = (uint *)(lVar7 + uVar6 * 0xc);
    param_2 = param_2 - *puVar5;
    uVar1 = puVar5[1];
    lVar7 = uVar6 * 8;
    if (param_2 < uVar1 >> 0x17) {
      uVar4 = (ulong)(uVar1 >> 7 & 0xff);
      if (param_2 < uVar4) {
        if ((uVar1 & 0x7f) <= param_2) {
          lVar7 = lVar7 + 1;
          param_2 = param_2 - (uVar1 & 0x7f);
        }
      }
      else {
        uVar3 = (ulong)(uVar1 >> 0xf & 0xff);
        if (param_2 < uVar3) {
          lVar7 = lVar7 + 2;
          param_2 = param_2 - uVar4;
        }
        else {
          lVar7 = lVar7 + 3;
          param_2 = param_2 - uVar3;
        }
      }
    }
    else {
      uVar2 = puVar5[2];
      uVar4 = (ulong)(uVar2 >> 9 & 0x1ff);
      if (param_2 < uVar4) {
        if (param_2 < (uVar2 & 0x1ff)) {
          lVar7 = lVar7 + 4;
          param_2 = param_2 - (uVar1 >> 0x17);
        }
        else {
          lVar7 = lVar7 + 5;
          param_2 = param_2 - (uVar2 & 0x1ff);
        }
      }
      else {
        uVar3 = (ulong)(uVar2 >> 0x12 & 0x1ff);
        if (param_2 < uVar3) {
          lVar7 = lVar7 + 6;
          param_2 = param_2 - uVar4;
        }
        else {
          lVar7 = lVar7 + 7;
          param_2 = param_2 - uVar3;
        }
      }
    }
    uVar4 = FUN_001242f0(param_2,lVar7 << 6,*(undefined8 *)(*(long *)(param_1 + 0x10) + lVar7 * 8));
    return uVar4;
  }
  do {
    uVar6 = uVar4;
    uVar4 = uVar3;
    do {
      uVar3 = uVar4;
      if (uVar3 <= uVar6 + 1) goto LAB_00124ff6;
      uVar4 = uVar3 + uVar6 >> 1;
    } while (param_2 < *(uint *)(lVar7 + ((uVar3 + uVar6 & 0xfffffffffffffffe) + uVar4) * 4));
  } while( true );
}


//===== FUN_00125120 @ 00125120 size=3709 =====

void FUN_00125120(long param_1,long param_2,char param_3,char param_4)

{
  undefined1 (*pauVar1) [16];
  undefined8 *puVar2;
  undefined8 uVar3;
  char cVar4;
  undefined8 uVar5;
  void *pvVar6;
  long lVar7;
  ulong uVar8;
  uint uVar9;
  undefined1 (*pauVar10) [16];
  undefined1 (*pauVar11) [16];
  long lVar12;
  ulong uVar13;
  uint uVar14;
  void *pvVar15;
  ulong uVar16;
  ulong uVar17;
  uint uVar18;
  int *piVar19;
  ulong uVar20;
  
  uVar8 = *(ulong *)(param_2 + 0x30);
  uVar13 = *(ulong *)(param_1 + 0x60);
  uVar20 = ((uVar8 >> 9) + 2) - (ulong)((uVar8 & 0x1ff) == 0);
  if (uVar13 < uVar20) {
    uVar8 = uVar13 * 2;
    if (uVar13 <= uVar20 >> 1) {
      uVar8 = uVar20;
    }
    pvVar6 = operator_new__(uVar8 * 0xc,(nothrow_t *)PTR_nothrow_00132fb8);
    uVar13 = *(ulong *)(param_1 + 0x58);
    if (uVar13 != 0) {
      lVar12 = *(long *)(param_1 + 0x48);
      lVar7 = 0;
      do {
        *(undefined8 *)((long)pvVar6 + lVar7) = *(undefined8 *)(lVar12 + lVar7);
        *(undefined4 *)((long)pvVar6 + lVar7 + 8) = *(undefined4 *)(lVar12 + 8 + lVar7);
        lVar7 = lVar7 + 0xc;
      } while (lVar7 != uVar13 * 0xc);
      pvVar15 = *(void **)(param_1 + 0x40);
      *(void **)(param_1 + 0x48) = pvVar6;
      *(void **)(param_1 + 0x40) = pvVar6;
      *(void **)(param_1 + 0x50) = pvVar6;
      *(ulong *)(param_1 + 0x60) = uVar8;
      if (pvVar15 != (void *)0x0) goto LAB_00125206;
      uVar8 = *(ulong *)(param_2 + 0x30);
      goto LAB_0012521e;
    }
    pvVar15 = *(void **)(param_1 + 0x40);
    *(void **)(param_1 + 0x50) = pvVar6;
    *(ulong *)(param_1 + 0x60) = uVar8;
    *(void **)(param_1 + 0x40) = pvVar6;
    *(void **)(param_1 + 0x48) = pvVar6;
    if (pvVar15 != (void *)0x0) {
LAB_00125206:
      operator_delete__(pvVar15);
      uVar13 = *(ulong *)(param_1 + 0x58);
      uVar8 = *(ulong *)(param_2 + 0x30);
      goto LAB_0012521e;
    }
    uVar8 = *(ulong *)(param_2 + 0x30);
LAB_0012522b:
    uVar16 = uVar13 + 1;
    uVar17 = 1;
    if (uVar16 <= uVar20) {
      uVar17 = uVar20 - uVar13;
    }
    if ((2 < (uVar20 - uVar13) - 1) && (uVar16 <= uVar20)) {
      pauVar1 = (undefined1 (*) [16])((long)pvVar6 + uVar13 * 0xc);
      pauVar10 = pauVar1;
      do {
        *pauVar10 = (undefined1  [16])0x0;
        pauVar11 = pauVar10 + 3;
        pauVar10[1] = (undefined1  [16])0x0;
        pauVar10[2] = (undefined1  [16])0x0;
        pauVar10 = pauVar11;
      } while (pauVar1 + (uVar17 >> 2) * 3 != pauVar11);
      uVar13 = uVar13 + (uVar17 & 0xfffffffffffffffc);
      if ((uVar17 & 0xfffffffffffffffc) == uVar17) goto LAB_001252e6;
      uVar16 = uVar13 + 1;
    }
    lVar12 = uVar13 * 0xc;
    *(undefined8 *)((long)pvVar6 + lVar12) = 0;
    *(undefined4 *)((undefined8 *)((long)pvVar6 + lVar12) + 1) = 0;
    if (uVar16 < uVar20) {
      puVar2 = (undefined8 *)((long)pvVar6 + lVar12 + 0xc);
      *puVar2 = 0;
      *(undefined4 *)(puVar2 + 1) = 0;
      if (uVar13 + 2 < uVar20) {
        puVar2 = (undefined8 *)((long)pvVar6 + lVar12 + 0x18);
        *puVar2 = 0;
        *(undefined4 *)(puVar2 + 1) = 0;
      }
    }
  }
  else {
    uVar13 = *(ulong *)(param_1 + 0x58);
LAB_0012521e:
    if (uVar13 < uVar20) {
      pvVar6 = *(void **)(param_1 + 0x48);
      goto LAB_0012522b;
    }
  }
LAB_001252e6:
  *(ulong *)(param_1 + 0x58) = uVar20;
  uVar13 = 0;
  uVar14 = 0;
  uVar18 = 0;
  if (uVar8 == 0) {
    lVar12 = *(long *)(param_1 + 0x48);
    uVar14 = 0;
  }
  else {
    do {
      if ((uVar13 & 0x3f) == 0) {
        lVar7 = *(long *)(param_1 + 0x48);
        lVar12 = (uVar13 >> 9) * 0xc;
        switch((uint)(uVar13 >> 6) & 7) {
        case 0:
          *(uint *)(lVar7 + (uVar13 >> 9) * 0xc) = uVar14;
          break;
        case 1:
          piVar19 = (int *)(lVar12 + lVar7);
          piVar19[1] = uVar14 - *piVar19 & 0x7f | piVar19[1] & 0xffffff80U;
          break;
        case 2:
          piVar19 = (int *)(lVar12 + lVar7);
          piVar19[1] = (uVar14 - *piVar19 & 0xff) << 7 | piVar19[1] & 0xffff807fU;
          break;
        case 3:
          piVar19 = (int *)(lVar12 + lVar7);
          piVar19[1] = (uVar14 - *piVar19 & 0xff) << 0xf | piVar19[1] & 0xff807fffU;
          break;
        case 4:
          piVar19 = (int *)(lVar12 + lVar7);
          piVar19[1] = (uVar14 - *piVar19) * 0x800000 | piVar19[1] & 0x7fffffU;
          break;
        case 5:
          piVar19 = (int *)(lVar12 + lVar7);
          piVar19[2] = uVar14 - *piVar19 & 0x1ff | piVar19[2] & 0xfffffe00U;
          break;
        case 6:
          piVar19 = (int *)(lVar12 + lVar7);
          piVar19[2] = (uVar14 - *piVar19 & 0x1ff) << 9 | piVar19[2] & 0xfffc01ffU;
          break;
        case 7:
          piVar19 = (int *)(lVar7 + lVar12);
          piVar19[2] = (uVar14 - *piVar19 & 0x1ff) << 0x12 | piVar19[2] & 0xf803ffffU;
        }
      }
      uVar9 = (uint)uVar13;
      if ((*(uint *)(*(long *)(param_2 + 0x10) + (uVar13 >> 5) * 4) >> (uVar9 & 0x1f) & 1) == 0) {
        if ((param_3 != '\0') && ((uVar18 & 0x1ff) == 0)) {
          uVar17 = *(ulong *)(param_1 + 0x88);
          uVar16 = *(ulong *)(param_1 + 0x90);
          uVar20 = uVar17 + 1;
          if (uVar16 < uVar20) {
            if (uVar20 >> 1 < uVar16) {
              uVar8 = 0xfffffffffffffffc;
              uVar20 = 0x3fffffffffffffff;
              if (uVar16 < 0x2000000000000000) {
                uVar20 = uVar16 * 2;
                uVar8 = uVar16 * 8;
              }
            }
            else {
              uVar8 = uVar20 * 4;
            }
            pvVar6 = operator_new__(uVar8,(nothrow_t *)PTR_nothrow_00132fb8);
            uVar17 = *(ulong *)(param_1 + 0x88);
            if (uVar17 != 0) {
              lVar12 = *(long *)(param_1 + 0x78);
              uVar8 = 0;
              if (((ulong)((long)pvVar6 - (lVar12 + 4)) < 9) || (uVar17 - 1 < 3)) {
                do {
                  *(undefined4 *)((long)pvVar6 + uVar8 * 4) = *(undefined4 *)(lVar12 + uVar8 * 4);
                  uVar8 = uVar8 + 1;
                } while (uVar17 != uVar8);
              }
              else {
                lVar7 = 0;
                do {
                  uVar3 = ((undefined8 *)(lVar12 + lVar7))[1];
                  *(undefined8 *)((long)pvVar6 + lVar7) = *(undefined8 *)(lVar12 + lVar7);
                  ((undefined8 *)((long)pvVar6 + lVar7))[1] = uVar3;
                  lVar7 = lVar7 + 0x10;
                } while (lVar7 != (uVar17 >> 2) * 0x10);
                uVar8 = uVar17 & 0xfffffffffffffffc;
                if ((uVar17 & 3) != 0) {
                  lVar7 = uVar8 * 4;
                  *(undefined4 *)((long)pvVar6 + uVar8 * 4) = *(undefined4 *)(lVar12 + uVar8 * 4);
                  if ((uVar8 + 1 < uVar17) &&
                     (*(undefined4 *)((long)pvVar6 + lVar7 + 4) =
                           *(undefined4 *)(lVar12 + 4 + lVar7), uVar8 + 2 < uVar17)) {
                    *(undefined4 *)((long)pvVar6 + lVar7 + 8) = *(undefined4 *)(lVar12 + 8 + lVar7);
                  }
                }
              }
            }
            pvVar15 = *(void **)(param_1 + 0x70);
            *(void **)(param_1 + 0x80) = pvVar6;
            *(ulong *)(param_1 + 0x90) = uVar20;
            *(void **)(param_1 + 0x70) = pvVar6;
            *(void **)(param_1 + 0x78) = pvVar6;
            if (pvVar15 == (void *)0x0) {
              uVar8 = *(ulong *)(param_2 + 0x30);
              uVar20 = uVar17 + 1;
            }
            else {
              operator_delete__(pvVar15);
              pvVar6 = *(void **)(param_1 + 0x78);
              uVar17 = *(ulong *)(param_1 + 0x88);
              uVar8 = *(ulong *)(param_2 + 0x30);
              uVar20 = uVar17 + 1;
            }
          }
          else {
            pvVar6 = *(void **)(param_1 + 0x78);
          }
          *(uint *)((long)pvVar6 + uVar17 * 4) = uVar9;
          *(ulong *)(param_1 + 0x88) = uVar20;
        }
        uVar18 = uVar18 + 1;
      }
      else {
        if ((param_4 != '\0') && ((uVar14 & 0x1ff) == 0)) {
          uVar17 = *(ulong *)(param_1 + 0xb8);
          uVar16 = *(ulong *)(param_1 + 0xc0);
          uVar20 = uVar17 + 1;
          if (uVar16 < uVar20) {
            if (uVar20 >> 1 < uVar16) {
              uVar8 = 0xfffffffffffffffc;
              uVar20 = 0x3fffffffffffffff;
              if (uVar16 < 0x2000000000000000) {
                uVar20 = uVar16 * 2;
                uVar8 = uVar16 * 8;
              }
            }
            else {
              uVar8 = uVar20 * 4;
            }
            pvVar6 = operator_new__(uVar8,(nothrow_t *)PTR_nothrow_00132fb8);
            uVar17 = *(ulong *)(param_1 + 0xb8);
            if (uVar17 != 0) {
              lVar12 = *(long *)(param_1 + 0xa8);
              uVar8 = 0;
              if (((ulong)((long)pvVar6 - (lVar12 + 4)) < 9) || (uVar17 - 1 < 3)) {
                do {
                  *(undefined4 *)((long)pvVar6 + uVar8 * 4) = *(undefined4 *)(lVar12 + uVar8 * 4);
                  uVar8 = uVar8 + 1;
                } while (uVar17 != uVar8);
              }
              else {
                lVar7 = 0;
                do {
                  uVar3 = ((undefined8 *)(lVar12 + lVar7))[1];
                  *(undefined8 *)((long)pvVar6 + lVar7) = *(undefined8 *)(lVar12 + lVar7);
                  ((undefined8 *)((long)pvVar6 + lVar7))[1] = uVar3;
                  lVar7 = lVar7 + 0x10;
                } while (lVar7 != (uVar17 >> 2) * 0x10);
                uVar8 = uVar17 & 0xfffffffffffffffc;
                if ((uVar17 & 3) != 0) {
                  lVar7 = uVar8 * 4;
                  *(undefined4 *)((long)pvVar6 + uVar8 * 4) = *(undefined4 *)(lVar12 + uVar8 * 4);
                  if ((uVar8 + 1 < uVar17) &&
                     (*(undefined4 *)((long)pvVar6 + lVar7 + 4) =
                           *(undefined4 *)(lVar12 + 4 + lVar7), uVar8 + 2 < uVar17)) {
                    *(undefined4 *)((long)pvVar6 + lVar7 + 8) = *(undefined4 *)(lVar12 + 8 + lVar7);
                  }
                }
              }
            }
            pvVar15 = *(void **)(param_1 + 0xa0);
            *(void **)(param_1 + 0xb0) = pvVar6;
            *(ulong *)(param_1 + 0xc0) = uVar20;
            *(void **)(param_1 + 0xa0) = pvVar6;
            *(void **)(param_1 + 0xa8) = pvVar6;
            if (pvVar15 == (void *)0x0) {
              uVar8 = *(ulong *)(param_2 + 0x30);
              uVar20 = uVar17 + 1;
            }
            else {
              operator_delete__(pvVar15);
              uVar17 = *(ulong *)(param_1 + 0xb8);
              pvVar6 = *(void **)(param_1 + 0xa8);
              uVar8 = *(ulong *)(param_2 + 0x30);
              uVar20 = uVar17 + 1;
            }
          }
          else {
            pvVar6 = *(void **)(param_1 + 0xa8);
          }
          *(uint *)((long)pvVar6 + uVar17 * 4) = uVar9;
          *(ulong *)(param_1 + 0xb8) = uVar20;
        }
        uVar14 = uVar14 + 1;
      }
      uVar13 = uVar13 + 1;
    } while (uVar13 < uVar8);
    lVar12 = *(long *)(param_1 + 0x48);
    uVar20 = *(ulong *)(param_1 + 0x58);
    if ((uVar8 & 0x1ff) == 0) goto switchD_001253eb_default;
    uVar13 = uVar8 - 1 >> 9;
    switch((uint)(uVar8 - 1 >> 6) & 7) {
    case 0:
      piVar19 = (int *)(lVar12 + uVar13 * 0xc);
      uVar9 = uVar14 - *piVar19;
      uVar18 = piVar19[1] & 0xffffff80U | uVar9 & 0x7f;
      piVar19[1] = uVar18;
      break;
    case 1:
      piVar19 = (int *)(lVar12 + uVar13 * 0xc);
      uVar18 = piVar19[1];
      uVar9 = uVar14 - *piVar19;
      break;
    case 2:
      piVar19 = (int *)(lVar12 + uVar13 * 0xc);
      uVar18 = piVar19[1];
      uVar9 = uVar14 - *piVar19;
      goto LAB_00125ec6;
    case 3:
      piVar19 = (int *)(lVar12 + uVar13 * 0xc);
      uVar18 = piVar19[1];
      uVar9 = uVar14 - *piVar19;
      goto LAB_00125e9e;
    case 4:
      piVar19 = (int *)(lVar12 + uVar13 * 0xc);
      uVar9 = uVar14 - *piVar19;
      goto LAB_00125e6c;
    case 5:
      piVar19 = (int *)(lVar12 + uVar13 * 0xc);
      uVar18 = piVar19[2];
      uVar9 = uVar14 - *piVar19;
      goto LAB_00125528;
    case 6:
      piVar19 = (int *)(lVar12 + uVar13 * 0xc);
      uVar18 = piVar19[2];
      uVar9 = uVar14 - *piVar19;
      goto LAB_00125544;
    default:
      goto switchD_001253eb_default;
    }
    uVar18 = (uVar9 & 0xff) << 7 | uVar18 & 0xffff807f;
    piVar19[1] = uVar18;
LAB_00125ec6:
    uVar18 = (uVar9 & 0xff) << 0xf | uVar18 & 0xff807fff;
    piVar19[1] = uVar18;
LAB_00125e9e:
    piVar19[1] = uVar18 & 0x7fffff | uVar9 << 0x17;
LAB_00125e6c:
    uVar18 = piVar19[2] & 0xfffffe00U | uVar9 & 0x1ff;
    piVar19[2] = uVar18;
LAB_00125528:
    uVar18 = (uVar9 & 0x1ff) << 9 | uVar18 & 0xfffc01ff;
    piVar19[2] = uVar18;
LAB_00125544:
    piVar19[2] = (uVar9 & 0x1ff) << 0x12 | uVar18 & 0xf803ffff;
  }
switchD_001253eb_default:
  uVar3 = *(undefined8 *)(param_2 + 0x38);
  *(ulong *)(param_1 + 0x30) = uVar8;
  *(undefined8 *)(param_1 + 0x38) = uVar3;
  *(uint *)(lVar12 + -0xc + uVar20 * 0xc) = uVar14;
  if (param_3 != '\0') {
    uVar8 = *(ulong *)(param_1 + 0x88);
    uVar20 = *(ulong *)(param_1 + 0x90);
    uVar3 = *(undefined8 *)(param_2 + 0x30);
    uVar13 = uVar8 + 1;
    if (uVar20 < uVar13) {
      if (uVar13 >> 1 < uVar20) {
        uVar8 = 0xfffffffffffffffc;
        uVar13 = 0x3fffffffffffffff;
        if (uVar20 >> 0x3d == 0) {
          uVar13 = uVar20 * 2;
          uVar8 = uVar20 * 8;
        }
      }
      else {
        uVar8 = uVar13 * 4;
      }
      pvVar6 = operator_new__(uVar8,(nothrow_t *)PTR_nothrow_00132fb8);
      uVar8 = *(ulong *)(param_1 + 0x88);
      if (uVar8 != 0) {
        lVar12 = *(long *)(param_1 + 0x78);
        if (((ulong)((long)pvVar6 - (lVar12 + 4)) < 9) || (uVar8 - 1 < 3)) {
          uVar20 = 0;
          do {
            *(undefined4 *)((long)pvVar6 + uVar20 * 4) = *(undefined4 *)(lVar12 + uVar20 * 4);
            uVar20 = uVar20 + 1;
          } while (uVar8 != uVar20);
        }
        else {
          lVar7 = 0;
          do {
            uVar5 = ((undefined8 *)(lVar12 + lVar7))[1];
            *(undefined8 *)((long)pvVar6 + lVar7) = *(undefined8 *)(lVar12 + lVar7);
            ((undefined8 *)((long)pvVar6 + lVar7))[1] = uVar5;
            lVar7 = lVar7 + 0x10;
          } while (lVar7 != (uVar8 >> 2) * 0x10);
          uVar20 = uVar8 & 0xfffffffffffffffc;
          if ((uVar8 & 3) != 0) {
            lVar7 = uVar20 * 4;
            *(undefined4 *)((long)pvVar6 + uVar20 * 4) = *(undefined4 *)(lVar12 + uVar20 * 4);
            if ((uVar20 + 1 < uVar8) &&
               (*(undefined4 *)((long)pvVar6 + lVar7 + 4) = *(undefined4 *)(lVar12 + 4 + lVar7),
               uVar20 + 2 < uVar8)) {
              *(undefined4 *)((long)pvVar6 + lVar7 + 8) = *(undefined4 *)(lVar12 + 8 + lVar7);
            }
          }
        }
      }
      pvVar15 = *(void **)(param_1 + 0x70);
      *(void **)(param_1 + 0x80) = pvVar6;
      *(ulong *)(param_1 + 0x90) = uVar13;
      *(void **)(param_1 + 0x70) = pvVar6;
      *(void **)(param_1 + 0x78) = pvVar6;
      if (pvVar15 != (void *)0x0) {
        operator_delete__(pvVar15);
        pvVar6 = *(void **)(param_1 + 0x78);
        uVar8 = *(ulong *)(param_1 + 0x88);
      }
      uVar13 = uVar8 + 1;
    }
    else {
      pvVar6 = *(void **)(param_1 + 0x78);
    }
    cVar4 = *(char *)(param_1 + 0x98);
    *(int *)((long)pvVar6 + uVar8 * 4) = (int)uVar3;
    *(ulong *)(param_1 + 0x88) = uVar13;
    if (cVar4 != '\0') goto LAB_00126014;
    if (*(ulong *)(param_1 + 0x90) != uVar13) {
      pvVar6 = operator_new__(uVar13 * 4,(nothrow_t *)PTR_nothrow_00132fb8);
      uVar20 = *(ulong *)(param_1 + 0x88);
      if (uVar20 != 0) {
        lVar12 = *(long *)(param_1 + 0x78);
        if (((ulong)((long)pvVar6 - (lVar12 + 4)) < 9) || (uVar20 - 1 < 3)) {
          uVar8 = 0;
          do {
            *(undefined4 *)((long)pvVar6 + uVar8 * 4) = *(undefined4 *)(lVar12 + uVar8 * 4);
            uVar8 = uVar8 + 1;
          } while (uVar20 != uVar8);
        }
        else {
          lVar7 = 0;
          do {
            uVar3 = ((undefined8 *)(lVar12 + lVar7))[1];
            *(undefined8 *)((long)pvVar6 + lVar7) = *(undefined8 *)(lVar12 + lVar7);
            ((undefined8 *)((long)pvVar6 + lVar7))[1] = uVar3;
            lVar7 = lVar7 + 0x10;
          } while ((uVar20 >> 2) * 0x10 != lVar7);
          uVar8 = uVar20 & 0xfffffffffffffffc;
          if ((uVar20 & 3) != 0) {
            lVar7 = uVar8 * 4;
            *(undefined4 *)((long)pvVar6 + uVar8 * 4) = *(undefined4 *)(lVar12 + uVar8 * 4);
            if ((uVar8 + 1 < uVar20) &&
               (*(undefined4 *)((long)pvVar6 + lVar7 + 4) = *(undefined4 *)(lVar12 + 4 + lVar7),
               uVar8 + 2 < uVar20)) {
              *(undefined4 *)((long)pvVar6 + lVar7 + 8) = *(undefined4 *)(lVar12 + 8 + lVar7);
            }
          }
        }
      }
      pvVar15 = *(void **)(param_1 + 0x70);
      *(void **)(param_1 + 0x80) = pvVar6;
      *(ulong *)(param_1 + 0x90) = uVar13;
      *(void **)(param_1 + 0x70) = pvVar6;
      *(void **)(param_1 + 0x78) = pvVar6;
      if (pvVar15 != (void *)0x0) {
        operator_delete__(pvVar15);
      }
    }
  }
  if (param_4 != '\0') {
    uVar8 = *(ulong *)(param_1 + 0xb8);
    uVar20 = *(ulong *)(param_1 + 0xc0);
    uVar3 = *(undefined8 *)(param_2 + 0x30);
    uVar13 = uVar8 + 1;
    if (uVar20 < uVar13) {
      if (uVar13 >> 1 < uVar20) {
        uVar8 = 0xfffffffffffffffc;
        uVar13 = 0x3fffffffffffffff;
        if (uVar20 >> 0x3d == 0) {
          uVar13 = uVar20 * 2;
          uVar8 = uVar20 * 8;
        }
      }
      else {
        uVar8 = uVar13 * 4;
      }
      pvVar6 = operator_new__(uVar8,(nothrow_t *)PTR_nothrow_00132fb8);
      uVar8 = *(ulong *)(param_1 + 0xb8);
      if (uVar8 != 0) {
        lVar12 = *(long *)(param_1 + 0xa8);
        if (((ulong)((long)pvVar6 - (lVar12 + 4)) < 9) || (uVar8 - 1 < 3)) {
          uVar20 = 0;
          do {
            *(undefined4 *)((long)pvVar6 + uVar20 * 4) = *(undefined4 *)(lVar12 + uVar20 * 4);
            uVar20 = uVar20 + 1;
          } while (uVar8 != uVar20);
        }
        else {
          lVar7 = 0;
          do {
            uVar5 = ((undefined8 *)(lVar12 + lVar7))[1];
            *(undefined8 *)((long)pvVar6 + lVar7) = *(undefined8 *)(lVar12 + lVar7);
            ((undefined8 *)((long)pvVar6 + lVar7))[1] = uVar5;
            lVar7 = lVar7 + 0x10;
          } while ((uVar8 >> 2) * 0x10 != lVar7);
          uVar20 = uVar8 & 0xfffffffffffffffc;
          if ((uVar8 & 3) != 0) {
            lVar7 = uVar20 * 4;
            *(undefined4 *)((long)pvVar6 + uVar20 * 4) = *(undefined4 *)(lVar12 + uVar20 * 4);
            if ((uVar20 + 1 < uVar8) &&
               (*(undefined4 *)((long)pvVar6 + lVar7 + 4) = *(undefined4 *)(lVar12 + 4 + lVar7),
               uVar20 + 2 < uVar8)) {
              *(undefined4 *)((long)pvVar6 + lVar7 + 8) = *(undefined4 *)(lVar12 + 8 + lVar7);
            }
          }
        }
      }
      pvVar15 = *(void **)(param_1 + 0xa0);
      *(void **)(param_1 + 0xb0) = pvVar6;
      *(ulong *)(param_1 + 0xc0) = uVar13;
      *(void **)(param_1 + 0xa0) = pvVar6;
      *(void **)(param_1 + 0xa8) = pvVar6;
      if (pvVar15 != (void *)0x0) {
        operator_delete__(pvVar15);
        pvVar6 = *(void **)(param_1 + 0xa8);
        uVar8 = *(ulong *)(param_1 + 0xb8);
      }
      uVar13 = uVar8 + 1;
    }
    else {
      pvVar6 = *(void **)(param_1 + 0xa8);
    }
    cVar4 = *(char *)(param_1 + 200);
    *(int *)((long)pvVar6 + uVar8 * 4) = (int)uVar3;
    *(ulong *)(param_1 + 0xb8) = uVar13;
    if (cVar4 != '\0') {
LAB_00126014:
                    /* WARNING: Subroutine does not return */
      FUN_00107cc0();
    }
    if (*(ulong *)(param_1 + 0xc0) != uVar13) {
      pvVar6 = operator_new__(uVar13 * 4,(nothrow_t *)PTR_nothrow_00132fb8);
      uVar20 = *(ulong *)(param_1 + 0xb8);
      if (uVar20 != 0) {
        lVar12 = *(long *)(param_1 + 0xa8);
        if (((ulong)((long)pvVar6 - (lVar12 + 4)) < 9) || (uVar20 - 1 < 3)) {
          uVar8 = 0;
          do {
            *(undefined4 *)((long)pvVar6 + uVar8 * 4) = *(undefined4 *)(lVar12 + uVar8 * 4);
            uVar8 = uVar8 + 1;
          } while (uVar20 != uVar8);
        }
        else {
          lVar7 = 0;
          do {
            uVar3 = ((undefined8 *)(lVar12 + lVar7))[1];
            *(undefined8 *)((long)pvVar6 + lVar7) = *(undefined8 *)(lVar12 + lVar7);
            ((undefined8 *)((long)pvVar6 + lVar7))[1] = uVar3;
            lVar7 = lVar7 + 0x10;
          } while ((uVar20 >> 2) * 0x10 != lVar7);
          uVar8 = uVar20 & 0xfffffffffffffffc;
          if ((uVar20 & 3) != 0) {
            lVar7 = uVar8 * 4;
            *(undefined4 *)((long)pvVar6 + uVar8 * 4) = *(undefined4 *)(lVar12 + uVar8 * 4);
            if ((uVar8 + 1 < uVar20) &&
               (*(undefined4 *)((long)pvVar6 + lVar7 + 4) = *(undefined4 *)(lVar12 + 4 + lVar7),
               uVar8 + 2 < uVar20)) {
              *(undefined4 *)((long)pvVar6 + lVar7 + 8) = *(undefined4 *)(lVar12 + 8 + lVar7);
            }
          }
        }
      }
      pvVar15 = *(void **)(param_1 + 0xa0);
      *(void **)(param_1 + 0xb0) = pvVar6;
      *(ulong *)(param_1 + 0xc0) = uVar13;
      *(void **)(param_1 + 0xa0) = pvVar6;
      *(void **)(param_1 + 0xa8) = pvVar6;
      if (pvVar15 != (void *)0x0) {
        operator_delete__(pvVar15);
        return;
      }
    }
  }
  return;
}


//===== FUN_00126020 @ 00126020 size=3738 =====

void FUN_00126020(long param_1,long param_2,char param_3,char param_4)

{
  undefined1 (*pauVar1) [16];
  undefined8 *puVar2;
  undefined8 uVar3;
  char cVar4;
  undefined8 uVar5;
  void *pvVar6;
  long lVar7;
  ulong uVar8;
  uint uVar9;
  undefined1 (*pauVar10) [16];
  undefined1 (*pauVar11) [16];
  long lVar12;
  ulong uVar13;
  int *piVar14;
  uint uVar15;
  void *pvVar16;
  ulong uVar17;
  ulong uVar18;
  uint uVar19;
  ulong uVar20;
  
  uVar8 = *(ulong *)(param_2 + 0x30);
  uVar13 = *(ulong *)(param_1 + 0x60);
  uVar20 = ((uVar8 >> 9) + 2) - (ulong)((uVar8 & 0x1ff) == 0);
  if (uVar13 < uVar20) {
    uVar8 = uVar13 * 2;
    if (uVar13 <= uVar20 >> 1) {
      uVar8 = uVar20;
    }
    pvVar6 = operator_new__(uVar8 * 0xc,(nothrow_t *)PTR_nothrow_00132fb8);
    uVar13 = *(ulong *)(param_1 + 0x58);
    if (uVar13 != 0) {
      lVar12 = *(long *)(param_1 + 0x48);
      lVar7 = 0;
      do {
        *(undefined8 *)((long)pvVar6 + lVar7) = *(undefined8 *)(lVar12 + lVar7);
        *(undefined4 *)((long)pvVar6 + lVar7 + 8) = *(undefined4 *)(lVar12 + 8 + lVar7);
        lVar7 = lVar7 + 0xc;
      } while (lVar7 != uVar13 * 0xc);
      pvVar16 = *(void **)(param_1 + 0x40);
      *(void **)(param_1 + 0x48) = pvVar6;
      *(void **)(param_1 + 0x40) = pvVar6;
      *(void **)(param_1 + 0x50) = pvVar6;
      *(ulong *)(param_1 + 0x60) = uVar8;
      if (pvVar16 != (void *)0x0) goto LAB_00126106;
      uVar8 = *(ulong *)(param_2 + 0x30);
      goto LAB_0012611e;
    }
    pvVar16 = *(void **)(param_1 + 0x40);
    *(void **)(param_1 + 0x50) = pvVar6;
    *(ulong *)(param_1 + 0x60) = uVar8;
    *(void **)(param_1 + 0x40) = pvVar6;
    *(void **)(param_1 + 0x48) = pvVar6;
    if (pvVar16 != (void *)0x0) {
LAB_00126106:
      operator_delete__(pvVar16);
      uVar13 = *(ulong *)(param_1 + 0x58);
      uVar8 = *(ulong *)(param_2 + 0x30);
      goto LAB_0012611e;
    }
    uVar8 = *(ulong *)(param_2 + 0x30);
LAB_0012612b:
    uVar17 = uVar13 + 1;
    uVar18 = 1;
    if (uVar17 <= uVar20) {
      uVar18 = uVar20 - uVar13;
    }
    if ((2 < (uVar20 - uVar13) - 1) && (uVar17 <= uVar20)) {
      pauVar1 = (undefined1 (*) [16])((long)pvVar6 + uVar13 * 0xc);
      pauVar10 = pauVar1;
      do {
        *pauVar10 = (undefined1  [16])0x0;
        pauVar11 = pauVar10 + 3;
        pauVar10[1] = (undefined1  [16])0x0;
        pauVar10[2] = (undefined1  [16])0x0;
        pauVar10 = pauVar11;
      } while (pauVar11 != pauVar1 + (uVar18 >> 2) * 3);
      uVar13 = uVar13 + (uVar18 & 0xfffffffffffffffc);
      if ((uVar18 & 0xfffffffffffffffc) == uVar18) goto LAB_001261e6;
      uVar17 = uVar13 + 1;
    }
    lVar12 = uVar13 * 0xc;
    *(undefined8 *)((long)pvVar6 + lVar12) = 0;
    *(undefined4 *)((undefined8 *)((long)pvVar6 + lVar12) + 1) = 0;
    if (uVar17 < uVar20) {
      puVar2 = (undefined8 *)((long)pvVar6 + lVar12 + 0xc);
      *puVar2 = 0;
      *(undefined4 *)(puVar2 + 1) = 0;
      if (uVar13 + 2 < uVar20) {
        puVar2 = (undefined8 *)((long)pvVar6 + lVar12 + 0x18);
        *puVar2 = 0;
        *(undefined4 *)(puVar2 + 1) = 0;
      }
    }
  }
  else {
    uVar13 = *(ulong *)(param_1 + 0x58);
LAB_0012611e:
    if (uVar13 < uVar20) {
      pvVar6 = *(void **)(param_1 + 0x48);
      goto LAB_0012612b;
    }
  }
LAB_001261e6:
  *(ulong *)(param_1 + 0x58) = uVar20;
  uVar13 = 0;
  uVar15 = 0;
  uVar19 = 0;
  if (uVar8 == 0) {
    lVar12 = *(long *)(param_1 + 0x48);
    uVar15 = 0;
  }
  else {
    do {
      if ((uVar13 & 0x3f) == 0) {
        lVar7 = *(long *)(param_1 + 0x48);
        lVar12 = (uVar13 >> 9) * 0xc;
        switch((uint)(uVar13 >> 6) & 7) {
        case 0:
          *(uint *)(lVar7 + (uVar13 >> 9) * 0xc) = uVar15;
          break;
        case 1:
          piVar14 = (int *)(lVar12 + lVar7);
          piVar14[1] = uVar15 - *piVar14 & 0x7f | piVar14[1] & 0xffffff80U;
          break;
        case 2:
          piVar14 = (int *)(lVar12 + lVar7);
          piVar14[1] = (uVar15 - *piVar14 & 0xff) << 7 | piVar14[1] & 0xffff807fU;
          break;
        case 3:
          piVar14 = (int *)(lVar12 + lVar7);
          piVar14[1] = (uVar15 - *piVar14 & 0xff) << 0xf | piVar14[1] & 0xff807fffU;
          break;
        case 4:
          piVar14 = (int *)(lVar12 + lVar7);
          piVar14[1] = (uVar15 - *piVar14) * 0x800000 | piVar14[1] & 0x7fffffU;
          break;
        case 5:
          piVar14 = (int *)(lVar12 + lVar7);
          piVar14[2] = uVar15 - *piVar14 & 0x1ff | piVar14[2] & 0xfffffe00U;
          break;
        case 6:
          piVar14 = (int *)(lVar12 + lVar7);
          piVar14[2] = (uVar15 - *piVar14 & 0x1ff) << 9 | piVar14[2] & 0xfffc01ffU;
          break;
        case 7:
          piVar14 = (int *)(lVar12 + lVar7);
          piVar14[2] = (uVar15 - *piVar14 & 0x1ff) << 0x12 | piVar14[2] & 0xf803ffffU;
        }
      }
      if ((*(ulong *)(*(long *)(param_2 + 0x10) + (uVar13 >> 6) * 8) >> (uVar13 & 0x3f) & 1) == 0) {
        if ((param_3 != '\0') && ((uVar19 & 0x1ff) == 0)) {
          uVar18 = *(ulong *)(param_1 + 0x88);
          uVar17 = *(ulong *)(param_1 + 0x90);
          uVar20 = uVar18 + 1;
          if (uVar17 < uVar20) {
            if (uVar20 >> 1 < uVar17) {
              uVar8 = 0xfffffffffffffffc;
              uVar20 = 0x3fffffffffffffff;
              if (uVar17 < 0x2000000000000000) {
                uVar20 = uVar17 * 2;
                uVar8 = uVar17 * 8;
              }
            }
            else {
              uVar8 = uVar20 * 4;
            }
            pvVar6 = operator_new__(uVar8,(nothrow_t *)PTR_nothrow_00132fb8);
            uVar18 = *(ulong *)(param_1 + 0x88);
            if (uVar18 != 0) {
              lVar12 = *(long *)(param_1 + 0x78);
              uVar8 = 0;
              if (((ulong)((long)pvVar6 - (lVar12 + 4)) < 9) || (uVar18 - 1 < 3)) {
                do {
                  *(undefined4 *)((long)pvVar6 + uVar8 * 4) = *(undefined4 *)(lVar12 + uVar8 * 4);
                  uVar8 = uVar8 + 1;
                } while (uVar8 != uVar18);
              }
              else {
                lVar7 = 0;
                do {
                  uVar3 = ((undefined8 *)(lVar12 + lVar7))[1];
                  *(undefined8 *)((long)pvVar6 + lVar7) = *(undefined8 *)(lVar12 + lVar7);
                  ((undefined8 *)((long)pvVar6 + lVar7))[1] = uVar3;
                  lVar7 = lVar7 + 0x10;
                } while (lVar7 != (uVar18 >> 2) * 0x10);
                uVar8 = uVar18 & 0xfffffffffffffffc;
                if ((uVar18 & 3) != 0) {
                  lVar7 = uVar8 * 4;
                  *(undefined4 *)((long)pvVar6 + uVar8 * 4) = *(undefined4 *)(lVar12 + uVar8 * 4);
                  if ((uVar8 + 1 < uVar18) &&
                     (*(undefined4 *)((long)pvVar6 + lVar7 + 4) =
                           *(undefined4 *)(lVar12 + 4 + lVar7), uVar8 + 2 < uVar18)) {
                    *(undefined4 *)((long)pvVar6 + lVar7 + 8) = *(undefined4 *)(lVar12 + 8 + lVar7);
                  }
                }
              }
            }
            pvVar16 = *(void **)(param_1 + 0x70);
            *(void **)(param_1 + 0x80) = pvVar6;
            *(ulong *)(param_1 + 0x90) = uVar20;
            *(void **)(param_1 + 0x70) = pvVar6;
            *(void **)(param_1 + 0x78) = pvVar6;
            if (pvVar16 == (void *)0x0) {
              uVar8 = *(ulong *)(param_2 + 0x30);
              uVar20 = uVar18 + 1;
            }
            else {
              operator_delete__(pvVar16);
              pvVar6 = *(void **)(param_1 + 0x78);
              uVar18 = *(ulong *)(param_1 + 0x88);
              uVar8 = *(ulong *)(param_2 + 0x30);
              uVar20 = uVar18 + 1;
            }
          }
          else {
            pvVar6 = *(void **)(param_1 + 0x78);
          }
          *(int *)((long)pvVar6 + uVar18 * 4) = (int)uVar13;
          *(ulong *)(param_1 + 0x88) = uVar20;
        }
        uVar19 = uVar19 + 1;
      }
      else {
        if ((param_4 != '\0') && ((uVar15 & 0x1ff) == 0)) {
          uVar18 = *(ulong *)(param_1 + 0xb8);
          uVar17 = *(ulong *)(param_1 + 0xc0);
          uVar20 = uVar18 + 1;
          if (uVar17 < uVar20) {
            if (uVar20 >> 1 < uVar17) {
              uVar8 = 0xfffffffffffffffc;
              uVar20 = 0x3fffffffffffffff;
              if (uVar17 < 0x2000000000000000) {
                uVar20 = uVar17 * 2;
                uVar8 = uVar17 * 8;
              }
            }
            else {
              uVar8 = uVar20 * 4;
            }
            pvVar6 = operator_new__(uVar8,(nothrow_t *)PTR_nothrow_00132fb8);
            uVar18 = *(ulong *)(param_1 + 0xb8);
            if (uVar18 != 0) {
              lVar12 = *(long *)(param_1 + 0xa8);
              uVar8 = 0;
              if (((ulong)((long)pvVar6 - (lVar12 + 4)) < 9) || (uVar18 - 1 < 3)) {
                do {
                  *(undefined4 *)((long)pvVar6 + uVar8 * 4) = *(undefined4 *)(lVar12 + uVar8 * 4);
                  uVar8 = uVar8 + 1;
                } while (uVar18 != uVar8);
              }
              else {
                lVar7 = 0;
                do {
                  uVar3 = ((undefined8 *)(lVar12 + lVar7))[1];
                  *(undefined8 *)((long)pvVar6 + lVar7) = *(undefined8 *)(lVar12 + lVar7);
                  ((undefined8 *)((long)pvVar6 + lVar7))[1] = uVar3;
                  lVar7 = lVar7 + 0x10;
                } while ((uVar18 >> 2) * 0x10 != lVar7);
                uVar8 = uVar18 & 0xfffffffffffffffc;
                if ((uVar18 & 3) != 0) {
                  lVar7 = uVar8 * 4;
                  *(undefined4 *)((long)pvVar6 + uVar8 * 4) = *(undefined4 *)(lVar12 + uVar8 * 4);
                  if ((uVar8 + 1 < uVar18) &&
                     (*(undefined4 *)((long)pvVar6 + lVar7 + 4) =
                           *(undefined4 *)(lVar12 + 4 + lVar7), uVar8 + 2 < uVar18)) {
                    *(undefined4 *)((long)pvVar6 + lVar7 + 8) = *(undefined4 *)(lVar12 + 8 + lVar7);
                  }
                }
              }
            }
            pvVar16 = *(void **)(param_1 + 0xa0);
            *(void **)(param_1 + 0xb0) = pvVar6;
            *(ulong *)(param_1 + 0xc0) = uVar20;
            *(void **)(param_1 + 0xa0) = pvVar6;
            *(void **)(param_1 + 0xa8) = pvVar6;
            if (pvVar16 == (void *)0x0) {
              uVar8 = *(ulong *)(param_2 + 0x30);
              uVar20 = uVar18 + 1;
            }
            else {
              operator_delete__(pvVar16);
              uVar18 = *(ulong *)(param_1 + 0xb8);
              pvVar6 = *(void **)(param_1 + 0xa8);
              uVar8 = *(ulong *)(param_2 + 0x30);
              uVar20 = uVar18 + 1;
            }
          }
          else {
            pvVar6 = *(void **)(param_1 + 0xa8);
          }
          *(int *)((long)pvVar6 + uVar18 * 4) = (int)uVar13;
          *(ulong *)(param_1 + 0xb8) = uVar20;
        }
        uVar15 = uVar15 + 1;
      }
      uVar13 = uVar13 + 1;
    } while (uVar13 < uVar8);
    lVar12 = *(long *)(param_1 + 0x48);
    uVar20 = *(ulong *)(param_1 + 0x58);
    if ((uVar8 & 0x1ff) == 0) goto switchD_001262ee_default;
    uVar13 = uVar8 - 1 >> 9;
    switch((uint)(uVar8 - 1 >> 6) & 7) {
    case 0:
      piVar14 = (int *)(lVar12 + uVar13 * 0xc);
      uVar9 = uVar15 - *piVar14;
      uVar19 = piVar14[1] & 0xffffff80U | uVar9 & 0x7f;
      piVar14[1] = uVar19;
      break;
    case 1:
      piVar14 = (int *)(lVar12 + uVar13 * 0xc);
      uVar19 = piVar14[1];
      uVar9 = uVar15 - *piVar14;
      break;
    case 2:
      piVar14 = (int *)(lVar12 + uVar13 * 0xc);
      uVar19 = piVar14[1];
      uVar9 = uVar15 - *piVar14;
      goto LAB_00126de6;
    case 3:
      piVar14 = (int *)(lVar12 + uVar13 * 0xc);
      uVar19 = piVar14[1];
      uVar9 = uVar15 - *piVar14;
      goto LAB_00126dbe;
    case 4:
      piVar14 = (int *)(lVar12 + uVar13 * 0xc);
      uVar9 = uVar15 - *piVar14;
      goto LAB_00126d8c;
    case 5:
      piVar14 = (int *)(lVar12 + uVar13 * 0xc);
      uVar19 = piVar14[2];
      uVar9 = uVar15 - *piVar14;
      goto LAB_00126448;
    case 6:
      piVar14 = (int *)(lVar12 + uVar13 * 0xc);
      uVar19 = piVar14[2];
      uVar9 = uVar15 - *piVar14;
      goto LAB_00126464;
    default:
      goto switchD_001262ee_default;
    }
    uVar19 = (uVar9 & 0xff) << 7 | uVar19 & 0xffff807f;
    piVar14[1] = uVar19;
LAB_00126de6:
    uVar19 = (uVar9 & 0xff) << 0xf | uVar19 & 0xff807fff;
    piVar14[1] = uVar19;
LAB_00126dbe:
    piVar14[1] = uVar19 & 0x7fffff | uVar9 << 0x17;
LAB_00126d8c:
    uVar19 = piVar14[2] & 0xfffffe00U | uVar9 & 0x1ff;
    piVar14[2] = uVar19;
LAB_00126448:
    uVar19 = (uVar9 & 0x1ff) << 9 | uVar19 & 0xfffc01ff;
    piVar14[2] = uVar19;
LAB_00126464:
    piVar14[2] = (uVar9 & 0x1ff) << 0x12 | uVar19 & 0xf803ffff;
  }
switchD_001262ee_default:
  uVar3 = *(undefined8 *)(param_2 + 0x38);
  *(ulong *)(param_1 + 0x30) = uVar8;
  *(undefined8 *)(param_1 + 0x38) = uVar3;
  *(uint *)(lVar12 + -0xc + uVar20 * 0xc) = uVar15;
  if (param_3 != '\0') {
    uVar8 = *(ulong *)(param_1 + 0x88);
    uVar20 = *(ulong *)(param_1 + 0x90);
    uVar3 = *(undefined8 *)(param_2 + 0x30);
    uVar13 = uVar8 + 1;
    if (uVar20 < uVar13) {
      if (uVar13 >> 1 < uVar20) {
        uVar8 = 0xfffffffffffffffc;
        uVar13 = 0x3fffffffffffffff;
        if (uVar20 >> 0x3d == 0) {
          uVar13 = uVar20 * 2;
          uVar8 = uVar20 * 8;
        }
      }
      else {
        uVar8 = uVar13 * 4;
      }
      pvVar6 = operator_new__(uVar8,(nothrow_t *)PTR_nothrow_00132fb8);
      uVar8 = *(ulong *)(param_1 + 0x88);
      if (uVar8 != 0) {
        lVar12 = *(long *)(param_1 + 0x78);
        if (((ulong)((long)pvVar6 - (lVar12 + 4)) < 9) || (uVar8 - 1 < 3)) {
          uVar20 = 0;
          do {
            *(undefined4 *)((long)pvVar6 + uVar20 * 4) = *(undefined4 *)(lVar12 + uVar20 * 4);
            uVar20 = uVar20 + 1;
          } while (uVar8 != uVar20);
        }
        else {
          lVar7 = 0;
          do {
            uVar5 = ((undefined8 *)(lVar12 + lVar7))[1];
            *(undefined8 *)((long)pvVar6 + lVar7) = *(undefined8 *)(lVar12 + lVar7);
            ((undefined8 *)((long)pvVar6 + lVar7))[1] = uVar5;
            lVar7 = lVar7 + 0x10;
          } while ((uVar8 >> 2) * 0x10 != lVar7);
          uVar20 = uVar8 & 0xfffffffffffffffc;
          if ((uVar8 & 3) != 0) {
            lVar7 = uVar20 * 4;
            *(undefined4 *)((long)pvVar6 + uVar20 * 4) = *(undefined4 *)(lVar12 + uVar20 * 4);
            if ((uVar20 + 1 < uVar8) &&
               (*(undefined4 *)((long)pvVar6 + lVar7 + 4) = *(undefined4 *)(lVar12 + 4 + lVar7),
               uVar20 + 2 < uVar8)) {
              *(undefined4 *)((long)pvVar6 + lVar7 + 8) = *(undefined4 *)(lVar12 + 8 + lVar7);
            }
          }
        }
      }
      pvVar16 = *(void **)(param_1 + 0x70);
      *(void **)(param_1 + 0x80) = pvVar6;
      *(ulong *)(param_1 + 0x90) = uVar13;
      *(void **)(param_1 + 0x70) = pvVar6;
      *(void **)(param_1 + 0x78) = pvVar6;
      if (pvVar16 != (void *)0x0) {
        operator_delete__(pvVar16);
        pvVar6 = *(void **)(param_1 + 0x78);
        uVar8 = *(ulong *)(param_1 + 0x88);
      }
      uVar13 = uVar8 + 1;
    }
    else {
      pvVar6 = *(void **)(param_1 + 0x78);
    }
    cVar4 = *(char *)(param_1 + 0x98);
    *(int *)((long)pvVar6 + uVar8 * 4) = (int)uVar3;
    *(ulong *)(param_1 + 0x88) = uVar13;
    if (cVar4 != '\0') goto LAB_00126f34;
    if (*(ulong *)(param_1 + 0x90) != uVar13) {
      pvVar6 = operator_new__(uVar13 * 4,(nothrow_t *)PTR_nothrow_00132fb8);
      uVar20 = *(ulong *)(param_1 + 0x88);
      if (uVar20 != 0) {
        lVar12 = *(long *)(param_1 + 0x78);
        if (((ulong)((long)pvVar6 - (lVar12 + 4)) < 9) || (uVar20 - 1 < 3)) {
          uVar8 = 0;
          do {
            *(undefined4 *)((long)pvVar6 + uVar8 * 4) = *(undefined4 *)(lVar12 + uVar8 * 4);
            uVar8 = uVar8 + 1;
          } while (uVar20 != uVar8);
        }
        else {
          lVar7 = 0;
          do {
            uVar3 = ((undefined8 *)(lVar12 + lVar7))[1];
            *(undefined8 *)((long)pvVar6 + lVar7) = *(undefined8 *)(lVar12 + lVar7);
            ((undefined8 *)((long)pvVar6 + lVar7))[1] = uVar3;
            lVar7 = lVar7 + 0x10;
          } while (lVar7 != (uVar20 >> 2) * 0x10);
          uVar8 = uVar20 & 0xfffffffffffffffc;
          if ((uVar20 & 3) != 0) {
            lVar7 = uVar8 * 4;
            *(undefined4 *)((long)pvVar6 + uVar8 * 4) = *(undefined4 *)(lVar12 + uVar8 * 4);
            if ((uVar8 + 1 < uVar20) &&
               (*(undefined4 *)((long)pvVar6 + lVar7 + 4) = *(undefined4 *)(lVar12 + 4 + lVar7),
               uVar8 + 2 < uVar20)) {
              *(undefined4 *)((long)pvVar6 + lVar7 + 8) = *(undefined4 *)(lVar12 + 8 + lVar7);
            }
          }
        }
      }
      pvVar16 = *(void **)(param_1 + 0x70);
      *(void **)(param_1 + 0x80) = pvVar6;
      *(ulong *)(param_1 + 0x90) = uVar13;
      *(void **)(param_1 + 0x70) = pvVar6;
      *(void **)(param_1 + 0x78) = pvVar6;
      if (pvVar16 != (void *)0x0) {
        operator_delete__(pvVar16);
      }
    }
  }
  if (param_4 != '\0') {
    uVar8 = *(ulong *)(param_1 + 0xb8);
    uVar20 = *(ulong *)(param_1 + 0xc0);
    uVar3 = *(undefined8 *)(param_2 + 0x30);
    uVar13 = uVar8 + 1;
    if (uVar20 < uVar13) {
      if (uVar13 >> 1 < uVar20) {
        uVar8 = 0xfffffffffffffffc;
        uVar13 = 0x3fffffffffffffff;
        if (uVar20 >> 0x3d == 0) {
          uVar13 = uVar20 * 2;
          uVar8 = uVar20 * 8;
        }
      }
      else {
        uVar8 = uVar13 * 4;
      }
      pvVar6 = operator_new__(uVar8,(nothrow_t *)PTR_nothrow_00132fb8);
      uVar8 = *(ulong *)(param_1 + 0xb8);
      if (uVar8 != 0) {
        lVar12 = *(long *)(param_1 + 0xa8);
        if (((ulong)((long)pvVar6 - (lVar12 + 4)) < 9) || (uVar8 - 1 < 3)) {
          uVar20 = 0;
          do {
            *(undefined4 *)((long)pvVar6 + uVar20 * 4) = *(undefined4 *)(lVar12 + uVar20 * 4);
            uVar20 = uVar20 + 1;
          } while (uVar8 != uVar20);
        }
        else {
          lVar7 = 0;
          do {
            uVar5 = ((undefined8 *)(lVar12 + lVar7))[1];
            *(undefined8 *)((long)pvVar6 + lVar7) = *(undefined8 *)(lVar12 + lVar7);
            ((undefined8 *)((long)pvVar6 + lVar7))[1] = uVar5;
            lVar7 = lVar7 + 0x10;
          } while ((uVar8 >> 2) * 0x10 != lVar7);
          uVar20 = uVar8 & 0xfffffffffffffffc;
          if ((uVar8 & 3) != 0) {
            lVar7 = uVar20 * 4;
            *(undefined4 *)((long)pvVar6 + uVar20 * 4) = *(undefined4 *)(lVar12 + uVar20 * 4);
            if ((uVar20 + 1 < uVar8) &&
               (*(undefined4 *)((long)pvVar6 + lVar7 + 4) = *(undefined4 *)(lVar12 + 4 + lVar7),
               uVar20 + 2 < uVar8)) {
              *(undefined4 *)((long)pvVar6 + lVar7 + 8) = *(undefined4 *)(lVar12 + 8 + lVar7);
            }
          }
        }
      }
      pvVar16 = *(void **)(param_1 + 0xa0);
      *(void **)(param_1 + 0xb0) = pvVar6;
      *(ulong *)(param_1 + 0xc0) = uVar13;
      *(void **)(param_1 + 0xa0) = pvVar6;
      *(void **)(param_1 + 0xa8) = pvVar6;
      if (pvVar16 != (void *)0x0) {
        operator_delete__(pvVar16);
        pvVar6 = *(void **)(param_1 + 0xa8);
        uVar8 = *(ulong *)(param_1 + 0xb8);
      }
      uVar13 = uVar8 + 1;
    }
    else {
      pvVar6 = *(void **)(param_1 + 0xa8);
    }
    cVar4 = *(char *)(param_1 + 200);
    *(int *)((long)pvVar6 + uVar8 * 4) = (int)uVar3;
    *(ulong *)(param_1 + 0xb8) = uVar13;
    if (cVar4 != '\0') {
LAB_00126f34:
                    /* WARNING: Subroutine does not return */
      FUN_00107cc0();
    }
    if (*(ulong *)(param_1 + 0xc0) != uVar13) {
      pvVar6 = operator_new__(uVar13 * 4,(nothrow_t *)PTR_nothrow_00132fb8);
      uVar20 = *(ulong *)(param_1 + 0xb8);
      if (uVar20 != 0) {
        lVar12 = *(long *)(param_1 + 0xa8);
        if (((ulong)((long)pvVar6 - (lVar12 + 4)) < 9) || (uVar20 - 1 < 3)) {
          uVar8 = 0;
          do {
            *(undefined4 *)((long)pvVar6 + uVar8 * 4) = *(undefined4 *)(lVar12 + uVar8 * 4);
            uVar8 = uVar8 + 1;
          } while (uVar20 != uVar8);
        }
        else {
          lVar7 = 0;
          do {
            uVar3 = ((undefined8 *)(lVar12 + lVar7))[1];
            *(undefined8 *)((long)pvVar6 + lVar7) = *(undefined8 *)(lVar12 + lVar7);
            ((undefined8 *)((long)pvVar6 + lVar7))[1] = uVar3;
            lVar7 = lVar7 + 0x10;
          } while ((uVar20 >> 2) * 0x10 != lVar7);
          uVar8 = uVar20 & 0xfffffffffffffffc;
          if ((uVar20 & 3) != 0) {
            lVar7 = uVar8 * 4;
            *(undefined4 *)((long)pvVar6 + uVar8 * 4) = *(undefined4 *)(lVar12 + uVar8 * 4);
            if ((uVar8 + 1 < uVar20) &&
               (*(undefined4 *)((long)pvVar6 + lVar7 + 4) = *(undefined4 *)(lVar12 + 4 + lVar7),
               uVar8 + 2 < uVar20)) {
              *(undefined4 *)((long)pvVar6 + lVar7 + 8) = *(undefined4 *)(lVar12 + 8 + lVar7);
            }
          }
        }
      }
      pvVar16 = *(void **)(param_1 + 0xa0);
      *(void **)(param_1 + 0xb0) = pvVar6;
      *(ulong *)(param_1 + 0xc0) = uVar13;
      *(void **)(param_1 + 0xa0) = pvVar6;
      *(void **)(param_1 + 0xa8) = pvVar6;
      if (pvVar16 != (void *)0x0) {
        operator_delete__(pvVar16);
        return;
      }
    }
  }
  return;
}


//===== _DT_FINI @ 00126f3c size=13 =====

void _DT_FINI(void)

{
  return;
}


//===== operator.new[] @ 00134000 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * operator_new__(ulong param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== _M_append @ 00134018 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__cxx11::string::_M_append(char *param_1,ulong param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== write @ 00134020 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t write(int __fd,void *__buf,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== __throw_bad_alloc @ 00134028 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__throw_bad_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== strchr @ 00134030 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strchr(char *__s,int __c)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== __cxa_begin_catch @ 00134038 size=1 =====

/* WARNING: Control flow encountered bad instruction data */

void __cxa_begin_catch(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== __cxa_finalize @ 00134040 size=1 =====

/* WARNING: Control flow encountered bad instruction data */

void __cxa_finalize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== strlen @ 00134048 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== strncmp @ 00134050 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== __cxa_allocate_exception @ 00134058 size=1 =====

/* WARNING: Control flow encountered bad instruction data */

void __cxa_allocate_exception(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== __throw_length_error @ 00134060 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__throw_length_error(char *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== memset @ 00134068 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== munmap @ 00134070 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int munmap(void *__addr,size_t __len)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== operator.delete @ 00134078 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void operator_delete(void *param_1,nothrow_t *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== ~string @ 00134080 size=1 =====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall std::__cxx11::string::~string(string *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== __throw_logic_error @ 00134088 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__throw_logic_error(char *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== __throw_bad_array_new_length @ 00134090 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__throw_bad_array_new_length(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== memcpy @ 00134098 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== perror @ 001340a0 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void perror(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== __cxa_atexit @ 001340a8 size=1 =====

/* WARNING: Control flow encountered bad instruction data */

void __cxa_atexit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== operator.delete @ 001340b0 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void operator_delete(void *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== mmap64 @ 001340b8 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * mmap64(void *__addr,size_t __len,int __prot,int __flags,int __fd,__off64_t __offset)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== fclose @ 001340c0 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fclose(FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== operator.new @ 001340c8 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * operator_new(ulong param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== fseek @ 001340d0 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fseek(FILE *__stream,long __off,int __whence)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== __stack_chk_fail @ 001340d8 size=1 =====

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== fopen64 @ 001340e0 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * fopen64(char *__filename,char *__modes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== _M_construct @ 001340e8 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__cxx11::string::_M_construct(ulong param_1,char param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== fflush @ 001340f0 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fflush(FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== free @ 001340f8 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== read @ 00134100 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::istream::read(char *param_1,long param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== operator.delete[] @ 00134110 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void operator_delete__(void *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== write @ 00134120 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::ostream::write(char *param_1,long param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== malloc @ 00134128 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== strcmp @ 00134130 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== strtol @ 00134138 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long strtol(char *__nptr,char **__endptr,int __base)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== read @ 00134140 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== __cxa_rethrow @ 00134148 size=1 =====

/* WARNING: Control flow encountered bad instruction data */

void __cxa_rethrow(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== fread @ 00134150 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t fread(void *__ptr,size_t __size,size_t __n,FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== __throw_out_of_range_fmt @ 00134158 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__throw_out_of_range_fmt(char *param_1,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== Init @ 00134160 size=1 =====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall std::ios_base::Init::Init(Init *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== _M_replace @ 00134168 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__cxx11::string::_M_replace(ulong param_1,ulong param_2,char *param_3,ulong param_4)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== fgets @ 00134170 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * fgets(char *__s,int __n,FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== memmove @ 00134178 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memmove(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== __cxa_end_catch @ 00134180 size=1 =====

/* WARNING: Control flow encountered bad instruction data */

void __cxa_end_catch(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== operator.new[] @ 00134188 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * operator_new__(ulong param_1,nothrow_t *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== __fprintf_chk @ 00134190 size=1 =====

/* WARNING: Control flow encountered bad instruction data */

void __fprintf_chk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== __gxx_personality_v0 @ 00134198 size=1 =====

/* WARNING: Control flow encountered bad instruction data */

void __gxx_personality_v0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== __cxa_throw @ 001341a0 size=1 =====

/* WARNING: Control flow encountered bad instruction data */

void __cxa_throw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== stat64 @ 001341a8 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int stat64(char *__file,stat64 *__buf)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== open64 @ 001341b0 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int open64(char *__file,int __oflag,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== _ITM_deregisterTMCloneTable @ 001341b8 size=1 =====

/* WARNING: Control flow encountered bad instruction data */

void _ITM_deregisterTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== _Unwind_Resume @ 001341c0 size=1 =====

/* WARNING: Control flow encountered bad instruction data */

void _Unwind_Resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== _M_create @ 001341c8 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__cxx11::string::_M_create(ulong *param_1,ulong param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== ~exception @ 001341d0 size=1 =====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall std::exception::~exception(exception *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== _M_replace_aux @ 001341d8 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__cxx11::string::_M_replace_aux(ulong param_1,ulong param_2,ulong param_3,char param_4)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== __gmon_start__ @ 001341e8 size=1 =====

/* WARNING: Control flow encountered bad instruction data */

void __gmon_start__(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== _ITM_registerTMCloneTable @ 001341f0 size=1 =====

/* WARNING: Control flow encountered bad instruction data */

void _ITM_registerTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== fwrite @ 001341f8 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t fwrite(void *__ptr,size_t __size,size_t __n,FILE *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== close @ 00134200 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== operator.new @ 00134208 size=1 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * operator_new(ulong param_1,nothrow_t *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//===== ~Init @ 00134210 size=1 =====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall std::ios_base::Init::~Init(Init *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


