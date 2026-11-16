/* PAL near miss (Codex wave 10): near miss: 126 words differ with the file's flags.
 * Worker's note: 125 diff; build/codex/w508/002FCDC0-best.log; complete four-state draft from PAL branches (asm saved); residual register allocation and call-argument scheduling; ten compiles
 */
#include "common.h"
/* localdecomp:start func_L01_002FCDC0 */
#include "vu0.h"
typedef struct { s32 a, b, c; } Params_002FCDC0;
typedef struct { u8 pad[0x25C4]; s32 state; u8 pad25C8[0x28BC - 0x25C8]; s32 timer; } Hero_002FCDC0;
extern Params_002FCDC0 D_L01_001DC420;
extern u8 D_001A52D0[];
extern u8 D_001A4BE0[];
extern u8 *D_001D52FC[];
extern u8 *D_001D52FC_sda;
__asm__(".extern D_001D52FC_sda, 4");
void func_L01_002FCDC0(u8 *self) {
    extern void func_003C2F58(u8 *, s32, Q_002F98F8 *);
    extern void *func_L01_004501E8(void *,void *,f32,f32,f32,void *,s32,s32,s32,f32,f32,s32,Params_002FCDC0 *,s32,s32,s32);
    extern void func_L01_004C7438(Q_002F98F8 *,Q_002F98F8 *,void *,f32,f32,f32,f32,s32);
    extern s32 func_L01_004C7A18(Q_002F98F8 *,Q_002F98F8 *,void *,void *,void *,s32,s32,f32);
    extern s32 func_0038CAD0(s32 *);
    extern s32 func_L01_005118D0(s32,s32);
    extern void func_L01_004EA7D8(s32);
    extern s32 func_003A52A0(s32,s32,void *);
    extern u8 *func_L01_002F98F8(Q_002F98F8 *,Q_002F98F8 *);
    extern void func_L01_004EAA80(void);
    extern void func_L01_00404A10(void *,void *);
    extern void func_L01_002FD090(u8 *);
    Q_002F98F8 position[1];
    Params_002FCDC0 params;
    Q_002F98F8 origin[1];
    Q_002F98F8 *origin_ptr;
    Q_002F98F8 hit[1];
    u8 *vars = *(u8 **)(self + 0x68);
    u8 *ref;
    Hero_002FCDC0 *hero;
    void *target;
    f32 distance;
    s32 allowed;
    func_003C2F58(self, 0, position);
    ref = D_001A52D0;
    params = D_L01_001DC420;
    target = func_L01_004501E8(self+0x10,ref,0.39269909262657166f,0.7853981852531433f,11.100000381469727f,hit,0,0,0,0.0f,0.0f,0,&params,1,-1,0);
    hero = (Hero_002FCDC0 *)(ref - 0x6F0);
    distance = 10.0f;
    if (hero->state==29) distance = 11.0f;
    origin_ptr = origin;
    allowed = 1;
    func_L01_004C7438(origin_ptr,position,target,1.5f,distance,0.20000001788139343f,0.004399999976158142f,0);
    *(s32 *)(vars+0x24)=func_L01_004C7A18(position,origin_ptr,vars,vars+0x10,self,0,0,0.004399999976158142f);
    if (hero->state==29) {
        if (func_0038CAD0((s32 *)(ref+0x21CC))==0) allowed = 0;
    } else hero->timer=33;
    switch (self[0x20]) {
    case 0:
        self[0x20]=1;
        *(s32 *)(vars+0x24)=0;
    case 1:
        {
        u8 *hero=D_001A4BE0;
        if ((*(s32 *)(D_001D52FC[0]+0x1A0)&*(s32 *)(hero+0x1210)) && hero[0x25ED]==0 && *(s32 *)(hero+0x1220)>=19 && allowed) {
            if (func_L01_005118D0(-1,1)) {
                func_L01_004EA7D8(-1);
                self[0x20]=2;
                *(s32 *)(vars+0x20)=17;
            } else if (*(s32 *)(D_001D52FC_sda+0x1A4)&*(s32 *)(hero+0x1210)) {
                func_003A52A0(2,0,self);
            }
        }
        break;
        }
    case 2:
        if (func_0038CAD0((s32 *)(vars+0x20))) {
            u8 *m=func_L01_002F98F8(position,origin_ptr);
            *(u8 **)(m+0xB8)=self;
            func_L01_004EAA80();
            self[0x20]=3;
            *(s32 *)(vars+0x20)=8;
        }
        break;
    case 3:
        if (func_0038CAD0((s32 *)(vars+0x20))!=0) self[0x20]=1;
        break;
    }
    func_L01_00404A10(func_L01_002FD090,self);
}
/* localdecomp:end func_L01_002FCDC0 */
