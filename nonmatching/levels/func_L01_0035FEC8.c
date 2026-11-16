/* PAL near miss (Codex wave 8): near miss: 166 words differ with the file's flags.
 * Worker's note: 165 diff/169 retail words; build/codex/w452/func_L01_0035FEC8.check4.log (retained v4). Complete fresh particle/ray effect draft; frame 0xC0 vs 0xA0, excess pointer/constant hoisting and saved registers, final VU scheduling. Five wrapper attempts without ...
 */
#include "common.h"
/* localdecomp:start func_L01_0035FEC8 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_0035FEC8;
extern u8 D_00142637 __attribute__((section(".data")));
typedef struct { u8 pad; u8 kind; u8 rest[238]; } Row_0035FEC8;
extern Row_0035FEC8 D_L01_002C5600[];
extern u8 *D_L01_00221098[];
void func_L01_0035FEC8(u8 *obj) {
    extern void func_003C5180(void *,void *,s32);
    extern f32 func_003824E0(f32,f32);
    extern f32 func_00382538(void);
    extern void func_00382760(void *,f32,f32,f32);
    extern f32 func_L01_00443A18(f32,f32);
    extern s32 func_00382498(s32,s32);
    extern u8 *func_L01_004708C8(void *,void *,f32,f32,s32,s32,s32,s32,s32,s32,s32);
    extern void func_00382580(void *,f32,f32);
    extern void func_0038CF68(void *,void *,f32);
    extern void *func_L01_004735F0(void *,void *,s32,f32);
    V_0035FEC8 scratch,velocity,position;
    V_0035FEC8 *vel=&velocity,*pos=&position;
    s32 i,kind;
    f32 yaw,pitch,scale;
    u8 *p;
    s32 color;
    func_003C5180(obj+16,&scratch,1);
    kind=D_L01_002C5600[D_00142637].kind;
    for(i=2;i>=0;i--) {
        pitch=func_003824E0(-0.9599310755729675f,-1.3962633609771729f);
        yaw=func_00382538();
        func_00382760(vel,func_003824E0(0.0f,0.5f)*0.020000001415610313f,yaw,pitch);
        scale=func_003824E0(0.65f,0.85f)*210000.0f;
        pos->x=*(f32 *)(obj+16)+func_L01_00443A18(0.0f,0.3f);
        pos->y=*(f32 *)(obj+20)+func_L01_00443A18(0.0f,0.3f);
        pos->z=*(f32 *)(obj+24)+func_L01_00443A18(0.0f,0.3f);
        color=0x28323232;
        if(kind>=2) color=0x28204080;
        p=func_L01_004708C8(pos,vel,scale,0.5f,color,0x08101010,func_00382498(12,21),1,1,-1,1);
        if(p) {
            p[2]=D_L01_00221098[0x5b][1];
            if(kind==2) p[2]=D_L01_00221098[0x5b][3];
            if(kind==3) p[2]=D_L01_00221098[0x5b][3];
        }
    }
    func_00382580(vel,0.0f,0.025f);
    __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%0\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "+m"(*vel):"m"(*(V_0035FEC8 *)(obj+16)):"vf1","vf2");
    __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%2\n\tvsub.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0" : "=m"(*pos):"m"(*(V_0035FEC8 *)(obj+16)),"m"(*vel):"vf1","vf2");
    func_0038CF68(pos,pos,-0.015000000596046448f);
    func_L01_004735F0(vel,pos,17,5.0f);
}
/* localdecomp:end func_L01_0035FEC8 */
