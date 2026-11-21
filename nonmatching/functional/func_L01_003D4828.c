/* functional: medium. Near miss (28 word diffs: register/branch order, gp-relative vs absolute store to the same word). */
#include "common.h"
/* localdecomp:start func_L01_003D4828 */
#include "vu0.h"
extern u8 D_001A4C60[];
extern u8 D_L01_001D66B0[] __attribute__((section(".sdata")));
extern u8 *D_L01_00221208 __attribute__((section(".data")));
extern u8 D_001425C0[];
typedef struct { u8 a; u8 b; u8 pad[0x44]; s16 id; u8 rest[0xA8]; } Row_003D4828;
extern Row_003D4828 D_L01_002C5600[];
extern s32 D_L01_001DFD38;
void func_L01_003D4828(u8 *m) {
    extern s32 func_00382468(s32);
    extern f32 func_L01_00443A18(f32, f32);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    extern void func_00382580(void *, f32, f32);
    extern void func_0038CF68(vu0_v4 *, vu0_v4 *, f32);
    extern void func_L01_004735F0(void *, void *, s32, f32);
    extern f32 func_0038CF38(void *, void *);
    extern s32 func_L01_00418D48(s32);
    extern void func_L01_004C94C0(s32, s32);
    extern void func_L01_00419318(s32);
    extern void func_L01_00418C90(s32, s32);
    extern void func_L01_00391610(void);
    extern void func_003C2880(u8 *);
    vu0_v4 pos, jitter, origin, delta;
    u8 *effect;
    s32 state, n;
    Row_003D4828 *table;
    f32 duration = 105000.0f;
    if (*(u8 **)(m+0xB8))
        *(u128_t *)(m+0x10) = *(u128_t *)(*(u8 **)(m+0xB8)+0x10);
    *(u128_t *)&pos = *(u128_t *)(m+0x10);
    pos.z += 0.5f;
    if (func_00382468(2)) {
        effect = func_L01_0046A610(&pos, D_L01_001D66B0, 12, 6, 0x409020,
            (s32)func_L01_00443A18(1.0f,-1.0f),420000.0f,500.0f,1.0f,0.0f,0.0f);
        if (effect) effect[2] = D_L01_00221208[1];
    }
    jitter.x = pos.x + func_L01_00443A18(0.0f,0.04f);
    jitter.y = pos.y + func_L01_00443A18(0.0f,0.04f);
    jitter.z = pos.z + func_L01_00443A18(0.0f,0.04f);
    effect = func_L01_0046A610(&jitter,D_L01_001D66B0,12,127,0x408020,
        (s32)func_L01_00443A18(1.0f,-1.0f),duration*2.4f,500.0f,1.0f,0.0f,0.0f);
    if (effect) {
        effect[3] = func_00382468(2) ? 72 : 68;
        effect[2] = D_L01_00221208[0];
    }
    func_00382580(&origin,0.025f,0.15f);
    vec_add_ab(&origin,&origin,&pos);
    vec_sub_ab(&delta,&pos,&origin);
    func_0038CF68(&delta,&delta,0.015000001f);
    func_L01_004735F0(&origin,&delta,12,1.0f);
    if (m[0xBC] && func_0038CF38(m+0x10,D_001A4C60)<10.0f) {
        state = *(s32 *)(D_001A4C60+0x11A8);
        if (state != 9) {
            n = func_L01_00418D48(state);
            table = D_L01_002C5600;
            if (n != table[D_001425C0[state]].b) {
                if (table[D_001425C0[state]].b == n-1 && state != 127) {
                    D_L01_001DFD38 = 1;
                    func_L01_004C94C0(state,table[D_001425C0[state]].id);
                    func_L01_00419318(table[D_001425C0[state]].id);
                    D_L01_001DFD38 = 0;
                } else {
                    func_L01_00418C90(state,0);
                    func_L01_00419318(state);
                    func_L01_00391610();
                }
                func_003C2880(m);
            }
        }
    }
}
/* localdecomp:end func_L01_003D4828 */
