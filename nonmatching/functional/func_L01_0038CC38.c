/* functional: high. Codex near-miss draft re-verified: 4 words differ with the file's flags (VU add vs lwc1 scheduling only), behaviour identical. Uses inline VU0 vadd.xyz. */
#include "common.h"
typedef struct {
    S_38C110v velocity;
    u8 pad10[0x2C];
    s32 alpha;
} Vars_0038CC38;
typedef struct {
    u8 pad0[0x10];
    S_38C110v position;
    u8 state;
    u8 pad21[0x47];
    Vars_0038CC38 *vars;
    u8 pad6C[0x3E];
    s16 class_id;
} Moby_0038CC38;
extern f32 D_001DDF48_sda, D_001DDF44_sda, D_001DDF40_sda;
extern s32 D_001DDF3C_sda;
__asm__(".extern D_001DDF48_sda, 4");
__asm__(".extern D_001DDF44_sda, 4");
__asm__(".extern D_001DDF40_sda, 4");
__asm__(".extern D_001DDF3C_sda, 4");
extern f32 D_L01_001E1F18;
void func_L01_0038CC38(Moby_0038CC38 *moby) {
    extern f32 func_0038CED8(S_38C110v *);
    extern f32 func_0038D160(f32,f32);
    extern void func_0038D328(s128 *,S_38C110v *);
    extern void func_0038CE20(s128 *,s128 *,f32);
    extern void func_003D9740(s128 *,s32,u32,s32,s32,f32);
    s128 matrix[4];
    S_38C110v pos,vel,rot,offset;
    Vars_0038CC38 *vars;
    long state;
    if (moby != 0 && (state=moby->state) != 0xFE && state != 0xFD && moby->class_id == 0x1888) {
    pos=moby->position;
    vars=moby->vars;
    vel=vars->velocity;
    rot.x=0.0f;
    rot.y=-func_0038D160(func_0038CED8(&vel),vel.z) + -1.5707963705062866f;
    rot.z=func_0038D160(vel.x,vel.y);
    rot.w=1.0f;
    func_0038D328(matrix,&rot);
    offset=vars->velocity;
    func_0038CE20((s128 *)&offset,(s128 *)&offset,5.0f);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(pos) : "m"(pos), "m"(offset) : "vf1", "vf2");
    *(S_38C110v *)&matrix[3]=pos;
    func_0038CE20(&matrix[0],&matrix[0],D_001DDF48_sda);
    func_0038CE20(&matrix[1],&matrix[1],D_001DDF44_sda);
    func_0038CE20(&matrix[2],&matrix[2],D_001DDF40_sda);
    D_L01_001E1F18 += 0.2f;
    if (D_L01_001E1F18 >= 7.0f) D_L01_001E1F18 -= 7.0f;
    func_003D9740(matrix,D_001DDF3C_sda,(vars->alpha * 3 << 24) | 0x008080FF,4,1,D_L01_001E1F18);
    }
}
