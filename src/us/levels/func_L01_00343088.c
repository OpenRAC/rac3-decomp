#include "common.h"

typedef int s128_00341C10 __attribute__((mode(TI)));
typedef union {
    s128_00341C10 q;
    f32 f[4];
} V_00341C10;
typedef struct {
    u8 a;
    u8 b;
    u8 pad[238];
} S_00341C10;
typedef struct {
    u8 pad0[16];
    u8 pos[20];
    s32 active;
    s32 visible;
    s32 target;
} Vars3462F0;
typedef struct {
    char pad0[0x20];
    unsigned char b32;
} Obj;
typedef struct { u8 pad[0x1A]; s16 x1A; } V_347888;
typedef struct { u8 pad[0x68]; V_347888 *x68; } O_347888;

typedef struct {
    u8 pad0[0x170];
    f32 f170;
    u8 pad1[0x109C];
    s32 f1210;
    u8 pad2[0x13B0];
    s32 f25C4;
    u8 pad3[0x25];
    u8 b25ED;
    u8 pad4[0x2CE];
    s32 f28BC;
} G_00346998;

extern u8 D_001A4BE0[];
extern void func_003BDA38(s32 a, s32 b, void *c);
/* localdecomp:start func_L01_00343088 */
extern u8 *D_001D52FC;
extern s32 D_L01_00278C30[];
extern void func_L01_004C3888(void *out, void *in, s32 a, s32 b, f32 c, f32 d, f32 e, f32 f);
extern s32 func_L01_004C3E68(f32 h, void *a, void *b, void *c, void *d, void *e, s32 f, s32 g);
extern s32 func_00388398(void *);
extern void func_0039FE80(s32, s32, void *);
extern s32 func_L01_0050D8F8(s32, s32);
extern s32 func_L01_0050DA08(s32);
extern void func_L01_004E6A08(s32);
extern void func_L01_004E6CB0(void);
extern void func_L01_0032F3D8(void *, void *, void *);
extern void func_L01_003432F8(u8 *);
extern void func_L01_004026A0_00343928(void (*)(u8 *), u8 *);

void func_L01_00343088(u8 *owner) {
    f32 origin[4];
    f32 target[4];
    u8 *context = *(u8 **)(owner + 0x68);
    s32 allowed;
    u8 *base;
    u8 *base2;

    func_003BDA38((s32)owner, 0, origin);
    func_L01_004C3888(target,origin, 0, 0, 1.5f, 11.0f, 0.25f, 0.0030555557f);
    allowed = 1;
    *(s32 *)(context + 0x24) = func_L01_004C3E68(0.0030555557f, origin, target, context, context + 0x10, owner, 0, 0);

    base = D_001A4BE0;
    if (*(s32 *)(base +0x25C4) == 29) {
        if (!func_00388398(base +0x28BC))
            allowed = 0;
    } else {
        *(s32 *)(base +0x28BC) = 40;
    }

    switch (owner[0x20]) {
    case 0:
        owner[0x20] = 1;
        *(s32 *)(context + 0x24) = 0;
        /* Fall through. */
    case 1:
        base2 = D_001A4BE0;
        if ((*(s32 *)(D_001D52FC + 0x1A4) & *(s32 *)(base2 + 0x1210)) && !base2[0x25ED] && allowed && D_L01_00278C30[0] < 6) {
            if (func_L01_0050D8F8(-1, 1)) {
                func_L01_004E6A08(-1);
                owner[0x20] = 2;
                *(s32 *)(context + 0x20) = 20;
            } else {
                func_0039FE80(2, 0, owner);
            }
        } else if (!(func_L01_0050DA08(-1) && D_L01_00278C30[0] < 7)) {
            u8 *base3 = D_001A4BE0;
            if (*(s32 *)(D_001D52FC + 0x1A4) & *(s32 *)(base3 + 0x1210)) {
                func_0039FE80(2, 0, owner);
            }
        }
        break;
    case 2:
        if (func_00388398(context + 0x20)) {
            func_0039FE80(0, 0, owner);
            func_L01_0032F3D8(owner, origin, target);
            func_L01_004E6CB0();
            owner[0x20] = 3;
            *(s32 *)(context + 0x20) = 10;
        }
        break;
    case 3:
        if (func_00388398(context + 0x20))
            owner[0x20] = 1;
        break;
    }
    func_L01_004026A0_00343928(func_L01_003432F8, owner);
}
/* localdecomp:end func_L01_00343088 */
