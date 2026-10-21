#include "common.h"

typedef struct {
    s32 v[3];
} Ids3;
typedef struct { u8 b[16]; } V16_3DF9E0;

/* localdecomp:start func_L01_0047B798 */
extern Ids3 D_L01_001D80D8;
extern void func_L01_00517190(s32 a0, s32 a1);
extern void func_L01_00516AA0(s32 a0, s32 a1, s32 a2);
void func_L01_0047B798(s32 a0, s32 a1) {
    Ids3 t;
    t = D_L01_001D80D8;
    func_L01_00517190(t.v[a1], a0);
    if (a0 == 0) {
        func_L01_00516AA0(t.v[a1], 1, 0);
    } else {
        func_L01_00516AA0(t.v[a1], 1, 1);
    }
}
/* localdecomp:end func_L01_0047B798 */

INCLUDE_ASM("asm/levels", func_L01_0047B820);

/* localdecomp:start func_L01_0047B948 */
extern u8 D_L01_001D80CD;
extern void func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_0047C368(s32);
extern s32 func_L01_00516010(s32);
s32 func_L01_0047B948(void) {
    if (D_L01_001D80CD != 0) {
        func_L01_00516AA0(0x20000, 1, 0);
        return func_L01_00516010(func_L01_0047C368(0));
    }
    return 0;
}
/* localdecomp:end func_L01_0047B948 */

INCLUDE_ASM("asm/levels", func_L01_0047B990);

INCLUDE_ASM("asm/levels", func_L01_0047B9B8);

INCLUDE_ASM("asm/levels", func_L01_0047BB98);

INCLUDE_ASM("asm/levels", func_L01_0047BBE0);

/* localdecomp:start func_L01_0047C220 */
extern s32 func_L01_0047C368(s32);
extern s32 func_L01_00516000(s32);
extern void func_L01_00516AA0(s32, s32, s32);
extern s32 D_L01_001D80C8;
extern u8 D_L01_001D80CC;

void func_L01_0047C220(s32 a) {
    if (func_L01_00516000(func_L01_0047C368(0)) == 1) {
        D_L01_001D80C8 = a;
        D_L01_001D80CC = 0;
        func_L01_00516AA0(0x20000, 1, a != 0);
    }
}
/* localdecomp:end func_L01_0047C220 */

INCLUDE_ASM("asm/levels", func_L01_0047C278);

/* localdecomp:start func_L01_0047C348 */
extern u8 D_L01_001D80CD;
extern s32 func_L01_00517918();

void func_L01_0047C348(void) {
    D_L01_001D80CD = 0;
    func_L01_00517918(6);
}
/* localdecomp:end func_L01_0047C348 */

/* localdecomp:start func_L01_0047C368 */
extern s32 func_L01_0047C368(s32);
extern void func_L01_0047C278();

extern void func_L01_0047BBE0(s32);
extern void func_L01_0047C348(void);
extern void func_L01_0047C278(void);
extern s32 func_003E6FA0(s32 *, s32, s32, s32, s32, s32);
extern s32 D_L01_001E0498;
extern s32 D_L01_001E04B8;
extern s32 D_L01_001E04D8;
extern s32 D_L01_001E04F8;
extern s32 D_L01_001E0480[2];
extern s32 D_L01_001E04A0[2];
extern s32 D_L01_001E04C0[2];
extern s32 D_L01_001E04E0[2];
extern V16_3DF9E0 D_L01_001D8178[];
s32 func_L01_0047C368(s32 idx) {
    V16_3DF9E0 v;
    if (D_L01_001E0498 == 0) {
        func_003E6FA0(D_L01_001E0480, (s32)func_L01_0047BBE0, (s32)func_L01_0047C348, (s32)func_L01_0047C278, 0, 0);
        D_L01_001E0498 = 1;
    }
    if (D_L01_001E04B8 == 0) {
        func_003E6FA0(D_L01_001E04A0, (s32)func_L01_0047BBE0, (s32)func_L01_0047C348, (s32)func_L01_0047C278, 0, 0);
        D_L01_001E04B8 = 1;
    }
    if (D_L01_001E04D8 == 0) {
        func_003E6FA0(D_L01_001E04C0, (s32)func_L01_0047BBE0, (s32)func_L01_0047C348, (s32)func_L01_0047C278, 0, 0);
        D_L01_001E04D8 = 1;
    }
    if (D_L01_001E04F8 == 0) {
        func_003E6FA0(D_L01_001E04E0, (s32)func_L01_0047BBE0, (s32)func_L01_0047C348, (s32)func_L01_0047C278, 0, 0);
        D_L01_001E04F8 = 1;
    }
    v = D_L01_001D8178[0];
    return *(s32 *)(v.b + (idx << 2));
}
/* localdecomp:end func_L01_0047C368 */

INCLUDE_ASM("asm/levels", func_L01_0047C4A8);

/* localdecomp:start func_L01_0047C4F8 */
extern void func_L01_0047C728_0047C4F8();
 
void func_L01_0047C4F8(void) {
    func_L01_0047C728_0047C4F8();
}
/* localdecomp:end func_L01_0047C4F8 */

/* localdecomp:start func_L01_0047C518 */
extern void func_L01_0047C970_0047C518();
 
void func_L01_0047C518(void) {
    func_L01_0047C970_0047C518();
}
/* localdecomp:end func_L01_0047C518 */

INCLUDE_ASM("asm/levels", func_L01_0047C538);

INCLUDE_ASM("asm/levels", func_L01_0047C728);

INCLUDE_ASM("asm/levels", func_L01_0047C800);

/* localdecomp:start func_L01_0047C970 */
extern s32 func_L01_00517918();
void func_L01_0047C970(void) {
    ((void (*)(s32))func_L01_00517918)(12);
}
/* localdecomp:end func_L01_0047C970 */

/* localdecomp:start func_L01_0047C990 */
extern s32 D_L01_001D8188[2];
extern s32 D_L01_001D8198[2];
extern f32 D_L01_001D81A8[2];
extern s32 D_L01_001D81B8;

void func_L01_0047C990(s32 a0, s32 idx, u8 flag, f32 f) {
    if (f > 1.0f) {
        f = 1.0f;
    }
    if (f < 0.0f) {
        f = 0.0f;
    }
    D_L01_001D8188[idx] += 2;
    D_L01_001D81A8[idx] = f;
    if (flag) {
        if (D_L01_001D81B8 >> 1 < D_L01_001D8188[idx]) {
            D_L01_001D8188[idx] = D_L01_001D81B8 >> 1;
        }
    } else {
        if (D_L01_001D81B8 < D_L01_001D8188[idx]) {
            D_L01_001D8188[idx] = D_L01_001D81B8;
        }
    }
    D_L01_001D8198[idx] = a0;
}
/* localdecomp:end func_L01_0047C990 */

LINKER_REMNANT("asm/levels", func_L01_0047CA30);
