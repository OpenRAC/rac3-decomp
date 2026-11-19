#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 *func_003E5CD0(s32 *);
extern s32 func_003E5CB0();
/* --- end of declarations from other files --- */

typedef int u128_3E0190 __attribute__((mode(TI)));
typedef struct { u128_3E0190 q0; f32 f10; f32 f14; f32 f18; f32 f1C; } P_3E0190;
typedef struct { u8 pad[0x38]; s32 f38; u8 pad2[0x28]; u8 *f64; } G_3E0190;
typedef struct { u8 pad[0xB0]; f32 fB0; } H_3E0190;
typedef struct { f32 v[4]; } V4_3E0190;
typedef struct { V4_3E0190 v0; u8 pad[0x370]; f32 f380[4]; f32 f390[4]; f32 f3A0[4]; } M_3E0190;
extern G_3E0190 D_00225700;
extern H_3E0190 D_00225900;
extern M_3E0190 D_00222480;
extern u8 D_002224A0[];
extern f32 D_001D5BC8;
extern f32 D_001D5BCC;
extern void func_003877A0();
extern void func_12FF40(f32 *);
extern void func_130088(f32 *, f32 *, f32);
extern void func_130130(f32 *, f32 *, f32);
extern void func_12FFE0(f32 *, f32 *, f32);
extern void func_0038D348(void *, void *, f32);
extern void func_003850A8(s32);

LINKER_REMNANT("asm/boot_elf/remnants", func_003E5C60);

/* localdecomp:start func_003E5C78 */
void func_003E5C78(f32 *p, f32 lo, f32 hi) {
    *p = (*p < lo) ? lo : *p;
    *p = (hi < *p) ? hi : *p;
}
/* localdecomp:end func_003E5C78 */

/* localdecomp:start func_003E5CB0 */
extern s32 func_003E6730();
 
s32 func_003E5CB0(void **p) {
    return func_003E6730(p) != 0;
}
/* localdecomp:end func_003E5CB0 */

/* localdecomp:start func_003E5CD0 */
s32 *func_003E5CD0(s32 *p) {
    *p = 0;
    return p;
}
/* localdecomp:end func_003E5CD0 */

/* localdecomp:start func_003E5CE0 */
typedef struct { u8 p0[0x50]; s32 *arr[35]; u8 pad[0x41DC - 0xDC]; } O_3E03D8;
extern O_3E03D8 D_00306E00_003E5CE0[];
extern O_3E03D8 D_0031B74C[];
extern s32 func_003E74D0();
void func_003E5CE0(void) {
    O_3E03D8 *s = D_00306E00_003E5CE0;
    O_3E03D8 *p;
    s32 **q;
    if (s != 0) {
        p = D_0031B74C;
        if (p != s) {
            do {
                p--;
                if (p->arr != 0) {
                    q = p->arr + 35;
                    if (p->arr != q) {
                        do {
                            q--;
                            if (*q) func_003E74D0(*q);
                            *q = 0;
                        } while (p->arr != q);
                    }
                }
            } while (p != D_00306E00_003E5CE0);
        }
    }
}
/* localdecomp:end func_003E5CE0 */

/* localdecomp:start func_003E5D80 */
extern u8 D_00306E00[];
extern s32 D_001DA878;
extern void *func_003E6A28();
extern void func_116FD0();
extern void func_003E5CE0();
void *func_003E5D80(s32 idx) {
    u8 *q;
    s32 *w;
    s32 n, j;
    if (D_001DA878 == 0) {
        q = D_00306E00;
        n = 4;
        do {
            w = (s32 *)(q + 0x50);
            for (j = 0x22; j != -1; j--) *w++ = 0;
            func_003E6A28(q + 0x1C4);
            func_003E6A28(q + 0x21CC);
            q += 0x41DC;
            n--;
        } while (n != -1);
        D_001DA878 = 1;
        func_116FD0(func_003E5CE0);
    }
    return D_00306E00 + idx * 0x41DC;
}
/* localdecomp:end func_003E5D80 */

/* localdecomp:start func_003E5E58 */
typedef struct { u8 b[16]; } B16_003E0550;
typedef struct { B16_003E0550 hdr; s32 a[16]; s32 b[16]; u8 p90[0x4C]; s32 c[16]; s32 d[16]; s32 e[16]; u8 f[16]; u8 g[16]; s32 f1BC; u32 f1C0; u8 p1C4[0x41D4 - 0x1C4]; s32 f41D4; s32 f41D8; } O_003E0550;
extern void func_003E6238();
s32 func_003E5E58(O_003E0550 **o, u32 mode) {
    B16_003E0550 tmp;
    s32 i;
    if (mode < 5) {
        *o = func_003E5D80(mode);
        (*o)->hdr = tmp;
        for (i = 0; i < 16; i++) (*o)->a[i] = 0;
        for (i = 0; i < 16; i++) *(s32 *)((u8 *)(*o) + i * 4 + 0x50) = 0;
        for (i = 0; i < 16; i++) {
            (*o)->c[i] = 0;
            (*o)->d[i] = 0;
            (*o)->e[i] = 0;
            (*o)->f[i] = 0;
            (*o)->g[i] = 0;
        }
        (*o)->f1BC = 0;
        (*o)->f1C0 = 0;
        (*o)->f41D4 = 0;
        (*o)->f1C0 = mode;
        (*o)->f41D8 = 0;
        func_003E6238(o);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E5E58 */

/* localdecomp:start func_003E5F88 */
s32 func_003E5F88(void **p) {
    return *(s32 *)((u8 *)*p + 0x1C0);
}
/* localdecomp:end func_003E5F88 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E5F98);

/* localdecomp:start func_003E5FA8 */
typedef struct { u8 pad[0x10]; s32 a[16]; } S_3E06A0;
void func_003E5FA8(S_3E06A0 **p) {
    s32 i;
    for (i = 0; i < 16; i++) (*p)->a[i] = 0;
}
/* localdecomp:end func_003E5FA8 */

/* localdecomp:start func_003E5FD8 */
extern void func_003E7398(void *);

void func_003E5FD8(s32 *arg0) {
    s32 temp_s0;
    s32 temp_v1;
    s32 var_s2;
    void *temp_v0;

    var_s2 = 0;
    do {
        temp_s0 = var_s2 * 4;
        temp_v1 = (*(s32 *)((u8 *)((*arg0 + temp_s0)) + 0xDC));
        if (temp_v1 != 0) {
            func_003E7398(temp_v1);
        }
        (*(s32 *)((u8 *)((*arg0 + temp_s0)) + 0xDC)) = 0;
        (*(s32 *)((u8 *)((*arg0 + temp_s0)) + 0x11C)) = 0;
        (*(s32 *)((u8 *)((*arg0 + temp_s0)) + 0x15C)) = 0;
        (*(s8 *)((u8 *)((*arg0 + var_s2)) + 0x1AC)) = 0;
        temp_v0 = *arg0 + var_s2;
        var_s2 += 1;
        (*(s8 *)((u8 *)(temp_v0) + 0x19C)) = 0;
    } while (var_s2 < 0x10);
}
/* localdecomp:end func_003E5FD8 */

/* localdecomp:start func_003E6078 */
s32 func_003E6078(void **p) {
    return *(s32 *)((u8 *)*p + 0x1BC);
}
/* localdecomp:end func_003E6078 */

/* localdecomp:start func_003E6088 */
typedef struct { u8 pad[0xDC]; s32 arr[1]; } S_3E0780;
 
s32 func_003E6088(S_3E0780 **p, s32 i) {
    return (*p)->arr[i];
}
/* localdecomp:end func_003E6088 */
