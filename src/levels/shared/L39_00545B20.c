#include "common.h"

/* declared by functions of L39_00545498.c, which this file was cut from */
extern f32 func_0038CED8(void *);
extern void func_0038CE20(void *, void *, f32);

/* localdecomp:start func_L39_00545B20 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x100];
    f32 f100;
    f32 f104;
    u8 pad108[0x1A4 - 0x108];
    s32 f1A4;
} Q_00545B20;

typedef struct {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1C[0x380 - 0x1C];
    u8 m380[0x40];
    u8 pad3C0[0x428 - 0x3C0];
    f32 f428;
} R_00545B20;

typedef struct {
    u8 pad0[0x110];
    f32 f110;
    f32 f114;
    u8 pad118[0x320 - 0x118];
    s16 h320;
    u8 pad322[0x1A14 - 0x322];
    u8 b1A14;
    u8 pad1A15[0x24C9 - 0x1A15];
    u8 b24C9;
    u8 pad24CA[0x2530 - 0x24CA];
    R_00545B20 *f2530;
    Q_00545B20 *f2534;
    u8 pad2538[0x2544 - 0x2538];
    s32 f2544;
} P_00545B20;

typedef struct {
    u8 pad0[0x2DC];
    P_00545B20 *f2DC;
    u8 pad2E0[0x308 - 0x2E0];
    f32 f308;
} G_00545B20;

typedef struct {
    u8 pad0[0x384];
    G_00545B20 *f384;
    u8 pad388[0x3AC - 0x388];
    s32 f3AC;
    f32 f3B0;
    f32 f3B4;
    s32 f3B8;
    u8 pad3BC[0x3DC - 0x3BC];
    s32 f3DC;
    s32 f3E0;
    s32 f3E4;
    s32 f3E8;
} E_00545B20;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad20[0x23 - 0x20];
    u8 b23;
    u8 pad24[0x34 - 0x24];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    E_00545B20 *ex;
} O_00545B20;

typedef struct { u8 pad[0xA4]; u8 fA4[4]; } T_00545B20;
typedef struct { vu0_v4 p; vu0_v4 q; vu0_v4 n; } H_00545B20;

extern T_00545B20 D_001A5810;
extern s32 D_001A58D0[][8];
extern s32 D_001A5930[][8];
extern H_00545B20 D_L39_0025F760;
extern vu0_v4 D_L39_0025F770;
__asm__(".extern D_L39_00241120, 16");
extern s32 *D_L39_00241120;
__asm__(".extern D_L39_00241640, 16");
extern u8 *D_L39_00241640;
__asm__(".extern D_L39_0024BB90, 4");
extern s32 D_L39_0024BB90;
extern s32 D_L39_0024BB90_00545B20; /* the same variable; no .extern size, so the assembler reaches it through lui $at */
__asm__(".extern D_L39_0024AEB8, 4");
extern s32 D_L39_0024AEB8;
__asm__(".extern D_L39_0024AF28, 4");
extern f32 D_L39_0024AF28;
__asm__(".extern D_L39_0024AF2C, 4");
extern f32 D_L39_0024AF2C;
__asm__(".extern D_L39_0024AF30, 4");
extern f32 D_L39_0024AF30;
__asm__(".extern D_L39_0024AF34, 4");
extern f32 D_L39_0024AF34;
__asm__(".extern D_L39_0024AF38, 4");
extern f32 D_L39_0024AF38;
__asm__(".extern D_L39_0024AF3C, 4");
extern f32 D_L39_0024AF3C;
__asm__(".extern D_L39_0024AF40, 4");
extern f32 D_L39_0024AF40;
__asm__(".extern D_L39_0024AF44, 4");
extern f32 D_L39_0024AF44;
__asm__(".extern D_L39_0024AF48, 4");
extern f32 D_L39_0024AF48;
__asm__(".extern D_L39_0024AF4C, 4");
extern f32 D_L39_0024AF4C;
__asm__(".extern D_L39_0024AF50, 4");
extern f32 D_L39_0024AF50;
__asm__(".extern D_L39_0024AF54, 4");
extern s32 D_L39_0024AF54;
__asm__(".extern D_L39_0024AF58, 4");
extern s32 D_L39_0024AF58;
__asm__(".extern D_L39_0024AF5C, 4");
extern f32 D_L39_0024AF5C;
__asm__(".extern D_L39_0024AF60, 4");
extern f32 D_L39_0024AF60;
__asm__(".extern D_L39_0024AF64, 4");
extern f32 D_L39_0024AF64;
__asm__(".extern D_L39_0024AF68, 4");
extern f32 D_L39_0024AF68;
__asm__(".extern D_L39_0024AF6C, 4");
extern f32 D_L39_0024AF6C;
__asm__(".extern D_L39_0024AF70, 4");
extern f32 D_L39_0024AF70;
__asm__(".extern D_L39_0024AF74, 4");
extern f32 D_L39_0024AF74;
__asm__(".extern D_L39_0024AF78, 1");
extern u8 D_L39_0024AF78;

extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB3C0(s32, void *);
extern f32 func_0038CED8(void *);
extern f32 func_0038D098(f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_003F6F20(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern s32 func_L01_003F1F20(s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_L39_00570200(s32, void *, void *, s32, s32, s32);
extern void func_L39_005455C8(u8 *, u8 *, u32);

void func_L39_00545B20(u8 *a0) {
    O_00545B20 *o = (O_00545B20 *)a0;
    E_00545B20 *ex = o->ex;
    P_00545B20 *pl = ex->f384->f2DC;
    vu0_v4 v;
    vu0_v4 s;
    vu0_v4 t;
    vu0_v4 w;
    f32 yaw;
    f32 pitch;
    f32 sx;
    f32 sy;
    f32 f;
    f32 cx;
    f32 cy;
    s32 b;
    s32 i;
    s32 m;
    u32 col;
    s32 sel;

    if (pl->b1A14 != 0 && 0.0f < ex->f384->f308) {
        if (ex->f3AC == -1) {
            ex->f3B8 = 0x2D;
            ex->f3B0 = 0.5f;
            ex->f3B4 = 0.5f;
            ex->f3AC = pl->b24C9;
            o->b23 = D_L39_0024AF78;
            o->h34 |= 0x800;
            func_L39_00570200(pl->b24C9, pl->f2530, &pl->f2530->pad0[0x10], 3, 0x3C, 0);
            D_L39_0024BB90 = 2;
        } else {
            yaw = func_0038DAB8(pl->f2530->f18, 3.1415927f);
            pitch = *(f32 *)&pl->f2530->pad0[0x14];
            i = ex->f384->f2DC->f2544;
            b = D_001A5810.fA4[i];
            sx = 1.0f;
            if (D_001A5930[b][i] != 0) {
                sx = -1.0f;
            }
            sy = 1.0f;
            if (D_001A58D0[b][i] != 0) {
                sy = -1.0f;
            }
            if (b == 0) {
                sy = -sy;
                sx = 1.0f;
            }
            D_L39_0024BB90_00545B20 = 2;
            f = pl->f2534->f100 * D_L39_0024AF34 * sx;
            if (pl->h320 > 0) {
                f = 0.0f;
            }
            yaw = func_0038DAB8(yaw, f);
            f = pl->f2534->f104 * D_L39_0024AF38 * sy;
            if (pl->h320 > 0) {
                f = 0.0f;
            }
            pitch = func_0038DAB8(pitch, f);
            if (D_L39_0024AF30 * 0.017453292f < pitch) {
                pitch = D_L39_0024AF30 * 0.017453292f;
            }
            if (pitch < D_L39_0024AF2C * 0.017453292f) {
                pitch = D_L39_0024AF2C * 0.017453292f;
            }
            func_00382760(&v, D_L39_0024AF28, yaw, pitch);
            vec_add_ab(&v, &v, &o->pos);
            if (func_003D3CB0(&o->pos, &v, 4, o, 0) != 0) {
                v = D_L39_0025F760.p;
                func_0038CF68(&w, &D_L39_0025F760.n, 0.02f);
                vec_add_ab(&v, &v, &w);
            }
            if (func_L01_003FB640(&v, 4, a0, 0.4f) != 0) {
                v = D_L39_0025F770;
            }
            func_L01_003EB350(ex->f3AC, &v);
            v.x = 0.0f;
            v.y = pitch;
            v.z = func_0038DAB8(yaw, 3.1415927f);
            func_L01_003EB3C0(ex->f3AC, &v);

            f = pl->f110 * D_L39_0024AF3C;
            if (pl->h320 > 0) {
                f = 0.0f;
            }
            f *= fabs_asm(f);
            ex->f3B0 += f;
            if (D_L39_0024AF44 < ex->f3B0) {
                ex->f3B0 = D_L39_0024AF44;
            }
            if (ex->f3B0 < D_L39_0024AF40) {
                ex->f3B0 = D_L39_0024AF40;
            }
            f = -pl->f114 * D_L39_0024AF3C;
            if (pl->h320 > 0) {
                f = 0.0f;
            }
            f *= fabs_asm(f);
            ex->f3B4 += f;
            if (D_L39_0024AF4C < ex->f3B4) {
                ex->f3B4 = D_L39_0024AF4C;
            }
            if (ex->f3B4 < D_L39_0024AF48) {
                ex->f3B4 = D_L39_0024AF48;
            }

            v.x = ex->f3B0 - 0.5f;
            v.y = ex->f3B4 - 0.5f;
            v.z = 0.0f;
            v.w = 0.0f;
            f = func_0038CED8(&v);
            if (D_L39_0024AF50 < f) {
                f = D_L39_0024AF50 / f;
                ex->f3B0 = v.x * f + 0.5f;
                ex->f3B4 = v.y * f + 0.5f;
            }
            yaw = func_0038D098(pl->f2530->f428 * 0.5f);
            f = -(ex->f3B0 - 0.5f);
            cx = f * yaw * (*D_L39_00241120 < 3 ? D_L39_0024AF60 : D_L39_0024AF64);
            f = -(ex->f3B4 - 0.5f);
            m = *D_L39_00241120;
            cy = f * yaw * (m == 2 ? D_L39_0024AF6C : (m == 1 ? D_L39_0024AF68 : D_L39_0024AF70));
            func_00382760(&v, 1.0f, cx, cy);
            func_0038D000(&s, &v, pl->f2530->m380);
            func_0038CE20(&t, &s, D_L39_0024AF74);
            vec_add_ab(&s, &t, pl->f2530);
            if (s.z < 0.0f) {
                func_0038CE20(&t, &t, s.z / (D_L39_0024AF74 * 0.67f) + 1.0f);
                vec_add_ab(&s, &t, pl->f2530);
            }
            col = 0x800000FF;
            sel = D_L39_0024AF54;
            if (func_003D3CB0(pl->f2530, &s, 2, o, 0) != 0) {
                if (D_L39_0025F760.p.z < o->pos.z - 0.5f) {
                    col = 0x8000FF00;
                    sel = D_L39_0024AF58;
                }
            }
            func_L01_003F6F20(pl->b24C9, o, col, 0, sel, -1, 4, D_L39_0024AF5C, 0.0f, 90.0f,
                              ex->f3B0, ex->f3B4, 40.0f, 40.0f);
            if (ex->f3DC > 0) {
                ex->f3E8++;
                if (ex->f3E4 > 10) {
                    ex->f3E4 = 10;
                }
            } else {
                ex->f3E8 = 0;
            }
            if (sel == D_L39_0024AF58 && pl->h320 == 0 && (pl->f2534->f1A4 & 0x28) &&
                ex->f3B8 <= 0 && ex->f3DC > 0 && ex->f3E8 >= 3) {
                if (*(s8 *)(D_L39_00241640 + 0x19B) == 0) {
                    ex->f3DC--;
                }
                func_L01_003F1F20(D_L39_0024AEB8, (s32)pl->f2534);
                func_L39_005455C8(a0, (u8 *)&D_L39_0025F760, 0xFFFFFFFF);
                ex->f3E0 = 50;
            }
            ex->f3E0--;
            if (ex->f3E0 <= 0 && ex->f3DC < 5) {
                ex->f3DC++;
                ex->f3E0 = 50;
            }
        }
    }
    func_0038CAD0(&ex->f3B8);
}
/* localdecomp:end func_L39_00545B20 */
