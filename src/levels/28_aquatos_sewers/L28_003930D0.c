#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L28_003930D0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003930D0;
typedef struct {
    s32 n;
    s32 pad[3];
    V4_003930D0 p[1];
} Path_003930D0;

extern u8 *D_L28_001DEC9C;
extern u8 D_L28_001D66B0[8];
extern Path_003930D0 *D_L28_0021C940[];
extern s32 D_001D545C;
extern s32 D_L28_001DDC98;
extern f32 D_L28_001DDC9C;
extern f32 D_L28_001DDCA0;
extern f32 D_L28_001DDCA4;
extern f32 D_L28_001DDCA8;
extern f32 D_L28_001DDCAC;
extern s32 D_L28_001DDCB0;
extern s32 D_L28_001DDCB4;
extern s32 D_L28_001DDCB8;
extern s32 D_L28_001DDCBC;
extern f32 D_L28_001DDCC0;
__asm__(".extern D_L28_001DDC98, 4");
__asm__(".extern D_L28_001DDC9C, 4");
__asm__(".extern D_L28_001DDCA0, 4");
__asm__(".extern D_L28_001DDCA4, 4");
__asm__(".extern D_L28_001DDCA8, 4");
__asm__(".extern D_L28_001DDCAC, 4");
__asm__(".extern D_L28_001DDCB0, 4");
__asm__(".extern D_L28_001DDCB4, 4");
__asm__(".extern D_L28_001DDCB8, 4");
__asm__(".extern D_L28_001DDCBC, 4");
__asm__(".extern D_L28_001DDCC0, 4");

