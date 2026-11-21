#include "common.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x228]; f32 f228; u8 pad22C[0x244 - 0x22C]; s32 i244;
    u8 pad248[0x2BC - 0x248]; s32 i2BC;
    V4 a2C0[8]; V4 a340[8]; V4 a3C0[8]; V4 a440[8];
} P_3AFAF0;
typedef struct { u8 pad0[0x68]; P_3AFAF0 *p; } S_3AFAF0;
typedef struct {
    u8 pad0[0x10];
    u128_t pos;
    u8 x20;
    u8 pad21[0xB];
    f32 scale;
    u8 x30;
    u8 pad31;
    s16 x32;
    u16 x34;
    u8 pad36[0x32];
    u8 *vars;
} Moby_3B12C8;
typedef struct {
    u8 pad0[0x220]; s32 w220; u8 pad224[0x22C - 0x224]; void *p22C;
    u8 pad230[0x2BC - 0x230]; s32 i2BC;
    V4 a2C0[8]; V4 a340[8];
} P_3AFC40;
typedef struct { u8 pad0[0x20]; u8 b20; u8 pad21[0x68 - 0x21]; P_3AFC40 *p; u8 pad6C[0xAA - 0x6C]; u16 hAA; } S_3AFC40;
typedef struct { u8 pad0[0x18]; u8 b18; u8 b19; u16 h1A; u8 pad1C[0x14]; } B_3AFC40;
typedef struct { u8 pad0[0x18]; void *p18; u8 pad1C[4]; u8 a20[1]; } H_3AFC40;
typedef struct {
    u8 pad0[0x10];
    V4 pos;
    u8 x20;
    u8 pad21[0x95 - 0x21];
    u8 x95;
    u8 pad96[0xA8 - 0x96];
    u8 xA8;
} Moby_3AF6E8;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B0200;
typedef struct { u8 pad0[0x12]; s16 count; u8 pad14[0xC]; s32 *ids; u8 pad24[0xC]; } Path_3B0200;
typedef struct { s32 count; u8 pad4[0x1C]; Path_3B0200 paths[1]; } Paths_3B0200;
typedef struct { u8 pad0[0x30]; V4_3B0200 pos; u8 pad40[0x40]; } Node_3B0200;
typedef struct { u8 pad0[0x180]; struct Moby *target; } Vars_3B34F8;
typedef struct { s32 x0; void *x4; s32 x8; s32 xC; V4 pos; } Vars_3B0A20;
typedef struct { u8 pad0[0x18]; u8 b18; u8 b19; s16 h1A; u8 pad1C[4]; s32 x20; u8 pad24[0xC]; } Hit_3B0A20;
typedef struct {
    u8 pad0[0x10]; V4 pos; u8 pad20[0x48]; Vars_3B0A20 *vars; u8 pad6C[0x2A]; u16 x96; u8 pad98[0x12]; s16 xAA;
} M_3B0A20;
typedef struct {
    u8 pad0[0x220]; s32 w220; u8 pad224[0x238 - 0x224]; f32 f238;
    u8 pad23C[0x2BC - 0x23C]; s32 i2BC;
    V4 a2C0[8]; V4 a340[8]; V4 a3C0[8]; V4 a440[8];
} P_3B0480;
typedef struct { u8 pad0[0x68]; P_3B0480 *p; } S_3B0480;
typedef struct {
    u8 pad0[0x30];
    f32 x30;
    s16 x34;
    u8 pad36[0x39 - 0x36];
    u8 x39;
    u8 pad3A[0x40 - 0x3A];
    f32 x40;
    u8 pad44[0x58 - 0x44];
    u8 x58;
    u8 pad59;
    u8 x5A;
    u8 pad5B[0x70 - 0x5B];
    f32 x70;
    f32 x74;
    f32 x78;
    f32 x7C;
    f32 x80;
    u8 pad84[0xA8 - 0x84];
    s32 xA8;
    u8 padAC[0x2A4 - 0xAC];
    f32 x2A4;
    u8 pad2A8[0x2B8 - 0x2A8];
    f32 x2B8;
    u8 pad2BC[0x2DC - 0x2BC];
    s32 x2DC;
    s32 x2E0;
    s32 x2E4;
    u8 pad2E8[0x300 - 0x2E8];
    s32 x300;
    s32 x304;
    f32 x308;
    s32 x30C;
    u8 pad310[4];
    s32 x314;
    s32 x318;
    s32 x31C;
    u8 pad320[4];
    s32 x324;
    s32 x328;
    s32 x32C;
    s32 x330;
    s32 x334;
    f32 x338;
    s32 x33C;
    s32 x340;
    s32 x344;
    s32 x348;
    s32 x34C;
    V4 x350;
    V4 x360;
    V4 x370;
    s32 x380;
    s32 x384;
    s32 x388;
    s32 x38C;
    s32 x390;
    u8 pad394[4];
    s32 x398;
} Vars_3B3998;

#include "vu0.h"
#include "structs/hero.h"
typedef struct { u8 pad0[0x10]; u8 b10; } Sub_AD;
typedef struct {
    u8 pad0[0x10]; s32 i10; u8 pad14[0x30]; u16 h44; u8 pad46[2];
    Sub_AD *p48; Sub_AD *p4C; u8 pad50[0x10]; Sub_AD *p60; Sub_AD *p64;
} Cls_AD;
typedef struct {
    u8 pad0[0x30]; f32 f30; s16 h34; u8 pad36[0xA4 - 0x36]; f32 fA4;
    u8 padA8[0xF4 - 0xA8]; s32 iF4;
    u8 padF8[0x170 - 0xF8]; f32 f170; f32 f174; u8 pad178[0x184 - 0x178]; s16 h184;
    u8 pad186[0x210 - 0x186]; s32 i210; s32 i214; s32 i218; s32 i21C; s32 i220; f32 f224;
    s32 i228; s32 i22C; f32 f230; f32 f234; u8 pad238[4]; s32 i23C; s32 i240; s32 i244;
    u8 pad248[4]; f32 f24C; V4 v250; V4 v260; V4 v270; u8 pad280[0x10]; V4 v290;
    u8 pad2A0[0x10]; s32 i2B0; f32 f2B4; f32 f2B8; s32 i2BC;
} Vars_AD;
typedef struct {
    u8 pad0[0x10]; V4 pos;
    u8 b20; u8 b21; u8 pad22[2]; Cls_AD *cls; u8 pad28[8];
    union { unsigned long q; u8 b[8]; u16 h[4]; } f30;
    u8 pad38[8];
    u8 b40[2]; u8 b42; u8 b43; u8 pad44[4]; f32 f48; u8 pad4C[0x60 - 0x4C];
    u8 b60; u8 pad61[7]; Vars_AD *vars; u8 pad6C[0x94 - 0x6C];
    u8 b94; u8 b95; s16 h96; s32 i98; u8 pad9C[0xF0 - 0x9C]; V4 vF0;
} Moby_AD;

extern f32 D_L23_001DE1F0[6] __attribute__((section(".sdata"))); __asm__(".extern D_L23_001DE1F0, 4");
extern f32 D_L23_001DE208[6] __attribute__((section(".sdata"))); __asm__(".extern D_L23_001DE208, 4");
extern f32 D_L23_001DE220; __asm__(".extern D_L23_001DE220, 4");
extern f32 D_L23_001DE224; __asm__(".extern D_L23_001DE224, 4");
extern f32 D_L23_001DE228; __asm__(".extern D_L23_001DE228, 4");
extern f32 D_L23_001DE22C; __asm__(".extern D_L23_001DE22C, 4");
extern f32 D_L23_001DE234; __asm__(".extern D_L23_001DE234, 4");
extern f32 D_L23_001DE238; __asm__(".extern D_L23_001DE238, 4");
extern f32 D_L23_001DE23C; __asm__(".extern D_L23_001DE23C, 4");
extern f32 D_L23_001DE240; __asm__(".extern D_L23_001DE240, 4");
extern f32 D_L23_001DE248; __asm__(".extern D_L23_001DE248, 4");
extern f32 D_L23_001DE254; __asm__(".extern D_L23_001DE254, 4");
extern f32 D_L23_001DE258; __asm__(".extern D_L23_001DE258, 4");
extern f32 D_L23_001DE25C; __asm__(".extern D_L23_001DE25C, 4");
extern f32 D_L23_001DE264; __asm__(".extern D_L23_001DE264, 4");
extern f32 D_L23_001DE268; __asm__(".extern D_L23_001DE268, 4");
extern f32 D_L23_001DE26C; __asm__(".extern D_L23_001DE26C, 4");
extern f32 D_L23_001DE270; __asm__(".extern D_L23_001DE270, 4");
extern s32 D_L23_001DE278; __asm__(".extern D_L23_001DE278, 4");
extern Moby_AD *D_L23_001DE2D0;
extern s32 D_001A7430[];
extern s32 D_001A71A0[];

