/* PAL near miss (Codex wave 10): near miss: 0 words differ with the file's flags.
 * Worker's note: 0 byte diff/MATCH; TYPE_CONTRACT_FAIL: supplied type fixture duplicates later F/V/O_003303B0 typedefs; move exact existing type chain before target and remove fixture include; build/codex/w503/func_L07_0032FDC8.all.log; see .context-note.txt
 */
#include "common.h"
/* localdecomp:start func_L07_0032FDC8 */
#include "build/codex/wave10/contracts/596098e8f9ac612c.h"
extern u8 D_L07_001DD104;
__asm__(".extern D_L07_001DD104, 1");
typedef struct {
    u8 p0[0x1200]; s32 lock;
    u8 p1204[0x24]; s32 weapon;
    u8 p122C[0x25C4-0x122C]; s32 mode;
    u8 p25C8[0x25ED-0x25C8]; u8 cycling;
    u8 p25EE[0x2850-0x25EE]; s32 health;
    u8 p2854[0x28C9-0x2854]; u8 selected, changed;
} Game_0032FDC8;
extern Game_0032FDC8 D_001A4BE0_0032FDC8;
typedef struct { u8 pad[0xE0]; u32 flags; } State_0032FDC8;
extern s32 D_001D4C38;
extern s32 D_L07_001DF518;
extern u8 D_L07_002B0EB0[];
void func_L07_0032FDC8(u8 *obj) {
    extern void func_L07_003303B0(O_003303B0 *);
    extern s32 func_0038CB00(void *);
    extern void func_L07_003354A0(u8 *);
    extern s32 func_L07_003A2380(s32,u8 *,s32,s32);
    extern void func_003E4D10(s32);
    extern f32 func_0038DAB8(f32,f32);
    extern f32 func_0038D098(f32);
    extern s32 func_0038DBD8(s32,s32,f32);
    extern void func_L01_005170B8(s32,s32);
    extern s32 func_L01_0040E020(void *);
    extern void func_L01_00452560(s32,s32,s32,s32,s32,s32,s32);
    extern void func_L07_00335558(u8 *);
    extern void func_L07_003352B8(u8 *,s32);
    extern s32 func_L07_003334A8(u8 *,s32);
    extern void func_L07_003304C0(u8 *);
    u8 *vars=*(u8 **)(obj+0x68);
    u8 *entry;
    u8 *row;
    s32 flag, color, i, weapon, amount;
    func_L07_003303B0((O_003303B0 *)obj);
    if ((u32)(obj[0x20]-4)>=4) return;
    entry=(u8 *)func_L07_00333460(vars[0x9E],vars[0x9F]);
    if (D_001A4BE0_0032FDC8.mode==0x39) {
        if(entry[3]) D_L07_001DD104=1;
        func_L07_00330F30(obj);
    }
    if (D_001A4BE0_0032FDC8.mode!=0x74) {
        if (*(s16 *)(vars+0xA4)!=-1) {
            if (*(s16 *)(vars+0xA4)%50==0) {
                if (*(s16 *)(vars+0xA4)<501) func_003A52A0(3,0,obj);
                func_L07_003354A0(obj);
            }
            if(func_0038CB00(vars+0xA4)) {
                func_L07_003A2380(44,obj,0,100);
                vars[0xA8]=1;
                func_L07_00330F30(obj);
            }
        }
        if(entry[2]) {
            *(f32 *)(vars+0xAC)+=0.0060000005178153515f;
            if (*(f32 *)(vars+0xAC)>=1.0f && D_001A4BE0_0032FDC8.health>0) {
                flag=0;
                if (D_001A4BE0_0032FDC8.health<=(D_00142668[0]>>2) && !(((State_0032FDC8 *)vars)->flags&0x800)) {
                    func_L07_003A2380(57,obj,0,100);
                    ((State_0032FDC8 *)vars)->flags|=0x800;
                    flag=1;
                }
                if (!flag && !(((State_0032FDC8 *)vars)->flags&0x400) && !func_00382468(8)) {
                    func_L07_003A2380(56,obj,0,100);
                    ((State_0032FDC8 *)vars)->flags|=0x400;
                }
                (D_001A4BE0_0032FDC8.health)--;
                *(f32 *)(vars+0xAC)-=1.0f;
                vars[0xAB]++;
            }
            func_003E4D10(3);
        }
        if(vars[0xBE]) {
            *(f32 *)(vars+0xB8)=func_0038DAB8(*(f32 *)(vars+0xB8),0.25132742524147034f);
            color=func_0038DBD8(0x8066CCFF,0x80FFFFFF,(1.0f-func_0038D098(*(f32 *)(vars+0xB8)))*0.5f);
            for(i=0;i<8;i++) if((vars[0xBE]>>i)&1) func_L01_005170B8(0x150008+i,color);
            if(func_0038CB00(vars+0xBC)) vars[0xBE]=0;
        }
        if(vars[0xDC] && func_L01_0040E020(vars+0xDD)) {
            if (D_001A4BE0_0032FDC8.health<D_00142668[0]) (D_001A4BE0_0032FDC8.health)++;
            vars[0xDD]=3;
            vars[0xDC]--;
            func_003E4D10(30);
        }
    }
    if(entry[3]) {
        func_L01_00452560(0,5,0,1,0,0,0);
        func_L07_00335558(obj);
        row=D_L07_002B0EB0+vars[0xB0]*8;
        weapon=*(s32 *)row;
        amount=*(s16 *)(vars+0xB2);
        if(amount<D_001427F0[weapon]) *(s16 *)(vars+0xB2)=D_001427F0[weapon];
        else {
            *(s16 *)(vars+0xB4)-=*(s16 *)(vars+0xB2)-(u16)D_001427F0[weapon];
            D_001427F0[weapon]=amount;
            {
                s32 threshold=row[4]>>3;
                s32 remaining=*(s16 *)(vars+0xB4);
                if (threshold) {
                    if (remaining==threshold) goto low_ammo;
                    goto ammo_check;
                } else if (remaining!=1) goto ammo_check;
            }
low_ammo:
            {
                if (!(((State_0032FDC8 *)vars)->flags&0x8000) && !func_00382468(4)) {
                    func_L07_003A2380(49,obj,0,100);
                    ((State_0032FDC8 *)vars)->flags|=0x10000;
                }
                ((State_0032FDC8 *)vars)->flags|=0x8000;
            }
ammo_check:
            if (*(s16 *)(vars+0xB4)<=0) {
                (*(s16 *)(vars+0xB6))++;
                D_001A4BE0_0032FDC8.cycling=1;
                if (*(s16 *)(vars+0xB6)>=26) {
                    weapon=func_L07_00332958(obj);
                    D_001A4BE0_0032FDC8.cycling=0;
                    func_L07_003352B8(obj,weapon);
                }
            } else *(s16 *)(vars+0xB6)=0;
        }
        if (!D_001A4BE0_0032FDC8.lock || D_001A4BE0_0032FDC8.weapon!=weapon) {
            D_001A4BE0_0032FDC8.selected=0;D_001A4BE0_0032FDC8.changed=1;
            func_L01_0044CD60(weapon);
        } else D_001A4BE0_0032FDC8.selected=1;
    } else if (*(s32 *)(entry+8)!=-1) {
        func_L01_00452560(0,5,0,1,0,0,0);
        if (!D_001A4BE0_0032FDC8.lock || D_001A4BE0_0032FDC8.weapon!=*(s32 *)(entry+8)) {
            D_001A4BE0_0032FDC8.selected=0;
            func_L01_0044CD60(*(s32 *)(entry+8));
        } else D_001A4BE0_0032FDC8.selected=1;
        if (func_L07_003334A8(obj,*(s32 *)(entry+8))) {
            vars[0xA8]=2;func_L07_00330F30(obj);
        }
    } else D_001A4BE0_0032FDC8.selected=0;
    if(!entry[0]) {
        if(vars[0xDE]<D_001A4BE0_0032FDC8.health) vars[0xDE]=*(u8 *)&D_001A4BE0_0032FDC8.health;
        if(D_001A4BE0_0032FDC8.health<vars[0xDE]) {
            vars[0xA8]=3;func_L07_00330F30(obj);
        }
    }
    func_L07_003304C0(obj);
    D_L07_001D7B20=vars[0x9E]+10;
    D_L07_001DF518=D_001D4C38;
}
/* localdecomp:end func_L07_0032FDC8 */
