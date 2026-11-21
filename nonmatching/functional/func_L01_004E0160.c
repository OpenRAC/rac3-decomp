/* functional: high (EXACT at levels 01, 02, 05). Callee pointer types widened to void* to avoid later typedef conflicts; otherwise as the near-miss draft. */
#include "vu0.h"
extern u8 D_001A71C4[];
void func_L01_004E0160(S_4DC790 *spring)
{
    extern s32 func_L01_004E0100(s32);
    extern void func_003C2C98(void *, void *);
    extern void func_L01_0043A430(void *, s32, void *);
    extern void func_L01_00448728(f32 *, f32 *, f32, f32, f32, f32, s32);
    extern void func_L01_004482A0(f32 *, f32 *, f32, f32, f32, f32);
    extern void func_003C3FC0(void *, void *);
    u8 *s=(u8 *)spring;
    void *m=(void *)func_L01_004E0100(*(s16 *)(s+0xA2));
    if (!m) return;
    if (D_001A71C4[0] == 0) {
        s32 type=*(s16 *)(s+0xA2);
        if (type==4 || type==2 || type==6 || type==7 || type==3) return;
    } else if (*(s16 *)(s+0xA2)==0) return;
    if (*(f32 *)(s+0x60)==0.0f && *(f32 *)(s+0x64)==0.0f && *(f32 *)(s+0x68)==0.0f &&
        *(f32 *)(s+0x90)==0.0f && *(f32 *)(s+0x94)==0.0f && *(f32 *)(s+0x98)==0.0f &&
        fabs_asm(*(f32 *)(s+0x70))<0.003f && fabs_asm(*(f32 *)(s+0x74))<0.003f && fabs_asm(*(f32 *)(s+0x78))<0.003f &&
        *(f32 *)(s+0xAC)==1.0f &&
        fabs_asm(*(f32 *)(s+0x40))<0.005f && fabs_asm(*(f32 *)(s+0x44))<0.005f && fabs_asm(*(f32 *)(s+0x48))<0.005f) {
        if (s[1]) func_003C2C98(m,(void *)spring);
    } else {
        func_L01_00448728((f32 *)(s+0x40),(f32 *)(s+0x50),*(f32 *)(s+0x60),*(f32 *)(s+0xA4)*1.44f,*(f32 *)(s+0xA8)*1.44f,0.0f,2);
        func_L01_00448728((f32 *)(s+0x44),(f32 *)(s+0x54),*(f32 *)(s+0x64),*(f32 *)(s+0xA4)*1.44f,*(f32 *)(s+0xA8)*1.44f,0.0f,2);
        func_L01_00448728((f32 *)(s+0x48),(f32 *)(s+0x58),*(f32 *)(s+0x68),*(f32 *)(s+0xA4)*1.44f,*(f32 *)(s+0xA8)*1.44f,0.0f,2);
        func_L01_004482A0((f32 *)(s+0x70),(f32 *)(s+0x80),*(f32 *)(s+0x90),*(f32 *)(s+0xA4),*(f32 *)(s+0xA8),0.0f);
        func_L01_004482A0((f32 *)(s+0x74),(f32 *)(s+0x84),*(f32 *)(s+0x94),*(f32 *)(s+0xA4),*(f32 *)(s+0xA8),0.0f);
        func_L01_004482A0((f32 *)(s+0x78),(f32 *)(s+0x88),*(f32 *)(s+0x98),*(f32 *)(s+0xA4),*(f32 *)(s+0xA8),0.0f);
        if (!s[1]) func_L01_0043A430(m,*(s16 *)(s+0xA0),(void *)spring);
        func_003C3FC0(s+0x10,s+0x40);
        *(u128_t *)(s+0x30)=*(u128_t *)(s+0x70);
        *(f32 *)(s+0x20)=*(f32 *)(s+0xAC);
        *(f32 *)(s+0x24)=*(f32 *)(s+0xAC);
        *(f32 *)(s+0x28)=*(f32 *)(s+0xAC);
    }
    qzero(s+0x90);
    qzero(s+0x60);
    *(f32 *)(s+0xAC)=1.0f;
}
