#include "common.h"

typedef struct {
    u8 pad[80];
} Ent_4C4520;
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 w4;
    s32 w8;
    s32 w12;
    s32 w16;
    s32 w20;
    s32 w24;
    s32 w28;
    s32 w32;
    s32 w36;
    s32 w40;
    s32 w44;
    s32 w48;
    s32 w52;
    s32 w56;
    s32 w60;
    s32 owner;
    char pad44[0x50 - 0x44];
} Slot;
typedef struct {
    u8 pad[64];
    s32 handle;
    u8 pad2[12];
} Ent_004C45F8;
typedef struct {
    s32 w0;
    s32 w4;
    s32 pad8[2];
} E_4C46A8;
typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} Unk24FA60;
typedef int u128_4C4A18 __attribute__((mode(TI)));
typedef struct {
    u128_4C4A18 pos;
    f32 x10;
    f32 x14;
    f32 x18;
    u8 *x1C;
} E_4C4A18;
typedef struct {
    u8 pad0[872];
    s16 x368;
    u8 pad36A[8790];
    u8 *x25C0;
} S_4C4A18;
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4_004C4AD8;
typedef struct {
    u8 p0[0x10];
    Vec4_004C4AD8 x10;
} O_004C4AD8;
typedef struct {
    u8 p0[0xE0];
    Vec4_004C4AD8 xE0;
} P_004C4AD8;
typedef struct {
    Vec4_004C4AD8 x0;
    f32 x10;
    f32 x14;
    f32 x18;
    O_004C4AD8 *x1C;
} T_004C4AD8;
typedef struct {
    u8 p0[0x368];
    s16 x368;
    u8 p36A[0x25C0 - 0x36A];
    P_004C4AD8 *x25C0;
} S_004C4AD8;
typedef struct { u8 a; u8 b; u8 pad[238]; } Ent_004C4F88;
typedef struct {
    u8 pad0[4608];
    s32 f4608;
    u8 pad4612[36];
    s32 f4648;
} Game_004C5038;
typedef struct {
    u8 pad0[28];
    s32 f28;
} Ent_004C5038;
typedef struct {
    u8 pad0[16];
    f32 x;
    f32 y;
    f32 z;
    u8 pad1C[20];
    u8 b30;
    u8 pad31[3];
    u16 h34;
    u8 pad36[98];
    s32 f98;
} Obj_4C5DE0;
typedef struct {
    u8 pad0[336];
    s16 unk150;
    s16 unk152;
} G4C67B8;
typedef struct { u8 pad[336]; s16 a; s16 b; } Ent_004C6A70;
typedef struct {
    int a[64];
    int b[64];
    int c[8];
    int n220;
    int n224;
    int n228;
} S_4C7228;

LINKER_REMNANT("asm/levels", func_L01_004C6618);

/* localdecomp:start func_L01_004C6620 */
typedef struct {
    s32 x,y,z;
    u16 width,height;
} Box_004C6620;
typedef struct {
    f32 x,y;
    u8 pad8[0x1E - 8];
    u16 mask;
    u8 pad20[0x1190-0x20];
} Sector_004C6620;
__asm__(".extern D_L01_001E1098, 16");
extern s32 D_L01_001E1098[] __attribute__((section(".sdata")));
extern Box_004C6620 *D_L01_001E1094;
__asm__(".extern D_L01_001E1090, 16");
extern Sector_004C6620 *D_L01_001E1090;
__asm__(".extern D_L01_001DAEA8, 16");
extern f32 D_L01_001DAEA8[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DAEB0, 16");
extern f32 D_L01_001DAEB0[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DAEAC, 16");
extern f32 D_L01_001DAEAC[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DAEB4, 16");
extern f32 D_L01_001DAEB4[] __attribute__((section(".sdata")));
s32 func_L01_004C6620(f32 x,f32 y,f32 z)
{
    s32 iy=(s32)(y*1024.0f);
    s32 iz=(s32)(z*1024.0f);
    s32 ix=(s32)(x*1024.0f);
    s32 i=0;
    Box_004C6620 *b=D_L01_001E1094;
    Sector_004C6620 *s;
    if (D_L01_001E1098[0]>0) {
    f32 offsetX=D_L01_001DAEA8[0];
    f32 scaleX=D_L01_001DAEB0[0];
    f32 offsetY=D_L01_001DAEAC[0];
    f32 scaleY=D_L01_001DAEB4[0];
    s=D_L01_001E1090;
    do {
        if (ix>=b->x && iy>=b->y && iz>=b->z && ix<b->x+b->width && iy<b->y+b->height && iz<b->z+2048) {
            s32 cx=(s32)((x-(s->x+offsetX))/scaleX);
            s32 cy=(s32)((y-(s->y+offsetY))/scaleY);
            if ((s32)(s->mask & (u16)(1U<<(((cx>>2)&3)|(cy&12)))) > 0) return i;
        }
        i++;s++;b++;
    } while(i<D_L01_001E1098[0]);
    }
    return -1;
}
/* localdecomp:end func_L01_004C6620 */

LINKER_REMNANT("asm/levels", func_L01_004C6788);

/* localdecomp:start func_L01_004C67A0 */
#include "vu0.h"
typedef struct {
    f32 grid[16][16];
    f32 s[16];
    f32 e[16];
    f32 n[16];
    f32 w[16];
    f32 n2[16];
    f32 w2[16];
    f32 c[6];
    u8 pad598[0x28];
} Layer_004C67A0;
typedef struct {
    f32 x, y, z;
    u8 nb[8];
    u8 pad14[0x3C];
    Layer_004C67A0 b[3];
} Tile_004C67A0;
extern s32 D_L01_001DAE80 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DAE80, 4");
extern s32 D_L01_001DAE88 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DAE88, 4");

void func_L01_004C67A0(Tile_004C67A0 *tile, s32 count, s32 add, f32 x, f32 y, f32 radius, f32 strength) {
    Tile_004C67A0 *tiles = tile;
    s32 row, col;
    s32 k;

    for (k = 0; k < count; k++, tile++) {
        f32 oy;
        f32 cy = (y - (tile->y + D_L01_001DAEA8[1])) / D_L01_001DAEA8[3];
        f32 cx = (x - (tile->x + D_L01_001DAEA8[0])) / D_L01_001DAEA8[2];
        s32 ymin = (s32)(cy - radius);
        s32 ymax = (s32)(cy + radius);
        s32 xmin = (s32)(cx - radius);
        s32 xmax = (s32)(cx + radius);
        if (ymin < 0) ymin = 0;
        if (ymax > 15) ymax = 15;
        if (xmax > 15) xmax = 15;
        if (xmin < 0) xmin = 0;
        oy = tile->y + D_L01_001DAEA8[1] + D_L01_001DAEA8[3] * ymin;
        for (row = ymin; row <= ymax; row++) {
            f32 ox = tile->x + D_L01_001DAEA8[0] + D_L01_001DAEA8[2] * xmin;
            for (col = xmin; col <= xmax; col++) {
                f32 d = (x - ox) * (x - ox) + (y - oy) * (y - oy);
                f32 v;
                if (d < 1.0f) v = strength;
                else v = strength / sqrt_asm(d);
                if (add == 0) {
                    f32 old = tile->b[D_L01_001DAE80].grid[row][col];
                    if (fabs_asm(v) < fabs_asm(old)) v = old;
                } else {
                    v += tile->b[D_L01_001DAE88].grid[row][col];
                }
                tile->b[D_L01_001DAE80].grid[row][col] = v;
                if (row < 2 && tile->nb[0] != 255) {
                    if (row == 0) tiles[tile->nb[0]].b[D_L01_001DAE80].n[col] = tile->b[D_L01_001DAE80].grid[0][col];
                    else tiles[tile->nb[0]].b[D_L01_001DAE80].n2[col] = tile->b[D_L01_001DAE80].grid[row][col];
                }
                if (col < 2 && tile->nb[1] != 255) {
                    if (col == 0) tiles[tile->nb[1]].b[D_L01_001DAE80].w[row] = tile->b[D_L01_001DAE80].grid[row][0];
                    else tiles[tile->nb[1]].b[D_L01_001DAE80].w2[row] = tile->b[D_L01_001DAE80].grid[row][col];
                }
                if (row == 15 && tile->nb[2] != 255) tiles[tile->nb[2]].b[D_L01_001DAE80].s[col] = tile->b[D_L01_001DAE80].grid[row][col];
                if (col == 15 && tile->nb[3] != 255) tiles[tile->nb[3]].b[D_L01_001DAE80].e[row] = tile->b[D_L01_001DAE80].grid[row][col];
                if (tile->nb[4] != 255) {
                    if (col == 0 && row == 0) tiles[tile->nb[4]].b[D_L01_001DAE80].c[3] = tile->b[D_L01_001DAE80].grid[0][0];
                    if (col == 1 && row == 0) tiles[tile->nb[4]].b[D_L01_001DAE80].c[4] = tile->b[D_L01_001DAE80].grid[0][1];
                    if (col == 0 && row == 1) tiles[tile->nb[4]].b[D_L01_001DAE80].c[5] = tile->b[D_L01_001DAE80].grid[1][0];
                }
                if (tile->nb[5] != 255 && col == 15 && row == 0) tiles[tile->nb[5]].b[D_L01_001DAE80].c[2] = tile->b[D_L01_001DAE80].grid[0][15];
                if (tile->nb[6] != 255 && col == 0 && row == 15) tiles[tile->nb[6]].b[D_L01_001DAE80].c[1] = tile->b[D_L01_001DAE80].grid[15][0];
                if (tile->nb[7] != 255 && col == 15 && row == 15) tiles[tile->nb[7]].b[D_L01_001DAE80].c[0] = tile->b[D_L01_001DAE80].grid[15][15];
                ox += D_L01_001DAEA8[2];
            }
            oy += D_L01_001DAEA8[3];
        }
    }
}
/* localdecomp:end func_L01_004C67A0 */

/* localdecomp:start func_L01_004C6D40 */
typedef struct {
    f32 grid[16][16];
    u8 pad400[0x80];
    f32 edgeY[16];
    f32 edgeX[16];
    u8 pad500[0x8C];
    f32 corner;
    u8 pad590[0x30];
} Layer_004C6D40;
typedef struct {
    f32 x, y, z;
    u8 padC[0x50 - 0xC];
    Layer_004C6D40 cells[3];
    u8 pad[0x1190 - 0x50 - 3 * 0x5C0];
} Tile_004C6D40;
extern s32 D_L01_001DAE88 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DAE88, 4");
extern s32 func_L01_004C6620(f32, f32, f32);
extern void func_0038CE90(Vec4_004C4AD8 *, Vec4_004C4AD8 *, T_004C4AD8 *);
extern void func_0038CF68(Vec4_004C4AD8 *, Vec4_004C4AD8 *, f32);

s32 func_L01_004C6D40(f32 *height, Vec4_004C4AD8 *normal, f32 x, f32 y, f32 z) {
    Vec4_004C4AD8 dx, dy;
    Tile_004C6D40 *tile;
    f32 *grid;
    s32 off;
    s32 idx, ix, iy, layer;
    f32 rx, ry, u, v, a, b, c, d, bottom, top;

    idx = func_L01_004C6620(x, y, z);
    if (idx < 0) return 0;
    tile = (Tile_004C6D40 *)&D_L01_001E1090[idx];
    rx = x - (tile->x + D_L01_001DAEA8[0]);
    ry = y - (tile->y + D_L01_001DAEA8[1]);
    ix = (s32)(rx / D_L01_001DAEA8[2]);
    iy = (s32)(ry / D_L01_001DAEA8[3]);
    u = (rx - (f32)ix * D_L01_001DAEA8[2]) / D_L01_001DAEA8[2];
    v = (ry - (f32)iy * D_L01_001DAEA8[3]) / D_L01_001DAEA8[3];
    grid = tile->cells[0].grid[0];
    off = D_L01_001DAE88 * 0x5C0;
    layer = D_L01_001DAE88;
    a = *(f32 *)((u8 *)grid + ((ix << 2) + (iy << 6) + off));
    if (ix == 15) b = *(f32 *)((u8 *)tile + ((iy << 2) + off) + 0x510);
    else b = *(f32 *)((u8 *)grid + (((ix + 1) << 2) + (iy << 6) + off));
    if (iy == 15) c = tile->cells[layer].edgeY[ix];
    else c = tile->cells[layer].grid[iy + 1][ix];
    if (ix == 15) {
        if (iy == 15) d = tile->cells[layer].corner;
        else d = tile->cells[layer].edgeX[iy + 1];
    } else {
        if (iy == 15) d = tile->cells[layer].edgeY[ix + 1];
        else d = tile->cells[layer].grid[iy + 1][ix + 1];
    }
    if (height) {
        bottom = a + (b - a) * u;
        top = c + (d - c) * u;
        *height = bottom + (top - bottom) * v + tile->z;
    }
    if (normal) {
        dx.x = D_L01_001DAEA8[2]; dx.y = 0.0f; dx.z = b - a; dx.w = 1.0f;
        dy.x = 0.0f; dy.y = D_L01_001DAEA8[3]; dy.z = c - a; dy.w = 1.0f;
        func_0038CE90(normal, &dx, (T_004C4AD8 *)&dy);
        func_0038CF68(normal, normal, 1.0f);
    }
    return 1;
}
/* localdecomp:end func_L01_004C6D40 */

LINKER_REMNANT("asm/levels", func_L01_004C7028);

INCLUDE_ASM("asm/levels", func_L01_004C70A8);

INCLUDE_ASM("asm/levels", func_L01_004C7438);

INCLUDE_ASM("asm/levels", func_L01_004C7A18);

/* localdecomp:start func_L01_004C7D40 */
#include "vu0.h"
extern void func_L01_004C7D98(void *, void *);
extern void func_0038CE20(Vec4_004C4AD8 *, Vec4_004C4AD8 *, f32);

void func_L01_004C7D40(void *obj, f32 *pos, f32 s) {
    Vec4_004C4AD8 v;

    func_L01_004C7D98(obj, &v);
    func_0038CE20(&v, &v, s);
    vec_sub_ab(pos, pos, &v);
}
/* localdecomp:end func_L01_004C7D40 */

/* localdecomp:start func_L01_004C7D98 */
#include "vu0.h"
extern void func_0038CF68(Vec4_004C4AD8 *, Vec4_004C4AD8 *, f32);
extern S_4C4A18 D_001A4BE0;
__asm__(".extern D_L01_001D6740, 4");
__asm__(".extern D_L01_001D673C, 4");
extern s32 D_L01_001D6740;
extern s32 D_L01_001D673C;
extern u8 D_L01_001D6750[];
void func_L01_004C7D98(void *position, void *out) {
    f32 sign;
    s32 mode;
    if (D_001A4BE0.x368 != 0) {
        mode = D_L01_001D6740;
        if (mode == 0) {
            *(u128_4C4A18 *)out = *(u128_4C4A18 *)(D_001A4BE0.x25C0 + 0xE0);
            return;
        }
    } else {
        mode = D_L01_001D6740;
    }
    if (mode != 0) {
        {
            vu0_q qa, qb, qr;
            __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)position));
            __asm__("lqc2 %0, D_L01_001D6750" : "=j"(qa));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
            __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)out) : "j"(qr));
        }
        ((f32 *)out)[2] = 0.0f;
        func_0038CF68(out, out, 1.0f);
    } else if (D_L01_001D673C != 0) {
        sign = 1.0f;
        if (*(f32 *)((u8 *)&D_001A4BE0 + 0xBC) > 0.0f) sign = -1.0f;
        vec_sub_ba(out, (u8 *)&D_001A4BE0 + 0xB0, position);
        func_0038CF68(out, out, sign);
    } else {
        __asm__ __volatile__("vmr32.xyzw $vf1, $vf0\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)out) : : "vf1");
    }
}
/* localdecomp:end func_L01_004C7D98 */

