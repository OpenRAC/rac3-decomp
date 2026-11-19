#include "common.h"

typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
    u8 pad8[8];
    void (*f10)(u8 *);
} Tbl_003A5118;
typedef struct {
    u8 pad0[576];
    s32 f240;
    u8 pad244[284];
    s32 ids[10];
    u8 pad388[32];
    s32 f3A8;
} Vars_003A5118;
typedef struct {
    u8 pad0[104];
    Vars_003A5118 *vars;
} Obj_003A5118;
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    u8 p10[0x30];
    s32 x40;
    s32 x44;
    s32 x48;
    s32 x4C;
    u8 p50[0x18];
    s32 x68;
    s32 x6C;
    u8 p70[0x64];
    s32 xD4;
} S_3A68C0;
typedef struct {
    u8 p0[0xB2];
    u16 xB2;
} O_3A68C0;
typedef struct {
    u8 p0[0x464];
    u8 x464[1];
} T_3A68C0;
typedef struct {
    u8 pad0[150];
    u16 timer;
} Obj003A7510;
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef int s128_3A7C18 __attribute__((mode(TI)));
typedef struct {
    s128_3A7C18 q0;
    u8 *parent;
    f32 f14;
    int f18;
    f32 f1C;
    f32 f20;
} V_3A7C18;
typedef int u128_003A9A80 __attribute__((mode(TI)));
typedef struct {
    u8 pad[0x64];
    u8 *w64;
} Moby_003A9A80;
typedef struct {
    u8 pad[0x30];
    u8 b30;
    u8 pad2[3];
    u16 h34;
    u8 pad3[0x98 - 0x36];
    int x98;
} S_3A9AC0m;
typedef struct {
    int x0;
    int x4;
    u8 pad[0x10];
} S_3A9AC0a;
typedef struct {
    int x0;
    int x4;
    u8 pad[0x28];
} S_3A9AC0b;
typedef struct {
    u8 pad[0x24];
    int n;
    S_3A9AC0b *p;
    u8 pad2[4];
} S_3A9AC0c;
typedef struct {
    u8 pad[8];
    int n8;
    S_3A9AC0a *pC;
    u8 pad2[0x34 - 0x10];
    int n34;
    S_3A9AC0c *p38;
} S_3A9AC0d;
typedef struct {
    u8 pad[0xD0];
    u8 bD0;
    u8 pad2[0xDC - 0xD1];
    S_3A9AC0m *mDC;
} S_3A9AC0e;
typedef struct {
    u8 pad[0x64];
    S_3A9AC0m *m;
    S_3A9AC0d *d;
    u8 pad2[0xBA0 - 0x6C];
    u8 xBA0[0xC48 - 0xBA0];
    int xC48;
    u8 pad3[0xD1C - 0xC4C];
    int xD1C;
} S_3A9AC0o;
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4_003AB448;

typedef struct {
    u8 pad0[0x60];
    s32 group;
} G_003AADB8;


/* localdecomp:start func_L01_003A5340 */
extern f32 D_L01_001DE32C;
__asm__(".extern D_L01_001DE32C, 4");
extern f32 D_L01_001DE330;
__asm__(".extern D_L01_001DE330, 4");
extern f32 D_L01_001DE334;
__asm__(".extern D_L01_001DE334, 4");
extern f32 D_L01_001DE338;
__asm__(".extern D_L01_001DE338, 4");
extern f32 D_L01_001DE33C;
__asm__(".extern D_L01_001DE33C, 4");
void func_L01_003A5340(u8 *obj) {
    extern s32 func_L01_0040BA90(s32 *);
    extern void func_L01_0040BAC0(s32 *);
    extern void func_L01_0044EB78(void *, void *, s32, s32, f32);
    extern void func_L01_0044B860(void *, void *, void *, f32, f32, f32);
    extern void func_L01_0044B920(void *, void *, void *, f32, f32, f32);
    u8 *v = *(u8 **)(obj + 0x68);
    func_L01_0040BA90((s32 *)(v + 0x2E0));
    func_L01_0040BAC0((s32 *)(v + 0x2E4));
    if (*(u16 *)(obj + 0x96) < 0xFFFF) ++*(u16 *)(obj + 0x96);
    func_L01_0044EB78(obj, v + 0x250, 4, 1, 2.5f);
    func_L01_0044B860(obj, v + 0x2EC, v + 0x2F0, D_L01_001DE32C, D_L01_001DE330 * 0.017453292f * 0.0166666675f, -1.0f);
    func_L01_0044B920(obj, v + 0x2F4, v + 0x2F8, D_L01_001DE33C * 0.017453292f, D_L01_001DE334 * 0.017453292f * 0.0166666675f, D_L01_001DE338 * 0.017453292f * 0.0166666675f);
}
/* localdecomp:end func_L01_003A5340 */
