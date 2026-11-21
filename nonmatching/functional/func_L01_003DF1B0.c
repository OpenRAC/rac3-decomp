/* functional: high. Codex near miss, 161 words differ: callee-saved register choice and branch offsets only. I fixed two draft errors: func_00382348 takes *cursor (retail passes it in a0; the file's context declares it (void), so the snippet casts the function pointer: the file prototype needs fixing at integration), and the final slot-clear loop starts at D_L01_002A3A40+0x750 (owner word of the last of 24 rows), not +0x730. */
#include "common.h"
/* localdecomp:start func_L01_003DF1B0 */
#include "vu0.h"
extern vu0_v4 D_L01_001E29E0;
extern s32 D_L01_001DF54C;
__asm__(".extern D_L01_001DF54C, 4");
extern u8 D_001425C0[];
typedef struct { u8 p[0x6C]; f32 value; u8 tail[0x80]; } Weapon_003DF1B0;
extern u8 D_L01_002A3A40[];
extern S_003DEF68 D_001A4BE0;
void func_L01_003DF1B0(u8 *obj) {
    extern void func_L01_00404808(void (*)(u8 *),void *);
    extern void func_L01_003DF620(u8 *);
    extern s32 func_0038CAD0(void *);
    extern void func_L01_00404A10(void (*)(u8 *),void *);
    extern void func_L01_003DF558(u8 *);
    extern void func_0038CBA0(void *,s32);
    extern void func_L01_004C84D8(void *);
    extern void func_L01_004501E8(void *,void *,s32 *,void *,s32,f32,f32,f32,f32,f32,s32,s32,s32,s32,s32,s32);
    extern void func_0038CE20(void *,void *,f32);
    extern void func_L01_00446748(void *,void *,s32,f32);
    extern void func_L01_00446978(void *,void *);
    extern void func_L01_004AAC98(s32,s32,void *,s32);
    extern void func_L01_00315900(void *,s32,void (*)(void));
    extern void func_L01_003DE198(void);
    extern void func_003C2880(void *);
    u8 *d=*(u8 **)(obj+0x68);
    vu0_v4 direction;
    u8 *objects[32];
    u8 damage[0x30] __attribute__((aligned(16)));
    s32 count;
    s32 i;
    u8 **cursor;
    u8 *status;
    if(obj[0x20]!=1) func_L01_00404808(func_L01_003DF620,obj);
    if(obj[0x20]==1) {
        if(func_0038CAD0(d+0x10)) {
            obj[0x20]=5;
            *(s32 *)(d+4)=(D_L01_001DF54C*5+2)/6;
        }
    } else if(obj[0x20]==5) {
        if(func_0038CAD0(d+8)) {
            obj[0x20]=3;
            *(s32 *)(d+8)=53;
        } else func_L01_00404A10(func_L01_003DF558,obj);
    } else if(obj[0x20]==3) {
        i=0;
        direction=D_L01_001E29E0;
        func_0038CBA0(objects,128);
        func_L01_004C84D8(obj);
        func_L01_004501E8(obj+0x10,&direction,&count,objects,32,4.71238899230957f,1.3962633609771729f,60.0f,0.0f,0.0f,0,0,0,1,-1,0);
        cursor=objects;
        while(i<count) {
            status=((u8 *(*)(u8 *))func_00382348)(*cursor);
            if(*cursor && *(u8 **)(*cursor+0x24) && (*(u8 **)(*cursor+0x24))[0x46]==5 && status && status[14]!=3) {
                if(*(f32 *)status>((Weapon_003DF1B0 *)&D_L01_002C5600[D_001425C0[0x97]])->value) {
                    *(s32 *)(damage+0x20)=1;
                    func_0038CE20(damage,obj+0xD0,-1.0f);
                    *(f32 *)(damage+0xC)=5627.9248046875f;
                    func_L01_00446748(damage,*cursor,0x110000,((Weapon_003DF1B0 *)&D_L01_002C5600[D_001425C0[0x97]])->value);
                    func_L01_00446978(*cursor,damage);
                } else {
                    func_L01_004AAC98(2,0,*(u8 **)((u8 *)&D_001A4BE0+0x25C0),500);
                    func_L01_00315900(*cursor,4,func_L01_003DE198);
                }
            } else if(*cursor && *(u8 **)(*cursor+0x24) && (*(u8 **)(*cursor+0x24))[0x46]==5 && status && status[14]==3) {
                *(s32 *)(damage+0x20)=1;
                func_0038CE20(damage,obj+0xD0,-1.0f);
                *(f32 *)(damage+0xC)=5627.9248046875f;
                func_L01_00446748(damage,*cursor,0x110000,((Weapon_003DF1B0 *)&D_L01_002C5600[D_001425C0[0x97]])->value);
                func_L01_00446978(*cursor,damage);
            }
            ++i; ++cursor;
        }
        {
            u8 *row=D_L01_002A3A40+0x750;
            s32 n=23;
            do { *(s32 *)row=0; row-=0x50; } while(--n>=0);
        }
        func_003C2880(obj);
    }
}
/* localdecomp:end func_L01_003DF1B0 */