INCLUDE_ASM("asm/levels", func_L01_004C7E70);

/* localdecomp:start func_L01_004C80D0 */

extern Ent_4C4520 D_L01_0024E5E0[];

Ent_4C4520 *func_L01_004C80D0(u32 a0) {
    Ent_4C4520 *r = 0;
    if (a0 < 64) {
        r = &D_L01_0024E5E0[a0];
    }
    return r;
}
/* localdecomp:end func_L01_004C80D0 */

/* localdecomp:start func_L01_004C80F8 */
extern Ent_4C4520 D_L01_0024E5E0[];

extern void func_L01_0043A430(s32, s32, Slot *);

s32 func_L01_004C80F8(s32 owner, s32 arg1) {
    Slot *e;
    s32 i;

    for (i = 0; i < 64; i++) {
        e = &((Slot *)&D_L01_0024E5E0)[i];
        if (e->owner == 0) {
            e->w4 = -1;
            e->owner = owner;
            e->b3 = 0;
            e->b0 = 0;
            e->w12 = 0;
            e->w8 = 0;
            e->w16 = 0;
            e->w20 = 0;
            e->w24 = 0;
            e->w28 = 0;
            e->w48 = 0;
            e->w52 = 0;
            e->w56 = 0;
            e->w60 = 0;
            e->b2 = 0;
            e->w32 = 0;
            e->w36 = 0;
            e->w40 = 0;
            e->w44 = 0;
            e->b1 = 0;
            func_L01_0043A430(owner, arg1, e);
            goto out;
        }
    }
out:
    return i;
}
/* localdecomp:end func_L01_004C80F8 */

/* localdecomp:start func_L01_004C81A8 */
extern Ent_4C4520 D_L01_0024E5E0[];

extern void func_003C2C98(s32, Ent_004C45F8 *);

void func_L01_004C81A8(u32 i) {
    Ent_004C45F8 *e;

    if (i < 64) {
        e = &((Ent_004C45F8 *)&D_L01_0024E5E0)[i];
        func_003C2C98(e->handle, e);
        e->handle = 0;
    }
}
/* localdecomp:end func_L01_004C81A8 */

/* localdecomp:start func_L01_004C81F0 */
/* func_L01_004C81F0: insert into a 16-byte table of 32 entries (w0, w4, pad8[0]), first free slot */
extern E_4C46A8 D_L01_0024F9E0[];

void func_L01_004C81F0(s32 a0, s32 a1, s32 a2) {
    s32 i = 0;
    E_4C46A8 *e;

    if (D_L01_0024F9E0[0].w4 == 0) {
        D_L01_0024F9E0[0].w0 = a1;
        D_L01_0024F9E0[0].w4 = a0;
        D_L01_0024F9E0[0].pad8[0] = a2;
        return;
    }
loop:
    i++;
    if (i >= 32) {
        return;
    }
    if (D_L01_0024F9E0[i].w4 != 0) {
        goto loop;
    }
    e = &D_L01_0024F9E0[i];
    e->w4 = a0;
    e->w0 = a1;
    e->pad8[0] = a2;
}
/* localdecomp:end func_L01_004C81F0 */

/* localdecomp:start func_L01_004C8258 */

