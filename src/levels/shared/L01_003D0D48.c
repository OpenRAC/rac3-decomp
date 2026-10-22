#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef int s128_3D41E8 __attribute__((mode(TI)));
typedef struct {
    u8 p0[0x3C4];
    s16 x3C4;
    s16 x3C6;
    u8 p3C8[8];
    u8 x3D0;
    u8 x3D1;
    u8 x3D2;
    u8 p3D3;
    f32 x3D4;
    f32 x3D8;
    f32 x3DC;
    u8 p3E0[0xC];
    s32 x3EC;
} V_3D41E8;
typedef struct {
    u8 p0[0x10];
    s128_3D41E8 x10;
    u8 p20[3];
    u8 x23;
    u8 p24[0xC];
    u8 x30;
    u8 x31;
    u16 x32;
    u16 x34;
    u8 p36[0x32];
    V_3D41E8 *x68;
    u8 p6C[0x10];
    u16 x7C;
    u8 p7E[0x42];
    u8 xC0[1];
} M_3D41E8;
typedef struct {
    u8 pad0[0x40];
    u8 mtx[0x15];
    u8 alpha;
    u8 pad56[0x60 - 0x56];
} Elem_003D4478;
typedef struct {
    Elem_003D4478 elem[10];
    u8 pad[0x3C4 - 0x3C0];
    s16 h3C4;
    s16 h3C6;
    u8 pad3C8[0x3D0 - 0x3C8];
    u8 mode;
    u8 pad3D1;
    u8 count;
    u8 pad3D3[0x3D8 - 0x3D3];
    f32 w;
    f32 h;
    u8 pad3E0[0x3EC - 0x3E0];
    u32 color;
} Hdr_003D4478;
typedef struct {
    f32 v[4][4];
    u32 color[4];
    f32 uv[8];
    u8 pad[0x20];
} Quad_003D4478;
typedef struct {
    u8 pad[0x68];
    Hdr_003D4478 *data;
} Moby_003D4478;
typedef int u128_3D6FB0 __attribute__((mode(TI)));
struct M_3D6FB0;
typedef struct { struct M_3D6FB0 *arr[15]; s16 h3C; u8 p3E[2]; f32 f40; f32 f44; u8 b48; u8 b49; u8 b4A; u8 b4B; } V_3D6FB0;
typedef struct M_3D6FB0 {
    u8 p0[0x10]; u128_3D6FB0 pos; u8 p20[0x10];
    u8 b30; u8 b31; s16 h32; u8 p34[0x34]; V_3D6FB0 *w68;
} M_3D6FB0;

INCLUDE_ASM("asm/levels", func_L01_003D0D48);

INCLUDE_ASM("asm/levels", func_L01_003D1210);

/* localdecomp:start func_L01_003D1848 */
f32 func_L01_00446630(s32, s32, s32, void *);
extern u8 D_001A4C60[];
extern s32 D_L01_001E0100;

void func_L01_003D1848(s32 arg0, void *arg1) {
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = func_L01_00446630(arg1 + 0x140, D_L01_001E0100 + ((*(s32 *)arg1) << 7) + 0x30, D_L01_001E0100 + ((*(s32 *)((u8 *)arg1 + 4)) << 7) + 0x30, D_001A4C60);
    temp_f2 = *(f32 *)((u8 *)arg1 + 8);
    *(f32 *)((u8 *)arg1 + 0x30) = temp_f0;
    *(f32 *)((u8 *)arg1 + 0x54) = (f32) (temp_f2 + (((*(f32 *)((u8 *)arg1 + 0xC)) - temp_f2) * temp_f0));
}
/* localdecomp:end func_L01_003D1848 */

/* localdecomp:start func_L01_003D18C0 */
extern void func_L01_003D1E30(void);
extern void func_L01_003D2300(void);
extern void func_L01_00404A10(void *, s32);

void func_L01_003D18C0(s32 a0, s32 *a1) {
    if (a1[4] >= 0) {
        func_L01_003D1E30();
        func_L01_00404A10(func_L01_003D2300, a0);
    }
}
/* localdecomp:end func_L01_003D18C0 */

INCLUDE_ASM("asm/levels", func_L01_003D1900);

INCLUDE_ASM("asm/levels", func_L01_003D1A50);

