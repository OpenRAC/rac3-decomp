#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 pos[2]; s32 color0; s32 x24; s32 color1; s32 x2C; } Sparks;
typedef struct { s32 id; u8 pad4[0xC]; u128_t pos; u8 path[0x10]; } Vars_3B5068;
typedef struct {
    u8 pad0[0x10];
    u128_t pos;
    u8 pad20[0xC];
    f32 scale;
    u8 pad30[4];
    u16 x34;
    u8 pad36[0x32];
    Vars_3B5068 *vars;
} Moby_3B5068;
typedef struct { u8 pad0[0x12]; s16 count; u8 pad14[0xC]; s32 *ids; u8 pad24[0xC]; } Path_3B4108;
typedef struct { s32 count; u8 pad4[0x1C]; Path_3B4108 paths[1]; } Paths_3B4108;
typedef struct { u8 pad0[0x30]; V4 pos; u8 pad40[0x40]; } Node_3B4108;
typedef struct { u8 pad0[0x18]; s32 x18; u8 pad1C[4]; V4 pos; } Tgt_3B4108;
typedef struct {
    f32 pos[4][4];
    u32 rgba[4];
    f32 uv[4][2];
    unsigned long count;
    unsigned long tex;
    unsigned long tex0;
    unsigned long alpha;
} Quad_3B5628;
typedef struct {
    u8 pad0[0xA8];
    s32 xA8;
    u8 padAC[0x2C8 - 0xAC];
    s32 x2C8;
    u8 pad2CC[0x310 - 0x2CC];
    u128_t x310;
    V4 x320;
} Vars_3B67B0;
typedef struct {
    u8 pad0[0x30]; f32 x30; s16 x34; u8 pad36[0x388 - 0x36];
    s32 x388; u8 pad38C[4]; u32 x390; u8 pad394[4]; s32 x398; u8 pad39C[4]; s32 x3A0[12];
} Vars_3B44F8;
typedef struct { u8 pad0[0x2B0]; s32 x2B0; } EVars_3B44F8;
typedef struct {
    u8 pad0[0x30]; f32 x30; s16 h34; u8 pad36[0x3]; u8 x39; u8 pad3A[0x6]; f32 x40; u8 pad44[0x14];
    u8 x58; u8 pad59[0x1]; u8 x5A; u8 pad5B[0x15]; f32 x70; f32 x74; f32 x78; f32 x7C; f32 x80; u8 pad84[0x18];
    f32 x9C; f32 xA0; f32 xA4; u8 padA8[0xC8]; u8 x170; u8 x171; u8 pad172[0xA];
    f32 x17C; f32 x180; f32 x184; f32 x188; f32 x18C; f32 x190; f32 x194; u8 pad198[0x4]; f32 x19C; f32 x1A0;
    u8 pad1A4[0x5]; u8 x1A9; u8 pad1AA[0xE]; f32 x1B8; f32 x1BC; u8 pad1C0[0xC]; u8 x1CC; u8 x1CD; u8 pad1CE[0x9];
    u8 x1D7; u8 x1D8; u8 pad1D9[0x2]; u8 x1DB; u8 pad1DC[0x220 - 0x1DC];
    V4 v220; s32 w230; s16 h234; u8 pad236[0x240 - 0x236]; u8 a240[0x80];
    s32 x2C0; s32 x2C4; s32 x2C8; s32 x2CC;
    s32 w2D0; f32 f2D4; s32 w2D8; f32 f2DC; u8 pad2E0[0x8]; s32 x2E8; u8 pad2EC[0x4]; s32 x2F0; s32 x2F4;
    u8 pad2F8[0x10]; s32 x308; s32 w30C; u8 pad310[0x10]; V4 x320; V4 x330;
} V_3B6390;
typedef struct {
    u8 pad0[0x10]; V4 pos; u8 b20; u8 pad21[0x10]; u8 b31; u8 pad32[0x68 - 0x32];
    V_3B6390 *vars; u8 pad6C[3]; u8 b6F; u8 pad70[0x25]; u8 b95;
} M_3B6390;
typedef struct { u8 pad0[0x24]; f32 x24; } Cls_3B4AD0;
typedef struct { s32 id; u8 pad4[0xC]; V4 home; u8 path[0x10]; } Vars_3B4AD0;
typedef struct {
    u8 pad0[0x10]; V4 pos; u8 b20; u8 pad21[3]; Cls_3B4AD0 *cls; u8 pad28[4]; f32 scale; u8 pad30[4]; u16 x34;
    u8 pad36[0x32]; Vars_3B4AD0 *vars; u8 pad6C[0x2A]; u16 h96; s32 x98; u8 pad9C[0xC]; u8 bA8; u8 padA9[0x47]; f32 rot[3];
} Moby_3B4AD0;
typedef struct { u8 pad0[0x44]; u16 x44; u8 pad46[2]; u8 *x48; u8 pad4C[8]; u8 *x54; u8 *x58; } Cls_3B57B8;
typedef struct { s32 count; u8 pad4[0xC]; V4 pts[1]; } Pts_3B57B8;
typedef struct {
    u8 pad0[0x30]; f32 x30; u8 pad34[0x160 - 0x34]; u8 a160[0xC0];
    V4 v220; s32 w230; s16 h234; u8 pad236[0x2C0 - 0x236];
    s32 x2C0; s32 x2C4; u8 pad2C8[4]; s32 x2CC; u8 pad2D0[0x2E0 - 0x2D0];
    s32 x2E0; s32 x2E4; s32 x2E8; f32 x2EC; u8 pad2F0[0x300 - 0x2F0];
    s32 x300; s32 x304; u8 pad308[0x320 - 0x308];
    V4 x320; V4 x330;
} Vars_3B57B8;
typedef struct {
    u8 pad0[0x10]; V4 pos; u8 b20; u8 pad21[3]; Cls_3B57B8 *cls; u8 pad28[0xC]; u16 flags;
    u8 pad36[0xC]; u8 b42; u8 b43; u8 pad44[4]; s32 x48; u8 pad4C[0x14]; u8 b60; u8 pad61[7];
    Vars_3B57B8 *vars; u8 pad6C[0x29]; u8 b95; u8 pad96[2]; s32 x98; u8 pad9C[0x20]; u8 bBC;
    u8 padBD[0x3B]; f32 fF8;
} Moby_3B57B8;
typedef struct {
    u8 pad0[0x78]; f32 f78; f32 f7C; f32 f80; u8 pad84[0x9C - 0x84]; f32 f9C;
    u8 padA0[4]; f32 fA4; s32 wA8; u8 padAC[0x110 - 0xAC]; f32 a110[2]; f32 f118;
    u8 pad11C[0x300 - 0x11C]; s32 w300; u8 pad304[0x310 - 0x304]; s32 w310; u8 a314[0x10];
    f32 f324; f32 f328; u8 pad32C[0x334 - 0x32C]; s32 w334; u8 pad338[8]; s32 w340; f32 f344;
    u8 pad348[8]; u8 a350[0x28]; f32 f378; u8 pad37C[0x39C - 0x37C]; f32 f39C;
} V_3B3BB8;
typedef struct {
    u8 pad0[0x10]; V4 pos; u8 pad20[0x48]; V_3B3BB8 *vars; u8 pad6C[0xF4 - 0x6C]; s32 wF4;
} M_3B3BB8;

