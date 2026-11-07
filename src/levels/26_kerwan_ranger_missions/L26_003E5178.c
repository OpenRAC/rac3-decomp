#include "common.h"

typedef struct {
    void (*f0)(u8 *);
    void (*f4)(u8 *);
} Vt_003E54F8;

/* localdecomp:start func_L26_003E5178 */
s32 func_L26_003E5218(s32, s32);
f32 func_L01_0040E548(void *, void *);
void func_L01_004472C0(void *);
s32 func_L26_003E5330(void *, s32);
extern u8 D_L26_001E2840[];

void func_L26_003E5178(void *arg0) {
    s32 temp_s1;

    temp_s1 = *(s32 *)((u8 *)arg0 + 0x68);
    if ((((*(u8 *)((u8 *)arg0 + 0x20)) != 0) || (func_L26_003E5218((s32) arg0, temp_s1) != 0)) && (func_L26_003E5330(arg0, temp_s1) != 0) && ((*(u8 *)((u8 *)arg0 + 0x31)) != 0) && (func_L01_0040E548(D_L26_001E2840, arg0 + 0x10) < 1024.0f)) {
        func_L01_004472C0(arg0);
        *(s8 *)((u8 *)arg0 + 0x6F) = 0x1E;
    }
}
/* localdecomp:end func_L26_003E5178 */

/* localdecomp:start func_L26_003E5218 */
typedef struct { u8 p0[0x30]; f32 f30; s16 h34; u8 p36[2]; u8 b38; u8 b39; u8 p3A[4]; u8 b3E; u8 b3F; u8 p40[4]; u8 b44; u8 p45[0x3C]; u8 b81; u8 p82[0x36]; u8 bB8; u8 pB9[0xF]; f32 fC8; f32 fCC; u8 pD0[0x17]; u8 bE7; u8 pE8[0x48]; s32 f130; u8 p134[0xA]; u8 b13E; } S_5218_O;
extern Vt_003E54F8 *func_L01_0043B548(s32 a0, s32 a1);
extern s32 func_00382498(s32, s32);
extern void func_003C3A10(s32, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
s32 func_L26_003E5218(s32 a0_, s32 a1_) {
    u8 *a0 = (u8 *)a0_;
    S_5218_O *a1 = (S_5218_O *)a1_;
    Vt_003E54F8 *v;
    s32 r;
    a1->bB8 = 0xFF;
    a1->b81 = 0xFF;
    a1->bE7 = 1;
    a1->fC8 = 1.0f;
    a1->fCC = 1.0f;
    if (a1->h34 == 0) a1->h34 = 100;
    a1->f30 = (f32)a1->h34;
    a1->b3E = 1;
    a1->b3F = 0;
    a1->b39 = 0;
    a1->b38 = 2;
    if (a1->b44 == 0) a1->b44 = 10;
    if (a1->f130 > 0) {
        v = func_L01_0043B548(0x19E1, 0x6C);
        a1->f130 = -1;
        r = func_00382498(0, 6);
        func_003C3A10(a0_, 0, r, 0);
        a1->b13E = 2;
        v->f0(a0);
        return 0;
    }
    func_L01_004450F0(a0, 1, -1);
    return 1;
}
/* localdecomp:end func_L26_003E5218 */

INCLUDE_ASM("asm/levels", func_L26_003E5330);

/* localdecomp:start func_L26_003E54F8 */
extern Vt_003E54F8 *func_L01_0043B548(s32 a0, s32 a1);
extern void func_003C2880(u8 *a0);

void func_L26_003E54F8(u8 *arg0, s32 arg1) {
    Vt_003E54F8 *vt;
    if (*(s32 *)(*(u8 **)(arg0 + 104) + 304) != 0) {
        vt = func_L01_0043B548(6625, 108);
        vt->f0(arg0);
        if (arg1 != 0) {
            vt->f4(arg0);
        }
    } else {
        func_003C2880(arg0);
    }
}
/* localdecomp:end func_L26_003E54F8 */

/* localdecomp:start func_L26_003E5578 */
s32 func_00382498(s32, s32);
void func_003C3A10(s32, s32, s32, s32);

void func_L26_003E5578(s32 arg0) {
    func_003C3A10(arg0, 0, func_00382498(0, 6), 0);
}
/* localdecomp:end func_L26_003E5578 */
