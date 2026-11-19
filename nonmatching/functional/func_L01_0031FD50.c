/* functional: medium. Near-miss draft from the PAL assembly (Codex waves), re-checked at level 01: compiles in the file context with relocations resolved (callees/globals as retail); 188 words differ in VU0 sequences; goto structure kept from the draft; not byte-identical, behaviour as retail. */
typedef int Q_0031FD50 __attribute__((mode(TI)));
typedef union { Q_0031FD50 q; f32 f[4]; } V_0031FD50 __attribute__((aligned(16)));
extern D_31DB28 D_L01_001EAA00[];
void func_L01_0031FD50(u8 *obj)
{
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
    extern void func_L01_004AAC98(s32, s32, u8 *, s32);
    extern s32 func_003D3CB0(void *, void *, s32, u8 *, s32);
    extern void func_L01_0040E790(void *, void *, void *);
    extern void func_0038CF68(f32 *, s32, f32);
    extern s32 func_0038CAD0(s32);
    extern f32 func_0038CEA8(void *);
    extern void func_003C2880(Moby_0031BEF0 *);
    extern void func_L01_003303B8(float, u8 *,
                              s32, s32, s32, s32, s32, s32, s32,
                              s32, s32, s32, s32, s32, s32, s32,
                              s32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
                              float, float, float);
    V_0031FD50 old, drag, correction, position, up;
    u8 *vars = *(u8 **)(obj + 0x68);
    u8 *hit;
    u8 *collision;
    if (vars == 0) return;
    old.q = *(Q_0031FD50 *)(obj + 0x10);
    __asm__("lqc2 $vf1,%2\n\tsqc2 $vf1,%0\n\tvmr32.xyzw $vf2,$vf0\n\tsqc2 $vf2,%1"
        : "=m"(position), "=m"(up) : "m"(*(V_0031FD50 *)(obj+0x10)) : "vf1", "vf2");
    __asm__("lqc2 $vf1,%2\n\tlqc2 $vf2,%3\n\tvadd.xyz $vf1,$vf1,$vf2\n\tlqc2 $vf2,%4\n\tsqc2 $vf2,%0\n\tsqc2 $vf1,%1"
        : "=m"(drag), "=m"(*(V_0031FD50 *)(obj+0x10)) : "m"(*(V_0031FD50 *)vars), "m"(position), "m"(up) : "vf1", "vf2");
    func_0038CE20(&drag, &drag, 0.0044f);
    __asm__("lqc2 $vf1,%0\n\tlqc2 $vf2,%1\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0"
        : "+m"(*(V_0031FD50 *)vars) : "m"(drag) : "vf1", "vf2");
    if (func_L01_003FB640(obj+0x10,0,obj,0.1f)) {
        func_L01_004AAC98(2,0,obj,*(s16 *)(obj+0xAA));
        collision = (u8 *)D_L01_001EAA00;
        hit = *(u8 **)(collision+0x18);
        if (hit != 0) goto hit_test;
        goto reflect;
    } else if (func_003D3CB0(&old,obj+0x10,0x10,obj,0)) {
        func_L01_004AAC98(2,0,obj,*(s16 *)(obj+0xAA));
        collision = (u8 *)D_L01_001EAA00;
        hit = *(u8 **)(collision+0x18);
        if (hit != 0) {
hit_test:
            if ((u32)(*(u16 *)(hit+0xAA)-0x109E) < 2) goto finish;
            if (hit == *(u8 **)(obj+0xB8)) goto finish;
reflect:
            *(Q_0031FD50 *)(obj+0x10) = *(Q_0031FD50 *)(collision+0x30);
            func_L01_0040E790(vars,vars,collision+0x40);
            *(f32 *)(vars+8) += *(f32 *)(vars+8);
            func_0038CE20(vars,vars,0.25000003f);
        } else {
            *(Q_0031FD50 *)(obj+0x10) = *(Q_0031FD50 *)(collision+0x20);
            func_0038CF68(correction.f,(s32)(collision+0x40),0.1f);
            __asm__("lqc2 $vf1,%0\n\tlqc2 $vf2,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0"
                : "+m"(*(V_0031FD50 *)(obj+0x10)) : "m"(correction) : "vf1", "vf2");
            func_L01_0040E790(vars,vars,collision+0x40);
            *(f32 *)(vars+8) += *(f32 *)(vars+8);
            func_0038CE20(vars,vars,0.25000003f);
        }
    }
finish:
    if (func_0038CAD0((s32)(vars+0x18)) || func_0038CEA8(vars)<0.010000001f) {
        func_L01_004AAC98(1,0,obj,*(s16 *)(obj+0xAA));
        func_L01_003303B8(1.5f,obj+0x10,1,10,10,10,10,30,0,
            0,1,0,0,0,0,0x10001,0,0x804020,0x806040,0x407FFF,0x20FF,
            0x8FFF,0x3064FF,0x7F804020,0x28802020,0xFF6020,0,
            0.0f,*(f32 *)(vars+0x20),2.0f);
        func_003C2880((Moby_0031BEF0 *)obj);
    }
}