INCLUDE_ASM("asm/levels", func_L01_003D1C60);

INCLUDE_ASM("asm/levels", func_L01_003D1E30);

INCLUDE_ASM("asm/levels", func_L01_003D2158);

/* localdecomp:start func_L01_003D2278 */
extern s32 D_0016C580[];
extern void func_003C2C98(s32, void *);

void func_L01_003D2278(s32 a0, u8 *a1) {
    if (*(s32 *)(a1 + 96)) {
        func_003C2C98(D_0016C580[0], a1 + 112);
    }
}
/* localdecomp:end func_L01_003D2278 */

INCLUDE_ASM("asm/levels", func_L01_003D22A8);

INCLUDE_ASM("asm/levels", func_L01_003D2300);

INCLUDE_ASM("asm/levels", func_L01_003D25D8);

INCLUDE_ASM("asm/levels", func_L01_003D2A18);

INCLUDE_ASM("asm/levels", func_L01_003D2B50);

INCLUDE_ASM("asm/levels", func_L01_003D2F58);

/* localdecomp:start func_L01_003D3090 */
extern void func_L01_003D2A18(void *, void *);
extern void func_L01_003D2B50(void *, void *);
extern void func_L01_003D2F58(void *, void *);

void func_L01_003D3090(void *a0, u8 *a1) {
    if (*(s32 *)(a1 + 52) != 0) {
        func_L01_003D2A18(a0, a1);
        func_L01_003D2B50(a0, a1);
        func_L01_003D2F58(a0, a1);
    }
}
/* localdecomp:end func_L01_003D3090 */

/* localdecomp:start func_L01_003D30E8 */
int func_L01_003D30E8(u8 *a) {
    u8 *p = *(u8 **)(a + 104);
    return *(s32 *)(p + 232) > *(s32 *)(p + 228);
}
/* localdecomp:end func_L01_003D30E8 */

INCLUDE_ASM("asm/levels", func_L01_003D3100);

INCLUDE_ASM("asm/levels", func_L01_003D3CF8);

INCLUDE_ASM("asm/levels", func_L01_003D3EE0);

INCLUDE_ASM("asm/levels", func_L01_003D42D0);

INCLUDE_ASM("asm/levels", func_L01_003D4718);

INCLUDE_ASM("asm/levels", func_L01_003D4750);

INCLUDE_ASM("asm/levels", func_L01_003D4788);

INCLUDE_ASM("asm/levels", func_L01_003D4828);

/* localdecomp:start func_L01_003D4BB0 */

extern u8 *func_003C24B0(s32, s32);

u8 *func_L01_003D4BB0(u8 *src) {
    u8 *o = func_003C24B0(7110, 128);
    if (o != 0) {
        *(u128_t *)(o + 16) = *(u128_t *)(src + 16);
        o[48] = 64;
        *(u8 **)(o + 184) = src;
    }
    return o;
}
/* localdecomp:end func_L01_003D4BB0 */

/* localdecomp:start func_L01_003D4C00 */
void func_L01_003D4C00(void) {

}
/* localdecomp:end func_L01_003D4C00 */

INCLUDE_ASM("asm/levels", func_L01_003D4C08);

/* localdecomp:start func_L01_003D4E70 */
extern void func_L01_0040C948(u8 *, s32);
void func_L01_003D4E70(u8 *a0) {
    s32 i;
    u8 *p = *(u8 **)(a0 + 104);
    for (i = 0; i < *(s32 *)(p + 676); i++) {
        if (*(s32 *)(p + i * 224 + 192) > 0) {
            func_L01_0040C948(p + i * 224, *(s32 *)(p + 672));
        }
    }
}
/* localdecomp:end func_L01_003D4E70 */

INCLUDE_ASM("asm/levels", func_L01_003D4EE0);

INCLUDE_ASM("asm/levels", func_L01_003D4F30);

/* localdecomp:start func_L01_003D5198 */
extern void func_L01_00404A10_003D5198(void *, s32);
extern void func_003C2880(u8 *);
extern void func_L01_004450F0(u8 *, int, int);
extern void func_L01_003D4F30(u8 *, int);
extern void func_L01_003D4E70(u8 *);

