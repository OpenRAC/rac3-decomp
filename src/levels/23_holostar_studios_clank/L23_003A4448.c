#include "common.h"
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x10];
    u8 x10;
    u8 pad11[0x1F];
    f32 x30;
    f32 x34;
    u8 pad38[0x4];
    f32 x3C;
    u8 pad40[0x8];
    u8 x48;
    u8 pad49[0xE0 - 0x49];
} Move_3A5008;
typedef struct {
    u8 x0[0x10];
    u8 x10[0x30];
} Node_3A5008;
typedef struct {
    u8 pad0[0x30];
    f32 x30;
    s16 x34;
    u8 pad36[0x3A];
    f32 x70;
    f32 x74;
    f32 x78;
    f32 x7C;
    f32 x80;
    u8 pad84[0x18];
    s32 x9C;
    f32 xA0;
    f32 xA4;
    s32 xA8;
    u8 padAC[0xB4];
    Move_3A5008 x160;
    s32 x240;
    f32 x244;
    u8 pad248[0x4];
    s32 x24C;
    s32 x250;
    s32 x254;
    u8 pad258[0x4];
    f32 x25C;
    Node_3A5008 x260;
    s32 x2A0;
    s32 x2A4;
    u8 pad2A8[0x4];
    s32 x2AC;
    u8 x2B0[16];
    u8 x2C0[16];
    u8 x2D0[16];
} S_3A5008;

/* localdecomp:start func_L23_003A4448 */
extern s32 D_L23_001DE098;
__asm__(".extern D_L23_001DE098, 4");
extern s32 D_L23_001DE09C;
__asm__(".extern D_L23_001DE09C, 4");
extern f32 D_L23_001DE0A0;
__asm__(".extern D_L23_001DE0A0, 4");

void func_L23_003A4448(s32 arg0, s32 arg1, f32 fparg0) {
    D_L23_001DE098 = arg0;
    D_L23_001DE09C = arg1;
    D_L23_001DE0A0 = fparg0;
}
/* localdecomp:end func_L23_003A4448 */

LINKER_REMNANT("asm/levels", func_L23_003A4458);

INCLUDE_ASM("asm/levels", func_L23_003A4460);