extern E_4C46A8 D_L01_0024F9E0[];

s32 func_L01_004C8258(s32 a0, s32 a1) {
    s32 i;
    s32 r = 1;
    for (i = 0; i < 32; i++) {
        if (D_L01_0024F9E0[i].w4 == a0 && D_L01_0024F9E0[i].w0 == a1) {
            r = 0;
            break;
        }
    }
    return r;
}
/* localdecomp:end func_L01_004C8258 */

/* localdecomp:start func_L01_004C82C0 */
extern E_4C46A8 D_L01_0024F9E0[];
s32 func_L01_004C82C0(s32 b, s32 a) {
    s32 i;
    for (i = 0; i < 32; i++) {
        if (((Unk24FA60 *)&D_L01_0024F9E0)[i].b == b && ((Unk24FA60 *)&D_L01_0024F9E0)[i].a == a) {
            return ((Unk24FA60 *)&D_L01_0024F9E0)[i].c;
        }
    }
    return -1;
}
/* localdecomp:end func_L01_004C82C0 */

/* localdecomp:start func_L01_004C8308 */
extern s32 func_L01_004C82C0(s32 b, s32 a);

s32 func_L01_004C8308(void *ctx, s32 *list, s32 n, s32 type) {
    s32 best = 0;
    s32 bestd = 9999;
    s32 d;
    s32 i;

    for (i = 0; i < n; i++) {
        if (type <= 0 || *(u8 *)(*(s32 *)(list[i] + 36) + 70) == type) {
            d = ((s32 (*)(void *, s32))func_L01_004C82C0)(ctx, list[i]);
            if (d < bestd && d != -1) {
                best = list[i];
                bestd = d;
            }
        }
    }
    return best;
}
/* localdecomp:end func_L01_004C8308 */

/* localdecomp:start func_L01_004C83D0 */
extern s32 func_L01_004C8308(void *ctx, s32 *list, s32 n, s32 type);
extern s32 func_L01_004C8258(s32 a0, s32 a1);

u8 *func_L01_004C83D0(void *a, u8 **list, s32 n, s32 *out, s32 type) {
    s32 i;
    u8 *r;

    *out = 1;
    for (i = 0; i < n; i++) {
        if (type > 0 && (*(u8 **)(list[i] + 36))[70] != type) {
            continue;
        }
        if (((s32 (*)(void *, u8 *))func_L01_004C8258)(a, list[i]) == 1) {
            return list[i];
        }
    }
    if (n < 2) {
        return 0;
    }
    r = ((u8 * (*)(void *, u8 **, s32, s32))func_L01_004C8308)(a, list, n, type);
    if (r != 0) {
        *out = 0;
    }
    return r;
}
/* localdecomp:end func_L01_004C83D0 */

/* localdecomp:start func_L01_004C84D8 */
static __inline__ void expire_004C84D8(E_4C46A8 *entry)
{
    extern s32 func_0038CAD0(void *);
    u8 *m = (u8 *)entry->w0;
    if (m == 0 || m[0x20] == 254 || m[0x20] == 253) {
        entry->w4 = 0;
        return;
    }
    if (func_0038CAD0(&entry->pad8[0])) entry->w4 = 0;
}
void func_L01_004C84D8(s32 owner)
{
    s32 i;
    for (i = 0; i < 32; i++) {
        if (D_L01_0024F9E0[i].w4 == owner) {
            if (*(u16 *)((u8 *)D_L01_0024F9E0[i].w0 + 0x34) & 0x1000) {
                expire_004C84D8(&D_L01_0024F9E0[i]);
            } else D_L01_0024F9E0[i].w4 = 0;
        }
    }
}
/* localdecomp:end func_L01_004C84D8 */

/* localdecomp:start func_L01_004C8598 */
void func_L01_004C8598(s32 a0) {
    s32 i;

    for (i = 0; i < 32; i++) {
        if (D_L01_0024F9E0[i].w4 == a0) {
            D_L01_0024F9E0[i].w4 = 0;
        }
    }
}
/* localdecomp:end func_L01_004C8598 */

/* localdecomp:start func_L01_004C85C8 */



extern void func_003C5180(u128_4C4A18 *, E_4C4A18 *, s32);
extern E_4C4A18 D_L01_00250100[];
extern S_4C4A18 D_001A4BE0;

s32 func_L01_004C85C8(u8 *a0, u128_4C4A18 *a1, f32 f12, f32 f13, f32 f14) {
    u128_4C4A18 v;
    E_4C4A18 *e = D_L01_00250100;
    s32 i;
    for (i = 0; i < 128; i++, e++) {
        if (e->x1C == 0) {
            if (a1 != 0) {
                v = *a1;
            } else {
                v = *(u128_4C4A18 *)(a0 + 16);
            }
            e->x1C = a0;
            e->x10 = f12;
            e->x14 = f13;
            e->x18 = f14;
            if (D_001A4BE0.x368 != 0) {
                e->pos = *(u128_4C4A18 *)(D_001A4BE0.x25C0 + 224);
            } else {
                func_003C5180(&v, e, 1);
            }
            return i;
        }
    }
    return -1;
}
/* localdecomp:end func_L01_004C85C8 */

/* localdecomp:start func_L01_004C8668 */
extern int func_0011A930(int, void (*)(void), int);

/* from rac2-decomp's func_002FEE50, renamed */
void func_L01_004C8668(int index) {
    int *p;
    if (index < 0) return;
    p = (int *)((unsigned int)D_L01_00250100 + (index << 5));
    p[7] = 0;
}
/* localdecomp:end func_L01_004C8668 */

/* localdecomp:start func_L01_004C8688 */
extern S_4C4A18 D_001A4BE0;
extern E_4C4A18 D_L01_00250100[];
extern void func_003C5180(u128_4C4A18 *, E_4C4A18 *, s32);





extern f32 func_0038CEA8(Vec4_004C4AD8 *);
extern void func_0038CF68(Vec4_004C4AD8 *, Vec4_004C4AD8 *, f32);
extern void func_0038CE90(Vec4_004C4AD8 *, Vec4_004C4AD8 *, T_004C4AD8 *);
extern f32 func_0038CE68(Vec4_004C4AD8 *, T_004C4AD8 *);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_0038CE20(Vec4_004C4AD8 *, Vec4_004C4AD8 *, f32);
extern void func_0038D688(Vec4_004C4AD8 *, Vec4_004C4AD8 *, Vec4_004C4AD8 *);
extern s32 D_L01_001D673C;
extern s32 D_L01_001D6740;
extern s16 D_001A4F48[];
extern s32 D_001A6290[];

void func_L01_004C8688(s32 idx, Vec4_004C4AD8 *r, Vec4_004C4AD8 *target) {
    Vec4_004C4AD8 q;
    Vec4_004C4AD8 d;
    Vec4_004C4AD8 a;
    Vec4_004C4AD8 b;
    Vec4_004C4AD8 c;
    Vec4_004C4AD8 tgt;
    T_004C4AD8 *t;
    f32 k;
    f32 len;
    f32 w;
    f32 h;
    f32 s;

    if (idx < 0) {
        return;
    }
    if (D_L01_001D673C == 0) {
        if (D_L01_001D6740 == 0 && D_001A4F48[0] == 0) {
            return;
        }
    } else if (D_001A6290[0] > 0) {
        return;
    }
    t = &((T_004C4AD8 *)&D_L01_00250100)[idx];
    k = 1.0f;
    if (target != 0) {
        tgt = *target;
    } else {
        if (t->x1C == 0) {
            return;
        }
        tgt = t->x1C->x10;
    }
    if ((*(S_004C4AD8 *)&D_001A4BE0).x368 != 0) {
        if (D_L01_001D6740 != 0) {
            k = t->x14;
        } else {
            k = t->x18;
        }
    } else if (D_L01_001D6740 != 0) {
        k = t->x14;
    }
    if (D_L01_001D673C != 0) {
        k = t->x10;
    }
    q = t->x0;
    w = r->w;
    r->w = 0.0f;
    len = func_0038CEA8(r);
    if ((*(S_004C4AD8 *)&D_001A4BE0).x368 != 0 && D_L01_001D6740 == 0) {
        t->x0 = (*(S_004C4AD8 *)&D_001A4BE0).x25C0->xE0;
    } else {
        ((void (*)(Vec4_004C4AD8 *, T_004C4AD8 *, s32))func_003C5180)(&tgt, t, 1);
    }
    func_0038CF68(r, r, 1.0f);
    func_0038CE90(&d, &q, t);
    h = -func_0038CE68(&q, t) * 0.5f * k;
    func_0038CE20(&a, &d, func_0038D0B0(h));
    s = func_0038D098(h);
    a.w = s;
    b.x = -a.x;
    b.y = -a.y;
    b.z = -a.z;
    b.w = s;
    func_0038D688(&c, &a, r);
    func_0038D688(r, &c, &b);
    func_0038CF68(r, r, len);
    r->w = w;
}
/* localdecomp:end func_L01_004C8688 */

