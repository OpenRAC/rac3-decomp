/* functional: medium. compiles; 291 diff lines (regalloc/frame); a1 quad is read by retail but never used afterwards, dropped; quad descriptor layout as func_L01_003AEB68; renderer packet builder - port may replace */
static void fx_add3(void *d, void *a, void *b) { f32 *D=d,*A=a,*B=b; D[0]=A[0]+B[0]; D[1]=A[1]+B[1]; D[2]=A[2]+B[2]; }
static void fx_sub3(void *d, void *a, void *b) { f32 *D=d,*A=a,*B=b; D[0]=A[0]-B[0]; D[1]=A[1]-B[1]; D[2]=A[2]-B[2]; }
static void fx_copy4(void *d, void *s) { f32 *D=d,*S=s; f32 x=S[0],y=S[1],z=S[2],w=S[3]; D[0]=x; D[1]=y; D[2]=z; D[3]=w; }
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L01_00443A18(f32, f32);
extern long func_00389598(s32);
extern void func_003D2DA0(void *, s32, s32);
extern u8 D_L01_001E29C0[];
extern f32 D_L01_001DE610[];
extern f32 D_L01_001DE614[];

void func_L01_003B1870(char *obj_, void *unused) {
    u8 *p = *(u8 **)(obj_ + 0x68);
    f32 q[36] __attribute__((aligned(16)));   /* quad descriptor: corners q[0..15], colours q[16..19], uv q[20..27], tex at q+30, flags at q+32/34 */
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    f32 cam[4] __attribute__((aligned(16)));
    f32 f23;
    f32 age;
    s32 col;
    int k;

    f23 = *(f32 *)(p + 0x54);
    age = *(f32 *)(p + 0x38);
    if (84.0f < age) {
        f23 = f23 * (1.0f - (age - 84.0f) / 6.0f);
        if (f23 < 0.001f) {
            f23 = 0.001f;
        }
    }

    /* first ribbon */
    fx_sub3(c, p, p + 0x10);
    fx_sub3(a, p, D_L01_001E29C0);
    fx_sub3(b, p + 0x10, D_L01_001E29C0);
    func_0038CE90(a, a, c);
    func_0038CF68(a, a, (*(f32 *)(p + 0x54) + func_L01_00443A18(0.1f, 0.3f)) * f23);
    func_0038CE90(b, b, c);
    func_0038CF68(b, b, (*(f32 *)(p + 0x54) + func_L01_00443A18(0.1f, 0.3f)) * f23);
    *(long *)(q + 32) = 0x0000FF9000000260L;
    *(long *)(q + 34) = 0x0000003000000048L;
    *(long *)(q + 30) = func_00389598(0x3E);
    *(long *)(q + 28) = 0;
    col = *(s32 *)(p + 0x44);
    ((s32 *)q)[16] = col;
    ((s32 *)q)[17] = col;
    ((s32 *)q)[18] = col;
    ((s32 *)q)[19] = col;
    for (k = 0; k < 4; k++) {
        q[20 + k * 2] = D_L01_001DE610[k * 2];
        q[21 + k * 2] = D_L01_001DE614[k * 2];
    }
    fx_sub3(q + 0, p, a);
    fx_add3(q + 4, p, a);
    fx_sub3(q + 8, p + 0x10, b);
    fx_add3(q + 12, p + 0x10, b);
    func_003D2DA0(q, 0, 0);

    /* second, thinner ribbon */
    fx_sub3(c, p, p + 0x10);
    fx_copy4(cam, D_L01_001E29C0);
    fx_sub3(a, p, D_L01_001E29C0);
    fx_sub3(b, p + 0x10, cam);
    func_0038CE90(a, a, c);
    func_0038CF68(a, a, (*(f32 *)(p + 0x54) * 0.5f + func_L01_00443A18(0.05f, 0.15f)) * f23);
    func_0038CE90(b, b, c);
    func_0038CF68(b, b, (*(f32 *)(p + 0x54) * 0.5f + func_L01_00443A18(0.05f, 0.15f)) * f23);
    *(long *)(q + 32) = 0x0000FF9000000260L;
    *(long *)(q + 34) = 0x0000003000000048L;
    *(long *)(q + 30) = func_00389598(0x3F);
    *(long *)(q + 28) = 0;
    col = *(s32 *)(p + 0x48);
    ((s32 *)q)[16] = col;
    ((s32 *)q)[17] = col;
    ((s32 *)q)[18] = col;
    ((s32 *)q)[19] = col;
    for (k = 0; k < 4; k++) {
        q[20 + k * 2] = D_L01_001DE610[k * 2];
        q[21 + k * 2] = D_L01_001DE614[k * 2];
    }
    fx_sub3(q + 0, p, a);
    fx_add3(q + 4, p, a);
    fx_sub3(q + 8, p + 0x10, b);
    fx_add3(q + 12, p + 0x10, b);
    func_003D2DA0(q, 0, 0);
}
