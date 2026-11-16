/* PAL near miss (Codex wave 7): near miss: 298 words differ with the file's flags.
 * Worker's note: 288 diff wrapper02.log: fixed default assembler emits .lit4 loads versus retail inline float constants; vector/register and store scheduling remain; complete PAL draft, no alternate flags
 */
#include "common.h"
/* localdecomp:start func_L20_003D65D0 */
#include "vu0.h"
extern s32 D_L20_001DEBF0, D_L20_001DEBF4;
extern f32 D_L20_001DEBF8, D_L20_001DEBBC, D_L20_001DEBC0;
extern s32 D_L20_001E2640[4];
extern vu0_q D_L20_001E2600, D_L20_001E2610, D_L20_001E2620, D_L20_001E2630;
extern u8 D_L20_002A2940[];
extern u8 *D_L20_001E029C;
__asm__(".extern D_L20_001D67A8, 16");
s32 func_L20_003D65D0(void *arg0) {
    extern void *func_003C24B0(s32,s32);
    extern void func_L01_00456160(void *,void *);
    extern void func_L01_004AA7E8(void *,s32);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_0038CE90(void *,void *,void *);
    extern void func_L01_0045BD78(void *,f32,f32,f32,f32);
    extern s32 func_L01_0041A4F0(void);
    u8 *obj=arg0;
    u8 *p=*(u8 **)(obj+0x68);
    u8 *q;
    s32 i, mode;
    f32 hp;
    *(u16 *)(obj+0x34) |= 0x800;
    *(vu0_q *)(p+0x5b0)=*(vu0_q *)(obj+0x10);
    *(void **)(p+0x2f8)=func_003C24B0(0x1cb4,0x80);
    *(void **)(p+0x2fc)=func_003C24B0(0x1cb4,0x80);
    func_L01_00456160(*(void **)(p+0x2f8),obj);
    func_L01_00456160(*(void **)(p+0x2fc),obj);
    obj[0x30]=255; *(u16 *)(obj+0x32)=255;
    D_L20_001DEBEC=0; D_L20_001DEBF0=0; D_L20_001DEBF4=0;
    *(u16 *)(*(u8 **)(p+0x2f8)+0x34) |= 0x41;
    *(u16 *)(*(u8 **)(p+0x2f8)+0x34) &= 0xefff;
    *(s32 *)(*(u8 **)(p+0x2f8)+0x98)=0;
    func_L01_004AA7E8(*(void **)(p+0x2f8),1);
    *(u16 *)(*(u8 **)(p+0x2fc)+0x34) |= 0x41;
    *(u16 *)(*(u8 **)(p+0x2fc)+0x34) &= 0xefff;
    *(s32 *)(*(u8 **)(p+0x2fc)+0x98)=0;
    func_L01_004AA7E8(*(void **)(p+0x2fc),1);
    for (i=3;i>=0;i--) D_L20_001E2640[i]=0;
    func_0038CF68(D_L20_002A2940,obj+0xc0,D_L20_001DEBF8);
    D_L20_001E2600=*(vu0_q *)(obj+0xe0);
    func_0038CF68(D_L20_002A2940+0x140,obj+0xd0,D_L20_001DEBF8);
    D_L20_001E2610=*(vu0_q *)(obj+0xc0);
    func_0038CF68(D_L20_002A2940+0x280,obj+0xe0,D_L20_001DEBF8);
    D_L20_001E2620=*(vu0_q *)(obj+0xd0);
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)(D_L20_002A2940+0x3c0))
        : "m"(*(vu0_v4 *)(obj+0xe0)), "m"(*(vu0_v4 *)(obj+0xc0))
        : "vf1", "vf2");
    func_0038CF68(D_L20_002A2940+0x3c0,D_L20_002A2940+0x3c0,D_L20_001DEBF8);
    func_0038CE90(&D_L20_001E2630,D_L20_002A2940+0x3c0,obj+0xd0);
    if (*(s32 *)(p+0x614)!=-1) {
        q=D_L20_001E029C+(*(s32 *)(p+0x614)<<8);
        *(u8 **)(p+0x618)=q; *(u16 *)(q+0x34)|=0x41;
    }
    if (*(s32 *)(p+0x678)!=-1) {
        q=D_L20_001E029C+(*(s32 *)(p+0x678)<<8);
        *(u8 **)(p+0x67c)=q; *(u16 *)(q+0x34)|=0x41;
    }
    p[0x170]=0x23; p[0x1a8]=3; p[0x1d7]=1; p[0x1db]=255;
    p[0x1d8]=0; p[0x1d9]=0; p[0x1da]=0;
    *(f32 *)(p+0x190)=0.5f; *(f32 *)(p+0x194)=0.5f; *(f32 *)(p+0x74)=0.5f;
    *(f32 *)(p+0x19c)=0.15f; *(s32 *)(p+0x218)=1;
    *(f32 *)(p+0x70)=0.7f; *(f32 *)(p+0x78)=1.0f; *(f32 *)(p+0x7c)=2.0f;
    *(f32 *)(p+0x80)=1.5533430576324463f; *(f32 *)(p+0xa0)=0.3490658402442932f;
    *(f32 *)(p+0x9c)=0.003920000046491623f;
    func_L01_0045BD78(obj,D_L20_001DEBC0*0.0004000000189989805f,D_L20_001DEBBC*0.020000001415610313f,0.010053097270429134f,0.25132742524147034f);
    p[0x58]=20; p[0x5a]=14;
    if (*(s16 *)(p+0x34)==0) { *(s16 *)(p+0x34)=2000; *(f32 *)(p+0x30)=2000.0f; }
    if (p[0x44]==0) { p[0x46]=60; p[0x44]=60; p[0x45]=60; }
    if (func_L01_0041A4F0()) { *(s16 *)(p+0x34)=32000; *(f32 *)(p+0x30)=32000.0f; }
    mode=D_L20_001D67A8;
    if (mode==5 || mode==6) hp=*(s16 *)(p+0x34)*0.9f;
    else if (mode==7) hp=*(s16 *)(p+0x34)*0.8f;
    else if (mode==8) hp=*(s16 *)(p+0x34)*0.75f;
    else if (mode>=9) hp=*(s16 *)(p+0x34)*0.5f;
    else goto health_done;
    *(s16 *)(p+0x34)=(s32)hp;
    *(f32 *)(p+0x30)=*(s16 *)(p+0x34);
health_done:
    *(s32 *)(p+0x650)=*(s16 *)(p+0x34);
    *(s32 *)(p+0x620)=(s32)(*(s16 *)(p+0x34)*0.75f);
    *(s32 *)(p+0x624)=(s32)(*(s16 *)(p+0x34)*0.5f);
    *(s32 *)(p+0x628)=(s32)(*(s16 *)(p+0x34)*0.25f);
    *(f32 *)(p+0x40)=2.0f; p[0x3f]=0; p[0x64]=0; p[0x39]=1; p[0x3e]=3;
    *(s32 *)(p+0x5cc)=1;
    func_L01_004450F0(obj,2,0);
    if (obj[0x43]) func_003C3A10(obj,0,0,0);
    return 0;
}
/* localdecomp:end func_L20_003D65D0 */
