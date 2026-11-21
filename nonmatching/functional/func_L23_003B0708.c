/* functional: high. Same packet fields and calls; frame size and register allocation differ. */
typedef struct {
    V4 m[4];
    s32 c40, c44, c48, c4C;
    s32 x50, x54, x58;
    f32 x5C, x60;
    s32 x64;
    f32 x68, x6C;
    long x70, x78, x80, x88;
} S_3B0708;
extern long func_00389598(s32);
extern void func_003D2DA0(S_3B0708 *, V4 *, s32);
extern s32 D_L23_001DE274;
__asm__(".extern D_L23_001DE274, 4");

void func_L23_003B0708(void *pa, void *pb, s32 n, s32 idx, s32 unused, s32 col, s32 a6, s32 a7, s32 tex)
{
    V4 *A = pa;
    V4 *B = pb;
    S_3B0708 s;
    s32 i;
    s32 j;
    s32 last;
    s32 t;
    s32 alpha1;
    s32 alpha2;

    s.x78 = func_00389598(tex);
    col &= 0xFFFFFF;
    last = n - 1;
    s.m[3] = A[idx];
    s.m[2] = B[idx];
    s.c48 = col | (a7 << 24);
    s.c4C = col | (a6 << 24);
    s.x70 = 4;
    s.x80 = 0xFF9000000260L;
    s.x88 = 0x8000000048L;
    s.x50 = 0;
    s.x54 = 0;
    s.x58 = 0;
    s.x5C = 1.0f;
    s.x60 = 1.0f;
    s.x64 = 0;
    s.x68 = 1.0f;
    s.x6C = 1.0f;
    j = idx - 1;
    for (i = 1; i <= last; i++) {
        if (j < 0) {
            j = D_L23_001DE274 - 1;
        }
        t = last - i;
        alpha1 = a7 * t / last;
        alpha2 = a6 * t / last;
        if (i & 1) {
            s.c40 = col | (alpha1 << 24);
            s.c44 = col | (alpha2 << 24);
            s.m[0] = B[j];
            s.m[1] = A[j];
        } else {
            s.c48 = col | (alpha1 << 24);
            s.c4C = col | (alpha2 << 24);
            s.m[2] = B[j];
            s.m[3] = A[j];
        }
        func_003D2DA0(&s, 0, 1);
        j--;
    }
}
