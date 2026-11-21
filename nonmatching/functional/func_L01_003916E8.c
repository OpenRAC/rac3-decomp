/* functional: high. 28 diff = scheduling only. Draft's own D_001A4BE0/D_001425C0/D_L01_002C5600 externs conflicted with file context so use context's u8[] and cast; verified color tables, loop count 5, arg order of func_L01_0046B458, signed div by 6 */
#include "common.h"
#include "vu0.h"
typedef struct { u8 pad[0x1200]; u8 *object; u8 pad1204[0x24]; s32 index; } Hero_003916E8;
typedef struct { u8 pad; u8 type; u8 rest[0xEE]; } Entry_003916E8;
extern f32 D_001DDFEC_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DDFEC_sda, 4");
extern f32 D_001DDFF0_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DDFF0_sda, 4");
void func_L01_003916E8(void) {
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern void func_00382760(void *, f32, f32, f32);
    extern s32 func_00382498(s32, s32);
    extern u8 *func_L01_0046B458(void *, s32, s32, s32, s32, void *, f32, f32, f32, s32);
    vu0_v4 zero, origin, pos;
    s32 type = ((Entry_003916E8 *)(D_001425C0[((Hero_003916E8 *)D_001A4BE0)->index]*240 + (s32)D_L01_002C5600))->type;
    s32 color1, color2, i, alpha;
    f32 radius, azimuth;
    u8 *p;
    u8 *p2;
    qzero(&zero);
    if (type==1) { color1=0x7F2020; color2=0xFF4040; }
    else if (type==2) { color1=0x20207F; color2=0x4040FF; }
    else if (type==3) { color1=0x20407F; color2=0x4080FF; }
    else { color1=0x20207F; color2=0x4040FF; }
    *(vu0_q *)&origin = *(vu0_q *)(((Hero_003916E8 *)D_001A4BE0)->object + 0x10);
    for (i=0; i<5; i++) {
        radius=func_003824E0(0.01f,0.8f);
        azimuth=func_00382538();
        func_00382760(&pos,radius,azimuth,func_003824E0(0.0f,3.1415927f));
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(pos) : "m"(pos), "m"(origin) : "vf1", "vf2");
        alpha=func_00382498(0,111);
        p=func_L01_0046B458(&pos,(func_00382498(12,20)*5+2)/6,color1|(alpha<<24),0,1,&zero,D_001DDFEC_sda*0.5f,D_001DDFEC_sda,0.0f,0);
        if (p) p[9]=0x74;
        p2=func_L01_0046B458(&pos,(func_00382498(12,20)*5+2)/6,color2|(alpha<<24),1,1,&zero,D_001DDFF0_sda*0.5f,D_001DDFF0_sda,0.0f,0);
        if (p2) p2[9]=0x74;
    }
}
