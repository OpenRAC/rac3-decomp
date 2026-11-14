#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef struct { u8 p0[0x44]; s16 n; u8 p1[0x15A]; void *slot[1]; } S_B7288;
extern S_B7288 D_00225700;


/* localdecomp:start func_003BDA58 */
/* PROVISIONAL, VU0 j-constraint form. */
typedef int Q_3B8560 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B8560;
typedef struct { u8 p0[0xC]; u8 c; } I_3B8560;
typedef struct {
    u8 p0[0x10];
    V4_3B8560 v10;
    u8 p20[0x4];
    I_3B8560 *f24;
    u8 p28[0xA];
    s16 f32;
    u8 p34[0xC];
    u8 f40, f41, f42, f43;
    f32 f44;
    u8 p48[0x19];
    u8 f61, f62;
    u8 p63[0x5];
    u8 *f68;
    u8 p6C[0x3E];
    s16 fAA;
} O_3B8560;
typedef struct { u8 p0[0x38]; s32 f38; u8 p3C[0x8]; s16 n; u8 p46[0x15A]; O_3B8560 *slot[1]; } S_3B8560;
extern S_3B8560 D_00225700_003BDA58;
extern void func_0038CE20(f32 *, void *, f32);
extern void func_003C29B0();
extern void func_003C7C38();
extern void func_003BD938(u8 *);
void func_003BDA58(void) {
    s32 i;
    for (i = 0; i < D_00225700_003BDA58.n; i++) {
        V4_3B8560 a, b;
        Q_3B8560 x, y, r;
        O_3B8560 *o = D_00225700_003BDA58.slot[i];
        s32 bits = D_00225700_003BDA58.f38;
        s32 hi = bits >> 1;
        u8 *t = o->f68;
        s32 k;
        o->f44 = (f32)(bits & 1) * 0.5f;
        func_0038CE20(&a.x, t + hi * 16, 1.0f - o->f44);
        func_0038CE20(&b.x, t + (hi + 1) * 16, o->f44);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(Q_3B8560 *)&a));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(Q_3B8560 *)&b));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(o->v10) : "j"(r));
        o->f42 = o->f24->c - 1;
        o->f43 = o->f24->c - 1;
        o->f40 = hi;
        o->f41 = hi + 1;
        func_003C29B0(o);
        o->f62 = 0xFF;
        o->f61 = 0xFF;
        o->f32 = 0x1FF;
        func_003C7C38(o);
        o->f42 = o->f24->c - 1;
        o->f43 = o->f24->c - 1;
        k = o->fAA;
        if (k == 10 || k == 0x19C9 || k == 0x1159 || k == 0x57 || k == 0x259 || k == 0x1F6B) {
            func_003BD938((u8 *)o);
        }
    }
}
/* localdecomp:end func_003BDA58 */

/* US draft of func_003BDBF8 (rac3-uya-decomp func_003B8700, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003BDBF8 */
extern void func_0039A690(s32);
extern void func_003BB848(s32);
extern s32 func_003BD648(void);
extern void func_003BDA58(void);
extern s32 D_001D8CDC;
extern s32 D_0016C5E4[];
typedef struct { u8 pad0[0x34]; s32 f34; s32 f38; s32 f3C; s16 f40; } S_003B8700;
extern S_003B8700 D_00225700_003BDBF8[];
s32 func_003BDBF8(void) {
    S_003B8700 *p = D_00225700_003BDBF8;
    s32 temp_3;
    s32 temp_4;
    s32 var_17;

    var_17 = 0;
        p->f38 = p->f38 + 1;
        temp_3 = p->f34 + 1;
        p->f34 = temp_3;
    if (temp_3 == 1) {
        func_003BB848(D_0016C5E4[0]);
    }
    if (p->f40 >= p->f34) {
        if (p->f38 >= 0x50) {
            temp_4 = p->f3C + 1;
            p->f3C = temp_4;
            func_0039A690(temp_4);
        }
        func_003BD648();
        func_003BDA58();
    } else {
        var_17 = 1;
        D_001D8CDC = D_001D8CDC + 1;
    }
    return var_17;
}
/* localdecomp:end func_003BDBF8 */

extern s32 D_001D8CFC;
extern s32 D_001D8CF8;
extern s32 D_001DA268[];
extern s8 D_001DA290[];
INCLUDE_ASM("asm/nonmatchings/text", func_003BDCB0);

extern s8 D_001DA299[];
/* localdecomp:start func_003BDD08 */
void func_003BDD08(void) {
    s32 var_v1;
    s8 *var_v0;

    var_v1 = 9;
    do { var_v0 = D_001DA299; } while (0);
    do {
        *var_v0 = 0;
        var_v1 -= 1;
        var_v0 -= 1;
    } while (var_v1 >= 0);
}
/* localdecomp:end func_003BDD08 */

