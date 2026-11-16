/*
 * P03 PAL reconstruction, base eb302969 (2026-11-16).
 * Owning file: src/levels/20_final_boss/L20_003EBA98.c.
 * Flags: -O2 -G8 -fopt-stack -mno-check-zero-division.
 * One stock check.py compile: 242 positional differences, level 20.
 * Default assembler emits literal-pool loads instead of retail's inline float
 * constants; 64-bit constant synthesis and UV-loop addressing also differ.
 * Stopped on the file-wide assembler blocker; no alternate flags tested.
 * The second float division appears to need padding-table investigation.
 * No table changes, full-program checks or NTSC-U checks performed.
 */
#include "common.h"
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_BA98;
typedef struct {
    V_BA98 v[4]; u32 col[4]; f32 uv[4][2]; unsigned long u70,u78,u80,gif;
} Q_BA98;
extern void func_0038D2A0(void *);
extern long func_00389598(s32);
extern void func_L06_00359B60(void *, void *, f32, f32);
extern void func_L06_00359C38(void *, s32, s32, f32);
extern void func_L06_00359CA8(s32, s32);
extern void func_003D2DA0(void *, void *, s32);
extern s32 D_L20_001DF288;
extern s32 D_L20_001DF2C8;
extern f32 D_L20_001DF2CC;
extern f32 D_L20_001DF2F8[4][2];
void func_L20_003EBA98(u8 *m) {
    Q_BA98 q;
    V_BA98 mat[4];
    u8 *v;
    f32 phase, t, inverse;
    s32 i;
    v = *(u8 **)(m + 0x68);
    if (m[0x20] < 3) return;
    if (m[0x20] == 3)
        phase = 1.0f - (f32)*(s32 *)v / (f32)D_L20_001DF288;
    else phase = 1.0f;
    func_0038D2A0(mat);
    q.u78 = func_00389598(D_L20_001DF2C8);
    q.u80 = 0xFF9000000260L;
    q.gif = (0x8000L << 24) | 0x48;
    q.u70 = 0;
    for (i=0;i<4;i++) {
        q.uv[i][0] = D_L20_001DF2F8[i][0];
        q.uv[i][1] = D_L20_001DF2F8[i][1];
    }
    switch (m[0x20]) {
    case 3:
        if (0.0f <= phase && phase < 0.5f) {
            t = (phase - 0.0f) * 2.0f;
            func_L06_00359C38(&q, 0x20C03030, 0x80C03030, t);
            inverse = 1.0f - t;
            func_L06_00359B60(v, &q, D_L20_001DF2CC + inverse * D_L20_001DF2CC * 0.5f,
                              *(f32 *)(m+0xF0) + inverse * 0.7853982f);
            func_003D2DA0(&q, mat, 0);
            func_L06_00359B60(v, &q, D_L20_001DF2CC - inverse * D_L20_001DF2CC * 0.5f,
                              *(f32 *)(m+0xF0) + inverse * -0.7853982f);
            func_003D2DA0(&q, mat, 0);
        }
        if (0.5f <= phase && phase < 0.9f) {
            t = (phase - 0.5f) / 0.39999998f;
            func_L06_00359C38(&q, 0x6000F0F0, 0xF0F0, t);
            func_L06_00359B60(v, &q, D_L20_001DF2CC + t * D_L20_001DF2CC * 0.05f,
                              *(f32 *)(m+0xF0));
            func_003D2DA0(&q, mat, 0);
        }
        if (0.5f <= phase && phase < 1.0f) {
            t = (phase - 0.5f) * 2.0f;
            func_L06_00359C38(&q, 0x80800080, 0x04F00060, t);
            func_L06_00359B60(v, &q, D_L20_001DF2CC + t * D_L20_001DF2CC * 0.25f,
                              *(f32 *)(m+0xF0) + t * 0.2617994f);
            func_003D2DA0(&q, mat, 0);
            func_L06_00359B60(v, &q, D_L20_001DF2CC - t * D_L20_001DF2CC * 0.25f,
                              *(f32 *)(m+0xF0) + t * -0.2617994f);
            func_003D2DA0(&q, mat, 0);
        }
        if (0.5f <= phase && phase < 0.7f) {
            t = (phase - 0.5f) / 0.19999999f;
            func_L06_00359C38(&q, 0x102040D0, 0x802050F0, t);
            func_L06_00359B60(v, &q, D_L20_001DF2CC, *(f32 *)(m+0xF0));
            func_003D2DA0(&q, mat, 0);
        }
        if (phase < 0.7f) break;
    case 4:
    case 5:
        func_L06_00359CA8((s32)&q, 0x802050F0);
        func_L06_00359B60(v, &q, D_L20_001DF2CC, *(f32 *)(m+0xF0));
        func_003D2DA0(&q, mat, 0);
        break;
    }
}
