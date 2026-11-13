#include "common.h"

/* localdecomp:start func_L39_00689F00 */
extern s32 D_003D2880[];
extern u8 D_001DC30A_sda;
extern f32 D_001DC370_sda;
extern f32 D_001DC374_sda;
extern f32 D_001DC378_sda;
extern f32 D_001DC37C_sda;
extern void func_L01_00516AA0(s32, s32, s32);
s32 func_L01_00516C78(s32, s32, s32);
s32 func_L01_005170B8(s32, s32);
s32 func_L01_00516470(s32, f32, f32);
s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L01_005169C8(s32, f32);
extern s32 func_0038DBD8(s32, s32, f32);

typedef struct {
    u8 pad0[0x78];
    s32 f78;
    s32 f7C;
    s32 f80;
    u8 pad84[0x29C - 0x84];
    u8 f29C;
    u8 pad29D[3];
    f32 f2A0;
} S_00689F00;

void func_L39_00689F00(S_00689F00 *self, s32 a1, s32 a2, s32 a3, f32 x, f32 y, f32 sx, f32 sy, f32 h) {
    f32 t;

    self->f2A0 = h;
    if (D_001DC30A_sda == 0) {
        return;
    }
    if (self->f29C) {
        s32 c;

        func_L01_00516AA0(self->f78, 1, 1);
        func_L01_00516AA0(self->f7C, 1, 0);
        func_L01_00516AA0(self->f80, 1, 0);
        func_L01_00516470(self->f78, x, y);
        func_L01_00517538(self->f78, sx, sy);
        func_L01_00516470(self->f7C, x + D_001DC370_sda, y - self->f2A0 + D_001DC374_sda);
        func_L01_00516470(self->f80, x + D_001DC370_sda, y + self->f2A0 + D_001DC374_sda);
        func_L01_00517538(self->f7C, 0.5f, 0.5f);
        func_L01_00517538(self->f80, 0.5f, -0.5f);
        t = (sx + D_001DC37C_sda) * D_001DC378_sda;
        if (t > 1.0f) {
            t = 1.0f;
        } else if (t < 0.0f) {
            t = 0.0f;
        }
        func_L01_005169C8(self->f7C, t);
        func_L01_005169C8(self->f80, t);
        c = func_0038DBD8(0x332299DE, 0x2299DE, 0.5f);
        func_L01_005170B8(self->f7C, c);
        func_L01_005170B8(self->f78, 0x332299DE);
        func_L01_005170B8(self->f80, c);
        func_L01_00516C78(self->f78, a2, a3);
        func_L01_00516C78(self->f7C, a2, a3);
        func_L01_00516C78(self->f80, a2, a3);
    } else {
        s32 c;

        func_L01_00516AA0(D_003D2880[0x14], 1, 1);
        func_L01_00516AA0(D_003D2880[0x15], 1, 0);
        func_L01_00516AA0(D_003D2880[0x16], 1, 0);
        func_L01_00516470(D_003D2880[0x14], x, y);
        func_L01_00517538(D_003D2880[0x14], sx, sy);
        func_L01_00516470(D_003D2880[0x15], x + D_001DC370_sda, y - self->f2A0 + D_001DC374_sda);
        func_L01_00516470(D_003D2880[0x16], x + D_001DC370_sda, y + self->f2A0 + D_001DC374_sda);
        func_L01_00517538(D_003D2880[0x15], 0.5f, 0.5f);
        func_L01_00517538(D_003D2880[0x16], 0.5f, -0.5f);
        t = (sx + D_001DC37C_sda) * D_001DC378_sda;
        if (t > 1.0f) {
            t = 1.0f;
        } else if (t < 0.0f) {
            t = 0.0f;
        }
        func_L01_005169C8(D_003D2880[0x15], t);
        func_L01_005169C8(D_003D2880[0x16], t);
        c = func_0038DBD8(0x332299DE, 0x2299DE, 0.5f);
        func_L01_005170B8(D_003D2880[0x15], c);
        func_L01_005170B8(D_003D2880[0x14], 0x332299DE);
        func_L01_005170B8(D_003D2880[0x16], c);
        func_L01_00516C78(D_003D2880[0x14], a2, a3);
        func_L01_00516C78(D_003D2880[0x15], a2, a3);
        func_L01_00516C78(D_003D2880[0x16], a2, a3);
    }
}
/* localdecomp:end func_L39_00689F00 */

/* localdecomp:start func_L39_0068A2D0 */
extern s32 D_003D2880[];
extern u8 D_001DC30A_sda;
extern f32 D_001DC370_sda;
extern f32 D_001DC374_sda;
extern void func_L01_00516AA0(s32, s32, s32);
s32 func_L01_00516C78(s32, s32, s32);
s32 func_L01_00516470(s32, f32, f32);

