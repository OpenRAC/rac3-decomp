#include "common.h"

/* NTSC-U counterpart of func_003C3DC8 (boot_elf). */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { u8 p10[0x10]; u8 n; u8 f11; } T_3BE418;
typedef struct { u8 p0[0x48]; T_3BE418 *e[1]; } Q_3BE418;
typedef struct {
    u8 p0[0x24]; Q_3BE418 *f24; u8 p28[0x18];
    u8 f40; u8 f41; u8 f42; u8 f43; s32 f44; f32 f48; f32 f4C; u8 p50[8]; f32 *f58; u8 p5c[4]; u8 f60; u8 p61[0xB]; u8 f6C;
} S_3BE418;
extern void func_U_003C2C50();

/* localdecomp:start func_U_003C3CB0 */
/* the same code as frontbin's func_003C3A10 */
typedef struct {
    u8 p0[0x24]; Q_3BE418 *f24; u8 p28[0x18];
    u8 f40; u8 f41; u8 f42; u8 f43; f32 f44; f32 f48; f32 f4C; void *f50; void *f54; u8 p58[8]; u8 f60; u8 p61[0xB]; u8 f6C;
    u8 p6D[0x13]; u128_t f80; u8 p90[0x19]; u8 fA9;
} S_003C3DC8;
extern u128_t D_U_002DA180[];
extern void func_U_003C7110_003C3CB0(void *, s32, u16);
extern s32 func_U_003C2FD0();
extern void func_U_003C8D68();
void func_U_003C3CB0(S_003C3DC8 *p, s32 idx, s32 lim, s32 frames) {
    s32 r;
    if (lim >= p->f24->e[idx]->n) lim = p->f24->e[idx]->n - 1;
    if (frames <= 0) {
        func_U_003C3BD8((S_3BE418 *)p, idx, lim);
        return;
    }
    if (lim >= 1 && lim <= 11) func_U_003C7110_003C3CB0(p, idx, lim);
    if (p->f44 > 0.025f || p->f50 != 0 || p->f54 != 0) {
        r = func_U_003C2FD0(p);
        if (r >= 0) {
            func_U_003C8D68(p, r | 0x300);
            D_U_002DA180[r] = p->f80;
            if (p->f42 != 0xFF) p->fA9 = p->f42;
            p->f42 = 0xFF;
            p->f40 = r;
        }
    }
    p->f41 = lim;
    p->f43 = idx;
    func_U_003C2C50(p);
    p->f48 = 1.0f;
    p->f44 = 0.0f;
    p->f4C = 1.0f / (f32)frames;
    p->f60 &= 0xFD;
    p->f6C = p->f24->e[idx]->f11;
}
/* localdecomp:end func_U_003C3CB0 */
TEXT_PADDING(4);
