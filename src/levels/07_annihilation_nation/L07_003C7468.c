#include "common.h"
#include "vu0.h"
#include "structs/moby.h"

/* localdecomp:start func_L07_003C7468 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003C7468;
typedef union {
    u8 b[0x500];
    s16 h[0x280];
    u16 uh[0x280];
    s32 i[0x140];
    u32 u[0x140];
    f32 f[0x140];
    void *p[0x140];
    V_003C7468 v[0x50];
} O_003C7468;

/* Per-step state machine of a walker-style moby: sets up on state 0, then by its state at 0x20
 * checks timers, animation ends and targets, switching to the next state through func_L07_003C8718
 * and related helpers. */
void func_L07_003C7468(O_003C7468 *m) {
    extern u8 *D_L07_001DF41C_003C7468;
    extern u8 *D_L07_001DF500;
    extern s32 *D_L07_0021D2C0[];
    extern u8 D_L07_003C9C40[];
    extern u8 D_L07_003C9D50[];
    extern void func_L07_003C7E70(void *);
    extern void func_L07_003C80C0(void *);
    extern s32 func_L01_004561B8(void *);
    extern s32 func_L07_003C8960(void *);
    extern s32 func_0038CB00(void *);
    extern void func_L07_003C8718(void *, s32);
    extern void func_L01_00409598(void *, void *, void *, s32, s32, s32, s32, s32, u32, u32);
    extern void func_L07_003C8A10(void *);
    extern void func_L07_003C8A88(void *);
    extern void func_L07_003C8B18(void *);
    extern void func_L07_003C8C90(void *);
    extern void func_L07_003C8AD0(void *);
    extern void func_L07_003C8B60(void *);
    extern void func_L07_003C8BA0(void *);
    extern void func_L07_003C8C30(void *);
    extern void func_L07_003C9488(void *, s32, s32);
    extern s32 func_L01_0045BDE8(void *, s32);
    extern s32 func_L01_0045A9F0(void *);
    extern s32 func_L01_00454370(void *, void *);
    extern void func_L07_003C8CF8(void *, f32);
    extern void func_L07_003C8FF8(void *, void *, f32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_L01_0040E570(void *, void *);
    extern f32 func_0038CF38(void *, void *);
    extern f32 func_0038DBA0(f32, f32);
    extern void func_L07_003C9150(void *, void *);
    extern void func_L01_0045AA10(void *, f32);
    extern s32 func_L01_0045A748(void *, void *);
    extern s32 func_L07_003BAF28(void *);
    extern s32 func_003A52A0(s32, s32, void *);
    extern void func_L07_003C8D60(void *);
    extern void func_L07_003C91A8(void *, void *);
    extern void func_L07_003C97E0(void *);
    extern void func_L07_003C9780(void *, void *, f32, f32);
    extern void func_L07_003C9280(void *);
    extern void func_L07_003C99A0(void *);
    extern void func_L01_00404808(void *, void *);
    extern void func_L07_003C90F8(void *);
    extern f32 func_L07_003C9528(void *);
    extern void func_L07_003C96C0(void *, void *, f32);
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern void func_L07_003C84F8(void *, void *);

    O_003C7468 *p;
    V_003C7468 old, tmp;
    f32 radius, angle, dist, t;

    if (m->b[0x20] == 1)
        return;
    if (!m->b[0x20])
        func_L07_003C7E70(m);
    func_L07_003C80C0(m);
    p = m->p[0x68 / 4];
    old = m->v[0x10 / 16];

    switch (m->b[0x20]) {
    case 2:
        if (func_L01_004561B8(m))
            p->uh[0x4C6 / 2] = (p->h[0x4C4 / 2] * 5 + 2) / 6;
        if (func_L07_003C8960(m) && func_0038CB00(p->b + 0x4C6))
            func_L07_003C8718(m, 3);
        break;
    case 3:
        {
            u8 *r = D_L07_001DF41C_003C7468 + (p->i[0x4C0 / 4] << 8);
            func_L01_00409598(m, r + 0x10, r + 0xF0, 0, 2, 3, 37, 37, 0x00FF8040, 0x008F1010);
        }
        p->v[0x440 / 16] = m->v[0x10 / 16];
        func_L07_003C8A10(m);
        break;
    case 4:
        if (func_L01_004561B8(m))
            func_L07_003C9488(m, p->i[0x4A8 / 4], 2);
        if (func_L07_003C8960(m))
            func_L07_003C8B18(m);
        else if (func_L01_0045BDE8(m, p->i[0x4A8 / 4]))
            func_L07_003C8718(m, 4);
        break;
    case 5:
        func_L01_0045A9F0(m);
        if (func_L07_003C8960(m))
            func_L07_003C8B18(m);
        break;
    case 6:
        if (func_L01_004561B8(m))
            func_L07_003C9488(m, p->i[0x4AC / 4], 1);
        if (func_L07_003C8960(m))
            func_L07_003C8718(m, 10);
        else if (func_L01_0045BDE8(m, p->i[0x4AC / 4]))
            func_L07_003C8A88(m);
        break;
    case 7:
        if (func_L07_003C8960(m))
            func_L07_003C8C90(m);
        break;
    case 8:
        func_L01_0045A9F0(m);
        if (func_L01_00454370(m, p->b + 0x70) & 2) {
            if (p->i[0x4B8 / 4] == -1 && p->i[0x4B0 / 4] == -1)
                func_L07_003C8718(m, 9);
            else
                func_L07_003C8C90(m);
        }
        break;
    case 9:
        if (func_L01_004561B8(m))
            p->h[0x4C6 / 2] = 250;
        if (func_L07_003C8960(m))
            func_L07_003C8B18(m);
        else if (func_0038CB00(p->b + 0x4C6))
            func_L07_003C8AD0(m);
        break;
    case 10:
        if (func_L01_004561B8(m))
            func_L07_003C9488(m, p->i[0x4AC / 4], 0);
        if (!func_L07_003C8960(m))
            func_L07_003C8718(m, 9);
        else if (func_L01_0045BDE8(m, p->i[0x4AC / 4]))
            func_L07_003C8B60(m);
        break;
    case 11:
        if (func_L01_004561B8(m)) {
            O_003C7468 *sub = (O_003C7468 *)(p->b + 0x150);
            sub->u[0x38 / 4] |= 0x10;
        }
        radius = p->f[0x4CC / 4] + (p->f[0x4D0 / 4] - p->f[0x4CC / 4]) * 0.6000000238418579f;
        func_L07_003C8CF8(m, p->f[0x4CC / 4] + (p->f[0x4D0 / 4] - p->f[0x4CC / 4]) * 0.5f);
        angle = func_0038D160(p->f[0x130 / 4] - m->f[0x10 / 4], p->f[0x134 / 4] - m->f[0x14 / 4]);
        func_L07_003C8FF8(m, &old, angle);
        func_L07_003C9150(m, p->b + 0x130);
        if (!func_L07_003C8960(m))
            func_L07_003C8718(m, 9);
        else if (func_0038CB00(p->b + 0x4D4)) {
            if (!(func_L01_0040E570(m->b + 0x10, p->b + 0x130) < radius * radius))
                break;
            goto select;
        }
        break;
    case 12:
        if (!func_L07_003C8960(m))
            func_L07_003C8718(m, 9);
        else {
            if (p->i[0x1D0 / 4] >= 9)
                p->b[0x4DD] = 1;
            if (p->b[0x4DD] || (func_L01_0045A748(m, p->b + 0x440) & 0x80))
                func_L07_003C8718(m, 13);
        }
        break;
    case 13:
        if (!func_L07_003C8960(m)) {
            func_L07_003C8718(m, 9);
            break;
        }
        angle = func_0038D160(p->f[0x130 / 4] - m->f[0x10 / 4], p->f[0x134 / 4] - m->f[0x14 / 4]);
        func_L01_0045AA10(m, angle);
        dist = func_0038CF38(m->b + 0x10, p->b + 0x130);
        if (func_0038CB00(p->b + 0x4D4) && p->f[0x4CC / 4] < dist && dist < p->f[0x4D0 / 4]) {
            if (func_0038DBA0(angle, m->f[0xF8 / 4]) < 0.4363323152065277f) {
            select:
                p->h[0x460 / 2] = func_L07_003BAF28(m);
                if (p->h[0x460 / 2] <= 0)
                    func_L07_003C8BA0(m);
            }
        }
        break;
    case 14:
    case 18:
        func_L01_0045A9F0(m);
        if (m->b[0x60] & 2)
            func_L07_003C8718(m, m->b[0x20] + 1);
        break;
    case 15:
    case 19:
        if (func_L01_004561B8(m)) {
            func_003A52A0(2, 0, m);
            p->h[0x4C6 / 2] = 25;
        }
        func_L01_0045A9F0(m);
        func_L07_003C8D60(m);
        func_L07_003C91A8(m, p->b + 0x470);
        func_L07_003C97E0(m);
        if (func_0038CB00(p->b + 0x4C6))
            func_L07_003C8718(m, m->b[0x20] + 1);
        break;
    case 16:
    case 20:
        if (func_L01_004561B8(m)) {
            p->i[0x488 / 4] = 0;
            p->h[0x4C6 / 2] = 25;
            func_003A52A0(1, 0, m);
        }
        func_L01_0045A9F0(m);
        func_L07_003C91A8(m, p->b + 0x470);
        func_L07_003C9780(p->b + 0x488, p->b + 0x48C, 0.120000005f, 0.192000002f);
        func_L07_003C9280(m);
        func_L07_003C99A0(m);
        func_L01_00404808(D_L07_003C9C40, m);
        if (func_0038CB00(p->b + 0x4C6))
            func_L07_003C8718(m, m->b[0x20] + 1);
        break;
    case 17:
    case 21:
        func_L01_0045A9F0(m);
        if (m->b[0x60] & 2)
            func_L07_003C8C30(m);
        break;
    case 22:
        func_L01_0045A9F0(m);
        if (m->b[0x60] & 2)
            func_L07_003C8B60(m);
        break;
    case 23:
        if (!func_L07_003C8960(m))
            goto fail7;
        else if (func_L01_0045A748(m, D_L07_001DF500 + (p->i[0x4B8 / 4] << 7) + 0x30) & 0x80)
            func_L07_003C8718(m, 24);
        break;
    case 24:
        if (func_L01_004561B8(m)) {
            p->i[0x488 / 4] = 0;
            p->f[0x4C8 / 4] = m->f[0xF8 / 4];
        }
        if (!func_L07_003C8960(m))
            goto fail7;
        func_L07_003C9780(p->b + 0x488, p->b + 0x48C, 0.0120000001f, 0.192000002f);
        func_L01_00404808(D_L07_003C9D50, m);
        func_L01_0045A9F0(m);
        goto velocity;
    case 25:
        if (func_L01_004561B8(m)) {
            {
                O_003C7468 *sub = (O_003C7468 *)(p->b + 0x150);
                sub->u[0x38 / 4] |= 0x10;
            }
            func_L07_003C9488(m, p->i[0x4B0 / 4], 2);
            if (m->b[0x94] != m->b[0x20]) {
                p->i[0x488 / 4] = 0;
                p->f[0x4C8 / 4] = m->f[0xF8 / 4];
                if (m->b[0x94] != m->b[0x20])
                    func_003A52A0(1, 0, m);
            }
        }
        if (!func_L07_003C8960(m))
            goto fail7;
        func_L07_003C9780(p->b + 0x488, p->b + 0x48C, 0.0120000001f, 0.192000002f);
        func_L01_00404808(D_L07_003C9D50, m);
        if (func_L01_0045BDE8(m, p->i[0x4B0 / 4]))
            func_L07_003C8718(m, 25);
        func_L07_003C8FF8(m, &old, m->f[0xF8 / 4]);
    velocity:
        func_L07_003C90F8(m);
        t = p->f[0x4BC / 4] * 0.01745329238474369f;
        p->f[0x3A0 / 4] = t;
        p->f[0x320 / 4] = -t;
        break;
    fail7:
        func_L07_003C8718(m, 7);
        break;
    case 26:
        if (func_L01_004561B8(m)) {
            {
                O_003C7468 *sub = (O_003C7468 *)(p->b + 0x150);
                sub->u[0x38 / 4] |= 0x10;
            }
            func_L07_003C9488(m, p->i[0x4B0 / 4], 2);
            if (m->b[0x94] != m->b[0x20]) {
                p->i[0x488 / 4] = 0;
                t = func_L07_003C9528(m);
                func_L07_003C96C0(D_L07_0021D2C0[p->i[0x4B4 / 4]], p->b + 0x470,
                                 t * (f32)*D_L07_0021D2C0[p->i[0x4B4 / 4]]);
                if (m->b[0x94] != m->b[0x20])
                    func_003A52A0(1, 0, m);
            }
        }
        if (func_L07_003C8960(m)) {
            t = func_L07_003C9528(m);
            func_L07_003C96C0(D_L07_0021D2C0[p->i[0x4B4 / 4]], &tmp,
                             t * (f32)*D_L07_0021D2C0[p->i[0x4B4 / 4]]);
            func_0038CDF8(p->b + 0x470, p->b + 0x470, &tmp, 0.1f);
            func_L07_003C9780(p->b + 0x488, p->b + 0x48C, 0.0120000001f, 0.192000002f);
            func_L07_003C9280(m);
            func_L07_003C99A0(m);
            func_L01_00404808(D_L07_003C9C40, m);
            if (func_L01_0045BDE8(m, p->i[0x4B0 / 4]))
                func_L07_003C8718(m, 26);
            func_L07_003C8FF8(m, &old, m->f[0xF8 / 4]);
            func_L07_003C9150(m, p->b + 0x470);
            func_L07_003C91A8(m, p->b + 0x470);
        } else
            func_L07_003C8718(m, 7);
        break;
    }
    func_L07_003C84F8(m, &old);
}
/* localdecomp:end func_L07_003C7468 */

/* localdecomp:start func_L07_003C7E70 */
typedef int Q_003C7E70 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x10];
    u8 f10;
    u8 pad11[0x30 - 0x11];
    f32 f30;
    f32 f34;
    u8 pad38[4];
    f32 f3C;
    u8 pad40[8];
    u8 f48;
    u8 pad49[0x58 - 0x49];
    f32 f58;
    f32 f5C;
    u8 pad60[0x77 - 0x60];
    u8 f77;
    u8 pad78[0xB0 - 0x78];
    f32 fB0;
} Move_003C7E70;

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    u8 pad14[0x2C - 0x14];
    f32 f2C;
    f32 f30;
    f32 f34;
    u8 pad38[0xEC - 0x38];
    s32 fEC;
} Tune_003C7E70;

