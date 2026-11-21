#include "common.h"

/* localdecomp:start func_L30_004BB918 */
#include "vu0.h"
typedef union {
    u8 b[0x2A00];
    s16 h[0x1500];
    s32 i[0xA80];
    f32 f[0xA80];
    u8 *ptr[0xA80];
} Hero_004BB918;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 *target;
    u32 flags;
    u8 kind;
    u8 pad29[3];
    f32 amount;
    u32 flags30;
    u8 pad34[4];
    u8 *moby;
    u8 pad3C[4];
} S_004BB918;
extern Hero_004BB918 D_001A4BE0;
extern s32 D_L30_001D6694;
__asm__(".extern D_L30_001D6694, 16");
extern S_004BB918 D_L30_001ED280[];
extern u8 D_00142660[];
extern s16 D_001426A0[];
extern vu0_v4 D_001A4C60;
extern vu0_v4 D_001A4CD0[];
extern s32 func_L01_0041A4F0(void);
extern f32 func_L01_004C93D8(void);
extern f32 func_L01_004C9360(f32);
extern f32 func_L01_004DFE88(s32);
extern void func_L01_004E1560(void);
extern void func_L01_005110E8(s32, s32, f32, f32, f32);
extern s32 func_L30_004CF4B0(s32, s32);
extern void *func_L01_00447490(void *, u32, s32);
extern void func_L01_004DFEA0(int);
extern s32 func_L01_003F1F20(s32, s32);
extern s32 func_L01_004F4E70(s32, s32);
extern void func_L01_004ED838(s32, s32, f32, f32);
extern void func_L01_00511618(s32, s32, f32);
extern void func_L01_0050FB40(s32, s32, f32);

