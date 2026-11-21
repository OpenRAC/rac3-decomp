/* functional: high. Particle/trail effect draw, run while the effect time k = D_001DA334 / (D_001D8E60/60) exceeds D_001D8FC8 (k is then clamped to 1.0): gets 3 basis vectors from func_003C2EC0(p,0,m80), sets GS state (func_003A9440 0x08/0x14/0x47), and for each of 4 rings (i) draws D_001D8F9C quads: phase t (time-offset along D_001D8F98, +0.5 for odd rings, squared) interpolates width w and size s between two parameter sets (rings 0,1 use D_001D8FA0..AC, rings 2,3 D_001D8FB8..C4), colour from func_0038DBD8(D_001D8FB0,D_001D8FB4,t) with its alpha scaled by k, builds three scaled basis vectors m40[0..2] (s, s, w) and m40[3] = m30 - m40[2] (xyz; w = m30.w, as the VU vsub.xyz), then func_003D9740(m40, D_001D8F90, col, 4, 1, ph + t + (i&1)*0.5); ends with func_003A9440(0x47, 0x5360B). US draft re-verified against the PAL asm: gp offsets map to D_001D8Exx/8Fxx as named; the draft's COP2 inline asm replaced by plain C (m70 kept: it is the 4th vector of the block passed to func_003D9740, which may read it). */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003C03A8;
extern f32 D_001D8E60;
extern f32 D_001D8FC8;
extern s32 D_001D8F94;
extern V4_003C03A8 D_001D8E80[];
extern s32 D_001D8F9C;
extern s32 D_001D8F98;
extern f32 D_001D8FA0, D_001D8FA4, D_001D8FA8, D_001D8FAC;
extern f32 D_001D8FB8, D_001D8FBC, D_001D8FC0, D_001D8FC4;
extern s32 D_001D8FB0, D_001D8FB4, D_001D8F90;
extern f32 D_001DA334;
extern s32 D_001DA338;
extern s32 D_001D9D00;
extern void func_003C2EC0();
extern void func_003A9440(s32, unsigned long);
extern void func_0038C750(void);
extern void func_0038D028();
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D9740(void *, s32, s32, s32, s32, f32);

void func_003C03A8(void *p)
{
    V4_003C03A8 m0[3];
    V4_003C03A8 m30;
    V4_003C03A8 m40[4];
    V4_003C03A8 m80[4];
    f32 k, ph, t, w, s;
    s32 i, j, n, col, al, lo;

    k = D_001DA334 / (D_001D8E60 * 0.0166666675f);
    if (D_001D8FC8 < k) {
        func_003C2EC0(p, 0, m80);
        k = 1.0f;
        ph = (f32)(D_001D9D00 % D_001D8F94) / (f32)D_001D8F94;
        func_003A9440(8, 0);
        func_003A9440(0x14, 0xFF9000000260UL);
        func_003A9440(0x47, 0x533F1);
        func_0038C750();
        for (i = 0; i < 4; i++) {
            m0[0] = m80[1];
            m0[1] = m80[2];
            m0[2] = m80[0];
            func_0038D028(&m30, &D_001D8E80[i], m80);
            for (j = 0; j < D_001D8F9C; j++) {
                n = D_001D8F98;
                t = (f32)((D_001DA338 + n / D_001D8F9C * j) % n) / (f32)n;
                if (i & 1) {
                    t += 0.5f;
                    if (1.0f < t) {
                        t -= 1.0f;
                    }
                }
                t = t * t;
                if (i < 2) {
                    w = (D_001D8FA4 - D_001D8FA0) * t * k + D_001D8FA0;
                    s = (D_001D8FAC - D_001D8FA8) * t + D_001D8FA8;
                } else {
                    w = (D_001D8FBC - D_001D8FB8) * t * k + D_001D8FB8;
                    s = (D_001D8FC4 - D_001D8FC0) * t + D_001D8FC0;
                }
                col = func_0038DBD8(D_001D8FB0, D_001D8FB4, t);
                lo = col & 0xFFFFFF;
                al = (s32)((f32)((u32)(col & 0xFF000000) >> 24) * k);
                col = lo | (al << 24);
                func_0038CE20(&m40[0], &m0[0], s);
                func_0038CE20(&m40[1], &m0[1], s);
                func_0038CE20(&m40[2], &m0[2], w);
                m40[3].x = m30.x - m40[2].x;
                m40[3].y = m30.y - m40[2].y;
                m40[3].z = m30.z - m40[2].z;
                m40[3].w = m30.w;
                func_003D9740(m40, D_001D8F90, col, 4, 1, ph + t + (f32)(i & 1) * 0.5f);
            }
        }
        func_003A9440(0x47, 0x5360B);
    }
}