void func_L07_003C7E70(void *object) {
    extern void func_L01_00445F40(void *, s32);
    extern s32 func_L07_003C1AF8(void);
    extern f32 func_L07_003C1B40(s32);
    extern void func_L01_00446058(void *, s32, s32);
    extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
    extern void func_L07_003C86D0(char *);
    u8 *obj = object;
    u8 *state = *(u8 **)(obj + 0x68);
    u8 *stats;
    Move_003C7E70 *move;
    Tune_003C7E70 *tune;
    s32 kind;
    f32 scale;
    f32 half;
    func_L01_00445F40(obj, 0x19BD);
    stats = state + 0x30;
    kind = func_L07_003C1AF8();
    scale = func_L07_003C1B40(kind);
    *(s16 *)(stats + 4) = (s32)(*(s16 *)(state + 0x34) * scale);
    *(f32 *)(state + 0x30) = *(s16 *)(stats + 4);
    stats[0x14] = (s32)(state[0x44] * scale);
    stats[0x15] = (s32)(state[0x45] * scale);
    stats[0x16] = (s32)(state[0x46] * scale);
    if (kind == 1 || kind == 3) {
        func_L01_00446058(obj, 0x1D8A, 0x19BD);
    }
    stats[0x28] = 20;
    stats[0x2A] = 14;
    *(f32 *)(stats + 0x10) = 1.0f;
    stats[0xF] = 0;
    stats[9] = 0;
    move = (Move_003C7E70 *)(state + 0x70);
    move->f3C = 0.15f;
    move->f30 = 1.0f;
    move->fB0 = 1.0f;
    half = 0.5f;
    move->f58 = 0.35f;
    move->f48 = 255;
    move->f10 = 8;
    move->f34 = half;
    move->f5C = half;
    move->f77 = 1;
    tune = (Tune_003C7E70 *)(state + 0x150);
    tune->f0 = 0.6f;
    tune->f4 = 0.3f;
    tune->fEC = 0;
    tune->fC = tune->f8 = half;
    tune->f10 = 1.5707963705062866f;
    tune->f30 = 0.24434609711170197f;
    tune->f2C = 0.19600002467632294f;
    tune->f34 = 0.2f;
    *(Q_003C7E70 *)(state + 0x440) = *(Q_003C7E70 *)(obj + 0x10);
    *(Q_003C7E70 *)(state + 0x450) = *(Q_003C7E70 *)(obj + 0xF0);
    func_L01_0045BD78(obj, 0.002400000113993883f, 0.12000000476837158f, 0.005026548635214567f, 0.12566371262073517f);
    func_L07_003C86D0((char *)obj);
}
/* localdecomp:end func_L07_003C7E70 */

