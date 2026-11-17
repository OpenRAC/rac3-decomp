#include "common.h"

/* NTSC-U counterpart of func_L39_006E1108 (src/levels/39_multiplayer_menu/L39_006E0D90.c) */
/* localdecomp:start func_L39_006DE5A8 */
typedef struct {
    u8 x[0x10];
} S_006E1108_Half;
typedef struct {
    S_006E1108_Half h0;
    S_006E1108_Half h1;
} S_006E1108_Hdr;
typedef struct {
    u8 b0;
    u8 b1;
} S_006E1108_Pair;
typedef struct {
    f32 a[8];
    f32 b[8];
    f32 c[8];
    S_006E1108_Hdr hdr;
    char names[8][15];
    u8 f0F8[8];
    u8 f100[8];
    S_006E1108_Pair f108[8];
    u8 f118[8];
    u8 f120[8];
    s16 f128[8];
    u8 f138[8];
    u8 f140[8];
    u8 f148;
    u8 f149;
    u8 f14A[8];
    S_006E1108_Pair f152[8][9];
    u8 f1E2;
    u8 f1E3;
    u8 f1E4;
    u8 f1E5;
    char pad[2];
} S_006E1108;
typedef struct {
    S_006E1108_Hdr hdr;
    char pad[0x30 - 0x20];
    u8 f30;
} S_006E1108_Src;
typedef struct {
    s32 ids[8];
    f32 a[8];
    f32 b[8];
    f32 c[8];
    char pad[0x8C - 0x80];
    s32 count;
    char pad2[0xA4 - 0x90];
} S_006E1108_Ent;
typedef struct { u8 v; u8 pad[3]; } S_006E1108_B4;
typedef struct { u8 f0; u8 f1; u8 f2; u8 f3; } S_006E1108_Q4;
typedef struct {
    u8 names[8][0x20];
    S_006E1108_B4 f100[8];
    S_006E1108_B4 f120[8];
    S_006E1108_Q4 f140[8];
    u8 f160[8];
    u8 f168[8];
    u8 f170[8];
    u8 f178[8];
    f32 f180[8];
    char pad1A0[8];
    u8 f1A8;
    char pad1A9[3];
    u8 f1AC;
    char pad1AD[0x1B8 - 0x1AD];
    s16 f1B8[8];
    u8 f1C8[8][36];
    char pad2E8[0x2E8 - 0x1C8 - 8 * 36];
    S_006E1108_Ent ent[8];
    char pad808[4];
    u8 f80C;
    char pad80D[3];
    u8 f810;
} S_006E1108_D;
extern S_006E1108_D D_L39_001FD968;
extern S_006E1108_Src D_001A5ED8;
__asm__(".extern D_L39_00240580, 16");
extern u8 D_L39_00240580;
extern char D_L39_0024A1F8[];
extern char D_001A6032[];
void func_0011D534(void *, s32, s32);
s32 func_00120048(char *, char *, ...);
s32 func_00120884(void *);
void func_0014C280(char *, char *);
void func_0014AB98(s32, char *, s32, s32, s32, void *);
s32 func_L39_006DE570(u8 *arg0);

void func_L39_006DE5A8(void) {
    S_006E1108 s;
    char buf[0x10];
    s32 i;
    s32 k;
    s32 h;

    i = 0;
    func_0011D534(&s, 0, sizeof(s));
    s.hdr.h0 = D_001A5ED8.hdr.h0;
    s.hdr.h1 = D_001A5ED8.hdr.h1;
    s.f148 = D_L39_001FD968.f1A8;
    s.f149 = D_L39_001FD968.f1AC;
    s.f1E2 = D_L39_001FD968.f80C;
    s.f1E3 = D_L39_001FD968.f810;
    s.f1E4 = D_L39_00240580;
    s.f1E5 = D_001A5ED8.f30;
    for (; i < 8; i++) {
        for (k = 0; k < D_L39_001FD968.ent[i].count; k++) {
            s32 id = D_L39_001FD968.ent[i].ids[k];
            s.a[id] = D_L39_001FD968.ent[i].a[k];
            s.b[id] = D_L39_001FD968.ent[i].b[k];
            s.c[id] = D_L39_001FD968.ent[i].c[k];
        }
        h = func_L39_006DE570(D_L39_001FD968.names[i]);
        func_00120048(s.names[i], D_L39_0024A1F8, h);
        s.f0F8[i] = D_L39_001FD968.f100[i].v;
        s.f100[i] = D_L39_001FD968.f120[i].v;
        s.f108[i].b0 = D_L39_001FD968.f140[i].f0;
        s.f108[i].b1 = D_L39_001FD968.f140[i].f2;
        s.f118[i] = D_L39_001FD968.f160[i];
        s.f120[i] = D_L39_001FD968.f168[i];
        s.f128[i] = D_L39_001FD968.f180[i];
        s.f138[i] = D_L39_001FD968.f170[i];
        s.f140[i] = D_L39_001FD968.f178[i];
        s.f14A[i] = D_L39_001FD968.f1B8[i];
        for (k = 0; k < 9; k++) {
            s.f152[i][k].b0 = D_L39_001FD968.f1C8[i][k * 4];
            s.f152[i][k].b1 = D_L39_001FD968.f1C8[i][k * 4 + 2];
        }
    }
    if (func_00120884(D_001A6032) != 0) {
        func_0014C280(buf, D_001A6032);
        func_0014AB98(0, buf, 2, 0, sizeof(s), &s);
    }
}
/* localdecomp:end func_L39_006DE5A8 */