void func_L01_003D5198(u8 *m) {
    u8 *pv = *(u8 **)(m + 0x68);
    u8 *e;
    u8 *t;
    int i;

    if (m[0x20] == 0) {
        for (i = 0; i < *(int *)(pv + 676); i++) {
            e = pv + i * 224;
            t = *(u8 **)(e + 208);
            if (t == 0) {
                goto kill;
            }
            if (t[0x20] == 254) {
                goto kill;
            }
            if (t[0x20] == 253) {
                goto kill;
            }
            if (*(u16 *)(t + 0x34) & 2) {
                goto kill;
            }
            t = *(u8 **)(e + 200);
            if (t == 0) {
                goto ok;
            }
            if (t[0x20] == 254) {
                goto kill;
            }
            if (t[0x20] == 253) {
                goto kill;
            }
            if (!(*(u16 *)(t + 0x34) & 2)) {
                goto ok;
            }
        kill:
            func_L01_004450F0(m, 1, -1);
            continue;
        ok:
            func_L01_003D4F30(m, i);
            ((void (*)(void (*)(u8 *), u8 *))func_L01_00404A10_003D5198)(func_L01_003D4E70, m);
        }
    } else {
        func_003C2880(m);
    }
}
/* localdecomp:end func_L01_003D5198 */

INCLUDE_ASM("asm/levels", func_L01_003D52A8);

INCLUDE_ASM("asm/levels", func_L01_003D57E8);

INCLUDE_ASM("asm/levels", func_L01_003D59C0);

