#include "common.h"

typedef int s128_003985C0 __attribute__((mode(TI)));
typedef struct {
    u8 pad[112];
    f32 f112;
    u8 pad2[124];
} Ent_003985C0;
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;

INCLUDE_ASM("asm/levels", func_L01_00396B78);

LINKER_REMNANT("asm/levels", func_L01_00396DE8);

INCLUDE_ASM("asm/levels", func_L01_00396E08);

/* localdecomp:start func_L01_00396FD8 */
void func_L01_00396FD8(u8 *p)
{
    *(unsigned long *)(p + 128) = 0xFF9000000260;
    *(unsigned long *)(p + 112) = 0;
    *(f32 *)(p + 80) = 0.0f;
    *(f32 *)(p + 84) = 0.0f;
    *(f32 *)(p + 88) = 1.0f;
    *(f32 *)(p + 92) = 0.0f;
    *(f32 *)(p + 96) = 0.0f;
    *(f32 *)(p + 100) = 1.0f;
    *(f32 *)(p + 104) = 1.0f;
    *(f32 *)(p + 108) = 1.0f;
    *(f32 *)(p + 8) = -1.0f;
    *(f32 *)(p + 24) = 1.0f;
    *(f32 *)(p + 40) = -1.0f;
    *(f32 *)(p + 56) = 1.0f;
    *(f32 *)(p + 4) = -1.0f;
    *(f32 *)(p + 36) = 1.0f;
    *(f32 *)(p + 52) = 1.0f;
    *(f32 *)(p + 0) = 0.0f;
    *(f32 *)(p + 16) = 0.0f;
    *(f32 *)(p + 32) = 0.0f;
    *(f32 *)(p + 48) = 0.0f;
    *(f32 *)(p + 12) = 1.0f;
    *(f32 *)(p + 28) = 1.0f;
    *(f32 *)(p + 20) = -1.0f;
    *(f32 *)(p + 44) = 1.0f;
    *(f32 *)(p + 60) = 1.0f;
}
/* localdecomp:end func_L01_00396FD8 */

/* localdecomp:start func_L01_00397060 */
extern void func_0038CE20(f32 *, f32 *, f32);
void func_L01_00397060(f32 *m, f32 s) {
    func_0038CE20(m, m, s);
    func_0038CE20(m + 4, m + 4, s);
    func_0038CE20(m + 8, m + 8, s);
    func_0038CE20(m + 12, m + 12, s);
}
/* localdecomp:end func_L01_00397060 */

INCLUDE_ASM("asm/levels", func_L01_003970C8);

INCLUDE_ASM("asm/levels", func_L01_00397278);

INCLUDE_ASM("asm/levels", func_L01_003973F8);

INCLUDE_ASM("asm/levels", func_L01_00397A28);

INCLUDE_ASM("asm/levels", func_L01_00397E98);

/* localdecomp:start func_L01_00399A40 */
void func_L01_00399A40(u8 *a) {
    a[0xBC] = 3;
}
/* localdecomp:end func_L01_00399A40 */

/* localdecomp:start func_L01_00399A50 */
extern void func_0038CE20(f32 *, f32 *, f32);


