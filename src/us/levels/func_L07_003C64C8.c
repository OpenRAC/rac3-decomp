#include "common.h"

/* localdecomp:start func_L07_003C64C8 */
typedef int Q_003C64C8 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x10];
    u8 f10;
    u8 pad11[0x30 - 0x11];
    f32 f30;
    f32 f34;
    u8 pad38[4];
    f32 f3C;
    u8 pad40[8];
    u8 f48;
    u8 pad49[0x58 - 0x49];
    f32 f58;
    f32 f5C;
    u8 pad60[0x77 - 0x60];
    u8 f77;
    u8 pad78[0xB0 - 0x78];
    f32 fB0;
} Move_003C64C8;

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    u8 pad14[0x2C - 0x14];
    f32 f2C;
    f32 f30;
    f32 f34;
    u8 pad38[0xEC - 0x38];
    s32 fEC;
} Tune_003C64C8;

void func_L07_003C64C8(void *object) {
    extern void func_L01_00442E08(void *, s32);
    extern s32 func_L07_003C01A8(void);
    extern f32 func_L07_003C01F0(s32);
    extern void func_L01_00442F20(void *, s32, s32);
    extern void func_L01_00458A70(void *, f32, f32, f32, f32);
    extern void func_L07_003C6D10(char *);
    u8 *obj = object;
    u8 *state = *(u8 **)(obj + 0x68);
    u8 *stats;
    Move_003C64C8 *move;
    Tune_003C64C8 *tune;
    s32 kind;
    f32 scale;
    f32 half;
    func_L01_00442E08(obj, 0x19BD);
    stats = state + 0x30;
    kind = func_L07_003C01A8();
    scale = func_L07_003C01F0(kind);
    *(s16 *)(stats + 4) = (s32)(*(s16 *)(state + 0x34) * scale);
    *(f32 *)(state + 0x30) = *(s16 *)(stats + 4);
    stats[0x14] = (s32)(state[0x44] * scale);
    stats[0x15] = (s32)(state[0x45] * scale);
    stats[0x16] = (s32)(state[0x46] * scale);
    if (kind == 1 || kind == 3) {
        func_L01_00442F20(obj, 0x1D8A, 0x19BD);
    }
    stats[0x28] = 20;
    stats[0x2A] = 14;
    *(f32 *)(stats + 0x10) = 1.0f;
    stats[0xF] = 0;
    stats[9] = 0;
    move = (Move_003C64C8 *)(state + 0x70);
    move->f3C = 0.15f;
    move->f30 = 1.0f;
    move->fB0 = 1.0f;
    half = 0.5f;
    move->f58 = 0.35f;
    move->f48 = 255;
    move->f10 = 8;
    move->f34 = half;
    move->f5C = half;
    move->f77 = 1;
    tune = (Tune_003C64C8 *)(state + 0x150);
    tune->f0 = 0.6f;
    tune->f4 = 0.3f;
    tune->fEC = 0;
    tune->fC = tune->f8 = half;
    tune->f10 = 1.5707963705062866f;
    tune->f30 = 0.24434609711170197f;
    tune->f2C = 0.163333341f;
    tune->f34 = 0.2f;
    *(Q_003C64C8 *)(state + 0x440) = *(Q_003C64C8 *)(obj + 0x10);
    *(Q_003C64C8 *)(state + 0x450) = *(Q_003C64C8 *)(obj + 0xF0);
    func_L01_00458A70(obj, 0.00166666671f, 0.100000009f, 0.00349065871f, 0.104719765f);
    func_L07_003C6D10((char *)obj);
}
/* localdecomp:end func_L07_003C64C8 */
