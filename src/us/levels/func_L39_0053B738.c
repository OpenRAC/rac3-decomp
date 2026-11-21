#include "common.h"

/* NTSC-U counterpart of func_L39_0053BED0 (src/levels/shared/L39_0053BA68.c): 500 -> 600; 6 -> 7 */
extern u8 *D_L39_0024CF20[8] __attribute__((section(".sdata")));
extern u8 *D_L39_0024CF20[8] __attribute__((section(".sdata")));
#include "vu0.h"
extern f32 func_L01_0040C018(void *, void *);

/* localdecomp:start func_L39_0053B738 */
typedef struct O_53BED0 O_53BED0;
typedef struct {
    u8 pad0[16];
    u8 *(*fn)(O_53BED0 *);
} V_53BED0;
struct O_53BED0 {
    u8 pad0[20];
    V_53BED0 *vt;
};
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    s32 w0C;
    u32 type;
    s32 w14;
    u32 key;
} Ev_53BED0;
typedef struct {
    u8 pad0[0x40];
    s32 w40;
    u8 pad44[4];
    s32 w48;
    u8 pad4C[4];
    s32 w50;
} X_53BED0;
extern u8 *D_L39_0024CF20[8] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024CF20, 32");
extern f32 func_003887C8(void *, void *);
extern f32 func_L01_0040C018(void *, void *);
extern O_53BED0 *func_L39_0061AA60(s32);
extern s32 func_L39_005F0CE0(s32, s32, u8 *);
extern void func_L39_00644110(u8 *, s32);
extern u8 *func_L39_0053B6B8(s32, s32);

/* sets x up for target o: state, timer and the flag at 0x52; clears 0x40 */
static __inline__ void start_0053BED0(u8 *x, u8 *o, s32 timer, s16 n, s32 state) {
    *(u8 **)(x + 0x54) = o;
    *(s32 *)(x + 0x48) = state;
    *(s32 *)(x + 0x58) = timer;
    *(s16 *)(x + 0x52) = n;
    *(s32 *)(x + 0x40) = 0;
}

void func_L39_0053B738(Ev_53BED0 *ev) {
    s32 idx;
    s32 id;
    u8 *m;
    u8 *x;
    u8 *o;
    O_53BED0 *ob;
    idx = ev->key >> 16;
    id = ev->key & 0xFFFF;
    m = func_L39_0053B6B8(idx, id);
    if (m == 0) {
        if (ev->type == 0x40 && D_L39_0024CF20[idx] != 0) {
            func_L39_00644110(D_L39_0024CF20[idx], id);
        }
        return;
    }
    x = *(u8 **)(m + 0x68);
    switch (ev->type) {
    case 0x10:
        if (ev->w14 == 0) {
            m[0xBC] = 1;
        } else {
            *(s32 *)(x + 0x5C) = -1;
        }
        m[0x30] = 0xFF;
        break;
    case 0x20:
        if (*(s32 *)(x + 0x30) == 0 || *(s32 *)(x + 0x30) >= ev->w0C) {
            *(s32 *)(x + 0x30) = ev->w0C;
            ob = func_L39_0061AA60(ev->w14);
            o = ob->vt->fn(ob);
            if (o != 0 && o[0x20] != 0xFE && o[0x20] != 0xFD) {
                if (!(func_003887C8(m + 0x10, o + 0x10) > 20.0f)) {
                    if (m[0x20] & 0x10) {
                        *(u8 **)(x + 0x54) = o;
                        *(s32 *)(x + 0x58) = 600;
                    } else {
                        m[0x20] |= 0x10;
                        func_L39_005F0CE0(0, 0, m);
                        start_0053BED0(x, o, 600, 1, 7);
                    }
                }
            }
        }
        break;
    case 0x40: {
        f32 v[4];
        v[0] = ev->x;
        v[1] = ev->y;
        v[2] = ev->z;
        v[3] = 0;
        if (func_L01_0040C018(m + 0x10, v) > 15.0f) {
            m[0xBC] = 1;
            m[0x30] = 0xFF;
            if (D_L39_0024CF20[idx] != 0) {
                func_L39_00644110(D_L39_0024CF20[idx], id);
            }
        }
        break;
    }
    }
}
/* localdecomp:end func_L39_0053B738 */