typedef struct { u8 pad[0x64]; s32 f64; } S_16C580_3B8840;
extern S_16C580_3B8840 D_16C580_003BDD38;
extern u8 D_001DA290_003BDD38[1];
extern s32 D_001DA268_003BDD38[2];
extern s32 func_00382468(s32);
extern void func_003BDD08(void);
INCLUDE_ASM("asm/nonmatchings/text", func_003BDD38);

/* localdecomp:start func_003BDE20 */
typedef struct { u8 pad[0x64]; s32 f64; s32 f68; } S_16C580b;
extern S_16C580b D_16C580;
extern void func_003BC698_003BDE20(s32);
extern void func_0039A690(s32);
void func_003BDE20(s32 a) {
    func_003BC698_003BDE20(a);
    D_16C580.f64 = a;
    D_16C580.f68 = 0;
    func_0039A690(0);
}
/* localdecomp:end func_003BDE20 */

/* localdecomp:start func_003BDE60 */
extern void func_003BC698_003BDE60(s32);
extern void func_0039A690(s32);
extern void func_003BDA58(void);
extern void func_003C29B0();
void func_003BDE60(s32 a) {
    s32 i;
    func_003BC698_003BDE60(a);
    D_16C580.f64 = a;
    func_0039A690(0);
    func_003BDA58();
    for (i = 0; i < D_00225700.n; i++) {
        if (D_00225700.slot[i] != 0) {
            func_003C29B0(D_00225700.slot[i]);
        }
    }
}
/* localdecomp:end func_003BDE60 */

/* localdecomp:start func_003BDEF0 */
extern s32 D_0016C5E4[];
 
s32 func_003BDEF0(void) {
    return D_0016C5E4[0];
}
/* localdecomp:end func_003BDEF0 */

/* localdecomp:start func_003BDF00 */
extern s32 D_00225734[];
s32 func_003BDF00(void) {
    return D_00225734[0];
}
/* localdecomp:end func_003BDF00 */

/* localdecomp:start func_003BDF10 */
extern s32 D_001D8CDC;
s32 func_003BDF10(void) { return D_001D8CDC; }
/* localdecomp:end func_003BDF10 */

/* func_003BDF18: from the US C of func_003B8A20 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags. */


/* localdecomp:start func_003BDF18 */
extern s32 D_001D4B4C[];
extern s32 D_001D4B48;
s32 func_003BDF18(void)
{
  s32 new_var;
  if (new_var)
  {
    new_var = D_001D4B4C[0];
  }
  else
  {
    new_var = D_001D4B4C[0];
  }
  if ((new_var != 0) && (D_001D4B48 >= 2))
  {
    return 1;
  }
  return 0;
}
/* localdecomp:end func_003BDF18 */

/* localdecomp:start func_003BDF40 */
/* func_003BDF40: init the three globals of the "frontbin" state.
 *
 * The retail code addresses the first two through a lui/lo pair that the
 * assembler built from a plain symbol reference (`lui $at` +
 * `sw ..., %lo(sym)($at)`).  An unsized array would make gcc split the
 * address itself into a register it allocates ($v0/$a0).  So the two are
 * declared sized (gcc leaves the store to the assembler as one macro), with an
 * `.extern X, 16` hint before their first use, so the assembler expands the
 * macro with `lui $at`
 * (as SN's single-pass Ps2EeAs did for a global whose size it had not seen
 * yet).  D_001DA5CC is small data and is reached through $gp, as in retail. */

extern s32 D_001DA5C4;
extern s32 D_001DA5C8;
__asm__(".extern D_001DA5C4, 16");
__asm__(".extern D_001DA5C8, 16");
extern s32 D_001DA5CC;

void func_003BDF40(void) {
    s32 v = -1;
    D_001DA5C4 = 0;
    D_001DA5C8 = v;
    D_001DA5CC = 0;
}
/* localdecomp:end func_003BDF40 */

/* localdecomp:start func_003BDF60 */
extern f32 D_001D8CF0;
void func_003BDF60(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
  arg1 = arg1 - 1;
  if (arg0 <= 0 || arg0 >= arg1) {
    D_001D8CF0 = 0.0f;
  } else if (arg2 >= arg0) {
    D_001D8CF0 = (f32)arg0 / (f32)arg2;
  } else if (arg1 - arg3 < arg0) {
    D_001D8CF0 = (f32)(arg1 - arg0) / (f32)arg3;
  } else {
    D_001D8CF0 = 1.0f;
  }
  D_001D8CF0 = 1.0f - D_001D8CF0;
}
/* localdecomp:end func_003BDF60 */

/* localdecomp:start func_003BE008 */
extern f32 D_001D8CF0;
void func_003BE008(f32 a) {
    D_001D8CF0 = a;
}
/* localdecomp:end func_003BE008 */