s32 func_L30_004BB918(s32 a0) {
    vu0_v4 buf;
    S_004BB918 *e;
    u8 *p;
    s32 hit;
    s32 n;
    s32 snd;

    if (D_001A4BE0.i[0x25CC / 4] == 0x14 || D_001A4BE0.i[0x25CC / 4] == 7) {
        return 0;
    }
    if (D_001A4BE0.i[0x25C4 / 4] == 0x74) {
        return 0;
    }
    if (D_001A4BE0.i[0x25C4 / 4] == 0x31 || D_001A4BE0.h[0x1DC / 2] != 0 || D_L30_001D6694 != 0) {
        return 0;
    }
    D_001A4BE0.ptr[0x2808 / 4] = 0;
    if (D_001A4BE0.ptr[0x25C0 / 4][0xA8] == 0xFF) {
        return 0;
    }
    e = &D_L30_001ED280[D_001A4BE0.ptr[0x25C0 / 4][0xA8]];
    if (e->moby != D_001A4BE0.ptr[0x25C0 / 4]) {
        return 0;
    }
    if (!(e->flags & 9)) {
        return 0;
    }
    if (D_001A4BE0.i[0x234 / 4] != 0) {
        return 0;
    }
    if (e->amount != 0.0f && func_L01_0041A4F0() != 0 && D_001A4BE0.b[0x25E4] != 5) {
        D_00142660[0x5A] = 0;
        D_00142660[0x5B] = 0;
    }
    if (func_L01_004C93D8() != 0.0f && D_001A4BE0.b[0x25E4] == 0 && !(e->flags & 0x20000000)) {
        e->amount = func_L01_004C9360(e->amount);
        if (e->amount == 0.0f) {
            return 0;
        }
    }
    if ((e->flags & 0x20000000) && D_001A4BE0.b[0x25E4] == 0) {
        n = D_001426A0[0];
        if (n > 4) {
            n = 4;
        }
        if (n < 0) {
            n = 0;
        }
        e->amount = e->amount / func_L01_004DFE88(n);
    }
    D_001A4BE0.ptr[0x2808 / 4] = e->target;
    if (D_001A4BE0.i[0x25CC / 4] == 0xF) {
        D_001A4BE0.ptr[0x664 / 4] = (u8 *)e;
        D_001A4BE0.h[0x62E / 2] = 1;
        return 0;
    }
    if (D_001A4BE0.b[0x25E4] == 5 && D_001A4BE0.i[0x25CC / 4] == 6 && !(e->flags & 0x30000) &&
        D_001A4BE0.i[0x1B8 / 4] < 0x11) {
        return 0;
    }
    if (a0 != 0) {
        func_L01_004E1560();
        hit = 0;
        if (e->flags30 & 1) {
            buf = e->pos;
            if (e->pos.w == 5627.925f) {
                hit = 1;
            }
        } else if (e->target != 0) {
            vec_sub_ba(&buf, &D_001A4C60, e->target + 0x10);
        } else {
            func_L01_005110E8((s32)&buf, 0, -1.0f, 0.0f, 0.0f);
        }
        switch (D_001A4BE0.b[0x25E4]) {
        case 0:
            p = D_001A4BE0.ptr[0x2808 / 4];
            if (p != 0 && (*(s16 *)(p + 0xAA) == 0x4EB || *(s16 *)(p + 0xAA) == 0x558 ||
                           *(s16 *)(p + 0xAA) == 0x1C5F)) {
                func_L30_004CF4B0(0x82, 1);
                return 1;
            }
            if ((D_001A4BE0.i[0x25C4 / 4] == 1 || D_001A4BE0.i[0x25C4 / 4] == 0x1D ||
                 D_001A4BE0.i[0x16B0 / 4] == 2) && !(e->flags & 8)) {
                p = func_L01_00447490(D_001A4BE0.ptr[0x25C0 / 4], 1, 0);
                if (p != 0) {
                    func_L01_004DFEA0(*(f32 *)(p + 0x2C));
                }
                if (D_001A4BE0.i[0x2850 / 4] == 0) {
                    func_L30_004CF4B0(0x16, 1);
                } else {
                    func_L01_003F1F20(0x12, 0);
                }
                D_001A4BE0.h[0x1DC / 2] = 0x40;
                if (D_001A4BE0.h[0x21C / 2] == 0) {
                    D_001A4BE0.h[0x21C / 2] = 0xF;
                }
                func_L01_004F4E70(0x14, 0);
                return 0;
            }
            if (D_001A4BE0.i[0x25CC / 4] == 0x12) {
                func_L30_004CF4B0(0x77, 1);
            } else if (D_001A4BE0.i[0x25CC / 4] == 0x11) {
                func_L30_004CF4B0(0x78, 1);
            } else if (e->flags & 8) {
                func_L30_004CF4B0(0x91, 1);
            } else {
                func_L30_004CF4B0(0x16, 1);
            }
            if (D_001A4BE0.i[0x25C4 / 4] == 0x91) {
                qzero(&buf);
            } else {
                func_L01_004ED838((s32)&buf, hit, D_001A4BE0.b[0x1479] ? 0.0f : 0.06600001f, 0.034f);
                if (hit && e->kind == 4) {
                    func_L01_00511618((s32)&buf, (s32)&buf, 2.0f);
                }
            }
            break;
        case 1:
            func_L30_004CF4B0(0x42, 1);
            func_L01_004ED838((s32)&buf, hit, 0.060000002f, 0.060000002f);
            break;
        case 5:
            if (e->flags & 0x100000) {
                p = func_L01_00447490(D_001A4BE0.ptr[0x25C0 / 4], 0x100001, 0);
                if (p != 0) {
                    func_L01_004DFEA0(*(f32 *)(p + 0x2C));
                } else {
                    func_L01_004DFEA0(1);
                }
                D_001A4BE0.h[0x1DC / 2] = 100;
                if (D_001A4BE0.i[0x2850 / 4] > 0) {
                    func_L30_004CF4B0(0xAC, 1);
                } else {
                    func_L30_004CF4B0(0x9F, 0);
                    func_L01_0050FB40(0x28, 0x46, 6.0f);
                }
            } else {
                D_001A4BE0.h[0x1DC / 2] = 100;
                func_L30_004CF4B0(0x9E, 1);
                func_L01_004ED838((s32)&buf, hit, 0.040000003f, 0.020000001f);
            }
            func_L01_003F1F20(0x12, 0);
            break;
        case 3:
            func_L30_004CF4B0(0x55, 1);
            func_L01_004ED838((s32)&buf, hit, 0.10000001f, 0.048000004f);
            break;
        }
        vec_add_ab(&D_001A4CD0[0], &D_001A4CD0[0], &buf);
        vec_add_ab(&D_001A4CD0[2], &D_001A4CD0[2], &buf);
    } else {
        if (D_001A4BE0.h[0x1DC / 2] != 0) {
            return 1;
        }
        p = func_L01_00447490(D_001A4BE0.ptr[0x25C0 / 4], 1, 0);
        if (p != 0) {
            func_L01_004DFEA0(*(f32 *)(p + 0x2C));
        } else {
            func_L01_004DFEA0(1);
        }
        D_001A4BE0.h[0x1DC / 2] = 0x40;
    }
    return 1;
}
/* localdecomp:end func_L30_004BB918 */
