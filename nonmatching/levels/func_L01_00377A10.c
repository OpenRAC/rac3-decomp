/* PAL near miss (Codex wave 10): near miss: 95 words differ with the file's flags.
 * Worker's note: w531/func_L01_00377A10.attempt07.log: 95 positional diffs (one instruction short); remaining absolute-load versus explicit table-base addressing at 0xA0..0xD4 and scheduler order around hero copy; three table address wordings unchanged under fixed ...
 */
#include "common.h"
/* localdecomp:start func_L01_00377A10 */
typedef int Q_00377A10 __attribute__((mode(TI)));
extern u8 D_00142692[];
extern s32 D_001D545C;
extern s32 D_L01_001D60EC;
extern f32 D_L01_002F16F0[] __attribute__((section(".sdata")));
typedef struct { u8 pad[0x25C0]; u8 *object; } Hero_00377A10;
extern Hero_00377A10 D_001A4BE0;
__asm__(".extern D_001D545C, 4");
u8 *func_L01_00377A10(void *owner, void *pos, void *velocity, f32 scale) {
    extern u8 *func_003C24B0(s32, s32);
    extern f32 func_00382538(void);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_L01_004C85C8(void *, s32, f32, f32, f32);
    u8 *obj = func_003C24B0(0x186D, 0x900);
    u8 *vars;
    u8 *axis;
    void *hero;
    if (obj) {
        obj[0x20]=0;
        obj[0x30]=*(u16 *)(obj+0x32)=255;
        vars=*(u8 **)(obj+0x68);
        *(Q_00377A10 *)(obj+0x10)=*(Q_00377A10 *)pos;
        *(Q_00377A10 *)vars=*(Q_00377A10 *)velocity;
        *(f32 *)(vars+0x10)=func_00382538();
        *(s32 *)(vars+0x28)=-1;
        *(f32 *)(vars+0x2C)=scale;
        *(s32 *)(vars+0x30)=25;
        *(s32 *)(vars+0x14)=0;
        *(f32 *)(vars+0x18)=0.05f;
        *(f32 *)(vars+0x1C)=0.05f;
        if(D_00142692[0]) {
            f32 *table=D_L01_002F16F0;
            *(s16 *)(vars+0x26)=(f32)D_L01_001D60EC*0.75f**(f32 *)((D_001D545C<<2)+(s32)table);
        }
        else *(s16 *)(vars+0x26)=(f32)D_L01_001D60EC*0.75f;
        *(s32 *)(vars+0x54)=1;
        if(!*(s16 *)(vars+0x26)) *(s16 *)(vars+0x26)=4;
        *(void **)(vars+0x58)=owner;
        *(s32 *)(vars+0x20)=37;
        *(s32 *)(vars+0x64)=150;
        *(s16 *)(vars+0x24)=0;
        *(f32 *)(obj+0x2C)=*(f32 *)(*(u8 **)(obj+0x24)+0x24)*3.25f;
        *(u16 *)(obj+0x34)|=0x100;
        obj[0x23]=20;
        hero=&D_001A4BE0;
        *(Q_00377A10 *)(obj+0xF0)=*(Q_00377A10 *)(((Hero_00377A10 *)hero)->object+0xF0);
        *(Q_00377A10 *)(obj+0xC0)=*(Q_00377A10 *)(((Hero_00377A10 *)hero)->object+0xC0);
        *(Q_00377A10 *)(obj+0xD0)=*(Q_00377A10 *)(((Hero_00377A10 *)hero)->object+0xD0);
        *(Q_00377A10 *)(obj+0xE0)=*(Q_00377A10 *)(((Hero_00377A10 *)hero)->object+0xE0);
        axis=obj+0xE0;
        func_0038CF68(obj+0xD0,obj+0xD0,*(f32 *)(vars+0x18));
        func_0038CF68(axis,axis,*(f32 *)(vars+0x1C));
        *(s32 *)(vars+0x60)=func_L01_004C85C8(obj,0,1.0f,1.0f,1.0f);
        *(s32 *)(obj+0x98)=0;
        *(u16 *)(obj+0x34)|=4;
    }
    return obj;
}
/* localdecomp:end func_L01_00377A10 */
