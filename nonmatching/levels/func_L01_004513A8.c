/* func_L01_004513A8: 11 diff with split addresses and Ps2EeAs (check.py --mode S --as ps2as); 114 with
   L01_00451388.c's flags (N mode, default assembler) and 57 with N mode under Ps2EeAs. Retail splits the
   addresses of D_L01_001EAA20 itself (lui $s0, %hi shared by an addiu and an lq; lui %hi(D + 8) for the .z load)
   and builds 0.01f inline, so the function needs S mode and @ps2as. func_L01_00451388 and func_L01_004515D8 also
   match that way, func_L01_00451580 does not (19 diff in S mode), so it needs a cut 0x4513A8..0x451580. Left in
   S mode: in the first branch gcc CSEs &D_L01_001EAA20 from the copy for the .z load (lwc1 8($v0)) where retail
   rebuilds %hi(D + 8), and the order of the D_L01_001DFC50 lq and the D_L01_001D6740 test. */
typedef int Q_004513A8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_004513A8;
extern s32 D_L01_001D673C;
extern s32 D_L01_001D6740[];
extern u8 D_L01_001DFC50[];
extern V_004513A8 D_L01_001EAA20;
extern s32 func_L01_003FA5F0(void *, void *, s32, void *, s32);
extern void func_L01_00451308(void *, void *, void *, f32);
extern f32 func_L01_0040E4E0(void *, void *);

f32 func_L01_004513A8(V_004513A8 *p, void *a1, V_004513A8 *out) {
    V_004513A8 a;
    V_004513A8 b;
    f32 d;
    f32 e;
    if (D_L01_001D673C == 0) {
        *(Q_004513A8 *)&b = *(Q_004513A8 *)p;
        *(Q_004513A8 *)&a = *(Q_004513A8 *)p;
        b.z += 0.5f;
        a.z = 0.01f;
        if (func_L01_003FA5F0(&b, &a, 2, a1, 0) != 0) {
            if (out != 0) {
                *(Q_004513A8 *)out = *(Q_004513A8 *)&D_L01_001EAA20;
            }
            return p->z - D_L01_001EAA20.z;
        }
        if (out != 0) {
            *(Q_004513A8 *)out = *(Q_004513A8 *)p;
        }
        return p->z;
    }
    *(Q_004513A8 *)&a = *(Q_004513A8 *)D_L01_001DFC50;
    if (D_L01_001D6740[0] != 0) {
        *(Q_004513A8 *)&a = *(Q_004513A8 *)p;
        func_L01_00451308(&a, &a, &a, -10.0f);
    }
    func_L01_00451308(p, &b, p, -0.5f);
    d = func_L01_0040E4E0(p, &a);
    if (func_L01_003FA5F0(&b, &a, 2, a1, 0) != 0) {
        if (out != 0) {
            *(Q_004513A8 *)out = *(Q_004513A8 *)&D_L01_001EAA20;
        }
        e = func_L01_0040E4E0(p, &D_L01_001EAA20);
        if (d < func_L01_0040E4E0(&D_L01_001EAA20, &a)) {
            e = -e;
        }
        return e;
    }
    if (out != 0) {
        *(Q_004513A8 *)out = *(Q_004513A8 *)p;
    }
    return d;
}
