#include "common.h"

/* localdecomp:start func_L41_00414A10 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00414A10;

typedef struct {
    u8 pad0[0x70];
    s32 x70[5];
    u8 pad84_[0x84 - 0x84];
    s32 x84;
    u8 pad88[0x90 - 0x88];
    s32 x90;
    u8 pad94[0x98 - 0x94];
    s32 x98;
    u8 pad9C[0xA0 - 0x9C];
    s32 xA0;
    s32 xA4[5];
    u8 padB8[0xBC - 0xB8];
    s32 xBC;
} P_00414A10;

typedef struct {
    u8 pad0[0x10];
    V_00414A10 x10;
    u8 x20;
    u8 pad21[0x30 - 0x21];
    u8 x30;
    u8 pad31[0x68 - 0x31];
    P_00414A10 *x68;
} A_00414A10;

typedef struct {
    u8 pad[0x100];
} M_00414A10;

typedef struct {
    u8 pad[0x168];
    u8 b168;
} G_00414A10;

extern void func_L40_0053D8C8(s32, void *, void *, void *);
extern void func_L40_003EFDE0(void);
extern void func_L40_003EE130(void);
extern void func_L41_003EDA60(void);
extern void func_L39_0061C1E0(M_00414A10 *, s32);
extern s32 func_003D4D00(void *, s32, f32, s32, void *);
extern void func_0038CAD0(s32 *);
extern void func_L41_00414900(s32 *, s32 *);
extern s32 func_L41_004149E0(P_00414A10 *);
extern s32 func_L41_00414980(A_00414A10 *);
extern void func_L41_003ED748(V_00414A10 *, s32, s32, s32 *, s32, s32, s32);
extern s16 *D_L41_0028EB60[];
extern s32 D_L41_00248698;
extern M_00414A10 *D_L41_0024865C;
extern s32 D_L41_0025BAD8 __attribute__((section(".data")));
extern G_00414A10 D_001A5CD0;

void func_L41_00414A10(A_00414A10 *a) {
    P_00414A10 *p;
    s32 i;
    s16 *s;
    M_00414A10 *m;
    V_00414A10 tmp;

    a->x30 = 0xFF;
    p = a->x68;
    if (a->x20 == 0) {
        for (i = 0; i < 5; i++) {
            p->x70[i] = 0;
            p->xA4[i] = 0;
            func_L40_0053D8C8(0x109D, func_L40_003EFDE0, func_L40_003EE130, func_L41_003EDA60);
        }
        s = D_L41_0028EB60[p->xBC];
        while ((p->xBC & 0xFF) != 0xFF && p->xBC <= D_L41_00248698 && s != 0
               && (s[-1] >= 0 || s == D_L41_0028EB60[p->xBC])) {
            m = &D_L41_0024865C[*s & 0x7FFF];
            if (m == 0) break;
            func_L39_0061C1E0(m, -1);
            s++;
        }
        if (p->x84 <= 0) {
            p->x84 = 30;
        }
        if (func_003D4D00(&a->x10, 1, 3.0f, 0, 0)) {
            p->x98 = D_L41_0025BAD8;
        }
        a->x20 = 1;
    }
    if (D_001A5CD0.b168 != 0) {
        for (i = 0; i < 5; i++) {
            func_L41_00414900(&p->xA4[i], &p->x70[i]);
        }
        if (func_L41_004149E0(p)) {
            func_0038CAD0(&p->x90);
        }
        if (p->x90 > 0) return;
        if (!func_L41_00414980(a)) return;
        if (func_003D4D00(&a->x10, 1, 3.0f, p->x98, 0)) return;
        tmp = a->x10;
        func_L41_003ED748(&tmp, p->xBC, -1, p->x70, -1, p->xA0, -1);
    }
    p->x90 = (s32)((f32)p->x84 * 50.0f);
}
/* localdecomp:end func_L41_00414A10 */