/* localdecomp:start func_L01_004C88C8 */
extern s32 D_L01_001DAFEC;
__asm__(".extern D_L01_001DAFEC, 4");
extern s32 D_L01_0024FFF0[];
typedef struct { u8 pad[0x400]; s32 count; } Table_004C88C8;
extern Table_004C88C8 D_L01_0024FBE0;
extern s32 D_L01_001DDBB0;
extern s32 D_L01_001E2360[] __attribute__((section(".sdata")));
extern s32 D_L01_001E10E0[] __attribute__((section(".sdata")));
extern s32 D_L01_001DD9A0;
extern s32 D_L01_001E10D0[] __attribute__((section(".sdata")));
extern s32 D_L01_001E1A24[] __attribute__((section(".sdata")));
typedef struct { u8 pad[0xD4]; u8 state; } State_004C88C8;
extern State_004C88C8 D_001426E0;
extern Obj_4C5DE0 *D_L01_001E1138;
extern float D_L01_001E1140_004C88C8;
extern s32 D_L01_001E1144;
extern u8 D_L01_001DFCF2, D_L01_001DFCF3;
void func_L01_004C88C8(void) {
    extern void func_L01_0030A140(void);
    extern void func_L01_00343650(void);
    extern void func_L01_00344A58(void);
    extern void func_L01_003119D8(void);
    extern void func_L01_003185E8(void);
    extern void func_L01_0032C9F0(void);
    extern void func_L01_0032FB18(void);
    extern void func_L01_00350688(void);
    extern void func_L01_003916E0(void);
    extern void func_L01_00392A78(void);
    extern void func_L01_003C3830(void);
    extern void func_L01_0031B3A0(void);
    extern void func_L01_0034CEB8(void);
    extern Obj_4C5DE0 *func_L01_00303D30(void *, s32);
    extern void func_L01_004CB068(void);
    Slot *p;
    s32 i;
    Vec4_004C4AD8 v;
    Obj_4C5DE0 *object;
    D_L01_001DAFEC = 0;
    p = (Slot *)D_L01_0024E5E0;
    do {
        p->b1 = 0;
        p->owner = 0;
        p++;
    } while ((s32)p < (s32)(D_L01_0024E5E0 + 64));
    for (i = 31; i >= 0; i--) D_L01_0024F9E0[i].w4 = 0;
    for (i = 127; i >= 0; i--) D_L01_00250100[i].x1C = 0;
    for (i = 0; i < 64; i++) D_L01_0024FFF0[i] = -1;
    D_L01_0024FFF0[64] = 0;
    D_L01_0024FBE0.count = 0;
    func_L01_0030A140();
    func_L01_00343650();
    func_L01_00344A58();
    func_L01_003119D8();
    func_L01_003185E8();
    func_L01_0032C9F0();
    func_L01_0032FB18();
    func_L01_00350688();
    func_L01_003916E0();
    func_L01_00392A78();
    func_L01_003C3830();
    D_L01_001DDBB0 = 1;
    for (i = 11; i >= 0; i--) D_L01_001E2360[i] = 0;
    for (i = 5; i >= 0; i--) D_L01_001E10E0[i] = 0;
    D_L01_001DD9A0 = 0;
    for (i = 3; i >= 0; i--) D_L01_001E10D0[i] = 0;
    {
        s32 *q = D_L01_001E1A24;
        s32 j = 8;
        do { *q++ = 0; } while (--j >= 0);
    }
    func_L01_0031B3A0();
    func_L01_0034CEB8();
    *(u128_4C4A18 *)&v = 0;
    D_001426E0.state = 30;
    v.x = 5.0f;
    v.y = 5.0f;
    v.z = 5.0f;
    v.w = 1.0f;
    object = func_L01_00303D30(&v, 0);
    D_L01_001E1138 = object;
    *(s32 *)((u8 *)object + 0x98) = 0;
    *(u16 *)((u8 *)object + 0x34) |= 2;
    D_L01_001E1140_004C88C8 = 0;
    D_L01_001E1144 = 0;
    func_L01_004CB068();
    D_L01_001DFCF2 = 0;
    D_L01_001DFCF3 = 0;
}
/* localdecomp:end func_L01_004C88C8 */

/* localdecomp:start func_L01_004C8B38 */
extern Ent_004C4F88 D_L01_002C5600[];
extern u8 D_0014261F[];
extern void func_L01_0032CA80(void);
extern void func_L01_0032FB80(void);
extern void func_L01_004C9030(void);
extern void func_L01_004C8BA0(void);
extern void func_L01_004C8DD0(void);
void func_L01_004C8B38(void) {
    func_L01_0032CA80();
    func_L01_0032FB80();
    if ((D_0014261F[0] + D_L01_002C5600)->b) func_L01_004C9030();
    func_L01_004C8BA0();
    func_L01_004C8DD0();
}
/* localdecomp:end func_L01_004C8B38 */

/* localdecomp:start func_L01_004C8BA0 */
extern S_4C4A18 D_001A4BE0;
extern void func_L01_004C8D28(void);
void func_L01_004C8BA0(void) {
    u8 *p = ((u8 *)&D_001A4BE0);
    if (*(s32 *)(p + 4648) != 127 || *(u8 *)(p + 9700) == 3) {
        func_L01_004C8D28();
    }
}
/* localdecomp:end func_L01_004C8BA0 */

/* localdecomp:start func_L01_004C8BE8 */
extern S_4C4A18 D_001A4BE0;


extern s32 D_L01_001D6694;
extern s32 D_L01_001DD298;
extern Ent_004C5038 D_L01_0028CAA0[];
extern void func_L01_00323300(s32);
extern f32 func_L01_004C93D8_004C8BE8(void);
extern void func_L01_003438C0(s32);
extern void func_00382810(s32, s32, s32, f32, f32, f32, f32);
extern void func_L01_004B14C8(s32);

