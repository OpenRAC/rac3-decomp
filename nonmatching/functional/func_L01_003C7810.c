/* functional: medium. 147 instructions differ (scheduling and vector-helper register use); same reads, writes and calls; vector helpers written as plain float math. */
typedef struct { f32 x, y, z, w; } fx_v4;
static void fx_add3(void *d, void *a, void *b) { f32 *D=d,*A=a,*B=b; D[0]=A[0]+B[0]; D[1]=A[1]+B[1]; D[2]=A[2]+B[2]; }
static void fx_sub3(void *d, void *a, void *b) { f32 *D=d,*A=a,*B=b; D[0]=A[0]-B[0]; D[1]=A[1]-B[1]; D[2]=A[2]-B[2]; }
static void fx_copy4(void *d, void *s) { f32 *D=d,*S=s; f32 x=S[0],y=S[1],z=S[2],w=S[3]; D[0]=x; D[1]=y; D[2]=z; D[3]=w; }
static void fx_zero4(void *d) { f32 *D=d; D[0]=0.0f; D[1]=0.0f; D[2]=0.0f; D[3]=0.0f; }
extern u8 *D_L01_0021F6C0[];
extern u8 *D_L01_001E0100;
extern f32 D_L01_001DEC70_003C7810;
__asm__(".extern D_L01_001DEC70_003C7810, 4");
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_003C5728(void *, void *, void *, void *);

void func_L01_003C7810(u8 *obj, u8 *s, s32 idx, s32 k, s32 flag) {
    fx_v4 tmp0, tmp1, tmp2;
    f32 d;
    u8 *t = D_L01_0021F6C0[idx];
    *(s32 *)(s + 0xC0) = idx;
    if (flag) {
        fx_copy4(obj + 0x10, t + 0x10);
        fx_sub3(&tmp0, t + 0x20, t + 0x10);
        *(f32 *)(obj + 0xF8) = func_0038D160(tmp0.x, tmp0.y);
        fx_zero4(obj + 0xF0);
        func_L01_003C5728(obj, s, obj + 0x10, obj + 0xF0);
        *(s32 *)(s + 0xC4) = 0;
        fx_copy4(s + 0x140, t + 0x10);
        d = -1.0f;
    } else if (func_0038CF00(obj + 0x10, t + 0x10) < D_L01_001DEC70_003C7810) {
        *(s32 *)(s + 0xC4) = 0;
        fx_copy4(s + 0x140, t + 0x10);
        d = -1.0f;
    } else {
        *(f32 *)(s + 0xC4) = -1.0f;
        fx_copy4(s + 0x140, obj + 0x10);
        d = func_0038CF00(obj + 0x10, t + 0x10);
    }
    *(f32 *)(s + 0x14C) = d;
    if (k != -1) {
        u8 *p = D_L01_001E0100 + k * 128;
        f32 r;
        fx_copy4(s + 0x150, p + 0x30);
        r = func_0038CF00(p + 0x30, t + *(s32 *)t * 16);
        *(f32 *)(t + (*(s32 *)t - 1) * 16 + 0x1C) = r;
        func_0038CF68(s + 0x160, p, 10.0f);
        fx_add3(s + 0x160, s + 0x160, p + 0x30);
        *(f32 *)(s + 0x15C) = func_0038CF00(s + 0x160, p + 0x30);
        *(f32 *)(s + 0x16C) = 5.0f;
    } else {
        fx_sub3(&tmp1, t + *(s32 *)t * 16, t + (*(s32 *)t - 1) * 16);
        func_0038CF68(&tmp1, &tmp1, 0.1f);
        *(f32 *)(t + (*(s32 *)t - 1) * 16 + 0x1C) = 0.1f;
        fx_copy4(&tmp2, &tmp1);
        fx_add3(s + 0x150, t + *(s32 *)t * 16, &tmp1);
        *(f32 *)(s + 0x15C) = 0.1f;
        fx_add3(s + 0x160, s + 0x150, &tmp2);
        *(f32 *)(s + 0x16C) = 0.1f;
    }
    fx_zero4(s + 0x130);
}
