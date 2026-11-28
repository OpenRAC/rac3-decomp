#include "common.h"

typedef struct {
    int w[4];
    char pad10[0x21 - 0x10];
    unsigned char b33;
    char pad22[0xA0 - 0x22];
    unsigned char b160[4];
    int w164;
} Sub;
typedef struct {
    char pad0[0x20];
    unsigned char b32;
    char pad21[0x30 - 0x21];
    unsigned char b48;
    char pad31[0x34 - 0x31];
    unsigned short h52;
    char pad36[0x68 - 0x36];
    Sub *p104;
} Obj_00329E70;
typedef int s128_329AA8 __attribute__((mode(TI)));

/* localdecomp:start func_L01_00329AD0 */
#include "vu0.h"
extern u8 D_L01_001EAA40[];
typedef struct {
    vu0_v4 velocity;
    f32 pitch, yaw;
    s16 timer, duration, scale, alpha;
    s32 colors[4];
    s32 kind, collide, texture;
    s16 a, b;
} Vars_00329AD0;
void func_L01_00329AD0(u8 *self) {
    extern f32 func_0038DAB8(f32, f32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
    extern void func_L01_0040E790(void *, void *, void *);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_00451388_00329AD0(void *, void *, void *, f32);
    extern s32 func_00382468(s32);
    extern f32 func_003824E0(f32, f32);
    extern void func_L01_004637C8(void *, void *, s32, s32, s32, s32, s32, s32);
    extern void func_003C2880(void *);
    extern s32 func_0038CB00(void *);
    Vars_00329AD0 *p = *(Vars_00329AD0 **)(self + 0x68);
    vu0_v4 temp;
    s32 quarter;
    s32 i;
    *(f32 *)(self + 0xF0) = func_0038DAB8(*(f32 *)(self + 0xF0), p->pitch);
    *(f32 *)(self + 0xF4) = func_0038DAB8(*(f32 *)(self + 0xF4), p->yaw);
    if (p->collide) {
        *(vu0_q *)&temp = *(vu0_q *)(self + 0x10);
        vec_add_ab(self + 0x10, self + 0x10, p);
        if (func_003D3CB0(&temp, self + 0x10, 16, self, 0)) {
            f32 speed;
            func_L01_0040E790(p, p, D_L01_001EAA40);
            speed = func_0038CEA8(p);
            func_0038CF68(p, p, speed * 0.76f);
        }
    } else {
        vec_add_ab(self + 0x10, self + 0x10, p);
    }
    func_L01_00451388_00329AD0(self, p, p, (f32)p->alpha * 0.0078125f * 0.0004000000189989805f);
    if (p->kind == 1) {
        if (func_00382468(2)) {
            vu0_v4 random = {0};
            random.x = func_003824E0(-1.0f, 1.0f);
            random.y = func_003824E0(-1.0f, 1.0f);
            random.z = func_003824E0(-1.0f, 1.0f);
            *(vu0_q *)&temp = *(vu0_q *)&random;
            func_0038CF68(&temp, &temp, 0.020000001415610313f);
            func_L01_004637C8(self + 0x10, &temp, p->colors[func_00382468(4)], 0, 0x25, p->a, p->b, p->texture);
        }
    }
    if (p->kind == 4 || p->kind == 2) {
        for (i = 0; i < 3; i++) {
            vu0_v4 random = {0};
            random.x = func_003824E0(-1.0f, 1.0f);
            random.y = func_003824E0(-1.0f, 1.0f);
            random.z = func_003824E0(-1.0f, 1.0f);
            *(vu0_q *)&temp = *(vu0_q *)&random;
            func_0038CF68(&temp, &temp, 0.020000001415610313f);
            func_L01_004637C8(self + 0x10, &temp, p->colors[func_00382468(4)], 0, 0x25, p->a, p->b, p->texture);
        }
    }
    if (*(f32 *)(self + 0x10) < 0.0f || *(f32 *)(self + 0x14) < 0.0f || *(f32 *)(self + 0x18) < 0.0f) {
        func_003C2880(self);
        return;
    }
    quarter = p->duration / 4;
    if (p->timer < quarter)
        *(f32 *)(self + 0x2C) = (f32)p->scale * 0.0078125f * (f32)p->timer / (f32)quarter;
    if (func_0038CB00(&p->timer)) func_003C2880(self);
}
/* localdecomp:end func_L01_00329AD0 */

/* localdecomp:start func_L01_00329E70 */
extern void func_L01_004450F0(void *, s32, s32);



void func_L01_00329E70(Obj_00329E70 *obj) {
    Sub *p;
    int i, j;

    if (obj->b32 == 0) {
        p = obj->p104;
        if (p->b33 != 0) {
            j = 0;
            for (i = 0; i < 4; i++) {
                if (p->w[i] != -1) {
                    p->b160[j] = i;
                    j++;
                }
            }
            p->w164 = 0;
        }
        obj->b48 = 255;
        obj->h52 |= 2;
        ((void (*)(Obj_00329E70 *, int, int))func_L01_004450F0)(obj, 1, -1);
    }
}
/* localdecomp:end func_L01_00329E70 */

/* localdecomp:start func_L01_00329F00 */
extern u8 *D_L01_001E001C;
extern u8 *D_L01_001E0100;
extern void func_L01_003362B0(u8 *a0, s32 a1);
extern void func_L01_00335F28(u8 *a0, s32 a1);
void func_L01_00329F00(u8 *a0, u8 *a1) {
    u8 *pv;
    u8 *pv1;
    s8 *list;
    u8 *f;
    u8 *src;
    u8 *dst;
    s32 i;
    s32 k;

    pv = *(u8 **)(a0 + 104);
    pv1 = *(u8 **)(a1 + 104);
    list = (s8 *)(pv + 160);
    for (i = 0, f = pv + 16; i < 24; i++, f++) {
        if (*f == 0) {
            continue;
        }
        if (i == 17) {
            k = *(s32 *)(pv + 164);
            if (k >= 4 || list[k] == -1) {
                *(s32 *)(pv + 164) = 0;
            }
            if (*(s32 *)(pv + 164) != -1) {
                func_L01_00329F00(D_L01_001E001C + (((s32 *)pv)[list[*(s32 *)(pv + 164)]] << 8), a1);
                *(s32 *)(pv + 164) += 1;
            }
        } else if (i == 18) {
            if (*(s32 *)(pv1 + 76) != -1) {
                func_L01_00329F00(D_L01_001E001C + (*(s32 *)(pv1 + 76) << 8), a1);
            }
        } else if (i == 19) {
            func_L01_003362B0(a1, 0);
            return;
        } else if (i == 21) {
            k = *(s32 *)(pv + 100);
            if (k != -1) {
                src = D_L01_001E0100 + (k << 7);
                dst = D_L01_001E001C + (*(s32 *)(pv1 + 80) << 8);
                *(s128_329AA8 *)(dst + 16) = *(s128_329AA8 *)(src + 48);
                *(s128_329AA8 *)(dst + 240) = *(s128_329AA8 *)(src + 112);
            }
            func_L01_00329F00(D_L01_001E001C + (*(s32 *)pv << 8), a1);
        } else {
            *(s32 *)(pv1 + 76) = (*(u8 **)(a1 + 184) - D_L01_001E001C) >> 8;
            *(u8 **)(a1 + 184) = a0;
            func_L01_00335F28(a1, i);
            return;
        }
    }
}
/* localdecomp:end func_L01_00329F00 */

/* localdecomp:start func_L01_0032A0C8 */
/* The integer abs is the game's abs_asm (include/vu0.h): retail runs it on a value it has just
   tested, which the compiler would fold away. */
#include "vu0.h"
extern u8 *D_L01_001E001C;

void func_L01_0032A0C8(void *arg0, u8 *arg1, s32 arg2) {
    u8 *pv = *(u8 **)((u8 *)arg0 + 0x68);
    s32 n = *(s8 *)(pv + arg2 + 0x30);

    if (n > 0) {
        n = abs_asm(n);
        func_L01_00329F00(D_L01_001E001C + (*(s32 *)(pv + n * 4 - 4) << 8), arg1);
    }
}
/* localdecomp:end func_L01_0032A0C8 */

/* localdecomp:start func_L01_0032A118 */
/* The integer abs is the game's abs_asm (include/vu0.h): retail runs it on a value it has just
   tested, which the compiler would fold away. */
#include "vu0.h"
extern u8 *D_L01_001E001C;

void func_L01_0032A118(void *arg0, u8 *arg1, s32 arg2) {
    u8 *pv = *(u8 **)((u8 *)arg0 + 0x68);
    s32 n = *(s8 *)(pv + arg2 + 0x30);

    if (n < 0) {
        n = abs_asm(n);
        func_L01_00329F00(D_L01_001E001C + (*(s32 *)(pv + n * 4 - 4) << 8), arg1);
    }
}
/* localdecomp:end func_L01_0032A118 */

/* localdecomp:start func_L01_0032A168 */
extern s32 D_001D545C;
#include "vu0.h"

typedef struct {
    s32 w0;
    s32 w4;
    u8 b8;
    s8 c9;
    u8 ba;
    s8 cb;
    s8 cc;
    u8 bd;
    u8 pe;
    u8 bf;
    s32 w10;
    s32 w14;
    u8 p18[8];
    s32 w20[4];
    s32 w30;
    s32 w34;
    s8 c38;
    u8 b39;
    u8 b3a;
    u8 b3b;
} V_32A168;

typedef struct {
    u8 p0[0x20];
    u8 b20;
    u8 p21[0x47];
    V_32A168 *vars;
    u8 p6c[0x28];
    u8 b94;
    u8 p95[0x1B];
    u8 bb0;
    u8 pb1[0xB];
    u8 bbc;
} O_32A168;

typedef struct {
    u8 p0[0x80];
    f32 x80;
    f32 y84;
    f32 z88;
    u8 p8c[0xC];
    f32 f98;
    u8 p9c[0x25C4 - 0x9C];
    s32 w25C4;
    u8 p25C8[0x2850 - 0x25C8];
    s32 w2850;
} H_32A168;

typedef struct {
    u8 p0[0x26];
    s16 h26;
    u8 p28[0x48];
    vu0_q q70;
} G_32A168;

typedef struct {
    u8 p0[0x24];
    void (*f24)(s32, s32);
    u8 p28[0x1C];
    void (*f44)(s32);
} Vt_32A168;

typedef struct {
    u8 p0[0x30];
    u8 b30;
    u8 p31[3];
    u16 h34;
    u8 p36[0x2E];
    void (*f64)(u8 *);
} E_32A168;

extern u8 D_001D5530[8];
__asm__(".extern D_001D5530, 16");
extern u8 D_001BBC40[][16];
extern u8 *D_001D52FC;
extern s32 D_L01_001DFB40;
extern s32 D_L01_001DFB94;
extern s32 D_L01_001E1880;
extern s32 D_L01_001DFC28;
extern f32 D_L01_001DF950;
extern s32 D_L01_001E6DB0[];
extern s32 D_L01_001D6694;
extern s32 D_L01_001D6690;
extern s32 D_L01_002D15F0[];
extern u8 D_00142CAD[];
extern u8 D_0014275D[];
extern u8 D_0014275C[];
extern u8 D_00142CA0[];
extern u8 D_00142CBE[];
extern u8 D_00142D62[];
extern u8 D_001426E0[];
extern u8 D_001BBDA2;
extern u8 D_L01_001DFE82;
extern u32 D_00142BA0[];
extern u8 D_L01_001EA7C0[];
extern s32 D_L01_001F3F40[];
extern s16 **D_L01_002AF350[];
extern H_32A168 D_001A4BE0;
extern G_32A168 D_0016C580;
extern u8 D_001A4C60[];

extern void func_L01_00456230(void *, s32);
extern s32 func_L01_00456250(void *);
extern void func_003C2880(void *);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_00392B20(void *, s32);
extern s32 func_00392C78(void *);
extern void func_L01_004BA7B8(void);
extern s32 func_L01_004BA800(void);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_0044CCC8(s32);
extern void func_0039EF28(void);
extern void func_L01_0044FC48(s32, s32);
extern void func_L01_0043B510(s32);
extern void func_L01_004A3610(u8 *, u8 *);
extern void func_00392DF0(s32, s32);
extern void func_003A0EC0(s32, s32, s32, s32, s32);
extern void func_0039EC28(s32, s32);
extern void func_L01_0042B068(s32, s32);
extern Vt_32A168 *func_L01_0043B548(s32, s32);
extern void func_L01_00419188(s32);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L01_00511A40(void *, s32, f32);

void func_L01_0032A168(O_32A168 *o) {
    V_32A168 *v;
    s32 i;
    s32 j;
    s32 id;
    s32 g;
    s32 ok;
    s32 f;
    s16 **tbl;
    s16 *p;
    u8 *hero;
    E_32A168 *e;
    vu0_v4 vec;
    Vt_32A168 *vt;
    s32 c;
    u32 x;

    v = o->vars;
    if (D_001D545C == 0x11 && o->b20 == 0 && v->w10 != 0 && (D_001BBC40[D_001D545C][o->bb0] & 0x80)) {
        for (i = 0; i < 4; i++) {
            if (v->w20[i] >= 0) {
                func_L01_00456230(D_L01_001E001C + (v->w20[i] << 8), 1);
            }
        }
        func_003C2880(o);
        return;
    }
    if (D_L01_001DFB40 <= 0) {
        return;
    }
    switch (o->b20) {
    case 0:
        if (v->c9 != -1 && D_001D5530[v->c9] != 0) {
            func_003C2880(o);
            return;
        }
        if (o->bb0 != 0xFF && (D_001BBC40[D_001D545C][o->bb0] & 0x80)) {
            func_003C2880(o);
            return;
        }
        func_L01_004450F0(o, 1, -1);
    case 1:
        if (v->ba == 0 && func_L01_00456250(o) == 0 && o->bbc == 0) {
            return;
        }
        v->ba = 1;
        func_L01_004450F0(o, 2, -1);
    case 2:
        if (v->w14 != 0) {
            if (D_00142CAD[0] == 0) {
                return;
            }
            if (D_0014275D[0] == 0) {
                return;
            }
            if (D_001D545C == 0xD) {
                if ((*(s32 *)(D_001D52FC + 0x1A4) & 0x10) == 0) {
                    return;
                }
                if (D_L01_002D15F0[0] == 0xC) {
                    return;
                }
            }
        }
        if (D_001D545C == 4 && D_L01_001D6694 == 6) {
            return;
        }
        if (v->ba == 0) {
            func_L01_004450F0(o, 1, -1);
            return;
        }
        if (D_001A4BE0.w25C4 == 0x1C) {
            return;
        }
        if (D_001A4BE0.w25C4 == 0x31) {
            return;
        }
        if (D_001A4BE0.w2850 <= 0) {
            return;
        }
        if (D_L01_001D6694 != 0) {
            return;
        }
        if (v->w0 != -1 && func_00382380(&D_001A4BE0.x80, v->w0, 0) == 0) {
            return;
        }
        ok = 1;
        D_L01_001E1880 = D_L01_001DFB94;
        id = -1;
        if (D_L01_002AF350[D_001D545C] != 0 && D_L01_002AF350[D_001D545C][v->b8] != 0) {
            for (j = 0; D_L01_002AF350[D_001D545C][v->b8][j] != -1; j++) {
                id = D_L01_002AF350[D_001D545C][v->b8][j];
                if (v->bd == 0 && (v->w34 == -1 || (D_001BBC40[D_001D545C][v->w34] & 0x80)) &&
                    (D_00142BA0[(u32)id >> 2] & (1 << (id & 0x1F)))) {
                    continue;
                }
                if (func_00392B20(D_L01_001EA7C0, id) == 0 && j == 0) {
                    return;
                }
                ok = 0;
            }
        }
        if (ok != 0) {
            v->bf = 0;
            func_L01_004450F0(o, 4, -1);
            return;
        }
        v->bf = 1;
        func_00392C78(D_L01_001EA7C0);
        if (D_L01_001DFB40 < 5 || D_L01_001DF950 >= 0.83f) {
            D_L01_001DF950 = 1.5f;
            func_L01_004BA7B8();
        }
        func_L01_004450F0(o, 3, -1);
        break;
    case 3:
        if (D_001D545C == 3 && v->b8 == 0) {
            D_L01_001DFB94 = 0;
        }
        if (D_001D545C == 0xA && (u32)(D_L01_001E6DB0[0] - 5) < 2) {
            D_L01_001DFB94 = 0;
        }
        if (D_L01_001D6694 != 2) {
            if (D_L01_001DFB40 < 300 && D_L01_001DF950 > 0.7f) {
                D_L01_001DF950 = 1.5f;
            }
            if (v->w14 != 0 && D_001D545C == 0xD && D_L01_001D6690 != 6 && D_L01_001D6694 != 6) {
                vec.x = 260.53f;
                vec.y = 268.38f;
                vec.z = 100.0f;
                D_L01_001DFC28 = 1;
                D_0016C580.h26 = 1;
                D_0016C580.q70 = *(vu0_q *)&vec;
            }
        }
        if (func_L01_004BA800() == 0) {
            if (v->w4 != -1) {
                func_L01_004F50C8(D_L01_001E0100 + (v->w4 << 7) + 0x30, D_L01_001E0100 + (v->w4 << 7) + 0x70, 0, 1);
            }
            func_L01_004450F0(o, 4, -1);
        }
        if (D_001D545C != 0 || v->c9 == -1 || func_L01_004BA800() != 0) {
            goto chk;
        }
        f = 0;
        if (v->c9 != -1) {
            func_L01_0044CCC8(v->c9);
            func_0039EF28();
            if (v->c9 != 0x18) {
                func_L01_0044FC48(v->c9, 0);
            }
            f = 1;
        }
        if (o->bb0 != 0xFF && (D_001BBC40[D_001D545C][o->bb0] & 0x80) == 0) {
            func_L01_0043B510(o->bb0);
            f = 1;
        }
        if (v->cb != 0) {
            if (*(u32 *)((u8 *)v + 0xC) & 0xFFFF0000) {
                if (v->w4 != -1) {
                    func_L01_004A3610(D_L01_001E0100 + (v->w4 << 7) + 0x30, D_L01_001E0100 + (v->w4 << 7) + 0x70);
                } else {
                    func_L01_004A3610((u8 *)o + 0x10, (u8 *)o + 0xF0);
                }
            }
        }
        if (v->cc != -1) {
            if (v->b39 == 0) {
                func_00392DF0(v->cc, 1);
            } else {
                D_L01_001D6694 = 3;
                D_L01_001D6690 = -2;
                func_003A0EC0(6, 2, 1, v->cc, 0);
            }
        } else if (f != 0 || v->bf != 0) {
            func_0039EC28(0, -1);
        }
    chk:
        if (o->b20 != 4) {
            break;
        }
    case 4:
        D_L01_001DFB94 = D_L01_001E1880;
        g = 0;
        if (v->c9 != -1) {
            func_L01_0044CCC8(v->c9);
            func_0039EF28();
            func_L01_0044FC48(v->c9, 0);
            if (v->c38 != -1) {
                func_L01_0044CCC8(v->c38);
                func_0039EF28();
                func_L01_0044FC48(v->c38, 1);
            }
            g = 1;
        }
        if (o->bb0 != 0xFF && (D_001BBC40[D_001D545C][o->bb0] & 0x80) == 0) {
            func_L01_0043B510(o->bb0);
            g = 1;
        }
        if (v->w10 != 0) {
            if (D_001D545C == 0x13) {
                D_001426E0[0x82] |= 1;
                func_0039EF28();
            } else if (D_001D545C == 0x11) {
                if (D_00142CA0[0x22] == 0) {
                    D_00142CA0[0x22] = 1;
                    D_00142D62[0] = 1;
                    func_0039EF28();
                    func_L01_00452560(0, 0xF, 0x14EB, 0x96, 0, 0, 0);
                }
            } else if (D_001D545C == 7) {
                if (D_00142CBE[0] == 0) {
                    func_L01_00419188(0x1E);
                    func_L01_00452560(0, 0xF, 0xAF0, 0x96, 0, 0, 0);
                }
            } else {
                D_0014275C[0] = 1;
            }
            g = 1;
        }
        if (v->cb > 0 && (*(u32 *)((u8 *)v + 0xC) & 0xFFFF0000)) {
            if (v->w4 != -1) {
                func_L01_004A3610(D_L01_001E0100 + (v->w4 << 7) + 0x30, D_L01_001E0100 + (v->w4 << 7) + 0x70);
            } else {
                func_L01_004A3610(D_001A4C60, D_001A4C60 + 0x10);
            }
        }
        for (i = 0; i < 4; i++) {
            if (v->w20[i] >= 0) {
                func_L01_00456230(D_L01_001E001C + (v->w20[i] << 8), 1);
            }
        }
        if (D_001D545C == 0x16) {
            if (v->w20[0] >= 0) {
                vt = func_L01_0043B548(0x19E1, 0x6C);
                vt->f24(0, 0);
                vt->f44(1);
                D_001BBC40[0x16][2] = 0x80;
                D_L01_001DFE82 = 0x80;
                x = ((D_001D545C & 0x1F) << 11) | 0x64;
                D_001426E0[0x72] = x;
                D_001426E0[0x71] = x >> 8;
            }
        }
        if (v->cc != -1) {
            if (D_001D545C == 0xA && v->b8 == 0) {
                func_L01_0042B068(1, 0);
            } else if (v->cc == D_001D545C) {
                if (D_L01_001F3F40[3] > 0) {
                    func_L01_0042B068(1 - D_L01_001F3F40[0], 0);
                } else {
                    goto lab_a40;
                }
            } else {
            lab_a40:
                if (v->b39 == 0) {
                    func_00392DF0(v->cc, 1);
                } else {
                    D_L01_001D6694 = 3;
                    D_L01_001D6690 = -2;
                    func_003A0EC0(6, 2, 1, v->cc, 0);
                }
            }
        } else if (g != 0 || v->bf != 0) {
            if (v->cb != v->cc) {
                func_0039EC28(0, -1);
            }
        }
        if (v->w30 != -1) {
            e = (E_32A168 *)(D_L01_001E001C + (v->w30 << 8));
            func_L01_00456230(e, 1);
            e->h34 &= ~2;
            e->b30 = 0xFF;
            e->f64((u8 *)e);
        }
        if (v->b3a != 0) {
            func_0038CE20(&vec, &D_001A4BE0, 3.0f);
            vec_add_ab(&vec, &vec, &D_001A4BE0.x80);
            vec.z += 0.5f;
            vec.z = func_003C3D30(&vec, 0, 0, 0.5f);
            if (fabs_asm(D_001A4BE0.z88 - vec.z) > 0.3f) {
                return;
            }
            func_L01_00511A40(&vec, 1, D_001A4BE0.f98);
        }
        if (v->b3b != 0 && o->b94 == 3) {
            func_003A0EC0(5, 1, 6, 0, 0);
        }
        func_003C2880(o);
        break;
    }
}
/* localdecomp:end func_L01_0032A168 */

/* localdecomp:start func_L01_0032AD70 */
extern s32 D_001D545C;
extern s16 **D_L01_002AF350[];

s32 func_L01_0032AD70(u8 *a0) {
    s16 **tbl = D_L01_002AF350[D_001D545C];
    u8 *v = *(u8 **)(a0 + 0x68);
    s16 *p;

    if (tbl != 0) {
        p = tbl[v[8]];
        if (p != 0) {
            return *p;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_0032AD70 */

/* localdecomp:start func_L01_0032ADC0 */
extern u8 D_L01_001DCE18;
__asm__(".extern D_L01_001DCE18, 4");

u8 *func_L01_0032ADC0(s32 a0, s32 a1, s32 *a2) {
    if (a1 == 0) {
        *a2 = 4;
        return &D_L01_001DCE18;
    }
    return 0;
}
/* localdecomp:end func_L01_0032ADC0 */

LINKER_REMNANT("asm/levels", func_L01_0032ADE0);

/* localdecomp:start func_L01_0032ADE8 */
/* from rac2-decomp's func_001203C0, renamed */
void func_L01_0032ADE8(void) {
}
/* localdecomp:end func_L01_0032ADE8 */
