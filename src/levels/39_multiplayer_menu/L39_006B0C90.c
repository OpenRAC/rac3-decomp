#include "common.h"

/* localdecomp:start func_L39_006B0C90 */
typedef struct S_006B0C90_C {
    u8 b[0x1E];
} __attribute__((aligned(2))) S_006B0C90_C;
typedef struct S_006B0C90_G {
    u8 pad0[0x17C];
    s32 f17C;
    u8 f180;
    u8 f181;
    u8 pad182[0x1A2 - 0x182];
    S_006B0C90_C f1A2;
    u8 pad1C0[0x2C4 - 0x1C0];
    s32 f2C4;
    u8 f2C8;
} S_006B0C90_G;
extern S_006B0C90_G D_001A5CD0;
extern S_006B0C90_C D_L39_00248E20;
extern s32 D_001A5E44[];
extern u8 D_L39_00247A34;
__asm__(".extern D_L39_00247A34, 16");
extern f32 D_L39_00247A30;
__asm__(".extern D_L39_00247A30, 16");
extern s32 D_L39_00242910;
__asm__(".extern D_L39_00242910, 16");
extern u8 D_001DC324_sda;
extern u8 *D_L39_00247914;
__asm__(".extern D_L39_00247914, 16");
extern void func_L39_00689A70(void);
extern void func_L39_005BF798(int, int, int, int, int);
extern void func_00139328(void *);
extern void func_0019D500(u32);
extern void func_L39_0059DAD0(s32, s32);
extern s32 func_L39_00688340(s32, s32, s32);
extern s32 func_L39_0068AEF8(void *, s32);
void func_L39_0068A2D0(void *, s32, s32, s32, f32, f32);

typedef struct S_006B0C90_VT {
    u8 pad[0x30];
    void (*getpos)(void *, f32 *, f32 *);
    u8 pad34[0xF0 - 0x34];
    void (*fF0)(void *);
} S_006B0C90_VT;

s32 func_L39_006B0C90(u8 *this, s32 arg)
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

    if (D_L39_00247A34) {
        if (D_L39_00247A30 <= 0.0f) {
            sel = *(s32 *)(this + 0x290);
            if (sel == 0) {
                D_001A5E44[0] = 0;
                (*(S_006B0C90_VT **)(this + 0x60))->fF0(this);
                func_L39_00689A70();
                func_L39_005BF798(0xB, 2, 0, 0, 0);
            } else if (sel == 1) {
                D_001A5E44[0] = sel;
                func_00139328(buf);
                func_0019D500(((buf[1] << 24) | (buf[2] << 16) | (buf[3] << 8) | buf[5]) ^ *(volatile u32 *)0x10000800);
                *(s32 *)(D_L39_00247914 + 0x284) = 0x15;
            } else if (sel == 2) {
                D_001A5E44[0] = 1;
                *(s32 *)(D_L39_00247914 + 0x284) = 0;
            } else if (sel == 3) {
                func_L39_0059DAD0(0, 0);
            } else {
                D_001DC324_sda = 0;
            }
        }
        return 1;
    }
    if (arg == 5) {
        func_L39_00688340(0x17, 0, 0);
        return 1;
    }
    if (arg == 7) {
        func_L39_00688340(4, 0, 0);
        st = *(s32 *)(this + 0x290);
        if (st == 0) {
            c = &D_001A5CD0.f1A2;
            *c = D_L39_00248E20;
            D_001A5CD0.f2C4 = 0x275B;
            D_001A5CD0.f17C = 0;
            D_001A5CD0.f181 = 0;
            D_001A5CD0.f180 = 1;
            D_001A5CD0.f2C8 = 1;
            D_L39_00242910 = -2;
            D_L39_00247A34 = 1;
            return 1;
        }
        if (st == 1) {
            D_001DC324_sda = 1;
            return 1;
        }
        if (st == 2) {
            D_001DC324_sda = 1;
            return 1;
        }
        if (st == 3) {
            D_001DC324_sda = 1;
            return 1;
        }
    }
    if (func_L39_0068AEF8(this, arg)) {
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
    func_L39_0068A2D0(this, flags, 3, 3, pos[0], pos[1]);
    return 0;
}
/* localdecomp:end func_L39_006B0C90 */
