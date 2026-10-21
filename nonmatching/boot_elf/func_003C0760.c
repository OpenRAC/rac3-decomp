/* US draft of func_003C0760 (rac3-uya-decomp func_003C0658, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003C0760 */
typedef int Q_3BAE98 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BAE98;
__asm__(".extern D_001D8E60, 4");
__asm__(".extern D_001D8FC8, 4");
__asm__(".extern D_001D8F94, 4");
__asm__(".extern D_001D8E80, 4");
__asm__(".extern D_001D8F9C, 4");
__asm__(".extern D_001D8F98, 4");
__asm__(".extern D_001D8FA0, 4");
__asm__(".extern D_001D8FA4, 4");
__asm__(".extern D_001D8FA8, 4");
__asm__(".extern D_001D8FAC, 4");
__asm__(".extern D_001D8FB8, 4");
__asm__(".extern D_001D8FBC, 4");
__asm__(".extern D_001D8FC0, 4");
__asm__(".extern D_001D8FC4, 4");
__asm__(".extern D_001D8FB0, 4");
__asm__(".extern D_001D8FB4, 4");
__asm__(".extern D_001D8F90, 4");
extern f32 D_001D8E60;
extern f32 D_001D8FC8;
extern s32 D_001D8F94;
extern s32 D_001D8E80;
extern s32 D_001D8F9C;
extern s32 D_001D8F98;
extern f32 D_001D8FA0;
extern f32 D_001D8FA4;
extern f32 D_001D8FA8;
extern f32 D_001D8FAC;
extern f32 D_001D8FB8;
extern f32 D_001D8FBC;
extern f32 D_001D8FC0;
extern f32 D_001D8FC4;
extern s32 D_001D8FB0;
extern s32 D_001D8FB4;
extern s32 D_001D8F90;
extern f32 D_001DA334;
extern s32 D_001D9D00;
extern void func_003C3278();
extern void func_003A97F8(s32, unsigned long);
extern void func_0038CB30(void);
extern void func_0038D408();
extern s32 func_0038DFB8(s32, s32, f32);
extern void func_0038D200(f32 *, void *, f32);
extern void func_003D9AF8(void *, s32, s32, s32, s32, f32);
void func_003C0760(void *p) {
    V4_3BAE98 m0[3];
    V4_3BAE98 m30;
    V4_3BAE98 m40[3];
    V4_3BAE98 m70;
    V4_3BAE98 m80[4];
    f32 k, ph, t, a, b, c, d, s, w;
    s32 i, j, odd, n, col, al, lo;
    Q_3BAE98 x, y;
    u8 ob;
    k = D_001DA334 / (D_001D8E60 * 0.0166666675f);
    if (D_001D8FC8 < k) {
        func_003C3278(p, 0, m80);
        k = 1.0f;
        ph = (f32)(D_001D9D00 % D_001D8F94) / (f32)D_001D8F94;
        func_003A97F8(8, 0);
        func_003A97F8(0x14, 0xFF9000000260UL);
        func_003A97F8(0x47, 0x533F1);
        func_0038CB30();
        for (i = 0; i < 4; i++) {
            *(Q_3BAE98 *)&m0[0] = *(Q_3BAE98 *)&m80[1];
            *(Q_3BAE98 *)&m0[1] = *(Q_3BAE98 *)&m80[2];
            *(Q_3BAE98 *)&m0[2] = *(Q_3BAE98 *)&m80[0];
            func_0038D408(&m30, (V4_3BAE98 *)&D_001D8E80 + i, m80);
            for (j = 0; j < D_001D8F9C; j++) {
                n = D_001D8F98;
                t = (f32)((D_001DA338 + n / D_001D8F9C * j) % n) / (f32)n;
                ob = i & 1;
                if (ob) {
                    t += 0.5f;
                    if (1.0f < t) t -= 1.0f;
                }
                t = t * t;
                if (i < 2) {
                    w = (D_001D8FA4 - D_001D8FA0) * t * k + D_001D8FA0;
                    s = (D_001D8FAC - D_001D8FA8) * t + D_001D8FA8;
                } else {
                    w = (D_001D8FBC - D_001D8FB8) * t * k + D_001D8FB8;
                    s = (D_001D8FC4 - D_001D8FC0) * t + D_001D8FC0;
                }
                col = func_0038DFB8(D_001D8FB0, D_001D8FB4, t);
                lo = col & 0xFFFFFF;
                al = (s32)((f32)((u32)(col & 0xFF000000) >> 24) * k);
                col = lo | (al << 24);
                func_0038D200((f32 *)&m40[0], &m0[0], s);
                func_0038D200((f32 *)&m40[1], &m0[1], s);
                func_0038D200((f32 *)&m40[2], &m0[2], w);
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(m30));
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(m40[2]));
                __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
                __asm__("sqc2 %1, %0" : "=m"(m70) : "j"(x));
                func_003D9AF8(m40, D_001D8F90, col, 4, 1, ph + t + (f32)(i & 1) * 0.5f);
            }
        }
        func_003A97F8(0x47, 0x5360B);
    }
}
/* localdecomp:end func_003C0760 */
