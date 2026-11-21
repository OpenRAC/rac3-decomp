#include "common.h"

/* NTSC-U counterpart of func_L39_006AD9A0 (src/levels/39_multiplayer_menu/L39_006AD978.c) */
/* localdecomp:start func_L39_006AB050 */
typedef struct O_006AD9A0 O_006AD9A0;
typedef struct V_006AD9A0 {
    u8 pad0[0x1C];
    void (*f1C)(O_006AD9A0 *, s32, s32);
    u8 pad20[4];
    void (*f24)(O_006AD9A0 *, s32);
    u8 pad28[0x18];
    void (*f40)(O_006AD9A0 *, s32);
    void (*f44)(O_006AD9A0 *, s32, f32, f32);
    void (*f48)(O_006AD9A0 *, s32, s32);
    u8 pad4C[0x90];
    s32 (*fDC)(O_006AD9A0 *, s32);
} V_006AD9A0;
struct O_006AD9A0 {
    u8 pad[0x60];
    V_006AD9A0 *vt;
};
typedef struct T_006AD9A0 {
    u8 pad0[0x110];
    O_006AD9A0 *f110;
    O_006AD9A0 *f114;
    O_006AD9A0 *f118;
    u8 pad11C[4];
    O_006AD9A0 *f120;
    O_006AD9A0 *f124;
    O_006AD9A0 *f128;
    O_006AD9A0 *f12C;
    O_006AD9A0 *grid[4][4];
    u8 pad170[0x138];
    s32 a2A8[4];
    s32 a2B8[8];
    u8 a2D8[4];
    char a2DC[4][32];
    s32 a35C[4];
    s32 a36C[4];
    s32 a37C[4];
    u8 pad38C_[0];
    s32 f38C;
    s32 f390;
} T_006AD9A0;
typedef struct G_006AD9A0 {
    u8 pad[0x17C];
    s16 f17C;
    u8 pad17E[2];
    s32 f180;
    u8 pad184[0x19];
    s8 f19D;
} G_006AD9A0;
typedef struct N_006AD9A0 { s32 s[10]; } N_006AD9A0;
typedef union U_006AD9A0 { char buf[0x50]; N_006AD9A0 n; } U_006AD9A0;

typedef struct Net_006AD9A0 { s32 w[4]; } Net_006AD9A0;
extern Net_006AD9A0 D_L39_002407A8 __attribute__((section(".sdata")));
__asm__(".extern D_L39_002417C0, 16");
extern G_006AD9A0 *D_L39_002417C0;
extern f32 D_001DD3BC_sda;
extern f32 D_001DD3C0_sda;
extern f32 D_001DD3C4_sda;
extern f32 D_001DD3C8_sda;
extern f32 D_001DD3CC_sda;
extern f32 D_001DD3D0_sda;
extern f32 D_001DD3D4_sda;
extern f32 D_001DD3D8_sda;
extern f32 D_001DD3DC_sda;
extern f32 D_001DD3E0_sda;
extern f32 D_001DD3E4_sda;
extern f32 D_001DD3E8_sda;
extern f32 D_001DD3EC_sda;
extern f32 D_001DD3F0_sda;
extern f32 D_001DD3F4_sda_006AB050;
extern f32 D_001DD3F8_sda_006AB050;
extern f32 D_001DD3FC_sda_006AB050;
extern f32 D_001DD400_sda_006AB050;
extern f32 D_001DD404_sda_006AB050;
extern f32 D_001DD408_sda_006AB050;
extern f32 D_001DD40C_sda_006AB050;
extern f32 D_001DD414_sda_006AB050;
extern f32 D_L39_00248CBC[] __attribute__((section(".sdata")));
extern f32 D_L39_00248CC0[] __attribute__((section(".sdata")));
extern f32 D_001DD428_sda_006AB050;
extern char D_L39_00248CD8[];
extern char D_L39_00248CE0[];
extern char D_L39_00248CE8[];
extern char D_L39_00248CF0[];
extern char D_L39_00248CF8[];
extern char D_001A5F0E[];
extern s32 func_L39_0067C5E0(s32);
extern void func_L39_00687E10(s32);
extern s32 func_0037DF98(s32);
extern void func_L39_00687030(T_006AD9A0 *, s32);
extern void func_L39_00687180(T_006AD9A0 *, s32);
extern void func_L39_006872B0(T_006AD9A0 *, char *, u32, f32, f32);
extern void func_L39_00687210(T_006AD9A0 *, s32);
extern void func_L39_00687B28(T_006AD9A0 *, s32, u32, f32, f32, f32, f32);
extern void func_L39_00687900(T_006AD9A0 *, s32, s32, u32, f32, f32, f32, f32);
extern void func_L39_00687F10(T_006AD9A0 *);
extern s32 func_00120048(char *, const char *, ...);
extern void func_00388490(char *, s32);
extern void func_00120D28(char *, s32, s32);
extern void func_L39_006ABFA8(T_006AD9A0 *, s32, s32);
extern void func_L39_006AC5D0(u8 *);
extern void func_L39_005BFA18(s32, s32, s32);