/* localdecomp:start func_L07_003C80C0 */

#include "vu0.h"
typedef int Q_003C80C0 __attribute__((mode(TI)));
typedef struct { f32 f[4]; } __attribute__((aligned(16))) V_003C80C0;
extern s32 D_L07_001DEF40;
extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));
extern u8 D_L07_001E1EC0[];
void func_L07_003C80C0(char *o) {
    extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
    extern s32 func_L01_003303B8(void *, f32,f32,f32,f32,
        s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
    extern void func_L01_00451FE0(void *,s32,void *,s32,
        f32,f32,f32,f32,f32,f32,f32,f32,s32,s32,s32,s32,s32,s32);
    extern void func_L01_004443E8(void *,s32,s32);
    extern void func_L07_003C86D0(char *);
    extern s32 func_003A52A0(s32,s32,void *);
    extern void func_L01_00446A70(void *,void *,s32,void *,void *,f32);
    extern s32 func_L01_00452860(void *,void *,s32);
    extern void func_L01_00456BD0(void *,s32);
    extern void func_L01_00456C98(void *,s32,s32,s32,s32,s32,s32,s32,f32,f32,f32,s32,s32);
    extern void func_L07_004522E8(void *,s32,void *,f32);
    extern f32 func_L01_0040E548(void *,void *);
    extern void func_L01_004472C0(void *);
    extern void func_003A4F28(s32);
    V_003C80C0 pos;
    s32 sound;
    f32 volume;
    u8 *s = *(u8 **)(o + 0x68);
    if (func_L01_00452FB0(o,s+0x70,0,0,0)) *(s32 *)(s+0x188) &= ~0x10;
    if (*(f32 *)(s+0x30) <= 0.0f) {
        *(Q_003C80C0 *)&pos = *(Q_003C80C0 *)(o+0x10);
        pos.f[2] += *(f32 *)(s+0x40);
        func_L01_003303B8(&pos,0.5f,0.0f,0.0f,2.0f,0,10,5,4,10,15,0,
            0,0,0,0,0,1,0x1010000,0,0x388EF7,0x63F7,0x407FFF,0x20FF,0x8FFF,0x3064FF,0x7F60A0FF,0x280000FF,0x3064FF,0);
        func_L01_00451FE0(o,0x7FFF,D_L07_001D66B0,0xFF,
            3.0f,6.0f,3.0f,6.0f,-1.0f,-1.0f,1.0f,1.0f,180,0,0,35,0,3);
        func_L01_004443E8(o,0,3);
        func_L07_003C86D0(o);
        func_003A52A0(8,0,o);
        return;
    }
    if (*(s32 *)(s+0x228)==1 || *(s32 *)(s+0x228)==11) {
        qzero(&pos);
        func_L01_00446A70(o,o,0x10000,&pos,&pos,(f32)*(s16 *)(s+0x34));
    } else if (s[0x5E] || s[0x60] || s[0x3E]==2) {
        func_L01_004443E8(o,0,3);
        func_L07_003C86D0(o);
        return;
    }
    func_L01_00452860(o,s+0x30,0);
    if (s[0x5F]) {
        func_L01_00456BD0(o,5);
        if ((D_L07_001DEF40&15)==(((s32)o>>8)&15)) {
            func_L01_00456C98(o,((u8)o[0x20]>=8 ? *(s32 *)(s+0x498) : *(s32 *)(s+0x490)),0,0,0,0,3,0,
                ((u8)o[0x20]>=8 ? *(f32 *)(s+0x49C) : *(f32 *)(s+0x494)),10.0f,1.0f,0,0);
        }
    } else {
        func_L01_00456BD0(o,3);
        if ((D_L07_001DEF40&15)==(((s32)o>>8)&15)) {
            func_L01_00456C98(o,((u8)o[0x20]>=8 ? *(s32 *)(s+0x498) : *(s32 *)(s+0x490)),0,0,0,0,1,0,
                ((u8)o[0x20]>=8 ? *(f32 *)(s+0x49C) : *(f32 *)(s+0x494)),10.0f,1.0f,0,0);
        }
    }
    func_L07_004522E8(o,8,s+0x400,2.5f);
    if (*((u8 *)o+0x31) && func_L01_0040E548(D_L07_001E1EC0,o+0x10)<576.0f) {
        func_L01_004472C0(o);
        o[0x6F] = 22;
    }
    if ((u8)o[0x20] >= 24) {
        if (*(s32 *)(s+0x4D8)==-1) *(s32 *)(s+0x4D8) = func_003A52A0(11,4,o);
    } else {
        if (*(s32 *)(s+0x4D8)!=-1) {
            func_003A4F28(*(s32 *)(s+0x4D8));
            *(s32 *)(s+0x4D8)=-1;
        }
    }
}
/* localdecomp:end func_L07_003C80C0 */

/* localdecomp:start func_L07_003C84F8 */
#include "vu0.h"
void func_L07_003C84F8(u8 *obj, void *point) {
    extern f32 func_0038CE68(f32 *, f32 *);
    extern f32 func_0038DB48(f32);
    extern void func_0038D750(void *, s32, f32);
    extern void func_0038D688(void *, void *, void *);
    extern void func_L01_0044E850(void *, void *, s32, f32, f32);
    vu0_v4 delta;
    vu0_v4 rotation;
    u8 *state = *(u8 **)(obj + 0x68);
    vec_sub_ba(&delta, obj + 0x10, point);
    {
        f32 angle = func_0038CE68((f32 *)&delta, (f32 *)(obj + 0xC0));
        angle = func_0038DB48(angle / 0.3f);
        func_0038D750(&rotation, 1, angle);
    }
    func_0038D688(state + 0x3D0, state + 0x3D0, &rotation);
    func_L01_0044E850(obj, state + 0x240, 6, 0.014400000683963299f, 0.4320000410079956f);
    func_L01_0044E850(obj, state + 0x2C0, 3, 0.0432f, 0.4320000410079956f);
    func_L01_0044E850(obj, state + 0x340, 4, 0.0432f, 0.4320000410079956f);
}
/* localdecomp:end func_L07_003C84F8 */

/* localdecomp:start func_L07_003C8608 */
typedef int Q_003C8608 __attribute__((mode(TI)));
typedef struct { u8 pad[0x480]; u8 enabled[0x40]; } Vars_003C8608;
void func_L07_003C8608(u8 *obj, s32 index) {
    extern void func_L07_003BB1A8(void *);
    extern void func_0038CB78(void *, s32, s32);
    extern void func_L01_0043A430(void *, s32, void *);
    extern void func_L07_003C8718(void *, s32);
    extern void func_L07_003C8A10(void *arg0);
    u8 *p = *(u8 **)(obj + 0x68);
    if (((Vars_003C8608 *)p)->enabled[index]) {
        u8 *transform = p + 0x3C0;
        func_L07_003BB1A8(obj);
        *(Q_003C8608 *)(obj + 0x10) = *(Q_003C8608 *)(p + 0x440);
        *(Q_003C8608 *)(obj + 0xF0) = *(Q_003C8608 *)(p + 0x450);
        func_0038CB78(transform, 0, 0x40);
        func_L01_0043A430(obj, 5, transform);
        *(s16 *)(p + 0x4D4) = 0;
        p[0x4DD] = 0;
        if (*(s32 *)(p + 0x4C0) != -1) {
            func_L07_003C8718(obj, 2);
        } else {
            *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) & 0xFFBE) | 0x1000;
            *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
            func_L07_003C8A10(obj);
        }
    }
}
/* localdecomp:end func_L07_003C8608 */

