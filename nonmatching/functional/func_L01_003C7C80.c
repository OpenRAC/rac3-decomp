/* functional: high. 42 instructions differ (stack layout and scheduling); same reads, writes and calls. */
typedef struct { f32 x, y, z, w; } fx_v4;
static void fx_add3(void *d, void *a, void *b) { f32 *D=d,*A=a,*B=b; D[0]=A[0]+B[0]; D[1]=A[1]+B[1]; D[2]=A[2]+B[2]; }
static void fx_sub3(void *d, void *a, void *b) { f32 *D=d,*A=a,*B=b; D[0]=A[0]-B[0]; D[1]=A[1]-B[1]; D[2]=A[2]-B[2]; }
static void fx_copy4(void *d, void *s) { f32 *D=d,*S=s; f32 x=S[0],y=S[1],z=S[2],w=S[3]; D[0]=x; D[1]=y; D[2]=z; D[3]=w; }
static void fx_zero4(void *d) { f32 *D=d; D[0]=0.0f; D[1]=0.0f; D[2]=0.0f; D[3]=0.0f; }
extern f32 D_L01_001DECC8_003C7C80;
extern f32 D_L01_001DECCC_003C7C80;
extern f32 D_L01_001DECD0_003C7C80;
__asm__(".extern D_L01_001DECC8_003C7C80, 4");
__asm__(".extern D_L01_001DECCC_003C7C80, 4");
__asm__(".extern D_L01_001DECD0_003C7C80, 4");
extern f32 func_0038CEA8(void *);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CF68(void *, void *, f32);

void func_L01_003C7C80(u8 *obj, void *unused, f32 *from, f32 *out_a, f32 *out_b) {
    fx_v4 diff;
    f32 src[4]; fx_copy4(src, from);
    fx_sub3(&diff, obj + 0x10, src);
    if (D_L01_001DECC8_003C7C80 < func_0038CEA8(&diff)) {
        func_0038CF68(&diff, &diff, D_L01_001DECC8_003C7C80);
    }
    *out_a = func_0038CE68(&diff, obj + 0xD0) * D_L01_001DECCC_003C7C80;
    *out_b = func_0038CE68(&diff, obj + 0xC0) * D_L01_001DECD0_003C7C80;
}
