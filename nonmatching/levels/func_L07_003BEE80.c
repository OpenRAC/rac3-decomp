/* PAL near miss (Codex wave 10): near miss: 10 words differ with the file's flags.
 * Worker's note: 10 word diffs; c03.log; three address/source formulations unchanged. Retail +0x1B8..1C4 interleaves float preparation within VU sequence; retained one legal atomic VU block; additional address/call scheduling at +0x188..198. Fixed flags.
 */
#include "common.h"
/* localdecomp:start func_L07_003BEE80 */
#include "structs/hero.h"
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003BEE80;
extern struct Hero D_001A4BE0;
extern u8 *D_L07_001ECC80[];
extern V_003BEE80 D_L07_001D9AE0;
void func_L07_003BEE80(u8 *obj) {
    extern void func_L07_003BF318(u8 *,u8 *);
    extern f32 func_0038DAB8(f32,f32);
    extern s32 func_L01_004561B8(void *);
    extern void func_003A52A0(s32,s32,void *);
    extern void func_L07_003BF838(u8 *);
    extern void func_L07_003BF3A8(u8 *,u8 *,f32,void *);
    extern s32 func_0038CB00(void *);
    extern void func_L07_003BF2D0(void *);
    extern f32 func_0038CF38(void *,void *);
    extern void func_L01_004AA760(s32,void *);
    extern void func_L07_003BF368(void *);
    extern void func_L07_003BF480(void *);
    extern void func_0038CE90(void *,void *,void *);
    extern void func_0038CF68(void *,void *,f32);
    extern s32 func_L01_00446780(void *,void *,s32,s32,f32,f32,f32,s32,s32);
    extern void func_L07_003A2380(s32,void *,s32,s32);
    extern s32 func_00382468(s32);
    extern void func_L01_00456230(void *,s32);
    V_003BEE80 direction;
    u8 *d=*(u8 **)(obj+0x68);
    u8 *pos;
    u8 *target;
    u8 **objects;
    s32 count;
    if(d[0xE]) return;
    func_L07_003BF318(obj,*(u8 **)d);
    *(f32 *)(obj+0xF4)=func_0038DAB8(*(f32 *)(obj+0xF4),0.25132742524147034f);
    switch(obj[0x20]) {
    case 1:
        if(func_L01_004561B8(obj)) func_003A52A0(0,4,obj);
        func_L07_003BF838(obj);
        func_L07_003BF3A8(obj,*(u8 **)(d+4),0.0052359881810843945f,0);
        if(func_0038CB00(d+0xC)) {
            obj[0x20]=2;
            *(s16 *)(d+0xC)=250;
            if(*(u8 **)d) func_L07_003BF2D0(*(u8 **)d);
        }
        break;
    case 2:
        if(func_0038CB00(d+0xC) || func_0038CF38(pos=obj+0x10,*(u8 **)(obj+0xB8)+0x10)>100.0f) {
            func_L01_004AA760(0,obj);
            func_L07_003BF368(obj);
        } else {
            func_L07_003BF480(obj);
            func_L07_003BF838(obj);
            *(f32 *)(d+8)+=0.12000000476837158f;
            if(*(f32 *)(d+8)>0.6f) *(f32 *)(d+8)=0.6f;
            func_0038CE90(&direction,&D_L07_001D9AE0,obj+0xD0);
            func_0038CF68(&direction,&direction,*(f32 *)(d+8));
            __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %0\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
              : "+m"(*(V_003BEE80 *)(obj+0x10)) : "m"(direction) : "vf1","vf2");
            func_L07_003BF3A8(obj,*(u8 **)(d+4),0.020943952724337578f,&direction);
            count=func_L01_00446780(obj,pos,1,0,1.0f,(f32)d[0xF],1.0f,1,9);
            if(count>0) {
                s32 remaining;
                objects=D_L07_001ECC80;
                remaining=count;
                do {
                    if(*objects==(u8 *)D_001A4BE0.hero_moby) {
                        func_003A52A0(1,0,obj);
                        target=*(u8 **)(obj+0xB8);
                        if(target && *(s16 *)(target+0xAA)==0x1A18) {
                            u8 *child=*(u8 **)(target+0x68);
                            if(*(s16 *)(child+0x66E)==0) {
                                func_L07_003A2380(25,obj,0,100);
                                *(s16 *)(child+0x66E)=func_00382468(125)+250;
                            }
                            func_L01_00456230(*(u8 **)(obj+0xB8),1);
                        }
                    }
                    --remaining;
                    ++objects;
                } while(remaining);
            }
        }
        break;
    }
}
/* localdecomp:end func_L07_003BEE80 */