static __inline__ void label_006AD9A0(O_006AD9A0 **slot, char *fmt, s32 id) {
    char buf[0x50];
    func_00120048(buf, fmt, func_0037DF98(id));
    (*slot)->vt->f24(*slot, (s32)buf);
}

void func_L39_006AB050(T_006AD9A0 *this) {
    s32 s;
    f32 d;
    s32 i;
    s32 j;
    s32 k;
    O_006AD9A0 **p;

    func_L39_0067C5E0(0x410000);
    func_L39_00687E10(0);
    func_L39_00687030(this, func_0037DF98(0xFF4));
    func_L39_00687180(this, func_0037DF98(0x124));
    func_L39_006872B0(this, D_L39_00248CD8, 0x706EC8FF, 1.0f, 1.0f);
    func_L39_00687210(this, func_0037DF98(0xCD5));
    func_L39_00687B28(this, 0, 0x332299DE, D_001DD3BC_sda, D_001DD3C0_sda, D_001DD3C4_sda, D_001DD3C8_sda);
    func_L39_00687B28(this, 1, 0x332299DE, D_001DD3CC_sda, D_001DD3D0_sda, D_001DD3D4_sda, D_001DD3D8_sda);
    func_L39_00687B28(this, 2, 0x332299DE, D_001DD3DC_sda, D_001DD3E0_sda, D_001DD3E4_sda, D_001DD3E8_sda);
    func_L39_00687B28(this, 3, 0x332299DE, D_001DD3EC_sda, D_001DD3F0_sda, D_001DD3F4_sda_006AB050, D_001DD3F8_sda_006AB050);
    func_L39_00687B28(this, 4, 0x332299DE, D_001DD3FC_sda_006AB050, D_001DD400_sda_006AB050, D_001DD404_sda_006AB050, D_001DD408_sda_006AB050);
    d = D_001DD408_sda_006AB050 - D_001DD40C_sda_006AB050;
    func_L39_00687900(this, 1, 4, 0x332299DE, D_001DD3FC_sda_006AB050,
                      D_001DD400_sda_006AB050 + d * -1.5f / 5.0f + D_001DD414_sda_006AB050,
                      (D_001DD400_sda_006AB050 + -d / 5.0f) - (D_001DD400_sda_006AB050 + d * -2.0f / 5.0f),
                      D_001DD404_sda_006AB050 - (D_001DD40C_sda_006AB050 + D_001DD40C_sda_006AB050));
    func_L39_00687F10(this);

    label_006AD9A0(&this->f124, D_L39_00248CE0, 0x1332);
    label_006AD9A0(&this->f128, D_L39_00248CE8, 0x1631);
    label_006AD9A0(&this->f12C, D_L39_00248CF0, 0x1632);

    for (p = this->grid[3], j = 0; j < 4; j++, p++) {
        p[-12]->vt->f1C(p[-12], 0, 0);
        p[-4]->vt->f1C(p[-4], 0, 0);
        p[-8]->vt->f1C(p[-8], 0, 0);
        p[0]->vt->f1C(p[0], 0, 0);
        p[-12]->vt->f48(p[-12], 1, 3);
        p[0]->vt->f48(p[0], 3, 3);
        p[-12]->vt->f44(p[-12], 1, D_001DD428_sda_006AB050, 0.0f);
        p[0]->vt->f44(p[0], 1, D_L39_00248CC0[0], 0.0f);
        p[-12]->vt->f40(p[-12], 1);
        p[0]->vt->f40(p[0], 1);
    }

    this->f120->vt->fDC(this->f120, D_L39_002417C0->f17C % 10 + 0x25);
    this->f110->vt->f1C(this->f110, 1, 0);
    this->f114->vt->f1C(this->f114, 1, 0);
    this->f114->vt->f40(this->f114, 1);
    this->f118->vt->f1C(this->f118, 1, 0);
    this->f118->vt->f40(this->f118, 1);
    this->f124->vt->f48(this->f124, 1, 3);
    this->f124->vt->f1C(this->f124, 1, 0);
    this->f124->vt->f40(this->f124, 1);
    this->f124->vt->f44(this->f124, 1, D_001DD428_sda_006AB050, 0.0f);
    this->f128->vt->f1C(this->f128, 1, 0);
    this->f128->vt->f40(this->f128, 1);
    this->f128->vt->f44(this->f128, 1, D_L39_00248CBC[0], 0.0f);
    this->f12C->vt->f1C(this->f12C, 1, 0);
    this->f12C->vt->f40(this->f12C, 1);
    this->f12C->vt->f44(this->f12C, 1, D_L39_00248CC0[0], 0.0f);

    {
    N_006AD9A0 names = {{
        func_0037DF98(0xBB1), func_0037DF98(0xBB2), func_0037DF98(0xDA),
        func_0037DF98(0xBB4), func_0037DF98(0xD8), func_0037DF98(0xD4),
        func_0037DF98(0x18C4), func_0037DF98(0x18C5), func_0037DF98(0x18C6),
        func_0037DF98(0x18C7)
    }};
    s = names.s[D_L39_002417C0->f17C % 10];
    this->f114->vt->f24(this->f114, s);
    }

    s = func_0037DF98(0x1328);
    switch (D_L39_002407A8.w[0]) {
    case 0: s = func_0037DF98(0x1024); break;
    case 1: s = func_0037DF98(0x10E2); break;
    case 2: s = func_0037DF98(0x1026); break;
    }
    this->f118->vt->f24(this->f118, s);
    this->f110->vt->f24(this->f110, func_0037DF98(0xF58));
    func_00388490(D_001A5F0E, 0x40);
    func_00120D28(D_001A5F0E, func_0037DF98(0xF58), 0x10);

    for (i = 0; i < 4; i++) {
        this->a2D8[i] = 0;
        func_00120048(this->a2DC[i], D_L39_00248CF8, func_0037DF98(0x1424), i + 1);
        this->a35C[i] = 0;
        if (D_L39_002417C0->f180 == 2 && D_L39_002417C0->f19D == 0) {
            this->a36C[i] = i;
        } else {
            this->a36C[i] = i % 2;
        }
        this->a2A8[i] = -1;
        this->a37C[i] = -1;
    }
    for (k = 7; k >= 0; k--) {
        this->a2B8[k] = -1;
    }
    this->a2A8[0] = 0;
    this->a2D8[0] = 1;
    this->a2B8[0] = 0;
    if (D_L39_002417C0->f180 == 2) {
        this->f390 = 8;
    } else {
        this->f390 = 2;
    }
    this->f38C = 0x16;
    func_L39_006ABFA8(this, 1, -1);
    func_L39_006AC5D0((u8 *)this);
    func_L39_005BFA18(1, 1, 0x400);
}
/* localdecomp:end func_L39_006AB050 */
