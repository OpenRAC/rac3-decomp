#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[6];
    s16 h6;
} S_4DBFE8_Ent;
typedef struct {
    u8 pad0[0x10];
    u8 b10;
    u8 pad11[2];
    u8 b13;
    u8 pad14[8];
    S_4DBFE8_Ent *entries[1];
} S_4DBFE8_Hdr;
typedef struct {
    u8 pad0[8];
    u8 b8;
    u8 pad9[0x3F];
    S_4DBFE8_Hdr *hdrs[1];
} S_4DBFE8_Tbl;
typedef struct {
    u8 pad0[0x24];
    S_4DBFE8_Tbl *tbl;
} S_4DBFE8_Obj;
typedef struct { u8 pad[0xB0]; } S_4DC790;
typedef struct {
    u8 pad0[4688];
    s32 f1250;
    u8 pad1254[36];
    s32 f1278;
    u8 pad127C[4932];
    s32 f25C0;
} G_4DD4B0;
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad[8944];
    u128_t q[8];
    s32 i[8];
    f32 a[8];
    f32 b[8];
    s16 count;
} S_4DF808;
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[128];
    s128 v128;
    s128 v144;
    u8 pad160[336];
    s16 h496;
    u8 pad498[126];
    f32 f624;
    f32 f628;
    u8 pad632[12];
    f32 f644;
    u8 pad648[9016];
    u8 *obj;
    u8 pad9668[8];
    s32 w9676;
} S_001A4BE0;
typedef struct {
    u8 p0[0x10];
    u128_t q10;
    u8 p20[0x98 - 0x20];
    s32 f98;
    u8 p9C[0xA8 - 0x9C];
    u8 bA8;
    u8 pA9[0xC0 - 0xA9];
    u8 fC0[0x30];
    u128_t qF0;
} Obj_4E09A8;
typedef struct {
    u8 p0[0x80];
    u128_t q80;
    u128_t q90;
    u8 pA0[0x1F0 - 0xA0];
    s16 h1F0;
    u8 p1F2[0x270 - 0x1F2];
    f32 f270;
    f32 f274;
    u8 p278[0x284 - 0x278];
    f32 f284;
    u8 p288[0x25C0 - 0x288];
    Obj_4E09A8 *f25C0;
    s32 f25C4;
    u8 p25C8[0x25E5 - 0x25C8];
    u8 b25E5;
} S_4E09A8;
typedef struct {
    u8 pad0[8800];
    f32 x2260;
    f32 x2264;
} S_004E1168;
typedef unsigned long u64l;
typedef struct {
    u64l a;
    u64l b;
    u64l c;
    u64l d;
} E_4E1758;
typedef struct {
    s16 h0;
    s16 h2;
    s16 h4;
    s16 h6;
    s16 h8;
    s16 hA;
    s16 hC;
    s16 hE;
    u64l x10;
    u64l data[1];
} H_4E1758;
typedef struct { u8 pad[164]; f32 a; f32 b; } S_004E25C8;
typedef struct { u8 pad[340]; f32 a; f32 b; } S_004E25E0;
typedef struct { u8 pad[516]; f32 a; f32 b; } S_004E25F8;
typedef struct { u8 pad[692]; f32 a; f32 b; } S_004E2610;

typedef struct {
    u8 p0[0x1B8];
    s32 f1B8;
    u8 p1BC[0xC0C - 0x1BC];
    s32 fC0C;
    u8 pC10[0x147F - 0xC10];
    u8 b147F;
    u8 p1480[0x25C0 - 0x1480];
    u8 *f25C0;
    s32 f25C4;
} S_004E1218;

typedef struct {
    u8 p0[0x600];
    s32 f600;
    u8 p604[0x650 - 0x604];
    f32 f650;
    u8 p654[0x65C - 0x654];
    s16 h65C;
    u8 p65E[0x25C0 - 0x65E];
    u8 *f25C0;
    s32 f25C4;
} S_4E2E30;

typedef struct {
    u8 pad0[0x80];
    f32 x;
    f32 y;
    u8 pad88[0x10];
    f32 angle;
    u8 pad9C[0x350 - 0x9C];
    f32 z;
    u8 pad354[0x9C8 - 0x354];
    u16 counter;
} G_004E5840;

typedef struct {
    u8 pad0[0x80];
    f32 x;
    f32 y;
    u8 pad88[0x110 - 0x88];
    f32 vx;
    f32 vy;
    u8 pad118[0x350 - 0x118];
    f32 z;
    u8 pad354[0x9C6 - 0x354];
    s16 counter;
    u8 pad9C8[0x2848 - 0x9C8];
    f32 amount;
} Emit_004E5A20;

