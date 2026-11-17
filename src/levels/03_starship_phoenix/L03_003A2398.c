#include "common.h"

/* declared by functions of L03_003A2328.c, which this file was cut from */
void func_L01_004450F0(s32, s32, s32);

/* localdecomp:start func_L03_003A2398 */
/* localdecomp:start func_L03_003A2398 */
typedef struct T_003A2398 {
    char pad0[0x35C];
    void *owner;
    s32 flag;
    char pad1[0x25C0 - 0x364];
    char *cur;
} T_003A2398;
extern T_003A2398 D_001A4BE0_003A2398;
extern s32 D_L03_002A1420[];
extern s32 D_L03_002D09B0[];
extern s32 D_001A71A0[];
extern s32 D_001DF99C_sda;
extern s32 D_001DE3F0_sda; __asm__(".extern D_001DE3F0_sda, 4");
extern char *D_001D52FC;
extern u8 D_00142765[];
extern u32 D_00142C1C[];

extern s32 func_0038CB00(void *);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L02_003BAAB0(void *, void *);
extern s32 func_L01_004BA800(void);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern void func_0039EF28(void);
extern void func_L01_00456230(void *, s32);
extern void func_003A52A0(s32, s32, void *);
extern f32 func_00382538(void);
extern void func_L01_00511A40(void *, s32, f32);
extern void func_L01_00446780(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);
extern void func_L03_003A2BB8(void *);
extern void func_L03_003A2A10(s32);
extern void func_L03_003A2790(void *, void *);
extern s32 func_L01_00511A98(void);
extern void func_L01_005003D0(s32, s32);
extern void func_L03_003A1B70(void *, int);
extern s32 func_L01_004AAC98(s32, s32, s32, s32);

void func_L03_003A2398(char *arg0) {
    char *p = *(char **)(arg0 + 0x68);
    f32 f;
    if (func_0038CB00(p + 0x24) != 0) {
        *(s16 *)(p + 0x24) = 50;
    }
    f = func_0038D0B0((f32)*(s16 *)(p + 0x24) * 6.2831855f / 50.0f);
    *(s32 *)(arg0 + 0x78) = func_0038DBD8(0x80B0B0B0, 0x80505050, f * 0.5f + 0.5f);
    switch (*(u8 *)(arg0 + 0x20)) {
    case 0:
        func_L02_003BAAB0((void *)D_001A71A0[0], D_L03_002A1420);
        func_L01_004450F0((s32)arg0, 2, -1);
        break;
    case 1:
        break;
    case 2:
        if (D_001A4BE0_003A2398.flag != 0 && D_001A4BE0_003A2398.owner == arg0) {
            if (func_L01_004BA800() == 0) {
                func_L01_004450F0((s32)arg0, 3, -1);
            }
        }
        break;
    case 3:
        func_L01_00452560(0, 12, 0xA27, 1, 0, 0, 0);
        if (D_001A4BE0_003A2398.flag == 0 || D_001A4BE0_003A2398.owner != arg0) {
            func_L01_004450F0((s32)arg0, 2, -1);
        }
        if (D_L03_002D09B0[0] == 12) {
            char *s = D_001D52FC;
            if (*(s32 *)(s + 0x1A4) & 0x10) {
                D_00142765[0] = 1;
                func_0039EF28();
                if ((D_00142C1C[0] & 0x40000000) == 0) {
                    char *r = (char *)D_001DF99C_sda + (*(s32 *)(p + 8) << 8);
                    func_L01_00456230(r, 1);
                    *(u8 *)(r + 0x30) = 0xFF;
                    (*(void (**)(char *))(r + 0x64))(r);
                    func_L01_004450F0((s32)arg0, 2, -1);
                } else {
                    f32 g;
                    f32 one = 1.0f;
                    func_003A52A0(0, 0, arg0);
                    *(u16 *)(D_001A4BE0_003A2398.cur + 0x34) |= 0x2000;
                    g = func_00382538();
                    *(f32 *)(p + 0x18) = g;
                    *(f32 *)(p + 0x14) = 0.03490658849f;
                    *(f32 *)(p + 0x1C) = 0.8f;
                    *(f32 *)(p + 0x20) = 0.8f;
                    *(f32 *)(p + 0xC) = one;
                    *(f32 *)(p + 0x10) = 0.3f;
                    func_L01_00511A40(arg0 + 0x10, 0, *(f32 *)(arg0 + 0xF8));
                    func_L01_00446780((u8 *)arg0, (u8 *)arg0 + 0x10, 0x10000, 0, 1, 0, 1.5f, 20.0f, one);
                    func_L01_004450F0((s32)arg0, 4, -1);
                }
            }
        }
        break;
    case 4:
        func_L03_003A2BB8(arg0);
        func_L03_003A2A10(-1);
        func_L03_003A2790(arg0, &D_001DE3F0_sda);
        *(u16 *)(arg0 + 0x34) &= 0xFFBE;
        *(u16 *)(arg0 + 0x34) |= *(u16 *)(*(char **)(arg0 + 0x24) + 0x44) & 0x1000;
        *(s32 *)(arg0 + 0x98) = *(s32 *)(*(char **)(arg0 + 0x24) + 0x10);
        if (func_L01_00511A98() == 2) {
            func_L01_005003D0(0x74, 1);
            func_L01_004450F0((s32)arg0, 5, -1);
        }
        break;
    case 5: {
        char *q;
        *(u16 *)(arg0 + 0x34) &= 0xFFBE;
        *(u16 *)(arg0 + 0x34) |= *(u16 *)(*(char **)(arg0 + 0x24) + 0x44) & 0x1000;
        *(s32 *)(arg0 + 0x98) = *(s32 *)(*(char **)(arg0 + 0x24) + 0x10);
        q = D_001A4BE0_003A2398.cur;
        if ((u8)q[0x23] >= 0xD) {
            func_L03_003A2A10(-1);
            func_L03_003A2790(arg0, &D_001DE3F0_sda);
            func_L03_003A2BB8(arg0);
        } else {
            char *w;
            *((u8 *)&D_001A4BE0_003A2398 + 0x25E5) = 1;
            w = (char *)D_001DF99C_sda + (*(s32 *)p << 8);
            func_L03_003A1B70(w, 1);
            func_L01_004AAC98(1, 0, (s32)w, 0x19CD);
            func_L01_004450F0((s32)arg0, 2, -1);
        }
        break;
    }
    }
}
/* localdecomp:end func_L03_003A2398 */
/* localdecomp:end func_L03_003A2398 */
/* localdecomp:end func_L03_003A2398 */
/* localdecomp:end func_L03_003A2398 */

