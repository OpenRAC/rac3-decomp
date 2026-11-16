/* PAL near miss (Codex wave 7): near miss: 45 words differ with the file's flags.
 * Worker's note: 45 diff; best build/codex/w350/func_L01_0035D738.06.log; s1/s2 swapped, table/scalar scheduling and v0/v1 allocation; 3 wordings stayed at same 45 diff; switch states 0,1,2,3 decoded from PAL branches in saved .s; no metadata needed on canonical place.
 */
#include "common.h"
/* localdecomp:start func_L01_0035D738 */
typedef struct Hero_0035D738 {
    u8 pad0[0x1210]; s32 mask;
    u8 pad1214[0x49c]; s32 camera;
    u8 pad16b4[0xf10]; s32 item;
    u8 pad25c8[0x25]; u8 locked;
    u8 pad25ee[0x2ce]; s32 timer;
} Hero_0035D738;
extern u8 *D_001D52FC;
extern s32 D_L01_001DD6E8;
extern u8 D_00142617;
extern u8 D_L01_002C5600[][0xf0];
extern f32 D_L01_002F4D7C;
extern u8 D_001A4C60[];
void func_L01_0035D738(u8 *m) {
    extern void func_003C2F58(void *,s32,void *);
    extern void func_L01_004C7438(void *,void *,f32,f32,f32,f32,s32,s32);
    extern s32 func_L01_004C7A18(void *,void *,void *,void *,void *,s32,void *,f32);
    extern s32 func_0038CAD0(void *);
    extern s32 func_L01_005119E0(s32);
    extern void func_L01_004EA7D8(s32);
    extern void func_003A52A0(s32,s32,void *);
    extern void func_L01_005118D0(s32,s32);
    extern s32 func_L01_003C2E10(void);
    extern void func_L01_003C27E0(void *,void *);
    extern void func_0038CF68(void *,void *,f32);
    extern u8 *func_L01_0035DEC8(s128 *,s128 *);
    extern void func_L01_004EAA80(void);
    extern void func_L01_0035DAF0(u8 *);
    extern void func_L01_00404A10(void (*)(u8 *),u8 *);
    u8 *v=*(u8 **)(m+0x68);
    s128 pos,velocity;
    f32 range;
    s32 can;
    Hero_0035D738 *hero;
    s128 *vel;
    s32 level,i;
    func_003C2F58(m,0,&pos);
    hero=(Hero_0035D738 *)D_001A4BE0;
    vel=&velocity;
    range=4.5f;
    if (hero->camera==2) range=11.0f;
    func_L01_004C7438(vel,&pos,1.5f,range,0.3f,0.0044f,0,0);
    can=1;
    *(s32 *)(v+0x24)=func_L01_004C7A18(&pos,vel,v,v+0x10,m,0,v+0x2c,0.0044f);
    if (hero->item==29) {
        if (!func_0038CAD0(&hero->timer)) can=0;
    } else hero->timer=33;
    level=D_L01_002C5600[D_00142617][1];
    if (m[0x31]) D_L01_002F4D7C=0.1f;
    func_0038CAD0(v+0x30);
    switch (m[0x20]) {
    case 0:
        m[0x20]=1;
        *(s32 *)(v+0x28)=1;
        *(s32 *)(v+0x24)=0;
    case 1:
        if (((*(s32 *)(D_001D52FC+0x1a4)&((Hero_0035D738 *)D_001A4BE0)->mask) ||
             ((*(s32 *)(D_001D52FC+0x1a4)&8) && ((Hero_0035D738 *)D_001A4BE0)->item==29)) &&
             !((Hero_0035D738 *)D_001A4BE0)->locked && can && *(s32 *)(v+0x28) &&
             D_L01_001DD6E8<8 && !*(s32 *)(v+0x30)) {
            if (func_L01_005119E0(-1)) {
                func_L01_004EA7D8(-1);
                m[0x20]=2;
                *(s32 *)(v+0x20)=17;
                *(s32 *)(v+0x30)=37;
            } else func_003A52A0(0,0,m);
        } else if (!func_L01_005119E0(-1) || D_L01_001DD6E8>=8) {
            if (*(s32 *)(D_001D52FC+0x1a4)&((Hero_0035D738 *)D_001A4BE0)->mask) func_003A52A0(0,0,m);
        }
        break;
    case 2:
        if (func_0038CAD0(v+0x20)) {
            func_L01_005118D0(-1,1);
            if (level>=3 && func_L01_003C2E10()) {
                for (i=3;i>=0;i--) {
                    if (func_L01_003C2E10()) {
                        func_L01_003C27E0(m,D_001A4C60);
                        D_L01_001DD6E8++;
                    }
                }
            } else {
                if (func_0038CEA8(vel)>0.40000003576278687f)
                    func_0038CF68(vel,vel,0.40000003576278687f);
                *(u8 **)(func_L01_0035DEC8(&pos,vel)+0xb8)=m;
            }
            func_L01_004EAA80();
            m[0x20]=3;
            *(s32 *)(v+0x20)=8;
        }
        break;
    case 3:
        if (func_0038CAD0(v+0x20)) m[0x20]=1;
        break;
    }
    func_L01_00404A10(func_L01_0035DAF0,m);
}
/* localdecomp:end func_L01_0035D738 */
