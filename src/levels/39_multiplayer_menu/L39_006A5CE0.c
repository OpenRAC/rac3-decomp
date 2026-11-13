#include "common.h"

/* localdecomp:start func_L39_006A5CE0 */
typedef struct S_006A5CE0_P {
    u8 pad[0xE0];
    s16 id[8];
    s16 state[8];
} S_006A5CE0_P;
extern S_006A5CE0_P *D_L39_00241640;
extern u8 *D_L39_00247914;
typedef struct S_006A5CE0_G {
    s32 f0;
    s32 f4;
    s32 f8;
} S_006A5CE0_G;
extern S_006A5CE0_G D_001A5CD0;
extern void func_L39_006A5F30(void *);
extern void func_L39_006A65B8(void *);
extern void func_L39_006A6778(void *);
extern void func_L39_006A6470(void *);
extern void func_L39_006A5FE0(void *);
extern void func_L39_006A6108(void *);
extern void func_L39_006A6078(void *);
extern void func_L39_006A61A0(void *);
extern s32 func_L39_0068AEF8(void *, s32);
void func_L39_0068A2D0(void *, s32, s32, s32, f32, f32);

typedef struct S_006A5CE0_VT {
    u8 pad[0x30];
    void (*getpos)(void *, f32 *, f32 *);
} S_006A5CE0_VT;

s32 func_L39_006A5CE0(u8 *this, s32 arg)
{
    u8 *p;
    s32 i;
    s32 j;
    s32 idx;
    s32 sel;
    s32 first;
    s32 last;
    s32 flags;
    u8 **items;
    f32 pos[2];
    f32 y;

    func_L39_006A5F30(this);
    idx = -1;
    for (i = 0; i < 8; i++) {
        if (D_L39_00241640->id[i] == D_001A5CD0.f8) {
            idx = i;
            break;
        }
    }
    if (D_L39_00241640 != 0 && idx >= 0 && D_L39_00241640->state[idx] == 5) {
        *(s32 *)(D_L39_00247914 + 0x284) = 0x2C;
        return 1;
    }
    func_L39_006A65B8(this);
    func_L39_006A6778(this);
    func_L39_006A6470(this);
    if (arg == 7) {
        switch (*(u32 *)(this + 0x290)) {
        case 0:
            func_L39_006A5FE0(this);
            return 1;
        case 1:
            func_L39_006A6108(this);
            return 1;
        case 2:
            func_L39_006A6078(this);
            return 1;
        case 3:
            func_L39_006A61A0(this);
            return 1;
        case 4:
            *(s32 *)(D_L39_00247914 + 0x284) = 0x2C;
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
    (*(S_006A5CE0_VT **)(p + 0x60))->getpos(p, &pos[0], &pos[1]);
    first = -1;
    last = -1;
    for (j = 0; j < 5; j++) {
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
    y = pos[1];
    func_L39_0068A2D0(this, flags, 3, 3, pos[0], y);
    return 0;
}
/* localdecomp:end func_L39_006A5CE0 */
