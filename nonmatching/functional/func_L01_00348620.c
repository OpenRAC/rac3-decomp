/* functional: high. Near miss (209 words): VU0 interleaving and register allocation only; every read, write, call, constant verified against the retail asm. */
/* localdecomp:start func_L01_00348620 */
#include "vu0.h"
typedef struct {
    vu0_v4 vertices[4];
    u32 colors[4];
    f32 uv[4][2];
    long mode, texture, alpha, bits;
} Packet_00348620;
typedef struct { vu0_v4 pos; u8 rest[0x20]; } Point_00348620;
extern s32 D_L01_001DD348, D_L01_001DD34C;
extern f32 D_L01_001DD340, D_L01_001DD33C;
extern u32 D_L01_001DD32C, D_L01_001DD334, D_L01_001DD330, D_L01_001DD338;
typedef struct { u8 pad0[0x16B0]; s32 mode; u8 pad16B4[0x25C4-0x16B4]; s32 state; } Hero_00348620;
extern Hero_00348620 D_001A4BE0;
extern vu0_v4 D_L01_001E29C0[];
static __inline__ void sub_ab_00348620(void *d, void *a, void *b)
{
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
static __inline__ void sub_ba_00348620(void *d, void *a, void *b)
{
    __asm__("lqc2 $vf1, %2\n\tlqc2 $vf2, %1\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
static __inline__ void add_ab_00348620(void *d, void *a, void *b)
{
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
static __inline__ void add_ba_00348620(void *d, void *a, void *b)
{
    __asm__("lqc2 $vf1, %2\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
__asm__(".extern D_L01_001DD348, 4");
__asm__(".extern D_L01_001DD34C, 4");
__asm__(".extern D_L01_001DD340, 4");
__asm__(".extern D_L01_001DD33C, 4");
__asm__(".extern D_L01_001DD32C, 4");
__asm__(".extern D_L01_001DD334, 4");
__asm__(".extern D_L01_001DD330, 4");
__asm__(".extern D_L01_001DD338, 4");
void func_L01_00348620(u8 *obj)
{
    extern char *func_L01_00457480(s32,s32);
    extern void func_003D93B0(void *,s32,s32,s32);
    extern void func_0038CE90(void *,void *,void *);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_0038CE20(f32 *,f32 *,f32);
    extern s32 func_0038DBD8(s32,s32,f32);
    extern void func_003D2DA0(void *,void *,s32);
    Packet_00348620 core, glow;
    vu0_v4 normal, width, view, tangent;
    u32 end_core;
    u8 *vars = *(u8 **)(obj+0x68);
    Point_00348620 *points;
    f32 strength, step, t;
    u32 begin_core, begin_glow, end_glow;
    s32 i;
    if (*(s16 *)(vars+0x20)<2 || *(s16 *)(vars+0x22)==0) return;
    points = *(Point_00348620 **)(func_L01_00457480(0xC04,*(s16 *)(vars+0x1A)) + *(s16 *)(vars+0x18)*4);
    func_003D93B0(&core,D_L01_001DD348,1,0x80);
    core.uv[0][0]=0.0f;
    core.uv[0][1]=0.0f;
    core.uv[1][0]=0.0f;
    core.uv[1][1]=1.0f;
    core.uv[2][0]=1.0f;
    core.uv[2][1]=0.0f;
    core.uv[3][0]=1.0f;
    core.uv[3][1]=1.0f;
    core.uv[0][0]+=D_L01_001DD340;
    core.uv[1][0]+=D_L01_001DD340;
    core.uv[2][0]+=D_L01_001DD340;
    core.uv[3][0]+=D_L01_001DD340;
    func_003D93B0(&glow,D_L01_001DD34C,1,0x80);
    glow.uv[0][0]=0.0f;
    glow.uv[0][1]=0.0f;
    glow.uv[1][0]=0.0f;
    glow.uv[1][1]=1.0f;
    glow.uv[2][0]=1.0f;
    glow.uv[2][1]=0.0f;
    glow.uv[3][0]=1.0f;
    glow.uv[3][1]=1.0f;
    glow.uv[0][0]+=D_L01_001DD340;
    glow.uv[1][0]+=D_L01_001DD340;
    glow.uv[2][0]+=D_L01_001DD340;
    glow.uv[3][0]+=D_L01_001DD340;
    strength=*(s16 *)(vars+0x22)**(f32 *)(vars+0x24);
    if (D_001A4BE0.state==0x1D || D_001A4BE0.mode!=0) strength*=0.5f;
    begin_core = (D_L01_001DD32C&0xFFFFFF)|((s32)((s32)(D_L01_001DD32C>>24)*strength)<<24);
    end_core = (D_L01_001DD334&0xFFFFFF)|((s32)((s32)(D_L01_001DD334>>24)*strength)<<24);
    begin_glow = (D_L01_001DD330&0xFFFFFF)|((s32)((s32)(D_L01_001DD330>>24)*strength)<<24);
    end_glow = (D_L01_001DD338&0xFFFFFF)|((s32)((s32)(D_L01_001DD338>>24)*strength)<<24);
    core.colors[0]=core.colors[1]=begin_core;
    glow.colors[0]=glow.colors[1]=begin_glow;
    sub_ab_00348620(&view,points,D_L01_001E29C0);
    sub_ba_00348620(&tangent,points+1,points);
    func_0038CE90(&normal,&tangent,&view);
    func_0038CF68(&width,&normal,points->pos.w);
    add_ab_00348620(&core.vertices[0],points,&width);
    sub_ab_00348620(&core.vertices[1],points,&width);
    func_0038CE20((f32 *)&width,(f32 *)&width,D_L01_001DD33C);
    add_ba_00348620(&glow.vertices[0],points,&width);
    sub_ab_00348620(&glow.vertices[1],points,&width);
    step=1.0f / *(s16 *)(vars+0x20);
    points++;
    for(i=1;i<*(s16 *)(vars+0x20);i++,points++) {
        sub_ba_00348620(&view,points,D_L01_001E29C0);
        sub_ba_00348620(&tangent,points,points-1);
        func_0038CE90(&normal,&tangent,&view);
        func_0038CF68(&width,&normal,points->pos.w);
        add_ab_00348620(&core.vertices[2],points,&width);
        sub_ab_00348620(&core.vertices[3],points,&width);
        func_0038CE20((f32 *)&width,(f32 *)&width,D_L01_001DD33C);
        add_ab_00348620(&glow.vertices[2],points,&width);
        sub_ab_00348620(&glow.vertices[3],points,&width);
        t=i*step;
        core.colors[2]=core.colors[3]=func_0038DBD8(begin_core,end_core,t);
        glow.colors[2]=glow.colors[3]=func_0038DBD8(begin_glow,end_glow,t);
        func_003D2DA0(&core,0,0);
        func_003D2DA0(&glow,0,0);
        *(vu0_q *)&core.vertices[0]=*(vu0_q *)&core.vertices[2];
        *(vu0_q *)&core.vertices[1]=*(vu0_q *)&core.vertices[3];
        *(vu0_q *)&glow.vertices[0]=*(vu0_q *)&glow.vertices[2];
        *(vu0_q *)&glow.vertices[1]=*(vu0_q *)&glow.vertices[3];
        core.colors[0]=core.colors[1]=core.colors[2];
        glow.colors[0]=glow.colors[1]=glow.colors[2];
    }
}
/* localdecomp:end func_L01_00348620 */
