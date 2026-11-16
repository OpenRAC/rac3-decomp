/* NTSC-U draft (Claude wave K): C of func_L10_003AE9F8, the NTSC-U twin of func_L10_003B0940, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 56 words differ on NTSC-U (the worker's best count) (NTSC-U twin "func_L10_003AE9F8", whose code is not the PAL one).
 * Worker's note: 56 diff (constant register numbering f0-f7 and store-before-jal placement only; all ~60 stores decoded in retail order): NPC init void f(u8 *a): s0 = a->0x68 block: 0x40=0.45f, b39=1, 0x70/0x74=0.3f, b58=0x14, b5A=0xE, f30=100.0f, h34=100, 0x368=1.0f, ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L10_003AEE90 (src/levels/shared/L10_003AEE90.c) */
/* localdecomp:start func_L10_003AE9F8 */
typedef int u128_t __attribute__((mode(TI)));
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);

void func_L10_003AE9F8(u8 *a) {
    u8 *s0;
    s32 v;

    s0 = *(u8 **)(a + 0x68);
    v = *(s32 *)(s0 + 0xA8) | 0x80;
    *(f32 *)(s0 + 0x40) = 0.45f;
    s0[0x39] = 1;
    *(f32 *)(s0 + 0x70) = 0.3f;
    *(f32 *)(s0 + 0x74) = 0.3f;
    s0[0x58] = 0x14;
    s0[0x5A] = 0xE;
    *(f32 *)(s0 + 0x30) = 100.0f;
    *(s16 *)(s0 + 0x34) = 100;
    *(f32 *)(s0 + 0x368) = 1.0f;
    *(s32 *)(s0 + 0x390) = 0x28;
    *(s32 *)(s0 + 0x394) = 0x50;
    *(f32 *)(s0 + 0x354) = 0.8726646304130554f;
    *(f32 *)(s0 + 0xA4) = 0.2f;
    *(f32 *)(s0 + 0x7C) = 0.5f;
    *(f32 *)(s0 + 0x80) = 1.483529806137085f;
    *(f32 *)(s0 + 0xA0) = 0.3490658402442932f;
    *(f32 *)(s0 + 0x9C) = 0.0027222223579883575f;
    *(s32 *)(s0 + 0xA8) = v;
    *(f32 *)(s0 + 0x78) = 0.5f;
    func_L01_00458A70(a, 0.004444444552063942f, 0.01666666753590107f, 0.005235987715423107f, 0.13962635397911072f);
    s0[0x1A8] = 4;
    *(f32 *)(s0 + 0x190) = 0.3f;
    *(f32 *)(s0 + 0x194) = 0.45f;
    *(f32 *)(s0 + 0x19C) = 0.15f;
    s0[0x1D7] = 1;
    *(f32 *)(s0 + 0x1B8) = 0.01f;
    *(f32 *)(s0 + 0x1BC) = 0.02f;
    *(s32 *)(s0 + 0x510) = -1;
    s0[0x170] = 0xA;
    *(s16 *)(s0 + 0x198) = 0;
    *(s32 *)(s0 + 0x3B0) = 0;
    *(s32 *)(s0 + 0x4EC) = 0;
    *(s32 *)(s0 + 0x4E8) = 0;
    *(s32 *)(s0 + 0x4F0) = 0;
    *(s32 *)(s0 + 0x3BC) = 0;
    *(s16 *)(s0 + 0x3B8) = 0;
    *(s16 *)(s0 + 0x3BA) = 0;
    *(s32 *)(s0 + 0x4FC) = 0;
    *(s32 *)(s0 + 0x518) = 0;
    *(s32 *)(s0 + 0x514) = 0;
    *(s32 *)(s0 + 0x51C) = 0;
    *(s32 *)(s0 + 0x3D4) = 0;
    *(s32 *)(s0 + 0x3B4) = 0;
    *(s32 *)(s0 + 0x3D8) = 0;
    *(s32 *)(s0 + 0x3DC) = 0;
    *(u128_t *)(s0 + 0x550) = *(u128_t *)(a + 0x10);
    *(u128_t *)(s0 + 0x520) = 0;
    func_L01_00441FB8(a, 1, 1);
}
/* localdecomp:end func_L10_003AE9F8 */
