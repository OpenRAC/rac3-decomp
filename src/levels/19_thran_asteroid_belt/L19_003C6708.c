#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L19_003C6708 */
typedef struct { u8 pad0[0x24]; u8 *f24; u8 pad28[0xC]; u16 f34; u8 pad36[0x32]; u8 *f68; u8 pad6C[0x2C]; s32 f98; u8 pad9C[0x64]; } M_003C6708;

typedef struct { u8 pad0[0x30]; f32 x30, x34, x38; u8 pad3C[0x44]; } P_003C6708;

typedef struct {
    s32 f00;
    s32 f04;
    s32 f08;
    s32 f0C;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
    s32 f3C;
    struct { f32 x, y, z; } *marker;
    s16 f44;
    s16 f46;
    s32 f48;
    s32 f4C;
} V_003C6708;

extern s32 D_L19_001D66D4;
extern s32 D_L19_001D66D0;
extern s32 D_L19_001E6470[];
extern u8 *D_L19_001DF71C_003C6708;
extern u8 *D_L19_001DF800_003C6708;
extern u8 D_001A4C60[];
extern u8 D_001A4BE0[];
extern u8 D_0014270B[];
extern u8 D_0014270C[];
extern u8 D_001A71C4[];
extern u32 D_00142C54[];
extern s32 D_001A8000[];
extern s32 D_001D545C;
extern u8 D_001BBC40[];
extern u8 D_L19_001E2080[];
extern u16 D_L19_001DF42C[] __attribute__((section(".sdata")));
extern s16 *D_L19_0021C260[];
extern s32 D_L19_001DF758;
extern f32 D_L19_001DF050;
__asm__(".extern D_L19_001DEA34, 4");
__asm__(".extern D_L19_001DEA38, 4");
__asm__(".extern D_L19_001DEA3C, 4");
__asm__(".extern D_L19_001DEA40, 4");
__asm__(".extern D_L19_001DEA44, 4");
extern f32 D_L19_001DEA34;
extern f32 D_L19_001DEA38;
extern f32 D_L19_001DEA3C;
extern f32 D_L19_001DEA40;
extern s32 D_L19_001DEA44;

