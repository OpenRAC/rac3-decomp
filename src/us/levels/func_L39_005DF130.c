#include "common.h"

/* NTSC-U counterpart of func_L39_005E16D8 (src/levels/shared/L39_005E16D8.c) */
/* localdecomp:start func_L39_005DF130 */
#include "vu0.h"

__asm__(".extern D_L39_002412A0, 16");
extern s32 *D_L39_002412A0;
__asm__(".extern D_L39_002412B0, 16");
extern f32 D_L39_002412B0[4] __attribute__((section(".sdata")));
extern f32 D_L39_0049A1A8[];
extern u8 D_L39_004998A0[];
__asm__(".extern D_L39_0024CF20, 32");
extern u8 *D_L39_0024CF20[1];
typedef struct { u8 v[1]; } B_005E16D8;
__asm__(".extern D_L39_00246428, 16");
__asm__(".extern D_L39_00246429, 16");
__asm__(".extern D_L39_0024642A, 16");
extern B_005E16D8 D_L39_00246428;
extern B_005E16D8 D_L39_00246429;
extern B_005E16D8 D_L39_0024642A;
__asm__(".extern D_001D81F8_sda, 4");
__asm__(".extern D_001D81FC_sda, 4");
__asm__(".extern D_L39_0024C5F8, 4");
__asm__(".extern D_001D8200_sda_005DF130, 4");
__asm__(".extern D_001D8210_sda, 4");
extern f32 D_001D81F8_sda;
extern f32 D_001D81FC_sda;
extern s32 D_001D8200_sda_005DF130[4] __attribute__((section(".sdata")));
extern u8 D_001D8210_sda[4] __attribute__((section(".sdata")));
extern f32 D_L39_0024C5F8;

