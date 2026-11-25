#include "common.h"

typedef struct {
    u8 pad0[0x34];
    u16 f34;
    u8 pad36[0xB2 - 0x36];
    s16 fB2;
    u8 padB4[0x100 - 0xB4];
} Type_004A3A90;

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x4B90 - 0x4958];
    u8 f4B90[1];
    u8 pad2[0x6D28 - 0x4B91];
    u8 fX[1];
} S_func_0049A930;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 pad[3];
} Ent_0049AB20;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 f14;
    u8 pad[3];
} S_2EC7A8;
typedef struct { u8 b[16]; } V16_48DCD8;
typedef struct {
    s32 v[12][3];
} S_236B80;
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
    u8 x14;
    u8 pad[3];
} E_49E5B8;
typedef struct {
    s32 offset;
    s32 data;
    u16 size;
    s16 kind;
    s16 arg1;
    s16 arg0;
} Entry_4A0270;
typedef struct {
    s32 count;
    Entry_4A0270 entries[1];
} Table_4A0270;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 fC;
    u8 pad[11];
} S_2EC760_0049E648;

/* localdecomp:start func_L01_004A32E0 */
extern s32 func_00381FF0(s32);
extern f32 D_L01_001DC0E8_004A32E0;
__asm__(".extern D_L01_001DC0E8_004A32E0, 16");
extern void *func_0011A264(void *, s32, s32);
extern s32 func_0011B868(u8 *);
extern s32 func_0038E548(u8 *, s32, f32);

void func_L01_004A32E0(s32 id, u8 *buf, f32 scale, f32 maxw) {
    u8 idx[0x40];
    u8 *s;
    s32 n;
    s32 len;
    s32 i;
    s32 j;
    f32 w;

    func_0011A264(idx, 0, 0x40);
    n = 0;
    s = (u8 *)func_00381FF0(id);
    len = func_0011B868(s);
    if (len > 0x3F) len = 0x3F;
    for (i = 0; i <= len; i++) {
        buf[i] = s[i];
        if (i > 0 && buf[i] == 0x20 && (buf[i - 1] & 0x80) == 0) {
            idx[n++] = i;
        }
    }
    j = n - 1;
    if (j < 0) j = 0;
    while (j > 0 && idx[j] >= 0x3C) j--;
    w = (f32)func_0038E548(buf, -1, scale) / D_L01_001DC0E8_004A32E0;
    while (j >= 0 && maxw < w) {
        buf[idx[j] + 1] = 0x2E;
        buf[idx[j] + 2] = 0x2E;
        buf[idx[j] + 3] = 0x2E;
        buf[idx[j] + 4] = 0;
        j--;
        w = (f32)func_0038E548(buf, -1, scale) / D_L01_001DC0E8_004A32E0;
    }
}
/* localdecomp:end func_L01_004A32E0 */

/* localdecomp:start func_L01_004A34A8 */
typedef struct {
    u8 pad0[0x34];
    u16 f34;
    u8 pad36[0x100 - 0x36];
} Ent_004A34A8;
extern s32 D_L01_001D9730_004A34A8;
extern s32 D_L01_001D9734_004A34A8;
extern s32 D_L01_001DF988_004A34A8;
__asm__(".extern D_L01_001DF988_004A34A8, 16");
extern Ent_004A34A8 *D_L01_001E001C_004A34A8;
__asm__(".extern D_L01_001E001C_004A34A8, 16");
extern Ent_004A34A8 *D_L01_001E0024_004A34A8;
__asm__(".extern D_L01_001E0024_004A34A8, 16");
extern void func_003A0EC0(s32, s32, s32, s32, s32);
extern s32 func_00392260(s32, s32, s32);

void func_L01_004A34A8(s32 a0, s32 a1) {
    Ent_004A34A8 *p;
    func_003A0EC0(7, 1, 0, 0, 0);
    D_L01_001D9734_004A34A8 = a1;
    D_L01_001D9730_004A34A8 = a0;
    D_L01_001DF988_004A34A8 = 0;
    func_00392260(0, 0, 0);
    for (p = D_L01_001E001C_004A34A8; p < D_L01_001E0024_004A34A8; p++) {
        p->f34 |= 0x80;
    }
}
/* localdecomp:end func_L01_004A34A8 */

/* localdecomp:start func_L01_004A3548 */
typedef struct {
    u8 pad0[0x25C];
    s32 w25C;
    s32 w260;
    s32 w264;
} S_4A3548;
extern S_4A3548 D_L01_001E7580;
extern Type_004A3A90 *D_L01_001E001C;
extern Type_004A3A90 *D_L01_001E0024;
__asm__(".extern D_L01_001E001C, 16");
__asm__(".extern D_L01_001E0024, 16");
extern s32 func_003A0F98(s32, s32);
extern s32 func_00392260(s32, s32, s32);

void func_L01_004A3548(void) {
    Type_004A3A90 *p;

    func_003A0F98(0, 0);
    func_00392260(D_L01_001E7580.w25C, D_L01_001E7580.w260, D_L01_001E7580.w264);
    for (p = D_L01_001E001C; p < D_L01_001E0024; p++) {
        p->f34 &= 0xFF7F;
    }
}
/* localdecomp:end func_L01_004A3548 */

/* localdecomp:start func_L01_004A35C0 */
extern void func_0038CB78(unsigned int *dst, unsigned int val, int size);
extern char D_L01_00236B90[];
extern char D_L01_00237800[];
extern char D_L01_001E0D30[] __attribute__((section(".sdata")));

