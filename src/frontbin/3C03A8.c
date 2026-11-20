#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003C0720();


typedef int Q_3BAE98 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BAE98;
extern f32 D_001D8E60;
extern f32 D_001D8FC8;
extern s32 D_001D8F94;
extern s32 D_001D8E80;
extern s32 D_001D8F9C;
extern s32 D_001D8F98;
extern f32 D_001D8FA0;
extern f32 D_001D8FA4;
extern f32 D_001D8FA8;
extern f32 D_001D8FAC;
extern f32 D_001D8FB8;
extern f32 D_001D8FBC;
extern f32 D_001D8FC0;
extern f32 D_001D8FC4;
extern s32 D_001D8FB0;
extern s32 D_001D8FB4;
extern s32 D_001D8F90;
extern f32 D_001DA334;
extern s32 D_001D9D00;
extern void func_003A9440(s32, unsigned long);
extern void func_0038C750(void);
extern void func_0038D028();
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_003D9740(void *, s32, s32, s32, s32, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_003C03A8);

/* localdecomp:start func_003C0720 */
/* from boot_elf func_003C0AD8 (twin), callees renamed through config/frontend_pairs.tsv */
#include "vu0.h"
extern f32 D_001DA340;
extern u8 D_001DA33C;
extern s32 D_001D8E40;
__asm__(".extern D_001D8E40, 4");
extern vu0_v4 D_00222400[];
extern void func_003C09E8(void *);
extern void func_00389D60(void (*)(), s32);
extern void func_003C2EC0();
extern f32 func_0038CEA8(void *);
extern f32 func_003824E0(f32, f32);
extern void func_003BF988(void *, void *, void *);
void func_003C0720(u8 *obj) {
    vu0_v4 mat[4], d, p, v;
    vu0_v4 *table;
    vu0_v4 *velocity, *position;
    f32 base, ratio;
    s32 i;
    func_00389D60(func_003C09E8,(s32)obj);
    func_003C2EC0(obj,0,(u8 *)mat);
    D_001DA33C=0;
    *(f32 *)(&D_001DA33C+4)=1.0f;
    base=func_0038CEA8(mat);
    vec_sub_ab(&d,obj+0x10,D_00222400);
    ratio=func_0038CEA8(&d)/base;
    if(ratio>20.0f) {
        D_001DA33C=1;
        *(f32 *)(&D_001DA33C+4)=1.0f-(ratio-20.0f)/40.0f;
        if(*(f32 *)(&D_001DA33C+4)<0.0f) *(f32 *)(&D_001DA33C+4)=0.0f;
    }
    velocity=&v;
    position=&p;
    table=(vu0_v4 *)&D_001D8E40;
    for(i=1;i>=0;i--) {
        func_0038D028(position,table++,mat);
        v.x=0;
        v.y=0;
        v.z=func_003824E0(0.007f,0.015f);
        func_003BF988(obj,position,velocity);
    }
}
/* localdecomp:end func_003C0720 */