/* localdecomp:start func_L07_003C86D0 */
extern void func_003C2C98(void *, void *);
extern void func_L07_003BB038(void *);
extern void func_L07_003BB1F0(void *);
extern void func_L07_003C8718(void *, s32);

void func_L07_003C86D0(char *obj) {
    func_003C2C98(obj, *(char **)(obj + 0x68) + 0x3C0);
    func_L07_003BB038(obj);
    func_L07_003BB1F0(obj);
    func_L07_003C8718(obj, 1);
}
/* localdecomp:end func_L07_003C86D0 */

/* localdecomp:start func_L07_003C8718 */
void func_L07_003C8718(void *arg0, s32 state) {
    extern void func_003C3A10(void *, s32, s32, s32);
    extern void func_L01_004450F0(void *, s32, s32);
    u8 *obj = arg0;
    switch (state) {
    case 1: case 2: case 3:
        if (obj[0x43] != 0) func_003C3A10(obj, 0, 0, 0);
        break;
    case 4:
        if (obj[0x43] != 0) func_003C3A10(obj, 0, 0, 7);
        break;
    case 5:
        if (obj[0x43] != 0) func_003C3A10(obj, 0, 0, 7);
        break;
    case 6:
        if (obj[0x43] != 0) func_003C3A10(obj, 0, 0, 7);
        break;
    case 9:
        if (obj[0x43] != 1) func_003C3A10(obj, 1, 0, 7);
        break;
    case 13:
        if (obj[0x43] != 0) func_003C3A10(obj, 0, 0, 7);
        break;
    case 14:
        if (obj[0x43] != 5) func_003C3A10(obj, 5, 0, 7);
        break;
    case 15:
        if (obj[0x43] != 6) func_003C3A10(obj, 6, 0, 7);
        break;
    case 16:
        if (obj[0x43] != 7) func_003C3A10(obj, 7, 0, 7);
        break;
    case 17:
        if (obj[0x43] != 8) func_003C3A10(obj, 8, 0, 7);
        break;
    case 18:
        if (obj[0x43] != 9) func_003C3A10(obj, 9, 0, 7);
        break;
    case 19:
        if (obj[0x43] != 10) func_003C3A10(obj, 10, 0, 7);
        break;
    case 20:
        if (obj[0x43] != 11) func_003C3A10(obj, 11, 0, 7);
        break;
    case 21:
        if (obj[0x43] != 12) func_003C3A10(obj, 12, 0, 7);
        break;
    case 22:
        if (obj[0x43] != 14) func_003C3A10(obj, 14, 0, 7);
        break;
    case 7: case 10: case 11: case 12: case 23:
        if (obj[0x43] != 3) func_003C3A10(obj, 3, 0, 7);
        break;
    case 24: case 25:
        if (obj[0x43] != 13) func_003C3A10(obj, 13, 0, 7);
        *(f32 *)(obj + 0x48) = 0.15f;
        break;
    case 26:
        if (obj[0x43] != 11) func_003C3A10(obj, 11, 0, 25);
        break;
    case 8: break;
    }
    func_L01_004450F0(obj, state, -1);
}
/* localdecomp:end func_L07_003C8718 */

