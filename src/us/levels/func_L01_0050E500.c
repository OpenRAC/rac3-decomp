#include "common.h"

typedef struct {
    char pad0[0x10];
    u8 count;
} Anim;
typedef struct {
    char pad0[0x48];
    Anim *anims[1];
} Class;
typedef struct {
    char pad0[0x24];
    Class *cls;
    char pad28[0x40 - 0x28];
    u8 unk40;
    u8 unk41;
    u8 unk42;
    u8 unk43;
    s32 unk44;
    char pad48[0x58 - 0x48];
    s32 unk58;
    s32 unk5C;
} Moby;
typedef struct {
    char data[0x600];
} Buf;
typedef struct {
    u8 pad0[0xC20];
    s32 xC20;
    s32 xC24;
    s32 xC28;
} D_001A4BE0_t;
typedef struct {
    u8 pad0[0x20];
    u8 b32;
    u8 pad21[0x34 - 0x21];
    u16 h52;
    u8 pad36[0xAA - 0x36];
    s16 h170;
} M_50C8E8;
typedef struct {
    M_50C8E8 *p[3];
    u8 padC[0x28 - 0xC];
    s32 w40;
    u8 pad2C[0x50 - 0x2C];
} E_50C8E8;
typedef struct {
    u8 pad0[0xBF8];
    M_50C8E8 *p3064;
    u8 padBFC[0x1200 - 0xBFC];
    E_50C8E8 e[1];
    u8 pad1250[0x12FC - 0x1250];
    M_50C8E8 *p4860;
    u8 pad1300[0x1A24 - 0x1300];
    M_50C8E8 *p6692;
    u8 pad1A28[0x25E4 - 0x1A28];
    u8 b9700;
} G_50C8E8;
typedef struct {
    u8 pad0[0x44];
    s16 h68;
    u8 pad46[0x1A0 - 0x46];
    M_50C8E8 *arr[1];
} H_50C8E8;
typedef struct {
    u8 pad0[0x20];
    s16 h32;
} K_50C8E8;
typedef struct {
    f32 m[16];
} M_0050D430;
typedef struct {
    f32 v[4];
} V_0050D430;
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4_50D4D8;
typedef struct {
    u8 pad0[64];
    Vec4_50D4D8 m;
    u8 pad50[9636];
    u8 b25F4;
} G_50D4D8;
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct {
    u8 m0[64];
    u8 m40[9716 - 64];
    u8 mode;
} S_50D530;
typedef struct {
    f32 m0[4][4];
    f32 m1[4][4];
    u8 pad[0x25F4 - 0x80];
    u8 mode;
} Cam50D5B0;
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4_00511618;
typedef struct {
    u8 m0[64];
    u8 m40[9716 - 64];
    u8 mode;
} S_50D870;
typedef struct {
    u8 pad[138];
    u16 h8A;
    u8 pad2[240 - 140];
} S_50D8F8;
typedef struct {
    u8 pad0[0x8A];
    u16 h8A;
    u8 pad8C[0xF0 - 0x8C];
} S_50DA08;
typedef struct {
    u8 arr[0x40];
} S_50DA08a;
typedef struct {
    s32 arr[0x40];
} S_50DA08b;
typedef struct {
    u8 pad0[52];
    s32 x34;
} G_0050F828;

typedef struct {
    u8 pad0[0x78];
    s32 color78;
} Node_005124D8;
typedef struct {
    u8 pad0[0x1340];
    Node_005124D8 *p1340;
    Node_005124D8 *p1344;
    Node_005124D8 *p1348;
    u8 pad134C[0x1390 - 0x134C];
    Node_005124D8 *p1390;
    u8 pad1394[0x2890 - 0x1394];
    f32 f2890;
    f32 f2894;
    f32 f2898;
    f32 f289C;
} Glob_005124D8;

typedef struct Manip_00512A30 {
    u8 pad0;
    u8 initialized;
    u8 pad2[0x1E];
    f32 scale[3];
    u8 pad2C[0x14];
} Manip_00512A30;

