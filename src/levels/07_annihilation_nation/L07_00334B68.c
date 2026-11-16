#include "common.h"

typedef struct E_003354A0 {
    u8 pad0[0x9E];
    u8 f9E;
    u8 f9F;
    u8 pad1[4];
    s16 fA4;
} E_003354A0;
typedef struct O_003354A0 {
    u8 pad0[0x68];
    E_003354A0 *f68;
} O_003354A0;

/* localdecomp:start func_L07_00334B68 */
s32 func_00382498(s32, s32);
s32 func_L07_003A2380(s32, s32, s32, s32);

void func_L07_00334B68(s32 arg0) {
    func_L07_003A2380(func_00382498(0x43, 0x46) & 0xFF, arg0, 0, 0x64);
}
/* localdecomp:end func_L07_00334B68 */

/* localdecomp:start func_L07_00334BA8 */
s32 func_00382498(s32, s32);
s32 func_L07_003A2380(s32, s32, s32, s32);

void func_L07_00334BA8(s32 arg0) {
    func_L07_003A2380(func_00382498(0x47, 0x49) & 0xFF, arg0, 0, 0x64);
}
/* localdecomp:end func_L07_00334BA8 */

/* localdecomp:start func_L07_00334BE8 */
s32 func_00382498(s32, s32);
s32 func_L07_003A2380(s32, s32, s32, s32);

void func_L07_00334BE8(s32 arg0) {
    func_L07_003A2380(func_00382498(0x4A, 0x4E) & 0xFF, arg0, 0, 0x64);
}
/* localdecomp:end func_L07_00334BE8 */

