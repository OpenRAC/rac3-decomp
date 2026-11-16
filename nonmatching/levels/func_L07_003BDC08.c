/* PAL near miss (Codex wave 6): near miss: 2 words differ with the file's flags.
 * Worker's note: 2 diff; build/codex/w289/func_L07_003BDC08.02.log and .03.log; swc1 position.z versus stack argument sw at 0xF0/0xF8; struct, quad copy and array formulations identical; stopped after three wordings
 */
#include "common.h"
/* localdecomp:start func_L07_003BDC08 */
#include "vu0.h"
typedef int Quad_003BDC08 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_003BDC08;
extern u8 D_L07_001D66B0_003BDC08[] __attribute__((section(".sdata")));
extern u8 D_L07_001E1EC0_003BDC08[];
void func_L07_003BDC08(u8 *obj)
{
    extern s32 func_L01_00452FB0(void *,void *,s32,s32,s32);
    extern void func_L01_003303B8(void *,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,f32,f32,f32,f32);
    extern void func_L01_00451FE0(void *,s32,void *,f32,f32,f32,f32,s32,s32,s32,s32,s32,s32,s32,f32,f32,f32,f32);
    extern void func_L01_004443E8(void *,s32,s32);
    extern void func_L07_003BE368(char *);
    extern void func_003A52A0(s32,s32,void *);
    extern void func_L01_00446A70(void *,void *,s32,void *,void *,f32);
    extern s32 func_L01_00452860(void *,void *,s32);
    extern void func_L01_00456BD0(void *,s32);
    extern void func_L01_00456C98(void *,s32,s32,s32,s32,s32,s32,s32,s32,s32,f32,f32,f32);
    extern void func_L07_004522E8(void *,s32,void *,f32);
    extern f32 func_L01_0040E548(void *,void *);
    extern void func_L01_004472C0(void *);
    u8 *p = *(u8 **)(obj+0x68);
    Vec_003BDC08 position;
    s32 id;
    f32 speed;
    if (func_L01_00452FB0(obj,p+0x70,0,0,0)) {
        *(s32 *)(p+0x188) &= ~0x10;
    }
    if (*(f32 *)(p+0x30) <= 0.0f) {
        position = *(Vec_003BDC08 *)(obj+0x10);
        position.z += *(f32 *)(p+0x40);
        func_L01_003303B8(&position,0,10,5,4,10,15,0,
            0,0,0,0,0,1,0x1010000,0,0x388EF7,0x63F7,0x407FFF,0x20FF,
            0x8FFF,0x3064FF,0x7F60A0FF,0x280000FF,0x3064FF,0,
            0.5f,0.0f,0.0f,2.0f);
        func_L01_00451FE0(obj,0x7FFF,D_L07_001D66B0_003BDC08,3.0f,6.0f,3.0f,6.0f,
            0xFF,0xB4,0,0,0x23,0,3,-1.0f,-1.0f,1.0f,1.0f);
        func_L01_004443E8(obj,0,3);
        func_L07_003BE368((char *)obj);
        func_003A52A0(8,0,obj);
        return;
    }
    if (*(s32 *)(p+0x228)==1 || *(s32 *)(p+0x228)==11) {
        qzero(&position);
        func_L01_00446A70(obj,obj,0x10000,&position,&position,(f32)*(s16 *)(p+0x34));
    } else if (p[0x5E] || p[0x60] || p[0x3E]==2) {
        func_L01_004443E8(obj,0,3);
        func_L07_003BE368((char *)obj);
        return;
    }
    func_L01_00452860(obj,p+0x30,0);
    if (p[0x5F]) {
        func_L01_00456BD0(obj,5);
        id = obj[0x20]>=8 ? *(s32 *)(p+0x388) : *(s32 *)(p+0x380);
        speed = obj[0x20]>=8 ? *(f32 *)(p+0x38C) : *(f32 *)(p+0x384);
        func_L01_00456C98(obj,id,0,0,0,0,3,0,0,0,speed,10.0f,1.0f);
    } else {
        func_L01_00456BD0(obj,3);
        id = obj[0x20]>=8 ? *(s32 *)(p+0x388) : *(s32 *)(p+0x380);
        speed = obj[0x20]>=8 ? *(f32 *)(p+0x38C) : *(f32 *)(p+0x384);
        func_L01_00456C98(obj,id,0,0,0,0,1,0,0,0,speed,10.0f,1.0f);
    }
    func_L07_004522E8(obj,5,p+0x300,2.5f);
    if (obj[0x31] && func_L01_0040E548(D_L07_001E1EC0_003BDC08,obj+0x10) < 576.0f) {
        func_L01_004472C0(obj);
        obj[0x6F]=0x16;
    }
}
/* localdecomp:end func_L07_003BDC08 */
