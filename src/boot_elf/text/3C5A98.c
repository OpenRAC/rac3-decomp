#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3C4D90.c's earlier functions (tools/port_from_us.py) */
extern s32 func_003C4EF8_003C4F08(s16);
extern u32 D_001DA49C[];
extern u32 D_001DA4A4[];
extern f32 func_0038D288(s32 a);
extern void func_0038D348(s32 a, s32 b, f32 x);
extern f32 func_003828C0(f32, f32);
extern void func_0038D348(s32 a, s32 b, f32 x);
typedef int u128_3BF838 __attribute__((mode(TI)));
typedef struct { u128_3BF838 r[4]; } M_3BF838;
extern void func_0038D708();
extern void func_0038D990();
extern void func_0038DA20();
extern void func_003C4C60();
extern s32 func_0038D438(f32 *);
typedef struct { u8 pad[0x40]; } M_3BFAF8;
void func_0038D990(M_3BFAF8 *, void *);
void func_0038D3E0(void *, void *, M_3BFAF8 *);
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BFBA8;
typedef int Q_3BFBA8 __attribute__((mode(TI)));
extern f32 D_001D5C00;
extern void func_0038D200(f32 *, void *, f32);
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BFC18;
typedef int Q_3BFC18 __attribute__((mode(TI)));
extern s32 D_001D5BEC_003C5538;
extern s32 D_001D5BF0;
typedef struct { u8 p0[0xB0]; V4_3BFC18 v; } S_3BFC18;
extern S_3BFC18 D_001A4BE0;
extern void func_0038D200(f32 *, void *, f32);
extern void func_003C54C8(void *, void *, s32);
extern void func_003C5538(void *);
extern s32 D_001D5BEC[];
extern void func_003C5538_003C5630();
extern void func_0038D348(s32, s32, f32);
extern void func_003C5630_003C56B0(void *);
extern void func_0038D200(f32 *, void *, f32);
extern void func_003C5728(s32, f32 *, s32);
extern void func_0038D270(f32 *, f32 *, s32);
extern void func_0038DBF0(f32 *, f32 *);
extern void func_0038D9D0(s32, f32 *, s32);
extern void func_0038D068(s32, f32 *, s32);

typedef int Q_3BFEF0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3BFEF0;
typedef struct { f32 m[4][4]; s32 c[4]; f32 uv[8]; long gs[4]; } P_3BFEF0;
extern V_3BFEF0 D_00222400;
extern f32 D_001D9180[2];
extern void func_0038D408();
extern void func_003D3158();
typedef struct {
    u8 p0[7]; u8 f7; u8 p8[9]; u8 f11; u8 f12; u8 p13; u8 f14; u8 p15; u8 f16; u8 f17; u8 p18[4];
    f32 f1C; f32 f20; f32 f24; f32 f28; f32 f2C; f32 f30; f32 f34; u16 f38; u8 p3A[0x12];
    f32 f4C; f32 f50; f32 f54; u8 p58[8]; f32 f60; f32 f64; u8 p68[4]; s8 f6C; s8 f6D; s8 f6E; s8 f6F;
    u8 p70[2]; s8 f72; s8 f73; u8 p74[2]; u8 f76; u8 p77; u8 f78; u8 f79; u8 f7A; u8 p7B[5];
    f32 f80; f32 f84; f32 f88; u8 p8C[4]; f32 f90; f32 f94;
} E_3C0188;
typedef struct { u8 p0[0x1C]; f32 *f1C; } T_3C0188;
typedef struct {
    u8 p0[0x34]; u16 f34; u8 p36[0xE]; f32 f44; u8 p48[4]; f32 f4C; u8 p50[0x18]; T_3C0188 *f68; u8 p6C[0x2C]; s32 f98;
} O_3C0188;
extern s32 D_001D5BEC_003C5A98;
extern void func_003C5238(void *, void *);
extern f32 func_0038D248(void *, void *);
extern void func_003C6720(void *, f32 *, f32 *, f32, f32, f32);
extern f32 func_0038D2B8(f32 *);
extern f32 func_003C54A0(s32, s32, s32);
extern s32 func_003C6420();
extern void func_003C6680();
extern f32 func_0038D540(f32, f32);
extern void func_0038DE98(f32, f32);
extern void func_0038D398(void);
typedef struct { f32 x, y, z, w; } V4_3C0188;
typedef int Q_3C0188 __attribute__((mode(TI)));
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C5A98);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031CA90);

typedef struct { u8 key; u8 b1; u8 pad[2]; f32 f4, f8, fC, f10, f14, f18, f1C; } E3C;
typedef struct { u8 pad[0x14]; E3C *e; } P3C;
typedef struct { u8 pad[0xC]; u8 n; u8 pad2[0x3B]; P3C *arr[1]; } S3C;
typedef struct { u8 pad[0x24]; S3C *set; } O3C;
extern s32 func_00382848();
extern f32 func_003828C0(f32, f32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C6420);

/* US draft of func_003C6680 (rac3-uya-decomp func_003C6530, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */

/* PAL retail runs at 50 Hz, so the frame scale is 1/50 (0x3CA3D70B) and the angular
   scale is 1/50*1/50 (0x39D1B718); the US 60 Hz constants (1/60, 1/3600) are wrong here. */

/* localdecomp:start func_003C6680 */
typedef struct { u8 pad[0x48]; void *a[1]; } S_3C0D70;
void func_003C6680(void *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5, f32 *arg6, f32 *arg7, f32 *arg_sp0, u8 *arg_sp8) {
    u8 temp_3_2;
    void *temp_3;
    S_3C0D70 *s;

    s = *(S_3C0D70 **)((u8 *)arg0 + 0x24);
    temp_3 = (*(void **)((u8 *)s->a[arg1] + 0x14));
    if (temp_3 != 0) {
        *arg2 = (*(f32 *)((u8 *)temp_3 + 8)) * 0.020000001f;
        *arg3 = (*(f32 *)((u8 *)temp_3 + 0xC)) * 0.020000001f;
        *arg4 = (*(f32 *)((u8 *)temp_3 + 0x10)) * 0.00040000001f;
        *arg5 = (*(f32 *)((u8 *)temp_3 + 0x14)) * 0.00040000001f;
        *arg_sp0 = (*(f32 *)((u8 *)temp_3 + 4)) * 0.00040000001f;
        *arg6 = (*(f32 *)((u8 *)temp_3 + 0x18));
        *arg7 = (*(f32 *)((u8 *)temp_3 + 0x1C));
        temp_3_2 = (*(u8 *)((u8 *)temp_3 + 1));
        if (temp_3_2 != 0) {
            *arg_sp8 = temp_3_2;
        }
    }
}
/* localdecomp:end func_003C6680 */