extern struct Hero D_001A4BE0;
extern Paths_3B0200 *D_L23_001DED4C; __asm__(".extern D_L23_001DED4C, 16");
extern Node_3B0200 *D_L23_001DF240; __asm__(".extern D_L23_001DF240, 16");
extern u16 *D_L23_0021C0E0[];
extern u8 *D_L23_001DF15C;
extern s32 D_L23_001DF198;
extern u8 D_L23_001E1A40[];
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_004561E0(void *);
extern s32 func_L01_0044C108(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_L01_0040E570(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_0038CAD0(void *);
extern s32 func_L01_0044E1B8(void *, f32);
extern s32 func_L01_004468C8(void *, s32, f32, s32, f32, f32, s32, s32, s32);
extern s32 func_L01_00446780(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);
extern void func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern f32 func_L01_004395E0(void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003C2880(void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_0045AA30(void *, void *);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_00463378(void *, void *, void *, u32, u32, s32, s32, s32, s32);
extern int func_00382380(void *, int, int);
extern void func_L23_0034DF80(f32, void *, void *, void *, void *, s32, s32);
extern void func_L23_003AF6E8();
extern void func_L23_003AFE10(u8 *);
extern void func_L23_003AFC40();
extern void func_L23_003AFAF0();
extern void func_L23_003B08E0(void *);
extern s32 func_L23_003B0110(u8 *, V4 *, f32, s32);


/* decls from earlier in L23_003AD800.c */
#include "vu0.h"
extern f32 D_L23_001DE248;
__asm__(".extern D_L23_001DE248, 4");
extern f32 D_L23_001DE220;
__asm__(".extern D_L23_001DE220, 4");
extern V4 D_L23_001E87A0;
#include "structs/hero.h"
extern struct Hero D_001A4BE0;
extern void func_L23_003AF9B8(u8 *self);
extern void func_L01_00451DF8(u8 *, void *, s32, s32, f32);
extern void *func_L01_00447490(void *, s32, s32);
extern void func_003C4A40(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D160(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_0044ABD0(void *, void *);
extern void func_L01_00404A10(void *, s32);
__asm__(".extern D_L23_001DE244, 4");
__asm__(".extern D_L23_001DE248, 4");
extern f32 D_L23_001DE244;
extern f32 D_L23_001DE248;
extern void func_L01_004450F0(void *, s32, s32);
#include "vu0.h"
__asm__(".extern D_L23_001DE250, 4");
__asm__(".extern D_L23_001DE274, 4");
extern f32 D_L23_001DE250;
extern s32 D_L23_001DE274;
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_003C2EC0(void *, s32, void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00404808(void *, void *);
void func_L23_003B0480(void *);
#include "vu0.h"
__asm__(".extern D_L23_001DE238, 4");
extern f32 D_L23_001DE238;
extern H_3AFC40 D_L23_001E8780;
__asm__(".extern D_L23_001E8780, 16");
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern s32 func_L01_003303B8(void *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern f32 D_L23_001DE224;
__asm__(".extern D_L23_001DE224, 4");
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L03_0043FC00(void *, s32, u8 *, s32, s32, f32, f32, f32, f32, u8, f32, f32, s32, s32, f32);
extern void func_L01_004443E8(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern u16 *D_L23_0021C0E0[];
extern u8 *D_L23_001DF15C;
extern s32 D_L23_001DF198;
extern void func_L01_0045AA10(void *, f32);
extern s32 func_L01_0045BD10(void *, f32);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L01_0045A748(void *, void *);
extern s32 func_L23_003B0200(u8 *, s32, f32 *, void *, void *, s32);
#include "common.h"
#include "vu0.h"
extern Paths_3B0200 *D_L23_001DED4C;
__asm__(".extern D_L23_001DED4C, 16");
extern Node_3B0200 *D_L23_001DF240;
__asm__(".extern D_L23_001DF240, 16");
extern f32 D_L23_001DE24C;
__asm__(".extern D_L23_001DE24C, 4");
extern f32 func_L01_0040E570(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern int func_00382380(void *, int, int);
__asm__(".extern D_L23_001DE288, 4");
__asm__(".extern D_L23_001DE288, 4");
__asm__(".extern D_L23_001DE28C, 4");
__asm__(".extern D_L23_001DE290, 4");
__asm__(".extern D_L23_001DE294, 4");
__asm__(".extern D_L23_001DE274, 4");
extern s32 D_L23_001DE274;
extern s32 D_L23_001DE288;
extern f32 D_L23_001DE28C;
extern f32 D_L23_001DE290;
extern s32 D_L23_001DE294;
extern void func_L01_0040A8C0(void *, void *, s32, s32, f32, f32, s32, s32, s32, s32, f32);
extern void func_L23_003B0708(void *, void *, s32, s32, s32, s32, s32, s32, s32);

/* localdecomp:start func_L23_003B08E0 */
extern s32 func_0038CAD0(void *);
f32 func_L01_0040E548(void *, void *);
void func_L01_004472C0(void *);
extern u8 D_L23_001E1A40[];

void func_L23_003B08E0(void *arg0) {
    u8 *temp_s1;
    u16 temp_v1;

    temp_s1 = *(u8 **)((u8 *)arg0 + 0x68);
    if (((*(u8 *)((u8 *)arg0 + 0x31)) != 0) && (func_L01_0040E548(D_L23_001E1A40, arg0 + 0x10) < 1024.0f)) {
        func_L01_004472C0(arg0);
        *(s8 *)((u8 *)arg0 + 0x6F) = 0x1E;
    }
    func_0038CAD0(temp_s1 + 0x214);
    temp_v1 = *(u16 *)((u8 *)arg0 + 0x96);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1 + 1);
    }
}
/* localdecomp:end func_L23_003B08E0 */

/* localdecomp:start func_L23_003B0978 */
extern u8 *func_003C24B0(s32, s32);
extern s32 D_L23_001DEC40;
__asm__(".extern D_L23_001DEC40, 16");

u8 *func_L23_003B0978(s32 a0, u128_t *pos, u128_t *target, s32 a3, s32 a4, s32 a5) {
    u8 *m = func_003C24B0(0x1BC8, 0x80);
    u8 *v;

    if (m != 0) {
        m[0x20] = 0;
        m[0x30] = 0xFF;
        v = *(u8 **)(m + 0x68);
        *(u128_t *)(m + 0x10) = *pos;
        *(u128_t *)(v + 0x10) = *target;
        *(s32 *)(v + 0) = a3;
        *(s32 *)(v + 4) = a0;
        *(s32 *)(v + 8) = D_L23_001DEC40 + 150;
        *(s32 *)(v + 0xC) = a5;
    }
    return m;
}
/* localdecomp:end func_L23_003B0978 */

/* localdecomp:start func_L23_003B0A20 */
#include "vu0.h"
#include "structs/hero.h"
extern struct Hero D_001A4BE0;
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4098(void *, void *, void *, f32);
extern void func_L01_00446748(void *, void *, s32, f32);
extern s32 func_003D4D00(void *, f32, s32, void *, void *);
extern void func_003C2880(void *);
extern void func_L01_00404808(void *, void *);
void func_L23_003B0CE0(u8 *o);


void func_L23_003B0A20(M_3B0A20 *o)
{
    Vars_3B0A20 *v = o->vars;
    V4 d;
    V4 n;
    Hit_3B0A20 hit;
    f32 t;
    V4 *pos;

    if (v->xC != 0) {
        vec_sub_ba(&d, &D_001A4BE0.pickup_point, &o->pos);
        func_0038CF68(&d, &d, func_0038CEA8(&v->pos));
        t = (f32)o->x96 / 50.333332f;
        n = v->pos;
        func_003C4098(&v->pos, &n, &d, 0.5f < t ? 0.5f : t);
    }
    pos = &o->pos;
    d = *pos;
    vec_add_ab(&n, &d, &v->pos);
    func_L01_00446748(&hit, o, 0x10003, v->xC != 0 ? 10.0f : 5.0f);
    hit.b18 = 3;
    hit.b19 = 3;
    hit.h1A = o->xAA;
    hit.x20 = 0;
    if (func_003D3CB0(&d, &n, 0, v->x4, &hit) != 0 ||
        func_003D4D00(&n, 0.2f, 0, v->x4, &hit) != 0) {
        func_L01_003303B8(pos, v->xC != 0 ? 1.0f : 0.2f, 1, 2, 0x14, 2, 0x14, 0x14, (s16)(v->xC * 8), 0.0f, 0.0f, 2.0f,
                          (s16)v->xC, (s16)v->xC, (s16)v->xC, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_003C2880(o);
        return;
    }
    *(u128_t *)pos = *(u128_t *)&n;
    o->x96++;
    if (v->x8 < D_L23_001DEC40)
        func_003C2880(o);
    else
        func_L01_00404808(func_L23_003B0CE0, o);
}
/* localdecomp:end func_L23_003B0A20 */

/* localdecomp:start func_L23_003B0CE0 */
extern s32 D_L23_001DEC40_3B0CE0;
__asm__(".extern D_L23_001DEC40_3B0CE0, 4");
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
extern void func_L01_00463378(void *, void *, void *, u32, u32, s32, s32, s32, s32);

void func_L23_003B0CE0(u8 *o)
{
    V4 pos;
    V4 dir;
    V4 *pp = &pos;
    V4 *pd = &dir;
    V4 a;
    V4 b;
    u8 *v;
    V4 *t;
    f32 s;

    *pp = *(V4 *)(o + 0x10);
    v = *(u8 **)(o + 0x68);
    t = (V4 *)(v + 0x10);
    s = 0.1f;
    if (*(s32 *)(v + 0xC) != 0)
        s = 0.5f;
    func_0038CF68(pd, t, s);
    vec_sub_ab(pd, pp, pd);
    func_L01_0040A8C0(pp, pd, 0x16, 0, 0.05f, 1.0f, 0x60606080, 0x60606080, 0x60606080, 0x60606080, 0.0f);
    func_003D9508(pd, 6, 0x80002080, 1, 0.2f, 0.0f, 0.0f);
    if (*(s32 *)(v + 0xC) != 0) {
        if (D_L23_001DEC40_3B0CE0 & 1) {
            func_0038CE20(&a, t, 0.5f);
            func_L01_00463378(pd, &a, &a, 0xFF008080, 0xFF404080, 4, 4, 4, -1);
        } else {
            qzero(&b);
            qzero(&a);
            a.w = 0.4f;
            b.z = 0.01f;
            b.w = 0.8f;
            func_L01_00463378(pd, &a, &b, 0x60406060, 0x60808080, 4, 0x11, 0x11, -1);
        }
    }
}
/* localdecomp:end func_L23_003B0CE0 */

/* localdecomp:start func_L23_003B0EC0 */
extern s32 D_L23_001DEC40_3B0EC0;
__asm__(".extern D_L23_001DEC40_3B0EC0, 4");
extern u16 **D_L23_001D6764;
__asm__(".extern D_L23_001D6764, 16");
extern u8 *D_L23_001E001C;
__asm__(".extern D_L23_001E001C, 16");
extern u8 *D_L23_001E0014;
__asm__(".extern D_L23_001E0014, 16");
extern u8 *D_L23_001E0014_3B12C8;
__asm__(".extern D_L23_001E0014_3B12C8, 4");
extern s16 D_L23_0023A3C0[];
extern f32 D_L23_001DE2A0;
__asm__(".extern D_L23_001DE2A0, 4");
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
void func_L23_003B1418(void *arg0);

void func_L23_003B0EC0(u8 *self)
{
    u8 *v = *(u8 **)(self + 0x68);
    u8 *hit;
    u16 *p;
    u16 *q;
    u8 *m;
    u8 *e;
    f32 ang;
    V4 dir;
    f32 z;
    V4 b;
    V4 a;

    if (self[0x20] == 1) {
        hit = func_L01_00447490(self, -1, 0);
        if (hit != 0) {
            *(f32 *)(v + 8) -= *(f32 *)(hit + 0x2C);
            if (*(f32 *)(v + 8) <= 0.0f)
                func_L01_004450F0(self, 2, -1);
        }
        if ((D_L23_001DEC40 & 7) == (((s32)self >> 8) & 7)) {
            p = D_L23_001D6764[*(s32 *)v];
            while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[*(s32 *)v])) {
                m = D_L23_001E001C + ((*p & 0x7FFF) << 6);
                if (m == 0)
                    break;
                if (D_L23_0023A3C0[(D_L23_001E0014_3B12C8 + ((*p & 0x7FFF) << 5))[0x1D]] == 0x1CCC &&
                    __builtin_fabsf(*(f32 *)(m + 0x38) - *(f32 *)(self + 0x18)) > 0.01f)
                    func_L01_004450F0(self, 2, -1);
                p++;
            }
        }
        func_L01_00404808(func_L23_003B1418, self);
    }
    if (self[0x20] == 2) {
        ang = func_0038D160(*(f32 *)(self + 0x10) - D_001A4BE0.pos.x, *(f32 *)(self + 0x14) - D_001A4BE0.pos.y);
        dir.x = func_0038D098(ang) * 0.3f;
        dir.y = func_0038D0B0(ang) * 0.3f;
        dir.z = 0.0f;
        dir.w = 1.0f;
        z = dir.z;
    func_L03_0043FC00(self, 0xFF, (u8 *)&dir, 3, 3, z, 5.0f, z, 1.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 1.0f);
        q = D_L23_001D6764[*(s32 *)v];
        while (q != 0 && ((s16)q[-1] >= 0 || q == D_L23_001D6764[*(s32 *)v])) {
            e = D_L23_001E0014 + ((*q & 0x7FFF) << 5);
            if (e == 0)
                break;
            if (D_L23_0023A3C0[e[0x1D]] == 0x1CCC) {
                e[0x1E] |= 4;
                break;
            }
            q++;
        }
        qzero(&a);
        qzero(&b);
        a.z = D_L23_001DE2A0;
        func_L02_003E2E38(self, &a, 5.0f, &b, 0x28, 0, 0, 0.40000004f, 2.0f, 10.0f, 1.0f);
        func_003A52A0(0, 0, self);
        func_003C2880(self);
    }
}
/* localdecomp:end func_L23_003B0EC0 */

/* localdecomp:start func_L23_003B1230 */
extern u16 **D_L23_001D6764;
__asm__(".extern D_L23_001D6764, 16");
extern u8 *D_L23_001E0014;
__asm__(".extern D_L23_001E0014, 16");
extern s16 D_L23_0023A3C0[];

s32 func_L23_003B1230(s32 idx)
{
    u16 *p = D_L23_001D6764[idx];
    u8 *e;

    while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[idx])) {
        e = D_L23_001E0014 + ((*p & 0x7FFF) << 5);
        if (e == 0)
            break;
        if (D_L23_0023A3C0[e[0x1D]] == 0x1CCC)
            return 1;
        p++;
    }
    return 0;
}
/* localdecomp:end func_L23_003B1230 */

/* localdecomp:start func_L23_003B12C8 */
extern u8 *D_L23_001E001C;
__asm__(".extern D_L23_001E001C, 16");
extern u8 *D_L23_001E0014_3B12C8;
__asm__(".extern D_L23_001E0014_3B12C8, 4");
extern f32 D_L23_001DE2A8;
__asm__(".extern D_L23_001DE2A8, 4");
extern s32 D_001A71A0[];
extern s32 func_L01_0044E7D8(s32);
extern void func_L01_0044E820(void *, s32);
extern f32 func_0038CEA8(void *);

void func_L23_003B12C8(s32 id)
{
    Moby_3B12C8 *o = (Moby_3B12C8 *)func_003C24B0(0x1BD4, 0x80);
    u8 *v;
    u16 *p;
    u8 *e;
    f32 s;

    if (o == 0)
        return;
    v = o->vars;
    *(f32 *)(v + 8) = D_L23_001DE2A8;
    *(s32 *)v = id;
    o->x20 = 1;
    o->x30 = 0xFF;
    o->x32 = 0xFF;
    func_L01_0044E820(o, func_L01_0044E7D8(D_001A71A0[0]));
    o->x34 |= 0x41;
    p = D_L23_001D6764[*(s32 *)v];
    while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[*(s32 *)v])) {
        e = D_L23_001E001C + ((*p & 0x7FFF) << 6);
        if (e == 0)
            break;
        if (D_L23_0023A3C0[(D_L23_001E0014_3B12C8 + ((*p & 0x7FFF) << 5))[0x1D]] == 0x1CCC) {
            o->pos = *(u128_t *)(e + 0x30);
            s = func_0038CEA8(e + 0x20);
            *(f32 *)(v + 4) = s;
            o->scale *= s;
            return;
        }
        p++;
    }
}
/* localdecomp:end func_L23_003B12C8 */

/* localdecomp:start func_L23_003B1418 */
#include "vu0.h"
extern void func_0038CE20(void *, void *, f32);
extern void func_003D9508(void *v, s32 id, u32 col, s32 e, f32 a, f32 b, f32 c);
__asm__(".extern D_L23_001DE2B0, 8");
__asm__(".extern D_L23_001DE2C0, 4");
__asm__(".extern D_L23_001DE2C4, 4");
__asm__(".extern D_L23_001DE2C8, 4");
extern f32 D_L23_001DE2B0[2];
extern s32 D_L23_001DE2C0;
extern u32 D_L23_001DE2C4;
extern f32 D_L23_001DE2C8;

void func_L23_003B1418(void *arg0) {
    V4 v;
    f32 *p;

    p = *(f32 **)((u8 *)arg0 + 0x68);
    if (p != 0) {
        func_0038CE20(&v, D_L23_001DE2B0, p[1]);
        vec_add_ba(&v, &v, (u8 *)arg0 + 0x10);
        func_003D9508(&v, D_L23_001DE2C0, D_L23_001DE2C4, 1, D_L23_001DE2C8, 0.3f, 0.0f);
    }
}
/* localdecomp:end func_L23_003B1418 */

/* localdecomp:start func_L23_003B1490 */
typedef struct {
    u8 pad0[0x30]; f32 f30; u8 pad34[0xA4 - 0x34]; f32 fA4;
    u8 padA8[0x110 - 0xA8]; f32 f110; f32 f114; f32 f118; u8 pad11C[0x13C - 0x11C]; f32 f13C;
    u8 pad140[0x170 - 0x140]; V4 v170; u8 pad180[4]; s16 h184;
    u8 pad186[0x300 - 0x186];
    s32 x300; s32 x304; f32 x308; s32 x30C; s32 x310; u8 pad314[8]; s32 x31C; s32 x320; f32 x324;
    f32 x328; f32 f32C; s32 x330; s32 x334; f32 f338; s32 x33C; u8 pad340[4]; f32 x344; s32 x348; f32 x34C;
    u8 pad350[0x10]; V4 v360; V4 v370; f32 f380; f32 f384; u8 pad388[4]; s32 x38C; u8 pad390[8]; s32 x398; f32 f39C;
} Vars_3B1490;
typedef struct {
    u8 pad0[0x10]; V4 pos; u8 b20; u8 pad21[0x42 - 0x21]; u8 b42; u8 b43;
    u8 pad44[4]; f32 f48; u8 pad4C[0x60 - 0x4C]; u8 b60; u8 pad61[7]; Vars_3B1490 *vars; u8 pad6C[0x94 - 0x6C];
    u8 b94; u8 b95; u16 h96; u8 pad98[0xBC - 0x98]; u8 bBC; u8 padBD[0xF8 - 0xBD]; f32 fF8;
} Moby_3B1490;
extern f32 D_L23_001DE344; __asm__(".extern D_L23_001DE344, 4");
extern f32 D_L23_001DE354; __asm__(".extern D_L23_001DE354, 4");
extern f32 D_L23_001DE358; __asm__(".extern D_L23_001DE358, 4");
extern s32 D_L23_001DE2D4; __asm__(".extern D_L23_001DE2D4, 4");
extern s32 D_L23_001DE35C; __asm__(".extern D_L23_001DE35C, 4");
extern s32 D_L23_001DE360; __asm__(".extern D_L23_001DE360, 4");
extern s32 D_L23_001DE364; __asm__(".extern D_L23_001DE364, 4");
extern s32 D_L23_001DE368; __asm__(".extern D_L23_001DE368, 4");
extern f32 D_L23_001DE3A0; __asm__(".extern D_L23_001DE3A0, 4");
extern f32 D_L23_001DE328; __asm__(".extern D_L23_001DE328, 4");
extern f32 D_L23_001DE33C; __asm__(".extern D_L23_001DE33C, 4");
extern f32 D_L23_001DE340; __asm__(".extern D_L23_001DE340, 4");
extern f32 D_L23_001DE348; __asm__(".extern D_L23_001DE348, 4");
extern s32 D_L23_001DE34C; __asm__(".extern D_L23_001DE34C, 4");
extern f32 D_L23_001DE350; __asm__(".extern D_L23_001DE350, 4");
extern f32 D_L23_001DE36C; __asm__(".extern D_L23_001DE36C, 4");
extern s32 D_L23_001DE370; __asm__(".extern D_L23_001DE370, 4");
extern f32 D_L23_001DE374; __asm__(".extern D_L23_001DE374, 4");
extern f32 D_L23_001DE378; __asm__(".extern D_L23_001DE378, 4");
extern f32 D_L23_001DE37C; __asm__(".extern D_L23_001DE37C, 4");
extern f32 D_L23_001DE380; __asm__(".extern D_L23_001DE380, 4");
extern s32 D_L23_001DE384; __asm__(".extern D_L23_001DE384, 4");
extern f32 D_L23_001DE388; __asm__(".extern D_L23_001DE388, 4");
extern s32 D_L23_001DE38C; __asm__(".extern D_L23_001DE38C, 4");
extern s32 D_L23_001DE390; __asm__(".extern D_L23_001DE390, 4");
extern f32 D_L23_001DE394; __asm__(".extern D_L23_001DE394, 4");
extern f32 D_L23_001DE398; __asm__(".extern D_L23_001DE398, 4");
extern s32 D_L23_001DE39C; __asm__(".extern D_L23_001DE39C, 4");
extern u8 *D_001A73E8[];
extern f32 func_0038CED8(void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_00382580(void *, f32, f32);
extern void func_003C4098(void *, void *, void *, f32);
extern void *func_L23_00456AA8(V4 *, V4 *, f32, s32, s32, s32);
extern void *func_L23_003BB7C8(s32 arg0, u128_t *pos, u128_t *arg2, f32 scale, s32 arg3, f32 arg5);
extern void func_L01_003A9928(u8 *obj);
extern void func_L23_003B3908(void *arg0);
extern void func_L23_003B34F8(u8 *self);
extern void func_L23_003B3BB8(void *m, V4 *target, f32 speed, s32 mode);
extern void func_L23_003B4108(V4 *out, u8 *self, s32 idx, V4 from, f32 r1, f32 r2);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_L01_00443A18(f32, f32);

void func_L23_003B1490(Moby_3B1490 *m) {
    Vars_3B1490 *v;
    V4 w[6];

    v = m->vars;
    func_L23_003B34F8((u8 *)m);
    switch (m->b95) {
    case 1:
        break;
    case 2:
        if (v->x300 != 3) {
            func_L01_004450F0(m, 3, -1);
        }
        break;
    case 3:
        if (v->x30C == 3) {
            if (v->x300 == 3) {
                f32 d;
                V4 *p = &v->v170;
                *p = *(V4 *)&D_001A4BE0.pos;
                func_003C2F58(m, (v->x304 & 1) ^ 1, &w[0]);
                d = func_0038CF38(&w[0], p);
                v->x344 = -func_0038D160(d, v->v170.z - w[0].z);
            } else {
                f32 t = func_0038CF38(&D_001A4BE0.pos, &m->pos) / D_L23_001DE344;
                t *= v->x398 ? D_L23_001DE358 : D_L23_001DE354;
                func_0038CE20(&w[0], &D_001A4BE0.vel, t);
                vec_add_ba(&v->v170, &w[0], &D_001A4BE0.pickup_point);
            }
        }
        break;
    }
    switch (m->b20) {
    case 1: {
        f32 a;
        u8 b;
        if (func_L01_004561B8(m) != 0) {
            if (m->b43 != 0) {
                func_003C3A10(m, 0, 0, 8);
            }
            v->x31C = 0;
            v->x308 = m->fF8;
            v->v360 = m->pos;
            v->x300 = 0;
        } else if (v->x31C == 8) {
            if (m->b43 != 1) {
                func_003C3A10(m, 1, 0, 8);
            }
            v->x300 = 0;
        } else if ((b = m->b43) == 1 && func_L01_0044E1B8(m, 100.0f) != 0) {
            v->v360.x = func_0038D098(func_0038D160(D_001A4BE0.pos.x - m->pos.x, D_001A4BE0.pos.y - m->pos.y)) * 10.0f;
            v->v360.y = func_0038D0B0(func_0038D160(D_001A4BE0.pos.x - m->pos.x, D_001A4BE0.pos.y - m->pos.y)) * 10.0f;
            v->v360.z = 0.0f;
            vec_add_ab(&v->v360, &v->v360, &m->pos);
            v->x308 = func_0038D160(D_001A4BE0.pos.x - v->v360.x, D_001A4BE0.pos.y - v->v360.y);
            v->x300 = b;
            if (m->b43 != 13) {
                func_003C3A10(m, 13, 0, 17);
            }
        } else if (v->x31C == 0xFA) {
            v->v360 = m->pos;
            v->x308 = func_0038D160(D_001A4BE0.pos.x - m->pos.x, D_001A4BE0.pos.y - m->pos.y);
            v->x300 = 0;
            if (m->b43 != 2) {
                func_003C3A10(m, 2, 0, 8);
            }
        } else if (m->b43 == 2 && func_L01_0044E1B8(m, 78.0f) != 0) {
            v->x300 = 0;
            if (m->b43 != 0) {
                func_003C3A10(m, 0, 0, 8);
            }
        }
        func_L23_003B3BB8(m, &v->v360, v->x308, v->x300);
        break;
    }
    case 2: {
        f32 d1, d2, a, b, c, s;
        Node_3B0200 *n;
        if (func_L01_004561B8(m) != 0 && m->b43 != 4) {
            func_003C3A10(m, 4, 0, 5);
        }
        d1 = func_L01_0040E570(&v->v360, &D_001A4BE0.pos);
        d2 = func_L01_0040E570(&m->pos, &D_001A4BE0.pos);
        if (d1 < 6400.0f) {
            vec_sub_ab(&w[0], &D_001A4BE0.pos, &D_L23_001DF240[v->x320].pos);
            a = func_0038D160(w[0].x, w[0].y);
            vec_sub_ab(&w[1], &m->pos, &D_L23_001DF240[v->x320].pos);
            b = func_0038D160(w[1].x, w[1].y);
            if (func_0038DBA0(b, a) < 0.0f) {
                c = func_0038DB00(a, 2.0943952f);
            } else {
                c = func_0038DAB8(a, 2.0943952f);
            }
            v->v360.x = func_0038D098(c) * (100.0f - func_0038CEA8(&w[0]));
            v->v360.y = func_0038D0B0(c) * (100.0f - func_0038CEA8(&w[0]));
            v->v360.z = 0.0f;
            vec_add_ba(&v->v360, &v->v360, &D_L23_001DF240[v->x320].pos);
        }
        if (d2 < 900.0f) {
            if (m->b43 != 6) {
                func_003C3A10(m, 6, 0, 25);
            }
            v->x308 = func_0038D160(D_001A4BE0.pos.x - m->pos.x, D_001A4BE0.pos.y - m->pos.y);
        } else if (v->f13C > v->fA4) {
            if (m->b43 != 5) {
                func_003C3A10(m, 5, 0, 25);
            }
            v->x308 = func_0038D160(v->v360.x - m->pos.x, v->v360.y - m->pos.y);
        } else {
            if (m->b43 != 4) {
                func_003C3A10(m, 4, 0, 8);
            }
            v->x308 = func_0038D160(D_001A4BE0.pos.x - m->pos.x, D_001A4BE0.pos.y - m->pos.y);
        }
        func_L23_003B3BB8(m, &v->v360, v->x308, 3);
        break;
    }
    case 3:
        if (func_L01_004561B8(m) != 0) {
            if (m->b43 != 3) {
                func_003C3A10(m, 3, 0, 8);
            }
            v->x300 = 0;
            v->x328 = 0.0f;
            v->x304 = 0;
            v->x30C = 0;
            v->x34C = 0;
            v->x334 = 0;
        }
        if (func_L01_0044E1B8(m, 8.0f) != 0) {
            v->x300 = 3;
            v->x324 = D_L23_001DE3A0;
        }
        if (m->b42 == m->b43 && (m->b60 & 2)) {
            if (m->b43 != 4) {
                func_003C3A10(m, 4, 0, 5);
            }
            if (m->b94 == 6) {
                func_L01_004450F0(m, 6, -1);
            } else if (m->b94 == 5) {
                func_L01_004450F0(m, 5, -1);
            } else {
                switch (m->b95) {
                case 1: func_L01_004450F0(m, 1, -1); break;
                case 2: func_L01_004450F0(m, 2, -1); break;
                case 3: func_L01_004450F0(m, 7, -1); break;
                default: func_L01_004450F0(m, 1, 1); break;
                }
            }
        }
        func_L23_003B3BB8(m, &m->pos, m->fF8, v->x300);
        break;
    case 4: {
        f32 a;
        if (m->h96 >= 0x97 || func_L01_004561B8(m) != 0) {
            w[0] = m->pos;
            func_L23_003B4108(&v->v360, (u8 *)m, v->x310, w[0], 30.0f, 50.0f);
            m->h96 = 0;
            v->x34C = 0;
            v->x334 = 0;
        }
        a = func_0038D160(D_001A4BE0.pos.x - m->pos.x, D_001A4BE0.pos.y - m->pos.y);
        v->x308 = a;
        if (m->b43 != 26) {
            if (func_L01_0040E570(&m->pos, &v->v360) < v->fA4 * v->fA4) {
                if (m->b43 != 26) {
                    func_003C3A10(m, 26, 0, 5);
                }
            } else {
                v->x300 = 3;
                if (1.5707964f < fabs_asm(func_0038DBA0(func_0038D160(v->v360.x - m->pos.x, v->v360.y - m->pos.y), v->x308))) {
                    if (m->b43 != 6) {
                        func_003C3A10(m, 6, 0, 8);
                    }
                } else if (m->b43 != 5) {
                    func_003C3A10(m, 5, 0, 8);
                }
            }
            func_L23_003B3BB8(m, &v->v360, v->x308, 3);
        } else if (m->b42 == m->b43) {
            f32 f = func_L01_004395E0(m);
            if (f <= 5.0f) {
                v->x328 = func_003C4088(0.0f, v->f39C, 1.0f - (f / 5.0f) * (f / 5.0f));
                w[0] = m->pos;
                w[0].z = v->v370.z + v->x328;
                vec_sub_ba(&w[0], &w[0], &m->pos);
                func_L01_0045AA30(m, &w[0]);
            } else {
                func_L23_003B3BB8(m, &m->pos, m->fF8, 0);
            }
            if (func_L01_0044E1B8(m, 5.0f) != 0) {
                u8 *q = D_L23_001E1A40;
                *(f32 *)(q + 0x20) = 0.3f;
                *(s32 *)(q + 0x28) = 0x21;
                *(s32 *)(q + 0x2C) = 0;
            }
            if (m->b60 & 2) {
                if (m->b43 != 0) {
                    func_003C3A10(m, 0, 0, 5);
                }
                switch (m->b95) {
                case 1: func_L01_004450F0(m, 1, -1); break;
                case 2: func_L01_004450F0(m, 2, -1); break;
                case 3: func_L01_004450F0(m, 7, -1); break;
                default: func_L01_004450F0(m, 1, 1); break;
                }
            }
        } else {
            func_L23_003B3BB8(m, &v->v360, a, 3);
        }
        break;
    }
    case 5:
        v->v360 = *(V4 *)&D_001A4BE0.pos;
        v->x308 = func_0038D160(D_001A4BE0.pos.x - m->pos.x, D_001A4BE0.pos.y - m->pos.y);
        if (v->x300 == 3) {
            if (1.5707964f < fabs_asm(func_0038DBA0(func_0038D160(v->v360.x - m->pos.x, v->v360.y - m->pos.y), v->x308))) {
                if (m->b43 != 6) {
                    func_003C3A10(m, 6, 0, 8);
                }
            } else if (m->b43 != 5) {
                func_003C3A10(m, 5, 0, 8);
            }
        } else if (v->h184 == 0 && m->h96 >= 0x33) {
            func_L01_004450F0(m, 3, -1);
        } else {
            v->x300 = 2;
            if (m->b43 != 20) {
                func_003C3A10(m, 20, 0, 8);
            }
        }
        func_L23_003B3BB8(m, &v->v360, v->x308, v->x300);
        if (func_L01_0040E570(&m->pos, &D_001A4BE0.pos) <= v->f32C * v->f32C) {
            func_L01_004450F0(m, 7, -1);
        }
        break;
    case 6:
        if (v->x300 != 3) {
            func_L01_004450F0(m, 3, -1);
            break;
        }
        if (func_L01_004561B8(m) != 0) {
            f32 r, c;
            if (m->b43 != 6) {
                func_003C3A10(m, 6, 0, 8);
            }
            v->v360.x = func_0038D098(func_0038DAB8(func_L01_00443A18(0.0f, 1.0471976f), func_0038D160(m->pos.x - D_001A4BE0.pos.x, m->pos.y - D_001A4BE0.pos.y))) * v->f32C;
            v->v360.y = func_0038D0B0(func_0038DAB8(func_L01_00443A18(0.0f, 1.0471976f), func_0038D160(m->pos.x - D_001A4BE0.pos.x, m->pos.y - D_001A4BE0.pos.y))) * v->f32C;
            v->v360.z = 0.0f;
            vec_add_ab(&v->v360, &v->v360, &D_001A4BE0.pos);
            v->x308 = func_0038D160(D_001A4BE0.pos.x - m->pos.x, D_001A4BE0.pos.y - m->pos.y);
        }
        func_L23_003B3BB8(m, &v->v360, v->x308, 3);
        if (func_L01_0040E570(&m->pos, &v->v360) <= v->fA4 * v->fA4 || m->h96 >= 0xFB) {
            func_L01_004450F0(m, 7, -1);
        }
        break;
    case 7: {
        f32 d;
        if (v->x304 == 0 && func_L01_004561B8(m) != 0) {
            if (v->x300 == 3) {
                if (v->x334 != 0) {
                    if (m->b43 != 8) func_003C3A10(m, 8, 0, 5);
                } else {
                    if (m->b43 != 4) func_003C3A10(m, 4, 0, 5);
                }
            } else if (v->x334 != 0) {
                if (m->b43 != 15) func_003C3A10(m, 15, 0, 5);
            } else {
                if (m->b43 != 0) func_003C3A10(m, 0, 0, 5);
            }
        }
        func_L23_003B3BB8(m, &m->pos, func_0038D160(v->v170.x - m->pos.x, v->v170.y - m->pos.y), v->x300 == 3 ? 3 : 0);
        d = func_L01_0040E570(&m->pos, &D_001A4BE0.pos);
        if (v->x30C == 3 && d < 196.0f) {
            v->x304 = 0;
        }
        if (100.0f < d) {
            v->x38C = 0;
        }
        if (v->x30C == 1 && v->x38C >= 3) {
            v->x304 = 0;
            v->f32C = 30.0f;
            func_L01_004450F0(m, 6, -1);
            break;
        }
        if (v->x304 <= 0) {
            if (D_L23_001DE2D4 < 0) {
                if (v->x300 == 3) {
                    if (v->x30C == 0) {
                        v->x304 = v->x398 ? D_L23_001DE368 : D_L23_001DE364;
                        v->x30C = 3;
                    } else {
                        func_L01_004450F0(m, 4, -1);
                        v->x30C = 0;
                    }
                    break;
                } else if (d < 100.0f && v->x30C != 1) {
                    v->x304 = v->x398 ? func_00382498(2, 4) : 2;
                    v->x30C = 1;
                } else if (196.0f <= d && v->x30C != 3) {
                    v->x304 = v->x398 ? D_L23_001DE360 : D_L23_001DE35C;
                    v->x30C = 3;
                } else if (v->x330 > 0) {
                    v->x304 = 2;
                    v->x30C = 1;
                } else if (v->x398 != 0) {
                    v->x304 = 1;
                    v->x30C = 2;
                } else {
                    v->x304 = 2;
                    v->x30C = 1;
            }
            } else {
                v->x30C = D_L23_001DE2D4;
            }
        }
        if (v->x30C == 3) {
            if (d < 196.0f) {
                v->f32C = 30.0f;
                if (v->x334 != 0) {
                    func_L01_004450F0(m, 9, -1);
                } else {
                    func_L01_004450F0(m, 6, -1);
                }
            } else if (2500.0f < d) {
                v->f32C = 30.0f;
                if (v->x334 != 0) {
                    func_L01_004450F0(m, 9, -1);
                } else {
                    func_L01_004450F0(m, 5, -1);
                }
            } else if (v->x334 == 0) {
                func_L01_004450F0(m, 8, -1);
            } else {
                func_L01_004450F0(m, 10, -1);
            }
        } else if (v->x30C == 2) {
            if (v->x334 != 0) {
                func_L01_004450F0(m, 9, -1);
            } else if (d < 100.0f) {
                v->f32C = 16.0f;
                func_L01_004450F0(m, 6, -1);
            } else if (324.0f < d) {
                v->f32C = 16.0f;
                func_L01_004450F0(m, 5, -1);
            } else if (v->x300 == 3) {
                func_L01_004450F0(m, 4, -1);
            } else {
                func_L01_004450F0(m, 12, -1);
            }
        } else if (v->x30C == 1) {
            if (v->x334 != 0) {
                func_L01_004450F0(m, 9, -1);
            } else if (100.0f < d) {
                v->f32C = 9.0f;
                func_L01_004450F0(m, 5, -1);
            } else if (v->x300 == 3) {
                func_L01_004450F0(m, 4, -1);
            } else {
                func_L01_004450F0(m, 11, -1);
            }
        }
        break;
    }
    case 8:
        if (func_L01_004561B8(m) != 0) {
            if (v->x300 == 3) {
                if (m->b43 != 7) func_003C3A10(m, 7, 0, 5);
            } else {
                if (m->b43 != 14) func_003C3A10(m, 14, 0, 5);
            }
        }
        if (m->b42 == m->b43 && (m->b60 & 2)) {
            if (v->x300 == 3) {
                if (m->b43 != 8) func_003C3A10(m, 8, 0, 5);
            } else {
                if (m->b43 != 15) func_003C3A10(m, 15, 0, 5);
            }
            v->x334 = 1;
            func_L01_004450F0(m, 7, -1);
        }
        func_L23_003B3BB8(m, &m->pos, func_0038D160(v->v170.x - m->pos.x, v->v170.y - m->pos.y), v->x300 == 3 ? 3 : 0);
        break;
    case 9:
        if (func_L01_004561B8(m) != 0) {
            if (v->x300 == 3) {
                if (m->b43 != 11) func_003C3A10(m, 11, 0, 5);
            } else {
                if (m->b43 != 18) func_003C3A10(m, 18, 0, 5);
            }
        }
        if (m->b42 == m->b43 && (m->b60 & 2)) {
            if (v->x300 == 3) {
                if (m->b43 != 4) func_003C3A10(m, 4, 0, 5);
            } else {
                if (m->b43 != 0) func_003C3A10(m, 0, 0, 5);
            }
            v->x334 = 0;
            func_L01_004450F0(m, 7, -1);
        }
        func_L23_003B3BB8(m, &m->pos, func_0038D160(v->v170.x - m->pos.x, v->v170.y - m->pos.y), v->x300 == 3 ? 3 : 0);
        break;
    case 10:
        if (func_L01_004561B8(m) != 0) {
            if (v->x300 == 3) {
                if (v->x304 & 1) {
                    if (m->b43 != 10) func_003C3A10(m, 10, 0, 5);
                } else {
                    if (m->b43 != 9) func_003C3A10(m, 9, 0, 5);
                }
            } else if (v->x304 & 1) {
                if (m->b43 != 17) func_003C3A10(m, 17, 0, 5);
            } else {
                if (m->b43 != 16) func_003C3A10(m, 16, 0, 5);
            }
            m->f48 = v->x398 ? 2.0f : 1.5f;
        }
        {
            f32 f = func_L01_004395E0(m);
            if (f < 47.0f || 52.0f < f) {
                func_L23_003B3BB8(m, &m->pos, func_0038D160(v->v170.x - m->pos.x, v->v170.y - m->pos.y), v->x300 == 3 ? 3 : 0);
            } else {
                func_L23_003B3BB8(m, &m->pos, m->fF8, v->x300 == 3 ? 3 : 0);
            }
        }
        if (func_L01_0044E1B8(m, 47.0f) != 0) {
            func_003C2EC0(m, (v->x304 & 1) ^ 1, &w[2]);
            w[0] = w[5];
            if (v->x300 == 3) {
                f32 l;
                vec_sub_ba(&w[1], &v->v170, &w[0]);
                l = func_0038CED8(&w[1]);
                w[1].x = func_0038D098(m->fF8) * l;
                w[1].y = func_0038D0B0(m->fF8) * l;
                func_0038CF68(&w[1], &w[1], D_L23_001DE344);
            } else {
                w[1].x = func_0038D098(m->fF8) * D_L23_001DE344;
                w[1].y = func_0038D0B0(m->fF8) * D_L23_001DE344;
                w[1].z = 0.0f;
            }
            func_L23_003BB7C8((s32)m, (u128_t *)&w[0], (u128_t *)&w[1], D_L23_001DE348, D_L23_001DE34C, D_L23_001DE350);
            v->x34C = 0.0f;
        }
        if (func_L01_0044E1B8(m, 64.0f) != 0) {
            v->x304 = v->x304 - 1;
            func_L01_004450F0(m, 7, -1);
        }
        break;
    case 11: {
        f32 f;
        u8 *hero;
        if (func_L01_004561B8(m) != 0) {
            if (v->x304 & 1) {
                if (m->b43 != 21) func_003C3A10(m, 21, 0, 5);
            } else {
                if (m->b43 != 22) func_003C3A10(m, 22, 0, 5);
            }
            m->f48 = v->x398 ? 2.0f : 1.5f;
        }
        f = func_L01_004395E0(m);
        if (23.0f <= f && f <= 26.0f) {
            if (v->x304 & 1) {
                func_L01_004468C8((u8 *)m, 4, D_L23_001DE36C, D_L23_001DE370, D_L23_001DE374, 1.0f, 0, 1, 0);
            } else {
                func_L01_004468C8((u8 *)m, 3, D_L23_001DE36C, D_L23_001DE370, D_L23_001DE374, 1.0f, 0, 1, 0);
            }
        }
        hero = (u8 *)&D_001A4BE0;
        if (*(Moby_3B1490 **)(hero + 0x2808) == m) {
            v->x38C++;
            *(s32 *)(hero + 0x2808) = 0;
            if (v->x38C >= 3) {
                v->x304 = 1;
            }
        }
        if (23.0f <= f && f <= 25.0f) {
            v->f110 = func_0038D098(m->fF8) * (D_L23_001DE378 * (f - 23.0f) * 0.5f);
            v->f114 = func_0038D0B0(m->fF8) * (D_L23_001DE378 * (f - 23.0f) * 0.5f);
            v->f118 = 0.0f;
        }
        if (func_L01_0044E1B8(m, 43.0f) != 0) {
            m->f48 = 1.0f;
            v->x304 = v->x304 - 1;
            func_L01_004450F0(m, 7, -1);
            v->x34C = 0.0f;
        }
        if (v->x398 != 0) {
            func_L23_003B3BB8(m, &m->pos, func_0038D160(v->v170.x - m->pos.x, v->v170.y - m->pos.y), 0);
        } else {
            func_L23_003B3BB8(m, &m->pos, m->fF8, 0);
        }
        break;
    }
    case 12: {
        s32 i, j;
        u8 *hero;
        if (func_L01_004561B8(m) != 0) {
            m->bBC = 1;
            if (m->b43 != 23) func_003C3A10(m, 23, 0, 5);
            D_001A73E8[0] = 0;
            v->x348 = 0;
        }
        if (m->b42 == m->b43 && (m->b60 & 2) && m->bBC == 1) {
            v->x330 = D_L23_001DE390;
            m->bBC = 2;
            if (m->b43 != 24) func_003C3A10(m, 24, 0, 0);
        }
        if (m->bBC == 2) {
            f32 k = 15.0f;
            func_003C2EC0(m, 2, &w[0]);
            hero = (u8 *)&D_001A4BE0;
            for (i = 0; i < 4; i++) {
                f32 t = (f32)(D_L23_001DE390 - v->x330) / 50.0f;
                f32 r = (f32)((D_L23_001DEC40 + i * 4) % 16);
                f32 s, g;
                s = (1.0f < t ? r : t * r) / k;
                func_0038CE20(&w[4], &w[0], D_L23_001DE37C - D_L23_001DE380);
                w[4].z = 0.0f;
                vec_add_ab(&w[4], &w[4], &w[3]);
                w[5] = w[3];
                func_003C4098(&w[4], &w[5], &w[4], s);
                g = func_003C4088(1.0f, D_L23_001DE380, s);
                if (v->x348 == 0 &&
                    func_L01_00446780((u8 *)m, (u8 *)&w[4], D_L23_001DE384, 5, 1, 0, g, D_L23_001DE388, 0.0f) != 0 &&
                    *(Moby_3B1490 **)(hero + 0x2808) == m) {
                    v->x348 = 1;
                    v->x330 -= 50;
                }
            }
            for (j = 0; j < D_L23_001DE39C; j++) {
                f32 t, a, rad;
                w[4] = w[3];
                t = (f32)(D_L23_001DE390 - v->x330) / 17.0f;
                a = func_003824E0(0.0f, 1.0f < t ? 1.0f : t);
                rad = D_L23_001DE398;
                func_00382580(&w[5], 0.0f, rad);
                w[5].x += w[0].x;
                w[5].y += w[0].y;
                func_0038CF68(&w[5], &w[5], D_L23_001DE394);
                func_L23_00456AA8(&w[4], &w[5], (a * 0.5f + 0.5f) * 4.0f, (s32)(a * 42.0f), func_00382498(17, 25), func_00382498(17, 25));
            }
            if (v->x330 <= 0) {
                m->bBC = 3;
                if (m->b43 != 25) func_003C3A10(m, 25, 0, 5);
            }
        }
        if (m->b42 == m->b43 && (m->b60 & 2) && m->bBC == 3) {
            if (m->b43 != 0) func_003C3A10(m, 0, 0, 5);
            v->x304 = v->x304 - 1;
            v->x330 = D_L23_001DE38C;
            func_L01_004450F0(m, 7, -1);
            v->x34C = 0.0f;
        }
        func_L23_003B3BB8(m, &m->pos, m->fF8, 0);
        break;
    }
    case 13: {
        f32 f, c;
        if (func_L01_004561B8(m) != 0) {
            if (v->x300 == 3) {
                if (m->b43 != 12) func_003C3A10(m, 12, 0, 3);
            } else {
                if (m->b43 != 19) func_003C3A10(m, 19, 0, 3);
                m->f48 = 2.0f;
            }
            v->x34C += v->f338 - v->f30;
            v->f338 = v->f30;
            v->x30C = -1;
            v->x304 = 0;
            if (m->b94 == 12) {
                v->x330 = D_L23_001DE38C;
            }
        }
        c = v->f380 < D_L23_001DE33C ? v->f380 : D_L23_001DE33C;
        v->f380 -= c;
        w[0].x = func_0038D098(v->f384) * c;
        w[0].y = func_0038D0B0(v->f384) * c;
        w[0].z = 0.0f;
        func_L01_0045AA30(m, &w[0]);
        w[1].x = func_0038D098(v->f384) * D_L23_001DE328;
        w[1].y = func_0038D0B0(v->f384) * D_L23_001DE328;
        w[1].z = 0.0f;
        vec_add_ba(&w[1], &w[1], &m->pos);
        w[1].z += D_L23_001DE328;
        func_L01_00446780((u8 *)m, (u8 *)&w[1], D_L23_001DE370, 0, 1, 0, D_L23_001DE328, 100.0f, 1.0f);
        v->x33C = D_L23_001DEC40 + 2;
        if ((m->b43 == 19 && func_L01_0044E1B8(m, 18.0f) != 0) || (m->b60 & 2)) {
            m->f48 = 1.0f;
            switch (m->b95) {
            case 1: func_L01_004450F0(m, 1, -1); break;
            case 2: func_L01_004450F0(m, 2, -1); break;
            case 3:
                if (v->x300 == 3) {
                    func_L01_004450F0(m, 7, -1);
                } else if (v->x34C >= D_L23_001DE340) {
                    v->f32C = 30.0f;
                    func_L01_004450F0(m, 6, -1);
                } else {
                    func_L01_004450F0(m, m->b94, -1);
                }
                break;
            }
        }
        func_L23_003B3BB8(m, &m->pos, m->fF8, v->x300 == 3 ? 3 : 0);
        break;
    }
    case 14:
        if (func_L01_004561B8(m) != 0) {
            if (m->b43 != 27) func_003C3A10(m, 27, 0, 8);
        } else if (func_L01_0044E1B8(m, 84.0f) != 0) {
            m->f48 = 0.0f;
            func_L01_003A9928((u8 *)m);
        }
        break;
    }
    func_L23_003B3908(m);
}
/* localdecomp:end func_L23_003B1490 */

/* localdecomp:start func_L23_003B34F8 */
/* MATCH with --no-context --as ps2as. Needs L23_003AD800.c line 58 changed to
   extern void *func_L01_00447490(void *, s32, s32);  (s32 as in every other file; u32 makes -1 a lui/ori). */
#include "vu0.h"
#include "structs/hero.h"
extern struct Hero D_001A4BE0;
extern s32 D_L23_001DEC40;
__asm__(".extern D_L23_001DEC40, 16");
extern struct Moby *D_L23_001E8798[];
extern V4 D_L23_001E87A0;
__asm__(".extern D_L23_001E87A0, 16");
extern f32 D_L23_001DE338;
__asm__(".extern D_L23_001DE338, 4");
extern f32 D_L23_001DE328;
__asm__(".extern D_L23_001DE328, 4");
extern f32 D_L23_001DE32C;
__asm__(".extern D_L23_001DE32C, 4");
extern s32 D_L23_001DE2D8;
__asm__(".extern D_L23_001DE2D8, 4");
extern void *func_L01_00447490(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C4A40(void *a, void *b);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern void func_L01_0044ABD0(void *a, void *b);
extern void func_L01_00404A10(void *, s32);
extern void func_L03_0043BE98(int, void *, int, int, int);
extern void func_L01_00404808(void *, void *);
void func_L23_003B3998(u8 *self);
void func_L23_003B44F8(u8 *self);
void func_L23_003B48D0(void *self);


void func_L23_003B34F8(u8 *self)
{
    u8 *v = *(u8 **)(self + 0x68);
    u8 *hit;
    s32 n;
    f32 d;
    f32 len;
    V4 dir;
    V4 a;
    V4 b;

    if (self[0x20] == 0)
        func_L23_003B3998(self);
    hit = func_L01_00447490(self, -1, 0);
    if (hit != 0) {
        if (D_L23_001DEC40 >= *(s32 *)(v + 0x33C) && *(f32 *)(hit + 0x2C) > 2.0f) {
            n = (s32)*(f32 *)(hit + 0x2C) >> 1;
            if (n > 20)
                n = 20;
            *(s32 *)(v + 0x33C) = D_L23_001DEC40 + n;
            *(f32 *)(v + 0x30) -= *(f32 *)(hit + 0x2C);
            v[0x167] = 0xFF;
            func_003C4A40(self, v + 0x160);
            d = *(f32 *)(v + 0x338) - *(f32 *)(v + 0x30);
            if (*(s32 *)(v + 0x398) != 0 ? d >= 50.0f : d >= 35.0f) {
                if (self[0x20] != 3) {
                    if (self[0x20] != 4) {
                    if (*(f32 *)(hit + 0x2C) >= 35.0f && *(u8 **)(hit + 0x20) != 0) {
                        vec_sub_ba(&dir, self + 0x10, *(u8 **)(hit + 0x20) + 0x10);
                        dir.z = 0.0f;
                        func_0038CF68(&dir, &dir, D_L23_001DE338 + D_L23_001DE328);
                        a = *(V4 *)(self + 0x10);
                        a.z += 1.0f;
                        vec_add_ab(&b, &a, &dir);
                        if (func_003D3CB0(&a, &b, 0, self, 0) != 0) {
                            vec_sub_ba(&dir, &D_L23_001E87A0, self + 0x10);
                            dir.z = 0.0f;
                            len = func_0038CEA8(&dir);
                            if (len > D_L23_001DE328)
                                func_0038CE20(&dir, &dir, (len - D_L23_001DE328) / len);
                            else
                                qzero(&dir);
                        } else {
                            func_0038CE20(&dir, &dir, D_L23_001DE338 / (D_L23_001DE338 + D_L23_001DE328));
                        }
                        *(f32 *)(v + 0x380) = func_0038CEA8(&dir);
                        *(f32 *)(v + 0x384) = func_0038D160(dir.x, dir.y);
                    }
                    func_L01_004450F0(self, 0xD, -1);
                    }
                }
            }
        }
        self[0xA8] = 0xFF;
    }
    func_L01_0044ABD0(self, v + 0x160);
    func_L01_00404A10(self, 3);
    if (self[0x20] != 0xE && *(f32 *)(v + 0x30) < 0.0f) {
        if (*(s32 *)(v + 0x300) == 3) {
            *(f32 *)(v + 0x30) = 1.0f;
            func_L01_004450F0(self, 4, 3);
        } else {
            func_L01_004450F0(self, 0xE, 4);
        }
    }
    ((Vars_3B34F8 *)v)->target = D_001A4BE0.hero_moby;
    dir = *(V4 *)(self + 0x10);
    a = *(V4 *)&D_001A4BE0.pickup_point;
    dir.z += D_L23_001DE32C;
    if (func_003D3CB0(&dir, &a, 0, self, 0) == 0 || D_L23_001E8798[0] == D_001A4BE0.hero_moby)
        *(s16 *)(v + 0x184) = 1;
    else
        *(s16 *)(v + 0x184) = 0;
    func_L23_003B44F8(self);
    if (self[0x95] == 3) {
        *(V4 *)(v + 0x190) = *(V4 *)&D_001A4BE0.pos;
        *(f32 *)(v + 0x198) += 5.0f;
        func_L03_0043BE98((int)self, v + 0x190, 5, 6, 1);
    } else {
        func_L03_0043BE98((int)self, v + 0x190, 5, 6, 0);
    }
    if (D_L23_001DE2D8 != 0)
        func_L01_00404808(func_L23_003B48D0, self);
}
/* localdecomp:end func_L23_003B34F8 */

/* localdecomp:start func_L23_003B3908 */
extern s32 func_0038CAD0(void *);
f32 func_L01_0040E548(void *, void *);
void func_L01_004472C0(void *);
extern u8 D_L23_001E1A40[];

void func_L23_003B3908(void *arg0) {
    void *temp_s1;

    temp_s1 = *(void **)((u8 *)arg0 + 0x68);
    if (((*(u8 *)((u8 *)arg0 + 0x31)) != 0) && (func_L01_0040E548(D_L23_001E1A40, arg0 + 0x10) < 9216.0f)) {
        func_L01_004472C0(arg0);
        *(s8 *)((u8 *)arg0 + 0x6F) = 0x5A;
    }
    *(u16 *)((u8 *)arg0 + 0x96) = (u16) ((*(u16 *)((u8 *)arg0 + 0x96)) + 1);
    *(s32 *)((u8 *)temp_s1 + 0x31C) = (s32) ((*(s32 *)((u8 *)temp_s1 + 0x31C)) + 1);
    func_0038CAD0(temp_s1 + 0x330);
}
/* localdecomp:end func_L23_003B3908 */

/* localdecomp:start func_L23_003B3998 */
/* MATCH */
extern u16 D_L23_001DE330;
__asm__(".extern D_L23_001DE330, 4");
extern f32 D_L23_001DE328;
__asm__(".extern D_L23_001DE328, 4");
extern s32 D_L23_001DDFA0;

extern f32 func_003C3D30(void *, s32, s32, f32);

void func_L23_003B3998(u8 *self)
{
    Vars_3B3998 *v = *(Vars_3B3998 **)(self + 0x68);
    f32 f;
    f32 s;

    v->x58 = 0x14;
    v->x5A = 0xE;
    if (v->x34 == 0)
        v->x34 = D_L23_001DE330;
    if (D_L23_001DDFA0 > 0) {
        f = 1.0f - D_L23_001DDFA0 * 0.1f;
        if (f > 0.25f)
            s = f;
        else
            s = 0.25f;
        v->x34 = v->x34 * s;
    }
    v->x30 = v->x34;
    v->x39 = 1;
    v->x2DC = 0;
    v->x70 = D_L23_001DE328;
    v->x40 = 3.5f;
    v->x2E0 = 0x21;
    v->x2E4 = 0x43;
    v->x2B8 = 1.0f;
    v->x300 = 0;
    v->x2A4 = 0.87266463f;
    v->x74 = D_L23_001DE328;
    v->x304 = 0;
    v->x80 = 1.3962634f;
    v->xA8 = 1;
    v->x78 = 1.0f;
    v->x7C = 1.0f;
    v->x308 = *(f32 *)(self + 0xF8);
    v->x30C = 0;
    v->x318 = 0;
    v->x31C = 0;
    v->x324 = 0;
    v->x328 = 0;
    v->x32C = 0;
    v->x330 = 0;
    v->x334 = 0;
    v->x314 = -1;
    v->x33C = 0;
    v->x338 = v->x34;
    v->x340 = 0;
    v->x344 = 0;
    v->x348 = 0;
    v->x34C = 0;
    v->x350 = *(V4 *)(self + 0x10);
    v->x360 = *(V4 *)(self + 0x10);
    v->x370 = *(V4 *)(self + 0x10);
    v->x370.z = func_003C3D30(&v->x370, 0, 0, 0.5f);
    v->x390 = -1;
    v->x380 = 0;
    v->x384 = 0;
    v->x388 = 0;
    v->x38C = 0;
    v->x398 = 0;
    *(s16 *)(self + 0x32) = 0xF0;
    self[0x30] = 0xF0;
    *(s16 *)(self + 0x7C) = 0xFF;
    D_L23_001DE2D0 = (Moby_AD *)self;
    func_L01_004450F0(self, 1, 0);
}
/* localdecomp:end func_L23_003B3998 */
