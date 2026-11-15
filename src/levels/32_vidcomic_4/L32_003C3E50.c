#include "common.h"

typedef struct {
    u8 pad0[0x34];
    s32 f34;
} S_Sub_003C3E50;
typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad1[0x47];
    S_Sub_003C3E50 *f68;
} S_Obj_003C3E50;
typedef struct {
    u8 pad0[0x24];
    s32 f24;
    u8 pad1[0x44];
    s32 f6C;
    s16 f70;
    u8 pad2[4];
    s16 f76;
    u8 pad3[0x1C];
    s32 f94;
    s16 f98;
    u8 pad4[4];
    s16 f9E;
} S_1CCFD0_003C3E50;

/* localdecomp:start func_L32_003C3E50 */
extern S_1CCFD0_003C3E50 D_001CCFD0;
extern void func_L32_003C3EE8(void *);
extern void func_L32_003C3F10(S_Obj_003C3E50 *);
extern void func_L32_003C4000(void *);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L32_003C3E50(S_Obj_003C3E50 *a0) {
    S_Sub_003C3E50 *s1 = a0->f68;

    if (a0->f20 == 0) {
        func_L32_003C3EE8(a0);
        func_L01_004450F0((u8 *)a0, 1, -1);
    }
    if (D_001CCFD0.f6C == 0 && D_001CCFD0.f24 == -1 && D_001CCFD0.f94 == 0 && s1->f34 == 0) {
        func_L32_003C4000(a0);
    }
    func_L32_003C3F10(a0);
}
/* localdecomp:end func_L32_003C3E50 */

/* localdecomp:start func_L32_003C3EE8 */
void func_L32_003C3EE8(void *o) {
    unsigned char *obj = o;
    int *p = *(int **)(obj + 0x68);
    obj[0x30] = 0xFF;
    p[8] = 0; p[9] = 0; p[10] = 0; p[11] = 0; p[12] = 0; p[13] = 0;
}
/* localdecomp:end func_L32_003C3EE8 */

/* localdecomp:start func_L32_003C3F10 */
extern S_1CCFD0_003C3E50 D_001CCFD0;
extern void func_003A1798(void);

void func_L32_003C3F10(S_Obj_003C3E50 *p) {
    S_Sub_003C3E50 *q = p->f68;

    if (D_001CCFD0.f70 >= 7000) {
        if (q->f34 != 0) {
            q->f34 = 0;
        }
    }
    if (D_001CCFD0.f76 == 0 && D_001CCFD0.f9E == 3 && D_001CCFD0.f98 < 7000) {
        func_003A1798();
        q->f34 = 0;
    }
}
/* localdecomp:end func_L32_003C3F10 */

/* localdecomp:start func_L32_003C3F98 */
void func_L32_003C3F98(void *arg0, s32 arg1) {
    void *temp_a2;

    temp_a2 = *(void **)((u8 *)arg0 + 0x68);
    switch (arg1) {
    case 0:
        *(s32 *)((u8 *)temp_a2 + 0x20) = 1;
        return;
    case 1:
        *(s32 *)((u8 *)temp_a2 + 0x24) = 1;
        return;
    case 2:
        *(s32 *)((u8 *)temp_a2 + 0x28) = 1;
        return;
    case 3:
        *(s32 *)((u8 *)temp_a2 + 0x2C) = 1;
        return;
    case 6:
        *(s32 *)((u8 *)temp_a2 + 0x30) = 1;
        break;
    case 4:
    case 5:
        break;
    }
}
/* localdecomp:end func_L32_003C3F98 */

/* localdecomp:start func_L32_003C4000 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    u8 pad1C[4];
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
} V_003C4000;

typedef struct {
    u8 pad0[0x1B04];
    s32 f1B04;
    u8 pad1B08[0x30];
    s32 f1B38;
    u8 pad1B3C[0x25C4 - 0x1B3C];
    s32 f25C4;
} G_003C4000;

extern G_003C4000 D_001A4BE0;
extern void func_003A2B68(s32, s32);

void func_L32_003C4000(void *a0) {
    V_003C4000 *v = *(V_003C4000 **)((u8 *)a0 + 0x68);

    if (v->f20 != 0) {
        v->f20 = 0;
        func_003A2B68((v->f0 & 0x3FFF) + 2000, 0);
        v->f34 = 1;
    } else if (v->f24 != 0) {
        v->f24 = 0;
        func_003A2B68((v->f4 & 0x3FFF) + 2000, 0);
        v->f34 = 1;
    } else if (v->f28 != 0) {
        v->f28 = 0;
        func_003A2B68((v->f8 & 0x3FFF) + 2000, 0);
        v->f34 = 1;
    } else if (v->f2C != 0) {
        v->f2C = 0;
        func_003A2B68((v->fC & 0x3FFF) + 2000, 0);
        v->f34 = 1;
    } else if (v->f30 != 0) {
        v->f30 = 0;
        func_003A2B68((v->f18 & 0x3FFF) + 2000, 0);
        v->f34 = 1;
    } else if (D_001A4BE0.f1B04 == 3 && ((*(u8 *)&D_001A4BE0.f1B38 ^ 1) & 1)) {
        D_001A4BE0.f1B38 |= 1;
        func_003A2B68((v->f10 & 0x3FFF) + 2000, 0);
        v->f34 = 1;
    } else if (D_001A4BE0.f25C4 == 0xAD && !(D_001A4BE0.f1B38 & 2)) {
        D_001A4BE0.f1B38 |= 2;
        func_003A2B68((v->f14 & 0x3FFF) + 2000, 0);
        v->f34 = 1;
    }
}
/* localdecomp:end func_L32_003C4000 */