/* localdecomp:start func_L01_003D5C98 */
extern void func_L01_004450F0(u8 *, int, int);
extern u8 *func_003C24B0(s32, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern s32 func_00382468(s32);
extern void func_L01_003D59C0(M_3D41E8 *, s32, void *, void *, f32, f32, f32, f32, f32);
extern f32 func_003824E0(f32, f32);

M_3D41E8 *func_L01_003D5C98(M_3D41E8 *o, s128_3D41E8 *pos, s32 n, s32 mode, s32 a, s32 b, u8 c,
                        f32 f0, f32 f1, f32 f2, f32 f3, f32 f4) {
    M_3D41E8 *m = ((M_3D41E8 * (*)(s32, s32))func_003C24B0)(7181, 1008);
    if (m) {
        V_3D41E8 *v;
        s32 i;
        v = m->x68;
        m->x30 = o->x30;
        m->x32 = o->x30;
        m->x10 = *pos;
        ((void (*)(M_3D41E8 *, s32, s32))func_L01_004450F0)(m, 0, -1);
        v->x3D1 = c;
        v->x3D0 = mode;
        v->x3D2 = n;
        v->x3D4 = func_003C3D30(pos, 0, 0, 0.5f) + 0.1f;
        if (v->x3D0 == 1) {
            v->x3EC = func_00382468(2) ? 0x7F205050 : 0x7F50A0A0;
        }
        for (i = 0; i < n && i < 10; i++) {
            func_L01_003D59C0(m, i, pos, o->xC0, f3, f4, f0, f1, f2);
        }
        if (mode == 0) {
            m->x23 = 127;
            m->x31 = 1;
            m->x34 &= ~1;
            m->x7C = (1 << func_00382468(4)) - 0x8000;
        } else {
            m->x31 = 0;
            m->x34 |= 1;
            v->x3C4 = a;
            v->x3C6 = b;
            v->x3D8 = func_003824E0(0.06f, 0.1f) * f3;
            v->x3DC = func_003824E0(0.06f, 0.1f) * f3;
        }
    }
    return m;
}
/* localdecomp:end func_L01_003D5C98 */

INCLUDE_ASM("asm/levels", func_L01_003D5ED0);

/* localdecomp:start func_L01_003D5F28 */




extern s32 func_00382468(s32);
extern void func_003D93B0(Quad_003D4478 *, s32, s32, s32);
extern void func_0038D308(void *, void *);
extern void func_L01_003D5ED0(void *, void *, f32 *, f32, f32, f32);
extern void func_003D2DA0(Quad_003D4478 *, s32, s32);

void func_L01_003D5F28(Moby_003D4478 *moby) {
    Quad_003D4478 q;
    u8 mtx[48];
    Hdr_003D4478 *hdr;
    Elem_003D4478 *e;
    u32 color;
    s32 odd;
    s32 i;

    hdr = moby->data;
    for (i = 0; i < hdr->count && i < 10; i++) {
        e = &hdr->elem[i];
        odd = i % 2;
        q.uv[0] = 0.0f;
        q.uv[1] = 0.0f;
        q.uv[2] = 0.0f;
        q.uv[3] = 1.0f;
        q.uv[4] = 1.0f;
        q.uv[5] = 0.0f;
        q.uv[6] = 1.0f;
        q.uv[7] = 1.0f;
        switch (hdr->mode) {
        case 1:
            color = hdr->color;
            break;
        case 2:
            color = odd ? 0x7F00E7B9 : 0x7F297E38;
            break;
        case 3:
            func_00382468(2);
            color = 0x7F54F6D9;
            break;
        default:
            color = 0x7F808080;
            break;
        }
        color &= 0xFFFFFF;
        color += e->alpha << 24;
        q.color[3] = color;
        q.color[2] = color;
        q.color[1] = color;
        q.color[0] = color;
        func_003D93B0(&q, odd ? hdr->h3C4 : hdr->h3C6, 0, 128);
        func_0038D308(mtx, hdr->elem[i].mtx);
        func_L01_003D5ED0(e, mtx, q.v[0], 0.0f, hdr->w, -hdr->h);
        func_L01_003D5ED0(e, mtx, q.v[1], 0.0f, hdr->w, hdr->h);
        func_L01_003D5ED0(e, mtx, q.v[2], 0.0f, -hdr->w, -hdr->h);
        func_L01_003D5ED0(e, mtx, q.v[3], 0.0f, -hdr->w, hdr->h);
        func_003D2DA0(&q, 0, 0);
    }
}
/* localdecomp:end func_L01_003D5F28 */

INCLUDE_ASM("asm/levels", func_L01_003D6158);

INCLUDE_ASM("asm/levels", func_L01_003D6218);

INCLUDE_ASM("asm/levels", func_L01_003D6398);

INCLUDE_ASM("asm/levels", func_L01_003D6F10);

INCLUDE_ASM("asm/levels", func_L01_003D7168);

INCLUDE_ASM("asm/levels", func_L01_003D7288);

INCLUDE_ASM("asm/levels", func_L01_003D7510);

INCLUDE_ASM("asm/levels", func_L01_003D76C0);

INCLUDE_ASM("asm/levels", func_L01_003D79D0);

INCLUDE_ASM("asm/levels", func_L01_003D7C60);

INCLUDE_ASM("asm/levels", func_L01_003D80D0);

INCLUDE_ASM("asm/levels", func_L01_003D8298);

INCLUDE_ASM("asm/levels", func_L01_003D8780);

INCLUDE_ASM("asm/levels", func_L01_003D8B10);

/* localdecomp:start func_L01_003D8B30 */
extern void func_L01_004450F0(u8 *, int, int);
extern u8 *func_003C24B0(s32, s32);
extern s32 func_00382468(s32);

M_3D6FB0 *func_L01_003D8B30(s32 n, M_3D6FB0 **list, s32 chance, s32 a, s32 b, f32 x, f32 y) {
    M_3D6FB0 *m;
    V_3D6FB0 *v;
    s32 i;
    m = ((M_3D6FB0 * (*)(s32, s32))func_003C24B0)(7383, 80);
    if (m == 0) return 0;
    if (n == 0 || list == 0) return 0;
    if (list[0] == 0) return 0;
    v = m->w68;
    m->h32 = 0xFF;
    m->b30 = 0xFF;
    m->pos = list[0]->pos;
    v->f40 = x;
    v->b48 = a;
    v->b49 = b;
    v->f44 = y;
    v->b4A = 0;
    v->b4B = 0;
    for (i = 0; i < n; i++) {
        if (list[i] != 0 && func_00382468(100) < chance) {
            v->arr[v->h3C] = list[i];
            v->h3C++;
        }
    }
    ((void (*)(M_3D6FB0 *, s32, s32))func_L01_004450F0)(m, 0, -1);
    return m;
}
/* localdecomp:end func_L01_003D8B30 */

LINKER_REMNANT("asm/levels", func_L01_003D8C78);

INCLUDE_ASM("asm/levels", func_L01_003D8C80);