/* localdecomp:start func_L07_00334C28 */
typedef struct { u8 pad[0xE0]; u32 flags; } Data_00334C28;
typedef struct { s32 pad[2]; s32 count; } Progress_00334C28;
typedef struct { u8 pad[0x2808]; u8 *target; u8 gap[0x44]; s32 count; } State_00334C28;
extern Progress_00334C28 D_00142660[];
extern State_00334C28 D_001A4BE0[];
void func_L07_00334C28(s32 arg0) {
    extern s32 func_00382468(s32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_L07_003A2380(s32, s32, s32, s32);
    Data_00334C28 *p = *(Data_00334C28 **)(arg0 + 0x68);
    s32 r;
    if ((D_00142660[0].count >> 3) >= D_001A4BE0[0].count) {
        switch (r = func_00382468(3)) {
        case 0:
            if (!(p->flags & 0x40)) {
                func_L07_003A2380(0x59, arg0, 0, 100);
                r = p->flags;
                r |= 0x40;
                p->flags = r;
                return;
            }
        case 1:
            if (!(p->flags & 0x80)) {
                func_L07_003A2380(0x5A, arg0, 0, 100);
                r = p->flags;
                r |= 0x80;
                p->flags = r;
                return;
            }
        }
    }
    if ((D_00142660[0].count >> 2) >= D_001A4BE0[0].count) {
        switch (r = func_00382468(3)) {
        case 0:
            if (!(p->flags & 0x100)) {
                func_L07_003A2380(0x57, arg0, 0, 100);
                r = p->flags;
                r |= 0x100;
                p->flags = r;
                return;
            }
        case 1:
            if (!(p->flags & 0x200)) {
                func_L07_003A2380(0x58, arg0, 0, 100);
                r = p->flags;
                r |= 0x200;
                p->flags = r;
                return;
            }
        }
    }
    if (D_001A4BE0[0].target) {
        switch (*(s16 *)(D_001A4BE0[0].target + 0xAA)) {
        case 0x1A18:
            if (func_00382468(5) == 0) {
                func_L07_003A2380(0x5B, arg0, 0, 100);
                return;
            }
        case 0x1769: case 0x195E: case 0x19BE: case 0x19D2:
        case 0x1D88: case 0x1D89: case 0x1D8B: case 0x1D8C:
            func_L07_003A2380(func_00382498(0x54, 0x56) & 0xFF, arg0, 0, 100);
            return;
        }
    }
    func_L07_003A2380(func_00382498(0x52, 0x53) & 0xFF, arg0, 0, 100);
}
/* localdecomp:end func_L07_00334C28 */

/* localdecomp:start func_L07_00334EC0 */
typedef union U_00334EC0 {
    u32 w;
    u8 b;
} U_00334EC0;
typedef struct S_00334EC0 {
    u8 pad0[0xE0];
    U_00334EC0 fE0;
} S_00334EC0;
typedef struct O_00334EC0 {
    u8 pad0[0x68];
    S_00334EC0 *f68;
} O_00334EC0;

s32 func_00382468(s32);
s32 func_00382498(s32, s32);
s32 func_L07_003A2380(s32, s32, s32, s32);

s32 func_L07_00334EC0(s32 arg0) {
    S_00334EC0 *s = ((O_00334EC0 *)arg0)->f68;

    if (s->fE0.w & 1) {
        if (!(s->fE0.w & 2)) {
            func_L07_003A2380(0x3D, arg0, 0, 0x64);
            func_L07_003A2380(0x3E, arg0, 0, 0x258);
            s->fE0.w |= 2;
            return 1;
        }
    }
    if ((s->fE0.b ^ 1) & 1) {
        func_L07_003A2380(0x3C, arg0, 0, 0x64);
        s->fE0.w |= 1;
        return 1;
    }
    if (func_00382468(2)) {
        func_L07_003A2380(func_00382498(0x62, 0x69) & 0xFF, arg0, 0, 0x64);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L07_00334EC0 */

/* localdecomp:start func_L07_00334FB0 */
typedef struct Row_00334FB0 {
    u8 pad0[4];
    u8 *f4;
    u8 *f8;
    u8 fC;
} Row_00334FB0;
typedef struct Res_00334FB0 {
    u8 pad0[2];
    u8 f2;
    u8 f3;
    s32 f4;
    s32 f8;
} Res_00334FB0;
typedef struct Ent_00334FB0 {
    u8 pad0[0x9E];
    u8 f9E;
    u8 f9F;
} Ent_00334FB0;
typedef struct Obj_00334FB0 {
    u8 pad0[0x68];
    Ent_00334FB0 *f68;
} Obj_00334FB0;

extern Row_00334FB0 D_L07_002B0D40_00334FB0[];
extern s32 func_L07_00333460(s32, s32);
extern s32 func_L07_003A2380(s32, s32, s32, s32);
extern s32 func_00382498(s32, s32);

void func_L07_00334FB0(s32 arg0) {
    Ent_00334FB0 *e = ((Obj_00334FB0 *)arg0)->f68;
    Res_00334FB0 *r;
    s32 id;
    s32 done;

    id = e->f9E;
    done = 0;
    if (D_L07_002B0D40_00334FB0[id].fC == 0) {
        r = (Res_00334FB0 *)func_L07_00333460(id, e->f9F);
        if (r->f4 != -1) {
            func_L07_003A2380(0x2B, arg0, 0, 0x64);
            done = 1;
        }
        if (!done) {
            if (r->f2 != 0) {
                func_L07_003A2380(0x37, arg0, 0, 0x64);
                done = 1;
            }
            if (!done) {
                if (r->f8 != -1) {
                    func_L07_003A2380(0x2E, arg0, 0, 0x64);
                    done = 1;
                }
                if (!done) {
                    if (r->f3 != 0) {
                        func_L07_003A2380(0x30, arg0, 0, 0x64);
                        done = 1;
                    }
                }
            }
        }
    } else {
        func_L07_003A2380(0x3A, arg0, 0, 0x64);
        done = 1;
    }
    if (!done) {
        func_L07_003A2380(func_00382498(0x27, 0x29) & 0xFF, arg0, 0, 0x64);
    }
}
/* localdecomp:end func_L07_00334FB0 */

/* localdecomp:start func_L07_003350F0 */
typedef struct {
    u8 pad[0xC];
    u8 f0C;
    u8 pad2[3];
} Ent_003350F0;

typedef struct {
    u8 pad0[0x9E];
    u8 f9E;
    u8 f9F;
} E_003350F0;

typedef struct {
    u8 pad0[0x68];
    E_003350F0 *f68;
} O_003350F0;

extern Ent_003350F0 D_L07_002B0D40_003350F0[];
extern s32 func_L07_00333460(s32, s32);
extern s32 func_L07_003A2380(s32, s32, s32, s32);
extern s32 func_00382498(s32, s32);

void func_L07_003350F0(O_003350F0 *arg0) {
    E_003350F0 *s = arg0->f68;
    u8 idx = s->f9E;
    s32 *r;
    s32 done = 0;

    if (((Ent_003350F0 *)((u8 *)D_L07_002B0D40_003350F0 + (idx << 4)))->f0C == 0) {
        r = (s32 *)func_L07_00333460(idx, s->f9F);
        if (r[1] != -1) {
            func_L07_003A2380(0x2B, (s32)arg0, 0, 0x64);
            done = 1;
        }
        if (done == 0) {
            if (((u8 *)r)[2] != 0) {
                func_L07_003A2380(0x36, (s32)arg0, 0, 0x64);
                done = 1;
            }
        }
        if (done == 0) {
            if (r[2] != -1) {
                func_L07_003A2380(0x2D, (s32)arg0, 0, 0x64);
                done = 1;
            }
        }
        if (done == 0) {
            if (((u8 *)r)[3] != 0) {
                func_L07_003A2380(0x2F, (s32)arg0, 0, 0x64);
                done = 1;
            }
        }
    } else {
        func_L07_003A2380(0x3A, (s32)arg0, 0, 0x64);
        done = 1;
    }
    if (done == 0) {
        func_L07_003A2380(func_00382498(0x27, 0x29) & 0xFF, (s32)arg0, 0, 0x64);
    }
}
/* localdecomp:end func_L07_003350F0 */

/* localdecomp:start func_L07_00335230 */
s32 func_00382468(s32);
s32 func_00382498(s32, s32);
s32 func_L07_003A2380(s32, s32, s32, s32);

void func_L07_00335230(s32 arg0) {
    s32 r = func_00382468(4);

    switch (r) {
    case 0:
        func_L07_003A2380(0x4F, arg0, 0, 0x64);
        break;
    case 1:
        func_L07_003A2380(0x50, arg0, 0, 0x64);
        break;
    default:
        func_L07_003A2380(func_00382498(0x67, 0x69) & 0xFF, arg0, 0, 0x64);
        break;
    }
}
/* localdecomp:end func_L07_00335230 */

/* localdecomp:start func_L07_003352B8 */
typedef struct S_003352B8 {
    u8 pad0[0xB1];
    u8 fB1;
    u8 pad1[0xE0 - 0xB2];
    u32 fE0;
} S_003352B8;
typedef struct O_003352B8 {
    u8 pad0[0x68];
    S_003352B8 *f68;
} O_003352B8;

s32 func_00382468(s32);
s32 func_L07_003A2380(s32, s32, s32, s32);

void func_L07_003352B8(O_003352B8 *arg0, s32 arg1) {
    S_003352B8 *s = arg0->f68;
    s32 r;

    s->fE0 &= ~0x8000;
    if (s->fE0 & 0x10000) {
        func_L07_003A2380(0x32, (s32)arg0, 0, 0x64);
        s->fE0 &= ~0x10000;
        return;
    }
    r = func_00382468(6);
    switch (r) {
    case 0:
        if (!(s->fE0 & 0x1000)) {
            func_L07_003A2380(0x33, (s32)arg0, 0, 0x64);
            s->fE0 |= 0x1000;
        }
        break;
    case 1:
        switch (arg1) {
        case 0x13:
        case 0x27:
        case 0x3F:
        case 0x97:
            if (!(s->fE0 & 0x2000)) {
                func_L07_003A2380(0x34, (s32)arg0, 0, 0x64);
                s->fE0 |= 0x2000;
            }
            break;
        }
        break;
    case 2:
        if (s->fB1 >= 3 && !(s->fE0 & 0x4000)) {
            func_L07_003A2380(0x35, (s32)arg0, 0, 0x64);
            s->fE0 |= 0x4000;
        }
        break;
    }
}
/* localdecomp:end func_L07_003352B8 */

/* localdecomp:start func_L07_00335448 */
extern void func_L03_003AECB0(void *);
extern void func_L01_00516FD8(s32, void *);
extern u8 D_L07_001E0D10_00335448 __asm__("D_L07_001E0D10");
__asm__(".extern D_L07_001E0D10, 16");
extern u8 D_L07_001E0D20_00335448 __asm__("D_L07_001E0D20");
__asm__(".extern D_L07_001E0D20, 16");
extern void func_L07_003354A0(O_003354A0 *);

void func_L07_00335448(O_003354A0 *arg0) {
    func_L03_003AECB0(arg0);
    func_L01_00516FD8(0x150006, &D_L07_001E0D10_00335448);
    func_L01_00516FD8(0x150007, &D_L07_001E0D20_00335448);
    func_L07_003354A0(arg0);
}
/* localdecomp:end func_L07_00335448 */

/* localdecomp:start func_L07_003354A0 */
extern u8 D_L07_002B0D40[];
extern u8 D_L07_001DD128[];
extern u8 D_L07_001E0D10[];
extern u8 D_L07_001DD130[];
extern u8 D_L07_001E0D20[];
extern void func_11B2E8(long, ...);
extern s32 func_00381FF0(s32);
extern void func_L03_0032FAB8(s32, s32 *, s32 *);
s32 func_L07_00333460(s32, s32);

void func_L07_003354A0(O_003354A0 *arg0) {
    E_003354A0 *s0;
    s32 buf[2];
    s32 *r;
    s32 id, b0, b1;

    s0 = arg0->f68;
    func_11B2E8((long)D_L07_001E0D10, D_L07_001DD128, s0->f9F + 1, *(s16 *)(D_L07_002B0D40 + s0->f9E * 16));
    r = (s32 *)func_L07_00333460(s0->f9E, s0->f9F);
    if (r[1] != -1) {
        func_L03_0032FAB8(s0->fA4, &buf[0], &buf[1]);
        b1 = buf[1];
        b0 = buf[0];
        func_11B2E8((long)D_L07_001E0D20, D_L07_001DD130, b0, b1);
    } else {
        id = func_00381FF0(0x1921);
        func_11B2E8((long)D_L07_001E0D20, id);
    }
}
/* localdecomp:end func_L07_003354A0 */

/* localdecomp:start func_L07_00335558 */
typedef struct St_00335558 {
    u8 pad0[0x80];
    u8 f80[0x30];
    u8 bB0;
    u8 bB1;
    u8 padB2[2];
    s16 hB4;
} St_00335558;
typedef struct Obj_00335558 {
    u8 pad0[0x68];
    St_00335558 *f68;
} Obj_00335558;
typedef struct Row_00335558 {
    s32 w0;
    s32 w4;
} Row_00335558;
typedef struct GunRow_00335558 {
    u8 pad0[0x38];
    u16 icon;
    u8 pad1[0xF0 - 0x3A];
} GunRow_00335558;

extern Row_00335558 D_L07_002B0EB0[];
extern GunRow_00335558 D_L07_002C72C0[];
extern u8 D_001425C0[];
extern void func_L01_0047DA90(void);
extern void func_L01_0047B798(s32, s32);
extern void func_L01_0047B820(s32, s32);
extern void func_L01_0047B9B8(s32);
extern void func_L01_0047C220(s32);

void func_L07_00335558(Obj_00335558 *arg0) {
    St_00335558 *s = arg0->f68;
    Row_00335558 *row;
    GunRow_00335558 *gun;

    func_L01_0047DA90();
    row = &D_L07_002B0EB0[s->bB0];
    gun = &D_L07_002C72C0[D_001425C0[row->w0]];
    func_L01_0047B798(gun->icon, 0);
    func_L01_0047B820(s->hB4, 0);
    func_L01_0047B9B8(row->w0);
    func_L01_0047C220(8);
    s = (St_00335558 *)((u8 *)s + s->bB1);
    row = &D_L07_002B0EB0[s->f80[0]];
    gun = &D_L07_002C72C0[D_001425C0[row->w0]];
    func_L01_0047B798(gun->icon, 1);
}
/* localdecomp:end func_L07_00335558 */
