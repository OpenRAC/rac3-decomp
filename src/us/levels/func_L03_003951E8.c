#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_003951E8 */
typedef struct Obj_003951E8 {
    u8 pad0[0x10];
    f32 x;
    f32 y;
    u8 pad18[8];
    u8 b20;
    u8 pad21[0x10];
    u8 b31;
    u8 pad32[2];
    u16 h34;
    u8 pad36[0xC];
    u8 b42;
    u8 b43;
    u8 pad44[0x24];
    struct St_003951E8 *st;
    u8 pad6C[0x54];
    vu0_v4 v0C0;
    u8 padD0[0x28];
    f32 fF8;
    u8 padFC[4];
} Obj_003951E8;
typedef struct St_003951E8 {
    u8 pad0[0xB4];
    Obj_003951E8 *fB4;
    u8 padB8[0x68];
    vu0_v4 v120;
    vu0_v4 v130;
    s32 f140;
    u8 pad144[4];
    s32 f148;
    s32 f14C;
    u8 pad150[8];
    s32 f158;
    s16 h15C;
    s16 h15E;
    u8 pad160[0x14];
    Obj_003951E8 *f174;
    u8 pad178;
    u8 b179;
    s16 h17A;
} St_003951E8;
typedef struct {
    s32 n;
    u8 pad4[0xC];
    vu0_v4 pt[1];
} Path_003951E8;

extern Obj_003951E8 *D_L03_001DFA1C;
extern Path_003951E8 *D_L03_0021D940[];
extern s32 D_L03_001D6694_003951E8;
extern void func_L03_00395788(void *);
extern s32 func_L01_004B6C68(void);
extern void func_L03_00395978(void *);
extern s32 func_L01_00457440(void *, void *);
extern s32 func_L03_00395BE8(void *);
extern s32 func_L01_004435E8(void);
extern void func_L03_00395AC0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_L03_00395B38(void *);
extern f32 func_L01_0040C040(void *, void *);
extern f32 func_00388A28(f32, f32);
extern void func_L01_00457708(void *, f32);
extern f32 func_00389468(f32, f32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_004576E8(void *);
extern s32 func_003883C8(void *);

void func_L03_003951E8(Obj_003951E8 *o) {
    St_003951E8 *s;
    Path_003951E8 *path;
    Path_003951E8 *path2;
    s32 flags;
    Obj_003951E8 *other;
    s32 dir;
    f32 ang;
    f32 d;

    if (o->b20 == 0) {
        func_L03_00395788(o);
    }
    if (o != 0 && o->b20 != 0xFE && o->b20 != 0xFD) {
        s = o->st;
        if (D_L03_001D6694_003951E8 == 2) {
            o->b31 = 0;
            o->h34 = o->h34 | 1;
            D_L03_001DFA1C[s->f140].h34 = D_L03_001DFA1C[s->f140].h34 | 1;
            D_L03_001DFA1C[s->f140].b31 = 0;
            return;
        }
        if (func_L01_004B6C68() == 0) {
            o->b31 = 1;
            o->h34 = o->h34 & 0xFFFE;
            D_L03_001DFA1C[s->f140].h34 = D_L03_001DFA1C[s->f140].h34 & 0xFFFE;
            D_L03_001DFA1C[s->f140].b31 = 1;
        }
        if (o->h34 & 2) {
            return;
        }
        func_L03_00395978(o);
        switch (o->b20) {
        case 1:
            break;
        case 2:
            flags = func_L01_00457440(o, &s->v120);
            func_L03_00395BE8(o);
            if (s->fB4 != 0) {
                if (s->f148 != -1 && s->fB4 == D_L03_001DFA1C + s->f148) {
                    goto walk;
                }
                if (s->f158 != -1 && s->fB4 == D_L03_001DFA1C + s->f158) {
                    goto walk;
                }
                if (func_L01_004435E8() == 0) {
                    s->f174 = s->fB4;
                    func_L03_00395AC0(o, 6, 0, 0xC);
                    func_L01_00441FB8(o, 5, -1);
                    return;
                }
            }
        walk:
            if (flags & 0x80) {
                path2 = D_L03_0021D940[s->f14C];
                s->h15C = s->h15C + s->h15E;
                if (s->h15C >= path2->n) {
                    s->h15C = path2->n - 2;
                    s->h15E = -1;
                }
                if (s->h15C < 0) {
                    s->h15C = 1;
                    s->h15E = 1;
                }
                s->v120 = *(&path2->pt[0] + s->h15C);
                s->v130 = o->v0C0;
                if (func_L03_00395B38(o) < 0.0f) {
                    func_L01_00441FB8(o, 3, -1);
                    return;
                }
            }
            break;
        case 5:
            d = func_L01_0040C040(&s->f174->x, &o->x);
            if (!(16.0f < d)) {
                if (func_L03_00395BE8(o) == 0) {
                    break;
                }
            }
            func_L03_00395AC0(o, 2, 0, 0xA);
            func_L01_00441FB8(o, 2, -1);
            return;
        case 3:
            if (o->b42 == 2) {
                ang = func_00388A28(s->v120.x - o->x, s->v120.y - o->y);
                func_L01_00457708(o, ang);
                d = func_00389468(ang, o->fF8);
                if (d < 0.08726646f) {
                    if (o->b43 != 0) {
                        func_003BE4F0(o, 0, 0, 8);
                    }
                }
            } else {
                func_L01_004576E8(o);
            }
            if (func_L03_00395B38(o) >= 0.0f) {
                if (s->b179 ? s->h15E == 1 : s->h15E == -1) {
                    goto fin3;
                }
                s->h17A = 0x32;
                func_L01_00441FB8(o, 4, -1);
                return;
            }
            other = D_L03_001DFA1C + s->f148;
            if (other->b20 != 3) {
                return;
            }
            dir = s->h15C < other->st->h15C ? 1 : -1;
            if (dir != s->h15E) {
                path = D_L03_0021D940[s->f14C];
                s->h15E = dir;
                s->h15C = s->h15C + dir;
                if (s->h15C >= path->n) {
                    s->h15C = path->n - 2;
                    s->h15E = -1;
                }
                if (s->h15C < 0) {
                    s->h15C = 1;
                    s->h15E = 1;
                }
                s->v120 = *(&path->pt[0] + s->h15C);
            }
        fin3:
            if (o->b43 != 2) {
                func_003BE4F0(o, 2, 0, 8);
            }
            func_L01_00441FB8(o, 2, -1);
            return;
        case 4:
            if (o->b42 == 2) {
                ang = func_00388A28(s->v120.x - o->x, s->v120.y - o->y);
                func_L01_00457708(o, ang);
                d = func_00389468(ang, o->fF8);
                if (d < 0.08726646f) {
                    if (o->b43 != 0) {
                        func_003BE4F0(o, 0, 0, 8);
                    }
                }
            } else {
                func_L01_004576E8(o);
            }
            if (func_003883C8(&s->h17A) != 0) {
                if (o->b43 != 2) {
                    func_003BE4F0(o, 2, 0, 8);
                }
                func_L01_00441FB8(o, 2, -1);
            }
            break;
        }
    }
}
/* localdecomp:end func_L03_003951E8 */
