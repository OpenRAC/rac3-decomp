/* PAL near miss (round 10): 30 words differ with the file's flags, all of them the moby (retail $s2)
 * and its vars (retail $s1) swapped. func_003A52A0 and func_L01_005118D0 return s32 and
 * func_L01_003C27E0 a pointer (each closed a $v0/$v1 swap); D_00142617 and D_L01_002F4D7C as
 * arrays and the weapon row as a struct gave retail's lui forms (45 -> 30). regalloc.py: the moby
 * has 16 weighted refs (its in-loop use counts twice) over 191 insns, priority 0.335, the vars 15
 * over 150, 0.300; retail needs the vars first. A goto loop (no loop notes) swaps them but loses
 * the hoisted lui of D_001A4C60. Tried: loop as for-up/for-down, case 1 as nested ifs or an
 * early break, the pod as a local, (s32) first argument, vars loaded after the first call.
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
extern u8 D_00142617[];
typedef struct { u8 pad_0; u8 level; u8 pad_2[0xEE]; } Row_0035D738;
extern Row_0035D738 D_L01_002C5600[];
extern f32 D_L01_002F4D7C[];
extern u8 D_001A4C60[];
void func_L01_0035D738(u8 *m) {
    extern void func_003C2F58(void *,s32,void *);
    extern void func_L01_004C7438(void *,void *,f32,f32,f32,f32,s32,s32);
    extern s32 func_L01_004C7A18(void *,void *,void *,void *,void *,s32,void *,f32);
    extern s32 func_0038CAD0(void *);
    extern s32 func_L01_005119E0(s32);
    extern void func_L01_004EA7D8(s32);
    extern s32 func_003A52A0(s32,s32,void *);
    extern s32 func_L01_005118D0(s32,s32);
    extern s32 func_L01_003C2E10(void);
    extern u8 *func_L01_003C27E0(void *,void *);
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
    level=(D_L01_002C5600 + D_00142617[0])->level;
    if (m[0x31]) D_L01_002F4D7C[0]=0.1f;
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
