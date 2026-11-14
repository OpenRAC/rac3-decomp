#include "common.h"

typedef struct {
    u8 pad0[0x1C];
    u8 *f1C;
    u8 pad20[0x38];
    s32 f58;
    u8 pad5C[0x24];
} E_005F2FF8;

/* localdecomp:start func_L39_005F2FF8 */
extern E_005F2FF8 D_L39_001FE0E0[];
extern void func_L39_005F3088(s32);

void func_L39_005F2FF8(u8 *a0, s32 a1) {
    E_005F2FF8 *e;
    s32 i;

    if (a0 != 0) {
        e = D_L39_001FE0E0;
        for (i = 0; i < 52; i++) {
            if (a0 == e->f1C) {
                if (a1 == 0 || (e->f58 & 4)) {
                    func_L39_005F3088(i);
                }
            }
            e++;
        }
        a0[0x6D] = 0xFF;
    }
}
/* localdecomp:end func_L39_005F2FF8 */

/* localdecomp:start func_L39_005F3088 */
extern u8 D_L39_001FE020_005F3088[];

void func_L39_005F3088(s32 a0) {
    u8 *p;
    s32 state;
    if ((u32)a0 < 0x34) {
        p = D_L39_001FE020_005F3088 + a0 * 0x80;
        state = p[0xD0];
        if (state == 7) {
            *(s32 *)(p + 0xDC) = 0;
            *(s32 *)(p + 0x100) = 0;
            p[0xD0] = 0;
            return;
        }
        if (state != 0 && state != 6) {
            p[0xD0] = 4;
        }
    }
}
/* localdecomp:end func_L39_005F3088 */

/* localdecomp:start func_L39_005F30E0 */
typedef struct {
    u8 pad0[80];
    u8 b;
    u8 pad51[47];
} E_5F09E0;
typedef struct {
    u8 pad0[128];
    E_5F09E0 e[52];
} T_5F09E0;
extern T_5F09E0 D_L39_001FE020;
s32 func_L39_005F30E0(s32 a0) {
    s32 n = a0 == 0 ? 42 : 52;
    s32 i;
    for (i = 0; i < n; i++) {
        if (D_L39_001FE020.e[i].b == 0) {
            break;
        }
    }
    return i == n ? -1 : i;
}
/* localdecomp:end func_L39_005F30E0 */

/* localdecomp:start func_L39_005F3138 */
#include "vu0.h"

typedef struct {
    u32 f0;
    u8 *f4;
    s16 f8;
    s16 fA;
    s16 fC;
    s16 fE;
    u8 f10;
    u8 p11[2];
    u8 f13;
    s32 f14;
    s32 f18;
    s32 f1C;
    vu0_v4 f20;
    vu0_v4 f30;
    s32 f40;
    u8 p44[0xC];
    f32 f50;
    s32 f54;
    s32 f58;
    u8 p5C[0x24];
} Slot_005F3138;
typedef struct {
    u8 p0[0xC0];
    Slot_005F3138 s[52];
} G_005F3138;
typedef struct { u8 b[0x460]; } Cam_005F3138;

extern G_005F3138 D_L39_001FE020_005F3138;
extern Cam_005F3138 D_L39_0024DE80[];
extern s32 D_L39_00242914;
__asm__(".extern D_L39_00242914, 16");
extern s32 D_L39_002410E8;
__asm__(".extern D_L39_002410E8, 16");
extern u8 D_001D8704_sda;
extern f32 func_0038CF00(void *, void *);
extern s32 func_L39_005F1130(void *, s32, f32, f32, f32);
extern s32 func_003A3DC8(void *, void *, void *, void *);
extern s32 func_L39_005B4398(s32);
extern s32 func_L39_005F30E0(s32);