extern s32 func_L01_0044C108(void *);
extern void func_003C2880(void *);
extern void func_L19_003C6F18(); /* defined later in this file with an H_6F18 * parameter */
extern s32 func_00382380(void *, s32, s32);
extern void func_0039EF28(void);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L19_003C6F30(void *);
extern void func_L19_003BED90(void *, void *, void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L01_0041A5B0(s32, s32);
extern void *func_L01_003F2A50(s32, s32);
extern void func_L16_00402D30(s32, void *);
extern void func_L01_003F2AF8(s32, void *);
extern s32 func_L01_00456250(void *);
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern void func_L01_003EB350(s32, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern void func_L01_003EB3C0(s32, void *);
extern void func_L01_003EB5E0(s32, s32);
extern void func_L01_00511A40(void *, s32, f32);
extern f32 func_003C4138(void *, f32, f32);
extern void func_L01_0043B510(s32);
extern void func_L19_003C7058(void *);

void func_L19_003C6708(u8 *o) {
    vu0_v4 sum;
    vu0_v4 rot;
    V_003C6708 *v;
    u8 *m;
    u8 *p;
    s16 *list;
    f32 count;
    s32 all;

    v = *(V_003C6708 **)(o + 0x68);
    if (!func_L01_0044C108(o + 0x10)) {
        return;
    }
    if ((u32)(D_L19_001D66D4 - 1) < 2 || D_L19_001D66D0 == 1 || D_L19_001D66D0 == 2) {
        if (D_L19_001E6470[0] == 1) {
            m = D_L19_001DF71C_003C6708 + (v->f4C << 8);
            if (m) {
                func_003C2880(m);
            }
        }
        return;
    }
    switch (o[0x20]) {
    case 0:
        func_L19_003C6F18(o);
        func_L01_004450F0(o, 1, -1);
        break;
    case 1:
        if (func_00382380(D_001A4C60, v->f14, 0) || D_001A4C60[0x2564] == 1) {
            D_0014270B[0] = 1;
            func_0039EF28();
            func_L01_004450F0(o, 2, -1);
        }
        break;
    case 2:
        if (D_001A71C4[0] != 1) {
            func_L19_003C6F30(o);
        }
        func_L19_003BED90(D_L19_001DF71C_003C6708 + (v->f04 << 8), D_L19_001DF800_003C6708 + (v->f0C << 7) + 0x30, D_L19_001DF800_003C6708 + (v->f0C << 7) + 0x70);
        func_L01_004450F0(o, 3, -1);
        break;
    case 3:
        if (D_00142C54[0] & 0x800000) {
            if ((*(unsigned long *)((u8 *)&((M_003C6708 *)D_L19_001DF71C_003C6708)[v->f04] + 0x30) & ((unsigned long)0x8208 << 29)) == ((unsigned long)0x8200 << 23)
                && ((M_003C6708 *)D_L19_001DF71C_003C6708)[v->f04].f98 == 0) {
                ((M_003C6708 *)D_L19_001DF71C_003C6708)[v->f04].f34 &= 0xFFBE;
                ((M_003C6708 *)D_L19_001DF71C_003C6708)[v->f04].f34 |= *(u16 *)(((M_003C6708 *)D_L19_001DF71C_003C6708)[v->f04].f24 + 0x44) & 0x1000;
                ((M_003C6708 *)D_L19_001DF71C_003C6708)[v->f04].f98 = *(s32 *)(((M_003C6708 *)D_L19_001DF71C_003C6708)[v->f04].f24 + 0x10);
                ((M_003C6708 *)D_L19_001DF71C_003C6708)[v->f04].f34 &= 0xFFFD;
            }
            m = D_L19_001DF71C_003C6708 + (v->f4C << 8);
            if (m && m[0x20] != 0xFE && m[0x20] != 0xFD) {
                func_003C2880(m);
            }
        } else {
            if ((*(unsigned long *)((u8 *)&((M_003C6708 *)D_L19_001DF71C_003C6708)[v->f04] + 0x30) & ((unsigned long)0x8208 << 29)) != ((unsigned long)0x8200 << 23)
                || ((M_003C6708 *)D_L19_001DF71C_003C6708)[v->f04].f98 != 0) {
                ((M_003C6708 *)D_L19_001DF71C_003C6708)[v->f04].f34 |= 0x41;
                ((M_003C6708 *)D_L19_001DF71C_003C6708)[v->f04].f34 &= 0xEFFF;
                ((M_003C6708 *)D_L19_001DF71C_003C6708)[v->f04].f98 = 0;
                func_L01_004AA7E8(&((M_003C6708 *)D_L19_001DF71C_003C6708)[v->f04], 1);
                ((M_003C6708 *)D_L19_001DF71C_003C6708)[v->f04].f34 |= 2;
            }
        }
        if (func_00382380(D_001A4C60, v->f38, 0)) {
            if (++v->f46 > 1000) {
                if (D_001A8000[0] >= 0) {
                    func_L01_0041A5B0(0xB85, 0x28);
                }
                v->f46 = 0;
            }
            if (v->marker == 0) {
                v->marker = func_L01_003F2A50(0, 5);
            }
            if (v->marker != 0) {
                v->marker->z = D_L19_001DEA34;
                v->marker->y = D_L19_001DEA38;
                v->marker->x = D_L19_001DEA3C;
                func_L16_00402D30(0, v->marker);
            }
        } else if (v->marker) {
            func_L01_003F2AF8(0, v->marker);
            v->marker = 0;
        }
        if (func_00382380(D_001A4C60, v->f3C, 0)) {
            *(f32 *)(D_001A4C60 + 0x19DC) = D_L19_001DEA40;
        } else {
            *(f32 *)(D_001A4C60 + 0x19DC) = 0.0f;
        }
        *(s32 *)(((M_003C6708 *)D_L19_001DF71C_003C6708)[v->f28].f68 + 0xC) = func_L01_00456250(D_L19_001DF71C_003C6708 + (v->f2C << 8));
        D_L19_001DF42C[0]++;
        if (v->f24 >= 0 && func_00382380(D_001A4C60, v->f24, 0)) {
            if (!D_L19_001DEA44) {
                if (++v->f44 > 25) {
                    func_L01_003EB438(0, D_L19_001E2080, D_L19_001E2080 + 0x10, 0, 0, 0);
                    func_L01_003EB350(0, D_L19_001DF800_003C6708 + (v->f34 << 7) + 0x30);
                    D_L19_001DEA44 = 1;
                    v->f24 = -1;
                }
            } else {
                v->f30 = -1;
                v->f24 = -1;
            }
        }
        if (D_L19_001DEA44 && v->f30 >= 0) {
            qzero(&sum);
            count = 0.0f;
            all = 1;
            list = D_L19_0021C260[v->f30];
            while ((v->f30 & 0xFF) != 0xFF && v->f30 <= D_L19_001DF758 && list
                   && (list[-1] >= 0 || list == D_L19_0021C260[v->f30])) {
                u8 *e = D_L19_001DF71C_003C6708 + ((*(u16 *)list & 0x7FFF) << 8);
                if (!e) {
                    break;
                }
                vec_add_ab(&sum, &sum, e + 0x10);
                count += 1.0f;
                list++;
                if (e[0x20] != 2) {
                    all = 0;
                }
            }
            func_0038CE20(&sum, &sum, 1.0f / count);
            rot.x = 0.0f;
            rot.y = -func_0038D160(func_0038CF38(D_L19_001DF800_003C6708 + (v->f34 << 7) + 0x30, &sum),
                                   sum.z - ((P_003C6708 *)D_L19_001DF800_003C6708)[v->f34].x38);
            rot.z = func_0038D160(sum.x - ((P_003C6708 *)D_L19_001DF800_003C6708)[v->f34].x30, sum.y - ((P_003C6708 *)D_L19_001DF800_003C6708)[v->f34].x34);
            func_L01_003EB3C0(0, &rot);
            if (all) {
                u8 *hero = D_001A4BE0;
                *(f32 *)(hero + 0x98) = func_0038D160(sum.x - *(f32 *)(hero + 0x80), sum.y - *(f32 *)(hero + 0x84));
                func_L01_003EB5E0(0, 2);
                v->f30 = -1;
            }
        }
        if (func_L01_00456250(D_L19_001DF71C_003C6708 + (v->f20 << 8))) {
            func_L01_004450F0(o, 4, -1);
        }
        if ((D_001BBC40[v->f10 + (D_001D545C << 4)] & 0x80) && func_00382380(D_001A4C60, v->f18, 0)) {
            func_L01_004450F0(o, 4, -1);
        }
        break;
    case 4:
        if (*(u16 *)(o + 0x96) == 50) {
            func_L01_00511A40(D_L19_001DF800_003C6708 + (v->f48 << 7) + 0x30, 0, *(f32 *)(D_L19_001DF800_003C6708 + (v->f48 << 7) + 0x78));
        }
        if (*(u16 *)(o + 0x96) >= 101) {
            func_003C4138(&D_L19_001DF050, 1.0f, 0.35f);
        }
        if (*(u16 *)(o + 0x96) >= 151) {
            func_L01_0043B510(v->f10);
            D_0014270C[0] = 1;
            func_0039EF28();
            func_L19_003C7058(o);
            func_L01_004450F0(o, 1, -1);
        }
        break;
    }
    if (*(u16 *)(o + 0x96) < 0xFFFF) {
        ++*(u16 *)(o + 0x96);
    }
}
/* localdecomp:end func_L19_003C6708 */

/* localdecomp:start func_L19_003C6F18 */
typedef struct { u8 pad[0x40]; s32 f40; s16 f44; s16 f46; } S_6F18;
typedef struct { u8 pad[0x68]; S_6F18 *f68; } H_6F18;

void func_L19_003C6F18(H_6F18 *a0) {
    S_6F18 *p = a0->f68;
    p->f40 = 0;
    p->f44 = 0;
    p->f46 = 0;
}
/* localdecomp:end func_L19_003C6F18 */

/* localdecomp:start func_L19_003C6F30 */
#include "vu0.h"

s32 func_L01_004F50C8_003C6F30(s32, s32, s32, s32);  /* extern */
extern s32 D_L19_001DF800_003C6F30;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
__asm__(".extern D_L19_001DF71C_003C6F30, 16");
extern u8 *D_L19_001DF71C_003C6F30;
extern void func_L01_004ED3F8_003C6F30(s32, s32, void *);
extern void func_L01_00456230_003C6F30(void *, s32);
extern void func_L01_00511A40_003C6F30(void *, s32, f32);
extern u32 D_00142C54[];
extern s32 D_L19_001DBC94_003C6F30;

void func_L19_003C6F30(void *arg0) {
    s32 *p = *(s32 **)((u8 *)arg0 + 0x68);
    s32 b;
    u32 m;
    vu0_v4 v;

    func_L01_004ED3F8_003C6F30(1, 0x3F, D_L19_001DF71C_003C6F30 + (p[0] << 8));
    b = D_L19_001DF800_003C6F30 + (p[2] << 7);
    func_L01_004F50C8_003C6F30(b + 0x30, b + 0x70, -1, 1);
    func_L01_00456230_003C6F30(D_L19_001DF71C_003C6F30 + (p[8] << 8), 0);
    v.x = func_0038D098(*(f32 *)((p[2] << 7) + D_L19_001DF800_003C6F30 + 0x78));
    v.y = func_0038D0B0(*(f32 *)((p[2] << 7) + D_L19_001DF800_003C6F30 + 0x78));
    v.z = 0;
    vec_add_ab(&v, &v, (void *)((p[2] << 7) + D_L19_001DF800_003C6F30 + 0x30));
    func_L01_00511A40_003C6F30(&v, 1, *(f32 *)((p[2] << 7) + D_L19_001DF800_003C6F30 + 0x78));
    m = D_00142C54[0] & 0x800000;
    D_L19_001DBC94_003C6F30 = m != 0;
}
/* localdecomp:end func_L19_003C6F30 */

/* localdecomp:start func_L19_003C7058 */
/* m2c3 */
s32 func_L01_0042B068(s32, s32);            /* extern */
s32 func_L01_004ED658(s32);                     /* extern */
s32 func_L01_004F50C8(s32, s32, s32, s32);  /* extern */
s32 func_L01_00504E38(s32);                     /* extern */
extern s32 D_001DF800;

void func_L19_003C7058(void *arg0) {
    s32 temp_4;
    void *temp_16;

    temp_16 = (*(void **)((u8 *)(arg0) + 0x68));
    func_L01_004ED658(0);
    func_L01_0042B068(0, 0);
    temp_4 = D_001DF800 + ((*(s32 *)((u8 *)(temp_16) + 0x1C)) << 7);
    func_L01_004F50C8(temp_4 + 0x30, temp_4 + 0x70, -1, 1);
    func_L01_00504E38(0);
}
/* localdecomp:end func_L19_003C7058 */

/* localdecomp:start func_L19_003C70C0 */
typedef struct {
    u8 pad0[0x70];
    f32 f70;
    f32 f74;
    s32 w78;
    s32 w7C;
    f32 f80;
    s32 w84;
    s32 w88;
    s32 w8C;
} S_3C70C0;
typedef struct {
    u8 pad0[0x20];
    f32 f20;
    u8 pad24[4];
    s32 w28;
    s32 w2C;
} G_3C70C0;
extern s32 func_L01_0044C108(void *);
extern s32 func_L01_004561B8(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038CAD0(void *);
extern void func_003A52A0(s32, s32, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_00439880(void *, u16 *, s32 *);
extern u8 *func_L01_003F79D8(void *, s32, s32, s32, void *, void *, void *, s32, f32, f32, s32, s32, s32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_L13_0044DB78(void *, s32, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern u8 *func_L01_0046ADE0(void *, void *, f32);
extern f32 func_003C41A0(void *, void *, f32, f32, f32, f32);
extern void func_003C4DA8(void *, void *, void *, void *);
extern void func_L19_003D6240(u8 *);
extern u8 D_001A4C60[];
extern s32 D_001A4F3C[];
extern u8 D_001D66F0[8];
extern s32 D_L19_001DF240;
extern f32 D_L19_001E8E68[];
extern G_3C70C0 D_L19_001E2100;
__asm__(".extern D_L19_001DEA48, 4");
__asm__(".extern D_L19_001DEA4C, 4");
__asm__(".extern D_L19_001DEA50, 4");
__asm__(".extern D_L19_001DEA54, 4");
__asm__(".extern D_L19_001DEA58, 4");
__asm__(".extern D_L19_001DEA5C, 4");
__asm__(".extern D_L19_001DEA60, 4");
__asm__(".extern D_L19_001DEA64, 4");
__asm__(".extern D_L19_001DEA68, 4");
__asm__(".extern D_L19_001DEA6C, 4");
extern f32 D_L19_001DEA48;
extern f32 D_L19_001DEA4C;
extern f32 D_L19_001DEA50;
extern f32 D_L19_001DEA54;
extern f32 D_L19_001DEA58;
extern f32 D_L19_001DEA5C;
extern s32 D_L19_001DEA60;
extern f32 D_L19_001DEA64;
extern f32 D_L19_001DEA68;
extern s32 D_L19_001DEA6C;

void func_L19_003C70C0(u8 *m) {
    vu0_v4 pos;
    vu0_v4 d;
    vu0_v4 a;
    vu0_v4 b;
    u16 cnt;
    s32 n;
    S_3C70C0 *s;
    G_3C70C0 *g;
    u8 *r;
    s32 below;
    s32 i;
    s32 j;
    s32 k;
    s32 hit;
    s32 prev;
    s32 r2;
    f32 ang;
    f32 rad;
    f32 sc;
    f32 rnd;

    if (func_L01_0044C108(m + 0x10) == 0) {
        return;
    }
    *(vu0_q *)&pos = *(vu0_q *)(m + 0x10);
    s = *(S_3C70C0 **)(m + 0x68);
    switch (m[0x20]) {
    case 0:
        s->w84 = -1;
        s->f70 = 0.0f;
        s->w88 = 0;
        *(f32 *)(m + 0xF8) = func_00382538();
        *(s16 *)(m + 0x7C) = 0;
        s->w7C = (s->w7C * 5 + 2) / 6;
        if (s->w78 >= 0) {
            func_L01_004450F0(m, 1, -1);
        } else {
            func_L01_004450F0(m, 2, -1);
        }
        break;
    case 1:
        if (func_L01_004561B8(m) != 0) {
            *(vu0_q *)&a = *(vu0_q *)(m + 0x10);
            *(s16 *)(m + 0x7C) = 0xFF;
            *(vu0_q *)&d = *(vu0_q *)(m + 0x10);
            a.z = a.z + 100.0f;
            if (func_003D3CB0(&d, &a, 2, m, 0) != 0) {
                *(f32 *)(m + 0x18) = D_L19_001E8E68[0] + D_L19_001DEA54;
            }
        }
        if (s->w88 == 0) {
            if (s->w84 < 0) {
                if ((D_L19_001DF240 & 7) == (((s32)m >> 8) & 7)) {
                    if (func_00382380(D_001A4C60, s->w78, 0) != 0) {
                        s->w84 = s->w7C;
                        g = &D_L19_001E2100;
                        if (g->w28 < s->w84) {
                            g->f20 = D_L19_001DEA68;
                            g->w28 = s->w84;
                            g->w2C = 0;
                        }
                    }
                }
            }
            if (s->w84 > 0) {
                func_L01_00439880(m, &cnt, &n);
                for (i = 0; i < n; i++) {
                    if (s->w84 - 1 == s->w7C * i / n) {
                        r = func_L01_003F79D8(m, 1, *(s16 *)(m + 0xAA), i, m + 0x10, m + 0xF0, D_001D66F0, 0xFF, 0.0f, 10.0f, 0xB4, 0, 0x80);
                        *(void (**)(u8 *))(r + 0x64) = func_L19_003D6240;
                        *(u16 *)(m + 0x7C) = *(u16 *)(m + 0x7C) & ~(1 << i);
                    }
                }
                j = 0;
                while (j < D_L19_001DEA6C) {
                    j++;
                    rnd = func_00382538();
                    func_00382760(&d, 1.0f, rnd, func_00382538());
                    vec_add_ab(&d, &d, m + 0x10);
                    qzero(&a);
                    a.z = -0.020000001f;
                    a.w = 1.0f;
                    func_L13_0044DB78(&d, 0, &a, 10.0f);
                }
                func_0038CAD0(&s->w84);
            }
            if (s->w84 == 0) {
                func_003A52A0(0, 0, m);
                s->w88 = 1;
                s->f80 = s->f74 - D_L19_001DEA48;
            }
        } else {
            hit = *(f32 *)(m + 0x18) + D_L19_001DEA58 < s->f74;
            func_003C41A0(m + 0x18, (u8 *)s + 0x70, s->f80, 0.004f, 0.008f, 2.0000002f);
            below = *(f32 *)(m + 0x18) + D_L19_001DEA58 < s->f74;
            if (below != 0) {
                if (hit == 0) {
                    func_003A52A0(1, 0, m);
                }
                for (k = 0; k < D_L19_001DEA60; k++) {
                    ang = func_00382538();
                    rad = func_003824E0(D_L19_001DEA64 * 0.5f, D_L19_001DEA64);
                    d.x = func_0038D098(ang) * rad;
                    d.y = func_0038D0B0(ang) * rad;
                    d.z = 0.0f;
                    vec_add_ab(&d, &d, m + 0x10);
                    d.z = s->f74;
                    ang = ang + func_003824E0(-0.17453292f, 0.17453292f);
                    sc = -s->f70 * func_003824E0(0.2f, 0.5f);
                    a.x = func_0038D098(ang) * sc;
                    a.y = func_0038D0B0(ang) * sc;
                    a.z = 0.0f;
                    a.z = -s->f70 * func_003824E0(0.2f, 0.5f);
                    a.w = 0.5f;
                    func_0038CE20(&b, &a, 0.5f);
                    b.z = 0.0f;
                    b.w = 0.75f;
                    r = func_L01_0046ADE0(&d, &a, func_003824E0(0.25f, 0.75f));
                    if (r != 0) {
                        *(s32 *)(r + 4) = 0x50908080;
                    }
                }
            }
            if (fabs_asm(*(f32 *)(m + 0x18) - s->f80) < 0.0001f) {
                func_L01_004450F0(m, 2, -1);
            }
        }
        break;
    case 2:
        prev = s->w8C;
        s->w8C = D_001A4F3C[0] == (s32)m;
        prev = prev != 0;
        r2 = func_L01_004561B8(m);
        if (r2 != 0 || s->w8C != prev || fabs_asm(*(f32 *)(m + 0x18) - s->f80) < 0.0001f) {
            s->f80 = s->f74 - (s->w8C != 0 ? D_L19_001DEA4C : D_L19_001DEA48);
            s->f80 = s->f80 + func_003824E0(-D_L19_001DEA50, D_L19_001DEA50);
        }
        func_003C41A0(m + 0x18, (u8 *)s + 0x70, s->f80, 0.00012000001f, 0.00012000001f, 0.20000002f);
        if (*(f32 *)(m + 0x18) < s->f80 - D_L19_001DEA5C) {
            if (s->f70 < 0.0f) {
                s->f70 = 0.0f;
            }
        }
        break;
    }
    vec_sub_ab(&d, m + 0x10, &pos);
    func_003C4DA8((u8 *)s + 0x30, &d, m + 0xF0, m + 0xF0);
}
/* localdecomp:end func_L19_003C70C0 */