/* declared by functions of L01_004DF428.c, which this file was cut from */
extern void func_0038CD28(s32, S_4DBFE8_Ent *, s32);
typedef struct {
    u8 pad0[0x24];
    s32 fire_sequence;
    u8 pad28[0xF0 - 0x28];
} GunRow_4DFDB0;
extern G_4DD4B0 D_001A4BE0;
extern u8 D_001425C0[];
extern GunRow_4DFDB0 D_L01_002C5600[];
extern s32 func_L01_004E9238(s32 slot);
extern s32 D_001A71A0[];
extern S_4DC790 D_L01_002F4540[];
typedef int u128_4E0618 __attribute__((mode(TI)));
typedef struct {
    u8 joint;
    u8 active;
    u8 pad2;
    u8 set;
    u8 pad4[0xC - 4];
    f32 amount;
    u128_4E0618 a;
    u128_4E0618 b;
    u128_4E0618 c;
} Lid_4E0618;
typedef struct {
    u8 pad0[0x43];
    u8 seq;
} Moby_4E0618;
extern void func_L01_0043A430(Moby_4E0618 *moby, s32 joint, Lid_4E0618 *lid);
extern u8 D_001D5470;
extern s32 D_L01_001DFB40;
extern f32 D_L01_001DBD3C __attribute__((section(".sdata")));
extern f32 func_003C4138(f32 *, f32, f32);
extern s32 func_0038CB00(void *);
extern f32 func_0038D0B0(f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_004E3268(void);
extern void func_0038CC88(void *dst, void *src, s32 n);

/* localdecomp:start func_L01_004E2ED0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_004E2ED0;
typedef struct {
    u8 p0[0x1200];
    u8 *parts[7][20];
    u8 p1430[0x22D0 - 0x1430];
    f32 sx, sy, sz;
    u8 p22DC[0x25C0 - 0x22DC];
    u8 *moby;
    u8 p25C4[0x25E4 - 0x25C4];
    u8 mode;
    u8 p25E5[0x2888 - 0x25E5];
    s16 active, index;
} H_004E2ED0;
extern H_004E2ED0 D_001A4BE0_004E2ED0;
extern f32 D_L01_002F4280[];
extern void func_0038D278(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038D000(void *, void *, void *);

void func_L01_004E2ED0(void) {
    V_004E2ED0 scale[3], matrix[3], pos;
    s32 i, j;

    if (!D_001A4BE0_004E2ED0.active) {
        return;
    }
    if (D_001A4BE0_004E2ED0.index) {
        f32 v = D_L01_002F4280[++D_001A4BE0_004E2ED0.index];
        if (v == -1.0f) {
            D_001A4BE0_004E2ED0.active = 0;
            D_001A4BE0_004E2ED0.index = 0;
            return;
        }
        D_001A4BE0_004E2ED0.sx = v;
        D_001A4BE0_004E2ED0.sz = 1.0f;
        D_001A4BE0_004E2ED0.sy = v;
    }
    func_0038D278(scale);
    func_0038CF68(&scale[0], &scale[0], D_001A4BE0_004E2ED0.sx);
    func_0038CF68(&scale[1], &scale[1], D_001A4BE0_004E2ED0.sy);
    func_0038CF68(&scale[2], &scale[2], D_001A4BE0_004E2ED0.sz);
    func_0038D5F0(matrix, scale, (u8 *)&D_001A4BE0_004E2ED0 + 0x40);
    func_0038D5F0(matrix, &D_001A4BE0_004E2ED0, matrix);
    func_0038D5F0(D_001A4BE0_004E2ED0.moby + 0xC0, D_001A4BE0_004E2ED0.moby + 0xC0, scale);
    if (!D_001A4BE0_004E2ED0.mode) {
        for (i = 0; i < 7; i++) {
            for (j = 0; j < 3; j++) {
                u8 *base = (u8 *)&D_001A4BE0_004E2ED0 + i * 80;
                u8 *p = *(u8 **)(base + 0x1200);
                if (j == 1) {
                    p = *(u8 **)(base + 0x1204);
                } else if (j == 2) {
                    p = *(u8 **)(base + 0x1208);
                }
                if (p) {
                    func_0038D5F0(p + 0xC0, matrix, p + 0xC0);
                    vec_sub_ab(&pos, p + 0x10, (u8 *)&D_001A4BE0_004E2ED0 + 0x80);
                    func_0038D000(&pos, &pos, matrix);
                    vec_add_ab(p + 0x10, &pos, (u8 *)&D_001A4BE0_004E2ED0 + 0x80);
                }
            }
        }
    }
    if (!D_001A4BE0_004E2ED0.index && D_001A4BE0_004E2ED0.sx == 1.0f && D_001A4BE0_004E2ED0.sy == 1.0f && D_001A4BE0_004E2ED0.sz == 1.0f) {
        D_001A4BE0_004E2ED0.active = 0;
    }
    D_001A4BE0_004E2ED0.sx = 1.0f;
    D_001A4BE0_004E2ED0.sy = 1.0f;
    D_001A4BE0_004E2ED0.sz = 1.0f;
}
/* localdecomp:end func_L01_004E2ED0 */