/* localdecomp:start func_L23_003A5008 */
extern f32 D_L23_001DE02C;
extern s32 D_L23_001DE090;
__asm__(".extern D_L23_001DE090, 4");
extern u8 *D_L23_001DE2D0;
extern void func_L23_003A5110(u8 *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_0038D750(void *, s32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_L01_004450F0(u8 *, s32, s32);


void func_L23_003A5008(u8 *m) {
    S_3A5008 *v = *(S_3A5008 **)(m + 0x68);
    if (m[0x20] == 0) {
        func_L23_003A5110(m);
    }
    if (m[0x95] != 4) {
        func_L01_00452FB0(m, &v->x160, 0, 0, 0);
        if (m[0x31] != 0) {
            func_0038D750(v->x260.x10, 2, v->x25C);
            v->x25C = func_0038DB00(v->x25C, D_L23_001DE02C);
        }
    }
    if (v->x2A0 != 0) {
        if (m[0x95] != 2) {
            v->x2A0 = 0;
            D_L23_001DE090--;
        }
    } else if (m[0x95] == 2) {
        v->x2A0 = 1;
        D_L23_001DE090++;
    }
    if (m[0x95] != 4 && *(f32 *)(*(u8 **)(D_L23_001DE2D0 + 0x68) + 0x30) <= 0.0f) {
        func_L01_004450F0(m, 1, 0);
    }
}
/* localdecomp:end func_L23_003A5008 */

/* localdecomp:start func_L23_003A5110 */
extern float D_L23_001DE028;
__asm__(".extern D_L23_001DE028, 4");
extern f32 D_L23_001DE06C;
__asm__(".extern D_L23_001DE06C, 4");
extern f32 D_L23_001DE078;
__asm__(".extern D_L23_001DE078, 4");
extern f32 D_L23_001DE07C;
__asm__(".extern D_L23_001DE07C, 4");
extern f32 D_L23_001DE080;
__asm__(".extern D_L23_001DE080, 4");
extern f32 D_L23_001DE084;
__asm__(".extern D_L23_001DE084, 4");
extern s32 D_L23_001DE094;
__asm__(".extern D_L23_001DE094, 4");
extern s32 D_L23_001DE0A8;
__asm__(".extern D_L23_001DE0A8, 4");
extern s32 D_L23_001DE098;
__asm__(".extern D_L23_001DE098, 4");
extern s32 D_L23_001DE09C;
__asm__(".extern D_L23_001DE09C, 4");
extern f32 D_L23_001DE0A0;
__asm__(".extern D_L23_001DE0A0, 4");
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern f32 func_00382538(void);
extern void func_L01_0043A430(u8 *, s32, u8 *);

void func_L23_003A5110(u8 *m)
{
    S_3A5008 *v;

    *(f32 *)(m + 0x2C) = *(f32 *)(m + 0x2C) * D_L23_001DE028;
    *(s16 *)(m + 0x7C) = 0xFF;
    v = *(S_3A5008 **)(m + 0x68);
    v->x160.x10 = 6;
    v->x160.x48 = 3;
    v->x160.x3C = 0.15f;
    v->x160.x30 = 0.5f;
    v->x160.x34 = 0.5f;
    if (v->x34 == 0) {
        v->x34 = 1;
        v->x30 = 1.0f;
    }
    v->x74 = -D_L23_001DE06C;
    v->xA0 = 0.08726646f;
    v->xA8 |= 0x514;
    v->x78 = 20.0f;
    v->x7C = 20.0f;
    v->x80 = 1.5707964f;
    v->xA4 = 0.5f;
    v->x70 = D_L23_001DE06C;
    v->x9C = 0;
    func_L01_0045BD78(m, D_L23_001DE07C, D_L23_001DE078, D_L23_001DE084, D_L23_001DE080);
    v->x244 = func_00382538() * 0.5f;
    v->x240 = 0;
    v->x24C = 0;
    v->x250 = 0;
    v->x254 = 0;
    v->x25C = 0.0f;
    qzero(v->x2B0);
    qzero(v->x2C0);
    qzero(v->x2D0);
    v->x2A4 = 0;
    v->x2A0 = 0;
    v->x2AC = -1;
    func_L01_0043A430(m, 0, (u8 *)&v->x260);
    D_L23_001DE0A0 = 0.5f;
    D_L23_001DE090 = 0;
    D_L23_001DE094 = 0;
    D_L23_001DE0A8 = 0;
    D_L23_001DE098 = 0;
    D_L23_001DE09C = 0;
    func_L01_004450F0(m, 7, 4);
}
/* localdecomp:end func_L23_003A5110 */

/* localdecomp:start func_L23_003A5290 */
extern s32 func_0038CAD0(void *);
f32 func_L01_0040E548(void *, void *);
void func_L01_004472C0(void *);
extern u8 D_L23_001E1A40[];

void func_L23_003A5290(void *arg0) {
    u8 *temp_s1;
    u16 temp_v1;

    temp_s1 = *(u8 **)((u8 *)arg0 + 0x68);
    if (((*(u8 *)((u8 *)arg0 + 0x31)) != 0) && (func_L01_0040E548(D_L23_001E1A40, arg0 + 0x10) < 1024.0f)) {
        func_L01_004472C0(arg0);
        *(s8 *)((u8 *)arg0 + 0x6F) = 0x1E;
    }
    func_0038CAD0(temp_s1 + 0x240);
    temp_v1 = *(u16 *)((u8 *)arg0 + 0x96);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1 + 1);
    }
}
/* localdecomp:end func_L23_003A5290 */

/* localdecomp:start func_L23_003A5328 */
extern float D_L23_001DE064;
__asm__(".extern D_L23_001DE064, 4");
extern float D_L23_001DE028;
__asm__(".extern D_L23_001DE028, 4");
extern s32 D_L23_001DE068;
__asm__(".extern D_L23_001DE068, 4");
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, float);
extern s32 func_003A52A0(s32, s32, void *);
extern void *func_L23_0032B060(void *, void *, void *, float);

void func_L23_003A5328(void *obj) {
    char matrix[64] __attribute__((aligned(16)));
    u128_t v[2];
    s32 i;

    for (i = 1; i < 3; i++) {
        func_003C2EC0(obj, i, matrix);
        v[0] = *(u128_t *)(matrix + 0x30);
        func_0038CF68(&v[1], matrix, D_L23_001DE064);
        func_003A52A0(2, 0, obj);
        func_L23_0032B060(&v[0], &v[1], &D_L23_001DE068, D_L23_001DE028);
    }
}
/* localdecomp:end func_L23_003A5328 */