/* localdecomp:start func_L07_003C8960 */
extern s32 D_L07_001DF41C;
s32 func_L07_003BAC58();
s32 func_L07_003BADA8();

s32 func_L07_003C8960(void *arg0) {
    u8 *p;
    s32 a;

    p = *(u8 **)((u8 *)arg0 + 0x68);
    if (*(s16 *)(p + 0x144) != 1) {
        return 0;
    }
    a = *(s32 *)(p + 0x4A0);
    if (a != -1) {
        if (func_L07_003BAC58(D_L07_001DF41C + (a << 8)) == 0) {
            return 0;
        }
    }
    a = *(s32 *)(p + 0x4A4);
    if (a != -1) {
        if (func_L07_003BADA8() == 0) {
            return 0;
        }
    }
    if (*(s32 *)(p + 0x4B8) != -1 && *(s32 *)(p + 0x4B0) != -1) {
        if (*((u8 *)arg0 + 0x31) == 0) {
            return 0;
        }
    }
    return 1;
}
/* localdecomp:end func_L07_003C8960 */

/* localdecomp:start func_L07_003C8A10 */
s32 func_L07_003C8960(void *);
void func_L07_003C8718(void *, s32);
void func_L07_003C8A88(void *);
void func_L07_003C8B18(void *);

