/* PAL near miss (Codex wave 10): near miss: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details).
 * Worker's note: Ordinary all-place check blocked by later Moby_4E0618/Lid_4E0618 typedefs (w523/func_L01_004E0160-final.log). Exact signatures retained. Contract-only snippet MATCH (contract-02.log), NOT accepted exact proof. NEEDS move existing types before entry; no source ...
 */
#include "common.h"
/* localdecomp:start func_L01_004E0160 */
#include "vu0.h"
extern u8 D_001A71C4[];
void func_L01_004E0160(S_4DC790 *spring)
{
    extern s32 func_L01_004E0100(s32);
    extern void func_003C2C98(Moby_4E0618 *, Lid_4E0618 *);
    extern void func_L01_0043A430(Moby_4E0618 *, s32, Lid_4E0618 *);
    extern void func_L01_00448728(f32 *, f32 *, f32, f32, f32, f32, s32);
    extern void func_L01_004482A0(f32 *, f32 *, f32, f32, f32, f32);
    extern void func_003C3FC0(void *, void *);
    u8 *s=(u8 *)spring;
    Moby_4E0618 *m=(Moby_4E0618 *)func_L01_004E0100(*(s16 *)(s+0xA2));
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
        if (s[1]) func_003C2C98(m,(Lid_4E0618 *)spring);
    } else {
        func_L01_00448728((f32 *)(s+0x40),(f32 *)(s+0x50),*(f32 *)(s+0x60),*(f32 *)(s+0xA4)*1.44f,*(f32 *)(s+0xA8)*1.44f,0.0f,2);
        func_L01_00448728((f32 *)(s+0x44),(f32 *)(s+0x54),*(f32 *)(s+0x64),*(f32 *)(s+0xA4)*1.44f,*(f32 *)(s+0xA8)*1.44f,0.0f,2);
        func_L01_00448728((f32 *)(s+0x48),(f32 *)(s+0x58),*(f32 *)(s+0x68),*(f32 *)(s+0xA4)*1.44f,*(f32 *)(s+0xA8)*1.44f,0.0f,2);
        func_L01_004482A0((f32 *)(s+0x70),(f32 *)(s+0x80),*(f32 *)(s+0x90),*(f32 *)(s+0xA4),*(f32 *)(s+0xA8),0.0f);
        func_L01_004482A0((f32 *)(s+0x74),(f32 *)(s+0x84),*(f32 *)(s+0x94),*(f32 *)(s+0xA4),*(f32 *)(s+0xA8),0.0f);
        func_L01_004482A0((f32 *)(s+0x78),(f32 *)(s+0x88),*(f32 *)(s+0x98),*(f32 *)(s+0xA4),*(f32 *)(s+0xA8),0.0f);
        if (!s[1]) func_L01_0043A430(m,*(s16 *)(s+0xA0),(Lid_4E0618 *)spring);
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
/* localdecomp:end func_L01_004E0160 */