void func_L01_004C8BE8(void) {
    s32 i;

    if ((*(Game_004C5038 *)&D_001A4BE0).f4648 == 71 && D_L01_001D6694 == 6) {
        func_L01_00323300((*(Game_004C5038 *)&D_001A4BE0).f4608);
    }
    if (func_L01_004C93D8_004C8BE8() != 0.0f && D_L01_001D6694 != 0 && D_L01_001DD298 != 0) {
        func_L01_003438C0(D_L01_001DD298);
    }
    if ((*(Game_004C5038 *)&D_001A4BE0).f4648 == 135 && D_L01_001D6694 != 0) {
        for (i = 199; i >= 0; i--) {
            D_L01_0028CAA0[i].f28 = 0;
        }
    }
    if ((*(Game_004C5038 *)&D_001A4BE0).f4648 == 111 && D_L01_001D6694 == 8) {
        func_00382810(0, 0, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
        func_L01_004B14C8(1);
    }
}
/* localdecomp:end func_L01_004C8BE8 */

/* localdecomp:start func_L01_004C8D28 */
extern u8 *D_L01_001E1A24_004C8D28[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001E1A24_004C8D28, 36");
extern s32 D_L01_001DD65C;
__asm__(".extern D_L01_001DD65C, 16");
void func_L01_004C8D28(void) {
    extern void func_003C2880(void *);
    extern void func_L01_00424D88(s32);
    u8 **slot = D_L01_001E1A24_004C8D28;
    s32 i;
    for (i = 8; i >= 0; i--, slot++) {
        u8 *p = *slot;
        if (p != 0 && p[0x20] != 0xFE && p[0x20] != 0xFD) {
            func_003C2880(p);
            *slot = 0;
        }
    }
    if (D_L01_001DD65C != -1) {
        func_L01_00424D88(D_L01_001DD65C);
        D_L01_001DD65C = -1;
    }
}
/* localdecomp:end func_L01_004C8D28 */

INCLUDE_ASM("asm/levels", func_L01_004C8DD0);

INCLUDE_ASM("asm/levels", func_L01_004C9030);

/* localdecomp:start func_L01_004C9360 */
extern f32 D_L01_001E1140_004C9360;
extern s32 D_L01_001E1144;

f32 func_L01_004C9360(f32 fparg0) {
    f32 temp;
    f32 var_f1 = 0.0f;

    if (D_L01_001E1144 != 0) {
        return 0.0f;
    }
    temp = D_L01_001E1140_004C9360 - fparg0;
    D_L01_001E1140_004C9360 = temp;
    if (temp < 0.0f) {
        var_f1 = -temp;
        *(s32 *)&D_L01_001E1140_004C9360 = 0;
    }
    D_L01_001E1144 = 12;
    return var_f1;
}
/* localdecomp:end func_L01_004C9360 */

/* localdecomp:start func_L01_004C93B0 */
extern s32 func_0038CAD0(void *);

void func_L01_004C93B0(void) {
    func_0038CAD0(&D_L01_001E1144);
}
/* localdecomp:end func_L01_004C93B0 */

/* localdecomp:start func_L01_004C93D8 */
extern float D_L01_001E1140;
float func_L01_004C93D8(void) {
    return D_L01_001E1140;
}
/* localdecomp:end func_L01_004C93D8 */

/* localdecomp:start func_L01_004C93E0 */
/* shield_charger_points: the Shield Charger's points for a gun level (0 is V1): 225, then 75
   more a level, 750 at Omega; and no hit cooldown (D_L01_001E1144). */
/* the points, under an alias: in some levels func_L01_004C93D8's D_L01_001E1140 is another
   variable than this function's (levels 13, 18 and 26) */
extern f32 D_L01_001E1140_004C93E0;
void func_L01_004C93E0(s32 level) {
    if (level == 7) {
        D_L01_001E1140_004C93E0 = 750.0f;
    } else if (level == 6) {
        D_L01_001E1140_004C93E0 = 675.0f;
    } else if (level == 5) {
        D_L01_001E1140_004C93E0 = 600.0f;
    } else if (level == 4) {
        D_L01_001E1140_004C93E0 = 525.0f;
    } else if (level == 3) {
        D_L01_001E1140_004C93E0 = 450.0f;
    } else if (level == 2) {
        D_L01_001E1140_004C93E0 = 375.0f;
    } else if (level == 1) {
        D_L01_001E1140_004C93E0 = 300.0f;
    } else {
        D_L01_001E1140_004C93E0 = 225.0f;
    }
    D_L01_001E1144 = 0;
}
/* localdecomp:end func_L01_004C93E0 */

/* localdecomp:start func_L01_004C94B0 */
void func_L01_004C94B0(void) {
    *(s32 *)&D_L01_001E1140_004C9360 = 0;
    D_L01_001E1144 = 0;
}
/* localdecomp:end func_L01_004C94B0 */

/* localdecomp:start func_L01_004C94C0 */
extern s32 func_003A0EC0(s32, s32, s32, s32, u8 *);
extern short D_L01_001E1108;
extern short D_L01_001E110A;

/* from rac2-decomp's func_L00_0037E6A8, renamed */
void func_L01_004C94C0(int x, int y)
{
    D_L01_001E1108 = x;
    D_L01_001E110A = y;
    func_003A0EC0(8, 2, 0, 0, 0);
}
/* localdecomp:end func_L01_004C94C0 */

INCLUDE_ASM("asm/levels", func_L01_004C9500);

/* localdecomp:start func_L01_004C97C8 */
extern s32 D_L01_001E0280;
extern u8 *D_L01_001E0278;
extern void func_003CD250(void *);
void func_L01_004C97C8(void) {
    s32 i;
    u8 *p;
    for (i = 0; i <= D_L01_001E0280; i++) {
        p = D_L01_001E0278 + (i << 6);
        if ((*(long *)p & 0x80FF) == 0xFF) {
            func_003CD250(p);
        }
    }
}
/* localdecomp:end func_L01_004C97C8 */

/* localdecomp:start func_L01_004C9848 */
extern void func_003C25D8(void *);
extern void func_0038CB78(void *, s32, s32);
extern void func_003C7C38(void *);

void func_L01_004C9848(u8 *a0) {
    void *p = *(void **)(a0 + 104);
    func_003C25D8(a0);
    *(void **)(a0 + 104) = p;
    func_0038CB78(p, 0, 128);
    if (!(*(u16 *)(a0 + 52) & 4)) {
        func_003C7C38(a0);
    }
}
/* localdecomp:end func_L01_004C9848 */

/* localdecomp:start func_L01_004C98A8 */
#include "vu0.h"
extern Obj_4C5DE0 *D_L01_001E1138;
extern void func_L01_004C9848_004C98A8(u8 *a0, s32 kind);
extern void func_003C3938(void *, s32, s32);
extern void func_003C7C38(void *);

u8 *func_L01_004C98A8(s32 kind, s32 animation, u8 *object) {
    u8 *p = (u8 *)D_L01_001E1138;
    if (object) p = object;
    func_L01_004C9848_004C98A8(p, kind);
    *(u16 *)(p + 0x34) &= 0xFFBC;
    qzero(p + 0xF0);
    p[0x30] = 255;
    *(u16 *)(p + 0x32) = 32;
    p[0x31] = 1;
    *(f32 *)(p + 0x10) = 5.0f;
    *(f32 *)(p + 0x14) = 5.0f;
    *(f32 *)(p + 0x18) = 900.0f;
    *(f32 *)(p + 0x1C) = 1.0f;
    if (animation >= 0) func_003C3938(p, animation, 0);
    else if (*(u8 **)(p + 0x24) && (*(u8 **)(p + 0x24))[0xC] >= 2) func_003C3938(p, 1, 0);
    if (!(*(u16 *)(p + 0x34) & 4)) func_003C7C38(p);
    return p;
}
/* localdecomp:end func_L01_004C98A8 */

/* localdecomp:start func_L01_004C99A0 */
extern void func_L01_004C9848(u8 *a0);
extern Obj_4C5DE0 *D_L01_001E1138;
void func_L01_004C99A0(void) {
    Obj_4C5DE0 *o;
    ((void (*)(Obj_4C5DE0 *, s32))func_L01_004C9848)(D_L01_001E1138, 1007);
    o = D_L01_001E1138;
    o->b30 = 255;
    o->h34 |= 0x43;
    o->f98 = 0;
    o->z = 5.0f;
    o->y = 5.0f;
    o->x = 5.0f;
}
/* localdecomp:end func_L01_004C99A0 */

/* localdecomp:start func_L01_004C99F8 */
typedef int Q_004C99F8 __attribute__((mode(TI)));
typedef struct {
    u8 pad00[0x140];
    f32 position[4];
    f32 rotation[4];
    f32 forward[4];
} Cam_004C99F8;
typedef struct {
    u8 pad00[0x34];
    u16 x34;
    u8 pad36[0xF0 - 0x36];
    f32 rot[4];
} Moby_004C99F8;
typedef struct {
    u8 pad[0x76];
    s16 mode0;
    u8 pad78[0x20];
    s16 position;
    u8 pad9A[4];
    s16 mode1;
} Stream_004C99F8;

typedef struct {
    s16 state;
    s16 timer;
    f32 step;
    s16 item;
    s16 item2;
    u8 flag0C;
    u8 flag0D;
    s16 flag0E;
    u8 pad10[0x20];
    u8 *moby;
    u8 flag34;
    u8 flag35;
    s16 fade;
} Ctl_004C99F8;
extern Ctl_004C99F8 D_L01_001E1100 __attribute__((section(".sdata")));
extern s32 D_L01_001DAFE4;
__asm__(".extern D_L01_001DAFE4, 4");
extern s32 D_L01_001DAFE8;
__asm__(".extern D_L01_001DAFE8, 4");
extern s32 D_L01_001DB004;
__asm__(".extern D_L01_001DB004, 4");
extern s32 D_L01_001DB008;
__asm__(".extern D_L01_001DB008, 4");
extern s32 D_L01_001DB00C;
__asm__(".extern D_L01_001DB00C, 4");
extern s32 D_L01_001DB010;
__asm__(".extern D_L01_001DB010, 4");
extern s32 D_L01_001D7B88;
__asm__(".extern D_L01_001D7B88, 4");
extern Cam_004C99F8 D_L01_001E2880;
extern f32 D_L01_001E7630[];
extern Stream_004C99F8 D_001CCFD0;
extern u8 D_001425C0[];
extern s16 D_001A4DC0[];
extern Ent_004C4F88 D_L01_002C5600[];

extern s32 func_0038CB00(void *);
extern void func_L01_00404AD8(void *, s32);
extern void func_L01_004CA3F0(void);
extern void func_L01_004CA6A8(void);
extern void func_003A1798(void);
extern void func_0038D278(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_003873C0(void);
extern void func_L01_004CA088(void *);
extern void func_L01_004CA478(void *);
extern u8 *func_L01_004CA270(u8 *);
extern void func_L01_004CB388(u8 *, s32, s32);
extern void func_L01_004C99A0(void);
extern void func_L01_00418C90(s32, s32);
extern void func_L01_00419318(s32);
extern s32 func_L01_0044CD60(s32);
extern s32 func_003A0EC0(s32, s32, s32, s32, u8 *);
extern void func_00382810(s32, s32, s32, f32, f32, f32, f32);
extern void func_L01_004B14C8(s32);

void func_L01_004C99F8(void) {
    Moby_004C99F8 *m;
    Stream_004C99F8 *s;
    f32 t;

    switch (D_L01_001E1100.state) {
    case 0:
        if (func_0038CB00(&D_L01_001E1100.timer)) {
            if (D_L01_001DAFE4 != 0) {
                s = &D_001CCFD0;
                if (!(s->mode0 == 0 && s->mode1 == 3 && s->position < 7000)) {
                    if (D_L01_001DAFE8++ < 16) goto wait;
                }
            }
            s = &D_001CCFD0;
            if (s->mode0 == 0 && s->mode1 == 3 && s->position < 7000 && D_L01_001DAFE4 != 0) {
                func_003A1798();
                D_L01_001DAFE4 = 0;
            }
            D_L01_001DAFE8 = 0;
            D_L01_001E2880.position[0] = 25.0f;
            D_L01_001E2880.position[1] = 25.0f;
            D_L01_001E2880.position[2] = 900.0f;
            func_0038D278(D_L01_001E2880.forward);
            D_L01_001E1100.state = 1;
            D_L01_001E1100.timer = (D_L01_001DB008 * 5 + 2) / 6;
            D_L01_001E1100.flag0E = 0;
            m = (Moby_004C99F8 *)D_L01_001E1100.moby;
            D_L01_001E2880.rotation[0] = D_L01_001E2880.rotation[1] = D_L01_001E2880.rotation[2] = 0.0f;
            *(Q_004C99F8 *)m->rot = *(Q_004C99F8 *)D_L01_001E2880.rotation;
            if (D_L01_001E1100.flag35) {
                m->rot[1] = func_0038DAB8(m->rot[1], -1.5707964f);
            }
            t = func_0038D0B0(0.55501467f);
            D_L01_001E7630[0] = t / func_0038D098(0.55501467f);
            func_003873C0();
            m->x34 &= 0xFFBE;
            break;
        }
    wait:
        func_L01_00404AD8(func_L01_004CA3F0, 0);
        break;
    case 1:
        func_L01_004CA088(D_L01_001E1100.moby);
        if (func_0038CB00(&D_L01_001E1100.timer)) {
            D_L01_001E1100.state = 2;
            D_L01_001E1100.flag34 = 0;
            D_L01_001E1100.timer = (D_L01_001DB00C * 5 + 2) / 6;
            D_L01_001E1100.step = 1.0f / D_L01_001E1100.timer;
        }
        break;
    case 2: {
        u8 *m2 = D_L01_001E1100.moby;
        func_L01_004CA088(m2);
        func_L01_004CA478(m2);
        if (func_0038CB00(&D_L01_001E1100.timer)) {
            D_L01_001E1100.timer = 2;
            D_L01_001E1100.state = 3;
            D_L01_001E1100.fade = 0x80;
            func_L01_00404AD8(func_L01_004CA6A8, 0);
        }
        break;
    }
    case 3: {
        u8 *m3 = D_L01_001E1100.moby;
        func_L01_00404AD8(func_L01_004CA6A8, 0);
        if (func_0038CB00(&D_L01_001E1100.timer)) {
            D_L01_001E1100.timer = 10;
            D_L01_001E1100.state = 4;
            D_L01_001E1100.moby = func_L01_004CA270(m3);
            func_L01_004CB388(D_L01_001E1100.moby, D_L01_001E1100.item, (D_001425C0[D_L01_001E1100.item] + D_L01_002C5600)->b + 1);
        }
        break;
    }
    case 4:
        if (D_L01_001E1100.moby) func_L01_004CA088(D_L01_001E1100.moby);
        func_L01_00404AD8(func_L01_004CA6A8, 0);
        D_L01_001E1100.fade = (f32)D_L01_001E1100.timer / 12.0f * 128.0f;
        if (func_0038CB00(&D_L01_001E1100.timer)) {
            D_L01_001E1100.fade = 0;
            D_L01_001E1100.state = 5;
            D_L01_001E1100.timer = (D_L01_001DB010 * 5 + 2) / 6;
        }
        break;
    case 5:
        if (D_L01_001E1100.moby) func_L01_004CA088(D_L01_001E1100.moby);
        if (func_0038CB00(&D_L01_001E1100.timer)) {
            D_L01_001E1100.timer = 2;
            D_L01_001E1100.state = 6;
        }
        break;
    case 6:
        if (D_L01_001E1100.moby) func_L01_004CA088(D_L01_001E1100.moby);
        func_L01_00404AD8(func_L01_004CA3F0, 0);
        if (func_0038CB00(&D_L01_001E1100.timer)) {
            Stream_004C99F8 *s6;
            D_L01_001E1100.flag0D = D_L01_001E1100.flag0E = 1;
            D_L01_001E1100.timer = 0;
            D_L01_001E1100.step = 1.0f / ((D_L01_001DB004 * 5 + 2) / 6);
            D_001A4DC0[0] = ((D_L01_001DB004 + 5) * 5 + 2) / 6;
            func_L01_004C99A0();
            D_L01_001E1100.moby = 0;
            func_L01_00418C90(D_L01_001E1100.item, 0);
            s6 = &D_001CCFD0;
            if (s6->mode0 != 6 && s6->mode0 != 7) s6->mode0 = 5;
            if (s6->mode1 != 6 && s6->mode1 != 7) s6->mode1 = 5;
            func_L01_00419318(D_L01_001E1100.item);
            func_L01_0044CD60(D_L01_001E1100.item);
            D_L01_001E1100.state = 7;
        }
        break;
    case 7:
        if (D_L01_001E1100.timer++ >= (D_L01_001DB004 * 5 + 2) / 6) {
            func_003A0EC0(0, 2, 0, 0, 0);
            func_00382810(0, 0, 3, 1.11002934f, 0.00499999989f, 0.200000003f, 0.0f);
            D_L01_001D7B88 = 0xE0;
            func_L01_004B14C8(1);
        } else {
            func_L01_00404AD8(func_L01_004CA3F0, 0);
        }
        break;
    }
}
/* localdecomp:end func_L01_004C99F8 */

INCLUDE_ASM("asm/levels", func_L01_004CA088);

/* localdecomp:start func_L01_004CA270 */
typedef int Q_004CA270 __attribute__((mode(TI)));
typedef struct { u8 pad[8]; s32 slot; u8 pC[4]; s32 id; u8 p14[0xF0 - 0x14]; } R_004CA270;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_004CA270;
typedef struct { u8 pad[0x20]; u8 *moby; u8 pad24[0x50 - 0x24]; } Item_004CA270;
typedef struct { u8 p[0x11E0]; Item_004CA270 items[7]; u8 gap[0x2614 - 0x1410]; s32 slots[7]; } H_004CA270;
extern short D_L01_001E110A;
extern Ent_004C4F88 D_L01_002C5600[];
extern S_4C4A18 D_001A4BE0;
extern s32 D_001D4C40[] __attribute__((section(".sdata")));
extern void func_L01_004C99A0(void);
extern void func_003C2880(void *);
extern s32 func_0039AC08(s32);
extern void func_0039AA38(s32);
extern void func_003A2750(s32);
extern void func_L01_0042D110(s32);

u8 *func_L01_004CA270(u8 *old) {
    s32 item = D_L01_001E110A;
    V_004CA270 pos, rot;
    u8 *m;

    *(Q_004CA270 *)&pos = *(Q_004CA270 *)(old + 0x10);
    *(Q_004CA270 *)&rot = *(Q_004CA270 *)(old + 0xF0);
    if (item == 0xA7 || item == 0xC0 || item == 0xC1 || item == 0xC2 || item == 0xC3 || item == 0xC4 || item == 0xC5) {
        func_L01_004C99A0();
    } else {
        R_004CA270 *r;
        func_003C2880(old);
        r = &((R_004CA270 *)D_L01_002C5600)[item];
        if (!func_0039AC08(r->id)) {
            func_0039AA38(r->id);
            func_003A2750(1);
        }
        func_L01_0042D110(r->id);
    }
    if ((u32)(item - 0x57) < 8) {
        m = func_L01_004C98A8(0x1ADA, 0, 0);
    } else {
        m = func_L01_004C98A8(((R_004CA270 *)D_L01_002C5600)[item].id, -1, 0);
    }
    if (m) {
        s32 slot;
        H_004CA270 *h;
        Item_004CA270 *it;
        *(Q_004CA270 *)(m + 0x10) = *(Q_004CA270 *)&pos;
        *(Q_004CA270 *)(m + 0xF0) = *(Q_004CA270 *)&rot;
        slot = ((R_004CA270 *)D_L01_002C5600)[item].slot;
        h = (H_004CA270 *)&D_001A4BE0;
        D_001D4C40[slot] = 0;
        it = &h->items[slot];
        it->moby = 0;
        h->slots[slot] = 0;
    }
    return m;
}
/* localdecomp:end func_L01_004CA270 */

/* localdecomp:start func_L01_004CA3F0 */

extern G4C67B8 D_001CFEC0;
extern s16 D_L01_001E1102;
extern f32 D_L01_001E1104;
extern void func_003A9440(s32, s32);
extern void func_0038AF30(s32, s32, s32, s32, long);

void func_L01_004CA3F0(void)
{
    s32 c;

    func_003A9440(66, 68);
    c = (s32)((1.0f - (f32)D_L01_001E1102 * D_L01_001E1104) * 255.0f);
    func_0038AF30(0, D_001CFEC0.unk152, 0, D_001CFEC0.unk150, c << 24);
}
/* localdecomp:end func_L01_004CA3F0 */

INCLUDE_ASM("asm/levels", func_L01_004CA478);

/* localdecomp:start func_L01_004CA6A8 */
extern void func_0038AF30(s32, s32, s32, s32, long);
extern void func_003A9440(s32, s32);
extern G4C67B8 D_001CFEC0;
extern s16 D_L01_001E1136;
void func_L01_004CA6A8(void) {
    ((void (*)(s32, long))func_003A9440)(66, ((long)D_L01_001E1136 << 32) | 68);
    {
        s32 c = D_L01_001E1136 << 24;
        ((void (*)(s32, s32, s32, s32, s32))func_0038AF30)(0, ((Ent_004C6A70 *)&D_001CFEC0)[0].b, 0, ((Ent_004C6A70 *)&D_001CFEC0)[0].a, c | 0xFFFFFF);
    }
}
/* localdecomp:end func_L01_004CA6A8 */

INCLUDE_ASM("asm/levels", func_L01_004CA710);

/* localdecomp:start func_L01_004CA8C8 */
extern void func_00392350(s32);
extern void func_0038AE20();
extern void func_00388AF8(s32);
extern s16 D_L01_001E110E;
extern s32 D_L01_001DF944;

void func_L01_004CA8C8(void) {
    func_00392350(0);
    func_0038AE20(0, 0, 0, 0x80);
    if (D_L01_001E110E != 0) {
        D_L01_001DF944 = 0x100FF;
    } else {
        D_L01_001DF944 = 0x70;
    }
    func_00388AF8(0);
}
/* localdecomp:end func_L01_004CA8C8 */

/* localdecomp:start func_L01_004CA928 */
extern s32 D_L01_001D6694;
extern s32 D_001D4CEC_sda;
__asm__(".extern D_001D4CEC_sda, 4");
extern u8 D_L01_001E002C[] __attribute__((section(".sdata")));
extern u8 *D_L01_001E0028;
__asm__(".extern D_L01_001E0028, 4");
extern u8 D_L01_001E110C;
extern u8 D_L01_001E110D;
extern s32 D_L01_001E0280;
extern u8 *D_L01_001E0278;
void func_L01_004CA928(void) {
    extern void func_00392260(s32, s32, s32);
    extern s32 func_003A0EC0(s32, s32, s32, s32, u8 *);
    extern s32 func_L01_004B8EC8_004CA928(void);
    extern void func_003E5520(void);
    extern void func_003A4288(void);
    extern u8 *func_003C7550(void *);
    extern void func_003C7C38(void *);
    extern void func_003C6FE0(void *);
    extern void func_L01_004E20E8(void);
    extern void func_00384D88(void);
    extern void func_L01_004C99F8(void);
    extern void func_L01_0046FD18(void *);
    extern void func_003E55B8(void);
    u8 *p;
    s32 i;
    func_00392260(0, 0, 0);
    if (D_L01_001D6694 == 0 && (D_001D4CEC_sda & 1)) {
        if (func_003A0EC0(4, 1, 1, 0, 0) == 0) return;
    }
    if (func_L01_004B8EC8_004CA928() != 0) return;
    func_003E5520();
    func_003A4288();
    p = D_L01_001E0028 = func_003C7550(D_L01_001E002C);
    while (p != 0) {
        if (*(s8 *)(p + 0x20) >= 0) {
            if (*(s16 *)(p + 0xAA) == 0xDC1) {
                (*(void (**)(void *))(p+0x64))(p);
                if (!(*(u16 *)(p+0x34) & 4)) func_003C7C38(p);
            } else if (*(s16 *)(p+0xAA) == 0xCB2 || *(s16 *)(p+0xAA) == 0xB02 ||
                       *(s16 *)(p+0xAA) == 0x259 || *(s16 *)(p+0xAA) == 0xA5C ||
                       *(s16 *)(p+0xAA) == 0x1192) {
                func_003C6FE0(p);
                func_003C7C38(p);
            }
        }
        p = *(u8 **)(p+0x28);
    }
    if (D_L01_001E110C) func_L01_004E20E8();
    if ((&D_L01_001E110C)[1]) func_00384D88();
    func_L01_004C99F8();
    for (i=0; i<=D_L01_001E0280; i++) {
        u8 *e = D_L01_001E0278 + (i<<6);
        if ((*(long *)e & 0x80FF) == 0xFF) func_L01_0046FD18(e);
    }
    func_003E55B8();
}
/* localdecomp:end func_L01_004CA928 */

/* localdecomp:start func_L01_004CAB30 */
/* Ps2EeAs only uses $gp for the record if it knows it is small before the use; D_L01_001D66B0
   is declared small (8 bytes) without a hint, so gcc emits one `la` that Ps2EeAs expands. */
__asm__(".extern D_L01_001DAFEC, 4");
typedef int u128_4CAB30 __attribute__((mode(TI)));
extern s32 D_L01_001DAFEC;
extern S_4C4A18 D_001A4BE0;
extern u8 D_L01_001D66B0[8];
extern s32 func_L01_0044C638(u8 *moby, s32 record, u128_4CAB30 *pos, u8 *facing, u128_4CAB30 *pos_out,
                             u128_4CAB30 *facing_out);

/* vec_copy_unless_flag: copies a position, or while the moving-collision record is set puts it
   through the hero moby's move this frame (moby_carry_pose). */
void func_L01_004CAB30(u128_4CAB30 *out, u128_4CAB30 *pos) {
    u128_4CAB30 facing_out;
    if (D_L01_001DAFEC != 0) {
        func_L01_0044C638(D_001A4BE0.x25C0, D_L01_001DAFEC, pos, D_L01_001D66B0, out, &facing_out);
    } else {
        *out = *pos;
    }
}
/* localdecomp:end func_L01_004CAB30 */

/* localdecomp:start func_L01_004CAB80 */
__asm__(".extern D_L01_001DAFEC, 4");

void func_L01_004CAB80(u128_4CAB30 *out, u128_4CAB30 *pos, u128_4CAB30 *facing_out, u8 *facing) {
    if (D_L01_001DAFEC != 0) {
        func_L01_0044C638(D_001A4BE0.x25C0, D_L01_001DAFEC, pos, facing, out, facing_out);
    } else {
        *out = *pos;
        *facing_out = *(u128_4CAB30 *)facing;
    }
}
/* localdecomp:end func_L01_004CAB80 */

/* localdecomp:start func_L01_004CABD8 */
__asm__(".extern D_L01_001DAFEC, 4");
extern s32 D_L01_001DAFEC;
extern s32 D_001A71A0[];

void func_L01_004CABD8(u128_4CAB30 *out, u128_4CAB30 *pos, s32 mode) {
    extern void func_L01_0044C870(s32, s32, s32, u128_4CAB30 *);
    u128_4CAB30 delta;
    if (D_L01_001DAFEC != 0) {
        func_L01_0044C870(D_001A71A0[0], D_L01_001DAFEC, mode, &delta);
        __asm__(
            "lqc2 $vf1, %1\n\t"
            "lqc2 $vf2, %2\n\t"
            "vadd.xyz $vf1, $vf1, $vf2\n\t"
            "sqc2 $vf1, %0"
            : "=m"(*out) : "m"(*pos), "m"(delta) : "vf1", "vf2");
    } else {
        *out = *pos;
    }
}
/* localdecomp:end func_L01_004CABD8 */

/* localdecomp:start func_L01_004CAC40 */
__asm__(".extern D_L01_001DAFEC, 4");
extern s32 D_L01_001DAFEC;
extern s32 D_001A71A0[];
extern s32 func_L01_0044C790(s32, s32, s32 *, s32 *);

void func_L01_004CAC40(s32 *a0, s32 *a1) {
    if (D_L01_001DAFEC != 0) {
        func_L01_0044C790(D_001A71A0[0], D_L01_001DAFEC, a1, a0);
    }
}
/* localdecomp:end func_L01_004CAC40 */

/* localdecomp:start func_L01_004CAC78 */
#include "vu0.h"
extern Vec4_004C4AD8 D_001A6230[];
void func_L01_004CAC78(Vec4_004C4AD8 *out, Vec4_004C4AD8 *pos, f32 scale, f32 unused, f32 angle)
{
    extern f32 func_0038CEA8(Vec4_004C4AD8 *);
    extern void func_0038CF68(Vec4_004C4AD8 *, Vec4_004C4AD8 *, f32);
    extern f32 func_0038CE68(Vec4_004C4AD8 *, T_004C4AD8 *);
    extern f32 func_0038D098(f32);
    extern void func_0038CE90(Vec4_004C4AD8 *, Vec4_004C4AD8 *, T_004C4AD8 *);
    extern void func_0038D890(Vec4_004C4AD8 *, T_004C4AD8 *, Vec4_004C4AD8 *, f32);
    extern void func_0038CE20(Vec4_004C4AD8 *, Vec4_004C4AD8 *, f32);
    Vec4_004C4AD8 axis;
    Vec4_004C4AD8 *base = D_001A6230;
    T_004C4AD8 *target;
    f32 dot;
    vec_sub_ab(out, base, pos);
    if (func_0038CEA8(out) < 4.0f) {
        angle *= 0.1f;
        func_0038CF68(out, out, 1.0f);
        target = (T_004C4AD8 *)((u8 *)base - 0xF60);
        dot = func_0038CE68(out, target);
        if (dot < func_0038D098(angle)) goto rotate;
        func_0038CE20(out, out, scale);
    } else {
        func_0038CF68(out, out, 1.0f);
        target = (T_004C4AD8 *)((u8 *)base - 0xF60);
        dot = func_0038CE68(out, target);
        if (dot < func_0038D098(angle)) {
rotate:
            func_0038CE90(&axis, out, target);
            func_0038D890(out, target, &axis, angle);
            func_0038CF68(out, out, scale);
        } else {
            func_0038CE20(out, out, scale);
        }
    }
}
/* localdecomp:end func_L01_004CAC78 */

/* localdecomp:start func_L01_004CADE8 */
s32 func_L01_004CADE8(s32 *a0, s32 a1) {
    s32 ret = -1;
    s32 i;
    for (i = 0; i < 64; i++) {
        if (a0[i] == 0) {
            a0[i] = a1;
            ret = i;
            a0[137] = 1;
            a0[136]++;
            a0[i + 64] = 0;
            break;
        }
    }
    return ret;
}
/* localdecomp:end func_L01_004CADE8 */

/* localdecomp:start func_L01_004CAE60 */
typedef unsigned int Rac2Native_74a5d71aacb394c6_u32;
typedef struct {
    Rac2Native_74a5d71aacb394c6_u32 first[64];
    Rac2Native_74a5d71aacb394c6_u32 second[64];
    unsigned char gap[0x20];
    int count;
    Rac2Native_74a5d71aacb394c6_u32 current;
} Rac2Native_74a5d71aacb394c6_ExtraIndexState48;
extern int func_0011A930(int, void (*)(void), int);

/* from rac2-decomp's func_00300300, renamed */
void func_L01_004CAE60(Rac2Native_74a5d71aacb394c6_ExtraIndexState48 *state, int index) {
    state->first[index] = 0;
    state->second[index] = 0;
    if (--state->count == 0) {
        state->current = 0;
    }
}
/* localdecomp:end func_L01_004CAE60 */

/* localdecomp:start func_L01_004CAE90 */

extern u8 D_001A4C60[];
extern f32 func_L01_0040E548(void *, void *);

void func_L01_004CAE90(S_4C7228 *s) {
    f32 d[64];
    int cnt;
    int i;

    if (s->n224 == 0) {
        return;
    }
    cnt = 0;
    for (i = 0; i < 64; i++) {
        if (s->a[i] != 0) {
            s->b[i] = 0;
            cnt++;
            d[i] = func_L01_0040E548(D_001A4C60, (u8 *)s->a[i] + 16);
        }
        if (cnt == s->n220) {
            break;
        }
    }
    for (i = 0; i < s->n228 && i < s->n220; i++) {
        f32 best = 9999.0f;
        int bi = -1;
        int j;

        for (j = 0; j < 64; j++) {
            if (d[j] < best && s->b[j] == 0 && s->a[j] != 0) {
                best = d[j];
                bi = j;
            }
        }
        s->c[i] = s->a[bi];
        s->b[bi] = 1;
    }
}
/* localdecomp:end func_L01_004CAE90 */

LINKER_REMNANT("asm/levels", func_L01_004CB008);

/* localdecomp:start func_L01_004CB018 */
int func_L01_004CB018(int a0)
{
    int r = 0;
    if (a0 == 0 || a0 == 14 || a0 == 13) {
        r = 2;
    } else if (a0 == 1 || a0 == 3 || a0 == 11 || a0 == 12) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L01_004CB018 */

/* localdecomp:start func_L01_004CB068 */
extern u8 *D_L01_001E001C;
extern u8 *D_L01_001E0024;
extern u8 *D_L01_001E1148;

void func_L01_004CB068(void)
{
    u8 *cursor = D_L01_001E001C;
    int count = 0;

    while ((u32)cursor <= (u32)D_L01_001E0024) {
        if (*(s16 *)(cursor + 0xAA) == 0x135F) {
            ((u8 **)&D_L01_001E1148)[count++] = cursor;
            if (count >= 16)
                break;
        }
        cursor += 0x100;
    }
    while (count < 16)
        ((u8 **)&D_L01_001E1148)[count++] = 0;
}
/* localdecomp:end func_L01_004CB068 */

LINKER_REMNANT("asm/levels", func_L01_004CB120);

/* localdecomp:start func_L01_004CB128 */
#include "vu0.h"
s32 func_L01_004CB128(Vec4_004C4AD8 *out, u8 *moby, s32 joint) {
    extern void func_003C2F58(void *, s32, void *);
    extern u8 *func_00382348(void);
    extern void func_0038CE20(Vec4_004C4AD8 *, Vec4_004C4AD8 *, f32);
    u8 *state;
    if (moby != 0) {
        if (joint != 0) {
            func_003C2F58(moby, joint, out);
            return 1;
        }
        *(vu0_q *)out = *(vu0_q *)(moby + 16);
        state = func_00382348();
        if (state != 0) {
            func_0038CE20(out, (Vec4_004C4AD8 *)(moby + 224), *(f32 *)(state + 16));
            vec_add_ab(out, out, moby + 16);
            if (*(s16 *)(moby + 170) == 0x1AB8) {
                func_003C2F58(moby, 4, out);
            }
            if (*(s16 *)(moby + 170) == 0x1C08) {
                func_003C2F58(moby, 5, out);
            }
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_004CB128 */

/* localdecomp:start func_L01_004CB1F0 */
typedef struct {
    u8 pad0[0x15F0];
    f32 look_cam_weight;
    u8 pad15F4[0x16D4 - 0x15F4];
    f32 crosshair_pulse;
    s32 crosshair_fade;
} H_4CB1F0;
extern f32 func_0038DAB8(f32 angle, f32 step);
extern f32 func_0038D0B0(f32 angle);
extern u32 func_0038DBD8(u32 from, u32 to, f32 t);

/* crosshair_colour: fades in over 20 counts (5 alpha a count) and pulses between green and
   white, the phase moving deg_per_s; solid red while the free-look target's weight is above
   the threshold. */
u32 func_L01_004CB1F0(f32 threshold, f32 deg_per_s) {
    u32 alpha;
    u32 colour;
    (*(H_4CB1F0 *)&D_001A4BE0).crosshair_fade++;
    if ((*(H_4CB1F0 *)&D_001A4BE0).crosshair_fade > 20) {
        (*(H_4CB1F0 *)&D_001A4BE0).crosshair_fade = 20;
    }
    /* degrees a second to radians a frame */
    (*(H_4CB1F0 *)&D_001A4BE0).crosshair_pulse =
        func_0038DAB8((*(H_4CB1F0 *)&D_001A4BE0).crosshair_pulse, deg_per_s * 0.0174532924f * 0.0200000014f);
    alpha = ((*(H_4CB1F0 *)&D_001A4BE0).crosshair_fade * 5) << 24;
    /* green (0x0F, 0xFF, 0x00) to white, by 0.5 + 0.5 sin */
    colour = func_0038DBD8(alpha | 0xFF0F, alpha | 0xFFFFFF,
                           func_0038D0B0((*(H_4CB1F0 *)&D_001A4BE0).crosshair_pulse) * 0.5f + 0.5f);
    if (threshold < (*(H_4CB1F0 *)&D_001A4BE0).look_cam_weight) {
        colour = 0x600000FF; /* red */
    }
    return colour;
}
/* localdecomp:end func_L01_004CB1F0 */

/* localdecomp:start func_L01_004CB2D8 */
__asm__(".extern D_L01_001DB03C, 4");
extern s32 D_L01_001DB03C;
extern s32 D_L01_001DFB40;
extern u8 *D_001A4F3C[];

s32 func_L01_004CB2D8(void) {
    u8 *p;

    if (D_L01_001DB03C >= D_L01_001DFB40) {
        p = D_001A4F3C[0];
        D_L01_001DAFEC = (s32)p;
        if (p != 0) {
            return *(s16 *)(p + 0xAA);
        }
        return 1;
    }
    D_L01_001DAFEC = 0;
    return 0;
}
/* localdecomp:end func_L01_004CB2D8 */

LINKER_REMNANT("asm/levels", func_L01_004CB318);

/* localdecomp:start func_L01_004CB320 */
extern s32 D_L01_001E10D0[] __attribute__((section(".sdata")));
void func_L01_004CB320(void) {
    s32 *slot = D_L01_001E10D0;
    s32 i;
    for (i = 3; i >= 0; i--, slot++) {
        u8 *p = (u8 *)*slot;
        if (p) {
            *(s32 *)(p + 0x98) = *(s32 *)(*(u8 **)(p + 0x24) + 0x10);
        }
    }
}
/* localdecomp:end func_L01_004CB320 */

/* localdecomp:start func_L01_004CB358 */
extern s32 D_L01_001E10D0[] __attribute__((section(".sdata")));
void func_L01_004CB358(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_L01_001E10D0[i] != 0) {
            *(s32 *)(D_L01_001E10D0[i] + 0x98) = 0;
        }
    }
}
/* localdecomp:end func_L01_004CB358 */

/* localdecomp:start func_L01_004CB388 */
/* Case labels are decoded from the PAL table at 0x002BD880; see the retained table evidence. */
typedef struct { u8 pad[0x7C]; s16 state; } Obj_004CB388;
void func_L01_004CB388(u8 *obj, s32 type, s32 level) {
    switch (type) {
    case 39:
        if (level >= 2) ((Obj_004CB388 *)obj)->state = 3;
        else if (level == 1) ((Obj_004CB388 *)obj)->state = 2;
        break;
    case 47:
        if (level >= 2) ((Obj_004CB388 *)obj)->state = 3;
        else if (level == 1) ((Obj_004CB388 *)obj)->state = level;
        break;
    case 55:
        if (level >= 3) ((Obj_004CB388 *)obj)->state = 7;
        if (level == 2) ((Obj_004CB388 *)obj)->state = 3;
        else if (level == 1) ((Obj_004CB388 *)obj)->state = 2;
        break;
    case 63: case 71: case 119:
        if (level == 2) ((Obj_004CB388 *)obj)->state = 3;
        else if (level == 1) ((Obj_004CB388 *)obj)->state = level;
        else if (level >= 3) ((Obj_004CB388 *)obj)->state = 7;
        break;
    case 79: case 95: case 143:
        if (level >= 3) ((Obj_004CB388 *)obj)->state = 7;
        if (level == 2) ((Obj_004CB388 *)obj)->state = 3;
        else if (level == 1) ((Obj_004CB388 *)obj)->state = level;
        break;
    case 87:
        if (level >= 4) ((Obj_004CB388 *)obj)->state = 5;
        if ((u32)(level - 1) < 3) ((Obj_004CB388 *)obj)->state = 9;
        else if (level == 0) ((Obj_004CB388 *)obj)->state = 1;
        break;
    case 103: case 127:
        if (level >= 2) ((Obj_004CB388 *)obj)->state = 3;
        else if (level == 1) ((Obj_004CB388 *)obj)->state = 2;
        break;
    case 111:
        if (level == 1) ((Obj_004CB388 *)obj)->state = level;
        else if (level == 2) ((Obj_004CB388 *)obj)->state = 3;
        else if (level >= 3) ((Obj_004CB388 *)obj)->state = 7;
        break;
    case 151:
        if (level >= 3) ((Obj_004CB388 *)obj)->state = 7;
        if (level == 2) ((Obj_004CB388 *)obj)->state = 6;
        else if (level == 1) ((Obj_004CB388 *)obj)->state = 4;
        break;
    case 135:
        if (level == 2) ((Obj_004CB388 *)obj)->state = 3;
        else if (level == 1) ((Obj_004CB388 *)obj)->state = level;
        else if (level >= 3) ((Obj_004CB388 *)obj)->state = 25;
        break;
    }
}
/* localdecomp:end func_L01_004CB388 */

/* localdecomp:start func_L01_004CB540 */
extern u8 D_L01_001DB084_004CB540;
void func_L01_004CB540(u8 a) { D_L01_001DB084_004CB540 = a; }
/* localdecomp:end func_L01_004CB540 */

/* localdecomp:start func_L01_004CB548 */
extern u8 D_L01_001DB084_004CB548;

u8 func_L01_004CB548(void) {
    return D_L01_001DB084_004CB548;
}
/* localdecomp:end func_L01_004CB548 */
