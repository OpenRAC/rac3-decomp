/* functional: high. One frame as retail's (0xC0: a at sp+0, b +0x10, query c +0x20, d +0x50, e +0x60): func_L01_00446760 leaves c's bytes 0x18/0x19 unset and func_003D3CB0 reads them, so they must be the same stack garbage as retail's; PAL constants are 0x3ECCCCCE/0xBECCCCCE/0x3DA3D70B (one ulp off 0.4f/0.08f) and the first vadd.xyz stores p+0's w into p+0x1C, both kept; rewritten from PAL asm (the repo draft is the NTSC-U twin with different callees); the two retail copies of the bounce block unified (one frame, no helper call) (phase 2 passes obj instead of obj+0xB8 as 4th arg of func_003D3CB0, kept); 242 diff lines (regalloc/frame) */
static __inline__ void fx_add3(void *d, void *a, void *b) { f32 *D=d,*A=a,*B=b; D[0]=A[0]+B[0]; D[1]=A[1]+B[1]; D[2]=A[2]+B[2]; }
/* vadd.xyz into the register loaded from a: the stored w is a's */
static __inline__ void fx_add3w(void *d, void *a, void *b) { f32 *D=d,*A=a,*B=b; f32 w=A[3]; D[0]=A[0]+B[0]; D[1]=A[1]+B[1]; D[2]=A[2]+B[2]; D[3]=w; }
static __inline__ void fx_copy4(void *d, void *s) { f32 *D=d,*S=s; f32 x=S[0],y=S[1],z=S[2],w=S[3]; D[0]=x; D[1]=y; D[2]=z; D[3]=w; }
extern f32 func_00382538(void);
extern void func_L01_0046A610(void *, void *, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern s32 func_L01_00456250(void *);
extern void func_L01_00456230(void *, s32);
extern void func_L01_003B1D10(void *, s32, s32);
extern void func_L01_003B1DB8(void *);
extern void func_L01_00404A10(void *, u8 *);
extern void func_L01_003B1848(void);
extern void func_003C2880(void *);
extern u8 D_L01_001D66B0[];
extern u8 D_L01_001EAA00[];

void func_L01_003B1358(u8 *o) {
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    u8 c[0x30] __attribute__((aligned(16)));
    f32 d[4] __attribute__((aligned(16)));
    f32 e[4] __attribute__((aligned(16)));
    u8 *p = *(u8 **)(o + 0x68);
    u8 *g;
    f32 f20;
    f32 age;
    s32 rot;

    f20 = *(f32 *)(p + 0x3C);
    age = *(f32 *)(p + 0x38) + 1.0f;
    *(f32 *)(p + 0x38) = age;
    if (84.0f < age) {
        f20 = f20 * (1.0f - (age - 84.0f) / 6.0f);
    }
    if (2.0f < age) {
        fx_copy4(a, p + 0x10);
    } else {
        fx_copy4(a, p);
    }
    rot = (s32)func_00382538();
    func_L01_0046A610(p + 0x10, D_L01_001D66B0, 210000.0f, 200.0f, 0.949999988f, 0.0f, 0.0f,
                      3, 0x60, *(s32 *)(p + 0x50), rot);
    age = *(f32 *)(p + 0x38);
    if (age < 15.0f) {
        *(f32 *)(p + 0x34) = *(f32 *)(p + 0x34) + 0.400000036f;
        func_0038CF68(p + 0x10, p + 0x20, *(f32 *)(p + 0x34));
        func_0038CF68(b, p + 0x20, 0.0800000057f);
        func_L01_00446760(c, o, 0x10000, b, f20);
        *(u16 *)(c + 0x1A) = *(u16 *)(o + 0xAA);
        fx_add3w(p + 0x10, p, p + 0x10);
        func_0038CF68(d, p + 0x20, -0.400000036f);
        fx_add3(d, d, p + 0x10);
        if (func_003D3CB0(p + 0x10, a, 0x10, *(s32 *)(o + 0xB8), (s32)c) != 0) {
            g = D_L01_001EAA00;
            if (*(s32 *)(g + 0x18) != *(s32 *)(o + 0xB8)) {
                if (*(s32 *)(g + 0x18) == 0) {
                    goto take;
                }
                if (*(s16 *)(*(u8 **)(g + 0x18) + 0xAA) != 0x1C7F) {
                    goto take;
                }
            }
        }
        func_0038CF68(e, p + 0x20, 0.400000036f);
    } else if (age < 90.0f) {
        if (!(0.400000036f < func_0038CF38(p, p + 0x10))) {
            return;
        }
        *(f32 *)(p + 0x34) = *(f32 *)(p + 0x34) + 0.400000036f;
        func_0038CF68(p + 0x10, p + 0x20, *(f32 *)(p + 0x34));
        func_0038CF68(b, p + 0x20, 0.0800000057f);
        func_L01_00446760(c, o, 0x10000, b, f20);
        *(u16 *)(c + 0x1A) = *(u16 *)(o + 0xAA);
        fx_add3w(p + 0x10, p, p + 0x10);
        func_0038CF68(d, p + 0x20, -0.400000036f);
        fx_add3(d, d, p + 0x10);
        if (func_003D3CB0(p + 0x10, a, 0x10, (s32)o, (s32)c) != 0) {
            g = D_L01_001EAA00;
            if (*(s32 *)(g + 0x18) != *(s32 *)(o + 0xB8)) {
                if (*(s32 *)(g + 0x18) == 0) {
                    goto take;
                }
                if (*(s16 *)(*(u8 **)(g + 0x18) + 0xAA) != 0x1625) {
                    goto take;
                }
            }
        }
        func_0038CF68(e, p + 0x20, 1.00000012f);
    } else {
        func_L01_003B1DB8(p + 0x10);
        func_003C2880(o);
        return;
    }
    fx_add3(p, p, e);
    func_L01_00404A10(func_L01_003B1848, o);
    return;
take:
    fx_copy4(p + 0x10, g + 0x20);
    if (func_L01_00456250(o) == 0) {
        func_L01_003B1D10(g + 0x20, 0x14, *(s32 *)(p + 0x4C));
        func_L01_00456230(o, 1);
    }
    func_003C2880(o);
}
