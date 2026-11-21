/* functional: high. 4 diff vs retail, instruction scheduling only (retail multiset identical); VU0 add via inline asm */
#include "common.h"
extern f32 D_L01_001DDE14;
extern f32 D_L01_001DDE10;
extern f32 D_L01_001DDE0C;
extern s32 D_L01_001DDE30;
extern s32 D_L01_001DDE34;
__asm__(".extern D_L01_001DDE14,4");
__asm__(".extern D_L01_001DDE10,4");
__asm__(".extern D_L01_001DDE0C,4");
__asm__(".extern D_L01_001DDE30,4");
__asm__(".extern D_L01_001DDE34,4");
extern f32 D_L01_001E1EC0;
extern s32 D_L01_001E1EBC;
void func_L01_003884D8(u8 *obj) {
    extern void func_0038CE20(s128 *,s128 *,f32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32,f32);
    extern void func_0038D328(s128 *,S_38C110v *);
    extern void func_003D9740(s128 *,s32,u32,s32,s32,f32);
    s128 mat[4];
    S_38C110v pos;
    S_38C110v dir;
    S_38C110v rot;
    S_38C110v offset;
    u8 *basis=obj+0xD0;
    pos=*(S_38C110v *)(*(u8 **)(obj+0x68)+0x10);
    func_0038CE20((s128 *)&dir,(s128 *)basis,-1.0f);
    rot.x=0;
    rot.y=-func_0038D160(func_0038CED8(&dir),dir.z) + -1.5707964f;
    rot.z=func_0038D160(dir.x,dir.y);
    rot.w=1.0f;
    func_0038D328(mat,&rot);
    func_0038CE20((s128 *)&offset,(s128 *)basis,-1.0f);
    func_0038CE20((s128 *)&offset,(s128 *)&offset,5.0f);
    __asm__("lqc2 $vf1,%1
	lqc2 $vf2,%2
	vadd.xyz $vf1,$vf1,$vf2
	sqc2 $vf1,%0"
       : "=m"(pos) : "m"(pos),"m"(offset) : "vf1","vf2");
    mat[3]=*(s128 *)&pos;
    func_0038CE20(&mat[0],&mat[0],D_L01_001DDE14);
    func_0038CE20(&mat[1],&mat[1],D_L01_001DDE10);
    func_0038CE20(&mat[2],&mat[2],D_L01_001DDE0C);
    D_L01_001E1EC0+=0.2f;
    if (D_L01_001E1EC0>=7.0f) D_L01_001E1EC0-=7.0f;
    func_003D9740(mat,D_L01_001DDE30,((D_L01_001E1EBC*5)<<24)|0xFF8080,4,1,D_L01_001E1EC0);
    func_0038CE20(&mat[0],&mat[0],D_L01_001DDE14*1.25f);
    func_0038CE20(&mat[1],&mat[1],D_L01_001DDE10*1.25f);
    func_003D9740(mat,D_L01_001DDE34,((D_L01_001E1EBC*3)<<24)|0xBF0530,2,1,D_L01_001E1EC0);
}