void func_L07_003C8A10(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);

    if (*(s32 *)(p + 0x4B8) == -1 && *(s32 *)(p + 0x4B0) == -1) {
        if (func_L07_003C8960(arg0)) {
            func_L07_003C8B18(arg0);
        } else {
            func_L07_003C8A88(arg0);
        }
    } else {
        func_L07_003C8718(arg0, 7);
    }
}
/* localdecomp:end func_L07_003C8A10 */

/* localdecomp:start func_L07_003C8A88 */
void func_L07_003C8718(void *, s32);

void func_L07_003C8A88(void *arg0) {
    if ((*(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x4a8)) != -1) {
        func_L07_003C8718(arg0, 4);
        return;
    }
    func_L07_003C8718(arg0, 0x5);
}
/* localdecomp:end func_L07_003C8A88 */

/* localdecomp:start func_L07_003C8AD0 */
void func_L07_003C8718(void *, s32);
void func_L07_003C8A88_003C8AD0(void *, void *);

void func_L07_003C8AD0(void *arg0) {
    if ((*(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x4AC)) != -1) {
        func_L07_003C8718(arg0, 0x6);
        return;
    }
    func_L07_003C8A88_003C8AD0(arg0, arg0);
}
/* localdecomp:end func_L07_003C8AD0 */

