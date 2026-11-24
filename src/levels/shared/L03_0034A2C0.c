#include "common.h"
#include "vu0.h"

typedef int q128 __attribute__((mode(TI)));

typedef struct {
    char pad0[0x150];
    q128 unk150;
    char pad160[0x190 - 0x160];
    q128 unk190;
    char pad1A0[0x300 - 0x1A0];
    q128 unk300;
    char pad310[0x940 - 0x310];
    q128 unk940;
} Vars;

typedef struct {
    char pad0[0x10];
    q128 pos;
    char pad20[0x34 - 0x20];
    u16 flags;
    char pad36[0x68 - 0x36];
    Vars *vars;
    char pad6C[0xA8 - 0x6C];
    u8 unkA8;
    char padA9[0xAA - 0xA9];
    s16 oClass;
} Moby;

/* localdecomp:start func_L03_0034A2C0 */
extern void func_L01_004450F0(Moby *, s32, s32);
extern s32 func_L01_00456250(void *);
extern s32 func_L01_004561B8(u8 *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L03_0034A4B8(void *, s32);
extern void func_L01_004AA7E8(void *, s32);
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern u8 D_001A4C60[];
__asm__(".extern D_L03_001DF4C0, 4");
extern s32 D_L03_001DF4C0;
__asm__(".extern D_L03_001DD610, 4");
extern s32 D_L03_001DD610;

void func_L03_0034A2C0(u8 *m) {
    u8 *v;
    f32 k;
    s32 c;

    v = *(u8 **)(m + 0x68);
    switch (m[0x20]) {
    case 0:
        *(s32 *)(v + 0x24) = 0;
        *(f32 *)(m + 0x14) = *(f32 *)(D_001A4C60 + 4);
        func_L01_004450F0((Moby *)m, 1, -1);
        break;
    case 1:
        if (func_L01_00456250(m) != 0) {
            func_L01_004450F0((Moby *)m, 2, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(m) != 0) {
            if (D_L03_001DF4C0 >= 0x1F) {
                func_003A52A0(0, 0, m);
            }
            func_L03_0034A4B8(m + 0x10, 10);
            *(s32 *)(m + 0x98) = 0;
            *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(m, 1);
        }
        break;
    case 3:
        *(s32 *)(m + 0x48) = 0;
        k = func_L03_0034B440(1, 0, 0, (f32)*(s32 *)(v + 0x2C), (f32)*(s32 *)(v + 0x28), 1.0f);
        m[0x23] = (s32)((1.0f - k) * 128.0f);
        if (D_L03_001DD610 != 0) {
            *(u16 *)(m + 0x34) |= 8;
        } else {
            *(u16 *)(m + 0x34) &= ~8;
        }
        *(f32 *)(m + 0x2C) = func_003C4088(*(f32 *)(v + 0x1C), *(f32 *)(v + 0x20), k);
        c = func_0038DBD8(*(s32 *)(v + 0x18), *(s32 *)(v + 0x14), k);
        vec_add_ab(m + 0x10, m + 0x10, v);
        func_L01_0043B9E8(m, c & 0xFF, (c >> 8) & 0xFF, (c >> 16) & 0xFF);
        if (func_0038CAD0(v + 0x2C) != 0) {
            func_003C2880(m);
        }
        break;
    }
}
/* localdecomp:end func_L03_0034A2C0 */

/* localdecomp:start func_L03_0034A4B8 */
extern vu0_v4 D_L03_001E2440;
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_L01_00443A18(f32, f32);
extern u8 *func_L01_0046B458(void *position, s32 life, f32 size, f32 start_size, s32 colour, s32 roll_kind, s32 spin, void *velocity, f32 unk, s32 delay);

void func_L03_0034A4B8(void *arg0, s32 count) {
    f32 *position = arg0;
    vu0_v4 velocity, at, delta, axis, base;
    f32 size, angle, z, dt;
    s32 spin, i;
    u8 *p;
    vec_sub_ab(&delta, &D_L03_001E2440, position);
    func_0038CF68(&base, &delta, 0.3f);
    delta.z = 0.0f;
    axis.x = 0.0f;
    axis.y = 0.0f;
    axis.z = 1.0f;
    axis.w = 1.0f;
    i = 0;
    if (count > 0) {
        dt = 0.020000001f;
        z = delta.z;
        while (i < count) {
            size = func_003824E0(0.5f, 2.0f);
            spin = func_00382468(2);
            if (spin == 0) spin--;
            angle = func_003824E0(-1.0471976f, 1.0471976f);
            func_0038D890(&velocity, &delta, &axis, angle);
            func_0038CF68(&velocity, &velocity, func_003824E0(0.05f, 3.0f) * dt);
            velocity.z = func_003824E0(1.0f, 5.0f) * dt;
            vec_add_ab(&at, position, &base);
            position[0] += func_L01_00443A18(z, 0.15f);
            position[1] += func_L01_00443A18(z, 0.15f);
            position[2] += func_L01_00443A18(z, 0.15f);
            p = func_L01_0046B458(&at, 50, size * 0.1f, size, 0xDD10FF10, 0, spin, &velocity, 0.0028800003f, 0);
            if (p) p[9] = 0x74;
            p = func_L01_0046B458(&at, 50, size * 0.07f, size * 0.7f, 0xDD10FF10, 1, -spin, &velocity, 0.0028800003f, 0);
            if (p) p[9] = 0x74;
            i++;
        }
    }
}
/* localdecomp:end func_L03_0034A4B8 */

/* localdecomp:start func_L03_0034A760 */
extern u8 *func_L01_00447490(u8 *, s32, s32);
void func_L03_0034A760(u8 *a0) {
    u8 *p = func_L01_00447490(a0, 0x10000, 0);
    if (p != 0) {
        u8 *q = *(u8 **)(p + 32);
        if (q != 0) {
            s16 t = *(s16 *)(q + 170);
            if (t == 208 || t == 2085) {
                a0[188] = 1;
            }
        }
    }
    a0[168] = 255;
}
/* localdecomp:end func_L03_0034A760 */

LINKER_REMNANT("asm/levels", func_L03_0034A7C8);

/* localdecomp:start func_L03_0034A7D8 */
extern void func_003C6680(void *, void *, s32, s32, void *, s32, s32, s32, void *, void *, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_L01_004395E0(void *);
extern void func_003A4F28(s32);
extern void func_003C6990(void *, void *, s32);
__asm__(".extern D_L03_001DD620, 4");
extern f32 D_L03_001DD620;
__asm__(".extern D_L03_001DD624, 4");
extern f32 D_L03_001DD624;
extern u8 D_001A30B0[];

void func_L03_0034A7D8(u8 *m) {
    u8 *pv = *(u8 **)(m + 0x68);
    s32 a1;
    u8 *o;

    func_L03_0034A760(m);
    switch (m[0x20]) {
    case 0:
        *(f32 *)(pv + 0x158) = *(f32 *)(m + 0x18);
        func_003C6680(m, pv + 0x70, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        *(q128 *)(pv + 0x70) = *(q128 *)(m + 0x10);
        *(f32 *)(pv + 0x78) += D_L03_001DD620;
        if (m[0x43] != 0) {
            func_003C3A10(m, 0, 0, 10);
        }
        func_L01_004450F0((Moby *)m, 4, -1);
        break;
    case 1:
        *(f32 *)(pv + 0x78) += (*(f32 *)(pv + 0x158) + D_L03_001DD620 - *(f32 *)(pv + 0x78)) * (D_L03_001DD624 * 1.2f);
        if (m[0xBC] != 0) {
            if (m[0x43] != 1) {
                func_003C3A10(m, 1, 0, 10);
            }
            func_L01_004450F0((Moby *)m, 2, -1);
        }
        break;
    case 2:
        *(f32 *)(pv + 0x78) += (*(f32 *)(pv + 0x158) - *(f32 *)(pv + 0x78)) * (D_L03_001DD624 * 1.2f);
        if (func_L01_004561B8(m)) {
            *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
            *(s32 *)(pv + 0x14C) = func_003A52A0(0, 4, m);
        }
        if (m[0x60] & 2) {
            if (m[0x43] != 2) {
                func_003C3A10(m, 2, 0, 10);
            }
            func_L01_004450F0((Moby *)m, 3, -1);
        }
        break;
    case 3:
        *(f32 *)(pv + 0x78) += (*(f32 *)(pv + 0x158) - *(f32 *)(pv + 0x78)) * (D_L03_001DD624 * 1.2f);
        if (func_L01_004561B8(m)) {
            *(s32 *)(pv + 0x148) = 200;
        }
        if ((f32)((*(u16 *)(m + 0x96))++) > ((*(f32 *)(pv + 0x150) + *(f32 *)(pv + 0x154)) * 60.0f * 5.0f + 2.0f) / 6.0f) {
            if (m[0x43] != 3) {
                func_003C3A10(m, 3, 0, 10);
            }
            func_L01_004450F0((Moby *)m, 4, -1);
        }
        break;
    case 4:
        *(f32 *)(pv + 0x78) += (*(f32 *)(pv + 0x158) + D_L03_001DD620 - *(f32 *)(pv + 0x78)) * (D_L03_001DD624 * 1.2f);
        if (m[0x42] == 3) {
            if (func_L01_004395E0(m) > 5.0f) {
                *(s32 *)(m + 0x98) = 0;
            }
        }
        if (m[0x60] & 2) {
            if (m[0x43] != 0) {
                func_003C3A10(m, 0, 0, 10);
            }
            m[0xBC] = 0;
            *(s32 *)(m + 0x98) = 0;
            func_L01_004450F0((Moby *)m, 1, -1);
            a1 = *(s32 *)(pv + 0x14C);
            if (a1 != -1) {
                o = D_001A30B0 + (a1 << 7);
                if (*(u8 **)(o + 0xDC) == m && o[0xD0] != 0) {
                    func_003A4F28(a1);
                }
            }
            *(s32 *)(pv + 0x14C) = -1;
        }
        break;
    }
    func_003C6990(m, pv + 0x70, 0);
}
/* localdecomp:end func_L03_0034A7D8 */

/* localdecomp:start func_L03_0034AB60 */
extern void func_L01_004450F0(Moby *, s32, s32);
extern void func_L03_0034AF98(u8 *);
extern void func_L03_0034B008(u8 *);
extern void func_L03_0034AC40(u8 *);
extern u8 D_001426E0[];

void func_L03_0034AB60(u8 *a0) {
    switch (a0[0x20]) {
    case 0:
        func_L03_0034AF98(a0);
        break;
    case 1:
        if (D_001426E0[0xDB] == 1) {
            func_L01_004450F0((Moby *)a0, 2, -1);
        }
        if (D_001426E0[0xDB] == 2) {
            func_L01_004450F0((Moby *)a0, 3, -1);
        }
        break;
    case 2:
        func_L03_0034B008(a0);
        break;
    case 3:
        func_L03_0034AC40(a0);
        break;
    }
}
/* localdecomp:end func_L03_0034AB60 */

/* localdecomp:start func_L03_0034AC40 */
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_005003D0(s32, s32);
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern void func_L01_003EB3C0(s32, void *);
extern void func_L01_003EB350(s32, void *);
extern s32 func_0039EC28(s32, s32);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern void func_00392DF0(s32, s32);
extern s32 func_L03_0034AE68(u8 *, s32);
extern void func_L03_0034AED8(void *, Moby *);
extern u8 D_L03_001E24C0[];
extern u8 *D_L03_001DFA80;
extern s32 D_L03_001E1410[] __attribute__((section(".sdata")));
typedef struct {
    u8 pad0[0x558];
    u8 f558;
    u8 pad559[0x5C0 - 0x559];
} P_0034AC40;
extern P_0034AC40 D_001CD0C0[];
extern u8 *D_001D52FC;
extern u8 *D_L03_001DF9A8;
typedef struct {
    u8 pad[0x100];
} S_0034AC40;
extern S_0034AC40 *D_L03_001DF99C_0034AC40;
__asm__(".extern D_L03_001DD63C, 4");
extern s32 D_L03_001DD63C;

void func_L03_0034AC40(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    s32 n = 0;
    s32 i;
    s32 j;
    u8 *m;

    if (func_L01_004561B8(a0) != 0) {
        func_L01_005003D0(0x74, 1);
        func_L01_003EB438(0, D_L03_001E24C0, D_L03_001E24C0 + 0x10, 1, 100, 0);
        func_L01_003EB3C0(0, D_L03_001DFA80 + (*(s32 *)(v + 0xC) << 7) + 0x70);
        func_L01_003EB350(0, D_L03_001DFA80 + (*(s32 *)(v + 0xC) << 7) + 0x30);
        D_001426E0[0xDB] = 0;
        func_0039EC28(0, 3);
        D_L03_001DD63C = 0;
        for (j = 3; j >= 0; j--) {
            D_L03_001E1410[j] = -1;
        }
        for (j = 0; j < 8 && n < 5; j++) {
            if (D_001CD0C0[j].f558 != 0) {
                D_L03_001E1410[n] = j;
                n++;
            }
        }
        func_L01_00452560(0, 5, 0xE79, 1, 0, 0, 0);
    }
    if (*(s32 *)(D_001D52FC + 0x1A4) & 0x800) {
        func_00392DF0(3, 1);
    }
    if (func_L03_0034AE68(a0, 1) < 2) {
        D_L03_001DD63C = 1;
        for (m = D_L03_001DF9A8; m != 0; m = *(u8 **)(m + 0x28)) {
            if (*(s16 *)(m + 0xAA) == 0x1B9B) {
                m[0xBC] = 1;
            }
        }
    }
    if (func_L03_0034AE68(a0, 0) < 2) {
        for (i = 0; i < 4; i++) {
            func_L03_0034AED8(a0, (Moby *)&D_L03_001DF99C_0034AC40[((s32 *)(v + 0x10))[i]]);
        }
        D_L03_001DD63C = 0;
    }
}
/* localdecomp:end func_L03_0034AC40 */

/* localdecomp:start func_L03_0034AE68 */
typedef struct {
    u8 pad[32];
    u8 type;
    u8 pad2[223];
} E_0034A2A8;
extern E_0034A2A8 *D_L03_001DF99C;
s32 func_L03_0034AE68(u8 *a0, s32 a1) {
    s32 *q = (s32 *)(*(u8 **)(a0 + 104) + 16);
    s32 count = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (q[i] != -1) {
            u8 t = D_L03_001DF99C[q[i]].type;
            if (t != 3 && (a1 == 0 || t != 2)) {
                count++;
            }
        }
    }
    return count;
}
/* localdecomp:end func_L03_0034AE68 */

/* localdecomp:start func_L03_0034AED8 */
extern void func_L01_004450F0(Moby *, s32, s32);

void func_L03_0034AED8(void *arg0, Moby *m) {
    if (arg0 == 0 || m == 0) {
        return;
    }
    if (m->oClass == 7003) {
        m->pos = m->vars->unk940;
    }
    if (m->oClass == 7062) {
        m->pos = m->vars->unk150;
    }
    if (m->oClass == 7063) {
        m->pos = m->vars->unk300;
    }
    if (m->oClass == 7066) {
        m->pos = m->vars->unk190;
    }
    m->unkA8 = 255;
    m->flags &= ~2;
    func_L01_004450F0(m, 0, -1);
}
/* localdecomp:end func_L03_0034AED8 */