extern f32 D_L23_001DE2E8[] __attribute__((section(".sdata")));
extern f32 D_L23_001DE2F8[] __attribute__((section(".sdata")));
extern f32 D_L23_001DE308[] __attribute__((section(".sdata")));
extern f32 D_L23_001DE318[] __attribute__((section(".sdata")));
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern f32 func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern s32 func_L23_003B3EA8(u8 *, s32, f32 *, void *, void *, s32);
extern void func_L01_0045A898(void *, void *, f32);
extern s32 func_L01_0045BD10(void *, f32);
extern f32 func_L01_0040E570(void *a, void *b);
extern void func_L01_0045AA10(void *, f32);
extern void func_L01_0045A748(void *, void *);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern f32 func_0038CEA8(f32 *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_L01_00448890(u8 *a0, u8 *a1, f32 f12, f32 f13, f32 f14, f32 f15, s32 a2);
#include "common.h"
#include "vu0.h"
extern Paths_3B4108 *D_L23_001DED4C;
extern Node_3B4108 *D_L23_001DF240;
extern f32 func_L01_0040E570(void *, void *);
extern void func_003886E8(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern int func_00382380(void *, int, int);
extern Paths_3B4108 *D_L23_001DED4C;
extern Node_3B4108 *D_L23_001DF240;
extern Tgt_3B4108 D_L23_001E8780;
#include "structs/hero.h"
extern struct Hero D_001A4BE0_3B4108;
extern V4 D_001A4C60;
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern u16 *D_L23_0021C0E0[];
extern u8 *D_L23_001DF15C;
extern s32 D_L23_001DF198;
extern s32 D_L23_001DE2DC;
extern s32 D_L23_001DE2E0;
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L23_003A4448(s32, s32, f32);
extern void func_L23_003B0010(s32);
#include "vu0.h"
extern f32 D_L23_001DE32C;
extern u8 D_001A4CC0[];
extern void func_L01_0040A8C0(void *, void *, s32, s32, u32, u32, u32, u32, f32, f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);

/* localdecomp:start func_L23_003B31C8 */
#include "vu0.h"
extern Moby_3B5068 *D_L23_001DE450;
__asm__(".extern D_L23_001DE450, 4");
extern s32 D_L23_001DE170;
extern s32 D_L23_001DE440;
__asm__(".extern D_L23_001DE440, 4");
extern s32 D_L23_001DE430_003B31C8;
__asm__(".extern D_L23_001DE430_003B31C8, 4");
extern u16 **D_L23_001D6764;
extern u8 *D_L23_001E0094;
void func_L23_003B3A10(void);
void func_L23_003B3760(Moby_3B5068 *o);
void func_L23_003B3D20(u8 *obj);
extern s32 func_L01_00444358(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_L01_0044C1D0(void *, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_0045FEC8(void *, void *, void *, u32, u32, s32, s32, s32, s32);
extern s32 func_L01_00452EC8(u8 *);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern s32 func_0039FE80(s32, s32, void *);
extern s32 func_L01_0032FE90(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00402498(void *, void *);

void func_L23_003B31C8(Moby_3B4AD0 *self)
{
    Vars_3B4AD0 *v = self->vars;
    V4 d;
    V4 a;
    V4 b;
    V4 c;
    u8 *h;
    f32 f;
    f32 ang;
    f32 t;
    s32 i;
    u16 *p;
    u8 *e;

    if (v->id < 0)
        return;
    if (D_L23_001DE450 == (Moby_3B5068 *)self)
        func_L23_003B3A10();
    switch (self->b20) {
    case 0:
        func_L23_003B3760((Moby_3B5068 *)self);
        break;
    case 1:
        h = (u8 *)func_L01_00444358(self, -1, 0);
        if (h != 0) {
            f = *(f32 *)(h + 0x2C);
            if (3.0f < f) {
                if (40.0f < f)
                    func_L01_00441FB8(self, 3, -1);
                else
                    func_L01_00441FB8(self, 2, -1);
            }
            self->bA8 = 0xFF;
        }
        break;
    case 2:
        ang = func_0037E250(-3.1415927f, 3.1415927f);
        t = (f32)self->h96 / (f32)D_L23_001DE170;
        d.x = (v->home.x - self->pos.x) + t * 0.100000009f * func_00388960(ang);
        d.y = (v->home.y - self->pos.y) + t * 0.100000009f * func_00388978(ang);
        d.z = 0.0f;
        d.w = 1.0f;
        vec_add_ab(&self->pos, &self->pos, &d);
        func_L01_0044C1D0(self, v->path);
        for (i = 4; i >= 0; i--) {
            f32 th;
            func_003886E8(&a, &D_L23_001DE430_003B31C8, self->scale / self->cls->x24);
            vec_add_ab(&a, &a, &self->pos);
            th = func_0037E250(-3.1415927f, 3.1415927f);
            b.x = func_00388960(th) * 0.26666668f;
            b.y = func_00388978(th) * 0.26666668f;
            b.z = 0.033333335f;
            vec_add_ab(&b, &b, &d);
            b.w = 1.0f;
            func_003886E8(&c, &b, 0.25f);
            c.w = 2.0f;
            func_L01_0045FEC8(&a, &b, &c, 0x60807070, 0x40706060, 0xF, 0xA, 0xA, -1);
        }
        if (self->h96 >= 0x3D)
            func_L01_00441FB8(self, 3, -1);
        break;
    case 3:
        if (func_L01_00452EC8((u8 *)self) != 0) {
            self->x34 |= 0x41;
            self->x98 = 0;
            self->rot[2] = func_0037E250(-3.1415927f, 3.1415927f);
            self->pos.z = func_003BE7F0(&self->pos, 0, 0, 0.5f);
            func_0039FE80(0, 0, self);
            p = D_L23_001D6764[v->id];
            while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[v->id])) {
                e = D_L23_001E0094 + ((*p & 0x7FFF) << 5);
                if (e == 0)
                    break;
                e[0x1E] |= 4;
                p++;
            }
            func_003886E8(&d, &D_L23_001DE440, self->scale * 0.5f / self->cls->x24);
            vec_add_ab(&d, &d, &self->pos);
            func_L01_0032FE90((u8 *)&d, 1, 0xE, 0x14, 0xC, 0xA, 0x14, 8, 7.0f, 10.0f, 1.5f, 5.0f,
                              1, 1, 1, 1, 1, 1, 0x1130007, 0, 0x688EF7, 0x6363F7, 0x7000FFFF, 0x7000FFFF, 0x8FAF, 0x70303280, 0x7F004020, 0x2800FFFF, 0x3064FF, 0);
        }
        func_L01_00402498(func_L23_003B3D20, self);
        break;
    }
    self->h96++;
}
/* localdecomp:end func_L23_003B31C8 */