/* localdecomp:start func_L07_003C8B18 */
void func_L07_003C8718(void *, s32);
void func_L07_003C8B60(void *, void *);

void func_L07_003C8B18(void *arg0) {
    if ((*(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x4AC)) != -1) {
        func_L07_003C8718(arg0, 0xA);
        return;
    }
    func_L07_003C8B60(arg0, arg0);
}
/* localdecomp:end func_L07_003C8B18 */

/* localdecomp:start func_L07_003C8B60 */
void func_L07_003C8B60(void *arg0, void *arg1) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);

    if (p[0x4D6] != 0) {
        func_L07_003C8718(arg0, 0xC);
        return;
    }
    func_L07_003C8718(arg0, 0xB);
}
/* localdecomp:end func_L07_003C8B60 */

/* localdecomp:start func_L07_003C8BA0 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_003C8BA0;
void func_L07_003C8BA0(u8 *obj)
{
    extern f32 func_0038CE68(f32 *, f32 *);
    Vec_003C8BA0 delta;
    u8 *p = *(u8 **)(obj + 0x68);
    p[0x4D7] = 0;
    __asm__ (
        "lqc2 $vf1, 0x130(%1)\n"
        "lqc2 $vf2, 0x10(%2)\n"
        "vsub.xyz $vf2, $vf2, $vf1\n"
        "sqc2 $vf2, %0\n"
        : "=m" (delta) : "r" (p), "r" (obj) : "vf1", "vf2", "memory");
    if (func_0038CE68(&delta.x, (f32 *)(obj + 0xD0)) >= 0.0f) {
        p[0x4DC] = 1;
        func_L07_003C8718(obj, 0x12);
    } else {
        p[0x4DC] = 0;
        func_L07_003C8718(obj, 0xE);
    }
}
/* localdecomp:end func_L07_003C8BA0 */

/* localdecomp:start func_L07_003C8C30 */
void func_L07_003BB038(void *);
void func_L07_003C8718(void *, s32);
void func_L07_003C8B60_003C8C30(void *) __asm__("func_L07_003C8B60");

void func_L07_003C8C30(void *arg0) {
    u8 *h = *(u8 **)((u8 *)arg0 + 0x68);

    func_L07_003BB038(arg0);
    *(s16 *)(h + 0x4D4) = 0x25;
    if (h[0x4D7] != 0) {
        func_L07_003C8718(arg0, 0x16);
    } else {
        func_L07_003C8B60_003C8C30(arg0);
    }
}
/* localdecomp:end func_L07_003C8C30 */

/* localdecomp:start func_L07_003C8C90 */
void func_L07_003C8718(void *, s32);

void func_L07_003C8C90(unsigned char *a0)
{
    unsigned char *s = *(unsigned char **)(a0 + 0x68);

    if (*(s32 *)(s + 0x4B8) != -1) {
        func_L07_003C8718(a0, 0x17);
        return;
    }
    if (*(s32 *)(s + 0x4B0) == *(s32 *)(s + 0x4B8)) {
        return;
    }
    if (*(s32 *)(s + 0x4B4) != *(s32 *)(s + 0x4B8)) {
        *(u8 *)(s + 0x4DC) = 1;
        func_L07_003C8718(a0, 0x1A);
    } else {
        func_L07_003C8718(a0, 0x19);
    }
}
/* localdecomp:end func_L07_003C8C90 */

/* localdecomp:start func_L07_003C8CF8 */
typedef struct Pvar_003C8CF8 {
    u8 pad_0[0x130];
    Vec4f origin;
} Pvar_003C8CF8;
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0045A748(f32 *, f32 *);

void func_L07_003C8CF8(struct Moby *obj, f32 distance) {
    Vec4f delta __attribute__((aligned(16)));
    Pvar_003C8CF8 *p = obj->pvar;
    vec_sub_ab(&delta, &obj->position, &p->origin);
    func_0038CF68(&delta, &delta, distance);
    vec_add_ab(&delta, &p->origin, &delta);
    func_L01_0045A748((f32 *)obj, (f32 *)&delta);
}
/* localdecomp:end func_L07_003C8CF8 */

