/* US draft of func_003BFEB0 (rac3-uya-decomp func_003BA9A0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003BFEB0 */
typedef int Q_3BA9A0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BA9A0;
typedef struct { f32 x, y; } V2_3BA9A0;
typedef struct { f32 v[3]; } V3_3BA9A0;
typedef struct { u8 pad[8]; u8 b8; } O_3BA9A0;
__asm__(".extern D_001D8ED8, 4");
__asm__(".extern D_001D8EDC, 4");
__asm__(".extern D_001D8EF0, 4");
__asm__(".extern D_001D8EC0, 4");
__asm__(".extern D_001D8EC4, 4");
__asm__(".extern D_001D8F10, 4");
__asm__(".extern D_001D8EE0, 4");
__asm__(".extern D_001D8F50, 4");
__asm__(".extern D_001D8ED0, 4");
__asm__(".extern D_001D8ED4, 4");
__asm__(".extern D_001D8EC8, 4");
__asm__(".extern D_001D8ECC, 4");
__asm__(".extern D_001D8F70, 4");
extern s32 D_001D8ED8;
extern s32 D_001D8EDC;
extern s32 D_001D8EF0;
extern s32 D_001D8EC0;
extern s32 D_001D8EC4;
extern s32 D_001D8F10;
extern f32 D_001D8EE0;
extern s32 D_001D8F50;
extern f32 D_001D8ED0;
extern f32 D_001D8ED4;
extern s32 D_001D8EC8;
extern s32 D_001D8ECC;
extern s32 D_001D8F70;
extern s32 D_001D8F00_003BFEB0;
extern V4_3BA9A0 D_003800C0[];
extern O_3BA9A0 *D_001DA318_003BFEB0;
extern V2_3BA9A0 D_001DA390_003BFEB0;
extern s32 D_001DA348_003BFEB0;
extern s32 D_001DA378_003BFEB0;
extern V4_3BA9A0 D_00222420[];
extern V4_3BA9A0 D_00222400[];
extern s32 D_001D9D00;
extern f32 D_001DA340;
extern void func_003C2EC0();
extern void func_003A9440(s32, unsigned long);
extern void func_0038C750(void);
extern s32 func_00382468();
extern void func_0038D028();
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE20(f32 *, void *, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_0038CC88();
extern long func_00389598(s32);
extern void func_003D3A24();
extern f32 func_0038CF00(void *, void *);
extern void func_00384DA0();
static __inline__ void vadd_3BA9A0(V4_3BA9A0 *d, V4_3BA9A0 *a, V4_3BA9A0 *b) {
    Q_3BA9A0 x, y;
    __asm__ ("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__ ("lqc2 %0, %1" : "=j"(y) : "m"(*b));
    __asm__ ("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__ ("sqc2 %1, %0" : "=m"(*d) : "j"(x));
}
void func_003BFEB0(void *obj) {
    V4_3BA9A0 m0, m10, m20, m30;
    V4_3BA9A0 m40[4];
    V4_3BA9A0 m80[4];
    s32 base;
    V4_3BA9A0 *e;
    V2_3BA9A0 *dst;
    f32 lim;
    s32 n;
    f32 u;
    s32 i;
    s32 j;
    s32 k;
    O_3BA9A0 **tab;
    f32 s;
    s32 r;
    s32 col;
    f32 t;
    tab = &D_001DA318_003BFEB0;
    func_003A9440(8, 5);
    func_003A9440(0x14, 0xFF9000000260UL);
    func_003A9440(0x47, 0x513F1);
    func_0038C750();
    n = D_001D8ED8 / D_001D8EDC;
    base = (D_001D9D00 + n) % D_001D8ED8;
    base = D_001D9D00 + base / n * n;
    func_003C2EC0((u8 *)obj, 0, (u8 *)m80);
    for (i = 0; i < 6; i++) {
        r = (u8)func_00382468(0xFF);
        (*(O_3BA9A0 **)((u32)tab + (i << 2) + 4))->b8 = r;
        func_0038D028(&m0, &D_003800C0[i], m80);
        for (j = 0; j < D_001D8EDC; j++) {
            e = &D_003800C0[i];
            t = (f32)((base + D_001D8ED8 / D_001D8EDC * j) % D_001D8ED8) / (f32)D_001D8ED8;
            if (0.0f < e->y) func_0038D000(&m10, &D_001D8EF0, m80);
            else func_0038D000(&m10, &D_001D8F00_003BFEB0, m80);
            func_0038CE20((f32 *)&m10, &m10, t);
            vadd_3BA9A0(&m30, &m0, &m10);
            u = 1.0f;
            col = func_0038DBD8(D_001D8EC0, D_001D8EC4, t);
            for (k = 0; k < 4; k++) {
                V4_3BA9A0 *pm = &((V4_3BA9A0 *)&D_001D8F10)[k];
                s32 *pf = &(&D_001DA378_003BFEB0)[k];
                V3_3BA9A0 *pc = &((V3_3BA9A0 *)&D_001DA348_003BFEB0)[k];
                *pf = col;
                m20 = *pm;
                s = D_001D8EE0 * t + u;
                m20.y *= s;
                m20.z *= s;
                func_0038D000(&m40[k], &m20, D_00222420);
                func_0038CE20((f32 *)&m40[k], &m40[k], D_001DA340);
                vadd_3BA9A0(&m40[k], &m40[k], &m30);
                func_0038CC88(pc, &m40[k], 0xC);
                dst = &(&D_001DA390_003BFEB0)[k];
                {
                    f32 *a = (f32 *)&((V2_3BA9A0 *)&D_001D8F50)[k], *b = (f32 *)dst;
                    s32 c;
                    for (c = 1; c != -1; c--) *b++ = *a++;
                }
            }
            func_003A9440(6, func_00389598(0x16));
            func_003A9440(0x42, 0x800000006AUL);
            func_003D3A24(4, &D_001DA348_003BFEB0, &D_001DA378_003BFEB0, &D_001DA390_003BFEB0, 1);
            u = D_001D8ED0 * (1.0f / (func_0038CF00(&m30, D_00222400) + 1.0f));
            lim = D_001D8ED4;
            if (lim < u) u = lim;
            else if (u < -lim) u = -lim;
            col = func_0038DBD8(D_001D8EC8, D_001D8ECC, t);
            for (k = 0; k < 4; k++) {
                (&D_001DA378_003BFEB0)[k] = col;
                func_00384DA0(&m40[k], &(&D_001DA390_003BFEB0)[k], &((f32 *)&D_001DA390_003BFEB0 + 1)[k * 2]);
                (&D_001DA390_003BFEB0)[k].x += ((V2_3BA9A0 *)&D_001D8F70)[k].x * u;
                ((f32 *)&D_001DA390_003BFEB0 + 1)[k * 2] += ((V2_3BA9A0 *)((f32 *)&D_001D8F70 + 1))[k].x * u;
            }
            func_003A9440(6, func_00389598(-1));
            func_003A9440(0x42, 0x8000000054UL);
            func_003D3A24(4, &D_001DA348_003BFEB0, &D_001DA378_003BFEB0, &D_001DA390_003BFEB0, 1);
        }
    }
    func_003A9440(8, 0);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_003BFEB0 */
