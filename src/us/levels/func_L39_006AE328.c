#include "common.h"

/* NTSC-U counterpart of func_L39_006B0C90 (src/levels/39_multiplayer_menu/L39_006B0C90.c) */
/* localdecomp:start func_L39_006AE328 */
typedef struct S_006B0C90_C {
    u8 b[0x21];
} S_006B0C90_C;
typedef struct S_006B0C90_G {
    u8 pad0[0x17C];
    s32 f17C;
    u8 f180;
    u8 f181;
    u8 pad182[0x1A2 - 0x182];
    S_006B0C90_C f1A2;
    u8 pad1C3[0x2C4 - 0x1C3];
    s32 f2C4;
    u8 f2C8;
} S_006B0C90_G;
extern S_006B0C90_G D_001A5E50;
extern S_006B0C90_C D_L39_00248F68;
extern s32 D_001A5FC4[];
extern u8 D_L39_00247B94;
__asm__(".extern D_L39_00247B94, 16");
extern f32 D_L39_00247B90;
__asm__(".extern D_L39_00247B90, 16");
extern s32 D_L39_00242A90;
__asm__(".extern D_L39_00242A90, 16");
extern u8 D_001DC304_sda;
extern u8 *D_L39_00247A74_006AE328;
__asm__(".extern D_L39_00247A74_006AE328, 16");
extern void func_L39_00686EC8(void);
extern void func_L39_005BD7D8(int, int, int, int, int);
extern void func_00139328(void *);
extern void func_0019D640(u32);
extern void func_L39_0059C740(s32, s32);
extern s32 func_L39_00685798(s32, s32, s32);
extern s32 func_L39_00688350(void *, s32);
void func_L39_00687728(void *, s32, s32, s32, f32, f32);

typedef struct S_006B0C90_VT {
    u8 pad[0x30];
    void (*getpos)(void *, f32 *, f32 *);
    u8 pad34[0xF0 - 0x34];
    void (*fF0)(void *);
} S_006B0C90_VT;

s32 func_L39_006AE328(u8 *this, s32 arg)
{
    u8 buf[8];
    f32 pos[2];
    u8 *p;
    u8 **items;
    s32 j;
    s32 sel;
    s32 st;
    S_006B0C90_C *c;
    s32 first;
    s32 last;
    s32 flags;

    if (D_L39_00247B94) {
        if (D_L39_00247B90 <= 0.0f) {
            sel = *(s32 *)(this + 0x290);
            if (sel == 0) {
                D_001A5FC4[0] = 0;
                (*(S_006B0C90_VT **)(this + 0x60))->fF0(this);
                func_L39_00686EC8();
                func_L39_005BD7D8(0xB, 2, 0, 0, 0);
            } else if (sel == 1) {
                D_001A5FC4[0] = sel;
                func_00139328(buf);
                func_0019D640(((buf[1] << 24) | (buf[2] << 16) | (buf[3] << 8) | buf[5]) ^ *(volatile u32 *)0x10000800);
                *(s32 *)(D_L39_00247A74_006AE328 + 0x284) = 0x15;
            } else if (sel == 2) {
                D_001A5FC4[0] = 1;
                *(s32 *)(D_L39_00247A74_006AE328 + 0x284) = 0;
            } else if (sel == 3) {
                func_L39_0059C740(0, 0);
            } else {
                D_001DC304_sda = 0;
            }
        }
        return 1;
    }
    if (arg == 5) {
        func_L39_00685798(0x17, 0, 0);
        return 1;
    }
    if (arg == 7) {
        func_L39_00685798(4, 0, 0);
        st = *(s32 *)(this + 0x290);
        if (st == 0) {
            c = &D_001A5E50.f1A2;
            *c = D_L39_00248F68;
            D_001A5E50.f2C4 = 0x275B;
            D_001A5E50.f17C = 0;
            D_001A5E50.f181 = 0;
            D_001A5E50.f180 = 1;
            D_001A5E50.f2C8 = 1;
            D_L39_00242A90 = -2;
            D_L39_00247B94 = 1;
            return 1;
        }
        if (st == 1) {
            D_001DC304_sda = 1;
            return 1;
        }
        if (st == 2) {
            D_001DC304_sda = 1;
            return 1;
        }
        if (st == 3) {
            D_001DC304_sda = 1;
            return 1;
        }
    }
    if (func_L39_00688350(this, arg)) {
        return 1;
    }
    sel = *(s32 *)(this + 0x290);
    if (sel == -1) {
        return 0;
    }
    items = (u8 **)(this + 0x110);
    p = *(u8 **)((u8 *)items + (sel << 2));
    (*(S_006B0C90_VT **)(p + 0x60))->getpos(p, &pos[0], &pos[1]);
    first = -1;
    last = -1;
    for (j = 0; j < 4; j++) {
        if (*(s32 *)(items[j] + 4) == 3) {
            if (first == -1) {
                first = j;
            }
            last = j;
        } else if (*(s32 *)(items[j] + 4) == 4) {
            if (first == -1) {
                first = j;
            }
            last = j;
        } else if (*(s32 *)(items[j] + 4) == 5) {
            if (first == -1) {
                first = j;
            }
            last = j;
        }
    }
    flags = *(s32 *)(this + 0x290) != first;
    if (*(s32 *)(this + 0x290) != last) {
        flags |= 2;
    }
    func_L39_00687728(this, flags, 3, 3, pos[0], pos[1]);
    return 0;
}
/* localdecomp:end func_L39_006AE328 */