extern void fe_func_003C29B0(Moby *);
extern D_001A4BE0_t D_001A4BE0;
extern D_001A4BE0_t D_001A4BE0;
extern s32 D_L01_001D6694;
extern D_001A4BE0_t D_001A4BE0;
extern D_001A4BE0_t D_001A4BE0;
extern f32 fe_func_0038CED8(V_0050D430 *);
extern void fe_func_0038D328(M_0050D430 *, u8 *);
extern void fe_func_0038D5B0(M_0050D430 *, M_0050D430 *);
extern void fe_func_0038D028(V_0050D430 *, V_0050D430 *, M_0050D430 *);
extern D_001A4BE0_t D_001A4BE0;
extern void fe_func_0038D000(Vec4_50D4D8 *, f32 *, Vec4_50D4D8 *);
extern void fe_func_0038D028(V_0050D430 *, V_0050D430 *, M_0050D430 *);
extern D_001A4BE0_t D_001A4BE0;
extern void fe_func_0038D028(V_0050D430 *, V_0050D430 *, M_0050D430 *);
extern D_001A4BE0_t D_001A4BE0;
extern void fe_func_0038CFB8(f32 *, f32 *, f32);
extern void fe_func_0038D028(V_0050D430 *, V_0050D430 *, M_0050D430 *);
extern D_001A4BE0_t D_001A4BE0;
extern void fe_func_0038D028(V_0050D430 *, V_0050D430 *, M_0050D430 *);
extern D_001A4BE0_t D_001A4BE0;
extern f32 fe_func_0038CED8(V_0050D430 *);
extern void fe_func_0038D028(V_0050D430 *, V_0050D430 *, M_0050D430 *);
extern D_001A4BE0_t D_001A4BE0;
extern f32 fe_func_0038D160(f32, f32);
extern D_001A4BE0_t D_001A4BE0;
extern D_001A4BE0_t D_001A4BE0;
/* localdecomp:start func_L01_0050E500 */
extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);
extern s32 func_003894A0(s32, s32, f32);
extern void func_L01_0044EB38(Node_005124D8 *, f32 *, s32, s32, f32);

void func_L01_0050E500(void)
{
    Node_005124D8 *node;

    node = ((Glob_005124D8 *)&D_001A4BE0)->p1340;
    if (node != 0) {
        if (D_L01_001D6694 == 2)
            ((Glob_005124D8 *)&D_001A4BE0)->f2890 = func_00389380(((Glob_005124D8 *)&D_001A4BE0)->f2890, 0.020362176f);
        else
            ((Glob_005124D8 *)&D_001A4BE0)->f2890 = func_00389380(((Glob_005124D8 *)&D_001A4BE0)->f2890, 0.0349065885f);
        node->color78 = func_003894A0(0xd2d2d2, 0x285050,
                                      func_00388978(((Glob_005124D8 *)&D_001A4BE0)->f2890) * 0.5f + 0.5f);
    }
    node = ((Glob_005124D8 *)&D_001A4BE0)->p1344;
    if (node != 0) {
        if (D_L01_001D6694 != 2) {
            f32 limit;
            s32 which;

            limit = func_00389380(((Glob_005124D8 *)&D_001A4BE0)->f2894, 0.0494509973f);
            ((Glob_005124D8 *)&D_001A4BE0)->f2894 = limit;
            which = 0x1ee628;
            if (limit > 0.0f && limit < 1.9198622f) {
                which = 0x1e1ed2;
            }
            node->color78 = func_003894A0(node->color78, which, 0.07f);
        } else {
            ((Glob_005124D8 *)&D_001A4BE0)->f2894 = func_00389380(((Glob_005124D8 *)&D_001A4BE0)->f2894, 0.0261799414f);
            node->color78 = func_003894A0(0x1e1ed2, 0x1e1e50,
                                          func_00388978(((Glob_005124D8 *)&D_001A4BE0)->f2894) * 0.5f + 0.5f);
        }
    }
    if (((Glob_005124D8 *)&D_001A4BE0)->p1348 != 0) {
        if (D_L01_001D6694 == 2)
            func_L01_0044EB38(((Glob_005124D8 *)&D_001A4BE0)->p1348, &((Glob_005124D8 *)&D_001A4BE0)->f2898, 0xdcdcdc, 0x323232, 0.0261799414f);
        else
            func_L01_0044EB38(((Glob_005124D8 *)&D_001A4BE0)->p1348, &((Glob_005124D8 *)&D_001A4BE0)->f2898, 0xdcdcdc, 0x323232, 0.040724352f);
    }
    node = ((Glob_005124D8 *)&D_001A4BE0)->p1390;
    if (node != 0) {
        f32 a;
        s32 which;

        a = func_00389380(((Glob_005124D8 *)&D_001A4BE0)->f289C, 0.0494509973f);
        ((Glob_005124D8 *)&D_001A4BE0)->f289C = a;
        which = 0x5a5a5a;
        if (a > 0.0f && a < 1.2217305f) {
            which = 0xaac8aa;
        }
        node->color78 = func_003894A0(node->color78, which, 0.15f);
    }
}
/* localdecomp:end func_L01_0050E500 */