/* localdecomp:start func_L07_003C8D60 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003C8D60;
extern V_003C8D60 D_L07_001E8C20;
void func_L07_003C8D60(u8 *obj) {
    extern void func_003CA4A0(void *, s32, s32 *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038D000(void *, void *, void *);
    extern f32 func_0038CF38(void *, void *);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038DB00(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
    V_003C8D60 matrix[4] __attribute__((aligned(16)));
    V_003C8D60 origin __attribute__((aligned(16)));
    V_003C8D60 forward __attribute__((aligned(16)));
    V_003C8D60 destination __attribute__((aligned(16)));
    V_003C8D60 delta __attribute__((aligned(16)));
    V_003C8D60 endpoint __attribute__((aligned(16)));
    s32 joint;
    u8 *state=*(u8 **)(obj+0x68);
    f32 scale=*(f32 *)(obj+0x2C)*0.0009765625f;
    f32 distance, target_angle, facing, turn;
    joint=state[0x4DC]+3;
    func_003CA4A0(obj,1,&joint,matrix);
    func_0038CE20(&origin,&matrix[3],scale);
    func_0038D000(&origin,&origin,obj+0xC0);
    vec_add_ab(&origin,&origin,obj+0x10);
    distance=func_0038CF38(&origin,state+0x130);
    if(distance>*(f32 *)(state+0x4D0)) distance=*(f32 *)(state+0x4D0);
    else if(distance<*(f32 *)(state+0x4CC)) distance=*(f32 *)(state+0x4CC);
    target_angle=func_0038D160(*(f32 *)(state+0x130)-origin.x,*(f32 *)(state+0x134)-origin.y);
    func_0038D000(&forward,&matrix[1],obj+0xC0);
    facing=func_0038D160(forward.x,forward.y);
    if(state[0x4DC]==1) facing=func_0038DAB8(facing,3.1415927410125732f);
    turn=func_0038DB00(target_angle,facing);
    if(turn>0.2617993950843811f) turn=0.2617993950843811f;
    else if(turn<-0.2617993950843811f) turn=-0.2617993950843811f;
    target_angle=func_0038DAB8(facing,turn);
    destination.x=func_0038D098(target_angle)*(distance+1.0f);
    destination.y=func_0038D0B0(target_angle)*(distance+1.0f);
    destination.z=0;
    vec_add_ab(&destination,&origin,&destination);
    {
        f32 z=*(f32 *)(state+0x138)-0.3f;
        if(origin.z<z) z=origin.z;
        destination.z=z;
    }
    vec_sub_ab(&delta,&destination,&origin);
    func_0038CF68(&delta,&delta,20.0f);
    vec_add_ab(&endpoint,&origin,&delta);
    if(func_003D3CB0(&origin,&endpoint,2,0,0)) {
        *(V_003C8D60 *)(state+0x470)=D_L07_001E8C20;
    }else {
        *(V_003C8D60 *)(state+0x470)=endpoint;
    }
}
/* localdecomp:end func_L07_003C8D60 */

/* localdecomp:start func_L07_003C8FF8 */
extern f32 func_L01_0040E570(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);

void func_L07_003C8FF8(u8 *a0, u8 *a1, f32 ang) {
    u8 *p = *(u8 **)(a0 + 0x68);

    if (func_L01_0040E570(a1, a0 + 0x10) > 0.0001f) {
        f32 a = func_0038D160(*(f32 *)(a0 + 0x10) - *(f32 *)a1,
                              *(f32 *)(a0 + 0x14) - *(f32 *)(a1 + 4));

        if (func_0038DBA0(ang, a) > 1.5707964f) {
            a = func_0038DAB8(a, 3.1415927f);
        }
        func_L01_00448890(a0 + 0xF8, p + 0x204, 0, a, *(f32 *)(p + 0x164),
                      *(f32 *)(p + 0x168), *(f32 *)(p + 0x16C));
    }
}
/* localdecomp:end func_L07_003C8FF8 */

/* localdecomp:start func_L07_003C90F8 */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);

void func_L07_003C90F8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 t = func_0038DAB8(*(f32 *)(p + 0x4C8), 0.06283186f);

    *(f32 *)(p + 0x4C8) = t;
    t = func_0038DB00(t, *(f32 *)(a0 + 0xF8));
    *(f32 *)(p + 0x288) = t;
    *(f32 *)(p + 0x2A8) = t;
}
/* localdecomp:end func_L07_003C90F8 */

/* localdecomp:start func_L07_003C9150 */
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);

void func_L07_003C9150(u8 *a0, u8 *a1) {
    u8 *q = *(u8 **)(a0 + 0x68);
    f32 v = func_0038D160(*(f32 *)(a1 + 0) - *(f32 *)(a0 + 0x10),
                          *(f32 *)(a1 + 4) - *(f32 *)(a0 + 0x14));
    *(f32 *)(q + 0x2A8) = func_0038DB00(v, *(f32 *)(a0 + 0xF8));
}
/* localdecomp:end func_L07_003C9150 */

/* localdecomp:start func_L07_003C91A8 */
extern void func_003C2F58(u8 *a, s32 b, f32 *out);
extern f32 func_0038D160(f32 x, f32 y);
extern f32 func_0038DB48(f32 a);

void func_L07_003C91A8(u8 *arg0, f32 *arg1) {
    u8 *p;
    u8 *q1;
    u8 *q2;
    f32 v[4];
    f32 d;

    p = *(u8 **)(arg0 + 0x68);
    func_003C2F58(arg0, p[0x4DC] + 3, v);
    d = func_0038D160(arg1[0] - v[0], arg1[1] - v[1]);
    d = func_0038DB48((d - *(f32 *)(p + 0x288)) - *(f32 *)(arg0 + 0xF8));
    q1 = p + p[0x4DC] * 128;
    *(f32 *)(q1 + 0x328) = d;
    q2 = p + p[0x4DC] * 128;
    d = *(f32 *)(q2 + 0x328);
    if (d > 0.87266463f) {
        *(f32 *)(q2 + 0x328) = 0.87266463f;
    } else if (d < -0.87266463f) {
        *(f32 *)(q2 + 0x328) = -0.87266463f;
    }
}
/* localdecomp:end func_L07_003C91A8 */