typedef struct {
    u8 pad0[0x78];
    s32 f78;
    s32 f7C;
    s32 f80;
    u8 pad84[0x29C - 0x84];
    u8 f29C;
    u8 pad29D[3];
    f32 f2A0;
} S_0068A2D0;

void func_L39_0068A2D0(S_0068A2D0 *self, s32 a1, s32 a2, s32 a3, f32 x, f32 y) {
    if (D_001DC30A_sda == 0) {
        return;
    }
    if (self->f29C) {
        func_L01_00516AA0(self->f78, 1, 1);
        func_L01_00516AA0(self->f7C, 1, 0);
        func_L01_00516AA0(self->f80, 1, 0);
        func_L01_00516C78(self->f78, a2, a3);
        func_L01_00516C78(self->f7C, a2, a3);
        func_L01_00516C78(self->f80, a2, a3);
        func_L01_00516470(self->f78, x, y);
        func_L01_00516470(self->f7C, x + D_001DC370_sda, y - self->f2A0 + D_001DC374_sda);
        func_L01_00516470(self->f80, x + D_001DC370_sda, y + self->f2A0 + D_001DC374_sda);
    } else {
        func_L01_00516AA0(D_003D2880[0x14], 1, 1);
        func_L01_00516AA0(D_003D2880[0x15], 1, 0);
        func_L01_00516AA0(D_003D2880[0x16], 1, 0);
        func_L01_00516C78(D_003D2880[0x14], a2, a3);
        func_L01_00516C78(D_003D2880[0x15], a2, a3);
        func_L01_00516C78(D_003D2880[0x16], a2, a3);
        func_L01_00516470(D_003D2880[0x14], x, y);
        func_L01_00516470(D_003D2880[0x15], x + D_001DC370_sda, y - self->f2A0 + D_001DC374_sda);
        func_L01_00516470(D_003D2880[0x16], x + D_001DC370_sda, y + self->f2A0 + D_001DC374_sda);
    }
}
/* localdecomp:end func_L39_0068A2D0 */

INCLUDE_ASM("asm/levels", func_L39_0068A4A8);

/* localdecomp:start func_L39_0068A6D0 */
extern s32 D_003D2880[];
extern f32 D_001DC314_sda;
extern f32 D_001DC318_sda;
extern void func_L01_00516AA0(s32, s32, s32);
s32 func_L01_005170B8(s32, s32);
s32 func_L01_00516470(s32, f32, f32);
s32 func_L01_00517538(s32, f32, f32);
s32 func_L01_00516640(s32, f32, f32);

void func_L39_0068A6D0(u8 *arg0, s32 idx, s32 arg2, f32 x, f32 y, f32 sx, f32 sy) {
    s32 p;

    if (idx > 7) {
        idx = 7;
    } else if (idx < 0) {
        idx = 0;
    }
    p = D_003D2880[idx + 0x62];
    if (arg0[0x29C]) {
        p = *(s32 *)(arg0 + 0xFC);
    }
    func_L01_00516AA0(p, 1, 1);
    func_L01_005170B8(p, arg2);
    func_L01_00516470(p, x, y);
    func_L01_00517538(p, sx, sy);
    func_L01_00516640(p, D_001DC314_sda, D_001DC318_sda);
}
/* localdecomp:end func_L39_0068A6D0 */

/* localdecomp:start func_L39_0068A7B8 */
extern s32 D_003D2880[];
extern f32 D_001DC31C_sda;
extern void func_L01_00516AA0(s32, s32, s32);
s32 func_L01_005170B8(s32, s32);
s32 func_L01_00516470(s32, f32, f32);
s32 func_L01_00517538(s32, f32, f32);

typedef struct {
    u8 pad0[0x100];
    s32 f100[2];
    u8 pad108[0x29C - 0x108];
    u8 f29C;
} S_0068A7B8;

void func_L39_0068A7B8(S_0068A7B8 *self, s32 idx, s32 arg2, f32 x, f32 y, f32 dy, f32 sx) {
    s32 i;
    s32 p;
    s32 base;

    if (idx >= 4) {
        idx = 3;
    } else if (idx < 0) {
        idx = 0;
    }
    base = 0x6A + idx * 2;
    for (i = 0; i < 2; i++) {
        if (self->f29C) {
            p = self->f100[i];
        } else {
            p = D_003D2880[base + i];
        }
        if (arg2 == 0) {
            func_L01_00516AA0(p, 1, 0);
        } else {
            func_L01_00516AA0(p, 1, 1);
            func_L01_005170B8(p, arg2);
            func_L01_00516470(p, x, y);
            func_L01_00517538(p, sx, D_001DC31C_sda);
            y += dy;
        }
    }
}
/* localdecomp:end func_L39_0068A7B8 */