/* from rac2-decomp's func_L00_003588A8, renamed */
void func_L01_004A35C0(void)
{
    func_0038CB78((unsigned int *)D_L01_00236B90, 0, 0xC70);
    func_0038CB78((unsigned int *)D_L01_00237800, 0, 0xC70);
    func_0038CB78((unsigned int *)D_L01_001E0D30, 0, 0x40);
}
/* localdecomp:end func_L01_004A35C0 */

/* localdecomp:start func_L01_004A3610 */
typedef int u128_3610 __attribute__((mode(TI)));
typedef struct {
    s32 valid;
    u8 pad04[0xC];
    u128_3610 q10;
    u128_3610 q20;
    s32 w30;
    s32 w34;
    s32 w38;
    u8 b3C, b3D, b3E, b3F, b40, b41;
    u8 pad42[2];
    f32 f44, f48, f4C, f50;
    s32 w54;
    s32 w58;
    s32 w5C;
    u8 data60[0x404];
    u8 vis[0x800];
    s32 wC64;
    s32 wC68;
    u8 padC6C[4];
} Ckpt_3610;
typedef struct {
    u8 pad0[0x25C0];
    u8 *p25C0;
    u8 pad25C4[0x25E4 - 0x25C4];
    u8 b25E4;
    u8 pad25E5[0x287A - 0x25E5];
    s16 h287A;
} Hero_3610;
typedef struct {
    u8 pad0[0x40];
    u8 b40, b41, b42, b43;
    u8 pad44[0xB4 - 0x44];
    s32 wB4;
} Tab_3610;
typedef struct {
    u8 pad0[0x48];
    s16 h48;
} Flg_3610;

extern Hero_3610 D_001A4BE0;
extern char D_L01_00236B90[];
extern char D_L01_00237800[];
extern Tab_3610 D_001A30B0;
extern Flg_3610 D_001CCFD0;
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_001BBC40[][16];
extern u8 D_001BBE90[][0x400];
extern s32 D_L01_001F3F40[];
extern u8 D_L01_001DF9E4;
__asm__(".extern D_L01_001DF9E4, 16");
extern u8 D_L01_001DF9E5;
__asm__(".extern D_L01_001DF9E5, 16");
extern u8 D_L01_001DF9E6;
__asm__(".extern D_L01_001DF9E6, 16");
extern f32 D_L01_001DF9E8;
__asm__(".extern D_L01_001DF9E8, 16");
extern f32 D_L01_001DF9EC;
__asm__(".extern D_L01_001DF9EC, 16");
extern f32 D_L01_001DF9F0;
__asm__(".extern D_L01_001DF9F0, 16");
extern f32 D_L01_001DF9F4;
__asm__(".extern D_L01_001DF9F4, 16");
extern void func_0038CC88(void *, void *, s32);
extern s32 func_0039EC28(s32, s32);

void func_L01_004A3610(u128_3610 *a, u128_3610 *b) {
    s32 i;
    s32 lvl;
    u8 *p;
    Ckpt_3610 *c;
    u8 *src;

    if (D_001A4BE0.b25E4 == 4) {
        return;
    }
    func_0038CC88(((Ckpt_3610 *)D_L01_00237800)->data60, ((Ckpt_3610 *)D_L01_00236B90)->data60, 0x404);
    lvl = D_001D545C;
    src = ((Ckpt_3610 *)D_L01_00236B90)->vis;
    for (i = 0; i < 0x800 - 1; i++, src++) {
        if (*src == 0) {
            continue;
        }
        if (*src != 1 && !(D_001BBC40[lvl][*src - 2] & 0x80)) {
            continue;
        }
        ((Ckpt_3610 *)D_L01_00237800)->vis[i] = *src;
        if (i & 1) {
            p = &D_001BBE90[0][(i >> 1) + (lvl << 10)];
            if (((*p >> 4) & 7) != 7) {
                *p += 0x10;
            }
        } else {
            p = &D_001BBE90[0][(i >> 1) + (lvl << 10)];
            if ((*p & 7) != 7) {
                *p += 1;
            }
        }
    }
    c = (Ckpt_3610 *)D_L01_00237800;
    c->valid = 1;
    *(u128_3610 *)((u8 *)c + 0x10) = *a;
    *(u128_3610 *)((u8 *)c + 0x20) = *b;
    c->w30 = *(s32 *)(D_001A4BE0.p25C0 + 0x38);
    c->w34 = *(s32 *)(D_001A4BE0.p25C0 + 0x3C);
    c->w54 = D_001A4BE0.b25E4;
    c->w58 = (s32)D_001A4BE0.p25C0;
    c->w5C = D_001A4BE0.h287A;
    c->w38 = D_001A30B0.wB4;
    c->b3C = D_001A30B0.b40;
    c->b3D = D_001A30B0.b41;
    c->b3E = D_001A30B0.b42;
    c->wC64 = D_001CCFD0.h48;
    c->wC68 = D_L01_001F3F40[0];
    c->b3F = D_L01_001DF9E4;
    c->b40 = D_L01_001DF9E5;
    c->b41 = D_L01_001DF9E6;
    c->f44 = D_L01_001DF9E8;
    c->f48 = D_L01_001DF9EC;
    c->f4C = D_L01_001DF9F0;
    c->f50 = D_L01_001DF9F4;
    func_0039EC28(0, -1);
}
/* localdecomp:end func_L01_004A3610 */