extern s32 func_L28_003941D8(u8 *);
extern void func_L28_00394768(u8 *);
extern s32 func_L28_00394890(u8 *, s32);
extern s32 func_L28_00394988(u8 *, s32);
extern void func_L28_00394618(void *);
extern void func_003C2880(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_004561E0(void *);
extern s32 func_L01_00456500(void *, s32);
extern s32 func_00382498(s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_00454370(void *, void *);
extern void func_L01_00451FE0(u8 *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32,
                              s32);
extern void func_L01_004443E8(u8 *, s32, s32);
extern void func_L01_00315900(void *, s32, s32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L01_00459590(void *, s32, f32);
extern void func_L08_003A1BE8(u8 *, u8 *);
extern void func_L02_003F4BE8(s32, s32);
extern f32 func_L01_0040E570(void *, void *);
extern f32 func_0038D160(f32, f32);
extern s32 func_L01_0044E1B8(void *, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L01_0045C150(void *, void *, s32, s32);
extern void func_L01_0045A748(void *, void *);
extern s32 func_L01_0045BDE8(void *, s32);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_00446780(u8 *, void *, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_L01_0045BD10(void *, f32);
extern f32 func_L01_004395E0(void *);
extern void func_003C4C18(void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L01_00447878(void *, void *, s32, f32, f32);
extern s32 func_L08_003AA088(void *, void *, void *, f32, f32);
extern void func_L01_004468C8(u8 *, s32, f32, s32, f32, f32, s32, s32, s32);

#define FRAMES(x) (((x) * 5 + 2) / 6)
#define U8(p, o) (((struct { u8 _p[o]; u8 v; } *)(p))->v)
#define U16(p, o) (((struct { u8 _p[o]; u16 v; } *)(p))->v)
#define S16(p, o) (((struct { u8 _p[o]; s16 v; } *)(p))->v)
#define S32(p, o) (((struct { u8 _p[o]; s32 v; } *)(p))->v)
#define F32(p, o) (((struct { u8 _p[o]; f32 v; } *)(p))->v)

#define KILL_003930D0(m)                                                                                          \
    func_L01_00451FE0(m, 0x4FFF, D_L28_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0, 0, 35, 1.0f, 1.0f, \
                      0, 3);                                                                                    \
    func_L01_00451FE0(m, 0x4FFF, D_L28_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0, 0, 35, 1.0f, 1.0f, \
                      0, 3);                                                                                    \
    func_L01_004443E8(m, 0, 3);                                                                                 \
    func_003C2880(m)

void func_L28_003930D0(u8 *self) {
    u8 *st = *(u8 **)(self + 0x68);
    s32 found;
    s32 idx, idx2, idx3, i2;
    s32 r;
    s32 r4;
    s32 i;
    Path_003930D0 *path;
    f32 d0, g;

    if (func_L28_003941D8(self) != 0) {
        func_003C2880(self);
        return;
    }

    switch (self[0x95]) {
    case 3:
        found = 0;
        if (func_L28_00394890(self, 0) != 0) {
            found = 1;
            S32(st, 0x338) = 0;
        } else if (func_L28_00394890(self, 1) != 0) {
            found = 1;
            S32(st, 0x338) = 1;
        }
        if (S32(st, 0x340) != 0 && func_L01_00456500(st + 0x220, S32(st, 0x2F8)) != 0) {
            func_L01_004450F0(self, 1, 0);
        }
        if (S32(st, 0x344) != 0 && func_L01_00456500(st + 0x220, S32(st, 0x310)) != 0) {
            func_L01_004450F0(self, 1, 0);
        }
        if (found) {
            u8 *o;
            *(s32 *)(st + (S32(st, 0x338) << 2) + 0x340) = 1;
            o = *(u8 **)(self + 0x24);
            U16(self, 0x34) &= ~0x41;
            U16(self, 0x34) |= U16(o, 0x44) & 0x1000;
            S32(self, 0x98) = S32(o, 0x10);
            func_L01_004450F0(self, 4, 1);
            idx3 = S32(st, 0x338) ? S32(st, 0x318) : S32(st, 0x300);
            if (idx3 != -1) {
                func_L01_004450F0(self, 2, 1);
            }
        }
        break;
    case 4:
        found = 0;
        if (func_L28_00394890(self, 0) != 0) {
            found = 1;
            S32(st, 0x338) = 0;
        } else if (func_L28_00394890(self, 1) != 0) {
            found = 1;
            S32(st, 0x338) = 1;
        }
        if (found) {
            u8 *o = *(u8 **)(self + 0x24);
            U16(self, 0x34) &= ~0x41;
            U16(self, 0x34) |= U16(o, 0x44) & 0x1000;
            S32(self, 0x98) = S32(o, 0x10);
            *(s32 *)(st + (S32(st, 0x338) << 2) + 0x340) = 1;
            func_L01_004450F0(self, 10, 1);
            if (self[0x43] != 8) {
                func_003C3A10(self, 8, 0, 8);
            }
        }
        break;
    case 0:
        if (S16(st, 0x234) == 1) {
            if (func_L28_00394988(self, 0) != 0) {
                S32(st, 0x338) = 0;
                if (S32(st, 0x340) == 0) {
                    goto no;
                }
                func_L01_004450F0(self, 4, 1);
            } else if (func_L28_00394988(self, 1) != 0) {
                S32(st, 0x338) = 1;
                if (S32(st, 0x344) != 0) {
                    func_L01_004450F0(self, 4, 1);
                } else {
                no:
                    func_L01_004450F0(self, 12, 3);
                }
            }
        }
        break;
    case 1:
        if (S16(st, 0x234) != 1 && func_L01_004561E0(self) == 0 && self[0x20] != 10) {
            func_L01_004450F0(self, 6, 0);
            S32(st, 0x32C) = FRAMES(func_00382498(0x244, 0x258));
        }
        break;
    case 2:
        r = func_L01_00454370(self, st + 0x160);
        if (func_L01_004561B8(self) != 0 && self[0x94] == 2) {
            idx2 = S32(st, 0x338) ? S32(st, 0x318) : S32(st, 0x300);
            if (idx2 != -1) {
                u8 *m = D_L28_001DEC9C + (idx2 << 8);
                KILL_003930D0(m);
                if (S32(st, 0x338) == 0) {
                    S32(st, 0x300) = -1;
                } else {
                    S32(st, 0x318) = -1;
                }
            }
        }
        if (r & 1) {
            V4_003930D0 q;
            V4_003930D0 p;
            V4_003930D0 *pq;
            func_L28_00394618(self);
            func_L01_00315900(self, 7, 0);
            for (i = 4; i < 8; i++) {
                func_003C2F58(self, i, &p);
                pq = &q;
                q = p;
                q.w = 5.0f;
                if (func_L01_00459590(pq, 0, 255.0f) >= 0) {
                    func_L08_003A1BE8(self, (u8 *)&p);
                }
            }
            if (S32(st, 0x300) != -1) {
                u8 *m = D_L28_001DEC9C + (S32(st, 0x300) << 8);
                KILL_003930D0(m);
            }
            if (S32(st, 0x318) != -1) {
                u8 *m = D_L28_001DEC9C + (S32(st, 0x318) << 8);
                KILL_003930D0(m);
            }
            return;
        }
        if (r & 2) {
            if (S16(st, 0x234) == 1) {
                func_L01_004450F0(self, 4, 1);
            } else {
                func_L01_004450F0(self, 1, 0);
                S32(st, 0x32C) = FRAMES(func_00382498(0x244, 0x258));
            }
        }
        break;
    }

    switch (self[0x20]) {
    case 1:
        if (func_L01_004561B8(self) != 0 && self[0x43] != 1) {
            func_003C3A10(self, 1, 0, 8);
        }
        break;
    case 2:
        i2 = S32(st, 0x338) ? S32(st, 0x308) : S32(st, 0x2F0);
        path = D_L28_0021C940[i2];
        if (func_L01_004561B8(self) != 0) {
            if (D_001D545C == 8) {
                func_L02_003F4BE8(0xB76, 0x3A98);
            }
            if (self[0x43] != 0) {
                func_003C3A10(self, 0, 0, 8);
            }
            d0 = func_L01_0040E570(&path->p[0], st + 0x2E0);
            if (func_L01_0040E570(&path->p[path->n - 1], st + 0x2E0) < d0) {
                F32(self, 0x10) = path->p[path->n - 1].x;
                F32(self, 0x14) = path->p[path->n - 1].y;
            } else {
                F32(self, 0x10) = path->p[0].x;
                F32(self, 0x14) = path->p[0].y;
            }
            F32(self, 0xF8) = func_0038D160(F32(st, 0x220) - F32(self, 0x10), F32(st, 0x224) - F32(self, 0x14));
        }
        if (func_L01_0044E1B8(self, 20.0f) != 0 && self[0x42] == 0) {
            u8 *m = D_L28_001DEC9C + ((S32(st, 0x338) ? S32(st, 0x318) : S32(st, 0x300)) << 8);
            KILL_003930D0(m);
            if (S32(st, 0x338) == 0) {
                S32(st, 0x300) = -1;
            } else {
                S32(st, 0x318) = -1;
            }
        }
        if (self[0x60] & 2) {
            func_L01_004450F0(self, 4, -1);
        }
        break;
    case 10: {
        f32 h;
        h = func_003C3D30(self + 0x10, 0x10, 0, 0.5f);
        if (h < 959.0f && F32(st, 0x34C) >= 959.0f) {
            h = 959.0f;
        }
        if (h < 959.0f && F32(st, 0x34C) >= 959.0f) {
            h = 959.0f;
        }
        F32(self, 0x18) -= 0.70000005f;
        if (F32(self, 0x18) < h) {
            F32(self, 0x18) = h;
        }
        if (self[0x60] & 2) {
            func_L01_004450F0(self, 4, -1);
            if (self[0x43] != 2) {
                func_003C3A10(self, 2, 0, 7);
            }
        }
        break;
    }
    case 4:
        idx = S32(st, 0x338) ? S32(st, 0x308) : S32(st, 0x2F0);
        if (func_L01_004561B8(self) != 0) {
            S32(st, 0xA8) &= ~4;
            S32(st, 0xA8) &= ~0x10;
            F32(st, 0x78) = 0.7f;
            F32(st, 0x7C) = 0.7f;
            U16(self, 0x34) &= ~0x100;
            F32(st, 0x80) = 12.566371f;
            S32(st, 0xA8) |= 3;
            if (idx != -1) {
                path = D_L28_0021C940[idx];
                d0 = func_L01_0040E570(&path->p[0], st + 0x2E0);
                if (func_L01_0040E570(&path->p[path->n - 1], st + 0x2E0) < d0) {
                    func_L01_0045C150(self, path, 0, 0);
                } else {
                    func_L01_0045C150(self, path, path->n - 1, path->n - 1);
                }
            }
            if (self[0x43] != 2) {
                func_003C3A10(self, 2, 0, 8);
            }
        }
        if (idx == -1) {
            func_L01_0045A748(self, st + 0x220);
            if (func_0038CF38(self + 0x10, st + 0x220) < D_L28_001DDCAC) {
                func_L01_004450F0(self, 9, -1);
            }
        } else {
            r4 = func_L01_0045BDE8(self, idx);
            if (func_0038CF38(self + 0x10, st + 0x220) < D_L28_001DDCAC) {
                func_L01_004450F0(self, 9, -1);
            } else if (r4 != 0 || U16(self, 0x96) > 0x32) {
                func_L01_004450F0(self, 7, -1);
            }
            if (func_0038CF38(self + 0x10, st + 0x220) < 6.0f) {
                func_L01_004450F0(self, 7, -1);
                if (self[0x43] != 4) {
                    func_003C3A10(self, 4, 0, 8);
                }
            }
        }
        if (func_L01_00456500(st + 0x220, S32(st, 0x338) ? S32(st, 0x310) : S32(st, 0x2F8)) == 0) {
            func_L01_004450F0(self, 6, -1);
        }
        func_L01_00446780(self, self + 0x10, 0x10000, 0, 1, 0, D_L28_001DDCC0, 5.0f, 1.0f);
        break;
    case 6:
        if (func_L01_004561B8(self) != 0 && self[0x43] != 3) {
            func_003C3A10(self, 3, 0, 8);
        }
        func_L01_0045A748(self, st + 0x2E0);
        if (func_0038CF38(self + 0x10, st + 0x2E0) < F32(st, 0xA4)) {
            func_L01_004450F0(self, 1, 0);
        }
        break;
    case 7:
        func_L01_0045BD10(self, func_0038D160(F32(st, 0x220) - F32(self, 0x10), F32(st, 0x224) - F32(self, 0x14)));
        if (func_L01_004561B8(self) != 0 && self[0x43] != 4) {
            func_003C3A10(self, 4, 0, 8);
        }
        if (self[0x60] & 2) {
            func_L01_004450F0(self, 8, -1);
            if (self[0x43] != 5) {
                func_003C3A10(self, 5, 0, 2);
            }
        }
        break;
    case 8:
        func_L01_0045BD10(self, func_0038D160(F32(st, 0x220) - F32(self, 0x10), F32(st, 0x224) - F32(self, 0x14)));
        if (func_L01_004561B8(self) != 0) {
            S32(st, 0x348) = 0;
        }
        if (self[0x60] & 2) {
            func_L01_004450F0(self, 4, -1);
        }
        if (func_L01_004395E0(self) > D_L28_001DDCA0 && S32(st, 0x348) < D_L28_001DDC98) {
            V4_003930D0 tgt;
            V4_003930D0 muz;
            V4_003930D0 dir;
            f32 d, sp;
            V4_003930D0 *pv;
            d = func_0038CF38(self + 0x10, st + 0x220);
            tgt = *(V4_003930D0 *)(st + 0x220);
            pv = &tgt;
            if (S32(st, 0x348) != 0) {
                func_003C4C18(pv, D_L28_001DDC9C * d);
            }
            sp = D_L28_001DDCA4 * d;
            func_003C2F58(self, 2, &muz);
            vec_sub_ab(&dir, &tgt, &muz);
            sp = sp * 0.020000001f;
            func_0038CF68(&dir, &dir, sp);
            dir.z = func_L01_00447878(&muz, pv, 0, sp, -(D_L28_001DDCA8 * 0.00040000002f));
            func_L08_003AA088(&muz, &dir, self, 5.0f, D_L28_001DDCA8);
            S32(st, 0x348)++;
        }
        break;
    case 9:
        if (func_L01_004561B8(self) != 0 && self[0x43] != 6) {
            func_003C3A10(self, 6, 0, 8);
        }
        func_L01_0045BD10(self, func_0038D160(F32(st, 0x220) - F32(self, 0x10), F32(st, 0x224) - F32(self, 0x14)));
        g = func_L01_004395E0(self);
        if (g < (f32)D_L28_001DDCBC && (f32)D_L28_001DDCB8 < g) {
            func_L01_004468C8(self, 0, 1.0f, 1, 5.0f, 1.5f, 0, 1, 0);
        }
        if (g < (f32)D_L28_001DDCB4 && (f32)D_L28_001DDCB0 < g) {
            func_L01_004468C8(self, 1, 1.0f, 1, 5.0f, 1.5f, 0, 1, 0);
        }
        if (self[0x60] & 2) {
            func_L01_004450F0(self, 4, -1);
        }
        break;
    }
    func_L28_00394768(self);
}
/* localdecomp:end func_L28_003930D0 */

/* localdecomp:start func_L28_003941D8 */
extern s32 func_L28_00394320(void *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L02_0034FD58(void *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L28_00394618(void *);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
s32 func_L28_003941D8(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    if (a0[0x20] == 0) {
        if (func_L28_00394320(a0) != 0) return 1;
    }
    if (st[0x3E] == 2) {
        func_L28_00394618(a0);
        return 1;
    }
    if (func_L01_00452FB0(a0, st + 0x160, 0, 0, 0) != 0) func_L02_0034FD58(a0);
    func_L01_00452860(a0, st + 0x30, 0);
    if (st[0x5E] != 0) {
        func_L28_00394618(a0);
        return 1;
    }
    if (st[0x5F] != 0) {
        func_L01_00456BD0(a0, 5);
        func_L01_00456C98(a0, *(s32 *)(st + 0x324), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(st + 0x328), 10.0f, 1.0f);
    } else {
        func_L01_00456BD0(a0, 3);
        func_L01_00456C98(a0, *(s32 *)(st + 0x324), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(st + 0x328), 10.0f, 1.0f);
    }
    return 0;
}
/* localdecomp:end func_L28_003941D8 */

/* localdecomp:start func_L28_00394320 */
/* func_L28_00394320 */
#include "common.h"
typedef int q_00394320 __attribute__((mode(TI)));
__asm__(".extern D_L28_001DEC9C, 4");
extern u8 *D_L28_001DEC9C;
__asm__(".extern D_001D545C, 16");
extern s32 D_001D545C;
typedef struct { u8 pad[0x464]; u8 arr[1]; } T_394320;
extern T_394320 D_L28_00234A80_00394320;
extern u8 D_001BBE90[];
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L01_004443E8(u8 *, s32, s32);
extern void func_003C2880(void *);
s32 func_L28_00394320(void *arg) {
    u8 *a0 = arg;
    u8 *st = *(u8 **)(a0 + 0x68);
    u8 *m;
    u16 h;
    s32 v;
    st[0x170] = 0xB;
    st[0x1A8] = 2;
    st[0x171] = 8;
    st[0x176] = 8;
    *(f32 *)(st + 0x19C) = 0.15000001f;
    st[0x1DB] = 0xFF;
    *(f32 *)(st + 0x190) = 0.5f;
    *(f32 *)(st + 0x194) = 0.5f;
    st[0x1D7] = 1;
    st[0x1D8] = 0;
    st[0x1D9] = 0;
    st[0x1DA] = 0;
    *(f32 *)(st + 0x34C) = *(f32 *)(a0 + 0x18);
    *(f32 *)(a0 + 0x2C) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) * 1.25f;
    *(f32 *)(st + 0x70) = 2.6f;
    *(f32 *)(st + 0x74) = 0.5f;
    *(f32 *)(st + 0x78) = 0.5f;
    *(f32 *)(st + 0x7C) = 1.0f;
    *(f32 *)(st + 0x80) = 0.7853982f;
    *(f32 *)(st + 0xA0) = 0.34906584f;
    *(f32 *)(st + 0x9C) = 0.00392f;
    func_L01_0045BD78(a0, 0.016f, 0.120000005f, 0.010053097f, 0.25132743f);
    st[0x58] = 0x14;
    st[0x5A] = 0xE;
    if (*(s16 *)(st + 0x34) == 0) {
        *(s16 *)(st + 0x34) = 0x14;
        *(f32 *)(st + 0x30) = 20.0f;
    }
    st[0x39] = 1;
    st[0x3E] = 1;
    st[0x64] = 0;
    st[0x3F] = 0;
    *(f32 *)(st + 0x40) = 2.0f;
    func_L01_004450F0(a0, 1, 0);
    if (*(s32 *)(st + 0x300) != -1 || *(s32 *)(st + 0x318) != -1) {
        func_L01_004450F0(a0, 0xC, 3);
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(a0 + 0x98) = 0;
        func_L01_004AA7E8(a0, 1);
    }
    if (*(s32 *)(st + 0x330) != 0) {
        func_L01_004450F0(a0, 0xC, 4);
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(a0 + 0x98) = 0;
        func_L01_004AA7E8(a0, 1);
    }
    h = *(u16 *)(a0 + 0xB2);
    if (D_L28_00234A80_00394320.arr[(s16)h] == 0) {
        v = D_001BBE90[((s16)h >> 1) + (D_001D545C << 10)];
        if ((((h & 1) ? v >> 4 : v) & 7) == 0) goto zero;
    }
    if (*(s32 *)(st + 0x300) != -1) {
        m = D_L28_001DEC9C;
        m += *(s32 *)(st + 0x300) << 8;
        func_L01_004443E8(m, 0, 3);
        func_003C2880(m);
    }
    if (*(s32 *)(st + 0x318) != -1) {
        m = D_L28_001DEC9C;
        m += *(s32 *)(st + 0x318) << 8;
        func_L01_004443E8(m, 0, 3);
        func_003C2880(m);
    }
    return 1;
zero:
    *(q_00394320 *)(st + 0x2E0) = *(q_00394320 *)(a0 + 0x10);
    *(s32 *)(st + 0x340) = 0;
    *(s32 *)(st + 0x344) = 0;
    return 0;
}
/* localdecomp:end func_L28_00394320 */

/* localdecomp:start func_L28_00394618 */
typedef struct { u8 pad[0x464]; u8 spent[1]; } S_00394618;
extern S_00394618 D_L28_00234A80;
extern u8 D_001BBE90[];
extern s32 D_001D545C;
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_L01_004443E8(u8 *, s32, s32);
void func_L28_00394618(void *self) {
    u8 *a0 = self;
    u8 *m;
    s32 id;
    s32 id2;
    s32 v;
    id = *(u16 *)(a0 + 0xB2);
    if (D_L28_00234A80.spent[(s16)id] == 0) {
        v = D_001BBE90[((s16)id >> 1) + (D_001D545C << 10)];
        if (id & 1)
            v = (v >> 4) & 7;
        else
            v = v & 7;
        if (v == 0) {
            m = func_003C24B0(0x8C4, 0x80);
            func_L01_00456160(m, a0);
            *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 0.5f;
            id2 = *(u16 *)(a0 + 0xB2);
            if (id2 & 1) {
                if (((D_001BBE90[((s16)id2 >> 1) + (D_001D545C << 10)] >> 4) & 7) != 7)
                    D_001BBE90[((s16)id2 >> 1) + (D_001D545C << 10)] += 0x10;
            } else {
                if ((D_001BBE90[((s16)id2 >> 1) + (D_001D545C << 10)] & 7) != 7)
                    D_001BBE90[((s16)id2 >> 1) + (D_001D545C << 10)] += 1;
            }
        }
    }
    func_L01_004443E8(a0, 0, 3);
}
/* localdecomp:end func_L28_00394618 */

/* localdecomp:start func_L28_00394768 */
extern void func_0038CAD0(void *);
extern void func_0038CB00(void *);
extern void func_L01_00451DF8(u8 *, void *, s32, s32, f32);

void func_L28_00394768(u8 *self) {
    u8 *v = *(u8 **)(self + 0x68);
    u16 value;

    func_0038CAD0(v + 0x32C);
    func_0038CB00(v + 0x33C);
    value = *(u16 *)(self + 0x96);
    if (value <= 0xFFFEu) {
        *(u16 *)(self + 0x96) = value + 1;
    }
    func_L01_00451DF8(self, v + 0x260, 3, 1, 2.5f);
}
/* localdecomp:end func_L28_00394768 */