extern u8 D_001425FF[];
extern Ent_003985C0 D_L01_002C5600[];
extern u8 D_L01_001EEA80[];
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern void func_L01_00447718(void *, void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L01_00399A50(u8 *obj, s32 unused, s32 arg) {
    s128_003985C0 v;
    s128_003985C0 q;
    f32 scale;
    s32 r;

    ((void (*)(void *, f32))func_0038CE20)(&v, -3.0f);
    scale = (D_L01_002C5600 + D_001425FF[0])->f112;
    r = func_003D4D00(obj + 16, 16, obj, 0, 0.75f);
    q = *(s128_003985C0 *)(obj + 16);
    func_L01_00447718(obj, &q, D_L01_001EEA80, r, arg, 0x1110000, 3, 1, -1, scale, 1.0f, 1.0f);
}
/* localdecomp:end func_L01_00399A50 */

INCLUDE_ASM("asm/levels", func_L01_00399B18);

INCLUDE_ASM("asm/levels", func_L01_00399D78);

/* localdecomp:start func_L01_00399DE8 */
extern u8 D_L01_002A19F0[];
extern void func_L01_00399D78(u8 *a0, u8 *a1);
extern void func_L01_00409B08(u8 *a0, s32 a1, s32 a2);
extern void func_L01_00409E70(u8 *a0, u8 *a1, s32 a2, s32 a3, f32 f12, f32 f13);
void func_L01_00399DE8(u8 *a0) {
    u8 buf[16];
    u8 *s0;
    if (a0 != 0 && a0[32] != 254 && a0[32] != 253) {
        s0 = *(u8 **)(a0 + 104);
        if (s0 != 0) {
            func_L01_00399D78(a0, buf);
            func_L01_00409B08(buf, 0x103080, 0);
            func_L01_00409E70(buf, D_L01_002A19F0 + *(s32 *)(s0 + 44) * 64, 0x103080, 4, 0.0f, 0.25f);
        }
    }
}
/* localdecomp:end func_L01_00399DE8 */

INCLUDE_ASM("asm/levels", func_L01_00399E80);

INCLUDE_ASM("asm/levels", func_L01_0039A320);

INCLUDE_ASM("asm/levels", func_L01_0039A860);

INCLUDE_ASM("asm/levels", func_L01_0039AB60);

INCLUDE_ASM("asm/levels", func_L01_0039AEB8);

INCLUDE_ASM("asm/levels", func_L01_0039B478);

INCLUDE_ASM("asm/levels", func_L01_0039B6B8);

INCLUDE_ASM("asm/levels", func_L01_0039B9F0);

INCLUDE_ASM("asm/levels", func_L01_0039BD08);

INCLUDE_ASM("asm/levels", func_L01_0039BEF8);

INCLUDE_ASM("asm/levels", func_L01_0039C190);

INCLUDE_ASM("asm/levels", func_L01_0039C498);

/* localdecomp:start func_L01_0039C4D8 */
void func_L01_0039C4D8(u8 *p)
{
    *(unsigned long *)(p + 128) = 0xFF9000000260;
    *(unsigned long *)(p + 112) = 0;
    *(f32 *)(p + 80) = 0.0f;
    *(f32 *)(p + 84) = 0.0f;
    *(f32 *)(p + 88) = 1.0f;
    *(f32 *)(p + 92) = 0.0f;
    *(f32 *)(p + 96) = 0.0f;
    *(f32 *)(p + 100) = 1.0f;
    *(f32 *)(p + 104) = 1.0f;
    *(f32 *)(p + 108) = 1.0f;
    *(f32 *)(p + 8) = -1.0f;
    *(f32 *)(p + 24) = 1.0f;
    *(f32 *)(p + 40) = -1.0f;
    *(f32 *)(p + 56) = 1.0f;
    *(f32 *)(p + 4) = -1.0f;
    *(f32 *)(p + 36) = 1.0f;
    *(f32 *)(p + 52) = 1.0f;
    *(f32 *)(p + 0) = 0.0f;
    *(f32 *)(p + 16) = 0.0f;
    *(f32 *)(p + 32) = 0.0f;
    *(f32 *)(p + 48) = 0.0f;
    *(f32 *)(p + 12) = 1.0f;
    *(f32 *)(p + 28) = 1.0f;
    *(f32 *)(p + 20) = -1.0f;
    *(f32 *)(p + 44) = 1.0f;
    *(f32 *)(p + 60) = 1.0f;
}
/* localdecomp:end func_L01_0039C4D8 */

INCLUDE_ASM("asm/levels", func_L01_0039C560);

INCLUDE_ASM("asm/levels", func_L01_0039C9E0);

INCLUDE_ASM("asm/levels", func_L01_0039D2E0);

INCLUDE_ASM("asm/levels", func_L01_0039D6E0);

INCLUDE_ASM("asm/levels", func_L01_0039D818);

LINKER_REMNANT("asm/levels", func_L01_0039D930);

INCLUDE_ASM("asm/levels", func_L01_0039D938);

INCLUDE_ASM("asm/levels", func_L01_0039DB90);

INCLUDE_ASM("asm/levels", func_L01_0039DCB8);

INCLUDE_ASM("asm/levels", func_L01_0039E018);

INCLUDE_ASM("asm/levels", func_L01_0039E0C8);

/* localdecomp:start func_L01_0039E158 */

extern void func_003C5278(Vec4 *, Vec4 *, Vec4 *, f32);
extern s32 func_003D3CB0(Vec4 *, s32 *, s32, s32, s32);
extern s32 D_001A4CC0[];

s32 func_L01_0039E158(u8 *obj) {
    Vec4 v;
    v = *(Vec4 *)(obj + 16);
    func_003C5278((Vec4 *)(obj + 16), &v, &v, -0.5f);
    return func_003D3CB0(&v, D_001A4CC0, 18, 0, 0) == 0;
}
/* localdecomp:end func_L01_0039E158 */