/* localdecomp:start func_L03_003A2790 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003A2790;
typedef struct { u8 pad[0x68]; f32 *p68; } S_003A2790;
typedef struct { u8 pad[0xE0]; V4_003A2790 v; } A_003A2790;
typedef struct { u8 pad0[0x25C0]; void *q; } H_003A2790;
typedef struct { u8 pad[0xD4]; u8 *p; } G_003A2790;
extern H_003A2790 D_001A4BE0_003A2790;
extern G_003A2790 D_L03_0021F298_003A2790;
extern u8 D_L03_002A1420_003A2790[];
__asm__(".extern D_001A4BE0_003A2790, 16");
__asm__(".extern D_L03_0021F298_003A2790, 16");
__asm__(".extern D_L03_002A1420_003A2790, 16");
void func_L02_003BAFA0(f32, void *, void *, void *, s32);
void func_0038CF68(V4_003A2790 *, V4_003A2790 *, f32);
f32 func_L01_00443A18(f32, f32);
f32 func_003824E0(f32, f32);
s32 func_00382498(s32, s32);
u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);

void func_L03_003A2790(void *a0, void *b0) {
    A_003A2790 *a = a0;
    s32 *b = b0;
    char buf[0x10];
    V4_003A2790 vec;
    f32 *p = *(f32 **)((u8 *)a + 0x68);
    s32 i;
    for (i = 0; i < 24; i++) {
        s32 h;
        f32 f;
        u8 *r;
        func_L02_003BAFA0(0.0f, D_001A4BE0_003A2790.q, D_L03_002A1420_003A2790, buf, 0);
        vec = a->v;
        func_0038CF68(&vec, &vec, p[4] * 0.040000003f);
        h = (s32)func_L01_00443A18(2.0f, 5.0f);
        f = func_003824E0(0.05f, 0.1f);
        r = func_L01_004713C8(buf, &vec, (s32)((f32)((func_00382498(20, 25) * 5 + 2) / 6) * p[4]), b[0], h, 0x7F, 0x7F, f * 210000.0f, 2100.0f, -0.0012f, 1);
        h = -(h * 2);
        r = func_L01_004713C8(buf, &vec, (s32)((f32)((func_00382498(20, 25) * 5 + 2) / 6) * p[4]), b[1], h, 0x30, 0x30, (f *= 4.0f) * 210000.0f, 4200.0f, -0.0012f, 0);
        if (r) r[2] = *D_L03_0021F298_003A2790.p;
    }
    p[4] = p[4] + 0.035000004f;
    if (p[4] > 1.0f) p[4] = 1.0f;
}
/* localdecomp:end func_L03_003A2790 */