extern s32 func_L01_00513698(void);
extern void func_L39_005DEA20(void);
extern s32 func_L01_00512480(s32, f32, f32);
extern s32 func_L01_00513548(s32, f32, f32);
extern s32 func_L01_005129D8(s32, f32);
extern s32 func_L01_00512AB0(s32, s32, s32);
extern s32 func_L39_0060DD90(s32);
extern s32 func_L39_005DF968(s32);
extern u8 *func_L39_006197C0(s32);
extern f32 func_00389380(f32, f32);
extern void func_00388BD0(void *, void *);
extern void func_00388758(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_00388EB8(void *, void *, void *);
extern void func_L01_0040C920(void *, void *);
extern f32 func_L01_0040BF90(void *);
extern f32 func_00388730(void *, void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_00388770(void *);
extern void func_003888C8(void *, void *, void *);
extern s32 func_L01_005130C8(s32, s32);
extern f32 func_L39_005DE930(void *);
extern f32 func_003893C8(f32, f32);
extern s32 func_L01_00512900(s32, f32);

typedef union __attribute__((aligned(16))) {
    u8 b[8];
    u32 w[2];
} Buf_005E16D8;

void func_L39_005DF130(void) {
    vu0_v4 pos0;
    vu0_v4 ang;
    vu0_v4 m[3];
    vu0_v4 fwd;
    vu0_v4 cam;
    vu0_v4 pos;
    s32 me;
    s32 i;
    s32 label;
    u8 *p;
    u8 *e;
    f32 yaw;
    f32 dist;
    f32 len;
    f32 dot;
    f32 rot;
    f32 sc;
    s32 alpha;

    me = func_L01_00513698();
    func_L39_005DEA20();
    D_001D81F8_sda = D_L39_002412B0[*D_L39_002412A0 - 1];
    D_001D81FC_sda = D_L39_0049A1A8[*D_L39_002412A0 - 1];
    func_L01_00512480(0x3000F, 0.925f, 0.095f);
    func_L01_00512480(0x3000D, 0.5f, 0.5f);
    func_L01_00512480(0x3000E, 0.5f, 0.5f);
    func_L01_00512480(0x30011, 0.875f, 0.095f);
    func_L01_00512480(0x30010, 0.875f, 0.06999999f);
    func_L01_00513548(0x3000D, 1.0f, 1.0f);
    func_L01_00513548(0x3000E, 1.0f, 1.0f);
    func_L01_00513548(0x3000F, 0.06f, 0.06f);
    func_L01_005129D8(0x3000D, 1.0f);
    func_L01_005129D8(0x3000E, 1.0f);
    if (D_001D8200_sda_005DF130[me] != 0) {
        D_001D8200_sda_005DF130[me]--;
    } else {
        func_L01_00512AB0(0x30000, 1, 0);
        D_001D8210_sda[me] = 1;
    }
    if (D_001D8210_sda[me] != 0) {
        return;
    }
    if (func_L39_0060DD90(func_L39_005DF968(0)) != 1) {
        return;
    }
    if (*D_L39_002412A0 >= 3 && (me == 0 || me == 2)) {
        D_L39_0024C5F8 = 0.135f;
    } else {
        D_L39_0024C5F8 = 0.865f;
    }
    sc = 0.83f;
    if (*D_L39_002412A0 >= 3) {
        sc = 0.93f;
    }
    func_L01_00512480(0x30001, D_L39_0024C5F8, sc * D_001D81FC_sda);
    func_L01_00512480(0x30002, D_L39_0024C5F8, sc * D_001D81FC_sda);
    func_L01_00512480(0x30003, D_L39_0024C5F8, sc * D_001D81FC_sda);
    func_L01_00513548(0x30001, 1.75f, 1.75f);
    func_L01_00513548(0x30002, 1.75f, 1.75f);
    func_L01_00513548(0x30003, 1.75f, 1.75f);
    for (i = 0x30004; i <= 0x3000B; i++) {
        func_L01_00513548(i, 0.03f, D_001D81F8_sda * 0.03f);
        func_L01_00512AB0(i, 1, 0);
    }
    p = func_L39_006197C0(me);
    yaw = func_00389380(*(f32 *)(*(u8 **)(p + 0x2530) + 0x18), -1.5707964f);
    qzero(&ang);
    ang.z = -1.5707964f;
    func_00388BD0(m, &ang);
    pos0 = *(vu0_v4 *)(*(u8 **)(p + 0x2524) + 0xE0);
    pos = pos0;
    cam = *(vu0_v4 *)(*(u8 **)(p + 0x2530) + 0x390);
    func_00388758(&fwd, &cam, &pos);
    func_00388830(&fwd, &fwd, 1.0f);
    func_00388EB8(&fwd, &fwd, m);
    func_L01_0040C920(&fwd, &fwd);
    label = 0x30004;
    for (i = 0; i < 8; i++) {
        e = D_L39_0024CF20[i];
        if (e == 0) {
            continue;
        }
        if (*(s32 *)(e + 0x2548) != *(s32 *)(p + 0x2548)) {
            Buf_005E16D8 buf;
            u32 r;
            u8 *q = e + 0x19E6;
            if (*q == 0) {
                r = 0;
            } else {
                s32 n = *q;
                s32 k = ((u32)q - n) & 7;
                s32 mm = n + 1;
                s32 j;
                u8 *dd = buf.b;
                u32 a;
                for (j = 0; j < 40; j += 5) {
                    *dd++ = D_L39_004998A0[mm + ((k + j) & 7) * 255];
                }
                a = buf.w[0] ^ (u32)q;
                buf.w[0] = a;
                buf.w[1] ^= a;
                r = buf.w[1];
            }
            if ((r ^ 3) == 0) {
                continue;
            }
        }
        {
        vu0_v4 dir;
        vu0_v4 proj;
        vu0_v4 ofs;
        vec_sub_ab(&dir, e + 0xA0, p + 0xA0);
        len = func_L01_0040BF90(&dir);
        if (1225.0f < len) {
            continue;
        }
        len = sqrt_asm(len);
        dist = len * 0.028571429f;
        alpha = (u8)((s32)((1.0f - dist) * 96.0f) + 32);
        dot = func_00388730(&dir, &pos0);
        func_003886E8(&proj, &pos0, dot);
        vec_sub_ab(&dir, &dir, &proj);
        len = func_00388770(&dir);
        if (35.0f < len) {
            len = 35.0f;
        } else if (len < 4.5f) {
            len = 4.5f;
        }
        dist = len * 0.028571429f;
        func_003888C8(&dir, &dir, &fwd);
        func_00388830(&ofs, &dir, dist * 0.085f);
        ofs.y *= D_001D81F8_sda;
        {
            u8 *q = e + 0x19E6;
            s32 t;
            s32 s;
            Buf_005E16D8 buf2;
            u32 r;
            if (*q == 0) {
                r = 0;
            } else {
                s32 n = *q;
                s32 k = ((u32)q - n) & 7;
                s32 mm = n + 1;
                s32 j;
                u8 *dd = buf2.b;
                u32 a;
                for (j = 0; j < 40; j += 5) {
                    *dd++ = D_L39_004998A0[mm + ((k + j) & 7) * 255];
                }
                a = buf2.w[0] ^ (u32)q;
                buf2.w[0] = a;
                buf2.w[1] ^= a;
                r = buf2.w[1];
            }
            s = (r == 0x14);
            t = *(s32 *)(e + 0x2548) * 3;
            func_L01_005130C8(label, (alpha << 24) | ((D_L39_0024642A.v[t] >> s) << 16) |
                                         ((D_L39_00246429.v[t] >> s) << 8) | (D_L39_00246428.v[t] >> s));
        }
        if (*(u8 **)(e + 0x2528) == 0) {
            rot = func_L39_005DE930(*(void **)(e + 0x2524));
        } else {
            rot = func_L39_005DE930(*(void **)(*(u8 **)(e + 0x2528) + 0x2D0));
        }
        rot = func_003893C8(rot, yaw);
        sc = 0.83f;
        if (*D_L39_002412A0 >= 3) {
            sc = 0.93f;
        }
        func_L01_00512AB0(label, 1, 1);
        func_L01_00512480(label, D_L39_0024C5F8 + ofs.x, sc * D_001D81FC_sda + ofs.y);
        func_L01_00512900(label, rot);
        label++;
        }
    }
}
/* localdecomp:end func_L39_005DF130 */
