#include "common.h"
/* localdecomp:start func_L01_00471390 */
#include "vu0.h"
typedef int Q_00474B48 __attribute__((mode(TI)));
extern u8 D_001A4C60[];
extern s32 D_L01_001DFBC0_00471390;
extern f32 D_L01_001E2900[];

void func_L01_00471390(u8 *p)
{
    extern void func_L01_004C6EC8(void *,void *);
    extern void func_003886E8(void *,void *,f32);
    extern f32 func_003887C8(void *,void *);
    extern f32 func_0037E250(f32,f32);
    extern void func_00388830(void *,void *,f32);
    extern f32 func_00389380(f32,f32);
    extern f32 func_00388978(f32);
    extern s32 func_003883C8(void *);
    extern void func_003C7CE0(u8 *);
    vu0_v4 delta,hero;
    u8 *s=p+0x20;
    u8 *pos=p+0x10;
    u8 *h;
    func_L01_004C6EC8(pos,pos);
    func_003886E8(s,s,0.9f);
    *(f32 *)(s+8)-=*(f32 *)(s+12);
    vec_add_ba((vu0_v4 *)(pos), (vu0_v4 *)(pos), (vu0_v4 *)(s));
    func_L01_004C6EC8(pos,pos);
    if(func_003887C8(pos,D_001A4C60)<1.05f) {
        h=D_001A4C60-0x80;
        if(*(f32 *)(h+0x170)!=0.0f) {
            *(Q_00474B48 *)&hero=*(Q_00474B48 *)D_001A4C60;
            vec_sub_ab((vu0_v4 *)(&delta), (vu0_v4 *)(pos), (vu0_v4 *)(&hero));
            func_00388830(&delta,&delta,*(f32 *)(h+0x170)*0.2f+func_0037E250(0.1f,2.0f)*0.0166666675f*0.15f);
            p[8]+=(s32)((f32)*(s16 *)(s+0x16)**(f32 *)(h+0x170)*0.5f);
            vec_add_ba((vu0_v4 *)(pos), (vu0_v4 *)(pos), (vu0_v4 *)(&delta));
        }
    }
    if(D_L01_001DFBC0_00471390%10==0) {
        *(f32 *)(s+0x1c)=func_00389380(*(f32 *)(s+0x1c),1.0f);
        { f32 k=func_00388978(*(f32 *)(s+0x1c))*0.0075f;
        func_00388830(&delta,D_L01_001E2900,k); }
        vec_add_ab((vu0_v4 *)(s), (vu0_v4 *)(s), (vu0_v4 *)(&delta));
    }
    if(*(s16 *)(p+0xa)<*(s16 *)(s+0x14))
        *(s32 *)(p+4)=((s32)((f32)*(s16 *)(p+0xa)/(f32)*(s16 *)(s+0x14)*128.0f)<<24)|0x204040;
    else {
        *(s32 *)(p+4)=0x4f204040;
    }
    p[8]+=s[0x16];
    if(func_003883C8(p+0xa)) func_003C7CE0(p);
}
/* localdecomp:end func_L01_00471390 */
