/* functional: high. Draft near miss (4 words, VU add/store interleave); constants, $gp globals, callees and both mode branches verified against PAL asm. */
#include "common.h"
/* localdecomp:start func_L01_0036D8C8 */
typedef int Q_0036D8C8 __attribute__((mode(TI)));
typedef union { Q_0036D8C8 q; f32 f[4]; } V_0036D8C8;
typedef struct {
    u8 pad[0x25C0];
    u8 *camera;
    u8 pad25C4[0x2874-0x25C4];
    s16 mode;
} Hero_0036D8C8;
extern Hero_0036D8C8 D_001A4BE0;
extern f32 D_L01_001E1D20;
extern s32 D_L01_001E1D1C;
extern f32 D_L01_001DD85C;
__asm__(".extern D_L01_001DD85C, 4");
extern f32 D_L01_001DD858;
__asm__(".extern D_L01_001DD858, 4");
extern f32 D_L01_001DD854;
__asm__(".extern D_L01_001DD854, 4");
extern s32 D_L01_001DD868;
__asm__(".extern D_L01_001DD868, 4");
extern s32 D_L01_001DD86C;
__asm__(".extern D_L01_001DD86C, 4");
void func_L01_0036D8C8(u8 *obj) {
    extern void func_003C2F58(s32,s32,void *);
    extern void func_0038CE20(void *,void *,f32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32,f32);
    extern void func_0038D328(void *,void *);
    extern void func_003D9740(void *,s32,u32,s32,s32,f32);
    V_0036D8C8 matrix[4];
    V_0036D8C8 position, direction, rotation, offset;
    func_003C2F58((s32)obj,0,&position);
    if(D_001A4BE0.mode) func_0038CE20(&direction,obj+0xD0,-1.0f);
    else direction.q=*(Q_0036D8C8 *)(D_001A4BE0.camera+0xC0);
    rotation.f[0]=0.0f;
    rotation.f[1]=-func_0038D160(func_0038CED8(&direction),direction.f[2]) + -1.5707964f;
    rotation.f[2]=func_0038D160(direction.f[0],direction.f[1]);
    rotation.f[3]=1.0f;
    func_0038D328(matrix,&rotation);
    if(D_001A4BE0.mode) func_0038CE20(&offset,obj+0xD0,-1.0f);
    else offset.q=*(Q_0036D8C8 *)(D_001A4BE0.camera+0xC0);
    func_0038CE20(&offset,&offset,5.0f);
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(position) : "m"(position),"m"(offset) : "vf1","vf2");
    *(Q_0036D8C8 *)&matrix[3]=*(Q_0036D8C8 *)&position;
    func_0038CE20(&matrix[0],&matrix[0],D_L01_001DD85C);
    func_0038CE20(&matrix[1],&matrix[1],D_L01_001DD858);
    func_0038CE20(&matrix[2],&matrix[2],D_L01_001DD854);
    D_L01_001E1D20 += 0.2f;
    if(D_L01_001E1D20 >= 7.0f) D_L01_001E1D20 -= 7.0f;
    func_003D9740(matrix,D_L01_001DD868,(D_L01_001E1D1C*5 <<24)|0x00FF8080,4,1,D_L01_001E1D20);
    func_0038CE20(&matrix[0],&matrix[0],D_L01_001DD85C*1.25f);
    func_0038CE20(&matrix[1],&matrix[1],D_L01_001DD858*1.25f);
    func_003D9740(matrix,D_L01_001DD86C,(D_L01_001E1D1C*3 <<24)|0x00FFC480,2,1,D_L01_001E1D20);
}
/* localdecomp:end func_L01_0036D8C8 */