s32 func_L39_005F3138(void *a0, s32 a1, void *a2, s32 a3, s32 a4) {
    u8 *e = a0;
    u8 *o = a2;
    s32 sum = 0;
    s32 r;
    s32 i;
    s32 v;
    s32 z = e[0x18] == 0;

    if ((a1 & 4) ? z : (z ^ 1) != 0) {
        return -1;
    }
    r = func_L39_005F30E0((s32)o);
    if (r >= 0) {
        D_L39_001FE020_005F3138.s[r].f54 = 0;
        D_L39_001FE020_005F3138.s[r].f4 = e;
        D_L39_001FE020_005F3138.s[r].f8 = *(u16 *)(e + 0x1A);
        D_L39_001FE020_005F3138.s[r].fA = -1;
        D_L39_001FE020_005F3138.s[r].f50 = -1.0f;
        D_L39_001FE020_005F3138.s[r].fC = a4;
        D_L39_001FE020_005F3138.s[r].f1C = 0;
        D_L39_001FE020_005F3138.s[r].f40 = 0;
        qzero(&D_L39_001FE020_005F3138.s[r].f30);
        if (a3 != 0 || o != 0) {
            if (o != 0) {
                *(vu0_v4 *)((u8 *)&D_L39_001FE020_005F3138 + r * 128 + 0xE0) = *(vu0_v4 *)(o + 0x10);
                D_L39_001FE020_005F3138.s[r].f20.z += 1.0f;
            } else {
                *(vu0_v4 *)((u8 *)&D_L39_001FE020_005F3138 + r * 128 + 0xE0) = *(vu0_v4 *)a3;
            }
        } else {
            a1 |= 0x11;
            qzero(&D_L39_001FE020_005F3138.s[r].f20);
        }
        if (!(a1 & 0x10)) {
            if (D_L39_00242914 != 0) {
                for (i = 0; i < D_L39_00242914 + 1; i++) {
                    f32 d = func_0038CF00(&D_L39_001FE020_005F3138.s[r].f20, &D_L39_0024DE80[i]);
                    f32 *q = (f32 *)D_L39_001FE020_005F3138.s[r].f4;
                    sum += func_L39_005F1130(q, 1, d, q[0], q[1]);
                }
                {
                    s32 lim = 0x400 - D_L39_002410E8;
                    if (sum >= lim) {
                        sum = lim;
                    }
                }
            } else {
                sum = func_003A3DC8(&D_L39_001FE020_005F3138.s[r], &D_L39_001FE020_005F3138.s[r].f20, 0, 0);
            }
        } else {
            sum = a4;
        }
        if (sum < 0x20) {
            return -1;
        }
        D_L39_001FE020_005F3138.s[r].f58 = a1;
        D_L39_001FE020_005F3138.s[r].f10 = 7;
        D_L39_001FE020_005F3138.s[r].fE = 0;
        v = *(s32 *)(e + 0x14) == *(s32 *)(e + 0x10) ? *(s32 *)(e + 0x14) : func_L39_005B4398(*(s32 *)(e + 0x14) - *(s32 *)(e + 0x10)) + *(s32 *)(e + 0x10);
        D_L39_001FE020_005F3138.s[r].f14 = v;
        D_L39_001FE020_005F3138.s[r].f0 = -1;
        D_L39_001FE020_005F3138.s[r].f18 = 0;
        D_L39_001FE020_005F3138.s[r].f13 = D_001D8704_sda++;
    } else {
        r = -1;
    }
    return r;
}
/* localdecomp:end func_L39_005F3138 */

/* localdecomp:start func_L39_005F33E0 */
extern s32 func_L39_005F3138(void *, s32, void *, s32, s32);

s32 func_L39_005F33E0(s32 index, s32 a1, u8 *a2) {
    s32 v0;
    s32 v1;
    s32 r;
    u8 *p;

    if (a2 == 0) {
        return -1;
    }
    v0 = *(s32 *)(a2 + 0x24);
    if (v0 == 0) {
        return -1;
    }
    v1 = *(s32 *)(v0 + 0x28);
    if (v1 == 0) {
        return -1;
    }
    v0 = *(u8 *)(v0 + 0xD);
    if (index >= v0) {
        return -1;
    }
    r = func_L39_005F3138((u8 *)(v1 + index * 32), a1, a2, 0, 1024);
    if (r >= 0) {
        p = (u8 *)&D_L39_001FE020 + r * 128;
        *(s32 *)(p + 0xDC) = (s32)a2;
        *(s16 *)(p + 0xCA) = (s16)index;
        *(s32 *)(p + 0x108) = -1;
    }
    return r;
}
/* localdecomp:end func_L39_005F33E0 */

/* localdecomp:start func_L39_005F3488 */
extern u8 D_L39_00272590[];
extern char *D_L39_00271B40[];
extern s32 func_L39_005F3138(void *, s32, void *, s32, s32);

s32 func_L39_005F3488(s32 index, s32 value, char *object, s32 kind) {
    char *header = D_L39_00271B40[D_L39_00272590[kind]];
    char *entries;
    s32 result;
    u8 *row;

    if (header == 0) {
        return -1;
    }
    entries = *(char **)(header + 0x28);
    if (entries == 0) {
        return -1;
    }
    if (index >= (u8)header[0xD]) {
        return -1;
    }
    result = func_L39_005F3138(entries + index * 32, value, object, 0, 0x400);
    if (result >= 0) {
        row = (u8 *)&D_L39_001FE020 + result * 128;
        *(char **)(row + 0xDC) = object;
        *(s16 *)(row + 0xCA) = index;
        *(s32 *)(row + 0x108) = kind;
    }
    return result;
}
/* localdecomp:end func_L39_005F3488 */

/* localdecomp:start func_L39_005F3548 */
extern u8 D_001FE020[];
extern u8 *D_L39_0024BB6C;
__asm__(".extern D_L39_0024BB6C, 16");
extern s32 D_L39_00242918;
__asm__(".extern D_L39_00242918, 16");


s32 func_L39_005F3548(s32 index, s32 value, void *object) {
    s32 r;
    u8 *row;
    if (D_L39_0024BB6C == 0) return -1;
    if (index >= D_L39_00242918) {
        return -1;
    }
    r = func_L39_005F3138(D_L39_0024BB6C + index * 32, value, object, 0, 0x400);
    if (r >= 0) {
        row = D_001FE020 + r * 0x80;
        *(void **)(row + 0xDC) = object;
        *(s16 *)(row + 0xCA) = index;
    }
    return r;
}
/* localdecomp:end func_L39_005F3548 */
