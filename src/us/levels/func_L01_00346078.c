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
extern u8 *D_001D52FC;
extern void func_L01_004C3888(void *out, void *in, s32 a, s32 b, f32 c, f32 d, f32 e, f32 f);
extern s32 func_L01_004C3E68(f32 h, void *a, void *b, void *c, void *d, void *e, s32 f, s32 g);
extern s32 func_00388398(void *);
extern void func_0039FE80(s32, s32, void *);
extern s32 func_L01_0050D8F8(s32, s32);
extern s32 func_L01_0050DA08(s32);
extern void func_L01_004E6A08(s32);
extern void func_L01_004E6CB0(void);
extern void func_003BDA38(s32 a, s32 b, void *c);
/* localdecomp:start func_L01_00346078 */
extern u8 D_001A4BE0[];
extern u8 *D_001D52FC;
extern void func_L01_004C3888(void *a, void *b, s32 i, s32 j, f32 f0, f32 f1, f32 f2, f32 f3);
extern s32 func_00388398(void *p);
extern s32 func_L01_0050D8F8(s32 i, s32 n);
extern s32 func_L01_0050DA08(s32 i);
extern void func_L01_004E6A08(s32 i);
extern void func_L01_004E6CB0(void);
extern void func_0039FE80(s32, s32, void *);
extern u8 *func_L01_0032C320(void *a, void *b);
extern void func_L01_003462F0(u8 *self);
extern void func_L01_004026A0_00346998(void *, u8 *);

/* miniturret_update: steps the miniturret: finds its muzzle point, runs the aiming and target
 * check, and in state 1 waits for the player's fire button, spending ammo; in state 2 it fires a
 * shot and plays a sound, in state 3 it cools down for 10 frames. */
void func_L01_00346078(u8 *self) {
    u8 a[16];
    u8 b[16];
    u8 *st = *(u8 **)(self + 0x68);
    s32 ready;
    u8 *shot;

    func_003BDA38((s32)self, 0, a);
    func_L01_004C3888(b, a, 0, 0, 1.5f, 11.0f, 0.25f, 0.0030555557f);
    *(s32 *)(st + 0x24) = func_L01_004C3E68(0.0030555557f, a, b, st, st + 0x10, self, 0, (s32)(st + 0x2C));
    ready = 1;
    if ((*(G_00346998 *)&D_001A4BE0).f25C4 == 29) {
        if (!func_00388398(&(*(G_00346998 *)&D_001A4BE0).f28BC)) ready = 0;
    } else {
        (*(G_00346998 *)&D_001A4BE0).f28BC = 40;
    }
    switch (self[0x20]) {
    case 0:
        self[0x20] = 1;
        *(s32 *)(st + 0x28) = 1;
        *(s32 *)(st + 0x24) = 0;
    case 1:
        if ((*(s32 *)(D_001D52FC + 0x1A4) & (*(G_00346998 *)&D_001A4BE0).f1210) &&
            !(*(G_00346998 *)&D_001A4BE0).b25ED && ready && *(s32 *)(st + 0x28) != 0) {
            if (func_L01_0050D8F8(-1, 1)) {
                func_L01_004E6A08(-1);
                self[0x20] = 2;
                *(s32 *)(st + 0x20) = 20;
            } else {
                func_0039FE80(2, 0, self);
            }
        } else if (!func_L01_0050DA08(-1) &&
                   (*(s32 *)(D_001D52FC + 0x1A4) & (*(G_00346998 *)&D_001A4BE0).f1210)) {
            func_0039FE80(2, 0, self);
        }
        break;
    case 2:
        if (func_00388398(st + 0x20) || (*(G_00346998 *)&D_001A4BE0).f170 > 0.0f) {
            func_0039FE80(0, 0, self);
            shot = func_L01_0032C320(a, b);
            *(u8 **)(shot + 0xB8) = self;
            func_L01_004E6CB0();
            self[0x20] = 3;
            *(s32 *)(st + 0x20) = 10;
        }
        break;
    case 3:
        if (func_00388398(st + 0x20)) self[0x20] = 1;
        break;
    }
    func_L01_004026A0_00346998(func_L01_003462F0, self);
}
/* localdecomp:end func_L01_00346078 */
