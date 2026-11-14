#include "common.h"

/* declared by functions of L32_003B5828.c, which this file was cut from */
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L32_003B7190(void *, void *);
s32 func_003A52A0(s32, s32, void *);
void func_L01_004450F0(void *, s32, s32);

/* localdecomp:start func_L32_003B7190 */
#include "vu0.h"

extern void func_003C4DA8(void *, void *, void *, void *);
extern void func_L30_003A2C68(void *, s32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L32_003B6618(void *);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
__asm__(".extern D_L32_001DEE1C, 4");
extern f32 D_L32_001DEE1C;
__asm__(".extern D_L32_001DEE38, 4");
extern f32 D_L32_001DEE38;

void func_L32_003B7190(void *arg0, void *arg1) {
    u8 *a0 = (u8 *)arg0;
    f32 *old = (f32 *)arg1;
    u8 *st = *(u8 **)(a0 + 0x68);
    vu0_v4 d;
    vu0_v4 v;
    vu0_v4 w;
    u8 **list;
    f32 *t;
    s32 i;
    s32 j;
    s32 r;

    vec_sub_ab(&d, a0 + 0x10, old);
    func_003C4DA8(st + 0x30, &d, a0 + 0xF0, a0 + 0xF0);
    if (a0[0x20] != 1) {
        list = (u8 **)(st + 0x150);
        for (i = 0; i < 48; i++) {
            if (list[i] != 0 && list[i][0x20] >= 0xFD) {
                list[i] = 0;
            }
        }
        for (i = 0; i < 48; i++) {
            if (list[i] != 0) {
                u8 *s = *(u8 **)(list[i] + 0x68);
                if (s != 0) {
                    f32 *x = (f32 *)(s + 0x80);
                    f32 *z = (f32 *)(s + 0x100);
                    for (j = 0; j < 32; j++) {
                        x[j] += d.x;
                        z[j] += d.z;
                    }
                    vec_add_ba(s + 0x30, s + 0x30, &d);
                    vec_add_ab(s + 0x10, s + 0x10, &d);
                    vec_add_ba(list[i] + 0x10, list[i] + 0x10, &d);
                }
            }
        }
    } else {
        list = (u8 **)(st + 0x150);
        for (i = 0; i < 48; i++) {
            if (list[i] != 0) {
                func_L30_003A2C68(list[i], 0x42);
                list[i] = 0;
            }
        }
    }
    *(f32 *)(st + 0x254) += D_L32_001DEE1C;
    if (*(f32 *)(st + 0x254) > 1.0f) {
        r = func_L32_003B6618(a0);
        *(f32 *)(st + 0x254) -= 1.0f;
        if (r >= 0) {
            func_003C2F58(a0, r % 8 + 2, &w);
            w.y += D_L32_001DEE38;
        }
    }
    t = (f32 *)(st + 0xB0);
    for (i = 0; i < 16; i++) {
        if (old[0] < t[i] && t[i] <= *(f32 *)(a0 + 0x10)) {
            f32 *add = (f32 *)(st + 0xF0);
            *(f32 *)(st + 0x148) += add[i];
            if (i < 8) {
                func_003C2F58(a0, i + 2, &v);
                func_L01_003303B8(&v, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, 0.9f, 0.0f, 0.0f, 2.0f, 1, 1, 0, 0, 1, 1,
                                  0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF,
                                  0x280000FF, 0x3064FF, 0);
                func_003A52A0(1, 0, a0);
            }
        }
    }
    if (old[0] < *(f32 *)(st + 0x238) && *(f32 *)(st + 0x238) <= *(f32 *)(a0 + 0x10)) {
        func_003C2F58(a0, 1, &v);
        func_L01_003303B8(&v, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, 0.9f, 0.0f, 0.0f, 2.0f, 1, 1, 0, 0, 1, 1,
                          0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF,
                          0x280000FF, 0x3064FF, 0);
        func_003A52A0(1, 0, a0);
    }
}
/* localdecomp:end func_L32_003B7190 */

/* localdecomp:start func_L32_003B7610 */
#include "vu0.h"
typedef struct {
    s32 count;
    s32 end;
    s32 start;
    s32 id;
    u8 pad[0x200];
} E_003B7610;

typedef struct {
    u8 pad0[0x80];
    E_003B7610 e[4];
    s32 slot[4];
    s32 f8D0;
    s32 f8D4;
    f32 f8D8;
    f32 f8DC;
    f32 f8E0;
    f32 f8E4;
    s32 f8E8;
    f32 f8EC;
    f32 f8F0;
} V_003B7610;

extern void *func_L31_0034E0F0(void *, s32, s32, s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern s32 func_L01_004561B8(void *);
extern void func_L32_003B7BE8(u8 *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_00456250(void *);
extern u8 *func_L32_003B8390(u8 *, f32, f32);
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_L32_0039FE78(void *, void *, s32, f32 *, f32 *);
extern void func_L32_003B81F0(u8 *, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern f32 func_L01_004395E0(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L32_003B7AB0(u8 *);
extern u8 D_001A4C60[];
extern s32 D_L32_001DEF70;
__asm__(".extern D_L32_001DEF70, 4");
extern f32 D_L32_001DEF74;
__asm__(".extern D_L32_001DEF74, 4");
extern f32 D_L32_001DEF78;
__asm__(".extern D_L32_001DEF78, 4");
extern f32 D_L32_001DEF7C;
__asm__(".extern D_L32_001DEF7C, 4");
extern f32 D_L32_001DEF80;
__asm__(".extern D_L32_001DEF80, 4");
extern f32 D_L32_001DEF84;
__asm__(".extern D_L32_001DEF84, 4");

void func_L32_003B7610(u8 *a0) {
    V_003B7610 *v = *(V_003B7610 **)(a0 + 0x68);
    f32 vec[4] __attribute__((aligned(16)));
    f32 fa0;
    f32 fa4;
    s32 frame;
    s32 found;
    s32 i;
    s32 j;
    f32 t;
    f32 f;

    switch (a0[0x20]) {
    case 0x42:
        if (func_L01_004561B8(a0)) {
            func_L01_003303B8(a0 + 0x10, 0, 25, 20, 20, 20, 45, 1, 0.9f, 0.0f, 0.0f, 2.0f,
                              1, 1, 0, 0, 1, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L31_0034E0F0(a0 + 0x10, 3, 10, 0, 0xF0);
            *(s32 *)(a0 + 0x98) = 0;
            *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(a0, 1);
        }
        break;
    case 0:
        func_L32_003B7BE8(a0);
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        v->f8E8++;
        frame = v->f8E8 % v->f8D4;
        found = 0;
        if (func_00382380(D_001A4C60, v->f8D0, 0) != 0 && func_L01_00456250(a0) == 0) {
            for (i = 0; i < 4; i++) {
                if (v->e[i].id != -1 && v->e[i].start <= frame && frame <= v->e[i].end) {
                    s32 *slots = v->slot;
                    s32 *slot = &slots[i];
                    if (*slot == 0) {
                        *slot = (s32)func_L32_003B8390(a0 + 0x10, v->f8EC, v->f8F0);
                    }
                    if (func_L01_0044E1B8(a0, D_L32_001DEF80)) {
                        f32 *pv = vec;
                        t = (f32)(frame - v->e[i].start) / (f32)(v->e[i].end - v->e[i].start);
                        qzero(vec);
                        vec[2] = D_L32_001DEF84;
                        func_0038D000(pv, pv, a0 + 0xC0);
                        vec_add_ab(vec, vec, a0 + 0x10);
                        fa4 = func_003C4088(v->f8DC, v->f8D8, t);
                        fa0 = func_003C4088(v->f8E4, v->f8E0, t);
                        for (j = 0; j < v->e[i].count; j++) {
                            s32 r = func_L32_0039FE78(vec, &v->e[i], 1, &fa0, &fa4);
                            if (slots[i] != 0) {
                                func_L32_003B81F0((u8 *)slots[i], r);
                            }
                        }
                        func_003A52A0(0, 0, a0);
                    }
                    found = 1;
                } else {
                    s32 *slots = v->slot;
                    s32 *slot = &slots[i];
                    if (*slot != 0) {
                        *(s32 *)(*(u8 **)((u8 *)*slot + 0x68) + 0x88) = 0;
                        *slot = 0;
                    }
                }
            }
        } else {
            v->f8E8 = 0;
        }
        if (found) {
            if (a0[0x43] != 1 || D_L32_001DEF74 <= func_L01_004395E0(a0)) {
                func_003C3A10(a0, 1, (s32)D_L32_001DEF7C, (D_L32_001DEF70 * 5 + 2) / 6);
            }
            f = D_L32_001DEF78;
        } else {
            if (a0[0x43] != 0) {
                func_003C3A10(a0, 0, 0, (D_L32_001DEF70 * 5 + 2) / 6);
            }
            f = 1.0f;
        }
        *(f32 *)(a0 + 0x48) = f;
        break;
    }
    func_L32_003B7AB0(a0);
}
/* localdecomp:end func_L32_003B7610 */
