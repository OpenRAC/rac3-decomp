#include "common.h"

typedef struct { u8 pad[0x240]; s32 f240; u8 pad2[0xC]; f32 f250; f32 f254; } S_003AEF78;
typedef struct { u8 pad[0x68]; S_003AEF78 *s68; } O_003AEF78;

/* localdecomp:start func_L07_003AEF78 */
extern s32 D_L07_001DEF40[1];
extern f32 func_0038DB00(f32, f32);
extern s32 func_L01_0045A7A8(void *, f32 *, f32);
extern void func_L07_00333DB8(s32, void *, s32, s32, f32);

void func_L07_003AEF78(O_003AEF78 *a0, f32 *a1) {
    S_003AEF78 *s = a0->s68;
    f32 f = func_0038DB00(s->f250, s->f254);
    s32 g;
    s32 b;
    func_L01_0045A7A8(a0, a1, f * 0.4f);
    g = D_L07_001DEF40[0] & 0xF;
    b = ((s32)a0 >> 8) & 0xF;
    if (g == b) {
        func_L07_00333DB8(s->f240, a0, 0, 0, 8.0f);
    }
}
/* localdecomp:end func_L07_003AEF78 */

/* localdecomp:start func_L07_003AF010 */
typedef int Quad_003AF010 __attribute__((mode(TI)));

extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern void func_L07_003AF0B0(void *, void *, f32);

void func_L07_003AF010(u8 *self, Quad_003AF010 *in, void (*fn)(void *, void *)) {
    u8 *s = *(u8 **)(self + 0x68);
    Quad_003AF010 tmp;

    *(f32 *)(self + 0x18) = *(f32 *)(self + 0x18) - *(f32 *)(s + 0x27C);
    tmp = *in;
    fn(self, &tmp);
    *(f32 *)(s + 0x278) = func_0038DAB8(*(f32 *)(s + 0x278), 0.12566371f);
    *(f32 *)(s + 0x27C) = func_0038D0B0(*(f32 *)(s + 0x278)) * 0.2f;
    *(f32 *)(self + 0x18) = *(f32 *)(self + 0x18) + *(f32 *)(s + 0x27C);
    func_L07_003AF0B0(self, s + 0xD0, *(f32 *)(s + 0xE4));
}
/* localdecomp:end func_L07_003AF010 */

INCLUDE_ASM("asm/levels", func_L07_003AF0B0);

/* localdecomp:start func_L07_003AF240 */
typedef struct {
    u8 pad[0x240];
    void *p240;
    u8 pad2[0x1C];
    f32 f260;
    f32 f264;
    f32 f268;
} S_3AF240;
typedef struct { u8 pad[0x68]; S_3AF240 *s68; } O_3AF240;

extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern s32 func_L07_00331FF0(u8 *);

void func_L07_003AF240(O_3AF240 *a0) {
    S_3AF240 *s = a0->s68;
    s32 t;

    s->f260 = func_00382538();
    t = func_L07_00331FF0(s->p240);
    s->f264 = func_003824E0(15.0f, t ? 24.8f : 30.0f);
    s->f268 = func_003824E0(0.5f, 6.0f);
}
/* localdecomp:end func_L07_003AF240 */

INCLUDE_ASM("asm/levels", func_L07_003AF2B8);
