#include "common.h"

/* NTSC-U counterpart of func_003C3A10. Uses the same transition as boot_elf's func_U_003C3CB0. */
/* localdecomp:start func_U_003BE4F0 */
typedef int u128_003BE4F0 __attribute__((mode(TI)));

typedef struct {
    u8 pad[0x10];
    u8 n;
    u8 f11;
} T_003BE4F0;

typedef struct {
    u8 pad[0x48];
    T_003BE4F0 *e[1];
} Q_003BE4F0;

typedef struct {
    u8 p0[0x24];
    Q_003BE4F0 *f24;
    u8 p28[0x18];
    u8 f40;
    u8 f41;
    u8 f42;
    u8 f43;
    f32 f44;
    f32 f48;
    f32 f4C;
    void *f50;
    void *f54;
    u8 p58[8];
    u8 f60;
    u8 p61[0xB];
    u8 f6C;
    u8 p6D[0x13];
    u128_003BE4F0 f80;
    u8 p90[0x19];
    u8 fA9;
} S_003BE4F0;

extern u128_003BE4F0 D_U_002D6180[];
extern void func_U_003BE418(void *, s32, s32);
extern void func_U_003C1950(void *, s32, u16);
extern s32 func_U_003BD810(void *);
extern void func_U_003C35A8(void *, s32);
extern void func_U_003BD490(void *);

void func_U_003BE4F0(S_003BE4F0 *p, s32 idx, s32 lim, s32 frames) {
    s32 r;
    if (lim >= p->f24->e[idx]->n) lim = p->f24->e[idx]->n - 1;
    if (frames <= 0) {
        func_U_003BE418(p, idx, lim);
        return;
    }
    if (lim >= 1 && lim <= 11) func_U_003C1950(p, idx, lim);
    if (p->f44 > 0.025f || p->f50 != 0 || p->f54 != 0) {
        r = func_U_003BD810(p);
        if (r >= 0) {
            func_U_003C35A8(p, r | 0x300);
            D_U_002D6180[r] = p->f80;
            if (p->f42 != 0xFF) p->fA9 = p->f42;
            p->f42 = 0xFF;
            p->f40 = r;
        }
    }
    p->f41 = lim;
    p->f43 = idx;
    func_U_003BD490(p);
    p->f48 = 1.0f;
    p->f44 = 0.0f;
    p->f4C = 1.0f / (f32)frames;
    p->f60 &= 0xFD;
    p->f6C = p->f24->e[idx]->f11;
}
/* localdecomp:end func_U_003BE4F0 */
