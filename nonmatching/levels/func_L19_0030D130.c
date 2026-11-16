/* PAL near miss (Codex wave 10): near miss: 110 words differ with the file's flags.
 * Worker's note: 106 positional diff: func_L19_0030D130.ordinary.log; incomplete-array sdata globals correct large-address loads; fractional constants still gp pooled with fixed plain assembler, VU operation remains opaque; no padding metadata required.
 */
#include "common.h"
/* localdecomp:start func_L19_0030D130 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_0030D130;
extern u8 *D_L19_001DF720[] __attribute__((section(".sdata")));
extern s32 D_L19_001DF240[] __attribute__((section(".sdata")));
extern u16 D_001DC5D0_sda, D_001DC5D4_sda;
extern s32 D_001DC5C8_sda, D_001DC5D8_sda;
extern s32 D_L19_001DC5CC[] __attribute__((section(".sdata")));
extern f32 D_001DC5DC_sda,D_001DC5E0_sda,D_001DC5E4_sda,D_001DC5E8_sda;
extern u8 D_L19_001D66F0[];
void func_L19_0030D130(u8 *object) {
    extern void func_L01_004450F0(void *,s32,s32);
    extern void func_L01_00404808(void *,void *);
    extern void func_L19_0030D388(void *);
    extern f32 func_0038D0B0(f32);
    extern s32 func_0038DBD8(s32,s32,f32);
    extern s32 func_L01_00447490(void *,s32,s32);
    extern void func_L02_00429840(void *,void *,s32,s32,void *,s32,s32,s32,f32,f32,f32,f32);
    extern void func_L01_00451FE0(void *,s32,void *,s32,s32,s32,s32,s32,s32,s32,f32,f32,f32,f32,f32,f32,f32,f32);
    extern s32 func_003A52A0(s32,s32,void *);
    extern void func_L01_00456230(void *,s32);
    Vec_0030D130 offset,velocity;
    switch (object[0x20]) {
    case 0:
        if ((s32)object < (s32)D_L19_001DF720[0]) {
            *(s32 *)(object+0x9C)=15;
            func_L01_004450F0(object,3,-1);
        } else {
            *(u16 *)(object+0x7C)=D_001DC5D0_sda;
            func_L01_004450F0(object,1,-1);
        }
        break;
    case 1:
        if (object[0x31]) {
            func_L01_00404808(func_L19_0030D388,object);
            *(s32 *)(object+0x78)=func_0038DBD8(D_001DC5C8_sda,D_L19_001DC5CC[0],
                (func_0038D0B0((f32)(D_L19_001DF240[0]%150)/150.0f*6.2831802f-3.1415901f)+1.0f)*0.5f);
        }
        if (func_L01_00447490(object,0x10000,0)) {
            *(u128_t *)&offset=0;
            *(u128_t *)&velocity=0;
            offset.z=0.5f;
            velocity.z=0.060000002f;
            __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0"
                : "=m"(offset) : "m"(offset),"m"(*(Vec_0030D130 *)(object+0x10)) : "vf1","vf2");
            func_L02_00429840(object,&offset,5,1,&velocity,0x504040C0,0,180,0.333f,3.0f,0.5f,1.0f);
            func_L01_00451FE0(object,D_001DC5D8_sda,D_L19_001D66F0,255,180,0,0,35,0,3,
                 D_001DC5DC_sda,D_001DC5E0_sda,D_001DC5E4_sda,D_001DC5E8_sda,-1.0f,-1.0f,1.0f,1.0f);
            func_003A52A0(0,0,object);
            *(u16 *)(object+0x7C)=D_001DC5D4_sda;
            func_L01_00456230(object,1);
            *(s32 *)(object+0x9C)=15;
            *(u16 *)(object+0x34)|=2;
            func_L01_004450F0(object,2,-1);
        }
        break;
    }
}
/* localdecomp:end func_L19_0030D130 */
